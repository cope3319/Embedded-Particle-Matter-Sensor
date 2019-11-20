#include "msp.h"


/**
 * main.c
 */

# define STARTMEASUREMENT 

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	
	send_byte()
}
