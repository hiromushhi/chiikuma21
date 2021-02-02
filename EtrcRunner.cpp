#include "EtrcRunner.h"

#include "ev3api.h"

EtrcRunner::EtrcRunner() {
  wheels_ = new Wheels();
  color_meter_ = new ColorMeter();
  linetrace_mode_ = new LinetraceMode(wheels_, color_meter_);
  curr_state_ = new SpeedrunState(linetrace_mode_);
}

EtrcRunner::~EtrcRunner() {
  delete curr_state_;
  delete linetrace_mode_;
  delete color_meter_;
  delete wheels_;
}

void EtrcRunner::Run() {
  State* next_state = curr_state_->Update();
  if (curr_state_ != next_state) {
    curr_state_ = next_state;
  }
}
