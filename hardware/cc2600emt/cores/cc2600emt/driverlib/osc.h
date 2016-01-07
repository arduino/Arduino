/******************************************************************************
*  Filename:       osc.h
*  Revised:        2015-11-11 17:32:44 +0100 (Wed, 11 Nov 2015)
*  Revision:       45043
*
*  Description:    Defines and prototypes for the system oscillator control.
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
//! \addtogroup system_control_group
//! @{
//! \addtogroup osc_api
//! @{
//
//*****************************************************************************

#ifndef __OSC_H__
#define __OSC_H__

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
#include <inc/hw_ddi.h>
#include <inc/hw_ddi_0_osc.h>
#include <driverlib/aon_wuc.h>
#include <driverlib/aux_wuc.h>
#include <driverlib/rom.h>
#include <driverlib/ddi.h>
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
    #define OSCClockSourceSet               NOROM_OSCClockSourceSet
    #define OSCClockSourceGet               NOROM_OSCClockSourceGet
    #define OSCInterfaceEnable              NOROM_OSCInterfaceEnable
#endif

//*****************************************************************************
//
// Defines for the High Frequency XTAL Power mode
//
//*****************************************************************************
#define LOW_POWER_XOSC          1
#define HIGH_POWER_XOSC         0

//*****************************************************************************
//
// Defines for the High Frequency XTAL Power mode
//
//*****************************************************************************
#define OSC_SRC_CLK_HF          0x00000001
#define OSC_SRC_CLK_MF          0x00000002
#define OSC_SRC_CLK_LF          0x00000004

#define OSC_RCOSC_HF            0x00000000
#define OSC_XOSC_HF             0x00000001
#define OSC_RCOSC_LF            0x00000002
#define OSC_XOSC_LF             0x00000003

#define SCLK_HF_RCOSC_HF        0
#define SCLK_HF_XOSC_HF         1

#define SCLK_MF_RCOSC_HF        0
#define SCLK_MF_XOSC_HF         1

#define SCLK_LF_FROM_RCOSC_HF   0
#define SCLK_LF_FROM_XOSC_HF    1
#define SCLK_LF_FROM_RCOSC_LF   2
#define SCLK_LF_FROM_XOSC_LF    3

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Set Power Mode for High Frequency XTAL Oscillator.
//!
//! \param ui32Mode is the power mode for the HF XTAL.
//! - \ref LOW_POWER_XOSC
//! - \ref HIGH_POWER_XOSC
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
OSCXHfPowerModeSet(uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Mode == LOW_POWER_XOSC) ||
           (ui32Mode == HIGH_POWER_XOSC));

    //
    // Change the power mode.
    //
    DDI16BitWrite(AUX_DDI0_OSC_BASE, DDI_0_OSC_O_CTL0, DDI_0_OSC_CTL0_XOSC_HF_POWER_MODE,
                  ui32Mode);
}

//*****************************************************************************
//
//! \brief Enables OSC clock loss event detection.
//!
//! Enables the clock loss event flag to be raised if a clock loss is detected.
//!
//! \note OSC clock loss event must be disabled before SCLK_LF clock source is
//! changed (by calling \ref OSCClockSourceSet()) and remain disabled until the
//! change is confirmed (by calling \ref OSCClockSourceGet()).
//!
//! \return None
//!
//! \sa \ref OSCClockLossEventDisable()
//
//*****************************************************************************
__STATIC_INLINE void
OSCClockLossEventEnable( void )
{
    DDI16BitfieldWrite( AUX_DDI0_OSC_BASE, DDI_0_OSC_O_CTL0,
        DDI_0_OSC_CTL0_CLK_LOSS_EN_M,
        DDI_0_OSC_CTL0_CLK_LOSS_EN_S, 1 );
}

//*****************************************************************************
//
//! \brief Disables OSC clock loss event detection.
//!
//! Disabling the OSC clock loss event does also clear the clock loss event flag.
//!
//! \note OSC clock loss event must be disabled before SCLK_LF clock source is
//! changed (by calling \ref OSCClockSourceSet()) and remain disabled until the
//! change is confirmed (by calling \ref OSCClockSourceGet()).
//!
//! \return None
//!
//! \sa \ref OSCClockLossEventEnable()
//
//*****************************************************************************
__STATIC_INLINE void
OSCClockLossEventDisable( void )
{
    DDI16BitfieldWrite( AUX_DDI0_OSC_BASE, DDI_0_OSC_O_CTL0,
        DDI_0_OSC_CTL0_CLK_LOSS_EN_M,
        DDI_0_OSC_CTL0_CLK_LOSS_EN_S, 0 );
}

//*****************************************************************************
//
//! \brief Configure the oscillator input to the a source clock.
//!
//! Use this function to set the oscillator source for one or more of the
//! system source clocks.
//!
//! When selecting the high frequency clock source, this function will not do
//! the actual switch. Enabling the high frequency XTAL can take several hundred
//! micro seconds, so the actual switch is split into a separate function,
//! leaving System CPU free to perform other tasks as the XTAL starts up.
//!
//! \note The High Frequency (\ref OSC_SRC_CLK_HF) and Medium Frequency
//! (\ref OSC_SRC_CLK_MF) can only be derived from the high frequency
//! oscillator. The Low Frequency source clock (\ref OSC_SRC_CLK_LF) can be
//! derived from all 4 oscillators.
//!
//! \note If enabling \ref OSC_XOSC_LF it is not safe to go to powerdown/shutdown
//! until the LF clock is running which can be checked using \ref OSCClockSourceGet().
//!
//! \note Clock loss reset generation must be disabled before SCLK_LF (\ref OSC_SRC_CLK_LF)
//! clock source is changed and remain disabled until the change is confirmed.
//!
//! \param ui32SrcClk is the source clocks to configure.
//! - \ref OSC_SRC_CLK_HF
//! - \ref OSC_SRC_CLK_MF
//! - \ref OSC_SRC_CLK_LF
//! \param ui32Osc is the oscillator that drives the source clock.
//! - \ref OSC_RCOSC_HF
//! - \ref OSC_XOSC_HF
//! - \ref OSC_RCOSC_LF (only when ui32SrcClk is \ref OSC_SRC_CLK_LF)
//! - \ref OSC_XOSC_LF (only when ui32SrcClk is \ref OSC_SRC_CLK_LF)
//!
//! \sa OSCClockSourceGet()
//!
//! \return None
//
//*****************************************************************************
extern void OSCClockSourceSet(uint32_t ui32SrcClk, uint32_t ui32Osc);

//*****************************************************************************
//
//! \brief Get the source clock settings.
//!
//! Use this function to get the oscillator source for one of the system source
//! clocks.
//!
//! \param ui32SrcClk is the source clock to check.
//! - \ref OSC_SRC_CLK_HF
//! - \ref OSC_SRC_CLK_MF
//! - \ref OSC_SRC_CLK_LF
//!
//! \return Returns the type of oscillator that drives the clock source.
//! - \ref OSC_RCOSC_HF
//! - \ref OSC_XOSC_HF
//! - \ref OSC_RCOSC_LF
//! - \ref OSC_XOSC_LF
//!
//! \sa \ref OSCClockSourceSet(), \ref OSCHfSourceSwitch()
//
//*****************************************************************************
extern uint32_t OSCClockSourceGet(uint32_t ui32SrcClk);

//*****************************************************************************
//
//! \brief Check if the HF clock source is ready to be switched.
//!
//! If a request to switch the HF clock source has been made, this function
//! can be used to check if the clock source is ready to be switched.
//!
//! Once the HF clock source is ready the switch can be performed by calling
//! the \ref OSCHfSourceSwitch()
//!
//! \return Returns status of HF clock source:
//! - \c true  : HF clock source is ready.
//! - \c false : HF clock source is \b not ready.
//
//*****************************************************************************
__STATIC_INLINE bool
OSCHfSourceReady(void)
{
    //
    // Return the readiness of the HF clock source
    //
    return (DDI16BitfieldRead(AUX_DDI0_OSC_BASE, DDI_0_OSC_O_STAT0,
                              DDI_0_OSC_STAT0_PENDINGSCLKHFSWITCHING_M,
                              DDI_0_OSC_STAT0_PENDINGSCLKHFSWITCHING_S)) ?
        true : false;
}

//*****************************************************************************
//
//! \brief Switch the high frequency clock.
//!
//! When switching the HF clock source the clock period might be prolonged
//! leaving the clock 'stuck-at' high or low for a few cycles. To ensure that
//! this does not coincide with a read access to the Flash potentially
//! freezing the device, the HF clock source switch must be executed from ROM.
//!
//! \note This function will not return until the clock source has been
//! switched. It is left to the programmer to ensure, that there is a pending
//! request for a HF clock source switch before this function is called.
//!
//! \return None
//!
//! \sa \ref OSCClockSourceSet()
//
//*****************************************************************************
__STATIC_INLINE void
OSCHfSourceSwitch(void)
{
    //
    // Switch the HF clock source
    //
    HapiHFSourceSafeSwitch();
}

//*****************************************************************************
//
//! \brief Enable System CPU access to the OSC_DIG module.
//!
//! Force power on AUX and enable clocks to allow System CPU access on the OSC_DIG
//! interface.
//!
//! \note Access to the OSC_DIG interface is a shared resource between the
//! Sensor Controller and the CPU, so enabling or disabling this interface must
//! be done with consideration.
//!
//! \return None
//
//*****************************************************************************
extern void OSCInterfaceEnable(void);

//*****************************************************************************
//
//! \brief Disable System CPU access to the OSC_DIG module.
//!
//! Release the "force power on" of AUX and disable clock to AUX.
//!
//! \note Access to the OSC_DIG interface is a shared resource between the
//! Sensor Controller and the CPU, so enabling or disabling this interface must
//! be done with consideration.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
OSCInterfaceDisable(void)
{
    //
    // Disable clock for OSC_DIG
    //
    AUXWUCClockDisable(AUX_WUC_OSCCTRL_CLOCK);

    //
    // Release the 'force power' on AUX
    //
    AONWUCAuxWakeupEvent(AONWUC_AUX_ALLOW_SLEEP);
}


//*****************************************************************************
//
//! \brief Returns maximum startup time (in microseconds) of XOSC_HF.
//!
//! The startup time depends on several factors. This function calculates the
//! maximum startup time based on statistical information.
//!
//! \param timeUntilWakeupInMs indicates how long time (milliseconds) to the
//! startup will occur.
//!
//! \return Time margin to use in microseconds.
//
//*****************************************************************************
uint32_t OSCHF_GetStartupTime( uint32_t timeUntilWakeupInMs );


//*****************************************************************************
//
//! \brief Turns on XOSC_HF (but without switching to XOSC_HF).
//!
//! This function simply indicates the need for XOSC_HF to the hardware which
//! initiates the XOSC_HF startup.
//!
//! \return None
//
//*****************************************************************************
void OSCHF_TurnOnXosc( void );


//*****************************************************************************
//
//! \brief Switch to XOSC_HF if XOSC_HF is ready.
//!
//! This is a non-blocking function checking if the XOSC_HF is ready and
//! performs the switching if ready. The function is somewhat blocking in the
//! case where switching is performed.
//!
//! \return Returns status of the XOSC_HF switching:
//! - \c true  : Switching to XOSC_HF has occurred.
//! - \c false : Switching has not occurred.
//
//*****************************************************************************
bool OSCHF_AttemptToSwitchToXosc( void );


//*****************************************************************************
//
//! \brief Switch to RCOSC_HF and turn off XOSC_HF.
//!
//! This operation takes approximately 50 microseconds (can be shorter if
//! RCOSC_HF already was running).
//!
//! \return None
//
//*****************************************************************************
void OSCHF_SwitchToRcOscTurnOffXosc( void );

//*****************************************************************************
//
//! \brief Calculate the temperature dependent relative frequency offset of HPOSC
//!
//! The HPOSC (High Precision Oscillator) frequency will vary slightly with chip temperature.
//! The frequency offset from the nominal value can be predicted based on
//! second order linear interpolation using coefficients measured in chip
//! production and stored as factory configuration parameters.
//!
//! This function calculates the relative frequency offset, defined as:
//! <pre>
//!     F_HPOSC = F_nom * (1 + d/(2^22))
//! </pre>
//! where
//! -   F_HPOSC is the current HPOSC frequency.
//! -   F_nom is the nominal oscillator frequency, assumed to be 48.000 MHz.
//! -   d is the relative frequency offset (the value returned).
//!
//! By knowing the relative frequency offset it is then possible to compensate
//! any timing related values accordingly.
//!
//! \param tempDegC is the chip temperature in degrees Celsius. Use the
//! function \ref AONBatMonTemperatureGetDegC() to get current chip temperature.
//!
//! \return Returns the relative frequency offset parameter d.
//!
//! \sa OSC_HPOSCRelativeFrequencyOffsetToRFCoreFormatConvert(), AONBatMonTemperatureGetDegC()
//
//*****************************************************************************
extern int32_t OSC_HPOSCRelativeFrequencyOffsetGet( int32_t tempDegC );

//*****************************************************************************
//
//! \brief Converts the relative frequency offset of HPOSC to the RF Core parameter format.
//!
//! The HPOSC (High Precision Oscillator) clock is used by the RF Core.
//! To compensate for a frequency offset in the frequency of the clock source,
//! a frequency offset parameter can be provided as part of the radio configuration
//! override setting list to enable compensation of the RF synthesizer frequency,
//! symbol timing, and radio timer to still achieve correct frequencies.
//!
//! The RF Core takes a relative frequency offset parameter defined differently
//! compared to the relative frequency offset parameter returned from function
//! \ref OSC_HPOSCRelativeFrequencyOffsetGet() and thus needs to be converted:
//! <pre>
//!     F_nom = F_HPOSC * (1 + RfCoreRelFreqOffset/(2^22))
//! </pre>
//! where
//! -   F_nom is the nominal oscillator frequency, assumed to be 48.000 MHz.
//! -   F_HPOSC is the current HPOSC frequency.
//! -   RfCoreRelFreqOffset is the relative frequency offset in the "RF Core" format (the value returned).
//!
//! \return Returns the relative frequency offset in RF Core format.
//!
//! \sa OSC_HPOSCRelativeFrequencyOffsetGet()
//
//*****************************************************************************
extern int16_t OSC_HPOSCRelativeFrequencyOffsetToRFCoreFormatConvert( int32_t HPOSC_RelFreqOffset );


//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#if !defined(DRIVERLIB_NOROM) && !defined(DOXYGEN)
    #include <driverlib/rom.h>
    #ifdef ROM_OSCClockSourceSet
        #undef  OSCClockSourceSet
        #define OSCClockSourceSet               ROM_OSCClockSourceSet
    #endif
    #ifdef ROM_OSCClockSourceGet
        #undef  OSCClockSourceGet
        #define OSCClockSourceGet               ROM_OSCClockSourceGet
    #endif
    #ifdef ROM_OSCInterfaceEnable
        #undef  OSCInterfaceEnable
        #define OSCInterfaceEnable              ROM_OSCInterfaceEnable
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


#endif // __OSC_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//*****************************************************************************
