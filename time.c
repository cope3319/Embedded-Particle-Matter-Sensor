/*
 * Timer.c
 *
 *  Created on: Nov 14, 2019
 *      Author: Kanin
 */
//#include "LCD.h"
#include "msp.h"
#include <string.h>
#include <stdio.h>
#include "Timer.h"
//#include "GPIO.h"
/*
extern volatile uint8_t secs = 0;
extern volatile uint8_t Tcount = 1;
extern volatile uint8_t state = 2;

//need milliseconds
void delay_ms(uint16_t period){
    period = Intperiod(period);
    state = 1;
    timerA0_config(period);

    do{

    }while(state == 1);
}
void delay_mms(uint16_t period){
    period = Intperiod(period);
    state = 4;
    timerA0_config(period);
}

void delay_s(uint16_t seconds){
    uint16_t period;
    secs = 20*seconds;
    period = Intperiod(20);
    state = 2;
    timerA0_config(period);

    do{

    }while(state == 2);

}

void delay_ss(uint16_t seconds){
    uint16_t period;
    secs = 20*seconds;
    state = 4;
    period = Intperiod(20);
    timerA0_config(period);

}

void timerA0_config(uint16_t period){
    P2->DIR |= 0b00100000;
    TIMER_A0->CCR[0] |= period; // set CCR0 to the period(50ms)
    TIMER_A0->CCTL[0] &= ~(0b0000000100000000);//set cap
    TIMER_A0->CTL |= 0b0000001010010000;//sets smclk divider by 4 and upmode
    TIMER_A0->CCTL[0] |= 0b0000000000010000;//set interrupt enabled
    NVIC_EnableIRQ(TA0_0_IRQn);//ccr0
    NVIC_SetPriority(TA0_0_IRQn, 2);//priority
}    


void TA0_0_IRQHandler(void){

    if(TIMER_A0->CCTL[0] == 0x0011 && secs == 0 && state == 1){// if interrupt flag up
        stop_pwm();
        //P2->OUT ^= BIT4;

        TIMER_A0->CCTL[0] &= ~(0x0001); // turn interrupt flag down
    }
    if(TIMER_A0->CCTL[0] == 0x0011 && secs != 0 && state == 2){// if interrupt flag up
        if(Tcount == secs){
        stop_pwm();
        Tcount = 1;
        secs = 0;

    }
    else{
        Tcount++;
        state = 2;
    }
        //P2->OUT ^= BIT4;

        TIMER_A0->CCTL[0] &= ~(0x0001); // turn interrupt flag down
    }
    if(state == 4){
    if(TIMER_A0->CCTL[0] == 0x0011 && secs == 0){// if interrupt flag up
            stop_pwm();
            //P2->OUT ^= BIT4;

            TIMER_A0->CCTL[0] &= ~(0x0001); // turn interrupt flag down
        }
        if(TIMER_A0->CCTL[0] == 0x0011 && secs != 0){// if interrupt flag up
            if(Tcount == secs){
            stop_pwm();
            Tcount = 1;
            secs = 0;

        }
        else{
            Tcount++;
        }
            //P2->OUT ^= BIT4;

            TIMER_A0->CCTL[0] &= ~(0x0001); // turn interrupt flag down
        }}
    TIMER_A0->CCTL[0] &= ~(0x0001); // turn interrupt flag down
}

void stop_pwm(void){
    //TIMER_A0->CTL &= ~(0b0000000000110000); //Turns off the counter
    TIMER_A0->CTL |= (0b0000000000000100);
    state = 0;
}
*/
