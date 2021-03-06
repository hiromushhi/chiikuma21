#include "utils.h"

PidControl::PidControl(float kp, float ki, float kd, float dt) {
  SetGain(kp, ki, kd);
  SetPeriod(dt);
  diff0_ = 0;
  diff1_ = 0;
  integral_ = 0;
}

void PidControl::SetGain(float kp, float ki, float kd) {
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;
}

void PidControl::SetPeriod(float dt) {
  dt_ = dt;
}

float PidControl::GetMv(int32_t current_val, int32_t target_val) {
  float p, i, d, mv;

  diff0_ = diff1_;
  diff1_ = current_val - target_val;
  integral_ += (diff1_ + diff0_) / 2.0 * dt_;

  p = kp_ * diff1_;
  i = ki_ * integral_;
  d = kd_ * (diff1_ - diff0_) / dt_;
  mv = p + i + d;

  return mv;
}
