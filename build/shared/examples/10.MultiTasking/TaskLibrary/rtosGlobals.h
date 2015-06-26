///
/// @file		rtosGlobals.h
/// @brief		Global variables for Energia MT project
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 23, 2015 10:32
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library
#include "Energia.h"
#include "Task.h"
#include "Timer.h"

#ifndef rtosGlobals_h
#define rtosGlobals_h

// Include application, user and local libraries


// Prototypes
void functionTask();


// Define variables and constants
Task myTask;
Timer myTimer;
uint8_t valueB = 0;

void functionTask()
{
    //    // Solution 1: with loop, works fine
    //    while (true)
    //    {
    //        valueB = 1 - valueB;
    //        digitalWrite(BLUE_LED, valueB);
    //        delay(333);
    //    }
    //
    //    // Solution 2: with delay, doesn't work
    //    valueB = 1 - valueB;
    //    digitalWrite(BLUE_LED, valueB);
    //    delay(333);
    
    // Solution 3: with Timer, works fine
    valueB = 1 - valueB;
    digitalWrite(BLUE_LED, valueB);
}

// Add optional rtosSetup function
void rtosSetup()
{
    pinMode(BLUE_LED, OUTPUT);
    myTask.begin(functionTask, Task_numPriorities - 1);
    
    // Solution 3: with Timer, works fine
    myTimer.begin(functionTask, 333);
    myTimer.start();
}

#endif
