//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430F5529__) || defined(__MSP430FR5739__)

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
// timer_a.h - Driver for the TIMER_A Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_TIMER_A_H__
#define __MSP430WARE_TIMER_A_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_TxA7__

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
// The following is a parameter used for TIMER_A_getCounterValue that
// determines the maximum difference in counts of the TAxR register for a
// majority vote.
//
//*****************************************************************************
#define TIMER_A_THRESHOLD                                                    50

//*****************************************************************************
//
// The following are values that can be passed to the clockSourceDivider
// parameter for functions: TIMER_A_configureContinuousMode(),
// TIMER_A_configureUpMode(), TIMER_A_configureUpDownMode(),
// TIMER_A_startContinuousMode(), TIMER_A_startContinousMode(),
// TIMER_A_startUpMode(), TIMER_A_startUpDownMode(), and TIMER_A_generatePWM().
//
//*****************************************************************************
#define TIMER_A_CLOCKSOURCE_DIVIDER_1                                      0x01
#define TIMER_A_CLOCKSOURCE_DIVIDER_2                                      0x02
#define TIMER_A_CLOCKSOURCE_DIVIDER_4                                      0x04
#define TIMER_A_CLOCKSOURCE_DIVIDER_8                                      0x08
#define TIMER_A_CLOCKSOURCE_DIVIDER_3                                      0x03
#define TIMER_A_CLOCKSOURCE_DIVIDER_5                                      0x05
#define TIMER_A_CLOCKSOURCE_DIVIDER_6                                      0x06
#define TIMER_A_CLOCKSOURCE_DIVIDER_7                                      0x07
#define TIMER_A_CLOCKSOURCE_DIVIDER_10                                     0x0A
#define TIMER_A_CLOCKSOURCE_DIVIDER_12                                     0x0C
#define TIMER_A_CLOCKSOURCE_DIVIDER_14                                     0x0E
#define TIMER_A_CLOCKSOURCE_DIVIDER_16                                     0x10
#define TIMER_A_CLOCKSOURCE_DIVIDER_20                                     0x14
#define TIMER_A_CLOCKSOURCE_DIVIDER_24                                     0x18
#define TIMER_A_CLOCKSOURCE_DIVIDER_28                                     0x1C
#define TIMER_A_CLOCKSOURCE_DIVIDER_32                                     0x20
#define TIMER_A_CLOCKSOURCE_DIVIDER_40                                     0x28
#define TIMER_A_CLOCKSOURCE_DIVIDER_48                                     0x30
#define TIMER_A_CLOCKSOURCE_DIVIDER_56                                     0x38
#define TIMER_A_CLOCKSOURCE_DIVIDER_64                                     0x40

//*****************************************************************************
//
// The following are values that can be passed to the timerMode parameter for
// functions: TIMER_A_startCounter().
//
//*****************************************************************************
#define TIMER_A_STOP_MODE                                                  MC_0
#define TIMER_A_UP_MODE                                                    MC_1
#define TIMER_A_CONTINUOUS_MODE                                            MC_2
#define TIMER_A_UPDOWN_MODE                                                MC_3

//*****************************************************************************
//
// The following are values that can be passed to the timerClear parameter for
// functions: TIMER_A_configureContinuousMode(), TIMER_A_configureUpMode(),
// TIMER_A_configureUpDownMode(), TIMER_A_startContinuousMode(),
// TIMER_A_startContinousMode(), TIMER_A_startUpMode(), and
// TIMER_A_startUpDownMode().
//
//*****************************************************************************
#define TIMER_A_DO_CLEAR                                                  TACLR
#define TIMER_A_SKIP_CLEAR                                                 0x00

//*****************************************************************************
//
// The following are values that can be passed to the clockSource parameter for
// functions: TIMER_A_configureContinuousMode(), TIMER_A_configureUpMode(),
// TIMER_A_configureUpDownMode(), TIMER_A_startContinuousMode(),
// TIMER_A_startContinousMode(), TIMER_A_startUpMode(),
// TIMER_A_startUpDownMode(), and TIMER_A_generatePWM().
//
//*****************************************************************************
#define TIMER_A_CLOCKSOURCE_EXTERNAL_TXCLK                        TASSEL__TACLK
#define TIMER_A_CLOCKSOURCE_ACLK                                   TASSEL__ACLK
#define TIMER_A_CLOCKSOURCE_SMCLK                                 TASSEL__SMCLK
#define TIMER_A_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK               TASSEL__INCLK

//*****************************************************************************
//
// The following are values that can be passed to the timerInterruptEnable_TAIE
// parameter for functions: TIMER_A_configureContinuousMode(),
// TIMER_A_configureUpMode(), TIMER_A_configureUpDownMode(),
// TIMER_A_startContinuousMode(), TIMER_A_startContinousMode(),
// TIMER_A_startUpMode(), and TIMER_A_startUpDownMode().
//
//*****************************************************************************
#define TIMER_A_TAIE_INTERRUPT_ENABLE                                      TAIE
#define TIMER_A_TAIE_INTERRUPT_DISABLE                                     0x00

//*****************************************************************************
//
// The following are values that can be passed to the
// captureCompareInterruptEnable_CCR0_CCIE parameter for functions:
// TIMER_A_configureUpMode(), TIMER_A_configureUpDownMode(),
// TIMER_A_startUpMode(), and TIMER_A_startUpDownMode().
//
//*****************************************************************************
#define TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE                                 CCIE
#define TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE                                0x00

//*****************************************************************************
//
// The following are values that can be passed to the captureInterruptEnable
// parameter for functions: TIMER_A_initCapture(); the compareInterruptEnable
// parameter for functions: TIMER_A_initCompare().
//
//*****************************************************************************
#define TIMER_A_CAPTURECOMPARE_INTERRUPT_DISABLE                           0x00
#define TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE                            CCIE

//*****************************************************************************
//
// The following are values that can be passed to the captureInputSelect
// parameter for functions: TIMER_A_initCapture().
//
//*****************************************************************************
#define TIMER_A_CAPTURE_INPUTSELECT_CCIxA                                CCIS_0
#define TIMER_A_CAPTURE_INPUTSELECT_CCIxB                                CCIS_1
#define TIMER_A_CAPTURE_INPUTSELECT_GND                                  CCIS_2
#define TIMER_A_CAPTURE_INPUTSELECT_Vcc                                  CCIS_3

//*****************************************************************************
//
// The following are values that can be passed to the compareOutputMode
// parameter for functions: TIMER_A_initCompare(), and TIMER_A_generatePWM();
// the captureOutputMode parameter for functions: TIMER_A_initCapture().
//
//*****************************************************************************
#define TIMER_A_OUTPUTMODE_OUTBITVALUE                                 OUTMOD_0
#define TIMER_A_OUTPUTMODE_SET                                         OUTMOD_1
#define TIMER_A_OUTPUTMODE_TOGGLE_RESET                                OUTMOD_2
#define TIMER_A_OUTPUTMODE_SET_RESET                                   OUTMOD_3
#define TIMER_A_OUTPUTMODE_TOGGLE                                      OUTMOD_4
#define TIMER_A_OUTPUTMODE_RESET                                       OUTMOD_5
#define TIMER_A_OUTPUTMODE_TOGGLE_SET                                  OUTMOD_6
#define TIMER_A_OUTPUTMODE_RESET_SET                                   OUTMOD_7

//*****************************************************************************
//
// The following are values that can be passed to the compareRegister parameter
// for functions: TIMER_A_initCompare(), TIMER_A_generatePWM(), and
// TIMER_A_setCompareValue(); the captureCompareRegister parameter for
// functions: TIMER_A_enableCaptureCompareInterrupt(),
// TIMER_A_disableCaptureCompareInterrupt(),
// TIMER_A_getCaptureCompareInterruptStatus(),
// TIMER_A_getSynchronizedCaptureCompareInput(),
// TIMER_A_getOutputForOutputModeOutBitValue(),
// TIMER_A_getCaptureCompareCount(),
// TIMER_A_setOutputForOutputModeOutBitValue(), and
// TIMER_A_clearCaptureCompareInterruptFlag(); the captureRegister parameter
// for functions: TIMER_A_initCapture().
//
//*****************************************************************************
#define TIMER_A_CAPTURECOMPARE_REGISTER_0                                  0x02
#define TIMER_A_CAPTURECOMPARE_REGISTER_1                                  0x04
#define TIMER_A_CAPTURECOMPARE_REGISTER_2                                  0x06
#define TIMER_A_CAPTURECOMPARE_REGISTER_3                                  0x08
#define TIMER_A_CAPTURECOMPARE_REGISTER_4                                  0x0A
#define TIMER_A_CAPTURECOMPARE_REGISTER_5                                  0x0C
#define TIMER_A_CAPTURECOMPARE_REGISTER_6                                  0x0E

//*****************************************************************************
//
// The following are values that can be passed to the captureMode parameter for
// functions: TIMER_A_initCapture().
//
//*****************************************************************************
#define TIMER_A_CAPTUREMODE_NO_CAPTURE                                     CM_0
#define TIMER_A_CAPTUREMODE_RISING_EDGE                                    CM_1
#define TIMER_A_CAPTUREMODE_FALLING_EDGE                                   CM_2
#define TIMER_A_CAPTUREMODE_RISING_AND_FALLING_EDGE                        CM_3

//*****************************************************************************
//
// The following are values that can be passed to the synchronizeCaptureSource
// parameter for functions: TIMER_A_initCapture().
//
//*****************************************************************************
#define TIMER_A_CAPTURE_ASYNCHRONOUS                                       0x00
#define TIMER_A_CAPTURE_SYNCHRONOUS                                         SCS

//*****************************************************************************
//
// The following are values that can be passed to the mask parameter for
// functions: TIMER_A_getCaptureCompareInterruptStatus() as well as returned by
// the TIMER_A_getCaptureCompareInterruptStatus() function.
//
//*****************************************************************************
#define TIMER_A_CAPTURE_OVERFLOW                                            COV
#define TIMER_A_CAPTURECOMPARE_INTERRUPT_FLAG                             CCIFG

//*****************************************************************************
//
// The following are values that can be passed to the synchronized parameter
// for functions: TIMER_A_getSynchronizedCaptureCompareInput().
//
//*****************************************************************************
#define TIMER_A_READ_SYNCHRONIZED_CAPTURECOMPAREINPUT                      SCCI
#define TIMER_A_READ_CAPTURE_COMPARE_INPUT                                  CCI

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the TIMER_A_getSynchronizedCaptureCompareInput()
// function.
//
//*****************************************************************************
#define TIMER_A_CAPTURECOMPARE_INPUT_HIGH                                  0x01
#define TIMER_A_CAPTURECOMPARE_INPUT_LOW                                   0x00

//*****************************************************************************
//
// The following are values that can be passed to the outputModeOutBitValue
// parameter for functions: TIMER_A_setOutputForOutputModeOutBitValue() as well
// as returned by the TIMER_A_getOutputForOutputModeOutBitValue() function.
//
//*****************************************************************************
#define TIMER_A_OUTPUTMODE_OUTBITVALUE_HIGH                                 OUT
#define TIMER_A_OUTPUTMODE_OUTBITVALUE_LOW                                 0x00

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the TIMER_A_getInterruptStatus() function.
//
//*****************************************************************************
#define TIMER_A_INTERRUPT_NOT_PENDING                                      0x00
#define TIMER_A_INTERRUPT_PENDING                                          0x01

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void TIMER_A_startCounter(uint32_t baseAddress,
                                 uint16_t timerMode);

extern void TIMER_A_configureContinuousMode(uint32_t baseAddress,
                                            uint16_t clockSource,
                                            uint16_t clockSourceDivider,
                                            uint16_t timerInterruptEnable_TAIE,
                                            uint16_t timerClear);

extern void TIMER_A_configureUpMode(uint32_t baseAddress,
                                    uint16_t clockSource,
                                    uint16_t clockSourceDivider,
                                    uint16_t timerPeriod,
                                    uint16_t timerInterruptEnable_TAIE,
                                    uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                    uint16_t timerClear);

extern void TIMER_A_configureUpDownMode(uint32_t baseAddress,
                                        uint16_t clockSource,
                                        uint16_t clockSourceDivider,
                                        uint16_t timerPeriod,
                                        uint16_t timerInterruptEnable_TAIE,
                                        uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                        uint16_t timerClear);

extern void TIMER_A_startContinuousMode(uint32_t baseAddress,
                                        uint16_t clockSource,
                                        uint16_t clockSourceDivider,
                                        uint16_t timerInterruptEnable_TAIE,
                                        uint16_t timerClear);

extern void TIMER_A_startContinousMode(uint32_t baseAddress,
                                       uint16_t clockSource,
                                       uint16_t clockSourceDivider,
                                       uint16_t timerInterruptEnable_TAIE,
                                       uint16_t timerClear);

extern void TIMER_A_startUpMode(uint32_t baseAddress,
                                uint16_t clockSource,
                                uint16_t clockSourceDivider,
                                uint16_t timerPeriod,
                                uint16_t timerInterruptEnable_TAIE,
                                uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                uint16_t timerClear);

extern void TIMER_A_startUpDownMode(uint32_t baseAddress,
                                    uint16_t clockSource,
                                    uint16_t clockSourceDivider,
                                    uint16_t timerPeriod,
                                    uint16_t timerInterruptEnable_TAIE,
                                    uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                    uint16_t timerClear);

extern void TIMER_A_initCapture(uint32_t baseAddress,
                                uint16_t captureRegister,
                                uint16_t captureMode,
                                uint16_t captureInputSelect,
                                uint16_t synchronizeCaptureSource,
                                uint16_t captureInterruptEnable,
                                uint16_t captureOutputMode);

extern void TIMER_A_initCompare(uint32_t baseAddress,
                                uint16_t compareRegister,
                                uint16_t compareInterruptEnable,
                                uint16_t compareOutputMode,
                                uint16_t compareValue);

extern void TIMER_A_enableInterrupt(uint32_t baseAddress);

extern void TIMER_A_disableInterrupt(uint32_t baseAddress);

extern uint32_t TIMER_A_getInterruptStatus(uint32_t baseAddress);

extern void TIMER_A_enableCaptureCompareInterrupt(uint32_t baseAddress,
                                                  uint16_t captureCompareRegister);

extern void TIMER_A_disableCaptureCompareInterrupt(uint32_t baseAddress,
                                                   uint16_t captureCompareRegister);

extern uint32_t TIMER_A_getCaptureCompareInterruptStatus(uint32_t baseAddress,
                                                         uint16_t captureCompareRegister,
                                                         uint16_t mask);

extern void TIMER_A_clear(uint32_t baseAddress);

extern uint8_t TIMER_A_getSynchronizedCaptureCompareInput(uint32_t baseAddress,
                                                          uint16_t captureCompareRegister,
                                                          uint16_t synchronized);

extern uint8_t TIMER_A_getOutputForOutputModeOutBitValue(uint32_t baseAddress,
                                                         uint16_t captureCompareRegister);

extern uint16_t TIMER_A_getCaptureCompareCount(uint32_t baseAddress,
                                               uint16_t captureCompareRegister);

extern void TIMER_A_setOutputForOutputModeOutBitValue(uint32_t baseAddress,
                                                      uint16_t captureCompareRegister,
                                                      uint8_t outputModeOutBitValue);

extern void TIMER_A_generatePWM(uint32_t baseAddress,
                                uint16_t clockSource,
                                uint16_t clockSourceDivider,
                                uint16_t timerPeriod,
                                uint16_t compareRegister,
                                uint16_t compareOutputMode,
                                uint16_t dutyCycle);

extern void TIMER_A_stop(uint32_t baseAddress);

extern void TIMER_A_setCompareValue(uint32_t baseAddress,
                                    uint16_t compareRegister,
                                    uint16_t compareValue);

extern void TIMER_A_clearTimerInterruptFlag(uint32_t baseAddress);

extern void TIMER_A_clearCaptureCompareInterruptFlag(uint32_t baseAddress,
                                                     uint16_t captureCompareRegister);

extern uint16_t TIMER_A_getCounterValue(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_TIMER_A_H__

#endif
