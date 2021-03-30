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

void OvDriver::Drive(float base, float mv) {
  int8_t power_l = (base + mv);
  int8_t power_r = (base - mv);
  motor_io_->SetPower(power_l, power_r);
}

ColorCond::ColorCond(Luminous* luminous) {
  luminous_ = luminous;
}

void ColorCond::SetColor(Color color) {
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

DistCond::DistCond(Localize* localize) {
  localize_ = localize;
  origin_ = -1;
}

void DistCond::SetDistance(float distance) {
  distance_ = distance;
}

bool DistCond::IsSatisfied() {
  if (origin_ == -1) {
    origin_ = localize_->GetDistance();
  }

  float dL = localize_->GetDistance() - origin_;
  if (dL >= distance_) {
    return true;
  } else {
    return false;
  }
}
