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
// adc12_b.h - Driver for the ADC12_B Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_ADC12_B_H__
#define __MSP430WARE_ADC12_B_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_ADC12_B__

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
// The following are values that can be passed to the clockSourceDivider
// parameter for functions: ADC12_B_init().
//
//*****************************************************************************
#define ADC12_B_CLOCKDIVIDER_1                                     (ADC12DIV_0)
#define ADC12_B_CLOCKDIVIDER_2                                     (ADC12DIV_1)
#define ADC12_B_CLOCKDIVIDER_3                                     (ADC12DIV_2)
#define ADC12_B_CLOCKDIVIDER_4                                     (ADC12DIV_3)
#define ADC12_B_CLOCKDIVIDER_5                                     (ADC12DIV_4)
#define ADC12_B_CLOCKDIVIDER_6                                     (ADC12DIV_5)
#define ADC12_B_CLOCKDIVIDER_7                                     (ADC12DIV_6)
#define ADC12_B_CLOCKDIVIDER_8                                     (ADC12DIV_7)

//*****************************************************************************
//
// The following are values that can be passed to the clockSourceSelect
// parameter for functions: ADC12_B_init().
//
//*****************************************************************************
#define ADC12_B_CLOCKSOURCE_ADC12OSC                              (ADC12SSEL_0)
#define ADC12_B_CLOCKSOURCE_ACLK                                  (ADC12SSEL_1)
#define ADC12_B_CLOCKSOURCE_MCLK                                  (ADC12SSEL_2)
#define ADC12_B_CLOCKSOURCE_SMCLK                                 (ADC12SSEL_3)

//*****************************************************************************
//
// The following are values that can be passed to the clockSourcePredivider
// parameter for functions: ADC12_B_init().
//
//*****************************************************************************
#define ADC12_B_CLOCKPREDIVIDER__1                               (ADC12PDIV__1)
#define ADC12_B_CLOCKPREDIVIDER__4                               (ADC12PDIV__4)
#define ADC12_B_CLOCKPREDIVIDER__32                             (ADC12PDIV__32)
#define ADC12_B_CLOCKPREDIVIDER__64                             (ADC12PDIV__64)

//*****************************************************************************
//
// The following are values that can be passed to the
// sampleHoldSignalSourceSelect parameter for functions: ADC12_B_init().
//
//*****************************************************************************
#define ADC12_B_SAMPLEHOLDSOURCE_SC                                (ADC12SHS_0)
#define ADC12_B_SAMPLEHOLDSOURCE_1                                 (ADC12SHS_1)
#define ADC12_B_SAMPLEHOLDSOURCE_2                                 (ADC12SHS_2)
#define ADC12_B_SAMPLEHOLDSOURCE_3                                 (ADC12SHS_3)
#define ADC12_B_SAMPLEHOLDSOURCE_4                                 (ADC12SHS_4)
#define ADC12_B_SAMPLEHOLDSOURCE_5                                 (ADC12SHS_5)
#define ADC12_B_SAMPLEHOLDSOURCE_6                                 (ADC12SHS_6)
#define ADC12_B_SAMPLEHOLDSOURCE_7                                 (ADC12SHS_7)

//*****************************************************************************
//
// The following are values that can be passed to the internalChannelMap
// parameter for functions: ADC12_B_init().
//
//*****************************************************************************
#define ADC12_B_MAPINTCH3                                        (ADC12ICH3MAP)
#define ADC12_B_MAPINTCH2                                        (ADC12ICH2MAP)
#define ADC12_B_MAPINTCH1                                        (ADC12ICH1MAP)
#define ADC12_B_MAPINTCH0                                        (ADC12ICH0MAP)
#define ADC12_B_TEMPSENSEMAP                                       (ADC12TCMAP)
#define ADC12_B_BATTMAP                                           (ADC12BATMAP)
#define ADC12_B_NOINTCH                                                  (0x00)

//*****************************************************************************
//
// The following are values that can be passed to the clockCycleHoldCountLowMem
// parameter for functions: ADC12_B_setupSamplingTimer(); the
// clockCycleHoldCountHighMem parameter for functions:
// ADC12_B_setupSamplingTimer().
//
//*****************************************************************************
#define ADC12_B_CYCLEHOLD_4_CYCLES                                (ADC12SHT0_0)
#define ADC12_B_CYCLEHOLD_8_CYCLES                                (ADC12SHT0_1)
#define ADC12_B_CYCLEHOLD_16_CYCLES                               (ADC12SHT0_2)
#define ADC12_B_CYCLEHOLD_32_CYCLES                               (ADC12SHT0_3)
#define ADC12_B_CYCLEHOLD_64_CYCLES                               (ADC12SHT0_4)
#define ADC12_B_CYCLEHOLD_96_CYCLES                               (ADC12SHT0_5)
#define ADC12_B_CYCLEHOLD_128_CYCLES                              (ADC12SHT0_6)
#define ADC12_B_CYCLEHOLD_192_CYCLES                              (ADC12SHT0_7)
#define ADC12_B_CYCLEHOLD_256_CYCLES                              (ADC12SHT0_8)
#define ADC12_B_CYCLEHOLD_384_CYCLES                              (ADC12SHT0_9)
#define ADC12_B_CYCLEHOLD_512_CYCLES                             (ADC12SHT0_10)
#define ADC12_B_CYCLEHOLD_768_CYCLES                             (ADC12SHT0_11)
#define ADC12_B_CYCLEHOLD_1024_CYCLES                            (ADC12SHT0_12)

//*****************************************************************************
//
// The following are values that can be passed to the multipleSamplesEnabled
// parameter for functions: ADC12_B_setupSamplingTimer().
//
//*****************************************************************************
#define ADC12_B_MULTIPLESAMPLESDISABLE                            (!(ADC12MSC))
#define ADC12_B_MULTIPLESAMPLESENABLE                                (ADC12MSC)

//*****************************************************************************
//
// The following are values that can be passed to the differentialModeSelect
// parameter for functions: ADC12_B_memoryConfigure().
//
//*****************************************************************************
#define ADC12_B_DIFFERENTIAL_MODE_DISABLE                                (0x00)
#define ADC12_B_DIFFERENTIAL_MODE_ENABLE                             (ADC12DIF)

//*****************************************************************************
//
// The following are values that can be passed to the endOfSequence parameter
// for functions: ADC12_B_memoryConfigure().
//
//*****************************************************************************
#define ADC12_B_NOTENDOFSEQUENCE                                  (!(ADC12EOS))
#define ADC12_B_ENDOFSEQUENCE                                        (ADC12EOS)

//*****************************************************************************
//
// The following are values that can be passed to the refVoltageSourceSelect
// parameter for functions: ADC12_B_memoryConfigure().
//
//*****************************************************************************
#define ADC12_B_VREFPOS_AVCC_VREFNEG_VSS                         (ADC12VRSEL_0)
#define ADC12_B_VREFPOS_INTBUF_VREFNEG_VSS                       (ADC12VRSEL_1)
#define ADC12_B_VREFPOS_EXTNEG_VREFNEG_VSS                       (ADC12VRSEL_2)
#define ADC12_B_VREFPOS_EXTBUF_VREFNEG_VSS                       (ADC12VRSEL_3)
#define ADC12_B_VREFPOS_EXTPOS_VREFNEG_VSS                       (ADC12VRSEL_4)
#define ADC12_B_VREFPOS_AVCC_VREFNEG_EXTBUF                      (ADC12VRSEL_5)
#define ADC12_B_VREFPOS_AVCC_VREFNEG_EXTPOS                      (ADC12VRSEL_6)
#define ADC12_B_VREFPOS_INTBUF_VREFNEG_EXTPOS                    (ADC12VRSEL_7)
#define ADC12_B_VREFPOS_AVCC_VREFNEG_INTBUF                      (ADC12VRSEL_9)
#define ADC12_B_VREFPOS_EXTPOS_VREFNEG_INTBUF                   (ADC12VRSEL_11)
#define ADC12_B_VREFPOS_AVCC_VREFNEG_EXTNEG                     (ADC12VRSEL_12)
#define ADC12_B_VREFPOS_INTBUF_VREFNEG_EXTNEG                   (ADC12VRSEL_13)
#define ADC12_B_VREFPOS_EXTPOS_VREFNEG_EXTNEG                   (ADC12VRSEL_14)
#define ADC12_B_VREFPOS_EXTBUF_VREFNEG_EXTNEG                   (ADC12VRSEL_15)

//*****************************************************************************
//
// The following are values that can be passed to the inputSourceSelect
// parameter for functions: ADC12_B_memoryConfigure().
//
//*****************************************************************************
#define ADC12_B_INPUT_A0                                          (ADC12INCH_0)
#define ADC12_B_INPUT_A1                                          (ADC12INCH_1)
#define ADC12_B_INPUT_A2                                          (ADC12INCH_2)
#define ADC12_B_INPUT_A3                                          (ADC12INCH_3)
#define ADC12_B_INPUT_A4                                          (ADC12INCH_4)
#define ADC12_B_INPUT_A5                                          (ADC12INCH_5)
#define ADC12_B_INPUT_A6                                          (ADC12INCH_6)
#define ADC12_B_INPUT_A7                                          (ADC12INCH_7)
#define ADC12_B_INPUT_A8                                          (ADC12INCH_8)
#define ADC12_B_INPUT_A9                                          (ADC12INCH_9)
#define ADC12_B_INPUT_A10                                        (ADC12INCH_10)
#define ADC12_B_INPUT_A11                                        (ADC12INCH_11)
#define ADC12_B_INPUT_A12                                        (ADC12INCH_12)
#define ADC12_B_INPUT_A13                                        (ADC12INCH_13)
#define ADC12_B_INPUT_A14                                        (ADC12INCH_14)
#define ADC12_B_INPUT_A15                                        (ADC12INCH_15)
#define ADC12_B_INPUT_A16                                        (ADC12INCH_16)
#define ADC12_B_INPUT_A17                                        (ADC12INCH_17)
#define ADC12_B_INPUT_A18                                        (ADC12INCH_18)
#define ADC12_B_INPUT_A19                                        (ADC12INCH_19)
#define ADC12_B_INPUT_A20                                        (ADC12INCH_20)
#define ADC12_B_INPUT_A21                                        (ADC12INCH_21)
#define ADC12_B_INPUT_A22                                        (ADC12INCH_22)
#define ADC12_B_INPUT_A23                                        (ADC12INCH_23)
#define ADC12_B_INPUT_A24                                        (ADC12INCH_24)
#define ADC12_B_INPUT_A25                                        (ADC12INCH_25)
#define ADC12_B_INPUT_A26                                        (ADC12INCH_26)
#define ADC12_B_INPUT_A27                                        (ADC12INCH_27)
#define ADC12_B_INPUT_A28                                        (ADC12INCH_28)
#define ADC12_B_INPUT_A29                                        (ADC12INCH_29)
#define ADC12_B_INPUT_TCMAP                                      (ADC12INCH_30)
#define ADC12_B_INPUT_BATMAP                                     (ADC12INCH_31)

//*****************************************************************************
//
// The following are values that can be passed to the windowComparatorSelect
// parameter for functions: ADC12_B_memoryConfigure().
//
//*****************************************************************************
#define ADC12_B_WINDOW_COMPARATOR_DISABLE                                (0x00)
#define ADC12_B_WINDOW_COMPARATOR_ENABLE                            (ADC12WINC)

//*****************************************************************************
//
// The following are values that can be passed to the memoryIndex parameter for
// functions: ADC12_B_getMemoryAddressForDMA(); the memoryBufferControlIndex
// parameter for functions: ADC12_B_memoryConfigure(); the memoryBufferIndex
// parameter for functions: ADC12_B_getResults().
//
//*****************************************************************************
#define ADC12_B_MEMORY_0                                                 (0x00)
#define ADC12_B_MEMORY_1                                                 (0x02)
#define ADC12_B_MEMORY_2                                                 (0x04)
#define ADC12_B_MEMORY_3                                                 (0x06)
#define ADC12_B_MEMORY_4                                                 (0x08)
#define ADC12_B_MEMORY_5                                                 (0x0A)
#define ADC12_B_MEMORY_6                                                 (0x0C)
#define ADC12_B_MEMORY_7                                                 (0x0E)
#define ADC12_B_MEMORY_8                                                 (0x10)
#define ADC12_B_MEMORY_9                                                 (0x12)
#define ADC12_B_MEMORY_10                                                (0x14)
#define ADC12_B_MEMORY_11                                                (0x16)
#define ADC12_B_MEMORY_12                                                (0x18)
#define ADC12_B_MEMORY_13                                                (0x1A)
#define ADC12_B_MEMORY_14                                                (0x1C)
#define ADC12_B_MEMORY_15                                                (0x1E)
#define ADC12_B_MEMORY_16                                                (0x20)
#define ADC12_B_MEMORY_17                                                (0x22)
#define ADC12_B_MEMORY_18                                                (0x24)
#define ADC12_B_MEMORY_19                                                (0x26)
#define ADC12_B_MEMORY_20                                                (0x28)
#define ADC12_B_MEMORY_21                                                (0x2A)
#define ADC12_B_MEMORY_22                                                (0x2C)
#define ADC12_B_MEMORY_23                                                (0x2E)
#define ADC12_B_MEMORY_24                                                (0x30)
#define ADC12_B_MEMORY_25                                                (0x32)
#define ADC12_B_MEMORY_26                                                (0x34)
#define ADC12_B_MEMORY_27                                                (0x36)
#define ADC12_B_MEMORY_28                                                (0x38)
#define ADC12_B_MEMORY_29                                                (0x3A)
#define ADC12_B_MEMORY_30                                                (0x3C)
#define ADC12_B_MEMORY_31                                                (0x3E)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask0 parameter
// for functions: ADC12_B_enableInterrupt(), and ADC12_B_disableInterrupt().
//
//*****************************************************************************
#define ADC12_B_IE0                                                  (ADC12IE0)
#define ADC12_B_IE1                                                  (ADC12IE1)
#define ADC12_B_IE2                                                  (ADC12IE2)
#define ADC12_B_IE3                                                  (ADC12IE3)
#define ADC12_B_IE4                                                  (ADC12IE4)
#define ADC12_B_IE5                                                  (ADC12IE5)
#define ADC12_B_IE6                                                  (ADC12IE6)
#define ADC12_B_IE7                                                  (ADC12IE7)
#define ADC12_B_IE8                                                  (ADC12IE8)
#define ADC12_B_IE9                                                  (ADC12IE9)
#define ADC12_B_IE10                                                (ADC12IE10)
#define ADC12_B_IE11                                                (ADC12IE11)
#define ADC12_B_IE12                                                (ADC12IE12)
#define ADC12_B_IE13                                                (ADC12IE13)
#define ADC12_B_IE14                                                (ADC12IE14)
#define ADC12_B_IE15                                                (ADC12IE15)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask1 parameter
// for functions: ADC12_B_enableInterrupt(), and ADC12_B_disableInterrupt().
//
//*****************************************************************************
#define ADC12_B_IE16                                                (ADC12IE16)
#define ADC12_B_IE17                                                (ADC12IE17)
#define ADC12_B_IE18                                                (ADC12IE18)
#define ADC12_B_IE19                                                (ADC12IE19)
#define ADC12_B_IE20                                                (ADC12IE20)
#define ADC12_B_IE21                                                (ADC12IE21)
#define ADC12_B_IE22                                                (ADC12IE22)
#define ADC12_B_IE23                                                (ADC12IE23)
#define ADC12_B_IE24                                                (ADC12IE24)
#define ADC12_B_IE25                                                (ADC12IE25)
#define ADC12_B_IE26                                                (ADC12IE26)
#define ADC12_B_IE27                                                (ADC12IE27)
#define ADC12_B_IE28                                                (ADC12IE28)
#define ADC12_B_IE29                                                (ADC12IE29)
#define ADC12_B_IE30                                                (ADC12IE30)
#define ADC12_B_IE31                                                (ADC12IE31)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask2 parameter
// for functions: ADC12_B_enableInterrupt(), and ADC12_B_disableInterrupt().
//
//*****************************************************************************
#define ADC12_B_INIE                                                (ADC12INIE)
#define ADC12_B_LOIE                                                (ADC12LOIE)
#define ADC12_B_HIIE                                                (ADC12HIIE)
#define ADC12_B_OVIE                                                (ADC12OVIE)
#define ADC12_B_TOVIE                                              (ADC12TOVIE)
#define ADC12_B_RDYIE                                              (ADC12RDYIE)

//*****************************************************************************
//
// The following are values that can be passed to the memoryInterruptFlagMask
// parameter for functions: ADC12_B_clearInterrupt(), and
// ADC12_B_getInterruptStatus().
//
//*****************************************************************************
#define ADC12_B_IFG0                                                (ADC12IFG0)
#define ADC12_B_IFG1                                                (ADC12IFG1)
#define ADC12_B_IFG2                                                (ADC12IFG2)
#define ADC12_B_IFG3                                                (ADC12IFG3)
#define ADC12_B_IFG4                                                (ADC12IFG4)
#define ADC12_B_IFG5                                                (ADC12IFG5)
#define ADC12_B_IFG6                                                (ADC12IFG6)
#define ADC12_B_IFG7                                                (ADC12IFG7)
#define ADC12_B_IFG8                                                (ADC12IFG8)
#define ADC12_B_IFG9                                                (ADC12IFG9)
#define ADC12_B_IFG10                                              (ADC12IFG10)
#define ADC12_B_IFG11                                              (ADC12IFG11)
#define ADC12_B_IFG12                                              (ADC12IFG12)
#define ADC12_B_IFG13                                              (ADC12IFG13)
#define ADC12_B_IFG14                                              (ADC12IFG14)
#define ADC12_B_IFG15                                              (ADC12IFG15)
#define ADC12_B_IFG16                                              (ADC12IFG16)
#define ADC12_B_IFG17                                              (ADC12IFG17)
#define ADC12_B_IFG18                                              (ADC12IFG18)
#define ADC12_B_IFG19                                              (ADC12IFG19)
#define ADC12_B_IFG20                                              (ADC12IFG20)
#define ADC12_B_IFG21                                              (ADC12IFG21)
#define ADC12_B_IFG22                                              (ADC12IFG22)
#define ADC12_B_IFG23                                              (ADC12IFG23)
#define ADC12_B_IFG24                                              (ADC12IFG24)
#define ADC12_B_IFG25                                              (ADC12IFG25)
#define ADC12_B_IFG26                                              (ADC12IFG26)
#define ADC12_B_IFG27                                              (ADC12IFG27)
#define ADC12_B_IFG28                                              (ADC12IFG28)
#define ADC12_B_IFG29                                              (ADC12IFG29)
#define ADC12_B_IFG30                                              (ADC12IFG30)
#define ADC12_B_IFG31                                              (ADC12IFG31)
#define ADC12_B_INIFG                                              (ADC12INIFG)
#define ADC12_B_LOIFG                                              (ADC12LOIFG)
#define ADC12_B_HIIFG                                              (ADC12HIIFG)
#define ADC12_B_OVIFG                                              (ADC12OVIFG)
#define ADC12_B_TOVIFG                                            (ADC12TOVIFG)
#define ADC12_B_RDYIFG                                            (ADC12RDYIFG)

//*****************************************************************************
//
// The following are values that can be passed to the startingMemoryBufferIndex
// parameter for functions: ADC12_B_startConversion().
//
//*****************************************************************************
#define ADC12_B_START_AT_ADC12MEM0                           (ADC12CSTARTADD_0)
#define ADC12_B_START_AT_ADC12MEM1                           (ADC12CSTARTADD_1)
#define ADC12_B_START_AT_ADC12MEM2                           (ADC12CSTARTADD_2)
#define ADC12_B_START_AT_ADC12MEM3                           (ADC12CSTARTADD_3)
#define ADC12_B_START_AT_ADC12MEM4                           (ADC12CSTARTADD_4)
#define ADC12_B_START_AT_ADC12MEM5                           (ADC12CSTARTADD_5)
#define ADC12_B_START_AT_ADC12MEM6                           (ADC12CSTARTADD_6)
#define ADC12_B_START_AT_ADC12MEM7                           (ADC12CSTARTADD_7)
#define ADC12_B_START_AT_ADC12MEM8                           (ADC12CSTARTADD_8)
#define ADC12_B_START_AT_ADC12MEM9                           (ADC12CSTARTADD_9)
#define ADC12_B_START_AT_ADC12MEM10                         (ADC12CSTARTADD_10)
#define ADC12_B_START_AT_ADC12MEM11                         (ADC12CSTARTADD_11)
#define ADC12_B_START_AT_ADC12MEM12                         (ADC12CSTARTADD_12)
#define ADC12_B_START_AT_ADC12MEM13                         (ADC12CSTARTADD_13)
#define ADC12_B_START_AT_ADC12MEM14                         (ADC12CSTARTADD_14)
#define ADC12_B_START_AT_ADC12MEM15                         (ADC12CSTARTADD_15)
#define ADC12_B_START_AT_ADC12MEM16                         (ADC12CSTARTADD_16)
#define ADC12_B_START_AT_ADC12MEM17                         (ADC12CSTARTADD_17)
#define ADC12_B_START_AT_ADC12MEM18                         (ADC12CSTARTADD_18)
#define ADC12_B_START_AT_ADC12MEM19                         (ADC12CSTARTADD_19)
#define ADC12_B_START_AT_ADC12MEM20                         (ADC12CSTARTADD_20)
#define ADC12_B_START_AT_ADC12MEM21                         (ADC12CSTARTADD_21)
#define ADC12_B_START_AT_ADC12MEM22                         (ADC12CSTARTADD_22)
#define ADC12_B_START_AT_ADC12MEM23                         (ADC12CSTARTADD_23)
#define ADC12_B_START_AT_ADC12MEM24                         (ADC12CSTARTADD_24)
#define ADC12_B_START_AT_ADC12MEM25                         (ADC12CSTARTADD_25)
#define ADC12_B_START_AT_ADC12MEM26                         (ADC12CSTARTADD_26)
#define ADC12_B_START_AT_ADC12MEM27                         (ADC12CSTARTADD_27)
#define ADC12_B_START_AT_ADC12MEM28                         (ADC12CSTARTADD_28)
#define ADC12_B_START_AT_ADC12MEM29                         (ADC12CSTARTADD_29)
#define ADC12_B_START_AT_ADC12MEM30                         (ADC12CSTARTADD_30)
#define ADC12_B_START_AT_ADC12MEM31                         (ADC12CSTARTADD_31)

//*****************************************************************************
//
// The following are values that can be passed to the
// conversionSequenceModeSelect parameter for functions:
// ADC12_B_startConversion().
//
//*****************************************************************************
#define ADC12_B_SINGLECHANNEL                                   (ADC12CONSEQ_0)
#define ADC12_B_SEQOFCHANNELS                                   (ADC12CONSEQ_1)
#define ADC12_B_REPEATED_SINGLECHANNEL                          (ADC12CONSEQ_2)
#define ADC12_B_REPEATED_SEQOFCHANNELS                          (ADC12CONSEQ_3)

//*****************************************************************************
//
// The following are values that can be passed to the preempt parameter for
// functions: ADC12_B_disableConversions().
//
//*****************************************************************************
#define ADC12_B_COMPLETECONVERSION                                        false
#define ADC12_B_PREEMPTCONVERSION                                          true

//*****************************************************************************
//
// The following are values that can be passed to the resolutionSelect
// parameter for functions: ADC12_B_setResolution().
//
//*****************************************************************************
#define ADC12_B_RESOLUTION_8BIT                                (ADC12RES__8BIT)
#define ADC12_B_RESOLUTION_10BIT                              (ADC12RES__10BIT)
#define ADC12_B_RESOLUTION_12BIT                              (ADC12RES__12BIT)

//*****************************************************************************
//
// The following are values that can be passed to the invertedSignal parameter
// for functions: ADC12_B_setSampleHoldSignalInversion().
//
//*****************************************************************************
#define ADC12_B_NONINVERTEDSIGNAL                                (!(ADC12ISSH))
#define ADC12_B_INVERTEDSIGNAL                                      (ADC12ISSH)

//*****************************************************************************
//
// The following are values that can be passed to the readBackFormat parameter
// for functions: ADC12_B_setDataReadBackFormat().
//
//*****************************************************************************
#define ADC12_B_UNSIGNED_BINARY                                    (!(ADC12DF))
#define ADC12_B_SIGNED_2SCOMPLEMENT                                   (ADC12DF)

//*****************************************************************************
//
// The following are values that can be passed to the powerMode parameter for
// functions: ADC12_B_setAdcPowerMode().
//
//*****************************************************************************
#define ADC12_B_REGULARPOWERMODE                                (!(ADC12PWRMD))
#define ADC12_B_LOWPOWERMODE                                       (ADC12PWRMD)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the ADC12_B_isBusy() function.
//
//*****************************************************************************
#define ADC12_B_NOTBUSY                                                    0x00
#define ADC12_B_BUSY                                                  ADC12BUSY

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool ADC12_B_init(uint32_t baseAddress,
                         uint16_t sampleHoldSignalSourceSelect,
                         uint8_t clockSourceSelect,
                         uint16_t clockSourceDivider,
                         uint16_t clockSourcePredivider,
                         uint16_t internalChannelMap);

extern void ADC12_B_enable(uint32_t baseAddress);

extern void ADC12_B_disable(uint32_t baseAddress);

extern void ADC12_B_setupSamplingTimer(uint32_t baseAddress,
                                       uint16_t clockCycleHoldCountLowMem,
                                       uint16_t clockCycleHoldCountHighMem,
                                       uint16_t multipleSamplesEnabled);

extern void ADC12_B_disableSamplingTimer(uint32_t baseAddress);

extern void ADC12_B_memoryConfigure(uint32_t baseAddress,
                                    uint8_t memoryBufferControlIndex,
                                    uint8_t inputSourceSelect,
                                    uint16_t refVoltageSourceSelect,
                                    uint16_t endOfSequence,
                                    uint16_t windowComparatorSelect,
                                    uint16_t differentialModeSelect);

extern void ADC12_B_setWindowCompAdvanced(uint32_t baseAddress,
                                          uint16_t highThreshold,
                                          uint16_t lowThreshold);

extern void ADC12_B_enableInterrupt(uint32_t baseAddress,
                                    uint16_t interruptMask0,
                                    uint16_t interruptMask1,
                                    uint16_t interruptMask2);

extern void ADC12_B_disableInterrupt(uint32_t baseAddress,
                                     uint16_t interruptMask0,
                                     uint16_t interruptMask1,
                                     uint16_t interruptMask2);

extern void ADC12_B_clearInterrupt(uint32_t baseAddress,
                                   uint8_t interruptRegisterChoice,
                                   uint16_t memoryInterruptFlagMask);

extern uint16_t ADC12_B_getInterruptStatus(uint32_t baseAddress,
                                           uint8_t interruptRegisterChoice,
                                           uint16_t memoryInterruptFlagMask);

extern void ADC12_B_startConversion(uint32_t baseAddress,
                                    uint16_t startingMemoryBufferIndex,
                                    uint8_t conversionSequenceModeSelect);

extern void ADC12_B_disableConversions(uint32_t baseAddress,
                                       bool preempt);

extern uint16_t ADC12_B_getResults(uint32_t baseAddress,
                                   uint8_t memoryBufferIndex);

extern void ADC12_B_setResolution(uint32_t baseAddress,
                                  uint8_t resolutionSelect);

extern void ADC12_B_setSampleHoldSignalInversion(uint32_t baseAddress,
                                                 uint16_t invertedSignal);

extern void ADC12_B_setDataReadBackFormat(uint32_t baseAddress,
                                          uint8_t readBackFormat);

extern void ADC12_B_setAdcPowerMode(uint32_t baseAddress,
                                    uint8_t powerMode);

extern uint32_t ADC12_B_getMemoryAddressForDMA(uint32_t baseAddress,
                                               uint8_t memoryIndex);

extern uint8_t ADC12_B_isBusy(uint32_t baseAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_ADC12_B_H__

#endif
