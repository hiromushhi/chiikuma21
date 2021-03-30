#include "app.h"

#include "ev3api.h"
#include "device_io.h"
#include "etrc_info.h"
#include "driving.h"
#include "behavior.h"

MotorIo* motor_io;
SensorIo* sensor_io;
Localize* localize;
Luminous* luminous;
RlTracer* rl_tracer;
VlTracer* vl_tracer;
OvDriver* ov_driver;
Scenario* scenario;

void initialize() {
  motor_io = new MotorIo();
  sensor_io = new SensorIo();
  localize = new Localize(motor_io);
  luminous = new Luminous(sensor_io);
  rl_tracer = new RlTracer(luminous);
  vl_tracer = new VlTracer(localize);
  ov_driver = new OvDriver(motor_io);
  scenario = new Scenario();

  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
  delete scenario;
  delete ov_driver;
  delete vl_tracer;
  delete rl_tracer;
  delete luminous;
  delete localize;
  delete sensor_io;
  delete motor_io;

  ev3_led_set_color(LED_GREEN);
}

void main_task() {
  initialize();
  sta_cyc(UPDATE_INFO_CYC);
  tslp_tsk(10*1000U);
  sta_cyc(EXEC_ACTION_CYC);

  while (true) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
      break;
    }
    tslp_tsk(100*1000U);
  }

  stp_cyc(EXEC_ACTION_CYC);
  stp_cyc(UPDATE_INFO_CYC);
  finalize();
}

void exec_action_task() {
  scenario->Exec();
}

void update_info_task() {
  localize->Update();
  luminous->Update();
}
