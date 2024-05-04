#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "notes.h"

void led_init(){

  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT &= ~LED_RED;

}



void green_on(){

  P1OUT ^= LED_GREEN;
  P1OUT &= ~LED_RED;
  __delay_cycles(5000);

}



void green_off(){

  P1OUT &= ~LED_GREEN;
  __delay_cycles(500000);

}



void red_on(){

  P1OUT ^= LED_RED;
  P1OUT &= ~LED_GREEN;

}



void red_off(){

  P1OUT &= ~LED_RED;
  __delay_cycles(500000);

}



void flash(){
  P1OUT |= LED_GREEN;
  __delay_cycles(1500000);
  P1OUT &= ~LED_RED;
  __delay_cycles(500000);
  P1OUT &= ~LED_GREEN;
  __delay_cycles(500000);
  P1OUT |= LED_RED;
  __delay_cycles(1500000);

}
