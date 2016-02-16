/******************************************************************************
*  Filename:       aon_wuc.h
*  Revised:        2015-07-16 12:12:04 +0200 (Thu, 16 Jul 2015)
*  Revision:       44151
*
*  Description:    Defines and prototypes for the AUX Wakeup Controller
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

//****************************************************************************
//
//! \addtogroup aux_group
//! @{
//! \addtogroup auxwuc_api
//! @{
//
//****************************************************************************

#ifndef __AUX_WUC_H__
#define __AUX_WUC_H__

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
#include <inc/hw_aux_wuc.h>
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
    #define AUXWUCClockEnable               NOROM_AUXWUCClockEnable
    #define AUXWUCClockDisable              NOROM_AUXWUCClockDisable
    #define AUXWUCClockStatus               NOROM_AUXWUCClockStatus
    #define AUXWUCPowerCtrl                 NOROM_AUXWUCPowerCtrl
#endif

//*****************************************************************************
//
// Defines for the AUX power control.
//
//*****************************************************************************
#define AUX_WUC_POWER_OFF       0x00000001
#define AUX_WUC_POWER_DOWN      0x00000002
#define AUX_WUC_POWER_ACTIVE    0x00000004

//*****************************************************************************
//
// Defines for the AUX peripherals clock control.
//
//*****************************************************************************
#define AUX_WUC_SMPH_CLOCK      (AUX_WUC_MODCLKEN0_SMPH_EN)
#define AUX_WUC_AIODIO0_CLOCK   (AUX_WUC_MODCLKEN0_AIODIO0_EN)
#define AUX_WUC_AIODIO1_CLOCK   (AUX_WUC_MODCLKEN0_AIODIO1_EN)
#define AUX_WUC_TIMER_CLOCK     (AUX_WUC_MODCLKEN0_TIMER_EN)
#define AUX_WUC_ANAIF_CLOCK     (AUX_WUC_MODCLKEN0_ANAIF_EN)
#define AUX_WUC_TDCIF_CLOCK     (AUX_WUC_MODCLKEN0_TDC_EN)
#define AUX_WUC_OSCCTRL_CLOCK   (AUX_WUC_MODCLKEN0_AUX_DDI0_OSC_EN)
#define AUX_WUC_ADI_CLOCK       (AUX_WUC_MODCLKEN0_AUX_ADI4_EN)
#define AUX_WUC_MODCLK_MASK     0x000000FF

#define AUX_WUC_TDC_CLOCK       0x00000100
#define AUX_WUC_ADC_CLOCK       0x00000200
#define AUX_WUC_REF_CLOCK       0x00000400

#define AUX_WUC_CLOCK_OFF       0x00000000
#define AUX_WUC_CLOCK_UNSTABLE  0x00000001
#define AUX_WUC_CLOCK_READY     0x00000011

#define AUX_WUC_CLOCK_HIFREQ    0x00000000
#define AUX_WUC_CLOCK_LOFREQ    0x00000001

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//****************************************************************************
//
//! \brief Enable clocks for peripherals in the AUX domain.
//!
//! Use this function to enable specific clocks in the AUX domain.
//!
//! \param ui32Clocks is a bitmap of clocks to enable.
//! Use a bitwise OR combination of the following values:
//! - \ref AUX_WUC_ADI_CLOCK
//! - \ref AUX_WUC_OSCCTRL_CLOCK
//! - \ref AUX_WUC_TDCIF_CLOCK
//! - \ref AUX_WUC_ANAIF_CLOCK
//! - \ref AUX_WUC_TIMER_CLOCK
//! - \ref AUX_WUC_AIODIO0_CLOCK
//! - \ref AUX_WUC_AIODIO1_CLOCK
//! - \ref AUX_WUC_SMPH_CLOCK
//! - \ref AUX_WUC_TDC_CLOCK
//! - \ref AUX_WUC_ADC_CLOCK
//! - \ref AUX_WUC_REF_CLOCK
//!
//! \return None
//!
//! \sa \ref AUXWUCClockDisable()
//
//****************************************************************************
extern void AUXWUCClockEnable(uint32_t ui32Clocks);

//****************************************************************************
//
//! \brief Disable clocks for peripherals in the AUX domain.
//!
//! Use this function to enable specific clocks in the AUX domain.
//!
//! \param ui32Clocks a bitmap of clocks to disable.
//! Use a bitwise OR combination of the following values:
//! - \ref AUX_WUC_ADI_CLOCK
//! - \ref AUX_WUC_OSCCTRL_CLOCK
//! - \ref AUX_WUC_TDCIF_CLOCK
//! - \ref AUX_WUC_ANAIF_CLOCK
//! - \ref AUX_WUC_TIMER_CLOCK
//! - \ref AUX_WUC_AIODIO0_CLOCK
//! - \ref AUX_WUC_AIODIO1_CLOCK
//! - \ref AUX_WUC_SMPH_CLOCK
//! - \ref AUX_WUC_TDC_CLOCK
//! - \ref AUX_WUC_ADC_CLOCK
//! - \ref AUX_WUC_REF_CLOCK
//!
//! \return None
//!
//! \sa \ref AUXWUCClockEnable()
//
//****************************************************************************
extern void AUXWUCClockDisable(uint32_t ui32Clocks);

//****************************************************************************
//
//! \brief Get the status of a clock.
//!
//! Use this function to poll the status of a specific clock in the AUX
//! domain.
//!
//! \param ui32Clocks is the clock for which to return status.
//! - \ref AUX_WUC_ADI_CLOCK
//! - \ref AUX_WUC_OSCCTRL_CLOCK
//! - \ref AUX_WUC_TDCIF_CLOCK
//! - \ref AUX_WUC_ANAIF_CLOCK
//! - \ref AUX_WUC_TIMER_CLOCK
//! - \ref AUX_WUC_AIODIO0_CLOCK
//! - \ref AUX_WUC_AIODIO1_CLOCK
//! - \ref AUX_WUC_SMPH_CLOCK
//! - \ref AUX_WUC_TDC_CLOCK
//! - \ref AUX_WUC_ADC_CLOCK
//! - \ref AUX_WUC_REF_CLOCK
//!
//! \return Returns the status of the clock as one of two states:
//! - \ref AUX_WUC_CLOCK_OFF
//! - \ref AUX_WUC_CLOCK_READY
//
//****************************************************************************
extern uint32_t AUXWUCClockStatus(uint32_t ui32Clocks);

//****************************************************************************
//
//! \brief Request a high or low frequency clock source.
//!
//! Using this function it is possible to make a request to the System
//! Control to use a high or low frequency clock as clock source for the AUX
//! domain.
//!
//! \note A low frequency clock is always 32 kHz, while a high frequency clock
//! is really a large span of frequencies determined by the clock source (High
//! Frequency or Medium Frequency) and the setting for the clock divider for
//! the AUX domain in the System Control.
//!
//! \param ui32ClockFreq determines the clock source frequency.
//! - \ref AUX_WUC_CLOCK_LOFREQ : Request low frequency clock source for AUX domain.
//! - \ref AUX_WUC_CLOCK_HIFREQ : Request high frequency clock source for AUX domain.
//!
//! \return
//
//****************************************************************************
__STATIC_INLINE void
AUXWUCClockFreqReq(uint32_t ui32ClockFreq)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32ClockFreq == AUX_WUC_CLOCK_HIFREQ) ||
           (ui32ClockFreq == AUX_WUC_CLOCK_LOFREQ));

    //
    // Set the request
    //
    HWREG(AUX_WUC_BASE + AUX_WUC_O_CLKLFREQ) = ui32ClockFreq;
}

//****************************************************************************
//
//! \brief Control the power to the AUX domain.
//!
//! Use this function to set the power mode of the entire AUX domain.
//!
//! \param ui32PowerMode control the desired power mode for the AUX domain.
//! The domain has three different power modes:
//! - \ref AUX_WUC_POWER_OFF
//! - \ref AUX_WUC_POWER_DOWN
//! - \ref AUX_WUC_POWER_ACTIVE
//!
//! \return None
//
//****************************************************************************
extern void AUXWUCPowerCtrl(uint32_t ui32PowerMode);

//*****************************************************************************
//
//! \brief Freeze the AUX IOs.
//!
//! To retain the values of the output IOs during a powerdown of the AUX domain
//! all IO latches in the AUX domain should be frozen in their current state.
//! This ensures that software can regain control of the IOs after a powerdown
//! without the IOs first falling back to the default values (i.e. input and
//! pull-up).
//!
//! \return None
//!
//! \sa AUXWUCFreezeDisable()
//
//*****************************************************************************
__STATIC_INLINE void
AUXWUCFreezeEnable(void)
{
    //
    // Set the AUX WUC latches as static.
    //
    HWREG(AUX_WUC_BASE + AUX_WUC_O_AUXIOLATCH) = 0x0;
}

//*****************************************************************************
//
//! \brief Unfreeze the AUX IOs.
//!
//! When restarting the AUX domain after it has entered powerdown mode, the
//! software can regain control of the IOs by setting the IO latches as
//! transparent.
//!
//! \note The IOs should not be unfrozen before software has restored
//! the functionality of the IO.
//!
//! \return None
//!
//! \sa AUXWUCFreezeEnable()
//
//*****************************************************************************
__STATIC_INLINE void
AUXWUCFreezeDisable(void)
{
    //
    // Set the AUX WUC latches as transparent.
    //
    HWREG(AUX_WUC_BASE + AUX_WUC_O_AUXIOLATCH) = AUX_WUC_AUXIOLATCH_EN;
}

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#if !defined(DRIVERLIB_NOROM) && !defined(DOXYGEN)
    #include <driverlib/rom.h>
    #ifdef ROM_AUXWUCClockEnable
        #undef  AUXWUCClockEnable
        #define AUXWUCClockEnable               ROM_AUXWUCClockEnable
    #endif
    #ifdef ROM_AUXWUCClockDisable
        #undef  AUXWUCClockDisable
        #define AUXWUCClockDisable              ROM_AUXWUCClockDisable
    #endif
    #ifdef ROM_AUXWUCClockStatus
        #undef  AUXWUCClockStatus
        #define AUXWUCClockStatus               ROM_AUXWUCClockStatus
    #endif
    #ifdef ROM_AUXWUCPowerCtrl
        #undef  AUXWUCPowerCtrl
        #define AUXWUCPowerCtrl                 ROM_AUXWUCPowerCtrl
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

#endif //  __AUX_WUC_H__

//****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//****************************************************************************
