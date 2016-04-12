///
/// @mainpage	LCD_Joystick
///
/// @details	Joystick controlled cursor
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		11/12/2013 10:19
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2013
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		LCD_Joystick.ino
/// @brief		Main sketch
///
/// @details	Joystick controlled cursor
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		11/12/2013 10:19
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2013
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense
#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

// Prototypes


// Include application, user and local libraries
#include <SPI.h>

#include <LCD_screen.h>
#include <LCD_screen_font.h>
#include <LCD_utilities.h>
#include <Screen_HX8353E.h>
#include <Terminal12e.h>
#include <Terminal6e.h>
#include <Terminal8e.h>
Screen_HX8353E myScreen;


// Define variables and constants
#define joystickX 2
#define joystickY 26
uint16_t x, y, x00, y00;
uint16_t colour;
uint32_t z;


// Add setup code
void setup()
{
    Serial.begin(9600); // for LCD debug output

    // By default MSP432 has analogRead() set to 10 bits. 
    // This Sketch assumes 12 bits. Uncomment to line below to set analogRead()
    // to 12 bit resolution for MSP432.
    //analogReadResolution(12);

    myScreen.begin();
    x00 = 0;
    y00 = 0;
}

// Add loop code
void loop()
{
    x = map(analogRead(joystickX), 0, 4096, 0, 128);
    y = map(analogRead(joystickY), 0, 4096, 128, 0);
    if (x < 1)      x = 1;
    if (x > 126)    x = 126;
    if (y < 1)      y = 1;
    if (y > 126)    y = 126;
    
    if ((x00 != x) || (y00 != y)) {
        z = (uint32_t)((x-64)*(x-64)+(y-64)*(y-64)) >> 8;
        if (z > 4)      colour = redColour;
        else if (z > 1) colour = yellowColour;
        else            colour = greenColour;
        
        myScreen.dRectangle(x00-1, y00-1, 3, 3, blackColour);
        myScreen.dRectangle(x-1, y-1, 3, 3, colour);
        x00 = x;
        y00 = y;
    }
    
    
    myScreen.gText(0, myScreen.screenSizeY()-myScreen.fontSizeY(),
                   "x=" + i32toa((int16_t)x-64, 10, 1, 6) +" y=" + i32toa(64-(int16_t)y, 10, 1, 6),
                   colour);
}
