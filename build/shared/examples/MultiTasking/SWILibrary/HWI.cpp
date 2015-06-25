//
// HWI.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode+
// http://embedXcode.weebly.com
//
// Project 		EMT-HWI
//
// Created by 	Rei Vilo, Jun 08, 2015 09:53
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015
// Licence		CC = BY SA NC
//
// See 			HWI.h and ReadMe.txt for references
//


// Library header
#include "HWI.h"


// Code
/*
 UInt HWIKey;
 
 void disableHWI()
 {
 HWIKey = Hwi_disable();
 }
 
 void restoreHWI()
 {
 Hwi_restore(HWIKey);
 }
 */

HWI::HWI()
{
    ;
}

void HWI::begin(uint8_t pinNumber, void (*functionHWI)(void), int mode)
{
//    Error_Block eb;
//    Error_init(&eb);
//    
//    Hwi_Params hwiParams;
//    Hwi_Params_init(&hwiParams);
//    
//    HWIHandle = Hwi_create(interruptNumber, (Hwi_FuncPtr)functionHWI, &hwiParams, &eb);
    
    // from msp432/cores/msp432/WInterrupts.c
    HWIpin = pinNumber;
    GPIO_PinConfig intType;
    
    switch (mode) {
        case LOW:
            intType = GPIO_CFG_IN_INT_LOW;
            break;
        case CHANGE:
            intType = GPIO_CFG_IN_INT_BOTH_EDGES;
            break;
        case RISING:
            intType = GPIO_CFG_IN_INT_RISING;
            break;
        case FALLING:
            intType = GPIO_CFG_IN_INT_FALLING;
            break;
        case HIGH:
            intType = GPIO_CFG_IN_INT_HIGH;
            break;
    }
    
    GPIO_setConfig(pinNumber, GPIO_CFG_IN_INT_ONLY | intType);
    
    GPIO_setCallback(pinNumber, (GPIO_CallbackFxn)functionHWI);
    
    GPIO_enableInt(pinNumber);
}

void HWI::clearInterrupt()
{
        GPIO_setCallback(HWIpin, NULL);

}

