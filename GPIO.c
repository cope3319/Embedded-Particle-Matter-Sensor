

#include "msp.h"
#include "gpio.h"

void config_uart_gpio(void){
    P3->DIR |= 0b0001100; //Direction out for pins 3.2/3.3
    P3->SEL0 |= 0b00001100;//sets 
    P3->SEL1 &= ~(0b00001100);//sets 
}

void LCD_PinConfig(){
    //Initialize Pins to out
    P2->DIR |= 0b1011000;// RS,RW,D5
    P5->DIR |= 0b1000010;// E,D4
    P6->DIR |= 0b11000000;// D6,D7
    
}