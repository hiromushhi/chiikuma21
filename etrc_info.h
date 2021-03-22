#ifndef CHIIKUMA21_ETRC_INFO_H_
#define CHIIKUMA21_ETRC_INFO_H_

#include <math.h>
#include <vector>

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

class Luminous {
 public:
  Luminous(SensorIo* sensor_io);
  void Update();
  Color GetColor();
  Hsv GetHsv();

 private:
  void SetColorReference(Color c, Hsv data);
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

class Localize {
 public:
  Localize(MotorIo* motor_io);
  void Update();
  Posture GetPosture();
  float GetDistance();

 private:
  MotorIo* motor_io_;
  Posture posture_;
  Counts prev_counts_;
  float distance_;
  const float radius_ = 50;  // タイヤの半径 [mm]
  const float tread_ = 143;  // 左右の車輪中心間距離 [mm]
  const float dtheta_th_ = 0.001;  // dthetaが十分小さいか判定する閾値
};

class Logger {
 public:
  Logger(Localize* localize);
  ~Logger();
  void Update();

 private:
  Localize* localize_;
  std::vector<Posture> postures_;
};

#endif  // CHIIKUMA21_ETRC_INFO_H_
