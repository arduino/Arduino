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
#include "Semaphore.h"

// Prototypes


// Define variables and constants


// the setup routine runs once when you press reset:
void setup()
{
#if defined(optionSemaphore)

    // 1 is the recommended value as there is one single Serial port.
    // Try with 3 to show the remaining count
    mySemaphore.begin(1);
#endif
    
    Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop()
{
#if defined(optionSemaphore)
    mySemaphore.waitFor();
#endif

    Serial.print(millis(), DEC);
    Serial.print("\t: mySemaphore1    1   (");
#if defined(optionSemaphore)
    Serial.print(mySemaphore.available(), DEC);
#else
    Serial.print("-");
#endif
    Serial.println(")");
    
#if defined(optionSemaphore)
    mySemaphore.post();
#endif

    delay(70);
}

