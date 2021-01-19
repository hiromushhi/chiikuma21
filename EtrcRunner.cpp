#include "EtrcRunner.h"

#include "ev3api.h"
#include "SpeedrunState.h"

EtrcRunner::EtrcRunner() {
  curr_state_ = new SpeedrunState();
}

EtrcRunner::~EtrcRunner() {
  delete curr_state_;
  curr_state_ = NULL;
}

void EtrcRunner::Run() {
  State* next_state = curr_state_->Update();
  if (curr_state_ != next_state) {
    curr_state_ = next_state;
  }
}
