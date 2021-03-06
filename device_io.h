#ifndef CHIIKUMA21_DEVICE_IO_H_
#define CHIIKUMA21_DEVICE_IO_H_

#include "ev3api.h"

struct Counts {
  int32_t l;
  int32_t r;
};

class MotorIo {
 public:
  MotorIo();
  ~MotorIo();
  Counts GetCounts();
  void SetPower(int8_t power_l, int8_t power_r);
};

class SensorIo {
 public:
  SensorIo();
  rgb_raw_t GetRgbRaw();
};

#endif  // CHIIKUMA21_DEVICE_IO_H_
