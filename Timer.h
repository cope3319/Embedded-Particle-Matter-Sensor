/*
 * Timer.h
 *
 *  Created on: Nov 14, 2019
 *      Author: Kanin
 */

#ifndef TIMER_H_
#define TIMER_H_

//#include "LCD.h"
#include "msp.h"
#include <string.h>
#include <stdio.h>
//#include "GPIO.h"

//extern volatile uint8_t secs = 0;
//extern volatile uint8_t Tcount = 1;

#define SYSTEM_CLOCK 3000000 // [Hz] system_msp432p401r.c
//#define PWM_FREQUENCY 100000 // [Hz] PWM frequency desired
#define CALC_PERIOD(X) (SYSTEM_CLOCK / X) //calc # of ticks in period
#define Intperiod(X) ((SYSTEM_CLOCK/4)/X)

void timerA0_config(uint16_t period);

void TA0_0_IRQHandler(void);
void stop_pwm(void);
void delay_ms(uint16_t period);
void delay_s(uint16_t seconds);



#endif /* TIMER_H_ */
