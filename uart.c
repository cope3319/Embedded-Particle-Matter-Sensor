/* Connor's first attempt on UART Driver
    -> Reference from uart base implementation layout
*/ 

#include "uart.h"
#include "msp.h"



//imitialize UART communication
int16_t uart_init(const eUSCI_UART_Config *config) {
    UCAxCTLW0 = 0x0001; // Set UCSWRST High
    //Initialize all eUSCI_A registers in one
    UCAxCTLW0 = (basicCTLW0 + config->parityEn + config->MSB + config->bits + 
                              config->stopBit + config->eUSCImode + config->sync +
                              config->clockSel); 
    if(config->baudN < 16) {
        UCAxMCTLW = config->baudE; 
        UCAxBRW = config->baudN;
    }
    else {
        UCAxBRW = config->baudN;
        UCAxMCTLW = 0b1 + config->baudE + 0x60; //oversampling enabled
    }
    return 0;
}


// end UART communication
int16_t uart_end() {
    //implement here
    return 0;
}

/*
Transmit over UART- 
  -> len:     # of bytes to send
  -> @data:   data to send
  Returns # of bytes sent. 
*/
int16_t uart_tx(uint16_t len, const uint8_t *data){
    //implement this 
}

/*
Recieve over UART-
  -> max_len:  max # of bytes to recieve
  -> @data:    memory allocation for data
  Returns: # of bytes recieved
*/
int16_t uart_rx(uint16_t max_len, uint8_t *data){
    //implement this
}

/*
Sleep for a given time- 
   -> useconds:  # of microseconds
*/
void uart_sleep(uint32_t useconds) {
    //implement this
}