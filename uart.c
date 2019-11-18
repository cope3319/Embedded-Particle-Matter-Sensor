/* Connor's first attempt on UART Driver
    -> Reference from uart base implementation layout
*/ 

#include "uart.h"

//imitialize UART communication
int16_t uart_init() {
    // maybe?
    return 0;
}


// enc UART communication
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