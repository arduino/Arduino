/******************************************************************************
*  Filename:       hw_aon_sysctl_h
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

#ifndef __HW_AON_SYSCTL_H__
#define __HW_AON_SYSCTL_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AON_SYSCTL component
//
//*****************************************************************************
// Power Management
#define AON_SYSCTL_O_PWRCTL                                         0x00000000

// Reset Management
#define AON_SYSCTL_O_RESETCTL                                       0x00000004

// Sleep Mode
#define AON_SYSCTL_O_SLEEPCTL                                       0x00000008

//*****************************************************************************
//
// Register: AON_SYSCTL_O_PWRCTL
//
//*****************************************************************************
// Field:     [2] DCDC_ACTIVE
//
// Select to use DCDC regulator for VDDR in active mode
//
// 0: Use GLDO for regulation of VDDRin active mode.
// 1: Use DCDC for regulation of VDDRin active mode.
#define AON_SYSCTL_PWRCTL_DCDC_ACTIVE                               0x00000004
#define AON_SYSCTL_PWRCTL_DCDC_ACTIVE_BITN                                   2
#define AON_SYSCTL_PWRCTL_DCDC_ACTIVE_M                             0x00000004
#define AON_SYSCTL_PWRCTL_DCDC_ACTIVE_S                                      2

// Field:     [1] EXT_REG_MODE
//
// Status of source for VDDRsupply:
//
// 0: DCDC/GLDO are generating VDDR
// 1: DCDC/GLDO are bypassed, external regulator supplies VDDR
#define AON_SYSCTL_PWRCTL_EXT_REG_MODE                              0x00000002
#define AON_SYSCTL_PWRCTL_EXT_REG_MODE_BITN                                  1
#define AON_SYSCTL_PWRCTL_EXT_REG_MODE_M                            0x00000002
#define AON_SYSCTL_PWRCTL_EXT_REG_MODE_S                                     1

// Field:     [0] DCDC_EN
//
// Select to use DCDC regulator during recharge of VDDR
//
// 0: Use GLDO for recharge of VDDR
// 1: Use DCDC for recharge of VDDR
//
// Note: This bitfield should be set to the same as DCDC_ACTIVE
#define AON_SYSCTL_PWRCTL_DCDC_EN                                   0x00000001
#define AON_SYSCTL_PWRCTL_DCDC_EN_BITN                                       0
#define AON_SYSCTL_PWRCTL_DCDC_EN_M                                 0x00000001
#define AON_SYSCTL_PWRCTL_DCDC_EN_S                                          0

//*****************************************************************************
//
// Register: AON_SYSCTL_O_RESETCTL
//
//*****************************************************************************
// Field:    [31] SYSRESET
//
// Cold reset register. Writing 1 to this bitfield will reset the entire chip
// and cause boot code to run again.
//
// 0: No effect
// 1: Generate system reset. Appears as SYSRESET in RESET_SRC.
#define AON_SYSCTL_RESETCTL_SYSRESET                                0x80000000
#define AON_SYSCTL_RESETCTL_SYSRESET_BITN                                   31
#define AON_SYSCTL_RESETCTL_SYSRESET_M                              0x80000000
#define AON_SYSCTL_RESETCTL_SYSRESET_S                                      31

// Field:    [25] BOOT_DET_1_CLR
//
// Internal. Only to be used through TI provided API.
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_CLR                          0x02000000
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_CLR_BITN                             25
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_CLR_M                        0x02000000
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_CLR_S                                25

// Field:    [24] BOOT_DET_0_CLR
//
// Internal. Only to be used through TI provided API.
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_CLR                          0x01000000
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_CLR_BITN                             24
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_CLR_M                        0x01000000
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_CLR_S                                24

// Field:    [17] BOOT_DET_1_SET
//
// Internal. Only to be used through TI provided API.
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_SET                          0x00020000
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_SET_BITN                             17
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_SET_M                        0x00020000
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_SET_S                                17

// Field:    [16] BOOT_DET_0_SET
//
// Internal. Only to be used through TI provided API.
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_SET                          0x00010000
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_SET_BITN                             16
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_SET_M                        0x00010000
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_SET_S                                16

// Field:    [15] WU_FROM_SD
//
// A Wakeup from SHUTDOWN on an IO event has occurred, or a wakeup from
// SHUTDOWN has occurred as a result of the debugger being attached.. (TCK pin
// being forced low)
//
// Please refer to [IOC:IOCFGn,.WU_CFG] for configuring the IO's as wakeup
// sources.
//
// 0: Wakeup occurred from cold reset or brown out as seen in RESET_SRC
// 1: A wakeup has occurred from SHUTDOWN
//
// Note: This flag can not be cleared and will therefor remain valid untill
// poweroff/reset
#define AON_SYSCTL_RESETCTL_WU_FROM_SD                              0x00008000
#define AON_SYSCTL_RESETCTL_WU_FROM_SD_BITN                                 15
#define AON_SYSCTL_RESETCTL_WU_FROM_SD_M                            0x00008000
#define AON_SYSCTL_RESETCTL_WU_FROM_SD_S                                    15

// Field:    [14] GPIO_WU_FROM_SD
//
// A wakeup from SHUTDOWN on an IO event has occurred
//
// Please refer to [IOC:IOCFGn,.WU_CFG] for configuring the IO's as wakeup
// sources.
//
// 0: The wakeup did not occur from SHUTDOWN on an IO event
// 1: A wakeup from SHUTDOWN occurred from an IO event
//
// The case where WU_FROM_SD is asserted but this bitfield is not asserted will
// only occur in a debug session. The boot code will not proceed with wakeup
// from SHUTDOWN procedure until this bitfield is asserted as well.
//
// Note: This flag can not be cleared and will therefor remain valid untill
// poweroff/reset
#define AON_SYSCTL_RESETCTL_GPIO_WU_FROM_SD                         0x00004000
#define AON_SYSCTL_RESETCTL_GPIO_WU_FROM_SD_BITN                            14
#define AON_SYSCTL_RESETCTL_GPIO_WU_FROM_SD_M                       0x00004000
#define AON_SYSCTL_RESETCTL_GPIO_WU_FROM_SD_S                               14

// Field:    [13] BOOT_DET_1
//
// Internal. Only to be used through TI provided API.
#define AON_SYSCTL_RESETCTL_BOOT_DET_1                              0x00002000
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_BITN                                 13
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_M                            0x00002000
#define AON_SYSCTL_RESETCTL_BOOT_DET_1_S                                    13

// Field:    [12] BOOT_DET_0
//
// Internal. Only to be used through TI provided API.
#define AON_SYSCTL_RESETCTL_BOOT_DET_0                              0x00001000
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_BITN                                 12
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_M                            0x00001000
#define AON_SYSCTL_RESETCTL_BOOT_DET_0_S                                    12

// Field:    [11] VDDS_LOSS_EN_OVR
//
// Override of VDDS_LOSS_EN
//
// 0: Brown out detect of VDDS is ignored, unless VDDS_LOSS_EN=1
// 1: Brown out detect of VDDS generates system reset (regardless of
// VDDS_LOSS_EN)
//
// This bit can be locked
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_OVR                        0x00000800
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_OVR_BITN                           11
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_OVR_M                      0x00000800
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_OVR_S                              11

// Field:    [10] VDDR_LOSS_EN_OVR
//
// Override of VDDR_LOSS_EN
//
// 0: Brown out detect of VDDR is ignored, unless VDDR_LOSS_EN=1
// 1: Brown out detect of VDDR generates system reset (regardless of
// VDDR_LOSS_EN)
//
// This bit can be locked
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_OVR                        0x00000400
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_OVR_BITN                           10
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_OVR_M                      0x00000400
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_OVR_S                              10

// Field:     [9] VDD_LOSS_EN_OVR
//
// Override of VDD_LOSS_EN
//
// 0: Brown out detect of VDD is ignored, unless VDD_LOSS_EN=1
// 1: Brown out detect of VDD generates system reset (regardless of
// VDD_LOSS_EN)
//
// This bit can be locked
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_OVR                         0x00000200
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_OVR_BITN                             9
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_OVR_M                       0x00000200
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_OVR_S                                9

// Field:     [7] VDDS_LOSS_EN
//
// Controls reset generation in case VDDS is lost
//
// 0: Brown out detect of VDDS is ignored, unless VDDS_LOSS_EN_OVR=1
// 1: Brown out detect of VDDS generates system reset
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN                            0x00000080
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_BITN                                7
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_M                          0x00000080
#define AON_SYSCTL_RESETCTL_VDDS_LOSS_EN_S                                   7

// Field:     [6] VDDR_LOSS_EN
//
// Controls reset generation in case VDDR is lost
//
// 0: Brown out detect of VDDR is ignored, unless VDDR_LOSS_EN_OVR=1
// 1: Brown out detect of VDDR generates system reset
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN                            0x00000040
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_BITN                                6
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_M                          0x00000040
#define AON_SYSCTL_RESETCTL_VDDR_LOSS_EN_S                                   6

// Field:     [5] VDD_LOSS_EN
//
// Controls reset generation in case VDD is lost
//
// 0: Brown out detect of VDD is ignored, unless VDD_LOSS_EN_OVR=1
// 1: Brown out detect of VDD generates system reset
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN                             0x00000020
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_BITN                                 5
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_M                           0x00000020
#define AON_SYSCTL_RESETCTL_VDD_LOSS_EN_S                                    5

// Field:     [4] CLK_LOSS_EN
//
// Controls reset generation in case SCLK_LF is lost.  (provided that clock
// loss detection is enabled by DDI_0_OSC:CTL0.CLK_LOSS_EN)
//
// Note: Clock loss reset generation must be disabled before SCLK_LF clock
// source is changed in  DDI_0_OSC:CTL0.SCLK_LF_SRC_SEL and remain disabled
// untill the change is confirmed in DDI_0_OSC:STAT0.SCLK_LF_SRC. Failure to do
// so may result in a spurious system reset. Clock loss reset generation can be
// disabled through this bitfield or by clearing  DDI_0_OSC:CTL0.CLK_LOSS_EN
//
// 0: Clock loss is ignored
// 1: Clock loss generates system reset
#define AON_SYSCTL_RESETCTL_CLK_LOSS_EN                             0x00000010
#define AON_SYSCTL_RESETCTL_CLK_LOSS_EN_BITN                                 4
#define AON_SYSCTL_RESETCTL_CLK_LOSS_EN_M                           0x00000010
#define AON_SYSCTL_RESETCTL_CLK_LOSS_EN_S                                    4

// Field:   [3:1] RESET_SRC
//
// Shows the source of the last system reset:
// Occurrence of one of the reset sources may trigger several other reset
// sources as essential parts of the system are undergoing reset. This field
// will report the root cause of the reset (not the other resets that are
// consequence of the system reset).
// To support this feature the actual register is not captured before the reset
// source being released. If a new reset source is triggered, in a window of
// four  32 kHz periods after the previous has been released,  this register
// may indicate Power on reset as source.
// ENUMs:
// WARMRESET                Software reset via PRCM warm reset request
// SYSRESET                 Software reset via SYSRESET register
// CLK_LOSS                 Clock loss detect
// VDDR_LOSS                Brown out detect on VDDR
// VDD_LOSS                 Brown out detect on VDD
// VDDS_LOSS                Brown out detect on VDDS
// PIN_RESET                Reset pin
// PWR_ON                   Power on reset
#define AON_SYSCTL_RESETCTL_RESET_SRC_W                                      3
#define AON_SYSCTL_RESETCTL_RESET_SRC_M                             0x0000000E
#define AON_SYSCTL_RESETCTL_RESET_SRC_S                                      1
#define AON_SYSCTL_RESETCTL_RESET_SRC_WARMRESET                     0x0000000E
#define AON_SYSCTL_RESETCTL_RESET_SRC_SYSRESET                      0x0000000C
#define AON_SYSCTL_RESETCTL_RESET_SRC_CLK_LOSS                      0x0000000A
#define AON_SYSCTL_RESETCTL_RESET_SRC_VDDR_LOSS                     0x00000008
#define AON_SYSCTL_RESETCTL_RESET_SRC_VDD_LOSS                      0x00000006
#define AON_SYSCTL_RESETCTL_RESET_SRC_VDDS_LOSS                     0x00000004
#define AON_SYSCTL_RESETCTL_RESET_SRC_PIN_RESET                     0x00000002
#define AON_SYSCTL_RESETCTL_RESET_SRC_PWR_ON                        0x00000000

//*****************************************************************************
//
// Register: AON_SYSCTL_O_SLEEPCTL
//
//*****************************************************************************
// Field:     [0] IO_PAD_SLEEP_DIS
//
// Controls the I/O pad sleep mode. The boot code will set this bitfield
// automatically unless waking up from a SHUTDOWN ( RESETCTL.WU_FROM_SD is set
// ).
//
// 0: I/O pad sleep mode is enabled, ie all pads are latched and can not
// toggle.
// 1: I/O pad sleep mode is disabled
//
// Application software may want to reconfigure the state for all IO's before
// setting this bitfield upon waking up from a SHUTDOWN.
#define AON_SYSCTL_SLEEPCTL_IO_PAD_SLEEP_DIS                        0x00000001
#define AON_SYSCTL_SLEEPCTL_IO_PAD_SLEEP_DIS_BITN                            0
#define AON_SYSCTL_SLEEPCTL_IO_PAD_SLEEP_DIS_M                      0x00000001
#define AON_SYSCTL_SLEEPCTL_IO_PAD_SLEEP_DIS_S                               0


#endif // __AON_SYSCTL__
