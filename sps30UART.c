/*
   > sps30UART.c
   > Authors: Connor Peskin , Samuel Diaz, Kanin McGuire
*/

#include <stdint.h>
#include "sps30UART.h"
#include "msp.h"

/*
   > Pin 3.2 - TX
   > Pin 3.3 - RX
*/
void config_sps_uart(void){
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Setting software reset enable

    //uart settings config
    EUSCI_A0->CTLW0 |= (EUSCI_A_CTLW0_MODE_0 |  // select UART mode
                        EUSCI_A_CTLW0_UCSSEL_2); // select SMCLK
    //baud rate config
    EUSCI_A0->BRW = 8; //clock prescaler
    EUSCI_A0->MCTLW |= (EUSCI_A_MCTLW_BRS_MASK & 0xD600); //set secondModReg to 214 (0xD6)

    EUSCI_A0->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST); // Clear software reset

    EUSCI_A0->IE &= 0; // No interrupts enabled
    EUSCI_A0->IFG = 0; // Clear all EUSCI_A0 interrupts
}

void sps_start_measurement(){
    uin8_t data[] = {0x7E 0x00 0x02 };
}

void sps_uart_send(uint8_t data[]){
    if(EUSCI_A0->IE) // if there is enabled interrupts 
        while(EUSCI_A0->IFG); // wait for interrupt flags to clear
    
    EUSCI_A0->TXBUF = data; //store data in TX buffer
}

uint8_t sps_uart_recieve(){
    if(EUSCI_A0->IE) // if there is enabled interrupts
        while(EUSCI_A0->IFG); // wait for interrupt flags to clear

    return EUSCI_A0->RXBUF; // return 8-bit data in RX buffer
}

//thoughts- use interrupts and a for loop to gather data with a count to count
//start and last indicator bit- we can maybe get around shdlc