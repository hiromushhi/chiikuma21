#ifndef CHIIKUMA21_LINETRACEMODE_H_
#define CHIIKUMA21_LINETRACEMODE_H_

#include "Wheels.h"
#include "ColorMeter.h"

class LinetraceMode {
 public:
  explicit LinetraceMode(Wheels* wheels, ColorMeter* color_meter);
  ~LinetraceMode();
  void Exec();

 private:
  Wheels* wheels_;
  ColorMeter* color_meter_;
};

#endif  // CHIIKUMA21_LINETRACEMODE_H_
