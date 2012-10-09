//*****************************************************************************
//
// peci.h - Prototypes for Platform Environment Control Interface (PECI)
//          driver.
//
// Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __PECI_H__
#define __PECI_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Values that can be passed to PECIConfigDomain, PECIEnableDomain,
// PECIDisableDomain, PECIReadDomainValue, PECIReadDomainMax, and
// PECIClearDomain as the ulDomain parameter.
//
//*****************************************************************************
#define PECI_DOMAIN_M0D0        0           // Microprocessor 0 / Domain 0
#define PECI_DOMAIN_M0D1        1           // Microprocessor 0 / Domain 1
#define PECI_DOMAIN_M1D0        2           // Microprocessor 1 / Domain 0
#define PECI_DOMAIN_M1D1        3           // Microprocessor 1 / Domain 1

//*****************************************************************************
//
// Values that can be passed to PECIIntEnable, PECIIntDisable, and PECIIntClear
// as the ulIntFlags parameter and returned by PECIIntStatus.
//
//*****************************************************************************
#define PECI_READ               0x00000001  // End of PECI Poll
#define PECI_ERR                0x00000002  // Error on PECI Poll
#define PECI_AC                 0x00000004  // Advanced Command Complete
#define PECI_M0D0               0x00030000  // Microprocessor 0 / Domain 0
#define PECI_M0D1               0x000C0000  // Microprocessor 0 / Domain 1
#define PECI_M1D0               0x00300000  // Microprocessor 1 / Domain 0
#define PECI_M1D1               0x00C00000  // Microprocessor 1 / Domain 1

//*****************************************************************************
//
// Additional values that can be returned by PECIIntStatus.
//
//*****************************************************************************
#define PECI_M0D0_MODE1_HIGH    0x00030000  // Microprocessor 0 / Domain 0
                                            // Mode 1
                                            // Temperature IS above HIGH
#define PECI_M0D0_MODE2_MID     0x00020000  // Microprocessor 0 / Domain 0
                                            // Mode 2
                                            // Temperature CROSSED above LOW
#define PECI_M0D0_MODE2_HIGH    0x00030000  // Microprocessor 0 / Domain 0
                                            // Mode 2
                                            // Temperature CROSSED above HIGH
#define PECI_M0D0_MODE3_LOW     0x00010000  // Microprocessor 0 / Domain 0
                                            // Mode 3
                                            // Temperature CROSSED below LOW
#define PECI_M0D0_MODE3_MID     0x00020000  // Microprocessor 0 / Domain 0
                                            // Mode 3
                                            // Temperature CROSSED above LOW or
                                            // Temperature CROSSED below HIGH
#define PECI_M0D0_MODE3_HIGH    0x00030000  // Microprocessor 0 / Domain 0
                                            // Mode 3
                                            // Temperature CROSSED above HIGH
#define PECI_M0D1_MODE1_HIGH    0x00030000  // Microprocessor 0 / Domain 1
                                            // Mode 1
                                            // Temperature IS above HIGH
#define PECI_M0D1_MODE2_MID     0x00020000  // Microprocessor 0 / Domain 1
                                            // Mode 2
                                            // Temperature CROSSED above LOW
#define PECI_M0D1_MODE2_HIGH    0x00030000  // Microprocessor 0 / Domain 1
                                            // Mode 2
                                            // Temperature CROSSED above HIGH
#define PECI_M0D1_MODE3_LOW     0x00010000  // Microprocessor 0 / Domain 1
                                            // Mode 3
                                            // Temperature CROSSED below LOW
#define PECI_M0D1_MODE3_MID     0x00020000  // Microprocessor 0 / Domain 1
                                            // Mode 3
                                            // Temperature CROSSED above LOW or
                                            // Temperature CROSSED below HIGH
#define PECI_M0D1_MODE3_HIGH    0x00030000  // Microprocessor 0 / Domain 1
                                            // Mode 3
                                            // Temperature CROSSED above HIGH
#define PECI_M1D0_MODE1_HIGH    0x00030000  // Microprocessor 1 / Domain 0
                                            // Mode 1
                                            // Temperature IS above HIGH
#define PECI_M1D0_MODE2_MID     0x00020000  // Microprocessor 1 / Domain 0
                                            // Mode 2
                                            // Temperature CROSSED above LOW
#define PECI_M1D0_MODE2_HIGH    0x00030000  // Microprocessor 1 / Domain 0
                                            // Mode 2
                                            // Temperature CROSSED above HIGH
#define PECI_M1D0_MODE3_LOW     0x00010000  // Microprocessor 1 / Domain 0
                                            // Mode 3
                                            // Temperature CROSSED below LOW
#define PECI_M1D0_MODE3_MID     0x00020000  // Microprocessor 1 / Domain 0
                                            // Mode 3
                                            // Temperature CROSSED above LOW or
                                            // Temperature CROSSED below HIGH
#define PECI_M1D0_MODE3_HIGH    0x00030000  // Microprocessor 1 / Domain 0
                                            // Mode 3
                                            // Temperature CROSSED above HIGH
#define PECI_M1D1_MODE1_HIGH    0x00030000  // Microprocessor 1 / Domain 1
                                            // Mode 1
                                            // Temperature IS above HIGH
#define PECI_M1D1_MODE2_MID     0x00020000  // Microprocessor 1 / Domain 1
                                            // Mode 2
                                            // Temperature CROSSED above LOW
#define PECI_M1D1_MODE2_HIGH    0x00030000  // Microprocessor 1 / Domain 1
                                            // Mode 2
                                            // Temperature CROSSED above HIGH
#define PECI_M1D1_MODE3_LOW     0x00010000  // Microprocessor 1 / Domain 1
                                            // Mode 3
                                            // Temperature CROSSED below LOW
#define PECI_M1D1_MODE3_MID     0x00020000  // Microprocessor 1 / Domain 1
                                            // Mode 3
                                            // Temperature CROSSED above LOW or
                                            // Temperature CROSSED below HIGH
#define PECI_M1D1_MODE3_HIGH    0x00030000  // Microprocessor 1 / Domain 1
                                            // Mode 3
                                            // Temperature CROSSED above HIGH

//*****************************************************************************
//
// Values that can be passed to PECIIntEnable as the ulIntMode parameter.
//
//*****************************************************************************
#define PECI_M0D0_MODE1         0x00010000  // Domain Interrupt Mode 1
#define PECI_M0D0_MODE2         0x00020000  // Domain Interrupt Mode 2
#define PECI_M0D0_MODE3         0x00030000  // Domain Interrupt Mode 3
#define PECI_M0D1_MODE1         0x00040000  // Domain Interrupt Mode 1
#define PECI_M0D1_MODE2         0x00080000  // Domain Interrupt Mode 2
#define PECI_M0D1_MODE3         0x000C0000  // Domain Interrupt Mode 3
#define PECI_M1D0_MODE1         0x00100000  // Domain Interrupt Mode 1
#define PECI_M1D0_MODE2         0x00200000  // Domain Interrupt Mode 2
#define PECI_M1D0_MODE3         0x00300000  // Domain Interrupt Mode 3
#define PECI_M1D1_MODE1         0x00400000  // Domain Interrupt Mode 1
#define PECI_M1D1_MODE2         0x00800000  // Domain Interrupt Mode 2
#define PECI_M1D1_MODE3         0x00C00000  // Domain Interrupt Mode 3

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void PECIConfigSet(unsigned long ulBase, unsigned long ulPECIClk,
                          unsigned long ulBaud, unsigned long ulPoll,
                          unsigned long ulOffset, unsigned long ulRetry);
extern void PECIConfigGet(unsigned long ulBase, unsigned long ulPECIClk,
                          unsigned long *pulBaud, unsigned long *pulPoll,
                          unsigned long *pulOffset, unsigned long *pulRetry);
extern void PECIBypassEnable(unsigned long ulBase);
extern void PECIBypassDisable(unsigned long ulBase);
extern void PECIDomainConfigSet(unsigned long ulBase, unsigned long ulDomain,
                                unsigned long ulHigh, unsigned long ulLow);
extern void PECIDomainConfigGet(unsigned long ulBase, unsigned long ulDomain,
                                unsigned long *pulHigh, unsigned long *pulLow);
extern void PECIDomainEnable(unsigned long ulBase, unsigned long ulDomain);
extern void PECIDomainDisable(unsigned long ulBase, unsigned long ulDomain);
extern unsigned long PECIDomainValueGet(unsigned long ulBase,
                                        unsigned long ulDomain);
extern unsigned long PECIDomainMaxReadGet(unsigned long ulBase,
                                          unsigned long ulDomain);
extern void PECIDomainValueClear(unsigned long ulBase, unsigned long ulDomain);
extern void PECIDomainMaxReadClear(unsigned long ulBase,
                                   unsigned long ulDomain);
extern void PECIIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void PECIIntUnregister(unsigned long ulBase);
extern void PECIIntEnable(unsigned long ulBase, unsigned long ulIntFlags,
                          unsigned long ulIntMode);
extern void PECIIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long PECIIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void PECIIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void PECIAdvCmdSend(unsigned long ulBase, unsigned char ucCmd,
                           unsigned char ucHidRe, unsigned char ucDomain,
                           unsigned char ucProcAdd, unsigned long ulArg,
                           unsigned char ucSize, unsigned long ulData0,
                           unsigned long ulData1);
extern unsigned long PECIAdvCmdSendNonBlocking(unsigned long ulBase,
                                               unsigned char ucCmd,
                                               unsigned char ucHidRe,
                                               unsigned char ucDomain,
                                               unsigned char ucProcAdd,
                                               unsigned long ulArg,
                                               unsigned char ucSize,
                                               unsigned long ulData0,
                                               unsigned long ulData1);
extern unsigned long PECIAdvCmdStatusGet(unsigned long ulBase,
                                         unsigned long *pulData0,
                                         unsigned long *pulData1);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __PECI_H__
