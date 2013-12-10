//*****************************************************************************
//
// hw_types.h - Common types and macros.
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
// This is part of revision 2.0.1.11577 of the Tiva Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_TYPES_H__
#define __HW_TYPES_H__

//*****************************************************************************
//
// Macros for hardware access, both direct and via the bit-band region.
//
//*****************************************************************************
#define HWREG(x)                                                              \
        (*((volatile uint32_t *)(x)))
#define HWREGH(x)                                                             \
        (*((volatile uint16_t *)(x)))
#define HWREGB(x)                                                             \
        (*((volatile uint8_t *)(x)))
#define HWREGBITW(x, b)                                                       \
        HWREG(((uint32_t)(x) & 0xF0000000) | 0x02000000 |                     \
              (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2))
#define HWREGBITH(x, b)                                                       \
        HWREGH(((uint32_t)(x) & 0xF0000000) | 0x02000000 |                    \
               (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2))
#define HWREGBITB(x, b)                                                       \
        HWREGB(((uint32_t)(x) & 0xF0000000) | 0x02000000 |                    \
               (((uint32_t)(x) & 0x000FFFFF) << 5) | ((b) << 2))

//*****************************************************************************
//
// Helper Macros for determining silicon revisions, etc.
//
// These macros will be used by Driverlib at "run-time" to create necessary
// conditional code blocks that will allow a single version of the Driverlib
// "binary" code to support multiple(all) Tiva silicon revisions.
//
// It is expected that these macros will be used inside of a standard 'C'
// conditional block of code, e.g.
//
//     if(CLASS_IS_BLIZZARD)
//     {
//         do some Blizzard-class specific code here.
//     }
//
// By default, these macros will be defined as run-time checks of the
// appropriate register(s) to allow creation of run-time conditional code
// blocks for a common DriverLib across the entire Tiva family.
//
// However, if code-space optimization is required, these macros can be "hard-
// coded" for a specific version of Tiva silicon.  Many compilers will then
// detect the "hard-coded" conditionals, and appropriately optimize the code
// blocks, eliminating any "unreachable" code.  This would result in a smaller
// Driverlib, thus producing a smaller final application size, but at the cost
// of limiting the Driverlib binary to a specific Tiva silicon revision.
//
//*****************************************************************************
#ifndef CLASS_IS_BLIZZARD
#define CLASS_IS_BLIZZARD                                                    \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_VER_M | SYSCTL_DID0_CLASS_M)) == \
         (SYSCTL_DID0_VER_1 | SYSCTL_DID0_CLASS_BLIZZARD))
#endif

#ifndef CLASS_IS_SNOWFLAKE
#define CLASS_IS_SNOWFLAKE                                                   \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_VER_M | SYSCTL_DID0_CLASS_M)) == \
         (SYSCTL_DID0_VER_1 | SYSCTL_DID0_CLASS_SNOWFLAKE))
#endif

#ifndef REVISION_IS_A0
#define REVISION_IS_A0                                                     \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_MAJ_M | SYSCTL_DID0_MIN_M)) == \
         (SYSCTL_DID0_MAJ_REVA | SYSCTL_DID0_MIN_0))
#endif

#ifndef REVISION_IS_A1
#define REVISION_IS_A1                                                     \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_MAJ_M | SYSCTL_DID0_MIN_M)) == \
         (SYSCTL_DID0_MAJ_REVA | SYSCTL_DID0_MIN_0))
#endif

#ifndef REVISION_IS_A2
#define REVISION_IS_A2                                                     \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_MAJ_M | SYSCTL_DID0_MIN_M)) == \
         (SYSCTL_DID0_MAJ_REVA | SYSCTL_DID0_MIN_2))
#endif

#ifndef REVISION_IS_B0
#define REVISION_IS_B0                                                     \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_MAJ_M | SYSCTL_DID0_MIN_M)) == \
         (SYSCTL_DID0_MAJ_REVB | SYSCTL_DID0_MIN_0))
#endif

#ifndef REVISION_IS_B1
#define REVISION_IS_B1                                                     \
        ((HWREG(SYSCTL_DID0) & (SYSCTL_DID0_MAJ_M | SYSCTL_DID0_MIN_M)) == \
         (SYSCTL_DID0_MAJ_REVB | SYSCTL_DID0_MIN_1))
#endif

#endif // __HW_TYPES_H__
