#include "app.h"

#include "ev3api.h"
#include "EtrcRunner.h"

EtrcRunner* etrc_runner = NULL;

void initialize() {
  etrc_runner = new EtrcRunner();
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
  delete etrc_runner;
  ev3_led_set_color(LED_GREEN);
}

void main_task() {
  initialize();

  while (true) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
      break;
    }
    etrc_runner->update();
  }

  finalize();
  ext_tsk();
}
