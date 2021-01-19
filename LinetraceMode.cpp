#include "LinetraceMode.h"

LinetraceMode::LinetraceMode(Wheels* wheels) {
  wheels_ = wheels;
}

LinetraceMode::~LinetraceMode() {
}

void LinetraceMode::Exec() {
  wheels_->Control(15, 15);
}
