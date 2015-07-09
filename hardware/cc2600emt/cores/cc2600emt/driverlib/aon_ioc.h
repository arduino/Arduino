/******************************************************************************
*  Filename:       aon_ioc.h
*  Revised:        2015-01-14 12:12:44 +0100 (on, 14 jan 2015)
*  Revision:       42373
*
*  Description:    Defines and prototypes for the AON IO Controller
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
//! \addtogroup aonioc_api
//! @{
//
//*****************************************************************************

#ifndef __AON_IOC_H__
#define __AON_IOC_H__

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
#include <inc/hw_aon_ioc.h>
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
// Do not define DRIVERLIB_GENERATE_ROM!
//
//*****************************************************************************
#ifndef DRIVERLIB_GENERATE_ROM
    #define AONIOCDriveStrengthSet          NOROM_AONIOCDriveStrengthSet
    #define AONIOCDriveStrengthGet          NOROM_AONIOCDriveStrengthGet
#endif

//*****************************************************************************
//
// Defines for the drive strength
//
//*****************************************************************************
#define AONIOC_DRV_STR5_7_14    0x00000000  //
#define AONIOC_DRV_STR5_10_20   0x00000001  //
#define AONIOC_DRV_STR7_14_28   0x00000003  //
#define AONIOC_DRV_STR10_20_40  0x00000002  //
#define AONIOC_DRV_STR14_28_56  0x00000006  //
#define AONIOC_DRV_STR20_40_80  0x00000007  //
#define AONIOC_DRV_STR28_56_112 0x00000005  //
#define AONIOC_DRV_STR40_80_112 0x00000004  //

#define AONIOC_MAX_DRIVE        AONIOC_DRV_STR40_80_112
#define AONIOC_MED_DRIVE        AONIOC_DRV_STR14_28_56
#define AONIOC_MIN_DRIVE        AONIOC_DRV_STR5_7_14

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Setup the drive strength for all IOs on the chip.
//!
//! Use this function to define the general drive strength settings for all IOs
//! on the device. The drive strength of the individual IOs is set using the
//! IOC driver.
//!
//! \param ui32LowDrvStr is the minimum drive strength for all IOs
//! - \ref AONIOC_DRV_STR5_7_14
//! - \ref AONIOC_DRV_STR5_10_20
//! - \ref AONIOC_DRV_STR7_14_28
//! - \ref AONIOC_DRV_STR10_20_40
//! - \ref AONIOC_DRV_STR14_28_56
//! - \ref AONIOC_DRV_STR20_40_80
//! - \ref AONIOC_DRV_STR28_56_112
//! - \ref AONIOC_DRV_STR40_80_112
//! \param ui32MedDrvStr is the medium drive strength for all IOs
//! - \ref AONIOC_DRV_STR5_7_14
//! - \ref AONIOC_DRV_STR5_10_20
//! - \ref AONIOC_DRV_STR7_14_28
//! - \ref AONIOC_DRV_STR10_20_40
//! - \ref AONIOC_DRV_STR14_28_56
//! - \ref AONIOC_DRV_STR20_40_80
//! - \ref AONIOC_DRV_STR28_56_112
//! - \ref AONIOC_DRV_STR40_80_112
//! \param ui32MaxDrvStr is the maximum drive strength for all IOs
//! - \ref AONIOC_DRV_STR5_7_14
//! - \ref AONIOC_DRV_STR5_10_20
//! - \ref AONIOC_DRV_STR7_14_28
//! - \ref AONIOC_DRV_STR10_20_40
//! - \ref AONIOC_DRV_STR14_28_56
//! - \ref AONIOC_DRV_STR20_40_80
//! - \ref AONIOC_DRV_STR28_56_112
//! - \ref AONIOC_DRV_STR40_80_112
//!
//! \return None
//!
//! \sa AONIOCDriveStrengthGet()
//
//*****************************************************************************
extern void AONIOCDriveStrengthSet(uint32_t ui32LowDrvStr,
                                   uint32_t ui32MedDrvStr,
                                   uint32_t ui32MaxDrvStr);

//*****************************************************************************
//
//! \brief Get a specific drive level setting for all IOs.
//!
//! Use this function to retreive the driver strengt setting for a specific
//! IO drive level.
//!
//! \param ui32DriveLevel is the specific drive level to get the setting for.
//! - \ref AONIOC_MAX_DRIVE
//! - \ref AONIOC_MED_DRIVE
//! - \ref AONIOC_MIN_DRIVE
//!
//! \return Returns the requested drive strength level setting for all IOs.
//! Possible values are:
//! - \ref AONIOC_DRV_STR5_7_14
//! - \ref AONIOC_DRV_STR5_10_20
//! - \ref AONIOC_DRV_STR7_14_28
//! - \ref AONIOC_DRV_STR10_20_40
//! - \ref AONIOC_DRV_STR14_28_56
//! - \ref AONIOC_DRV_STR20_40_80
//! - \ref AONIOC_DRV_STR28_56_112
//! - \ref AONIOC_DRV_STR40_80_112
//!
//! \sa AONIOCDriveStrengthSet()
//
//*****************************************************************************
extern uint32_t AONIOCDriveStrengthGet(uint32_t ui32DriveLevel);

//*****************************************************************************
//
//! \brief Freeze the IOs.
//!
//! To retain the values of the output IOs during a powerdown/shutdown of the
//! device all IO latches in the AON domain should be frozen in their current
//! state. This ensures that software can regain control of the IOs after a
//! reboot without the IOs first falling back to the default values (i.e. input
//! and no pull).
//!
//! \return None
//!
//! \sa AONIOCFreezeDisable()
//
//*****************************************************************************
__STATIC_INLINE void
AONIOCFreezeEnable(void)
{
    //
    // Set the AON IO latches as static.
    //
    HWREG(AON_IOC_BASE + AON_IOC_O_IOCLATCH) = 0x0;
}

//*****************************************************************************
//
//! \brief Un-freeze the IOs.
//!
//! When rebooting the chip after it has entered powerdown/shutdown mode, the
//! software can regain control of the IOs by setting the IO latches as
//! transparent. The IOs should not be unfrozen before software has restored
//! the functionality of the IO.
//!
//! \return None
//!
//! \sa AONIOCFreezeEnable()
//
//*****************************************************************************
__STATIC_INLINE void
AONIOCFreezeDisable(void)
{
    //
    // Set the AON IOC latches as transparent.
    //
    HWREG(AON_IOC_BASE + AON_IOC_O_IOCLATCH) = AON_IOC_IOCLATCH_EN;
}

//*****************************************************************************
//
//! \brief Disable the 32kHz clock output.
//!
//! When outputting a 32 kHz clock on an IO, the output enable/disable functionality
//! in the IOC is bypassed. Therefore, the programmer needs to call this
//! function to disable the clock output.
//!
//! \return None
//!
//! \sa AONIOC32kHzOutputEnable()
//
//*****************************************************************************
__STATIC_INLINE void
AONIOC32kHzOutputDisable(void)
{
    //
    // Disable the LF clock output.
    //
    HWREG(AON_IOC_BASE + AON_IOC_O_CLK32KCTL) = AON_IOC_CLK32KCTL_OE_N;
}

//*****************************************************************************
//
//! \brief Enable the 32kHz clock output.
//!
//! When outputting a 32 kHz clock on an IO, the output enable/disable functionality
//! in the IOC is bypassed. Therefore, the programmer needs to call this
//! function to enable the clock output.
//!
//! \return None
//!
//! \sa AONIOC32kHzOutputDisable()
//
//*****************************************************************************
__STATIC_INLINE void
AONIOC32kHzOutputEnable(void)
{
    //
    // Enable the LF clock output.
    //
    HWREG(AON_IOC_BASE + AON_IOC_O_CLK32KCTL) = 0x0;
}

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#ifndef DRIVERLIB_NOROM
    #include <driverlib/rom.h>
    #ifdef ROM_AONIOCDriveStrengthSet
        #undef  AONIOCDriveStrengthSet
        #define AONIOCDriveStrengthSet          ROM_AONIOCDriveStrengthSet
    #endif
    #ifdef ROM_AONIOCDriveStrengthGet
        #undef  AONIOCDriveStrengthGet
        #define AONIOCDriveStrengthGet          ROM_AONIOCDriveStrengthGet
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

#endif //  __AON_IOC_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//*****************************************************************************
