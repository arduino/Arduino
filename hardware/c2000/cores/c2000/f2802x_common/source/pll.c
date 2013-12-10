//#############################################################################
//
//! \file   f2802x_common/source/pll.c
//!
//! \brief  Contains the various functions related to the phase-locked loop
//!         (PLL) object
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
#include "f2802x_common/include/pll.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

void PLL_disable(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLSTS |= PLL_PLLSTS_PLLOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disable() function


void PLL_disableClkDetect(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLSTS |= PLL_PLLSTS_MCLKOFF_BITS;
 
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disableClkDetect() function


void PLL_disableNormRdy(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pll->PLLSTS &= (~PLL_PLLSTS_NORMRDYE_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disableNormRdy() function


void PLL_disableOsc(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLSTS |= PLL_PLLSTS_OSCOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disableOsc() function


void PLL_enable(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pll->PLLSTS &= (~PLL_PLLSTS_PLLOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enable() function


void PLL_enableClkDetect(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pll->PLLSTS &= (~PLL_PLLSTS_MCLKOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enableClkDetect() function


void PLL_enableNormRdy(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLSTS |= (uint16_t)PLL_PLLSTS_NORMRDYE_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enableNormRdy() function


void PLL_enableOsc(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pll->PLLSTS &= (~PLL_PLLSTS_OSCOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enableOsc() function


PLL_Multiplier_e PLL_getMultiplier(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    // get the clock rate
    PLL_Multiplier_e clkMult = (PLL_Multiplier_e)(pll->PLLCR & PLL_PLLCR_DIV_BITS);

    return(clkMult);
} // end of PLL_setClkFreq() function


PLL_ClkStatus_e PLL_getClkStatus(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;

    // mask the bits
    PLL_ClkStatus_e status = (PLL_ClkStatus_e)(pll->PLLSTS & PLL_PLLSTS_MCLKSTS_BITS);

    return(status);
} // end of PLL_getClkStatus() function


PLL_DivideSelect_e PLL_getDivider(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;

    // mask the bits
    PLL_DivideSelect_e divSelect = (PLL_DivideSelect_e)(pll->PLLSTS & PLL_PLLSTS_DIVSEL_BITS);

    return(divSelect);
} // end of PLL_getDivideSelect() function


PLL_LockStatus_e PLL_getLockStatus(PLL_Handle pllHandle)
{
    volatile PLL_Obj *pll = (PLL_Obj *)pllHandle;


    // mask the bits
    PLL_LockStatus_e status = (PLL_LockStatus_e)(pll->PLLSTS & PLL_PLLSTS_PLLLOCKS_BITS);

    return(status);
} // end of PLL_getLockStatus() function


PLL_Handle PLL_init(void *pMemory, const size_t numBytes)
{
    PLL_Handle pllHandle;


    if(numBytes < sizeof(PLL_Obj))
    return((PLL_Handle)NULL);

    // assign the handle
    pllHandle = (PLL_Handle)pMemory;

    return(pllHandle);
} // end of PLL_init() function


void PLL_resetClkDetect(PLL_Handle pllHandle)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLSTS |= PLL_PLLSTS_MCLKCLR_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_resetClkDetect() function


void PLL_setMultiplier(PLL_Handle pllHandle, const PLL_Multiplier_e clkMult)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLCR = clkMult;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_setClkFreq() function


void PLL_setDivider(PLL_Handle pllHandle, const PLL_DivideSelect_e divSelect)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pll->PLLSTS &= (~PLL_PLLSTS_DIVSEL_BITS);

    // set the bits
    pll->PLLSTS |= divSelect;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_setDivideSelect() function

void PLL_setup(PLL_Handle pllHandle, const PLL_Multiplier_e clkMult, const PLL_DivideSelect_e divSelect)
{

    if(PLL_getClkStatus(pllHandle) == PLL_ClkStatus_Missing)
    {
        // The clock is missing so we cannot setup the PLL correctly
        asm(" ESTOP0");
    }
    
    // Set divider to max value (/4) for safety
    PLL_setDivider(pllHandle, PLL_DivideSelect_ClkIn_by_4);
    
    // Set the desired multiplier
    PLL_setMultiplier(pllHandle, clkMult);
    
    while(PLL_getLockStatus(pllHandle) != PLL_LockStatus_Done)
    {
    }
    
    // Set the desired divider
    PLL_setDivider(pllHandle, divSelect);
    
} // end of PLL_setup() function


void PLL_setLockPeriod(PLL_Handle pllHandle, const uint16_t lockPeriod)
{
    PLL_Obj *pll = (PLL_Obj *)pllHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pll->PLLLOCKPRD = lockPeriod;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_setLockPeriod() function


// end of file
