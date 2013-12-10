//*****************************************************************************
//
// qei.h - Prototypes for the Quadrature Encoder Driver.
//
// Copyright (c) 2005-2013 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_QEI_H__
#define __DRIVERLIB_QEI_H__

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
// Values that can be passed to QEIConfigure as the ui32Config paramater.
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
// Values that can be passed to QEIVelocityConfigure as the ui32PreDiv
// parameter.
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
// as the ui32IntFlags parameter, and returned by QEIGetIntStatus.
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
extern void QEIEnable(uint32_t ui32Base);
extern void QEIDisable(uint32_t ui32Base);
extern void QEIConfigure(uint32_t ui32Base, uint32_t ui32Config,
                         uint32_t ui32MaxPosition);
extern uint32_t QEIPositionGet(uint32_t ui32Base);
extern void QEIPositionSet(uint32_t ui32Base, uint32_t ui32Position);
extern int32_t QEIDirectionGet(uint32_t ui32Base);
extern bool QEIErrorGet(uint32_t ui32Base);
extern void QEIVelocityEnable(uint32_t ui32Base);
extern void QEIVelocityDisable(uint32_t ui32Base);
extern void QEIVelocityConfigure(uint32_t ui32Base, uint32_t ui32PreDiv,
                                 uint32_t ui32Period);
extern uint32_t QEIVelocityGet(uint32_t ui32Base);
extern void QEIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
extern void QEIIntUnregister(uint32_t ui32Base);
extern void QEIIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void QEIIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern uint32_t QEIIntStatus(uint32_t ui32Base, bool bMasked);
extern void QEIIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_QEI_H__
