#include "state_transition.h"

SpeedrunState::SpeedrunState(LinetraceMode* linetrace_mode) {
  linetrace_mode_ = linetrace_mode;
  ev3_sensor_config(touch_sensor_, TOUCH_SENSOR);
}

SpeedrunState::~SpeedrunState() {
}

State* SpeedrunState::Update() {
  static bool is_pushed = false;
  if (ev3_touch_sensor_is_pressed(touch_sensor_)) {
    is_pushed = true;
  }

  if (is_pushed) {
    linetrace_mode_->Exec();
  }

  return this;
}

GameplayState::GameplayState() {
  strategy_ = new Strategy();
}

GameplayState::~GameplayState() {
}

State* GameplayState::Update() {
  State* state = this;

  if (strategy_->IsCompleted()) {
    state = new ParkstopState();
  } else {
    strategy_->Exec();
  }

  return state;
}

ParkstopState::ParkstopState() {
}

ParkstopState::~ParkstopState() {
}

State* ParkstopState::Update() {
  return this;
}
