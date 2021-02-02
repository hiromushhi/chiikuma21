#include "LinetraceMode.h"

#include "ev3api.h"

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

  // uint16_t g = val.g;
  // uint16_t target = 20;

  // if (g > target) {
  //   wheels_->Control(15, 0);
  // } else if (g < target) {
  //   wheels_->Control(0, 15);
  // } else {
  //   wheels_->Control(15, 15);
  // }
}
