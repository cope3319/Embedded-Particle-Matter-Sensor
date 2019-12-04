#include "msp.h"
#include "sensirion_shdlc.h"
#include "sps30UART.h"
#include "gpio.h"
#include "Timer.h"
#include "sps30.h"
#include <stdio.h>
#include "LCD.h"

/**
 * main.c
 */

volatile uint8_t dataEx[256];
volatile uint8_t lastVar;
volatile uint16_t countEx = 0;

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
    config_uart_gpio();
	
    struct sps30_measurement m;
    char serial[SPS30_MAX_SERIAL_LEN];
    const uint8_t AUTO_CLEAN_DAYS = 4;
    int16_t ret;

    while (config_sps_uart() != 0) {
        printf("UART init failed\n");
        sps_sleep(1000000); /* sleep for 1s */
    }

    /* Busy loop for initialization, because the main loop does not work without
     * a sensor.
     */
   while (sps30_probe(serial) != 0) {
       printf("SPS30 sensor probing failed\n");
       sps_sleep(1000000);
   }
   printf("SPS30 sensor probing successful\n");
   printf("SPS30 Serial: %s\n", serial);

   ret = sps30_set_fan_auto_cleaning_interval_days(AUTO_CLEAN_DAYS);
   if (ret)
       printf("error %d setting the auto-clean interval\n", ret);

    ret = sps30_start_measurement();
    if (ret < 0)
        printf("error starting measurement\n");
    printf("measurements started\n");

    do {
        ret = sps30_read_measurement(&m);
        if (ret < 0) {
            printf("error reading measurement, error: %d \n", ret);

        } else {
            if (SPS30_IS_ERR_STATE(ret)) {
                printf("Chip state: %u - measurements may not be accurate\n",
                       SPS30_GET_ERR_STATE(ret));
            }
            printf("measured values:\n"
                    "\t%0.2f pm1.0\n"
                    "\t%0.2f pm2.5\n"
                    "\t%0.2f pm4.0\n"
                    "\t%0.2f pm10.0\n"
                    "\t%0.2f nc0.5\n"
                    "\t%0.2f nc1.0\n"
                    "\t%0.2f nc2.5\n"
                    "\t%0.2f nc4.5\n"
                    "\t%0.2f nc10.0\n"
                    "\t%0.2f typical particle size\n\n",
                    m.mc_1p0, m.mc_2p5, m.mc_4p0, m.mc_10p0, m.nc_0p5, m.nc_1p0,
                    m.nc_2p5, m.nc_4p0, m.nc_10p0, m.typical_particle_size);
        }

           delay_ms(1000000); /* sleep for 1s */
    } while (1);


LCD_PinConfig();
	initialize_LCD();
	//LCD_off();
char p1[] = "P1=";
char p2[] = "P2=";
char p3[] = "P3=";
char p4[] = "P4=";
delay_ms(10);
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
