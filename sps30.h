#ifndef SPS30_H
#define SPS30_H

#include "sps30.h"
#include "sensiron_shdlc.h"
#include "uart.h"

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

#endif // SPS30.H