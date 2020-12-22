#include "ev3api.h"
#include "app.h"
#include "etroboc_ext.h"

void initialize() {
  ev3_led_set_color(LED_ORANGE);
}

void finalize() {
  ev3_led_set_color(LED_GREEN);
}

void main_task() {
  initialize();

  while (true) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
      break;
    }
  }

  finalize();
  ext_tsk();
}
