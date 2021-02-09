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


class StraightMode {
 public:
  StraightMode(Wheels* wheels);
  ~StraightMode();
  void Exec(int8_t pwm);

 private:
  Wheels* wheels_;
};


class RotationMode {
 public:
  RotationMode(Wheels* wheels);
  ~RotationMode();
  void Exec(int8_t pwm);

 private:
  Wheels* wheels_;
};

#endif  // CHIIKUMA21_DRIVE_MODES_H_
