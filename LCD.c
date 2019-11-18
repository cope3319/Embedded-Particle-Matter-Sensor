/*
 * LCD.c
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

void initialize_LCD(){
    delay_ms(20);//atleast 40 ms
    bitset();
    delay_us(25000);//atleast 37 us
    twoline();
    delay_us(25000);//atleast 37 us
    twoline();
    delay_us(25000);//atleast 37 us
    LCD_on();
    delay_us(25000);//atleast 37 us
    clear();
    delay_us(658);//atleast 1.52 ms
    entrymode();
}

void bitset(){
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT |= BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
}

void twoline(){
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT |= BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
    P6->OUT |= BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT &= ~BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
}

void LCD_on(){
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT &= ~BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
    P6->OUT |= BIT8;//D7
    P6->OUT |= BIT7;//D6
    P2->OUT |= BIT4;//D5
    P5->OUT |= BIT2;//D4
    toggleE();
}

void LCD_off(){
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT &= ~BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT |= BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT |= BIT4;//D5
    P5->OUT |= BIT2;//D4
    toggleE();
}
void clear(){
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT &= ~BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT &= ~BIT4;//D5
    P5->OUT |= BIT2;//D4
    toggleE();
}

void entrymode(){
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT &= ~BIT7;//D6
    P2->OUT &= ~BIT4;//D5
    P5->OUT &= ~BIT2;//D4
    toggleE();
    P2->OUT &= ~BIT7;//RS
    P2->OUT &= ~BIT5;//RW
    P6->OUT &= ~BIT8;//D7
    P6->OUT |= BIT7;//D6
    P2->OUT |= BIT4;//D5
    P5->OUT |= BIT2;//D4
    toggleE();
}

void toggleE(){
    P5->OUT |= BIT7;//D4
    delay_us(200000);
    P5->OUT &= ~BIT7;//D4
    delay_us(200000);
}
