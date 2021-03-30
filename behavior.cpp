#include "behavior.h"

Scenario::Scenario(RlTracer* rl_tracer, VlTracer* vl_tracer, OvDriver* ov_driver) {
  sec_params_.push_back((SecParam){kReal, kColor, kBlue, -1, false, false});
  sec_params_.push_back((SecParam){kVirt, kDist, kNone, 1000, false, false});

  tracer_ = NULL;
  rl_tracer_ = rl_tracer;
  vl_tracer_ = vl_tracer;
  ov_driver_ = ov_driver;
  cond_ = NULL;
  color_cond_ = new ColorCond(rl_tracer_->luminous_);
  dist_cond_ = new DistCond(vl_tracer_->localize_);
}

Scenario::~Scenario() {
  delete dist_cond_;
  delete color_cond_;
}

void Scenario::Exec() {
  if (sec_params_.size() > 0) {
    SecParam& sec_param = sec_params_.front();
    if (!sec_param.started) {
      SetDefault(&sec_param);
      sec_param.started = true;
    }

    ExecSection(&sec_param);

    if (sec_param.finished) {
      sec_params_.pop_front();
    }
  } else {
    tracer_ = NULL;
    cond_ = NULL;
    ov_driver_->Drive(0, 0);
  }
}

void Scenario::SetDefault(SecParam* sec_param) {
  if (sec_param->line == kReal) {
    tracer_ = rl_tracer_;
  } else {
    tracer_ = vl_tracer_;
  }

  if (sec_param->end == kColor) {
    color_cond_->SetColor(sec_param->color);
    cond_ = color_cond_;
  } else {
    dist_cond_->SetDistance(sec_param->dist);
    cond_ = dist_cond_;
  }
}

void Scenario::ExecSection(SecParam* sec_param) {
  if (tracer_ != NULL && cond_ != NULL) {
    float mv = tracer_->Run();
    ov_driver_->Drive(20, mv);

    if (cond_->IsSatisfied()) {
      sec_param->finished = true;
    }
  } else {
    ov_driver_->Drive(0, 0);
  }
}
