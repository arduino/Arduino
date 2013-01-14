///
/// @mainpage	Nokia LCD 5110 SPI
///
/// @details	Library for Nokia 5110 LCD with hardware SPI
/// @n
/// @n
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	Jan 12, 2013
/// @version	105
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


///
/// @file	LCD_5110_SPI_main.ino
/// @brief	Main sketch
///
/// @details	Example for library for Nokia 5110 LCD with hardware SPI
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	Jan 12, 2013
/// @version	105
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///

#include "Energia.h"

// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Platform not defined
#endif


// Include application, user and local libraries
#include "SPI.h"
#include "LCD_5110_SPI.h"

// Variables
/// P._. / PB_4 = SCK (2) = Serial Clock
/// P._. / PB_7 = MOSI (2) = Serial Data

#if defined(__MSP430G2553__)
LCD_5110_SPI myScreen;
#elif defined(__LM4F120H5QR__)
LCD_5110_SPI myScreen(PA_7,    // Chip Select
                      PA_2,    // Data/Command
                      PB_5,    // Reset
                      PA_6,    // Backlight
                      PUSH2);  // Push Button 2
#endif
boolean	backlight = false;
uint8_t k = 0;


// Add setup code
void setup() {
#if defined(__MSP430G2553__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    
#elif defined(__LM4F120H5QR__)
    SPI.Select(2);
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV128); // for LM4F120H5QR DIV2 = 4 MHz !
#endif
    
    myScreen.begin();
    
    myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Hello!");
    
    delay(1000);
    myScreen.clear();
    myScreen.text(0, 5, "Light off");
}

// Add loop code
void loop() {
    if (myScreen.getButton()) {
        backlight = (backlight==0);
        myScreen.setFont(0);
        myScreen.text(0, 5, backlight ? "Light on " : "Light off");
        myScreen.setBacklight(backlight);
    }
    
    myScreen.setFont(1);
    if (k==0)   myScreen.text(0, 2, " MSP430");
    else if (k==8)   myScreen.text(0, 2, "  LM4F  ");
    
    myScreen.setFont(0);
    for (uint8_t i=0; i<14; i++) myScreen.text(i, 4, (i==k) ? "*" : " ");
    k ++;
    k %= 14;
    
    delay(200);
}
