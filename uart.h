
// UART HEADER DRIVER CONNOR BRANCH

#ifndef UART_H
#define UART_H

#include "msp.h"



//imitialize UART communication
int16_t uart_init();


// end UART communication
int16_t uart_end();

/*
Transmit over UART- 
  -> len:     # of bytes to send
  -> @data:   data to send
  Returns # of bytes sent. 
*/
int16_t uart_tx(uint16_t len, const uint8_t *data);

/*
Recieve over UART-
  -> max_len:  max # of bytes to recieve
  -> @data:    memory allocation for data
  Returns: # of bytes recieved
*/
int16_t uart_rx(uint16_t max_len, uint8_t *data);

/*
Sleep for a given time- 
   -> useconds:  # of microseconds
*/
void uart_sleep(uint32_t useconds);

#endif /* UART_H */