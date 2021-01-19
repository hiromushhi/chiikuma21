#ifndef CHIIKUMA21_ETRCRUNNER_H_
#define CHIIKUMA21_ETRCRUNNER_H_

#include "Wheels.h"
#include "LinetraceMode.h"
#include "ev3api.h"

class EtrcRunner {
 public:
  EtrcRunner();
  ~EtrcRunner();
  void Run();

 private:
  Wheels* wheels_;
  LinetraceMode* linetrace_mode_;
  static const sensor_port_t touch_sensor_ = EV3_PORT_1;
};

#endif  // CHIIKUMA21_ETRCRUNNER_H_
