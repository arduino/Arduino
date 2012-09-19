//
//  Thermometer_430.cpp 
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Pro_indexect LCD_BoosterPack_430
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//
// Formula: http://www.43oh.com/forum/viewtopic.php?p=18248#p18248

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

// Library header
#include "Thermometer_430.h"

// Code
Thermometer_430::Thermometer_430() {
  analogReference(INTERNAL1V5);
  analogRead(TEMPSENSOR); // discard first reading 
}

void Thermometer_430::begin() {
  _average = 0;
  for (uint8_t _index=0; _index<NUMBER; _index++) {
    delay(200);
    _values[_index] = ((uint32_t)analogRead(TEMPSENSOR)*27069 - 18169625) * 10 >> 16;
    _average += _values[_index];
  }
}

void Thermometer_430::get() {
  delay(200);
  _average -= _values[_index];
  _values[_index] = ((uint32_t)analogRead(TEMPSENSOR)*27069 - 18169625) * 10 >> 16;
  _average += _values[_index];
  _index++; 
  _index %= NUMBER;    
}

int32_t Thermometer_430::temperatureX10() {
  delay(100);
  return _average/NUMBER;
}


