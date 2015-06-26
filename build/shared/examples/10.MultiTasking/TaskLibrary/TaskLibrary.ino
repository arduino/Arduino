///
/// @mainpage	EMT-Task
///
/// @details	Task Library for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 23, 2015 10:32
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		EMT_Task.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 23, 2015 10:32
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


// Prototypes


// Define variables and constants
uint8_t valueR = 0;

// Add setup code
void setup()
{
    pinMode(RED_LED, OUTPUT);
}

// Add loop code
void loop()
{
    valueR = 1 - valueR;
    digitalWrite(RED_LED, valueR);
    delay(1000);
}
