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
// comp_e.h - Driver for the COMP_E Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_COMP_E_H__
#define __MSP430WARE_COMP_E_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_COMP_E__

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
// The following are values that can be passed to the
// outputFilterEnableAndDelayLevel parameter for functions: COMP_E_init().
//
//*****************************************************************************
#define COMP_E_FILTEROUTPUT_OFF                                            0x00
#define COMP_E_FILTEROUTPUT_DLYLVL1                            (CEF + CEFDLY_0)
#define COMP_E_FILTEROUTPUT_DLYLVL2                            (CEF + CEFDLY_1)
#define COMP_E_FILTEROUTPUT_DLYLVL3                            (CEF + CEFDLY_2)
#define COMP_E_FILTEROUTPUT_DLYLVL4                            (CEF + CEFDLY_3)

//*****************************************************************************
//
// The following are values that can be passed to the posTerminalInput
// parameter for functions: COMP_E_init(); the inputPort parameter for
// functions: COMP_E_disableInputBuffer(), and COMP_E_enableInputBuffer(); the
// negTerminalInput parameter for functions: COMP_E_init().
//
//*****************************************************************************
#define COMP_E_INPUT0                                                    (0x01)
#define COMP_E_INPUT1                                                    (0x02)
#define COMP_E_INPUT2                                                    (0x04)
#define COMP_E_INPUT3                                                    (0x08)
#define COMP_E_INPUT4                                                    (0x10)
#define COMP_E_INPUT5                                                    (0x20)
#define COMP_E_INPUT6                                                    (0x40)
#define COMP_E_INPUT7                                                    (0x80)
#define COMP_E_INPUT8                                                   (0x100)
#define COMP_E_INPUT9                                                   (0x200)
#define COMP_E_INPUT10                                                  (0x400)
#define COMP_E_INPUT11                                                  (0x800)
#define COMP_E_INPUT12                                                 (0x1000)
#define COMP_E_INPUT13                                                 (0x2000)
#define COMP_E_INPUT14                                                 (0x4000)
#define COMP_E_INPUT15                                                 (0x8000)
#define COMP_E_VREF                                                      (0x9F)

//*****************************************************************************
//
// The following are values that can be passed to the invertedOutputPolarity
// parameter for functions: COMP_E_init().
//
//*****************************************************************************
#define COMP_E_NORMALOUTPUTPOLARITY                               (!(CEOUTPOL))
#define COMP_E_INVERTEDOUTPUTPOLARITY                                (CEOUTPOL)

//*****************************************************************************
//
// The following are values that can be passed to the
// supplyVoltageReferenceBase parameter for functions:
// COMP_E_setReferenceVoltage().
//
//*****************************************************************************
#define COMP_E_REFERENCE_AMPLIFIER_DISABLED                          (CEREFL_0)
#define COMP_E_VREFBASE1_2V                                          (CEREFL_1)
#define COMP_E_VREFBASE2_0V                                          (CEREFL_2)
#define COMP_E_VREFBASE2_5V                                          (CEREFL_3)

//*****************************************************************************
//
// The following are values that can be passed to the referenceAccuracy
// parameter for functions: COMP_E_setReferenceAccuracy().
//
//*****************************************************************************
#define COMP_E_ACCURACY_STATIC                                      (!CEREFACC)
#define COMP_E_ACCURACY_CLOCKED                                      (CEREFACC)

//*****************************************************************************
//
// The following are values that can be passed to the powerMode parameter for
// functions: COMP_E_setPowerMode().
//
//*****************************************************************************
#define COMP_E_HIGH_SPEED_MODE                                      (CEPWRMD_0)
#define COMP_E_NORMAL_MODE                                          (CEPWRMD_1)
#define COMP_E_ULTRA_LOW_POWER_MODE                                 (CEPWRMD_2)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask parameter
// for functions: COMP_E_enableInterrupt(), and COMP_E_disableInterrupt().
//
//*****************************************************************************
#define COMP_E_OUTPUT_INTERRUPT                                          (CEIE)
#define COMP_E_INVERTED_POLARITY_INTERRUPT                              (CEIIE)
#define COMP_E_READY_INTERRUPT                                        (CERDYIE)

//*****************************************************************************
//
// The following are values that can be passed to the interruptFlagMask
// parameter for functions: COMP_E_clearInterrupt(), and
// COMP_E_getInterruptStatus() as well as returned by the
// COMP_E_getInterruptStatus() function.
//
//*****************************************************************************
#define COMP_E_OUTPUT_INTERRUPT_FLAG                                    (CEIFG)
#define COMP_E_INTERRUPT_FLAG_INVERTED_POLARITY                        (CEIIFG)
#define COMP_E_INTERRUPT_FLAG_READY                                  (CERDYIFG)

//*****************************************************************************
//
// The following are values that can be passed to the edgeDirection parameter
// for functions: COMP_E_interruptSetEdgeDirection().
//
//*****************************************************************************
#define COMP_E_FALLINGEDGE                                           (!(CEIES))
#define COMP_E_RISINGEDGE                                               (CEIES)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the COMP_E_outputValue() function.
//
//*****************************************************************************
#define COMP_E_LOW                                                        (0x0)
#define COMP_E_HIGH                                                     (CEOUT)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool COMP_E_init(uint32_t baseAddress,
                        uint16_t posTerminalInput,
                        uint16_t negTerminalInput,
                        uint8_t outputFilterEnableAndDelayLevel,
                        uint16_t invertedOutputPolarity);

extern void COMP_E_setReferenceVoltage(uint32_t baseAddress,
                                       uint16_t supplyVoltageReferenceBase,
                                       uint16_t lowerLimitSupplyVoltageFractionOf32,
                                       uint16_t upperLimitSupplyVoltageFractionOf32);

extern void COMP_E_setReferenceAccuracy(uint32_t baseAddress,
                                        uint16_t referenceAccuracy);

extern void COMP_E_setPowerMode(uint32_t baseAddress,
                                uint16_t powerMode);

extern void COMP_E_enableInterrupt(uint32_t baseAddress,
                                   uint16_t interruptMask);

extern void COMP_E_disableInterrupt(uint32_t baseAddress,
                                    uint16_t interruptMask);

extern void COMP_E_clearInterrupt(uint32_t baseAddress,
                                  uint16_t interruptFlagMask);

extern uint8_t COMP_E_getInterruptStatus(uint32_t baseAddress,
                                         uint16_t interruptFlagMask);

extern void COMP_E_interruptSetEdgeDirection(uint32_t baseAddress,
                                             uint16_t edgeDirection);

extern void COMP_E_interruptToggleEdgeDirection(uint32_t baseAddress);

extern void COMP_E_enable(uint32_t baseAddress);

extern void COMP_E_disable(uint32_t baseAddress);

extern void COMP_E_shortInputs(uint32_t baseAddress);

extern void COMP_E_unshortInputs(uint32_t baseAddress);

extern void COMP_E_disableInputBuffer(uint32_t baseAddress,
                                      uint16_t inputPort);

extern void COMP_E_enableInputBuffer(uint32_t baseAddress,
                                     uint16_t inputPort);

extern void COMP_E_IOSwap(uint32_t baseAddress);

extern uint16_t COMP_E_outputValue(uint32_t baseAddress);

//*****************************************************************************
//
// DEPRECATED
//
//*****************************************************************************
#define COMP_E_INTERRUPT_FLAG                                           (CEIFG)
#define COMP_E_VREFBASE_VCC                                          (CEREFL_0)

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_COMP_E_H__

#endif
