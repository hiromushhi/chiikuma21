#ifndef CHIIKUMA21_GAMEPLAY_H_
#define CHIIKUMA21_GAMEPLAY_H_

#include "ev3api.h"
#include "State.h"

class GameplayState : public State {
 public:
  GameplayState();
  ~GameplayState();
  State* Update();

 private:
};

#endif  // CHIIKUMA21_GAMEPLAY_H_
