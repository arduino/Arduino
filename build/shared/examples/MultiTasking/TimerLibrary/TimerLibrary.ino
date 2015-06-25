///
/// @mainpage	EMT-TimerLibrary
///
/// @details	Timer Library for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 17, 2015 09:28
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		EMT_TimerLibrary.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 17, 2015 09:28
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
/// @example    ReadMe.txt
///


// Core library for code-sense - IDE-based
#   include "Energia.h"

// Include application, user and local libraries
//#include "rtosGlobals.h"
#include "Timer.h"

// Prototypes


// Define variables and constants
uint8_t status = 1;
const uint8_t myLED = BLUE_LED;


///
/// @brief	1st timer
///
Timer myTimer;

///
/// @brief	Function for 1st timer
/// @note   Both void and ti_sysbios_interfaces_ITimer_FuncPtr work
/// @bug    Serial.print doesn't work
///
void timerFunction()
{
    status = 1 - status;
    digitalWrite(myLED, status);
    Serial.print("1 s. ");
}

/*
 ///
 /// @brief	2nd timer
 /// @bug    Doesn't work. Only one timer allowed
 ///
 Timer myTimer2;
 
 ///
 /// @brief	Function for 2nd timer
 /// @bug    Serial.print doesn't work
 ///
 void timerFunction2()
 {
 Serial.print("1 s\t");
 }
 */

// Add setup code
void setup()
{
    Serial.begin(115200);
    pinMode(myLED, OUTPUT);
    
    Serial.print(Timer_getNumTimers(), DEC);
    Serial.println(" timers");
    
    Serial.print("myTimer.begin... ");
    myTimer.begin(timerFunction, 500);
    Serial.println("done");
    
/*
     Serial.print("myTimer2.begin... ");
     myTimer2.begin(timerFunction2, 1000);
     Serial.println("done");
 */
    
    Serial.print("myTimer.start... ");
    myTimer.start();
    Serial.println("done");

/*
     Serial.print("myTimer2.start... ");
     myTimer2.start();
     Serial.println("done");
 */
}

// Add loop code
void loop() 
{
    
}
