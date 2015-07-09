/******************************************************************************
*  Filename:       hw_types.h
*  Revised:        2015-03-26 16:52:06 +0100 (to, 26 mar 2015)
*  Revision:       43138
*
*  Description:    Common types and macros.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_TYPES_H__
#define __HW_TYPES_H__

#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_chip_def.h>

//*****************************************************************************
//
// Common driverlib types
//
//*****************************************************************************
typedef void (* FPTR_VOID_UINT8_T) (uint8_t);

//*****************************************************************************
//
// This symbol forces simple driverlib functions to be inlined in the code
// instead of using function calls.
//
//*****************************************************************************
#ifndef __STATIC_INLINE
#define __STATIC_INLINE static inline
#endif

//*****************************************************************************
//
// C99 types only allows bitfield defintions on certain datatypes.
//
//*****************************************************************************
typedef unsigned int  __UINT32;

//*****************************************************************************
//
// Macros for direct hardware access.
//
// If using these macros the programmer should be aware of any limitations to
// the address accessed i.e. if it supports word and/or byte access.
//
//*****************************************************************************
// Word (32 bit) access to address x
// Read example  : my32BitVar = HWREG(base_addr + offset) ;
// Write example : HWREG(base_addr + offset) = my32BitVar ;
#define HWREG(x)                                                              \
        (*((volatile unsigned long *)(x)))

// Half word (16 bit) access to address x
// Read example  : my16BitVar = HWREGH(base_addr + offset) ;
// Write example : HWREGH(base_addr + offset) = my16BitVar ;
#define HWREGH(x)                                                             \
        (*((volatile unsigned short *)(x)))

// Byte (8 bit) access to address x
// Read example  : my8BitVar = HWREGB(base_addr + offset) ;
// Write example : HWREGB(base_addr + offset) = my8BitVar ;
#define HWREGB(x)                                                             \
        (*((volatile unsigned char *)(x)))

#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
//*****************************************************************************
//
// Macro for 32-bits read only accesses in RAW apertures of the OTP memory.
//
//*****************************************************************************
// Data word (32 bit) read access to ECC map address offset o within RAW aperture
// base address x
// Read example  : my32WordData = HWREGRAW(raw_base_addr + ecc_offset) ;
#define HWREGRAW(x,o)                                                         \
        HWREG( x + (( o << 1 ) & 0xFFFFFFF0 ) + ( o & 0x4 ))

// Info word (32 bit) read access to ECC map address offset o within RAW aperture
// base address x
// Read example  : my32WordInfo = HWREGRAWINFO(raw_base_addr + ecc_offset) ;
#define HWREGRAWINFO(x,o)                                                     \
        HWREG( x + (( o << 1 ) & 0xFFFFFFF0 ) + 8)
#endif

//*****************************************************************************
//
// Macros for hardware access to bit-band supported addresses via the bit-band region.
//
// Macros calculate the corresponding address to access in the bit-band region
// based on the actual address of the memory/register and the bit number.
//
// Do NOT use these macros to access the bit-band region directly!
//
//*****************************************************************************
// Bit-band access to address x bit number b using word access (32 bit)
#define HWREGBITW(x, b)                                                       \
        HWREG(((unsigned long)(x) & 0xF0000000) | 0x02000000 |                \
              (((unsigned long)(x) & 0x000FFFFF) << 5) | ((b) << 2))

// Bit-band access to address x bit number b using half word access (16 bit)
#define HWREGBITH(x, b)                                                       \
        HWREGH(((unsigned long)(x) & 0xF0000000) | 0x02000000 |               \
               (((unsigned long)(x) & 0x000FFFFF) << 5) | ((b) << 2))

// Bit-band access to address x bit number b using byte access (8 bit)
#define HWREGBITB(x, b)                                                       \
        HWREGB(((unsigned long)(x) & 0xF0000000) | 0x02000000 |               \
               (((unsigned long)(x) & 0x000FFFFF) << 5) | ((b) << 2))


#endif // __HW_TYPES_H__
