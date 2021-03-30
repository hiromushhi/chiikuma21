#ifndef CHIIKUMA21_DRIVING_H_
#define CHIIKUMA21_DRIVING_H_

#include "etrc_info.h"
#include "utils.h"

class Tracer {
 public:
  virtual float Run() = 0;
};

class RlTracer : public Tracer {
 public:
  RlTracer(Luminous* luminous);
  virtual ~RlTracer();
  float Run();

 private:
  Luminous* luminous_;
  PidControl* pid_control_;
};

class VlTracer : public Tracer {
 public:
  VlTracer(Localize* localize);
  virtual ~VlTracer();
  float Run();

 private:
  Localize* localize_;
  PidControl* pid_control_;
};

class OvDriver {
 public:
  OvDriver(MotorIo* motor_io);
  void Drive(float mv);

 private:
  MotorIo* motor_io_;
};

class Cond {
 public:
  virtual bool IsSatisfied() = 0;
};

class ColorCond : public Cond {
 public:
  ColorCond(Luminous* luminous);
  void SetColor(Color color);
  bool IsSatisfied();

 private:
  Luminous* luminous_;
  Color color_;
};

class DistCond : public Cond {
 public:
  DistCond(Localize* localize);
  void SetDistance(float distance);
  bool IsSatisfied();

 private:
  Localize* localize_;
  float distance_;
  float origin_;
};

#endif  // CHIIKUMA21_DRIVING_H_
