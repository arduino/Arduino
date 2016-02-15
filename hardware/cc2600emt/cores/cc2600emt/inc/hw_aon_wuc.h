/******************************************************************************
*  Filename:       hw_aon_wuc_h
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

#ifndef __HW_AON_WUC_H__
#define __HW_AON_WUC_H__

//*****************************************************************************
//
// This section defines the register offsets of
// AON_WUC component
//
//*****************************************************************************
// MCU Clock Management
#define AON_WUC_O_MCUCLK                                            0x00000000

// AUX Clock Management
#define AON_WUC_O_AUXCLK                                            0x00000004

// MCU Configuration
#define AON_WUC_O_MCUCFG                                            0x00000008

// AUX Configuration
#define AON_WUC_O_AUXCFG                                            0x0000000C

// AUX Control
#define AON_WUC_O_AUXCTL                                            0x00000010

// Power Status
#define AON_WUC_O_PWRSTAT                                           0x00000014

// Shutdown Control
#define AON_WUC_O_SHUTDOWN                                          0x00000018

// Control 0
#define AON_WUC_O_CTL0                                              0x00000020

// Control 1
#define AON_WUC_O_CTL1                                              0x00000024

// Recharge Controller Configuration
#define AON_WUC_O_RECHARGECFG                                       0x00000030

// Recharge Controller Status
#define AON_WUC_O_RECHARGESTAT                                      0x00000034

// Oscillator Configuration
#define AON_WUC_O_OSCCFG                                            0x00000038

// JTAG Configuration
#define AON_WUC_O_JTAGCFG                                           0x00000040

// JTAG USERCODE
#define AON_WUC_O_JTAGUSERCODE                                      0x00000044

//*****************************************************************************
//
// Register: AON_WUC_O_MCUCLK
//
//*****************************************************************************
// Field:     [2] RCOSC_HF_CAL_DONE
//
// MCU bootcode will set this bit when RCOSC_HF is calibrated.  The FLASH can
// not be used until this bit is set.
//
// 1: RCOSC_HF is calibrated to 48 MHz, allowing FLASH to power up.
// 0: RCOSC_HF is not yet calibrated, ie FLASH must not assume that the SCLK_HF
// is safe
#define AON_WUC_MCUCLK_RCOSC_HF_CAL_DONE                            0x00000004
#define AON_WUC_MCUCLK_RCOSC_HF_CAL_DONE_BITN                                2
#define AON_WUC_MCUCLK_RCOSC_HF_CAL_DONE_M                          0x00000004
#define AON_WUC_MCUCLK_RCOSC_HF_CAL_DONE_S                                   2

// Field:   [1:0] PWR_DWN_SRC
//
// Controls the clock source for the entire MCU domain while MCU is requesting
// powerdown.
//
// When MCU requests powerdown with SCLK_HF as source, then WUC will switch
// over to this clock source during powerdown, and automatically switch back to
// SCLK_HF when MCU is no longer requesting powerdown and system is back in
// active mode.
// ENUMs:
// SCLK_LF                  Use SCLK_LF in Powerdown
// NONE                     No clock in Powerdown
#define AON_WUC_MCUCLK_PWR_DWN_SRC_W                                         2
#define AON_WUC_MCUCLK_PWR_DWN_SRC_M                                0x00000003
#define AON_WUC_MCUCLK_PWR_DWN_SRC_S                                         0
#define AON_WUC_MCUCLK_PWR_DWN_SRC_SCLK_LF                          0x00000001
#define AON_WUC_MCUCLK_PWR_DWN_SRC_NONE                             0x00000000

//*****************************************************************************
//
// Register: AON_WUC_O_AUXCLK
//
//*****************************************************************************
// Field: [12:11] PWR_DWN_SRC
//
// When AUX requests powerdown with SCLK_HF as source, then WUC will switch
// over to this clock source during powerdown, and automatically switch back to
// SCLK_HF when AUX system is back in active mode
// ENUMs:
// SCLK_LF                  Use SCLK_LF in Powerdown
// NONE                     No clock in Powerdown
#define AON_WUC_AUXCLK_PWR_DWN_SRC_W                                         2
#define AON_WUC_AUXCLK_PWR_DWN_SRC_M                                0x00001800
#define AON_WUC_AUXCLK_PWR_DWN_SRC_S                                        11
#define AON_WUC_AUXCLK_PWR_DWN_SRC_SCLK_LF                          0x00000800
#define AON_WUC_AUXCLK_PWR_DWN_SRC_NONE                             0x00000000

// Field:  [10:8] SCLK_HF_DIV
//
// Select the AUX clock divider for SCLK_HF
//
// NB: It is not supported to change the AUX clock divider while SCLK_HF is
// active source for AUX
// ENUMs:
// DIV256                   Divide by 256
// DIV128                   Divide by 128
// DIV64                    Divide by 64
// DIV32                    Divide by 32
// DIV16                    Divide by 16
// DIV8                     Divide by 8
// DIV4                     Divide by 4
// DIV2                     Divide by 2
#define AON_WUC_AUXCLK_SCLK_HF_DIV_W                                         3
#define AON_WUC_AUXCLK_SCLK_HF_DIV_M                                0x00000700
#define AON_WUC_AUXCLK_SCLK_HF_DIV_S                                         8
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV256                           0x00000700
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV128                           0x00000600
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV64                            0x00000500
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV32                            0x00000400
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV16                            0x00000300
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV8                             0x00000200
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV4                             0x00000100
#define AON_WUC_AUXCLK_SCLK_HF_DIV_DIV2                             0x00000000

// Field:   [2:0] SRC
//
// Selects the clock source for AUX:
//
// NB: Switching the clock source is guaranteed to be glitchless
// ENUMs:
// SCLK_LF                  LF Clock (SCLK_LF)
// SCLK_HF                  HF Clock (SCLK_HF)
#define AON_WUC_AUXCLK_SRC_W                                                 3
#define AON_WUC_AUXCLK_SRC_M                                        0x00000007
#define AON_WUC_AUXCLK_SRC_S                                                 0
#define AON_WUC_AUXCLK_SRC_SCLK_LF                                  0x00000004
#define AON_WUC_AUXCLK_SRC_SCLK_HF                                  0x00000001

//*****************************************************************************
//
// Register: AON_WUC_O_MCUCFG
//
//*****************************************************************************
// Field:    [17] VIRT_OFF
//
// Internal. Only to be used through TI provided API.
#define AON_WUC_MCUCFG_VIRT_OFF                                     0x00020000
#define AON_WUC_MCUCFG_VIRT_OFF_BITN                                        17
#define AON_WUC_MCUCFG_VIRT_OFF_M                                   0x00020000
#define AON_WUC_MCUCFG_VIRT_OFF_S                                           17

// Field:    [16] FIXED_WU_EN
//
// Internal. Only to be used through TI provided API.
#define AON_WUC_MCUCFG_FIXED_WU_EN                                  0x00010000
#define AON_WUC_MCUCFG_FIXED_WU_EN_BITN                                     16
#define AON_WUC_MCUCFG_FIXED_WU_EN_M                                0x00010000
#define AON_WUC_MCUCFG_FIXED_WU_EN_S                                        16

// Field:   [3:0] SRAM_RET_EN
//
// MCU SRAM is partitioned into 4 banks . This register controls which of the
// banks that has retention during MCU power off
// ENUMs:
// RET_FULL                 Retention on for all banks (SRAM:BANK0, SRAM:BANK1
//                          ,SRAM:BANK2 and SRAM:BANK3)
// RET_LEVEL3               Retention on for SRAM:BANK0, SRAM:BANK1 and
//                          SRAM:BANK2
// RET_LEVEL2               Retention on for SRAM:BANK0 and SRAM:BANK1
// RET_LEVEL1               Retention on for SRAM:BANK0
// RET_NONE                 Retention is disabled
#define AON_WUC_MCUCFG_SRAM_RET_EN_W                                         4
#define AON_WUC_MCUCFG_SRAM_RET_EN_M                                0x0000000F
#define AON_WUC_MCUCFG_SRAM_RET_EN_S                                         0
#define AON_WUC_MCUCFG_SRAM_RET_EN_RET_FULL                         0x0000000F
#define AON_WUC_MCUCFG_SRAM_RET_EN_RET_LEVEL3                       0x00000007
#define AON_WUC_MCUCFG_SRAM_RET_EN_RET_LEVEL2                       0x00000003
#define AON_WUC_MCUCFG_SRAM_RET_EN_RET_LEVEL1                       0x00000001
#define AON_WUC_MCUCFG_SRAM_RET_EN_RET_NONE                         0x00000000

//*****************************************************************************
//
// Register: AON_WUC_O_AUXCFG
//
//*****************************************************************************
// Field:     [0] RAM_RET_EN
//
// This bit controls retention mode for the AUX_RAM:BANK0:
//
// 0: Retention is disabled
// 1: Retention is enabled
//
// NB: If retention is disabled, the AUX_RAM will be powered off when it would
// otherwise be put in retention mode
#define AON_WUC_AUXCFG_RAM_RET_EN                                   0x00000001
#define AON_WUC_AUXCFG_RAM_RET_EN_BITN                                       0
#define AON_WUC_AUXCFG_RAM_RET_EN_M                                 0x00000001
#define AON_WUC_AUXCFG_RAM_RET_EN_S                                          0

//*****************************************************************************
//
// Register: AON_WUC_O_AUXCTL
//
//*****************************************************************************
// Field:    [31] RESET_REQ
//
// Reset request for AUX. Writing 1 to this register will assert reset to AUX.
// The reset will be held until the bit is cleared again.
//
// 0: AUX reset pin will be deasserted
// 1: AUX reset pin will be asserted
#define AON_WUC_AUXCTL_RESET_REQ                                    0x80000000
#define AON_WUC_AUXCTL_RESET_REQ_BITN                                       31
#define AON_WUC_AUXCTL_RESET_REQ_M                                  0x80000000
#define AON_WUC_AUXCTL_RESET_REQ_S                                          31

// Field:     [2] SCE_RUN_EN
//
// Enables (1) or disables (0) AUX_SCE execution. AUX_SCE execution will begin
// when AUX Domain is powered and either this or AUX_SCE:CTL.CLK_EN is set.
//
// Setting this bit will assure that AUX_SCE execution starts as soon as AUX
// power domain is woken up. (  AUX_SCE:CTL.CLK_EN will be reset to 0 if AUX
// power domain has been off)
//
// 0: AUX_SCE execution will be disabled if AUX_SCE:CTL.CLK_EN is 0
// 1: AUX_SCE execution is enabled.
#define AON_WUC_AUXCTL_SCE_RUN_EN                                   0x00000004
#define AON_WUC_AUXCTL_SCE_RUN_EN_BITN                                       2
#define AON_WUC_AUXCTL_SCE_RUN_EN_M                                 0x00000004
#define AON_WUC_AUXCTL_SCE_RUN_EN_S                                          2

// Field:     [1] SWEV
//
// Writing 1 sets the software event to the AUX domain, which can be read
// through AUX_WUC:WUEVFLAGS.AON_SW.
//
// This event is normally cleared by AUX_SCE through the
// AUX_WUC:WUEVCLR.AON_SW. It can also be cleared by writing 0 to this
// register.
//
// Reading 0 means that there is no outstanding software event for AUX.
//
// Note that it can take up to 1,5 SCLK_LF clock cycles to clear the event from
// AUX.
#define AON_WUC_AUXCTL_SWEV                                         0x00000002
#define AON_WUC_AUXCTL_SWEV_BITN                                             1
#define AON_WUC_AUXCTL_SWEV_M                                       0x00000002
#define AON_WUC_AUXCTL_SWEV_S                                                1

// Field:     [0] AUX_FORCE_ON
//
// Forces the AUX domain into active mode, overriding the requests from
// AUX_WUC:PWROFFREQ, AUX_WUC:PWRDWNREQ and AUX_WUC:MCUBUSCTL.
// Note that an ongoing AUX_WUC:PWROFFREQ will complete before this bit will
// set the AUX domain into active mode.
//
// MCU must set this bit in order to access the AUX peripherals.
// The AUX domain status can be read from PWRSTAT.AUX_PD_ON
//
// 0: AUX is allowed to Power Off, Power Down or Disconnect.
// 1: AUX  Power OFF, Power Down or Disconnect requests will be overruled
#define AON_WUC_AUXCTL_AUX_FORCE_ON                                 0x00000001
#define AON_WUC_AUXCTL_AUX_FORCE_ON_BITN                                     0
#define AON_WUC_AUXCTL_AUX_FORCE_ON_M                               0x00000001
#define AON_WUC_AUXCTL_AUX_FORCE_ON_S                                        0

//*****************************************************************************
//
// Register: AON_WUC_O_PWRSTAT
//
//*****************************************************************************
// Field:     [9] AUX_PWR_DWN
//
// Indicates the AUX powerdown state when AUX domain is powered up.
//
// 0: Active mode
// 1: AUX Powerdown request has been granted
#define AON_WUC_PWRSTAT_AUX_PWR_DWN                                 0x00000200
#define AON_WUC_PWRSTAT_AUX_PWR_DWN_BITN                                     9
#define AON_WUC_PWRSTAT_AUX_PWR_DWN_M                               0x00000200
#define AON_WUC_PWRSTAT_AUX_PWR_DWN_S                                        9

// Field:     [6] JTAG_PD_ON
//
// Indicates JTAG power state:
//
// 0: JTAG is powered off
// 1: JTAG is powered on
#define AON_WUC_PWRSTAT_JTAG_PD_ON                                  0x00000040
#define AON_WUC_PWRSTAT_JTAG_PD_ON_BITN                                      6
#define AON_WUC_PWRSTAT_JTAG_PD_ON_M                                0x00000040
#define AON_WUC_PWRSTAT_JTAG_PD_ON_S                                         6

// Field:     [5] AUX_PD_ON
//
// Indicates AUX power state:
//
// 0: AUX is not ready for use ( may be powered off or in power state
// transition )
// 1: AUX is powered on, connected to bus and ready for use,
#define AON_WUC_PWRSTAT_AUX_PD_ON                                   0x00000020
#define AON_WUC_PWRSTAT_AUX_PD_ON_BITN                                       5
#define AON_WUC_PWRSTAT_AUX_PD_ON_M                                 0x00000020
#define AON_WUC_PWRSTAT_AUX_PD_ON_S                                          5

// Field:     [4] MCU_PD_ON
//
// Indicates MCU power state:
//
// 0: MCU Power sequencing is not yet finalized and MCU_AONIF registers may not
// be reliable
// 1: MCU Power sequencing is finalized and all MCU_AONIF registers are
// reliable
#define AON_WUC_PWRSTAT_MCU_PD_ON                                   0x00000010
#define AON_WUC_PWRSTAT_MCU_PD_ON_BITN                                       4
#define AON_WUC_PWRSTAT_MCU_PD_ON_M                                 0x00000010
#define AON_WUC_PWRSTAT_MCU_PD_ON_S                                          4

// Field:     [2] AUX_BUS_CONNECTED
//
// Indicates that AUX Bus is connected:
//
// 0: AUX bus is not connected
// 1: AUX bus is connected ( idle_ack = 0 )
#define AON_WUC_PWRSTAT_AUX_BUS_CONNECTED                           0x00000004
#define AON_WUC_PWRSTAT_AUX_BUS_CONNECTED_BITN                               2
#define AON_WUC_PWRSTAT_AUX_BUS_CONNECTED_M                         0x00000004
#define AON_WUC_PWRSTAT_AUX_BUS_CONNECTED_S                                  2

// Field:     [1] AUX_RESET_DONE
//
// Indicates Reset Done from AUX:
//
// 0: AUX is being reset
// 1: AUX reset is released
#define AON_WUC_PWRSTAT_AUX_RESET_DONE                              0x00000002
#define AON_WUC_PWRSTAT_AUX_RESET_DONE_BITN                                  1
#define AON_WUC_PWRSTAT_AUX_RESET_DONE_M                            0x00000002
#define AON_WUC_PWRSTAT_AUX_RESET_DONE_S                                     1

//*****************************************************************************
//
// Register: AON_WUC_O_SHUTDOWN
//
//*****************************************************************************
// Field:     [0] EN
//
// Writing a 1 to this bit forces a shutdown request to be registered and all
// I/O values to be latched - in the PAD ring, possibly enabling I/O wakeup.
// Writing 0 will cancel a registered shutdown request and open th I/O latches
// residing in the PAD ring.
//
// A registered shutdown request takes effect the next time power down
// conditions exists. At this time, the will not enter Powerdown mode, but
// instead it will turn off all internal powersupplies, effectively putting the
// device into Shutdown mode.
#define AON_WUC_SHUTDOWN_EN                                         0x00000001
#define AON_WUC_SHUTDOWN_EN_BITN                                             0
#define AON_WUC_SHUTDOWN_EN_M                                       0x00000001
#define AON_WUC_SHUTDOWN_EN_S                                                0

//*****************************************************************************
//
// Register: AON_WUC_O_CTL0
//
//*****************************************************************************
// Field:     [8] PWR_DWN_DIS
//
// Controls whether MCU and AUX requesting to be powered off will enable a
// transition to powerdown:
//
// 0: Enabled
// 1: Disabled
#define AON_WUC_CTL0_PWR_DWN_DIS                                    0x00000100
#define AON_WUC_CTL0_PWR_DWN_DIS_BITN                                        8
#define AON_WUC_CTL0_PWR_DWN_DIS_M                                  0x00000100
#define AON_WUC_CTL0_PWR_DWN_DIS_S                                           8

// Field:     [3] AUX_SRAM_ERASE
//
// Internal. Only to be used through TI provided API.
#define AON_WUC_CTL0_AUX_SRAM_ERASE                                 0x00000008
#define AON_WUC_CTL0_AUX_SRAM_ERASE_BITN                                     3
#define AON_WUC_CTL0_AUX_SRAM_ERASE_M                               0x00000008
#define AON_WUC_CTL0_AUX_SRAM_ERASE_S                                        3

// Field:     [2] MCU_SRAM_ERASE
//
// Internal. Only to be used through TI provided API.
#define AON_WUC_CTL0_MCU_SRAM_ERASE                                 0x00000004
#define AON_WUC_CTL0_MCU_SRAM_ERASE_BITN                                     2
#define AON_WUC_CTL0_MCU_SRAM_ERASE_M                               0x00000004
#define AON_WUC_CTL0_MCU_SRAM_ERASE_S                                        2

//*****************************************************************************
//
// Register: AON_WUC_O_CTL1
//
//*****************************************************************************
// Field:     [1] MCU_RESET_SRC
//
// Indicates source of last MCU Voltage Domain warm reset request:
//
// 0: MCU SW reset
// 1: JTAG reset
//
// This bit can only be cleared by writing a 1 to it
#define AON_WUC_CTL1_MCU_RESET_SRC                                  0x00000002
#define AON_WUC_CTL1_MCU_RESET_SRC_BITN                                      1
#define AON_WUC_CTL1_MCU_RESET_SRC_M                                0x00000002
#define AON_WUC_CTL1_MCU_RESET_SRC_S                                         1

// Field:     [0] MCU_WARM_RESET
//
// Indicates type of last MCU Voltage Domain reset:
//
// 0: Last MCU reset was not a warm reset
// 1: Last MCU reset was a warm reset (requested from MCU or JTAG as indicated
// in MCU_RESET_SRC)
//
// This bit can only be cleared by writing a 1 to it
#define AON_WUC_CTL1_MCU_WARM_RESET                                 0x00000001
#define AON_WUC_CTL1_MCU_WARM_RESET_BITN                                     0
#define AON_WUC_CTL1_MCU_WARM_RESET_M                               0x00000001
#define AON_WUC_CTL1_MCU_WARM_RESET_S                                        0

//*****************************************************************************
//
// Register: AON_WUC_O_RECHARGECFG
//
//*****************************************************************************
// Field:    [31] ADAPTIVE_EN
//
// Enable adaptive recharge
//
// Note: Recharge can be turned completely of by setting MAX_PER_E=7 and
// MAX_PER_M=31 and this bitfield to 0
#define AON_WUC_RECHARGECFG_ADAPTIVE_EN                             0x80000000
#define AON_WUC_RECHARGECFG_ADAPTIVE_EN_BITN                                31
#define AON_WUC_RECHARGECFG_ADAPTIVE_EN_M                           0x80000000
#define AON_WUC_RECHARGECFG_ADAPTIVE_EN_S                                   31

// Field: [23:20] C2
//
// Gain factor for adaptive recharge algorithm
//
// period_new=period * ( 1+/-(2^-C1+2^-C2) )
// Valid values for C2 is 2 to 10
//
// Note: Rounding may cause adaptive recharge not to start for very small
// values of both Gain and Initial period. Criteria for algorithm to start is
// MAX(PERIOD*2^-C1,PERIOD*2^-C2) >= 1
#define AON_WUC_RECHARGECFG_C2_W                                             4
#define AON_WUC_RECHARGECFG_C2_M                                    0x00F00000
#define AON_WUC_RECHARGECFG_C2_S                                            20

// Field: [19:16] C1
//
// Gain factor for adaptive recharge algorithm
//
// period_new=period * ( 1+/-(2^-C1+2^-C2) )
// Valid values for C1 is 1 to 10
//
// Note: Rounding may cause adaptive recharge not to start for very small
// values of both Gain and Initial period. Criteria for algorithm to start is
// MAX(PERIOD*2^-C1,PERIOD*2^-C2) >= 1
#define AON_WUC_RECHARGECFG_C1_W                                             4
#define AON_WUC_RECHARGECFG_C1_M                                    0x000F0000
#define AON_WUC_RECHARGECFG_C1_S                                            16

// Field: [15:11] MAX_PER_M
//
// This register defines the maximum period that the recharge algorithm can
// take, i.e. it defines  the maximum number of cycles between 2 recharges.
// The maximum number of cycles is specified with a 5 bit mantissa and 3 bit
// exponent:
// MAXCYCLES=(MAX_PER_M*16+15)*2^MAX_PER_E
// This field sets the mantissa of MAXCYCLES
#define AON_WUC_RECHARGECFG_MAX_PER_M_W                                      5
#define AON_WUC_RECHARGECFG_MAX_PER_M_M                             0x0000F800
#define AON_WUC_RECHARGECFG_MAX_PER_M_S                                     11

// Field:  [10:8] MAX_PER_E
//
// This register defines the maximum period that the recharge algorithm can
// take, i.e. it defines  the maximum number of cycles between 2 recharges.
// The maximum number of cycles is specified with a 5 bit mantissa and 3 bit
// exponent:
// MAXCYCLES=(MAX_PER_M*16+15)*2^MAX_PER_E
// This field sets the exponent MAXCYCLES
#define AON_WUC_RECHARGECFG_MAX_PER_E_W                                      3
#define AON_WUC_RECHARGECFG_MAX_PER_E_M                             0x00000700
#define AON_WUC_RECHARGECFG_MAX_PER_E_S                                      8

// Field:   [7:3] PER_M
//
// Number of 32 KHz clocks between activation of recharge controller
// For recharge algorithm, PERIOD is the initial period when entering powerdown
// mode. The adaptive recharge algorithm will not change this register
// PERIOD will effectively be a 16 bit value coded in a 5 bit mantissa and 3
// bit exponent:
// This field sets the Mantissa of the Period.
// PERIOD=(PER_M*16+15)*2^PER_E
#define AON_WUC_RECHARGECFG_PER_M_W                                          5
#define AON_WUC_RECHARGECFG_PER_M_M                                 0x000000F8
#define AON_WUC_RECHARGECFG_PER_M_S                                          3

// Field:   [2:0] PER_E
//
// Number of 32 KHz clocks between activation of recharge controller
// For recharge algorithm, PERIOD is the initial period when entering powerdown
// mode. The adaptive recharge algorithm will not change this register
// PERIOD will effectively be a 16 bit value coded in a 5 bit mantissa and 3
// bit exponent:
// This field sets the Exponent of the Period.
// PERIOD=(PER_M*16+15)*2^PER_E
#define AON_WUC_RECHARGECFG_PER_E_W                                          3
#define AON_WUC_RECHARGECFG_PER_E_M                                 0x00000007
#define AON_WUC_RECHARGECFG_PER_E_S                                          0

//*****************************************************************************
//
// Register: AON_WUC_O_RECHARGESTAT
//
//*****************************************************************************
// Field: [19:16] VDDR_SMPLS
//
// The last 4 VDDR samples, bit 0 being the newest.
//
// The register is being updated in every recharge period with a shift left,
// and bit 0 is updated with the last VDDR sample, ie a 1 is shiftet in in case
// VDDR > VDDR_threshold just before recharge starts. Otherwise a 0 will be
// shifted in.
#define AON_WUC_RECHARGESTAT_VDDR_SMPLS_W                                    4
#define AON_WUC_RECHARGESTAT_VDDR_SMPLS_M                           0x000F0000
#define AON_WUC_RECHARGESTAT_VDDR_SMPLS_S                                   16

// Field:  [15:0] MAX_USED_PER
//
// The maximum value of recharge period seen with VDDR>threshold.
//
// The VDDR voltage is compared against the threshold voltage at  just before
// each recharge. If VDDR is above threshold, MAX_USED_PER is updated with max
// ( current recharge peride; MAX_USED_PER )  This way MAX_USED_PER can track
// the recharge period where VDDR is decharged to the threshold value. We can
// therefore use the value as an indication of the leakage current during
// recharge.
//
// This bitfield is cleared to 0 when writing this register.
#define AON_WUC_RECHARGESTAT_MAX_USED_PER_W                                 16
#define AON_WUC_RECHARGESTAT_MAX_USED_PER_M                         0x0000FFFF
#define AON_WUC_RECHARGESTAT_MAX_USED_PER_S                                  0

//*****************************************************************************
//
// Register: AON_WUC_O_OSCCFG
//
//*****************************************************************************
// Field:   [7:3] PER_M
//
// Number of 32 KHz clocks between oscillator amplitude calibrations.
// When this counter expires, an oscillator amplitude compensation is triggered
// immediately in Active mode. When this counter expires in Powerdown mode an
// internal flag is set such that the amplitude compensation is postponed until
// the next recharge occurs.
//
// The Period will effectively be a 16 bit value coded in a 5 bit mantissa and
// 3 bit exponent
// PERIOD=(PER_M*16+15)*2^PER_E
// This field sets the mantissa
// Note: Oscillator amplitude calibration is turned of when both this bitfield
// and PER_E are set to 0
#define AON_WUC_OSCCFG_PER_M_W                                               5
#define AON_WUC_OSCCFG_PER_M_M                                      0x000000F8
#define AON_WUC_OSCCFG_PER_M_S                                               3

// Field:   [2:0] PER_E
//
// Number of 32 KHz clocks between oscillator amplitude calibrations.
// When this counter expires, an oscillator amplitude compensation is triggered
// immediately in Active mode. When this counter expires in Powerdown mode an
// internal flag is set such that the amplitude compensation is postponed until
// the next recharge occurs.
// The Period will effectively be a 16 bit value coded in a 5 bit mantissa and
// 3 bit exponent
// PERIOD=(PER_M*16+15)*2^PER_E
// This field sets the exponent
// Note: Oscillator amplitude calibration is turned of when both  PER_M and
// this bitfield are set to 0
#define AON_WUC_OSCCFG_PER_E_W                                               3
#define AON_WUC_OSCCFG_PER_E_M                                      0x00000007
#define AON_WUC_OSCCFG_PER_E_S                                               0

//*****************************************************************************
//
// Register: AON_WUC_O_JTAGCFG
//
//*****************************************************************************
// Field:     [8] JTAG_PD_FORCE_ON
//
// Controls JTAG PowerDomain power state:
//
// 0: Controlled exclusively by debug subsystem. (JTAG Powerdomain will be
// powered off unless a debugger is attached)
// 1: JTAG Power Domain is forced on, independent of debug subsystem.
//
// NB: The reset value causes JTAG Power Domain to be powered on by default.
// Software must clear this bit to turn off the JTAG Power Domain
#define AON_WUC_JTAGCFG_JTAG_PD_FORCE_ON                            0x00000100
#define AON_WUC_JTAGCFG_JTAG_PD_FORCE_ON_BITN                                8
#define AON_WUC_JTAGCFG_JTAG_PD_FORCE_ON_M                          0x00000100
#define AON_WUC_JTAGCFG_JTAG_PD_FORCE_ON_S                                   8

//*****************************************************************************
//
// Register: AON_WUC_O_JTAGUSERCODE
//
//*****************************************************************************
// Field:  [31:0] USER_CODE
//
// 32-bit JTAG USERCODE register feeding main JTAG TAP
// NB: This field can be locked
#define AON_WUC_JTAGUSERCODE_USER_CODE_W                                    32
#define AON_WUC_JTAGUSERCODE_USER_CODE_M                            0xFFFFFFFF
#define AON_WUC_JTAGUSERCODE_USER_CODE_S                                     0


#endif // __AON_WUC__
