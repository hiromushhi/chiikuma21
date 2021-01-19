#include "app.h"

#include "ev3api.h"
#include "EtrcRunner.h"

EtrcRunner* etrc_runner = NULL;

void initialize() {
  etrc_runner = new EtrcRunner();
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
  delete etrc_runner;
  ev3_led_set_color(LED_GREEN);
}

void main_task() {
  initialize();
  sta_cyc(RUNNER_CYC);

  while (true) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
      break;
    }
    tslp_tsk(100*1000U);
  }

  stp_cyc(RUNNER_CYC);
  finalize();
  ext_tsk();
}

void runner_task() {
  etrc_runner->Run();
}
