//
// SRAM.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode
// http://embedXcode.weebly.com
//
// Project chipKIT_SRAM
//
// Created by Rei VILO, déc. 22, 2012 14:26
// embedXcode.weebly.com
//
//
// Copyright © Rei VILO, 2012
// Licence CC = BY NC SA
//
// See SRAM.cpp.h and ReadMe.txt for references
//


#include "SRAM.h"

SRAM::SRAM(uint8_t pinChipSelect) {
    _pinChipSelect = pinChipSelect;
}

void SRAM::begin() {
    pinMode(_pinChipSelect, OUTPUT);
    setMode(SRAM_SEQUENCE_MODE);
}

void SRAM::setMode(uint8_t mode) {
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer(SRAM_WRITE_STATUS);
    SPI.transfer(mode);
    digitalWrite(_pinChipSelect, HIGH);
}

uint8_t SRAM::getMode() {
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer(SRAM_READ_STATUS);
    uint8_t v = SPI.transfer(0);
    digitalWrite(_pinChipSelect, HIGH);
    return v;
}

void SRAM::write(uint16_t address, uint8_t * data, uint16_t length) {
    if (length>0) {
        digitalWrite(_pinChipSelect, LOW);
        SPI.transfer(SRAM_WRITE);
        SPI.transfer(address >> 8);
        SPI.transfer(address & 0xff);
        for (uint16_t j=0; j<length; j++) SPI.transfer(data[j]);
        digitalWrite(_pinChipSelect, HIGH);
    }
}

void SRAM::read(uint16_t address, uint8_t * data, uint16_t length) {
    if (length>0) {
        digitalWrite(_pinChipSelect, LOW);
        SPI.transfer(SRAM_READ);
        SPI.transfer(address >> 8);
        SPI.transfer(address & 0xff);
        
        for (uint16_t j=0; j<length; j++) data[j] = SPI.transfer(0);
        
        digitalWrite (_pinChipSelect, HIGH);
    }
}
