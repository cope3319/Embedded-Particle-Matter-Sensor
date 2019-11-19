#ifndef SPS30_H
#define SPS30_H

#include <string.h>
#include <stdio.h>
#include <stdint.h>
typedef float float32_t;

struct measurements {
    float32_t mP1;
    float32_t mP2;
    float32_t mP3;
    float32_t mP4;
    float32_t nP0;
    float32_t nP1;
    float32_t nP2;
    float32_t nP3;
    float32_t nP4;
    float32_t typ_part_size;
};
struct measurements measurements;



/*
struct value {
        uint32_t int_val;
        float32_t float_val;
    }
struct value value;
*/



int16_t start_measurement();
int16_t stop_measurment();
int16_t sps_reset();
int16_t sps_start_cleaning();
int16_t sps_read_auto_clean_int(uint32_t *interval);
int16_t sps_write_auto_clean_int(uint32_t interval);
int16_t sps_read_measurements();
int16_t get_serial_number(char * serial);
int16_t get_article_code(char * article_code);
int16_t get_product_name(char * product_name);

#endif // SPS30.H