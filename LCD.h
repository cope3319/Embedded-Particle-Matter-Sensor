/*
 * LCD.h
 *
 *  Created on: Nov 14, 2019
 *      Author: Kanin
 */

#ifndef LCD_H_
#define LCD_H_

#include "msp.h"
#include <string.h>
#include <stdio.h>
#include "Timer.h"
#include "GPIO.h"
typedef float float32_t;



void    initialize_LCD();
void    bitset();
void    twoline();
void    LCD_on();
void    clear();
void    entrymode();
void    toggleE();
void    LCD_off();
void write_data(char measured);
void write_cmd(char cmd);
void write(char* data, int x, int y);
void convert(char val);


#endif /* LCD_H_ */
