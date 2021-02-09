#include "meters.h"

#include <math.h>

ColorMeter::ColorMeter() {
  ev3_sensor_config(color_sensor_, COLOR_SENSOR);
}

ColorMeter::~ColorMeter() {
}

rgb_raw_t ColorMeter::GetRawRgb() {
  rgb_raw_t val;
  ev3_color_sensor_get_rgb_raw(color_sensor_, &val);
  return val;
}

OdoMeter::OdoMeter() {
  ev3_motor_config(left_motor_, LARGE_MOTOR);
  ev3_motor_config(right_motor_, LARGE_MOTOR);

  ev3_motor_reset_counts(left_motor_);
  ev3_motor_reset_counts(right_motor_);
}

OdoMeter::~OdoMeter() {
  ;
}

int32_t OdoMeter::GetDistance() {
  float counts;
  counts = (ev3_motor_get_counts(left_motor_) +
            ev3_motor_get_counts(right_motor_)) / 2.0;

  int32_t distance;
  distance = static_cast<int32_t>(M_PI * diameter_ * counts / 360.0);

  return distance;
}
