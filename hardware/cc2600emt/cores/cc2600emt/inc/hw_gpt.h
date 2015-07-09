/******************************************************************************
*  Filename:       hw_gpt_h
*  Revised:        2015-03-24 13:39:29 +0100 (ti, 24 mar 2015)
*  Revision:       43111
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

#ifndef __HW_GPT_H__
#define __HW_GPT_H__

//*****************************************************************************
//
// This section defines the register offsets of
// GPT component
//
//*****************************************************************************
// Configuration
#define GPT_O_CFG                                                   0x00000000

// Timer A Mode
#define GPT_O_TAMR                                                  0x00000004

// Timer B Mode
#define GPT_O_TBMR                                                  0x00000008

// Control
#define GPT_O_CTL                                                   0x0000000C

// Synch Register
#define GPT_O_SYNC                                                  0x00000010

// Interrupt Mask
#define GPT_O_IMR                                                   0x00000018

// Raw Interrupt Status
#define GPT_O_RIS                                                   0x0000001C

// Masked Interrupt Status
#define GPT_O_MIS                                                   0x00000020

// Interrupt Clear
#define GPT_O_ICLR                                                  0x00000024

// Timer A Interval Load  Register
#define GPT_O_TAILR                                                 0x00000028

// Timer B Interval Load  Register
#define GPT_O_TBILR                                                 0x0000002C

// Timer A Match Register
#define GPT_O_TAMATCHR                                              0x00000030

// Timer B Match Register
#define GPT_O_TBMATCHR                                              0x00000034

// Timer A Pre-scale
#define GPT_O_TAPR                                                  0x00000038

// Timer B Pre-scale
#define GPT_O_TBPR                                                  0x0000003C

// Timer A Pre-scale Match
#define GPT_O_TAPMR                                                 0x00000040

// Timer B Pre-scale Match
#define GPT_O_TBPMR                                                 0x00000044

// Timer A Register
#define GPT_O_TAR                                                   0x00000048

// Timer B Register
#define GPT_O_TBR                                                   0x0000004C

// Timer A Value
#define GPT_O_TAV                                                   0x00000050

// Timer B Value
#define GPT_O_TBV                                                   0x00000054

// RTC Pre-divide Value
#define GPT_O_RTCPD                                                 0x00000058

// Timer A Pre-scale Snap-shot
#define GPT_O_TAPS                                                  0x0000005C

// Timer A Pre-scale Snap-shot
#define GPT_O_TBPS                                                  0x00000060

// Timer A Pre-scale Value
#define GPT_O_TAPV                                                  0x00000064

// Timer B Pre-scale Value
#define GPT_O_TBPV                                                  0x00000068

// DMA Event
#define GPT_O_DMAEV                                                 0x0000006C

// ADC Event
#define GPT_O_ADCEV                                                 0x00000070

// Peripheral Version
#define GPT_O_VERSION                                               0x00000FB0

// Combined CCP Output
#define GPT_O_ANDCCP                                                0x00000FB4

//*****************************************************************************
//
// Register: GPT_O_CFG
//
//*****************************************************************************
// Field:   [2:0] CFG
//
// GPT Configuration
// 0x2- 0x3 - Reserved
// 0x5- 0x7 - Reserved
// ENUMs:
// 16BIT_TIMER              16-bit timer configuration.
// Configure for two 16-bit timers.
// Also see TAMR.TAMR and TBMR.TBMR.
// REALTIME_CLOCK           32-bit real-time clock
// 32BIT_TIMER              32-bit timer configuration
#define GPT_CFG_CFG_M                                               0x00000007
#define GPT_CFG_CFG_S                                                        0
#define GPT_CFG_CFG_16BIT_TIMER                                     0x00000004
#define GPT_CFG_CFG_REALTIME_CLOCK                                  0x00000001
#define GPT_CFG_CFG_32BIT_TIMER                                     0x00000000

//*****************************************************************************
//
// Register: GPT_O_TAMR
//
//*****************************************************************************
// Field: [15:13] TCACT
//
// Timer Compare Action Select
// ENUMs:
// CLRSET_ON_TO             Clear CCP output pin immediately and set on
// Time-Out
// SETCLR_ON_TO             Set CCP output pin immediately and clear on
// Time-Out
// CLRTOG_ON_TO             Clear CCP output pin immediately and toggle on
// Time-Out
// SETTOG_ON_TO             Set CCP output pin immediately and toggle on
// Time-Out
// SET_ON_TO                Set CCP output pin on Time-Out
// CLR_ON_TO                Clear CCP output pin on Time-Out
// TOG_ON_TO                Toggle State on Time-Out
// DIS_CMP                  Disable compare operations
#define GPT_TAMR_TCACT_M                                            0x0000E000
#define GPT_TAMR_TCACT_S                                                    13
#define GPT_TAMR_TCACT_CLRSET_ON_TO                                 0x0000E000
#define GPT_TAMR_TCACT_SETCLR_ON_TO                                 0x0000C000
#define GPT_TAMR_TCACT_CLRTOG_ON_TO                                 0x0000A000
#define GPT_TAMR_TCACT_SETTOG_ON_TO                                 0x00008000
#define GPT_TAMR_TCACT_SET_ON_TO                                    0x00006000
#define GPT_TAMR_TCACT_CLR_ON_TO                                    0x00004000
#define GPT_TAMR_TCACT_TOG_ON_TO                                    0x00002000
#define GPT_TAMR_TCACT_DIS_CMP                                      0x00000000

// Field:    [12] TACINTD
//
// One-Shot/Periodic Interrupt Disable
// ENUMs:
// DIS_TO_INTR              Time-out interrupt are disabled
// EN_TO_INTR               Time-out interrupt function as normal
#define GPT_TAMR_TACINTD                                            0x00001000
#define GPT_TAMR_TACINTD_BITN                                               12
#define GPT_TAMR_TACINTD_M                                          0x00001000
#define GPT_TAMR_TACINTD_S                                                  12
#define GPT_TAMR_TACINTD_DIS_TO_INTR                                0x00001000
#define GPT_TAMR_TACINTD_EN_TO_INTR                                 0x00000000

// Field:    [11] TAPLO
//
// Legacy PWM operation
// ENUMs:
// CCP_ON_TO                CCP output pin is set to 1 on time-out
// LEGACY                   Legacy operation
#define GPT_TAMR_TAPLO                                              0x00000800
#define GPT_TAMR_TAPLO_BITN                                                 11
#define GPT_TAMR_TAPLO_M                                            0x00000800
#define GPT_TAMR_TAPLO_S                                                    11
#define GPT_TAMR_TAPLO_CCP_ON_TO                                    0x00000800
#define GPT_TAMR_TAPLO_LEGACY                                       0x00000000

// Field:    [10] TAMRSU
//
// Timer A Match Register Update mode
//
// If the timer is disabled (CTL.TAEN = 0) when this bit is set, TAMATCHR and
// TAPR are updated when the timer is enabled. If the timer is stalled
// (CTL.TASTALL is set), TAMATCHR and TAPR are updated according to the
// configuration of this bit.
// ENUMs:
// TOUPDATE                 Update TAMATCHR and TAPR, if used, on the next
// time-out.
// CYCLEUPDATE              Update TAMATCHR and TAPR, if used, on the next
// cycle.
#define GPT_TAMR_TAMRSU                                             0x00000400
#define GPT_TAMR_TAMRSU_BITN                                                10
#define GPT_TAMR_TAMRSU_M                                           0x00000400
#define GPT_TAMR_TAMRSU_S                                                   10
#define GPT_TAMR_TAMRSU_TOUPDATE                                    0x00000400
#define GPT_TAMR_TAMRSU_CYCLEUPDATE                                 0x00000000

// Field:     [9] TAPWMIE
//
// GPT Timer A PWM Interrupt Enable This bit enables interrupts in PWM mode on
// rising, falling, or both edges of the CCP output.
// ENUMs:
// EN                       Interrupt is enabled.  This bit is only valid in
// PWM mode.
// DIS                      Interrupt is disabled.
#define GPT_TAMR_TAPWMIE                                            0x00000200
#define GPT_TAMR_TAPWMIE_BITN                                                9
#define GPT_TAMR_TAPWMIE_M                                          0x00000200
#define GPT_TAMR_TAPWMIE_S                                                   9
#define GPT_TAMR_TAPWMIE_EN                                         0x00000200
#define GPT_TAMR_TAPWMIE_DIS                                        0x00000000

// Field:     [8] TAILD
//
// GPT Timer A PWM Interval Load Write
// ENUMs:
// TOUPDATE                 Update the TAR register with the value in the TAILR
// register on the next timeout. If the prescaler is used, update the TAPS
// register with the value in the TAPR register on the next timeout.
// CYCLEUPDATE              Update the TAR register with the value in the TAILR
// register on the next clock cycle. If the pre-scaler is used, update the TAPS
// register with the value in the TAPR register on the next clock cycle.
#define GPT_TAMR_TAILD                                              0x00000100
#define GPT_TAMR_TAILD_BITN                                                  8
#define GPT_TAMR_TAILD_M                                            0x00000100
#define GPT_TAMR_TAILD_S                                                     8
#define GPT_TAMR_TAILD_TOUPDATE                                     0x00000100
#define GPT_TAMR_TAILD_CYCLEUPDATE                                  0x00000000

// Field:     [7] TASNAPS
//
// GPT Timer A Snap-Shot Mode
// ENUMs:
// EN                       If Timer A is configured in the periodic mode, the
// actual free-running value of Timer A is loaded at the time-out event into
// the GPT Timer A (TAR) register.
// DIS                      Snap-shot mode is disabled.
#define GPT_TAMR_TASNAPS                                            0x00000080
#define GPT_TAMR_TASNAPS_BITN                                                7
#define GPT_TAMR_TASNAPS_M                                          0x00000080
#define GPT_TAMR_TASNAPS_S                                                   7
#define GPT_TAMR_TASNAPS_EN                                         0x00000080
#define GPT_TAMR_TASNAPS_DIS                                        0x00000000

// Field:     [6] TAWOT
//
// GPT Timer A Wait-On-Trigger
// ENUMs:
// WAIT                     If Timer A is enabled (CTL.TAEN = 1), Timer A does
// not begin counting until it receives a trigger from the timer in the
// previous position in the daisy chain. This bit must be clear for GPT Module
// 0, Timer A
// NOWAIT                   Timer A begins counting as soon as it is enabled.
#define GPT_TAMR_TAWOT                                              0x00000040
#define GPT_TAMR_TAWOT_BITN                                                  6
#define GPT_TAMR_TAWOT_M                                            0x00000040
#define GPT_TAMR_TAWOT_S                                                     6
#define GPT_TAMR_TAWOT_WAIT                                         0x00000040
#define GPT_TAMR_TAWOT_NOWAIT                                       0x00000000

// Field:     [5] TAMIE
//
// GPT Timer A Match Interrupt Enable
// ENUMs:
// EN                       An interrupt is generated when the match value in
// TAMATCHR is reached in the one-shot and periodic modes.
// DIS                      The match interrupt is disabled for match events.
// Additionally, triggers to the DMA and ADC on match events are prevented
#define GPT_TAMR_TAMIE                                              0x00000020
#define GPT_TAMR_TAMIE_BITN                                                  5
#define GPT_TAMR_TAMIE_M                                            0x00000020
#define GPT_TAMR_TAMIE_S                                                     5
#define GPT_TAMR_TAMIE_EN                                           0x00000020
#define GPT_TAMR_TAMIE_DIS                                          0x00000000

// Field:     [4] TACDIR
//
// GPT Timer A Count Direction
// ENUMs:
// UP                       The timer counts up. When counting up, the timer
// starts from a value of 0x0.
// DOWN                     The timer counts down.
#define GPT_TAMR_TACDIR                                             0x00000010
#define GPT_TAMR_TACDIR_BITN                                                 4
#define GPT_TAMR_TACDIR_M                                           0x00000010
#define GPT_TAMR_TACDIR_S                                                    4
#define GPT_TAMR_TACDIR_UP                                          0x00000010
#define GPT_TAMR_TACDIR_DOWN                                        0x00000000

// Field:     [3] TAAMS
//
// GPT Timer A Alternate Mode
//
// Note: To enable PWM mode, you must also clear TACM and then configure TAMR
// field to 0x2.
// ENUMs:
// PWM                      PWM mode is enabled
// CAP_COMP                 Capture/Compare mode is enabled.
#define GPT_TAMR_TAAMS                                              0x00000008
#define GPT_TAMR_TAAMS_BITN                                                  3
#define GPT_TAMR_TAAMS_M                                            0x00000008
#define GPT_TAMR_TAAMS_S                                                     3
#define GPT_TAMR_TAAMS_PWM                                          0x00000008
#define GPT_TAMR_TAAMS_CAP_COMP                                     0x00000000

// Field:     [2] TACM
//
// GPT Timer A Capture Mode
// ENUMs:
// EDGTIME                  Edge-Time mode
// EDGCNT                   Edge-Count mode
#define GPT_TAMR_TACM                                               0x00000004
#define GPT_TAMR_TACM_BITN                                                   2
#define GPT_TAMR_TACM_M                                             0x00000004
#define GPT_TAMR_TACM_S                                                      2
#define GPT_TAMR_TACM_EDGTIME                                       0x00000004
#define GPT_TAMR_TACM_EDGCNT                                        0x00000000

// Field:   [1:0] TAMR
//
// GPT Timer A Mode
//
// The Timer mode is based on the timer configuration defined by CFG
// ENUMs:
// CAPTURE                  Capture mode
// PERIODIC                 Periodic Timer mode
// ONE_SHOT                 One-Shot Timer mode
#define GPT_TAMR_TAMR_M                                             0x00000003
#define GPT_TAMR_TAMR_S                                                      0
#define GPT_TAMR_TAMR_CAPTURE                                       0x00000003
#define GPT_TAMR_TAMR_PERIODIC                                      0x00000002
#define GPT_TAMR_TAMR_ONE_SHOT                                      0x00000001

//*****************************************************************************
//
// Register: GPT_O_TBMR
//
//*****************************************************************************
// Field: [15:13] TCACT
//
// Timer Compare Action Select
// ENUMs:
// CLRSET_ON_TO             Clear CCP output pin immediately and set on
// Time-Out
// SETCLR_ON_TO             Set CCP output pin immediately and clear on
// Time-Out
// CLRTOG_ON_TO             Clear CCP output pin immediately and toggle on
// Time-Out
// SETTOG_ON_TO             Set CCP output pin immediately and toggle on
// Time-Out
// SET_ON_TO                Set CCP output pin on Time-Out
// CLR_ON_TO                Clear CCP output pin on Time-Out
// TOG_ON_TO                Toggle State on Time-Out
// DIS_CMP                  Disable compare operations
#define GPT_TBMR_TCACT_M                                            0x0000E000
#define GPT_TBMR_TCACT_S                                                    13
#define GPT_TBMR_TCACT_CLRSET_ON_TO                                 0x0000E000
#define GPT_TBMR_TCACT_SETCLR_ON_TO                                 0x0000C000
#define GPT_TBMR_TCACT_CLRTOG_ON_TO                                 0x0000A000
#define GPT_TBMR_TCACT_SETTOG_ON_TO                                 0x00008000
#define GPT_TBMR_TCACT_SET_ON_TO                                    0x00006000
#define GPT_TBMR_TCACT_CLR_ON_TO                                    0x00004000
#define GPT_TBMR_TCACT_TOG_ON_TO                                    0x00002000
#define GPT_TBMR_TCACT_DIS_CMP                                      0x00000000

// Field:    [12] TBCINTD
//
// One-Shot/Periodic Interrupt Mode
// ENUMs:
// DIS_TO_INTR              Mask Time-Out Interrupt
// EN_TO_INTR               Normal Time-Out Interrupt
#define GPT_TBMR_TBCINTD                                            0x00001000
#define GPT_TBMR_TBCINTD_BITN                                               12
#define GPT_TBMR_TBCINTD_M                                          0x00001000
#define GPT_TBMR_TBCINTD_S                                                  12
#define GPT_TBMR_TBCINTD_DIS_TO_INTR                                0x00001000
#define GPT_TBMR_TBCINTD_EN_TO_INTR                                 0x00000000

// Field:    [11] TBPLO
//
// Legacy PWM operation
// ENUMs:
// CCP_ON_TO                CCP output pin is set to 1 on time-out
// LEGACY                   Legacy operation
#define GPT_TBMR_TBPLO                                              0x00000800
#define GPT_TBMR_TBPLO_BITN                                                 11
#define GPT_TBMR_TBPLO_M                                            0x00000800
#define GPT_TBMR_TBPLO_S                                                    11
#define GPT_TBMR_TBPLO_CCP_ON_TO                                    0x00000800
#define GPT_TBMR_TBPLO_LEGACY                                       0x00000000

// Field:    [10] TBMRSU
//
// Timer B Match Register Update mode
//
// If the timer is disabled (CTL.TBEN is clear) when this bit is set, TBMATCHR
// and TBPR are updated when the timer is enabled. If the timer is stalled
// (CTL.TBSTALL is set), TBMATCHR and TBPR are updated according to the
// configuration of this bit.
// ENUMs:
// TOUPDATE                 Update the TBMATCHR and the TBPR, if used on the
// next time-out.
// CYCLEUPDATE              Update TBMATCHR and TBPR, if used on the next
// cycle.
#define GPT_TBMR_TBMRSU                                             0x00000400
#define GPT_TBMR_TBMRSU_BITN                                                10
#define GPT_TBMR_TBMRSU_M                                           0x00000400
#define GPT_TBMR_TBMRSU_S                                                   10
#define GPT_TBMR_TBMRSU_TOUPDATE                                    0x00000400
#define GPT_TBMR_TBMRSU_CYCLEUPDATE                                 0x00000000

// Field:     [9] TBPWMIE
//
// GPT Timer B PWM Interrupt Enable This bit enables interrupts in PWM mode on
// rising, falling, or both edges of the CCP output
// ENUMs:
// EN                       Interrupt is enabled.  This bit is only valid in
// PWM mode.
// DIS                      Interrupt is disabled.
#define GPT_TBMR_TBPWMIE                                            0x00000200
#define GPT_TBMR_TBPWMIE_BITN                                                9
#define GPT_TBMR_TBPWMIE_M                                          0x00000200
#define GPT_TBMR_TBPWMIE_S                                                   9
#define GPT_TBMR_TBPWMIE_EN                                         0x00000200
#define GPT_TBMR_TBPWMIE_DIS                                        0x00000000

// Field:     [8] TBILD
//
// GPT Timer B PWM Interval Load Write
// ENUMs:
// TOUPDATE                 Update the TBR register with the value in the TBILR
// register on the next timeout. If the prescaler is used, update the TBPS
// register with the value in the TBPR register on the next timeout.
// CYCLEUPDATE              Update the TBR register with the value in the TBILR
// register on the next clock cycle. If the pre-scaler is used, update the TBPS
// register with the value in the TBPR register on the next clock cycle.
#define GPT_TBMR_TBILD                                              0x00000100
#define GPT_TBMR_TBILD_BITN                                                  8
#define GPT_TBMR_TBILD_M                                            0x00000100
#define GPT_TBMR_TBILD_S                                                     8
#define GPT_TBMR_TBILD_TOUPDATE                                     0x00000100
#define GPT_TBMR_TBILD_CYCLEUPDATE                                  0x00000000

// Field:     [7] TBSNAPS
//
// GPT Timer B Snap-Shot Mode
// ENUMs:
// EN                       If Timer B is configured in the periodic mode
// DIS                      Snap-shot mode is disabled.
#define GPT_TBMR_TBSNAPS                                            0x00000080
#define GPT_TBMR_TBSNAPS_BITN                                                7
#define GPT_TBMR_TBSNAPS_M                                          0x00000080
#define GPT_TBMR_TBSNAPS_S                                                   7
#define GPT_TBMR_TBSNAPS_EN                                         0x00000080
#define GPT_TBMR_TBSNAPS_DIS                                        0x00000000

// Field:     [6] TBWOT
//
// GPT Timer B Wait-On-Trigger
// ENUMs:
// WAIT                     If Timer B is enabled (CTL.TBEN is set), Timer B
// does not begin counting until it receives a trigger from the timer in the
// previous position in the daisy chain.
// NOWAIT                   Timer B begins counting as soon as it is enabled.
#define GPT_TBMR_TBWOT                                              0x00000040
#define GPT_TBMR_TBWOT_BITN                                                  6
#define GPT_TBMR_TBWOT_M                                            0x00000040
#define GPT_TBMR_TBWOT_S                                                     6
#define GPT_TBMR_TBWOT_WAIT                                         0x00000040
#define GPT_TBMR_TBWOT_NOWAIT                                       0x00000000

// Field:     [5] TBMIE
//
// GPT Timer B Match Interrupt Enable.
// ENUMs:
// EN                       An interrupt is generated when the match value in
// the TBMATCHR register is reached in the one-shot and periodic modes.
// DIS                      The match interrupt is disabled for match events.
// Additionally, triggers to the DMA and ADC on match events are prevented
#define GPT_TBMR_TBMIE                                              0x00000020
#define GPT_TBMR_TBMIE_BITN                                                  5
#define GPT_TBMR_TBMIE_M                                            0x00000020
#define GPT_TBMR_TBMIE_S                                                     5
#define GPT_TBMR_TBMIE_EN                                           0x00000020
#define GPT_TBMR_TBMIE_DIS                                          0x00000000

// Field:     [4] TBCDIR
//
// GPT Timer B Count Direction
// ENUMs:
// UP                       The timer counts up. When counting up, the timer
// starts from a value of 0x0.
// DOWN                     The timer counts down.
#define GPT_TBMR_TBCDIR                                             0x00000010
#define GPT_TBMR_TBCDIR_BITN                                                 4
#define GPT_TBMR_TBCDIR_M                                           0x00000010
#define GPT_TBMR_TBCDIR_S                                                    4
#define GPT_TBMR_TBCDIR_UP                                          0x00000010
#define GPT_TBMR_TBCDIR_DOWN                                        0x00000000

// Field:     [3] TBAMS
//
// GPT Timer B Alternate Mode
//
// Note: To enable PWM mode, you must also clear TBCM bit and configure TBMR
// field to 0x2.
// ENUMs:
// PWM                      PWM mode is enabled
// CAP_COMP                 Capture/Compare mode is enabled.
#define GPT_TBMR_TBAMS                                              0x00000008
#define GPT_TBMR_TBAMS_BITN                                                  3
#define GPT_TBMR_TBAMS_M                                            0x00000008
#define GPT_TBMR_TBAMS_S                                                     3
#define GPT_TBMR_TBAMS_PWM                                          0x00000008
#define GPT_TBMR_TBAMS_CAP_COMP                                     0x00000000

// Field:     [2] TBCM
//
// GPT Timer B Capture Mode
// ENUMs:
// EDGTIME                  Edge-Time mode
// EDGCNT                   Edge-Count mode
#define GPT_TBMR_TBCM                                               0x00000004
#define GPT_TBMR_TBCM_BITN                                                   2
#define GPT_TBMR_TBCM_M                                             0x00000004
#define GPT_TBMR_TBCM_S                                                      2
#define GPT_TBMR_TBCM_EDGTIME                                       0x00000004
#define GPT_TBMR_TBCM_EDGCNT                                        0x00000000

// Field:   [1:0] TBMR
//
// GPT Timer B Mode
//
// The Timer mode is based on the timer configuration defined by CFG.CFG
// ENUMs:
// CAPTURE                  Capture mode
// PERIODIC                 Periodic Timer mode
// ONE_SHOT                 One-Shot Timer mode
#define GPT_TBMR_TBMR_M                                             0x00000003
#define GPT_TBMR_TBMR_S                                                      0
#define GPT_TBMR_TBMR_CAPTURE                                       0x00000003
#define GPT_TBMR_TBMR_PERIODIC                                      0x00000002
#define GPT_TBMR_TBMR_ONE_SHOT                                      0x00000001

//*****************************************************************************
//
// Register: GPT_O_CTL
//
//*****************************************************************************
// Field:    [14] TBPWML
//
// GPT Timer B PWM Output Level
//
// 0: Output is unaffected.
// 1: Output is inverted.
// ENUMs:
// INVERTED                 Inverted
// NORMAL                   Not inverted
#define GPT_CTL_TBPWML                                              0x00004000
#define GPT_CTL_TBPWML_BITN                                                 14
#define GPT_CTL_TBPWML_M                                            0x00004000
#define GPT_CTL_TBPWML_S                                                    14
#define GPT_CTL_TBPWML_INVERTED                                     0x00004000
#define GPT_CTL_TBPWML_NORMAL                                       0x00000000

// Field:    [13] TBOTE
//
// GPT Timer B Output Trigger Enable
// ENUMs:
// EN                       The output Timer B ADC trigger is enabled.
// DIS                      The output Timer B ADC trigger is disabled.
#define GPT_CTL_TBOTE                                               0x00002000
#define GPT_CTL_TBOTE_BITN                                                  13
#define GPT_CTL_TBOTE_M                                             0x00002000
#define GPT_CTL_TBOTE_S                                                     13
#define GPT_CTL_TBOTE_EN                                            0x00002000
#define GPT_CTL_TBOTE_DIS                                           0x00000000

// Field: [11:10] TBEVENT
//
// GPT Timer B Event Mode
// ENUMs:
// BOTH                     Both edges
// NEG                      Negative edge
// POS                      Positive edge
#define GPT_CTL_TBEVENT_M                                           0x00000C00
#define GPT_CTL_TBEVENT_S                                                   10
#define GPT_CTL_TBEVENT_BOTH                                        0x00000C00
#define GPT_CTL_TBEVENT_NEG                                         0x00000400
#define GPT_CTL_TBEVENT_POS                                         0x00000000

// Field:     [9] TBSTALL
//
// GPT Timer B Stall Enable
// ENUMs:
// EN                       Timer B freezes counting while the processor is
// halted by the debugger.
// DIS                      Timer B continues counting while the processor is
// halted by the debugger.
#define GPT_CTL_TBSTALL                                             0x00000200
#define GPT_CTL_TBSTALL_BITN                                                 9
#define GPT_CTL_TBSTALL_M                                           0x00000200
#define GPT_CTL_TBSTALL_S                                                    9
#define GPT_CTL_TBSTALL_EN                                          0x00000200
#define GPT_CTL_TBSTALL_DIS                                         0x00000000

// Field:     [8] TBEN
//
// GPT Timer B Enable
// ENUMs:
// EN                       Timer B is enabled and begins counting or the
// capture logic is enabled based on CFG register.
// DIS                      Timer B is disabled.
#define GPT_CTL_TBEN                                                0x00000100
#define GPT_CTL_TBEN_BITN                                                    8
#define GPT_CTL_TBEN_M                                              0x00000100
#define GPT_CTL_TBEN_S                                                       8
#define GPT_CTL_TBEN_EN                                             0x00000100
#define GPT_CTL_TBEN_DIS                                            0x00000000

// Field:     [6] TAPWML
//
// GPT Timer A PWM Output Level
// ENUMs:
// INVERTED                 Inverted
// NORMAL                   Not inverted
#define GPT_CTL_TAPWML                                              0x00000040
#define GPT_CTL_TAPWML_BITN                                                  6
#define GPT_CTL_TAPWML_M                                            0x00000040
#define GPT_CTL_TAPWML_S                                                     6
#define GPT_CTL_TAPWML_INVERTED                                     0x00000040
#define GPT_CTL_TAPWML_NORMAL                                       0x00000000

// Field:     [5] TAOTE
//
// GPT Timer A Output Trigger Enable
// ENUMs:
// EN                       The output Timer A ADC trigger is enabled.
// DIS                      The output Timer A ADC trigger is disabled.
#define GPT_CTL_TAOTE                                               0x00000020
#define GPT_CTL_TAOTE_BITN                                                   5
#define GPT_CTL_TAOTE_M                                             0x00000020
#define GPT_CTL_TAOTE_S                                                      5
#define GPT_CTL_TAOTE_EN                                            0x00000020
#define GPT_CTL_TAOTE_DIS                                           0x00000000

// Field:     [4] RTCEN
//
// GPT RTC Enable
// ENUMs:
// EN                       RTC counting is enabled.
// DIS                      RTC counting is disabled.
#define GPT_CTL_RTCEN                                               0x00000010
#define GPT_CTL_RTCEN_BITN                                                   4
#define GPT_CTL_RTCEN_M                                             0x00000010
#define GPT_CTL_RTCEN_S                                                      4
#define GPT_CTL_RTCEN_EN                                            0x00000010
#define GPT_CTL_RTCEN_DIS                                           0x00000000

// Field:   [3:2] TAEVENT
//
// GPT Timer A Event Mode
// ENUMs:
// BOTH                     Both edges
// NEG                      Negative edge
// POS                      Positive edge
#define GPT_CTL_TAEVENT_M                                           0x0000000C
#define GPT_CTL_TAEVENT_S                                                    2
#define GPT_CTL_TAEVENT_BOTH                                        0x0000000C
#define GPT_CTL_TAEVENT_NEG                                         0x00000004
#define GPT_CTL_TAEVENT_POS                                         0x00000000

// Field:     [1] TASTALL
//
// GPT Timer A Stall Enable
// ENUMs:
// EN                       Timer A freezes counting while the processor is
// halted by the debugger.
// DIS                      Timer A continues counting while the processor is
// halted by the debugger.
#define GPT_CTL_TASTALL                                             0x00000002
#define GPT_CTL_TASTALL_BITN                                                 1
#define GPT_CTL_TASTALL_M                                           0x00000002
#define GPT_CTL_TASTALL_S                                                    1
#define GPT_CTL_TASTALL_EN                                          0x00000002
#define GPT_CTL_TASTALL_DIS                                         0x00000000

// Field:     [0] TAEN
//
// GPT Timer A Enable
// ENUMs:
// EN                       Timer A is enabled and begins counting or the
// capture logic is enabled based on the CFG register.
// DIS                      Timer A is disabled.
#define GPT_CTL_TAEN                                                0x00000001
#define GPT_CTL_TAEN_BITN                                                    0
#define GPT_CTL_TAEN_M                                              0x00000001
#define GPT_CTL_TAEN_S                                                       0
#define GPT_CTL_TAEN_EN                                             0x00000001
#define GPT_CTL_TAEN_DIS                                            0x00000000

//*****************************************************************************
//
// Register: GPT_O_SYNC
//
//*****************************************************************************
// Field:   [7:6] SYNC3
//
// Synchronize GPT Timer 3.
// ENUMs:
// BOTH                     A timeout event for both Timer A and Timer B of
// GPT3 is triggered
// TIMERB                   A timeout event for Timer B of GPT3 is triggered
// TIMERA                   A timeout event for Timer A of GPT3 is triggered
// NOSYNC                   No Sync. GPT3 is not affected.
#define GPT_SYNC_SYNC3_M                                            0x000000C0
#define GPT_SYNC_SYNC3_S                                                     6
#define GPT_SYNC_SYNC3_BOTH                                         0x000000C0
#define GPT_SYNC_SYNC3_TIMERB                                       0x00000080
#define GPT_SYNC_SYNC3_TIMERA                                       0x00000040
#define GPT_SYNC_SYNC3_NOSYNC                                       0x00000000

// Field:   [5:4] SYNC2
//
// Synchronize GPT Timer 2.
// ENUMs:
// BOTH                     A timeout event for both Timer A and Timer B of
// GPT2 is triggered
// TIMERB                   A timeout event for Timer B of GPT2 is triggered
// TIMERA                   A timeout event for Timer A of GPT2 is triggered
// NOSYNC                   No Sync. GPT2 is not affected.
#define GPT_SYNC_SYNC2_M                                            0x00000030
#define GPT_SYNC_SYNC2_S                                                     4
#define GPT_SYNC_SYNC2_BOTH                                         0x00000030
#define GPT_SYNC_SYNC2_TIMERB                                       0x00000020
#define GPT_SYNC_SYNC2_TIMERA                                       0x00000010
#define GPT_SYNC_SYNC2_NOSYNC                                       0x00000000

// Field:   [3:2] SYNC1
//
// Synchronize GPT Timer 1
// ENUMs:
// BOTH                     A timeout event for both Timer A and Timer B of
// GPT1 is triggered
// TIMERB                   A timeout event for Timer B of GPT1 is triggered
// TIMERA                   A timeout event for Timer A of GPT1 is triggered
// NOSYNC                   No Sync. GPT1 is not affected.
#define GPT_SYNC_SYNC1_M                                            0x0000000C
#define GPT_SYNC_SYNC1_S                                                     2
#define GPT_SYNC_SYNC1_BOTH                                         0x0000000C
#define GPT_SYNC_SYNC1_TIMERB                                       0x00000008
#define GPT_SYNC_SYNC1_TIMERA                                       0x00000004
#define GPT_SYNC_SYNC1_NOSYNC                                       0x00000000

// Field:   [1:0] SYNC0
//
// Synchronize GPT Timer 0
// ENUMs:
// BOTH                     A timeout event for both Timer A and Timer B of
// GPT0 is triggered
// TIMERB                   A timeout event for Timer B of GPT0 is triggered
// TIMERA                   A timeout event for Timer A of GPT0 is triggered
// NOSYNC                   No Sync. GPT0 is not affected.
#define GPT_SYNC_SYNC0_M                                            0x00000003
#define GPT_SYNC_SYNC0_S                                                     0
#define GPT_SYNC_SYNC0_BOTH                                         0x00000003
#define GPT_SYNC_SYNC0_TIMERB                                       0x00000002
#define GPT_SYNC_SYNC0_TIMERA                                       0x00000001
#define GPT_SYNC_SYNC0_NOSYNC                                       0x00000000

//*****************************************************************************
//
// Register: GPT_O_IMR
//
//*****************************************************************************
// Field:    [16] WUMIS
//
// Enabling this bit will make the RIS.WURIS interrupt propagate to MIS.WUMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_WUMIS                                               0x00010000
#define GPT_IMR_WUMIS_BITN                                                  16
#define GPT_IMR_WUMIS_M                                             0x00010000
#define GPT_IMR_WUMIS_S                                                     16
#define GPT_IMR_WUMIS_EN                                            0x00010000
#define GPT_IMR_WUMIS_DIS                                           0x00000000

// Field:    [13] DMABIM
//
// Enabling this bit will make the RIS.DMABRIS interrupt propagate to
// MIS.DMABMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_DMABIM                                              0x00002000
#define GPT_IMR_DMABIM_BITN                                                 13
#define GPT_IMR_DMABIM_M                                            0x00002000
#define GPT_IMR_DMABIM_S                                                    13
#define GPT_IMR_DMABIM_EN                                           0x00002000
#define GPT_IMR_DMABIM_DIS                                          0x00000000

// Field:    [11] TBMIM
//
// Enabling this bit will make the RIS.TBMRIS interrupt propagate to MIS.TBMMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_TBMIM                                               0x00000800
#define GPT_IMR_TBMIM_BITN                                                  11
#define GPT_IMR_TBMIM_M                                             0x00000800
#define GPT_IMR_TBMIM_S                                                     11
#define GPT_IMR_TBMIM_EN                                            0x00000800
#define GPT_IMR_TBMIM_DIS                                           0x00000000

// Field:    [10] CBEIM
//
// Enabling this bit will make the RIS.CBERIS interrupt propagate to MIS.CBEMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_CBEIM                                               0x00000400
#define GPT_IMR_CBEIM_BITN                                                  10
#define GPT_IMR_CBEIM_M                                             0x00000400
#define GPT_IMR_CBEIM_S                                                     10
#define GPT_IMR_CBEIM_EN                                            0x00000400
#define GPT_IMR_CBEIM_DIS                                           0x00000000

// Field:     [9] CBMIM
//
// Enabling this bit will make the RIS.CBMRIS interrupt propagate to MIS.CBMMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_CBMIM                                               0x00000200
#define GPT_IMR_CBMIM_BITN                                                   9
#define GPT_IMR_CBMIM_M                                             0x00000200
#define GPT_IMR_CBMIM_S                                                      9
#define GPT_IMR_CBMIM_EN                                            0x00000200
#define GPT_IMR_CBMIM_DIS                                           0x00000000

// Field:     [8] TBTOIM
//
// Enabling this bit will make the RIS.TBTORIS interrupt propagate to
// MIS.TBTOMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_TBTOIM                                              0x00000100
#define GPT_IMR_TBTOIM_BITN                                                  8
#define GPT_IMR_TBTOIM_M                                            0x00000100
#define GPT_IMR_TBTOIM_S                                                     8
#define GPT_IMR_TBTOIM_EN                                           0x00000100
#define GPT_IMR_TBTOIM_DIS                                          0x00000000

// Field:     [5] DMAAIM
//
// Enabling this bit will make the RIS.DMAARIS interrupt propagate to
// MIS.DMAAMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_DMAAIM                                              0x00000020
#define GPT_IMR_DMAAIM_BITN                                                  5
#define GPT_IMR_DMAAIM_M                                            0x00000020
#define GPT_IMR_DMAAIM_S                                                     5
#define GPT_IMR_DMAAIM_EN                                           0x00000020
#define GPT_IMR_DMAAIM_DIS                                          0x00000000

// Field:     [4] TAMIM
//
// Enabling this bit will make the RIS.TAMRIS interrupt propagate to MIS.TAMMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_TAMIM                                               0x00000010
#define GPT_IMR_TAMIM_BITN                                                   4
#define GPT_IMR_TAMIM_M                                             0x00000010
#define GPT_IMR_TAMIM_S                                                      4
#define GPT_IMR_TAMIM_EN                                            0x00000010
#define GPT_IMR_TAMIM_DIS                                           0x00000000

// Field:     [3] RTCIM
//
// Enabling this bit will make the RIS.RTCRIS interrupt propagate to MIS.RTCMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_RTCIM                                               0x00000008
#define GPT_IMR_RTCIM_BITN                                                   3
#define GPT_IMR_RTCIM_M                                             0x00000008
#define GPT_IMR_RTCIM_S                                                      3
#define GPT_IMR_RTCIM_EN                                            0x00000008
#define GPT_IMR_RTCIM_DIS                                           0x00000000

// Field:     [2] CAEIM
//
// Enabling this bit will make the RIS.CAERIS interrupt propagate to MIS.CAEMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_CAEIM                                               0x00000004
#define GPT_IMR_CAEIM_BITN                                                   2
#define GPT_IMR_CAEIM_M                                             0x00000004
#define GPT_IMR_CAEIM_S                                                      2
#define GPT_IMR_CAEIM_EN                                            0x00000004
#define GPT_IMR_CAEIM_DIS                                           0x00000000

// Field:     [1] CAMIM
//
// Enabling this bit will make the RIS.CAMRIS interrupt propagate to MIS.CAMMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_CAMIM                                               0x00000002
#define GPT_IMR_CAMIM_BITN                                                   1
#define GPT_IMR_CAMIM_M                                             0x00000002
#define GPT_IMR_CAMIM_S                                                      1
#define GPT_IMR_CAMIM_EN                                            0x00000002
#define GPT_IMR_CAMIM_DIS                                           0x00000000

// Field:     [0] TATOIM
//
// Enabling this bit will make the RIS.TATORIS interrupt propagate to
// MIS.TATOMIS
// ENUMs:
// EN                       Enable Interrupt
// DIS                      Disable Interrupt
#define GPT_IMR_TATOIM                                              0x00000001
#define GPT_IMR_TATOIM_BITN                                                  0
#define GPT_IMR_TATOIM_M                                            0x00000001
#define GPT_IMR_TATOIM_S                                                     0
#define GPT_IMR_TATOIM_EN                                           0x00000001
#define GPT_IMR_TATOIM_DIS                                          0x00000000

//*****************************************************************************
//
// Register: GPT_O_RIS
//
//*****************************************************************************
// Field:    [16] WURIS
//
// GPT Write Update Error Raw Interrupt
//
// 0: No error.
// 1: Either Timer A or B was written twice in a Row or Timer A was written
// before the corresponding Timer B was written.
#define GPT_RIS_WURIS                                               0x00010000
#define GPT_RIS_WURIS_BITN                                                  16
#define GPT_RIS_WURIS_M                                             0x00010000
#define GPT_RIS_WURIS_S                                                     16

// Field:    [13] DMABRIS
//
// GPT Timer B DMA Done Raw Interrupt Status
//
// 0: Transfer has not completed
// 1: Transfer has completed
#define GPT_RIS_DMABRIS                                             0x00002000
#define GPT_RIS_DMABRIS_BITN                                                13
#define GPT_RIS_DMABRIS_M                                           0x00002000
#define GPT_RIS_DMABRIS_S                                                   13

// Field:    [11] TBMRIS
//
// GPT Timer B Match Raw  Interrupt
//
// 0:  The match value has not been reached
// 1:  The match value is reached.
//
// TBMR.TBMIE is set, and the match values in TBMATCHR and optionally TBPMR
// have been reached when configured in one-shot or periodic mode.
#define GPT_RIS_TBMRIS                                              0x00000800
#define GPT_RIS_TBMRIS_BITN                                                 11
#define GPT_RIS_TBMRIS_M                                            0x00000800
#define GPT_RIS_TBMRIS_S                                                    11

// Field:    [10] CBERIS
//
// GPT Timer B Capture Mode Event Raw Interrupt
//
// 0:  The event has not occured.
// 1:  The event has occured.
//
// This interrupt asserts when the subtimer is configured in Input Edge-Time
// mode
#define GPT_RIS_CBERIS                                              0x00000400
#define GPT_RIS_CBERIS_BITN                                                 10
#define GPT_RIS_CBERIS_M                                            0x00000400
#define GPT_RIS_CBERIS_S                                                    10

// Field:     [9] CBMRIS
//
// GPT Timer B Capture Mode Match Raw Interrupt
//
// 0:  Match for Timer B has not occured
// 1:  Match for Timer B has occurred.
//
// This interrupt asserts when the values in the TBR and TBPR match values in
// the TBMATCHR and TBPMR, and when configured in Input Edge-Time mode (reg-ref
// instead!!)
#define GPT_RIS_CBMRIS                                              0x00000200
#define GPT_RIS_CBMRIS_BITN                                                  9
#define GPT_RIS_CBMRIS_M                                            0x00000200
#define GPT_RIS_CBMRIS_S                                                     9

// Field:     [8] TBTORIS
//
// GPT Timer B Time-out Raw Interrupt
//
// 0:  Timer B has not timed out
// 1:  Timer B has timed out.
//
// This interrupt is asserted when a one-shot or periodic mode timer reaches
// it&#39;s count limit. The count limit is 0 or the value loaded into TBILR,
// depending on the count direction.
#define GPT_RIS_TBTORIS                                             0x00000100
#define GPT_RIS_TBTORIS_BITN                                                 8
#define GPT_RIS_TBTORIS_M                                           0x00000100
#define GPT_RIS_TBTORIS_S                                                    8

// Field:     [5] DMAARIS
//
// GPT Timer A DMA Done Raw Interrupt Status
//
// 0: Transfer has not completed
// 1: Transfer has completed
#define GPT_RIS_DMAARIS                                             0x00000020
#define GPT_RIS_DMAARIS_BITN                                                 5
#define GPT_RIS_DMAARIS_M                                           0x00000020
#define GPT_RIS_DMAARIS_S                                                    5

// Field:     [4] TAMRIS
//
// **GPT **Timer A Match Raw  Interrupt
//
// 0:  The match value has not been reached
// 1:  The match value is reached.
//
// TAMR.TAMIE is set, and the match values in TAMATCHR and optionally TAPMR
// have been reached when configured in one-shot or periodic mode.
#define GPT_RIS_TAMRIS                                              0x00000010
#define GPT_RIS_TAMRIS_BITN                                                  4
#define GPT_RIS_TAMRIS_M                                            0x00000010
#define GPT_RIS_TAMRIS_S                                                     4

// Field:     [3] RTCRIS
//
// GPT RTC Raw Interrupt
//
// 0:  The RTC event has not occured
// 1:  The RTC event has occured
#define GPT_RIS_RTCRIS                                              0x00000008
#define GPT_RIS_RTCRIS_BITN                                                  3
#define GPT_RIS_RTCRIS_M                                            0x00000008
#define GPT_RIS_RTCRIS_S                                                     3

// Field:     [2] CAERIS
//
// GPT Timer A Capture Mode Event Raw Interrupt
//
// 0:  The event has not occured.
// 1:  The event has occured.
//
// This interrupt asserts when the subtimer is configured in Input Edge-Time
// mode
#define GPT_RIS_CAERIS                                              0x00000004
#define GPT_RIS_CAERIS_BITN                                                  2
#define GPT_RIS_CAERIS_M                                            0x00000004
#define GPT_RIS_CAERIS_S                                                     2

// Field:     [1] CAMRIS
//
// GPT Timer A Capture Mode Match Raw Interrupt
//
// 0:  Match for Timer A has not occured
// 1:  Match for Timer A has occurred
//
// This interrupt asserts when the values in the TAR and TAPR match values in
// the TAMATCHR and TAPMR, and when configured in Input Edge-Time mode (reg-ref
// instead!!)
#define GPT_RIS_CAMRIS                                              0x00000002
#define GPT_RIS_CAMRIS_BITN                                                  1
#define GPT_RIS_CAMRIS_M                                            0x00000002
#define GPT_RIS_CAMRIS_S                                                     1

// Field:     [0] TATORIS
//
// GPT Timer A Time-out Raw Interrupt
//
// 0:  Timer A has not timed out
// 1:  Timer A has timed out.
//
// This interrupt is asserted when a one-shot or periodic mode timer reaches
// it&#39;s count limit. The count limit is 0 or the value loaded into TAILR,
// depending on the count direction.
#define GPT_RIS_TATORIS                                             0x00000001
#define GPT_RIS_TATORIS_BITN                                                 0
#define GPT_RIS_TATORIS_M                                           0x00000001
#define GPT_RIS_TATORIS_S                                                    0

//*****************************************************************************
//
// Register: GPT_O_MIS
//
//*****************************************************************************
// Field:    [16] WUMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.WURIS = 1 &#38;&#38; IMR.WUMIS = 1
#define GPT_MIS_WUMIS                                               0x00010000
#define GPT_MIS_WUMIS_BITN                                                  16
#define GPT_MIS_WUMIS_M                                             0x00010000
#define GPT_MIS_WUMIS_S                                                     16

// Field:    [13] DMABMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.DMABRIS = 1 &#38;&#38; IMR.DMABIM = 1
#define GPT_MIS_DMABMIS                                             0x00002000
#define GPT_MIS_DMABMIS_BITN                                                13
#define GPT_MIS_DMABMIS_M                                           0x00002000
#define GPT_MIS_DMABMIS_S                                                   13

// Field:    [11] TBMMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.TBMRIS = 1 &#38;&#38; IMR.TBMIM = 1
#define GPT_MIS_TBMMIS                                              0x00000800
#define GPT_MIS_TBMMIS_BITN                                                 11
#define GPT_MIS_TBMMIS_M                                            0x00000800
#define GPT_MIS_TBMMIS_S                                                    11

// Field:    [10] CBEMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.CBERIS = 1 &#38;&#38; IMR.CBEIM = 1
#define GPT_MIS_CBEMIS                                              0x00000400
#define GPT_MIS_CBEMIS_BITN                                                 10
#define GPT_MIS_CBEMIS_M                                            0x00000400
#define GPT_MIS_CBEMIS_S                                                    10

// Field:     [9] CBMMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.CBMRIS = 1 &#38;&#38; IMR.CBMIM = 1
#define GPT_MIS_CBMMIS                                              0x00000200
#define GPT_MIS_CBMMIS_BITN                                                  9
#define GPT_MIS_CBMMIS_M                                            0x00000200
#define GPT_MIS_CBMMIS_S                                                     9

// Field:     [8] TBTOMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.TBTORIS = 1 &#38;&#38; IMR.TBTOIM = 1
#define GPT_MIS_TBTOMIS                                             0x00000100
#define GPT_MIS_TBTOMIS_BITN                                                 8
#define GPT_MIS_TBTOMIS_M                                           0x00000100
#define GPT_MIS_TBTOMIS_S                                                    8

// Field:     [5] DMAAMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.DMAARIS = 1 &#38;&#38; IMR.DMAAIM = 1
#define GPT_MIS_DMAAMIS                                             0x00000020
#define GPT_MIS_DMAAMIS_BITN                                                 5
#define GPT_MIS_DMAAMIS_M                                           0x00000020
#define GPT_MIS_DMAAMIS_S                                                    5

// Field:     [4] TAMMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.TAMRIS = 1 &#38;&#38; IMR.TAMIM = 1
#define GPT_MIS_TAMMIS                                              0x00000010
#define GPT_MIS_TAMMIS_BITN                                                  4
#define GPT_MIS_TAMMIS_M                                            0x00000010
#define GPT_MIS_TAMMIS_S                                                     4

// Field:     [3] RTCMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.RTCRIS = 1 &#38;&#38; IMR.RTCIM = 1
#define GPT_MIS_RTCMIS                                              0x00000008
#define GPT_MIS_RTCMIS_BITN                                                  3
#define GPT_MIS_RTCMIS_M                                            0x00000008
#define GPT_MIS_RTCMIS_S                                                     3

// Field:     [2] CAEMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.CAERIS = 1 &#38;&#38; IMR.CAEIM = 1
#define GPT_MIS_CAEMIS                                              0x00000004
#define GPT_MIS_CAEMIS_BITN                                                  2
#define GPT_MIS_CAEMIS_M                                            0x00000004
#define GPT_MIS_CAEMIS_S                                                     2

// Field:     [1] CAMMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.CAMRIS = 1 &#38;&#38; IMR.CAMIM = 1
#define GPT_MIS_CAMMIS                                              0x00000002
#define GPT_MIS_CAMMIS_BITN                                                  1
#define GPT_MIS_CAMMIS_M                                            0x00000002
#define GPT_MIS_CAMMIS_S                                                     1

// Field:     [0] TATOMIS
//
// 0: No interrupt or interrupt not enabled
// 1: RIS.TATORIS = 1 &#38;&#38; IMR.TATOIM = 1
#define GPT_MIS_TATOMIS                                             0x00000001
#define GPT_MIS_TATOMIS_BITN                                                 0
#define GPT_MIS_TATOMIS_M                                           0x00000001
#define GPT_MIS_TATOMIS_S                                                    0

//*****************************************************************************
//
// Register: GPT_O_ICLR
//
//*****************************************************************************
// Field:    [16] WUECINT
//
// 0: Do nothing.
// 1: Clear RIS.WURIS and MIS.WUMIS
#define GPT_ICLR_WUECINT                                            0x00010000
#define GPT_ICLR_WUECINT_BITN                                               16
#define GPT_ICLR_WUECINT_M                                          0x00010000
#define GPT_ICLR_WUECINT_S                                                  16

// Field:    [13] DMABINT
//
// 0: Do nothing.
// 1: Clear RIS.DMABRIS and MIS.DMABMIS
#define GPT_ICLR_DMABINT                                            0x00002000
#define GPT_ICLR_DMABINT_BITN                                               13
#define GPT_ICLR_DMABINT_M                                          0x00002000
#define GPT_ICLR_DMABINT_S                                                  13

// Field:    [11] TBMCINT
//
// 0: Do nothing.
// 1: Clear RIS.TBMRIS and MIS.TBMMIS
#define GPT_ICLR_TBMCINT                                            0x00000800
#define GPT_ICLR_TBMCINT_BITN                                               11
#define GPT_ICLR_TBMCINT_M                                          0x00000800
#define GPT_ICLR_TBMCINT_S                                                  11

// Field:    [10] CBECINT
//
// 0: Do nothing.
// 1: Clear RIS.CBERIS and MIS.CBEMIS
#define GPT_ICLR_CBECINT                                            0x00000400
#define GPT_ICLR_CBECINT_BITN                                               10
#define GPT_ICLR_CBECINT_M                                          0x00000400
#define GPT_ICLR_CBECINT_S                                                  10

// Field:     [9] CBMCINT
//
// 0: Do nothing.
// 1: Clear RIS.CBMRIS and MIS.CBMMIS
#define GPT_ICLR_CBMCINT                                            0x00000200
#define GPT_ICLR_CBMCINT_BITN                                                9
#define GPT_ICLR_CBMCINT_M                                          0x00000200
#define GPT_ICLR_CBMCINT_S                                                   9

// Field:     [8] TBTOCINT
//
// 0: Do nothing.
// 1: Clear RIS.TBTORIS and MIS.TBTOMIS
#define GPT_ICLR_TBTOCINT                                           0x00000100
#define GPT_ICLR_TBTOCINT_BITN                                               8
#define GPT_ICLR_TBTOCINT_M                                         0x00000100
#define GPT_ICLR_TBTOCINT_S                                                  8

// Field:     [5] DMAAINT
//
// 0: Do nothing.
// 1: Clear RIS.DMAARIS and MIS.DMAAMIS
#define GPT_ICLR_DMAAINT                                            0x00000020
#define GPT_ICLR_DMAAINT_BITN                                                5
#define GPT_ICLR_DMAAINT_M                                          0x00000020
#define GPT_ICLR_DMAAINT_S                                                   5

// Field:     [4] TAMCINT
//
// 0: Do nothing.
// 1: Clear RIS.TAMRIS and MIS.TAMMIS
#define GPT_ICLR_TAMCINT                                            0x00000010
#define GPT_ICLR_TAMCINT_BITN                                                4
#define GPT_ICLR_TAMCINT_M                                          0x00000010
#define GPT_ICLR_TAMCINT_S                                                   4

// Field:     [3] RTCCINT
//
// 0: Do nothing.
// 1: Clear RIS.RTCRIS and MIS.RTCMIS
#define GPT_ICLR_RTCCINT                                            0x00000008
#define GPT_ICLR_RTCCINT_BITN                                                3
#define GPT_ICLR_RTCCINT_M                                          0x00000008
#define GPT_ICLR_RTCCINT_S                                                   3

// Field:     [2] CAECINT
//
// 0: Do nothing.
// 1: Clear RIS.CAERIS and MIS.CAEMIS
#define GPT_ICLR_CAECINT                                            0x00000004
#define GPT_ICLR_CAECINT_BITN                                                2
#define GPT_ICLR_CAECINT_M                                          0x00000004
#define GPT_ICLR_CAECINT_S                                                   2

// Field:     [1] CAMCINT
//
// 0: Do nothing.
// 1: Clear RIS.CAMRIS and MIS.CAMMIS
#define GPT_ICLR_CAMCINT                                            0x00000002
#define GPT_ICLR_CAMCINT_BITN                                                1
#define GPT_ICLR_CAMCINT_M                                          0x00000002
#define GPT_ICLR_CAMCINT_S                                                   1

// Field:     [0] TATOCINT
//
// 0: Do nothing.
// 1: Clear RIS.TATORIS and MIS.TATOMIS
#define GPT_ICLR_TATOCINT                                           0x00000001
#define GPT_ICLR_TATOCINT_BITN                                               0
#define GPT_ICLR_TATOCINT_M                                         0x00000001
#define GPT_ICLR_TATOCINT_S                                                  0

//*****************************************************************************
//
// Register: GPT_O_TAILR
//
//*****************************************************************************
// Field:  [31:0] TAILR
//
// GPT Timer A Interval Load  Register
#define GPT_TAILR_TAILR_M                                           0xFFFFFFFF
#define GPT_TAILR_TAILR_S                                                    0

//*****************************************************************************
//
// Register: GPT_O_TBILR
//
//*****************************************************************************
// Field:  [31:0] TBILR
//
// GPT Timer B Interval Load  Register
#define GPT_TBILR_TBILR_M                                           0xFFFFFFFF
#define GPT_TBILR_TBILR_S                                                    0

//*****************************************************************************
//
// Register: GPT_O_TAMATCHR
//
//*****************************************************************************
// Field:  [31:0] TAMATCHR
//
// GPT Timer A Match Register
#define GPT_TAMATCHR_TAMATCHR_M                                     0xFFFFFFFF
#define GPT_TAMATCHR_TAMATCHR_S                                              0

//*****************************************************************************
//
// Register: GPT_O_TBMATCHR
//
//*****************************************************************************
// Field:  [31:0] TBMATCHR
//
// GPT Timer B Match Register
#define GPT_TBMATCHR_TBMATCHR_M                                     0xFFFFFFFF
#define GPT_TBMATCHR_TBMATCHR_S                                              0

//*****************************************************************************
//
// Register: GPT_O_TAPR
//
//*****************************************************************************
// Field:   [7:0] TAPSR
//
// Timer A Pre-scale.
//
// Prescaler ratio in one-shot and periodic count mode is TAPSR + 1, ie:
//
// 0: Prescaler ratio = 1
// 1: Prescaler ratio = 2
// 2: Prescaler ratio = 3
// ...
// 255: Prescaler ratio = 256
#define GPT_TAPR_TAPSR_M                                            0x000000FF
#define GPT_TAPR_TAPSR_S                                                     0

//*****************************************************************************
//
// Register: GPT_O_TBPR
//
//*****************************************************************************
// Field:   [7:0] TBPSR
//
// Timer B Pre-scale.
//
// Prescale ratio in one-shot and periodic count mode is TBPSR + 1, ie:
//
//
// 0: Prescaler ratio = 1
// 1: Prescaler ratio = 2
// 2: Prescaler ratio = 3
// ...
// 255: Prescaler ratio = 256
#define GPT_TBPR_TBPSR_M                                            0x000000FF
#define GPT_TBPR_TBPSR_S                                                     0

//*****************************************************************************
//
// Register: GPT_O_TAPMR
//
//*****************************************************************************
// Field:   [7:0] TAPSMR
//
// GPT Timer A Pre-scale Match.  In 16 bit mode this field holds bits 23 to 16.
#define GPT_TAPMR_TAPSMR_M                                          0x000000FF
#define GPT_TAPMR_TAPSMR_S                                                   0

//*****************************************************************************
//
// Register: GPT_O_TBPMR
//
//*****************************************************************************
// Field:   [7:0] TBPSMR
//
// GPT Timer B Pre-scale Match Register.  In 16 bit mode this field holds bits
// 23 to 16.
#define GPT_TBPMR_TBPSMR_M                                          0x000000FF
#define GPT_TBPMR_TBPSMR_S                                                   0

//*****************************************************************************
//
// Register: GPT_O_TAR
//
//*****************************************************************************
// Field:  [31:0] TAR
//
// GPT Timer A Register
//
// A read returns the current value of the Timer A Count Register, in all cases
// except for Input Edge count and Timer modes.
// In the Input Edge Count Mode, this register contains the number of edges
// that have occurred. In the Input Edge Time mode, this register contains the
// time at which the last edge event took place.
#define GPT_TAR_TAR_M                                               0xFFFFFFFF
#define GPT_TAR_TAR_S                                                        0

//*****************************************************************************
//
// Register: GPT_O_TBR
//
//*****************************************************************************
// Field:  [31:0] TBR
//
// GPT Timer B Register
//
// A read returns the current value of the Timer B Count Register, in all cases
// except for Input Edge count and Timer modes.
// In the Input Edge Count Mode, this register contains the number of edges
// that have occurred. In the Input Edge Time mode, this register contains the
// time at which the last edge event took place.
#define GPT_TBR_TBR_M                                               0xFFFFFFFF
#define GPT_TBR_TBR_S                                                        0

//*****************************************************************************
//
// Register: GPT_O_TAV
//
//*****************************************************************************
// Field:  [31:0] TAV
//
// GPT Timer A Register
#define GPT_TAV_TAV_M                                               0xFFFFFFFF
#define GPT_TAV_TAV_S                                                        0

//*****************************************************************************
//
// Register: GPT_O_TBV
//
//*****************************************************************************
// Field:  [31:0] TBV
//
// GPT Timer B Register
#define GPT_TBV_TBV_M                                               0xFFFFFFFF
#define GPT_TBV_TBV_S                                                        0

//*****************************************************************************
//
// Register: GPT_O_RTCPD
//
//*****************************************************************************
// Field:  [15:0] RTCPD
//
// GPT RTC Pre-divider
#define GPT_RTCPD_RTCPD_M                                           0x0000FFFF
#define GPT_RTCPD_RTCPD_S                                                    0

//*****************************************************************************
//
// Register: GPT_O_TAPS
//
//*****************************************************************************
// Field:  [15:0] PSS
//
// GPT Timer A Pre-scaler
#define GPT_TAPS_PSS_M                                              0x0000FFFF
#define GPT_TAPS_PSS_S                                                       0

//*****************************************************************************
//
// Register: GPT_O_TBPS
//
//*****************************************************************************
// Field:  [15:0] PSS
//
// GPT Timer B Pre-scaler
#define GPT_TBPS_PSS_M                                              0x0000FFFF
#define GPT_TBPS_PSS_S                                                       0

//*****************************************************************************
//
// Register: GPT_O_TAPV
//
//*****************************************************************************
// Field:  [15:0] PSV
//
// GPT Timer A Pre-scaler Value
#define GPT_TAPV_PSV_M                                              0x0000FFFF
#define GPT_TAPV_PSV_S                                                       0

//*****************************************************************************
//
// Register: GPT_O_TBPV
//
//*****************************************************************************
// Field:  [15:0] PSV
//
// GPT Timer B Pre-scaler Value
#define GPT_TBPV_PSV_M                                              0x0000FFFF
#define GPT_TBPV_PSV_S                                                       0

//*****************************************************************************
//
// Register: GPT_O_DMAEV
//
//*****************************************************************************
// Field:    [11] TBMDMAEN
//
// GPT Timer B Match DMA Trigger Enable
#define GPT_DMAEV_TBMDMAEN                                          0x00000800
#define GPT_DMAEV_TBMDMAEN_BITN                                             11
#define GPT_DMAEV_TBMDMAEN_M                                        0x00000800
#define GPT_DMAEV_TBMDMAEN_S                                                11

// Field:    [10] CBEDMAEN
//
// GPT Timer B Capture Event DMA Trigger Enable
#define GPT_DMAEV_CBEDMAEN                                          0x00000400
#define GPT_DMAEV_CBEDMAEN_BITN                                             10
#define GPT_DMAEV_CBEDMAEN_M                                        0x00000400
#define GPT_DMAEV_CBEDMAEN_S                                                10

// Field:     [9] CBMDMAEN
//
// GPT Timer B Capture Match DMA Trigger Enable
#define GPT_DMAEV_CBMDMAEN                                          0x00000200
#define GPT_DMAEV_CBMDMAEN_BITN                                              9
#define GPT_DMAEV_CBMDMAEN_M                                        0x00000200
#define GPT_DMAEV_CBMDMAEN_S                                                 9

// Field:     [8] TBTODMAEN
//
// GPT Timer B Time-Out DMA Trigger Enable
#define GPT_DMAEV_TBTODMAEN                                         0x00000100
#define GPT_DMAEV_TBTODMAEN_BITN                                             8
#define GPT_DMAEV_TBTODMAEN_M                                       0x00000100
#define GPT_DMAEV_TBTODMAEN_S                                                8

// Field:     [4] TAMDMAEN
//
// GPT Timer A Match DMA Trigger Enable
#define GPT_DMAEV_TAMDMAEN                                          0x00000010
#define GPT_DMAEV_TAMDMAEN_BITN                                              4
#define GPT_DMAEV_TAMDMAEN_M                                        0x00000010
#define GPT_DMAEV_TAMDMAEN_S                                                 4

// Field:     [3] RTCDMAEN
//
// GPT RTC Match DMA Trigger Enable
#define GPT_DMAEV_RTCDMAEN                                          0x00000008
#define GPT_DMAEV_RTCDMAEN_BITN                                              3
#define GPT_DMAEV_RTCDMAEN_M                                        0x00000008
#define GPT_DMAEV_RTCDMAEN_S                                                 3

// Field:     [2] CAEDMAEN
//
// GPT Timer A Capture Event DMA Trigger Enable
#define GPT_DMAEV_CAEDMAEN                                          0x00000004
#define GPT_DMAEV_CAEDMAEN_BITN                                              2
#define GPT_DMAEV_CAEDMAEN_M                                        0x00000004
#define GPT_DMAEV_CAEDMAEN_S                                                 2

// Field:     [1] CAMDMAEN
//
// GPT Timer A Capture Match DMA Trigger Enable
#define GPT_DMAEV_CAMDMAEN                                          0x00000002
#define GPT_DMAEV_CAMDMAEN_BITN                                              1
#define GPT_DMAEV_CAMDMAEN_M                                        0x00000002
#define GPT_DMAEV_CAMDMAEN_S                                                 1

// Field:     [0] TATODMAEN
//
// GPT Timer A Time-Out DMA Trigger Enable
#define GPT_DMAEV_TATODMAEN                                         0x00000001
#define GPT_DMAEV_TATODMAEN_BITN                                             0
#define GPT_DMAEV_TATODMAEN_M                                       0x00000001
#define GPT_DMAEV_TATODMAEN_S                                                0

//*****************************************************************************
//
// Register: GPT_O_ADCEV
//
//*****************************************************************************
// Field:    [11] TBMADCEN
//
// GPT Timer B Match ADC Trigger Enable
#define GPT_ADCEV_TBMADCEN                                          0x00000800
#define GPT_ADCEV_TBMADCEN_BITN                                             11
#define GPT_ADCEV_TBMADCEN_M                                        0x00000800
#define GPT_ADCEV_TBMADCEN_S                                                11

// Field:    [10] CBEADCEN
//
// GPT Timer B Capture Event ADC Trigger Enable
#define GPT_ADCEV_CBEADCEN                                          0x00000400
#define GPT_ADCEV_CBEADCEN_BITN                                             10
#define GPT_ADCEV_CBEADCEN_M                                        0x00000400
#define GPT_ADCEV_CBEADCEN_S                                                10

// Field:     [9] CBMADCEN
//
// GPT Timer B Capture Match ADC Trigger Enable
#define GPT_ADCEV_CBMADCEN                                          0x00000200
#define GPT_ADCEV_CBMADCEN_BITN                                              9
#define GPT_ADCEV_CBMADCEN_M                                        0x00000200
#define GPT_ADCEV_CBMADCEN_S                                                 9

// Field:     [8] TBTOADCEN
//
// GPT Timer B Time-Out ADC Trigger Enable
#define GPT_ADCEV_TBTOADCEN                                         0x00000100
#define GPT_ADCEV_TBTOADCEN_BITN                                             8
#define GPT_ADCEV_TBTOADCEN_M                                       0x00000100
#define GPT_ADCEV_TBTOADCEN_S                                                8

// Field:     [4] TAMADCEN
//
// GPT Timer A Match ADC Trigger Enable
#define GPT_ADCEV_TAMADCEN                                          0x00000010
#define GPT_ADCEV_TAMADCEN_BITN                                              4
#define GPT_ADCEV_TAMADCEN_M                                        0x00000010
#define GPT_ADCEV_TAMADCEN_S                                                 4

// Field:     [3] RTCADCEN
//
// GPT RTC Match ADC Trigger Enable
#define GPT_ADCEV_RTCADCEN                                          0x00000008
#define GPT_ADCEV_RTCADCEN_BITN                                              3
#define GPT_ADCEV_RTCADCEN_M                                        0x00000008
#define GPT_ADCEV_RTCADCEN_S                                                 3

// Field:     [2] CAEADCEN
//
// GPT Timer A Capture Event ADC Trigger Enable
#define GPT_ADCEV_CAEADCEN                                          0x00000004
#define GPT_ADCEV_CAEADCEN_BITN                                              2
#define GPT_ADCEV_CAEADCEN_M                                        0x00000004
#define GPT_ADCEV_CAEADCEN_S                                                 2

// Field:     [1] CAMADCEN
//
// GPT Timer A Capture Match ADC Trigger Enable
#define GPT_ADCEV_CAMADCEN                                          0x00000002
#define GPT_ADCEV_CAMADCEN_BITN                                              1
#define GPT_ADCEV_CAMADCEN_M                                        0x00000002
#define GPT_ADCEV_CAMADCEN_S                                                 1

// Field:     [0] TATOADCEN
//
// GPT Timer A Time-Out ADC Trigger Enable
#define GPT_ADCEV_TATOADCEN                                         0x00000001
#define GPT_ADCEV_TATOADCEN_BITN                                             0
#define GPT_ADCEV_TATOADCEN_M                                       0x00000001
#define GPT_ADCEV_TATOADCEN_S                                                0

//*****************************************************************************
//
// Register: GPT_O_VERSION
//
//*****************************************************************************
// Field:  [31:0] VERSION
//
// Timer Revision.
#define GPT_VERSION_VERSION_M                                       0xFFFFFFFF
#define GPT_VERSION_VERSION_S                                                0

//*****************************************************************************
//
// Register: GPT_O_ANDCCP
//
//*****************************************************************************
// Field:     [0] CCP_AND_EN
//
// Enables anding of the CCP outputs for timers A and B
#define GPT_ANDCCP_CCP_AND_EN                                       0x00000001
#define GPT_ANDCCP_CCP_AND_EN_BITN                                           0
#define GPT_ANDCCP_CCP_AND_EN_M                                     0x00000001
#define GPT_ANDCCP_CCP_AND_EN_S                                              0


#endif // __GPT__
