#include "SpeedrunState.h"

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
