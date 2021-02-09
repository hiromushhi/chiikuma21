#include "drive_modes.h"

LinetraceMode::LinetraceMode(Wheels* wheels, ColorMeter* color_meter) {
  wheels_ = wheels;
  color_meter_ = color_meter;
  pid_control_ = new PidControl(0.2, 0.0, 0.01, 0.01);
}

LinetraceMode::~LinetraceMode() {
}

void LinetraceMode::Exec() {
  rgb_raw_t val;
  val = color_meter_->GetRawRgb();

  float mv = pid_control_->GetMv(val.g, 20);
  int8_t left_pwm = static_cast<float>(20 + mv);
  int8_t right_pwm = static_cast<float>(20 - mv);
  wheels_->Control(left_pwm, right_pwm);
}


StraightMode::StraightMode(Wheels* wheels) {
  wheels_ = wheels;
}

StraightMode::~StraightMode() {
  ;
}

void StraightMode::Exec(int8_t pwm) {
  wheels_->Control(pwm, pwm);
}


RotationMode::RotationMode(Wheels* wheels) {
  wheels_ = wheels;
}

RotationMode::~RotationMode() {
  ;
}

void RotationMode::Exec(int8_t pwm) {
  wheels_->Control(pwm, 0);
}
