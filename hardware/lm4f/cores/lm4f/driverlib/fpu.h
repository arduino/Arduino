//*****************************************************************************
//
// fpu.h - Prototypes for the floatint point manipulation routines.
//
// Copyright (c) 2011-2013 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __DRIVERLIB_FPU_H__
#define __DRIVERLIB_FPU_H__

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
// Values that can be passed to FPUHalfPrecisionSet as the ui32Mode parameter.
//
//*****************************************************************************
#define FPU_HALF_IEEE           0x00000000
#define FPU_HALF_ALTERNATE      0x04000000

//*****************************************************************************
//
// Values that can be passed to FPUNaNModeSet as the ui32Mode parameter.
//
//*****************************************************************************
#define FPU_NAN_PROPAGATE       0x00000000
#define FPU_NAN_DEFAULT         0x02000000

//*****************************************************************************
//
// Values that can be passed to FPUFlushToZeroModeSet as the ui32Mode
// parameter.
//
//*****************************************************************************
#define FPU_FLUSH_TO_ZERO_DIS   0x00000000
#define FPU_FLUSH_TO_ZERO_EN    0x01000000

//*****************************************************************************
//
// Values that can be passed to FPURoundingModeSet as the ui32Mode parameter.
//
//*****************************************************************************
#define FPU_ROUND_NEAREST       0x00000000
#define FPU_ROUND_POS_INF       0x00400000
#define FPU_ROUND_NEG_INF       0x00800000
#define FPU_ROUND_ZERO          0x00c00000

//*****************************************************************************
//
// Prototypes.
//
//*****************************************************************************
extern void FPUEnable(void);
extern void FPUDisable(void);
extern void FPUStackingEnable(void);
extern void FPULazyStackingEnable(void);
extern void FPUStackingDisable(void);
extern void FPUHalfPrecisionModeSet(uint32_t ui32Mode);
extern void FPUNaNModeSet(uint32_t ui32Mode);
extern void FPUFlushToZeroModeSet(uint32_t ui32Mode);
extern void FPURoundingModeSet(uint32_t ui32Mode);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_FPU_H__
