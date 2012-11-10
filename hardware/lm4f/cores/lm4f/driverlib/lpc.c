//*****************************************************************************
//
// lpc.c - Driver for the Low Pin Count (LPC) module.
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

//*****************************************************************************
//
//! \addtogroup lpc_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_lpc.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/lpc.h"

//*****************************************************************************
//
//! \internal
//! Checks an LPC Channel.
//!
//! \param ulChannel is the LPC channel identifier.
//!
//! This function determines if a channel identifier is valid.  This function
//! does not check for Channel 7 (COMx).
//!
//! \return Returns \b true if the channel identifier is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
LPCChannelValid(unsigned long ulChannel)
{
    return((ulChannel == LPC_CHAN_CH0) ||
           (ulChannel == LPC_CHAN_CH1) ||
           (ulChannel == LPC_CHAN_CH2) ||
           (ulChannel == LPC_CHAN_CH3) ||
           (ulChannel == LPC_CHAN_CH4) ||
           (ulChannel == LPC_CHAN_CH5) ||
           (ulChannel == LPC_CHAN_CH6) ||
           (ulChannel == LPC_CHAN_CH7));
}
#endif // #ifdef DEBUG

//*****************************************************************************
//
//! Sets the configuration of the LPC module.
//!
//! \param ulBase is the base address of the LPC module.
//! \param ulConfig specifies the configuration of the LPC module.
//!
//! This function configures the LPC module for basic operation.  The
//! configuration of individual channels is handled in a separate function.
//!
//! The \e ulConfig parameter is the logical OR of the following values:
//! - \b LPC_CFG_WAKE - Force assertion of the LPC0CLKRUN signal when the
//! LPC bus is powered down (LPC0PD is asserted).
//!
//! \return None.
//
//*****************************************************************************
void
LPCConfigSet(unsigned long ulBase, unsigned long ulConfig)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulConfig & ~(LPC_CFG_WAKE)) == 0);

    //
    // Configure the appropriate LPC Control Register fields.
    //
    ulTemp = HWREG(ulBase + LPC_O_CTL);
    ulTemp &= ~LPC_CTL_WAKE;
    ulTemp |= (ulConfig & LPC_CTL_WAKE);
    HWREG(ulBase + LPC_O_CTL) = ulTemp;
}

//*****************************************************************************
//
//! Gets the current configuration of the LPC module.
//!
//! \param ulBase is the base address of the LPC module.
//!
//! This function queries the control register of the LPC module and returns
//! a bit-mapped value.
//!
//! \sa The description of the LPCConfigSet() function provides detailed
//! information for the bit-mapped configuration values that are returned.
//!
//! \return Returns the bit-mapped LPC module configuration value.
//
//*****************************************************************************
unsigned long
LPCConfigGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Return the configuration value
    //
    return((HWREG(ulBase + LPC_O_CTL) & LPC_CTL_WAKE));
}

//*****************************************************************************
//
//! Sets the Status Block Address for the LPC peripheral.
//!
//! \param ulBase is the base address of the LPC module.
//! \param ulAddress is the host address to use for the block status.
//! \param bEnabled indicates whether the block address feature should
//! be enabled.
//!
//! This function sets the LPC block address register and optionally enables
//! it.
//!
//! \return None.
//
//*****************************************************************************
void
LPCStatusBlockAddressSet(unsigned long ulBase, unsigned long ulAddress,
                         tBoolean bEnabled)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulAddress & ~0xFFFFFFFE) == 0);

    //
    // Set (and optionally enable) the Status Block Address
    //
    HWREG(ulBase + LPC_O_STSADDR) = (ulAddress | (bEnabled ? 1 : 0));
}

//*****************************************************************************
//
//! Gets the Status Block Address for the LPC peripheral.
//!
//! \param ulBase is the base address of the LPC module.
//!
//! This function returns the LPC block address register.  The LSB is used
//! to indicate whether this feature has been enabled or not.
//!
//! \return None.
//
//*****************************************************************************
unsigned
LPCStatusBlockAddressGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Return the Status Block Address, including the enable bit.
    //
    return(HWREG(ulBase + LPC_O_STSADDR));
}

//*****************************************************************************
//
//! Returns the status of the LPC module.
//!
//! \param ulBase is the base address of the LPC module.
//! \param pulCount is a pointer to storage for the channel count.
//! \param pulPoolSize is a pointer to storage for the register pool size.
//!
//! This function reads the value of the LPC Status register, calculates the
//! number of channels and buffer pool size, and then returns the raw status
//! value.
//!
//! \return Returns the contents of the LPC Status register.
//
//*****************************************************************************
unsigned long
LPCStatusGet(unsigned long ulBase, unsigned long *pulCount,
             unsigned long *pulPoolSize)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Get a snapshot of the status register.
    //
    ulStatus = HWREG(ulBase + LPC_O_STS);

    //
    // Extract the channel count from the status, including COMx channel.
    //
    if(pulCount)
    {
        *pulCount = (((ulStatus & LPC_STS_CHCNT_M) >> LPC_STS_CHCNT_S) + 1);
    }

    //
    // Extract/Calculate the register pool size.
    //
    if(pulPoolSize)
    {
        *pulPoolSize = (((ulStatus & LPC_STS_POOLSZ_M) >> 16) * 256);
    }

    //
    // Return the raw status.
    //
    return(ulStatus);
}

//*****************************************************************************
//
//! Generates a pulse on the SCIn signal.
//!
//! \param ulBase is the base address of the LPC module.
//! \param ulCount is the number used to generate the pulse width value.
//!
//! This function generates a pulse on the SCIn interrupt pin.  The width of
//! the pulse is (2 << \e ulCount) LPC Clock Periods, where \e ulCount can take
//! on the value of 0, 1, 2, or 3.  So, the pulse width is 2, 4, 8, or 16 clock
//! periods.
//!
//! \return None.
//
//*****************************************************************************
void
LPCSCIAssert(unsigned long ulBase, unsigned long ulCount)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(ulCount <= 3);

    //
    // Wait for any previous pulse to be completed, by checking the SCI bit
    // (which is a self-clearing bit that is used to generate the pulse).
    //
    while(HWREG(ulBase + LPC_O_CTL) & LPC_CTL_SCI)
    {
    }

    //
    // Set the count value first, prior to enabling the pulse.
    //
    HWREG(ulBase + LPC_O_CTL) &= ~LPC_CTL_SCICNT_M;
    HWREG(ulBase + LPC_O_CTL) |= (ulCount << 10);

    //
    // Now, generate the pulse by setting the SCI bit.
    //
    HWREG(ulBase + LPC_O_CTL) |= LPC_CTL_SCI;
}

//*****************************************************************************
//
//! Configure the LPC IRQ operation.
//!
//! \param ulBase is the base address of the LPC module.
//! \param bIRQPulse is a flag to indicate the manual IRQ bits should be
//! cleared after they have been sent (in an SIRQ frame).
//! \param bIRQOnChange is a flag to indicate that an SIRQ frame should be
//! sent whenever any IRQ bits (manual/auto) change status.
//!
//! This function configures the LPC IRQs.  If the \e bIRQPulse parameter is
//! \b true, then manual IRQ values are cleared after they are sent.  If the
//! \e bIRQOnChange parameter is true, then IRQ values (manual and/or
//! automatic) are sent when a change is detected.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIRQConfig(unsigned long ulBase, tBoolean bIRQPulse, tBoolean bIRQOnChange)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Setup IRQ pulse configuration.
    //
    if(bIRQPulse)
    {
        HWREG(ulBase + LPC_O_IRQCTL) |= LPC_IRQCTL_PULSE;
    }
    else
    {
        HWREG(ulBase + LPC_O_IRQCTL) &= ~LPC_IRQCTL_PULSE;
    }

    //
    // Setup IRQ on-change configuration.
    //
    if(bIRQOnChange)
    {
        HWREG(ulBase + LPC_O_IRQCTL) |= LPC_IRQCTL_ONCHG;
    }
    else
    {
        HWREG(ulBase + LPC_O_IRQCTL) &= ~LPC_IRQCTL_ONCHG;
    }
}

//*****************************************************************************
//
//! Set the manual LPC IRQ bits.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIRQ specifies the IRQ bits that should be set.
//!
//! This function sets the IRQ bits that are sent in the SERIRQ frame.  The
//! value in the \e ulIRQ register is OR-ed into the existing manual IRQ
//! setting.  The value for the \e ulIRQ parameter can be any combination of
//! the following values:  \b LPC_IRQ15, \b LPC_IRQ14, \b LPC_IRQ13,
//! \b LPC_IRQ12, \b LPC_IRQ11, \b LPC_IRQ10, \b LPC_IRQ9, \b LPC_IRQ8,
//! \b LPC_IRQ7,  \b LPC_IRQ6, \b LPC_IRQ5, \b LPC_IRQ4, \b LPC_IRQ3,
//! \b LPC_IRQ2, \b LPC_IRQ1, or \b LPC_IRQ0.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIRQSet(unsigned long ulBase, unsigned long ulIRQ)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Get the current IRQ configuration, mask off the bits that we are to
    // be operating on, set/clear them as appropriate, then rewrite the
    // register.
    //
    ulTemp = HWREG(ulBase + LPC_O_IRQCTL);
    ulTemp |= (ulIRQ & 0xFFFF0000);
    HWREG(ulBase + LPC_O_IRQCTL) = ulTemp;
}

//*****************************************************************************
//
//! Clear the manual LPC IRQ bits.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIRQ specifies the IRQ bits that should be cleared.
//!
//! This function clears the IRQ bits that are sent in the SERIRQ frame.  The
//! value in the \e ulIRQ register is OR-ed into the existing manual IRQ
//! setting.  The value for the \e ulIRQ parameter can be any combination of
//! the following values:  \b LPC_IRQ15, \b LPC_IRQ14, \b LPC_IRQ13,
//! \b LPC_IRQ12, \b LPC_IRQ11, \b LPC_IRQ10, \b LPC_IRQ9, \b LPC_IRQ8,
//! \b LPC_IRQ7, \b LPC_IRQ6, \b LPC_IRQ5, \b LPC_IRQ4, \b LPC_IRQ3,
//! \b LPC_IRQ2, \b LPC_IRQ1, or \b LPC_IRQ0.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIRQClear(unsigned long ulBase, unsigned long ulIRQ)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Get the current IRQ configuration, mask off the bits that we are to
    // be operating on, set/clear them as appropriate, then rewrite the
    // register.
    //
    ulTemp = HWREG(ulBase + LPC_O_IRQCTL);
    ulTemp &= ~(ulIRQ & 0xFFFF0000);
    HWREG(ulBase + LPC_O_IRQCTL) = ulTemp;
}

//*****************************************************************************
//
//! Get the configuration and status of the IRQ signals
//!
//! \param ulBase specifies the LPC module base address.
//!
//! This function returns the LPC module's SERIRQ status.  The value returned
//! is a combination of the following values: \b LPC_IRQ15, \b LPC_IRQ14,
//! \b LPC_IRQ13, \b LPC_IRQ12, \b LPC_IRQ11, \b LPC_IRQ10, \b LPC_IRQ9,
//! \b LPC_IRQ8, \b LPC_IRQ7, \b LPC_IRQ6, \b LPC_IRQ5, \b LPC_IRQ4,
//! \b LPC_IRQ3, \b LPC_IRQ2, \b LPC_IRQ1, \b LPC_IRQ0, \b LPC_IRQ_BUSY, or
//! \b LPC_IRQ_CONT.
//!
//! \return None.
//
//*****************************************************************************
unsigned long
LPCIRQGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Simply read the registers and return the values.
    //
    return(HWREG(ulBase + LPC_O_IRQST));
}

//*****************************************************************************
//
//! Trigger a manual SIRQ frame.
//!
//! \param ulBase specifies the LPC module base address.
//!
//! This function forces the sending of an SIRQ frame using whatever values are
//! currently set (auto and/or manual).
//!
//! \return None.
//
//*****************************************************************************
void
LPCIRQSend(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Set the bit to force the sending of an SIRQ frame.
    //
    HWREG(ulBase + LPC_O_IRQCTL) |= LPC_IRQCTL_SND;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the LPC module.
//!
//! \param ulBase specifies the LPC module base address.
//! \param pfnHandler is a pointer to the function to be called when the
//! LPC interrupt occurs.
//!
//! This function registers the handler to be called when an LPC interrupt
//! occurs. This function enables the global interrupt in the interrupt
//! controller; specific LPC interrupts must be enabled via LPCIntEnable().
//! If necessary, it is the interrupt handler's responsibility to clear the
//! interrupt source via LPCIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(pfnHandler != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_LPC0, pfnHandler);

    //
    // Enable the LPC interrupt.
    //
    IntEnable(INT_LPC0);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the LPC module.
//!
//! \param ulBase specifies the LPC module base address.
//!
//! This function unregisters the handler to be called when an LPC interrupt
//! occurs.  This fucntion also masks off the interrupt in the interrupt
//! controller so that the interrupt handler is no longer called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Disable the LPC interrupt.
    //
    IntDisable(INT_LPC0);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_LPC0);
}

//*****************************************************************************
//
//! Enables individual LPC interrupt sources.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated LPC interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter can be any of the following values:
//! \b LPC_INT_RST, \b LPC_INT_SLEEP, \b LPC_INT_COMx, \b LPC_INT_SIRQ,
//! \b LPC_INT_CHn_EP_TO_HOST, \b LPC_INT_CHn_EP_FROM_DATA,
//! \b LPC_INT_CHn_EP_FROM_CMD, \b LPC_INT_CHn_MB_HOST_WON,
//! \b LPC_INT_CHn_MB_HOST_WRITE, \b LPC_INT_CHn_MB_HOST_READ, or
//! \b LPC_INT_CHn_MB_MCU_LOST, where \b CHn can be \b CH6, \b CH5, \b CH4,
//! \b CH3, \b CH2, \b CH1, or \b CH0.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Get the current mask value.
    //
    HWREG(ulBase + LPC_O_IM) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual LPC interrupt sources.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated LPC interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! \sa The description of the LPCIntEnable() function provides detailed
//! information for the bit-mapped values in \e ulIntFlags.
//!
//! \return None.
//
//*****************************************************************************
void
LPCIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + LPC_O_IM) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase specifies the LPC module base address.
//! \param bMasked is \b false if the raw interrupt status is required or
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the LPC module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! The interpretation of the LPC_INT_CHn fields varies based on the type
//! value programed for the specific Channel.
//!
//! \sa The description of the LPCIntEnable() function provides detailed
//! information for the bit-mapped values returned by this function.
//!
//! \return The current interrupt status.
//
//*****************************************************************************
unsigned long
LPCIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + LPC_O_MIS));
    }
    else
    {
        return(HWREG(ulBase + LPC_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears LPC interrupt sources.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified LPC interrupt sources are cleared so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupts from being recognized again immediately upon exit.
//!
//! \sa The description of the LPCIntEnable() function provides detailed
//! information for the bit-mapped values in \e ulIntFlags.
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
LPCIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + LPC_O_IC) = ulIntFlags;
}

//*****************************************************************************
//
//! Enables an LPC Channel.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to enable.
//!
//! The specified LPC Channel is enabled.
//!
//! The value for the \e ulChannel parameter can be any one of the following
//! values:  \b LPC_CHAN_CH0, \b LPC_CHAN_CH1, \b LPC_CHAN_CH2,
//! \b LPC_CHAN_CH3, \b LPC_CHAN_CH4, \b LPC_CHAN_CH5, \b LPC_CHAN_CH6 or
//! \b LPC_CHAN_CH7.
//!
//! \return None.
//
//*****************************************************************************
void
LPCChannelEnable(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));

    //
    // Enable the specified channel.
    //
    HWREG(ulBase + LPC_O_CTL) |= (1 << ulChannel);
}

//*****************************************************************************
//
//! Disables an LPC Channel.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to disable.
//!
//! This function disables the specified LPC Channel.
//!
//! \sa The description of the LPCChannelEnable() function provides detailed
//! information for the values that can be used for the \e ulChannel parameter.
//!
//! \return None.
//
//*****************************************************************************
void
LPCChannelDisable(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));

    //
    // Disable the specified channel.
    //
    HWREG(ulBase + LPC_O_CTL) &= ~(1 << ulChannel);
}

//*****************************************************************************
//
//! Sets the configuration of an LPC Channel as an endpoint.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to configure.
//! \param ulConfig specifies configuration options required for the endpoint.
//! \param ulOffset specifies the offset from the beginning of the buffer pool
//! for this endpoint's data.
//! \param ulAddress specifies the LPC bus address (IO and/or MEM) for this
//! channel.
//!
//! This function enables the specified LPC Channel as an endpoint.
//!
//! \return None.
//
//*****************************************************************************
void
LPCChannelConfigEPSet(unsigned long ulBase, unsigned long ulChannel,
                      unsigned long ulConfig, unsigned long ulAddress,
                      unsigned long ulOffset)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));
    ASSERT((ulConfig & ~(LPC_CH0CTL_IRQSEL1_M | LPC_CH0CTL_IRQSEL0_M |
                         LPC_CH0CTL_IRQEN1 | LPC_CH0CTL_IRQEN0_M)) == 0);
    ASSERT((ulOffset & 3) == 0);
    ASSERT(ulOffset < ((((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
              16) * 256) - 4));

    //
    // Convert the byte offset address into a half-word
    // offset address and add into the control word.
    //
    ulConfig |= (((ulOffset >> 1) << LPC_CH0CTL_OFFSET_S) &
                 LPC_CH0CTL_OFFSET_M);

    //
    // Write the final control value into the control word for
    // the channel.
    //
    HWREG(ulBase + LPC_O_CH0CTL + (ulChannel * 0x10)) = ulConfig;

    //
    // Setup the IO and/or MEM address to match for this channel.
    //
    HWREG(ulBase + LPC_O_CH0ADR + (ulChannel * 0x10)) = ulAddress;
}

//*****************************************************************************
//
//! Sets the configuration of an LPC Channel as a mailbox.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to configure.
//! \param ulConfig specifies configuration options required for the endpoint.
//! \param ulOffset specifies the offset from the beginning of the buffer pool
//! for this endpoint's data.
//! \param ulAddress specifies the LPC bus address (IO and/or MEM) for this
//! channel.
//!
//! This function enables the specified LPC Channel as a mailbox.
//!
//! \return None.
//
//*****************************************************************************
void
LPCChannelConfigMBSet(unsigned long ulBase, unsigned long ulChannel,
                      unsigned long ulConfig, unsigned long ulAddress,
                      unsigned long ulOffset)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));
    ASSERT((ulConfig & ~(LPC_CH0CTL_IRQSEL1_M | LPC_CH0CTL_IRQSEL1_M |
                         LPC_CH0CTL_IRQSEL0_M |
                         LPC_CH0CTL_IRQEN2 | LPC_CH0CTL_IRQEN1 |
                         LPC_CH0CTL_IRQEN0_M |
                         LPC_CH0CTL_ARBDIS | LPC_CH0CTL_AMASK_M)) == 0);
    ASSERT((ulOffset & 3) == 0);
    ASSERT(ulOffset < ((((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
              16) * 256) - 4));

    //
    // Convert the byte offset address into a half-word
    // offset address and add into the control word.
    //
    ulConfig |= (((ulOffset >> 1) << LPC_CH0CTL_OFFSET_S) &
                 LPC_CH0CTL_OFFSET_M);

    //
    // Set the configuration bit that enables Mailbox mode.
    //
    ulConfig |= LPC_CH0CTL_TYPE;

    //
    // Write the final control value into the control word for
    // the channel.
    //
    HWREG(ulBase + LPC_O_CH0CTL + (ulChannel * 0x10)) = ulConfig;

    //
    // Setup the IO and/or MEM address to match for this channel.
    //
    HWREG(ulBase + LPC_O_CH0ADR + (ulChannel * 0x10)) = ulAddress;
}

//*****************************************************************************
//
//! Sets the configuration of an LPC Channel as a COMx.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to configure.
//! \param ulConfig specifies configuration options required for the endpoint.
//! \param ulOffset specifies the offset from the beginning of the buffer pool
//! for this endpoint's data.
//! \param ulAddress specifies the LPC bus address (IO and/or MEM) for this
//! channel.
//! \param ulCOMxMode specifies the COMx mode to be used.
//!
//! The specified LPC Channel is enabled as a COMx.
//!
//! \return None.
//
//*****************************************************************************
void
LPCChannelConfigCOMxSet(unsigned long ulBase, unsigned long ulChannel,
                        unsigned long ulConfig, unsigned long ulAddress,
                        unsigned long ulOffset, unsigned long ulCOMxMode)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));
    ASSERT(ulChannel == LPC_CHAN_COMx);
    ASSERT((ulConfig & ~(LPC_CH7CTL_IRQSEL1_M | LPC_CH7CTL_IRQSEL0_M |
                         LPC_CH7CTL_CX | LPC_CH7CTL_IRQEN1 |
                         LPC_CH7CTL_IRQEN0_M)) == 0);
    ASSERT((ulOffset & 3) == 0);
    ASSERT(ulOffset < ((((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
              16) * 256) - 4));
    ASSERT((ulCOMxMode & ~LPC_DMACX_CXACT_M) == 0);

    //
    // Convert the byte offset address into a half-word
    // offset address and add into the control word.
    //
    ulConfig |= (((ulOffset >> 1) << LPC_CH0CTL_OFFSET_S) &
                 LPC_CH0CTL_OFFSET_M);

    //
    // Write the final control value into the control word for
    // the channel.
    //
    HWREG(ulBase + LPC_O_CH0CTL + (ulChannel * 0x10)) = ulConfig;

    //
    // Setup the IO and/or MEM address to match for this channel.
    //
    HWREG(ulBase + LPC_O_CH0ADR + (ulChannel * 0x10)) = ulAddress;

    //
    // Configure the COMx Mode for this channel.
    //
    ulTemp = HWREG(ulBase + LPC_O_DMACX);
    ulTemp &= ~LPC_DMACX_CXACT_M;
    ulTemp |= ulCOMxMode;
    ulTemp |= LPC_DMACX_COMX;
    HWREG(ulBase + LPC_O_DMACX) = ulTemp;
}

//*****************************************************************************
//
//! Gets the configuration of an LPC Channel.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to configure.
//! \param pulOffset is a pointer to storage for the channel pool offset.
//! \param pulAddress is a pointer to storage for the channel bus address.
//! \param pulCOMxMode is a pointer to storage for the channel COMx mode.
//!
//! This function determines and returns the configuration for the specified
//! channel.
//!
//! \return Returns the bit-mapped channel control register value.
//
//*****************************************************************************
unsigned long
LPCChannelConfigGet(unsigned long ulBase, unsigned long ulChannel,
                    unsigned long *pulAddress, unsigned long *pulOffset,
                    unsigned long *pulCOMxMode)
{
    unsigned long ulConfig;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));

    //
    // Read the channel control register.
    //
    ulConfig = HWREG(ulBase + LPC_O_CH0CTL + (ulChannel * 0x10));

    //
    // Get the buffer pool offset value.
    //
    if(pulOffset)
    {
        *pulOffset = ((ulConfig & LPC_CH0CTL_OFFSET_M) >>
                      (LPC_CH0CTL_OFFSET_S - 1));
    }

    //
    // Get the IO/Memory address that this endpoint responds to.
    //
    if(pulAddress)
    {
        *pulAddress = HWREG(ulBase + LPC_O_CH0ADR + (ulChannel * 0x10));
    }

    //
    // Configure the COMx Mode for this channel.
    //
    if(pulCOMxMode && (ulChannel == LPC_CHAN_COMx))
    {
        *pulCOMxMode = (HWREG(ulBase + LPC_O_DMACX) & 0x00070000);
    }

    //
    // Return the raw config value.
    //
    return(ulConfig);
}

//*****************************************************************************
//
//! Gets the absolute base address of the channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC channel to configure.
//!
//! Thos function calculates the absolute address of the channel pool from the
//! channel configuration setting and returns it.
//!
//! \return Returns the absolute base address of the channel pool.
//
//*****************************************************************************
unsigned long
LPCChannelPoolAddressGet(unsigned long ulBase, unsigned long ulChannel)
{
    unsigned long ulAddress;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));

    //
    // Read the channel control register.
    //
    ulAddress = HWREG(ulBase + LPC_O_CH0CTL + (ulChannel * 0x10));

    //
    // Mask off the channel offset portion and shift it into a byte
    // offset (stored as half-word offset).
    //
    ulAddress = ((ulAddress & LPC_CH0CTL_OFFSET_M) >>
                 (LPC_CH0CTL_OFFSET_S - 1));

    //
    // Add the LPC and Buffer Pool base address to get the final
    // address to return.
    //
    ulAddress += (ulBase + LPC_O_POOL);

    //
    // Return the address to the calling routine.
    //
    return(ulAddress);
}

//*****************************************************************************
//
//! Reads the status word from an LPC Channel.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC Channel.
//!
//! This function reads the status word from an LPC channel and returns it to
//! the caller.
//!
//! \return content of the channel status register.
//
//*****************************************************************************
unsigned long
LPCChannelStatusGet(unsigned long ulBase, unsigned long ulChannel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));

    //
    // Read the half-word status from the LPC Channel
    //
    return (HWREG(ulBase + LPC_O_CH0ST + (ulChannel * 0x10)));
}

//*****************************************************************************
//
//! Sets the user bits in the status word (16-bits) of an LPC Channel.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC Channel.
//! \param ulStatus is the user bit values to set.
//!
//! This function sets the selected user bits of the status word for an LPC
//! channel.
//!
//! \return None
//
//*****************************************************************************
void
LPCChannelStatusSet(unsigned long ulBase, unsigned long ulChannel,
                    unsigned long ulStatus)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));
    ASSERT((ulStatus & (~LPC_CH0ST_USER_M)) == 0);

    //
    // Read the status from the LPC Channel, and set new values for
    // the user bits.
    //
    ulTemp = HWREG(ulBase + LPC_O_CH0ST + (ulChannel * 0x10));
    ulTemp |= ulStatus;
    HWREG(ulBase + LPC_O_CH0ST + (ulChannel * 0x10)) = ulTemp;
}

//*****************************************************************************
//
//! Clears the user bits in the status word (16-bits) of an LPC Channel.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulChannel specifies the LPC Channel.
//! \param ulStatus is the user bit values to clear.
//!
//! This function sets the selected user bits of the status word for an LPC
//! channel.
//!
//! \return None
//
//*****************************************************************************
void
LPCChannelStatusClear(unsigned long ulBase, unsigned long ulChannel,
                      unsigned long ulStatus)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(LPCChannelValid(ulChannel));
    ASSERT((ulStatus & (~LPC_CH0ST_USER_M)) == 0);

    //
    // Read the status from the LPC Channel, and set new values for
    // the user bits.
    //
    ulTemp = HWREG(ulBase + LPC_O_CH0ST + (ulChannel * 0x10));
    ulTemp &= ~ulStatus;
    HWREG(ulBase + LPC_O_CH0ST + (ulChannel * 0x10)) = ulTemp;
}

//*****************************************************************************
//
//! Sets the configuration of DMA for LPC channels.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulConfig specifies the DMA channel configuration.
//! \param ulMask specifies the configuration mask to be used.
//!
//! This function sets the specified DMA channel operation based on the
//! \e ulConfig parameter.
//!
//! \return None.
//
//*****************************************************************************
void
LPCChannelDMAConfigSet(unsigned long ulBase, unsigned long ulConfig,
                       unsigned long ulMask)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulConfig & ~0x000000FF) == 0);
    ASSERT((ulConfig & 0x00000003) != 0x00000003);
    ASSERT((ulConfig & 0x0000000C) != 0x0000000C);
    ASSERT((ulConfig & 0x00000030) != 0x00000030);
    ASSERT((ulConfig & 0x000000C0) != 0x000000C0);
    ASSERT((ulMask & ~0x000000FF) == 0);

    //
    // Get the current mask value.
    //
    ulTemp = HWREG(ulBase + LPC_O_DMACX);
    ulTemp &= ~ulMask;
    ulTemp |= (ulConfig & ulMask);
    HWREG(ulBase + LPC_O_DMACX) = ulTemp;
}

//*****************************************************************************
//
//! Gets the configuration of DMA for LPC channels.
//!
//! \param ulBase specifies the LPC module base address.
//!
//! This function returns the configuration of the LPC DMA channels.
//!
//! \return Returns the bit-mapped DMA channel configuration.
//
//*****************************************************************************
unsigned long
LPCChannelDMAConfigGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Get the current mask value.
    //
    return(HWREG(ulBase + LPC_O_DMACX) & 0x000000FF);
}

//*****************************************************************************
//
//! Reads a byte from the LPC channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulOffset specifies the offset from the beginning of the LPC channel
//! pool.
//!
//! This function reads a byte from the channel pool.
//!
//! \return Returns the byte read from the pool memory.
//
//*****************************************************************************
unsigned char
LPCByteRead(unsigned long ulBase, unsigned long ulOffset)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(ulOffset < (((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
                        16) * 256));

    //
    // Return the byte from the LPC Buffer Pool.
    //
    return(HWREGB(ulBase + LPC_O_POOL + ulOffset));
}

//*****************************************************************************
//
//! Writes a byte to the LPC channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulOffset specifies the offset from the beginning of the LPC channel
//! pool.
//! \param ucData specifies the byte to write.
//!
//! This function writes a byte to the channel pool.
//!
//! \return None
//
//*****************************************************************************
void
LPCByteWrite(unsigned long ulBase, unsigned long ulOffset,
             unsigned char ucData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT(ulOffset < (((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
                        16) * 256));

    //
    // Write the byte to the LPC Buffer Pool.
    //
    HWREGB(ulBase + LPC_O_POOL + ulOffset) = ucData;
}

//*****************************************************************************
//
//! Reads a half-word from the LPC channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulOffset specifies the offset from the beginning of the LPC channel
//! pool.
//!
//! This function reads a half-word from the channel pool.  The \e ulOffset
//! specified must be half-word aligned.
//!
//! \return Returns the half-word read from the pool memory.
//
//*****************************************************************************
unsigned short
LPCHalfWordRead(unsigned long ulBase, unsigned long ulOffset)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulOffset & 1) == 0);
    ASSERT(ulOffset < (((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
                        16) * 256));

    //
    // Return the half-word from the LPC Buffer Pool.
    //
    return(HWREGH(ulBase + LPC_O_POOL + ulOffset));
}

//*****************************************************************************
//
//! Writes a half-word to the LPC channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulOffset specifies the offset from the beginning of the LPC channel
//! pool.
//! \param usData specifies the byte to write.
//!
//! This function writes a half-word to the channel pool.  The \e ulOffset
//! specified must be half-word aligned.
//!
//! \return None
//
//*****************************************************************************
void
LPCHalfWordWrite(unsigned long ulBase, unsigned long ulOffset,
                 unsigned short usData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulOffset & 1) == 0);
    ASSERT(ulOffset < (((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
                        16) * 256));

    //
    // Write the half-word to the LPC Buffer Pool.
    //
    HWREGH(ulBase + LPC_O_POOL + ulOffset) = usData;
}

//*****************************************************************************
//
//! Reads a word from the LPC channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulOffset specifies the offset from the beginning of the LPC channel
//! pool.
//!
//! This function reads a word from the channel pool.  The \e ulOffset
//! specified must be word aligned.
//!
//! \return Returns the word read from the pool memory.
//
//*****************************************************************************
unsigned long
LPCWordRead(unsigned long ulBase, unsigned long ulOffset)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulOffset & 3) == 0);
    ASSERT(ulOffset < (((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
                        16) * 256));

    //
    // Return the word from the LPC Buffer Pool.
    //
    return(HWREG(ulBase + LPC_O_POOL + ulOffset));
}

//*****************************************************************************
//
//! Writes a word to the LPC channel pool.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulOffset specifies the offset from the beginning of the LPC channel
//! pool.
//! \param ulData specifies the word to write.
//!
//! This function writes a word to the channel pool.  The \e ulOffset
//! specified must be word aligned.
//!
//! \return None
//
//*****************************************************************************
void
LPCWordWrite(unsigned long ulBase, unsigned long ulOffset,
             unsigned long ulData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulOffset & 1) == 0);
    ASSERT(ulOffset < (((HWREG(ulBase + LPC_O_STS) & LPC_STS_POOLSZ_M) >>
                        16) * 256));

    //
    // Write the word to the LPC Buffer Pool.
    //
    HWREG(ulBase + LPC_O_POOL + ulOffset) = ulData;
}

//*****************************************************************************
//
//! Enables individual COMx interrupt sources.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated COMx interrupt sources to trigger the
//! COMx interrupt in the primary LPC interrupt registers.
//!
//! \return None.
//
//*****************************************************************************
void
LPCCOMxIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulIntFlags & ~(LPC_DMACX_CXEM | LPC_DMACX_CXTXEM |
                           LPC_DMACX_CXRXEM)) == 0);

    //
    // Get the current mask value.
    //
    HWREG(ulBase + LPC_O_DMACX) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual COMx interrupt sources.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated COMx interrupt sources from triggering
//! the COMx interrupt in the primary LPC interrupt registers.
//!
//! \return None.
//
//*****************************************************************************
void
LPCCOMxIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulIntFlags & ~(LPC_DMACX_CXEM | LPC_DMACX_CXTXEM |
                           LPC_DMACX_CXRXEM)) == 0);

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + LPC_O_DMACX) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the current COMx interrupt status.
//!
//! \param ulBase specifies the LPC module base address.
//! \param bMasked is \b false if the raw interrupt status is required or
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the COMx module.
//!
//! \return The current interrupt status.
//
//*****************************************************************************
unsigned long
LPCCOMxIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    unsigned long ulStatus;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    ulStatus = HWREG(ulBase + LPC_O_DMACX);
    if(bMasked)
    {
        ulStatus = ulStatus & (ulStatus << 4);
    }
    return(ulStatus & (LPC_DMACX_CXRES | LPC_DMACX_CXTXRES |
                           LPC_DMACX_CXRXRES));
}

//*****************************************************************************
//
//! Clears COMx interrupt sources.
//!
//! \param ulBase specifies the LPC module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! This function clears the specified COMx interrupt sources so that they no
//! longer assert.
//!
//! \return None.
//
//*****************************************************************************
void
LPCCOMxIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == LPC0_BASE);
    ASSERT((ulIntFlags & ~(LPC_DMACX_CXRES | LPC_DMACX_CXTXRES |
                           LPC_DMACX_CXRXRES)) == 0);

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + LPC_O_DMACX) |= ulIntFlags;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
