//*****************************************************************************
//
// ssi.c - Driver for Synchronous Serial Interface.
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
//! \addtogroup ssi_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/ssi.h"

//*****************************************************************************
//
// A mapping of timer base address to interupt number.
//
//*****************************************************************************
static const unsigned long g_ppulSSIIntMap[][2] =
{
    { SSI0_BASE, INT_SSI0 },
    { SSI1_BASE, INT_SSI1 },
    { SSI2_BASE, INT_SSI2 },
    { SSI3_BASE, INT_SSI3 },
};

//*****************************************************************************
//
//! \internal
//! Checks an SSI base address.
//!
//! \param ulBase specifies the SSI module base address.
//!
//! This function determines if a SSI module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
SSIBaseValid(unsigned long ulBase)
{
    return((ulBase == SSI0_BASE) || (ulBase == SSI1_BASE) ||
           (ulBase == SSI2_BASE) || (ulBase == SSI3_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Gets the SSI interrupt number.
//!
//! \param ulBase specifies the SSI module base address.
//!
//! Given a SSI base address, returns the corresponding interrupt number.
//!
//! \return Returns an SSI interrupt number, or -1 if \e ulBase is invalid.
//
//*****************************************************************************
static long
SSIIntNumberGet(unsigned long ulBase)
{
    unsigned long ulIdx;

    //
    // Loop through the table that maps SSI base addresses to interrupt
    // numbers.
    //
    for(ulIdx = 0; ulIdx < (sizeof(g_ppulSSIIntMap) /
                            sizeof(g_ppulSSIIntMap[0])); ulIdx++)
    {
        //
        // See if this base address matches.
        //
        if(g_ppulSSIIntMap[ulIdx][0] == ulBase)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(g_ppulSSIIntMap[ulIdx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(-1);
}

//*****************************************************************************
//
//! Configures the synchronous serial interface.
//!
//! \param ulBase specifies the SSI module base address.
//! \param ulSSIClk is the rate of the clock supplied to the SSI module.
//! \param ulProtocol specifies the data transfer protocol.
//! \param ulMode specifies the mode of operation.
//! \param ulBitRate specifies the clock rate.
//! \param ulDataWidth specifies number of bits transferred per frame.
//!
//! This function configures the synchronous serial interface.  It sets
//! the SSI protocol, mode of operation, bit rate, and data width.
//!
//! The \e ulProtocol parameter defines the data frame format.  The
//! \e ulProtocol parameter can be one of the following values:
//! \b SSI_FRF_MOTO_MODE_0, \b SSI_FRF_MOTO_MODE_1, \b SSI_FRF_MOTO_MODE_2,
//! \b SSI_FRF_MOTO_MODE_3, \b SSI_FRF_TI, or \b SSI_FRF_NMW.  The Motorola
//! frame formats encode the following polarity and phase configurations:
//!
//! <pre>
//! Polarity Phase       Mode
//!   0       0   SSI_FRF_MOTO_MODE_0
//!   0       1   SSI_FRF_MOTO_MODE_1
//!   1       0   SSI_FRF_MOTO_MODE_2
//!   1       1   SSI_FRF_MOTO_MODE_3
//! </pre>
//!
//! The \e ulMode parameter defines the operating mode of the SSI module.  The
//! SSI module can operate as a master or slave; if it is a slave, the SSI can
//! be configured to disable output on its serial output line.  The \e ulMode
//! parameter can be one of the following values: \b SSI_MODE_MASTER,
//! \b SSI_MODE_SLAVE, or \b SSI_MODE_SLAVE_OD.
//!
//! The \e ulBitRate parameter defines the bit rate for the SSI.  This bit rate
//! must satisfy the following clock ratio criteria:
//!
//! - FSSI >= 2 * bit rate (master mode); this speed cannot exceed 25 MHz.
//! - FSSI >= 12 * bit rate or 6 * bit rate (slave modes), depending on the
//! capability of the specific microcontroller
//!
//! where FSSI is the frequency of the clock supplied to the SSI module.
//!
//! The \e ulDataWidth parameter defines the width of the data transfers and
//! can be a value between 4 and 16, inclusive.
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
//!
//! This function replaces the original SSIConfig() API and performs the same
//! actions.  A macro is provided in <tt>ssi.h</tt> to map the original API to
//! this API.
//!
//! \return None.
//
//*****************************************************************************
void
SSIConfigSetExpClk(unsigned long ulBase, unsigned long ulSSIClk,
                   unsigned long ulProtocol, unsigned long ulMode,
                   unsigned long ulBitRate, unsigned long ulDataWidth)
{
    unsigned long ulMaxBitRate;
    unsigned long ulRegVal;
    unsigned long ulPreDiv;
    unsigned long ulSCR;
    unsigned long ulSPH_SPO;

    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));
    ASSERT((ulProtocol == SSI_FRF_MOTO_MODE_0) ||
           (ulProtocol == SSI_FRF_MOTO_MODE_1) ||
           (ulProtocol == SSI_FRF_MOTO_MODE_2) ||
           (ulProtocol == SSI_FRF_MOTO_MODE_3) ||
           (ulProtocol == SSI_FRF_TI) ||
           (ulProtocol == SSI_FRF_NMW));
    ASSERT((ulMode == SSI_MODE_MASTER) ||
           (ulMode == SSI_MODE_SLAVE) ||
           (ulMode == SSI_MODE_SLAVE_OD));
    ASSERT(((ulMode == SSI_MODE_MASTER) && (ulBitRate <= (ulSSIClk / 2))) ||
           ((ulMode != SSI_MODE_MASTER) && (ulBitRate <= (ulSSIClk / 12))));
    ASSERT((ulSSIClk / ulBitRate) <= (254 * 256));
    ASSERT((ulDataWidth >= 4) && (ulDataWidth <= 16));

    //
    // Set the mode.
    //
    ulRegVal = (ulMode == SSI_MODE_SLAVE_OD) ? SSI_CR1_SOD : 0;
    ulRegVal |= (ulMode == SSI_MODE_MASTER) ? 0 : SSI_CR1_MS;
    HWREG(ulBase + SSI_O_CR1) = ulRegVal;

    //
    // Set the clock predivider.
    //
    ulMaxBitRate = ulSSIClk / ulBitRate;
    ulPreDiv = 0;
    do
    {
        ulPreDiv += 2;
        ulSCR = (ulMaxBitRate / ulPreDiv) - 1;
    }
    while(ulSCR > 255);
    HWREG(ulBase + SSI_O_CPSR) = ulPreDiv;

    //
    // Set protocol and clock rate.
    //
    ulSPH_SPO = (ulProtocol & 3) << 6;
    ulProtocol &= SSI_CR0_FRF_M;
    ulRegVal = (ulSCR << 8) | ulSPH_SPO | ulProtocol | (ulDataWidth - 1);
    HWREG(ulBase + SSI_O_CR0) = ulRegVal;
}

//*****************************************************************************
//
//! Enables the synchronous serial interface.
//!
//! \param ulBase specifies the SSI module base address.
//!
//! This function enables operation of the synchronous serial interface.  The
//! synchronous serial interface must be configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
void
SSIEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ulBase + SSI_O_CR1) |= SSI_CR1_SSE;
}

//*****************************************************************************
//
//! Disables the synchronous serial interface.
//!
//! \param ulBase specifies the SSI module base address.
//!
//! This function disables operation of the synchronous serial interface.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ulBase + SSI_O_CR1) &= ~(SSI_CR1_SSE);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the synchronous serial interface.
//!
//! \param ulBase specifies the SSI module base address.
//! \param pfnHandler is a pointer to the function to be called when the
//! synchronous serial interface interrupt occurs.
//!
//! This function registers the handler to be called when an SSI interrupt
//! occurs.  This function enables the global interrupt in the interrupt
//! controller; specific SSI interrupts must be enabled via SSIIntEnable().  If
//! necessary, it is the interrupt handler's responsibility to clear the
//! interrupt source via SSIIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
SSIIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Determine the interrupt number based on the SSI port.
    //
    ulInt = SSIIntNumberGet(ulBase);

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(ulInt, pfnHandler);

    //
    // Enable the synchronous serial interface interrupt.
    //
    IntEnable(ulInt);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the synchronous serial interface.
//!
//! \param ulBase specifies the SSI module base address.
//!
//! This function clears the handler to be called when an SSI interrupt
//! occurs.  This function also masks off the interrupt in the interrupt
//! controller so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
SSIIntUnregister(unsigned long ulBase)
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Determine the interrupt number based on the SSI port.
    //
    ulInt = SSIIntNumberGet(ulBase);

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
//! Enables individual SSI interrupt sources.
//!
//! \param ulBase specifies the SSI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated SSI interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.  The \e ulIntFlags
//! parameter can be any of the \b SSI_TXFF, \b SSI_RXFF, \b SSI_RXTO, or
//! \b SSI_RXOR values.
//!
//! \return None.
//
//*****************************************************************************
void
SSIIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Enable the specified interrupts.
    //
    HWREG(ulBase + SSI_O_IM) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual SSI interrupt sources.
//!
//! \param ulBase specifies the SSI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated SSI interrupt sources.  The
//! \e ulIntFlags parameter can be any of the \b SSI_TXFF, \b SSI_RXFF,
//!  \b SSI_RXTO, or \b SSI_RXOR values.
//!
//! \return None.
//
//*****************************************************************************
void
SSIIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + SSI_O_IM) &= ~(ulIntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase specifies the SSI module base address.
//! \param bMasked is \b false if the raw interrupt status is required or
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the SSI module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! \b SSI_TXFF, \b SSI_RXFF, \b SSI_RXTO, and \b SSI_RXOR.
//
//*****************************************************************************
unsigned long
SSIIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + SSI_O_MIS));
    }
    else
    {
        return(HWREG(ulBase + SSI_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears SSI interrupt sources.
//!
//! \param ulBase specifies the SSI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! This function clears the specified SSI interrupt sources so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep the interrupts from being triggered again immediately upon exit.  The
//! \e ulIntFlags parameter can consist of either or both the \b SSI_RXTO and
//! \b SSI_RXOR values.
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
SSIIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + SSI_O_ICR) = ulIntFlags;
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO.
//!
//! \param ulBase specifies the SSI module base address.
//! \param ulData is the data to be transmitted over the SSI interface.
//!
//! This function places the supplied data into the transmit FIFO of the
//! specified SSI module.  If there is no space available in the transmit FIFO,
//! this function waits until there is space available before returning.
//!
//! \note The upper 32 - N bits of \e ulData are discarded by the hardware,
//! where N is the data width as configured by SSIConfigSetExpClk().  For
//! example, if the interface is configured for 8-bit data width, the upper 24
//! bits of \e ulData are discarded.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDataPut(unsigned long ulBase, unsigned long ulData)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));
    ASSERT((ulData & (0xfffffffe << (HWREG(ulBase + SSI_O_CR0) &
                                     SSI_CR0_DSS_M))) == 0);

    //
    // Wait until there is space.
    //
    while(!(HWREG(ulBase + SSI_O_SR) & SSI_SR_TNF))
    {
    }

    //
    // Write the data to the SSI.
    //
    HWREG(ulBase + SSI_O_DR) = ulData;
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO.
//!
//! \param ulBase specifies the SSI module base address.
//! \param ulData is the data to be transmitted over the SSI interface.
//!
//! This function places the supplied data into the transmit FIFO of the
//! specified SSI module.  If there is no space in the FIFO, then this function
//! returns a zero.
//!
//! This function replaces the original SSIDataNonBlockingPut() API and
//! performs the same actions.  A macro is provided in <tt>ssi.h</tt> to map
//! the original API to this API.
//!
//! \note The upper 32 - N bits of \e ulData are discarded by the hardware,
//! where N is the data width as configured by SSIConfigSetExpClk().  For
//! example, if the interface is configured for 8-bit data width, the upper 24
//! bits of \e ulData are discarded.
//!
//! \return Returns the number of elements written to the SSI transmit FIFO.
//
//*****************************************************************************
long
SSIDataPutNonBlocking(unsigned long ulBase, unsigned long ulData)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));
    ASSERT((ulData & (0xfffffffe << (HWREG(ulBase + SSI_O_CR0) &
                                     SSI_CR0_DSS_M))) == 0);

    //
    // Check for space to write.
    //
    if(HWREG(ulBase + SSI_O_SR) & SSI_SR_TNF)
    {
        HWREG(ulBase + SSI_O_DR) = ulData;
        return(1);
    }
    else
    {
        return(0);
    }
}

//*****************************************************************************
//
//! Gets a data element from the SSI receive FIFO.
//!
//! \param ulBase specifies the SSI module base address.
//! \param pulData is a pointer to a storage location for data that was
//! received over the SSI interface.
//!
//! This function gets received data from the receive FIFO of the specified
//! SSI module and places that data into the location specified by the
//! \e pulData parameter.  If there is no data available, this function waits
//! until data is received before returning.
//!
//! \note Only the lower N bits of the value written to \e pulData contain
//! valid data, where N is the data width as configured by
//! SSIConfigSetExpClk().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to \e pulData
//! contain valid data.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDataGet(unsigned long ulBase, unsigned long *pulData)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Wait until there is data to be read.
    //
    while(!(HWREG(ulBase + SSI_O_SR) & SSI_SR_RNE))
    {
    }

    //
    // Read data from SSI.
    //
    *pulData = HWREG(ulBase + SSI_O_DR);
}

//*****************************************************************************
//
//! Gets a data element from the SSI receive FIFO.
//!
//! \param ulBase specifies the SSI module base address.
//! \param pulData is a pointer to a storage location for data that was
//! received over the SSI interface.
//!
//! This function gets received data from the receive FIFO of the specified SSI
//! module and places that data into the location specified by the \e ulData
//! parameter.  If there is no data in the FIFO, then this function returns a
//! zero.
//!
//! This function replaces the original SSIDataNonBlockingGet() API and
//! performs the same actions.  A macro is provided in <tt>ssi.h</tt> to map
//! the original API to this API.
//!
//! \note Only the lower N bits of the value written to \e pulData contain
//! valid data, where N is the data width as configured by
//! SSIConfigSetExpClk().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to \e pulData
//! contain valid data.
//!
//! \return Returns the number of elements read from the SSI receive FIFO.
//
//*****************************************************************************
long
SSIDataGetNonBlocking(unsigned long ulBase, unsigned long *pulData)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Check for data to read.
    //
    if(HWREG(ulBase + SSI_O_SR) & SSI_SR_RNE)
    {
        *pulData = HWREG(ulBase + SSI_O_DR);
        return(1);
    }
    else
    {
        return(0);
    }
}

//*****************************************************************************
//
//! Enables SSI DMA operation.
//!
//! \param ulBase is the base address of the SSI port.
//! \param ulDMAFlags is a bit mask of the DMA features to enable.
//!
//! This function enables the specified SSI DMA features.  The SSI can be
//! configured to use DMA for transmit and/or receive data transfers.
//! The \e ulDMAFlags parameter is the logical OR of any of the following
//! values:
//!
//! - SSI_DMA_RX - enable DMA for receive
//! - SSI_DMA_TX - enable DMA for transmit
//!
//! \note The uDMA controller must also be set up before DMA can be used
//! with the SSI.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDMAEnable(unsigned long ulBase, unsigned long ulDMAFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Set the requested bits in the SSI DMA control register.
    //
    HWREG(ulBase + SSI_O_DMACTL) |= ulDMAFlags;
}

//*****************************************************************************
//
//! Disables SSI DMA operation.
//!
//! \param ulBase is the base address of the SSI port.
//! \param ulDMAFlags is a bit mask of the DMA features to disable.
//!
//! This function is used to disable SSI DMA features that were enabled
//! by SSIDMAEnable().  The specified SSI DMA features are disabled.  The
//! \e ulDMAFlags parameter is the logical OR of any of the following values:
//!
//! - SSI_DMA_RX - disable DMA for receive
//! - SSI_DMA_TX - disable DMA for transmit
//!
//! \return None.
//
//*****************************************************************************
void
SSIDMADisable(unsigned long ulBase, unsigned long ulDMAFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Clear the requested bits in the SSI DMA control register.
    //
    HWREG(ulBase + SSI_O_DMACTL) &= ~ulDMAFlags;
}

//*****************************************************************************
//
//! Determines whether the SSI transmitter is busy or not.
//!
//! \param ulBase is the base address of the SSI port.
//!
//! This function allows the caller to determine whether all transmitted bytes
//! have cleared the transmitter hardware.  If \b false is returned, then the
//! transmit FIFO is empty and all bits of the last transmitted word have left
//! the hardware shift register.
//!
//! \return Returns \b true if the SSI is transmitting or \b false if all
//! transmissions are complete.
//
//*****************************************************************************
tBoolean
SSIBusy(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Determine if the SSI is busy.
    //
    return((HWREG(ulBase + SSI_O_SR) & SSI_SR_BSY) ? true : false);
}

//*****************************************************************************
//
//! Sets the data clock source for the specified SSI peripheral.
//!
//! \param ulBase is the base address of the SSI port.
//! \param ulSource is the baud clock source for the SSI.
//!
//! This function allows the baud clock source for the SSI to be selected.
//! The possible clock source are the system clock (\b SSI_CLOCK_SYSTEM) or
//! the precision internal oscillator (\b SSI_CLOCK_PIOSC).
//!
//! Changing the baud clock source changes the data rate generated by the
//! SSI.  Therefore, the data rate should be reconfigured after any change to
//! the SSI clock source.
//!
//! \note The ability to specify the SSI baud clock source varies with the
//! Stellaris part and SSI in use.  Please consult the data sheet for the part
//! in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SSIClockSourceSet(unsigned long ulBase, unsigned long ulSource)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));
    ASSERT((ulSource == SSI_CLOCK_SYSTEM) || (ulSource == SSI_CLOCK_PIOSC));

    //
    // Set the SSI clock source.
    //
    HWREG(ulBase + SSI_O_CC) = ulSource;
}

//*****************************************************************************
//
//! Gets the data clock source for the specified SSI peripheral.
//!
//! \param ulBase is the base address of the SSI port.
//!
//! This function returns the data clock source for the specified SSI.  The
//! possible data clock source are the system clock (\b SSI_CLOCK_SYSTEM) or
//! the precision internal oscillator (\b SSI_CLOCK_PIOSC).
//!
//! \note The ability to specify the SSI data clock source varies with the
//! Stellaris part and SSI in use.  Please consult the data sheet for the part
//! in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
unsigned long
SSIClockSourceGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ulBase));

    //
    // Return the SSI clock source.
    //
    return(HWREG(ulBase + SSI_O_CC));
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
