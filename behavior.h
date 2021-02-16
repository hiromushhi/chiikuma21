#ifndef CHIIKUMA21_BEHAVIOR_H_
#define CHIIKUMA21_BEHAVIOR_H_

#include <vector>
using namespace std;

#include "ev3api.h"
#include "driving.h"

class Scenario {
 public:
  Scenario();
  void Exec();
  bool IsCompleted();

 private:
  const char* name_;
  Section* current_section_;
  vector<Section*> sections_;
};

class ScenarioMaker {
 public:
  ScenarioMaker();
  bool HasNextScenario();
  Scenario* GetNextScenario();

 private:
  vector<Scenario*> scenarios_;
};

class StateManager {
 public:
  StateManager();
  ~StateManager();
  void Exec();

 private:
  ScenarioMaker* scenario_maker_;
  Scenario* current_scenario_;
};

#endif  // CHIIKUMA21_BEHAVIOR_H_
