#ifndef CHIIKUMA21_PARKSTOP_H_
#define CHIIKUMA21_PARKSTOP_H_

#include "ev3api.h"
#include "State.h"

class ParkstopState : public State {
 public:
  ParkstopState();
  ~ParkstopState();
  State* Update();

 private:
};

#endif  // CHIIKUMA21_PARKSTOP_H_
