/*#include "LCD.h"
#include "msp.h"
#include <string.h>
#include <stdio.h>
#include "Timer.h"
#include "GPIO.h"

/**
 * main.c
 */
/*void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//SPS_PinConfig();
	LCD_PinConfig();
	initialize_LCD();
	//LCD_off();
char p1[] = "P1=";
char p2[] = "P2=";
char p3[] = "P3=";
char p4[] = "P4=";

write(p1,0,0);
write(p2,5,0);
write(p3,0,1);
write(p4,5,1);
write("45",3,0);
write("15",8,0);
write("72",3,1);
write("0",8,1);
int i;
char number_string[3];
float lol = 7.53333322222233;
sprintf(number_string, "%2f", lol);
write(number_string,0,0);
//for(i=0;i<100;i++){
  //  write(p4,5,1);
//}

}
*/