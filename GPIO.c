/*
 * GPIO.c
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

void SPS_PinConfig(){
    P3->DIR |= 0b1000;//Pin 3 TX output
    P3->DIR &= 0b0100;//Pin 2 RX input
    P3->SEL0 |= 0b1000 | 0b0100;
}

void LCD_PinConfig(){
    //Initialize Pins to out
    P2->DIR |= 0b1011000;// RS,RW,D5
    P5->DIR |= 0b1000010;// E,D4
    P6->DIR |= 0b11000000;// D6,D7
    
}
