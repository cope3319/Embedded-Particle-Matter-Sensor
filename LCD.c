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
#include "gpio.h"



#define RS          PORT2 + BIT7
#define RS          PORT2 + BIT7
#define RS          PORT2 + BIT7
#define RS          PORT2 + BIT7
#define RS          PORT2 + BIT7
#define RS          PORT2 + BIT7

void initialize_LCD(){
    delay_ms(20 );//atleast 40 ms            actual 50ms
    bitset();
    delay_ms(25000);//atleast 37 us         actual 40us
    twoline();
    delay_ms(25000);//atleast 37 us         actual 40us
    twoline();
    delay_ms(25000);//atleast 37 us         actual 40us
    LCD_on();
    delay_ms(25000);//atleast 37 us         actual 40us
    clear();
    delay_ms(650);//atleast 1.52 ms         actual ~1.5384615ms
    entrymode();
}

void bitset(){//set to four bit mode
    P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT |= BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
}

void twoline(){
    P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT |= BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
    P6->OUT |= BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT &= ~BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
}

void LCD_on(){
    P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT &= ~BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
    P6->OUT |= BIT7;//D7
    P6->OUT |= BIT6;//D6
    P2->OUT |= BIT3;//D5
    P5->OUT |= BIT1;//D4
    toggleE();
}

void LCD_off(){
    P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT &= ~BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
    //P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT |= BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT |= BIT3;//D5
    P5->OUT |= BIT1;//D4
    toggleE();
}
void clear(){
    P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT &= ~BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
    //P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT &= ~BIT3;//D5
    P5->OUT |= BIT1;//D4
    toggleE();
}

void entrymode(){
    P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT &= ~BIT6;//D6
    P2->OUT &= ~BIT3;//D5
    P5->OUT &= ~BIT1;//D4
    toggleE();
    //P2->OUT &= ~BIT6;//RS
    //P2->OUT &= ~BIT4;//RW
    P6->OUT &= ~BIT7;//D7
    P6->OUT |= BIT6;//D6
    P2->OUT |= BIT3;//D5
    P5->OUT |= BIT1;//D4
    toggleE();
}

void toggleE(){
    P2->OUT |= BIT4;
    delay_ms(200000);//minimum 140 ns       actual 5us
    P2->OUT &= ~BIT4;
    
}

void write_data(char measured){
P2->OUT |= BIT6;//RS
convert(measured >> 4);//high four ([0000]0000)
toggleE();
convert(measured);//low four (0000[0000])
toggleE();
delay_ms(200000);
}

void write_cmd(char cmd){
P2->OUT &= ~BIT6;//RS
convert(cmd >> 4);//high four ([0000]0000)
toggleE();
convert(cmd);//low four (0000[0000])
toggleE();
delay_ms(200000);
}

void write(char* data, int x, int y){
    if(x<16){
        x |= 0x80;
        if(y == 1){
            x |= 0x40;
        }
    }
    write_cmd(x);

int j=0;
while(data[j]!= '\0'){
    write_data(data[j]);
    j++;
}
}

void convert(char val){
    if(val & 0b1000){
    P6->OUT |= BIT7;
    }
    else{
    P6->OUT &= ~BIT7;
    }
    if(val & 0b0100){
    P6->OUT |= BIT6;
    }
    else{
    P6->OUT &= ~BIT6;
    }
    if(val & 0b0010){
    P2->OUT |= BIT3;
    }
    else{
    P2->OUT &= ~BIT3;
    }
    if(val & 0b0001){
    P5->OUT |= BIT1;
    }
    else{
    P5->OUT &= ~BIT1;
    }
    delay_ms(10);
}

