#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

int main(void)



{

  configureClocks();
  switch_init(); // switches
  led_init(); // LED
  buzzer_init(); // Buzzer
  green_on();
  enableWDTInterrupts();

  or_sr(0x18); // CPU off, GIE on

}
