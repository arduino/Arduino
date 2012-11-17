///
/// @file 	LCD_Colour.h 
/// @brief	Library for LCD_Colour with Nokia 7110 display
/// @details 	Based on LCD BoosterPack by SugarAddict
/// @n		Uses GLCD fonts
/// @n		Push button on screen to turn backlight on / off 
///
/// @a 		Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author 	Rei VILO
/// @author 	http://embeddedcomputing.weebly.com
/// @date	May 28, 2012
/// @version	release 102
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
///

// Core library
#if defined (__AVR_ATmega328P__) || defined(__AVR_ATmega2560__) // Arduino specific
#include "WProgram.h" // #include "Arduino.h" for Arduino 1.0
#elif defined(__32MX320F128H__) || defined(__32MX795F512L__) // chipKIT specific 
#include "WProgram.h"
#elif defined(__AVR_ATmega644P__) // Wiring specific
#include "Wiring.h"
#elif defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#elif defined(MCU_STM32F103RB) || defined(MCU_STM32F103ZE) || defined(MCU_STM32F103CB) || defined(MCU_STM32F103RE) // Maple specific
#include "WProgram.h"	
#endif

#ifndef LCD_Colour_h
#define LCD_Colour_h

#include "Terminal6.h"
#include "Terminal12.h"

#define COLOR_16_BLACK   0x0000
#define COLOR_16_BLUE    0x001f
#define COLOR_16_RED     0xf800
#define COLOR_16_GREEN   0x07e0
#define COLOR_16_CYAN    0x07ff
#define COLOR_16_MAGENTA 0xf81f
#define COLOR_16_YELLOW  0xffe0
#define COLOR_16_WHITE   0xffff
#define COLOR_16_ORANGE	 0xfd20
#define COLOR_16_GRAY	 0xbdf7

///
/// @brief	Class for LCD BoosterPack and Nokia 7110 screen
///
class LCD_Colour {
public:
  ///
  /// @brief	Constructor with default pins
  /// @note	Default pins for LaunchPad
  /// @n	P2_2 = Chip Select
  /// @n	P2_4 = Serial Clock
  /// @n	P2_0 = Serial Data
  /// @n	P2_3 = Data/Command
  /// @n	P1_0 = Reset
  /// @n	P2_1 = Backlight
  /// @n	P2_5 = Push Button
  ///	
  LCD_Colour(); 
  
  ///
  /// @brief	Constructor with specific pins
  /// @param	pinChipSelect Chip Select pin number
  /// @param	pinSerialClock Serial Clock pin number
  /// @param	pinSerialData Serial Data pin number
  /// @param	pinDataCommand Data Command pin number
  /// @param	pinReset Reset pin number
  /// @param	pinBacklight Backlight pin number
  /// @param	pinPushButton Push Button pin number
  ///
  LCD_Colour(uint8_t pinChipSelect, uint8_t pinSerialClock, uint8_t pinSerialData, uint8_t pinDataCommand, uint8_t pinPushButton); 
  // uint8_t pinReset, uint8_t pinBacklight, 
  
  ///
  /// @brief	Initialise
  ///
  void begin(); 
  
  /// 
  /// @brief	Request information about the screen
  /// @return	string with hardware version
  /// 
  String WhoAmI();
  
  ///
  /// @brief	Clear the screen
  ///
  void clear();
  
  ///
  /// @brief	Switch backlight
  /// @param	flag default=true backlight on, false off
  ///
//  void setBacklight(boolean flag=true);
  
  ///
  /// @brief	Select font
  /// @param	font default=0=small, 1=large
  ///
  void setFont(uint8_t font=0);
  
  void setColour(uint16_t colour);
  
  /// 
  /// @brief	Font size, x-axis
  /// @return	horizontal size of current font, in pixels
  /// 
  uint8_t fontX();
  
  /// 
  /// @brief	Font size, y-axis
  /// @return	vertical size of current font, in pixels
  /// 
  uint8_t fontY();
  
  ///
  /// @brief	Draw ASCII text (row and line coordinates)
  /// @param	x row number, x-axis
  /// @param	y line number, y-axis
  /// @param	s text string
  ///
  void text(uint8_t x, uint8_t y, String s);
  
  ///
  /// @brief	Get button state
  /// @return	true=pressed, otherwise false
  /// @note	in case the button is pressed, debounce is checked
  ///
  boolean getButton();
  
private:    
  void setXY(uint8_t x, uint8_t y);
  void setArea(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
  void write(uint8_t dataCommand, uint8_t c);
  void drawPixel(uint8_t x, uint8_t y);

  uint8_t _font;
  uint8_t _colourLowByte, _colourHighByte;

};

#endif