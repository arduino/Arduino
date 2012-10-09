//*****************************************************************************
//
// qei.c - Driver for the Quadrature Encoder with Index.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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

//*****************************************************************************
//
//! \addtogroup qei_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_qei.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"

//*****************************************************************************
//
//! Enables the quadrature encoder.
//!
//! \param ulBase is the base address of the quadrature encoder module.
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
QEIEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Enable the QEI module.
    //
    HWREG(ulBase + QEI_O_CTL) |= QEI_CTL_ENABLE;
}

//*****************************************************************************
//
//! Disables the quadrature encoder.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//!
//! This function disables operation of the quadrature encoder module.
//!
//! \return None.
//
//*****************************************************************************
void
QEIDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Disable the QEI module.
    //
    HWREG(ulBase + QEI_O_CTL) &= ~(QEI_CTL_ENABLE);
}

//*****************************************************************************
//
//! Configures the quadrature encoder.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param ulConfig is the configuration for the quadrature encoder.  See below
//! for a description of this parameter.
//! \param ulMaxPosition specifies the maximum position value.
//!
//! This function configures the operation of the quadrature encoder.  The
//! \e ulConfig parameter provides the configuration of the encoder and is the
//! logical OR of several values:
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
//! \e ulMaxPosition is the maximum value of the position integrator and is
//! the value used to reset the position capture when in index reset mode and
//! moving in the reverse (negative) direction.
//!
//! \return None.
//
//*****************************************************************************
void
QEIConfigure(unsigned long ulBase, unsigned long ulConfig,
             unsigned long ulMaxPosition)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Write the new configuration to the hardware.
    //
    HWREG(ulBase + QEI_O_CTL) = ((HWREG(ulBase + QEI_O_CTL) &
                                  ~(QEI_CTL_CAPMODE | QEI_CTL_RESMODE |
                                    QEI_CTL_SIGMODE | QEI_CTL_SWAP)) |
                                 ulConfig);

    //
    // Set the maximum position.
    //
    HWREG(ulBase + QEI_O_MAXPOS) = ulMaxPosition;
}

//*****************************************************************************
//
//! Gets the current encoder position.
//!
//! \param ulBase is the base address of the quadrature encoder module.
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
unsigned long
QEIPositionGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Return the current position counter.
    //
    return(HWREG(ulBase + QEI_O_POS));
}

//*****************************************************************************
//
//! Sets the current encoder position.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param ulPosition is the new position for the encoder.
//!
//! This function sets the current position of the encoder; the encoder
//! position is then measured relative to this value.
//!
//! \return None.
//
//*****************************************************************************
void
QEIPositionSet(unsigned long ulBase, unsigned long ulPosition)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Set the position counter.
    //
    HWREG(ulBase + QEI_O_POS) = ulPosition;
}

//*****************************************************************************
//
//! Gets the current direction of rotation.
//!
//! \param ulBase is the base address of the quadrature encoder module.
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
long
QEIDirectionGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Return the direction of rotation.
    //
    return((HWREG(ulBase + QEI_O_STAT) & QEI_STAT_DIRECTION) ? -1 : 1);
}

//*****************************************************************************
//
//! Gets the encoder error indicator.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//!
//! This function returns the error indicator for the quadrature encoder.  It
//! is an error for both of the signals of the quadrature input to change at
//! the same time.
//!
//! \return Returns \b true if an error has occurred and \b false otherwise.
//
//*****************************************************************************
tBoolean
QEIErrorGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Return the error indicator.
    //
    return((HWREG(ulBase + QEI_O_STAT) & QEI_STAT_ERROR) ? true : false);
}

//*****************************************************************************
//
//! Enables the velocity capture.
//!
//! \param ulBase is the base address of the quadrature encoder module.
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
QEIVelocityEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Enable the velocity capture.
    //
    HWREG(ulBase + QEI_O_CTL) |= QEI_CTL_VELEN;
}

//*****************************************************************************
//
//! Disables the velocity capture.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//!
//! This function disables operation of the velocity capture in the quadrature
//! encoder module.
//!
//! \return None.
//
//*****************************************************************************
void
QEIVelocityDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Disable the velocity capture.
    //
    HWREG(ulBase + QEI_O_CTL) &= ~(QEI_CTL_VELEN);
}

//*****************************************************************************
//
//! Configures the velocity capture.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param ulPreDiv specifies the predivider applied to the input quadrature
//! signal before it is counted; can be one of \b QEI_VELDIV_1,
//! \b QEI_VELDIV_2, \b QEI_VELDIV_4, \b QEI_VELDIV_8, \b QEI_VELDIV_16,
//! \b QEI_VELDIV_32, \b QEI_VELDIV_64, or \b QEI_VELDIV_128.
//! \param ulPeriod specifies the number of clock ticks over which to measure
//! the velocity; must be non-zero.
//!
//! This function configures the operation of the velocity capture portion of
//! the quadrature encoder.  The position increment signal is predivided as
//! specified by \e ulPreDiv before being accumulated by the velocity capture.
//! The divided signal is accumulated over \e ulPeriod system clock before
//! being saved and resetting the accumulator.
//!
//! \return None.
//
//*****************************************************************************
void
QEIVelocityConfigure(unsigned long ulBase, unsigned long ulPreDiv,
                     unsigned long ulPeriod)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));
    ASSERT(!(ulPreDiv & ~(QEI_CTL_VELDIV_M)));
    ASSERT(ulPeriod != 0);

    //
    // Set the velocity predivider.
    //
    HWREG(ulBase + QEI_O_CTL) = ((HWREG(ulBase + QEI_O_CTL) &
                                  ~(QEI_CTL_VELDIV_M)) | ulPreDiv);

    //
    // Set the timer period.
    //
    HWREG(ulBase + QEI_O_LOAD) = ulPeriod - 1;
}

//*****************************************************************************
//
//! Gets the current encoder speed.
//!
//! \param ulBase is the base address of the quadrature encoder module.
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
unsigned long
QEIVelocityGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Return the speed capture value.
    //
    return(HWREG(ulBase + QEI_O_SPEED));
}

//*****************************************************************************
//
//! Registers an interrupt handler for the quadrature encoder interrupt.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param pfnHandler is a pointer to the function to be called when the
//! quadrature encoder interrupt occurs.
//!
//! This function registers the handler to be called when a quadrature encoder
//! interrupt occurs.  This function enables the global interrupt in the
//! interrupt controller; specific quadrature encoder interrupts must be
//! enabled via QEIIntEnable(). It is the interrupt handler's responsibility to
//! clear the interrupt source via QEIIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
QEIIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Determine the interrupt number based on the QEI module.
    //
    ulInt = (ulBase == QEI0_BASE) ? INT_QEI0 : INT_QEI1;

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(ulInt, pfnHandler);

    //
    // Enable the quadrature encoder interrupt.
    //
    IntEnable(ulInt);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the quadrature encoder interrupt.
//!
//! \param ulBase is the base address of the quadrature encoder module.
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
QEIIntUnregister(unsigned long ulBase)
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Determine the interrupt number based on the QEI module.
    //
    ulInt = (ulBase == QEI0_BASE) ? INT_QEI0 : INT_QEI1;

    //
    // Disable the interrupt.
    //
    IntDisable(ulInt);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ulInt);
}

//*****************************************************************************
//
//! Enables individual quadrature encoder interrupt sources.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
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
QEIIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Enable the specified interrupts.
    //
    HWREG(ulBase + QEI_O_INTEN) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual quadrature encoder interrupt sources.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
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
QEIIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + QEI_O_INTEN) &= ~(ulIntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param bMasked is false if the raw interrupt status is required and true if
//! the masked interrupt status is required.
//!
//! This function returns the interrupt status for the quadrature encoder
//! module. Either the raw interrupt status or the status of interrupts that
//! are allowed to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! \b QEI_INTERROR, \b QEI_INTDIR, \b QEI_INTTIMER, and \b QEI_INTINDEX.
//
//*****************************************************************************
unsigned long
QEIIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + QEI_O_ISC));
    }
    else
    {
        return(HWREG(ulBase + QEI_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears quadrature encoder interrupt sources.
//!
//! \param ulBase is the base address of the quadrature encoder module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
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
QEIIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT((ulBase == QEI0_BASE) || (ulBase == QEI1_BASE));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + QEI_O_ISC) = ulIntFlags;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
