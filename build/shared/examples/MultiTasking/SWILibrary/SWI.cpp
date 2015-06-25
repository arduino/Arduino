//
// SWI.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode+
// http://embedXcode.weebly.com
//
// Project 		EMT-SWI
//
// Created by 	Rei Vilo, Jun 08, 2015 09:53
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015
// Licence		CC = BY SA NC
//
// See 			SWI.h and ReadMe.txt for references
//


// Library header
#include "SWI.h"


// Code
/*
 UInt SWIKey;
 
 void disableSWI()
 {
 SWIKey = Swi_disable();
 }
 
 void restoreSWI()
 {
 Swi_restore(SWIKey);
 }
 */

SWI::SWI()
{
    ;
}

void SWI::begin(void (*functionSWI)(void))
{
    Error_Block eb;
    Error_init(&eb);
    
    Swi_Params swiParams;
    Swi_Params_init(&swiParams);
    
    SWIHandle = Swi_create((Swi_FuncPtr)functionSWI, &swiParams, &eb);
}

void SWI::post()
{
    Swi_post(SWIHandle);
}

