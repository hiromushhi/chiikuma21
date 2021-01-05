#include "Wheels.h"

Wheels::Wheels() {
  ev3_motor_config(left_motor_, LARGE_MOTOR);
  ev3_motor_config(right_motor_, LARGE_MOTOR);
}

Wheels::~Wheels() {
  stop();
}

void Wheels::control(int8_t left_pwm, int8_t right_pwm) {
  ev3_motor_set_power(left_motor_, left_pwm);
  ev3_motor_set_power(right_motor_, right_pwm);
}

void Wheels::stop() {
  ev3_motor_stop(left_motor_, false);
  ev3_motor_stop(right_motor_, false);
}
