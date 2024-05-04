#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "wakedemo.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "statemachines.h"
#include "switches.h"
#include "notes.h"
#include "wakedemo.c"

extern short redrawScreen;

int main(void)
{
  configureClocks();
  switch_init(); // switches
  led_init(); // LED
  buzzer_init(); // Buzzer
  green_on();
  enableWDTInterrupts();

  short redrawScreen = 1;

  unsigned int color = COLOR_BLACK;

  makeFace(color);
  
  while(1)
    {
      if(redrawScreen)
	{
	  redrawScreen = 0;
	  makeFace(COLOR_GREEN);
	  
      }
      or_sr(0x10);
    }   
}

void wdt_c_handler()
{
  unsigned char color;
  if (switches & SW3) color = COLOR_BLUE;
  if (switches & SW2) color = COLOR_PINK;
  if (switches & SW1) color = COLOR_RED;
  if (switches & SW4) return;
  makeFace(color);
}
