//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// mpu.h - Driver for the MPU Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_MPU_H__
#define __MSP430WARE_MPU_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_MPU__

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
// The following are values that can be passed to the seg2accmask parameter for
// functions: MPU_createTwoSegments(), and MPU_createThreeSegments(); the
// seg1accmask parameter for functions: MPU_createTwoSegments(), and
// MPU_createThreeSegments(); the seg3accmask parameter for functions:
// MPU_createThreeSegments().
//
//*****************************************************************************
#define MPU_READ                                                      MPUSEG1RE
#define MPU_WRITE                                                     MPUSEG1WE
#define MPU_EXEC                                                      MPUSEG1XE

//*****************************************************************************
//
// The following are values that can be passed to the segment parameter for
// functions: MPU_enablePUCOnViolation(), and MPU_disablePUCOnViolation().
//
//*****************************************************************************
#define MPU_FIRST_SEG                                                 MPUSEG1VS
#define MPU_SECOND_SEG                                                MPUSEG2VS
#define MPU_THIRD_SEG                                                 MPUSEG3VS

//*****************************************************************************
//
// The following are values that can be passed to the memAccFlag parameter for
// functions: MPU_getInterruptStatus(), and MPU_clearInterruptFlag() as well as
// returned by the MPU_getInterruptStatus() function, the
// MPU_clearAllInterruptFlags() function and the MPU_clearInterruptFlag()
// function.
//
//*****************************************************************************
#define MPU_SEG_1_ACCESS_VIOLATION                                   MPUSEG1IFG
#define MPU_SEG_2_ACCESS_VIOLATION                                   MPUSEG2IFG
#define MPU_SEG_3_ACCESS_VIOLATION                                   MPUSEG3IFG

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void MPU_createTwoSegments(uint32_t baseAddress,
                                  uint16_t seg1boundary,
                                  uint8_t seg1accmask,
                                  uint8_t seg2accmask);

extern void MPU_createThreeSegments(uint32_t baseAddress,
                                    uint16_t seg1boundary,
                                    uint16_t seg2boundary,
                                    uint8_t seg1accmask,
                                    uint8_t seg2accmask,
                                    uint8_t seg3accmask);

extern void MPU_enableNMIevent(uint32_t baseAddress);

extern void MPU_start(uint32_t baseAddress);

extern void MPU_enablePUCOnViolation(uint32_t baseAddress,
                                     uint16_t segment);

extern void MPU_disablePUCOnViolation(uint32_t baseAddress,
                                      uint16_t segment);

extern uint16_t MPU_getInterruptStatus(uint32_t baseAddress,
                                       uint16_t memAccFlag);

extern uint16_t MPU_clearInterruptFlag(uint32_t baseAddress,
                                       uint16_t memAccFlag);

extern uint16_t MPU_clearAllInterruptFlags(uint32_t baseAddress);

extern void MPU_lockMPU(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_MPU_H__

#endif
//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5739__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// mpu.h - Driver for the MPU Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_MPU_H__
#define __MSP430WARE_MPU_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_MPU__

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
// The following are values that can be passed to the seg2accmask parameter for
// functions: MPU_createTwoSegments(), and MPU_createThreeSegments(); the
// seg1accmask parameter for functions: MPU_createTwoSegments(), and
// MPU_createThreeSegments(); the seg3accmask parameter for functions:
// MPU_createThreeSegments().
//
//*****************************************************************************
#define MPU_READ                                                      MPUSEG1RE
#define MPU_WRITE                                                     MPUSEG1WE
#define MPU_EXEC                                                      MPUSEG1XE

//*****************************************************************************
//
// The following are values that can be passed to the segment parameter for
// functions: MPU_enablePUCOnViolation(), and MPU_disablePUCOnViolation().
//
//*****************************************************************************
#define MPU_FIRST_SEG                                                 MPUSEG1VS
#define MPU_SECOND_SEG                                                MPUSEG2VS
#define MPU_THIRD_SEG                                                 MPUSEG3VS

//*****************************************************************************
//
// The following are values that can be passed to the memAccFlag parameter for
// functions: MPU_getInterruptStatus(), and MPU_clearInterruptFlag() as well as
// returned by the MPU_getInterruptStatus() function, the
// MPU_clearAllInterruptFlags() function and the MPU_clearInterruptFlag()
// function.
//
//*****************************************************************************
#define MPU_SEG_1_ACCESS_VIOLATION                                   MPUSEG1IFG
#define MPU_SEG_2_ACCESS_VIOLATION                                   MPUSEG2IFG
#define MPU_SEG_3_ACCESS_VIOLATION                                   MPUSEG3IFG

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void MPU_createTwoSegments(uint32_t baseAddress,
                                  uint16_t seg1boundary,
                                  uint8_t seg1accmask,
                                  uint8_t seg2accmask);

extern void MPU_createThreeSegments(uint32_t baseAddress,
                                    uint16_t seg1boundary,
                                    uint16_t seg2boundary,
                                    uint8_t seg1accmask,
                                    uint8_t seg2accmask,
                                    uint8_t seg3accmask);

extern void MPU_start(uint32_t baseAddress);

extern void MPU_enablePUCOnViolation(uint32_t baseAddress,
                                     uint16_t segment);

extern void MPU_disablePUCOnViolation(uint32_t baseAddress,
                                      uint16_t segment);

extern uint16_t MPU_getInterruptStatus(uint32_t baseAddress,
                                       uint16_t memAccFlag);

extern uint16_t MPU_clearInterruptFlag(uint32_t baseAddress,
                                       uint16_t memAccFlag);

extern uint16_t MPU_clearAllInterruptFlags(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_MPU_H__

#endif
