/******************************************************************************
*  Filename:       hw_aux_timer_h
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

#ifndef __HW_AUX_TIMER_H__
#define __HW_AUX_TIMER_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AUX_TIMER component
//
//*****************************************************************************
// Timer 0 Configuration
#define AUX_TIMER_O_T0CFG                                           0x00000000

// Timer 1 Configuration
#define AUX_TIMER_O_T1CFG                                           0x00000004

// Timer 0 Control
#define AUX_TIMER_O_T0CTL                                           0x00000008

// Timer 0 Target
#define AUX_TIMER_O_T0TARGET                                        0x0000000C

// Timer 1 Target
#define AUX_TIMER_O_T1TARGET                                        0x00000010

// Timer 1 Control
#define AUX_TIMER_O_T1CTL                                           0x00000014

//*****************************************************************************
//
// Register: AUX_TIMER_O_T0CFG
//
//*****************************************************************************
// Field:    [13] TICK_SRC_POL
//
// Source count polarity for timer 0
// ENUMs:
// FALL                     Count on falling edges of TICK_SRC
// RISE                     Count on rising edges of TICK_SRC
#define AUX_TIMER_T0CFG_TICK_SRC_POL                                0x00002000
#define AUX_TIMER_T0CFG_TICK_SRC_POL_BITN                                   13
#define AUX_TIMER_T0CFG_TICK_SRC_POL_M                              0x00002000
#define AUX_TIMER_T0CFG_TICK_SRC_POL_S                                      13
#define AUX_TIMER_T0CFG_TICK_SRC_POL_FALL                           0x00002000
#define AUX_TIMER_T0CFG_TICK_SRC_POL_RISE                           0x00000000

// Field:  [12:8] TICK_SRC
//
// Selected tick source for timer 0
// ENUMs:
// ADC_IRQ                  Selects ADC_IRQ
// MCU_EVENT                Selects MCU_EV
// ACLK_REF                 Selects ACLK_REF
// AUXIO15                  Selects AUXIO15
// AUXIO14                  Selects AUXIO14
// AUXIO13                  Selects AUXIO13
// AUXIO12                  Selects AUXIO12
// AUXIO11                  Selects AUXIO11
// AUXIO10                  Selects AUXIO10
// AUXIO9                   Selects AUXIO9
// AUXIO8                   Selects AUXIO8
// AUXIO7                   Selects AUXIO7
// AUXIO6                   Selects AUXIO6
// AUXIO5                   Selects AUXIO5
// AUXIO4                   Selects AUXIO4
// AUXIO3                   Selects AUXIO3
// AUXIO2                   Selects AUXIO2
// AUXIO1                   Selects AUXIO1
// AUXIO0                   Selects AUXIO0
// AON_PROG_WU              Selects AON_PROG_WU
// AON_SW                   Selects AON_SW
// OBSMUX1                  Selects OBSMUX1
// OBSMUX0                  Selects OBSMUX0
// RTC_4KHZ                 Selects RTC_4KHZ
// ADC_DONE                 Selects ADC_DONE
// SMPH_AUTOTAKE_DONE       Selects SMPH_AUTOTAKE_DONE
// TIMER1_EV                Selects TIMER1_EV
// TDC_DONE                 Selects TDC_DONE
// AUX_COMPB                Selects AUX_COMPB
// AUX_COMPA                Selects AUX_COMPA
// RTC_CH2_EV               Selects RTC_CH2_EV
#define AUX_TIMER_T0CFG_TICK_SRC_W                                           5
#define AUX_TIMER_T0CFG_TICK_SRC_M                                  0x00001F00
#define AUX_TIMER_T0CFG_TICK_SRC_S                                           8
#define AUX_TIMER_T0CFG_TICK_SRC_ADC_IRQ                            0x00001F00
#define AUX_TIMER_T0CFG_TICK_SRC_MCU_EVENT                          0x00001E00
#define AUX_TIMER_T0CFG_TICK_SRC_ACLK_REF                           0x00001D00
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO15                            0x00001C00
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO14                            0x00001B00
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO13                            0x00001A00
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO12                            0x00001900
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO11                            0x00001800
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO10                            0x00001700
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO9                             0x00001600
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO8                             0x00001500
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO7                             0x00001400
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO6                             0x00001300
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO5                             0x00001200
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO4                             0x00001100
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO3                             0x00001000
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO2                             0x00000F00
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO1                             0x00000E00
#define AUX_TIMER_T0CFG_TICK_SRC_AUXIO0                             0x00000D00
#define AUX_TIMER_T0CFG_TICK_SRC_AON_PROG_WU                        0x00000C00
#define AUX_TIMER_T0CFG_TICK_SRC_AON_SW                             0x00000B00
#define AUX_TIMER_T0CFG_TICK_SRC_OBSMUX1                            0x00000A00
#define AUX_TIMER_T0CFG_TICK_SRC_OBSMUX0                            0x00000900
#define AUX_TIMER_T0CFG_TICK_SRC_RTC_4KHZ                           0x00000800
#define AUX_TIMER_T0CFG_TICK_SRC_ADC_DONE                           0x00000700
#define AUX_TIMER_T0CFG_TICK_SRC_SMPH_AUTOTAKE_DONE                 0x00000600
#define AUX_TIMER_T0CFG_TICK_SRC_TIMER1_EV                          0x00000500
#define AUX_TIMER_T0CFG_TICK_SRC_TDC_DONE                           0x00000300
#define AUX_TIMER_T0CFG_TICK_SRC_AUX_COMPB                          0x00000200
#define AUX_TIMER_T0CFG_TICK_SRC_AUX_COMPA                          0x00000100
#define AUX_TIMER_T0CFG_TICK_SRC_RTC_CH2_EV                         0x00000000

// Field:   [7:4] PRE
//
// Prescaler division ratio is 2^PRE
#define AUX_TIMER_T0CFG_PRE_W                                                4
#define AUX_TIMER_T0CFG_PRE_M                                       0x000000F0
#define AUX_TIMER_T0CFG_PRE_S                                                4

// Field:     [1] MODE
//
// Timer 0 mode
// ENUMs:
// TICK                     Timer 0 counter increments only on edges of the
//                          event set by TICK_SRC. The events are divided
//                          by the PRE setting.
// CLK                      Timer 0 increments on every 2^PRE edges of AUX
//                          clock
#define AUX_TIMER_T0CFG_MODE                                        0x00000002
#define AUX_TIMER_T0CFG_MODE_BITN                                            1
#define AUX_TIMER_T0CFG_MODE_M                                      0x00000002
#define AUX_TIMER_T0CFG_MODE_S                                               1
#define AUX_TIMER_T0CFG_MODE_TICK                                   0x00000002
#define AUX_TIMER_T0CFG_MODE_CLK                                    0x00000000

// Field:     [0] RELOAD
//
// Timer 0 reload setting
// ENUMs:
// CONT                     Timer is automatically restarted when target is
//                          reached
// MAN                      Timer has to be restarted manually
#define AUX_TIMER_T0CFG_RELOAD                                      0x00000001
#define AUX_TIMER_T0CFG_RELOAD_BITN                                          0
#define AUX_TIMER_T0CFG_RELOAD_M                                    0x00000001
#define AUX_TIMER_T0CFG_RELOAD_S                                             0
#define AUX_TIMER_T0CFG_RELOAD_CONT                                 0x00000001
#define AUX_TIMER_T0CFG_RELOAD_MAN                                  0x00000000

//*****************************************************************************
//
// Register: AUX_TIMER_O_T1CFG
//
//*****************************************************************************
// Field:    [13] TICK_SRC_POL
//
// Source count polarity for timer 1
// ENUMs:
// FALL                     Count on falling edges of TICK_SRC
// RISE                     Count on rising edges of TICK_SRC
#define AUX_TIMER_T1CFG_TICK_SRC_POL                                0x00002000
#define AUX_TIMER_T1CFG_TICK_SRC_POL_BITN                                   13
#define AUX_TIMER_T1CFG_TICK_SRC_POL_M                              0x00002000
#define AUX_TIMER_T1CFG_TICK_SRC_POL_S                                      13
#define AUX_TIMER_T1CFG_TICK_SRC_POL_FALL                           0x00002000
#define AUX_TIMER_T1CFG_TICK_SRC_POL_RISE                           0x00000000

// Field:  [12:8] TICK_SRC
//
// Selected tick source for timer 1
// ENUMs:
// ADC_IRQ                  Selects ADC_IRQ
// MCU_EVENT                Selects MCU_EV
// ACLK_REF                 Selects ACLK_REF
// AUXIO15                  Selects AUXIO15
// AUXIO14                  Selects AUXIO14
// AUXIO13                  Selects AUXIO13
// AUXIO12                  Selects AUXIO12
// AUXIO11                  Selects AUXIO11
// AUXIO10                  Selects AUXIO10
// AUXIO9                   Selects AUXIO9
// AUXIO8                   Selects AUXIO8
// AUXIO7                   Selects AUXIO7
// AUXIO6                   Selects AUXIO6
// AUXIO5                   Selects AUXIO5
// AUXIO4                   Selects AUXIO4
// AUXIO3                   Selects AUXIO3
// AUXIO2                   Selects AUXIO2
// AUXIO1                   Selects AUXIO1
// AUXIO0                   Selects AUXIO0
// AON_PROG_WU              Selects AON_PROG_WU
// AON_SW                   Selects AON_SW
// OBSMUX1                  Selects OBSMUX1
// OBSMUX0                  Selects OBSMUX0
// RTC_4KHZ                 Selects RTC_4KHZ
// ADC_DONE                 Selects ADC_DONE
// SMPH_AUTOTAKE_DONE       Selects SMPH_AUTOTAKE_DONE
// TIMER0_EV                Selects TIMER0_EV
// TDC_DONE                 Selects TDC_DONE
// AUX_COMPB                Selects AUX_COMPB
// AUX_COMPA                Selects AUX_COMPA
// RTC_CH2_EV               Selects RTC_CH2_EV
#define AUX_TIMER_T1CFG_TICK_SRC_W                                           5
#define AUX_TIMER_T1CFG_TICK_SRC_M                                  0x00001F00
#define AUX_TIMER_T1CFG_TICK_SRC_S                                           8
#define AUX_TIMER_T1CFG_TICK_SRC_ADC_IRQ                            0x00001F00
#define AUX_TIMER_T1CFG_TICK_SRC_MCU_EVENT                          0x00001E00
#define AUX_TIMER_T1CFG_TICK_SRC_ACLK_REF                           0x00001D00
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO15                            0x00001C00
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO14                            0x00001B00
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO13                            0x00001A00
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO12                            0x00001900
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO11                            0x00001800
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO10                            0x00001700
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO9                             0x00001600
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO8                             0x00001500
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO7                             0x00001400
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO6                             0x00001300
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO5                             0x00001200
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO4                             0x00001100
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO3                             0x00001000
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO2                             0x00000F00
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO1                             0x00000E00
#define AUX_TIMER_T1CFG_TICK_SRC_AUXIO0                             0x00000D00
#define AUX_TIMER_T1CFG_TICK_SRC_AON_PROG_WU                        0x00000C00
#define AUX_TIMER_T1CFG_TICK_SRC_AON_SW                             0x00000B00
#define AUX_TIMER_T1CFG_TICK_SRC_OBSMUX1                            0x00000A00
#define AUX_TIMER_T1CFG_TICK_SRC_OBSMUX0                            0x00000900
#define AUX_TIMER_T1CFG_TICK_SRC_RTC_4KHZ                           0x00000800
#define AUX_TIMER_T1CFG_TICK_SRC_ADC_DONE                           0x00000700
#define AUX_TIMER_T1CFG_TICK_SRC_SMPH_AUTOTAKE_DONE                 0x00000600
#define AUX_TIMER_T1CFG_TICK_SRC_TIMER0_EV                          0x00000400
#define AUX_TIMER_T1CFG_TICK_SRC_TDC_DONE                           0x00000300
#define AUX_TIMER_T1CFG_TICK_SRC_AUX_COMPB                          0x00000200
#define AUX_TIMER_T1CFG_TICK_SRC_AUX_COMPA                          0x00000100
#define AUX_TIMER_T1CFG_TICK_SRC_RTC_CH2_EV                         0x00000000

// Field:   [7:4] PRE
//
// Prescaler division ratio is 2^PRE
#define AUX_TIMER_T1CFG_PRE_W                                                4
#define AUX_TIMER_T1CFG_PRE_M                                       0x000000F0
#define AUX_TIMER_T1CFG_PRE_S                                                4

// Field:     [1] MODE
//
// Timer 1 mode
// ENUMs:
// TICK                     Timer 1 counter increments only on edges of the
//                          event set by TICK_SRC. The events are divided
//                          by the PRE setting.
// CLK                      Timer 1 increments on every 2^PRE edges of AUX
//                          clock
#define AUX_TIMER_T1CFG_MODE                                        0x00000002
#define AUX_TIMER_T1CFG_MODE_BITN                                            1
#define AUX_TIMER_T1CFG_MODE_M                                      0x00000002
#define AUX_TIMER_T1CFG_MODE_S                                               1
#define AUX_TIMER_T1CFG_MODE_TICK                                   0x00000002
#define AUX_TIMER_T1CFG_MODE_CLK                                    0x00000000

// Field:     [0] RELOAD
//
// Timer 1 reload setting
// ENUMs:
// CONT                     Timer is automatically restarted when target is
//                          reached
// MAN                      Timer has to be restarted manually
#define AUX_TIMER_T1CFG_RELOAD                                      0x00000001
#define AUX_TIMER_T1CFG_RELOAD_BITN                                          0
#define AUX_TIMER_T1CFG_RELOAD_M                                    0x00000001
#define AUX_TIMER_T1CFG_RELOAD_S                                             0
#define AUX_TIMER_T1CFG_RELOAD_CONT                                 0x00000001
#define AUX_TIMER_T1CFG_RELOAD_MAN                                  0x00000000

//*****************************************************************************
//
// Register: AUX_TIMER_O_T0CTL
//
//*****************************************************************************
// Field:     [0] EN
//
// Timer 0 run enable control. The counter restarts when enabling the timer. If
// T0CFG.RELOAD = 0, the timer is automatically disabled when reaching
// T0TARGET.VALUE
//
// 0: Disable timer 0
// 1: Enable timer 0
#define AUX_TIMER_T0CTL_EN                                          0x00000001
#define AUX_TIMER_T0CTL_EN_BITN                                              0
#define AUX_TIMER_T0CTL_EN_M                                        0x00000001
#define AUX_TIMER_T0CTL_EN_S                                                 0

//*****************************************************************************
//
// Register: AUX_TIMER_O_T0TARGET
//
//*****************************************************************************
// Field:  [15:0] VALUE
//
// Timer 0 counts from 0 to VALUE. Then gives an event and restarts if
// configured to do to so in the T0CFG.RELOAD setting. If VALUE is changed
// while timer 0 is running so that the count becomes higher than VALUE timer 0
// will also restart if configured to do so.
//
// If T0CFG.MODE=0,no prescaler is used, and VALUE equals 1, the TIMER0_EV
// event line will be always set
#define AUX_TIMER_T0TARGET_VALUE_W                                          16
#define AUX_TIMER_T0TARGET_VALUE_M                                  0x0000FFFF
#define AUX_TIMER_T0TARGET_VALUE_S                                           0

//*****************************************************************************
//
// Register: AUX_TIMER_O_T1TARGET
//
//*****************************************************************************
// Field:   [7:0] VALUE
//
// Timer 1 counts from 0 to VALUE. Then gives an event and restarts if
// configured to do to so in the T1CFG.RELOAD setting. If VALUE is changed
// while timer 1 is running so that the count becomes higher than VALUE timer 1
// will also restart if configured to do so.
//
// If T1CFG.MODE=0,no prescaler is used, and VALUE equals 1, the TIMER1_EV
// event line will be always set
#define AUX_TIMER_T1TARGET_VALUE_W                                           8
#define AUX_TIMER_T1TARGET_VALUE_M                                  0x000000FF
#define AUX_TIMER_T1TARGET_VALUE_S                                           0

//*****************************************************************************
//
// Register: AUX_TIMER_O_T1CTL
//
//*****************************************************************************
// Field:     [0] EN
//
// Timer 1 run enable control. The counter restarts when enabling the timer. If
// T1CFG.RELOAD = 0, the timer is automatically disabled when reaching
// T1TARGET.VALUE
//
// 0: Disable timer 1
// 1: Enable timer 1
#define AUX_TIMER_T1CTL_EN                                          0x00000001
#define AUX_TIMER_T1CTL_EN_BITN                                              0
#define AUX_TIMER_T1CTL_EN_M                                        0x00000001
#define AUX_TIMER_T1CTL_EN_S                                                 0


#endif // __AUX_TIMER__
