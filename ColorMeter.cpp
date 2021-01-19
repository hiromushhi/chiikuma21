#include "ColorMeter.h"

ColorMeter::ColorMeter() {
  ev3_sensor_config(color_sensor_, COLOR_SENSOR);
}

ColorMeter::~ColorMeter() {
}

rgb_raw_t ColorMeter::GetRawRgb() {
  rgb_raw_t val;
  ev3_color_sensor_get_rgb_raw(color_sensor_, &val);
  return val;
}
