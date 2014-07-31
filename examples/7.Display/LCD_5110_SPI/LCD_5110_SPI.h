///
/// @file 	LCD_5110_SPI.h
/// @brief	Library for Nokia 5110 display
/// @details Ported to LM4F120 by Bryan Schremp (bajabug@gmail.com) 11/10/2012
/// @n		Uses GLCD fonts
/// @n		Push button 2 to turn backlight on / off
///
/// @a 		Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author 	Rei VILO
/// @author 	http://embeddedcomputing.weebly.com
/// @date	Jan 12, 2013
/// @version	release 105
/// @n
/// @copyright 	© Rei VILO, 2010-2012
/// @copyright 	CC = BY NC SA
/// @n		http://embeddedcomputing.weebly.com
///
/// @see
/// *		Ported to LM4F120 by Bryan Schremp (bajabug@gmail.com) 11/10/2012
/// @n		http://forum.stellarisiti.com/topic/330-lcd-5110-lm4f120-sample-sketch-stellarpad-energia-branch/?p=1333
/// * 		Fonts generated with MikroElektronika GLCD Font Creator 1.2.0.0
/// @n		http://www.mikroe.com
///
// Core library - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Platform not supported
#endif
#ifndef LCD_5110_SPI_h
#define LCD_5110_SPI_h
#include "Terminal6.h"
#include "Terminal12.h"
#include "SPI.h"
class LCD_5110_SPI {
public:
//
//
    LCD_5110_SPI();
//
//
    LCD_5110_SPI(uint8_t pinChipSelect, uint8_t pinDataCommand, uint8_t pinReset, uint8_t pinBacklight, uint8_t pinPushButton);
    void begin();
    String WhoAmI();
    void clear();
    void setBacklight(boolean flag=true);
    void setFont(uint8_t font=0);
    uint8_t fontX();
    uint8_t fontY();
    void text(uint8_t x, uint8_t y, String s);
    boolean getButton();
private:
    void setXY(uint8_t x, uint8_t y);
    void write(uint8_t dataCommand, uint8_t c);
    uint8_t _font;

    uint8_t _pinReset;
    uint8_t _pinSerialData;
    uint8_t _pinBacklight;
    uint8_t _pinChipSelect;
    uint8_t _pinDataCommand;
    uint8_t _pinSerialClock;
    uint8_t _pinPushButton;
};
#endif
