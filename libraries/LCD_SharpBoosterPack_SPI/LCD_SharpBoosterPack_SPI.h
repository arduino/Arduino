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
//  Edited 2015-07-11 by ReiVilo
//  Added setOrientation(), setReverse() and flushReverse()
//  Unchanged #include <OneMsTaskTimer.h>
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

///
/// @brief      Class for Sharp Memory Display BoosterPack
/// @details    The screen uses a buffer.
/// @note       The class doesn't manage touch.
///
class LCD_SharpBoosterPack_SPI : public Print {
public:
    ///
    /// @brief	Constructor
    ///
    LCD_SharpBoosterPack_SPI();

    ///
    /// @brief	Constructor with selected pins
    /// @param	pinChipSelect SPI chip select
    /// @param	pinDISP Display pin
    /// @param	pinVCC VCC pin
    ///
    LCD_SharpBoosterPack_SPI(uint8_t pinChipSelect, uint8_t pinDISP, uint8_t pinVCC);
    LCD_SharpBoosterPack_SPI(uint8_t pinChipSelect, uint8_t pinDISP, uint8_t pinVCC, bool autoVCOM);

    ///
    /// @brief	Initialise the screen
    ///
    void begin();

    ///
    /// @brief	Return a Who Am I string
    /// @return	Who Am I string
    ///
    String WhoAmI();

    ///
    /// @brief	Clear the screen
    ///
    void clear();

    ///
    /// @brief	Clear the buffer
    ///
    void clearBuffer();
    
    ///
    /// @brief	Set the orientation
    /// @param	orientation 0=0°, 1=90°, 2=180°, 3=-90°
    /// @note   Screen initialised at 0=0°.
    ///
    void setOrientation(uint8_t orientation = 0);

    ///
    /// @brief	Set the reverse mode
    /// @param	reverse false=silver on white, default=true=white on silver
    /// @note   Screen initialised with false=silver on white.
    ///
    void setReverse(bool reverse = true);
    
    ///
    /// @brief	Reverse and display the screen
    ///
    void reverseFlush();

    ///
    /// @brief	Set the font
    /// @param	font default=0, 0..1
    ///
    void setFont(tNumOfFontsType font=0);

    void setLineSpacing(uint8_t pixel);
    void setXY(uint8_t x, uint8_t y, uint8_t ulValue);
    void text(uint8_t x, uint8_t y, String s);
    void text(uint8_t x, uint8_t y, String s, tLCDWrapType wrap);
    void text(uint8_t x, uint8_t y, uint8_t c) ;
    void flush();
    void setCharXY(uint8_t x, uint8_t y);
    void drawImage(const uint8_t * image, uint8_t x,uint8_t y);

    virtual size_t write(uint8_t c);
    //virtual size_t write(const uint8_t *buffer, size_t size);

    using Print::write; // pull in write(str) and write(buf, size) from Print

private:
    tNumOfFontsType _font;
    void TA0_enableVCOMToggle();
    void TA0_turnOff();
    uint8_t _orientation;
    bool _reverse;
};
#endif
