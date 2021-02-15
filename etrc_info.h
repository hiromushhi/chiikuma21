#ifndef CHIIKUMA21_ETRC_INFO_H_
#define CHIIKUMA21_ETRC_INFO_H_

#include "ev3api.h"

struct Hsv {
  uint16_t h;
  uint16_t s;
  uint16_t v;
};

enum Color {
  kGreen = 0,
  kBlack,
  kRed,
  kYellow,
  kBlue,
  kWhite,
  kColorNum
};

class SelfLocalization {
 public:
  void Update();
};

class LightEnvironment {
 public:
  void Update();
  void SetColorReference(Color c, Hsv data);
  Color GetColor();

 private:
  Hsv curr_hsv_;
  Hsv color_ref_[kColorNum];
  Color curr_color_;
};

class VehicleSpeed {
 public:
  void Update();
};

#endif  // CHIIKUMA21_ETRC_INFO_H_
