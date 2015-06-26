//
//  LCD_Colour.cpp
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//

#include "LCD_Colour.h"

const uint8_t  _commandLCD    = 0x00;
const uint8_t  _dataLCD       = 0x01;
//const uint8_t  _dataRepeatLCD = 0x02;

uint8_t _pinReset;
uint8_t _pinSerialData;
uint8_t _pinBacklight;
uint8_t _pinChipSelect;
uint8_t _pinDataCommand;
uint8_t _pinSerialClock;
uint8_t _pinPushButton;

//#define LCD_SCLK_PIN BIT5
//#define LCD_SD_PIN BIT7
//#define LCD_SCE_PIN BIT2
//#define LCD_DC_PIN BIT4
//#define LCD_SELECT P1OUT &= ~LCD_SCE_PIN
//#define LCD_DESELECT P1OUT |= LCD_SCE_PIN
//#define LCD_CLOCK P1OUT |= LCD_SCLK_PIN; P1OUT &= ~LCD_SCLK_PIN



#if defined(__MSP430G2553__) // LaunchPad MSP430G2553 specific
LCD_Colour::LCD_Colour(uint8_t version) {
    LCD_Colour((version==1) ? P1_2 : P1_0,    // Chip Select
               P1_5,    // Serial Clock
               P1_7,    // Serial Data
               P1_4,    // Data/Command
               PUSH2);  // Push Button 2
}
#elif defined(__LM4F120H5QR__) // StellarPad LM4F specific
LCD_Colour::LCD_Colour(uint8_t version) {
    LCD_Colour((version==1) ? PB_1 : PB_5,    // Chip Select
               PB_4,    // Serial Clock
               PB_7,    // Serial Data
               PE_5,    // Data/Command
               PUSH2);  // Push Button 2
}
#else
#error Platform not supported
#endif


LCD_Colour::LCD_Colour(uint8_t pinChipSelect,
                       uint8_t pinSerialClock, uint8_t pinSerialData,
                       uint8_t pinDataCommand,
                       uint8_t pinPushButton)
{
    _pinChipSelect  = pinChipSelect;
    _pinSerialClock = pinSerialClock;
    _pinSerialData  = pinSerialData;
    _pinDataCommand = pinDataCommand;
    _pinPushButton  = pinPushButton;
}

void LCD_Colour::write(uint8_t dataCommand, uint8_t c)
{
    digitalWrite(_pinDataCommand, dataCommand);
    digitalWrite(_pinChipSelect, LOW);
    shiftOut(_pinSerialData, _pinSerialClock, MSBFIRST, c);
    digitalWrite(_pinChipSelect, HIGH);
}

void LCD_Colour::setXY(uint8_t x, uint8_t y)
{
    x += 0x12;
    write(_commandLCD, 0xb0 | y);
    write(_commandLCD, 0x10 | (x >> 4));
    write(_commandLCD, 0x0f & x);
}

void LCD_Colour::setArea(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    write(_commandLCD, 0x2a);
    write(_dataLCD, 0);
    write(_dataLCD, x1);
    write(_dataLCD, 0);
    write(_dataLCD, x2);
    
    write(_commandLCD, 0x2b);
    write(_dataLCD, 0);
    write(_dataLCD, y1);
    write(_dataLCD, 0);
    write(_dataLCD, y2);
    
    write(_commandLCD, 0x2c); // data to follow
}


void LCD_Colour::begin()
{
    pinMode(_pinChipSelect, OUTPUT);
    pinMode(_pinDataCommand, OUTPUT);
    pinMode(_pinSerialData, OUTPUT);
    pinMode(_pinSerialClock, OUTPUT);
    delay(1);
    
    write(_commandLCD, 0x01);
    delay(20);
    write(_commandLCD, 0x11);
    delay(1); // driver is doing self check, but seems to be working fine without the delay
    write(_commandLCD, 0x3a);
    write(_dataLCD, 0x05); // 16-bit mode
    write(_commandLCD, 0x36);
    write(_dataLCD, 0xc8);
    write(_commandLCD, 0x25);
    write(_dataLCD, 0x3F);
    write(_commandLCD, 0x29); // why? DISPON should be set on power up, sleep out should be enough
    
    //  pinMode(_pinBacklight, OUTPUT);
    pinMode(_pinPushButton, INPUT_PULLUP);
    
    clear();
    _font = 0;
    _penSolid = false;
}


String LCD_Colour::WhoAmI() {
    return "LCD BoosterPack";
}

void LCD_Colour::clear() {
    setArea(0, 0, 127, 159);
    uint16_t total = 128 * 160;
    for (uint16_t k = 0; k < total; k++) {
        write(_dataLCD, 0x00);
        write(_dataLCD, 0x00);
    }
}

//void LCD_Colour::setBacklight(boolean flag) {
//  digitalWrite(_pinBacklight, flag ? HIGH : LOW);
//}

void LCD_Colour::setFont(uint8_t font) {
    _font = font;
}

void LCD_Colour::setColour(uint16_t colour) {
    _colourLowByte  = (colour & 0xff);
    _colourHighByte = (colour >> 8);
}

void LCD_Colour::text(uint8_t x, uint8_t y, String s) {
    uint8_t i;
    uint8_t j;
    uint8_t k;
    
    if (_font==0) {
        for (k=0; k<s.length(); k++)
            for (i=0; i<5; i++)
                for (j=0; j<8; j++)
                    if (bitRead(Terminal6x8[s.charAt(k)-' '][i], j)) point(x + 6*k + i, y + j);
    } else if (_font==1) {
        for (k=0; k<s.length(); k++)
            for (i=0; i<11; i++)
                for (j=0; j<8; j++) {
                    if (bitRead(Terminal11x16[s.charAt(k)-' '][2*i],   j)) point(x + 12*k + i, y + j);
                    if (bitRead(Terminal11x16[s.charAt(k)-' '][2*i+1], j)) point(x + 12*k + i, y +8 + j);
                }
    }
}


void LCD_Colour::setPenSolid(boolean flag) {
    _penSolid = flag;
}

void LCD_Colour::point(uint8_t x1, uint8_t y1) {
    setArea(x1, y1, x1, y1);
    write(_dataLCD, _colourHighByte);
    write(_dataLCD, _colourLowByte);
}

void LCD_Colour::line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    uint8_t xFrom, xTo, yFrom, yTo;
    uint8_t d = 0;
    
    // handle direction
    if (y1 > y2) {
        yFrom = y2;
        yTo = y1;
    } else {
        yTo = y2;
        yFrom = y1;
    }
    
    if (x1 > x2) {
        xFrom = x2;
        xTo = x1;
    } else {
        xTo = x2;
        xFrom = x1;
    }
    
    if (yFrom == yTo) { // check if horizontal
        
        d = xTo - xFrom + 1;
        setArea(xFrom, yFrom, xTo, yTo);
        while (d-- > 0) {
            write(_dataLCD, _colourHighByte);
            write(_dataLCD, _colourLowByte);
        }
        
    } else if (xFrom == xTo) { // check if vertical
        d = yTo - yFrom + 1;
        setArea(xFrom, yFrom, xTo, yTo);
        while (d-- > 0) {
            write(_dataLCD, _colourHighByte);
            write(_dataLCD, _colourLowByte);
        }
        
    } else { // angled
        uint8_t dx, dy;
        int8_t sx, sy;
        
        if (x1 < x2) {
            sx = 1;
            dx = x2 - x1;
        }
        else {
            sx = -1;
            dx = x1 - x2;
        }
        
        if (y1 < y2) {
            sy = 1;
            dy = y2 - y1;
        }
        else {
            sy = -1;
            dy = y1 - y2;
        }
        
        int8_t e1 = dx - dy;
        int8_t e2;
        
        while (1) {
            point(x1, y1);
            if (x1 == x2 && y1 == y2)
                break;
            e2 = 2 * e1;
            if (e2 > -dy) {
                e1 = e1 - dy;
                x1 = x1 + sx;
            }
            if (e2 < dx) {
                e1 = e1 + dx;
                y1 = y1 + sy;
            }
        }
    }
}

void LCD_Colour::rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
    
    if (_penSolid) {
        setArea(x1, y1, x2, y2);
        uint16_t total = (x2 - x1 + 1) * (y2 - y1 + 1);
        uint16_t c = 0;
        while (c < total) {
            write(_dataLCD, _colourHighByte);
            write(_dataLCD, _colourLowByte);
            c++;
        }
    } else {
        line(x1, y1, x2, y1);
        line(x1, y2, x2, y2);
        line(x1, y1, x1, y2);
        line(x2, y1, x2, y2);
    }
}


void LCD_Colour::circle(uint8_t x1, uint8_t y1, uint8_t radius) {
    uint8_t dx = radius;
    uint8_t dy = 0;
    int8_t xChange = 1 - 2 * radius;
    int8_t yChange = 1;
    int8_t radiusError = 0;
    
    
    while (dx >= dy) {
        if (_penSolid) {
            line(x1 + dy, y1 + dx, x1 - dy, y1 + dx);
            line(x1 - dy, y1 - dx, x1 + dy, y1 - dx);
            line(x1 - dx, y1 + dy, x1 + dx, y1 + dy);
            line(x1 - dx, y1 - dy, x1 + dx, y1 - dy);
        } else {
            point(x1 + dx, y1 + dy);
            point(x1 - dx, y1 + dy);
            point(x1 - dx, y1 - dy);
            point(x1 + dx, y1 - dy);
            point(x1 + dy, y1 + dx);
            point(x1 - dy, y1 + dx);
            point(x1 - dy, y1 - dx);
            point(x1 + dy, y1 - dx);
        }
        
        dy++;
        radiusError += yChange;
        yChange += 2;
        if (2 * radiusError + xChange > 0) {
            dx--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}

void LCD_Colour::setBacklight(boolean flag) {
    write(_commandLCD, (flag) ? 0x11: 0x10);
}

uint16_t LCD_Colour::calculateColour(uint8_t red8, uint8_t green8, uint8_t blue8) {
    // rgb16 = red5 green6 blue5
    return (red8 >> 3) << 11 | (green8 >> 2) << 5 | (blue8 >> 3);
}

boolean LCD_Colour::getButton() {
    if (digitalRead(_pinPushButton)==LOW) {
        while (digitalRead(_pinPushButton)==LOW); // debounce
        return true;
    } else {
        return false;
    }
}