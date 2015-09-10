/*
 * i2c_lcd.h
 *
 *  Created on: 10-Sep-2015
 *      Author: ipv1
 */

#ifndef I2C_LCD_H_
#define I2C_LCD_H_

// My Stuff for the LCD
#define LCD_ADDR 0x3e
#define MSEC_VAL 15000

// LCD Routines
void lcd_init(void);
void lcd_clear(void);
void lcd_setpos(char ln, char idx);
void lcd_print(char* str);

#endif /* I2C_LCD_H_ */
