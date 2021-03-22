#ifndef CHIIKUMA21_DRIVING_H_
#define CHIIKUMA21_DRIVING_H_

#include "etrc_info.h"
#include "utils.h"

enum Edge {
  kLeft = 0,
  kRight,
  kEdgeNum
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
  VirtualLinetracer(Localize* localize);
  ~VirtualLinetracer();
  float Exec();

 private:
  Localize* localize_;
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
 public:
  virtual bool IsSatisfied() = 0;
};

class ColorCondition : public Condition {
 public:
  ColorCondition(LightEnvironment* light_environment, Color color);
  bool IsSatisfied();

 private:
  LightEnvironment* light_environment_;
  Color color_;
};

class DistanceCondition : public Condition {
 public:
  DistanceCondition(Localize* localize, float distance);
  bool IsSatisfied();

 private:
  Localize* localize_;
  float distance_;
  float origin_;
};

class CompositeCondition : public Condition {
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

#endif  // CHIIKUMA21_DRIVING_H_
