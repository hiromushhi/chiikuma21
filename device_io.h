#ifndef CHIIKUMA21_DEVICE_IO_H_
#define CHIIKUMA21_DEVICE_IO_H_

#include "ev3api.h"

class MotorIo {
};

class SensorIo {
 public:
  SensorIo();
  rgb_raw_t GetRgbRaw();
};

#endif  // CHIIKUMA21_DEVICE_IO_H_
