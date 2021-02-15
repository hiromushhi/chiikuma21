#ifndef CHIIKUMA21_DRIVING_H_
#define CHIIKUMA21_DRIVING_H_

enum Edge {
  kLeft = 0,
  kRight,
  kEdgeNum
};

struct Param {
  float velocity;
};

class Section {
};

class LinetraceSection : public Section {
};

class VirtualLinetraceSection : public Section {
};

class Linetracer {
};

class VirtualLinetracer {
};

class DriveControl {
};

class Cond {
};

class ColorCond : public Cond {
};

class DistanceCond : public Cond {
};

class CompositeCond : public Cond {
};

#endif  // CHIIKUMA21_DRIVING_H_
