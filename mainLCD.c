#include "LCD.h"
#include "msp.h"
#include <string.h>
#include <stdio.h>
#include "Timer.h"
#include "GPIO.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//SPS_PinConfig();
	LCD_PinConfig();
	initialize_LCD();
	LCD_off();
}
