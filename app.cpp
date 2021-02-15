#include "app.h"

#include "ev3api.h"
#include "etrc_info.h"

SelfLocalization* self_localization;
LightEnvironment* light_environment;
VehicleSpeed* vehicle_speed;

void initialize() {
  self_localization = new SelfLocalization();
  light_environment = new LightEnvironment();
  vehicle_speed = new VehicleSpeed();

  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
  delete vehicle_speed;
  delete light_environment;
  delete self_localization;

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
}

void update_info_task() {
  self_localization->Update();
  light_environment->Update();
  vehicle_speed->Update();
}
