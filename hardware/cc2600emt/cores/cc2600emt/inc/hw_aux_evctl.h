/******************************************************************************
*  Filename:       hw_aux_evctl_h
*  Revised:        2015-11-12 13:07:02 +0100 (Thu, 12 Nov 2015)
*  Revision:       45056
*
* Copyright (c) 2015, Texas Instruments Incorporated
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1) Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2) Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3) Neither the name of the ORGANIZATION nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_AUX_EVCTL_H__
#define __HW_AUX_EVCTL_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AUX_EVCTL component
//
//*****************************************************************************
// Vector Configuration 0
#define AUX_EVCTL_O_VECCFG0                                         0x00000000

// Vector Configuration 1
#define AUX_EVCTL_O_VECCFG1                                         0x00000004

// Sensor Controller Engine Wait Event Selection
#define AUX_EVCTL_O_SCEWEVSEL                                       0x00000008

// Events To AON Domain Flags
#define AUX_EVCTL_O_EVTOAONFLAGS                                    0x0000000C

// Events To AON Domain Polarity
#define AUX_EVCTL_O_EVTOAONPOL                                      0x00000010

// Direct Memory Access Control
#define AUX_EVCTL_O_DMACTL                                          0x00000014

// Software Event Set
#define AUX_EVCTL_O_SWEVSET                                         0x00000018

// Event Status 0
#define AUX_EVCTL_O_EVSTAT0                                         0x0000001C

// Event Status 1
#define AUX_EVCTL_O_EVSTAT1                                         0x00000020

// Event To MCU Domain Polarity
#define AUX_EVCTL_O_EVTOMCUPOL                                      0x00000024

// Events to MCU Domain Flags
#define AUX_EVCTL_O_EVTOMCUFLAGS                                    0x00000028

// Combined Event To MCU Domain Mask
#define AUX_EVCTL_O_COMBEVTOMCUMASK                                 0x0000002C

// Vector Flags
#define AUX_EVCTL_O_VECFLAGS                                        0x00000034

// Events To MCU Domain Flags Clear
#define AUX_EVCTL_O_EVTOMCUFLAGSCLR                                 0x00000038

// Events To AON Domain Clear
#define AUX_EVCTL_O_EVTOAONFLAGSCLR                                 0x0000003C

// Vector Flags Clear
#define AUX_EVCTL_O_VECFLAGSCLR                                     0x00000040

//*****************************************************************************
//
// Register: AUX_EVCTL_O_VECCFG0
//
//*****************************************************************************
// Field:    [14] VEC1_POL
//
// Selects vector 1 trigger event polarity.
//
// To manually trigger vector 1 execution, set VEC1_EV to a known static value,
// and toggle VEC1_POL twice.
// ENUMs:
// FALL                     Falling edge triggers execution.
// RISE                     Rising edge triggers execution.
#define AUX_EVCTL_VECCFG0_VEC1_POL                                  0x00004000
#define AUX_EVCTL_VECCFG0_VEC1_POL_BITN                                     14
#define AUX_EVCTL_VECCFG0_VEC1_POL_M                                0x00004000
#define AUX_EVCTL_VECCFG0_VEC1_POL_S                                        14
#define AUX_EVCTL_VECCFG0_VEC1_POL_FALL                             0x00004000
#define AUX_EVCTL_VECCFG0_VEC1_POL_RISE                             0x00000000

// Field:    [13] VEC1_EN
//
// Enables (1) or disables (0) triggering of vector 1 execution.
//
// When enabled, the edge selected by VEC1_POL on the event selected by VEC1_EV
// will set VECFLAGS.VEC1, which in turn triggers vector 1 execution.
//
// Note: Lower vectors (0) have priority.
// ENUMs:
// EN                       An event selected by VEC1_EV with polarity from
//                          VEC1_POL triggers a jump to vector # 1 when
//                          AUX_SCE is in sleep
// DIS                      Event detection is disabled
#define AUX_EVCTL_VECCFG0_VEC1_EN                                   0x00002000
#define AUX_EVCTL_VECCFG0_VEC1_EN_BITN                                      13
#define AUX_EVCTL_VECCFG0_VEC1_EN_M                                 0x00002000
#define AUX_EVCTL_VECCFG0_VEC1_EN_S                                         13
#define AUX_EVCTL_VECCFG0_VEC1_EN_EN                                0x00002000
#define AUX_EVCTL_VECCFG0_VEC1_EN_DIS                               0x00000000

// Field:  [12:8] VEC1_EV
//
// Selects vector 1 trigger source event.
// ENUMs:
// ADC_IRQ                  ADC_IRQ event
// MCU_EV                   MCU_EV event
// ACLK_REF                 ACLK_REF event
// AUXIO15                  AUXIO15 input data
// AUXIO14                  AUXIO14 input data
// AUXIO13                  AUXIO13 input data
// AUXIO12                  AUXIO12 input data
// AUXIO11                  AUXIO11 input data
// AUXIO10                  AUXIO10 input data
// AUXIO9                   AUXIO9 input data
// AUXIO8                   AUXIO8 input data
// AUXIO7                   AUXIO7 input data
// AUXIO6                   AUXIO6 input data
// AUXIO5                   AUXIO5 input data
// AUXIO4                   AUXIO4 input data
// AUXIO3                   AUXIO3 input data
// AUXIO2                   AUXIO2 input data
// AUXIO1                   AUXIO1 input data
// AUXIO0                   AUXIO0 input data
// AON_PROG_WU              AON_PROG_WU event
// AON_SW                   AON_SW event
// OBSMUX1                  OBSMUX1 event
// OBSMUX0                  OBSMUX0 event
// ADC_FIFO_ALMOST_FULL     ADC_FIFO_ALMOST_FULL event
// ADC_DONE                 ADC_DONE event
// SMPH_AUTOTAKE_DONE       SMPH_AUTOTAKE_DONE event
// TIMER1_EV                TIMER1_EV event
// TIMER0_EV                TIMER0_EV event
// TDC_DONE                 TDC_DONE event
// AUX_COMPB                AUX_COMPB event
// AUX_COMPA                AUX_COMPA event
// AON_RTC_CH2              AON_RTC_CH2 event
#define AUX_EVCTL_VECCFG0_VEC1_EV_W                                          5
#define AUX_EVCTL_VECCFG0_VEC1_EV_M                                 0x00001F00
#define AUX_EVCTL_VECCFG0_VEC1_EV_S                                          8
#define AUX_EVCTL_VECCFG0_VEC1_EV_ADC_IRQ                           0x00001F00
#define AUX_EVCTL_VECCFG0_VEC1_EV_MCU_EV                            0x00001E00
#define AUX_EVCTL_VECCFG0_VEC1_EV_ACLK_REF                          0x00001D00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO15                           0x00001C00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO14                           0x00001B00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO13                           0x00001A00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO12                           0x00001900
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO11                           0x00001800
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO10                           0x00001700
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO9                            0x00001600
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO8                            0x00001500
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO7                            0x00001400
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO6                            0x00001300
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO5                            0x00001200
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO4                            0x00001100
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO3                            0x00001000
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO2                            0x00000F00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO1                            0x00000E00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUXIO0                            0x00000D00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AON_PROG_WU                       0x00000C00
#define AUX_EVCTL_VECCFG0_VEC1_EV_AON_SW                            0x00000B00
#define AUX_EVCTL_VECCFG0_VEC1_EV_OBSMUX1                           0x00000A00
#define AUX_EVCTL_VECCFG0_VEC1_EV_OBSMUX0                           0x00000900
#define AUX_EVCTL_VECCFG0_VEC1_EV_ADC_FIFO_ALMOST_FULL              0x00000800
#define AUX_EVCTL_VECCFG0_VEC1_EV_ADC_DONE                          0x00000700
#define AUX_EVCTL_VECCFG0_VEC1_EV_SMPH_AUTOTAKE_DONE                0x00000600
#define AUX_EVCTL_VECCFG0_VEC1_EV_TIMER1_EV                         0x00000500
#define AUX_EVCTL_VECCFG0_VEC1_EV_TIMER0_EV                         0x00000400
#define AUX_EVCTL_VECCFG0_VEC1_EV_TDC_DONE                          0x00000300
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUX_COMPB                         0x00000200
#define AUX_EVCTL_VECCFG0_VEC1_EV_AUX_COMPA                         0x00000100
#define AUX_EVCTL_VECCFG0_VEC1_EV_AON_RTC_CH2                       0x00000000

// Field:     [6] VEC0_POL
//
// Selects vector 0 trigger event polarity.
//
// To manually trigger vector 0 execution, set VEC0_EV to a known static value,
// and toggle VEC0_POL twice.
// ENUMs:
// FALL                     Falling edge triggers execution.
// RISE                     Rising edge triggers execution.
#define AUX_EVCTL_VECCFG0_VEC0_POL                                  0x00000040
#define AUX_EVCTL_VECCFG0_VEC0_POL_BITN                                      6
#define AUX_EVCTL_VECCFG0_VEC0_POL_M                                0x00000040
#define AUX_EVCTL_VECCFG0_VEC0_POL_S                                         6
#define AUX_EVCTL_VECCFG0_VEC0_POL_FALL                             0x00000040
#define AUX_EVCTL_VECCFG0_VEC0_POL_RISE                             0x00000000

// Field:     [5] VEC0_EN
//
// Enables (1) or disables (0) triggering of vector 0 execution.
//
// When enabled, the edge selected by VEC0_POL on the event selected by VEC0_EV
// will set VECFLAGS.VEC0, which in turn triggers vector 0 execution.
// ENUMs:
// EN                       An event selected by VEC0_EV with polarity from
//                          VEC0_POL triggers a jump to vector #0 when
//                          AUX_SCE is in sleep
// DIS                      Event detection is disabled
#define AUX_EVCTL_VECCFG0_VEC0_EN                                   0x00000020
#define AUX_EVCTL_VECCFG0_VEC0_EN_BITN                                       5
#define AUX_EVCTL_VECCFG0_VEC0_EN_M                                 0x00000020
#define AUX_EVCTL_VECCFG0_VEC0_EN_S                                          5
#define AUX_EVCTL_VECCFG0_VEC0_EN_EN                                0x00000020
#define AUX_EVCTL_VECCFG0_VEC0_EN_DIS                               0x00000000

// Field:   [4:0] VEC0_EV
//
// Selects vector 0 trigger source event.
// ENUMs:
// ADC_IRQ                  ADC_IRQ event
// MCU_EV                   MCU_EV event
// ACLK_REF                 ACLK_REF event
// AUXIO15                  AUXIO15 input data
// AUXIO14                  AUXIO14 input data
// AUXIO13                  AUXIO13 input data
// AUXIO12                  AUXIO12 input data
// AUXIO11                  AUXIO11 input data
// AUXIO10                  AUXIO10 input data
// AUXIO9                   AUXIO9 input data
// AUXIO8                   AUXIO8 input data
// AUXIO7                   AUXIO7 input data
// AUXIO6                   AUXIO6 input data
// AUXIO5                   AUXIO5 input data
// AUXIO4                   AUXIO4 input data
// AUXIO3                   AUXIO3 input data
// AUXIO2                   AUXIO2 input data
// AUXIO1                   AUXIO1 input data
// AUXIO0                   AUXIO0 input data
// AON_PROG_WU              AON_PROG_WU event
// AON_SW                   AON_SW event
// OBSMUX1                  OBSMUX1 event
// OBSMUX0                  OBSMUX0 event
// ADC_FIFO_ALMOST_FULL     ADC_FIFO_ALMOST_FULL event
// ADC_DONE                 ADC_DONE event
// SMPH_AUTOTAKE_DONE       SMPH_AUTOTAKE_DONE event
// TIMER1_EV                TIMER1_EV event
// TIMER0_EV                TIMER0_EV event
// TDC_DONE                 TDC_DONE event
// AUX_COMPB                AUX_COMPB event
// AUX_COMPA                AUX_COMPA event
// AON_RTC_CH2              AON_RTC_CH2 event
#define AUX_EVCTL_VECCFG0_VEC0_EV_W                                          5
#define AUX_EVCTL_VECCFG0_VEC0_EV_M                                 0x0000001F
#define AUX_EVCTL_VECCFG0_VEC0_EV_S                                          0
#define AUX_EVCTL_VECCFG0_VEC0_EV_ADC_IRQ                           0x0000001F
#define AUX_EVCTL_VECCFG0_VEC0_EV_MCU_EV                            0x0000001E
#define AUX_EVCTL_VECCFG0_VEC0_EV_ACLK_REF                          0x0000001D
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO15                           0x0000001C
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO14                           0x0000001B
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO13                           0x0000001A
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO12                           0x00000019
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO11                           0x00000018
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO10                           0x00000017
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO9                            0x00000016
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO8                            0x00000015
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO7                            0x00000014
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO6                            0x00000013
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO5                            0x00000012
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO4                            0x00000011
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO3                            0x00000010
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO2                            0x0000000F
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO1                            0x0000000E
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUXIO0                            0x0000000D
#define AUX_EVCTL_VECCFG0_VEC0_EV_AON_PROG_WU                       0x0000000C
#define AUX_EVCTL_VECCFG0_VEC0_EV_AON_SW                            0x0000000B
#define AUX_EVCTL_VECCFG0_VEC0_EV_OBSMUX1                           0x0000000A
#define AUX_EVCTL_VECCFG0_VEC0_EV_OBSMUX0                           0x00000009
#define AUX_EVCTL_VECCFG0_VEC0_EV_ADC_FIFO_ALMOST_FULL              0x00000008
#define AUX_EVCTL_VECCFG0_VEC0_EV_ADC_DONE                          0x00000007
#define AUX_EVCTL_VECCFG0_VEC0_EV_SMPH_AUTOTAKE_DONE                0x00000006
#define AUX_EVCTL_VECCFG0_VEC0_EV_TIMER1_EV                         0x00000005
#define AUX_EVCTL_VECCFG0_VEC0_EV_TIMER0_EV                         0x00000004
#define AUX_EVCTL_VECCFG0_VEC0_EV_TDC_DONE                          0x00000003
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUX_COMPB                         0x00000002
#define AUX_EVCTL_VECCFG0_VEC0_EV_AUX_COMPA                         0x00000001
#define AUX_EVCTL_VECCFG0_VEC0_EV_AON_RTC_CH2                       0x00000000

//*****************************************************************************
//
// Register: AUX_EVCTL_O_VECCFG1
//
//*****************************************************************************
// Field:    [14] VEC3_POL
//
// Selects vector 3 trigger event polarity.
//
// To manually trigger vector 3 execution, set VEC3_EV to a known static value,
// and toggle VEC3_POL twice.
// ENUMs:
// FALL                     Falling edge triggers execution.
// RISE                     Rising edge triggers execution.
#define AUX_EVCTL_VECCFG1_VEC3_POL                                  0x00004000
#define AUX_EVCTL_VECCFG1_VEC3_POL_BITN                                     14
#define AUX_EVCTL_VECCFG1_VEC3_POL_M                                0x00004000
#define AUX_EVCTL_VECCFG1_VEC3_POL_S                                        14
#define AUX_EVCTL_VECCFG1_VEC3_POL_FALL                             0x00004000
#define AUX_EVCTL_VECCFG1_VEC3_POL_RISE                             0x00000000

// Field:    [13] VEC3_EN
//
// Enables (1) or disables (0) triggering of vector 3 execution.
//
// When enabled, the edge selected by VEC3_POL on the event selected by VEC3_EV
// will set VECFLAGS.VEC3, which in turn triggers vector 3 execution.
//
// Note: Lower vectors (0, 1 and 2) have priority.
// ENUMs:
// EN                       An event selected by VEC3_EV with polarity from
//                          VEC3_POL triggers a jump to vector # 3 when
//                          AUX_SCE is in sleep
// DIS                      Event detection is disabled
#define AUX_EVCTL_VECCFG1_VEC3_EN                                   0x00002000
#define AUX_EVCTL_VECCFG1_VEC3_EN_BITN                                      13
#define AUX_EVCTL_VECCFG1_VEC3_EN_M                                 0x00002000
#define AUX_EVCTL_VECCFG1_VEC3_EN_S                                         13
#define AUX_EVCTL_VECCFG1_VEC3_EN_EN                                0x00002000
#define AUX_EVCTL_VECCFG1_VEC3_EN_DIS                               0x00000000

// Field:  [12:8] VEC3_EV
//
// Selects vector 3 trigger source event.
// ENUMs:
// ADC_IRQ                  ADC_IRQ event
// MCU_EV                   MCU_EV event
// ACLK_REF                 ACLK_REF event
// AUXIO15                  AUXIO15 input data
// AUXIO14                  AUXIO14 input data
// AUXIO13                  AUXIO13 input data
// AUXIO12                  AUXIO12 input data
// AUXIO11                  AUXIO11 input data
// AUXIO10                  AUXIO10 input data
// AUXIO9                   AUXIO9 input data
// AUXIO8                   AUXIO8 input data
// AUXIO7                   AUXIO7 input data
// AUXIO6                   AUXIO6 input data
// AUXIO5                   AUXIO5 input data
// AUXIO4                   AUXIO4 input data
// AUXIO3                   AUXIO3 input data
// AUXIO2                   AUXIO2 input data
// AUXIO1                   AUXIO1 input data
// AUXIO0                   AUXIO0 input data
// AON_PROG_WU              AON_PROG_WU event
// AON_SW                   AON_SW event
// OBSMUX1                  OBSMUX1 event
// OBSMUX0                  OBSMUX0 event
// ADC_FIFO_ALMOST_FULL     ADC_FIFO_ALMOST_FULL event
// ADC_DONE                 ADC_DONE event
// SMPH_AUTOTAKE_DONE       SMPH_AUTOTAKE_DONE event
// TIMER1_EV                TIMER1_EV event
// TIMER0_EV                TIMER0_EV event
// TDC_DONE                 TDC_DONE event
// AUX_COMPB                AUX_COMPB event
// AUX_COMPA                AUX_COMPA event
// AON_RTC_CH2              AON_RTC_CH2 event
#define AUX_EVCTL_VECCFG1_VEC3_EV_W                                          5
#define AUX_EVCTL_VECCFG1_VEC3_EV_M                                 0x00001F00
#define AUX_EVCTL_VECCFG1_VEC3_EV_S                                          8
#define AUX_EVCTL_VECCFG1_VEC3_EV_ADC_IRQ                           0x00001F00
#define AUX_EVCTL_VECCFG1_VEC3_EV_MCU_EV                            0x00001E00
#define AUX_EVCTL_VECCFG1_VEC3_EV_ACLK_REF                          0x00001D00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO15                           0x00001C00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO14                           0x00001B00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO13                           0x00001A00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO12                           0x00001900
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO11                           0x00001800
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO10                           0x00001700
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO9                            0x00001600
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO8                            0x00001500
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO7                            0x00001400
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO6                            0x00001300
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO5                            0x00001200
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO4                            0x00001100
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO3                            0x00001000
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO2                            0x00000F00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO1                            0x00000E00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUXIO0                            0x00000D00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AON_PROG_WU                       0x00000C00
#define AUX_EVCTL_VECCFG1_VEC3_EV_AON_SW                            0x00000B00
#define AUX_EVCTL_VECCFG1_VEC3_EV_OBSMUX1                           0x00000A00
#define AUX_EVCTL_VECCFG1_VEC3_EV_OBSMUX0                           0x00000900
#define AUX_EVCTL_VECCFG1_VEC3_EV_ADC_FIFO_ALMOST_FULL              0x00000800
#define AUX_EVCTL_VECCFG1_VEC3_EV_ADC_DONE                          0x00000700
#define AUX_EVCTL_VECCFG1_VEC3_EV_SMPH_AUTOTAKE_DONE                0x00000600
#define AUX_EVCTL_VECCFG1_VEC3_EV_TIMER1_EV                         0x00000500
#define AUX_EVCTL_VECCFG1_VEC3_EV_TIMER0_EV                         0x00000400
#define AUX_EVCTL_VECCFG1_VEC3_EV_TDC_DONE                          0x00000300
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUX_COMPB                         0x00000200
#define AUX_EVCTL_VECCFG1_VEC3_EV_AUX_COMPA                         0x00000100
#define AUX_EVCTL_VECCFG1_VEC3_EV_AON_RTC_CH2                       0x00000000

// Field:     [6] VEC2_POL
//
// Selects vector 2 trigger event polarity.
//
// To manually trigger vector 2 execution, set VEC2_EV to a known static value,
// and toggle VEC2_POL twice.
// ENUMs:
// FALL                     Falling edge triggers execution.
// RISE                     Rising edge triggers execution.
#define AUX_EVCTL_VECCFG1_VEC2_POL                                  0x00000040
#define AUX_EVCTL_VECCFG1_VEC2_POL_BITN                                      6
#define AUX_EVCTL_VECCFG1_VEC2_POL_M                                0x00000040
#define AUX_EVCTL_VECCFG1_VEC2_POL_S                                         6
#define AUX_EVCTL_VECCFG1_VEC2_POL_FALL                             0x00000040
#define AUX_EVCTL_VECCFG1_VEC2_POL_RISE                             0x00000000

// Field:     [5] VEC2_EN
//
// Enables (1) or disables (0) triggering of vector 2 execution.
//
// When enabled, the edge selected by VEC2_POL on the event selected by VEC2_EV
// will set VECFLAGS.VEC2, which in turn triggers vector 2 execution.
//
// Note: Lower vectors (0 and 1) have priority.
// ENUMs:
// EN                       An event selected by VEC2_EV with polarity from
//                          VEC2_POL triggers a jump to vector # 2 when
//                          AUX_SCE is in sleep
// DIS                      Event detection is disabled
#define AUX_EVCTL_VECCFG1_VEC2_EN                                   0x00000020
#define AUX_EVCTL_VECCFG1_VEC2_EN_BITN                                       5
#define AUX_EVCTL_VECCFG1_VEC2_EN_M                                 0x00000020
#define AUX_EVCTL_VECCFG1_VEC2_EN_S                                          5
#define AUX_EVCTL_VECCFG1_VEC2_EN_EN                                0x00000020
#define AUX_EVCTL_VECCFG1_VEC2_EN_DIS                               0x00000000

// Field:   [4:0] VEC2_EV
//
// Selects vector 2 trigger source event.
// ENUMs:
// ADC_IRQ                  ADC_IRQ event
// MCU_EV                   MCU_EV event
// ACLK_REF                 ACLK_REF event
// AUXIO15                  AUXIO15 input data
// AUXIO14                  AUXIO14 input data
// AUXIO13                  AUXIO13 input data
// AUXIO12                  AUXIO12 input data
// AUXIO11                  AUXIO11 input data
// AUXIO10                  AUXIO10 input data
// AUXIO9                   AUXIO9 input data
// AUXIO8                   AUXIO8 input data
// AUXIO7                   AUXIO7 input data
// AUXIO6                   AUXIO6 input data
// AUXIO5                   AUXIO5 input data
// AUXIO4                   AUXIO4 input data
// AUXIO3                   AUXIO3 input data
// AUXIO2                   AUXIO2 input data
// AUXIO1                   AUXIO1 input data
// AUXIO0                   AUXIO0 input data
// AON_PROG_WU              AON_PROG_WU event
// AON_SW                   AON_SW event
// OBSMUX1                  OBSMUX1 event
// OBSMUX0                  OBSMUX0 event
// ADC_FIFO_ALMOST_FULL     ADC_FIFO_ALMOST_FULL event
// ADC_DONE                 ADC_DONE event
// SMPH_AUTOTAKE_DONE       SMPH_AUTOTAKE_DONE event
// TIMER1_EV                TIMER1_EV event
// TIMER0_EV                TIMER0_EV event
// TDC_DONE                 TDC_DONE event
// AUX_COMPB                AUX_COMPB event
// AUX_COMPA                AUX_COMPA event
// AON_RTC_CH2              AON_RTC_CH2 event
#define AUX_EVCTL_VECCFG1_VEC2_EV_W                                          5
#define AUX_EVCTL_VECCFG1_VEC2_EV_M                                 0x0000001F
#define AUX_EVCTL_VECCFG1_VEC2_EV_S                                          0
#define AUX_EVCTL_VECCFG1_VEC2_EV_ADC_IRQ                           0x0000001F
#define AUX_EVCTL_VECCFG1_VEC2_EV_MCU_EV                            0x0000001E
#define AUX_EVCTL_VECCFG1_VEC2_EV_ACLK_REF                          0x0000001D
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO15                           0x0000001C
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO14                           0x0000001B
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO13                           0x0000001A
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO12                           0x00000019
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO11                           0x00000018
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO10                           0x00000017
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO9                            0x00000016
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO8                            0x00000015
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO7                            0x00000014
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO6                            0x00000013
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO5                            0x00000012
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO4                            0x00000011
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO3                            0x00000010
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO2                            0x0000000F
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO1                            0x0000000E
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUXIO0                            0x0000000D
#define AUX_EVCTL_VECCFG1_VEC2_EV_AON_PROG_WU                       0x0000000C
#define AUX_EVCTL_VECCFG1_VEC2_EV_AON_SW                            0x0000000B
#define AUX_EVCTL_VECCFG1_VEC2_EV_OBSMUX1                           0x0000000A
#define AUX_EVCTL_VECCFG1_VEC2_EV_OBSMUX0                           0x00000009
#define AUX_EVCTL_VECCFG1_VEC2_EV_ADC_FIFO_ALMOST_FULL              0x00000008
#define AUX_EVCTL_VECCFG1_VEC2_EV_ADC_DONE                          0x00000007
#define AUX_EVCTL_VECCFG1_VEC2_EV_SMPH_AUTOTAKE_DONE                0x00000006
#define AUX_EVCTL_VECCFG1_VEC2_EV_TIMER1_EV                         0x00000005
#define AUX_EVCTL_VECCFG1_VEC2_EV_TIMER0_EV                         0x00000004
#define AUX_EVCTL_VECCFG1_VEC2_EV_TDC_DONE                          0x00000003
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUX_COMPB                         0x00000002
#define AUX_EVCTL_VECCFG1_VEC2_EV_AUX_COMPA                         0x00000001
#define AUX_EVCTL_VECCFG1_VEC2_EV_AON_RTC_CH2                       0x00000000

//*****************************************************************************
//
// Register: AUX_EVCTL_O_SCEWEVSEL
//
//*****************************************************************************
// Field:   [4:0] WEV7_EV
//
// Selects the event source to be mapped to AUX_SCE:WUSTAT.EV_SIGNALS bit 7.
// ENUMs:
// ADC_IRQ                  ADC_IRQ event
// MCU_EV                   MCU_EV event
// ACLK_REF                 ACLK_REF event
// AUXIO15                  AUXIO15 input data
// AUXIO14                  AUXIO14 input data
// AUXIO13                  AUXIO13 input data
// AUXIO12                  AUXIO12 input data
// AUXIO11                  AUXIO11 input data
// AUXIO10                  AUXIO10 input data
// AUXIO9                   AUXIO9 input data
// AUXIO8                   AUXIO8 input data
// AUXIO7                   AUXIO7 input data
// AUXIO6                   AUXIO6 input data
// AUXIO5                   AUXIO5 input data
// AUXIO4                   AUXIO4 input data
// AUXIO3                   AUXIO3 input data
// AUXIO2                   AUXIO2 input data
// AUXIO1                   AUXIO1 input data
// AUXIO0                   AUXIO0 input data
// AON_PROG_WU              AON_PROG_WU event
// AON_SW                   AON_SW event
// OBSMUX1                  OBSMUX1 event
// OBSMUX0                  OBSMUX0 event
// ADC_FIFO_ALMOST_FULL     ADC_FIFO_ALMOST_FULL event
// ADC_DONE                 ADC_DONE event
// SMPH_AUTOTAKE_DONE       SMPH_AUTOTAKE_DONE event
// TIMER1_EV                TIMER1_EV event
// TIMER0_EV                TIMER0_EV event
// TDC_DONE                 TDC_DONE event
// AUX_COMPB                AUX_COMPB event
// AUX_COMPA                AUX_COMPA event
// AON_RTC_CH2              AON_RTC_CH2 event
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_W                                        5
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_M                               0x0000001F
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_S                                        0
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_ADC_IRQ                         0x0000001F
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_MCU_EV                          0x0000001E
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_ACLK_REF                        0x0000001D
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO15                         0x0000001C
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO14                         0x0000001B
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO13                         0x0000001A
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO12                         0x00000019
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO11                         0x00000018
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO10                         0x00000017
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO9                          0x00000016
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO8                          0x00000015
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO7                          0x00000014
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO6                          0x00000013
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO5                          0x00000012
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO4                          0x00000011
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO3                          0x00000010
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO2                          0x0000000F
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO1                          0x0000000E
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUXIO0                          0x0000000D
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AON_PROG_WU                     0x0000000C
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AON_SW                          0x0000000B
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_OBSMUX1                         0x0000000A
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_OBSMUX0                         0x00000009
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_ADC_FIFO_ALMOST_FULL            0x00000008
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_ADC_DONE                        0x00000007
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_SMPH_AUTOTAKE_DONE              0x00000006
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_TIMER1_EV                       0x00000005
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_TIMER0_EV                       0x00000004
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_TDC_DONE                        0x00000003
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUX_COMPB                       0x00000002
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AUX_COMPA                       0x00000001
#define AUX_EVCTL_SCEWEVSEL_WEV7_EV_AON_RTC_CH2                     0x00000000

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVTOAONFLAGS
//
//*****************************************************************************
// Field:     [8] TIMER1_EV
//
// TIMER1_EV event flag.
#define AUX_EVCTL_EVTOAONFLAGS_TIMER1_EV                            0x00000100
#define AUX_EVCTL_EVTOAONFLAGS_TIMER1_EV_BITN                                8
#define AUX_EVCTL_EVTOAONFLAGS_TIMER1_EV_M                          0x00000100
#define AUX_EVCTL_EVTOAONFLAGS_TIMER1_EV_S                                   8

// Field:     [7] TIMER0_EV
//
// TIMER0_EV event flag.
#define AUX_EVCTL_EVTOAONFLAGS_TIMER0_EV                            0x00000080
#define AUX_EVCTL_EVTOAONFLAGS_TIMER0_EV_BITN                                7
#define AUX_EVCTL_EVTOAONFLAGS_TIMER0_EV_M                          0x00000080
#define AUX_EVCTL_EVTOAONFLAGS_TIMER0_EV_S                                   7

// Field:     [6] TDC_DONE
//
// TDC_DONE event flag.
#define AUX_EVCTL_EVTOAONFLAGS_TDC_DONE                             0x00000040
#define AUX_EVCTL_EVTOAONFLAGS_TDC_DONE_BITN                                 6
#define AUX_EVCTL_EVTOAONFLAGS_TDC_DONE_M                           0x00000040
#define AUX_EVCTL_EVTOAONFLAGS_TDC_DONE_S                                    6

// Field:     [5] ADC_DONE
//
// ADC_DONE event flag.
#define AUX_EVCTL_EVTOAONFLAGS_ADC_DONE                             0x00000020
#define AUX_EVCTL_EVTOAONFLAGS_ADC_DONE_BITN                                 5
#define AUX_EVCTL_EVTOAONFLAGS_ADC_DONE_M                           0x00000020
#define AUX_EVCTL_EVTOAONFLAGS_ADC_DONE_S                                    5

// Field:     [4] AUX_COMPB
//
// AUX_COMPB event flag.
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPB                            0x00000010
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPB_BITN                                4
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPB_M                          0x00000010
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPB_S                                   4

// Field:     [3] AUX_COMPA
//
// AUX_COMPA event flag.
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPA                            0x00000008
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPA_BITN                                3
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPA_M                          0x00000008
#define AUX_EVCTL_EVTOAONFLAGS_AUX_COMPA_S                                   3

// Field:     [2] SWEV2
//
// SWEV2 event flag.
#define AUX_EVCTL_EVTOAONFLAGS_SWEV2                                0x00000004
#define AUX_EVCTL_EVTOAONFLAGS_SWEV2_BITN                                    2
#define AUX_EVCTL_EVTOAONFLAGS_SWEV2_M                              0x00000004
#define AUX_EVCTL_EVTOAONFLAGS_SWEV2_S                                       2

// Field:     [1] SWEV1
//
// SWEV1 event flag.
#define AUX_EVCTL_EVTOAONFLAGS_SWEV1                                0x00000002
#define AUX_EVCTL_EVTOAONFLAGS_SWEV1_BITN                                    1
#define AUX_EVCTL_EVTOAONFLAGS_SWEV1_M                              0x00000002
#define AUX_EVCTL_EVTOAONFLAGS_SWEV1_S                                       1

// Field:     [0] SWEV0
//
// SWEV0 event flag.
#define AUX_EVCTL_EVTOAONFLAGS_SWEV0                                0x00000001
#define AUX_EVCTL_EVTOAONFLAGS_SWEV0_BITN                                    0
#define AUX_EVCTL_EVTOAONFLAGS_SWEV0_M                              0x00000001
#define AUX_EVCTL_EVTOAONFLAGS_SWEV0_S                                       0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVTOAONPOL
//
//*****************************************************************************
// Field:     [8] TIMER1_EV
//
// Selects the event source level that sets EVTOAONFLAGS.TIMER1_EV.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOAONPOL_TIMER1_EV                              0x00000100
#define AUX_EVCTL_EVTOAONPOL_TIMER1_EV_BITN                                  8
#define AUX_EVCTL_EVTOAONPOL_TIMER1_EV_M                            0x00000100
#define AUX_EVCTL_EVTOAONPOL_TIMER1_EV_S                                     8
#define AUX_EVCTL_EVTOAONPOL_TIMER1_EV_LOW                          0x00000100
#define AUX_EVCTL_EVTOAONPOL_TIMER1_EV_HIGH                         0x00000000

// Field:     [7] TIMER0_EV
//
// Selects the event source level that sets EVTOAONFLAGS.TIMER0_EV.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOAONPOL_TIMER0_EV                              0x00000080
#define AUX_EVCTL_EVTOAONPOL_TIMER0_EV_BITN                                  7
#define AUX_EVCTL_EVTOAONPOL_TIMER0_EV_M                            0x00000080
#define AUX_EVCTL_EVTOAONPOL_TIMER0_EV_S                                     7
#define AUX_EVCTL_EVTOAONPOL_TIMER0_EV_LOW                          0x00000080
#define AUX_EVCTL_EVTOAONPOL_TIMER0_EV_HIGH                         0x00000000

// Field:     [6] TDC_DONE
//
// Selects the event source level that sets EVTOAONFLAGS.TDC_DONE.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOAONPOL_TDC_DONE                               0x00000040
#define AUX_EVCTL_EVTOAONPOL_TDC_DONE_BITN                                   6
#define AUX_EVCTL_EVTOAONPOL_TDC_DONE_M                             0x00000040
#define AUX_EVCTL_EVTOAONPOL_TDC_DONE_S                                      6
#define AUX_EVCTL_EVTOAONPOL_TDC_DONE_LOW                           0x00000040
#define AUX_EVCTL_EVTOAONPOL_TDC_DONE_HIGH                          0x00000000

// Field:     [5] ADC_DONE
//
// Selects the event source level that sets EVTOAONFLAGS.ADC_DONE.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOAONPOL_ADC_DONE                               0x00000020
#define AUX_EVCTL_EVTOAONPOL_ADC_DONE_BITN                                   5
#define AUX_EVCTL_EVTOAONPOL_ADC_DONE_M                             0x00000020
#define AUX_EVCTL_EVTOAONPOL_ADC_DONE_S                                      5
#define AUX_EVCTL_EVTOAONPOL_ADC_DONE_LOW                           0x00000020
#define AUX_EVCTL_EVTOAONPOL_ADC_DONE_HIGH                          0x00000000

// Field:     [4] AUX_COMPB
//
// Selects the event source level that sets EVTOAONFLAGS.AUX_COMPB.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPB                              0x00000010
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPB_BITN                                  4
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPB_M                            0x00000010
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPB_S                                     4
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPB_LOW                          0x00000010
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPB_HIGH                         0x00000000

// Field:     [3] AUX_COMPA
//
// Selects the event source level that sets EVTOAONFLAGS.AUX_COMPA.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPA                              0x00000008
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPA_BITN                                  3
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPA_M                            0x00000008
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPA_S                                     3
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPA_LOW                          0x00000008
#define AUX_EVCTL_EVTOAONPOL_AUX_COMPA_HIGH                         0x00000000

//*****************************************************************************
//
// Register: AUX_EVCTL_O_DMACTL
//
//*****************************************************************************
// Field:     [2] REQ_MODE
//
// DMA Request mode
// ENUMs:
// SINGLE                   Single requests are generated on DMA channel 7
//                          when the condition configured in SEL is met
// BURST                    Burst requests are generated on DMA channel 7 when
//                          the condition configured in SEL is met
#define AUX_EVCTL_DMACTL_REQ_MODE                                   0x00000004
#define AUX_EVCTL_DMACTL_REQ_MODE_BITN                                       2
#define AUX_EVCTL_DMACTL_REQ_MODE_M                                 0x00000004
#define AUX_EVCTL_DMACTL_REQ_MODE_S                                          2
#define AUX_EVCTL_DMACTL_REQ_MODE_SINGLE                            0x00000004
#define AUX_EVCTL_DMACTL_REQ_MODE_BURST                             0x00000000

// Field:     [1] EN
//
// 0: DMA interface is disabled
// 1: DMA interface is enabled
#define AUX_EVCTL_DMACTL_EN                                         0x00000002
#define AUX_EVCTL_DMACTL_EN_BITN                                             1
#define AUX_EVCTL_DMACTL_EN_M                                       0x00000002
#define AUX_EVCTL_DMACTL_EN_S                                                1

// Field:     [0] SEL
//
// Selection of FIFO watermark level required to trigger an ADC_DMA transfer
// ENUMs:
// FIFO_ALMOST_FULL         ADC_DMA event will be generated when the ADC FIFO
//                          is almost full (3/4 full)
// FIFO_NOT_EMPTY           ADC_DMA event will be generated when there are
//                          valid samples in the ADC FIFO
#define AUX_EVCTL_DMACTL_SEL                                        0x00000001
#define AUX_EVCTL_DMACTL_SEL_BITN                                            0
#define AUX_EVCTL_DMACTL_SEL_M                                      0x00000001
#define AUX_EVCTL_DMACTL_SEL_S                                               0
#define AUX_EVCTL_DMACTL_SEL_FIFO_ALMOST_FULL                       0x00000001
#define AUX_EVCTL_DMACTL_SEL_FIFO_NOT_EMPTY                         0x00000000

//*****************************************************************************
//
// Register: AUX_EVCTL_O_SWEVSET
//
//*****************************************************************************
// Field:     [2] SWEV2
//
// Writing 1 sets software event 2.
//
// For the MCU domain, the event flag can be read from EVTOAONFLAGS.SWEV2 and
// cleared using EVTOAONFLAGSCLR.SWEV2.
#define AUX_EVCTL_SWEVSET_SWEV2                                     0x00000004
#define AUX_EVCTL_SWEVSET_SWEV2_BITN                                         2
#define AUX_EVCTL_SWEVSET_SWEV2_M                                   0x00000004
#define AUX_EVCTL_SWEVSET_SWEV2_S                                            2

// Field:     [1] SWEV1
//
// Writing 1 sets software event 1.
//
// For the MCU domain, the event flag can be read from EVTOAONFLAGS.SWEV1 and
// cleared using EVTOAONFLAGSCLR.SWEV1.
#define AUX_EVCTL_SWEVSET_SWEV1                                     0x00000002
#define AUX_EVCTL_SWEVSET_SWEV1_BITN                                         1
#define AUX_EVCTL_SWEVSET_SWEV1_M                                   0x00000002
#define AUX_EVCTL_SWEVSET_SWEV1_S                                            1

// Field:     [0] SWEV0
//
// Writing 1 sets software event 0.
//
// For the MCU domain, the event flag can be read from EVTOAONFLAGS.SWEV0 and
// cleared using EVTOAONFLAGSCLR.SWEV0.
#define AUX_EVCTL_SWEVSET_SWEV0                                     0x00000001
#define AUX_EVCTL_SWEVSET_SWEV0_BITN                                         0
#define AUX_EVCTL_SWEVSET_SWEV0_M                                   0x00000001
#define AUX_EVCTL_SWEVSET_SWEV0_S                                            0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVSTAT0
//
//*****************************************************************************
// Field:    [15] AUXIO2
//
// Current value of AUXIO2 input data line
#define AUX_EVCTL_EVSTAT0_AUXIO2                                    0x00008000
#define AUX_EVCTL_EVSTAT0_AUXIO2_BITN                                       15
#define AUX_EVCTL_EVSTAT0_AUXIO2_M                                  0x00008000
#define AUX_EVCTL_EVSTAT0_AUXIO2_S                                          15

// Field:    [14] AUXIO1
//
// Current value of AUXIO1 input data line
#define AUX_EVCTL_EVSTAT0_AUXIO1                                    0x00004000
#define AUX_EVCTL_EVSTAT0_AUXIO1_BITN                                       14
#define AUX_EVCTL_EVSTAT0_AUXIO1_M                                  0x00004000
#define AUX_EVCTL_EVSTAT0_AUXIO1_S                                          14

// Field:    [13] AUXIO0
//
// Current value of AUXIO0 input data line
#define AUX_EVCTL_EVSTAT0_AUXIO0                                    0x00002000
#define AUX_EVCTL_EVSTAT0_AUXIO0_BITN                                       13
#define AUX_EVCTL_EVSTAT0_AUXIO0_M                                  0x00002000
#define AUX_EVCTL_EVSTAT0_AUXIO0_S                                          13

// Field:    [12] AON_PROG_WU
//
// Current value of OBSMUX3 event line
#define AUX_EVCTL_EVSTAT0_AON_PROG_WU                               0x00001000
#define AUX_EVCTL_EVSTAT0_AON_PROG_WU_BITN                                  12
#define AUX_EVCTL_EVSTAT0_AON_PROG_WU_M                             0x00001000
#define AUX_EVCTL_EVSTAT0_AON_PROG_WU_S                                     12

// Field:    [11] AON_SW
//
// Current value of OBSMUX2 event line
#define AUX_EVCTL_EVSTAT0_AON_SW                                    0x00000800
#define AUX_EVCTL_EVSTAT0_AON_SW_BITN                                       11
#define AUX_EVCTL_EVSTAT0_AON_SW_M                                  0x00000800
#define AUX_EVCTL_EVSTAT0_AON_SW_S                                          11

// Field:    [10] OBSMUX1
//
// Current value of OBSMUX1 event line
#define AUX_EVCTL_EVSTAT0_OBSMUX1                                   0x00000400
#define AUX_EVCTL_EVSTAT0_OBSMUX1_BITN                                      10
#define AUX_EVCTL_EVSTAT0_OBSMUX1_M                                 0x00000400
#define AUX_EVCTL_EVSTAT0_OBSMUX1_S                                         10

// Field:     [9] OBSMUX0
//
// Current value of OBSMUX0 event line
#define AUX_EVCTL_EVSTAT0_OBSMUX0                                   0x00000200
#define AUX_EVCTL_EVSTAT0_OBSMUX0_BITN                                       9
#define AUX_EVCTL_EVSTAT0_OBSMUX0_M                                 0x00000200
#define AUX_EVCTL_EVSTAT0_OBSMUX0_S                                          9

// Field:     [8] ADC_FIFO_ALMOST_FULL
//
// Current value of ADC_FIFO_ALMOST_FULL event line
#define AUX_EVCTL_EVSTAT0_ADC_FIFO_ALMOST_FULL                      0x00000100
#define AUX_EVCTL_EVSTAT0_ADC_FIFO_ALMOST_FULL_BITN                          8
#define AUX_EVCTL_EVSTAT0_ADC_FIFO_ALMOST_FULL_M                    0x00000100
#define AUX_EVCTL_EVSTAT0_ADC_FIFO_ALMOST_FULL_S                             8

// Field:     [7] ADC_DONE
//
// Current value of ADC_DONE event line
#define AUX_EVCTL_EVSTAT0_ADC_DONE                                  0x00000080
#define AUX_EVCTL_EVSTAT0_ADC_DONE_BITN                                      7
#define AUX_EVCTL_EVSTAT0_ADC_DONE_M                                0x00000080
#define AUX_EVCTL_EVSTAT0_ADC_DONE_S                                         7

// Field:     [6] SMPH_AUTOTAKE_DONE
//
// Current value of SMPH_AUTOTAKE_DONE event line
#define AUX_EVCTL_EVSTAT0_SMPH_AUTOTAKE_DONE                        0x00000040
#define AUX_EVCTL_EVSTAT0_SMPH_AUTOTAKE_DONE_BITN                            6
#define AUX_EVCTL_EVSTAT0_SMPH_AUTOTAKE_DONE_M                      0x00000040
#define AUX_EVCTL_EVSTAT0_SMPH_AUTOTAKE_DONE_S                               6

// Field:     [5] TIMER1_EV
//
// Current value of TIMER1_EV event line
#define AUX_EVCTL_EVSTAT0_TIMER1_EV                                 0x00000020
#define AUX_EVCTL_EVSTAT0_TIMER1_EV_BITN                                     5
#define AUX_EVCTL_EVSTAT0_TIMER1_EV_M                               0x00000020
#define AUX_EVCTL_EVSTAT0_TIMER1_EV_S                                        5

// Field:     [4] TIMER0_EV
//
// Current value of TIMER0_EV event line
#define AUX_EVCTL_EVSTAT0_TIMER0_EV                                 0x00000010
#define AUX_EVCTL_EVSTAT0_TIMER0_EV_BITN                                     4
#define AUX_EVCTL_EVSTAT0_TIMER0_EV_M                               0x00000010
#define AUX_EVCTL_EVSTAT0_TIMER0_EV_S                                        4

// Field:     [3] TDC_DONE
//
// Current value of TDC_DONE event line
#define AUX_EVCTL_EVSTAT0_TDC_DONE                                  0x00000008
#define AUX_EVCTL_EVSTAT0_TDC_DONE_BITN                                      3
#define AUX_EVCTL_EVSTAT0_TDC_DONE_M                                0x00000008
#define AUX_EVCTL_EVSTAT0_TDC_DONE_S                                         3

// Field:     [2] AUX_COMPB
//
// Current value of AUX_COMPB event line
#define AUX_EVCTL_EVSTAT0_AUX_COMPB                                 0x00000004
#define AUX_EVCTL_EVSTAT0_AUX_COMPB_BITN                                     2
#define AUX_EVCTL_EVSTAT0_AUX_COMPB_M                               0x00000004
#define AUX_EVCTL_EVSTAT0_AUX_COMPB_S                                        2

// Field:     [1] AUX_COMPA
//
// Current value of AUX_COMPA event line
#define AUX_EVCTL_EVSTAT0_AUX_COMPA                                 0x00000002
#define AUX_EVCTL_EVSTAT0_AUX_COMPA_BITN                                     1
#define AUX_EVCTL_EVSTAT0_AUX_COMPA_M                               0x00000002
#define AUX_EVCTL_EVSTAT0_AUX_COMPA_S                                        1

// Field:     [0] AON_RTC_CH2
//
// Current value of AON_RTC_CH2 event line
#define AUX_EVCTL_EVSTAT0_AON_RTC_CH2                               0x00000001
#define AUX_EVCTL_EVSTAT0_AON_RTC_CH2_BITN                                   0
#define AUX_EVCTL_EVSTAT0_AON_RTC_CH2_M                             0x00000001
#define AUX_EVCTL_EVSTAT0_AON_RTC_CH2_S                                      0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVSTAT1
//
//*****************************************************************************
// Field:    [15] ADC_IRQ
//
// Current value of ADC_IRQ event line
#define AUX_EVCTL_EVSTAT1_ADC_IRQ                                   0x00008000
#define AUX_EVCTL_EVSTAT1_ADC_IRQ_BITN                                      15
#define AUX_EVCTL_EVSTAT1_ADC_IRQ_M                                 0x00008000
#define AUX_EVCTL_EVSTAT1_ADC_IRQ_S                                         15

// Field:    [14] MCU_EV
//
// Current value of MCU_EV event line
#define AUX_EVCTL_EVSTAT1_MCU_EV                                    0x00004000
#define AUX_EVCTL_EVSTAT1_MCU_EV_BITN                                       14
#define AUX_EVCTL_EVSTAT1_MCU_EV_M                                  0x00004000
#define AUX_EVCTL_EVSTAT1_MCU_EV_S                                          14

// Field:    [13] ACLK_REF
//
// Current value of ACLK_REF event line
#define AUX_EVCTL_EVSTAT1_ACLK_REF                                  0x00002000
#define AUX_EVCTL_EVSTAT1_ACLK_REF_BITN                                     13
#define AUX_EVCTL_EVSTAT1_ACLK_REF_M                                0x00002000
#define AUX_EVCTL_EVSTAT1_ACLK_REF_S                                        13

// Field:    [12] AUXIO15
//
// Current value of AUXIO15 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO15                                   0x00001000
#define AUX_EVCTL_EVSTAT1_AUXIO15_BITN                                      12
#define AUX_EVCTL_EVSTAT1_AUXIO15_M                                 0x00001000
#define AUX_EVCTL_EVSTAT1_AUXIO15_S                                         12

// Field:    [11] AUXIO14
//
// Current value of AUXIO14 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO14                                   0x00000800
#define AUX_EVCTL_EVSTAT1_AUXIO14_BITN                                      11
#define AUX_EVCTL_EVSTAT1_AUXIO14_M                                 0x00000800
#define AUX_EVCTL_EVSTAT1_AUXIO14_S                                         11

// Field:    [10] AUXIO13
//
// Current value of AUXIO13 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO13                                   0x00000400
#define AUX_EVCTL_EVSTAT1_AUXIO13_BITN                                      10
#define AUX_EVCTL_EVSTAT1_AUXIO13_M                                 0x00000400
#define AUX_EVCTL_EVSTAT1_AUXIO13_S                                         10

// Field:     [9] AUXIO12
//
// Current value of AUXIO12 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO12                                   0x00000200
#define AUX_EVCTL_EVSTAT1_AUXIO12_BITN                                       9
#define AUX_EVCTL_EVSTAT1_AUXIO12_M                                 0x00000200
#define AUX_EVCTL_EVSTAT1_AUXIO12_S                                          9

// Field:     [8] AUXIO11
//
// Current value of AUXIO11 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO11                                   0x00000100
#define AUX_EVCTL_EVSTAT1_AUXIO11_BITN                                       8
#define AUX_EVCTL_EVSTAT1_AUXIO11_M                                 0x00000100
#define AUX_EVCTL_EVSTAT1_AUXIO11_S                                          8

// Field:     [7] AUXIO10
//
// Current value of AUXIO10 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO10                                   0x00000080
#define AUX_EVCTL_EVSTAT1_AUXIO10_BITN                                       7
#define AUX_EVCTL_EVSTAT1_AUXIO10_M                                 0x00000080
#define AUX_EVCTL_EVSTAT1_AUXIO10_S                                          7

// Field:     [6] AUXIO9
//
// Current value of AUXIO9 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO9                                    0x00000040
#define AUX_EVCTL_EVSTAT1_AUXIO9_BITN                                        6
#define AUX_EVCTL_EVSTAT1_AUXIO9_M                                  0x00000040
#define AUX_EVCTL_EVSTAT1_AUXIO9_S                                           6

// Field:     [5] AUXIO8
//
// Current value of AUXIO8 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO8                                    0x00000020
#define AUX_EVCTL_EVSTAT1_AUXIO8_BITN                                        5
#define AUX_EVCTL_EVSTAT1_AUXIO8_M                                  0x00000020
#define AUX_EVCTL_EVSTAT1_AUXIO8_S                                           5

// Field:     [4] AUXIO7
//
// Current value of AUXIO7 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO7                                    0x00000010
#define AUX_EVCTL_EVSTAT1_AUXIO7_BITN                                        4
#define AUX_EVCTL_EVSTAT1_AUXIO7_M                                  0x00000010
#define AUX_EVCTL_EVSTAT1_AUXIO7_S                                           4

// Field:     [3] AUXIO6
//
// Current value of AUXIO6 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO6                                    0x00000008
#define AUX_EVCTL_EVSTAT1_AUXIO6_BITN                                        3
#define AUX_EVCTL_EVSTAT1_AUXIO6_M                                  0x00000008
#define AUX_EVCTL_EVSTAT1_AUXIO6_S                                           3

// Field:     [2] AUXIO5
//
// Current value of AUXIO5 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO5                                    0x00000004
#define AUX_EVCTL_EVSTAT1_AUXIO5_BITN                                        2
#define AUX_EVCTL_EVSTAT1_AUXIO5_M                                  0x00000004
#define AUX_EVCTL_EVSTAT1_AUXIO5_S                                           2

// Field:     [1] AUXIO4
//
// Current value of AUXIO4 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO4                                    0x00000002
#define AUX_EVCTL_EVSTAT1_AUXIO4_BITN                                        1
#define AUX_EVCTL_EVSTAT1_AUXIO4_M                                  0x00000002
#define AUX_EVCTL_EVSTAT1_AUXIO4_S                                           1

// Field:     [0] AUXIO3
//
// Current value of AUXIO3 input data line
#define AUX_EVCTL_EVSTAT1_AUXIO3                                    0x00000001
#define AUX_EVCTL_EVSTAT1_AUXIO3_BITN                                        0
#define AUX_EVCTL_EVSTAT1_AUXIO3_M                                  0x00000001
#define AUX_EVCTL_EVSTAT1_AUXIO3_S                                           0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVTOMCUPOL
//
//*****************************************************************************
// Field:    [10] ADC_IRQ
//
// Selects the event source level that sets EVTOMCUFLAGS.ADC_IRQ.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_ADC_IRQ                                0x00000400
#define AUX_EVCTL_EVTOMCUPOL_ADC_IRQ_BITN                                   10
#define AUX_EVCTL_EVTOMCUPOL_ADC_IRQ_M                              0x00000400
#define AUX_EVCTL_EVTOMCUPOL_ADC_IRQ_S                                      10
#define AUX_EVCTL_EVTOMCUPOL_ADC_IRQ_LOW                            0x00000400
#define AUX_EVCTL_EVTOMCUPOL_ADC_IRQ_HIGH                           0x00000000

// Field:     [9] OBSMUX0
//
// Selects the event source level that sets EVTOMCUFLAGS.OBSMUX0.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_OBSMUX0                                0x00000200
#define AUX_EVCTL_EVTOMCUPOL_OBSMUX0_BITN                                    9
#define AUX_EVCTL_EVTOMCUPOL_OBSMUX0_M                              0x00000200
#define AUX_EVCTL_EVTOMCUPOL_OBSMUX0_S                                       9
#define AUX_EVCTL_EVTOMCUPOL_OBSMUX0_LOW                            0x00000200
#define AUX_EVCTL_EVTOMCUPOL_OBSMUX0_HIGH                           0x00000000

// Field:     [8] ADC_FIFO_ALMOST_FULL
//
// Selects the event source level that sets EVTOMCUFLAGS.ADC_FIFO_ALMOST_FULL.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_ADC_FIFO_ALMOST_FULL                   0x00000100
#define AUX_EVCTL_EVTOMCUPOL_ADC_FIFO_ALMOST_FULL_BITN                       8
#define AUX_EVCTL_EVTOMCUPOL_ADC_FIFO_ALMOST_FULL_M                 0x00000100
#define AUX_EVCTL_EVTOMCUPOL_ADC_FIFO_ALMOST_FULL_S                          8
#define AUX_EVCTL_EVTOMCUPOL_ADC_FIFO_ALMOST_FULL_LOW               0x00000100
#define AUX_EVCTL_EVTOMCUPOL_ADC_FIFO_ALMOST_FULL_HIGH              0x00000000

// Field:     [7] ADC_DONE
//
// Selects the event source level that sets EVTOMCUFLAGS.ADC_DONE.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_ADC_DONE                               0x00000080
#define AUX_EVCTL_EVTOMCUPOL_ADC_DONE_BITN                                   7
#define AUX_EVCTL_EVTOMCUPOL_ADC_DONE_M                             0x00000080
#define AUX_EVCTL_EVTOMCUPOL_ADC_DONE_S                                      7
#define AUX_EVCTL_EVTOMCUPOL_ADC_DONE_LOW                           0x00000080
#define AUX_EVCTL_EVTOMCUPOL_ADC_DONE_HIGH                          0x00000000

// Field:     [6] SMPH_AUTOTAKE_DONE
//
// Selects the event source level that sets EVTOMCUFLAGS.SMPH_AUTOTAKE_DONE.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_SMPH_AUTOTAKE_DONE                     0x00000040
#define AUX_EVCTL_EVTOMCUPOL_SMPH_AUTOTAKE_DONE_BITN                         6
#define AUX_EVCTL_EVTOMCUPOL_SMPH_AUTOTAKE_DONE_M                   0x00000040
#define AUX_EVCTL_EVTOMCUPOL_SMPH_AUTOTAKE_DONE_S                            6
#define AUX_EVCTL_EVTOMCUPOL_SMPH_AUTOTAKE_DONE_LOW                 0x00000040
#define AUX_EVCTL_EVTOMCUPOL_SMPH_AUTOTAKE_DONE_HIGH                0x00000000

// Field:     [5] TIMER1_EV
//
// Selects the event source level that sets EVTOMCUFLAGS.TIMER1_EV.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_TIMER1_EV                              0x00000020
#define AUX_EVCTL_EVTOMCUPOL_TIMER1_EV_BITN                                  5
#define AUX_EVCTL_EVTOMCUPOL_TIMER1_EV_M                            0x00000020
#define AUX_EVCTL_EVTOMCUPOL_TIMER1_EV_S                                     5
#define AUX_EVCTL_EVTOMCUPOL_TIMER1_EV_LOW                          0x00000020
#define AUX_EVCTL_EVTOMCUPOL_TIMER1_EV_HIGH                         0x00000000

// Field:     [4] TIMER0_EV
//
// Selects the event source level that sets EVTOMCUFLAGS.TIMER0_EV.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_TIMER0_EV                              0x00000010
#define AUX_EVCTL_EVTOMCUPOL_TIMER0_EV_BITN                                  4
#define AUX_EVCTL_EVTOMCUPOL_TIMER0_EV_M                            0x00000010
#define AUX_EVCTL_EVTOMCUPOL_TIMER0_EV_S                                     4
#define AUX_EVCTL_EVTOMCUPOL_TIMER0_EV_LOW                          0x00000010
#define AUX_EVCTL_EVTOMCUPOL_TIMER0_EV_HIGH                         0x00000000

// Field:     [3] TDC_DONE
//
// Selects the event source level that sets EVTOMCUFLAGS.TDC_DONE.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_TDC_DONE                               0x00000008
#define AUX_EVCTL_EVTOMCUPOL_TDC_DONE_BITN                                   3
#define AUX_EVCTL_EVTOMCUPOL_TDC_DONE_M                             0x00000008
#define AUX_EVCTL_EVTOMCUPOL_TDC_DONE_S                                      3
#define AUX_EVCTL_EVTOMCUPOL_TDC_DONE_LOW                           0x00000008
#define AUX_EVCTL_EVTOMCUPOL_TDC_DONE_HIGH                          0x00000000

// Field:     [2] AUX_COMPB
//
// Selects the event source level that sets EVTOMCUFLAGS.AUX_COMPB.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPB                              0x00000004
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPB_BITN                                  2
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPB_M                            0x00000004
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPB_S                                     2
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPB_LOW                          0x00000004
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPB_HIGH                         0x00000000

// Field:     [1] AUX_COMPA
//
// Selects the event source level that sets EVTOMCUFLAGS.AUX_COMPA.
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPA                              0x00000002
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPA_BITN                                  1
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPA_M                            0x00000002
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPA_S                                     1
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPA_LOW                          0x00000002
#define AUX_EVCTL_EVTOMCUPOL_AUX_COMPA_HIGH                         0x00000000

// Field:     [0] AON_WU_EV
//
// Selects the event source level that sets EVTOMCUFLAGS.AON_WU_EV
// ENUMs:
// LOW                      Low level
// HIGH                     High level
#define AUX_EVCTL_EVTOMCUPOL_AON_WU_EV                              0x00000001
#define AUX_EVCTL_EVTOMCUPOL_AON_WU_EV_BITN                                  0
#define AUX_EVCTL_EVTOMCUPOL_AON_WU_EV_M                            0x00000001
#define AUX_EVCTL_EVTOMCUPOL_AON_WU_EV_S                                     0
#define AUX_EVCTL_EVTOMCUPOL_AON_WU_EV_LOW                          0x00000001
#define AUX_EVCTL_EVTOMCUPOL_AON_WU_EV_HIGH                         0x00000000

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVTOMCUFLAGS
//
//*****************************************************************************
// Field:    [10] ADC_IRQ
//
// ADC_IRQ event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_IRQ                              0x00000400
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_IRQ_BITN                                 10
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_IRQ_M                            0x00000400
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_IRQ_S                                    10

// Field:     [9] OBSMUX0
//
// OBSMUX0 event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_OBSMUX0                              0x00000200
#define AUX_EVCTL_EVTOMCUFLAGS_OBSMUX0_BITN                                  9
#define AUX_EVCTL_EVTOMCUFLAGS_OBSMUX0_M                            0x00000200
#define AUX_EVCTL_EVTOMCUFLAGS_OBSMUX0_S                                     9

// Field:     [8] ADC_FIFO_ALMOST_FULL
//
// ADC_FIFO_ALMOST_FULL event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_FIFO_ALMOST_FULL                 0x00000100
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_FIFO_ALMOST_FULL_BITN                     8
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_FIFO_ALMOST_FULL_M               0x00000100
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_FIFO_ALMOST_FULL_S                        8

// Field:     [7] ADC_DONE
//
// ADC_DONE event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_DONE                             0x00000080
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_DONE_BITN                                 7
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_DONE_M                           0x00000080
#define AUX_EVCTL_EVTOMCUFLAGS_ADC_DONE_S                                    7

// Field:     [6] SMPH_AUTOTAKE_DONE
//
// SMPH_AUTOTAKE_DONE event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_SMPH_AUTOTAKE_DONE                   0x00000040
#define AUX_EVCTL_EVTOMCUFLAGS_SMPH_AUTOTAKE_DONE_BITN                       6
#define AUX_EVCTL_EVTOMCUFLAGS_SMPH_AUTOTAKE_DONE_M                 0x00000040
#define AUX_EVCTL_EVTOMCUFLAGS_SMPH_AUTOTAKE_DONE_S                          6

// Field:     [5] TIMER1_EV
//
// TIMER1_EV event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER1_EV                            0x00000020
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER1_EV_BITN                                5
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER1_EV_M                          0x00000020
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER1_EV_S                                   5

// Field:     [4] TIMER0_EV
//
// TIMER0_EV event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER0_EV                            0x00000010
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER0_EV_BITN                                4
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER0_EV_M                          0x00000010
#define AUX_EVCTL_EVTOMCUFLAGS_TIMER0_EV_S                                   4

// Field:     [3] TDC_DONE
//
// TDC_DONE event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_TDC_DONE                             0x00000008
#define AUX_EVCTL_EVTOMCUFLAGS_TDC_DONE_BITN                                 3
#define AUX_EVCTL_EVTOMCUFLAGS_TDC_DONE_M                           0x00000008
#define AUX_EVCTL_EVTOMCUFLAGS_TDC_DONE_S                                    3

// Field:     [2] AUX_COMPB
//
// AUX_COMPB event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPB                            0x00000004
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPB_BITN                                2
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPB_M                          0x00000004
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPB_S                                   2

// Field:     [1] AUX_COMPA
//
// AUX_COMPA event flag.
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPA                            0x00000002
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPA_BITN                                1
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPA_M                          0x00000002
#define AUX_EVCTL_EVTOMCUFLAGS_AUX_COMPA_S                                   1

// Field:     [0] AON_WU_EV
//
// AON_WU_EV event flag.
//
// This is an OR of the AON_RTC_CH2, AON_PROG_WU and AON_SW events. These event
// sources must be cleared before clearing AON_WU_EV.
#define AUX_EVCTL_EVTOMCUFLAGS_AON_WU_EV                            0x00000001
#define AUX_EVCTL_EVTOMCUFLAGS_AON_WU_EV_BITN                                0
#define AUX_EVCTL_EVTOMCUFLAGS_AON_WU_EV_M                          0x00000001
#define AUX_EVCTL_EVTOMCUFLAGS_AON_WU_EV_S                                   0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_COMBEVTOMCUMASK
//
//*****************************************************************************
// Field:    [10] ADC_IRQ
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.ADC_IRQ contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_IRQ                           0x00000400
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_IRQ_BITN                              10
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_IRQ_M                         0x00000400
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_IRQ_S                                 10

// Field:     [9] OBSMUX0
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.OBSMUX0 contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_OBSMUX0                           0x00000200
#define AUX_EVCTL_COMBEVTOMCUMASK_OBSMUX0_BITN                               9
#define AUX_EVCTL_COMBEVTOMCUMASK_OBSMUX0_M                         0x00000200
#define AUX_EVCTL_COMBEVTOMCUMASK_OBSMUX0_S                                  9

// Field:     [8] ADC_FIFO_ALMOST_FULL
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.ADC_FIFO_ALMOST_FULL contribution
// to the AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_FIFO_ALMOST_FULL              0x00000100
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_FIFO_ALMOST_FULL_BITN                  8
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_FIFO_ALMOST_FULL_M            0x00000100
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_FIFO_ALMOST_FULL_S                     8

// Field:     [7] ADC_DONE
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.ADC_DONE contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_DONE                          0x00000080
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_DONE_BITN                              7
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_DONE_M                        0x00000080
#define AUX_EVCTL_COMBEVTOMCUMASK_ADC_DONE_S                                 7

// Field:     [6] SMPH_AUTOTAKE_DONE
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.SMPH_AUTOTAKE_DONE contribution to
// the AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_SMPH_AUTOTAKE_DONE                0x00000040
#define AUX_EVCTL_COMBEVTOMCUMASK_SMPH_AUTOTAKE_DONE_BITN                    6
#define AUX_EVCTL_COMBEVTOMCUMASK_SMPH_AUTOTAKE_DONE_M              0x00000040
#define AUX_EVCTL_COMBEVTOMCUMASK_SMPH_AUTOTAKE_DONE_S                       6

// Field:     [5] TIMER1_EV
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.TIMER1_EV contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER1_EV                         0x00000020
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER1_EV_BITN                             5
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER1_EV_M                       0x00000020
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER1_EV_S                                5

// Field:     [4] TIMER0_EV
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.TIMER0_EV contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER0_EV                         0x00000010
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER0_EV_BITN                             4
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER0_EV_M                       0x00000010
#define AUX_EVCTL_COMBEVTOMCUMASK_TIMER0_EV_S                                4

// Field:     [3] TDC_DONE
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.TDC_DONE contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_TDC_DONE                          0x00000008
#define AUX_EVCTL_COMBEVTOMCUMASK_TDC_DONE_BITN                              3
#define AUX_EVCTL_COMBEVTOMCUMASK_TDC_DONE_M                        0x00000008
#define AUX_EVCTL_COMBEVTOMCUMASK_TDC_DONE_S                                 3

// Field:     [2] AUX_COMPB
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.AUX_COMPB contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPB                         0x00000004
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPB_BITN                             2
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPB_M                       0x00000004
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPB_S                                2

// Field:     [1] AUX_COMPA
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.AUX_COMPA contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPA                         0x00000002
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPA_BITN                             1
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPA_M                       0x00000002
#define AUX_EVCTL_COMBEVTOMCUMASK_AUX_COMPA_S                                1

// Field:     [0] AON_WU_EV
//
// Includes (1) or excludes (0) EVTOMCUFLAGS.AON_WU_EV contribution to the
// AUX_COMB event.
#define AUX_EVCTL_COMBEVTOMCUMASK_AON_WU_EV                         0x00000001
#define AUX_EVCTL_COMBEVTOMCUMASK_AON_WU_EV_BITN                             0
#define AUX_EVCTL_COMBEVTOMCUMASK_AON_WU_EV_M                       0x00000001
#define AUX_EVCTL_COMBEVTOMCUMASK_AON_WU_EV_S                                0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_VECFLAGS
//
//*****************************************************************************
// Field:     [3] VEC3
//
// The vector flag is set if the edge selected VECCFG1.VEC3_POL occurs on the
// event selected in VECCFG1.VEC3_EV.
//
// The flag is cleared by writing a 0 to this bit, or (preferably) a 1 to
// VECFLAGSCLR.VEC3.
#define AUX_EVCTL_VECFLAGS_VEC3                                     0x00000008
#define AUX_EVCTL_VECFLAGS_VEC3_BITN                                         3
#define AUX_EVCTL_VECFLAGS_VEC3_M                                   0x00000008
#define AUX_EVCTL_VECFLAGS_VEC3_S                                            3

// Field:     [2] VEC2
//
// The vector flag is set if the edge selected VECCFG1.VEC2_POL occurs on the
// event selected in VECCFG1.VEC2_EV.
//
// The flag is cleared by writing a 0 to this bit, or (preferably) a 1 to
// VECFLAGSCLR.VEC2.
#define AUX_EVCTL_VECFLAGS_VEC2                                     0x00000004
#define AUX_EVCTL_VECFLAGS_VEC2_BITN                                         2
#define AUX_EVCTL_VECFLAGS_VEC2_M                                   0x00000004
#define AUX_EVCTL_VECFLAGS_VEC2_S                                            2

// Field:     [1] VEC1
//
// The vector flag is set if the edge selected VECCFG0.VEC1_POL occurs on the
// event selected in VECCFG0.VEC1_EV.
//
// The flag is cleared by writing a 0 to this bit, or (preferably) a 1 to
// VECFLAGSCLR.VEC1.
#define AUX_EVCTL_VECFLAGS_VEC1                                     0x00000002
#define AUX_EVCTL_VECFLAGS_VEC1_BITN                                         1
#define AUX_EVCTL_VECFLAGS_VEC1_M                                   0x00000002
#define AUX_EVCTL_VECFLAGS_VEC1_S                                            1

// Field:     [0] VEC0
//
// The vector flag is set if the edge selected VECCFG0.VEC0_POL occurs on the
// event selected in VECCFG0.VEC0_EV.
//
// The flag is cleared by writing a 0 to this bit, or (preferably) a 1 to
// VECFLAGSCLR.VEC0.
#define AUX_EVCTL_VECFLAGS_VEC0                                     0x00000001
#define AUX_EVCTL_VECFLAGS_VEC0_BITN                                         0
#define AUX_EVCTL_VECFLAGS_VEC0_M                                   0x00000001
#define AUX_EVCTL_VECFLAGS_VEC0_S                                            0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVTOMCUFLAGSCLR
//
//*****************************************************************************
// Field:    [10] ADC_IRQ
//
// Writing 1 clears EVTOMCUFLAGS.ADC_IRQ.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_IRQ                           0x00000400
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_IRQ_BITN                              10
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_IRQ_M                         0x00000400
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_IRQ_S                                 10

// Field:     [9] OBSMUX0
//
// Writing 1 clears EVTOMCUFLAGS.OBSMUX0.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_OBSMUX0                           0x00000200
#define AUX_EVCTL_EVTOMCUFLAGSCLR_OBSMUX0_BITN                               9
#define AUX_EVCTL_EVTOMCUFLAGSCLR_OBSMUX0_M                         0x00000200
#define AUX_EVCTL_EVTOMCUFLAGSCLR_OBSMUX0_S                                  9

// Field:     [8] ADC_FIFO_ALMOST_FULL
//
// Writing 1 clears EVTOMCUFLAGS.ADC_FIFO_ALMOST_FULL.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_FIFO_ALMOST_FULL              0x00000100
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_FIFO_ALMOST_FULL_BITN                  8
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_FIFO_ALMOST_FULL_M            0x00000100
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_FIFO_ALMOST_FULL_S                     8

// Field:     [7] ADC_DONE
//
// Writing 1 clears EVTOMCUFLAGS.ADC_DONE.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_DONE                          0x00000080
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_DONE_BITN                              7
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_DONE_M                        0x00000080
#define AUX_EVCTL_EVTOMCUFLAGSCLR_ADC_DONE_S                                 7

// Field:     [6] SMPH_AUTOTAKE_DONE
//
// Writing 1 clears [EVTOMCUFLAGS.SMPH_AUTOTAKE_DONE.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_SMPH_AUTOTAKE_DONE                0x00000040
#define AUX_EVCTL_EVTOMCUFLAGSCLR_SMPH_AUTOTAKE_DONE_BITN                    6
#define AUX_EVCTL_EVTOMCUFLAGSCLR_SMPH_AUTOTAKE_DONE_M              0x00000040
#define AUX_EVCTL_EVTOMCUFLAGSCLR_SMPH_AUTOTAKE_DONE_S                       6

// Field:     [5] TIMER1_EV
//
// Writing 1 clears EVTOMCUFLAGS.TIMER1_EV.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER1_EV                         0x00000020
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER1_EV_BITN                             5
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER1_EV_M                       0x00000020
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER1_EV_S                                5

// Field:     [4] TIMER0_EV
//
// Writing 1 clears EVTOMCUFLAGS.TIMER0_EV.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER0_EV                         0x00000010
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER0_EV_BITN                             4
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER0_EV_M                       0x00000010
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TIMER0_EV_S                                4

// Field:     [3] TDC_DONE
//
// Writing 1 clears EVTOMCUFLAGS.TDC_DONE.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TDC_DONE                          0x00000008
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TDC_DONE_BITN                              3
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TDC_DONE_M                        0x00000008
#define AUX_EVCTL_EVTOMCUFLAGSCLR_TDC_DONE_S                                 3

// Field:     [2] AUX_COMPB
//
// Writing 1 clears EVTOMCUFLAGS.AUX_COMPB.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPB                         0x00000004
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPB_BITN                             2
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPB_M                       0x00000004
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPB_S                                2

// Field:     [1] AUX_COMPA
//
// Writing 1 clears EVTOMCUFLAGS.AUX_COMPA.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPA                         0x00000002
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPA_BITN                             1
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPA_M                       0x00000002
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AUX_COMPA_S                                1

// Field:     [0] AON_WU_EV
//
// Writing 1 clears EVTOMCUFLAGS.AON_WU_EV.
//
// Read value is 0.
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AON_WU_EV                         0x00000001
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AON_WU_EV_BITN                             0
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AON_WU_EV_M                       0x00000001
#define AUX_EVCTL_EVTOMCUFLAGSCLR_AON_WU_EV_S                                0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_EVTOAONFLAGSCLR
//
//*****************************************************************************
// Field:     [8] TIMER1_EV
//
// Writing 1 clears EVTOAONFLAGS.TIMER1_EV.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER1_EV                         0x00000100
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER1_EV_BITN                             8
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER1_EV_M                       0x00000100
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER1_EV_S                                8

// Field:     [7] TIMER0_EV
//
// Writing 1 clears EVTOAONFLAGS.TIMER0_EV.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER0_EV                         0x00000080
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER0_EV_BITN                             7
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER0_EV_M                       0x00000080
#define AUX_EVCTL_EVTOAONFLAGSCLR_TIMER0_EV_S                                7

// Field:     [6] TDC_DONE
//
// Writing 1 clears EVTOAONFLAGS.TDC_DONE.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_TDC_DONE                          0x00000040
#define AUX_EVCTL_EVTOAONFLAGSCLR_TDC_DONE_BITN                              6
#define AUX_EVCTL_EVTOAONFLAGSCLR_TDC_DONE_M                        0x00000040
#define AUX_EVCTL_EVTOAONFLAGSCLR_TDC_DONE_S                                 6

// Field:     [5] ADC_DONE
//
// Writing 1 clears EVTOAONFLAGS.ADC_DONE.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_ADC_DONE                          0x00000020
#define AUX_EVCTL_EVTOAONFLAGSCLR_ADC_DONE_BITN                              5
#define AUX_EVCTL_EVTOAONFLAGSCLR_ADC_DONE_M                        0x00000020
#define AUX_EVCTL_EVTOAONFLAGSCLR_ADC_DONE_S                                 5

// Field:     [4] AUX_COMPB
//
// Writing 1 clears EVTOAONFLAGS.AUX_COMPB.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPB                         0x00000010
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPB_BITN                             4
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPB_M                       0x00000010
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPB_S                                4

// Field:     [3] AUX_COMPA
//
// Writing 1 clears EVTOAONFLAGS.AUX_COMPA.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPA                         0x00000008
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPA_BITN                             3
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPA_M                       0x00000008
#define AUX_EVCTL_EVTOAONFLAGSCLR_AUX_COMPA_S                                3

// Field:     [2] SWEV2
//
// Writing 1 clears EVTOAONFLAGS.SWEV2.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV2                             0x00000004
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV2_BITN                                 2
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV2_M                           0x00000004
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV2_S                                    2

// Field:     [1] SWEV1
//
// Writing 1 clears EVTOAONFLAGS.SWEV1.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV1                             0x00000002
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV1_BITN                                 1
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV1_M                           0x00000002
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV1_S                                    1

// Field:     [0] SWEV0
//
// Writing 1 clears EVTOAONFLAGS.SWEV0.
//
// Read value is 0.
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV0                             0x00000001
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV0_BITN                                 0
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV0_M                           0x00000001
#define AUX_EVCTL_EVTOAONFLAGSCLR_SWEV0_S                                    0

//*****************************************************************************
//
// Register: AUX_EVCTL_O_VECFLAGSCLR
//
//*****************************************************************************
// Field:     [3] VEC3
//
// Writing 1 clears VECFLAGS.VEC3.
//
// Read value is 0.
#define AUX_EVCTL_VECFLAGSCLR_VEC3                                  0x00000008
#define AUX_EVCTL_VECFLAGSCLR_VEC3_BITN                                      3
#define AUX_EVCTL_VECFLAGSCLR_VEC3_M                                0x00000008
#define AUX_EVCTL_VECFLAGSCLR_VEC3_S                                         3

// Field:     [2] VEC2
//
// Writing 1 clears VECFLAGS.VEC2.
//
// Read value is 0.
#define AUX_EVCTL_VECFLAGSCLR_VEC2                                  0x00000004
#define AUX_EVCTL_VECFLAGSCLR_VEC2_BITN                                      2
#define AUX_EVCTL_VECFLAGSCLR_VEC2_M                                0x00000004
#define AUX_EVCTL_VECFLAGSCLR_VEC2_S                                         2

// Field:     [1] VEC1
//
// Writing 1 clears VECFLAGS.VEC1.
//
// Read value is 0.
#define AUX_EVCTL_VECFLAGSCLR_VEC1                                  0x00000002
#define AUX_EVCTL_VECFLAGSCLR_VEC1_BITN                                      1
#define AUX_EVCTL_VECFLAGSCLR_VEC1_M                                0x00000002
#define AUX_EVCTL_VECFLAGSCLR_VEC1_S                                         1

// Field:     [0] VEC0
//
// Writing 1 clears VECFLAGS.VEC0.
//
// Read value is 0.
#define AUX_EVCTL_VECFLAGSCLR_VEC0                                  0x00000001
#define AUX_EVCTL_VECFLAGSCLR_VEC0_BITN                                      0
#define AUX_EVCTL_VECFLAGSCLR_VEC0_M                                0x00000001
#define AUX_EVCTL_VECFLAGSCLR_VEC0_S                                         0


#endif // __AUX_EVCTL__
