#ifndef switches_included
#define switches_included

#define SW0 BIT3
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4) /* 4 switches on the board */

extern int state_flag;

void switch_init();
char switch_update_interrupt_sense();
char switch_zero_update_interrupt_sense();
void switch_interrupt_handler();


#endif // included
