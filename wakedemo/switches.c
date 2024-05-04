#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "statemachines.h"

extern int redrawScreen;
extern int eyes_state;

void switch_init()

{

  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  P1REN |= SW0;
  P1IE |= SW0;
  P1OUT |= SW0;//side button initialization
  P1DIR &= ~SW0;

}

char

switch_zero_update_interrupt_sense()

{

  char p1val = P1IN;

  /* update switch interrupt to detect changes from current buttons */

  P1IES |= (p1val & SW0);/* if switch up, sense down */

  P1IES &= (p1val | ~SW0);/* if switch down, sense up */

  return p1val;

}
char

switch_update_interrupt_sense()

{

  char p2val = P2IN;

  /* update switch interrupt to detect changes from current buttons */

  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */

  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */

  return p2val;

}

void switch_interrupt_handler()
{


  char p1val = switch_zero_update_interrupt_sense();
  char p2val = switch_update_interrupt_sense();
  char button_0 = (p1val & SW0) ? 0 : SW0;
  char button_1 = (p2val & SW1) ? 0 : SW1;
  char button_2 = (p2val & SW2) ? 0 : SW2;
  char button_3 = (p2val & SW3) ? 0 : SW3;
  char button_4 = (p2val & SW4) ? 0 : SW4;

  if (button_0)
    {
      next_state(0);
    }

  else if (button_1)
    {
      next_state(1);
    }
  else if (button_2)
    {
      next_state(2);
    }

  else if (button_3)
    {
      next_state(3);
    }

  else if(button_4)
    {
      next_state(4);
    }
}
