#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "notes.h"

void buzzer_init()

{
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}


void buzzer_set_period(short cycles)

{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void mario_jingle() {

  int mario_notes[] = {E4, E4, 0, E4, 0, C4, E4, 0, G4, 0, 0, 0, G3, 0, 0, 0, C4, 0, 0, G3, 0, 0, E3, 0, 0, A3, 0, B3, 0, B3, A3};

  int total_notes = sizeof(mario_notes) / sizeof(mario_notes[0]);

  for(int i = 0; i < 32; i++)
    {
      buzzer_set_period(mario_notes[i]);

      __delay_cycles(2500000);

      buzzer_set_period(0);

      __delay_cycles(250000);

    }
  
  buzzer_set_period(0);

}
