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


LCD_Colour::LCD_Colour() 
{
  LCD_Colour(P1_2,    // Chip Select
             P1_5,    // Serial Clock
             P1_7,    // Serial Data
             P1_4,    // Data/Command
             P1_3);   // Push Button 2
}

LCD_Colour::LCD_Colour(uint8_t pinChipSelect, 
                       uint8_t pinSerialClock, uint8_t pinSerialData, 
                       uint8_t pinDataCommand, 
                       uint8_t pinPushButton) 
//             , uint8_t pinReset, 
//                       uint8_t pinBacklight) 
{
  _pinChipSelect  = pinChipSelect;
  _pinSerialClock = pinSerialClock;
  _pinSerialData  = pinSerialData;
  _pinDataCommand = pinDataCommand;
  //  _pinReset       = pinReset;
  //  _pinBacklight   = pinBacklight;
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
  //  pinMode(_pinReset, OUTPUT);
  pinMode(_pinDataCommand, OUTPUT);
  pinMode(_pinSerialData, OUTPUT);
  pinMode(_pinSerialClock, OUTPUT);
  //  digitalWrite(_pinReset, LOW);
  delay(1);
  //  digitalWrite(_pinReset, HIGH);
  
  write(_commandLCD, 0x01);
  delay(20);
  write(_commandLCD, 0x11);
  delay(1); // driver is doing self check, but seems to be working fine without the delay
  write(_commandLCD, 0x3a);
  write(_dataLCD, 0x05); // 16-bit mode
  write(_commandLCD, 0x36);
  write(_dataLCD, 0xc8);
  //write(_commandLCD, SETCON);
  //write(_dataLCD, 0x3F);
  write(_commandLCD, 0x29); // why? DISPON should be set on power up, sleep out should be enough
  
  //  pinMode(_pinBacklight, OUTPUT);
  pinMode(_pinPushButton, INPUT_PULLUP);
  
  clear();
  _font = 0;
  //  setBacklight(false);
}

String LCD_Colour::WhoAmI() {
  return "LCD BoosterPack";
}

void LCD_Colour::clear() {
  setArea(0, 0, 127, 159);
  
  for (uint8_t y = 0; y < 128; y++)  
    for (uint8_t x = 0; x < 160; x++) 
      write(_dataLCD, 0x00);
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

void LCD_Colour::drawPixel(uint8_t x, uint8_t y) {
  setArea(x, y, x, y);
  write(_dataLCD, _colourHighByte);
  write(_dataLCD, _colourLowByte);
}

//void LCD_Colour::drawChar(uint8_t c) {
//char col = 0;
//char row = 0;
//char bit = 0x01;
//while (row < 8) {
//  while (col < 5) {
//    if (font[c - 0x20][col] & bit)
//      drawPixel(x + col, y + row);
//      col++;
//  }
//  col = 0;
//  bit <<= 1;
//  row++;
//  }
//}


void LCD_Colour::text(uint8_t x, uint8_t y, String s) {
  uint8_t i; // character in the string
  uint8_t j; // row
  uint8_t k; // col
  uint8_t bit = 0x01; // bit
  
  if (_font==0) {
    for (i=0; i<s.length(); i++) {
      for (j=0; j<8; j++) {
        for (k=0; k<5; k++) {
          if (Terminal6x8[s.charAt(i)-' '][j] & bit) drawPixel(x + k, y + j);
        }
      }
    }
  } else if (_font==1) { 
    for (i=0; i<s.length(); i++) {
      for (j=0; j<8; j++) {
        for (k=0; k<11; k++) {
          if (Terminal6x8[s.charAt(i)-' '][2*j] & bit)   drawPixel(x + k, y + 2*j);
          if (Terminal6x8[s.charAt(i)-' '][2*j+1] & bit) drawPixel(x + k, y + 2*j+1);
        }
      }
    }
  }
}

boolean LCD_Colour::getButton() {
  if (digitalRead(_pinPushButton)==LOW) {
    while (digitalRead(_pinPushButton)==LOW); // debounce
    return true;
  } else {
    return false;
  }
}