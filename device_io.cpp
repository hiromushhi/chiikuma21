#include "device_io.h"

SensorIo::SensorIo() {
  ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
}

rgb_raw_t SensorIo::GetRgbRaw() {
  rgb_raw_t val;
  ev3_color_sensor_get_rgb_raw(EV3_PORT_2, &val);
  return val;
}
