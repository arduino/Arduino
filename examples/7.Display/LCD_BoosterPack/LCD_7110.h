///
/// @file 	LCD_7110.h
/// @brief	Library for LCD_BoosterPack with Nokia 7110 display
/// @details 	Based on LCD BoosterPack by SugarAddict
/// @n		Works on LaunchPad MSP430G2553 and SteallarPad LM4F
/// @n		Uses GLCD fonts
/// @n		Push button on screen to turn backlight on / off
///
/// @a 		Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author 	Rei VILO
/// @author 	http://embeddedcomputing.weebly.com
/// @date	Dec 13, 2012
/// @version	release 104
/// @n
/// @copyright 	© Rei VILO, 2010-2012
/// @copyright 	CC = BY NC SA
/// @n		http://embeddedcomputing.weebly.com
///
/// @see 	
/// *		LCD BoosterPack by SugarAddict » Mon Jan 02, 2012 6:01 am
/// @n		http://www.43oh.com/forum/viewtopic.php?p=15140#p15140
/// * 		Fonts generated with MikroElektronika GLCD Font Creator 1.2.0.0
/// @n		http://www.mikroe.com

// Core library
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#else
#error Platform not supported
#endif

#ifndef LCD_7110_h
#define LCD_7110_h

#include "Terminal6.h"
#include "Terminal12.h"

class LCD_7110 {
public:
  LCD_7110();
  LCD_7110(uint8_t pinChipSelect, uint8_t pinSerialClock, uint8_t pinSerialData, uint8_t pinDataCommand, uint8_t pinReset, uint8_t pinBacklight, uint8_t pinPushButton);
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
