#include "behavior.h"

Scenario::Scenario() {
  Section* s;
  s = new LinetraceSection();
  sections_.push_back(s);
}

void Scenario::Exec() {
}

bool Scenario::IsCompleted() {
  return false;
}

ScenarioMaker::ScenarioMaker() {
  Scenario* s;
  s = new Scenario();
  scenarios_.push_back(s);
}

bool ScenarioMaker::HasNextScenario() {
  return false;
}

Scenario* ScenarioMaker::GetNextScenario() {
  return NULL;
}

StateManager::StateManager() {
  scenario_maker_ = new ScenarioMaker();
  current_scenario_ = NULL;
}

StateManager::~StateManager() {
  delete scenario_maker_;
}

void StateManager::Exec() {
  if (current_scenario_ == NULL) {
    if (scenario_maker_->HasNextScenario()) {
      current_scenario_ = scenario_maker_->GetNextScenario();
    }
  } else {
    current_scenario_->Exec();
    if (current_scenario_->IsCompleted()) {
      current_scenario_ = NULL;
    }
  }
}
