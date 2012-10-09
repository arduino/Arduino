//*****************************************************************************
//
// qei.h - Prototypes for the Quadrature Encoder Driver.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __QEI_H__
#define __QEI_H__

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
// Values that can be passed to QEIConfigure as the ulConfig paramater.
//
//*****************************************************************************
#define QEI_CONFIG_CAPTURE_A    0x00000000  // Count on ChA edges only
#define QEI_CONFIG_CAPTURE_A_B  0x00000008  // Count on ChA and ChB edges
#define QEI_CONFIG_NO_RESET     0x00000000  // Do not reset on index pulse
#define QEI_CONFIG_RESET_IDX    0x00000010  // Reset position on index pulse
#define QEI_CONFIG_QUADRATURE   0x00000000  // ChA and ChB are quadrature
#define QEI_CONFIG_CLOCK_DIR    0x00000004  // ChA and ChB are clock and dir
#define QEI_CONFIG_NO_SWAP      0x00000000  // Do not swap ChA and ChB
#define QEI_CONFIG_SWAP         0x00000002  // Swap ChA and ChB

//*****************************************************************************
//
// Values that can be passed to QEIVelocityConfigure as the ulPreDiv parameter.
//
//*****************************************************************************
#define QEI_VELDIV_1            0x00000000  // Predivide by 1
#define QEI_VELDIV_2            0x00000040  // Predivide by 2
#define QEI_VELDIV_4            0x00000080  // Predivide by 4
#define QEI_VELDIV_8            0x000000C0  // Predivide by 8
#define QEI_VELDIV_16           0x00000100  // Predivide by 16
#define QEI_VELDIV_32           0x00000140  // Predivide by 32
#define QEI_VELDIV_64           0x00000180  // Predivide by 64
#define QEI_VELDIV_128          0x000001C0  // Predivide by 128

//*****************************************************************************
//
// Values that can be passed to QEIEnableInts, QEIDisableInts, and QEIClearInts
// as the ulIntFlags parameter, and returned by QEIGetIntStatus.
//
//*****************************************************************************
#define QEI_INTERROR            0x00000008  // Phase error detected
#define QEI_INTDIR              0x00000004  // Direction change
#define QEI_INTTIMER            0x00000002  // Velocity timer expired
#define QEI_INTINDEX            0x00000001  // Index pulse detected

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void QEIEnable(unsigned long ulBase);
extern void QEIDisable(unsigned long ulBase);
extern void QEIConfigure(unsigned long ulBase, unsigned long ulConfig,
                         unsigned long ulMaxPosition);
extern unsigned long QEIPositionGet(unsigned long ulBase);
extern void QEIPositionSet(unsigned long ulBase, unsigned long ulPosition);
extern long QEIDirectionGet(unsigned long ulBase);
extern tBoolean QEIErrorGet(unsigned long ulBase);
extern void QEIVelocityEnable(unsigned long ulBase);
extern void QEIVelocityDisable(unsigned long ulBase);
extern void QEIVelocityConfigure(unsigned long ulBase, unsigned long ulPreDiv,
                                 unsigned long ulPeriod);
extern unsigned long QEIVelocityGet(unsigned long ulBase);
extern void QEIIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void QEIIntUnregister(unsigned long ulBase);
extern void QEIIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void QEIIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long QEIIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void QEIIntClear(unsigned long ulBase, unsigned long ulIntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __QEI_H__
