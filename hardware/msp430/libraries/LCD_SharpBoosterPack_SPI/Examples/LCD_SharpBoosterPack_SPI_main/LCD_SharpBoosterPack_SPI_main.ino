///
/// @mainpage	Sharp BoosterPackLCD SPI
///
/// @details	Library for Sharp BoosterPack LCD with hardware SPI
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
/// @file	LCD_SharpBoosterPack_SPI_main.ino
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

// Include application, user and local libraries
#include "SPI.h"
#include "LCD_SharpBoosterPack_SPI.h"

// Variables
/// P._. / PB_4 = SCK (2) = Serial Clock
/// P._. / PB_7 = MOSI (2) = Serial Data

#if defined(__MSP430G2553__)
LCD_SharpBoosterPack_SPI myScreen;
#elif defined(__MSP430FR5969__)
LCD_SharpBoosterPack_SPI myScreen;
#elif defined(__LM4F120H5QR__)
LCD_SharpBoosterPack_SPI myScreen(
                      6,    // Chip Select
                      2,    // DISP
                      5);  // Push Button 2
#endif
uint8_t k = 0;


// Add setup code
void setup() {
#if defined(__MSP430G2553__)
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    
#elif defined(__MSP430FR5969__)
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
    
    myScreen.text(0, 0, "Hello!");
    
    delay(1000);
    myScreen.clear();
    myScreen.text(0, 5, "Light off");
}

// Add loop code
void loop() {
    
    myScreen.setFont(1);
    if (k==0)   myScreen.text(0, 2, " MSP430");
    else if (k==8)   myScreen.text(0, 2, "  LM4F  ");
    
    myScreen.setFont(0);
    for (uint8_t i=0; i<14; i++) myScreen.text(i, 4, (i==k) ? "*" : " ");
    k ++;
    k %= 14;
    
    delay(200);
}