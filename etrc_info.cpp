#include "etrc_info.h"

SelfLocalization::SelfLocalization(VehicleSpeed* vehicle_speed) {
  vehicle_speed_ = vehicle_speed;
  coordinate_ = {0, 0, 0};
}

void SelfLocalization::Update() {
  Speed v = vehicle_speed_->GetSpeed();

  float dLR = v.r * dt_;
  float dLL = v.l * dt_;
  float dL = (dLR + dLL) / 2;
  float dtheta = (dLR - dLL) / tread_;
  float p = dL / dtheta;
  float dLprime = 2 * p * sin(dtheta/2);

  coordinate_.x = coordinate_.x + dLprime * cos(coordinate_.theta + dtheta/2);
  coordinate_.y = coordinate_.y + dLprime * sin(coordinate_.theta + dtheta/2);
  coordinate_.theta = coordinate_.theta + dtheta;
}

LightEnvironment::LightEnvironment(SensorIo* sensor_io) {
  sensor_io_ = sensor_io;

  SetColorReference(kGreen, {120, 0, 0});
  SetColorReference(kBlack, {0, 0, 0});
  SetColorReference(kRed, {0, 0, 0});
  SetColorReference(kYellow, {50, 0, 0});
  SetColorReference(kBlue, {210, 0, 0});
  SetColorReference(kWhite, {0, 20, 0});
  SetColorReference(kNone, {0, 0, 0});
}

void LightEnvironment::Update() {
  rgb_raw_t val = sensor_io_->GetRgbRaw();
  UpdateHsv(val);
  UpdateColor();

  // debug
  char str[32];
  sprintf(str, "H:%5f", curr_hsv_.h);
  ev3_lcd_draw_string(str, 10, 10);
  sprintf(str, "S:%5f", curr_hsv_.s);
  ev3_lcd_draw_string(str, 10, 30);
  sprintf(str, "V:%5f", curr_hsv_.v);
  ev3_lcd_draw_string(str, 10, 50);

  switch (curr_color_) {
    case kGreen:  sprintf(str, "Green "); break;
    case kBlack:  sprintf(str, "Black "); break;
    case kRed:    sprintf(str, "Red   "); break;
    case kYellow: sprintf(str, "Yellow"); break;
    case kBlue:   sprintf(str, "Blue  "); break;
    case kWhite:  sprintf(str, "White "); break;
    case kNone:   sprintf(str, "None  "); break;
    default:      sprintf(str, "Nonen "); break;
  }
  ev3_lcd_draw_string(str, 10, 70);
}

void LightEnvironment::SetColorReference(Color c, Hsv data) {
  color_ref_[c] = data;
}

Color LightEnvironment::GetColor() {
  return curr_color_;
}

void LightEnvironment::UpdateHsv(rgb_raw_t val) {
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

void LightEnvironment::UpdateColor() {
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

VehicleSpeed::VehicleSpeed(MotorIo* motor_io) {
  motor_io_ = motor_io;
  speed_ = {0, 0, 0};
}

void VehicleSpeed::Update() {
  static Count prev_count = {0, 0};

  Count curr_count = motor_io_->GetCounts();
  float dl = (curr_count.l - prev_count.l) / 360.0 * circ_;
  float dr = (curr_count.r - prev_count.r) / 360.0 * circ_;
  float db = (dl + dr) / 2.0;

  speed_.l = dl / dt_;
  speed_.r = dr / dt_;
  speed_.b = db / dt_;

  prev_count = curr_count;
}

Speed VehicleSpeed::GetSpeed() {
  return speed_;
}
