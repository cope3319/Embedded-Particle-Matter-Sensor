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
int config_sps_uart(void){
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Setting software reset enable

    //uart settings config
    EUSCI_A0->CTLW0 |= (EUSCI_A_CTLW0_MODE_0 |  // select UART mode
                        EUSCI_A_CTLW0_UCSSEL_2); // select SMCLK
    //baud rate config
    EUSCI_A0->BRW = 8; //clock prescaler
    EUSCI_A0->MCTLW |= (EUSCI_A_MCTLW_BRS_MASK & 0xD600); //set secondModReg to 214 (0xD6)

    EUSCI_A0->CTLW0 &= ~(EUSCI_A_CTLW0_SWRST); // Clear software reset

    EUSCI_A0->IE |= 0b11; // Transmit, and Recieve interrupt enabled
    EUSCI_A0->IFG = 0;      // Clear all EUSCI_A0 interrupts
    return 0;
}

void sps_uart_send(uint16_t len, uint8_t *data){
    uint16_t count = 0;
    while(count <= len){
        while(EUSCI_A0->IFG < 2); // wait for transmit interrupt flags to clear
        EUSCI_A0->TXBUF = data[count]; //store data in TX buffer
        count++;
    }
}

uint8_t sps_uart_recieve(uint16_t max_data_len, uint8_t *data){
    uint16_t count = 0;
    uint8_t lastVar = 0;
    while((count < max_data_len)|((lastVar = 0x7E && count != 1))){
        while(EUSCI_A0->IFG == 0b1); // wait for interrupt flags to clear
        data[count] = EUSCI_A0->RXBUF;
        lastVar = data[count]; //to check for indicator last bit
        count++;
    }
    
    return count; // return number of bits recieved
}

void sps_sleep(uint32_t useconds) {
    int ticks = useconds * 3; 
    int i = 0;
    while(i<=ticks) i++;
}

