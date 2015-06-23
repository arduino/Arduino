///
/// @mainpage	EMT-rtosSetup
///
/// @details	Main rtosSetup()
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 10:18
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		EMT_rtosSetup.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 10:18
/// @version	101
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
//#include "rtosGlobals.h"


// Optional rtosSetup function
// defined in main sketch or in rtosGlobals
// no delay() in rtosSetup()!
void rtosSetup()
{
    Serial.begin(115200);
    Serial.print("rtosSetup...");
    
    pinMode(BLUE_LED, OUTPUT);
    digitalWrite(BLUE_LED, HIGH);

    Serial.println("done");
}


// Prototypes


// Define variables and constants
uint8_t statusR = 1;


// Add setup code
void setup()
{
    delay(100); // to avoid scrambled Serial.print() output
    
    Serial.print("setup...");
    pinMode(RED_LED, OUTPUT);
    digitalWrite(RED_LED, statusR);
    Serial.println("done");
}

// Add loop code
void loop()
{
    statusR = 1 - statusR;
    digitalWrite(RED_LED, statusR);
    Serial.print(statusR ? "*" : "o");
    delay(500);
}
