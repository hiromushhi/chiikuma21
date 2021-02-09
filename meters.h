#ifndef CHIIKUMA21_METERS_H_
#define CHIIKUMA21_METERS_H_

#include "ev3api.h"

class ColorMeter {
 public:
  ColorMeter();
  ~ColorMeter();
  rgb_raw_t GetRawRgb();

 private:
  static const sensor_port_t color_sensor_ = EV3_PORT_2;
};

#endif  // CHIIKUMA21_METERS_H_
