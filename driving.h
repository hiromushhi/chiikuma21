#ifndef CHIIKUMA21_DRIVING_H_
#define CHIIKUMA21_DRIVING_H_

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
};

class VirtualLinetracer {
};

class DriveControl {
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
