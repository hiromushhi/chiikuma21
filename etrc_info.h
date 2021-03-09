#ifndef CHIIKUMA21_ETRC_INFO_H_
#define CHIIKUMA21_ETRC_INFO_H_

#include <math.h>

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

struct Posture {
  float x;
  float y;
  float theta;
};

class SelfLocalization {
 public:
  SelfLocalization(MotorIo* motor_io);
  void Update();
  Posture GetPosture();
  float GetDistance();

 private:
  MotorIo* motor_io_;
  Posture posture_;
  Count prev_count_;
  float distance_;
  const float radius_ = 50;  // タイヤの半径 [mm]
  const float tread_ = 143;  // 左右の車輪中心間距離 [mm]
  const float dtheta_th_ = 0.001;  // dthetaが十分小さいか判定する閾値
};

#endif  // CHIIKUMA21_ETRC_INFO_H_
