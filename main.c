#include "msp.h"
#include "sps30.h"
#include "sensirion_shdlc.h"
#include "GPIO.h"

//*
// * main.c
 
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	uint32_t CleanInterval = 18000;//18000 seconds = 5 hours //need clean interval integer and when we read it pass its address
	int16_t err = 0;
    //EUSCI_A0->CTLW0 |= 0b1;
    //EUSCI_A_CTLW0_SWRST;
	SPS_PinConfig();
	sps30Config();
	send_byte(0x00);
	send_byte(0x01);
	send_byte(0x00);
	send_byte(0x01);
	send_byte(0x00);
	send_byte(0x01);


	//char serial[32];
	//char article_code[32];
	//char product_name[32];
	//err = sps_write_auto_clean_int(CleanInterval);
}
