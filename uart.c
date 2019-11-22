/* Connor's first attempt on UART Driver
    -> Reference from uart base implementation layout
*/ 

#include "uart.h"
#include "msp.h"



//imitialize UART communication
int16_t uart_init(const EUSCI_config config) {
    EUSCI_A -> CTLW0 |= (0x0001); // Set UCSWRST High
    //Initialize all eUSCI_A registers in one
    EUSCI_A -> CTLW0 &= ~(basicCTLW0 + config->parityEn + config->MSB + config->bits + 
                              config->stopBit + config->eUSCImode + config->sync +
                              config->clockSel); 
    if(config->baudN < 16) {
        EUSCI_A -> MCTLW = config->baudE; 
        EUSCI_A -> BRW = config->baudN;
    }
    else {
        EUSCI_A -> BRW = config->baudN;
        EUSCI_A -> MCTLW = 0b1 + config->baudE + 0x60; //oversampling enabled
    }

    EUSCI_A -> CTLW0 &= ~(0x0001); // Set UCSWRST High
    return 0;
}

/*
Transmit over UART- 
  -> len:     # of bytes to send
  -> @data:   data to send
  Returns # of bytes sent. 
*/
int16_t uart_tx(uint8_t data){
    //interrupt check
    transInt = (UCAxIE & 0b0010);
    if(transInt == 0b0010)
        while((UCAxIFG & 0b0010) == 0b0010); //wait for intterupt to clear
    UCAxTXBUF = data; //put data in tx buffer
    return 0; 
}

/*
Recieve over UART-
  -> max_len:  max # of bytes to recieve
  -> @data:    memory allocation for data
  Returns: # of bytes recieved
*/
int16_t uart_rx(uint8_t *data){
    //implement this
}

/*
Sleep for a given time- 
   -> useconds:  # of microseconds
*/
void uart_sleep(uint32_t useconds) {
    //implement this
}