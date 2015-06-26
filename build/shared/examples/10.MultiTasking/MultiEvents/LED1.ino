///
/// @file		LED1.ino
/// @brief		Task for Energia MT
/// @details	<#details#>
/// @n
/// @n @b		Project EMT-event
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		05/06/2015 21:20
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	<#license#>
///
/// @see		ReadMe.txt for references
///



// Core library for code-sense - IDE-based
#if defined(EMBEDXCODE)
#if defined(ENERGIA) && defined(__MSP432P401R__) // LaunchPad MSP432 on Energia MT only
#include "Energia.h"
#else
#error LaunchPad MSP432 on Energia MT only
#endif
#endif // end IDE

// Include application, user and local libraries
#include "rtosGlobals.h"


// Prototypes


// Define variables and constants
int value3 = 0;


// Setup
void LED1_setup()
{
    Serial.begin(115200);
    pinMode(RED_LED, OUTPUT);
}

// Loop
void LED1_loop()
{
    myEvent1.waitFor(Event_Id_01);
    value3 = 1 - value3;
    digitalWrite(RED_LED, value3);
    Serial.print("R");
}

