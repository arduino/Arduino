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
// timer_b.h - Driver for the TIMER_B Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_TIMER_B_H__
#define __MSP430WARE_TIMER_B_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_TxB7__

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
// The following is a parameter used for TIMER_B_getCounterValue that
// determines the maximum difference in counts of the TAxR register for a
// majority vote.
//
//*****************************************************************************
#define TIMER_B_THRESHOLD                                                    50

//*****************************************************************************
//
// The following are values that can be passed to the clockSourceDivider
// parameter for functions: TIMER_B_configureContinuousMode(),
// TIMER_B_configureUpMode(), TIMER_B_configureUpDownMode(),
// TIMER_B_startContinuousMode(), TIMER_B_startContinousMode(),
// TIMER_B_startUpMode(), TIMER_B_startUpDownMode(), and TIMER_B_generatePWM().
//
//*****************************************************************************
#define TIMER_B_CLOCKSOURCE_DIVIDER_1                                      0x01
#define TIMER_B_CLOCKSOURCE_DIVIDER_2                                      0x02
#define TIMER_B_CLOCKSOURCE_DIVIDER_4                                      0x04
#define TIMER_B_CLOCKSOURCE_DIVIDER_8                                      0x08
#define TIMER_B_CLOCKSOURCE_DIVIDER_3                                      0x03
#define TIMER_B_CLOCKSOURCE_DIVIDER_5                                      0x05
#define TIMER_B_CLOCKSOURCE_DIVIDER_6                                      0x06
#define TIMER_B_CLOCKSOURCE_DIVIDER_7                                      0x07
#define TIMER_B_CLOCKSOURCE_DIVIDER_10                                     0x0A
#define TIMER_B_CLOCKSOURCE_DIVIDER_12                                     0x0C
#define TIMER_B_CLOCKSOURCE_DIVIDER_14                                     0x0E
#define TIMER_B_CLOCKSOURCE_DIVIDER_16                                     0x10
#define TIMER_B_CLOCKSOURCE_DIVIDER_20                                     0x14
#define TIMER_B_CLOCKSOURCE_DIVIDER_24                                     0x18
#define TIMER_B_CLOCKSOURCE_DIVIDER_28                                     0x1C
#define TIMER_B_CLOCKSOURCE_DIVIDER_32                                     0x20
#define TIMER_B_CLOCKSOURCE_DIVIDER_40                                     0x28
#define TIMER_B_CLOCKSOURCE_DIVIDER_48                                     0x30
#define TIMER_B_CLOCKSOURCE_DIVIDER_56                                     0x38
#define TIMER_B_CLOCKSOURCE_DIVIDER_64                                     0x40

//*****************************************************************************
//
// The following are values that can be passed to the timerMode parameter for
// functions: TIMER_B_startCounter().
//
//*****************************************************************************
#define TIMER_B_STOP_MODE                                                  MC_0
#define TIMER_B_UP_MODE                                                    MC_1
#define TIMER_B_CONTINUOUS_MODE                                            MC_2
#define TIMER_B_UPDOWN_MODE                                                MC_3

//*****************************************************************************
//
// The following are values that can be passed to the timerClear parameter for
// functions: TIMER_B_configureContinuousMode(), TIMER_B_configureUpMode(),
// TIMER_B_configureUpDownMode(), TIMER_B_startContinuousMode(),
// TIMER_B_startContinousMode(), TIMER_B_startUpMode(), and
// TIMER_B_startUpDownMode().
//
//*****************************************************************************
#define TIMER_B_DO_CLEAR                                                  TBCLR
#define TIMER_B_SKIP_CLEAR                                                 0x00

//*****************************************************************************
//
// The following are values that can be passed to the clockSource parameter for
// functions: TIMER_B_configureContinuousMode(), TIMER_B_configureUpMode(),
// TIMER_B_configureUpDownMode(), TIMER_B_startContinuousMode(),
// TIMER_B_startContinousMode(), TIMER_B_startUpMode(),
// TIMER_B_startUpDownMode(), and TIMER_B_generatePWM().
//
//*****************************************************************************
#define TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK                        TBSSEL__TACLK
#define TIMER_B_CLOCKSOURCE_ACLK                                   TBSSEL__ACLK
#define TIMER_B_CLOCKSOURCE_SMCLK                                 TBSSEL__SMCLK
#define TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK               TBSSEL__INCLK

//*****************************************************************************
//
// The following are values that can be passed to the timerInterruptEnable_TBIE
// parameter for functions: TIMER_B_configureContinuousMode(),
// TIMER_B_configureUpMode(), TIMER_B_configureUpDownMode(),
// TIMER_B_startContinuousMode(), TIMER_B_startContinousMode(),
// TIMER_B_startUpMode(), and TIMER_B_startUpDownMode().
//
//*****************************************************************************
#define TIMER_B_TBIE_INTERRUPT_ENABLE                                      TBIE
#define TIMER_B_TBIE_INTERRUPT_DISABLE                                     0x00

//*****************************************************************************
//
// The following are values that can be passed to the
// captureCompareInterruptEnable_CCR0_CCIE parameter for functions:
// TIMER_B_configureUpMode(), TIMER_B_configureUpDownMode(),
// TIMER_B_startUpMode(), and TIMER_B_startUpDownMode().
//
//*****************************************************************************
#define TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE                                 CCIE
#define TIMER_B_CCIE_CCR0_INTERRUPT_DISABLE                                0x00

//*****************************************************************************
//
// The following are values that can be passed to the captureInterruptEnable
// parameter for functions: TIMER_B_initCapture(); the compareInterruptEnable
// parameter for functions: TIMER_B_initCompare().
//
//*****************************************************************************
#define TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE                           0x00
#define TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE                            CCIE

//*****************************************************************************
//
// The following are values that can be passed to the captureInputSelect
// parameter for functions: TIMER_B_initCapture().
//
//*****************************************************************************
#define TIMER_B_CAPTURE_INPUTSELECT_CCIxA                                CCIS_0
#define TIMER_B_CAPTURE_INPUTSELECT_CCIxB                                CCIS_1
#define TIMER_B_CAPTURE_INPUTSELECT_GND                                  CCIS_2
#define TIMER_B_CAPTURE_INPUTSELECT_Vcc                                  CCIS_3

//*****************************************************************************
//
// The following are values that can be passed to the compareOutputMode
// parameter for functions: TIMER_B_initCompare(), and TIMER_B_generatePWM();
// the captureOutputMode parameter for functions: TIMER_B_initCapture().
//
//*****************************************************************************
#define TIMER_B_OUTPUTMODE_OUTBITVALUE                                 OUTMOD_0
#define TIMER_B_OUTPUTMODE_SET                                         OUTMOD_1
#define TIMER_B_OUTPUTMODE_TOGGLE_RESET                                OUTMOD_2
#define TIMER_B_OUTPUTMODE_SET_RESET                                   OUTMOD_3
#define TIMER_B_OUTPUTMODE_TOGGLE                                      OUTMOD_4
#define TIMER_B_OUTPUTMODE_RESET                                       OUTMOD_5
#define TIMER_B_OUTPUTMODE_TOGGLE_SET                                  OUTMOD_6
#define TIMER_B_OUTPUTMODE_RESET_SET                                   OUTMOD_7

//*****************************************************************************
//
// The following are values that can be passed to the compareRegister parameter
// for functions: TIMER_B_initCompare(), TIMER_B_generatePWM(),
// TIMER_B_setCompareValue(), and TIMER_B_initCompareLatchLoadEvent(); the
// captureCompareRegister parameter for functions:
// TIMER_B_enableCaptureCompareInterrupt(),
// TIMER_B_disableCaptureCompareInterrupt(),
// TIMER_B_getCaptureCompareInterruptStatus(),
// TIMER_B_getSynchronizedCaptureCompareInput(),
// TIMER_B_getOutputForOutputModeOutBitValue(),
// TIMER_B_getCaptureCompareCount(),
// TIMER_B_setOutputForOutputModeOutBitValue(), and
// TIMER_B_clearCaptureCompareInterruptFlag(); the captureRegister parameter
// for functions: TIMER_B_initCapture().
//
//*****************************************************************************
#define TIMER_B_CAPTURECOMPARE_REGISTER_0                                  0x02
#define TIMER_B_CAPTURECOMPARE_REGISTER_1                                  0x04
#define TIMER_B_CAPTURECOMPARE_REGISTER_2                                  0x06
#define TIMER_B_CAPTURECOMPARE_REGISTER_3                                  0x08
#define TIMER_B_CAPTURECOMPARE_REGISTER_4                                  0x0A
#define TIMER_B_CAPTURECOMPARE_REGISTER_5                                  0x0C
#define TIMER_B_CAPTURECOMPARE_REGISTER_6                                  0x0E

//*****************************************************************************
//
// The following are values that can be passed to the captureMode parameter for
// functions: TIMER_B_initCapture().
//
//*****************************************************************************
#define TIMER_B_CAPTUREMODE_NO_CAPTURE                                     CM_0
#define TIMER_B_CAPTUREMODE_RISING_EDGE                                    CM_1
#define TIMER_B_CAPTUREMODE_FALLING_EDGE                                   CM_2
#define TIMER_B_CAPTUREMODE_RISING_AND_FALLING_EDGE                        CM_3

//*****************************************************************************
//
// The following are values that can be passed to the synchronizeCaptureSource
// parameter for functions: TIMER_B_initCapture().
//
//*****************************************************************************
#define TIMER_B_CAPTURE_ASYNCHRONOUS                                       0x00
#define TIMER_B_CAPTURE_SYNCHRONOUS                                         SCS

//*****************************************************************************
//
// The following are values that can be passed to the mask parameter for
// functions: TIMER_B_getCaptureCompareInterruptStatus() as well as returned by
// the TIMER_B_getCaptureCompareInterruptStatus() function.
//
//*****************************************************************************
#define TIMER_B_CAPTURE_OVERFLOW                                            COV
#define TIMER_B_CAPTURECOMPARE_INTERRUPT_FLAG                             CCIFG

//*****************************************************************************
//
// The following are values that can be passed to the synchronized parameter
// for functions: TIMER_B_getSynchronizedCaptureCompareInput().
//
//*****************************************************************************
#define TIMER_B_READ_SYNCHRONIZED_CAPTURECOMPAREINPUT                      SCCI
#define TIMER_B_READ_CAPTURE_COMPARE_INPUT                                  CCI

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the TIMER_B_getSynchronizedCaptureCompareInput()
// function.
//
//*****************************************************************************
#define TIMER_B_CAPTURECOMPARE_INPUT_HIGH                                  0x01
#define TIMER_B_CAPTURECOMPARE_INPUT_LOW                                   0x00

//*****************************************************************************
//
// The following are values that can be passed to the outputModeOutBitValue
// parameter for functions: TIMER_B_setOutputForOutputModeOutBitValue() as well
// as returned by the TIMER_B_getOutputForOutputModeOutBitValue() function.
//
//*****************************************************************************
#define TIMER_B_OUTPUTMODE_OUTBITVALUE_HIGH                                 OUT
#define TIMER_B_OUTPUTMODE_OUTBITVALUE_LOW                                 0x00

//*****************************************************************************
//
// The following are values that can be passed to the counterLength parameter
// for functions: TIMER_B_selectCounterLength().
//
//*****************************************************************************
#define TIMER_B_COUNTER_16BIT                                            CNTL_3
#define TIMER_B_COUNTER_12BIT                                            CNTL_2
#define TIMER_B_COUNTER_10BIT                                            CNTL_1
#define TIMER_B_COUNTER_8BIT                                             CNTL_0

//*****************************************************************************
//
// The following are values that can be passed to the groupLatch parameter for
// functions: TIMER_B_selectLatchingGroup().
//
//*****************************************************************************
#define TIMER_B_GROUP_NONE                                            TBCLGRP_0
#define TIMER_B_GROUP_CL12_CL23_CL56                                  TBCLGRP_1
#define TIMER_B_GROUP_CL123_CL456                                     TBCLGRP_2
#define TIMER_B_GROUP_ALL                                             TBCLGRP_3

//*****************************************************************************
//
// The following are values that can be passed to the compareLatchLoadEvent
// parameter for functions: TIMER_B_initCompareLatchLoadEvent().
//
//*****************************************************************************
#define TIMER_B_LATCH_ON_WRITE_TO_TBxCCRn_COMPARE_REGISTER               CLLD_0
#define TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_0_IN_UP_OR_CONT_MODE        CLLD_1
#define TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_0_IN_UPDOWN_MODE            CLLD_2
#define TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_CURRENT_COMPARE_LATCH_VALUE CLLD_3

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the TIMER_B_getInterruptStatus() function.
//
//*****************************************************************************
#define TIMER_B_INTERRUPT_NOT_PENDING                                      0x00
#define TIMER_B_INTERRUPT_PENDING                                          0x01

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void TIMER_B_startCounter(uint32_t baseAddress,
                                 uint16_t timerMode);

extern void TIMER_B_configureContinuousMode(uint32_t baseAddress,
                                            uint16_t clockSource,
                                            uint16_t clockSourceDivider,
                                            uint16_t timerInterruptEnable_TBIE,
                                            uint16_t timerClear);

extern void TIMER_B_configureUpMode(uint32_t baseAddress,
                                    uint16_t clockSource,
                                    uint16_t clockSourceDivider,
                                    uint16_t timerPeriod,
                                    uint16_t timerInterruptEnable_TBIE,
                                    uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                    uint16_t timerClear);

extern void TIMER_B_configureUpDownMode(uint32_t baseAddress,
                                        uint16_t clockSource,
                                        uint16_t clockSourceDivider,
                                        uint16_t timerPeriod,
                                        uint16_t timerInterruptEnable_TBIE,
                                        uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                        uint16_t timerClear);

extern void TIMER_B_startContinuousMode(uint32_t baseAddress,
                                        uint16_t clockSource,
                                        uint16_t clockSourceDivider,
                                        uint16_t timerInterruptEnable_TBIE,
                                        uint16_t timerClear);

extern void TIMER_B_startContinousMode(uint32_t baseAddress,
                                       uint16_t clockSource,
                                       uint16_t clockSourceDivider,
                                       uint16_t timerInterruptEnable_TBIE,
                                       uint16_t timerClear);

extern void TIMER_B_startUpMode(uint32_t baseAddress,
                                uint16_t clockSource,
                                uint16_t clockSourceDivider,
                                uint16_t timerPeriod,
                                uint16_t timerInterruptEnable_TBIE,
                                uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                uint16_t timerClear);

extern void TIMER_B_startUpDownMode(uint32_t baseAddress,
                                    uint16_t clockSource,
                                    uint16_t clockSourceDivider,
                                    uint16_t timerPeriod,
                                    uint16_t timerInterruptEnable_TBIE,
                                    uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                    uint16_t timerClear);

extern void TIMER_B_initCapture(uint32_t baseAddress,
                                uint16_t captureRegister,
                                uint16_t captureMode,
                                uint16_t captureInputSelect,
                                uint16_t synchronizeCaptureSource,
                                uint16_t captureInterruptEnable,
                                uint16_t captureOutputMode);

extern void TIMER_B_initCompare(uint32_t baseAddress,
                                uint16_t compareRegister,
                                uint16_t compareInterruptEnable,
                                uint16_t compareOutputMode,
                                uint16_t compareValue);

extern void TIMER_B_enableInterrupt(uint32_t baseAddress);

extern void TIMER_B_disableInterrupt(uint32_t baseAddress);

extern uint32_t TIMER_B_getInterruptStatus(uint32_t baseAddress);

extern void TIMER_B_enableCaptureCompareInterrupt(uint32_t baseAddress,
                                                  uint16_t captureCompareRegister);

extern void TIMER_B_disableCaptureCompareInterrupt(uint32_t baseAddress,
                                                   uint16_t captureCompareRegister);

extern uint32_t TIMER_B_getCaptureCompareInterruptStatus(uint32_t baseAddress,
                                                         uint16_t captureCompareRegister,
                                                         uint16_t mask);

extern void TIMER_B_clear(uint32_t baseAddress);

extern uint8_t TIMER_B_getSynchronizedCaptureCompareInput(uint32_t baseAddress,
                                                          uint16_t captureCompareRegister,
                                                          uint16_t synchronized);

extern uint8_t TIMER_B_getOutputForOutputModeOutBitValue(uint32_t baseAddress,
                                                         uint16_t captureCompareRegister);

extern uint16_t TIMER_B_getCaptureCompareCount(uint32_t baseAddress,
                                               uint16_t captureCompareRegister);

extern void TIMER_B_setOutputForOutputModeOutBitValue(uint32_t baseAddress,
                                                      uint16_t captureCompareRegister,
                                                      uint8_t outputModeOutBitValue);

extern void TIMER_B_generatePWM(uint32_t baseAddress,
                                uint16_t clockSource,
                                uint16_t clockSourceDivider,
                                uint16_t timerPeriod,
                                uint16_t compareRegister,
                                uint16_t compareOutputMode,
                                uint16_t dutyCycle);

extern void TIMER_B_stop(uint32_t baseAddress);

extern void TIMER_B_setCompareValue(uint32_t baseAddress,
                                    uint16_t compareRegister,
                                    uint16_t compareValue);

extern void TIMER_B_clearTimerInterruptFlag(uint32_t baseAddress);

extern void TIMER_B_clearCaptureCompareInterruptFlag(uint32_t baseAddress,
                                                     uint16_t captureCompareRegister);

extern void TIMER_B_selectCounterLength(uint16_t baseAddress,
                                        uint16_t counterLength);

extern void TIMER_B_selectLatchingGroup(uint16_t baseAddress,
                                        uint16_t groupLatch);

extern void TIMER_B_initCompareLatchLoadEvent(uint16_t baseAddress,
                                              uint16_t compareRegister,
                                              uint16_t compareLatchLoadEvent);

extern uint16_t TIMER_B_getCounterValue(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_TIMER_B_H__

#endif
