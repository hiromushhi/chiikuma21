#include "driving.h"

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

VirtualLinetracer::VirtualLinetracer(Localize* localize) {
  localize_ = localize;
  pid_control_ = new PidControl(0.2, 0.0, 0.01, 0.01);
}

VirtualLinetracer::~VirtualLinetracer() {
  delete pid_control_;
}

float VirtualLinetracer::Exec() {
  // Posture posture = localize_->GetPosture();

  // static Posture orbit = {0, 0, 0};
  // orbit.x = posture.x;
  // orbit.y = 0;

  // float L = sqrt(pow((orbit.x - posture.x), 2) + pow((orbit.y - posture.y), 2));
  // float mv = pid_control_->GetMv(L, 0);
  // return mv;
  return 0;
}

DriveControl::DriveControl(MotorIo* motor_io) {
  motor_io_ = motor_io;
}

void DriveControl::Exec(float mv) {
  int8_t power_l = (20 + mv);
  int8_t power_r = (20 - mv);
  motor_io_->SetPower(power_l, power_r);
}

ColorCondition::ColorCondition(LightEnvironment* light_environment, Color color) {
  light_environment_ = light_environment;
  color_ = color;
}

bool ColorCondition::IsSatisfied() {
  Color curr_color = light_environment_->GetColor();
  if (curr_color == color_) {
    return true;
  } else {
    return false;
  }
}

DistanceCondition::DistanceCondition(Localize* localize, float distance) {
  localize_ = localize;
  distance_ = distance;
  origin_ = -1;
}

bool DistanceCondition::IsSatisfied() {
  if (origin_ == -1) {
    localize_->GetDistance();
  }

  float dL = localize_->GetDistance() - origin_;
  if (dL >= distance_) {
    return true;
  } else {
    return false;
  }
}

void LinetraceSection::Exec() {
}

void VirtualLinetraceSection::Exec() {
}
