/******************************************************************************
*  Filename:       ssi.c
*  Revised:        2015-11-16 19:41:47 +0100 (Mon, 16 Nov 2015)
*  Revision:       45094
*
*  Description:    Driver for Synchronous Serial Interface
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

#include <driverlib/ssi.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #undef  SSIConfigSetExpClk
    #define SSIConfigSetExpClk              NOROM_SSIConfigSetExpClk
    #undef  SSIDataPut
    #define SSIDataPut                      NOROM_SSIDataPut
    #undef  SSIDataPutNonBlocking
    #define SSIDataPutNonBlocking           NOROM_SSIDataPutNonBlocking
    #undef  SSIDataGet
    #define SSIDataGet                      NOROM_SSIDataGet
    #undef  SSIDataGetNonBlocking
    #define SSIDataGetNonBlocking           NOROM_SSIDataGetNonBlocking
    #undef  SSIIntRegister
    #define SSIIntRegister                  NOROM_SSIIntRegister
    #undef  SSIIntUnregister
    #define SSIIntUnregister                NOROM_SSIIntUnregister
#endif

//*****************************************************************************
//
//! Configures the synchronous serial port
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
    ASSERT(SSIBaseValid(ui32Base));
    ASSERT((ui32Protocol == SSI_FRF_MOTO_MODE_0) ||
           (ui32Protocol == SSI_FRF_MOTO_MODE_1) ||
           (ui32Protocol == SSI_FRF_MOTO_MODE_2) ||
           (ui32Protocol == SSI_FRF_MOTO_MODE_3) ||
           (ui32Protocol == SSI_FRF_TI) ||
           (ui32Protocol == SSI_FRF_NMW));
    ASSERT((ui32Mode == SSI_MODE_MASTER) ||
           (ui32Mode == SSI_MODE_SLAVE) ||
           (ui32Mode == SSI_MODE_SLAVE_OD));
    ASSERT(((ui32Mode == SSI_MODE_MASTER) && (ui32BitRate <= (ui32SSIClk / 2))) ||
           ((ui32Mode != SSI_MODE_MASTER) && (ui32BitRate <= (ui32SSIClk / 12))));
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
    ui32RegVal = (ui32SCR << 8) | ui32SPH_SPO | ui32Protocol | (ui32DataWidth - 1);
    HWREG(ui32Base + SSI_O_CR0) = ui32RegVal;
}

//*****************************************************************************
//
//! Puts a data element into the SSI transmit FIFO
//
//*****************************************************************************
int32_t
SSIDataPutNonBlocking(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ui32Base));
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
//! Puts a data element into the SSI transmit FIFO
//
//*****************************************************************************
void
SSIDataPut(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ui32Base));
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
//! Gets a data element from the SSI receive FIFO
//
//*****************************************************************************
void
SSIDataGet(uint32_t ui32Base, uint32_t *pui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ui32Base));

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
//! Gets a data element from the SSI receive FIFO
//!
//! \param ui32Base specifies the SSI module base address.
//! \param pui32Data is a pointer to a storage location for data that was
//! received over the SSI interface.
//!
//! This function gets received data from the receive FIFO of the specified SSI
//! module and places that data into the location specified by the \e ui32Data
//! parameter. If there is no data in the FIFO, then this function  returns a
//! zero.
//!
//! \note Only the lower N bits of the value written to \e pui32Data contain
//! valid data, where N is the data width as configured by \sa
//! SSIConfigSetExpClk(). For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to \e pui32Data
//! contain valid data.
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
    ASSERT(SSIBaseValid(ui32Base));

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
//! Registers an interrupt handler for the synchronous serial port
//!
//! \param ui32Base specifies the SSI module base address.
//! \param pfnHandler is a pointer to the function to be called when the
//! synchronous serial port interrupt occurs.
//!
//! This sets the handler to be called when an SSI interrupt
//! occurs. This will enable the global interrupt in the interrupt controller;
//! specific SSI interrupts must be enabled via SSIIntEnable(). If necessary,
//! it is the interrupt handler's responsibility to clear the interrupt source
//! via SSIIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None
//
//*****************************************************************************
void
SSIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the SSI port.
    //
    ui32Int = (ui32Base == SSI0_BASE) ? INT_SSI0_COMB : INT_SSI1_COMB;

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the synchronous serial port interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the synchronous serial port
//!
//! \param ui32Base specifies the SSI module base address.
//!
//! This function will clear the handler to be called when a SSI
//! interrupt occurs. This will also mask off the interrupt in the interrupt
//! controller so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None
//
//*****************************************************************************
void
SSIIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(SSIBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the SSI port.
    //
    ui32Int = (ui32Base == SSI0_BASE) ? INT_SSI0_COMB : INT_SSI1_COMB;

    //
    // Disable the interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}
