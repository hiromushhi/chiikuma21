#include "etrc_info.h"

void SelfLocalization::Update() {
}

void LightEnvironment::Update() {
}

void LightEnvironment::SetColorReference(Color c, Hsv data) {
  color_ref_[c] = data;
}

Color LightEnvironment::GetColor() {
  return curr_color_;
}

void VehicleSpeed::Update() {
}
