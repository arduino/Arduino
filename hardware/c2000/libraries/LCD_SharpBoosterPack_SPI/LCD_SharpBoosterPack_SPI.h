//
//  Sharp BoosterPackLCD SPI
//  Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
//  Author :  Stefan Schauer
//  Date   :  Mar 05, 2015
//  Version:  1.02
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
#include <SPI.h>
#include <OneMsTaskTimer.h>
#include <Print.h>

#define LCD_VERTICAL_MAX    96
#define LCD_HORIZONTAL_MAX  96


typedef enum
{
    LCDWrapNone,                         // do not wrap
    LCDWrapLine,                         // wrap, to beginning of line
    LCDWrapNextLine                      // wrap, to next line
}
tLCDWrapType;

#define NUM_OF_FONTS 2
typedef uint8_t tNumOfFontsType;

class LCD_SharpBoosterPack_SPI : public Print {
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
    void setFont(tNumOfFontsType font=0);
    void setLineSpacing(uint8_t pixel);
    void setXY(uint8_t x, uint8_t y, uint8_t ulValue);
    void text(uint8_t x, uint8_t y, String s);
    void text(uint8_t x, uint8_t y, String s, tLCDWrapType wrap);
    void text(uint8_t x, uint8_t y, uint8_t c) ;
    void flush();
    void setCharXY(uint8_t x, uint8_t y);
  
  
    virtual size_t write(uint8_t c);
    //virtual size_t write(const uint8_t *buffer, size_t size);

    using Print::write; // pull in write(str) and write(buf, size) from Print

private:
    tNumOfFontsType _font;
    void TA0_enableVCOMToggle();
    void TA0_turnOff();
};
#endif
