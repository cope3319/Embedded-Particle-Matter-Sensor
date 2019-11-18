/*
 * Timer.c
 *
 *  Created on: Nov 14, 2019
 *      Author: Kanin
 */
#include "LCD.h"
#include "msp.h"
#include <string.h>
#include <stdio.h>
#include "Timer.h"
#include "GPIO.h"


//need milliseconds
void delay_ms(uint16_t period){
    period = Intperiod(period);
    timerA0_config(period);
}
//need microseconds
void delay_us(uint16_t period){
    period = Intperiod(period);
    timerA0_config(period);
}

void timerA0_config(uint16_t period){
    TIMER_A0->CCR[0] |= period; // set CCR0 to the period(50ms)
    TIMER_A0->CCTL[0] &= ~(0b0000000100000000);//set cap
    TIMER_A0->CTL |= 0b0000001010010000;//sets smclk divider by 4 and upmode
    TIMER_A0->CCTL[0] |= 0b0000000000010000;//set interrupt enabled
    NVIC_EnableIRQ(TA0_0_IRQn);//ccr0
    NVIC_SetPriority(TA0_0_IRQn, 2);//priority
}

void TA0_0_IRQHandler(void){
    if(TIMER_A0->CCTL[0] == 0x0011){// if interrupt flag up
        stop_pwm();
        TIMER_A0->CCTL[0] &= ~(0x0001); // turn interrupt flag down
    }
}

void stop_pwm(void){
    //TIMER_A0->CTL &= ~(0b0000000000110000); //Turns off the counter
    TIMER_A0->CTL |= (0b0000000000000100);
}
