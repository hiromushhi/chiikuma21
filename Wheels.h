#ifndef CHIIKUMA21_WHEELS_H_
#define CHIIKUMA21_WHEELS_H_

#include "ev3api.h"

class Wheels {
 public:
  Wheels();
  ~Wheels();
  void Control(int8_t left_pwm, int8_t right_pwm);
  void Stop();

 private:
  static const motor_port_t left_motor_ = EV3_PORT_C;
  static const motor_port_t right_motor_ = EV3_PORT_B;
};

#endif  // CHIIKUMA21_WHEELS_H_
