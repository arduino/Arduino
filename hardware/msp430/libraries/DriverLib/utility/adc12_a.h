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
// adc12_a.h - Driver for the ADC12_A Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_ADC12_A_H__
#define __MSP430WARE_ADC12_A_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_ADC12_PLUS__

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
// The following are values that can be passed to the clockSourceSelect
// parameter for functions: ADC12_A_init().
//
//*****************************************************************************
#define ADC12_A_CLOCKSOURCE_ADC12OSC                              (ADC12SSEL_0)
#define ADC12_A_CLOCKSOURCE_ACLK                                  (ADC12SSEL_1)
#define ADC12_A_CLOCKSOURCE_MCLK                                  (ADC12SSEL_2)
#define ADC12_A_CLOCKSOURCE_SMCLK                                 (ADC12SSEL_3)

//*****************************************************************************
//
// The following are values that can be passed to the clockSourceDivider
// parameter for functions: ADC12_A_init().
//
//*****************************************************************************
#define ADC12_A_CLOCKDIVIDER_1                                     (ADC12DIV_0)
#define ADC12_A_CLOCKDIVIDER_2                                     (ADC12DIV_1)
#define ADC12_A_CLOCKDIVIDER_3                                     (ADC12DIV_2)
#define ADC12_A_CLOCKDIVIDER_4                                     (ADC12DIV_3)
#define ADC12_A_CLOCKDIVIDER_5                                     (ADC12DIV_4)
#define ADC12_A_CLOCKDIVIDER_6                                     (ADC12DIV_5)
#define ADC12_A_CLOCKDIVIDER_7                                     (ADC12DIV_6)
#define ADC12_A_CLOCKDIVIDER_8                                     (ADC12DIV_7)
#define ADC12_A_CLOCKDIVIDER_12                        (ADC12DIV_2 + ADC12PDIV)
#define ADC12_A_CLOCKDIVIDER_16                        (ADC12DIV_3 + ADC12PDIV)
#define ADC12_A_CLOCKDIVIDER_20                        (ADC12DIV_4 + ADC12PDIV)
#define ADC12_A_CLOCKDIVIDER_24                        (ADC12DIV_5 + ADC12PDIV)
#define ADC12_A_CLOCKDIVIDER_28                        (ADC12DIV_6 + ADC12PDIV)
#define ADC12_A_CLOCKDIVIDER_32                        (ADC12DIV_7 + ADC12PDIV)

//*****************************************************************************
//
// The following are values that can be passed to the
// sampleHoldSignalSourceSelect parameter for functions: ADC12_A_init().
//
//*****************************************************************************
#define ADC12_A_SAMPLEHOLDSOURCE_SC                                (ADC12SHS_0)
#define ADC12_A_SAMPLEHOLDSOURCE_1                                 (ADC12SHS_1)
#define ADC12_A_SAMPLEHOLDSOURCE_2                                 (ADC12SHS_2)
#define ADC12_A_SAMPLEHOLDSOURCE_3                                 (ADC12SHS_3)

//*****************************************************************************
//
// The following are values that can be passed to the clockCycleHoldCountLowMem
// parameter for functions: ADC12_A_setupSamplingTimer(); the
// clockCycleHoldCountHighMem parameter for functions:
// ADC12_A_setupSamplingTimer().
//
//*****************************************************************************
#define ADC12_A_CYCLEHOLD_4_CYCLES                                (ADC12SHT0_0)
#define ADC12_A_CYCLEHOLD_8_CYCLES                                (ADC12SHT0_1)
#define ADC12_A_CYCLEHOLD_16_CYCLES                               (ADC12SHT0_2)
#define ADC12_A_CYCLEHOLD_32_CYCLES                               (ADC12SHT0_3)
#define ADC12_A_CYCLEHOLD_64_CYCLES                               (ADC12SHT0_4)
#define ADC12_A_CYCLEHOLD_96_CYCLES                               (ADC12SHT0_5)
#define ADC12_A_CYCLEHOLD_128_CYCLES                              (ADC12SHT0_6)
#define ADC12_A_CYCLEHOLD_192_CYCLES                              (ADC12SHT0_7)
#define ADC12_A_CYCLEHOLD_256_CYCLES                              (ADC12SHT0_8)
#define ADC12_A_CYCLEHOLD_384_CYCLES                              (ADC12SHT0_9)
#define ADC12_A_CYCLEHOLD_512_CYCLES                             (ADC12SHT0_10)
#define ADC12_A_CYCLEHOLD_768_CYCLES                             (ADC12SHT0_11)
#define ADC12_A_CYCLEHOLD_1024_CYCLES                            (ADC12SHT0_12)

//*****************************************************************************
//
// The following are values that can be passed to the multipleSamplesEnabled
// parameter for functions: ADC12_A_setupSamplingTimer().
//
//*****************************************************************************
#define ADC12_A_MULTIPLESAMPLESDISABLE                            (!(ADC12MSC))
#define ADC12_A_MULTIPLESAMPLESENABLE                                (ADC12MSC)

//*****************************************************************************
//
// The following are values that can be passed to the
// positiveRefVoltageSourceSelect parameter for functions:
// ADC12_A_memoryConfigure().
//
//*****************************************************************************
#define ADC12_A_VREFPOS_AVCC                       (!(ADC12SREF0 + ADC12SREF1))
#define ADC12_A_VREFPOS_EXT                                        (ADC12SREF1)
#define ADC12_A_VREFPOS_INT                                        (ADC12SREF0)

//*****************************************************************************
//
// The following are values that can be passed to the
// negativeRefVoltageSourceSelect parameter for functions:
// ADC12_A_memoryConfigure().
//
//*****************************************************************************
#define ADC12_A_VREFNEG_AVSS                                    (!(ADC12SREF2))
#define ADC12_A_VREFNEG_EXT                                        (ADC12SREF2)

//*****************************************************************************
//
// The following are values that can be passed to the endOfSequence parameter
// for functions: ADC12_A_memoryConfigure().
//
//*****************************************************************************
#define ADC12_A_NOTENDOFSEQUENCE                                  (!(ADC12EOS))
#define ADC12_A_ENDOFSEQUENCE                                        (ADC12EOS)

//*****************************************************************************
//
// The following are values that can be passed to the inputSourceSelect
// parameter for functions: ADC12_A_memoryConfigure().
//
//*****************************************************************************
#define ADC12_A_INPUT_A0                                          (ADC12INCH_0)
#define ADC12_A_INPUT_A1                                          (ADC12INCH_1)
#define ADC12_A_INPUT_A2                                          (ADC12INCH_2)
#define ADC12_A_INPUT_A3                                          (ADC12INCH_3)
#define ADC12_A_INPUT_A4                                          (ADC12INCH_4)
#define ADC12_A_INPUT_A5                                          (ADC12INCH_5)
#define ADC12_A_INPUT_A6                                          (ADC12INCH_6)
#define ADC12_A_INPUT_A7                                          (ADC12INCH_7)
#define ADC12_A_INPUT_A8                                          (ADC12INCH_8)
#define ADC12_A_INPUT_A9                                          (ADC12INCH_9)
#define ADC12_A_INPUT_TEMPSENSOR                                 (ADC12INCH_10)
#define ADC12_A_INPUT_BATTERYMONITOR                             (ADC12INCH_11)
#define ADC12_A_INPUT_A12                                        (ADC12INCH_12)
#define ADC12_A_INPUT_A13                                        (ADC12INCH_13)
#define ADC12_A_INPUT_A14                                        (ADC12INCH_14)
#define ADC12_A_INPUT_A15                                        (ADC12INCH_15)

//*****************************************************************************
//
// The following are values that can be passed to the startingMemoryBufferIndex
// parameter for functions: ADC12_A_startConversion(); the memoryIndex
// parameter for functions: ADC12_A_getMemoryAddressForDMA(); the
// memoryBufferControlIndex parameter for functions: ADC12_A_memoryConfigure();
// the memoryBufferIndex parameter for functions: ADC12_A_getResults().
//
//*****************************************************************************
#define ADC12_A_MEMORY_0                                                  (0x0)
#define ADC12_A_MEMORY_1                                                  (0x1)
#define ADC12_A_MEMORY_2                                                  (0x2)
#define ADC12_A_MEMORY_3                                                  (0x3)
#define ADC12_A_MEMORY_4                                                  (0x4)
#define ADC12_A_MEMORY_5                                                  (0x5)
#define ADC12_A_MEMORY_6                                                  (0x6)
#define ADC12_A_MEMORY_7                                                  (0x7)
#define ADC12_A_MEMORY_8                                                  (0x8)
#define ADC12_A_MEMORY_9                                                  (0x9)
#define ADC12_A_MEMORY_10                                                 (0xA)
#define ADC12_A_MEMORY_11                                                 (0xB)
#define ADC12_A_MEMORY_12                                                 (0xC)
#define ADC12_A_MEMORY_13                                                 (0xD)
#define ADC12_A_MEMORY_14                                                 (0xE)
#define ADC12_A_MEMORY_15                                                 (0xF)

//*****************************************************************************
//
// The following are values that can be passed to the memoryInterruptFlagMask
// parameter for functions: ADC12_A_clearInterrupt(), and
// ADC12_A_getInterruptStatus().
//
//*****************************************************************************
#define ADC12_A_IFG0                                                (ADC12IFG0)
#define ADC12_A_IFG1                                                (ADC12IFG1)
#define ADC12_A_IFG2                                                (ADC12IFG2)
#define ADC12_A_IFG3                                                (ADC12IFG3)
#define ADC12_A_IFG4                                                (ADC12IFG4)
#define ADC12_A_IFG5                                                (ADC12IFG5)
#define ADC12_A_IFG6                                                (ADC12IFG6)
#define ADC12_A_IFG7                                                (ADC12IFG7)
#define ADC12_A_IFG8                                                (ADC12IFG8)
#define ADC12_A_IFG9                                                (ADC12IFG9)
#define ADC12_A_IFG10                                              (ADC12IFG10)
#define ADC12_A_IFG11                                              (ADC12IFG11)
#define ADC12_A_IFG12                                              (ADC12IFG12)
#define ADC12_A_IFG13                                              (ADC12IFG13)
#define ADC12_A_IFG14                                              (ADC12IFG14)
#define ADC12_A_IFG15                                              (ADC12IFG15)

//*****************************************************************************
//
// The following are values that can be passed to the
// conversionSequenceModeSelect parameter for functions:
// ADC12_A_startConversion().
//
//*****************************************************************************
#define ADC12_A_SINGLECHANNEL                                   (ADC12CONSEQ_0)
#define ADC12_A_SEQOFCHANNELS                                   (ADC12CONSEQ_1)
#define ADC12_A_REPEATED_SINGLECHANNEL                          (ADC12CONSEQ_2)
#define ADC12_A_REPEATED_SEQOFCHANNELS                          (ADC12CONSEQ_3)

//*****************************************************************************
//
// The following are values that can be passed to the preempt parameter for
// functions: ADC12_A_disableConversions().
//
//*****************************************************************************
#define ADC12_A_COMPLETECONVERSION                                        false
#define ADC12_A_PREEMPTCONVERSION                                          true

//*****************************************************************************
//
// The following are values that can be passed to the resolutionSelect
// parameter for functions: ADC12_A_setResolution().
//
//*****************************************************************************
#define ADC12_A_RESOLUTION_8BIT                                    (ADC12RES_0)
#define ADC12_A_RESOLUTION_10BIT                                   (ADC12RES_1)
#define ADC12_A_RESOLUTION_12BIT                                   (ADC12RES_2)

//*****************************************************************************
//
// The following are values that can be passed to the invertedSignal parameter
// for functions: ADC12_A_setSampleHoldSignalInversion().
//
//*****************************************************************************
#define ADC12_A_NONINVERTEDSIGNAL                                (!(ADC12ISSH))
#define ADC12_A_INVERTEDSIGNAL                                      (ADC12ISSH)

//*****************************************************************************
//
// The following are values that can be passed to the readBackFormat parameter
// for functions: ADC12_A_setDataReadBackFormat().
//
//*****************************************************************************
#define ADC12_A_UNSIGNED_BINARY                                    (!(ADC12DF))
#define ADC12_A_SIGNED_2SCOMPLEMENT                                   (ADC12DF)

//*****************************************************************************
//
// The following are values that can be passed to the samplingRateSelect
// parameter for functions: ADC12_A_setReferenceBufferSamplingRate().
//
//*****************************************************************************
#define ADC12_A_MAXSAMPLINGRATE_200KSPS                            (!(ADC12SR))
#define ADC12_A_MAXSAMPLINGRATE_50KSPS                                (ADC12SR)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the ADC12_A_isBusy() function.
//
//*****************************************************************************
#define ADC12_A_NOTBUSY                                                    0x00
#define ADC12_A_BUSY                                                  ADC12BUSY

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask parameter
// for functions: ADC12_A_enableInterrupt(), and ADC12_A_disableInterrupt().
//
//*****************************************************************************
#define ADC12_A_IE0                                                  (ADC12IE0)
#define ADC12_A_IE1                                                  (ADC12IE1)
#define ADC12_A_IE2                                                  (ADC12IE2)
#define ADC12_A_IE3                                                  (ADC12IE3)
#define ADC12_A_IE4                                                  (ADC12IE4)
#define ADC12_A_IE5                                                  (ADC12IE5)
#define ADC12_A_IE6                                                  (ADC12IE6)
#define ADC12_A_IE7                                                  (ADC12IE7)
#define ADC12_A_IE8                                                  (ADC12IE8)
#define ADC12_A_IE9                                                  (ADC12IE9)
#define ADC12_A_IE10                                                (ADC12IE10)
#define ADC12_A_IE11                                                (ADC12IE11)
#define ADC12_A_IE12                                                (ADC12IE12)
#define ADC12_A_IE13                                                (ADC12IE13)
#define ADC12_A_IE14                                                (ADC12IE14)
#define ADC12_A_IE15                                                (ADC12IE15)
#define ADC12_A_OVERFLOW_IE                         ((uint32_t)ADC12OVIE << 16)
#define ADC12_A_CONVERSION_TIME_OVERFLOW_IE        ((uint32_t)ADC12TOVIE << 16)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool ADC12_A_init(uint32_t baseAddress,
                         uint16_t sampleHoldSignalSourceSelect,
                         uint8_t clockSourceSelect,
                         uint16_t clockSourceDivider);

extern void ADC12_A_enable(uint32_t baseAddress);

extern void ADC12_A_disable(uint32_t baseAddress);

extern void ADC12_A_setupSamplingTimer(uint32_t baseAddress,
                                       uint16_t clockCycleHoldCountLowMem,
                                       uint16_t clockCycleHoldCountHighMem,
                                       uint16_t multipleSamplesEnabled);

extern void ADC12_A_disableSamplingTimer(uint32_t baseAddress);

extern void ADC12_A_memoryConfigure(uint32_t baseAddress,
                                    uint8_t memoryBufferControlIndex,
                                    uint8_t inputSourceSelect,
                                    uint8_t positiveRefVoltageSourceSelect,
                                    uint8_t negativeRefVoltageSourceSelect,
                                    uint8_t endOfSequence);

extern void ADC12_A_enableInterrupt(uint32_t baseAddress,
                                    uint32_t interruptMask);

extern void ADC12_A_disableInterrupt(uint32_t baseAddress,
                                     uint32_t interruptMask);

extern void ADC12_A_clearInterrupt(uint32_t baseAddress,
                                   uint16_t memoryInterruptFlagMask);

extern uint8_t ADC12_A_getInterruptStatus(uint32_t baseAddress,
                                          uint16_t memoryInterruptFlagMask);

extern void ADC12_A_startConversion(uint32_t baseAddress,
                                    uint16_t startingMemoryBufferIndex,
                                    uint8_t conversionSequenceModeSelect);

extern void ADC12_A_disableConversions(uint32_t baseAddress,
                                       bool preempt);

extern uint16_t ADC12_A_getResults(uint32_t baseAddress,
                                   uint8_t memoryBufferIndex);

extern void ADC12_A_setResolution(uint32_t baseAddress,
                                  uint8_t resolutionSelect);

extern void ADC12_A_setSampleHoldSignalInversion(uint32_t baseAddress,
                                                 uint16_t invertedSignal);

extern void ADC12_A_setDataReadBackFormat(uint32_t baseAddress,
                                          uint8_t readBackFormat);

extern void ADC12_A_enableReferenceBurst(uint32_t baseAddress);

extern void ADC12_A_disableReferenceBurst(uint32_t baseAddress);

extern void ADC12_A_setReferenceBufferSamplingRate(uint32_t baseAddress,
                                                   uint8_t samplingRateSelect);

extern uint32_t ADC12_A_getMemoryAddressForDMA(uint32_t baseAddress,
                                               uint8_t memoryIndex);

extern uint16_t ADC12_A_isBusy(uint32_t baseAddress);

//*****************************************************************************
//
// The following values are deprecated values. Please refer to the documenation
// for the correct values to use.
//
//*****************************************************************************
#define ADC12TOVIE0                                         ADC12_A_OVERFLOW_IE
#define ADC12OVIE0                          ADC12_A_CONVERSION_TIME_OVERFLOW_IE

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_ADC12_A_H__

#endif
