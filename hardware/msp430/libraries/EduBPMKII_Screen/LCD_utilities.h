///
/// @file       LCD_utilities.h
/// @brief      Library header
/// @detailsUtilities for LCD_screen
/// @n
/// @n @b       Project LCD_screen
/// @n @a       Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author     Rei VILO
/// @author     embedXcode.weebly.com
/// @date       Sep 18, 2013
/// @version102
///
/// @copyright (c) Rei VILO, 2010-2013
/// @copyrightAll rights reserved
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
#ifndef LCD_UTILITIES_RELEASE
#define LCD_UTILITIES_RELEASE 102
int32_t cos32x100(int32_t degreesX100);
int32_t sin32x100(int32_t degreesX100);
String utf2iso(String s);
String htoa(uint32_t number, uint8_t size=0);
String btoa(uint16_t number, uint8_t size=8);
String ttoa(uint32_t number, uint8_t size=0);
String i32toa(int32_t number, int32_t unit=1, uint8_t decimal=0, uint8_t size=0);
#endif
