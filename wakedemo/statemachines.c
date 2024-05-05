#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"

void next_state(int state) {
  unsigned int newEyeColor;
  unsigned int newFaceColor;
  switch(state) {

  case 1:
    newEyeColor = COLOR_BLUE;
    newFaceColor = COLOR_PINK;
    makeFace(newEyeColor, newFaceColor);
    kirby_song();
    break;

  case 2:
    newEyeColor = COLOR_RED;
    newFaceColor = COLOR_BEIGE;
    makeFace(newEyeColor, newFaceColor);
    flash(3);
    mario_jingle();
    green_on();
    green_off();
    red_off();
    break;

  case 3:
    newEyeColor = COLOR_BLACK;
    newFaceColor = COLOR_BROWN;
    makeFace(newEyeColor,newFaceColor);
    break;

  case 4:
    drawString5x7(20,20, "Thank you!", COLOR_GREEN, COLOR_BLACK);
    drawDiagonalAssembly(screenHeight/2, screenWidth/2,50);
    green_on();
    red_on();
    break;

  default:
    red_on();
    green_on();
    break;
  }

  // Turn on the green led to indicate it's ready for the next step.
  green_on();

}
