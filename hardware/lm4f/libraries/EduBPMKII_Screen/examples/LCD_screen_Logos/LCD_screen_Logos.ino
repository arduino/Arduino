///
/// @mainpage	LCD_screen_Logos
///
/// @details	Energia logo for Educational BoosterPack 2
/// @n
/// @n
/// @n @a       Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embeddedcomputing.weebly.com
///
/// @date	Dec 14, 2103
/// @version	104
///
/// @copyright	(c) Rei VILO, 2013
/// @copyright	CC = BY SA NC
///
/// @see	ReadMe.txt for references
///


///
/// @file	LCD_screen_Logos.ino
/// @brief	Main sketch
///
/// @details	Energia logo for Educational BoosterPack 2
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embeddedcomputing.weebly.com
/// @date	26/07/13 20:26
/// @version	<#version#>
///
/// @copyright	(c) Rei VILO, 2013
/// @copyright	CC = BY SA NC
///
/// @see	ReadMe.txt for references
/// @n
///


// Core library for code-sense
#include "Energia.h"

// Following includes for Energia only
#include "SPI.h"

#include "Screen_HX8353E.h"
Screen_HX8353E myScreen;

// Define variables and constants
uint32_t chrono;

#include "Energia_logo_100_132.h"
void logo50()
{
    uint32_t p;
    uint16_t c;
    uint16_t x00 = 0;
    uint16_t y00 = 0;
    uint16_t i00 = 0;
    uint16_t j00 = 0;
    
    if ((myScreen.screenSizeX() > x_Energia_logo_100_132_bmp)) {
        x00 = (myScreen.screenSizeX() - x_Energia_logo_100_132_bmp) / 2;
    } else {
        i00 = (x_Energia_logo_100_132_bmp - myScreen.screenSizeX()) / 2;
    }
    if ((myScreen.screenSizeY() > y_Energia_logo_100_132_bmp)) {
        y00 = (myScreen.screenSizeY() - y_Energia_logo_100_132_bmp) / 2;
    } else {
        j00 = (y_Energia_logo_100_132_bmp - myScreen.screenSizeY()) / 2;
    }
    p = (uint32_t)x_Energia_logo_100_132_bmp * y_Energia_logo_100_132_bmp;
    
    for (uint16_t i=0; i<x_Energia_logo_100_132_bmp; i++) {
        for (uint16_t j=0; j<y_Energia_logo_100_132_bmp; j++) {
            if ((x00+i < myScreen.screenSizeX()) && (y00+j < myScreen.screenSizeY())) {
                c = pic_Energia_logo_100_132_bmp[i*y_Energia_logo_100_132_bmp + j];
                myScreen.point(x00+i-i00, y00+j-j00, c);
            }
        }
    }
}

// Add setup code
void setup() {
    Serial.begin(9600);
    delay(100);
    Serial.println("WITH_LOGO example for LCD_screen");
    
    myScreen.begin();
    String s = myScreen.WhoAmI();
    myScreen.setOrientation(0);
}

// Add loop code
void loop() {
    myScreen.clear(whiteColour);
    Serial.print("logo50... ");
    chrono = millis();
    logo50();
    Serial.println(millis() - chrono, DEC);
    delay(2000);
}


