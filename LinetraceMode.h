#ifndef CHIIKUMA21_LINETRACEMODE_H_
#define CHIIKUMA21_LINETRACEMODE_H_

#include "Wheels.h"

class LinetraceMode {
 public:
  LinetraceMode(Wheels* wheels);
  ~LinetraceMode();
  void exec();

 private:
  Wheels* wheels_;
};

#endif  // CHIIKUMA21_LINETRACEMODE_H_
