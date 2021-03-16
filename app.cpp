#include "app.h"

#include "ev3api.h"
#include "device_io.h"
#include "etrc_info.h"
#include "driving.h"
#include "behavior.h"

MotorIo* motor_io;
SensorIo* sensor_io;
SelfLocalization* self_localization;
LightEnvironment* light_environment;
Logger* logger;
Linetracer* linetracer;
VirtualLinetracer* virtual_linetracer;
DriveControl* drive_control;
StateManager* state_manager;

void initialize() {
  motor_io = new MotorIo();
  sensor_io = new SensorIo();
  self_localization = new SelfLocalization(motor_io);
  light_environment = new LightEnvironment(sensor_io);
  logger = new Logger(self_localization);
  linetracer = new Linetracer(light_environment);
  virtual_linetracer = new VirtualLinetracer(self_localization);
  drive_control = new DriveControl(motor_io);
  state_manager = new StateManager();

  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
  delete state_manager;
  delete drive_control;
  delete virtual_linetracer;
  delete linetracer;
  delete logger;
  delete light_environment;
  delete self_localization;
  delete sensor_io;
  delete motor_io;

  ev3_led_set_color(LED_GREEN);
}

void main_task() {
  initialize();
  sta_cyc(EXEC_ACTION_CYC);
  sta_cyc(UPDATE_INFO_CYC);

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
  state_manager->Exec();

  float mv = linetracer->Exec();
  drive_control->Exec(mv);
}

void update_info_task() {
  self_localization->Update();
  light_environment->Update();
  logger->Update();
}
