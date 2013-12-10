//*****************************************************************************
//
// hibernate.c - Driver for the Hibernation module
//
// Copyright (c) 2007-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup hibernate_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "inc/hw_hibernate.h"
#include "inc/hw_ints.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/hibernate.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

//*****************************************************************************
//
// The delay in microseconds for writing to the Hibernation module registers.
//
//*****************************************************************************
#define DELAY_USECS             95

//*****************************************************************************
//
// The number of processor cycles to execute one pass of the delay loop.
//
//*****************************************************************************
#define LOOP_CYCLES             3

//*****************************************************************************
//
// A macro used to determine whether the target part supports Wake from IO
// pins.
//
//*****************************************************************************
#define HIBERNATE_WAKE_IO       CLASS_IS_SNOWFLAKE

//*****************************************************************************
//
// A macro used to determine whether the target part supports Wake from IO
// pins.
//
//*****************************************************************************
#define HIBERNATE_CLOCK_OUTPUT  CLASS_IS_SNOWFLAKE

//*****************************************************************************
//
//! \internal
//!
//! Polls until the write complete (WRC) bit in the hibernate control register
//! is set.
//!
//! \param None.
//!
//! The Hibernation module provides an indication when any write is completed.
//! This mechanism is used to pace writes to the module.  This function merely
//! polls this bit and returns as soon as it is set.  At this point, it is safe
//! to perform another write to the module.
//!
//! \return None.
//
//*****************************************************************************
static void
_HibernateWriteComplete(void)
{
    //
    // Spin until the write complete bit is set.
    //
    while(!(HWREG(HIB_CTL) & HIB_CTL_WRC))
    {
    }
}

//*****************************************************************************
//
//! Enables the Hibernation module for operation.
//!
//! \param ui32HibClk is the rate of the clock supplied to the Hibernation
//! module.
//!
//! This function enables the Hibernation module for operation.  This function
//! should be called before any of the Hibernation module features are used.
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard-coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
//!
//! \return None.
//
//*****************************************************************************
void
HibernateEnableExpClk(uint32_t ui32HibClk)
{
    //
    // Turn on the clock enable bit.
    //
    HWREG(HIB_CTL) |= HIB_CTL_CLK32EN;

    //
    // Wait for write complete following register load (above).
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Disables the Hibernation module for operation.
//!
//! This function disables the Hibernation module.  After this function is
//! called, none of the Hibernation module features are available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateDisable(void)
{
    //
    // Turn off the clock enable bit.
    //
    HWREG(HIB_CTL) &= ~HIB_CTL_CLK32EN;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Configures the clock input for the Hibernation module.
//!
//! \param ui32Config is one of the possible configuration options for the
//! clock input listed below.
//!
//! This function is used to configure the clock input for the Hibernation
//! module.  The \e ui32Config parameter can be one of the following values:
//!
//! - \b HIBERNATE_OSC_DISABLE specifies that the internal oscillator
//! is powered off.  This is used when an externally supplied oscillator is
//! connected to the XOSC0 pin or to save power when the LFIOSC is used in
//! devices that have an LFIOSC in the hibernation module.
//! - \b HIBERNATE_OSC_HIGHDRIVE specifies a higher drive strength when a 24pF
//! filter capacitor is used with a crystal.
//! - \b HIBERNATE_OSC_LOWDRIVE specifies a lower drive strength when a 12pF
//! filter capacitor is used with a crystal.
//!
//! On some devices, there is an option to use an internal low frequency
//! oscillator (LFIOSC) as the clock source for the hibernation module.
//! Because of the low accuracy of this oscillator, this option should not be
//! used when the system requires a real time counter.  Adding the
//! \b HIBERNATE_OSC_LFIOSC value enables the LFIOSC as the clock source to
//! the hibernation module.
//!
//! - \b HIBERNATE_OSC_LFIOSC enables the hibernation module's internal low
//! frequency oscillator as the clock to the hibernation module.
//!
//! This \e ui32Config also configures how the clock output from the
//! hibernation is used to clock other peripherals in the system.  The ALT
//! clock settings allow clocking a subset of the peripherals.  See the
//! hibernate section in the datasheet to determine which peripherals can be
//! clocked by the ALT clock outputs from the hibernation module.
//! The \e ui32Config parameter can have any combination of the
//! following values:
//!
//! - \b HIBERNATE_OUT_SYSCLK enables the hibernate clock output to the system
//!      clock.
//! - \b HIBERNATE_OUT_ALT1CLK enables the hibernate clock output to the
//!      LPC module to allow the LPC and the hibernation module RTC to use the
//!      same 32.768-kHz clock.
//!
//! The \b HIBERNATE_OSC_DISABLE option is used to disable and power down the
//! internal oscillator if an external clock source or no clock source is used
//! instead of a 32.768-kHz crystal.  In the case where an external crystal is
//! used, either the \b HIBERNATE_OSC_HIGHDRIVE or \b HIBERNATE_OSC_LOWDRIVE is
//! used.  These settings optimizes the oscillator drive strength to match the
//! size of the filter capacitor that is used with the external crystal
//! circuit.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateClockConfig(uint32_t ui32Config)
{
    uint32_t ui32HIBCtl;

    ASSERT((ui32Config & ~(HIBERNATE_OSC_HIGHDRIVE | HIBERNATE_OSC_LOWDRIVE |
                           HIBERNATE_OSC_DISABLE)) == 0);

    ui32HIBCtl = HWREG(HIB_CTL);

    //
    // Clear the current configuration bits.
    //
    ui32HIBCtl &= ~(HIBERNATE_OSC_HIGHDRIVE | HIBERNATE_OSC_LOWDRIVE |
                    HIBERNATE_OSC_LFIOSC | HIBERNATE_OSC_DISABLE);

    //
    // Set the new configuration bits.
    //
    ui32HIBCtl |= ui32Config & (HIBERNATE_OSC_HIGHDRIVE |
                                HIBERNATE_OSC_LOWDRIVE |
                                HIBERNATE_OSC_LFIOSC |
                                HIBERNATE_OSC_DISABLE);

    //
    // Must be sure that the 32KHz clock is enabled if the hibernate is about
    // to switch to it.
    //
    if(ui32Config & HIBERNATE_OSC_LFIOSC)
    {
        ui32HIBCtl |= HIB_CTL_CLK32EN;
    }

    //
    // Set the hibernation clocking configuration.
    //
    HWREG(HIB_CTL) = ui32HIBCtl;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();

    //
    // Write the output clock configuration for devices that support
    // controlling the output clocks from the hibernate module.
    //
    if(HIBERNATE_CLOCK_OUTPUT)
    {
        HWREG(HIB_CC) = ui32Config & (HIBERNATE_OUT_SYSCLK |
                                      HIBERNATE_OUT_ALT1CLK);
    }
}

//*****************************************************************************
//
//! Enables the RTC feature of the Hibernation module.
//!
//! This function enables the RTC in the Hibernation module.  The RTC can be
//! used to wake the processor from hibernation at a certain time, or to
//! generate interrupts at certain times.  This function must be called before
//! using any of the RTC features of the Hibernation module.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRTCEnable(void)
{
    //
    // Turn on the RTC enable bit.
    //
    HWREG(HIB_CTL) |= HIB_CTL_RTCEN;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Disables the RTC feature of the Hibernation module.
//!
//! This function disables the RTC in the Hibernation module.  After calling
//! this function, the RTC features of the Hibernation module are not
//! available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRTCDisable(void)
{
    //
    // Turn off the RTC enable bit.
    //
    HWREG(HIB_CTL) &= ~HIB_CTL_RTCEN;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Forces the Hibernation module to initiate a check of the battery voltage.
//!
//! This function forces the Hibernation module to initiate a check of the
//! battery voltage immediately rather than waiting for the next check interval
//! to pass.  After calling this function, the application should call the
//! HibernateBatCheckDone() function and wait for the function to return a zero
//! value before calling the HibernateIntStatus() to check if the return code
//! has the \b HIBERNATE_INT_LOW_BAT set.  If \b HIBERNATE_INT_LOW_BAT is set,
//! the battery level is low.  The application can also enable the
//! \b HIBERNATE_INT_LOW_BAT interrupt and wait for an interrupt to indicate
//! that the battery level is low.
//!
//! \note A hibernation request is held off if a battery check is in progress.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateBatCheckStart(void)
{
    //
    // Initiated a forced battery check.
    //
    HWREG(HIB_CTL) |= HIB_CTL_BATCHK;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Determines whether or not a forced battery check has completed.
//!
//! This function determines whether the forced battery check initiated by a
//! call to the HibernateBatCheckStart() function has completed.  This function
//! returns a non-zero value until the battery level check has completed.  Once
//! this function returns a value of zero, the hibernation module has completed
//! the battery check and the HibernateIntStatus() function can be used to
//! check if the battery was low by checking if the value returned has the
//! \b HIBERNATE_INT_LOW_BAT set.
//!
//! \return The value is zero when the battery level check has completed or
//! non-zero if the check is still in process.
//
//*****************************************************************************
uint32_t
HibernateBatCheckDone(void)
{
    //
    // Read the current state of the battery check.
    //
    return(HWREG(HIB_CTL) & HIB_CTL_BATCHK);
}

//*****************************************************************************
//
//! Configures the wake conditions for the Hibernation module.
//!
//! \param ui32WakeFlags specifies which conditions should be used for waking.
//!
//! This function enables the conditions under which the Hibernation module
//! wakes.  The \e ui32WakeFlags parameter is the logical OR of any combination
//! of the following:
//!
//! - \b HIBERNATE_WAKE_PIN - wake when the external wake pin is asserted.
//! - \b HIBERNATE_WAKE_RTC - wake when the RTC match occurs.
//! - \b HIBERNATE_WAKE_LOW_BAT - wake from hibernate due to a low-battery
//! level being detected.
//! - \b HIBERNATE_WAKE_GPIO - wake when a GPIO pin is asserted.
//! - \b HIBERNATE_WAKE_RESET - wake when a reset pin is asserted.
//!
//! If the \b HIBERNATE_WAKE_GPIO flag is set, then one of the GPIO
//! configuration functions GPIOPinTypeWakeHigh() or GPIOPinTypeWakeLow() must
//! be called to properly configure and enable a GPIO as a wake source for
//! hibernation.
//!
//! \note The \b HIBERNATE_WAKE_GPIO and \b HIBERNATE_WAKE_RESET parameters are
//! only available on some Tiva devices.
//!
//! \note On some Tiva devices a tamper event acts as a wake source for the
//! hibernation module.  Refer the function \b HibernateTamperEventsConfig() to
//! wake from hibernation on a tamper event.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateWakeSet(uint32_t ui32WakeFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ui32WakeFlags & ~(HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC |
                               HIBERNATE_WAKE_GPIO | HIBERNATE_WAKE_RESET |
                               HIBERNATE_WAKE_LOW_BAT)));

    //
    // Set the specified wake flags in the control register.
    //
    HWREG(HIB_CTL) = (ui32WakeFlags | (HWREG(HIB_CTL) &
                                       ~(HIBERNATE_WAKE_PIN |
                                         HIBERNATE_WAKE_RTC |
                                         HIBERNATE_WAKE_LOW_BAT)));

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();

    //
    // Write the hibernate IO register if requested.
    //
    if(HIBERNATE_WAKE_IO)
    {
        //
        // If the reset or GPIOs are begin used as a wake source then the
        // the VDD3ON needs to be set to allow the pads to remained
        // powered.
        //
        if((ui32WakeFlags & (HIBERNATE_WAKE_RESET | HIBERNATE_WAKE_GPIO)) &&
           ((HWREG(HIB_CTL) & HIB_CTL_VDD3ON) == 0))
        {
            //
            // Make sure that VDD3ON mode is enabled so that the pads can
            // retain their state.
            //
            HWREG(HIB_CTL) |= HIB_CTL_VDD3ON;

            //
            // Wait for write completion
            //
            _HibernateWriteComplete();
        }

        //
        // Set the requested flags.
        //
        HWREG(HIB_IO) = (ui32WakeFlags >> 16) | HIB_IO_WUUNLK;

        //
        // Spin until the write complete bit is set.
        //
        while((HWREG(HIB_IO) & HIB_IO_IOWRC) == 0)
        {
        }

        //
        // Clear the write unlock bit.
        //
        HWREG(HIB_IO) &= ~HIB_IO_WUUNLK;
    }
}

//*****************************************************************************
//
//! Gets the currently configured wake conditions for the Hibernation module.
//!
//! This function returns the flags representing the wake configuration for the
//! Hibernation module.  The return value is a combination of the following
//! flags:
//!
//! - \b HIBERNATE_WAKE_PIN - wake when the external wake pin is asserted
//! - \b HIBERNATE_WAKE_RTC - wake when the RTC matches occurs
//! - \b HIBERNATE_WAKE_LOW_BAT - wake from hibernation due to a low-battery
//! level being detected
//! - \b HIBERNATE_WAKE_GPIO - wake when a GPIO pin is asserted
//! - \b HIBERNATE_WAKE_RESET - wake when a reset pin is asserted
//!
//! \note The \b HIBERNATE_WAKE_LOW_BAT, \b HIBERNATE_WAKE_GPIO, and
//! \b HIBERNATE_WAKE_RESET parameters are only available on some Tiva devices.
//!
//! \note On some Tiva devices a tamper event acts as a wake source for the
//! hibernation module.  Refer the function \b HibernateTamperEventsConfig() to
//! wake from hibernation on a tamper event.
//!
//! \return Returns flags indicating the configured wake conditions.
//
//*****************************************************************************
uint32_t
HibernateWakeGet(void)
{
    uint32_t ui32Ctrl;

    //
    // Read the wake bits from the control register and return those bits to
    // the caller.
    //
    if(HIBERNATE_WAKE_IO)
    {
        ui32Ctrl = HWREG(HIB_CTL);
        return((ui32Ctrl & (HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC |
                            HIBERNATE_WAKE_LOW_BAT)) |
               ((HWREG(HIB_IO) << 16) & (HIBERNATE_WAKE_RESET |
                                         HIBERNATE_WAKE_GPIO)));
    }
    else
    {
        return(HWREG(HIB_CTL) & (HIBERNATE_WAKE_PIN | HIBERNATE_WAKE_RTC |
                                 HIBERNATE_WAKE_LOW_BAT));
    }
}

//*****************************************************************************
//
//! Configures the low-battery detection.
//!
//! \param ui32LowBatFlags specifies behavior of low-battery detection.
//!
//! This function enables the low-battery detection and whether hibernation is
//! allowed if a low battery is detected.  If low-battery detection is enabled,
//! then a low-battery condition is indicated in the raw interrupt status
//! register, which can be enabled to trigger an interrupt.  Optionally,
//! hibernation can be aborted if a low battery condition is detected.
//!
//! The \e ui32LowBatFlags parameter is one of the following values:
//!
//! - \b HIBERNATE_LOW_BAT_DETECT - detect a low-battery condition
//! - \b HIBERNATE_LOW_BAT_ABORT - detect a low-battery condition and abort
//!   hibernation if low-battery is detected
//!
//! The other setting in the \e ui32LowBatFlags allows the caller to set one of
//! the following voltage level trigger values :
//!
//! - \b HIBERNATE_LOW_BAT_1_9V - voltage low level is 1.9 V
//! - \b HIBERNATE_LOW_BAT_2_1V - voltage low level is 2.1 V
//! - \b HIBERNATE_LOW_BAT_2_3V - voltage low level is 2.3 V
//! - \b HIBERNATE_LOW_BAT_2_5V - voltage low level is 2.5 V
//!
//! \b Example: Abort hibernate if the voltage level is below 2.1 V.
//!
//! \verbatim
//! HibernateLowBatSet(HIBERNATE_LOW_BAT_ABORT | HIBERNATE_LOW_BAT_2_1V);
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************
void
HibernateLowBatSet(uint32_t ui32LowBatFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ui32LowBatFlags &
             ~(HIB_CTL_VBATSEL_M | HIBERNATE_LOW_BAT_ABORT)));

    //
    // Set the low-battery detect and abort bits in the control register,
    // according to the parameter.
    //
    HWREG(HIB_CTL) = (ui32LowBatFlags |
                      (HWREG(HIB_CTL) & ~(HIB_CTL_VBATSEL_M |
                                          HIBERNATE_LOW_BAT_ABORT)));

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Gets the currently configured low-battery detection behavior.
//!
//! This function returns a value representing the currently configured low
//! battery detection behavior.
//!
//! The return value is a combination of the values described in the
//! HibernateLowBatSet() function.
//!
//! \return Returns a value indicating the configured low-battery detection.
//
//*****************************************************************************
uint32_t
HibernateLowBatGet(void)
{
    //
    // Read the supported low bat bits from the control register and return
    // those bits to the caller.
    //
    return(HWREG(HIB_CTL) & (HIB_CTL_VBATSEL_M | HIBERNATE_LOW_BAT_ABORT));
}

//*****************************************************************************
//
//! Sets the value of the real time clock (RTC) counter.
//!
//! \param ui32RTCValue is the new value for the RTC.
//!
//! This function sets the value of the RTC.  The RTC counter contains the
//! count in seconds when a 32.768kHz clock source is in use.  The RTC must be
//! enabled by calling HibernateRTCEnable() before calling this function.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRTCSet(uint32_t ui32RTCValue)
{
    //
    // Load register requires unlock.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Write the new RTC value to the RTC load register.
    //
    HWREG(HIB_RTCLD) = ui32RTCValue;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();

    //
    // Unlock.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Gets the value of the real time clock (RTC) counter.
//!
//! This function gets the value of the RTC and returns it to the caller.
//!
//! \return Returns the value of the RTC counter in seconds.
//
//*****************************************************************************
uint32_t
HibernateRTCGet(void)
{
    //
    // Return the value of the RTC counter register to the caller.
    //
    return(HWREG(HIB_RTCC));
}

//*****************************************************************************
//
//! Sets the value of the RTC match register.
//!
//! \param ui32Match is the index of the match register.
//! \param ui32Value is the value for the match register.
//!
//! This function sets a match register for the RTC.  The Hibernation
//! module can be configured to wake from hibernation, and/or generate an
//! interrupt when the value of the RTC counter is the same as the match
//! register.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRTCMatchSet(uint32_t ui32Match, uint32_t ui32Value)
{
    ASSERT(ui32Match == 0);

    //
    // Write the new match value to the match register.
    //
    HWREG(HIB_RTCM0) = ui32Value;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Gets the value of the requested RTC match register.
//!
//! \param ui32Match is the index of the match register.
//!
//! This function gets the value of the match register for the RTC.  The only
//! value that can be used with the \e ui32Match parameter is zero, other
//! values are reserved for future use.
//!
//! \return Returns the value of the requested match register.
//
//*****************************************************************************
uint32_t
HibernateRTCMatchGet(uint32_t ui32Match)
{
    ASSERT(ui32Match == 0);

    //
    // Return the value of the match register to the caller.
    //
    return(HWREG(HIB_RTCM0));
}

//*****************************************************************************
//
//! Sets the value of the RTC sub second match register.
//!
//! \param ui32Match is the index of the match register.
//! \param ui32Value is the value for the sub second match register.
//!
//! This function sets the sub second match register for the RTC in 1/32768
//! of a second increments.  The Hibernation module can be configured to wake
//! from hibernation, and/or generate an interrupt when the value of the RTC
//! counter is the same as the match combined with the sub second match
//! register.  The only value that can be used with the \e ui32Match
//! parameter is zero, other values are reserved for future use.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRTCSSMatchSet(uint32_t ui32Match, uint32_t ui32Value)
{
    ASSERT(ui32Match == 0);

    //
    // Write the new sub second match value to the sub second match register.
    //
    HWREG(HIB_RTCSS) = ui32Value << HIB_RTCSS_RTCSSM_S;

    //
    // Wait for write complete to be signaled on later devices.
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Returns the value of the requested RTC sub second match register.
//!
//! \param ui32Match is the index of the match register.
//!
//! This function returns the current value of the sub second match register
//! for the RTC.  The value returned is in 1/32768 second increments.  The only
//! value that can be used with the \e ui32Match parameter is zero, other
//! values are reserved for future use.
//!
//! \return Returns the value of the requested sub section match register.
//
//*****************************************************************************
uint32_t
HibernateRTCSSMatchGet(uint32_t ui32Match)
{
    ASSERT(ui32Match == 0);

    //
    // Read the current second RTC count.
    //
    return(HWREG(HIB_RTCSS) >> HIB_RTCSS_RTCSSM_S);
}

//*****************************************************************************
//
//! Returns the current value of the RTC sub second count.
//!
//! This function returns the current value of the sub second count for the RTC
//! in 1/32768 of a second increments.  The only value that can be used with
//! the \e ui32Match parameter is zero, other values are reserved for future
//! use.
//!
//! \return The current RTC sub second count in 1/32768 seconds.
//
//*****************************************************************************
uint32_t
HibernateRTCSSGet(void)
{
    //
    // Read the current second RTC count.
    //
    return(HWREG(HIB_RTCSS) & HIB_RTCSS_RTCSSC_M);
}

//*****************************************************************************
//
//! Sets the value of the RTC pre-divider trim register.
//!
//! \param ui32Trim is the new value for the pre-divider trim register.
//!
//! This function sets the value of the pre-divider trim register.  The input
//! time source is divided by the pre-divider to achieve a one-second clock
//! rate.  Once every 64 seconds, the value of the pre-divider trim register is
//! applied to the pre-divider to allow fine-tuning of the RTC rate, in order
//! to make corrections to the rate.  The software application can make
//! adjustments to the pre-divider trim register to account for variations in
//! the accuracy of the input time source.  The nominal value is 0x7FFF, and it
//! can be adjusted up or down in order to fine-tune the RTC rate.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRTCTrimSet(uint32_t ui32Trim)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Trim < 0x10000);

    //
    // Write the new trim value to the trim register.
    //
    HWREG(HIB_RTCT) = ui32Trim;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Gets the value of the RTC pre-divider trim register.
//!
//! This function gets the value of the pre-divider trim register.  This
//! function can be used to get the current value of the trim register prior
//! to making an adjustment by using the HibernateRTCTrimSet() function.
//!
//! \return None.
//
//*****************************************************************************
uint32_t
HibernateRTCTrimGet(void)
{
    //
    // Return the value of the trim register to the caller.
    //
    return(HWREG(HIB_RTCT));
}

//*****************************************************************************
//
//! Stores data in the battery-backed memory of the Hibernation module.
//!
//! \param pui32Data points to the data that the caller wants to store in the
//! memory of the Hibernation module.
//! \param ui32Count is the count of 32-bit words to store.
//!
//! Stores a set of data in the Hibernation module battery-backed memory.
//! This memory is preserved when the power to the processor is turned off
//! and can be used to store application state information that is needed when
//! the processor wakes.  Up to 16 32-bit words can be stored in the
//! battery-backed memory.  The data can be restored by calling the
//! HibernateDataGet() function.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateDataSet(uint32_t *pui32Data, uint32_t ui32Count)
{
    uint32_t ui32Idx;

    //
    // Check the arguments.
    //
    ASSERT(ui32Count <= 64);
    ASSERT(pui32Data != 0);

    //
    // Loop through all the words to be stored, storing one at a time.
    //
    for(ui32Idx = 0; ui32Idx < ui32Count; ui32Idx++)
    {
        //
        // Write a word to the battery-backed storage area.
        //
        HWREG(HIB_DATA + (ui32Idx * 4)) = pui32Data[ui32Idx];

        //
        // Wait for write completion
        //
        _HibernateWriteComplete();
    }
}

//*****************************************************************************
//
//! Reads a set of data from the battery-backed memory of the Hibernation
//! module.
//!
//! \param pui32Data points to a location where the data that is read from the
//! Hibernation module is stored.
//! \param ui32Count is the count of 32-bit words to read.
//!
//! This function retrieves a set of data from the Hibernation module
//! battery-backed memory that was previously stored with the
//! HibernateDataSet() function.  The caller must ensure that \e pui32Data
//! points to a large enough memory block to hold all the data that is read
//! from the battery-backed memory.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateDataGet(uint32_t *pui32Data, uint32_t ui32Count)
{
    uint32_t ui32Idx;

    //
    // Check the arguments.
    //
    ASSERT(ui32Count <= 64);
    ASSERT(pui32Data != 0);

    //
    // Loop through all the words to be restored, reading one at a time.
    //
    for(ui32Idx = 0; ui32Idx < ui32Count; ui32Idx++)
    {
        //
        // Read a word from the battery-backed storage area.  No delay is
        // required between reads.
        //
        pui32Data[ui32Idx] = HWREG(HIB_DATA + (ui32Idx * 4));
    }
}

//*****************************************************************************
//
//! Requests hibernation mode.
//!
//! This function requests the Hibernation module to disable the external
//! regulator, thus removing power from the processor and all peripherals.  The
//! Hibernation module remains powered from the battery or auxiliary power
//! supply.
//!
//! The Hibernation module re-enables the external regulator when one of
//! the configured wake conditions occurs (such as RTC match or external
//! \b WAKE pin).  When the power is restored, the processor goes through a
//! power-on reset although the Hibernation module is not reset.  The processor
//! can retrieve saved state information with the HibernateDataGet() function.
//! Prior to calling the function to request hibernation mode, the conditions
//! for waking must have already been set by using the HibernateWakeSet()
//! function.
//!
//! Note that this function may return because some time may elapse before the
//! power is actually removed, or it may not be removed at all.  For this
//! reason, the processor continues to execute instructions for some time,
//! and the caller should be prepared for this function to return.  There are
//! various reasons why the power may not be removed.  For example, if the
//! HibernateLowBatSet() function was used to configure an abort if low
//! battery is detected, then the power is not removed if the battery
//! voltage is too low.  There may be other reasons related to the external
//! circuit design, that a request for hibernation may not actually occur.
//!
//! For all these reasons, the caller must be prepared for this function to
//! return.  The simplest way to handle it is to just enter an infinite loop
//! and wait for the power to be removed.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateRequest(void)
{
    //
    // Set the bit in the control register to cut main power to the processor.
    //
    HWREG(HIB_CTL) |= HIB_CTL_HIBREQ;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Enables interrupts for the Hibernation module.
//!
//! \param ui32IntFlags is the bit mask of the interrupts to be enabled.
//!
//! This function enables the specified interrupt sources from the Hibernation
//! module.
//!
//! The \e ui32IntFlags parameter must be the logical OR of any combination of
//! the following:
//!
//! - \b HIBERNATE_INT_WR_COMPLETE - write complete interrupt
//! - \b HIBERNATE_INT_PIN_WAKE - wake from pin interrupt
//! - \b HIBERNATE_INT_LOW_BAT - low-battery interrupt
//! - \b HIBERNATE_INT_RTC_MATCH_0 - RTC match 0 interrupt
//! - \b HIBERNATE_INT_VDDFAIL - supply failure interrupt.
//! - \b HIBERNATE_INT_RESET_WAKE - wake from reset pin interrupt
//! - \b HIBERNATE_INT_GPIO_WAKE - wake from GPIO pin interrupt
//!
//! \note The \b HIBERNATE_INT_RESET_WAKE, \b HIBERNATE_INT_GPIO_WAKE, and
//! \b HIBERNATE_INT_VDDFAIL settings are not available on all Tiva devices.
//! Please consult the data sheet for the Tiva device that you are using to
//! determine if these interrupt sources are available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateIntEnable(uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ui32IntFlags & ~(HIBERNATE_INT_PIN_WAKE | HIBERNATE_INT_LOW_BAT |
                              HIBERNATE_INT_VDDFAIL |
                              HIBERNATE_INT_RESET_WAKE |
                              HIBERNATE_INT_GPIO_WAKE |
                              HIBERNATE_INT_RTC_MATCH_0 |
                              HIBERNATE_INT_WR_COMPLETE)));

    //
    // Set the specified interrupt mask bits.
    //
    HWREG(HIB_IM) |= ui32IntFlags;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Disables interrupts for the Hibernation module.
//!
//! \param ui32IntFlags is the bit mask of the interrupts to be disabled.
//!
//! This function disables the specified interrupt sources from the
//! Hibernation module.
//!
//! The \e ui32IntFlags parameter has the same definition as the
//! \e ui32IntFlags parameter to the HibernateIntEnable() function.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateIntDisable(uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ui32IntFlags & ~(HIBERNATE_INT_PIN_WAKE | HIBERNATE_INT_LOW_BAT |
                              HIBERNATE_INT_VDDFAIL |
                              HIBERNATE_INT_RESET_WAKE |
                              HIBERNATE_INT_GPIO_WAKE |
                              HIBERNATE_INT_RTC_MATCH_0 |
                              HIBERNATE_INT_WR_COMPLETE)));

    //
    // Clear the specified interrupt mask bits.
    //
    HWREG(HIB_IM) &= ~ui32IntFlags;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Returns the hibernate module interrupt number.
//!
//! This function returns the interrupt number for the hibernate module.
//!
//! \return Returns a hibernate interrupt number or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint32_t
_HibernateIntNumberGet(void)
{
    uint32_t ui32Int;

    //
    // Find the valid interrupt number for the hibernate module.
    //
    if(CLASS_IS_SNOWFLAKE)
    {
        ui32Int = INT_HIBERNATE_SNOWFLAKE;
    }
    else
    {
        ui32Int = INT_HIBERNATE_BLIZZARD;
    }

    return(ui32Int);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the Hibernation module interrupt.
//!
//! \param pfnHandler points to the function to be called when a hibernation
//! interrupt occurs.
//!
//! This function registers the interrupt handler in the system interrupt
//! controller.  The interrupt is enabled at the global level, but individual
//! interrupt sources must still be enabled with a call to
//! HibernateIntEnable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateIntRegister(void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Get the interrupt number for the Hibernate module.
    //
    ui32Int = _HibernateIntNumberGet();

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the hibernate module interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the Hibernation module interrupt.
//!
//! This function unregisters the interrupt handler in the system interrupt
//! controller.  The interrupt is disabled at the global level, and the
//! interrupt handler is no longer called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateIntUnregister(void)
{
    uint32_t ui32Int;

    //
    // Get the interrupt number for the Hibernate module.
    //
    ui32Int = _HibernateIntNumberGet();

    ASSERT(ui32Int != 0);

    //
    // Disable the hibernate interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Gets the current interrupt status of the Hibernation module.
//!
//! \param bMasked is false to retrieve the raw interrupt status, and true to
//! retrieve the masked interrupt status.
//!
//! This function returns the interrupt status of the Hibernation module.  The
//! caller can use this function to determine the cause of a hibernation
//! interrupt.  Either the masked or raw interrupt status can be returned.
//!
//! \return Returns the interrupt status as a bit field with the values as
//! described in the HibernateIntEnable() function.
//
//*****************************************************************************
uint32_t
HibernateIntStatus(bool bMasked)
{
    //
    // Read and return the Hibernation module raw or masked interrupt status.
    //
    if(bMasked == true)
    {
        return(HWREG(HIB_MIS));
    }
    else
    {
        return(HWREG(HIB_RIS));
    }
}

//*****************************************************************************
//
//! Clears pending interrupts from the Hibernation module.
//!
//! \param ui32IntFlags is the bit mask of the interrupts to be cleared.
//!
//! This function clears the specified interrupt sources.  This function must
//! be called within the interrupt handler or else the handler is called again
//! upon exit.
//!
//! The \e ui32IntFlags parameter has the same definition as the
//! \e ui32IntFlags parameter to the HibernateIntEnable() function.
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
void
HibernateIntClear(uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ui32IntFlags & ~(HIBERNATE_INT_PIN_WAKE | HIBERNATE_INT_LOW_BAT |
                              HIBERNATE_INT_VDDFAIL |
                              HIBERNATE_INT_RESET_WAKE |
                              HIBERNATE_INT_GPIO_WAKE |
                              HIBERNATE_INT_RTC_MATCH_0 |
                              HIBERNATE_INT_WR_COMPLETE)));

    //
    // Write the specified interrupt bits into the interrupt clear register.
    //
    HWREG(HIB_IC) |= ui32IntFlags;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Checks to see if the Hibernation module is already powered up.
//!
//! This function queries the control register to determine if the module is
//! already active.  This function can be called at a power-on reset to help
//! determine if the reset is due to a wake from hibernation or a cold start.
//! If the Hibernation module is already active, then it does not need to be
//! re-enabled, and its status can be queried immediately.
//!
//! The software application should also use the HibernateIntStatus() function
//! to read the raw interrupt status to determine the cause of the wake.  The
//! HibernateDataGet() function can be used to restore state.  These
//! combinations of functions can be used by the software to determine if the
//! processor is waking from hibernation and the appropriate action to take as
//! a result.
//!
//! \return Returns \b true if the module is already active, and \b false if
//! not.
//
//*****************************************************************************
uint32_t
HibernateIsActive(void)
{
    //
    // Read the control register, and return true if the module is enabled.
    //
    return(HWREG(HIB_CTL) & HIB_CTL_CLK32EN ? 1 : 0);
}

//*****************************************************************************
//
//! Enables GPIO retention after wake from hibernation.
//!
//! This function enables the GPIO pin state to be maintained during
//! hibernation and remain active even when waking from hibernation.  The GPIO
//! module itself is reset upon entering hibernation and no longer controls the
//! output pins.  To maintain the current output level after waking from
//! hibernation, the GPIO module must be reconfigured and then the
//! HibernateGPIORetentionDisable() function must be called to return control
//! of the GPIO pin to the GPIO module.
//!
//! \note The hibernation GPIO retention setting is not available on all
//! Tiva devices.  Please consult the data sheet to determine if the
//! device you are using supports this feature in the Hibernation module.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateGPIORetentionEnable(void)
{
    //
    // Enable power to the pads and enable GPIO retention during hibernate.
    //
    HWREG(HIB_CTL) |= HIB_CTL_VDD3ON | HIB_CTL_RETCLR;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Disables GPIO retention after wake from hibernation.
//!
//! This function disables the retention of the GPIO pin state during
//! hibernation and allows the GPIO pins to be controlled by the system.  If
//! the HibernateGPIORetentionEnable() function is called before entering
//! hibernation, this function must be called after returning from hibernation
//! to allow the GPIO pins to be controlled by GPIO module.
//!
//! \note The hibernate GPIO retention setting is not available on all
//! Tiva devices.  Please consult the data sheet to determine if the
//! device you are using supports this feature in the Hibernation module.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateGPIORetentionDisable(void)
{
    //
    // Reset the GPIO configuration after waking from hibernate and disable
    // the hibernate power to the pads.
    //
    HWREG(HIB_CTL) &= ~(HIB_CTL_RETCLR | HIB_CTL_VDD3ON);

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Returns the current setting for GPIO retention.
//!
//! This function returns the current setting for GPIO retention in the
//! hibernate module.
//!
//! \note The hibernation GPIO retention setting is not available on all
//! Tiva devices.  Please consult the data sheet to determine if the
//! device you are using supports this feature in the Hibernation module.
//!
//! \return Returns true if GPIO retention is enabled and false if GPIO
//! retention is disabled.
//
//*****************************************************************************
bool
HibernateGPIORetentionGet(void)
{
    //
    // Read the current GPIO retention configuration.
    //
    if((HWREG(HIB_CTL) & (HIB_CTL_RETCLR | HIB_CTL_VDD3ON)) ==
       (HIB_CTL_RETCLR | HIB_CTL_VDD3ON))
    {
        return(true);
    }
    return(false);
}

//*****************************************************************************
//
//! Configures the Hibernation module's internal counter mode.
//!
//! \param ui32Config is the configuration to use for the hibernation module's
//! counter.
//!
//! This function configures the Hibernate module's counter mode to operate
//! as a standard RTC counter or to operate in a calendar mode.  The
//! \e ui32Config parameter is used to provide the configuration for
//! the counter and must include only one of the following values:
//!
//! - \b HIBERNATE_COUNTER_24HR specifies 24-hour calendar mode.
//! - \b HIBERNATE_COUNTER_12HR specifies 12-hour AM/PM calendar mode.
//! - \b HIBERNATE_COUNTER_RTC specifies RTC counter mode.
//!
//! The HibernateCalendar functions can only be called when either
//! \b HIBERNATE_COUNTER_24HR or \b HIBERNATE_COUNTER_12HR is specified.
//!
//! \b Example: Configure hibernate counter to 24-hour calendar mode.
//!
//! \verbatim
//!
//! //
//! // Configure the hibernate module counter to 24-hour calendar mode.
//! //
//! HibernateCounterMode(HIBERNATE_COUNTER_24HR);
//!
//! \endverbatim
//!
//! \note The hibernate calendar mode is not available on all Tiva
//! devices.  Please consult the data sheet to determine if the device you are
//! using supports this feature in the Hibernation module.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateCounterMode(uint32_t ui32Config)
{
    //
    // Set the requested configuration.
    //
    HWREG(HIB_CALCTL) = ui32Config;

    //
    // Wait for write completion
    //
    _HibernateWriteComplete();
}

//*****************************************************************************
//
// Internal function to parse the time structure to set the calendar fields.
//
//*****************************************************************************
static void
_HibernateCalendarSet(uint32_t ui32Reg, struct tm *psTime)
{
    uint32_t ui32Time, ui32Date;

    ASSERT(HWREG(HIB_CALCTL) & HIB_CALCTL_CALEN);

    //
    // Minutes and seconds are consistent in all modes.
    //
    ui32Time = (((psTime->tm_min << HIB_CALLD0_MIN_S) & HIB_CALLD0_MIN_M) |
                ((psTime->tm_sec << HIB_CALLD0_SEC_S) & HIB_CALLD0_SEC_M));

    //
    // 24 Hour time is used directly for Calendar set.
    //
    if(HWREG(HIB_CALCTL) & HIB_CALCTL_CAL24)
    {
        ui32Time |= (psTime->tm_hour << HIB_CALLD0_HR_S);

        //
        // for Calendar match, if it is every hour, AMPM bit should be clear
        //
        if((ui32Reg == HIB_CALM0) && (psTime->tm_hour == 0xFF) )
        {
            //
            // clear AMPM bit
            //
            ui32Time &= ~HIB_CAL0_AMPM;
        }
    }
    else
    {
        //
        // In AM/PM time hours have to be capped at 12.
        // If the hours are all 1s, it means the match for the hour is
        // always true.  We need to set 1F in the hw field.
        //
        if(psTime->tm_hour == 0xFF)
        {
            //
            // Match every hour.
            //
            ui32Time |= HIB_CALLD0_HR_M;
        }
        else if(psTime->tm_hour >= 12)
        {
            //
            // Need to set the PM bit if it is noon or later.
            //
            ui32Time |= (((psTime->tm_hour - 12) << HIB_CALLD0_HR_S) |
                         HIB_CAL0_AMPM);
        }
        else
        {
            //
            // All other times are normal and AM.
            //
            ui32Time |= (psTime->tm_hour << HIB_CALLD0_HR_S);
        }
    }

    //
    // Create the date in the correct register format.
    //
    if(ui32Reg == HIB_CAL0)
    {
        //
        // We must add 1 to the month, since the time structure lists
        // the month from 0 to 11 and the HIB lists it from 1 to 12.
        //
        ui32Date = ((psTime->tm_mday << HIB_CAL1_DOM_S) |
                    ((psTime->tm_mon + 1) << HIB_CAL1_MON_S) |
                    (psTime->tm_wday << HIB_CAL1_DOW_S) |
                    ((psTime->tm_year - 100) << HIB_CAL1_YEAR_S));
    }
    else
    {
        //
        // Wday, month and year are not included in the match
        // Functionality.
        //
        if(psTime->tm_mday == 0xFF)
        {
            //
            // program 0 to match every day
            //
            ui32Date = 0 << HIB_CAL1_DOM_M;
        }
        else
        {
            ui32Date = (psTime->tm_mday << HIB_CAL1_DOM_S);
        }
    }

    //
    // Load register requires unlock.
    //
    if(ui32Reg == HIB_CAL0)
    {
        //
        // Unlock the hibernate counter load registers.
        //
        HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
        _HibernateWriteComplete();
    }

    //
    // Set the requested time and date.
    //
    if(ui32Reg == HIB_CAL0)
    {
        HWREG(HIB_CALLD0) = ui32Time;
        _HibernateWriteComplete();
        HWREG(HIB_CALLD1) = ui32Date;
        _HibernateWriteComplete();
    }
    else
    {
        HWREG(HIB_CALM0) = ui32Time;
        _HibernateWriteComplete();
        HWREG(HIB_CALM1) = ui32Date;
        _HibernateWriteComplete();
    }

    //
    // Load register requires unlock.
    //
    if(ui32Reg == HIB_CAL0)
    {
        //
        // Lock the hibernate counter load registers.
        //
        HWREG(HIB_LOCK) = 0;
        _HibernateWriteComplete();
    }
}

//*****************************************************************************
//
//! Sets the Hibernation module's date and time in calendar mode.
//!
//! \param psTime is the structure that holds the information for the current
//! date and time.
//!
//! This function uses the \e psTime parameter to set the current date and
//! time when the Hibernation module is in calendar mode.  Regardless of
//! whether 24-hour or 12-hour mode is in use, the \e psTime structure uses a
//! 24-hour representation of the time.  This function can only be called when
//! the hibernate counter is configured in calendar mode using the
//! HibernateCounterMode() function with one of the calendar modes.
//!
//! \note The hibernate calendar mode is not available on all Tiva
//! devices.  Please consult the data sheet to determine if the device you are
//! using supports this feature in the Hibernation module.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateCalendarSet(struct tm *psTime)
{
    //
    // Load a new date/time.
    //
    _HibernateCalendarSet(HIB_CAL0, psTime);
}

//*****************************************************************************
//
//! Returns the Hibernation module's date and time in calendar mode.
//!
//! \param psTime is the structure that is filled with the current date and
//! time.
//!
//! This function returns the current date and time in the structure provided
//! by the \e psTime parameter.  Regardless of the calendar mode, the
//! \e psTime parameter uses a 24-hour representation of the time.  This
//! function can only be called when the Hibernation module is configured in
//! calendar mode using the HibernateCounterMode() function with one of the
//! calendar modes.
//!
//! The only case where this function fails and returns a non-zero value is
//! when the function detects that the counter is passing from the last second
//! of the day to the first second of the next day.  This exception must be
//! handled in the application by waiting at least one second before calling
//! again to get the updated calendar information.
//!
//! \note The hibernate calendar mode is not available on all Tiva
//! devices.  Please consult the data sheet to determine if the device you are
//! using supports this feature in the Hibernation module.
//!
//! \return Returns zero if the time and date were read successfully and
//! returns a non-zero value if the \e psTime structure was not updated.
//
//*****************************************************************************
int
HibernateCalendarGet(struct tm *psTime)
{
    uint32_t ui32Date, ui32Time;

    ASSERT(HWREG(HIB_CALCTL) & HIB_CALCTL_CALEN);

    //
    // Wait for the value to be valid, this should never be more than a few
    // loops and should never hang.
    //
    do
    {
        ui32Date = HWREG(HIB_CAL1);
    }
    while((ui32Date & HIB_CAL1_VALID) == 0);

    //
    // Wait for the value to be valid, this should never be more than a few
    // loops and should never hang.
    //
    do
    {
        ui32Time = HWREG(HIB_CAL0);
    }
    while((ui32Time & HIB_CAL0_VALID) == 0);

    //
    // The date changed after reading the time so fail this call and let the
    // application call again since it knows how int32_t to wait until another
    // second passes.
    //
    if(ui32Date != HWREG(HIB_CAL1))
    {
        return(-1);
    }

    //
    // Populate the date and time fields in the psTime structure.
    // We must subtract 1 from the month, since the time structure lists
    // the month from 0 to 11 and the HIB lists it from 1 to 12.
    //
    psTime->tm_min = (ui32Time & HIB_CAL0_MIN_M) >> HIB_CAL0_MIN_S;
    psTime->tm_sec = (ui32Time & HIB_CAL0_SEC_M) >> HIB_CAL0_SEC_S;
    psTime->tm_mon = (((ui32Date & HIB_CAL1_MON_M) >> HIB_CAL1_MON_S) - 1);
    psTime->tm_mday = (ui32Date & HIB_CAL1_DOM_M) >> HIB_CAL1_DOM_S;
    psTime->tm_wday = (ui32Date & HIB_CAL1_DOW_M) >> HIB_CAL1_DOW_S;
    psTime->tm_year = ((ui32Date & HIB_CAL1_YEAR_M) >> HIB_CAL1_YEAR_S) + 100;
    psTime->tm_hour = (ui32Time & HIB_CAL0_HR_M) >> HIB_CAL0_HR_S;

    //
    // Fix up the hour in the non-24-hour mode and the time is in PM.
    //
    if(((HWREG(HIB_CALCTL) & HIB_CALCTL_CAL24) == 0) &&
       (ui32Time & HIB_CAL0_AMPM))
    {
        psTime->tm_hour += 12;
    }

    return(0);
}

//*****************************************************************************
//
//! Sets the Hibernation module's date and time match value in calendar mode.
//!
//! \param ui32Index indicates which match register to access.
//! \param psTime is the structure that holds all of the information to set
//! the current date and time match values.
//!
//! This function uses the \e psTime parameter to set the current date and time
//! match value in the Hibernation module's calendar.  Regardless of the mode,
//! the \e psTime parameter uses a 24-hour clock representation of time.
//! This function can only be called when the Hibernation module is
//! configured in calendar mode using the HibernateCounterMode()
//! function.  The \e ui32Index value is reserved for future use and should
//! always be zero.
//! Calendar match can be enabled for every day, every hour, every minute or
//! every second, setting any of these fields to 0xFF causes a match for
//! that field.  For example, setting the day of month field to 0xFF
//! results in a calendar match daily at the same time.
//!
//! \note The hibernate calendar mode is not available on all Tiva
//! devices.  Please consult the data sheet to determine if the device you are
//! using supports this feature in the Hibernation module.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateCalendarMatchSet(uint32_t ui32Index, struct tm *psTime)
{
    //
    // Set the Match value.
    //
    _HibernateCalendarSet(HIB_CALM0, psTime);
}

//*****************************************************************************
//
//! Returns the Hibernation module's date and time match value in calendar
//! mode.
//!
//! \param ui32Index indicates which match register to access.
//! \param psTime is the structure to fill with the current date and time
//! match value.
//!
//! This function returns the current date and time match value in the
//! structure provided by the \e psTime parameter.  Regardless of the mode, the
//! \e psTime parameter uses a 24-hour clock representation of time.
//! This function can only be called when the Hibernation module is configured
//! in calendar mode using the HibernateCounterMode() function.
//! The \e ui32Index value is reserved for future use and should always be
//! zero.
//!
//! \note The hibernate calendar mode is not available on all Tiva
//! devices.  Please consult the data sheet to determine if the device you are
//! using supports this feature in the Hibernation module.
//!
//! \return Returns zero if the time and date match value were read
//! successfully and returns a non-zero value if the psTime structure was not
//! updated.
//
//*****************************************************************************
void
HibernateCalendarMatchGet(uint32_t ui32Index, struct tm *psTime)
{
    uint32_t ui32Date, ui32Time;

    ASSERT(HWREG(HIB_CALCTL) & HIB_CALCTL_CALEN);

    //
    // Get the date field.
    //
    ui32Date = HWREG(HIB_CALM1);

    //
    // Get the time field.
    //
    ui32Time = HWREG(HIB_CALM0);

    //
    // Populate the date and time fields in the psTime structure.
    //
    if((ui32Time & HIB_CAL0_MIN_M) == HIB_CAL0_MIN_M)
    {
        //
        // Match every minute
        //
        psTime->tm_min = 0xFF;
    }
    else
    {
        psTime->tm_min = (ui32Time & HIB_CAL0_MIN_M) >> HIB_CAL0_MIN_S;
    }

    if((ui32Time & HIB_CAL0_SEC_M) == HIB_CAL0_SEC_M)
    {
        //
        // Match every second
        //
        psTime->tm_sec = 0xFF;
    }
    else
    {
        psTime->tm_sec = (ui32Time & HIB_CAL0_SEC_M) >> HIB_CAL0_SEC_S;
    }

    if((ui32Time & HIB_CAL0_HR_M) == HIB_CAL0_HR_M)
    {
        //
        // Match every hour
        //
        psTime->tm_hour = 0xFF;
    }
    else
    {
        psTime->tm_hour = (ui32Time & HIB_CAL0_HR_M) >> HIB_CAL0_HR_S;
    }

    if((ui32Date & HIB_CAL1_DOM_M) == 0)
    {
        //
        // Match every day
        //
        psTime->tm_mday = 0xFF;
    }
    else
    {
        psTime->tm_mday = (ui32Date & HIB_CAL1_DOM_M) >> HIB_CAL1_DOM_S;
    }

    //
    // Fix up the hour in the non-24-hour mode and the time is in PM.
    //
    if(((HWREG(HIB_CALCTL) & HIB_CALCTL_CAL24) == 0) &&
       (ui32Time & HIB_CAL0_AMPM))
    {
        psTime->tm_hour += 12;
    }
}

//*****************************************************************************
//
//! Configures the tamper feature event response.
//!
//! \param ui32Config specifies the configuration options for tamper events.
//!
//! This function is used to configure the event response options for the
//! tamper feature.  The \e ui32Config parameter provides a combination of the
//! \b HIBERNATE_TAMPER_EVENTS_* features to set these options.  The
//! application should choose from the following set of defines to determine
//! what happens to the system when a tamper event occurs:
//!
//! - \b HIBERNATE_TAMPER_EVENTS_ERASE_ALL_HIB_MEM all of the Hibernation
//! module's battery-backed RAM is cleared due to a tamper event
//! - \b HIBERNATE_TAMPER_EVENTS_ERASE_HIGH_HIB_MEM the upper half of the
//! Hibernation module's battery-backed RAM is cleared due to a tamper event
//! - \b HIBERNATE_TAMPER_EVENTS_ERASE_LOW_HIB_MEM the lower half of the
//! Hibernation module's battery-backed RAM is cleared due to a tamper event
//! - \b HIBERNATE_TAMPER_EVENTS_ERASE_NO_HIB_MEM the Hibernation module's
//! battery-backed RAM is not changed due to a tamper event
//! - \b HIBERNATE_TAMPER_EVENTS_HIB_WAKE a tamper event wakes the MCU from
//! hibernation
//! - \b HIBERNATE_TAMPER_EVENTS_NO_HIB_WAKE a tamper event does not wake the
//! MCU from hibernation
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperEventsConfig(uint32_t ui32Config)
{
    uint32_t ui32Temp;

    //
    // Mask out the on-event configuration options.
    //
    ui32Temp = (HWREG(HIB_TPCTL) & ~HIB_TPCTL_MEMCLR_M);

    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Set the on-event configuration.
    //
    HWREG(HIB_TPCTL) = (ui32Temp | ui32Config);

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Enables the tamper feature.
//!
//! This function is used to enable the tamper feature functionality.  This
//! function should only be called after the global configuration is set with
//! a call to HibernateTamperEventsConfig() and the tamper inputs have been
//! configured with a call to HibernateTamperIOEnable().
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperEnable(void)
{
    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Set the tamper enable bit.
    //
    HWREG(HIB_TPCTL) |= HIB_TPCTL_TPEN;

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Disables the tamper feature.
//!
//! This function is used to disable the tamper feature functionality.  All
//! other configuration settings are left unmodified, allowing a call to
//! HibernateTamperEnable() to quickly enable the tamper feature with its
//! previous configuration.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperDisable(void)
{
    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Clear the tamper enable bit.
    //
    HWREG(HIB_TPCTL) &= ~HIB_TPCTL_TPEN;

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Configures an input to the tamper feature.
//!
//! \param ui32Input is the tamper input to configure.
//! \param ui32Config holds the configuration options for a given input to the
//! tamper feature.
//!
//! This function is used to configure an input to the tamper feature.  The
//! \e ui32Input parameter specifies the tamper signal to configure and has a
//! valid range of 0-3.  The \e ui32Config parameter provides the set of tamper
//! features in the \b HIBERNATE_TAMPER_IO_* values.  The values that are valid
//! in the \e ui32Config parameter are:
//!
//! - \b HIBERNATE_TAMPER_IO_MATCH_SHORT configures the trigger to match after
//! 2 hibernation clocks
//! - \b HIBERNATE_TAMPER_IO_MATCH_LONG configures the trigger to match after
//! 3071 hibernation clocks
//! - \b HIBERNATE_TAMPER_IO_WPU_ENABLED turns on an internal weak pull up
//! - \b HIBERNATE_TAMPER_IO_WPU_DISABLED turns off an internal weak pull up
//! - \b HIBERNATE_TAMPER_IO_TRIGGER_HIGH sets the tamper event to active high
//! - \b HIBERNATE_TAMPER_IO_TRIGGER_LOW sets the tamper event to active low
//!
//! \note None of the GPIO API functions are needed to configure the tamper
//! pins.  The tamper pins configured by using this function overrides any
//! configuration by GPIO APIs.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperIOEnable(uint32_t ui32Input, uint32_t ui32Config)
{
    uint32_t ui32Temp, ui32Mask;

    //
    // Verify parameters.
    //
    ASSERT(ui32Input < 4);

    //
    // Read the current tamper I/O configuration.
    //
    ui32Temp = HWREG(HIB_TPIO);

    //
    // Mask out configuration options for the requested input.
    //
    ui32Mask = (ui32Temp & (~((HIB_TPIO_GFLTR0 | HIB_TPIO_PUEN0 |
                               HIB_TPIO_LEV0 | HIB_TPIO_EN0) <<
                              (ui32Input << 3))));

    //
    // Set tamper I/O configuration for the requested input.
    //
    ui32Temp |= (ui32Mask | ((ui32Config | HIB_TPIO_EN0) << (ui32Input << 3)));

    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Write to the register.
    //
    HWREG(HIB_TPIO) = ui32Temp;

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Disables an input to the tamper feature.
//!
//! \param ui32Input is the tamper input to disable.
//!
//! This function is used to disable an input to the tamper feature.  The
//! \e ui32Input parameter specifies the tamper signal to disable and has a
//! valid range of 0-3.
//!
//! \note None of the GPIO API functions are needed to configure the tamper
//! pins.  The tamper pins configured by using this function overrides any
//! configuration by GPIO APIs.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperIODisable(uint32_t ui32Input)
{
    //
    // Verify parameters.
    //
    ASSERT(ui32Input < 4);

    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Clear the I/O enable bit.
    //
    HWREG(HIB_TPIO) &= ((~HIB_TPIO_EN0) << (ui32Input << 3));

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Clears the tamper feature events.
//!
//! This function is used to clear all tamper events.  This function always
//! clears the tamper feature event state indicator along with all tamper log
//! entries.  Logged event data should be retrieved with
//! HibernateTamperEventsGet() prior to requesting a event clear.
//!
//! HibernateTamperEventsClear() should be called prior to clearing the system
//! control NMI that resulted from the tamper event.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperEventsClear(void)
{
    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Set the tamper event clear bit.
    //
    HWREG(HIB_TPCTL) |= HIB_TPCTL_TPCLR;

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Clears the tamper feature events without Unlock and Lock.
//!
//! This function is used to clear all tamper events without unlock/locking
//! the tamper control registers, so API HibernateTamperUnLock() should be
//! called before this function, and API HibernateTamperLock() should be
//! called after to ensure that tamper control registers are locked.
//!
//! This function doesn't block until the write is complete.
//! Therefore, care must be taken to ensure the next immediate write will
//! occure only after the write complete bit is set.
//!
//! This function is used to implement a software workaround in NMI interrupt
//! handler to fix an issue when a new tamper event could be missed during
//! the clear of current tamper event.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperEventsClearNoLock(void)
{
    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    //
    // Set the tamper event clear bit.
    //
    HWREG(HIB_TPCTL) |= HIB_TPCTL_TPCLR;

}

//*****************************************************************************
//
//! Unlock temper registers.
//!
//! This function is used to unlock the temper control registers.  This
//! function should be only used before calling API
//! HibernateTamperEventsClearNoLock().
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperUnLock(void)
{
    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Lock temper registers.
//!
//! This function is used to lock the temper control registers.  This
//! function should be used after calling API
//! HibernateTamperEventsClearNoLock().
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperLock(void)
{
    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Returns the current tamper feature status.
//!
//! This function is used to return the tamper feature status.  This function
//! returns one of the values from this group of options:
//!
//! - \b HIBERNATE_TAMPER_STATUS_INACTIVE indicates tamper detection is
//! disabled
//! - \b HIBERNATE_TAMPER_STATUS_ACTIVE indicates tamper detection is enabled
//! and ready
//! - \b HIBERNATE_TAMPER_STATUS_EVENT indicates tamper event was detected
//!
//! In addition, one of the values is included from this group:
//!
//! - \b HIBERNATE_TAMPER_STATUS_EXT_OSC_INACTIVE indicates the external
//! oscillator is not active
//! - \b HIBERNATE_TAMPER_STATUS_EXT_OSC_ACTIVE indicates the external
//! oscillator is active
//!
//! And one of the values is included from this group:
//!
//! - \b HIBERNATE_TAMPER_STATUS_EXT_OSC_FAILED indicates the external
//! oscillator signal has transitioned from valid to invalid
//! - \b HIBERNATE_TAMPER_STATUS_EXT_OSC_VALID indicates the external
//! oscillator is providing a valid signal
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return Returns a combination of the \b HIBERNATE_TAMPER_STATUS_* values.
//
//*****************************************************************************
uint32_t
HibernateTamperStatusGet(void)
{
    uint32_t ui32Status, ui32Reg;

    //
    // Retrieve the raw register value.
    //
    ui32Reg = HWREG(HIB_TPSTAT);

    //
    // Setup the oscillator status indicators.
    //
    ui32Status = (ui32Reg & (HIB_TPSTAT_XOSCST | HIB_TPSTAT_XOSCFAIL));
    ui32Status |= ((ui32Reg & HIB_TPSTAT_XOSCST) ? 0 :
                   HIBERNATE_TAMPER_STATUS_EXT_OSC_ACTIVE);
    ui32Status |= ((ui32Reg & HIB_TPSTAT_XOSCFAIL) ? 0 :
                   HIBERNATE_TAMPER_STATUS_EXT_OSC_VALID);

    //
    // Retrieve the tamper status indicators.
    //
    ui32Status |= ((ui32Reg & HIB_TPSTAT_STATE_M) << 3);

    //
    // The HW shows "disabled" with a zero value, use bit[0] as a flag
    // for this purpose.
    //
    if((ui32Reg & HIB_TPSTAT_STATE_M) == 0)
    {
        ui32Status |= HIBERNATE_TAMPER_STATUS_INACTIVE;
    }

    //
    // Return the API status flags.
    //
    return(ui32Status);
}

//*****************************************************************************
//
//! Returns a tamper log entry.
//!
//! \param ui32Index is the index of the log entry to return.
//! \param pui32RTC is a pointer to the memory to store the logged RTC data.
//! \param pui32Event is a pointer to the memory to store the logged tamper
//! event.
//!
//! This function is used to return a tamper log entry from the hibernate
//! feature.  The \e ui32Index specifies the zero-based index of the log entry
//! to query and has a valid range of 0-3.
//!
//! When this function returns, the \e pui32RTC value contains the time value
//! and \e pui32Event  parameter contains the tamper I/O event that triggered
//! this log.
//!
//! The format of the returned \e pui32RTC data is dependent on the
//! configuration of the RTC within the Hibernation module.  If the RTC is
//! configured for counter mode, the returned data contains counted seconds
//! from the RTC enable.  If the RTC is configured for calendar mode, the data
//! returned is formatted as follows:
//!
//! \verbatim
//! +----------------------------------------------------------------------+
//! |  31:26  |  25:22  |     21:17      |  16:12  |   11:6    |    5:0    |
//! +----------------------------------------------------------------------+
//! |  year   |  month  |  day of month  |  hours  |  minutes  |  seconds  |
//! +----------------------------------------------------------------------+
//! \endverbatim
//!
//! The data returned in the \e pui32Events parameter could include any of the
//! following flags:
//!
//! - \b HIBERNATE_TAMPER_EVENT_0 indicates a tamper event was triggered on I/O
//! signal 0
//! - \b HIBERNATE_TAMPER_EVENT_1 indicates a tamper event was triggered on I/O
//! signal 1
//! - \b HIBERNATE_TAMPER_EVENT_2 indicates a tamper event was triggered on I/O
//! signal 2
//! - \b HIBERNATE_TAMPER_EVENT_3 indicates a tamper event was triggered on I/O
//! signal 3
//! - \b HIBERNATE_TAMPER_EVENT_XOSC indicates an external oscillator failure
//! triggered the tamper event
//!
//! \note Tamper event logs are not consumed when read and remain available
//! until cleared.  Events are only logged if unused log space is available.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return Returns \b true if the \e pui32RTC and \e pui32Events were updated
//! successfully and returns \b false if the values were not updated.
//
//*****************************************************************************
bool
HibernateTamperEventsGet(uint32_t ui32Index, uint32_t *pui32RTC,
                         uint32_t *pui32Event)
{
    uint32_t ui32Reg;

    //
    // Verify parameters.
    //
    ASSERT(pui32RTC);
    ASSERT(pui32Event);
    ASSERT(ui32Index < 4);

    //
    // Retrieve the event log data for the requested index if available.
    //
    ui32Reg = HWREG(HIB_TPLOG0 + ((ui32Index << 3) + 4));
    if(ui32Reg == 0)
    {
        //
        // No event data is available for this index.
        //
        return(false);
    }

    //
    // Store the event data in the provided location.
    //
    *pui32Event = ui32Reg;

    //
    // Retrieve the calendar information.
    //
    *pui32RTC = HWREG(HIB_TPLOG0 + (ui32Index << 3));

    //
    // Convert the hour to 24hr mode if the Calendar is enabled
    // and in 24hr mode.
    //
    if((HWREG(HIB_CALCTL) & (HIB_CALCTL_CALEN | HIB_CALCTL_CAL24)) ==
       (HIB_CALCTL_CALEN | HIB_CALCTL_CAL24))
    {
        if(HWREG(HIB_CAL0) & HIB_CAL0_AMPM)
        {
            //
            // Add 12 hour since it is PM
            //
            ui32Reg = ((*pui32RTC & 0X0001f000) + (12<<12)) & 0X0001f000;
            *pui32RTC &= ~0X0001f000;
            *pui32RTC |= ui32Reg;
        }
    }

    //
    // Return success.
    //
    return(true);
}

//*****************************************************************************
//
//! Attempts to recover the external oscillator.
//!
//! This function is used to attempt to recover the external oscillator after a
//! \b HIBERNATE_TAMPER_STATUS_EXT_OSC_FAILED status is reported.  This
//! function must not be called if the external oscillator is not used as
//! the hibernation clock input.  HibernateTamperExtOscValid() should be called
//! before calling this function.
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
HibernateTamperExtOscRecover(void)
{
    //
    // Unlock the tamper registers.
    //
    HWREG(HIB_LOCK) = HIB_LOCK_HIBLOCK_KEY;
    _HibernateWriteComplete();

    //
    // Set the XOSCFAIL clear bit.
    //
    HWREG(HIB_TPSTAT) |= HIB_TPSTAT_XOSCFAIL;

    //
    // Wait for write completion.
    //
    _HibernateWriteComplete();

    //
    // Lock the tamper registers.
    //
    HWREG(HIB_LOCK) = 0;
    _HibernateWriteComplete();
}

//*****************************************************************************
//
//! Reports if the external oscillator signal is active and stable.
//!
//! This function should be used to verify the external oscillator is active
//! and valid before attempting to recover from a
//! \b HIBERNATE_TAMPER_STATUS_EXT_OSC_FAILED status by calling
//! HibernateTamperExtOscRecover().
//!
//! \note The hibernate tamper feature is not available on all Tiva
//! devices.  Please consult the data sheet for the Tiva device that you
//! are using to determine if this feature is available.
//!
//! \return Returns \b true if the external oscillator is both active and
//! stable, otherwise a \b false indicator is returned.
//
//*****************************************************************************
bool
HibernateTamperExtOscValid(void)
{
    if(HibernateTamperStatusGet() & (HIBERNATE_TAMPER_STATUS_EXT_OSC_ACTIVE |
                                     HIBERNATE_TAMPER_STATUS_EXT_OSC_VALID))
    {
        return(true);
    }

    return(false);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
