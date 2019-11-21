#ifndef SPS30_H
#define SPS30_H

#include "sps30.h"
#include "sensirion_shdlc.h"
#include "uart.h"

#define noParity   0x0000;
#define LSBfirst   0x0000;
#define bits8      0x0000;
#define oneStopBit 0x0000;
#define uartMode   0x0000;
#define async      0x0000;
#define SMCLKsel   0x0080;
#define baudScaler 0x2B; //5M / 115200 ~ 43
#define baudDec 0x9200; //for .40

#endif // SPS30.H
