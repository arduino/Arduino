//
//  LCD_7110.cpp
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

#include "LCD_7110.h"

const uint8_t  _commandLCD    = 0x00;
const uint8_t  _dataLCD       = 0x01;
const uint8_t  _dataRepeatLCD = 0x02;

// Core library - MCU-based
#if defined(ENERGIA)
#include "Energia.h"
#else
#error Platform not supported
#endif


#if defined(__MSP430G2553__) // LaunchPad MSP430G2553 specific
LCD_7110::LCD_7110() {
    LCD_7110(P2_2,    // Chip Select
                    P2_4,    // Serial Clock
                    P2_0,    // Serial Data
                    P2_3,    // Data/Command
                    P1_0,    // Reset
                    P2_1,    // Backlight
                    P2_5);   // Push Button
}
#elif defined(__LM4F120H5QR__) // StellarPad LM4F specific
LCD_7110::LCD_7110() {
    LCD_7110(PA_7,    // Chip Select
                    PA_3,    // Serial Clock
                    PA_5,    // Serial Data
                    PA_2,    // Data/Command
                    PB_5,    // Reset
                    PA_6,    // Backlight
                    PA_4);   // Push Button
}
#else
#error Platform not supported
#endif

LCD_7110::LCD_7110(uint8_t pinChipSelect,
                                 uint8_t pinSerialClock, uint8_t pinSerialData,
                                 uint8_t pinDataCommand, uint8_t pinReset,
                                 uint8_t pinBacklight, uint8_t pinPushButton) {
    _pinChipSelect  = pinChipSelect;
    _pinSerialClock = pinSerialClock;
    _pinSerialData  = pinSerialData;
    _pinDataCommand = pinDataCommand;
    _pinReset       = pinReset;
    _pinBacklight   = pinBacklight;
    _pinPushButton  = pinPushButton;
}

void LCD_7110::write(uint8_t dataCommand, uint8_t c) {
    digitalWrite(_pinDataCommand, dataCommand);
    digitalWrite(_pinChipSelect, LOW);
    shiftOut(_pinSerialData, _pinSerialClock, MSBFIRST, c);
    digitalWrite(_pinChipSelect, HIGH);
}

void LCD_7110::setXY(uint8_t x, uint8_t y) {
    x += 0x12;
    write(_commandLCD, 0xb0 | y);
    write(_commandLCD, 0x10 | (x >> 4));
    write(_commandLCD, 0x0f & x);
}

void LCD_7110::begin() {
    static const unsigned char init[] = {
        0xa6, // Display: Normal
        0xa3, // LCD Bias Settings: 1/7 0xa3
        0xa1, // ADC Selection: Reverse
        0xc0, // Common Output: Normal Direction
        // 0xC8, // Common Output: Upside Down
        0x22, // Set the V5 output Voltage
        0x81, // Set Electronic Volume Register
        0x2e, // Power Controller Set
        // Booster circuit: ON
        // Voltage regulator circuit: ON
        // Voltage follower circuit: OFF
        0x2f, // Power Controller Set
        // Voltage follower circuit: ON
        0xe3, // Non-OPeration Command
        0x40, // Set the start line
        0xaf, // LCD On
        // 0xA5, // Display All Points: ON
        0xa4, //Display All Points: NORMAL
    };
    
    pinMode(_pinChipSelect, OUTPUT);
    pinMode(_pinReset, OUTPUT);
    pinMode(_pinDataCommand, OUTPUT);
    pinMode(_pinSerialData, OUTPUT);
    pinMode(_pinSerialClock, OUTPUT);
    digitalWrite(_pinReset, LOW);
    delay(1);
    digitalWrite(_pinReset, HIGH);
    for (uint8_t i=0; i<sizeof(init); i++)  write(_commandLCD, init[i]);
    
    pinMode(_pinBacklight, OUTPUT);
    pinMode(_pinPushButton, INPUT_PULLUP);
    
    clear();
    _font = 0;
    setBacklight(false);
}

String LCD_7110::WhoAmI() {
    return "LCD BoosterPack";
}

void LCD_7110::clear() {
    for (uint8_t y = 0; y < 9; y++)  {
        setXY(0, y);
        for (uint8_t x = 0; x < 96; x++) write(_dataLCD, 0x00);
    }
}

void LCD_7110::setBacklight(boolean flag) {
    digitalWrite(_pinBacklight, flag ? HIGH : LOW);
}

void LCD_7110::setFont(uint8_t font) {
    _font = font;
}

void LCD_7110::text(uint8_t x, uint8_t y, String s) {
    uint8_t i;
    uint8_t j;
    
    if (_font==0) {
        setXY(6*x, y);
        for (j=0; j<s.length(); j++) {
            for (i=0; i<5; i++) write(_dataLCD, Terminal6x8[s.charAt(j)-' '][i]);
            write(_dataLCD, 0x00);
        }
    } else if (_font==1) {
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

boolean LCD_7110::getButton() {
    if (digitalRead(_pinPushButton)==LOW) {
        while (digitalRead(_pinPushButton)==LOW); // debounce
        return true;
    } else {
        return false;
    }
}
