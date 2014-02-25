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
// comp_d.h - Driver for the COMP_D Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_COMP_D_H__
#define __MSP430WARE_COMP_D_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_COMPD__

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
// outputFilterEnableAndDelayLevel parameter for functions: COMP_D_init().
//
//*****************************************************************************
#define COMP_D_FILTEROUTPUT_OFF                                            0x00
#define COMP_D_FILTEROUTPUT_DLYLVL1                            (CDF + CDFDLY_0)
#define COMP_D_FILTEROUTPUT_DLYLVL2                            (CDF + CDFDLY_1)
#define COMP_D_FILTEROUTPUT_DLYLVL3                            (CDF + CDFDLY_2)
#define COMP_D_FILTEROUTPUT_DLYLVL4                            (CDF + CDFDLY_3)

//*****************************************************************************
//
// The following are values that can be passed to the positiveTerminalInput
// parameter for functions: COMP_D_init(); the inputPort parameter for
// functions: COMP_D_enableInputBuffer(), and COMP_D_disableInputBuffer(); the
// negativeTerminalInput parameter for functions: COMP_D_init().
//
//*****************************************************************************
#define COMP_D_INPUT0                                               (CDIPSEL_0)
#define COMP_D_INPUT1                                               (CDIPSEL_1)
#define COMP_D_INPUT2                                               (CDIPSEL_2)
#define COMP_D_INPUT3                                               (CDIPSEL_3)
#define COMP_D_INPUT4                                               (CDIPSEL_4)
#define COMP_D_INPUT5                                               (CDIPSEL_5)
#define COMP_D_INPUT6                                               (CDIPSEL_6)
#define COMP_D_INPUT7                                               (CDIPSEL_7)
#define COMP_D_INPUT8                                               (CDIPSEL_8)
#define COMP_D_INPUT9                                               (CDIPSEL_9)
#define COMP_D_INPUT10                                             (CDIPSEL_10)
#define COMP_D_INPUT11                                             (CDIPSEL_11)
#define COMP_D_INPUT12                                             (CDIPSEL_12)
#define COMP_D_INPUT13                                             (CDIPSEL_13)
#define COMP_D_INPUT14                                             (CDIPSEL_14)
#define COMP_D_INPUT15                                             (CDIPSEL_15)
#define COMP_D_VREF                                                      (0x10)

//*****************************************************************************
//
// The following are values that can be passed to the invertedOutputPolarity
// parameter for functions: COMP_D_init().
//
//*****************************************************************************
#define COMP_D_NORMALOUTPUTPOLARITY                               (!(CDOUTPOL))
#define COMP_D_INVERTEDOUTPUTPOLARITY                                (CDOUTPOL)

//*****************************************************************************
//
// The following are values that can be passed to the
// supplyVoltageReferenceBase parameter for functions:
// COMP_D_setReferenceVoltage().
//
//*****************************************************************************
#define COMP_D_REFERENCE_AMPLIFIER_DISABLED                          (CDREFL_0)
#define COMP_D_VREFBASE1_5V                                          (CDREFL_1)
#define COMP_D_VREFBASE2_0V                                          (CDREFL_2)
#define COMP_D_VREFBASE2_5V                                          (CDREFL_3)

//*****************************************************************************
//
// The following are values that can be passed to the referenceAccuracy
// parameter for functions: COMP_D_setReferenceAccuracy().
//
//*****************************************************************************
#define COMP_D_ACCURACY_STATIC                                      (!CDREFACC)
#define COMP_D_ACCURACY_CLOCKED                                      (CDREFACC)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask parameter
// for functions: COMP_D_enableInterrupt(), and COMP_D_disableInterrupt().
//
//*****************************************************************************
#define COMP_D_INTERRUPT                                                 (CDIE)
#define COMP_D_INTERRUPT_INVERTED_POLARITY                              (CDIIE)

//*****************************************************************************
//
// The following are values that can be passed to the interruptFlagMask
// parameter for functions: COMP_D_clearInterrupt(), and
// COMP_D_getInterruptStatus().
//
//*****************************************************************************
#define COMP_D_INTERRUPT_FLAG                                           (CDIFG)
#define COMP_D_INTERRUPT_FLAG_INVERTED_POLARITY                        (CDIIFG)

//*****************************************************************************
//
// The following are values that can be passed to the edgeDirection parameter
// for functions: COMP_D_interruptSetEdgeDirection().
//
//*****************************************************************************
#define COMP_D_FALLINGEDGE                                           (!(CDIES))
#define COMP_D_RISINGEDGE                                               (CDIES)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the COMP_D_outputValue() function.
//
//*****************************************************************************
#define COMP_D_HIGH                                                     (CDOUT)
#define COMP_D_LOW                                                     (!CDOUT)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool COMP_D_init(uint32_t baseAddress,
                        uint8_t positiveTerminalInput,
                        uint8_t negativeTerminalInput,
                        uint8_t outputFilterEnableAndDelayLevel,
                        uint16_t invertedOutputPolarity);

extern void COMP_D_setReferenceVoltage(uint32_t baseAddress,
                                       uint16_t supplyVoltageReferenceBase,
                                       uint16_t lowerLimitSupplyVoltageFractionOf32,
                                       uint16_t upperLimitSupplyVoltageFractionOf32);

extern void COMP_D_setReferenceAccuracy(uint32_t baseAddress,
                                        uint16_t referenceAccuracy);

extern void COMP_D_enableInterrupt(uint32_t baseAddress,
                                   uint16_t interruptMask);

extern void COMP_D_disableInterrupt(uint32_t baseAddress,
                                    uint16_t interruptMask);

extern void COMP_D_clearInterrupt(uint32_t baseAddress,
                                  uint16_t interruptFlagMask);

extern uint8_t COMP_D_getInterruptStatus(uint32_t baseAddress,
                                         uint16_t interruptFlagMask);

extern void COMP_D_interruptSetEdgeDirection(uint32_t baseAddress,
                                             uint16_t edgeDirection);

extern void COMP_D_interruptToggleEdgeDirection(uint32_t baseAddress);

extern void COMP_D_enable(uint32_t baseAddress);

extern void COMP_D_disable(uint32_t baseAddress);

extern void COMP_D_shortInputs(uint32_t baseAddress);

extern void COMP_D_unshortInputs(uint32_t baseAddress);

extern void COMP_D_disableInputBuffer(uint32_t baseAddress,
                                      uint8_t inputPort);

extern void COMP_D_enableInputBuffer(uint32_t baseAddress,
                                     uint8_t inputPort);

extern void COMP_D_IOSwap(uint32_t baseAddress);

extern uint16_t COMP_D_outputValue(uint32_t baseAddress);

//*****************************************************************************
//
// The following are deprecated values. Please refer to documentation for the
// correct values to use.
//
//*****************************************************************************
#define COMP_D_VREFBASE_VCC                                          (CDREFL_0)
#define COMP_D_INTERRUPT_ENABLE                                          (CDIE)
#define COMP_D_INTERRUPT_ENABLE_INVERTED_POLARITY                       (CDIIE)

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_COMP_D_H__

#endif
