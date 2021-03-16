#ifndef CHIIKUMA21_DRIVING_H_
#define CHIIKUMA21_DRIVING_H_

#include "etrc_info.h"
#include "utils.h"

enum Edge {
  kLeft = 0,
  kRight,
  kEdgeNum
};

class Section {
 public:
  virtual void Exec() = 0;
};

class LinetraceSection : public Section {
 public:
  void Exec();
};

class VirtualLinetraceSection : public Section {
 public:
  void Exec();
};

class Linetracer {
 public:
  Linetracer(LightEnvironment* light_environment);
  ~Linetracer();
  float Exec();

 private:
  LightEnvironment* light_environment_;
  PidControl* pid_control_;
};

class VirtualLinetracer {
 public:
  VirtualLinetracer(SelfLocalization* self_localization);
  ~VirtualLinetracer();
  float Exec();

 private:
  SelfLocalization* self_localization_;
  PidControl* pid_control_;
};

class DriveControl {
 public:
  DriveControl(MotorIo* motor_io);
  void Exec(float mv);

 private:
  MotorIo* motor_io_;
};

class Condition {
};

class ColorCondition : public Condition {
};

class DistanceCondition : public Condition {
};

class CompositeCondition : public Condition {
};

#endif  // CHIIKUMA21_DRIVING_H_
