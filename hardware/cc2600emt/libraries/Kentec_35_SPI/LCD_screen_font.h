///
/// @file       LCD_screen_font.h
/// @brief      Class library header
/// @detailsGeneric LCD with font class library
/// @n
/// @n @b       Project LCD_screen_font_main
/// @n @a       Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author     Rei VILO
/// @author     embedXcode.weebly.com
/// @date       Dec 10, 2013
/// @version114
///
/// @copyright  (c) Rei VILO, 2010-2016 - SPECIAL EDITION FOR ENERGIA
/// @copyright  All rights reserved
/// @n          http://embeddedcomputing.weebly.com/lcd_screen-library-suite
///
/// @n  Dual license:
/// *   For hobbyists and for personal usage: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
/// *   For professionals or organisations or for commercial usage: All rights reserved
///
/// @n  For any enquiry about license, http://embeddedcomputing.weebly.com/contact
///
/// @seeReadMe.txt for references
#if defined(MPIDE)
#include "WProgram.h"
#elif defined(DIGISPARK)
#include "Arduino.h"
#elif defined(ENERGIA)
#include "Energia.h"
#elif defined(MAPLE_IDE)
#include "WProgram.h"
#elif defined(CORE_TEENSY)
#include "WProgram.h"
#elif defined(WIRING)
#include "Wiring.h"
#elif defined(ARDUINO) && (ARDUINO >= 100)
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100)
#include "WProgram.h"
#endif
#ifndef LCD_SCREEN_FONT_RELEASE
#define LCD_SCREEN_FONT_RELEASE 114
#include "LCD_screen.h"
#if LCD_SCREEN_RELEASE < 114
#error Required LCD_SCREEN_RELEASE 114
#endif
#if defined(__LM4F120H5QR__) || defined(__32MX320F128H__) || defined(__AVR_ATmega2560__)
#define MAX_FONT_SIZE 3
#elif defined(__MSP430F5529)
#define MAX_FONT_SIZE 2
#else
#define MAX_FONT_SIZE 1
#endif
#if (MAX_FONT_SIZE > 0)
#include "Terminal6e.h"
#if (MAX_FONT_SIZE > 1)
#include "Terminal8e.h"
#if (MAX_FONT_SIZE > 2)
#include "Terminal12e.h"
#if (MAX_FONT_SIZE > 3)
#include "Terminal16e.h"
#endif
#endif
#endif
#endif
class LCD_screen_font : public LCD_screen {
public:
    LCD_screen_font();
    virtual void setFontSize(uint8_t font = 0);
    virtual uint8_t fontMax();
    virtual uint8_t fontSizeX();
    virtual uint8_t fontSizeY();
    virtual void gText(uint16_t x0, uint16_t y0,
                       String s,
                       uint16_t textColour = whiteColour, uint16_t backColour = blackColour,
                       uint8_t ix = 1, uint8_t iy = 1);
protected:
    uint8_t _getCharacter(uint8_t c, uint8_t i);
    virtual void _fastFill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour) =0;
    virtual void _setPoint(uint16_t x1, uint16_t y1, uint16_t colour) =0;
    virtual void _getRawTouch(uint16_t &x0, uint16_t &y0, uint16_t &z0) =0;
    virtual void _setWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) =0;
    virtual void _writeData88(uint8_t dataHigh8, uint8_t dataLow8) =0;
};
#endif
