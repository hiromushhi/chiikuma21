#ifndef CHIIKUMA21_LINETRACEMODE_H_
#define CHIIKUMA21_LINETRACEMODE_H_

#include "Wheels.h"

class LinetraceMode {
 public:
  explicit LinetraceMode(Wheels* wheels);
  ~LinetraceMode();
  void Exec();

 private:
  Wheels* wheels_;
};

#endif  // CHIIKUMA21_LINETRACEMODE_H_
