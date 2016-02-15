/******************************************************************************
*  Filename:       hw_aux_tdc_h
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

#ifndef __HW_AUX_TDC_H__
#define __HW_AUX_TDC_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AUX_TDC component
//
//*****************************************************************************
// Control
#define AUX_TDC_O_CTL                                               0x00000000

// Status
#define AUX_TDC_O_STAT                                              0x00000004

// Result
#define AUX_TDC_O_RESULT                                            0x00000008

// Saturation Configuration
#define AUX_TDC_O_SATCFG                                            0x0000000C

// Trigger Source
#define AUX_TDC_O_TRIGSRC                                           0x00000010

// Trigger Counter
#define AUX_TDC_O_TRIGCNT                                           0x00000014

// Trigger Counter Load
#define AUX_TDC_O_TRIGCNTLOAD                                       0x00000018

// Trigger Counter Configuration
#define AUX_TDC_O_TRIGCNTCFG                                        0x0000001C

// Prescaler Control
#define AUX_TDC_O_PRECTL                                            0x00000020

// Prescaler Counter
#define AUX_TDC_O_PRECNT                                            0x00000024

//*****************************************************************************
//
// Register: AUX_TDC_O_CTL
//
//*****************************************************************************
// Field:   [1:0] CMD
//
// TDC command strobes
// ENUMs:
// ABORT                    This command forces the TDC back to IDLE state
// RUN                      This command makes the TDC FSM start  and stop
//                          counting asynchronously. TDC measurement may
//                          start immediately if start is high and hence it
//                          may not give precise edge to edge measurements.
//                          Only recommended when start pulse is guaranteed
//                          to arrive at least 7 clock periods after the
//                          command
// RUN_SYNC_START           This command makes the TDC FSM start counting
//                          synchronously to the first rising edge that
//                          follows a required falling edge of the start
//                          event. This guarantees an edge triggered start
//                          and is recommended for frequency measurements.
//                          A falling edge of the start event may be missed
//                          if the command is issued close to it in time,
//                          but the TDC will catch later falling edges and
//                          guarantee that a measurement starts
//                          synchronously to the rising edge of the start
//                          event
// CLR_RESULT               This command clears STAT.SAT, STAT.DONE and
//                          results. Note: This is not needed as
//                          prerequisite for a measurement. Reliable clear
//                          is only guaranteed from IDLE state
#define AUX_TDC_CTL_CMD_W                                                    2
#define AUX_TDC_CTL_CMD_M                                           0x00000003
#define AUX_TDC_CTL_CMD_S                                                    0
#define AUX_TDC_CTL_CMD_ABORT                                       0x00000003
#define AUX_TDC_CTL_CMD_RUN                                         0x00000002
#define AUX_TDC_CTL_CMD_RUN_SYNC_START                              0x00000001
#define AUX_TDC_CTL_CMD_CLR_RESULT                                  0x00000000

//*****************************************************************************
//
// Register: AUX_TDC_O_STAT
//
//*****************************************************************************
// Field:     [7] SAT
//
// Saturation flag for TDC measurement
//
// 0: Conversion has not saturated
// 1: Conversion stopped due to saturation
//
// This field is cleared when starting new measurement or setting CTL.CMD to
// CLR_RESULT
#define AUX_TDC_STAT_SAT                                            0x00000080
#define AUX_TDC_STAT_SAT_BITN                                                7
#define AUX_TDC_STAT_SAT_M                                          0x00000080
#define AUX_TDC_STAT_SAT_S                                                   7

// Field:     [6] DONE
//
// Measurement complete flag
//
// 0: Measurement not yet complete
// 1: Measurement complete
//
// This field is cleared when starting new measurement or setting CTL.CMD to
// CLR_RESULT
#define AUX_TDC_STAT_DONE                                           0x00000040
#define AUX_TDC_STAT_DONE_BITN                                               6
#define AUX_TDC_STAT_DONE_M                                         0x00000040
#define AUX_TDC_STAT_DONE_S                                                  6

// Field:   [5:0] STATE
//
// TDC internal state machine status
// ENUMs:
// FORCE_STOP               Current state is TDC_FORCESTOP
// START_FALL               Current state is TDC_WAIT_STARTFALL
// WAIT_CLR_CNT_DONE        Current state is TDC_STATE_WAIT_CLRCNT_DONE
// POR                      Current state is TDC_STATE_POR
// GET_RESULT               Current state is TDC_STATE_GETRESULTS
// WAIT_STOP_CNTDWN         Current state is TDC_STATE_WAIT_STOPCNTDOWN
// WAIT_STOP                Current state is TDC_STATE_WAIT_STOP
// CLR_CNT                  Current state is TDC_STATE_CLRCNT
// IDLE                     Current state is TDC_STATE_IDLE
// WAIT_START_STOP_CNT_EN   Current state is TDC_STATE_WAIT_STARTSTOPCNTEN
// WAIT_START               Current state is TDC_STATE_WAIT_START
#define AUX_TDC_STAT_STATE_W                                                 6
#define AUX_TDC_STAT_STATE_M                                        0x0000003F
#define AUX_TDC_STAT_STATE_S                                                 0
#define AUX_TDC_STAT_STATE_FORCE_STOP                               0x0000002E
#define AUX_TDC_STAT_STATE_START_FALL                               0x0000001E
#define AUX_TDC_STAT_STATE_WAIT_CLR_CNT_DONE                        0x00000016
#define AUX_TDC_STAT_STATE_POR                                      0x0000000F
#define AUX_TDC_STAT_STATE_GET_RESULT                               0x0000000E
#define AUX_TDC_STAT_STATE_WAIT_STOP_CNTDWN                         0x0000000C
#define AUX_TDC_STAT_STATE_WAIT_STOP                                0x00000008
#define AUX_TDC_STAT_STATE_CLR_CNT                                  0x00000007
#define AUX_TDC_STAT_STATE_IDLE                                     0x00000006
#define AUX_TDC_STAT_STATE_WAIT_START_STOP_CNT_EN                   0x00000004
#define AUX_TDC_STAT_STATE_WAIT_START                               0x00000000

//*****************************************************************************
//
// Register: AUX_TDC_O_RESULT
//
//*****************************************************************************
// Field:  [24:0] VALUE
//
// Result of the TDC conversion. The result is in clock edges of the clock
// selected in DDI_0_OSC:CTL0.ACLK_TDC_SRC_SEL. Both rising and falling edges
// are counted.
//
// When saturating the result is slightly higher than the saturation limit,
// since it takes a non-zero time to stop the measurement. The highest
// saturation limit is 24 bits (see SATCFG.LIMIT) so maximum value of VALUE is
// hence slightly above 2^24.
#define AUX_TDC_RESULT_VALUE_W                                              25
#define AUX_TDC_RESULT_VALUE_M                                      0x01FFFFFF
#define AUX_TDC_RESULT_VALUE_S                                               0

//*****************************************************************************
//
// Register: AUX_TDC_O_SATCFG
//
//*****************************************************************************
// Field:   [3:0] LIMIT
//
// Select when the TDC times out. Values not enumerated are not supported
// ENUMs:
// R24                      Result bit 24 : TDC saturates and stops when
//                          RESULT.VALUE[24] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R23                      Result bit 23 : TDC saturates and stops when
//                          RESULT.VALUE[23] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R22                      Result bit 22 : TDC saturates and stops when
//                          RESULT.VALUE[22] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R21                      Result bit 21 : TDC saturates and stops when
//                          RESULT.VALUE[21] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R20                      Result bit 20 : TDC saturates and stops when
//                          RESULT.VALUE[20] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R19                      Result bit 19 : TDC saturates and stops when
//                          RESULT.VALUE[19] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R18                      Result bit 18 : TDC saturates and stops when
//                          RESULT.VALUE[18] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R17                      Result bit 17 : TDC saturates and stops when
//                          RESULT.VALUE[17] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R16                      Result bit 16 : TDC saturates and stops when
//                          RESULT.VALUE[16] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R15                      Result bit 15 : TDC saturates and stops when
//                          RESULT.VALUE[15] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R14                      Result bit 14 : TDC saturates and stops when
//                          RESULT.VALUE[14] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R13                      Result bit 13 : TDC saturates and stops when
//                          RESULT.VALUE[13] is set. The flag STAT.SAT is
//                          set when the timer saturates.
// R12                      Result bit 12 : TDC saturates and stops when
//                          RESULT.VALUE[12] is set. The flag STAT.SAT is
//                          set when the timer saturates.
#define AUX_TDC_SATCFG_LIMIT_W                                               4
#define AUX_TDC_SATCFG_LIMIT_M                                      0x0000000F
#define AUX_TDC_SATCFG_LIMIT_S                                               0
#define AUX_TDC_SATCFG_LIMIT_R24                                    0x0000000F
#define AUX_TDC_SATCFG_LIMIT_R23                                    0x0000000E
#define AUX_TDC_SATCFG_LIMIT_R22                                    0x0000000D
#define AUX_TDC_SATCFG_LIMIT_R21                                    0x0000000C
#define AUX_TDC_SATCFG_LIMIT_R20                                    0x0000000B
#define AUX_TDC_SATCFG_LIMIT_R19                                    0x0000000A
#define AUX_TDC_SATCFG_LIMIT_R18                                    0x00000009
#define AUX_TDC_SATCFG_LIMIT_R17                                    0x00000008
#define AUX_TDC_SATCFG_LIMIT_R16                                    0x00000007
#define AUX_TDC_SATCFG_LIMIT_R15                                    0x00000006
#define AUX_TDC_SATCFG_LIMIT_R14                                    0x00000005
#define AUX_TDC_SATCFG_LIMIT_R13                                    0x00000004
#define AUX_TDC_SATCFG_LIMIT_R12                                    0x00000003

//*****************************************************************************
//
// Register: AUX_TDC_O_TRIGSRC
//
//*****************************************************************************
// Field:    [13] STOP_POL
//
// Polarity of stop signal.   Note! Must not be changed if STAT.STATE is not
// IDLE
// ENUMs:
// LOW                      TDC stops when low level is detected
// HIGH                     TDC stops when high level is detected
#define AUX_TDC_TRIGSRC_STOP_POL                                    0x00002000
#define AUX_TDC_TRIGSRC_STOP_POL_BITN                                       13
#define AUX_TDC_TRIGSRC_STOP_POL_M                                  0x00002000
#define AUX_TDC_TRIGSRC_STOP_POL_S                                          13
#define AUX_TDC_TRIGSRC_STOP_POL_LOW                                0x00002000
#define AUX_TDC_TRIGSRC_STOP_POL_HIGH                               0x00000000

// Field:  [12:8] STOP_SRC
//
// Selects the asynchronous stop signal  Note! Must not be changed if
// STAT.STATE is not IDLE
// ENUMs:
// TDC_PRE                  Selects TDC_PRE
// MCU_EV                   Selects MCU_EV
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
// ADC_FIFO_ALMOST_FULL     Selects ADC_FIFO_ALMOST_FULL
// ADC_DONE                 Selects ADC_DONE
// SMPH_AUTOTAKE_DONE       Selects SMPH_AUTOTAKE_DONE
// TIMER1_EV                Selects TIMER1_EV
// TIMER0_EV                Selects TIMER0_EV
// ISRC_RESET               Selects ISRC_RESET
// AUX_COMPB                Selects AUX_COMPB
// AUX_COMPA                Selects AUX_COMPA
// AON_RTC_CH2              Selects AON_RTC_CH2
#define AUX_TDC_TRIGSRC_STOP_SRC_W                                           5
#define AUX_TDC_TRIGSRC_STOP_SRC_M                                  0x00001F00
#define AUX_TDC_TRIGSRC_STOP_SRC_S                                           8
#define AUX_TDC_TRIGSRC_STOP_SRC_TDC_PRE                            0x00001F00
#define AUX_TDC_TRIGSRC_STOP_SRC_MCU_EV                             0x00001E00
#define AUX_TDC_TRIGSRC_STOP_SRC_ACLK_REF                           0x00001D00
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO15                            0x00001C00
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO14                            0x00001B00
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO13                            0x00001A00
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO12                            0x00001900
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO11                            0x00001800
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO10                            0x00001700
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO9                             0x00001600
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO8                             0x00001500
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO7                             0x00001400
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO6                             0x00001300
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO5                             0x00001200
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO4                             0x00001100
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO3                             0x00001000
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO2                             0x00000F00
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO1                             0x00000E00
#define AUX_TDC_TRIGSRC_STOP_SRC_AUXIO0                             0x00000D00
#define AUX_TDC_TRIGSRC_STOP_SRC_AON_PROG_WU                        0x00000C00
#define AUX_TDC_TRIGSRC_STOP_SRC_AON_SW                             0x00000B00
#define AUX_TDC_TRIGSRC_STOP_SRC_OBSMUX1                            0x00000A00
#define AUX_TDC_TRIGSRC_STOP_SRC_OBSMUX0                            0x00000900
#define AUX_TDC_TRIGSRC_STOP_SRC_ADC_FIFO_ALMOST_FULL               0x00000800
#define AUX_TDC_TRIGSRC_STOP_SRC_ADC_DONE                           0x00000700
#define AUX_TDC_TRIGSRC_STOP_SRC_SMPH_AUTOTAKE_DONE                 0x00000600
#define AUX_TDC_TRIGSRC_STOP_SRC_TIMER1_EV                          0x00000500
#define AUX_TDC_TRIGSRC_STOP_SRC_TIMER0_EV                          0x00000400
#define AUX_TDC_TRIGSRC_STOP_SRC_ISRC_RESET                         0x00000300
#define AUX_TDC_TRIGSRC_STOP_SRC_AUX_COMPB                          0x00000200
#define AUX_TDC_TRIGSRC_STOP_SRC_AUX_COMPA                          0x00000100
#define AUX_TDC_TRIGSRC_STOP_SRC_AON_RTC_CH2                        0x00000000

// Field:     [5] START_POL
//
// Polarity of start signal.   Note! Must not be changed if STAT.STATE is not
// IDLE
// ENUMs:
// LOW                      TDC starts when low level is detected
// HIGH                     TDC starts when high level is detected
#define AUX_TDC_TRIGSRC_START_POL                                   0x00000020
#define AUX_TDC_TRIGSRC_START_POL_BITN                                       5
#define AUX_TDC_TRIGSRC_START_POL_M                                 0x00000020
#define AUX_TDC_TRIGSRC_START_POL_S                                          5
#define AUX_TDC_TRIGSRC_START_POL_LOW                               0x00000020
#define AUX_TDC_TRIGSRC_START_POL_HIGH                              0x00000000

// Field:   [4:0] START_SRC
//
// Selects the asynchronous start signal Note! Must not be changed if
// STAT.STATE is not IDLE
// ENUMs:
// TDC_PRE                  Selects TDC_PRE
// MCU_EV                   Selects MCU_EV
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
// ADC_FIFO_ALMOST_FULL     Selects ADC_FIFO_ALMOST_FULL
// ADC_DONE                 Selects ADC_DONE
// SMPH_AUTOTAKE_DONE       Selects SMPH_AUTOTAKE_DONE
// TIMER1_EV                Selects TIMER1_EV
// TIMER0_EV                Selects TIMER0_EV
// ISRC_RESET               Selects ISRC_RESET
// AUX_COMPB                Selects AUX_COMPB
// AUX_COMPA                Selects AUX_COMPA
// AON_RTC_CH2              Selects AON_RTC_CH2
#define AUX_TDC_TRIGSRC_START_SRC_W                                          5
#define AUX_TDC_TRIGSRC_START_SRC_M                                 0x0000001F
#define AUX_TDC_TRIGSRC_START_SRC_S                                          0
#define AUX_TDC_TRIGSRC_START_SRC_TDC_PRE                           0x0000001F
#define AUX_TDC_TRIGSRC_START_SRC_MCU_EV                            0x0000001E
#define AUX_TDC_TRIGSRC_START_SRC_ACLK_REF                          0x0000001D
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO15                           0x0000001C
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO14                           0x0000001B
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO13                           0x0000001A
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO12                           0x00000019
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO11                           0x00000018
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO10                           0x00000017
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO9                            0x00000016
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO8                            0x00000015
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO7                            0x00000014
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO6                            0x00000013
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO5                            0x00000012
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO4                            0x00000011
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO3                            0x00000010
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO2                            0x0000000F
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO1                            0x0000000E
#define AUX_TDC_TRIGSRC_START_SRC_AUXIO0                            0x0000000D
#define AUX_TDC_TRIGSRC_START_SRC_AON_PROG_WU                       0x0000000C
#define AUX_TDC_TRIGSRC_START_SRC_AON_SW                            0x0000000B
#define AUX_TDC_TRIGSRC_START_SRC_OBSMUX1                           0x0000000A
#define AUX_TDC_TRIGSRC_START_SRC_OBSMUX0                           0x00000009
#define AUX_TDC_TRIGSRC_START_SRC_ADC_FIFO_ALMOST_FULL              0x00000008
#define AUX_TDC_TRIGSRC_START_SRC_ADC_DONE                          0x00000007
#define AUX_TDC_TRIGSRC_START_SRC_SMPH_AUTOTAKE_DONE                0x00000006
#define AUX_TDC_TRIGSRC_START_SRC_TIMER1_EV                         0x00000005
#define AUX_TDC_TRIGSRC_START_SRC_TIMER0_EV                         0x00000004
#define AUX_TDC_TRIGSRC_START_SRC_ISRC_RESET                        0x00000003
#define AUX_TDC_TRIGSRC_START_SRC_AUX_COMPB                         0x00000002
#define AUX_TDC_TRIGSRC_START_SRC_AUX_COMPA                         0x00000001
#define AUX_TDC_TRIGSRC_START_SRC_AON_RTC_CH2                       0x00000000

//*****************************************************************************
//
// Register: AUX_TDC_O_TRIGCNT
//
//*****************************************************************************
// Field:  [15:0] CNT
//
// Remaining number of stop events that will be ignored. Writing to this
// register updates the  value. The CNT will be loaded with the value of
// TRIGCNTLOAD.CNT at the start of every measurement.
//
// When the stop counter is enabled the first CNT-1 stop events is ignored
// after which the TDC will stop measurement on event number CNT
//
// Note! Must not be changed if STAT.STATE is not IDLE
#define AUX_TDC_TRIGCNT_CNT_W                                               16
#define AUX_TDC_TRIGCNT_CNT_M                                       0x0000FFFF
#define AUX_TDC_TRIGCNT_CNT_S                                                0

//*****************************************************************************
//
// Register: AUX_TDC_O_TRIGCNTLOAD
//
//*****************************************************************************
// Field:  [15:0] CNT
//
// Selects the number of stop events that will be ignored by the TDC. This can
// be used to measure multiple periods of a clock signal. The value written to
// this field is loaded into the stop counter at the start of each measurement.
//
// Note! Both values 0 and 1 will make the TDC stop on the first event after
// the start event
//
// Note! Must not be changed if STAT.STATE is not IDLE
#define AUX_TDC_TRIGCNTLOAD_CNT_W                                           16
#define AUX_TDC_TRIGCNTLOAD_CNT_M                                   0x0000FFFF
#define AUX_TDC_TRIGCNTLOAD_CNT_S                                            0

//*****************************************************************************
//
// Register: AUX_TDC_O_TRIGCNTCFG
//
//*****************************************************************************
// Field:     [0] EN
//
// Stop counter enable
//
// 0: Stop counter is disabled
// 1: Stop counter is enabled
#define AUX_TDC_TRIGCNTCFG_EN                                       0x00000001
#define AUX_TDC_TRIGCNTCFG_EN_BITN                                           0
#define AUX_TDC_TRIGCNTCFG_EN_M                                     0x00000001
#define AUX_TDC_TRIGCNTCFG_EN_S                                              0

//*****************************************************************************
//
// Register: AUX_TDC_O_PRECTL
//
//*****************************************************************************
// Field:     [7] RESET_N
//
// Prescaler reset control
//
// 0: Prescaler is held in reset
// 1: Prescaler is not held in reset
#define AUX_TDC_PRECTL_RESET_N                                      0x00000080
#define AUX_TDC_PRECTL_RESET_N_BITN                                          7
#define AUX_TDC_PRECTL_RESET_N_M                                    0x00000080
#define AUX_TDC_PRECTL_RESET_N_S                                             7

// Field:     [6] RATIO
//
// Prescaler ratio. This controls how often an event is generated on the
// TDC_PRE line. After the prescaler is reset the event output TDC_PRE is 0.
// ENUMs:
// DIV64                    Prescaler divides by 64. A rising edge on the
//                          output is generated for every 64 rising edges
//                          of the input (the output toggles on every 32th
//                          rising edge of the input). .
// DIV16                    Prescaler divides by 16. A rising edge on the
//                          output is generated for every 16 rising edges
//                          of the input (the output toggles on every 8th
//                          rising edge of the input).
#define AUX_TDC_PRECTL_RATIO                                        0x00000040
#define AUX_TDC_PRECTL_RATIO_BITN                                            6
#define AUX_TDC_PRECTL_RATIO_M                                      0x00000040
#define AUX_TDC_PRECTL_RATIO_S                                               6
#define AUX_TDC_PRECTL_RATIO_DIV64                                  0x00000040
#define AUX_TDC_PRECTL_RATIO_DIV16                                  0x00000000

// Field:   [4:0] SRC
//
// Selects event for prescaler to use as input
// Note! Only change when prescaler is in reset
// ENUMs:
// ADC_IRQ
// MCU_EV
// ACLK_REF
// AUXIO15
// AUXIO14
// AUXIO13
// AUXIO12
// AUXIO11
// AUXIO10
// AUXIO9
// AUXIO8
// AUXIO7
// AUXIO6
// AUXIO5
// AUXIO4
// AUXIO3
// AUXIO2
// AUXIO1
// AUXIO0
// AON_PROG_WU
// AON_SW
// OBSMUX1
// OBSMUX0
// ADC_FIFO_ALMOST_FULL
// ADC_DONE
// SMPH_AUTOTAKE_DONE
// TIMER1_EV
// TIMER0_EV
// ISRC_RESET
// AUX_COMPB
// AUX_COMPA
// AON_RTC_CH2
#define AUX_TDC_PRECTL_SRC_W                                                 5
#define AUX_TDC_PRECTL_SRC_M                                        0x0000001F
#define AUX_TDC_PRECTL_SRC_S                                                 0
#define AUX_TDC_PRECTL_SRC_ADC_IRQ                                  0x0000001F
#define AUX_TDC_PRECTL_SRC_MCU_EV                                   0x0000001E
#define AUX_TDC_PRECTL_SRC_ACLK_REF                                 0x0000001D
#define AUX_TDC_PRECTL_SRC_AUXIO15                                  0x0000001C
#define AUX_TDC_PRECTL_SRC_AUXIO14                                  0x0000001B
#define AUX_TDC_PRECTL_SRC_AUXIO13                                  0x0000001A
#define AUX_TDC_PRECTL_SRC_AUXIO12                                  0x00000019
#define AUX_TDC_PRECTL_SRC_AUXIO11                                  0x00000018
#define AUX_TDC_PRECTL_SRC_AUXIO10                                  0x00000017
#define AUX_TDC_PRECTL_SRC_AUXIO9                                   0x00000016
#define AUX_TDC_PRECTL_SRC_AUXIO8                                   0x00000015
#define AUX_TDC_PRECTL_SRC_AUXIO7                                   0x00000014
#define AUX_TDC_PRECTL_SRC_AUXIO6                                   0x00000013
#define AUX_TDC_PRECTL_SRC_AUXIO5                                   0x00000012
#define AUX_TDC_PRECTL_SRC_AUXIO4                                   0x00000011
#define AUX_TDC_PRECTL_SRC_AUXIO3                                   0x00000010
#define AUX_TDC_PRECTL_SRC_AUXIO2                                   0x0000000F
#define AUX_TDC_PRECTL_SRC_AUXIO1                                   0x0000000E
#define AUX_TDC_PRECTL_SRC_AUXIO0                                   0x0000000D
#define AUX_TDC_PRECTL_SRC_AON_PROG_WU                              0x0000000C
#define AUX_TDC_PRECTL_SRC_AON_SW                                   0x0000000B
#define AUX_TDC_PRECTL_SRC_OBSMUX1                                  0x0000000A
#define AUX_TDC_PRECTL_SRC_OBSMUX0                                  0x00000009
#define AUX_TDC_PRECTL_SRC_ADC_FIFO_ALMOST_FULL                     0x00000008
#define AUX_TDC_PRECTL_SRC_ADC_DONE                                 0x00000007
#define AUX_TDC_PRECTL_SRC_SMPH_AUTOTAKE_DONE                       0x00000006
#define AUX_TDC_PRECTL_SRC_TIMER1_EV                                0x00000005
#define AUX_TDC_PRECTL_SRC_TIMER0_EV                                0x00000004
#define AUX_TDC_PRECTL_SRC_ISRC_RESET                               0x00000003
#define AUX_TDC_PRECTL_SRC_AUX_COMPB                                0x00000002
#define AUX_TDC_PRECTL_SRC_AUX_COMPA                                0x00000001
#define AUX_TDC_PRECTL_SRC_AON_RTC_CH2                              0x00000000

//*****************************************************************************
//
// Register: AUX_TDC_O_PRECNT
//
//*****************************************************************************
// Field:  [15:0] CNT
//
// Writing to this register will latch the contents of the 16 bit prescaler
// counter (The value written is don't care).
//
// Reading will return the latched value.
#define AUX_TDC_PRECNT_CNT_W                                                16
#define AUX_TDC_PRECNT_CNT_M                                        0x0000FFFF
#define AUX_TDC_PRECNT_CNT_S                                                 0


#endif // __AUX_TDC__
