# Particulate Matter Sensor Project

This project was done for our ECEN 2440 Embedded Systems Final Project. Our goal was to use the MSP432 Microcontroller, along with the SPS30 Particulate Matter Sensor and an LCD screen, to create a mobile air quality unit. 

## Breakdown

Provided by Sensirion:
* sensirion_shdlc.c
* sensirion_shdlc.h - Sensirion's frame layer for UART/I2C Communication
* sensirion_arch_config.h
* sps30.c -- This was modified by us to call our UART functions, rather than ones provided by an alternate UART code provided by Sensirion. 
* sps30.h 

Written by Us:
* gpio.h/gpio.c - Basic pin setup functions
* LCD.h/LCD.c - Functions for interaction with 16x2 LCD screen.
* main.c - Indefinetely runs a script to read from the SPS30 and print the values to the LCD screen on interval.
* sps30UART.h/sps30UART.c - UART functions specific to the MSP432 Microcontroller, optimized to work with the sensirion sps30.c functions
* timer.h/timer.c - functions to implement delays for the main code. 


## Authors

* **Connor Peskin** - connor.peskin@colorado.edu - [GitHub](https://github.com/cope3319)
* **Kanin McGuire** - kanin.mcguire@colorado.edu - [GitHub](https://github.com/KaninMcGuire)
* **Samuel Diaz** - samuel.diaz@colorado.edu - [GitHub](https://github.com/samueldiaz970)


See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## Acknowledgments

* Sensirion for their frame layer and basic SPS30 command code.

