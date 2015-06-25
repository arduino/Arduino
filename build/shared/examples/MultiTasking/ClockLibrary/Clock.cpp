//
// Clock.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		EMT-ClockLibrary
//
// Created by 	Rei Vilo, Jun 17, 2015 09:59
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015
// Licence		CC = BY SA NC
//
// See 			Clock.h and ReadMe.txt for references
//


// Library header
#include "Clock.h"

// Code
Clock::Clock()
{
    ;
}

void Clock::begin(void (*ClockFunction)(void), uint32_t clockTimeOut_ms, uint32_t clockPeriod_ms)
{
    Error_Block eb;
    Error_init(&eb);
    
    Clock_Params params;
    Clock_Params_init(&params);

    // ClockParams.period = microsecondsToClockCycles(clockPeriod_ms); // ms to be translated into ticks
    // ClockHandle = Clock_create( (Clock_FuncPtr)ClockFunction, microsecondsToClockCycles(clockTimeOut_ms), &ClockParams, &eb);

    // Surprisingly, period already defined in ms for ClockParams.period andClockTimeOut_ms
    params.startFlag = false; // Requires Clock_start
    params.period = clockPeriod_ms;

    ClockHandle = Clock_create( (Clock_FuncPtr)ClockFunction, clockTimeOut_ms, &params, &eb);

    if (ClockHandle == NULL)
    {
        // Serial.println("*** Clock create failed");
        System_abort("Clock create failed");
    }
}

void Clock::start()
{
    Clock_start(ClockHandle);
}

void Clock::stop()
{
    Clock_stop(ClockHandle);
}
