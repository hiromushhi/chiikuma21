#ifndef CHIIKUMA21_SPEEDRUN_H_
#define CHIIKUMA21_SPEEDRUN_H_

#include "ev3api.h"
#include "State.h"
#include "Wheels.h"
#include "ColorMeter.h"
#include "LinetraceMode.h"

class SpeedrunState : public State {
 public:
  SpeedrunState();
  ~SpeedrunState();
  State* Update();

 private:
  Wheels* wheels_;
  ColorMeter* color_meter_;
  LinetraceMode* linetrace_mode_;
  static const sensor_port_t touch_sensor_ = EV3_PORT_1;
};

#endif  // CHIIKUMA21_SPEEDRUN_H_
