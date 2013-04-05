//#############################################################################
//
//! \file   f2802x_common/source/cpu.c
//!
//! \brief  Contains the various functions related to the central processing 
//!         unit (CPU) object
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
#include "f2802x_common/include/cpu.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals

CPU_Obj cpu;


// **************************************************************************
// the functions

void CPU_clearIntFlags(CPU_Handle cpuHandle)
{

    // clear the bits
    IFR = 0;

    return;
} // end of CPU_clearIntFlags() function


void CPU_disableDebugInt(CPU_Handle cpuHandle)
{

    // set the bit
    asm(" setc DBGM");

    return;
} // end of CPU_disableDebug() function


void CPU_disableGlobalInts(CPU_Handle cpuHandle)
{

    // set the bit
    asm(" setc INTM");

    return;
} // end of CPU_disableGlobalInts() function


void CPU_disableInt(CPU_Handle cpuHandle, const CPU_IntNumber_e intNumber)
{

    // clear the bit
    IER &= (~intNumber);

    return;
} // end of CPU_disableInt() function


void CPU_disableInts(CPU_Handle cpuHandle)
{

    // clear the bits
    IER = 0;

    return;
} // end of CPU_disableInts() function


void CPU_disableProtectedRegisterWrite(CPU_Handle cpuHandle)
{

    // clear the bits
    asm(" EDIS");

    return;
} // end fo CPU_disableProtectedRegisterWrite() function


void CPU_enableDebugInt(CPU_Handle cpuHandle)
{

    // clear the bit
    asm(" clrc DBGM");

    return;
} // end of CPU_enableDebugInt() function


void CPU_enableGlobalInts(CPU_Handle cpuHandle)
{

    // clear the bit
    asm(" clrc INTM");

    return;
} // end of CPU_enableGlobalInts() function


void CPU_enableInt(CPU_Handle cpuHandle, const CPU_IntNumber_e intNumber)
{

    // set the interrupt 
    IER |= intNumber;

    return;
} // end of CPU_enableInt() function


void CPU_enableProtectedRegisterWrite(CPU_Handle cpuHandle)
{

    // set the bits
    asm(" EALLOW");

    return;
} // end fo CPU_enableProtectedRegisterWrite() function


CPU_Handle CPU_init(void *pMemory, const size_t numBytes)
{
    CPU_Handle cpuHandle;


    if(numBytes < sizeof(CPU_Obj))
    return((CPU_Handle)NULL);

    // assign the handle
    cpuHandle = (CPU_Handle)pMemory;

    return(cpuHandle);
} // end of CPU_init() function


// end of file
