//
//  LCD_5110_SPI.cpp
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD 5110
//  Created by Rei VILO on Jan 12, 2013
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

#include "LCD_5110_SPI.h"

const uint8_t  _commandLCD = 0x00;
const uint8_t  _dataLCD    = 0x01;

#if defined(__MSP430G2553__) // LaunchPad MSP430G2553 specific
LCD_5110_SPI::LCD_5110_SPI() {
    LCD_5110_SPI(P2_2,    // Chip Select
                 P2_3,    // Data/Command
                 P1_0,    // Reset
                 P2_1,    // Backlight
                 PUSH2);   // Push Button 2
}
#elif defined(__LM4F120H5QR__) // StellarPad LM4F specific
LCD_5110_SPI::LCD_5110_SPI() {
    LCD_5110_SPI(PA_7,    // Chip Select
                 PA_2,    // Data/Command
                 PB_5,    // Reset
                 PA_6,    // Backlight
                 PUSH2);   // Push Button 2
}
#else
#error Platform not supported
#endif


LCD_5110_SPI::LCD_5110_SPI(uint8_t pinChipSelect, uint8_t pinDataCommand, uint8_t pinReset, uint8_t pinBacklight, uint8_t pinPushButton) {
    _pinChipSelect  = pinChipSelect;
    _pinDataCommand = pinDataCommand;
    //    _pinSerialData  = pinSerialData; //
    //    _pinSerialClock = pinSerialClock; //
    _pinReset       = pinReset;
    _pinBacklight   = pinBacklight;
    _pinPushButton  = pinPushButton;
}

void LCD_5110_SPI::write(uint8_t dataCommand, uint8_t c) {
    digitalWrite(_pinDataCommand, dataCommand);
    
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer((char)c);
    digitalWrite(_pinChipSelect, HIGH);
}

void LCD_5110_SPI::setXY(uint8_t x, uint8_t y) {
    write(_commandLCD, 0x40 | y);
    write(_commandLCD, 0x80 | x);
}

void LCD_5110_SPI::begin() {
    pinMode(_pinChipSelect, OUTPUT);
    pinMode(_pinReset, OUTPUT);
    pinMode(_pinDataCommand, OUTPUT);
    //  pinMode(_pinSerialData, OUTPUT);
    //  pinMode(_pinSerialClock, OUTPUT);
    pinMode(_pinBacklight, OUTPUT);
    pinMode(_pinPushButton, INPUT_PULLUP);
    
    
    
    digitalWrite(_pinDataCommand, LOW);
    delay(30);
    digitalWrite(_pinReset, LOW);
    delay(100); // as per 8.1 Initialisation
    digitalWrite(_pinReset, HIGH);
    
    write(_commandLCD, 0x21); // chip is active, horizontal addressing, use extended instruction set
    write(_commandLCD, 0xc8); // write VOP to register: 0xC8 for 3V — try other values
    write(_commandLCD, 0x12); // set Bias System 1:48
    write(_commandLCD, 0x20); // chip is active, horizontal addressing, use basic instruction set
    write(_commandLCD, 0x09); // temperature control
    write(_commandLCD, 0x0c); // normal mode
    delay(10);
    
    clear();
    _font = 0;
    setBacklight(false);
}

String LCD_5110_SPI::WhoAmI() {
    return "LCD Nokia 5110";
}

void LCD_5110_SPI::clear() {
    setXY(0, 0);
    for (uint16_t i=0; i<6*84; i++) write(_dataLCD, 0x00);
    setXY(0, 0);
}

void LCD_5110_SPI::setBacklight(boolean b) {
    digitalWrite(_pinBacklight, b ? LOW : HIGH);
}

void LCD_5110_SPI::setFont(uint8_t font) {
    _font = font;
}

void LCD_5110_SPI::text(uint8_t x, uint8_t y, String s) {
    uint8_t i;
    uint8_t j;
    
    if (_font==0) {
        setXY(6*x, y);
        for (j=0; j<s.length(); j++) {
            for (i=0; i<5; i++) write(_dataLCD, Terminal6x8[s.charAt(j)-' '][i]);
            write(_dataLCD, 0x00);
        }
    }
    else if (_font==1) {
        setXY(6*x, y);
        for (j=0; j<s.length(); j++) {
            for (i=0; i<11; i++) write(_dataLCD, Terminal11x16[s.charAt(j)-' '][2*i]);
            write(_dataLCD, 0x00);
        }
        
        setXY(6*x, y+1);
        for (j=0; j<s.length(); j++) {
            for (i=0; i<11; i++) write(_dataLCD, Terminal11x16[s.charAt(j)-' '][2*i+1]);
            write(_dataLCD, 0x00);
        }
    }
}

boolean LCD_5110_SPI::getButton() {
    if (digitalRead(_pinPushButton)==LOW) {
        while (digitalRead(_pinPushButton)==LOW); // debounce
        return true;
    } else {
        return false;
    }
}

