//*****************************************************************************
//
// adc.h - ADC headers for using the ADC driver functions.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __ADC_H__
#define __ADC_H__

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
// Values that can be passed to ADCSequenceConfigure as the ulTrigger
// parameter.
//
//*****************************************************************************
#define ADC_TRIGGER_PROCESSOR   0x00000000  // Processor event
#define ADC_TRIGGER_COMP0       0x00000001  // Analog comparator 0 event
#define ADC_TRIGGER_COMP1       0x00000002  // Analog comparator 1 event
#define ADC_TRIGGER_COMP2       0x00000003  // Analog comparator 2 event
#define ADC_TRIGGER_EXTERNAL    0x00000004  // External event
#define ADC_TRIGGER_TIMER       0x00000005  // Timer event
#define ADC_TRIGGER_PWM0        0x00000006  // PWM0 event
#define ADC_TRIGGER_PWM1        0x00000007  // PWM1 event
#define ADC_TRIGGER_PWM2        0x00000008  // PWM2 event
#define ADC_TRIGGER_PWM3        0x00000009  // PWM3 event
#define ADC_TRIGGER_ALWAYS      0x0000000F  // Always event

//*****************************************************************************
//
// Values that can be passed to ADCSequenceStepConfigure as the ulConfig
// parameter.
//
//*****************************************************************************
#define ADC_CTL_TS              0x00000080  // Temperature sensor select
#define ADC_CTL_IE              0x00000040  // Interrupt enable
#define ADC_CTL_END             0x00000020  // Sequence end select
#define ADC_CTL_D               0x00000010  // Differential select
#define ADC_CTL_CH0             0x00000000  // Input channel 0
#define ADC_CTL_CH1             0x00000001  // Input channel 1
#define ADC_CTL_CH2             0x00000002  // Input channel 2
#define ADC_CTL_CH3             0x00000003  // Input channel 3
#define ADC_CTL_CH4             0x00000004  // Input channel 4
#define ADC_CTL_CH5             0x00000005  // Input channel 5
#define ADC_CTL_CH6             0x00000006  // Input channel 6
#define ADC_CTL_CH7             0x00000007  // Input channel 7
#define ADC_CTL_CH8             0x00000008  // Input channel 8
#define ADC_CTL_CH9             0x00000009  // Input channel 9
#define ADC_CTL_CH10            0x0000000A  // Input channel 10
#define ADC_CTL_CH11            0x0000000B  // Input channel 11
#define ADC_CTL_CH12            0x0000000C  // Input channel 12
#define ADC_CTL_CH13            0x0000000D  // Input channel 13
#define ADC_CTL_CH14            0x0000000E  // Input channel 14
#define ADC_CTL_CH15            0x0000000F  // Input channel 15
#define ADC_CTL_CH16            0x00000100  // Input channel 16
#define ADC_CTL_CH17            0x00000101  // Input channel 17
#define ADC_CTL_CH18            0x00000102  // Input channel 18
#define ADC_CTL_CH19            0x00000103  // Input channel 19
#define ADC_CTL_CH20            0x00000104  // Input channel 20
#define ADC_CTL_CH21            0x00000105  // Input channel 21
#define ADC_CTL_CH22            0x00000106  // Input channel 22
#define ADC_CTL_CH23            0x00000107  // Input channel 23
#define ADC_CTL_CMP0            0x00080000  // Select Comparator 0
#define ADC_CTL_CMP1            0x00090000  // Select Comparator 1
#define ADC_CTL_CMP2            0x000A0000  // Select Comparator 2
#define ADC_CTL_CMP3            0x000B0000  // Select Comparator 3
#define ADC_CTL_CMP4            0x000C0000  // Select Comparator 4
#define ADC_CTL_CMP5            0x000D0000  // Select Comparator 5
#define ADC_CTL_CMP6            0x000E0000  // Select Comparator 6
#define ADC_CTL_CMP7            0x000F0000  // Select Comparator 7

//*****************************************************************************
//
// Values that can be passed to ADCComparatorConfigure as part of the
// ulConfig parameter.
//
//*****************************************************************************
#define ADC_COMP_TRIG_NONE      0x00000000  // Trigger Disabled
#define ADC_COMP_TRIG_LOW_ALWAYS \
                                0x00001000  // Trigger Low Always
#define ADC_COMP_TRIG_LOW_ONCE  0x00001100  // Trigger Low Once
#define ADC_COMP_TRIG_LOW_HALWAYS \
                                0x00001200  // Trigger Low Always (Hysteresis)
#define ADC_COMP_TRIG_LOW_HONCE 0x00001300  // Trigger Low Once (Hysteresis)
#define ADC_COMP_TRIG_MID_ALWAYS \
                                0x00001400  // Trigger Mid Always
#define ADC_COMP_TRIG_MID_ONCE  0x00001500  // Trigger Mid Once
#define ADC_COMP_TRIG_HIGH_ALWAYS \
                                0x00001C00  // Trigger High Always
#define ADC_COMP_TRIG_HIGH_ONCE 0x00001D00  // Trigger High Once
#define ADC_COMP_TRIG_HIGH_HALWAYS \
                                0x00001E00  // Trigger High Always (Hysteresis)
#define ADC_COMP_TRIG_HIGH_HONCE \
                                0x00001F00  // Trigger High Once (Hysteresis)

#define ADC_COMP_INT_NONE       0x00000000  // Interrupt Disabled
#define ADC_COMP_INT_LOW_ALWAYS \
                                0x00000010  // Interrupt Low Always
#define ADC_COMP_INT_LOW_ONCE   0x00000011  // Interrupt Low Once
#define ADC_COMP_INT_LOW_HALWAYS \
                                0x00000012  // Interrupt Low Always
                                            // (Hysteresis)
#define ADC_COMP_INT_LOW_HONCE  0x00000013  // Interrupt Low Once (Hysteresis)
#define ADC_COMP_INT_MID_ALWAYS \
                                0x00000014  // Interrupt Mid Always
#define ADC_COMP_INT_MID_ONCE   0x00000015  // Interrupt Mid Once
#define ADC_COMP_INT_HIGH_ALWAYS \
                                0x0000001C  // Interrupt High Always
#define ADC_COMP_INT_HIGH_ONCE  0x0000001D  // Interrupt High Once
#define ADC_COMP_INT_HIGH_HALWAYS \
                                0x0000001E  // Interrupt High Always
                                            // (Hysteresis)
#define ADC_COMP_INT_HIGH_HONCE \
                                0x0000001F  // Interrupt High Once (Hysteresis)

//*****************************************************************************
//
// Values that can be used to modify the sequence number passed to
// ADCProcessorTrigger in order to get cross-module synchronous processor
// triggers.
//
//*****************************************************************************
#define ADC_TRIGGER_WAIT        0x08000000  // Wait for the synchronous trigger
#define ADC_TRIGGER_SIGNAL      0x80000000  // Signal the synchronous trigger

//*****************************************************************************
//
// Values that can be passed to ADCPhaseDelaySet as the ulPhase parameter and
// returned from ADCPhaseDelayGet.
//
//*****************************************************************************
#define ADC_PHASE_0             0x00000000  // 0 degrees
#define ADC_PHASE_22_5          0x00000001  // 22.5 degrees
#define ADC_PHASE_45            0x00000002  // 45 degrees
#define ADC_PHASE_67_5          0x00000003  // 67.5 degrees
#define ADC_PHASE_90            0x00000004  // 90 degrees
#define ADC_PHASE_112_5         0x00000005  // 112.5 degrees
#define ADC_PHASE_135           0x00000006  // 135 degrees
#define ADC_PHASE_157_5         0x00000007  // 157.5 degrees
#define ADC_PHASE_180           0x00000008  // 180 degrees
#define ADC_PHASE_202_5         0x00000009  // 202.5 degrees
#define ADC_PHASE_225           0x0000000A  // 225 degrees
#define ADC_PHASE_247_5         0x0000000B  // 247.5 degrees
#define ADC_PHASE_270           0x0000000C  // 270 degrees
#define ADC_PHASE_292_5         0x0000000D  // 292.5 degrees
#define ADC_PHASE_315           0x0000000E  // 315 degrees
#define ADC_PHASE_337_5         0x0000000F  // 337.5 degrees

//*****************************************************************************
//
// Values that can be passed to ADCReferenceSet as the ulRef parameter.
//
//*****************************************************************************
#define ADC_REF_INT             0x00000000  // Internal reference
#define ADC_REF_EXT_3V          0x00000001  // External 3V reference
#define ADC_REF_EXT_1V          0x00000003  // External 1V reference

//*****************************************************************************
//
// Values that can be passed to ADCResolutionSet as the ulResolution parameter.
//
//*****************************************************************************
#define ADC_RES_10BIT           0x00000000  // 10-bit resolution
#define ADC_RES_12BIT           0x00000010  // 12-bit resolution

//*****************************************************************************
//
// Values that can be passed to ADCIntDisableEx(), ADCIntEnableEx(),
// ADCIntClearEx() and ADCIntStatusEx().
//
//*****************************************************************************
#define ADC_INT_SS0             0x00000001
#define ADC_INT_SS1             0x00000002
#define ADC_INT_SS2             0x00000004
#define ADC_INT_SS3             0x00000008
#define ADC_INT_DMA_SS0         0x00000100
#define ADC_INT_DMA_SS1         0x00000200
#define ADC_INT_DMA_SS2         0x00000400
#define ADC_INT_DMA_SS3         0x00000800
#define ADC_INT_DCON_SS0        0x00010000
#define ADC_INT_DCON_SS1        0x00020000
#define ADC_INT_DCON_SS2        0x00040000
#define ADC_INT_DCON_SS3        0x00080000

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void ADCIntRegister(unsigned long ulBase, unsigned long ulSequenceNum,
                           void (*pfnHandler)(void));
extern void ADCIntUnregister(unsigned long ulBase,
                             unsigned long ulSequenceNum);
extern void ADCIntDisable(unsigned long ulBase, unsigned long ulSequenceNum);
extern void ADCIntEnable(unsigned long ulBase, unsigned long ulSequenceNum);
extern unsigned long ADCIntStatus(unsigned long ulBase,
                                  unsigned long ulSequenceNum,
                                  tBoolean bMasked);
extern void ADCIntClear(unsigned long ulBase, unsigned long ulSequenceNum);
extern void ADCSequenceEnable(unsigned long ulBase,
                              unsigned long ulSequenceNum);
extern void ADCSequenceDisable(unsigned long ulBase,
                               unsigned long ulSequenceNum);
extern void ADCSequenceConfigure(unsigned long ulBase,
                                 unsigned long ulSequenceNum,
                                 unsigned long ulTrigger,
                                 unsigned long ulPriority);
extern void ADCSequenceStepConfigure(unsigned long ulBase,
                                     unsigned long ulSequenceNum,
                                     unsigned long ulStep,
                                     unsigned long ulConfig);
extern long ADCSequenceOverflow(unsigned long ulBase,
                                unsigned long ulSequenceNum);
extern void ADCSequenceOverflowClear(unsigned long ulBase,
                                     unsigned long ulSequenceNum);
extern long ADCSequenceUnderflow(unsigned long ulBase,
                                 unsigned long ulSequenceNum);
extern void ADCSequenceUnderflowClear(unsigned long ulBase,
                                      unsigned long ulSequenceNum);
extern long ADCSequenceDataGet(unsigned long ulBase,
                               unsigned long ulSequenceNum,
                               unsigned long *pulBuffer);
extern void ADCProcessorTrigger(unsigned long ulBase,
                                unsigned long ulSequenceNum);
extern void ADCSoftwareOversampleConfigure(unsigned long ulBase,
                                           unsigned long ulSequenceNum,
                                           unsigned long ulFactor);
extern void ADCSoftwareOversampleStepConfigure(unsigned long ulBase,
                                               unsigned long ulSequenceNum,
                                               unsigned long ulStep,
                                               unsigned long ulConfig);
extern void ADCSoftwareOversampleDataGet(unsigned long ulBase,
                                         unsigned long ulSequenceNum,
                                         unsigned long *pulBuffer,
                                         unsigned long ulCount);
extern void ADCHardwareOversampleConfigure(unsigned long ulBase,
                                           unsigned long ulFactor);
extern void ADCComparatorConfigure(unsigned long ulBase, unsigned long ulComp,
                                   unsigned long ulConfig);
extern void ADCComparatorRegionSet(unsigned long ulBase, unsigned long ulComp,
                                   unsigned long ulLowRef,
                                   unsigned long ulHighRef);
extern void ADCComparatorReset(unsigned long ulBase, unsigned long ulComp,
                               tBoolean bTrigger, tBoolean bInterrupt);
extern void ADCComparatorIntDisable(unsigned long ulBase,
                                    unsigned long ulSequenceNum);
extern void ADCComparatorIntEnable(unsigned long ulBase,
                                   unsigned long ulSequenceNum);
extern unsigned long ADCComparatorIntStatus(unsigned long ulBase);
extern void ADCComparatorIntClear(unsigned long ulBase,
                                  unsigned long ulStatus);
extern void ADCReferenceSet(unsigned long ulBase, unsigned long ulRef);
extern unsigned long ADCReferenceGet(unsigned long ulBase);
extern void ADCResolutionSet(unsigned long ulBase, unsigned long ulResolution);
extern unsigned long ADCResolutionGet(unsigned long ulBase);
extern void ADCPhaseDelaySet(unsigned long ulBase, unsigned long ulPhase);
extern unsigned long ADCPhaseDelayGet(unsigned long ulBase);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __ADC_H__
