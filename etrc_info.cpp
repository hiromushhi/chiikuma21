#include "etrc_info.h"

Luminous::Luminous(SensorIo* sensor_io) {
  sensor_io_ = sensor_io;

  SetColorReference(kGreen, (Hsv){120, 0, 0});
  SetColorReference(kBlack, (Hsv){0, 0, 0});
  SetColorReference(kRed, (Hsv){0, 0, 0});
  SetColorReference(kYellow, (Hsv){50, 0, 0});
  SetColorReference(kBlue, (Hsv){210, 0, 0});
  SetColorReference(kWhite, (Hsv){0, 20, 0});
  SetColorReference(kNone, (Hsv){0, 0, 0});
}

void Luminous::Update() {
  rgb_raw_t val = sensor_io_->GetRgbRaw();
  UpdateHsv(val);
  UpdateColor();
}

Color Luminous::GetColor() {
  return curr_color_;
}

Hsv Luminous::GetHsv() {
  return curr_hsv_;
}

void Luminous::SetColorReference(Color c, Hsv data) {
  color_ref_[c] = data;
}

void Luminous::UpdateHsv(rgb_raw_t val) {
  float r = static_cast<float>(val.r);
  float g = static_cast<float>(val.g);
  float b = static_cast<float>(val.b);

  float max = r > g ? r : g;
  max = max > b ? max : b;
  float min = r < g ? r : g;
  min = min < b ? min : b;
  float c = max - min;

  float h;
  if (c == 0) {
    h = -1;
  } else if (max == r) {
    h = fmodf(((g - b) / c), 6);
  } else if (max == g) {
    h = ((b - r) / c) + 2;
  } else if (max == b) {
    h = ((r - g) / c) + 4;
  } else {
    h = -1;
  }

  if (h != -1) {
    h = 60 * h;
  }

  float s;
  if (max == 0) {
    s = 0;
  } else {
    s = c / max;
  }

  float v = max;
  if (v > 100) {
    v = 100;
  }

  curr_hsv_.h = h;
  curr_hsv_.s = s * 100;
  curr_hsv_.v = v;
}

void Luminous::UpdateColor() {
  float sat_white = color_ref_[kWhite].s;
  float val_black = color_ref_[kBlack].v;
  float hue_green = color_ref_[kGreen].h;
  float hue_red = color_ref_[kRed].h;
  float hue_blue = color_ref_[kBlue].h;
  float hue_yellow = color_ref_[kYellow].h;

  if (sat_white - 20 < curr_hsv_.s && curr_hsv_.s < sat_white + 20) {
    curr_color_ = kWhite;
  } else {
    if (hue_green - 20 < curr_hsv_.h && curr_hsv_.h < hue_green + 70) {
      if (curr_hsv_.v < val_black + 20) {
        curr_color_ = kBlack;
      } else {
        curr_color_ = kGreen;
      }
    } else if (curr_hsv_.h < hue_red + 20 || 360 - 20 < curr_hsv_.h) {
      curr_color_ = kRed;
    } else if (hue_blue - 20 < curr_hsv_.h && curr_hsv_.h < hue_blue + 20) {
      curr_color_ = kBlue;
    } else if (hue_yellow - 20 < curr_hsv_.h && curr_hsv_.h < hue_yellow + 20) {
      curr_color_ = kYellow;
    } else {
      curr_color_ = kNone;
    }
  }
}

Localize::Localize(MotorIo* motor_io) {
  motor_io_ = motor_io;
  posture_ = (Posture){0, 0, 0};
  prev_counts_ = (Counts){0, 0};
  distance_ = 0;

  radius_ = 50;  // タイヤの半径 [mm]
  tread_ = 143;  // 左右の車輪中心間距離 [mm]
  dtheta_th_ = 0.001;  // dthetaが十分小さいか判定する閾値
}

void Localize::Update() {
  // 自己位置の更新
  Counts curr_counts = motor_io_->GetCounts();

  float dPhiL = (curr_counts.l - prev_counts_.l) * M_PI / 180;
  float dPhiR = (curr_counts.r - prev_counts_.r) * M_PI / 180;

  float dLL = radius_ * dPhiL;
  float dLR = radius_ * dPhiR;
  float dL = (dLR + dLL) / 2;
  float dtheta = (dLR - dLL) / tread_;

  posture_.theta = posture_.theta + dtheta;
  if (dtheta < dtheta_th_) {
    posture_.x = posture_.x + dL * cos(posture_.theta + dtheta / 2);
    posture_.y = posture_.y + dL * sin(posture_.theta + dtheta / 2);
  } else {
    float rho = dL / dtheta;
    float dLprime = 2 * rho * sin(dtheta / 2);
    posture_.x = posture_.x + dLprime * cos(posture_.theta + dtheta / 2);
    posture_.y = posture_.y + dLprime * sin(posture_.theta + dtheta / 2);
  }

  prev_counts_ = curr_counts;

  // 走行距離の更新
  distance_ = ((curr_counts.l + curr_counts.r) / 2) * M_PI / 180 * radius_;
}

Posture Localize::GetPosture() {
  return posture_;
}

float Localize::GetDistance() {
  return distance_;
}
