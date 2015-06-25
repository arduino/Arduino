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
int value2 = 0;


// Setup
void LED2_setup()
{
    Serial.begin(115200);
    pinMode(GREEN_LED, OUTPUT);
}

// Loop
void LED2_loop()
{
    // AND
    // myEvent2.waitFor(Event_Id_02 + Event_Id_03, Event_Id_NONE);
    // OR
    uint32_t events = myEvent2.waitFor(Event_Id_NONE, Event_Id_02 + Event_Id_03);
    
    value2 = 1 - value2;
    digitalWrite(GREEN_LED, value2);
    Serial.print("(");
    Serial.print(events, BIN);
    Serial.print(")");
    Serial.print("G");
}

