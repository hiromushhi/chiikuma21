#include "LinetraceMode.h"

#include "ev3api.h"

LinetraceMode::LinetraceMode(Wheels* wheels, ColorMeter* color_meter) {
  wheels_ = wheels;
  color_meter_ = color_meter;
}

LinetraceMode::~LinetraceMode() {
}

void LinetraceMode::Exec() {
  rgb_raw_t val;
  val = color_meter_->GetRawRgb();

  uint16_t g = val.g;
  uint16_t target = 20;

  if (g > target) {
    wheels_->Control(15, 0);
  } else if (g < target) {
    wheels_->Control(0, 15);
  } else {
    wheels_->Control(15, 15);
  }
}
