/*
   > sps30UART.c
   > Author: Connor Peskin 
*/

#include <stdint.h>
#include "sps30UART.h"
#include "msp.h"

/*
   > Pin 3.2 - RX
   > Pin 3.3 - TX
*/

extern volatile uint8_t dataEx[256];
extern volatile uint8_t lastVar; 
extern volatile uint8_t countEx;

void EUSCIA2_IRQHandler() {
    __disable_irq();
    if(EUSCI_A2->IFG & UCRXIFG) {
        sps_uart_recieve();
    }
    __enable_irq();
}

int config_sps_uart(void){
    EUSCI_A2->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Setting software reset enable

    //uart settings config
    EUSCI_A2->CTLW0 |= (EUSCI_A_CTLW0_MODE_0 |  // select UART mode
                        EUSCI_A_CTLW0_UCSSEL_2); // select SMCLK
    //baud rate config
    EUSCI_A2->BRW = 1; //clock prescaler
    EUSCI_A2->MCTLW = 0x00A1; //set secondModReg to 0, firstModReg to 10 (A) , Oversampling ^

    EUSCI_A2->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST); // Clear software reset

    EUSCI_A2->IE |= EUSCI_A_IE_RXIE; // Recieve interrupt enabled, Transmit disabled
    NVIC_EnableIRQ(EUSCIA2_IRQn);
    return 0;
}

void sps_uart_send(uint16_t len, uint8_t *data){
    uint16_t count = 0;
    while(count < len){
        while(!(EUSCI_A2->IFG & EUSCI_A_IFG_TXIFG)); // wait for transmit interrupt flags to clear
        EUSCI_A2->TXBUF = data[count]; //store data in TX buffer
        count++;
    }
}

uint8_t sps_uart_recieve(){
    lastVar = 0;
    dataEx[countEx] = EUSCI_A2->RXBUF;
    lastVar = dataEx[countEx]; //to check for indicator last bit
    countEx++;
    
    return countEx; // return number of bits recieved
}

uint16_t data_recieved(uint8_t *data){
    uint16_t length = countEx;
    countEx = 0;
    uint16_t i = 0;
    while(i<length){
        data[i] = dataEx[i]; 
        i++;
    }
    return length;
}

void sps_sleep(uint32_t uSeconds) {
    int i;
    int ticks = uSeconds /1000;
    while (i < ticks)
        i++;
}


