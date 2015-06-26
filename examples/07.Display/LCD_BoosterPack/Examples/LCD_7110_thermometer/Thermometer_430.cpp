//
//  Thermometer_430.cpp 
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD_BoosterPack_430
//  Created by Rei VILO on Dec 13, 2012
//  Copyright © 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

// Library header
#include "Thermometer_430.h"
#include "Energia.h"

// Code
Thermometer_430::Thermometer_430() {
    analogReference(INTERNAL1V5);
//    analogRead(TEMPSENSOR); // discard first reading // No action here!
}

void Thermometer_430::begin() {
    analogRead(TEMPSENSOR); // discard first reading

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


