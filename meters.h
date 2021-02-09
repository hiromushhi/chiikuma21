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

class OdoMeter {
 public:
  OdoMeter();
  ~OdoMeter();
  int32_t GetDistance();

 private:
  static const motor_port_t left_motor_ = EV3_PORT_C;
  static const motor_port_t right_motor_ = EV3_PORT_B;
  static const int32_t diameter_ = 100;  // [mm]
};

#endif  // CHIIKUMA21_METERS_H_
