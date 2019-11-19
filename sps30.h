#ifndef SPS30_H
#define SPS30_H

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
#endif // SPS30.H