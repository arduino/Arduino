//
// FastDigitalWrite.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode 
// http://embedXcode.weebly.com
//
// Project SPI_23LC1024
//
// Created by Rei VILO, Jul 08, 2013
//	
//
// Copyright © Rei VILO, 2013
// Licence CC = BY NC SA
//
// See FastDigitalWrite.h and ReadMe.txt for references
//


// Library header
#include "FastDigitalWrite.h"

// Macros
#define portOutputRegister(x) (regtype)portBASERegister(x)
#define cbi_macro(reg, mask) GPIOPinWrite(reg, mask, 0)
#define sbi_macro(reg, mask) GPIOPinWrite(reg, mask, mask)
#define pulse_high_macro(reg, bitmask) { sbi_macro(reg, bitmask); cbi_macro(reg, bitmask); }
#define pulse_low_macro(reg, bitmask) { cbi_macro(reg, bitmask); sbi_macro(reg, bitmask); }


// Code
fastDigitalOutputPin::fastDigitalOutputPin()
{
    ;
}

void fastDigitalOutputPin::begin(uint8_t outputPin)
{
    _port = portOutputRegister(digitalPinToPort(outputPin));
    _bit  = digitalPinToBitMask(outputPin);
    pinMode(outputPin, OUTPUT);
}

void fastDigitalOutputPin::setHIGH()
{
    sbi_macro(_port, _bit);                                                           // HIGH
}

void fastDigitalOutputPin::setLOW()
{
    cbi_macro(_port, _bit);                                                           // LOW
}

void fastDigitalOutputPin::set(uint8_t value)
{
    if (value>0) setHIGH();
    else setLOW();
}

void fastDigitalOutputPin::pulseHIGH()
{
    pulse_high_macro(_port, _bit);                                                    // HIGH then LOW
}

void fastDigitalOutputPin::pulseLOW()
{
    pulse_low_macro(_port, _bit);                                                     // LOW then HIGH
}



