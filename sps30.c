#include "sps30.h"
#include "sensiron_shdlc.h"
#include "uart.h"


#define SPS_ADDRESS 0x00 //Address of SPS30 PMS
// SPS30 Commands from datasheet
#define SPS_MEASURE_START      0x00 // Start Measurement
#define SPS_MEASURE_STOP       0x01 // Stop Measurement
#define SPS_MEASURE_READ       0x03 // Read Measurement
#define SPS_FAN_SPEED          0x40 // Read Fan Speed
#define SPS_FANCLEAN_INT       0x80 // Read/Write Auto Cleaning interval
#define SPS_START_FANCLEAN     0x56 // Start fancleaning
#define SPS_RESET              0xd3 // Reset the SPS30
#define UART_MODE              0x0100
#define SMCLK                  0x00C0
#define UC8BIT                 0x1000
#define UCPEN                  0x8000
#define UCSPB                  0x0800

#define noParity   0x0000;
#define LSBfirst   0x0000;
#define bits8      0x0000;
#define oneStopBit 0x0000;
#define uartMode   0x0000;
#define async      0x0000;
#define SMCLKsel   0x0080;
#define baudScaler 0x2B; //5M / 115200 ~ 43
#define baudDec 0x9200; //for .40


const EUSCI_config spsConfig = {
    EUSCI_config config;
    config.parityEN = noParity;
    config.MSB = LSBfirst;
    config.bits = bits8;
    config.stopBit = oneStopBit;
    config.eUSCImode = noParity;
    config.synch = noParity;
    config.clockSel = noParity;
    config.baudN = baudScaler;
    config.baudE = baudDec;
}

void sps30_send_data(uint8_t * data) {
 

}


void send_byte(uint8_t byte) {
    eUSCI_A -> TXBUF = byte;
}
