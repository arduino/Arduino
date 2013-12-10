//*****************************************************************************
//
// ssi.c - Driver for Synchronous Serial Interface.
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
//! \addtogroup ssi_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/ssi.h"

//*****************************************************************************
//
// A mapping of timer base address to interrupt number.
//
//*****************************************************************************
static const uint32_t g_ppui32SSIIntMap[][2] =
{
    { SSI0_BASE, INT_SSI0_BLIZZARD },
    { SSI1_BASE, INT_SSI1_BLIZZARD },
    { SSI2_BASE, INT_SSI2_BLIZZARD },
    { SSI3_BASE, INT_SSI3_BLIZZARD },
};
static const uint_fast8_t g_ui8SSIIntMapRows =
    sizeof(g_ppui32SSIIntMap) / sizeof(g_ppui32SSIIntMap[0]);

static const uint32_t g_ppui32SSIIntMapSnowflake[][2] =
{
    { SSI0_BASE, INT_SSI0_SNOWFLAKE },
    { SSI1_BASE, INT_SSI1_SNOWFLAKE },
    { SSI2_BASE, INT_SSI2_SNOWFLAKE },
    { SSI3_BASE, INT_SSI3_SNOWFLAKE },
};
static const uint_fast8_t g_ui8SSIIntMapSnowflakeRows =
    sizeof(g_ppui32SSIIntMapSnowflake) / sizeof(g_ppui32SSIIntMapSnowflake[0]);

//*****************************************************************************
//
//! \internal
//! Checks an SSI base address.
//!
//! \param ui32Base specifies the SSI module base address.
//!
//! This function determines if a SSI module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_SSIBaseValid(uint32_t ui32Base)
{
    return((ui32Base == SSI0_BASE) || (ui32Base == SSI1_BASE) ||
           (ui32Base == SSI2_BASE) || (ui32Base == SSI3_BASE));
}
#endif

//*****************************************************************************
//
//! Returns the interrupt number of SSI module .
//!
//! \param ui32Base is the base address of the SSI module.
//!
//! This function returns the interrupt number for the SSI module with the base
//! address passed in the \e ui32Base parameter.
//!
//! \return Returns an SSI interrupt number, or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint32_t
_SSIIntNumberGet(uint32_t ui32Base)
{
    uint_fast8_t ui8Idx, ui8Rows;
    const uint32_t (*ppui32SSIIntMap)[2];

    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    ppui32SSIIntMap = g_ppui32SSIIntMap;
    ui8Rows = g_ui8SSIIntMapRows;

    if(CLASS_IS_SNOWFLAKE)
    {
        ppui32SSIIntMap = g_ppui32SSIIntMapSnowflake;
        ui8Rows = g_ui8SSIIntMapSnowflakeRows;
    }

    //
    // Loop through the table that maps SSI base addresses to interrupt
    // numbers.
    //
    for(ui8Idx = 0; ui8Idx < ui8Rows; ui8Idx++)
    {
        //
        // See if this base address matches.
        //
        if(ppui32SSIIntMap[ui8Idx][0] == ui32Base)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(ppui32SSIIntMap[ui8Idx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(0);
}

//*****************************************************************************
//
//! Configures the synchronous serial interface.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32SSIClk is the rate of the clock supplied to the SSI module.
//! \param ui32Protocol specifies the data transfer protocol.
//! \param ui32Mode specifies the mode of operation.
//! \param ui32BitRate specifies the clock rate.
//! \param ui32DataWidth specifies number of bits transferred per frame.
//!
//! This function configures the synchronous serial interface.  It sets
//! the SSI protocol, mode of operation, bit rate, and data width.
//!
//! The \e ui32Protocol parameter defines the data frame format.  The
//! \e ui32Protocol parameter can be one of the following values:
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
//! The \e ui32Mode parameter defines the operating mode of the SSI module.
//! The SSI module can operate as a master or slave; if it is a slave, the SSI
//! can be configured to disable output on its serial output line.  The
//! \e ui32Mode parameter can be one of the following values:
//! \b SSI_MODE_MASTER, \b SSI_MODE_SLAVE, or \b SSI_MODE_SLAVE_OD.
//!
//! The \e ui32BitRate parameter defines the bit rate for the SSI.  This bit
//! rate must satisfy the following clock ratio criteria:
//!
//! - FSSI >= 2 * bit rate (master mode); this speed cannot exceed 25 MHz.
//! - FSSI >= 12 * bit rate or 6 * bit rate (slave modes), depending on the
//! capability of the specific microcontroller
//!
//! where FSSI is the frequency of the clock supplied to the SSI module.
//!
//! The \e ui32DataWidth parameter defines the width of the data transfers and
//! can be a value between 4 and 16, inclusive.
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
//!
//! \return None.
//
//*****************************************************************************
void
SSIConfigSetExpClk(uint32_t ui32Base, uint32_t ui32SSIClk,
                   uint32_t ui32Protocol, uint32_t ui32Mode,
                   uint32_t ui32BitRate, uint32_t ui32DataWidth)
{
    uint32_t ui32MaxBitRate;
    uint32_t ui32RegVal;
    uint32_t ui32PreDiv;
    uint32_t ui32SCR;
    uint32_t ui32SPH_SPO;

    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Protocol == SSI_FRF_MOTO_MODE_0) ||
           (ui32Protocol == SSI_FRF_MOTO_MODE_1) ||
           (ui32Protocol == SSI_FRF_MOTO_MODE_2) ||
           (ui32Protocol == SSI_FRF_MOTO_MODE_3) ||
           (ui32Protocol == SSI_FRF_TI) ||
           (ui32Protocol == SSI_FRF_NMW));
    ASSERT((ui32Mode == SSI_MODE_MASTER) ||
           (ui32Mode == SSI_MODE_SLAVE) ||
           (ui32Mode == SSI_MODE_SLAVE_OD));
    ASSERT(((ui32Mode == SSI_MODE_MASTER) &&
            (ui32BitRate <= (ui32SSIClk / 2))) ||
           ((ui32Mode != SSI_MODE_MASTER) &&
            (ui32BitRate <= (ui32SSIClk / 12))));
    ASSERT((ui32SSIClk / ui32BitRate) <= (254 * 256));
    ASSERT((ui32DataWidth >= 4) && (ui32DataWidth <= 16));

    //
    // Set the mode.
    //
    ui32RegVal = (ui32Mode == SSI_MODE_SLAVE_OD) ? SSI_CR1_SOD : 0;
    ui32RegVal |= (ui32Mode == SSI_MODE_MASTER) ? 0 : SSI_CR1_MS;
    HWREG(ui32Base + SSI_O_CR1) = ui32RegVal;

    //
    // Set the clock predivider.
    //
    ui32MaxBitRate = ui32SSIClk / ui32BitRate;
    ui32PreDiv = 0;
    do
    {
        ui32PreDiv += 2;
        ui32SCR = (ui32MaxBitRate / ui32PreDiv) - 1;
    }
    while(ui32SCR > 255);
    HWREG(ui32Base + SSI_O_CPSR) = ui32PreDiv;

    //
    // Set protocol and clock rate.
    //
    ui32SPH_SPO = (ui32Protocol & 3) << 6;
    ui32Protocol &= SSI_CR0_FRF_M;
    ui32RegVal = (ui32SCR << 8) | ui32SPH_SPO | ui32Protocol |
                 (ui32DataWidth - 1);
    HWREG(ui32Base + SSI_O_CR0) = ui32RegVal;
}

//*****************************************************************************
//
//! Enables the synchronous serial interface.
//!
//! \param ui32Base specifies the SSI module base address.
//!
//! This function enables operation of the synchronous serial interface.  The
//! synchronous serial interface must be configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
void
SSIEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ui32Base + SSI_O_CR1) |= SSI_CR1_SSE;
}

//*****************************************************************************
//
//! Disables the synchronous serial interface.
//!
//! \param ui32Base specifies the SSI module base address.
//!
//! This function disables operation of the synchronous serial interface.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ui32Base + SSI_O_CR1) &= ~(SSI_CR1_SSE);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the synchronous serial interface.
//!
//! \param ui32Base specifies the SSI module base address.
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
SSIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the SSI port.
    //
    ui32Int = _SSIIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the synchronous serial interface interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the synchronous serial interface.
//!
//! \param ui32Base specifies the SSI module base address.
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
SSIIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the SSI port.
    //
    ui32Int = _SSIIntNumberGet(ui32Base);

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
//! Enables individual SSI interrupt sources.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated SSI interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.  The \e ui32IntFlags
//! parameter can be any of the \b SSI_TXFF, \b SSI_RXFF, \b SSI_RXTO, or
//! \b SSI_RXOR values.
//!
//! \return None.
//
//*****************************************************************************
void
SSIIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Enable the specified interrupts.
    //
    HWREG(ui32Base + SSI_O_IM) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables individual SSI interrupt sources.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated SSI interrupt sources.  The
//! \e ui32IntFlags parameter can be any of the \b SSI_TXFF, \b SSI_RXFF,
//!  \b SSI_RXTO, or \b SSI_RXOR values.
//!
//! \return None.
//
//*****************************************************************************
void
SSIIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Disable the specified interrupts.
    //
    HWREG(ui32Base + SSI_O_IM) &= ~(ui32IntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ui32Base specifies the SSI module base address.
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
uint32_t
SSIIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ui32Base + SSI_O_MIS));
    }
    else
    {
        return(HWREG(ui32Base + SSI_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears SSI interrupt sources.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! This function clears the specified SSI interrupt sources so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep the interrupts from being triggered again immediately upon exit.  The
//! \e ui32IntFlags parameter can consist of either or both the \b SSI_RXTO and
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
SSIIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ui32Base + SSI_O_ICR) = ui32IntFlags;
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32Data is the data to be transmitted over the SSI interface.
//!
//! This function places the supplied data into the transmit FIFO of the
//! specified SSI module.  If there is no space available in the transmit FIFO,
//! this function waits until there is space available before returning.
//!
//! \note The upper 32 - N bits of \e ui32Data are discarded by the hardware,
//! where N is the data width as configured by SSIConfigSetExpClk().  For
//! example, if the interface is configured for 8-bit data width, the upper 24
//! bits of \e ui32Data are discarded.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDataPut(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Data & (0xfffffffe << (HWREG(ui32Base + SSI_O_CR0) &
                                       SSI_CR0_DSS_M))) == 0);

    //
    // Wait until there is space.
    //
    while(!(HWREG(ui32Base + SSI_O_SR) & SSI_SR_TNF))
    {
    }

    //
    // Write the data to the SSI.
    //
    HWREG(ui32Base + SSI_O_DR) = ui32Data;
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32Data is the data to be transmitted over the SSI interface.
//!
//! This function places the supplied data into the transmit FIFO of the
//! specified SSI module.  If there is no space in the FIFO, then this function
//! returns a zero.
//!
//! \note The upper 32 - N bits of \e ui32Data are discarded by the hardware,
//! where N is the data width as configured by SSIConfigSetExpClk().  For
//! example, if the interface is configured for 8-bit data width, the upper 24
//! bits of \e ui32Data are discarded.
//!
//! \return Returns the number of elements written to the SSI transmit FIFO.
//
//*****************************************************************************
int32_t
SSIDataPutNonBlocking(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Data & (0xfffffffe << (HWREG(ui32Base + SSI_O_CR0) &
                                       SSI_CR0_DSS_M))) == 0);

    //
    // Check for space to write.
    //
    if(HWREG(ui32Base + SSI_O_SR) & SSI_SR_TNF)
    {
        HWREG(ui32Base + SSI_O_DR) = ui32Data;
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
//! \param ui32Base specifies the SSI module base address.
//! \param pui32Data is a pointer to a storage location for data that was
//! received over the SSI interface.
//!
//! This function gets received data from the receive FIFO of the specified
//! SSI module and places that data into the location specified by the
//! \e pui32Data parameter.  If there is no data available, this function waits
//! until data is received before returning.
//!
//! \note Only the lower N bits of the value written to \e pui32Data contain
//! valid data, where N is the data width as configured by
//! SSIConfigSetExpClk().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to
//! \e pui32Data contain valid data.
//!
//! \return None.
//
//*****************************************************************************
void
SSIDataGet(uint32_t ui32Base, uint32_t *pui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Wait until there is data to be read.
    //
    while(!(HWREG(ui32Base + SSI_O_SR) & SSI_SR_RNE))
    {
    }

    //
    // Read data from SSI.
    //
    *pui32Data = HWREG(ui32Base + SSI_O_DR);
}

//*****************************************************************************
//
//! Gets a data element from the SSI receive FIFO.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param pui32Data is a pointer to a storage location for data that was
//! received over the SSI interface.
//!
//! This function gets received data from the receive FIFO of the specified SSI
//! module and places that data into the location specified by the \e ui32Data
//! parameter.  If there is no data in the FIFO, then this function returns a
//! zero.
//!
//! \note Only the lower N bits of the value written to \e pui32Data contain
//! valid data, where N is the data width as configured by
//! SSIConfigSetExpClk().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to
//! \e pui32Data contain valid data.
//!
//! \return Returns the number of elements read from the SSI receive FIFO.
//
//*****************************************************************************
int32_t
SSIDataGetNonBlocking(uint32_t ui32Base, uint32_t *pui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Check for data to read.
    //
    if(HWREG(ui32Base + SSI_O_SR) & SSI_SR_RNE)
    {
        *pui32Data = HWREG(ui32Base + SSI_O_DR);
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
//! \param ui32Base is the base address of the SSI port.
//! \param ui32DMAFlags is a bit mask of the DMA features to enable.
//!
//! This function enables the specified SSI DMA features.  The SSI can be
//! configured to use DMA for transmit and/or receive data transfers.
//! The \e ui32DMAFlags parameter is the logical OR of any of the following
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
SSIDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Set the requested bits in the SSI DMA control register.
    //
    HWREG(ui32Base + SSI_O_DMACTL) |= ui32DMAFlags;
}

//*****************************************************************************
//
//! Disables SSI DMA operation.
//!
//! \param ui32Base is the base address of the SSI port.
//! \param ui32DMAFlags is a bit mask of the DMA features to disable.
//!
//! This function is used to disable SSI DMA features that were enabled
//! by SSIDMAEnable().  The specified SSI DMA features are disabled.  The
//! \e ui32DMAFlags parameter is the logical OR of any of the following values:
//!
//! - SSI_DMA_RX - disable DMA for receive
//! - SSI_DMA_TX - disable DMA for transmit
//!
//! \return None.
//
//*****************************************************************************
void
SSIDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Clear the requested bits in the SSI DMA control register.
    //
    HWREG(ui32Base + SSI_O_DMACTL) &= ~ui32DMAFlags;
}

//*****************************************************************************
//
//! Determines whether the SSI transmitter is busy or not.
//!
//! \param ui32Base is the base address of the SSI port.
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
bool
SSIBusy(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Determine if the SSI is busy.
    //
    return((HWREG(ui32Base + SSI_O_SR) & SSI_SR_BSY) ? true : false);
}

//*****************************************************************************
//
//! Sets the data clock source for the specified SSI peripheral.
//!
//! \param ui32Base is the base address of the SSI port.
//! \param ui32Source is the baud clock source for the SSI.
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
//! Tiva part and SSI in use.  Please consult the data sheet for the part
//! in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SSIClockSourceSet(uint32_t ui32Base, uint32_t ui32Source)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Source == SSI_CLOCK_SYSTEM) ||
           (ui32Source == SSI_CLOCK_PIOSC));

    //
    // Set the SSI clock source.
    //
    HWREG(ui32Base + SSI_O_CC) = ui32Source;
}

//*****************************************************************************
//
//! Gets the data clock source for the specified SSI peripheral.
//!
//! \param ui32Base is the base address of the SSI port.
//!
//! This function returns the data clock source for the specified SSI.
//!
//! \note The ability to specify the SSI data clock source varies with the
//! Tiva part and SSI in use.  Please consult the data sheet for the part
//! in use to determine whether this support is available.
//!
//! \return Returns the current clock source, which will be either
//! \b SSI_CLOCK_SYSTEM or \b SSI_CLOCK_PIOSC.
//
//*****************************************************************************
uint32_t
SSIClockSourceGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Return the SSI clock source.
    //
    return(HWREG(ui32Base + SSI_O_CC));
}

//*****************************************************************************
//
//! Selects the advanced mode of operation for the SSI module.
//!
//! \param ui32Base is the base address of the SSI port.
//! \param ui32Mode is the mode of operation to use.
//!
//! This function selects the mode of operation for the SSI module, which is
//! needed when using the advanced operation modes (Bi- or Quad-SPI).  One of
//! the following modes can be selected:
//!
//! - \b SSI_ADV_MODE_LEGACY - Disables the advanced modes of operation,
//!   resulting in legacy, or backwards-compatible, operation.  When this mode
//!   is selected, it is not valid to switch to Bi- or Quad-SPI operation.
//!   This mode is the default.
//! - \b SSI_ADV_MODE_WRITE - The advanced mode of operation where data is only
//!   written to the slave; any data clocked in via the \b SSIRx pin is thrown
//!   away (instead of being placed into the SSI Rx FIFO).
//! - \b SSI_ADV_MODE_READ_WRITE - The advanced mode of operation where data is
//!   written to and read from the slave; this mode is the same as
//!   \b SSI_ADV_MODE_LEGACY but allows transitions to Bi- or Quad-SPI
//!   operation.
//! - \b SSI_ADV_MODE_BI_READ - The advanced mode of operation where data is
//!   read from the slave in Bi-SPI mode, with two bits of data read on every
//!   SSI clock.
//! - \b SSI_ADV_MODE_BI_WRITE - The advanced mode of operation where data is
//!   written to the slave in Bi-SPI mode, with two bits of data written on
//!   every SSI clock.
//! - \b SSI_ADV_MODE_QUAD_READ - The advanced mode of operation where data is
//!   read from the slave in Quad-SPI mode, with four bits of data read on
//!   every SSI clock.
//! - \b SSI_ADV_MODE_QUAD_WRITE - The advanced mode of operation where data is
//!   written to the slave in Quad-SPI mode, with four bits of data written on
//!   every SSI clock.
//!
//! The following mode transitions are valid (other transitions produce
//! undefined results):
//!
//! \verbatim
//! +----------+-------------------------------------------------------------+
//! |FROM      |                             TO                              |
//! |          |Legacy|Write|Read Write|Bi Read|Bi Write|Quad Read|Quad Write|
//! +----------+------+-----+----------+-------+--------+---------+----------+
//! |Legacy    | yes  | yes |   yes    |       |        |         |          |
//! |Write     | yes  | yes |   yes    |  yes  |  yes   |   yes   |   yes    |
//! |Read/Write| yes  | yes |   yes    |  yes  |  yes   |   yes   |   yes    |
//! |Bi Read   |      | yes |   yes    |  yes  |  yes   |         |          |
//! |Bi write  |      | yes |   yes    |  yes  |  yes   |         |          |
//! |Quad read |      | yes |   yes    |       |        |   yes   |   yes    |
//! |Quad write|      | yes |   yes    |       |        |   yes   |   yes    |
//! +----------+------+-----+----------+-------+--------+---------+----------+
//! \endverbatim
//!
//! When using an advanced mode of operation, the SSI module must have been
//! configured for eight data bits and the \b SSI_FRF_MOTO_MODE_0 protocol.
//! The advanced mode operation that is selected applies only to data newly
//! written into the FIFO; the data that is already present in the FIFO is
//! handled using the advanced mode of operation in effect when that data was
//! written.
//!
//! Switching into and out of legacy mode should only occur when the FIFO is
//! empty.
//!
//! \note The availability of the advanced mode of SSI operation varies with
//! the Tiva part and SSI in use.  Please consult the data sheet for the
//! part in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SSIAdvModeSet(uint32_t ui32Base, uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Mode == SSI_ADV_MODE_LEGACY) ||
           (ui32Mode == SSI_ADV_MODE_WRITE) ||
           (ui32Mode == SSI_ADV_MODE_READ_WRITE) ||
           (ui32Mode == SSI_ADV_MODE_BI_READ) ||
           (ui32Mode == SSI_ADV_MODE_BI_WRITE) ||
           (ui32Mode == SSI_ADV_MODE_QUAD_READ) ||
           (ui32Mode == SSI_ADV_MODE_QUAD_WRITE));

    //
    // Set the SSI mode of operation.
    //
    HWREG(ui32Base + SSI_O_CR1) =
        ((HWREG(ui32Base + SSI_O_CR1) & ~(SSI_CR1_DIR | SSI_CR1_MODE_M)) |
         ui32Mode);
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO as the end of a frame.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32Data is the data to be transmitted over the SSI interface.
//!
//! This function places the supplied data into the transmit FIFO of the
//! specified SSI module, marking it as the end of a frame.  If there is no
//! space available in the transmit FIFO, this function waits until there is
//! space available before returning.  After this byte is transmitted by the
//! SSI module, the FSS signal de-asserts for at least one SSI clock.
//!
//! \note The upper 24 bits of \e ui32Data are discarded by the hardware.
//!
//! \note The availability of the advanced mode of SSI operation varies with
//! the Tiva part and SSI in use.  Please consult the data sheet for the
//! part in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SSIAdvDataPutFrameEnd(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Data & 0xff) == 0);

    //
    // Wait until there is space.
    //
    while(!(HWREG(ui32Base + SSI_O_SR) & SSI_SR_TNF))
    {
    }

    //
    // Write the data to the SSI.
    //
    HWREG(ui32Base + SSI_O_CR1) |= SSI_CR1_EOM;
    HWREG(ui32Base + SSI_O_DR) = ui32Data;
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO as the end of a frame.
//!
//! \param ui32Base specifies the SSI module base address.
//! \param ui32Data is the data to be transmitted over the SSI interface.
//!
//! This function places the supplied data into the transmit FIFO of the
//! specified SSI module, marking it as the end of a frame.  After this byte is
//! transmitted by the SSI module, the FSS signal de-asserts for at least one
//! SSI clock.  If there is no space in the FIFO, then this function returns a
//! zero.
//!
//! \note The upper 24 bits of \e ui32Data are discarded by the hardware.
//!
//! \note The availability of the advanced mode of SSI operation varies with
//! the Tiva part and SSI in use.  Please consult the data sheet for the
//! part in use to determine whether this support is available.
//!
//! \return Returns the number of elements written to the SSI transmit FIFO.
//
//*****************************************************************************
int32_t
SSIAdvDataPutFrameEndNonBlocking(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));
    ASSERT((ui32Data & 0xff) == 0);

    //
    // Check for space to write.
    //
    if(HWREG(ui32Base + SSI_O_SR) & SSI_SR_TNF)
    {
        HWREG(ui32Base + SSI_O_CR1) |= SSI_CR1_EOM;
        HWREG(ui32Base + SSI_O_DR) = ui32Data;
        return(1);
    }
    else
    {
        return(0);
    }
}

//*****************************************************************************
//
//! Configures the SSI advanced mode to hold \b SSIFss during the full
//! transfer.
//!
//! \param ui32Base is the base address of the SSI port.
//!
//! This function configures the SSI module to de-assert the \b SSIFss signal
//! during the entire data transfer when using one of the advanced modes
//! (instead of briefly de-asserting it after every byte).  When using this
//! mode, \b SSIFss can be directly controlled via SSIAdvDataPutFrameEnd() and
//! SSIAdvDataPutFrameEndNonBlocking().
//!
//! \note The availability of the advanced mode of SSI operation varies with
//! the Tiva part and SSI in use.  Please consult the data sheet for the
//! part in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SSIAdvFrameHoldEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Set the hold frame bit.
    //
    HWREG(ui32Base + SSI_O_CR1) |= SSI_CR1_FSSHLDFRM;
}

//*****************************************************************************
//
//! Configures the SSI advanced mode to de-assert \b SSIFss after every byte
//! transfer.
//!
//! \param ui32Base is the base address of the SSI port.
//!
//! This function configures the SSI module to de-assert the \b SSIFss signal
//! for one SSI clock cycle after every byte is transferred using one of the
//! advanced modes (instead of leaving it asserted for the entire transfer).
//! This mode is the default operation.
//!
//! \note The availability of the advanced mode of SSI operation varies with
//! the Tiva part and SSI in use.  Please consult the data sheet for the
//! part in use to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SSIAdvFrameHoldDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_SSIBaseValid(ui32Base));

    //
    // Clear the hold frame bit.
    //
    HWREG(ui32Base + SSI_O_CR1) &= ~(SSI_CR1_FSSHLDFRM);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
