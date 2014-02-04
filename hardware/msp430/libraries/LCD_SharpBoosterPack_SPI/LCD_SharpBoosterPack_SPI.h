//
// Sharp BoosterPackLCD SPI
// Example for library for Sharp BoosterPack LCD with hardware SPI
//
//
// author:  Stefan Schauer
// date:    Jan 29, 2014
// version:	1.00
//
// file:    LCD_SharpBoosterPack_SPI_main.h
//
// see	ReadMe.txt for references
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
    uint8_t fontX();
    uint8_t fontY();
    void setXY(uint8_t x, uint8_t y, uint8_t ulValue);
    void text(uint8_t x, uint8_t y, String s);
    void flush();
private:
    uint8_t _font;
	void TA0_enableVCOMToggle();
	void TA0_turnOff();
};
#endif
