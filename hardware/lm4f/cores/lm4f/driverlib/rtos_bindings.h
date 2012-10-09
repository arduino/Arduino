//*****************************************************************************
//
// rtos_bindings.h - Macros ulIntIDended to aid porting of StellarisWare modules
//                   for use with an RTOS.
//
// Copyright (c) 2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************
#ifndef RTOS_BINDINGS_H_
#define RTOS_BINDINGS_H_

#ifdef USE_RTOS
//*****************************************************************************
//
// If an RTOS is in use, implement a header file called "stellaris_rtos.h"
// which contains RTOS-specific versions of each of the macros defined below
// and make sure it appears on the include path set when you build your
// project.
//
// Note that there is no default implementation of this header file included
// in StellarisWare - it is your responsibility to create it specifically for
// your RTOS.
//
//*****************************************************************************
#include "stellaris_rtos.h"

#else
//*****************************************************************************
//
// When no RTOS is in use, the follow macros compile to either nothing or a
// minimal implementation that works in a bare-metal environment.
//
// Each of these macros must be redefined in stellaris_rtos.h if you are using
// StellarisWare under an RTOS.
//
//*****************************************************************************

//*****************************************************************************
//
// A simple macro used to yield within polling loops.  In the default, non-RTOS
// implementation, this compiles to nothing.
//
//*****************************************************************************
#define OS_YIELD()

//*****************************************************************************
//
// A simple macro around the SysCtlDelay function.  The parameter is the number
// of 3 cycle loops to wait before returning (as for SysCtlDelay).  In an RTOS
// implementation, this could be replaced with an OS delay call with
// appropriate parameter scaling.
//
//*****************************************************************************
#define OS_DELAY(ul3Cycles) MAP_SysCtlDelay(ul3Cycles)

//*****************************************************************************
//
// Wrappers around low level interrupt control functions.  For information
// on each of these functions, please see the appropriate API documentation
// for the DriverLib Interrupt driver.
//
// The macros defined here represent interrupt-control functions that may be
// called from within StellarisWare code.  It is expected that application
// code will use RTOS-specific functions to control interrupt priority, to
// pend interrupts and to perform runtime vector manipulation.  As a result,
// no macros are defined to wrap any of these functions from interrupt.c.
//
//*****************************************************************************
#define OS_INT_MASTER_ENABLE() MAP_IntMasterEnable()
#define OS_INT_MASTER_DISABLE() MAP_IntMasterDisable()
#define OS_INT_DISABLE(ulIntID) MAP_IntDisable(ulIntID)
#define OS_INT_ENABLE(ulIntID) MAP_IntEnable(ulIntID)

#endif // USE_RTOS

#endif // RTOS_BINDINGS_H_
