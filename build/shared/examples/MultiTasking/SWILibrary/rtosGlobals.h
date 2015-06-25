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
/// @version    101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// PUSH1
// Solution 1: polling
// Solution 2: Energia interrupt
// Solution 3: HWI, actually = 2
#define SOLUTION 2


#ifndef rtosGlobals_h
#define rtosGlobals_h


// Core library
#include "Energia.h"


// Include application, user and local libraries
#include "Semaphore.h"
#include "SWI.h"
#if (SOLUTION == 3)
#   include "HWI.h"
#endif


// Prototypes


// Define variables and constants
Semaphore mySemaphore;
SWI mySWI;
#if (SOLUTION == 3)
HWI myHWI;
#endif
uint32_t chrono;

// SWI function
void functionSWI()
{
    chrono = millis();
}

#if (SOLUTION == 2)
// PUSH1 function
void functionPUSH1()
{
    mySWI.post();
}
#endif

#if (SOLUTION == 3)
// HWI function
void functionHWI()
{
    mySWI.post();
}
#endif

// Add optional rtosSetup function
void rtosSetup()
{
    Serial.begin(115200);
    mySemaphore.begin(1);
    mySWI.begin(functionSWI);
    
    mySemaphore.waitFor();
    Serial.println("rtosSetup");
    mySemaphore.post();
    
#if (SOLUTION == 2)
    // Solution 2: Energia interrupt
    pinMode(PUSH1, INPUT_PULLUP);
    attachInterrupt(PUSH1, functionPUSH1, FALLING);
#endif

#if (SOLUTION == 3)
    // Solution 3: HWI
    pinMode(PUSH1, INPUT_PULLUP);
    myHWI.begin(PUSH1, functionHWI, FALLING);
#endif
}



#endif
