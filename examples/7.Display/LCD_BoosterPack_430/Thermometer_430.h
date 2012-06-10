//
//  Thermometer_430.h 
//  Library header
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD_BoosterPack_430
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
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

#ifndef Thermometer_430_h
#define Thermometer_430_h

#define NUMBER  8 // take number / 2

class Thermometer_430 {
public:
  Thermometer_430();
  void begin();
  void get();
  int32_t temperatureX10();
  
private:
  int32_t _average;
  int32_t _values[NUMBER];
  uint8_t _index;
};

#endif
