//
// Semaphore.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode+ 
// http://embedXcode.weebly.com
//
// Project 		EMT-Semaphore
//
// Created by 	Rei Vilo, Jun 08, 2015 09:53
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015
// Licence		CC = BY SA NC
//
// See 			Semaphore.h and ReadMe.txt for references
//


// Library header
#include "Semaphore.h"

// Code
Semaphore::Semaphore()
{
    ;
}

void Semaphore::begin(uint8_t count)
{
    Error_Block eb;
    Error_init(&eb);

    Semaphore_Params params;
    Semaphore_Params_init(&params);
    
    SemaphoreHandle = Semaphore_create(count, &params, &eb);

    if (SemaphoreHandle == NULL)
    {
        System_abort("Semaphore create failed");
    }
}

void Semaphore::waitFor()
{
    Semaphore_pend(SemaphoreHandle, BIOS_WAIT_FOREVER);
}

uint16_t Semaphore::available()
{
    return Semaphore_getCount(SemaphoreHandle);
}

void Semaphore::post()
{
    Semaphore_post(SemaphoreHandle);
}
