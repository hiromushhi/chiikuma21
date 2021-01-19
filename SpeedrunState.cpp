#include "SpeedrunState.h"

SpeedrunState::SpeedrunState() {
  wheels_ = new Wheels();
  color_meter_ = new ColorMeter();
  linetrace_mode_ = new LinetraceMode(wheels_, color_meter_);
  ev3_sensor_config(touch_sensor_, TOUCH_SENSOR);
}

SpeedrunState::~SpeedrunState() {
  wheels_->Stop();
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
