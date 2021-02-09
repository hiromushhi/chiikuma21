#ifndef CHIIKUMA21_ETRCRUNNER_H_
#define CHIIKUMA21_ETRCRUNNER_H_

#include "state_transition.h"
#include "drive_modes.h"
#include "meters.h"
#include "Wheels.h"

class EtrcRunner {
 public:
  EtrcRunner();
  ~EtrcRunner();
  void Run();

 private:
  State* curr_state_;
  Wheels* wheels_;
  ColorMeter* color_meter_;
  LinetraceMode* linetrace_mode_;
};

#endif  // CHIIKUMA21_ETRCRUNNER_H_
