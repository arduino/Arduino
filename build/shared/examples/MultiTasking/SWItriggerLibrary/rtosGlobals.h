///
/// @file		rtosGlobals.h
/// @brief		Global variables for Energia MT project
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 17:06
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///

#ifndef rtosGlobals_h
#define rtosGlobals_h


// Core library
#include "Energia.h"


// Include application, user and local libraries
#include "Semaphore.h"
#include "SWItrigger.h"
#include "Event.h"

// Prototypes


// Define variables and constants
Semaphore mySemaphore;
SWItrigger mySWItrigger;
Event myEvent;
uint32_t chrono;

// SWItrigger function
//void functionSWItrigger(uint8_t number)
void functionSWItrigger()
{
    chrono = millis();
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    myEvent.send();
}

// PUSH1 function
void functionPUSH1()
{
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);

    mySWItrigger.dec();
}

// Add optional rtosSetup function
void rtosSetup()
{
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    
    Serial.begin(115200);
    mySemaphore.begin(1);
    mySWItrigger.begin(3, functionSWItrigger);
    myEvent.begin();
    
    mySemaphore.waitFor();
    Serial.println("rtosSetup");
    mySemaphore.post();
    
    // Solution 2: Energia interrupt
    pinMode(PUSH1, INPUT_PULLUP);
    attachInterrupt(PUSH1, functionPUSH1, FALLING);
}



#endif
