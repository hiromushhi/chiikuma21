#include "driving.h"

void LinetraceSection::Exec() {
}

void VirtualLinetraceSection::Exec() {
}

Linetracer::Linetracer(LightEnvironment* light_environment) {
  light_environment_ = light_environment;
  pid_control_ = new PidControl(0.2, 0.0, 0.01, 0.01);
}

Linetracer::~Linetracer() {
  delete pid_control_;
}

float Linetracer::Exec() {
  Hsv curr_hsv = light_environment_->GetHsv();

  float mv = pid_control_->GetMv(curr_hsv.v, 50);
  return mv;
}

DriveControl::DriveControl(MotorIo* motor_io) {
  motor_io_ = motor_io;
}

void DriveControl::Exec(float mv) {
  int8_t left_pwm = (20 + mv);
  int8_t right_pwm = (20 - mv);
  motor_io_->SetPwm(left_pwm, right_pwm);
}
