///
/// @file		Event2.ino
/// @brief		Task for Energia MT
/// @details	<#details#>
/// @n
/// @n @b		Project EMT-event
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		05/06/2015 21:07
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


// Setup
void Event2_setup()
{
    myEvent2.begin();
    Serial.begin(115200);
    delay(10);
}

// Loop
void Event2_loop()
{
    myEvent2.send(Event_Id_02);
    Serial.print("2");
    delay(1000);
}

