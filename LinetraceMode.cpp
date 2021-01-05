#include "LinetraceMode.h"

LinetraceMode::LinetraceMode(Wheels* wheels) {
  wheels_ = wheels;
}

LinetraceMode::~LinetraceMode() {
}

void LinetraceMode::exec() {
  wheels_->control(15, 15);
}
