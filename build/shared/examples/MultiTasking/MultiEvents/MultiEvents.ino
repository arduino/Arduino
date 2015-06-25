///
/// @file		EMT_event.ino
/// @brief		Main sketch
///
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///


// Core library for code-sense - IDE-based
#include "Energia.h"

// Include application, user and local libraries
#include "rtosGlobals.h"
#include "Event.h"

// Prototypes


// Define variables and constants


// the setup routine runs once when you press reset:
void setup()
{
    myEvent1.begin();
    Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop()
{
    myEvent1.send(Event_Id_01);
    Serial.print("1");
    delay(2000);
}

