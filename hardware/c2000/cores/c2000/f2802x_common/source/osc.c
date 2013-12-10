//#############################################################################
//
//! \file   f2802x_common/source/osc.c
//!
//! \brief  Contains the various functions related to the oscillator object
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
#include "f2802x_common/include/osc.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions


OSC_Handle OSC_init(void *pMemory, const size_t numBytes)
{
    OSC_Handle oscHandle;


    if(numBytes < sizeof(OSC_Obj))
    return((OSC_Handle)NULL);

    // assign the handle
    oscHandle = (OSC_Handle)pMemory;

    return(oscHandle);
} // end of OSC_init() function

void OSC_runCompensation(OSC_Handle oscHandle, const OSC_Number_e oscNumber, int16_t sample)
{
    int16_t compOscFineTrim;
    int16_t compOscCourseTrim;
    
    compOscFineTrim = (sample - OSC_getRefTempOffset(oscHandle));
    
    if(oscNumber == OSC_Number_1){
        compOscFineTrim = ((sample - OSC_getRefTempOffset(oscHandle))*(int32_t)OSC_getFineTrimSlope1(oscHandle)
                          + OSC_POSTRIM_OFF + FP_ROUND )/FP_SCALE + OSC_getFineTrimOffset1(oscHandle) - OSC_POSTRIM;
        compOscCourseTrim = OSC_getCourseTrim1(oscHandle);
    }
    else{
        compOscFineTrim = ((sample - OSC_getRefTempOffset(oscHandle))*(int32_t)OSC_getFineTrimSlope2(oscHandle)
                          + OSC_POSTRIM_OFF + FP_ROUND )/FP_SCALE + OSC_getFineTrimOffset2(oscHandle) - OSC_POSTRIM;
        compOscCourseTrim = OSC_getCourseTrim2(oscHandle);
    }

    if(compOscFineTrim > 31){
        compOscFineTrim = 31;
    }
    else if(compOscFineTrim < -31){
        compOscFineTrim = -31;
    } 
    
    if(compOscFineTrim < 0){
        compOscFineTrim = (-compOscFineTrim) | 0x20;
    }
    if(compOscCourseTrim < 0){
        compOscCourseTrim = (-compOscCourseTrim) | 0x80;
    }
    
    OSC_setCoarseTrim(oscHandle, oscNumber, (uint8_t)compOscCourseTrim);
    OSC_setFineTrim(oscHandle, oscNumber, (uint8_t)compOscFineTrim);
      
} // end of OSC_runCompensation() function

void OSC_setCoarseTrim(OSC_Handle oscHandle, 
                       const OSC_Number_e oscNumber, 
                       const uint8_t trimValue)
{
    OSC_Obj *osc = (OSC_Obj *)oscHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(oscNumber == OSC_Number_1)
    {
      // clear the bits
      osc->INTOSC1TRIM &= (~OSC_INTOSCnTRIM_COARSE_BITS);

      // set the bits
      osc->INTOSC1TRIM |= trimValue;
    }
    else
    {
      // clear the bits
      osc->INTOSC2TRIM &= (~OSC_INTOSCnTRIM_COARSE_BITS);

      // set the bits
      osc->INTOSC2TRIM |= trimValue;
    }
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of OSC_setCoarseTrim() function


void OSC_setFineTrim(OSC_Handle oscHandle, 
                     const OSC_Number_e oscNumber, 
                     const uint8_t trimValue)
{
    OSC_Obj *osc = (OSC_Obj *)oscHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(oscNumber == OSC_Number_1)
    {
      // clear the bits
      osc->INTOSC1TRIM &= (~OSC_INTOSCnTRIM_FINE_BITS);

      // set the bits
      osc->INTOSC1TRIM |= trimValue << 9;
    }
    else
    {
      // clear the bits
      osc->INTOSC2TRIM &= (~OSC_INTOSCnTRIM_FINE_BITS);

      // set the bits
      osc->INTOSC2TRIM |= trimValue << 9;
    }
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of OSC_setFineTrim() function


// end of file
