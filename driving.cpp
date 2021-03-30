#include "driving.h"

RlTracer::RlTracer(Luminous* luminous) {
  luminous_ = luminous;
  pid_control_ = new PidControl(0.2, 0.0, 0.01, 0.01);
}

RlTracer::~RlTracer() {
  delete pid_control_;
}

float RlTracer::Run() {
  Hsv curr_hsv = luminous_->GetHsv();
  float mv = pid_control_->GetMv(curr_hsv.v, 50);
  return mv;
}

VlTracer::VlTracer(Localize* localize) {
  localize_ = localize;
  pid_control_ = new PidControl(0.2, 0.0, 0.01, 0.01);
}

VlTracer::~VlTracer() {
  delete pid_control_;
}

float VlTracer::Run() {
  return 0;
}

OvDriver::OvDriver(MotorIo* motor_io) {
  motor_io_ = motor_io;
}

void OvDriver::Drive(float mv) {
  int8_t power_l = (20 + mv);
  int8_t power_r = (20 - mv);
  motor_io_->SetPower(power_l, power_r);
}

ColorCond::ColorCond(Luminous* luminous, Color color) {
  luminous_ = luminous;
  color_ = color;
}

bool ColorCond::IsSatisfied() {
  Color curr_color = luminous_->GetColor();
  if (curr_color == color_) {
    return true;
  } else {
    return false;
  }
}

DistCond::DistCond(Localize* localize, float distance) {
  localize_ = localize;
  distance_ = distance;
  origin_ = -1;
}

bool DistCond::IsSatisfied() {
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
