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

struct Speed {
  float l;
  float r;
  float b;
};

class VehicleSpeed {
 public:
  VehicleSpeed(MotorIo* motor_io);
  void Update();
  Speed GetSpeed();

 private:
  MotorIo* motor_io_;
  Speed speed_;
  const float dt_ = 0.01;  // app.cfgと整合する必要あり
  const float circ_ = M_PI * 100;  // タイヤの外周 [mm]
};

class SelfLocalization {
 public:
  SelfLocalization(VehicleSpeed* vehicle_speed);
  void Update();

 private:
  VehicleSpeed* vehicle_speed_;
  const float tread_ = 143;  // 左右の車輪中心間距離 [mm]
};

#endif  // CHIIKUMA21_ETRC_INFO_H_
