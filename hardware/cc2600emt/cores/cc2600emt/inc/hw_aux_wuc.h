/******************************************************************************
*  Filename:       hw_aux_wuc_h
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

#ifndef __HW_AUX_WUC_H__
#define __HW_AUX_WUC_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AUX_WUC component
//
//*****************************************************************************
// Module Clock Enable
#define AUX_WUC_O_MODCLKEN0                                         0x00000000

// Power Off Request
#define AUX_WUC_O_PWROFFREQ                                         0x00000004

// Power Down Request
#define AUX_WUC_O_PWRDWNREQ                                         0x00000008

// Power Down Acknowledgment
#define AUX_WUC_O_PWRDWNACK                                         0x0000000C

// Low Frequency Clock Request
#define AUX_WUC_O_CLKLFREQ                                          0x00000010

// Low Frequency Clock Acknowledgment
#define AUX_WUC_O_CLKLFACK                                          0x00000014

// Wake-up Event Flags
#define AUX_WUC_O_WUEVFLAGS                                         0x00000028

// Wake-up Event Clear
#define AUX_WUC_O_WUEVCLR                                           0x0000002C

// ADC Clock Control
#define AUX_WUC_O_ADCCLKCTL                                         0x00000030

// TDC Clock Control
#define AUX_WUC_O_TDCCLKCTL                                         0x00000034

// Reference Clock Control
#define AUX_WUC_O_REFCLKCTL                                         0x00000038

// Real Time Counter Sub Second Increment 0
#define AUX_WUC_O_RTCSUBSECINC0                                     0x0000003C

// Real Time Counter Sub Second Increment 1
#define AUX_WUC_O_RTCSUBSECINC1                                     0x00000040

// Real Time Counter Sub Second Increment Control
#define AUX_WUC_O_RTCSUBSECINCCTL                                   0x00000044

// MCU Bus Control
#define AUX_WUC_O_MCUBUSCTL                                         0x00000048

// MCU Bus Status
#define AUX_WUC_O_MCUBUSSTAT                                        0x0000004C

// AON Domain Control Status
#define AUX_WUC_O_AONCTLSTAT                                        0x00000050

// AUX Input Output Latch
#define AUX_WUC_O_AUXIOLATCH                                        0x00000054

// Module Clock Enable 1
#define AUX_WUC_O_MODCLKEN1                                         0x0000005C

//*****************************************************************************
//
// Register: AUX_WUC_O_MODCLKEN0
//
//*****************************************************************************
// Field:     [7] AUX_ADI4
//
// Enables (1) or disables (0) clock for AUX_ADI4.
// ENUMs:
// EN                       System CPU has requested clock for AUX_ADI4
// DIS                      System CPU has not requested clock for AUX_ADI4
#define AUX_WUC_MODCLKEN0_AUX_ADI4                                  0x00000080
#define AUX_WUC_MODCLKEN0_AUX_ADI4_BITN                                      7
#define AUX_WUC_MODCLKEN0_AUX_ADI4_M                                0x00000080
#define AUX_WUC_MODCLKEN0_AUX_ADI4_S                                         7
#define AUX_WUC_MODCLKEN0_AUX_ADI4_EN                               0x00000080
#define AUX_WUC_MODCLKEN0_AUX_ADI4_DIS                              0x00000000

// Field:     [6] AUX_DDI0_OSC
//
// Enables (1) or disables (0) clock for AUX_DDI0_OSC.
// ENUMs:
// EN                       System CPU has requested clock for AUX_DDI0_OSC
// DIS                      System CPU has not requested clock for
//                          AUX_DDI0_OSC
#define AUX_WUC_MODCLKEN0_AUX_DDI0_OSC                              0x00000040
#define AUX_WUC_MODCLKEN0_AUX_DDI0_OSC_BITN                                  6
#define AUX_WUC_MODCLKEN0_AUX_DDI0_OSC_M                            0x00000040
#define AUX_WUC_MODCLKEN0_AUX_DDI0_OSC_S                                     6
#define AUX_WUC_MODCLKEN0_AUX_DDI0_OSC_EN                           0x00000040
#define AUX_WUC_MODCLKEN0_AUX_DDI0_OSC_DIS                          0x00000000

// Field:     [5] TDC
//
// Enables (1) or disables (0) clock for AUX_TDCIF.
//
// Note that the TDC counter and reference clock sources must be requested
// separately using TDCCLKCTL and REFCLKCTL, respectively.
// ENUMs:
// EN                       System CPU has requested clock for TDC
// DIS                      System CPU has not requested clock for TDC
#define AUX_WUC_MODCLKEN0_TDC                                       0x00000020
#define AUX_WUC_MODCLKEN0_TDC_BITN                                           5
#define AUX_WUC_MODCLKEN0_TDC_M                                     0x00000020
#define AUX_WUC_MODCLKEN0_TDC_S                                              5
#define AUX_WUC_MODCLKEN0_TDC_EN                                    0x00000020
#define AUX_WUC_MODCLKEN0_TDC_DIS                                   0x00000000

// Field:     [4] ANAIF
//
// Enables (1) or disables (0) clock for AUX_ANAIF.
//
// Note that the ADC internal clock must be requested separately using
// ADCCLKCTL.
// ENUMs:
// EN                       System CPU has requested clock for ANAIF
// DIS                      System CPU has not requested clock for ANAIF
#define AUX_WUC_MODCLKEN0_ANAIF                                     0x00000010
#define AUX_WUC_MODCLKEN0_ANAIF_BITN                                         4
#define AUX_WUC_MODCLKEN0_ANAIF_M                                   0x00000010
#define AUX_WUC_MODCLKEN0_ANAIF_S                                            4
#define AUX_WUC_MODCLKEN0_ANAIF_EN                                  0x00000010
#define AUX_WUC_MODCLKEN0_ANAIF_DIS                                 0x00000000

// Field:     [3] TIMER
//
// Enables (1) or disables (0) clock for AUX_TIMER.
// ENUMs:
// EN                       System CPU has requested clock for TIMER
// DIS                      System CPU has not requested clock for TIMER
#define AUX_WUC_MODCLKEN0_TIMER                                     0x00000008
#define AUX_WUC_MODCLKEN0_TIMER_BITN                                         3
#define AUX_WUC_MODCLKEN0_TIMER_M                                   0x00000008
#define AUX_WUC_MODCLKEN0_TIMER_S                                            3
#define AUX_WUC_MODCLKEN0_TIMER_EN                                  0x00000008
#define AUX_WUC_MODCLKEN0_TIMER_DIS                                 0x00000000

// Field:     [2] AIODIO1
//
// Enables (1) or disables (0) clock for AUX_AIODIO1.
// ENUMs:
// EN                       System CPU has requested clock for AIODIO1
// DIS                      System CPU has not requested clock for AIODIO1
#define AUX_WUC_MODCLKEN0_AIODIO1                                   0x00000004
#define AUX_WUC_MODCLKEN0_AIODIO1_BITN                                       2
#define AUX_WUC_MODCLKEN0_AIODIO1_M                                 0x00000004
#define AUX_WUC_MODCLKEN0_AIODIO1_S                                          2
#define AUX_WUC_MODCLKEN0_AIODIO1_EN                                0x00000004
#define AUX_WUC_MODCLKEN0_AIODIO1_DIS                               0x00000000

// Field:     [1] AIODIO0
//
// Enables (1) or disables (0) clock for AUX_AIODIO0.
// ENUMs:
// EN                       System CPU has requested clock for AIODIO0
// DIS                      System CPU has not requested clock for AIODIO0
#define AUX_WUC_MODCLKEN0_AIODIO0                                   0x00000002
#define AUX_WUC_MODCLKEN0_AIODIO0_BITN                                       1
#define AUX_WUC_MODCLKEN0_AIODIO0_M                                 0x00000002
#define AUX_WUC_MODCLKEN0_AIODIO0_S                                          1
#define AUX_WUC_MODCLKEN0_AIODIO0_EN                                0x00000002
#define AUX_WUC_MODCLKEN0_AIODIO0_DIS                               0x00000000

// Field:     [0] SMPH
//
// Enables (1) or disables (0) clock for AUX_SMPH.
// ENUMs:
// EN                       System CPU has requested clock for SMPH
// DIS                      System CPU has not requested clock for SMPH
#define AUX_WUC_MODCLKEN0_SMPH                                      0x00000001
#define AUX_WUC_MODCLKEN0_SMPH_BITN                                          0
#define AUX_WUC_MODCLKEN0_SMPH_M                                    0x00000001
#define AUX_WUC_MODCLKEN0_SMPH_S                                             0
#define AUX_WUC_MODCLKEN0_SMPH_EN                                   0x00000001
#define AUX_WUC_MODCLKEN0_SMPH_DIS                                  0x00000000

//*****************************************************************************
//
// Register: AUX_WUC_O_PWROFFREQ
//
//*****************************************************************************
// Field:     [0] REQ
//
// Power off request
//
// 0: No action
// 1: Request to power down AUX. Once set, this bit shall not be cleared. The
// bit will be reset again when AUX is powered up again.
//
// The request will only happen if AONCTLSTAT.AUX_FORCE_ON = 0 and
// MCUBUSSTAT.DISCONNECTED=1.
#define AUX_WUC_PWROFFREQ_REQ                                       0x00000001
#define AUX_WUC_PWROFFREQ_REQ_BITN                                           0
#define AUX_WUC_PWROFFREQ_REQ_M                                     0x00000001
#define AUX_WUC_PWROFFREQ_REQ_S                                              0

//*****************************************************************************
//
// Register: AUX_WUC_O_PWRDWNREQ
//
//*****************************************************************************
// Field:     [0] REQ
//
// Power down request
//
// 0: Request for system to be in active mode
// 1: Request for system to be in power down mode
//
// When REQ is 1 one shall assume that the system is in power down, and that
// current supply is limited. When setting REQ = 0, one shall assume that the
// system is in power down until  PWRDWNACK.ACK = 0
#define AUX_WUC_PWRDWNREQ_REQ                                       0x00000001
#define AUX_WUC_PWRDWNREQ_REQ_BITN                                           0
#define AUX_WUC_PWRDWNREQ_REQ_M                                     0x00000001
#define AUX_WUC_PWRDWNREQ_REQ_S                                              0

//*****************************************************************************
//
// Register: AUX_WUC_O_PWRDWNACK
//
//*****************************************************************************
// Field:     [0] ACK
//
// Power down acknowledgment. Indicates whether the power down request given by
// PWRDWNREQ.REQ is captured by the AON domain or not
//
// 0: AUX can assume that the system is in active mode
// 1: The request for power down is acknowledged and the AUX must act like the
// system is in power down mode and power supply is limited
//
// The system CPU cannot use this bit since the bus bridge between MCU domain
// and AUX domain is always disconnected when this bit is set. For AUX_SCE use
// only
#define AUX_WUC_PWRDWNACK_ACK                                       0x00000001
#define AUX_WUC_PWRDWNACK_ACK_BITN                                           0
#define AUX_WUC_PWRDWNACK_ACK_M                                     0x00000001
#define AUX_WUC_PWRDWNACK_ACK_S                                              0

//*****************************************************************************
//
// Register: AUX_WUC_O_CLKLFREQ
//
//*****************************************************************************
// Field:     [0] REQ
//
// Low frequency request
//
// 0: Request clock frequency to be controlled by AON_WUC:AUXCLK and the system
// state
// 1: Request low frequency clock SCLK_LF as the clock source for AUX
//
// This bit must not be modified unless CLKLFACK.ACK matches the current value
#define AUX_WUC_CLKLFREQ_REQ                                        0x00000001
#define AUX_WUC_CLKLFREQ_REQ_BITN                                            0
#define AUX_WUC_CLKLFREQ_REQ_M                                      0x00000001
#define AUX_WUC_CLKLFREQ_REQ_S                                               0

//*****************************************************************************
//
// Register: AUX_WUC_O_CLKLFACK
//
//*****************************************************************************
// Field:     [0] ACK
//
// Acknowledgment of CLKLFREQ.REQ
//
// 0: Acknowledgement that clock frequency is controlled by AON_WUC:AUXCLK and
// the system state
// 1: Acknowledgement that the low frequency clock SCLK_LF is the clock source
// for AUX
#define AUX_WUC_CLKLFACK_ACK                                        0x00000001
#define AUX_WUC_CLKLFACK_ACK_BITN                                            0
#define AUX_WUC_CLKLFACK_ACK_M                                      0x00000001
#define AUX_WUC_CLKLFACK_ACK_S                                               0

//*****************************************************************************
//
// Register: AUX_WUC_O_WUEVFLAGS
//
//*****************************************************************************
// Field:     [2] AON_RTC_CH2
//
// Indicates pending event from AON_RTC_CH2 compare. Note that this flag will
// be set whenever the AON_RTC_CH2 event happens, but that does not mean that
// this event is a wake-up event. To make the AON_RTC_CH2 a wake-up event for
// the AUX domain configure it as a wake-up event in AON_EVENT:AUXWUSEL.WU0_EV,
// AON_EVENT:AUXWUSEL.WU1_EV or AON_EVENT:AUXWUSEL.WU2_EV.
#define AUX_WUC_WUEVFLAGS_AON_RTC_CH2                               0x00000004
#define AUX_WUC_WUEVFLAGS_AON_RTC_CH2_BITN                                   2
#define AUX_WUC_WUEVFLAGS_AON_RTC_CH2_M                             0x00000004
#define AUX_WUC_WUEVFLAGS_AON_RTC_CH2_S                                      2

// Field:     [1] AON_SW
//
// Indicates pending event triggered by system CPU writing a 1 to
// AON_WUC:AUXCTL.SWEV.
#define AUX_WUC_WUEVFLAGS_AON_SW                                    0x00000002
#define AUX_WUC_WUEVFLAGS_AON_SW_BITN                                        1
#define AUX_WUC_WUEVFLAGS_AON_SW_M                                  0x00000002
#define AUX_WUC_WUEVFLAGS_AON_SW_S                                           1

// Field:     [0] AON_PROG_WU
//
// Indicates pending event triggered by the sources selected in
// AON_EVENT:AUXWUSEL.WU0_EV, AON_EVENT:AUXWUSEL.WU1_EV and
// AON_EVENT:AUXWUSEL.WU2_EV.
#define AUX_WUC_WUEVFLAGS_AON_PROG_WU                               0x00000001
#define AUX_WUC_WUEVFLAGS_AON_PROG_WU_BITN                                   0
#define AUX_WUC_WUEVFLAGS_AON_PROG_WU_M                             0x00000001
#define AUX_WUC_WUEVFLAGS_AON_PROG_WU_S                                      0

//*****************************************************************************
//
// Register: AUX_WUC_O_WUEVCLR
//
//*****************************************************************************
// Field:     [2] AON_RTC_CH2
//
// Set to clear the WUEVFLAGS.AON_RTC_CH2 wake-up event. Note that if RTC
// channel 2 is also set as source for AON_PROG_WU this field can also clear
// WUEVFLAGS.AON_PROG_WU
//
// This bit must remain set until WUEVFLAGS.AON_RTC_CH2 returns to 0.
#define AUX_WUC_WUEVCLR_AON_RTC_CH2                                 0x00000004
#define AUX_WUC_WUEVCLR_AON_RTC_CH2_BITN                                     2
#define AUX_WUC_WUEVCLR_AON_RTC_CH2_M                               0x00000004
#define AUX_WUC_WUEVCLR_AON_RTC_CH2_S                                        2

// Field:     [1] AON_SW
//
// Set to clear the WUEVFLAGS.AON_SW wake-up event.
//
// This bit must remain set until WUEVFLAGS.AON_SW returns to 0.
#define AUX_WUC_WUEVCLR_AON_SW                                      0x00000002
#define AUX_WUC_WUEVCLR_AON_SW_BITN                                          1
#define AUX_WUC_WUEVCLR_AON_SW_M                                    0x00000002
#define AUX_WUC_WUEVCLR_AON_SW_S                                             1

// Field:     [0] AON_PROG_WU
//
// Set to clear the WUEVFLAGS.AON_PROG_WU wake-up event. Note only if an IO
// event is selected as wake-up event, is it possible to use this field to
// clear the source. Other sources cannot be cleared using this field.
//
// The IO pin needs to be assigned to AUX in the IOC and the input enable for
// the pin needs to be set in AIODIO0 or AIODIO1 for this clearing to take
// effect.
//
// This bit must remain set until WUEVFLAGS.AON_PROG_WU returns to 0.
#define AUX_WUC_WUEVCLR_AON_PROG_WU                                 0x00000001
#define AUX_WUC_WUEVCLR_AON_PROG_WU_BITN                                     0
#define AUX_WUC_WUEVCLR_AON_PROG_WU_M                               0x00000001
#define AUX_WUC_WUEVCLR_AON_PROG_WU_S                                        0

//*****************************************************************************
//
// Register: AUX_WUC_O_ADCCLKCTL
//
//*****************************************************************************
// Field:     [1] ACK
//
// Acknowledges the last value written to REQ.
#define AUX_WUC_ADCCLKCTL_ACK                                       0x00000002
#define AUX_WUC_ADCCLKCTL_ACK_BITN                                           1
#define AUX_WUC_ADCCLKCTL_ACK_M                                     0x00000002
#define AUX_WUC_ADCCLKCTL_ACK_S                                              1

// Field:     [0] REQ
//
// Enables(1) or disables (0) the ADC internal clock.
//
// This bit must not be modified unless ACK matches the current value.
#define AUX_WUC_ADCCLKCTL_REQ                                       0x00000001
#define AUX_WUC_ADCCLKCTL_REQ_BITN                                           0
#define AUX_WUC_ADCCLKCTL_REQ_M                                     0x00000001
#define AUX_WUC_ADCCLKCTL_REQ_S                                              0

//*****************************************************************************
//
// Register: AUX_WUC_O_TDCCLKCTL
//
//*****************************************************************************
// Field:     [1] ACK
//
// Acknowledges the last value written to REQ.
#define AUX_WUC_TDCCLKCTL_ACK                                       0x00000002
#define AUX_WUC_TDCCLKCTL_ACK_BITN                                           1
#define AUX_WUC_TDCCLKCTL_ACK_M                                     0x00000002
#define AUX_WUC_TDCCLKCTL_ACK_S                                              1

// Field:     [0] REQ
//
// Enables(1) or disables (0) the TDC counter clock source.
//
// This bit must not be modified unless ACK matches the current value.
#define AUX_WUC_TDCCLKCTL_REQ                                       0x00000001
#define AUX_WUC_TDCCLKCTL_REQ_BITN                                           0
#define AUX_WUC_TDCCLKCTL_REQ_M                                     0x00000001
#define AUX_WUC_TDCCLKCTL_REQ_S                                              0

//*****************************************************************************
//
// Register: AUX_WUC_O_REFCLKCTL
//
//*****************************************************************************
// Field:     [1] ACK
//
// Acknowledges the last value written to REQ.
#define AUX_WUC_REFCLKCTL_ACK                                       0x00000002
#define AUX_WUC_REFCLKCTL_ACK_BITN                                           1
#define AUX_WUC_REFCLKCTL_ACK_M                                     0x00000002
#define AUX_WUC_REFCLKCTL_ACK_S                                              1

// Field:     [0] REQ
//
// Enables(1) or disables (0) the TDC reference clock source.
//
// This bit must not be modified unless ACK matches the current value.
#define AUX_WUC_REFCLKCTL_REQ                                       0x00000001
#define AUX_WUC_REFCLKCTL_REQ_BITN                                           0
#define AUX_WUC_REFCLKCTL_REQ_M                                     0x00000001
#define AUX_WUC_REFCLKCTL_REQ_S                                              0

//*****************************************************************************
//
// Register: AUX_WUC_O_RTCSUBSECINC0
//
//*****************************************************************************
// Field:  [15:0] INC15_0
//
// Bits 15:0 of the RTC sub-second increment value.
#define AUX_WUC_RTCSUBSECINC0_INC15_0_W                                     16
#define AUX_WUC_RTCSUBSECINC0_INC15_0_M                             0x0000FFFF
#define AUX_WUC_RTCSUBSECINC0_INC15_0_S                                      0

//*****************************************************************************
//
// Register: AUX_WUC_O_RTCSUBSECINC1
//
//*****************************************************************************
// Field:   [7:0] INC23_16
//
// Bits 23:16 of the RTC sub-second increment value.
#define AUX_WUC_RTCSUBSECINC1_INC23_16_W                                     8
#define AUX_WUC_RTCSUBSECINC1_INC23_16_M                            0x000000FF
#define AUX_WUC_RTCSUBSECINC1_INC23_16_S                                     0

//*****************************************************************************
//
// Register: AUX_WUC_O_RTCSUBSECINCCTL
//
//*****************************************************************************
// Field:     [1] UPD_ACK
//
// Acknowledgment of the UPD_REQ.
#define AUX_WUC_RTCSUBSECINCCTL_UPD_ACK                             0x00000002
#define AUX_WUC_RTCSUBSECINCCTL_UPD_ACK_BITN                                 1
#define AUX_WUC_RTCSUBSECINCCTL_UPD_ACK_M                           0x00000002
#define AUX_WUC_RTCSUBSECINCCTL_UPD_ACK_S                                    1

// Field:     [0] UPD_REQ
//
// Signal that a new real time counter sub second increment value is available
//
// 0: New sub second increment is not available
// 1: New sub second increment is available
//
// This bit must not be modified unless UPD_ACK matches the current value.
#define AUX_WUC_RTCSUBSECINCCTL_UPD_REQ                             0x00000001
#define AUX_WUC_RTCSUBSECINCCTL_UPD_REQ_BITN                                 0
#define AUX_WUC_RTCSUBSECINCCTL_UPD_REQ_M                           0x00000001
#define AUX_WUC_RTCSUBSECINCCTL_UPD_REQ_S                                    0

//*****************************************************************************
//
// Register: AUX_WUC_O_MCUBUSCTL
//
//*****************************************************************************
// Field:     [0] DISCONNECT_REQ
//
// Requests the AUX domain bus to be disconnected from the MCU domain bus. The
// request has no effect when AON_WUC:AUX_CTL.AUX_FORCE_ON is set.
//
// The disconnection status can be monitored through MCUBUSSTAT. Note however
// that this register cannot be read by the system CPU while disconnected.
//
// It is recommended that this bit is set and remains set after initial
// power-up, and that the system CPU uses AON_WUC:AUX_CTL.AUX_FORCE_ON to
// connect/disconnect the bus.
#define AUX_WUC_MCUBUSCTL_DISCONNECT_REQ                            0x00000001
#define AUX_WUC_MCUBUSCTL_DISCONNECT_REQ_BITN                                0
#define AUX_WUC_MCUBUSCTL_DISCONNECT_REQ_M                          0x00000001
#define AUX_WUC_MCUBUSCTL_DISCONNECT_REQ_S                                   0

//*****************************************************************************
//
// Register: AUX_WUC_O_MCUBUSSTAT
//
//*****************************************************************************
// Field:     [1] DISCONNECTED
//
// Indicates whether the AUX domain and MCU domain buses are currently
// disconnected (1) or connected (0).
#define AUX_WUC_MCUBUSSTAT_DISCONNECTED                             0x00000002
#define AUX_WUC_MCUBUSSTAT_DISCONNECTED_BITN                                 1
#define AUX_WUC_MCUBUSSTAT_DISCONNECTED_M                           0x00000002
#define AUX_WUC_MCUBUSSTAT_DISCONNECTED_S                                    1

// Field:     [0] DISCONNECT_ACK
//
// Acknowledges reception of the bus disconnection request, by matching the
// value of MCUBUSCTL.DISCONNECT_REQ.
//
// Note that if AON_WUC:AUXCTL.AUX_FORCE_ON = 1 a reconnect to the MCU domain
// bus will be made regardless of the state of MCUBUSCTL.DISCONNECT_REQ
#define AUX_WUC_MCUBUSSTAT_DISCONNECT_ACK                           0x00000001
#define AUX_WUC_MCUBUSSTAT_DISCONNECT_ACK_BITN                               0
#define AUX_WUC_MCUBUSSTAT_DISCONNECT_ACK_M                         0x00000001
#define AUX_WUC_MCUBUSSTAT_DISCONNECT_ACK_S                                  0

//*****************************************************************************
//
// Register: AUX_WUC_O_AONCTLSTAT
//
//*****************************************************************************
// Field:     [1] AUX_FORCE_ON
//
// Status of AON_WUC:AUX_CTL.AUX_FORCE_ON.
#define AUX_WUC_AONCTLSTAT_AUX_FORCE_ON                             0x00000002
#define AUX_WUC_AONCTLSTAT_AUX_FORCE_ON_BITN                                 1
#define AUX_WUC_AONCTLSTAT_AUX_FORCE_ON_M                           0x00000002
#define AUX_WUC_AONCTLSTAT_AUX_FORCE_ON_S                                    1

// Field:     [0] SCE_RUN_EN
//
// Status of AON_WUC:AUX_CTL.SCE_RUN_EN.
#define AUX_WUC_AONCTLSTAT_SCE_RUN_EN                               0x00000001
#define AUX_WUC_AONCTLSTAT_SCE_RUN_EN_BITN                                   0
#define AUX_WUC_AONCTLSTAT_SCE_RUN_EN_M                             0x00000001
#define AUX_WUC_AONCTLSTAT_SCE_RUN_EN_S                                      0

//*****************************************************************************
//
// Register: AUX_WUC_O_AUXIOLATCH
//
//*****************************************************************************
// Field:     [0] EN
//
// Opens (1) or closes (0) the AUX_AIODIO0/AUX_AIODIO1 signal latching.
//
// At startup, set EN = TRANSP before configuring AUX_AIODIO0/AUX_AIODIO1 and
// subsequently selecting AUX mode in the AON_IOC.
//
// When powering off the AUX domain (using PWROFFREQ.REQ), set EN = STATIC in
// advance preserve the current state (mode and output value) of the I/O pins.
// ENUMs:
// TRANSP                   Latches are transparent ( open )
// STATIC                   Latches are static ( closed )
#define AUX_WUC_AUXIOLATCH_EN                                       0x00000001
#define AUX_WUC_AUXIOLATCH_EN_BITN                                           0
#define AUX_WUC_AUXIOLATCH_EN_M                                     0x00000001
#define AUX_WUC_AUXIOLATCH_EN_S                                              0
#define AUX_WUC_AUXIOLATCH_EN_TRANSP                                0x00000001
#define AUX_WUC_AUXIOLATCH_EN_STATIC                                0x00000000

//*****************************************************************************
//
// Register: AUX_WUC_O_MODCLKEN1
//
//*****************************************************************************
// Field:     [7] AUX_ADI4
//
// Enables (1) or disables (0) clock for AUX_ADI4.
// ENUMs:
// EN                       AUX_SCE has requested clock for AUX_ADI4
// DIS                      AUX_SCE has not requested clock for AUX_ADI4
#define AUX_WUC_MODCLKEN1_AUX_ADI4                                  0x00000080
#define AUX_WUC_MODCLKEN1_AUX_ADI4_BITN                                      7
#define AUX_WUC_MODCLKEN1_AUX_ADI4_M                                0x00000080
#define AUX_WUC_MODCLKEN1_AUX_ADI4_S                                         7
#define AUX_WUC_MODCLKEN1_AUX_ADI4_EN                               0x00000080
#define AUX_WUC_MODCLKEN1_AUX_ADI4_DIS                              0x00000000

// Field:     [6] AUX_DDI0_OSC
//
// Enables (1) or disables (0) clock for AUX_DDI0_OSC.
// ENUMs:
// EN                       AUX_SCE has requested clock for AUX_DDI0_OSC
// DIS                      AUX_SCE has not requested clock for AUX_DDI0_OSC
#define AUX_WUC_MODCLKEN1_AUX_DDI0_OSC                              0x00000040
#define AUX_WUC_MODCLKEN1_AUX_DDI0_OSC_BITN                                  6
#define AUX_WUC_MODCLKEN1_AUX_DDI0_OSC_M                            0x00000040
#define AUX_WUC_MODCLKEN1_AUX_DDI0_OSC_S                                     6
#define AUX_WUC_MODCLKEN1_AUX_DDI0_OSC_EN                           0x00000040
#define AUX_WUC_MODCLKEN1_AUX_DDI0_OSC_DIS                          0x00000000

// Field:     [4] ANAIF
//
// Enables (1) or disables (0) clock for AUX_ANAIF.
// ENUMs:
// EN                       AUX_SCE has requested clock for ANAIF
// DIS                      AUX_SCE has not requested clock for ANAIF
#define AUX_WUC_MODCLKEN1_ANAIF                                     0x00000010
#define AUX_WUC_MODCLKEN1_ANAIF_BITN                                         4
#define AUX_WUC_MODCLKEN1_ANAIF_M                                   0x00000010
#define AUX_WUC_MODCLKEN1_ANAIF_S                                            4
#define AUX_WUC_MODCLKEN1_ANAIF_EN                                  0x00000010
#define AUX_WUC_MODCLKEN1_ANAIF_DIS                                 0x00000000

// Field:     [3] TIMER
//
// Enables (1) or disables (0) clock for AUX_TIMER.
// ENUMs:
// EN                       AUX_SCE has requested clock for TIMER
// DIS                      AUX_SCE has not requested clock for TIMER
#define AUX_WUC_MODCLKEN1_TIMER                                     0x00000008
#define AUX_WUC_MODCLKEN1_TIMER_BITN                                         3
#define AUX_WUC_MODCLKEN1_TIMER_M                                   0x00000008
#define AUX_WUC_MODCLKEN1_TIMER_S                                            3
#define AUX_WUC_MODCLKEN1_TIMER_EN                                  0x00000008
#define AUX_WUC_MODCLKEN1_TIMER_DIS                                 0x00000000

// Field:     [2] AIODIO1
//
// Enables (1) or disables (0) clock for AUX_AIODIO1.
// ENUMs:
// EN                       AUX_SCE has requested clock for AIODIO1
// DIS                      AUX_SCE has not requested clock for AIODIO1
#define AUX_WUC_MODCLKEN1_AIODIO1                                   0x00000004
#define AUX_WUC_MODCLKEN1_AIODIO1_BITN                                       2
#define AUX_WUC_MODCLKEN1_AIODIO1_M                                 0x00000004
#define AUX_WUC_MODCLKEN1_AIODIO1_S                                          2
#define AUX_WUC_MODCLKEN1_AIODIO1_EN                                0x00000004
#define AUX_WUC_MODCLKEN1_AIODIO1_DIS                               0x00000000

// Field:     [1] AIODIO0
//
// Enables (1) or disables (0) clock for AUX_AIODIO0.
// ENUMs:
// EN                       AUX_SCE has requested clock for AIODIO0
// DIS                      AUX_SCE has not requested clock for AIODIO0
#define AUX_WUC_MODCLKEN1_AIODIO0                                   0x00000002
#define AUX_WUC_MODCLKEN1_AIODIO0_BITN                                       1
#define AUX_WUC_MODCLKEN1_AIODIO0_M                                 0x00000002
#define AUX_WUC_MODCLKEN1_AIODIO0_S                                          1
#define AUX_WUC_MODCLKEN1_AIODIO0_EN                                0x00000002
#define AUX_WUC_MODCLKEN1_AIODIO0_DIS                               0x00000000

// Field:     [0] SMPH
//
// Enables (1) or disables (0) clock for AUX_SMPH.
// ENUMs:
// EN                       AUX_SCE has requested clock for SMPH
// DIS                      AUX_SCE has not requested clock for SMPH
#define AUX_WUC_MODCLKEN1_SMPH                                      0x00000001
#define AUX_WUC_MODCLKEN1_SMPH_BITN                                          0
#define AUX_WUC_MODCLKEN1_SMPH_M                                    0x00000001
#define AUX_WUC_MODCLKEN1_SMPH_S                                             0
#define AUX_WUC_MODCLKEN1_SMPH_EN                                   0x00000001
#define AUX_WUC_MODCLKEN1_SMPH_DIS                                  0x00000000


#endif // __AUX_WUC__
