//*****************************************************************************
//
// qei.c - Driver for the Quadrature Encoder with Index.
//
// Copyright (c) 2005-2013 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup qei_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_qei.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"

//*****************************************************************************
//
//! Enables the quadrature encoder.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function enables operation of the quadrature encoder module.  The
//! module must be configured before it is enabled.
//!
//! \sa QEIConfigure()
//!
//! \return None.
//
//*****************************************************************************
void
QEIEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Enable the QEI module.
    //
    HWREG(ui32Base + QEI_O_CTL) |= QEI_CTL_ENABLE;
}

//*****************************************************************************
//
//! Disables the quadrature encoder.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function disables operation of the quadrature encoder module.
//!
//! \return None.
//
//*****************************************************************************
void
QEIDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Disable the QEI module.
    //
    HWREG(ui32Base + QEI_O_CTL) &= ~(QEI_CTL_ENABLE);
}

//*****************************************************************************
//
//! Configures the quadrature encoder.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param ui32Config is the configuration for the quadrature encoder.  See
//! below for a description of this parameter.
//! \param ui32MaxPosition specifies the maximum position value.
//!
//! This function configures the operation of the quadrature encoder.  The
//! \e ui32Config parameter provides the configuration of the encoder and is
//! the logical OR of several values:
//!
//! - \b QEI_CONFIG_CAPTURE_A or \b QEI_CONFIG_CAPTURE_A_B specify if edges
//!   on channel A or on both channels A and B should be counted by the
//!   position integrator and velocity accumulator.
//! - \b QEI_CONFIG_NO_RESET or \b QEI_CONFIG_RESET_IDX specify if the
//!   position integrator should be reset when the index pulse is detected.
//! - \b QEI_CONFIG_QUADRATURE or \b QEI_CONFIG_CLOCK_DIR specify if
//!   quadrature signals are being provided on ChA and ChB, or if a direction
//!   signal and a clock are being provided instead.
//! - \b QEI_CONFIG_NO_SWAP or \b QEI_CONFIG_SWAP to specify if the signals
//!   provided on ChA and ChB should be swapped before being processed.
//!
//! \e ui32MaxPosition is the maximum value of the position integrator and is
//! the value used to reset the position capture when in index reset mode and
//! moving in the reverse (negative) direction.
//!
//! \return None.
//
//*****************************************************************************
void
QEIConfigure(uint32_t ui32Base, uint32_t ui32Config,
             uint32_t ui32MaxPosition)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Write the new configuration to the hardware.
    //
    HWREG(ui32Base + QEI_O_CTL) = ((HWREG(ui32Base + QEI_O_CTL) &
                                    ~(QEI_CTL_CAPMODE | QEI_CTL_RESMODE |
                                      QEI_CTL_SIGMODE | QEI_CTL_SWAP)) |
                                   ui32Config);

    //
    // Set the maximum position.
    //
    HWREG(ui32Base + QEI_O_MAXPOS) = ui32MaxPosition;
}

//*****************************************************************************
//
//! Gets the current encoder position.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function returns the current position of the encoder.  Depending upon
//! the configuration of the encoder, and the incident of an index pulse, this
//! value may or may not contain the expected data (that is, if in reset on
//! index mode, if an index pulse has not been encountered, the position
//! counter is not yet aligned with the index pulse).
//!
//! \return The current position of the encoder.
//
//*****************************************************************************
uint32_t
QEIPositionGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Return the current position counter.
    //
    return(HWREG(ui32Base + QEI_O_POS));
}

//*****************************************************************************
//
//! Sets the current encoder position.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param ui32Position is the new position for the encoder.
//!
//! This function sets the current position of the encoder; the encoder
//! position is then measured relative to this value.
//!
//! \return None.
//
//*****************************************************************************
void
QEIPositionSet(uint32_t ui32Base, uint32_t ui32Position)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Set the position counter.
    //
    HWREG(ui32Base + QEI_O_POS) = ui32Position;
}

//*****************************************************************************
//
//! Gets the current direction of rotation.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function returns the current direction of rotation.  In this case,
//! current means the most recently detected direction of the encoder; it may
//! not be presently moving but this is the direction it last moved before it
//! stopped.
//!
//! \return Returns 1 if moving in the forward direction or -1 if moving in the
//! reverse direction.
//
//*****************************************************************************
int32_t
QEIDirectionGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Return the direction of rotation.
    //
    return((HWREG(ui32Base + QEI_O_STAT) & QEI_STAT_DIRECTION) ? -1 : 1);
}

//*****************************************************************************
//
//! Gets the encoder error indicator.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function returns the error indicator for the quadrature encoder.  It
//! is an error for both of the signals of the quadrature input to change at
//! the same time.
//!
//! \return Returns \b true if an error has occurred and \b false otherwise.
//
//*****************************************************************************
bool
QEIErrorGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Return the error indicator.
    //
    return((HWREG(ui32Base + QEI_O_STAT) & QEI_STAT_ERROR) ? true : false);
}

//*****************************************************************************
//
//! Enables the velocity capture.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function enables operation of the velocity capture in the quadrature
//! encoder module.  The module must be configured before velocity capture is
//! enabled.
//!
//! \sa QEIVelocityConfigure() and QEIEnable()
//!
//! \return None.
//
//*****************************************************************************
void
QEIVelocityEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Enable the velocity capture.
    //
    HWREG(ui32Base + QEI_O_CTL) |= QEI_CTL_VELEN;
}

//*****************************************************************************
//
//! Disables the velocity capture.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function disables operation of the velocity capture in the quadrature
//! encoder module.
//!
//! \return None.
//
//*****************************************************************************
void
QEIVelocityDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Disable the velocity capture.
    //
    HWREG(ui32Base + QEI_O_CTL) &= ~(QEI_CTL_VELEN);
}

//*****************************************************************************
//
//! Configures the velocity capture.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param ui32PreDiv specifies the predivider applied to the input quadrature
//! signal before it is counted; can be one of \b QEI_VELDIV_1,
//! \b QEI_VELDIV_2, \b QEI_VELDIV_4, \b QEI_VELDIV_8, \b QEI_VELDIV_16,
//! \b QEI_VELDIV_32, \b QEI_VELDIV_64, or \b QEI_VELDIV_128.
//! \param ui32Period specifies the number of clock ticks over which to measure
//! the velocity; must be non-zero.
//!
//! This function configures the operation of the velocity capture portion of
//! the quadrature encoder.  The position increment signal is predivided as
//! specified by \e ui32PreDiv before being accumulated by the velocity
//! capture.  The divided signal is accumulated over \e ui32Period system clock
//! before being saved and resetting the accumulator.
//!
//! \return None.
//
//*****************************************************************************
void
QEIVelocityConfigure(uint32_t ui32Base, uint32_t ui32PreDiv,
                     uint32_t ui32Period)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));
    ASSERT(!(ui32PreDiv & ~(QEI_CTL_VELDIV_M)));
    ASSERT(ui32Period != 0);

    //
    // Set the velocity predivider.
    //
    HWREG(ui32Base + QEI_O_CTL) = ((HWREG(ui32Base + QEI_O_CTL) &
                                    ~(QEI_CTL_VELDIV_M)) | ui32PreDiv);

    //
    // Set the timer period.
    //
    HWREG(ui32Base + QEI_O_LOAD) = ui32Period - 1;
}

//*****************************************************************************
//
//! Gets the current encoder speed.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function returns the current speed of the encoder.  The value returned
//! is the number of pulses detected in the specified time period; this number
//! can be multiplied by the number of time periods per second and divided by
//! the number of pulses per revolution to obtain the number of revolutions per
//! second.
//!
//! \return Returns the number of pulses captured in the given time period.
//
//*****************************************************************************
uint32_t
QEIVelocityGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Return the speed capture value.
    //
    return(HWREG(ui32Base + QEI_O_SPEED));
}

//*****************************************************************************
//
//! Returns the quadrature encoder interrupt number.
//!
//! \param ui32Base is the base address of the selected quadrature encoder
//!
//! This function returns the interrupt number for the quadrature encoder with
//! the base address passed in the \e ui32Base parameter.
//!
//! \return Returns a quadrature encoder interrupt number or 0 if the interrupt
//! does not exist.
//
//*****************************************************************************
static uint32_t
_QEIIntNumberGet(uint32_t ui32Base)
{
    uint32_t ui32Int;

    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Find the valid interrupt number for this quadrature encoder.
    //
    if(CLASS_IS_BLIZZARD)
    {
        if(ui32Base == QEI0_BASE)
        {
            ui32Int = INT_QEI0_BLIZZARD;
        }
        else
        {
            ui32Int = INT_QEI1_BLIZZARD;
        }
    }
    else if(CLASS_IS_SNOWFLAKE)
    {
        if(ui32Base == QEI0_BASE)
        {
            ui32Int = INT_QEI0_SNOWFLAKE;
        }
        else
        {
            ui32Int = 0;
        }
    }
    else
    {
        ui32Int = 0;
    }

    return(ui32Int);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the quadrature encoder interrupt.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param pfnHandler is a pointer to the function to be called when the
//! quadrature encoder interrupt occurs.
//!
//! This function registers the handler to be called when a quadrature encoder
//! interrupt occurs.  This function enables the global interrupt in the
//! interrupt controller; specific quadrature encoder interrupts must be
//! enabled via QEIIntEnable().  It is the interrupt handler's responsibility
//! to clear the interrupt source via QEIIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
QEIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Determine the interrupt number based on the QEI module.
    //
    ui32Int = _QEIIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the quadrature encoder interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the quadrature encoder interrupt.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//!
//! This function unregisters the handler to be called when a quadrature
//! encoder interrupt occurs.  This function also masks off the interrupt in
//! the interrupt controller so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
QEIIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Determine the interrupt number based on the QEI module.
    //
    ui32Int = _QEIIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Disable the interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Enables individual quadrature encoder interrupt sources.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be enabled.
//! Can be any of the \b QEI_INTERROR, \b QEI_INTDIR, \b QEI_INTTIMER, or
//! \b QEI_INTINDEX values.
//!
//! This function enables the indicated quadrature encoder interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! \return None.
//
//*****************************************************************************
void
QEIIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Enable the specified interrupts.
    //
    HWREG(ui32Base + QEI_O_INTEN) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables individual quadrature encoder interrupt sources.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be disabled.
//! This parameter can be any of the \b QEI_INTERROR, \b QEI_INTDIR,
//! \b QEI_INTTIMER, or \b QEI_INTINDEX values.
//!
//! This function disables the indicated quadrature encoder interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! \return None.
//
//*****************************************************************************
void
QEIIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Disable the specified interrupts.
    //
    HWREG(ui32Base + QEI_O_INTEN) &= ~(ui32IntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param bMasked is false if the raw interrupt status is required and true if
//! the masked interrupt status is required.
//!
//! This function returns the interrupt status for the quadrature encoder
//! module.  Either the raw interrupt status or the status of interrupts that
//! are allowed to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! \b QEI_INTERROR, \b QEI_INTDIR, \b QEI_INTTIMER, and \b QEI_INTINDEX.
//
//*****************************************************************************
uint32_t
QEIIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ui32Base + QEI_O_ISC));
    }
    else
    {
        return(HWREG(ui32Base + QEI_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears quadrature encoder interrupt sources.
//!
//! \param ui32Base is the base address of the quadrature encoder module.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be cleared.
//! This parameter can be any of the \b QEI_INTERROR, \b QEI_INTDIR,
//! \b QEI_INTTIMER, or \b QEI_INTINDEX values.
//!
//! The specified quadrature encoder interrupt sources are cleared, so that
//! they no longer assert.  This function must be called in the interrupt
//! handler to keep the interrupt from being triggered again immediately upon
//! exit.
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
QEIIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == QEI0_BASE) || (ui32Base == QEI1_BASE));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ui32Base + QEI_O_ISC) = ui32IntFlags;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
