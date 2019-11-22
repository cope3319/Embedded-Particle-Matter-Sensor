
// UART HEADER DRIVER CONNOR BRANCH

#ifndef UART_H
#define UART_H

#include "msp.h"


/* DECLARATIONS from MSP432 EUSCI UART page
  --> shorturl.at/drCN7
  BEGIN
*/ 
#define DEFAULT_SYNC                                            0x00
#define EUSCI_A_UART_AUTOMATICBAUDRATE_SYNC                     0x55
#define EUSCI_A_UART_NO_PARITY                                  0x00
#define EUSCI_A_UART_ODD_PARITY                                 0x01
#define EUSCI_A_UART_EVEN_PARITY                                0x02
#define EUSCI_A_UART_MSB_FIRST                                  EUSCI_A_CTLW0_MSB
#define EUSCI_A_UART_LSB_FIRST                                  0x00
#define EUSCI_A_UART_MODE                                       EUSCI_CTLW0_MODE_0
#define EUSCI_A_UART_IDLE_LINE_MULTI_PROCESSOR_MODE             EUSCI_CTLW0_MODE_1
#define EUSCI_A_UART_ADDRESS_BIT_MULTI_PROCESSOR_MODE           EUSCI_CTLW0_MODE_2
#define EUSCI_A_UART_AUTOMATIC_BAUDRATE_DETECTION_MODE          EUSCI_CTLW0_MODE_3
#define EUSCI_A_UART_CLOCKSOURCE_SMCLK                          EUSCI_A_CTLW0_SSEL_SMCLK
#define EUSCI_A_UART_CLOCKSOURCE_ACLK                           EUSCI_A_CTLW0_SSEL_ACLK
#define EUSCI_A_UART_ONE_STOP_BIT                               0x00
#define EUSCI_A_UART_TWO_STOP_BITS                              EUSCI_A_CTLW0_SPB
#define EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION           0x01
#define EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION          0x00
#define EUSCI_A_UART_RECEIVE_INTERRUPT                          EUSCI_A_IE_RXIE
#define EUSCI_A_UART_TRANSMIT_INTERRUPT                         EUSCI_A_IE_TXIE
#define EUSCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT            EUSCI_A_CTLW0_RXEIE
#define EUSCI_A_UART_BREAKCHAR_INTERRUPT                        EUSCI_A_CTLW0_BRKIE
#define EUSCI_A_UART_STARTBIT_INTERRUPT                         EUSCI_A_IE_STTIE
#define EUSCI_A_UART_TRANSMIT_COMPLETE_INTERRUPT                EUSCI_B_IE_STPIE
#define EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG                     EUSCI_A_IFG_RXIFG
#define EUSCI_A_UART_TRANSMIT_INTERRUPT_FLAG                    EUSCI_A_IFG_TXIFG
#define EUSCI_A_UART_STARTBIT_INTERRUPT_FLAG                    EUSCI_A_IFG_STTIFG
#define EUSCI_A_UART_TRANSMIT_COMPLETE_INTERRUPT_FLAG           EUSCI_A_IFG_TXCPTIFG
#define EUSCI_A_UART_LISTEN_ENABLE                              EUSCI_A_STATW_LISTEN
#define EUSCI_A_UART_FRAMING_ERROR                              EUSCI_A_STATW_FE
#define EUSCI_A_UART_OVERRUN_ERROR                              EUSCI_A_STATW_OE
#define EUSCI_A_UART_PARITY_ERROR                               EUSCI_A_STATW_PE
#define EUSCI_A_UART_BREAK_DETECT                               EUSCI_A_STATW_BRK
#define EUSCI_A_UART_RECEIVE_ERROR                              EUCSI_A_STATW_RXERR
#define EUSCI_A_UART_ADDRESS_RECEIVED                           EUSCI_A_STATW_ADDR_IDLE
#define EUSCI_A_UART_IDLELINE                                   EUSCI_A_STATW_ADDR_IDLE
#define EUSCI_A_UART_BUSY                                       EUSCI_A_STATW_BUSY
#define EUSCI_A_UART_DEGLITCH_TIME_2ns                          0x00
#define EUSCI_A_UART_DEGLITCH_TIME_50ns                         0x0001
#define EUSCI_A_UART_DEGLITCH_TIME_100ns                        0x0002
#define EUSCI_A_UART_DEGLITCH_TIME_200ns                        (0x0001 + 0x0002)

typedef struct EUSCI_config_struct {
    uint_fast16_t parityEN;
    uint_fast16_t MSB;
    uint_fast16_t bits;
    uint_fast16_t stopBit;
    uint_fast16_t eUSCImode;
    uint_fast16_t synch;
    uint_fast16_t clockSel;
    uint_fast8_t baudN;
    uint_fast8_t baudE; 
} EUSCI_config;

#define basicCTLW0 0x0007;

//imitialize UART communication
uint8_t uart_init(const EUSCI_config config);


/*
Transmit over UART- 
  -> @data:   data to send
  Returns # of bytes sent. 
*/
uint8_t uart_tx(const uint8_t *data);

/*
Recieve over UART-
  -> @data:    memory allocation for data
  Returns: # of bytes recieved
*/
int16_t uart_rx(uint8_t *data);

/*
Sleep for a given time- 
   -> useconds:  # of microseconds
*/
void uart_sleep(uint32_t useconds);

#endif /* UART_H */
