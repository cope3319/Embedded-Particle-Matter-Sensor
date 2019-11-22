

#include "msp.h"
#include "gpio.h"

void config_uart_gpio(void){
    P3->DIR |= 0b0001100; //Direction out for pins 3.2/3.3
    P2->SEL0 |= 0b00001100;//sets selection register value for P2.4
    P2->SEL1 &= ~(0b00001100);//sets selection register value for P2.4
}