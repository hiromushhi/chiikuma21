#ifndef CHIIKUMA21_STATE_H_
#define CHIIKUMA21_STATE_H_

class State {
 public:
  State() {}
  virtual ~State() {}
  virtual State* Update() = 0;

 private:
};

#endif  // CHIIKUMA21_STATE_H_
