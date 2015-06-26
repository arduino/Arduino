///
/// @mainpage	multiBlink_with_Clock
///
/// @details	Clock Library for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		18/06/2015 16:05
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		multiBlink_with_Clock.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		18/06/2015 16:05
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
#   include "Energia.h"
#else // error
#   error Platform not defined
#endif // end IDE


// Include application, user and local libraries
#include "rtosGlobals.h"
#include "Clock.h"


// Prototypes


// Define variables and constants
struct LED_t {
    uint8_t status;
    uint8_t pin;
};

LED_t ledR = { 0, RED_LED };
LED_t ledG = { 0, GREEN_LED };
LED_t ledB = { 0, BLUE_LED };


// Functions
void clockFunctionR()
{
    ledR.status = 1 - ledR.status;
    digitalWrite(ledR.pin, ledR.status);
}

void clockFunctionG()
{
    ledG.status = 1 - ledG.status;
    digitalWrite(ledG.pin, ledG.status);
}

void clockFunctionB()
{
    ledB.status = 1 - ledB.status;
    digitalWrite(ledB.pin, ledB.status);
}

// Define variables and constants
Clock myClockR;
Clock myClockG;
Clock myClockB;

// Setup
void setup()
{
    myClockR.begin(clockFunctionR, 1000, 100); // 1000 ms = 1 s
    myClockG.begin(clockFunctionG, 1000, 333); // 1000 ms = 1 s
    myClockB.begin(clockFunctionB, 1000, 500); // 1000 ms = 1 s
    
    myClockR.start();
    myClockG.start();
    myClockB.start();
}


// Loop
void loop()
{
    
}
