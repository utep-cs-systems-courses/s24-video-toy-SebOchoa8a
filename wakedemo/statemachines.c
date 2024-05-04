#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"

void next_state(int state) {
  unsigned int color;
  switch(state) {

  case 1:
    color = COLOR_RED;
    change_eye_color(color);
    makeFace();
    green_off();
    red_on();
    green_on();
    mario_jingle();
    green_off();
    break;

  case 2:
    flash(3);
    green_on();
    green_off();
    red_off();
    break;

  case 3:

    red_off();
    green_on();
    green_off();
    break;

  default:
    green_on();
    break;
  }

  // Turn on the green led to indicate it's ready for the next step.
  green_on();

}
