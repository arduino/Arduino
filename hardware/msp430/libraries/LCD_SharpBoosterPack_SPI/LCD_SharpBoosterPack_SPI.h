//
//  Sharp BoosterPackLCD SPI
//  Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
//  Author :  Stefan Schauer
//  Date   :  Jan 29, 2014
//  Version:  1.00
//  File   :  LCD_SharpBoosterPack_SPI_main.h
//
//  Based on the LCD5110 Library
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

#ifndef LCD_SharpBoosterPack_SPI_h
#define LCD_SharpBoosterPack_SPI_h

#include "Energia.h"
#include "Terminal6.h"
#include "Terminal12.h"
#include "SPI.h"

#define LCD_VERTICAL_MAX    96
#define LCD_HORIZONTAL_MAX  96

class LCD_SharpBoosterPack_SPI {
public:
//
//
    LCD_SharpBoosterPack_SPI();
//
//
    LCD_SharpBoosterPack_SPI(uint8_t pinChipSelect, uint8_t pinDISP, uint8_t pinVCC);
    void begin();
    String WhoAmI();
    void clear();
    void clearBuffer();
    void setFont(uint8_t font=0);
    void setXY(uint8_t x, uint8_t y, uint8_t ulValue);
    void text(uint8_t x, uint8_t y, String s);
    void flush();
private:
    uint8_t _font;
	void TA0_enableVCOMToggle();
	void TA0_turnOff();
};
#endif
