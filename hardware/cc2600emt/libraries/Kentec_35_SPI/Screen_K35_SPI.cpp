//
// Screen_K35_SPI.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode
// http://embedXcode.weebly.com
//
// Project LCD_screen Library Suite
//
// Created by Rei VILO, Jun 29, 2013
// embedXcode.weebly.com
//
//
// Copyright © Rei VILO, 2013-2016 - SPECIAL EDITION FOR ENERGIA
// Licence All rights reserved
//
// See LCD_document.h and ReadMe.txt for references
//

// Library header
#include "Screen_K35_SPI.h"

#if defined(__LM4F120H5QR__)
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#endif

///
/// @name	SSD2119 constants
///
/// @{

#define SSD2119_DEVICE_CODE_READ_REG  0x00
#define SSD2119_OSC_START_REG         0x00
#define SSD2119_OUTPUT_CTRL_REG       0x01
#define SSD2119_LCD_DRIVE_AC_CTRL_REG 0x02
#define SSD2119_PWR_CTRL_1_REG        0x03
#define SSD2119_DISPLAY_CTRL_REG      0x07
#define SSD2119_FRAME_CYCLE_CTRL_REG  0x0B
#define SSD2119_PWR_CTRL_2_REG        0x0C
#define SSD2119_PWR_CTRL_3_REG        0x0D
#define SSD2119_PWR_CTRL_4_REG        0x0E
#define SSD2119_GATE_SCAN_START_REG   0x0F
#define SSD2119_SLEEP_MODE_REG        0x10
#define SSD2119_ENTRY_MODE_REG        0x11
#define SSD2119_GEN_IF_CTRL_REG       0x15
#define SSD2119_PWR_CTRL_5_REG        0x1E
#define SSD2119_RAM_DATA_REG          0x22
#define SSD2119_FRAME_FREQ_REG        0x25
#define SSD2119_VCOM_OTP_1_REG        0x28
#define SSD2119_VCOM_OTP_2_REG        0x29
#define SSD2119_GAMMA_CTRL_1_REG      0x30
#define SSD2119_GAMMA_CTRL_2_REG      0x31
#define SSD2119_GAMMA_CTRL_3_REG      0x32
#define SSD2119_GAMMA_CTRL_4_REG      0x33
#define SSD2119_GAMMA_CTRL_5_REG      0x34
#define SSD2119_GAMMA_CTRL_6_REG      0x35
#define SSD2119_GAMMA_CTRL_7_REG      0x36
#define SSD2119_GAMMA_CTRL_8_REG      0x37
#define SSD2119_GAMMA_CTRL_9_REG      0x3A
#define SSD2119_GAMMA_CTRL_10_REG     0x3B
#define SSD2119_V_RAM_POS_REG         0x44
#define SSD2119_H_RAM_START_REG       0x45
#define SSD2119_H_RAM_END_REG         0x46
#define SSD2119_X_RAM_ADDR_REG        0x4E
#define SSD2119_Y_RAM_ADDR_REG        0x4F

#define ENTRY_MODE_DEFAULT 0x6830
#define MAKE_ENTRY_MODE(x) ((ENTRY_MODE_DEFAULT & 0xFF00) | (x))

#define K35_WIDTH       320 // Vertical
#define K35_HEIGHT      240 // Horizontal

/// @}

#define GPIO_SLOW 0
#define GPIO_FAST 1
#define GPIO_MODE GPIO_SLOW

#if ((GPIO_MODE == GPIO_FAST) && defined(__LM4F120H5QR__))
//
// LCD control line GPIO definitions.
//
#define LCD_CS_PERIPH           SYSCTL_PERIPH_GPIOA
#define LCD_CS_BASE             GPIO_PORTA_BASE
#define LCD_CS_PIN              GPIO_PIN_4
#define LCD_DC_PERIPH           SYSCTL_PERIPH_GPIOA
#define LCD_DC_BASE             GPIO_PORTA_BASE
#define LCD_DC_PIN              GPIO_PIN_5

#endif


///
/// @name   Touch constants
///
/// @{

#define TOUCH_TRIM  0x10 ///< Touch threshold
#define TOUCH_XP 23 // A7      ///< 23 PD_0  // must be an analog pin, use "An" notation!
#define TOUCH_YP 24 // A6      ///< 24 PD_1  // must be an analog pin, use "An" notation!
#define TOUCH_XN 11 // PA_2    ///< 11 can be a digital pin
#define TOUCH_YN 31 // PF_4    ///< 31 can be a digital pin

/// @}


///
/// @brief	Solution for touch on MSP432 ADC
/// MSP432 14-bit but 10-bit available by default
/// * Solution 1: keep 10-bit
/// * Solution 2: set to 12-bit with
///
#define MSP432_SOLUTION 1

#if defined(__MSP432P401R__)
#   if (MSP432_SOLUTION == 1)
// Solution 1: MSP432 14-bit but 10-bit available by default
#       define ANALOG_RESOLUTION 1023
#   else
// Solution 2: MSP432 14-bit set to 12-bit
#       define ANALOG_RESOLUTION 4095
#   endif
#else
// LM4F TM4C F5529 12-bit
#   define ANALOG_RESOLUTION 4095
#endif


// Code
Screen_K35_SPI::Screen_K35_SPI()
{
    // Use pins numbers, as pins names are deprecated
    _pinScreenDataCommand = 8;  // PA_5
    _pinScreenReset       = 32; // PD_7
    _pinScreenChipSelect  = 13; // PA_4
    _pinScreenBackLight   = 40; // PF_2 PWM, not connected
}

void Screen_K35_SPI::begin()
{
    
#if defined(__LM4F120H5QR__) || defined(__TM4C123GH6PM__) || defined(__TM4C129XNCZAD__)
    SPI.setModule(2);
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    
#else
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    
#endif
    
    pinMode(_pinScreenDataCommand, OUTPUT);
    pinMode(_pinScreenReset, OUTPUT);
    pinMode(_pinScreenChipSelect, OUTPUT);
    pinMode(_pinScreenBackLight, OUTPUT);
    analogWrite(_pinScreenBackLight, 127);
    
#if (GPIO_MODE == GPIO_FAST)
    //
    // Enable GPIOs
    //
    SysCtlPeripheralEnable(LCD_DC_PERIPH);
    SysCtlPeripheralEnable(LCD_CS_PERIPH);
    
    //
    // GPIOs as OUTPUT
    //
    GPIOPinTypeGPIOOutput(LCD_DC_BASE, LCD_DC_PIN);
    GPIOPinTypeGPIOOutput(LCD_CS_BASE, LCD_CS_PIN);
    
    //
    // Default values
    //
    GPIOPinWrite(LCD_CS_BASE, LCD_CS_PIN, LCD_CS_PIN);
    GPIOPinWrite(LCD_DC_BASE, LCD_DC_PIN, 0x00);
    GPIOPinWrite(LCD_CS_BASE, LCD_CS_PIN, 0);
    HWREG(LCD_DC_BASE + GPIO_O_DATA + (LCD_DC_PIN << 2)) = LCD_DC_PIN;          // HIGH = data
    
#else
    //
    // Default values
    //
    digitalWrite(_pinScreenDataCommand, HIGH);
    digitalWrite(_pinScreenChipSelect, HIGH);
    digitalWrite(_pinScreenReset, HIGH);
    
#endif
    
    delayMicroseconds(2000); // delay(2);
    
    //
    // RESET cycle
    //
    digitalWrite(_pinScreenReset, HIGH);
    delayMicroseconds(10000); // delay(10);
    digitalWrite(_pinScreenReset, LOW);
    delayMicroseconds(10000); // delay(10);
    digitalWrite(_pinScreenReset, HIGH);
    
    //    //
    //    // Enter sleep mode
    //    //
    //    _writeCommand16(SSD2119_SLEEP_MODE_REG);
    //    _writeData16(0x0001);
    
    //
    // Power parameters
    //
    _writeCommand16(SSD2119_PWR_CTRL_5_REG);
    _writeData16(0x00BA);
    _writeCommand16(SSD2119_VCOM_OTP_1_REG);
    _writeData16(0x0006);
    
    //
    // Start oscillator
    //
    _writeCommand16(SSD2119_OSC_START_REG);
    _writeData16(0x0001);
    
    //
    // Set pixel format and basic display orientation
    //
    _writeCommand16(SSD2119_OUTPUT_CTRL_REG);
    _writeData16(0x30EF);
    _writeCommand16(SSD2119_LCD_DRIVE_AC_CTRL_REG);
    _writeData16(0x0600);
    
    //
    // Exit sleep mode
    //
    _writeCommand16(SSD2119_SLEEP_MODE_REG);
    _writeData16(0x0000);
    
    delayMicroseconds(30000); // delay(30);
    
    //
    // Pixel color format
    //
    _writeCommand16(SSD2119_ENTRY_MODE_REG);
    _writeData16(ENTRY_MODE_DEFAULT);
    
    //
    // Enable  display
    //
    _writeCommand16(SSD2119_DISPLAY_CTRL_REG);
    _writeData16(0x0033);
    
    //
    // Set VCIX2 voltage to 6.1V
    //
    _writeCommand16(SSD2119_PWR_CTRL_2_REG);
    _writeData16(0x0005);
    
    //
    // Gamma correction
    //
    _writeCommand16(SSD2119_GAMMA_CTRL_1_REG);
    _writeData16(0x0000);
    _writeCommand16(SSD2119_GAMMA_CTRL_2_REG);
    _writeData16(0x0400);
    _writeCommand16(SSD2119_GAMMA_CTRL_3_REG);
    _writeData16(0x0106);
    _writeCommand16(SSD2119_GAMMA_CTRL_4_REG);
    _writeData16(0x0700);
    _writeCommand16(SSD2119_GAMMA_CTRL_5_REG);
    _writeData16(0x0002);
    _writeCommand16(SSD2119_GAMMA_CTRL_6_REG);
    _writeData16(0x0702);
    _writeCommand16(SSD2119_GAMMA_CTRL_7_REG);
    _writeData16(0x0707);
    _writeCommand16(SSD2119_GAMMA_CTRL_8_REG);
    _writeData16(0x0203);
    _writeCommand16(SSD2119_GAMMA_CTRL_9_REG);
    _writeData16(0x1400);
    _writeCommand16(SSD2119_GAMMA_CTRL_10_REG);
    _writeData16(0x0F03);
    
    //
    // Configure Vlcd63 and VCOMl
    //
    _writeCommand16(SSD2119_PWR_CTRL_3_REG);
    _writeData16(0x0007);
    _writeCommand16(SSD2119_PWR_CTRL_4_REG);
    _writeData16(0x3100);
    
    //
    // Display size and GRAM window
    //
    _writeCommand16(SSD2119_V_RAM_POS_REG);
    _writeData16((K35_HEIGHT-1) << 8);
    _writeCommand16(SSD2119_H_RAM_START_REG);
    _writeData16(0x0000);
    _writeCommand16(SSD2119_H_RAM_END_REG);
    _writeData16(K35_WIDTH-1);
    _writeCommand16(SSD2119_X_RAM_ADDR_REG);
    _writeData16(0x00);
    _writeCommand16(SSD2119_Y_RAM_ADDR_REG);
    _writeData16(0x00);
    
    // Standard
    setOrientation(1);
    
    _screenWidth  = K35_HEIGHT;
    _screenHeigth = K35_WIDTH;
    //    _screenDiagonal = 35;
    setFontSize(0);
    
    // Touch
    uint16_t x0, y0, z0;
    _getRawTouch(x0, y0, z0);
    
    // Touch calibration
    _touchTrim = TOUCH_TRIM;
    
#if (ANALOG_RESOLUTION == 4095)
#   warning ANALOG_RESOLUTION == 4095
    _touchXmin = 3077;
    _touchXmax = 881;
    _touchYmin = 3354;
    _touchYmax = 639;
#elif (ANALOG_RESOLUTION == 1023)
#   warning ANALOG_RESOLUTION == 1023
    _touchXmin = 837;
    _touchXmax = 160;
    _touchYmin = 898;
    _touchYmax = 114;
#else
#error Wrong
#endif
    
    _penSolid  = false;
    _fontSolid = true;
    _flagRead  = false;
    //    _flagIntensity = true;
    //    _fsmArea   = true;
    //    _touchTrim = 10;
    
    // Solution 2: MSP432 14-bit set to 12-bit
#if defined(__MSP432P401R__) && (MSP432_SOLUTION == 2)
    analogReadResolution(12);
#endif
    
#if (ANALOG_RESOLUTION == 4095)
    _touchTrim *= 4;
#endif
    
    clear();
}

String Screen_K35_SPI::WhoAmI()
{
    return "Kentec 3.5\" SPI screen";
}

void Screen_K35_SPI::_setOrientation(uint8_t orientation)
{
    // default = 0x6830 = 0x68 <<8 + 0b00110000
    switch (_orientation) {
        case 0:
            //                                                  hvO
            _writeRegister(SSD2119_ENTRY_MODE_REG, 0x6800 + 0b00101000);        // ok
            break;
        case 1:
            //                                                  hvO
            _writeRegister(SSD2119_ENTRY_MODE_REG, 0x6800 + 0b00000000);        // ok
            break;
        case 2:
            //                                                  hvO
            _writeRegister(SSD2119_ENTRY_MODE_REG, 0x6800 + 0b00011000);        // ok
            break;
        case 3:
            //                                                  hvO
            _writeRegister(SSD2119_ENTRY_MODE_REG, 0x6800 + 0b00110000);        // ok
            break;
    }
}

// Utilities
void Screen_K35_SPI::_writeData16(uint16_t data16)
{
    _writeData88(data16 >> 8, data16);
}

void Screen_K35_SPI::_writeData88(uint8_t dataHigh8, uint8_t dataLow8)
{
#if (GPIO_MODE == GPIO_FAST)
    
    HWREG(LCD_DC_BASE + GPIO_O_DATA + (LCD_DC_PIN << 2)) = LCD_DC_PIN;          // HIGH = data
    HWREG(LCD_CS_BASE + GPIO_O_DATA + (LCD_CS_PIN << 2)) = 0;                   // CS LOW
    
    SPI.transfer(dataHigh8);
    SPI.transfer(dataLow8);
    
    HWREG(LCD_CS_BASE + GPIO_O_DATA + (LCD_CS_PIN << 2)) = LCD_CS_PIN;          // CS HIGH
    
#else
    
    digitalWrite(_pinScreenDataCommand, HIGH);                                  // HIGH = data
    digitalWrite(_pinScreenChipSelect, LOW);                                    // CS LOW
    
    SPI.transfer(dataHigh8);
    SPI.transfer(dataLow8);
    
    digitalWrite(_pinScreenChipSelect, HIGH);                                   // CS HIGH
    
#endif
}

//*****************************************************************************
//
// Writes a command to the SSD2119.  This function implements the basic GPIO
// interface to the LCD display.
//
//*****************************************************************************
void Screen_K35_SPI::_writeCommand16(uint16_t command16)
{
#if (GPIO_MODE == GPIO_FAST)
    HWREG(LCD_CS_BASE + GPIO_O_DATA + (LCD_DC_PIN << 2)) = 0;                   // LOW = command
    HWREG(LCD_CS_BASE + GPIO_O_DATA + (LCD_CS_PIN << 2)) = 0;                   // CS LOW
    
    SPI.transfer(command16 & 0xff);
    
    HWREG(LCD_CS_BASE + GPIO_O_DATA + (LCD_CS_PIN << 2)) = LCD_CS_PIN;          // CS HIGH
    HWREG(LCD_DC_BASE + GPIO_O_DATA + (LCD_DC_PIN << 2)) = LCD_DC_PIN;          // HIGH = data
    
#else
    
    digitalWrite(_pinScreenDataCommand, LOW);                                   // LOW = command
    digitalWrite(_pinScreenChipSelect, LOW);                                    // CS LOW
    
    SPI.transfer(command16 & 0xff);
    
    digitalWrite(_pinScreenChipSelect, HIGH);                                   // CS HIGH
    digitalWrite(_pinScreenDataCommand, HIGH);                                  // HIGH = data
    
#endif
}

void Screen_K35_SPI::_writeRegister(uint8_t command8, uint16_t data16)
{
    _writeCommand16(command8);
    _writeData16(data16);
}

void Screen_K35_SPI::_orientCoordinates(uint16_t &x1, uint16_t &y1)
{
    switch (_orientation) {
        case 0:                                                                 // ok
            y1 = screenSizeY()-1 - y1;
            _swap(x1, y1);
            break;
        case 1:                                                                 // ok
            x1 = screenSizeX() - x1 -1;
            y1 = screenSizeY() - y1 -1;
            break;
        case 2:                                                                 // ok
            x1 = screenSizeX() - x1 -1;
            _swap(x1, y1);
            break;
        case 3:                                                                 // ok
            break;
    }
}

void Screen_K35_SPI::_setPoint(uint16_t x1, uint16_t y1, uint16_t colour)           // compulsory
{
    _setCursor(x1, y1);
    _writeData16(colour);
}

void Screen_K35_SPI::_setCursor(uint16_t x1, uint16_t y1)
{
    _orientCoordinates(x1, y1);
    _writeRegister(SSD2119_X_RAM_ADDR_REG, x1);
    _writeRegister(SSD2119_Y_RAM_ADDR_REG, y1);
    
    _writeCommand16(SSD2119_RAM_DATA_REG);
}

void Screen_K35_SPI::_setWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    _orientCoordinates(x1, y1);
    _orientCoordinates(x2, y2);
    
    _writeRegister(SSD2119_X_RAM_ADDR_REG, x1);
    _writeRegister(SSD2119_Y_RAM_ADDR_REG, y1);
    
    if (x1 > x2) _swap(x1, x2);
    if (y1 > y2) _swap(y1, y2);
    
    _writeCommand16(SSD2119_V_RAM_POS_REG);
    _writeData88(y2, y1);
    _writeRegister(SSD2119_H_RAM_START_REG, x1);
    _writeRegister(SSD2119_H_RAM_END_REG, x2);
    
    _writeCommand16(SSD2119_RAM_DATA_REG);
}

void Screen_K35_SPI::_closeWindow()
{
    _setWindow(0, 0, screenSizeX()-1, screenSizeY()-1);
}

inline uint16_t absDiff(uint16_t a, uint16_t b) { return (a > b) ? a-b : b-a; }

void Screen_K35_SPI::_fastFill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour)
{
    if (x1 > x2) _swap(x1, x2);
    if (y1 > y2) _swap(y1, y2);
    
    uint8_t highColour = highByte(colour);
    uint8_t lowColour  = lowByte(colour);
    
    _setWindow(x1, y1, x2, y2);
    for (uint32_t t=(uint32_t)(y2-y1+1)*(x2-x1+1); t>0; t--) {
        _writeData88(highColour, lowColour);
    }
}

// Touch
void Screen_K35_SPI::_getRawTouch(uint16_t &x0, uint16_t &y0, uint16_t &z0)
{
    // --- 2015-08-04 _getRawTouch revised entirely
    // Tested against MSP432, F5529 and LM4F/TM4C
    // However, the calibrateTouch() may throw wrong results
    //
    int16_t a, b, c, d;
    bool flag;
    
#if defined(__MSP432P401R__)
    pinMode(TOUCH_YP, OUTPUT);
    pinMode(TOUCH_YN, OUTPUT);
    pinMode(TOUCH_XP, OUTPUT);
    pinMode(TOUCH_XN, OUTPUT);
    digitalWrite(TOUCH_YP, LOW);
    digitalWrite(TOUCH_YN, LOW);
    digitalWrite(TOUCH_XP, LOW);
    digitalWrite(TOUCH_XN, LOW);
    
    delayMicroseconds(1000); // delay(1);
#endif
    
    do {
        flag = false;
        
        // Read x
        // xp = +Vref
        // xn = ground
        // yp = measure
        // yn = open
#ifndef ENERGIA
        digitalWrite(TOUCH_YP, LOW);
        digitalWrite(TOUCH_YN, LOW);
#endif
        pinMode(TOUCH_YP, INPUT);
        pinMode(TOUCH_YN, INPUT);
        
        pinMode(TOUCH_XP, OUTPUT);
        pinMode(TOUCH_XN, OUTPUT);
        digitalWrite(TOUCH_XP, HIGH);
        digitalWrite(TOUCH_XN, LOW);
        
        delayMicroseconds(1000); // delay(1);
        a = analogRead(TOUCH_YP);
        delayMicroseconds(1000); // delay(1);
        b = analogRead(TOUCH_YP);
        
        flag |= (absDiff(a, b) > 8);
        x0  = ANALOG_RESOLUTION - a;
        
        // Read y
        // xp = measure
        // xn = open
        // yp = +Vref
        // yn = ground
#ifndef ENERGIA
        digitalWrite(TOUCH_XP, LOW);
        digitalWrite(TOUCH_XN, LOW);
#endif
        pinMode(TOUCH_XP, INPUT);
        pinMode(TOUCH_XN, INPUT);
        
        pinMode(TOUCH_YP, OUTPUT);
        pinMode(TOUCH_YN, OUTPUT);
        digitalWrite(TOUCH_YP, HIGH);
        digitalWrite(TOUCH_YN, LOW);
        
        delayMicroseconds(1000); // delay(1);
        c = analogRead(TOUCH_XP);
        delayMicroseconds(1000); // delay(1);
        d = analogRead(TOUCH_XP);
        
        flag |= (absDiff(c, d) > 8);
        y0  = ANALOG_RESOLUTION - c;
        
        // Read z
        // xp = ground
        // xn = measure
        // yp = measure
        // yn = +Vref
        pinMode(TOUCH_XP, OUTPUT);
        pinMode(TOUCH_YN, OUTPUT);
        digitalWrite(TOUCH_XP, LOW);
        digitalWrite(TOUCH_YN, HIGH);
        
#ifndef ENERGIA
        digitalWrite(TOUCH_XN, LOW);
        digitalWrite(TOUCH_YP, LOW);
#endif
        pinMode(TOUCH_XN, INPUT);
        pinMode(TOUCH_YP, INPUT);
        
        delayMicroseconds(1000); // delay(1);
        a = analogRead(TOUCH_XN);
        delayMicroseconds(1000); // delay(1);
        c = analogRead(TOUCH_YP);
        delayMicroseconds(1000); // delay(1);
        b = analogRead(TOUCH_XN);
        delayMicroseconds(1000); // delay(1);
        d = analogRead(TOUCH_YP);
        
        flag |= (absDiff(a, b) > 8);
        flag |= (absDiff(c, d) > 8);
        // z0 = (ANALOG_RESOLUTION - (c-a));
        // Because a = TOUCH_XN non analog, remove a
        z0 = ANALOG_RESOLUTION - c;
    }
    while (flag);
}

void Screen_K35_SPI::_setBacklight(bool flag)
{
    if (flag)   _writeRegister(SSD2119_SLEEP_MODE_REG, 0);
    else        _writeRegister(SSD2119_SLEEP_MODE_REG, 1);
}

void Screen_K35_SPI::_setIntensity(uint8_t intensity)
{
    analogWrite(_pinScreenBackLight, intensity);
}


//#endif // end __LM4F120H5QR__
