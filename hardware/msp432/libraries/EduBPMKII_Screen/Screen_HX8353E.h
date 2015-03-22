///
/// @file       Screen_HX8353E.h
/// @brief      Library header
/// @details    HX8353E screen library
/// @n          Support for new LaunchPads
/// * MSP430F5529
/// * LM4F120H5QR TM4C123GH6PM
/// * TM4C1294NCPDT TM4C1294XNCZAD
/// Apr 25, 2014
///
/// @n
/// @n @b       Project new_screen_HX8353
/// @n @a       Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author     Rei VILO
/// @author     embedXcode.weebly.com
/// @date       Apr 25, 2014
/// @version    102
///
/// @copyright  © Rei VILO, 2013
/// @copyright  All rights reserved
///
/// @n  Dual license:
/// *   For hobbyists and for personal usage: Attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
/// *   For professionals or organisations or for commercial usage: All rights reserved
///
/// @n  For any enquiry about license, http://embeddedcomputing.weebly.com/contact
///
///
/// @see
#if defined(ENERGIA)
#include "Energia.h"
#else
#error Board not supported
#endif
#ifndef SCREEN_HX8353_RELEASE
#define SCREEN_HX8353_RELEASE 100
#include "LCD_screen_font.h"
#if LCD_SCREEN_FONT_RELEASE < 114
#error Required LCD_SCREEN_FONT_RELEASE 114
#endif
#include "SPI.h"
class Screen_HX8353E : public LCD_screen_font {
public:
    Screen_HX8353E();
    Screen_HX8353E(uint8_t resetPin, uint8_t dataCommandPin, uint8_t chipSelectPin, uint8_t backlightPin);
    void begin();
    String WhoAmI();
    void invert(boolean flag);
    void setBacklight(boolean flag);
    void setDisplay(boolean flag);
    void setOrientation(uint8_t orientation);
private:
    void _setPoint(uint16_t x1, uint16_t y1, uint16_t colour);
    void _setWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
    void _writeRegister(uint8_t command8, uint8_t data8);
    void _writeCommand(uint8_t command8);
    void _writeData(uint8_t data8);
    void _writeData16(uint16_t data16);
    void _writeData88(uint8_t dataHigh8, uint8_t dataLow8);
    void _writeData8888(uint8_t dataHigh8, uint8_t dataLow8, uint8_t data8_3, uint8_t data8_4);
    void _fastFill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour);
    void _getRawTouch(uint16_t &x, uint16_t &y, uint16_t &z);
    uint8_t _pinReset;
    uint8_t _pinDataCommand;
    uint8_t _pinChipSelect;
    uint8_t _pinBacklight;
};
#endif
