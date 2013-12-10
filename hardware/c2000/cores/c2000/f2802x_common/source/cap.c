//#############################################################################
//
//! \file   f2802x_common/source/cap.c
//!
//! \brief  Contains the various functions related to the serial 
//!         communications interface (CAP) object
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
#include "f2802x_common/include/cap.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions


CAP_Handle CAP_init(void *pMemory, const size_t numBytes)
{
    CAP_Handle capHandle;


    if(numBytes < sizeof(CAP_Obj))
    return((CAP_Handle)NULL);

    // assign the handle
    capHandle = (CAP_Handle)pMemory;
    
    return(capHandle);
} // end of CAP_init() function

void CAP_disableCaptureLoad(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;

    // clear the bits
    cap->ECCTL1 &= ~CAP_ECCTL1_CAPLDEN_BITS;

    return;
} // end of CAP_disableCaptureLoad() function

void CAP_disableSyncIn(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // set the bit
    cap->ECCTL2 &= ~CAP_ECCTL2_SYNCIEN_BITS;

    return;
} // end of CAP_disableSyncIn() function

void CAP_disableInt(CAP_Handle capHandle, const CAP_Int_Type_e intType)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECEINT &= ~intType;

    return;
} // end of CAP_disableInt() function

void CAP_disableTimestampCounter(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;

    // clear the bits
    cap->ECCTL2 &= ~CAP_ECCTL2_TSCTRSTOP_BITS;

    return;
} // end of CAP_disableTimestampCounter() function

void CAP_enableCaptureLoad(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;

    // clear the bits
    cap->ECCTL1 |= CAP_ECCTL1_CAPLDEN_BITS;

    return;
} // end of CAP_enableCaptureLoad() function

void CAP_enableInt(CAP_Handle capHandle, const CAP_Int_Type_e intType)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECEINT |= intType;

    return;
} // end of CAP_enableInt() function

void CAP_enableSyncIn(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // set the bit
    cap->ECCTL2 |= CAP_ECCTL2_SYNCIEN_BITS;

    return;
} // end of CAP_enableSyncIn() function

void CAP_enableTimestampCounter(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;

    // clear the bits
    cap->ECCTL2 |= CAP_ECCTL2_TSCTRSTOP_BITS;

    return;
} // end of CAP_enableTimestampCounter() function

void CAP_setCapEvtPolarity(CAP_Handle capHandle, const CAP_Event_e event, const CAP_Polarity_e polarity)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;

    // clear the bits
    cap->ECCTL1 &= ~(1 << (2 * event));
    
    // Set the new value
    cap->ECCTL1 |= (polarity << (2 * event));

    return;
} // end of CAP_setCapEvtPolarity() function

void CAP_setCapEvtReset(CAP_Handle capHandle, const CAP_Event_e event, const CAP_Reset_e reset)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;

    // clear the bits
    cap->ECCTL1 &= ~(1 << (1 + (2 * event)));
    
    // Set the new value
    cap->ECCTL1 |= (reset << (1 + (2 * event)));

    return;
} // end of CAP_setCapEvtReset() function

void CAP_setCapContinuous(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECCTL2 &= (~CAP_ECCTL2_CONTONESHOT_BITS);

    return;
} // end of CAP_setCapContinuous() function

void CAP_setCapOneShot(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECCTL2 |= CAP_ECCTL2_CONTONESHOT_BITS;

    return;
} // end of CAP_setCapOneShot() function

void CAP_setModeCap(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECCTL2 &= (~CAP_ECCTL2_CAPAPWM_BITS);

    return;
} // end of CAP_setModeCap() function

void CAP_setModeApwm(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECCTL2 |= CAP_ECCTL2_CAPAPWM_BITS;

    return;
} // end of CAP_setModeApwm() function

void CAP_setStopWrap(CAP_Handle capHandle, const CAP_Stop_Wrap_e stopWrap)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECCTL2 &= (~CAP_ECCTL2_STOP_WRAP_BITS);
    
    // Set the new value
    cap->ECCTL2 |= stopWrap;

    return;
} // end of CAP_setStopWrap() function

void CAP_setSyncOut(CAP_Handle capHandle, const CAP_SyncOut_e syncOut)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;


    // clear the bits
    cap->ECCTL2 &= (~CAP_ECCTL2_SYNCOSEL_BITS);
    
    // Set the new value
    cap->ECCTL2 |= syncOut;

    return;
} // end of CAP_setSyncOut() function

// end of file
