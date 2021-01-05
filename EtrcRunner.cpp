#include "EtrcRunner.h"

EtrcRunner::EtrcRunner() {
  line_tracer_ = new LineTracer();
}

EtrcRunner::~EtrcRunner() {
  delete line_tracer_;
}

void EtrcRunner::update() {
  line_tracer_->run();
}
