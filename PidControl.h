#ifndef CHIIKUMA21_PIDCONTROL_H_
#define CHIIKUMA21_PIDCONTROL_H_

#include "ev3api.h"

class PidControl {
 public:
  PidControl(float kp, float ki, float kd, float dt);
  void SetGain(float kp, float ki, float kd);
  void SetPeriod(float dt);
  float GetMv(int32_t current_val, int32_t target_val);

 private:
  float kp_;
  float ki_;
  float kd_;
  float dt_;
  float diff0_ = 0;
  float diff1_ = 0;
  float integral_ = 0;
};

#endif  // CHIIKUMA21_PIDCONTROL_H_
