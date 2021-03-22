#ifndef CHIIKUMA21_DRIVING_H_
#define CHIIKUMA21_DRIVING_H_

#include "etrc_info.h"
#include "utils.h"

enum Edge {
  kLeft = 0,
  kRight,
  kEdgeNum
};

class RlTracer {
 public:
  RlTracer(Luminous* luminous);
  ~RlTracer();
  float Exec();

 private:
  Luminous* luminous_;
  PidControl* pid_control_;
};

class VlTracer {
 public:
  VlTracer(Localize* localize);
  ~VlTracer();
  float Exec();

 private:
  Localize* localize_;
  PidControl* pid_control_;
};

class OvDriver {
 public:
  OvDriver(MotorIo* motor_io);
  void Exec(float mv);

 private:
  MotorIo* motor_io_;
};

class Cond {
 public:
  virtual bool IsSatisfied() = 0;
};

class ColorCond : public Cond {
 public:
  ColorCond(Luminous* luminous, Color color);
  bool IsSatisfied();

 private:
  Luminous* luminous_;
  Color color_;
};

class DistCond : public Cond {
 public:
  DistCond(Localize* localize, float distance);
  bool IsSatisfied();

 private:
  Localize* localize_;
  float distance_;
  float origin_;
};

class CompCond : public Cond {
};

class Section {
 public:
  virtual void Exec() = 0;
};

class RlSection : public Section {
 public:
  void Exec();
};

class VlSection : public Section {
 public:
  void Exec();
};

#endif  // CHIIKUMA21_DRIVING_H_
