#include "ev3api.h"
#include "app.h"
#include "etroboc_ext.h"

void main_task() {
  ev3_led_set_color(LED_ORANGE);

  while (true) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
      break;
    }
  }
  ev3_led_set_color(LED_GREEN);

  ext_tsk();
}
