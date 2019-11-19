#include "sps30.h"
#include "sensiron_shdlc.h"


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


void sps30Config(){
    eUSCI_A -> CTLW0 &= ~(UART_MODE);   //Set UCSYNC to Asychronous mode
    eUSCI_A -> CTLW0 |= (SMCLK);        //Set UCSSELx to SMCLK
    eUSCI_A -> CTLW0 &= ~(UC8BIT);      //Set UC7BIT to 8 bit mode
    eUSCI_A -> CTLW0 &= ~(UCPEN);       //Set UCPEN to parity disable
    eUSCI_A -> CTLW0 &= ~(UCSPB);       //Set UCSPB to one stop bit

}