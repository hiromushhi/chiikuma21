#ifndef CHIIKUMA21_ETRCRUNNER_H_
#define CHIIKUMA21_ETRCRUNNER_H_

#include "State.h"

class EtrcRunner {
 public:
  EtrcRunner();
  ~EtrcRunner();
  void Run();

 private:
  State* curr_state_;
};

#endif  // CHIIKUMA21_ETRCRUNNER_H_
