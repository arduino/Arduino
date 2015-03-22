//
// Screen_HX8353E.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode
// http://embedXcode.weebly.com
//
// Project new_screen_HX8353
//
// Created by Rei VILO, mars 07, 2013 09:21
// embedXcode.weebly.com
//
// Apr 25, 2014
// Support for new LaunchPads with
// . MSP430F5529
// . LM4F120H5QR TM4C123GH6PM
// . TM4C1294NCPDT TM4C1294XNCZAD
//
//
// Copyright © Rei VILO, 2013-2014
// License CC = BY NC SA
//
// See Screen_HX8353E.h and ReadMe.txt for references
//
// Library header
#include "Screen_HX8353E.h"
///
#define HX8353E_WIDTH  128
#define HX8353E_HEIGHT 128
#define HX8353E_MADCTL_MY  0x80
#define HX8353E_MADCTL_MX  0x40
#define HX8353E_MADCTL_MV  0x20
#define HX8353E_MADCTL_ML  0x10
#define HX8353E_MADCTL_RGB 0x08
#define HX8353E_MADCTL_MH  0x04
#define HX8353E_NOP     0x00
#define HX8353E_SWRESET 0x01
#define HX8353E_RDDID   0x04
#define HX8353E_RDDST   0x09
#define HX8353E_SLPIN   0x10
#define HX8353E_SLPOUT  0x11
#define HX8353E_PTLON   0x12
#define HX8353E_NORON   0x13
#define HX8353E_INVOFF  0x20
#define HX8353E_INVON   0x21
#define HX8353E_GAMSET  0x26
#define HX8353E_DISPOFF 0x28
#define HX8353E_DISPON  0x29
#define HX8353E_CASET   0x2A
#define HX8353E_RASET   0x2B
#define HX8353E_RAMWR   0x2C
#define HX8353E_RGBSET  0x2d
#define HX8353E_RAMRD   0x2E
#define HX8353E_PTLAR   0x30
#define HX8353E_MADCTL  0x36
#define HX8353E_COLMOD  0x3A
#define HX8353E_SETPWCTR 0xB1
#define HX8353E_SETDISPL 0xB2
#define HX8353E_FRMCTR3  0xB3
#define HX8353E_SETCYC   0xB4
#define HX8353E_SETBGP   0xb5
#define HX8353E_SETVCOM  0xB6
#define HX8353E_SETSTBA  0xC0
#define HX8353E_SETID    0xC3
#define HX8353E_GETHID   0xd0
#define HX8353E_SETGAMMA 0xE0
Screen_HX8353E::Screen_HX8353E() {
#if defined(__LM4F120H5QR__) || defined(__MSP430F5529__) || defined(__TM4C123GH6PM__) || defined(__TM4C1294NCPDT__) || defined(__TM4C1294XNCZAD__)
    _pinReset          = 17;
    _pinDataCommand    = 31;
    _pinChipSelect     = 13;
    _pinBacklight      = NULL;
#else
#error Platform not supported
#endif
}
Screen_HX8353E::Screen_HX8353E(uint8_t resetPin, uint8_t dataCommandPin, uint8_t chipSelectPin, uint8_t backlightPin)
{
    _pinReset = resetPin;
    _pinDataCommand = dataCommandPin;
    _pinChipSelect = chipSelectPin;
    _pinBacklight = backlightPin;
};
void Screen_HX8353E::begin()
{
#if defined(__LM4F120H5QR__)
    SPI.setModule(2);
#endif
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    if (_pinReset!=NULL) pinMode(_pinReset, OUTPUT);
    if (_pinBacklight!=NULL) pinMode(_pinBacklight, OUTPUT);
    pinMode(_pinDataCommand, OUTPUT);
    pinMode(_pinChipSelect, OUTPUT);
    if (_pinBacklight!=NULL) digitalWrite(_pinBacklight, HIGH);
    if (_pinReset!=NULL) digitalWrite(_pinReset, 1);
    delay(100);
    if (_pinReset!=NULL) digitalWrite(_pinReset, 0);
    delay(50);
    if (_pinReset!=NULL) digitalWrite(_pinReset, 1);
    delay(120);
    _writeCommand(HX8353E_SWRESET);
    delay(150);
    _writeCommand(HX8353E_SLPOUT);
    delay(200);
    _writeRegister(HX8353E_GAMSET, 0x04);
    _writeCommand(HX8353E_SETPWCTR);
    _writeData88(0x0A, 0x14);
    _writeCommand(HX8353E_SETSTBA);
    _writeData88(0x0A, 0x00);
    _writeRegister(HX8353E_COLMOD, 0x05);
    delay(10);
    _writeRegister(HX8353E_MADCTL, HX8353E_MADCTL_RGB);
    _writeCommand(HX8353E_CASET);
    _writeData8888(0x00, 0x00, 0x00, 0x79);
    _writeCommand(HX8353E_RASET);
    _writeData8888(0x00, 0x00, 0x00, 0x79);
    _writeCommand(HX8353E_NORON);
    delay(10);
    _writeCommand(HX8353E_DISPON);
    delay(120);
    _writeCommand(HX8353E_RAMWR);
    setBacklight(true);
    setOrientation(0);
    _screenWidth  = HX8353E_WIDTH;
    _screenHeigth = HX8353E_HEIGHT;
    _penSolid  = false;
    _fontSolid = true;
    _flagRead  = false;
    _touchTrim = 0;
    clear();
}
String Screen_HX8353E::WhoAmI()
{
    return "LCD MKII BoosterPack";
}
void Screen_HX8353E::invert(boolean flag)
{
    _writeCommand(flag ? HX8353E_INVON : HX8353E_INVOFF);
}
void Screen_HX8353E::setBacklight(boolean flag)
{
    if (_pinBacklight!=NULL) digitalWrite(_pinBacklight, flag);
}
void Screen_HX8353E::setDisplay(boolean flag)
{
    if (_pinBacklight!=NULL) setBacklight(flag);
}
void Screen_HX8353E::setOrientation(uint8_t orientation)
{
    _orientation = orientation % 4;
    _writeCommand(HX8353E_MADCTL);
    switch (_orientation) {
        case 0:
            _writeData(HX8353E_MADCTL_MX | HX8353E_MADCTL_MY | HX8353E_MADCTL_RGB);
            break;
        case 1:
            _writeData(HX8353E_MADCTL_MY | HX8353E_MADCTL_MV | HX8353E_MADCTL_RGB);
            break;
        case 2:
            _writeData(HX8353E_MADCTL_RGB);
            break;
        case 3:
            _writeData(HX8353E_MADCTL_MX | HX8353E_MADCTL_MV | HX8353E_MADCTL_RGB);
            break;
    }
}
void Screen_HX8353E::_fastFill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour)
{
    if (x1 > x2) _swap(x1, x2);
    if (y1 > y2) _swap(y1, y2);
    _setWindow(x1, y1, x2, y2);
    digitalWrite(_pinDataCommand, HIGH);
    digitalWrite(_pinChipSelect, LOW);
    uint8_t hi = highByte(colour);
    uint8_t lo = lowByte(colour);
    for (uint32_t t=(uint32_t)(y2-y1+1)*(x2-x1+1); t>0; t--) {
        SPI.transfer(hi);
        SPI.transfer(lo);
    }
    digitalWrite(_pinChipSelect, HIGH);
}
void Screen_HX8353E::_setPoint(uint16_t x1, uint16_t y1, uint16_t colour)
{
    if( (x1 < 0) || (x1 >= screenSizeX()) || (y1 < 0) || (y1 >= screenSizeY()) ) return;
    _setWindow(x1, y1, x1+1, y1+1);
    _writeData16(colour);
}
void Screen_HX8353E::_setWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    switch (_orientation) {
        case 0:
            x0 += 2;
            y0 += 3;
            x1 += 2;
            y1 += 3;
            break;
        case 1:
            x0 += 3;
            y0 += 2;
            x1 += 3;
            y1 += 2;
            break;
        case 2:
            x0 += 2;
            y0 += 1;
            x1 += 2;
            y1 += 1;
            break;
        case 3:
            x0 += 1;
            y0 += 2;
            x1 += 1;
            y1 += 2;
            break;
        default:
            break;
    }
    _writeCommand(HX8353E_CASET);
    _writeData16(x0);
    _writeData16(x1);
    _writeCommand(HX8353E_RASET);
    _writeData16(y0);
    _writeData16(y1);
    _writeCommand(HX8353E_RAMWR);
}
void Screen_HX8353E::_writeRegister(uint8_t command8, uint8_t data8)
{
    _writeCommand(command8);
    _writeData(data8);
}
void Screen_HX8353E::_writeCommand(uint8_t command8)
{
    digitalWrite(_pinDataCommand, LOW);
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer(command8);
    digitalWrite(_pinChipSelect, HIGH);
}
void Screen_HX8353E::_writeData(uint8_t data8)
{
    digitalWrite(_pinDataCommand, HIGH);
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer(data8);
    digitalWrite(_pinChipSelect, HIGH);
}
void Screen_HX8353E::_writeData16(uint16_t data16)
{
    digitalWrite(_pinDataCommand, HIGH);
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer(highByte(data16));
    SPI.transfer(lowByte(data16));
    digitalWrite(_pinChipSelect, HIGH);
}
void Screen_HX8353E::_writeData88(uint8_t dataHigh8, uint8_t dataLow8)
{
    digitalWrite(_pinDataCommand, HIGH);
    digitalWrite(_pinChipSelect, LOW);
    SPI.transfer(dataHigh8);
    SPI.transfer(dataLow8);
    digitalWrite(_pinChipSelect, HIGH);
}
void Screen_HX8353E::_writeData8888(uint8_t dataHigh8, uint8_t dataLow8, uint8_t data8_3, uint8_t data8_4)
{
    _writeData(dataHigh8);
    _writeData(dataLow8);
    _writeData(data8_3);
    _writeData(data8_4);
}
void Screen_HX8353E::_getRawTouch(uint16_t &x0, uint16_t &y0, uint16_t &z0)
{
    x0 = 0;
    y0 = 0;
    z0 = 0;
}
