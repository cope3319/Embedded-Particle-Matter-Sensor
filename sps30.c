#include "sps30.h"
#include "sensirion_shdlc.h"


#define SPS_ADDRESS 0x00 //Address of SPS30 PMS
// SPS30 Commands from datasheet
#define SPS_DEV_INFO                        0xD0 // Device information
#define SPS_MEASURE_START                   0x00 // Start Measurement
#define SPS_MEASURE_STOP                    0x01 // Stop Measurement
#define SPS_MEASURE_READ                    0x03 // Read Measurement
#define SPS_FAN_SPEED                       0x40 // Read Fan Speed
#define SPS_FANCLEAN_INT                    0x80 // Read/Write Auto Cleaning interval
#define SPS_START_FANCLEAN                  0x56 // Start fancleaning
#define SPS_RESET                           0xD3 // Reset the SPS30
#define SUB_CMD_START                       {0x01, 0x03} //Start subcommand
#define SUB_CMD_READ_AUTO_CLEAN_INT         0x00
#define SUB_CMD_WRITE_AUTO_CLEAN_INT        0x00
#define SUB_CMD_SERIAL_NUMBER               0x03
#define SUB_CMD_ARTICLE_CODE                0x02
#define SUB_CMD_PRODUCT_NAME                0x01


int16_t start_measurement(){
    struct sensirion_shdlc_rx_header rx_header;
    uint8_t strt = SUB_CMD_START;
    return sensirion_shdlc_xvc(SPS_ADDRESS, SPS_MEASURE_START, sizeof(strt) ,strt , 0 , &rx_header , NULL);

}

int16_t stop_measurment(){
    struct sensirion_shdlc_rx_header rx_header;
    return sensirion_shdlc_xvc(SPS_ADDRESS, SPS_MEASURE_STOP,0, NULL,0,&rx_header, NULL);
}

int16_t sps_reset(){
    return sensirion_shdlc_tx(SPS_ADDRESS, SPS_RESET,0, NULL);
}

int16_t sps_start_cleaning(){
    struct sensirion_shdlc_rx_header rx_header;
    return sensirion_shdlc_xvc(SPS_ADDRESS, SPS_START_FANCLEAN,0, NULL,0,&rx_header, NULL);
}

int16_t sps_read_auto_clean_int(uint32_t *interval){
    struct sensirion_shdlc_rx_header rx_header;
    uint8_t sub_cmd = SUB_CMD_READ_AUTO_CLEAN_INT;
    int16_t err = 0;
    err = sensirion_shdlc_xvc(SPS_ADDRESS, SPS_FANCLEAN_INT, sizeof(sub_cmd),sub_cmd,sizeof(*interval),&rx_header, (uint8_t *)interval);

if(rx_header.state != 0)
    return rx_header.state;
}

int16_t sps_write_auto_clean_int(uint32_t interval){
    struct sensirion_shdlc_rx_header rx_header;
    uint8_t sub_cmd = SUB_CMD_READ_AUTO_CLEAN_INT;
    uint8_t length[5];
    length[1] = sub_cmd;
    uint8_t val = be32_to_cpu(interval);
    int i;
    for(i = 1; i <= 4; i++){
        length[i] = (uint8_t)(val << (i*8));
    }
    
    return sensirion_shdlc_xvc(SPS_ADDRESS, SPS_FANCLEAN_INT, sizeof(length),(const uint8_t *)length/*pointer to data*/,sizeof(interval),&rx_header,(uint8_t *) &interval/*pointer to the address of interval*/); //use pointer so we can use interval in other places
}


int16_t sps_read_measurements(){
struct sensirion_shdlc_rx_header rx_header;
uint32_t data[10];
uint32_t val;
int16_t err;
err = sensirion_shdlc_xvc(SPS_ADDRESS, SPS_MEASURE_READ,0,NULL,sizeof(data),&rx_header,(uint8_t *) data);

if(err != 0)
return err;

if(sizeof(data) != rx_header.data_len){
    //error message here
}

if(rx_header.state != 0)
    return rx_header.state;

val = be32_to_cpu(data[0]);
measurements.mP1 = (float32_t)val;
val = be32_to_cpu(data[1]);
measurements.mP2 = (float32_t)val;
val = be32_to_cpu(data[2]);
measurements.mP3 = (float32_t)val;
val = be32_to_cpu(data[3]);
measurements.mP4 = (float32_t)val;
val = be32_to_cpu(data[4]);
measurements.nP0 = (float32_t)val;
val = be32_to_cpu(data[5]);
measurements.nP1 = (float32_t)val;
val = be32_to_cpu(data[6]);
measurements.nP2 = (float32_t)val;
val = be32_to_cpu(data[7]);
measurements.nP3 = (float32_t)val;
val = be32_to_cpu(data[8]);
measurements.nP4 = (float32_t)val;
val = be32_to_cpu(data[9]);
measurements.typ_part_size = (float32_t)val;

return 0;

}

int16_t get_serial_number(char * serial){
    struct sensirion_shdlc_rx_header rx_header;
    int16_t err = 0;
    uint8_t sub_cmd = SUB_CMD_SERIAL_NUMBER;

err = sensirion_shdlc_xvc(SPS_ADDRESS, SPS_DEV_INFO,sizeof(sub_cmd),sub_cmd,32,&rx_header,(uint8_t *) serial);

if(err != 0)
return err;

if(rx_header.state != 0)
return rx_header.state;

return 0;
}

int16_t get_article_code(char * article_code){
    struct sensirion_shdlc_rx_header rx_header;
    int16_t err = 0;
    uint8_t sub_cmd = SUB_CMD_ARTICLE_CODE;

err = sensirion_shdlc_xvc(SPS_ADDRESS, SPS_DEV_INFO,sizeof(sub_cmd),sub_cmd,32,&rx_header,(uint8_t *) article_code);

if(err != 0)
return err;

if(rx_header.state != 0)
return rx_header.state;

return 0;
}

int16_t get_product_name(char * product_name){
    struct sensirion_shdlc_rx_header rx_header;
    int16_t err = 0;
    uint8_t sub_cmd = SUB_CMD_PRODUCT_NAME;

err = sensirion_shdlc_xvc(SPS_ADDRESS, SPS_DEV_INFO,sizeof(sub_cmd),sub_cmd,32,&rx_header,(uint8_t *) product_name);

if(err != 0)
return err;

if(rx_header.state != 0)
return rx_header.state;

return 0;
}