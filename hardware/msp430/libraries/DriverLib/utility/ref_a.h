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
// ref_a.h - Driver for the REF_A Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_REF_A_H__
#define __MSP430WARE_REF_A_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_REF_A__

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
// The following are values that can be passed to the referenceVoltageSelect
// parameter for functions: REF_A_setReferenceVoltage().
//
//*****************************************************************************
#define REF_A_VREF1_2V                                              (REFVSEL_0)
#define REF_A_VREF2_0V                                              (REFVSEL_1)
#define REF_A_VREF2_5V                                              (REFVSEL_2)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the REF_A_isBandgapActive() function and the
// REF_A_isRefGenActive() function.
//
//*****************************************************************************
#define REF_A_ACTIVE                                                       true
#define REF_A_INACTIVE                                                    false

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the REF_A_getBandgapMode() function.
//
//*****************************************************************************
#define REF_A_STATICMODE                                                   0x00
#define REF_A_SAMPLEMODE                                                 BGMODE

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the REF_A_isRefGenBusy() function.
//
//*****************************************************************************
#define REF_A_NOTBUSY                                                      0x00
#define REF_A_BUSY                                                   REFGENBUSY

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the REF_A_getVariableReferenceVoltageStatus() function
// and the REF_A_getBufferedBandgapVoltageStatus() function.
//
//*****************************************************************************
#define REF_A_NOTREADY                                                    false
#define REF_A_READY                                                        true

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void REF_A_setReferenceVoltage(uint32_t baseAddress,
                                      uint8_t referenceVoltageSelect);

extern void REF_A_disableTempSensor(uint32_t baseAddress);

extern void REF_A_enableTempSensor(uint32_t baseAddress);

extern void REF_A_enableReferenceVoltageOutput(uint32_t baseAddress);

extern void REF_A_disableReferenceVoltageOutput(uint32_t baseAddress);

extern void REF_A_enableReferenceVoltage(uint32_t baseAddress);

extern void REF_A_disableReferenceVoltage(uint32_t baseAddress);

extern uint16_t REF_A_getBandgapMode(uint32_t baseAddress);

extern bool REF_A_isBandgapActive(uint32_t baseAddress);

extern uint16_t REF_A_isRefGenBusy(uint32_t baseAddress);

extern bool REF_A_isRefGenActive(uint32_t baseAddress);

extern bool REF_A_getBufferedBandgapVoltageStatus(uint32_t baseAddress);

extern bool REF_A_getVariableReferenceVoltageStatus(uint32_t baseAddress);

extern void REF_A_setReferenceVoltageOneTimeTrigger(uint32_t baseAddress);

extern void REF_A_setBufferedBandgapVoltageOneTimeTrigger(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_REF_A_H__

#endif
