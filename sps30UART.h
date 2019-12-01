
/*
   > sps30UART.h
   > Authors: Connor Peskin , Samuel Diaz, Kanin McGuire
*/

#ifndef SPS30UART_H
#define SPS30UART_H

/* Modifies UCA0CTLW0 control registar for eUSCI
   > This configures:
     -> no parity
     -> LSB first
     -> use 8 bits
     -> use 1 stop bit
     -> UART mode
     -> asynchronous communication
     -> select SMCLK (1MHz?)
     -> set baud rate to 115'200 
*/
int config_sps_uart(void);

/* Send 8-bit data over the TX line
   > data[] array must begin and end with 0x7E bits
   > MOSI Frame: 
  [0x7E ADR CMD LEN TXDATA(0-255) CHK 0x7E]
*/
void sps_uart_send(uint16_t len, uint8_t *data);

/* Recieve data over the RX line
   - RETURNS: bits recieved 
*/  
uint8_t sps_uart_recieve(uint16_t max_data_len, uint8_t *data);

// Pause for a certain time interval
void sps_sleep(uint32_t useconds);

#endif /* sps30UART.h */

