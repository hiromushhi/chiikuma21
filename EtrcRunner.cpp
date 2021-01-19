#include "EtrcRunner.h"

EtrcRunner::EtrcRunner() {
  wheels_ = new Wheels();
  linetrace_mode_ = new LinetraceMode(wheels_);
  ev3_sensor_config(touch_sensor_, TOUCH_SENSOR);
}

EtrcRunner::~EtrcRunner() {
  delete linetrace_mode_;
  linetrace_mode_ = NULL;
  delete wheels_;
  wheels_ = NULL;
}

void EtrcRunner::Run() {
  static bool is_pushed = false;

  if (ev3_touch_sensor_is_pressed(touch_sensor_)) {
    is_pushed = true;
  }

  if (is_pushed) {
    linetrace_mode_->Exec();
  }
}
