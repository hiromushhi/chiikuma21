#ifndef CHIIKUMA21_ETRC_INFO_H_
#define CHIIKUMA21_ETRC_INFO_H_

#include "ev3api.h"
#include "device_io.h"

struct Hsv {
  float h;
  float s;
  float v;
};

enum Color {
  kGreen = 0,
  kBlack,
  kRed,
  kYellow,
  kBlue,
  kWhite,
  kNone,
  kColorNum
};

class SelfLocalization {
 public:
  void Update();
};

class LightEnvironment {
 public:
  LightEnvironment(SensorIo* sensor_io);
  void Update();
  void SetColorReference(Color c, Hsv data);
  Color GetColor();

 private:
  void UpdateHsv(rgb_raw_t val);
  void UpdateColor();
  SensorIo* sensor_io_;
  Hsv curr_hsv_;
  Hsv color_ref_[kColorNum];
  Color curr_color_;
};

class VehicleSpeed {
 public:
  void Update();
};

#endif  // CHIIKUMA21_ETRC_INFO_H_
