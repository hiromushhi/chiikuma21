#include "device_io.h"

MotorIo::MotorIo() {
  ev3_motor_config(EV3_PORT_B, LARGE_MOTOR);
  ev3_motor_reset_counts(EV3_PORT_B);
  ev3_motor_config(EV3_PORT_C, LARGE_MOTOR);
  ev3_motor_reset_counts(EV3_PORT_C);
}

Count MotorIo::GetCounts() {
  Count count;
  count.l = ev3_motor_get_counts(EV3_PORT_C);
  count.r = ev3_motor_get_counts(EV3_PORT_B);
  return count;
}

SensorIo::SensorIo() {
  ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
}

rgb_raw_t SensorIo::GetRgbRaw() {
  rgb_raw_t val;
  ev3_color_sensor_get_rgb_raw(EV3_PORT_2, &val);
  return val;
}
