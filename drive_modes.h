#ifndef CHIIKUMA21_DRIVE_MODES_H_
#define CHIIKUMA21_DRIVE_MODES_H_

#include "ev3api.h"
#include "meters.h"
#include "Wheels.h"
#include "PidControl.h"

class LinetraceMode {
 public:
  explicit LinetraceMode(Wheels* wheels, ColorMeter* color_meter);
  ~LinetraceMode();
  void Exec();

 private:
  Wheels* wheels_;
  ColorMeter* color_meter_;
  PidControl* pid_control_;
};

#endif  // CHIIKUMA21_DRIVE_MODES_H_
