//
// SWItrigger.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode+
// http://embedXcode.weebly.com
//
// Project 		EMT-SWItrigger
//
// Created by 	Rei Vilo, Jun 08, 2015 09:53
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015
// Licence		CC = BY SA NC
//
// See 			SWItrigger.h and ReadMe.txt for references
//


// Library header
#include "SWItrigger.h"


// Code
/*
 UInt SWItriggerKey;
 
 void disableSWItrigger()
 {
 SWItriggerKey = Swi_disable();
 }
 
 void restoreSWItrigger()
 {
 Swi_restore(SWItriggerKey);
 }
 */

SWItrigger::SWItrigger()
{
    ;
}

//void SWItrigger::begin(uint8_t trigger, void (*functionSWItrigger)(uint8_t))
void SWItrigger::begin(uint8_t trigger, void (*functionSWItrigger)())
{
    Error_Block eb;
    Error_init(&eb);
    
    Swi_Params swiParams;
    Swi_Params_init(&swiParams);
    swiParams.trigger = trigger;
    
//    SWItriggerHandle = Swi_create((Swi_FuncPtr)functionSWItrigger(Swi_getTrigger()), &swiParams, &eb);
    SWItriggerHandle = Swi_create((Swi_FuncPtr)functionSWItrigger, &swiParams, &eb);

    if (SWItriggerHandle == NULL)
    {
        System_abort("SWItrigger create failed");
    }
}

void SWItrigger::post()
{
    Swi_post(SWItriggerHandle);
}

void SWItrigger::inc()
{
    Swi_inc(SWItriggerHandle);
}

void SWItrigger::dec()
{
    Swi_dec(SWItriggerHandle);
}

