//*****************************************************************************
//
// fan.c - Driver for the FAN controller.
//
// Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_fan.h"
#include "inc/hw_ints.h"
#include "driverlib/fan.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
//! \addtogroup fan_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Enables a FAN channel for operation.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to enable.
//!
//! This function enables the specified FAN channel for operation.
//!
//! \return None.
//
//*****************************************************************************
void
FanChannelEnable(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);

    //
    // Enable the requested channel
    //
    HWREG(ulBase + FAN_O_CTL) |= 1 << ulChannel;
}

//*****************************************************************************
//
//! Disables a FAN channel.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to disable.
//!
//! This function disables the specified FAN channel for operation.
//!
//! \return None.
//
//*****************************************************************************
void
FanChannelDisable(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);

    //
    // Disable the requested channel
    //
    HWREG(ulBase + FAN_O_CTL) &= ~(1 << ulChannel);
}

//*****************************************************************************
//
//! Gets the status of a FAN channel.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to query for status.
//!
//! This function queries and returns the status of the specified channel.
//! The returned value is one of:
//!
//! - \b FAN_STATUS_STALLED if the cooling fan is stalled
//! - \b FAN_STATUS_CHANGING if the fan is changing to the commanded speed
//! - \b FAN_STATUS_LOCKED if the fan is locked at the commanded speed
//! - \b FAN_STATUS_NOATTAIN if the fan cannot achieve the commanded speed
//!
//! \return Returns the status of the specified FAN channel.
//
//*****************************************************************************
unsigned long
FanChannelStatus(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);

    //
    // Read and return the status for the specified fan channel
    //
    return((HWREG(ulBase + FAN_O_STS) >> (ulChannel * 2)) & FAN_STS_ST0_M);
}

//*****************************************************************************
//
//! Configures a FAN channel for manual operation.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to configure.
//! \param ulConfig is the logical OR of manual configuration flags.
//!
//! This function configures a specific FAN channel to operate in manual
//! mode.  The \e ulConfig parameter is the logical OR of several choices of
//! configuration flags as follows:
//!
//! One of the following to select the number of tachometer pulses used for
//! speed averaging:
//!
//! - \b FAN_CONFIG_AVG_NONE to disable fan speed averaging
//! - \b FAN_CONFIG_AVG_2 to select 2 pulses for speed averaging
//! - \b FAN_CONFIG_AVG_4 to select 4 pulses for speed averaging
//! - \b FAN_CONFIG_AVG_8 to select 8 pulses for speed averaging
//!
//! One of the following to select the tachometer pulses per revolution:
//!
//! - \b FAN_CONFIG_TACH_1 to select 1 pulse per revolution
//! - \b FAN_CONFIG_TACH_2 to select 2 pulses per revolution
//! - \b FAN_CONFIG_TACH_4 to select 4 pulses per revolution
//! - \b FAN_CONFIG_TACH_8 to select 8 pulses per revolution
//!
//! \return None.
//
//*****************************************************************************
void
FanChannelConfigManual(unsigned long ulBase, unsigned long ulChannel,
                       unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);

    //
    // Program the fan channel for manual mode with parameters.
    //
    HWREG(ulBase + FAN_O_CH0 + (ulChannel * 0x10)) =  FAN_CH0_MAN | ulConfig;
}

//*****************************************************************************
//
//! Configures a FAN channel for automatic operation.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to configure.
//! \param ulConfig is the logical OR of configuration flags.
//!
//! This function configures a specific FAN channel to operate in automatic
//! mode.  The \e ulConfig parameter is the logical OR of several choices of
//! configuration flags as follows:
//!
//! One of the following to select the automatic restart mode:
//!
//! - \b FAN_CONFIG_RESTART to enable automatic restart after stall
//! - \b FAN_CONFIG_NORESTART to disable automatic restart after stall
//!
//! One of the following to select the acceleration rate when changing speed:
//!
//! - \b FAN_CONFIG_ACCEL_FAST to select fast acceleration
//! - \b FAN_CONFIG_ACCEL_SLOW to select slow acceleration
//!
//! One of the following to select the number of tachometer pulses to use
//! for the hysteresis count:
//! \b FAN_CONFIG_HYST_1, \b FAN_CONFIG_HYST_2, \b FAN_CONFIG_HYST_4,
//! \b FAN_CONFIG_HYST_8, \b FAN_CONFIG_HYST_16, \b FAN_CONFIG_HYST_32,
//! \b FAN_CONFIG_HYST_64, or \b FAN_CONFIG_HYST_128
//!
//! One of the following to select the start period as the number of tachometer
//! pulses.  The start period is the amount of time that a starting PWM duty
//! cycle is used after the FAN channel is commended to a certain speed:
//! \b FAN_CONFIG_START_2, \b FAN_CONFIG_START_4, \b FAN_CONFIG_START_8,
//! \b FAN_CONFIG_START_16, \b FAN_CONFIG_START_32, \b FAN_CONFIG_START_64,
//! \b FAN_CONFIG_START_128, or \b FAN_CONFIG_START_256
//!
//! One of the following to specify the duty cycle that is used when the FAN
//! channel is starting, during the starting period (above):
//!
//! - \b FAN_CONFIG_START_DUTY_OFF to disable the use of startup duty cycle
//! - \b FAN_CONFIG_START_DUTY_50 to select 50% startup duty cycle
//! - \b FAN_CONFIG_START_DUTY_75 to select 75% startup duty cycle
//! - \b FAN_CONFIG_START_DUTY_100 to select 100% startup duty cycle
//!
//! One of the following to select the number of tachometer pulses used for
//! speed averaging:
//!
//! - \b FAN_CONFIG_AVG_NONE to disable fan speed averaging
//! - \b FAN_CONFIG_AVG_2 to select 2 pulses for speed averaging
//! - \b FAN_CONFIG_AVG_4 to select 4 pulses for speed averaging
//! - \b FAN_CONFIG_AVG_8 to select 8 pulses for speed averaging
//!
//! One of the following to select the tachometer pulses per revolution:
//!
//! - \b FAN_CONFIG_TACH_1 to select 1 pulse per revolution
//! - \b FAN_CONFIG_TACH_2 to select 2 pulses per revolution
//! - \b FAN_CONFIG_TACH_4 to select 4 pulses per revolution
//! - \b FAN_CONFIG_TACH_8 to select 8 pulses per revolution
//!
//! \return None.
//
//*****************************************************************************
void
FanChannelConfigAuto(unsigned long ulBase, unsigned long ulChannel,
                     unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);

    //
    // Program the fan channel for automatic mode with parameters.
    //
    HWREG(ulBase + FAN_O_CH0 + (ulChannel * 0x10)) = ~FAN_CH0_MAN & ulConfig;
}

//*****************************************************************************
//
//! Sets the duty cycle of a FAN channel when in manual mode.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to program the duty cycle.
//! \param ulDuty is the duty cycle in clocks from 0-511.
//!
//! This function sets the duty cycle of a FAN channel if the channel is
//! configured for manual mode.  The duty cycle is specified in clocks from
//! 0-511 out of a 512-clock PWM period.
//!
//! \return None.
//
//*****************************************************************************
void
FanChannelDutySet(unsigned long ulBase, unsigned long ulChannel,
                  unsigned long ulDuty)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);
    ASSERT(ulDuty < 512);

    //
    // Program the specified duty cycle for the specified channel
    //
    HWREG(ulBase + FAN_O_CMD0 + (ulChannel * 0x10)) =
            (ulDuty << FAN_CMD0_DC_S) & FAN_CMD0_DC_M;
}

//*****************************************************************************
//
//! Reads the duty cycle of a FAN channel.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to query for duty cycle.
//!
//! This function reads the duty cycle of a FAN channel.  If the channel is in
//! manual mode, then this is the value that was programmed.  If the FAN
//! channel is configured for automatic mode, then this is the value that is
//! calculated by the Fan Control peripheral.
//!
//! \return Returns the FAN channel duty cycle as a number of clocks from
//! 0-511, out of a 512-clock PWM period.
//
//*****************************************************************************
unsigned long
FanChannelDutyGet(unsigned long ulBase, unsigned long ulChannel)
{
    unsigned long ulDuty;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);

    //
    // Read the duty cycle field from the command register and shift to
    // lower bits for return value.
    //
    ulDuty = HWREG(ulBase + FAN_O_CMD0 + (ulChannel * 0x10)) & FAN_CMD0_DC_M;
    ulDuty >>= FAN_CMD0_DC_S;

    //
    // Return the duty cycle for the specified channel.
    //
    return(ulDuty);
}

//*****************************************************************************
//
//! Sets the RPM of a FAN channel when in automatic mode.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to program the RPM.
//! \param ulRPM is the RPM as a value from 0-8191.
//!
//! This function sets the RPM of the fan channel if the fan channel is
//! configured for automatic mode.  If configured for manual mode, then this
//! function has no effect.
//!
//! \return None.
//
//*****************************************************************************
void
FanChannelRPMSet(unsigned long ulBase, unsigned long ulChannel,
                 unsigned long ulRPM)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);
    ASSERT(ulRPM < 8192);

    //
    // Program the specified RPM for the specified channel
    //
    HWREG(ulBase + FAN_O_CMD0 + (ulChannel * 0x10)) = ulRPM;
}

//*****************************************************************************
//
//! Reads the RPM of a FAN channel.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulChannel is the FAN channel to query for RPM.
//!
//! This function reads the RPM of a FAN channel.
//!
//! \return Returns the FAN channel RPM as a number from 0-4095.
//
//*****************************************************************************
unsigned long
FanChannelRPMGet(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(ulChannel < 6);


    //
    // Read and return the RPM for the specified channel.
    //
    return(HWREG(ulBase + FAN_O_CST0 + (ulChannel * 0x10)) & FAN_CST0_RPM_M);
}

//*****************************************************************************
//
//! Enables FAN module interrupts.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulFlags is the logical OR of all the interrupts to be enabled.
//!
//! This function enables one or more interrupts from the FAN module.  The
//! \e ulFlags parameter is the logical OR of all the possible interrupts that
//! can be enabled.  For each channel, the following interrupt flags are
//! available:
//!
//! - \b FAN_CHn_INT_STALL means that a stall was detected (in either mode).
//! - \b FAN_CHn_INT_AUTO_SPEED_ERROR means that in automatic mode, the cooling
//! fan cannot attain the commanded speed.
//! - \b FAN_CHn_INT_AUTO_SPEED_OK means that in automatic mode, the cooling
//! fan has attained the commanded speed.
//!
//! The interrupt flags have a different meaning if the FAN channel is
//! configured for manual mode.  The following alternate set of flag names is
//! available for convenience to use in manual mode:
//!
//! - \b FAN_CHn_INT_MANUAL_SPEED_UPDATE means that in manual mode, the speed
//! was calculated.
//! - \b FAN_CHn_INT_MANUAL_SPEED_CHANGE means that in manual mode, the speed
//! changed.
//!
//! In the above flag names, the \b CHn placeholder should be replaced with
//! the actual channel number, 0-5 (for example, CH1).
//!
//! Note that even though the names are different for manual mode, the values
//! are the same.  For example \b _AUTO_SPEED_ERROR is the same value as
//! \b _MANUAL_SPEED_UPDATE.  The different names are provided just to make it
//! easier to associate a meaning with each interrupt flag.
//!
//! \return None.
//
//*****************************************************************************
void
FanIntEnable(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);

    //
    // Enable the requested interrupt sources.
    //
    HWREG(ulBase + FAN_O_IM) |= ulFlags;
}

//*****************************************************************************
//
//! Disables FAN module interrupts.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulFlags is the logical OR of all the interrupts to be disabled.
//!
//! This function disables one or more interrupts from the FAN module.  The
//! \e ulFlags parameter is the logical OR of all the possible interrupts that
//! can be enabled.  For a list of possible interrupt flags, refer to the
//! documentation for the function FanIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
FanIntDisable(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);

    //
    // Disable the requested interrupt sources.
    //
    HWREG(ulBase + FAN_O_IM) &= ~ulFlags;
}

//*****************************************************************************
//
//! Gets the FAN module interrupt status.
//!
//! \param ulBase is the base address of the FAN module.
//! \param bMasked is \b true to get the masked interrupt status, or
//! \b false to get the raw interrupt status.
//!
//! This function returns the interrupt status of the FAN module.  It can
//! return either the raw or masked interrupt status.
//!
//! \return Returns the masked or raw FAN interrupt status, as a bit field
//! of multiple FAN interrupt flags.  For a list of all the possible interrupt
//! flags, refer to the documentation for the function FanIntEnable().
//
//*****************************************************************************
unsigned long
FanIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + FAN_O_MIS));
    }
    else
    {
        return(HWREG(ulBase + FAN_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears pending FAN module interrupts.
//!
//! \param ulBase is the base address of the FAN module.
//! \param ulFlags is the logical OR of all the interrupts to be cleared.
//!
//! This function clears one or more interrupts from the FAN module.  The
//! \e ulFlags parameter is the logical OR of all the possible interrupts that
//! can be cleared.  For a list of possible interrupt flags, refer to the
//! documentation for the function FanIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
FanIntClear(unsigned long ulBase, unsigned long ulFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);

    //
    // Clear the requested pending interrupts
    //
    HWREG(ulBase + FAN_O_IC) = ulFlags;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the FAN module.
//!
//! \param ulBase is the base address of the FAN module.
//! \param pfnHandler is a pointer to the function to be called when the
//! interrupt is activated.
//!
//! This function registers and enables the handler to be called when the FAN
//! module generates an interrupt.  Specific FAN interrupts must still be
//! enabled with the FanIntEnable() function.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
FanIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);
    ASSERT(pfnHandler);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_FAN0, pfnHandler);

    //
    // Enable the FAN peripheral interrupt.
    //
    IntEnable(INT_FAN0);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the FAN module.
//!
//! \param ulBase is the base address of the FAN module.
//!
//! This function unregisters and clears the handler to be called when the
//! FAN module interrupt occurs.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
FanIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);

    //
    // Disable the FAN peripheral interrupt.
    //
    IntDisable(INT_FAN0);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_FAN0);
}

//*****************************************************************************
//
//! Gets the number of supported FAN channels.
//!
//! \param ulBase is the base address of the FAN module.
//!
//! This function gets the number of FAN channels that are supported by the
//! Fan Control peripheral.
//!
//! \return Returns the number of FAN channels.
//
//*****************************************************************************
unsigned long
FanChannelsGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == FAN0_BASE);

    //
    // Read and return the fan channel count
    //
    return(HWREG(ulBase + FAN_O_PP) & FAN_PP_CHAN_M);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
