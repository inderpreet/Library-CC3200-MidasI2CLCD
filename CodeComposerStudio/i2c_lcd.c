/*
 * i2c_lcd.c
 *
 *  Created on: 10-Sep-2015
 *      Author: ipv1
 */

#include "i2c_lcd.h"
#include "rom_map.h"

#ifndef true
#define true 1
#endif

extern int
I2C_IF_Write(unsigned char ucDevAddr,
         unsigned char *pucData,
         unsigned char ucLen,
         unsigned char ucStop);

extern void MAP_UtilsDelay(unsigned long ulCount);

// LCD Routines
void lcd_init(void){
	const char lcd_init_arr[]={ 0x38, 0x39, 0x14, 0x79, 0x50, 0x6c, 0x0c, 0x01 };
    int i;
    char data[2];
    data[0]=0;
    for (i=0; i<8; i++)
    {
        data[1]=lcd_init_arr[i];
        I2C_IF_Write(LCD_ADDR, (unsigned char*)data, 2, true);
    }
}


void lcd_clear(void){
    char data[2];
    data[0]=0;
    data[1]=1;
    I2C_IF_Write(LCD_ADDR, (unsigned char*)data, 2, true);
    MAP_UtilsDelay(MSEC_VAL*2);
}


void lcd_setpos(char ln, char idx){
    char data [2];
    data[0]=0;
    if (ln==0)
        data[1]=0x80+idx;  // 0x00 | 0x80
    else
        data[1]=0xc0+idx;  // 0x40 | 0x80
    I2C_IF_Write(LCD_ADDR, (unsigned char*)data, 2, true);
}


void lcd_print(char* str)
{
    char data[2];
    data[0]=0x40;
    while(*str != '\0')
    {
        data[1]=*str++;
        I2C_IF_Write(LCD_ADDR, (unsigned char*)data, 2, true);
    }
}

