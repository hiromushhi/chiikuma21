#ifndef CHIIKUMA21_PARAMETER_H_
#define CHIIKUMA21_PARAMETER_H_

#include "ev3api.h"
#include "driving.h"

struct SectionParam {
  Edge edge;
  SectionType sect_type;
  int8_t velocity;
  ConditionType cond_type;
};

struct ScenarioParam {
  const char* name;
  SectionParam* section_params;
};

#endif  // CHIIKUMA21_PARAMETER_H_
