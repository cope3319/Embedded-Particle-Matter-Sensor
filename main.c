#include "msp.h"
#include "sensirion_shdlc.h"
#include "uart.h"
#include "sps30.h"


/**
 * main.c
 */
const EUSCI_config spsConfig = {
    EUSCI_config config;
    config.parityEN = noParity;
    config.MSB = LSBfirst;
    config.bits = bits8;
    config.stopBit = oneStopBit;
    config.eUSCImode = noParity;
    config.synch = noParity;
    config.clockSel = noParity;
    config.baudN = baudScaler;
    config.baudE = baudDec;
}

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	int16_t ret = 1;
	ret = uart_init(spsConfig);
	uint8_t data = 0x7A;
	ret = uart_tx(data);
	while(ret)
}
