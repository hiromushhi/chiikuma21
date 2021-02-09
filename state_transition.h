#ifndef CHIIKUMA21_STATE_TRANSITION_H_
#define CHIIKUMA21_STATE_TRANSITION_H_

#include "ev3api.h"
#include "drive_modes.h"
#include "game_strategy.h"
#include "meters.h"
#include "Wheels.h"

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

 private:
  Strategy* strategy_;
};

class ParkstopState : public State {
 public:
  ParkstopState();
  ~ParkstopState();
  State* Update();
};

#endif  // CHIIKUMA21_STATE_TRANSITION_H_
