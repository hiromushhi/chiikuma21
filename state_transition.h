#ifndef CHIIKUMA21_STATE_TRANSITION_H_
#define CHIIKUMA21_STATE_TRANSITION_H_

#include "ev3api.h"
#include "Wheels.h"
#include "ColorMeter.h"
#include "LinetraceMode.h"

class State {
 public:
  State() {}
  virtual ~State() {}
  virtual State* Update() = 0;
};

class SpeedrunState : public State {
 public:
  SpeedrunState(LinetraceMode* linetrace_mode);
  ~SpeedrunState();
  State* Update();

 private:
  Wheels* wheels_;
  ColorMeter* color_meter_;
  LinetraceMode* linetrace_mode_;
  static const sensor_port_t touch_sensor_ = EV3_PORT_1;
};

class GameplayState : public State {
 public:
  GameplayState();
  ~GameplayState();
  State* Update();
};

class ParkstopState : public State {
 public:
  ParkstopState();
  ~ParkstopState();
  State* Update();
};

#endif  // CHIIKUMA21_STATE_TRANSITION_H_
