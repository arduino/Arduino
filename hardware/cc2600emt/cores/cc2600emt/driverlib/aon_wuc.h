/******************************************************************************
*  Filename:       aon_wuc.h
*  Revised:        2015-07-16 12:12:04 +0200 (Thu, 16 Jul 2015)
*  Revision:       44151
*
*  Description:    Defines and prototypes for the AON Wake-Up Controller
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

//*****************************************************************************
//
//! \addtogroup aon_group
//! @{
//! \addtogroup aonwuc_api
//! @{
//
//*****************************************************************************

#ifndef __AON_WUC_H__
#define __AON_WUC_H__

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

#include <stdbool.h>
#include <stdint.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <inc/hw_ints.h>
#include <inc/hw_aon_wuc.h>
#include <inc/hw_aon_rtc.h>
#include <driverlib/interrupt.h>
#include <driverlib/debug.h>

//*****************************************************************************
//
// Support for DriverLib in ROM:
// This section renames all functions that are not "static inline", so that
// calling these functions will default to implementation in flash. At the end
// of this file a second renaming will change the defaults to implementation in
// ROM for available functions.
//
// To force use of the implementation in flash, e.g. for debugging:
// - Globally: Define DRIVERLIB_NOROM at project level
// - Per function: Use prefix "NOROM_" when calling the function
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #define AONWUCAuxReset                  NOROM_AONWUCAuxReset
    #define AONWUCRechargeCtrlConfigSet     NOROM_AONWUCRechargeCtrlConfigSet
    #define AONWUCOscConfig                 NOROM_AONWUCOscConfig
#endif

//*****************************************************************************
//
// Defines the possible clock source for the MCU and AUX domain.
//
//*****************************************************************************
#define AONWUC_CLOCK_SRC_HF     0x00000003  // System clock high frequency -
                                            // 48 MHz.
#define AONWUC_CLOCK_SRC_LF     0x00000001  // System clock low frequency -
                                            // 32 kHz.
#define AONWUC_NO_CLOCK         0x00000000  // System clock low frequency -
                                            // 32 kHz.

//*****************************************************************************
//
// Defines the possible clock division factors for the AUX domain.
//
//*****************************************************************************
#define AUX_CLOCK_DIV_2         ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV2   )
#define AUX_CLOCK_DIV_4         ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV4   )
#define AUX_CLOCK_DIV_8         ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV8   )
#define AUX_CLOCK_DIV_16        ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV16  )
#define AUX_CLOCK_DIV_32        ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV32  )
#define AUX_CLOCK_DIV_64        ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV64  )
#define AUX_CLOCK_DIV_128       ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV128 )
#define AUX_CLOCK_DIV_256       ( AON_WUC_AUXCLK_SCLK_HF_DIV_DIV256 )
#define AUX_CLOCK_DIV_UNUSED    ( AON_WUC_AUXCLK_SCLK_HF_DIV_M + ( 1 << AON_WUC_AUXCLK_SCLK_HF_DIV_S ))
#define AUX_CLOCK_DIV_M         ( AON_WUC_AUXCLK_SCLK_HF_DIV_M )

//*****************************************************************************
//
// Defines used for configuring the power-off and wake up procedure.
//
//*****************************************************************************
#define MCU_VIRT_PWOFF_DISABLE  0x00000000
#define MCU_VIRT_PWOFF_ENABLE   0x00020000
#define MCU_IMM_WAKE_UP         0x00000000
#define MCU_FIXED_WAKE_UP       0x00010000
#define AUX_VIRT_PWOFF_DISABLE  0x00000000
#define AUX_VIRT_PWOFF_ENABLE   0x00020000
#define AUX_IMM_WAKE_UP         0x00000000
#define AUX_FIXED_WAKE_UP       0x00010000

//*****************************************************************************
//
// Defines that can be be used to enable/disable the entire SRAM and the
// retention on the SRAM in both the MCU and the AUX domain.
//
//*****************************************************************************
#define MCU_RAM0_RETENTION      0x00000001
#define MCU_RAM1_RETENTION      0x00000002
#define MCU_RAM2_RETENTION      0x00000004
#define MCU_RAM3_RETENTION      0x00000008
#define MCU_RAM_BLOCK_RETENTION 0x0000000F
#define MCU_AUX_RET_ENABLE      0x00000001

//*****************************************************************************
//
// Defines for different wake up modes for AUX domain which can be set using
// AONWUCAuxWakeUpEvent() .
//
//*****************************************************************************
#define AONWUC_AUX_WAKEUP       0x00000001
#define AONWUC_AUX_ALLOW_SLEEP  0x00000000

//*****************************************************************************
//
// Defines for all the different power modes available through
// AONWUCPowerStatusGet() .
//
//*****************************************************************************
#define AONWUC_OSC_GBIAS_REQ    0x00400000  // OSC is requesting GBias
#define AONWUC_AUX_GBIAS_REQ    0x00200000  // AUX is requesting GBias
#define AONWUC_MCU_GBIAS_REQ    0x00100000  // MCU is requesting GBias
#define AONWUC_OSC_BGAP_REQ     0x00040000  // OSC is requesting BGap
#define AONWUC_AUX_BGAP_REQ     0x00020000  // AUX is requesting BGap
#define AONWUC_MCU_BGAP_REQ     0x00010000  // MCU is requesting BGap
#define AONWUC_GBIAS_ON         0x00002000  // Global Bias is on
#define AONWUC_BGAP_ON          0x00001000  // Band Gap is on
#define AONWUC_AUX_POWER_DOWN   0x00000200  // AUX is in powerdown mode
#define AONWUC_MCU_POWER_DOWN   0x00000100  // MCU is in powerdown mode
#define AONWUC_JTAG_POWER_ON    0x00000040  // JTAG is powered on
#define AONWUC_AUX_POWER_ON     0x00000020  // AUX is powered on
#define AONWUC_MCU_POWER_ON     0x00000010  // MCU is powered on
#define AONWUC_SPLY_POWER_DOWN  0x00000001  // Power supply is in power down


//*****************************************************************************
//
// RAM repair status bits. Values are returned by AOXWUCRamRepairStatusGet() .
//
//*****************************************************************************
#define MCU_RAMREPAIR_DONE      0x00000001
#define AUX_RAMREPAIR_DONE      0x00000002

//*****************************************************************************

//*****************************************************************************
#define RC_RATE_MAX                   768   // Maximum recharge rate for the
                                            // recharge controller.
#define RC_RATE_MIN                     2   // Minimum recharge rate for the
                                            // recharge controller.

//*****************************************************************************
#define AONWUC_MCU_RESET_SRC    0x00000002  // MCU reset source can be SW or
                                            // JTAG
#define AONWUC_MCU_WARM_RESET   0x00000001  // MCU reset type and can be warm
                                            // or not warm.

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Configure the power down clock for the MCU domain.
//!
//! Use this function to control which one of the clock sources that
//! is fed into the MCU domain when the system is in standby mode. When the
//! power is back in Active mode the clock source will automatically switch to
//! \ref AONWUC_CLOCK_SRC_HF.
//!
//! Each clock is fed 'as is' into the MCU domain, since the MCU domain
//! contains internal clock dividers controllable through the PRCM.
//!
//! \param ui32ClkSrc is the clock source for the MCU domain when in power
//! down. Values available as clock source:
//! - \ref AONWUC_NO_CLOCK
//! - \ref AONWUC_CLOCK_SRC_LF
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCMcuPowerDownConfig(uint32_t ui32ClkSrc)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT((ui32ClkSrc == AONWUC_NO_CLOCK) ||
           (ui32ClkSrc == AONWUC_CLOCK_SRC_LF));

    //
    // Set the clock source for the MCU domain when in power down.
    //
    ui32Reg = HWREG(AON_WUC_BASE + AON_WUC_O_MCUCLK);
    ui32Reg &= ~AON_WUC_MCUCLK_PWR_DWN_SRC_M;
    HWREG(AON_WUC_BASE + AON_WUC_O_MCUCLK) = ui32Reg |
                                             (ui32ClkSrc <<
                                              AON_WUC_MCUCLK_PWR_DWN_SRC_S);
}

//*****************************************************************************
//
//! \brief Configure the power down mode for the MCU domain.
//!
//! The parameter \c ui32Mode determines the power down mode of the MCU Voltage
//! Domain. When the AON WUC receives a request to power off the MCU domain it
//! can choose to power off completely or use a virtual power-off. In a virtual
//! power-off, reset is asserted and the clock is stopped but the power to the
//! domain is kept on.
//!
//! \param ui32Mode defines the power down mode of the MCU domain.
//! Allowed values for setting the virtual power-off are:
//! - \ref MCU_VIRT_PWOFF_DISABLE
//! - \ref MCU_VIRT_PWOFF_ENABLE
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCMcuPowerOffConfig(uint32_t ui32Mode)
{
    // Check the arguments.
    ASSERT((ui32Mode == MCU_VIRT_PWOFF_ENABLE) ||
           (ui32Mode == MCU_VIRT_PWOFF_DISABLE));

    // Set the powerdown mode.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_MCUCFG, AON_WUC_MCUCFG_VIRT_OFF_BITN) = (ui32Mode != 0);
}

//*****************************************************************************
//
//! \brief Configure the wake-up procedure for the MCU domain.
//!
//! The MCU domain can wake up using two different procedures. Either it wakes
//! up immediately following the triggering event or wake-up is forced to
//! happen a fixed number of 32 KHz clocks following the triggering
//! event. The last can be used to compensate for any variable delays caused
//! by other activities going on at the time of wakeup (such as a recharge
//! event, etc.).
//!
//! \param ui32WakeUp determines the timing of the MCU wake up  procedure.
//! - \ref MCU_IMM_WAKE_UP
//! - \ref MCU_FIXED_WAKE_UP
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCMcuWakeUpConfig(uint32_t ui32WakeUp)
{
    // Check the arguments.
    ASSERT((ui32WakeUp == MCU_IMM_WAKE_UP) ||
           (ui32WakeUp == MCU_FIXED_WAKE_UP));

    // Configure the wake up procedure.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_MCUCFG, AON_WUC_MCUCFG_FIXED_WU_EN_BITN) = (ui32WakeUp != 0);
}

//*****************************************************************************
//
//! \brief Configure the retention on the block RAM in the MCU domain.
//!
//! MCU SRAM is partitioned into 4 banks of 1k x 32 each. The SRAM supports
//! retention on all 4 blocks. The retention on the SRAM can be turned on and
//! off. Use this function to enable the retention on the individual blocks.
//!
//! If a block is not represented in the parameter \c ui32Retention then the
//! the retention will be disabled for that block.
//!
//! \note Retention on the SRAM is not enabled by default. If retention is
//! turned off on all RAM blocks then the SRAM is powered off when it would
//! otherwise be put in retention mode.
//!
//! \param ui32Retention defines which RAM blocks to enable/disable retention on.
//! To enable retention on individual parts of the RAM use a bitwise OR'ed
//! combination of:
//! - \ref MCU_RAM0_RETENTION
//! - \ref MCU_RAM1_RETENTION
//! - \ref MCU_RAM2_RETENTION
//! - \ref MCU_RAM3_RETENTION
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCMcuSRamConfig(uint32_t ui32Retention)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(ui32Retention & MCU_RAM_BLOCK_RETENTION);
    ASSERT(!(ui32Retention & ~MCU_RAM_BLOCK_RETENTION));

    //
    // Configure the retention.
    //
    ui32Reg = HWREG(AON_WUC_BASE + AON_WUC_O_MCUCFG) & ~MCU_RAM_BLOCK_RETENTION;
    ui32Reg |= ui32Retention;
    HWREG(AON_WUC_BASE + AON_WUC_O_MCUCFG) = ui32Reg;
}


//*****************************************************************************
//
//! \brief Return the clock configuration for the AUX domain.
//!
//! The AUX domain does not have a local clock divider, so the AON WUC contains
//! a dedicated clock divider for AUX domain. Use this function to
//! get the setting of the clock divider.
//!
//! \return Return the clock configuration. Enumerated return values are:
//! - \ref AUX_CLOCK_DIV_2
//! - \ref AUX_CLOCK_DIV_4
//! - \ref AUX_CLOCK_DIV_8
//! - \ref AUX_CLOCK_DIV_16
//! - \ref AUX_CLOCK_DIV_32
//! - \ref AUX_CLOCK_DIV_64
//! - \ref AUX_CLOCK_DIV_128
//! - \ref AUX_CLOCK_DIV_256
//!
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AONWUCAuxClockConfigGet(void)
{
    //
    // Return the clock divider value.
    //
    return ((HWREG(AON_WUC_BASE + AON_WUC_O_AUXCLK) &
             AON_WUC_AUXCLK_SCLK_HF_DIV_M) >>
             AON_WUC_AUXCLK_SCLK_HF_DIV_S);
}

//*****************************************************************************
//
//! \brief Configure the power down mode for the AUX domain.
//!
//! Use this function to control which one of the clock sources that
//! is fed into the MCU domain when it is in Power Down mode. When the Power
//! is back in active mode the clock source will automatically switch to
//! \ref AONWUC_CLOCK_SRC_HF.
//!
//! Each clock is fed 'as is' into the AUX domain, since the AUX domain
//! contains internal clock dividers controllable through the PRCM.
//!
//! \param ui32ClkSrc is the clock source for the AUX domain when in power down.
//! - \ref AONWUC_NO_CLOCK
//! - \ref AONWUC_CLOCK_SRC_LF
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCAuxPowerDownConfig(uint32_t ui32ClkSrc)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT((ui32ClkSrc == AONWUC_NO_CLOCK) ||
           (ui32ClkSrc == AONWUC_CLOCK_SRC_LF));

    //
    // Set the clock source for the AUX domain when in power down.
    //
    ui32Reg = HWREG(AON_WUC_BASE + AON_WUC_O_AUXCLK);
    ui32Reg &= ~AON_WUC_AUXCLK_PWR_DWN_SRC_M;
    HWREG(AON_WUC_BASE + AON_WUC_O_AUXCLK) = ui32Reg |
                                             (ui32ClkSrc <<
                                              AON_WUC_AUXCLK_PWR_DWN_SRC_S);
}


//*****************************************************************************
//
//! \brief Configure the retention on the AUX SRAM.
//!
//! The AUX SRAM contains only one block which supports retention. The retention
//! on the SRAM can be turned on and off. Use this function to enable/disable
//! the retention on the entire RAM.
//!
//! \param ui32Retention either enables or disables AUX SRAM retention.
//! - 0 : Disable retention.
//! - 1 : Enable retention.
//!
//! \note Retention on the SRAM is not enabled by default. If retention is
//! turned off then the SRAM is powered off when it would otherwise be put in
//! retention mode.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCAuxSRamConfig(uint32_t ui32Retention)
{
    // Enable/disable the retention.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_AUXCFG, AON_WUC_AUXCFG_RAM_RET_EN_BITN) = ui32Retention;
}

//*****************************************************************************
//
//! \brief Control the wake up procedure of the AUX domain.
//!
//! The AUX domain can be woken in two different modes. In both modes power
//! is turned on. In one mode a software event is generated for the
//! Sensor Controller and it is allowed to start processing. The second mode will
//! just force power on the Sensor Controller. If System CPU requires exclusive access
//! to the AUX domain resources, it is advised to ensure that the image in
//! the Sensor Controller memory is declared invalid. This can be achieved by
//! calling AONWUCAuxImageInvalid().
//!
//! \note Any writes to the AON interface must pass a 32 kHz clock boundary,
//! and is therefore relatively slow. To ensure that a given write is
//! complete the value of the register can be read back after write.
//
//! \note When accessing the AUX domain from the System CPU, it is advised always to
//! have set the AUX in at least \ref AONWUC_AUX_WAKEUP. This overwrites any
//! instruction from the Sensor Controller and ensures that the AUX domain
//! is on so it won't leave the System CPU hanging.
//!
//! \param ui32Mode is the wake up mode for the AUX domain.
//! - \ref AONWUC_AUX_WAKEUP
//! - \ref AONWUC_AUX_ALLOW_SLEEP
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCAuxWakeupEvent(uint32_t ui32Mode)
{
    // Check the arguments.
    ASSERT((ui32Mode == AONWUC_AUX_WAKEUP) ||
           (ui32Mode == AONWUC_AUX_ALLOW_SLEEP));

    // Wake up the AUX domain.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_AUXCTL, AON_WUC_AUXCTL_AUX_FORCE_ON_BITN) = ui32Mode;
}

//*****************************************************************************
//
//! \brief Reset the AUX domain.
//!
//! Use this function to reset the entire AUX domain. The write to the AON_WUC
//! module must pass an 32 kHz clock boundary. By reading the
//! AON_RTC_O_SYNC register after each write, it is guaranteed that the AON
//! interface will be in sync and that both the assert and the de-assert of the
//! reset signal to AUX will propagate.
//!
//! \note This requires two writes and two reads on a 32 kHz clock boundary.
//!
//! \return None
//
//*****************************************************************************
extern void AONWUCAuxReset(void);

//*****************************************************************************
//
//! \brief Tells the Sensor Controller that the image in memory is valid.
//!
//! Use this function to tell the sensor controller that the image in memory is
//! valid, and it is allowed to start executing the program.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCAuxImageValid(void)
{
    // Tell the Sensor Controller that the image in memory is valid.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_AUXCTL, AON_WUC_AUXCTL_SCE_RUN_EN_BITN) = 1;
}

//*****************************************************************************
//
//! \brief Tells the Sensor Controller that the image in memory is invalid.
//!
//! Use this function to tell the sensor controller that the image in memory is
//! invalid. Sensor Controller might wake up, but it will stay idle.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCAuxImageInvalid(void)
{
    // Tell the Sensor Controller that the image in memory is invalid.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_AUXCTL, AON_WUC_AUXCTL_SCE_RUN_EN_BITN) = 0;
}

//*****************************************************************************
//
//! \brief Get the power status of the device.
//!
//! The Always On (AON) domain is the only part of the device which is truly
//! "ALWAYS ON". The power status for the other device can always be read from
//! this status register.
//!
//! Possible power modes for the different parts of the device are:
//!
//! \return Returns the current power status of the device as a bitwise OR'ed
//! combination of these values:
//! - \ref AONWUC_AUX_POWER_DOWN
//! - \ref AONWUC_AUX_POWER_ON
//! - \ref AONWUC_JTAG_POWER_ON
//! - \ref AONWUC_MCU_POWER_ON
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AONWUCPowerStatusGet(void)
{
    //
    // Return the power status.
    //
    return (HWREG(AON_WUC_BASE + AON_WUC_O_PWRSTAT));
}

//*****************************************************************************
//
//! \brief Enable shut-down of the device.
//!
//! Use this function to enable shut-down of the device. This will force all I/O values to
//! be latched - possibly enabling I/O wakeup - then all internal power
//! supplies are turned off, effectively putting the device into shut-down mode.
//!
//! \note No action will take place before the System CPU is put to deep sleep.
//!
//! \note The shut-down command is ignored if the JTAG interface has been
//! activated.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCShutDownEnable(void)
{
    // Ensure the JTAG domain is turned off;
    // otherwise MCU domain can't be turned off.
    HWREG(AON_WUC_BASE + AON_WUC_O_JTAGCFG) = 0;

    // Enable shutdown of the device.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_CTL0, AON_WUC_CTL0_PWR_DWN_DIS_BITN) = 0;
    HWREG(AON_WUC_BASE + AON_WUC_O_SHUTDOWN) = AON_WUC_SHUTDOWN_EN;
}

//*****************************************************************************
//
//! \brief Enable power down mode on AUX and MCU domain.
//!
//! Use this function to enable powerdown on the AUX and MCU domain.
//!
//! \note The powerdown command is ignored if the JTAG interface has been
//! activated.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCDomainPowerDownEnable(void)
{
    // Ensure the JTAG domain is turned off;
    // otherwise MCU domain can't be turned off.
    HWREG(AON_WUC_BASE + AON_WUC_O_JTAGCFG) = 0;

    // Enable power down mode.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_CTL0, AON_WUC_CTL0_PWR_DWN_DIS_BITN) = 0;
}

//*****************************************************************************
//
//! \brief Use this function to disable power down mode of the MCU and AUX domain.
//!
//! Disabling powerdown on the MCU and/or AUX will put the domains in a
//! virtual power down when requesting to be powered down. Logic is the same
//! but power is kept on.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCDomainPowerDownDisable(void)
{
    // Disable power down mode.
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_CTL0, AON_WUC_CTL0_PWR_DWN_DIS_BITN) = 1;
}

//*****************************************************************************
//
//! \brief Use this function to clear specific status bits.
//!
//! Use this function to clear the bits that are set in the AON WUC status
//! register. This register requires a write 1 to clear.
//!
//! AON Wake Up Controller TAP can request a total/full Flash erase. If so,
//! the corresponding status bits will be set in the status register and can
//! be read using \ref AONWUCMcuResetStatusGet() or cleared using this function. The reset
//! source and type give information about what and how the latest reset
//! was performed. Access to these bits are identical to the flash erase
//! bits.
//!
//! \param ui32Status defines in a one-hot encoding which bits to clear in the
//! status register. Use OR'ed combinations of the following:
//! - \ref AONWUC_MCU_RESET_SRC
//! - \ref AONWUC_MCU_WARM_RESET
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCMcuResetClear(uint32_t ui32Status)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Status & AONWUC_MCU_RESET_SRC) ||
           (ui32Status & AONWUC_MCU_WARM_RESET));

    //
    // Clear the status bits.
    //
    HWREG(AON_WUC_BASE + AON_WUC_O_CTL1) = ui32Status;
}

//*****************************************************************************
//
//! \brief Return the reset status.
//!
//! This function returns the value of the AON_WUC_O_CTL1 register.
//!
//! \return Returns the status from the AON WUC.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AONWUCMcuResetStatusGet(void)
{
    //
    // Return the current status.
    //
    return (HWREG(AON_WUC_BASE + AON_WUC_O_CTL1));
}

//*****************************************************************************
//
//! \brief Configure the recharge controller.
//!
//! The parameter \c bAdaptEnable is used to enable or disable the adaptive
//! algorithm for the recharge controller.
//! The adaptive algorithm for the recharge controller is defined as
//!
/*!
\verbatim

  New_Period = Period * (1 + (AdaptRate / 1024) )

      AdaptRate
     ----------- = ( 2^(-C1) + 2^(-C2)  )
        1024

\endverbatim
*/
//!
//! Where C1 is between 1 and 10 and C2 is between 2 and 10. The \c ui32AdaptRate
//! must be a number between 2 and 768 (\ref RC_RATE_MIN and \ref RC_RATE_MAX)
//! resulting in an adaptive rate between 0.2% and 75%.
//!
//! The \c ui32Period is the number of 32 KHz clocks between two recharges. The
//! length of the interval is defined by the formula:
//!
/*!
\verbatim

  Period = ({ulMantissa,5'b1111} << ui32Exponent)

\endverbatim
*/
//!
//! \note The maximum number of recharge cycles is required when enabling the
//! adaptive recharge algorithm.
//!
//! \note The maximum period between two recharges should never exceed the
//! period between two oscillator amplitude calibrations which is configured
//! using AONWUCOscConfig().
//!
//! \param bAdaptEnable enables the adaptation algorithm for the controller.
//! \param ui32AdaptRate determines the adjustment value for the adoption
//! algorithm.
//! \param ui32Period determines the number of clock cycles between each
//! activation of the recharge controller.
//! \param ui32MaxPeriod determines the maximum number of clock cycles between
//! each activation of the recharge controller.
//!
//! \return None
//
//*****************************************************************************
extern void AONWUCRechargeCtrlConfigSet(bool bAdaptEnable,
                                        uint32_t ui32AdaptRate,
                                        uint32_t ui32Period,
                                        uint32_t ui32MaxPeriod);

//*****************************************************************************
//
//! \brief Get the current configuration of the recharge controller.
//!
//! This function returns the value of the register AON_WUC_O_RECHARGECFG.
//!
//! \return Returns the current configuration of the recharge controller.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AONWUCRechargeCtrlConfigGet(void)
{
    //
    // Return the current configuration.
    //
    return(HWREG(AON_WUC_BASE + AON_WUC_O_RECHARGECFG));
}

//*****************************************************************************
//
//! \brief Configure the interval for oscillator amplitude calibration.
//!
//! Use this function to set the number of 32 kHz clocks between oscillator
//! amplitude calibrations.
//!
//! The value of the interval is defined by the formula:
//!
/*!
\verbatim

  Period = ({ulMantissa,5'b1111} << ui32Exponent)

\endverbatim
*/
//!
//! \note When this counter expires an oscillator amplitude calibration is
//! triggered immediately in Active mode. When this counter expires in
//! Powerdown mode an internal flag is set that causes GBIAS to turn on
//! together with BGAP when the next recharge occurs, at the same time
//! triggering the oscillator amplitude calibration as well as a recharge of
//! the uLDO reference voltage.
//!
//! \note The oscillator amplitude calibration is performed at the same time
//! as the recharge for the uLDO reference voltage. So the maximum period
//! between each recharge operation should not exceed the number of clock
//! cycles for the amplitude calibration.
//!
//! \param ui32Period is the number of 32 kHz clock cycles in each interval.
//!
//! \return None
//
//*****************************************************************************
extern void AONWUCOscConfig(uint32_t ui32Period);

//*****************************************************************************
//
//! \brief Request power off of the JTAG domain.
//!
//! The JTAG domain is automatically powered up on if a debugger is connected.
//! If a debugger is not connected this function can be used to power off the
//! JTAG domain.
//!
//! \note Achieving the lowest power modes (shutdown/powerdown) requires the
//! JTAG domain to be turned off. In general the JTAG domain should never be
//! powered in production code.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AONWUCJtagPowerOff(void)
{
    //
    // Request the power off of the Jtag domain
    //
    HWREG(AON_WUC_BASE + AON_WUC_O_JTAGCFG) = 0;
}


//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#if !defined(DRIVERLIB_NOROM) && !defined(DOXYGEN)
    #include <driverlib/rom.h>
    #ifdef ROM_AONWUCAuxReset
        #undef  AONWUCAuxReset
        #define AONWUCAuxReset                  ROM_AONWUCAuxReset
    #endif
    #ifdef ROM_AONWUCRechargeCtrlConfigSet
        #undef  AONWUCRechargeCtrlConfigSet
        #define AONWUCRechargeCtrlConfigSet     ROM_AONWUCRechargeCtrlConfigSet
    #endif
    #ifdef ROM_AONWUCOscConfig
        #undef  AONWUCOscConfig
        #define AONWUCOscConfig                 ROM_AONWUCOscConfig
    #endif
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __AON_WUC_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//*****************************************************************************
