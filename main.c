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
    LCD_PinConfig();
    delay_s(5);
    initialize_LCD();
    char number_string[3];

    struct sps30_measurement m;
    struct sps30_measurement mm;
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
    else{
    printf("measurements started\n");
    }
    uint16_t screen = 0;
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

            char p1[] = "Mass1=";
            char p2[] = "#1=";
            char p3[] = "Mass2.5=";
            char p4[] = "#2.5=";
            char p5[] = "Mass4=";
            char p6[] = "#4=";
            char p7[] = "Mass10=";
            char p8[] = "#10=";
            char p9[] = "TypicalSize=";
            char p10[] = "#0.5=";
            
            if(screen == 0 && m.typical_particle_size >= 0.1 && ret != -5){
            mm = m;
            writeto(p1,0,0);
            writeto(p2,0,1);
            sprintf(number_string, "%.2f", mm.mc_1p0);
            writeto(number_string,6,0);
            sprintf(number_string, "%.2f", mm.nc_1p0);
            writeto(number_string,3,1);
            screen++;
            }
            if(screen <= 5 && m.typical_particle_size >= 0.1 && ret != -5){
            writeto(p1,0,0);
            writeto(p2,0,1);
            sprintf(number_string, "%.2f", mm.mc_1p0);
            writeto(number_string,6,0);
            sprintf(number_string, "%.2f", mm.nc_1p0);
            writeto(number_string,3,1);
            if(screen == 5)
                clear();
            screen++;
            }
            else{
            if(screen >= 6 && screen < 12 && m.typical_particle_size >= 0.1 && ret != -5){
            writeto(p3,0,0);
            writeto(p4,0,1);
            sprintf(number_string, "%.2f", mm.mc_2p5);
            writeto(number_string,8,0);
            sprintf(number_string, "%.2f", mm.nc_2p5);
            writeto(number_string,5,1);
            if(screen == 11)
                clear();
            screen++;
            }
            else{
            if(screen >= 12 && screen < 18 && m.typical_particle_size >= 0.1 && ret != -5){
            writeto(p5,0,0);
            writeto(p6,0,1);
            sprintf(number_string, "%.2f", mm.mc_4p0);
            writeto(number_string,6,0);
            sprintf(number_string, "%.2f", mm.nc_4p0);
            writeto(number_string,3,1);
            if(screen == 17)
                clear();
            screen++;
            }
            else{
            if(screen >= 18 && screen < 24 && m.typical_particle_size >= 0.1 && ret != -5){
            writeto(p7,0,0);
            writeto(p8,0,1);
            sprintf(number_string, "%.2f", mm.mc_10p0);
            writeto(number_string,7,0);
            sprintf(number_string, "%.2f", mm.nc_10p0);
            writeto(number_string,4,1);
            if(screen == 23)
                clear();
            screen++;
            }
            else{
            if(screen >= 24 && screen < 30 && m.typical_particle_size >= 0.1 && ret != -5){
            writeto(p9,0,0);
            writeto(p10,0,1);
            sprintf(number_string, "%.2f", mm.typical_particle_size);
            writeto(number_string,12,0);
            sprintf(number_string, "%.2f", mm.nc_0p5);
            writeto(number_string,5,1);
            screen++;
            }
            else{
            if(screen == 30 && m.typical_particle_size >= 0.1 && ret != -5){
            writeto(p9,0,0);
            writeto(p10,0,1);
            sprintf(number_string, "%.2f", mm.typical_particle_size);
            writeto(number_string,12,0);
            sprintf(number_string, "%.2f", mm.nc_0p5);
            writeto(number_string,5,1);
            clear();
            screen=0;
            }}}}}}
        }
           delay_ms(400);

    } while (1);

}
