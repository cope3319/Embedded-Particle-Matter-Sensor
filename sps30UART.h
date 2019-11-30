
// UART HEADER DRIVER FOR SPS30 PARTICULATE MATTER SENSOR

#ifndef SPS30UART_H
#define SPS30UART_H

// TODO: clear UCSYNC bit (UCAxCTLW0 bit 8)

/* Enables UART pins
  > Using:
    -> 3.2 TX
    -> 3.3 RX
*/
void sps_uart_gpio(void);

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
void config_sps_uart(void);

/* Send 8-bit data over the TX line
   > data[] array must begin and end with 0x7E bits
   > MOSI Frame: 
  [0x7E ADR CMD LEN TXDATA(0-255) CHK 0x7E]
*/
void sps_uart_send(uint8_t data[]);

/* Recieve data over the RX line
   - RETURNS: recieved bit
*/  
uint8_t sps_uart_recieve()


#endif /* sps30UART.h