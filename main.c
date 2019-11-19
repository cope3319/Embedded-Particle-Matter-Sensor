#include "msp.h"


/**
 * main.c
 
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	uint32_t CleanInterval = 18000;//18000 seconds = 5 hours //need clean interval integer and when we read it pass its address
	int16_t err = 0;
	char serial[32];
	char article_code[32];
	char product_name[32];
	err = sps_write_auto_clean_int(CleanInterval);
}
*/