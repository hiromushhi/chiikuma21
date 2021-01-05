#ifndef CHIIKUMA21_ETRCRUNNER_H_
#define CHIIKUMA21_ETRCRUNNER_H_

#include "LineTracer.h"

class EtrcRunner {
 public:
  EtrcRunner();
  ~EtrcRunner();
  void update();

 private:
  LineTracer* line_tracer_;
};

#endif  // CHIIKUMA21_ETRCRUNNER_H_
