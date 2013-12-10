//#############################################################################
//
//! \file   f2802x_common/source/timer.c
//!
//! \brief  Contains the various functions related to the timer (TIMER) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include "DSP28x_Project.h"
#include "f2802x_common/include/timer.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

void TIMER_clearFlag(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // set the bits
    timer->TCR |= (uint32_t)TIMER_TCR_TIF_BITS;

    return;
} // end of TIMER_clearFlag() function


void TIMER_disableInt(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // clear the bits
    timer->TCR &= (~(uint32_t)TIMER_TCR_TIE_BITS);

    return;
} // end of TIMER_disableInt() function


void TIMER_enableInt(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // set the bits
    timer->TCR |= (uint32_t)TIMER_TCR_TIE_BITS;

    return;
} // end of TIMER_enableInt() function


TIMER_Status_e TIMER_getStatus(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // get the status
    TIMER_Status_e status = (TIMER_Status_e)(timer->TCR & (uint32_t)TIMER_TCR_TIF_BITS);

    return(status);
} // end of TIMER_getStatus() function


TIMER_Handle TIMER_init(void *pMemory, const size_t numBytes)
{
    TIMER_Handle timerHandle;


    if(numBytes < sizeof(TIMER_Obj))
    return((TIMER_Handle)NULL);

    // assign the handle
    timerHandle = (TIMER_Handle)pMemory;

    return(timerHandle);
} // end of TIMER_init() function


void TIMER_reload(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // clear the bits
    timer->TCR &= (~(uint32_t)TIMER_TCR_TRB_BITS);

    return;
} // end of TIMER_reload() function


void TIMER_setDecimationFactor(TIMER_Handle timerHandle, 
                               const uint16_t decFactor)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // set the bits
    timer->TPR |= 
    ((uint32_t)(decFactor & 0xFF00) << 8) | (uint32_t)(decFactor & 0x00FF);

    return;
} // end of TIMER_setDecimationFactor() function


void TIMER_setEmulationMode(TIMER_Handle timerHandle, 
                            const TIMER_EmulationMode_e mode)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;

    
    // clear the bits
    timer->TCR &= (~(uint32_t)TIMER_TCR_FREESOFT_BITS);

    // set the bits
    timer->TCR |= (uint32_t)mode;

    return;
} // end of TIMER_setEmulationMode() function


void TIMER_setPeriod(TIMER_Handle timerHandle, 
                     const uint32_t period)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // set the bits
    timer->PRD = period;

    return;
} // end of TIMER_setPeriod() function


void TIMER_setPreScaler(TIMER_Handle timerHandle, 
                        const uint16_t preScaler)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // set the bits
    timer->TPR |= 
    ((uint32_t)(preScaler & 0xFF00) << 16) | ((uint32_t)(preScaler & 0x00FF) << 8);

    return;
} // end of TIMER_setPreScaler() function


void TIMER_start(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // clear the bits
    timer->TCR &= (~(uint32_t)TIMER_TCR_TSS_BITS);

    return;
} // end of TIMER_start() function


void TIMER_stop(TIMER_Handle timerHandle)
{
    TIMER_Obj *timer = (TIMER_Obj *)timerHandle;


    // set the bits
    timer->TCR |= (uint32_t)TIMER_TCR_TSS_BITS;

    return;
} // end of TIMER_stop() function



// end of file
