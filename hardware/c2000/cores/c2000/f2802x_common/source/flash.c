//#############################################################################
//
//! \file   f2802x_common/source/flash.c
//!
//! \brief  Contains the various functions related to the flash object
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
#include "f2802x_common/include/flash.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

void FLASH_clear3VStatus(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    flash->FSTATUS |= FLASH_FSTATUS_3VSTAT_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_clear3VStatus() function


#pragma CODE_SECTION(FLASH_disablePipelineMode, "ramfuncs");
void FLASH_disablePipelineMode(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    flash->FOPT &= (~FLASH_FOPT_ENPIPE_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_disablePipelineMode() function


#pragma CODE_SECTION(FLASH_enablePipelineMode, "ramfuncs");
void FLASH_enablePipelineMode(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    flash->FOPT |= FLASH_FOPT_ENPIPE_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_enablePipelineMode() function


FLASH_3VStatus_e FLASH_get3VStatus(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    // get the status
    FLASH_3VStatus_e status = (FLASH_3VStatus_e)(flash->FSTATUS & FLASH_FSTATUS_3VSTAT_BITS);

    return(status);
} // end of FLASH_get3VStatus() function


uint16_t FLASH_getActiveWaitCount(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    // get the status
    uint16_t count = (flash->FACTIVEWAIT & FLASH_FACTIVEWAIT_ACTIVEWAIT_BITS);

    return(count);
} // end of FLASH_getActiveWaitCount() function


FLASH_CounterStatus_e FLASH_getActiveWaitStatus(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    // get the status
    FLASH_CounterStatus_e status = (FLASH_CounterStatus_e)((flash->FSTATUS & FLASH_FSTATUS_ACTIVEWAITS_BITS) >> 3);

    return(status);
} // end of FLASH_getActiveWaitStatus() function


FLASH_PowerMode_e FLASH_getPowerMode(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    // get the bits
    FLASH_PowerMode_e mode = (FLASH_PowerMode_e)(flash->FSTATUS & FLASH_FSTATUS_PWRS_BITS);

    return(mode);
} // end of FLASH_getPowerMode() function


uint16_t FLASH_getStandbyWaitCount(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    // get the status
    uint16_t count = (flash->FSTDBYWAIT & FLASH_FSTDBYWAIT_STDBYWAIT_BITS);

    return(count);
} // end of FLASH_getStandbyWaitCount() function


FLASH_CounterStatus_e FLASH_getStandbyWaitStatus(FLASH_Handle flashHandle)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    // get the status
    FLASH_CounterStatus_e status = (FLASH_CounterStatus_e)((flash->FSTATUS & FLASH_FSTATUS_STDBYWAITS_BITS) >> 2);

    return(status);
} // end of FLASH_getStandbyWaitStatus() function


FLASH_Handle FLASH_init(void *pMemory, const size_t numBytes)
{
    FLASH_Handle flashHandle;


    if(numBytes < sizeof(FLASH_Obj))
    return((FLASH_Handle)NULL);

    // assign the handle
    flashHandle = (FLASH_Handle)pMemory;

    return(flashHandle);
} // end of FLASH_init() function


#pragma CODE_SECTION(FLASH_setActiveWaitCount, "ramfuncs");
void FLASH_setActiveWaitCount(FLASH_Handle flashHandle, const uint16_t count)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    flash->FACTIVEWAIT = count;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_setActiveWaitCount() function


#pragma CODE_SECTION(FLASH_setNumPagedReadWaitStates, "ramfuncs");
void FLASH_setNumPagedReadWaitStates(FLASH_Handle flashHandle, const FLASH_NumPagedWaitStates_e numStates)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    flash->FBANKWAIT &= (~FLASH_FBANKWAIT_PAGEWAIT_BITS);

    // set the bits
    flash->FBANKWAIT |= numStates;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_setNumPagedReadWaitStates() function


#pragma CODE_SECTION(FLASH_setNumRandomReadWaitStates, "ramfuncs");
void FLASH_setNumRandomReadWaitStates(FLASH_Handle flashHandle, const FLASH_NumRandomWaitStates_e numStates)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    flash->FBANKWAIT &= (~FLASH_FBANKWAIT_RANDWAIT_BITS);

    // set the bits
    flash->FBANKWAIT |= numStates;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_setNumRandomReadWaitStates() function


#pragma CODE_SECTION(FLASH_setOtpWaitStates, "ramfuncs");
void FLASH_setOtpWaitStates(FLASH_Handle flashHandle, const FLASH_NumOtpWaitStates_e numStates)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    flash->FOTPWAIT &= (~FLASH_FOTPWAIT_OTPWAIT_BITS);

    // set the bits
    flash->FOTPWAIT |= numStates;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_setOneTimeProgrammableStates() function


#pragma CODE_SECTION(FLASH_setPowerMode, "ramfuncs");
void FLASH_setPowerMode(FLASH_Handle flashHandle, const FLASH_PowerMode_e mode)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    flash->FPWR &= (~FLASH_FPWR_PWR_BITS);

    // set the bits
    flash->FPWR |= mode;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_setPowerMode() function


#pragma CODE_SECTION(FLASH_setStandbyWaitCount, "ramfuncs");
void FLASH_setStandbyWaitCount(FLASH_Handle flashHandle, const uint16_t count)
{
    FLASH_Obj *flash = (FLASH_Obj *)flashHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    flash->FSTDBYWAIT = count;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of FLASH_setStandbyWaitCount() function


#pragma CODE_SECTION(FLASH_setup, "ramfuncs");
void FLASH_setup(FLASH_Handle flashHandle)
{


    //Enable Flash Pipeline mode to improve performance
    //of code executed from Flash.
    FLASH_enablePipelineMode(flashHandle);
//    FlashRegs.FOPT.bit.ENPIPE = 1;
    
    //                CAUTION
    //Minimum waitstates required for the flash operating
    //at a given CPU rate must be characterized by TI.
    //Refer to the datasheet for the latest information.

    #if (CPU_FRQ_50MHZ)
    //Set the Paged Waitstate for the Flash
    FLASH_setNumPagedReadWaitStates(flashHandle, FLASH_NumPagedWaitStates_2);
//   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 2;

    //Set the Random Waitstate for the Flash
    FLASH_setNumRandomReadWaitStates(flashHandle, FLASH_NumRandomWaitStates_2);
//   FlashRegs.FBANKWAIT.bit.RANDWAIT = 2;

    //Set the Waitstate for the OTP
    FLASH_setOtpWaitStates(flashHandle, FLASH_NumOtpWaitStates_2);
//   FlashRegs.FOTPWAIT.bit.OTPWAIT = 2;

    #elif (CPU_FRQ_40MHZ)
    //Set the Paged Waitstate for the Flash
    FLASH_setNumPagedReadWaitStates(flashHandle, FLASH_NumPagedWaitStates_1);
//   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 1;

    //Set the Random Waitstate for the Flash
    FLASH_setNumRandomReadWaitStates(flashHandle, FLASH_NumRandomWaitStates_1);
//   FlashRegs.FBANKWAIT.bit.RANDWAIT = 1;

    //Set the Waitstate for the OTP
    FLASH_setOtpWaitStates(flashHandle, FLASH_NumOtpWaitStates_1);
//   FlashRegs.FOTPWAIT.bit.OTPWAIT = 1;
    #endif
    //                CAUTION
    //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
//   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;
    FLASH_setStandbyWaitCount(flashHandle, 0x01FF);
//   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;
    FLASH_setActiveWaitCount(flashHandle, 0x01FF);


    //Force a pipeline flush to ensure that the write to
    //the last register configured occurs before returning.

    asm(" RPT #7 || NOP");
    
}



// end of file
