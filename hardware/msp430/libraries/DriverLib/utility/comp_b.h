//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430F5529__)

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
// comp_b.h - Driver for the COMP_B Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_COMP_B_H__
#define __MSP430WARE_COMP_B_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_COMPB__

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
// The following are values that can be passed to the powerModeSelect parameter
// for functions: COMP_B_init().
//
//*****************************************************************************
#define COMP_B_POWERMODE_HIGHSPEED                                  (CBPWRMD_0)
#define COMP_B_POWERMODE_NORMALMODE                                 (CBPWRMD_1)
#define COMP_B_POWERMODE_ULTRALOWPOWER                              (CBPWRMD_2)

//*****************************************************************************
//
// The following are values that can be passed to the positiveTerminalInput
// parameter for functions: COMP_B_init(); the inputPort parameter for
// functions: COMP_B_disableInputBuffer(), and COMP_B_enableInputBuffer(); the
// negativeTerminalInput parameter for functions: COMP_B_init().
//
//*****************************************************************************
#define COMP_B_INPUT0                                               (CBIPSEL_0)
#define COMP_B_INPUT1                                               (CBIPSEL_1)
#define COMP_B_INPUT2                                               (CBIPSEL_2)
#define COMP_B_INPUT3                                               (CBIPSEL_3)
#define COMP_B_INPUT4                                               (CBIPSEL_4)
#define COMP_B_INPUT5                                               (CBIPSEL_5)
#define COMP_B_INPUT6                                               (CBIPSEL_6)
#define COMP_B_INPUT7                                               (CBIPSEL_7)
#define COMP_B_INPUT8                                               (CBIPSEL_8)
#define COMP_B_INPUT9                                               (CBIPSEL_9)
#define COMP_B_INPUT10                                             (CBIPSEL_10)
#define COMP_B_INPUT11                                             (CBIPSEL_11)
#define COMP_B_INPUT12                                             (CBIPSEL_12)
#define COMP_B_INPUT13                                             (CBIPSEL_13)
#define COMP_B_INPUT14                                             (CBIPSEL_14)
#define COMP_B_INPUT15                                             (CBIPSEL_15)
#define COMP_B_VREF                                                      (0x10)

//*****************************************************************************
//
// The following are values that can be passed to the
// outputFilterEnableAndDelayLevel parameter for functions: COMP_B_init().
//
//*****************************************************************************
#define COMP_B_FILTEROUTPUT_OFF                                            0x00
#define COMP_B_FILTEROUTPUT_DLYLVL1                            (CBF + CBFDLY_0)
#define COMP_B_FILTEROUTPUT_DLYLVL2                            (CBF + CBFDLY_1)
#define COMP_B_FILTEROUTPUT_DLYLVL3                            (CBF + CBFDLY_2)
#define COMP_B_FILTEROUTPUT_DLYLVL4                            (CBF + CBFDLY_3)

//*****************************************************************************
//
// The following are values that can be passed to the invertedOutputPolarity
// parameter for functions: COMP_B_init().
//
//*****************************************************************************
#define COMP_B_NORMALOUTPUTPOLARITY                               (!(CBOUTPOL))
#define COMP_B_INVERTEDOUTPUTPOLARITY                                (CBOUTPOL)

//*****************************************************************************
//
// The following are values that can be passed to the referenceAccuracy
// parameter for functions: COMP_B_setReferenceVoltage().
//
//*****************************************************************************
#define COMP_B_ACCURACY_STATIC                                      (!CBREFACC)
#define COMP_B_ACCURACY_CLOCKED                                      (CBREFACC)

//*****************************************************************************
//
// The following are values that can be passed to the
// supplyVoltageReferenceBase parameter for functions:
// COMP_B_setReferenceVoltage().
//
//*****************************************************************************
#define COMP_B_VREFBASE_VCC                                          (CBREFL_0)
#define COMP_B_VREFBASE1_5V                                          (CBREFL_1)
#define COMP_B_VREFBASE2_0V                                          (CBREFL_2)
#define COMP_B_VREFBASE2_5V                                          (CBREFL_3)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask parameter
// for functions: COMP_B_enableInterrupt(), and COMP_B_disableInterrupt().
//
//*****************************************************************************
#define COMP_B_OUTPUT_INT                                                  CBIE
#define COMP_B_OUTPUTINVERTED_INT                                         CBIIE

//*****************************************************************************
//
// The following are values that can be passed to the interruptFlagMask
// parameter for functions: COMP_B_clearInterrupt(), and
// COMP_B_getInterruptStatus() as well as returned by the
// COMP_B_getInterruptStatus() function.
//
//*****************************************************************************
#define COMP_B_OUTPUT_FLAG                                                CBIFG
#define COMP_B_OUTPUTINVERTED_FLAG                                       CBIIFG

//*****************************************************************************
//
// The following are values that can be passed to the edgeDirection parameter
// for functions: COMP_B_interruptSetEdgeDirection().
//
//*****************************************************************************
#define COMP_B_FALLINGEDGE                                           (!(CBIES))
#define COMP_B_RISINGEDGE                                               (CBIES)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the COMP_B_outputValue() function.
//
//*****************************************************************************
#define COMP_B_LOW                                                        (0x0)
#define COMP_B_HIGH                                                     (CBOUT)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool COMP_B_init(uint32_t baseAddress,
                        uint8_t positiveTerminalInput,
                        uint8_t negativeTerminalInput,
                        uint16_t powerModeSelect,
                        uint8_t outputFilterEnableAndDelayLevel,
                        uint16_t invertedOutputPolarity);

extern void COMP_B_setReferenceVoltage(uint32_t baseAddress,
                                       uint16_t supplyVoltageReferenceBase,
                                       uint16_t lowerLimitSupplyVoltageFractionOf32,
                                       uint16_t upperLimitSupplyVoltageFractionOf32,
                                       uint16_t referenceAccuracy);

extern void COMP_B_enableInterrupt(uint32_t baseAddress,
                                   uint16_t interruptMask);

extern void COMP_B_disableInterrupt(uint32_t baseAddress,
                                    uint16_t interruptMask);

extern void COMP_B_clearInterrupt(uint32_t baseAddress,
                                  uint16_t interruptFlagMask);

extern uint8_t COMP_B_getInterruptStatus(uint32_t baseAddress,
                                         uint16_t interruptFlagMask);

extern void COMP_B_interruptSetEdgeDirection(uint32_t baseAddress,
                                             uint16_t edgeDirection);

extern void COMP_B_interruptToggleEdgeDirection(uint32_t baseAddress);

extern void COMP_B_enable(uint32_t baseAddress);

extern void COMP_B_disable(uint32_t baseAddress);

extern void COMP_B_shortInputs(uint32_t baseAddress);

extern void COMP_B_unshortInputs(uint32_t baseAddress);

extern void COMP_B_disableInputBuffer(uint32_t baseAddress,
                                      uint8_t inputPort);

extern void COMP_B_enableInputBuffer(uint32_t baseAddress,
                                     uint8_t inputPort);

extern void COMP_B_IOSwap(uint32_t baseAddress);

extern uint16_t COMP_B_outputValue(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_COMP_B_H__

#endif
