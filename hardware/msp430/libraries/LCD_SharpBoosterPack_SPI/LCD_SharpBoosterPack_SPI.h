///
/// @file 	LCD_SharpBoosterPack_SPI.h
/// @brief	Library for Sharp BoosterPack LCD display
/// @details Ported to LM4F120 by Bryan Schremp (bajabug@gmail.com) 11/10/2012
/// @n		Uses GLCD fonts
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
#ifndef LCD_SharpBoosterPack_SPI_h
#define LCD_SharpBoosterPack_SPI_h
#include "Terminal6.h"
#include "Terminal12.h"
//#include "SPI.h"
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
    void setFont(uint8_t font=0);
    uint8_t fontX();
    uint8_t fontY();
    void setXY(uint8_t x, uint8_t y, uint8_t ulValue);
    void text(uint8_t x, uint8_t y, String s);
    void flush();
private:
    uint8_t _font;
	void initializeDisplayBuffer();
	void TA0_enableVCOMToggle();
	void TA0_turnOff();
};
#endif
