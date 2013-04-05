//#############################################################################
//
//! \file   f2802x_common/source/pwr.c
//!
//! \brief  Contains the various functions related to the power (PWR) object
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
#include "f2802x_common/include/pwr.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions


void PWR_disableBrownOutReset(PWR_Handle pwrHandle)
{
    PWR_Obj *pwr = (PWR_Obj *)pwrHandle;


    // set the bits
    pwr->BORCFG |= PWR_BORCFG_BORENZ_BITS;

    return;
} // end of PWR_disableBrownOutReset() function


void PWR_disableWatchDogInt(PWR_Handle pwrHandle)
{
    PWR_Obj *pwr = (PWR_Obj *)pwrHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwr->LPMCR0 &= (~PWR_LPMCR0_WDINTE_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWR_disableWatchDogInt() function


void PWR_enableBrownOutReset(PWR_Handle pwrHandle)
{
    PWR_Obj *pwr = (PWR_Obj *)pwrHandle;


    // clear the bits
    pwr->BORCFG &= (~PWR_BORCFG_BORENZ_BITS);

    return;
} // end of PWR_enableBrownOutReset() function


void PWR_enableWatchDogInt(PWR_Handle pwrHandle)
{
    PWR_Obj *pwr = (PWR_Obj *)pwrHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwr->LPMCR0 |= (uint16_t)(PWR_LPMCR0_WDINTE_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWR_enableWatchDogInt() function


PWR_Handle PWR_init(void *pMemory, const size_t numBytes)
{
    PWR_Handle pwrHandle;


    if(numBytes < sizeof(PWR_Obj))
    return((PWR_Handle)NULL);

    // assign the handle
    pwrHandle = (PWR_Handle)pMemory;

    return(pwrHandle);
} // end of PWR_init() function


void PWR_setLowPowerMode(PWR_Handle pwrHandle, const PWR_LowPowerMode_e lowPowerMode)
{
    PWR_Obj *pwr = (PWR_Obj *)pwrHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    // clear the bits
    pwr->LPMCR0 &= (~PWR_LPMCR0_LPM_BITS);

    // set the bits
    pwr->LPMCR0 |= lowPowerMode;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWR_enableBrownOutReset() function


void PWR_setNumStandByClocks(PWR_Handle pwrHandle, const PWR_NumStandByClocks_e numClkCycles)
{
    PWR_Obj *pwr = (PWR_Obj *)pwrHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwr->LPMCR0 &= (~PWR_LPMCR0_QUALSTDBY_BITS);

    // set the bits
    pwr->LPMCR0 |= numClkCycles;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWR_setNumStandByClocks() function


// end of file
