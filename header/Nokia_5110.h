/* Nokia 5110 LCD AVR Library
 *
 * Copyright (C) 2015 Sergey Denisov.
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * Original library written by SkewPL, http://skew.tk
 *
 * Edited by -> Dan Murphy ; dmurp006@ucr.edu
 */

#ifndef __NOKIA_5110_H__ /* Wrap __NOKIA_5110_H__ within the scope */
#define __NOKIA_5110_H__ /* If not defined, will be wrapped __NOKIA_5110_H__ within the scope */

// Libraries ------------
#include <avr/pgmspace.h>
#include <stdint.h>

// LCD's port --------
#define PORT_LCD PORTD //changed from B to D
#define DDR_LCD DDRD

// LCD's pins ------------------------
#define LCD_SCE PD1 /* Chip Enable  */
#define LCD_RST PD2 /* Reset        */
#define LCD_DC  PD3 /* Data/Command */
#define LCD_DIN PD4 /* Data Input   */
#define LCD_CLK PD5 /* Serial Clock */

#define LCD_CONTRAST 0x40

/* =======================================
 * >>> NOKIA 5110 PINOUT DOCUMENTATION <<<
 * =======================================
 *
 * RST -> pin resets the display. It's an
 *		  active low pin meaning you can
 *	      reset the display by pulling it low.
 *
 * CE  -> (Chip Enable) pin is used to select
 *		  one of many connected devices sharing
 *		  the same SPI bus. It's an active low
 *		  pin as well.
 *
 * DC  -> (Data Command) pin tells the display
 *		  whether the data it's receiving is
 *		  a command or displayable data.
 *
 * DIN -> is a serial data pin for SPI interface.
 *
 * CLK -> is a serial clock pin for SPI interface.
 *
 * VCC -> pin supplies power for the LCD.
 *
 * BL  -> (Backlight) pin controls the backlight of
 *		  the display. To control its brightness,
 *		  connect a potentiometer.
 *
 * GND -> should be connected to the ground of the
 *		  board/IEEE module.
 */

/*
 * Must be called once before any other function, initializes display
 */
void nokia_lcd_init(void);

/*
 * Clear screen
 */
void nokia_lcd_clear(void);

/**
 * Power of display
 * @lcd: lcd nokia struct
 * @on: 1 - on; 0 - off;
 */
void nokia_lcd_power(uint8_t on);

/**
 * Set single pixel
 * @x: horizontal pozition
 * @y: vertical position
 * @value: show/hide pixel
 */
void nokia_lcd_set_pixel(uint8_t x, uint8_t y, uint8_t value);

/**
 * Draw single char with 1-6 scale
 * @code: char code
 * @scale: size of char
 */
void nokia_lcd_write_char(char code, uint8_t scale);

/**
 * Draw string. Example: writeString("abc",3);
 * @str: sending string
 * @scale: size of text
 */
void nokia_lcd_write_string(const char *str, uint8_t scale);

/**
 * Set cursor position
 * @x: horizontal position
 * @y: vertical position
 */
void nokia_lcd_set_cursor(uint8_t x, uint8_t y);

/*
 * Render screen to display
 */
void nokia_lcd_render(void);

/*
Added myself to access cursor value
*/
uint8_t get_x(void);
uint8_t get_y(void);
void nokia_lcd_set_block_end(uint8_t x, uint8_t y);
void nokia_lcd_set_block_start(uint8_t x, uint8_t y);
void nokia_lcd_set_rect_end(uint8_t x, uint8_t y);
void nokia_lcd_set_rect_start(uint8_t x, uint8_t y);
uint8_t get_block_start_x();
uint8_t get_block_end_x();
uint8_t get_block_y();
uint8_t get_rect_start_x();
uint8_t get_rect_end_x();
uint8_t get_rect_y();
#endif /* ! __NOKIA_5110_H__ */

