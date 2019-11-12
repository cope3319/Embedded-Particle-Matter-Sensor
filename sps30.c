#include "sps30.h"
#include "sensiron_shdlc.h"


#define SPS_ADDRESS 0x00 //Address of SPS30 PMS
// SPS Commands
#define SPS_MEASURE_START      0x00 // Start Measurement
#define SPS_MEASURE_STOP       0x01 // Stop Measurement
#define SPS_MEASURE_READ       0x03 // Read Measurement
#define SPS_FAN_SPEED          0x40 // Read Fan Speed
#define SPS_FANCLEAN_INT       0x80 // Fancleaning interval set
#define SPS_FANCLEAN_INT_READ  0x00 // Read fancleaning interval
#define SPS_START_FANCLEAN     0x56 // Start fancleaning
#define SPS_RESET              0xd3 // Reset the SPS30



