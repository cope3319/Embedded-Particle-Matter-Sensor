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

void    initialize_LCD();
void    bitset();
void    twoline();
void    LCD_on();
void    clear();
void    entrymode();
void    toggleE();
void    LCD_off();


#endif /* LCD_H_ */
