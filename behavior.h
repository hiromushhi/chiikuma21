#ifndef CHIIKUMA21_BEHAVIOR_H_
#define CHIIKUMA21_BEHAVIOR_H_

#include <list>

#include "etrc_info.h"
#include "driving.h"

enum Line {
  kReal = 0,
  kVirt,
  kLineNum
};

enum End {
  kColor = 0,
  kDist,
  kEndNum
};

struct SecParam {
  Line line;
  End end;
  Color color;
  float dist;
  bool started;
  bool finished;
};

class Scenario {
 public:
  Scenario(RlTracer* rl_tracer, VlTracer* vl_tracer, OvDriver* ov_driver);
  ~Scenario();
  void Exec();

 private:
  void SetDefault(SecParam* sec_param);
  void ExecSection(SecParam* sec_param);
  std::list<SecParam> sec_params_;
  Tracer* tracer_;
  RlTracer* rl_tracer_;
  VlTracer* vl_tracer_;
  OvDriver* ov_driver_;
  Cond* cond_;
  ColorCond* color_cond_;
  DistCond* dist_cond_;
};

#endif  // CHIIKUMA21_BEHAVIOR_H_
