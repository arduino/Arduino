//
//  LCD_5110.h
//  Library header
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

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

#ifndef LCD_5110_h
#define LCD_5110_h

#include "Terminal6.h"
#include "Terminal12.h"

class LCD_5110 {
public:
  LCD_5110(); 
  LCD_5110(uint8_t pinChipSelect, uint8_t pinSerialClock, uint8_t pinSerialData, uint8_t pinDataCommand, uint8_t pinReset, uint8_t pinBacklight, uint8_t pinPushButton); 
  void begin(); 
  String WhoAmI();
  void clear(); 
  void setBacklight(boolean b=true); 
  void setFont(uint8_t font=0); 
  uint8_t fontX();     
  uint8_t fontY(); 
  void text(uint8_t x, uint8_t y, String s);
  boolean getButton();
  
private:    
  void setXY(uint8_t x, uint8_t y);
  void write(uint8_t dataCommand, uint8_t c);
  uint8_t _font;
};

#endif