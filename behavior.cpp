#include "behavior.h"

Scenario::Scenario(RlTracer* rl_tracer, VlTracer* vl_tracer, OvDriver* ov_driver) {
  sec_params_.push_back((SecParam){kReal, kColor, kBlue, -1, false, false});
  sec_params_.push_back((SecParam){kVirt, kDist, kNone, 1000, false, false});

  tracer_ = NULL;
  rl_tracer_ = rl_tracer;
  vl_tracer_ = vl_tracer;
  ov_driver_ = ov_driver;
  cond_ = NULL;
  color_cond_ = new ColorCond(NULL);
  dist_cond_ = new DistCond(NULL);
}

Scenario::~Scenario() {
}

void Scenario::Exec() {
  if (sec_params_.size() > 0) {
    SecParam& sec_param = sec_params_.front();

    if (!sec_param.started) {
      SetDefault(&sec_param);
      sec_param.started = true;
    }

    ExecSection();

    if (sec_param.finished) {
      sec_params_.pop_front();
    }
  }
}

void Scenario::SetDefault(SecParam* sec_param) {
}

void Scenario::ExecSection() {
  if (tracer_ != NULL) {
    tracer_->Run();
  }
}
