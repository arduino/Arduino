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
// fram.h - Driver for the FRAM Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_FRAM_H__
#define __MSP430WARE_FRAM_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_FRAM__

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
// The following are values that can be passed to the interruptMask parameter
// for functions: FRAM_enableInterrupt(), and FRAM_disableInterrupt().
//
//*****************************************************************************
#define FRAM_PUC_ON_UNCORRECTABLE_BIT                                  UBDRSTEN
#define FRAM_UNCORRECTABLE_BIT_INTERRUPT                                  UBDIE
#define FRAM_CORRECTABLE_BIT_INTERRUPT                                    CBDIE
#define FRAM_ACCESS_TIME_ERROR_INTERRUPT                                ACCTEIE

//*****************************************************************************
//
// The following are values that can be passed to the interruptFlagMask
// parameter for functions: FRAM_getInterruptStatus() as well as returned by
// the FRAM_getInterruptStatus() function.
//
//*****************************************************************************
#define FRAM_ACCESS_TIME_ERROR_FLAG                                    ACCTEIFG
#define FRAM_UNCORRECTABLE_BIT_FLAG                                      UBDIFG
#define FRAM_CORRECTABLE_BIT_FLAG                                        CBDIFG

//*****************************************************************************
//
// The following are values that can be passed to the waitState parameter for
// functions: FRAM_configureWaitStateControl().
//
//*****************************************************************************
#define FRAM_ACCESS_TIME_CYCLES_0                                      NWAITS_0
#define FRAM_ACCESS_TIME_CYCLES_1                                      NWAITS_1
#define FRAM_ACCESS_TIME_CYCLES_2                                      NWAITS_2
#define FRAM_ACCESS_TIME_CYCLES_3                                      NWAITS_3
#define FRAM_ACCESS_TIME_CYCLES_4                                      NWAITS_4
#define FRAM_ACCESS_TIME_CYCLES_5                                      NWAITS_5
#define FRAM_ACCESS_TIME_CYCLES_6                                      NWAITS_6
#define FRAM_ACCESS_TIME_CYCLES_7                                      NWAITS_7

//*****************************************************************************
//
// The following are values that can be passed to the delayStatus parameter for
// functions: FRAM_delayPowerUpFromLPM().
//
//*****************************************************************************
#define FRAM_DELAY_FROM_LPM_ENABLE                                         0x00
#define FRAM_DELAY_FROM_LPM_DISABLE                                        0x02

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void FRAM_write8(uint8_t *dataPtr,
                        uint8_t *framPtr,
                        uint16_t numberOfBytes);

extern void FRAM_write16(uint16_t *dataPtr,
                         uint16_t *framPtr,
                         uint16_t numberOfWords);

extern void FRAM_write32(uint32_t *dataPtr,
                         uint32_t *framPtr,
                         uint16_t count);

extern void FRAM_memoryFill32(uint32_t value,
                              uint32_t *framPtr,
                              uint16_t count);

extern void FRAM_enableInterrupt(uint8_t interruptMask);

extern uint8_t FRAM_getInterruptStatus(uint16_t interruptFlagMask);

extern void FRAM_disableInterrupt(uint16_t interruptMask);

extern void FRAM_configureWaitStateControl(uint8_t waitState);

extern void FRAM_delayPowerUpFromLPM(uint8_t delayStatus);

//*****************************************************************************
//
// The following values are deprecated values. Please refer to the documenation
// for the correct values to use.
//
//*****************************************************************************
#define FRAM_UNCORRECTABLE_BIT_INTERUPT                                  UBDIEN
#define FRAM_ACCESS_TIME_ERROR_INTERUPT                                 ACCTEIE
#define FRAM_DOUBLE_BIT_ERROR_INTERUPT                                   DBDIEN
#define FRAM_SINGLE_BIT_ERROR_INTERUPT                                   SBDIEN

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_FRAM_H__

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
// fram.h - Driver for the FRAM Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_FRAM_H__
#define __MSP430WARE_FRAM_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_FRAM_FR5XX__

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
// The following are values that can be passed to the interruptMask parameter
// for functions: FRAM_enableInterrupt(), and FRAM_disableInterrupt().
//
//*****************************************************************************
#define FRAM_PUC_ON_UNCORRECTABLE_BIT                                  UBDRSTEN
#define FRAM_UNCORRECTABLE_BIT_INTERRUPT                                 UBDIEN
#define FRAM_CORRECTABLE_BIT_INTERRUPT                                   CBDIEN
#define FRAM_ACCESS_VIOLATION_INTERRUPT                                  ACCVIE
#define FRAM_ACCESS_TIME_ERROR_INTERRUPT                                ACCTEIE

//*****************************************************************************
//
// The following are values that can be passed to the interruptFlagMask
// parameter for functions: FRAM_getInterruptStatus() as well as returned by
// the FRAM_getInterruptStatus() function.
//
//*****************************************************************************
#define FRAM_ACCESS_TIME_ERROR_FLAG                                    ACCTEIFG
#define FRAM_UNCORRECTABLE_BIT_FLAG                                      UBDIFG
#define FRAM_CORRECTABLE_BIT_FLAG                                        CBDIFG
#define FRAM_ACCESS_VIOLATION_FLAG                                      ACCVIFG

//*****************************************************************************
//
// The following are values that can be passed to the accessTime parameter for
// functions: FRAM_configureWaitStateControl().
//
//*****************************************************************************
#define FRAM_ACCESS_TIME_CYCLES_0                                     NACCESS_0
#define FRAM_ACCESS_TIME_CYCLES_1                                     NACCESS_1
#define FRAM_ACCESS_TIME_CYCLES_2                                     NACCESS_2
#define FRAM_ACCESS_TIME_CYCLES_3                                     NACCESS_3
#define FRAM_ACCESS_TIME_CYCLES_4                                     NACCESS_4
#define FRAM_ACCESS_TIME_CYCLES_5                                     NACCESS_5
#define FRAM_ACCESS_TIME_CYCLES_6                                     NACCESS_6
#define FRAM_ACCESS_TIME_CYCLES_7                                     NACCESS_7

//*****************************************************************************
//
// The following are values that can be passed to the accessTime parameter for
// functions: FRAM_configureWaitStateControl().
//
//*****************************************************************************
#define FRAM_PRECHARGE_TIME_CYCLES_0                                  NPRECHG_0
#define FRAM_PRECHARGE_TIME_CYCLES_1                                  NPRECHG_1
#define FRAM_PRECHARGE_TIME_CYCLES_2                                  NPRECHG_2
#define FRAM_PRECHARGE_TIME_CYCLES_3                                  NPRECHG_3
#define FRAM_PRECHARGE_TIME_CYCLES_4                                  NPRECHG_4
#define FRAM_PRECHARGE_TIME_CYCLES_5                                  NPRECHG_5
#define FRAM_PRECHARGE_TIME_CYCLES_6                                  NPRECHG_6
#define FRAM_PRECHARGE_TIME_CYCLES_7                                  NPRECHG_7

//*****************************************************************************
//
// The following are values that can be passed to the manualWaitState parameter
// for functions: FRAM_configureWaitStateControl().
//
//*****************************************************************************
#define FRAM_AUTO_MODE                                                    NAUTO
#define FRAM_MANUAL_MODE                                                   0x00

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void FRAM_write8(uint8_t *dataPtr,
                        uint8_t *framPtr,
                        uint16_t numberOfBytes);

extern void FRAM_write16(uint16_t *dataPtr,
                         uint16_t *framPtr,
                         uint16_t numberOfWords);

extern void FRAM_write32(uint32_t *dataPtr,
                         uint32_t *framPtr,
                         uint16_t count);

extern void FRAM_memoryFill32(uint32_t value,
                              uint32_t *framPtr,
                              uint16_t count);

extern void FRAM_enableInterrupt(uint8_t interruptMask);

extern uint8_t FRAM_getInterruptStatus(uint16_t interruptFlagMask);

extern void FRAM_disableInterrupt(uint16_t interruptMask);

extern void FRAM_configureWaitStateControl(uint8_t manualWaitState,
                                           uint8_t accessTime,
                                           uint8_t prechargeTime);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_FRAM_H__

#endif
