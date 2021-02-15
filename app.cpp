#include "app.h"

#include "ev3api.h"

void initialize() {
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
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
}
