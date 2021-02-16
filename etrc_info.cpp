#include "etrc_info.h"

void SelfLocalization::Update() {
}

LightEnvironment::LightEnvironment(SensorIo* sensor_io) {
  sensor_io_ = sensor_io;

  SetColorReference(kGreen, {120, 0, 0});
  SetColorReference(kBlack, {0, 0, 0});
  SetColorReference(kRed, {0, 0, 0});
  SetColorReference(kYellow, {50, 0, 0});
  SetColorReference(kBlue, {210, 0, 0});
  SetColorReference(kWhite, {0, 0, 0});
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

  float h;
  if (min == max) {
    h = -1;
  } else if (min == b) {
    h = 60 * (g - r) / (max - min) + 60;
  } else if (min == r) {
    h = 60 * (b - g) / (max - min) + 180;
  } else if (min == g) {
    h = 60 * (r - b) / (max - min) + 300;
  } else {
    h = -1;
  }

  curr_hsv_.h = h;
  curr_hsv_.s = (max - min);
  curr_hsv_.v = max;
}

void LightEnvironment::UpdateColor() {
}

void VehicleSpeed::Update() {
}
