//*****************************************************************************
//
// i2c.c - Driver for Inter-IC (I2C) bus block.
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup I2C_api
//! @{
//
//*****************************************************************************

#include "inc/hw_types.h"
#include "inc/hw_i2c.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "debug.h"
#include "i2c.h"
#include "interrupt.h"


//*****************************************************************************
//
//! \internal
//! Checks a I2C master base address.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function determines if a I2C master base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
I2CMasterBaseValid(unsigned long ulBase)
{
    return((ulBase == I2C_MASTER_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Gets the I2C interrupt number.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! Given a I2C base address, returns the corresponding interrupt number.
//!
//! \return Returns a I2C interrupt number, or -1 if \e ulBase is invalid.
//
//*****************************************************************************
static long
I2CIntNumberGet(unsigned long ulBase)
{
    return((ulBase==I2C_MASTER_BASE)?INT_I2CS0:-1);
}

//*****************************************************************************
//
//! Initializes the I2C Master block.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ulI2CClk is the rate of the clock supplied to the I2C module.
//! \param bFast set up for fast data transfers
//!
//! This function initializes operation of the I2C Master block.  Upon
//! successful initialization of the I2C block, this function will have set the
//! bus speed for the master, and will have enabled the I2C Master block.
//!
//! If the parameter \e bFast is \b true, then the master block will be set up
//! to transfer data at 400 kbps; otherwise, it will be set up to transfer data
//! at 100 kbps.
//!
//! The peripheral clock will be the same as the processor clock.  This will be
//! the value returned by SysCtlClockGet(), or it can be explicitly hard coded
//! if it is constant and known (to save the code/execution overhead of a call
//! to SysCtlClockGet()).
//!
//! This function replaces the original I2CMasterInit() API and performs the
//! same actions.  A macro is provided in <tt>i2c.h</tt> to map the original
//! API to this API.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterInitExpClk(unsigned long ulBase, unsigned long ulI2CClk,
                    tBoolean bFast)
{
    unsigned long ulSCLFreq;
    unsigned long ulTPR;

    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Must enable the device before doing anything else.
    //
    I2CMasterEnable(ulBase);

    //
    // Get the desired SCL speed.
    //
    if(bFast == true)
    {
        ulSCLFreq = 400000;
    }
    else
    {
        ulSCLFreq = 100000;
    }

    //
    // Compute the clock divider that achieves the fastest speed less than or
    // equal to the desired speed.  The numerator is biased to favor a larger
    // clock divider so that the resulting clock is always less than or equal
    // to the desired clock, never greater.
    //
    ulTPR = ((ulI2CClk + (2 * 10 * ulSCLFreq) - 1) / (2 * 10 * ulSCLFreq)) - 1;
    HWREG(ulBase + I2C_O_MTPR) = ulTPR;
}

//*****************************************************************************
//
//! Initializes the I2C Master block.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulI2CClk is the rate of the clock supplied to the I2C module.
//! \param bConfgHiSpd setup High Speed Data transfer.
//! \param ulMode is one of valid speeds. Ignored if bConfHiSpd if \b true.
//!
//!
//! This function initializes operation of the I2C Master block.  Upon
//! successful initialization of the I2C block, this function will have set the
//! bus speed for the master, and will have enabled the I2C Master block.
//!
//! If the parameter \e bConfHiSpd is \b true the Master block is configured for
//! 3.33 Mbps high speed mode and last parameter \b ulMode is igmored.
//!
//! The parameter \e ulMode is one of the following
//! - \b I2C_MASTER_MODE_STD for 100 Kbps standard mode.
//! - \b I2C_MASTER_MODE_FST for 400 Kbps fast mode.
//! - \b I2C_MASTER_MODE_FPLS for 1 Mbps fast plus mode.
//!
//!
//! The peripheral clock will be the same as the processor clock.
//!
//! This function replaces the original I2CMasterInit() API and performs the
//! same actions.  A macro is provided in <tt>i2c.h</tt> to map the original
//! API to this API.
//!
//! \return None.
//
//*****************************************************************************

void
I2CMasterInitExpClkEx(unsigned long ulBase, unsigned long ulI2CClk,
                    tBoolean bConfHiSpd,unsigned long ulMode)
{
    unsigned long ulSCLFreq;
    unsigned long ulTPR;

    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Must enable the device before doing anything else.
    //
    I2CMasterEnable(ulBase);

    //
    // Get the desired SCL speed.
    //
    if(bConfHiSpd == true)
    {
        ulSCLFreq = 3330000;
    }
    else if(ulMode == I2C_MASTER_MODE_STD)
    {
        ulSCLFreq = 100000;
    }
    else if(ulMode == I2C_MASTER_MODE_FST)
    {
        ulSCLFreq = 400000;
    }
    else if(ulMode == I2C_MASTER_MODE_FPLS)
    {
        ulSCLFreq = 1000000;
    }

    //
    // Compute the clock divider that achieves the fastest speed less than or
    // equal to the desired speed.  The numerator is biased to favor a larger
    // clock divider so that the resulting clock is always less than or equal
    // to the desired clock, never greater.
    //
    if(bConfHiSpd)
    {
      ulTPR = ((ulI2CClk ) / (2 * 3 * ulSCLFreq)) - 1;
      ulTPR = ulTPR | ((1<<7));
    }
    else
    {
      ulTPR = ((ulI2CClk + (2 * 10 * ulSCLFreq) - 1) / (2 * 10 * ulSCLFreq)) - 1;
    }

    HWREG(ulBase + I2C_O_MTPR) = ulTPR;
}

//*****************************************************************************
//
//! Initializes the I2C Slave block.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ucSlaveAddr 7-bit slave address
//!
//! This function initializes operation of the I2C Slave block.  Upon
//! successful initialization of the I2C blocks, this function will have set
//! the slave address and have enabled the I2C Slave block.
//!
//! The parameter \e ucSlaveAddr is the value that will be compared against the
//! slave address sent by an I2C master.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveInit(unsigned long ulBase, unsigned char ucSlaveAddr)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Must enable the device before doing anything else.
    //
    I2CSlaveEnable(ulBase);

    //
    // Set up the slave address.
    //
    HWREG(ulBase + I2C_O_SOAR) = ucSlaveAddr;
}


//*****************************************************************************
//
//! Sets the I2C slave address.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ucAddrNum determines which slave address is set.
//! \param ucSlaveAddr 7-bit slave address
//!
//! This function writes the specified slave address.  The \e ulAddrNum field
//! dictates which slave address is configured.  For example, a value of 0
//! configures the primary address and a value of 1 the secondary.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveAddressSet(unsigned long ulBase, unsigned char ucAddrNum,
                   unsigned char ucSlaveAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));
    ASSERT(!(ucAddrNum > 1));
    ASSERT(!(ucSlaveAddr & 0x80));


    switch(ucAddrNum)
    {
        //
        // Set up the primary slave address.
        //
        case 0:
        {
            HWREG(ulBase + I2C_O_SOAR) = ucSlaveAddr;

            break;
        }

        //
        // Set up and enable the secondary slave address.
        //
        case 1:
        {
            HWREG(ulBase + I2C_O_SOAR2) = I2C_SOAR2_OAR2EN | ucSlaveAddr;

            break;
        }
    }
}

//*****************************************************************************
//
//! Enables the I2C Master block.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This will enable operation of the I2C Master block.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Enable the master block.
    //
    HWREG(ulBase + I2C_O_MCR) |= I2C_MCR_MFE;
}

//*****************************************************************************
//
//! Enables the I2C Slave block.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This will enable operation of the I2C Slave block.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(ulBase == I2C_MASTER_BASE);

    //
    // Enable the clock to the slave block.
    //
    HWREG(ulBase + I2C_O_MCR) |=
        I2C_MCR_SFE;

    //
    // Enable the slave.
    //
    HWREG(ulBase + I2C_O_SCSR) = I2C_SCSR_DA;
}

//*****************************************************************************
//
//! Disables the I2C master block.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This will disable operation of the I2C master block.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Disable the master block.
    //
    HWREG(ulBase + I2C_O_MCR) &= ~(I2C_MCR_MFE);
}

//*****************************************************************************
//
//! Disables the I2C slave block.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This will disable operation of the I2C slave block.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Disable the slave.
    //
    HWREG(ulBase + I2C_O_SCSR) = 0;

    //
    // Disable the clock to the slave block.
    //
    HWREG(ulBase + I2C_O_MCR) &=
        ~(I2C_MCR_SFE);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the I2C module.
//!
//! \param ulBase is the base address of the I2C module.
//! \param pfnHandler is a pointer to the function to be called when the
//! I2C interrupt occurs.
//!
//! This sets the handler to be called when an I2C interrupt occurs.  This will
//! enable the global interrupt in the interrupt controller; specific I2C
//! interrupts must be enabled via I2CMasterIntEnable() and
//! I2CSlaveIntEnable().  If necessary, it is the interrupt handler's
//! responsibility to clear the interrupt source via I2CMasterIntClear() and
//! I2CSlaveIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
I2CIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Determine the interrupt number based on the I2C port.
    //

    ulInt = I2CIntNumberGet(ulBase);

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(ulInt, pfnHandler);

    //
    // Enable the I2C interrupt.
    //
    IntEnable(ulInt);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the I2C module.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function will clear the handler to be called when an I2C interrupt
//! occurs.  This will also mask off the interrupt in the interrupt controller
//! so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
I2CIntUnregister(unsigned long ulBase)
{
    unsigned long ulInt;

    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Determine the interrupt number based on the I2C port.
    //

    ulInt = I2CIntNumberGet(ulBase);


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
//! Enables the I2C Master interrupt.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! Enables the I2C Master interrupt source.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterIntEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Enable the master interrupt.
    //
    HWREG(ulBase + I2C_O_MIMR) = 1;
}

//*****************************************************************************
//
//! Enables individual the I2C Master interrupt.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulIntFlags is the bit mask of interrupt sources to be enabled.
//!
//! Enables the I2C Master interrupt source.
//! Tha parameter \e ulFlag in logical OR of any of the following
//! - \b I2C_MASTER_INT_RXFF    - Receive FIFO full
//! - \b I2C_MASTER_INT_TXFE    - Transmit FIFO empty
//! - \b I2C_MASTER_INT_RXFR    - Receive FIFO request
//! - \b I2C_MASTER_INT_TXFR    - Transmit FIFO request
//! - \b I2C_MASTER_INT_ARBL    - Arbitration Lost
//! - \b I2C_MASTER_INT_STOP    - Stop condition detected
//! - \b I2C_MASTER_INT_START   - Start condition detected
//! - \b I2C_MASTER_INT_NACK    - Address/data NACK received
//! - \b I2C_MASTER_INT_DMATX   - Transmit DMA completed
//! - \b I2C_MASTER_INT_DMARX   - Receive DMA completed
//! - \b I2C_MASTER_INT_TIMEOUT - Clock Timeout
//! - \b I2C_MASTER_INT_DATA    - Next Data
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterIntEnableEx(unsigned long ulBase,unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Enable the master interrupt.
    //
    HWREG(ulBase + I2C_O_MIMR)|= ulIntFlags ;
}

//*****************************************************************************
//
//! Enables the I2C Slave interrupt.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! Enables the I2C Slave interrupt source.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveIntEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Enable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) |= I2C_SLAVE_INT_DATA;
}

//*****************************************************************************
//
//! Enables individual I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! Enables the indicated I2C Slave interrupt sources.  Only the sources that
//! are enabled can be reflected to the processor interrupt; disabled sources
//! have no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b I2C_SLAVE_INT_RXFF   - Receive FIFO full
//! - \b I2C_SLAVE_INT_TXFE   - Transmit FIFO empty
//! - \b I2C_SLAVE_INT_RXFR   - Receive FIFO Request
//! - \b I2C_SLAVE_INT_TXFR   - Transmit FIFO Request
//! - \b I2C_SLAVE_INT_DMATX  - Transmit DMA complete
//! - \b I2C_SLAVE_INT_DMARX  - Transmit DMA complete
//! - \b I2C_SLAVE_INT_STOP   - Stop condition detected
//! - \b I2C_SLAVE_INT_START  - Start condition detected
//! - \b I2C_SLAVE_INT_DATA   - Next Data
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveIntEnableEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Enable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables the I2C Master interrupt.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! Disables the I2C Master interrupt source.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterIntDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Disable the master interrupt.
    //
    HWREG(ulBase + I2C_O_MIMR) = 0;
}

//*****************************************************************************
//
//! Disables individual I2C Master interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! Disables the indicated I2C Master interrupt sources.  Only the sources that
//! are enabled can be reflected to the processor interrupt; disabled sources
//! have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CMasterIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterIntDisableEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Disable the master interrupt.
    //
    HWREG(ulBase + I2C_O_MIMR) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Disables the I2C Slave interrupt.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! Disables the I2C Slave interrupt source.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveIntDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Disable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) &= ~I2C_SLAVE_INT_DATA;
}

//*****************************************************************************
//
//! Disables individual I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! Disables the indicated I2C Slave interrupt sources.  Only the sources that
//! are enabled can be reflected to the processor interrupt; disabled sources
//! have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CSlaveIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveIntDisableEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Disable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the current I2C Master interrupt status.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt status for the I2C master.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return The current interrupt status, returned as \b true if active
//! or \b false if not active.
//
//*****************************************************************************
tBoolean
I2CMasterIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return((HWREG(ulBase + I2C_O_MMIS) & I2C_INT_MASTER) ? true : false);
    }
    else
    {
        return((HWREG(ulBase + I2C_O_MRIS) & I2C_INT_MASTER) ? true : false);
    }
}

//*****************************************************************************
//
//! Gets the current I2C Master interrupt status.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt status for the I2C master.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! values described in I2CMasterIntEnableEx().
//
//*****************************************************************************
unsigned long
I2CMasterIntStatusEx(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + I2C_O_MMIS));
    }
    else
    {
        return(HWREG(ulBase + I2C_O_MRIS));
    }
}

//*****************************************************************************
//
//! Gets the current I2C Slave interrupt status.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt status for the I2C slave.  Either the raw
//! interrupt status or the status of interrupts that are allowed to reflect to
//! the processor can be returned.
//!
//! \return The current interrupt status, returned as \b true if active
//! or \b false if not active.
//
//*****************************************************************************
tBoolean
I2CSlaveIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return((HWREG(ulBase + I2C_O_SMIS)) ? true : false);
    }
    else
    {
        return((HWREG(ulBase + I2C_O_SRIS)) ? true : false);
    }
}


//*****************************************************************************
//
//! Gets the current I2C Slave interrupt status.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt status for the I2C slave.  Either the raw
//! interrupt status or the status of interrupts that are allowed to reflect to
//! the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! values described in I2CSlaveIntEnableEx().
//
//*****************************************************************************
unsigned long
I2CSlaveIntStatusEx(unsigned long ulBase, tBoolean bMasked)
{

    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + I2C_O_SMIS));
    }
    else
    {
        return(HWREG(ulBase + I2C_O_SRIS));
    }
}

//*****************************************************************************
//
//! Clears I2C Master interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! The I2C Master interrupt source is cleared, so that it no longer asserts.
//! This must be done in the interrupt handler to keep it from being called
//! again immediately upon exit.
//!
//! \note Because there is a write buffer in the Cortex-M3 processor, it may
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
I2CMasterIntClear(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Clear the I2C master interrupt source.
    //
    HWREG(ulBase + I2C_O_MICR) = I2C_MICR_IC;

    //
    // Workaround for I2C master interrupt clear errata for rev B Stellaris
    // devices.  For later devices, this write is ignored and therefore
    // harmless (other than the slight performance hit).
    //
    HWREG(ulBase + I2C_O_MMIS) = I2C_MICR_IC;
}

//*****************************************************************************
//
//! Clears I2C Master interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified I2C Master interrupt sources are cleared, so that they no
//! longer assert.  This must be done in the interrupt handler to keep it from
//! being called again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CMasterIntEnable().
//!
//! \note Because there is a write buffer in the Cortex-M3 processor, it may
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
I2CMasterIntClearEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Clear the I2C master interrupt source.
    //
    HWREG(ulBase + I2C_O_MICR) = ulIntFlags;
}

//*****************************************************************************
//
//! Clears I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! The I2C Slave interrupt source is cleared, so that it no longer asserts.
//! This must be done in the interrupt handler to keep it from being called
//! again immediately upon exit.
//!
//! \note Because there is a write buffer in the Cortex-M3 processor, it may
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
I2CSlaveIntClear(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Clear the I2C slave interrupt source.
    //
    HWREG(ulBase + I2C_O_SICR) = I2C_SICR_DATAIC;
}

//*****************************************************************************
//
//! Clears I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified I2C Slave interrupt sources are cleared, so that they no
//! longer assert.  This must be done in the interrupt handler to keep it from
//! being called again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CSlaveIntEnable().
//!
//! \note Because there is a write buffer in the Cortex-M3 processor, it may
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
I2CSlaveIntClearEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Clear the I2C slave interrupt source.
    //
    HWREG(ulBase + I2C_O_SICR) = ulIntFlags;
}

//*****************************************************************************
//
//! Sets the address that the I2C Master will place on the bus.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ucSlaveAddr 7-bit slave address
//! \param bReceive flag indicating the type of communication with the slave
//!
//! This function will set the address that the I2C Master will place on the
//! bus when initiating a transaction.  When the \e bReceive parameter is set
//! to \b true, the address will indicate that the I2C Master is initiating a
//! read from the slave; otherwise the address will indicate that the I2C
//! Master is initiating a write to the slave.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterSlaveAddrSet(unsigned long ulBase, unsigned char ucSlaveAddr,
                      tBoolean bReceive)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));

    ASSERT(!(ucSlaveAddr & 0x80));

    //
    // Set the address of the slave with which the master will communicate.
    //
    HWREG(ulBase + I2C_O_MSA) = (ucSlaveAddr << 1) | bReceive;
}

//*****************************************************************************
//
//! Reads the state of the SDA and SCL pins.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function returns the state of the I2C bus by providing the real time
//! values of the SDA and SCL pins.
//!
//! \return Returns the state of the bus with SDA in bit position 1 and SCL in
//! bit position 0.
//
//*****************************************************************************
unsigned long
I2CMasterLineStateGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Return the line state.
    //
    return(HWREG(ulBase + I2C_O_MBMON));
}
//*****************************************************************************
//
//! Enable the LoopBack
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function enables the internal loopback between the master block
//! and slave block.
//!
//!
//! \return none.
//
//*****************************************************************************
void
I2CLoopBackEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Enable the Loopback.
    //
    HWREG(ulBase + I2C_O_MCR)|=I2C_MCR_LPBK;
}

//*****************************************************************************
//
//! Disable the LoopBack
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function disables the internal loopback between the master block
//! & slave block and resumes the normal operation.
//!
//!
//! \return none.
//
//*****************************************************************************
void
I2CLoopBackDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Enable the Loopback.
    //
    HWREG(ulBase + I2C_O_MCR)&= ~I2C_MCR_LPBK;
}


//*****************************************************************************
//
//! Configures FIFO for Burst transfer
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulTxTrigLvl is the Tx FIFO Trigger Level
//! \param ulRxTrigLvl is the Rx FIFO Trigger Level
//! \param ulFif0Flag is the new fifo configuration
//!
//! This function configure the internal FIFO for burst transfer
//! The parameter \e ulRxFlag and \e ulTxFlag is logical OR of
//! any of the following
//!
//! - \b I2C_FIFO_SLAVE
//! - \b I2C_FIFO_FLUSH
//! - \b I2C_FIFO_DMA_EN
//!
//! The parameter \e ulTxTrigLvl and ulRxTrigLvl is one of the following
//!
//! - \b I2C_FIFO_TRIG_0
//! - \b I2C_FIFO_TRIG_1
//! - \b I2C_FIFO_TRIG_2
//! - \b I2C_FIFO_TRIG_3
//! - \b I2C_FIFO_TRIG_4
//! - \b I2C_FIFO_TRIG_5
//! - \b I2C_FIFO_TRIG_6
//! - \b I2C_FIFO_TRIG_7
//!
//! \return none.
//
//*****************************************************************************


void
I2CFIFOCtrlSet(unsigned long ulBase, unsigned long ulTxTrigLvl,
               unsigned long ulTxFlag, unsigned ulRxTrigLvl,
               unsigned long ulRxFlag)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Configure Rx FIFO
    //
    ulRxFlag|=((ulRxTrigLvl & 0x7));
    ulRxFlag=(ulRxFlag << 16);
    HWREG(ulBase + I2C_O_FIFOCTL)= ((HWREG(ulBase + I2C_O_FIFOCTL) & ~(0xE0070000)
                                    |ulRxFlag));

    //
    // Configure Tx FIFO
    //
    ulTxFlag|=(ulTxTrigLvl & 0x7);
    HWREG(ulBase + I2C_O_FIFOCTL)= ((HWREG(ulBase + I2C_O_FIFOCTL) & ~(0x0000E007)
                                    |ulTxFlag));

}
//*****************************************************************************
//
//! Transmit FIFO write
//!
//! \param ulBase is the base address of the I2C module.
//! \param ucData is the data to be transmitted.
//! This function writes a byte into the Tx FIFO
//!
//! \return none.
//
//*****************************************************************************
void
I2CFIFOWrite(unsigned long ulBase,unsigned char ucData)
{
    HWREG(I2C_O_FIFODATA)=ucData;
}

//*****************************************************************************
//
//! Receive FIFO read
//!
//! \param ulBase is the base address of the I2C module.
//! This function reads a byte from the Rx FIFO
//!
//! \return Return the byte read from the Rx fifo, cast as a \e long.
//
//*****************************************************************************
unsigned long
I2CFIFORead(unsigned long ulBase)
{
    return(HWREG(I2C_O_FIFODATA));
}

//*****************************************************************************
//
//! Gets the current FIFO status
//!
//! \param ulBase is the base address of the I2C module.
//! The returned vale is logical OR of one or more of the following
//!
//! - \b I2C_FIFO_RX_ABVTRIG
//! - \b I2C_FIFO_RX_FF
//! - \b I2C_FIFO_RX_FE
//! - \b I2C_FIFO_TX_BVLTRIG
//! - \b I2C_FIFO_TX_FF
//! - \b I2C_FIFO_TX_FE
//! - \b I2C_FIFO_NONE
//!
//! \return Return the status word.
//
//*****************************************************************************

unsigned long
I2CFIFOStatusGet(unsigned long ulBase)
{
    return(HWREG(I2C_O_FIFOSTATUS));
}


//*****************************************************************************
//
//! Enable the Multi Master feature.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function enables the Multi Master feature.
//!
//!
//! \return none.
//
//*****************************************************************************
void
I2CMultiMasterEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Enable the Multi Master.
    //
   HWREG(ulBase + I2C_O_MCR) &= ~((1<<6));
}

//*****************************************************************************
//
//! Disable the Multi Master feature.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function disables the Multi Master feature
//!
//!
//! \return none.
//
//*****************************************************************************
void
I2CMultiMasterDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Disable the Multi Master.
    //
    HWREG(ulBase + I2C_O_MCR) |= ((1<<6));
}


//*****************************************************************************
//
//! Indicates whether or not the I2C Master is busy.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function returns an indication of whether or not the I2C Master is
//! busy transmitting or receiving data.
//!
//! \return Returns \b true if the I2C Master is busy; otherwise, returns
//! \b false.
//
//*****************************************************************************
tBoolean
I2CMasterBusy(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Return the busy status.
    //
    if(HWREG(ulBase + I2C_O_MCS) & I2C_MCS_BUSY)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//*****************************************************************************
//
//! Indicates whether or not the I2C bus is busy.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function returns an indication of whether or not the I2C bus is busy.
//! This function can be used in a multi-master environment to determine if
//! another master is currently using the bus.
//!
//! \return Returns \b true if the I2C bus is busy; otherwise, returns
//! \b false.
//
//*****************************************************************************
tBoolean
I2CMasterBusBusy(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Return the bus busy status.
    //
    if(HWREG(ulBase + I2C_O_MCS) & I2C_MCS_BUSBSY)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//*****************************************************************************
//
//! Controls the state of the I2C master.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulCmd command to be issued to the I2C master
//!
//! This function is used to control the state of the master send and
//! receive operations.  The \e ucCmd parameter can be one of the following
//! values:
//!
//! - \b I2C_MASTER_CMD_SINGLE_SEND
//! - \b I2C_MASTER_CMD_SINGLE_RECEIVE
//! - \b I2C_MASTER_CMD_BURST_SEND_START
//! - \b I2C_MASTER_CMD_BURST_SEND_CONT
//! - \b I2C_MASTER_CMD_BURST_SEND_FINISH
//! - \b I2C_MASTER_CMD_BURST_SEND_ERROR_STOP
//! - \b I2C_MASTER_CMD_BURST_RECEIVE_START
//! - \b I2C_MASTER_CMD_BURST_RECEIVE_CONT
//! - \b I2C_MASTER_CMD_BURST_RECEIVE_FINISH
//! - \b I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterControl(unsigned long ulBase, unsigned long ulCmd)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));

    ASSERT((ulCmd == I2C_MASTER_CMD_SINGLE_SEND) ||
           (ulCmd == I2C_MASTER_CMD_SINGLE_RECEIVE) ||
           (ulCmd == I2C_MASTER_CMD_BURST_SEND_START) ||
           (ulCmd == I2C_MASTER_CMD_BURST_SEND_CONT) ||
           (ulCmd == I2C_MASTER_CMD_BURST_SEND_FINISH) ||
           (ulCmd == I2C_MASTER_CMD_BURST_SEND_ERROR_STOP) ||
           (ulCmd == I2C_MASTER_CMD_BURST_RECEIVE_START) ||
           (ulCmd == I2C_MASTER_CMD_BURST_RECEIVE_CONT) ||
           (ulCmd == I2C_MASTER_CMD_BURST_RECEIVE_FINISH) ||
           (ulCmd == I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP));

    //
    // Send the command.
    //
    HWREG(ulBase + I2C_O_MCS) = ulCmd;
}

//*****************************************************************************
//
//! Gets the error status of the I2C master.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function is used to obtain the error status of the master send
//! and receive operations.
//!
//! \return Returns the error status, as one of \b I2C_MASTER_ERR_NONE,
//! \b I2C_MASTER_ERR_ADDR_ACK, \b I2C_MASTER_ERR_DATA_ACK, or
//! \b I2C_MASTER_ERR_ARB_LOST.
//
//*****************************************************************************
unsigned long
I2CMasterErr(unsigned long ulBase)
{
    unsigned long ulErr;

    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Get the raw error state
    //
    ulErr = HWREG(ulBase + I2C_O_MCS);

    //
    // If the I2C master is busy, then all the other bit are invalid, and
    // don't have an error to report.
    //
    if(ulErr & I2C_MCS_BUSY)
    {
        return(I2C_MASTER_ERR_NONE);
    }

    //
    // Check for errors.
    //
    if(ulErr & (I2C_MCS_ERROR | I2C_MCS_ARBLST | I2C_MCS_CLKTO))
    {
        return(ulErr & (I2C_MCS_ARBLST|I2C_MCS_CLKTO| I2C_MCS_ACK | I2C_MCS_ADRACK));
    }
    else
    {
        return(I2C_MASTER_ERR_NONE);
    }
}

//*****************************************************************************
//
//! Transmits a byte from the I2C Master.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ucData data to be transmitted from the I2C Master
//!
//! This function will place the supplied data into I2C Master Data Register.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterDataPut(unsigned long ulBase, unsigned char ucData)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Write the byte.
    //
    HWREG(ulBase + I2C_O_MDR) = ucData;
}

//*****************************************************************************
//
//! Receives a byte that has been sent to the I2C Master.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function reads a byte of data from the I2C Master Data Register.
//!
//! \return Returns the byte received from by the I2C Master, cast as an
//! unsigned long.
//
//*****************************************************************************
unsigned long
I2CMasterDataGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Read a byte.
    //
    return(HWREG(ulBase + I2C_O_MDR));
}


//*****************************************************************************
//
//! Sets the Master clock timeout value.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ulValue is the number of I2C clocks before the timeout is asserted.
//!
//! This function enables and configures the clock low timeout feature in the
//! I2C peripheral (required by SMBus).  This feature is implemented as a 12
//! bit counter, with the upper 8-bits being programmable.  For example, to
//! program a timeout of 20ms with a 100kHz SCL frequency, \e ulValue would be
//! 0x7d.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterTimeoutSet(unsigned long ulBase, unsigned long ulValue)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Write the timeout value.
    //
    HWREG(ulBase + I2C_O_MCLKOCNT) = ulValue;
}

//*****************************************************************************
//
//! Configures ACK override behavior of the I2C Slave.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bEnable enables or disables ACK override.
//!
//! This function enables or disables ACK override, allowing the user
//! application to drive the value on SDA during the ACK cycle.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveACKOverride(unsigned long ulBase, tBoolean bEnable)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Enable or disable based on bEnable.
    //
    if(bEnable)
    {
        HWREG(ulBase + I2C_O_SACKCTL) |= I2C_SACKCTL_ACKOEN;
    }
    else
    {
        HWREG(ulBase + I2C_O_SACKCTL) &= ~I2C_SACKCTL_ACKOEN;
    }
}

//*****************************************************************************
//
//! Writes the ACK value.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bACK chooses whether to ACK (true) or NACK (false) the transfer.
//!
//! This function puts the desired ACK value on SDA during the ACK cycle.  The
//! value written is only valid when ACK override is enabled using
//! I2CMasterACKOverride.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveACKValueSet(unsigned long ulBase, tBoolean bACK)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // ACK or NACK based on the value of bACK.
    //
    if(bACK)
    {
        HWREG(ulBase + I2C_O_SACKCTL) &= ~I2C_SACKCTL_ACKOVAL;
    }
    else
    {
        HWREG(ulBase + I2C_O_SACKCTL) |= I2C_SACKCTL_ACKOVAL;
    }
}


//*****************************************************************************
//
//! Gets the I2C slave status
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function will return the action requested from a master, if any.
//! Possible values are:
//!
//! - \b I2C_SLAVE_ACT_NONE
//! - \b I2C_SLAVE_ACT_RREQ
//! - \b I2C_SLAVE_ACT_TREQ
//! - \b I2C_SLAVE_ACT_RREQ_FBR
//! - \b I2C_SLAVE_ACT_OAR2SEL
//! - \b I2C_SLAVE_ACT_QCMD
//! - \b I2C_SLAVE_ACT_QCMD_DATA
//!
//! \return Returns \b I2C_SLAVE_ACT_NONE to indicate that no action has been
//! requested of the I2C slave, \b I2C_SLAVE_ACT_RREQ to indicate that
//! an I2C master has sent data to the I2C slave, \b I2C_SLAVE_ACT_TREQ
//! to indicate that an I2C master has requested that the I2C slave send
//! data, and \b I2C_SLAVE_ACT_RREQ_FBR to indicate that an I2C master has sent
//! data to the I2C slave and the first byte following the slave's own address
//! has been received.
//
//*****************************************************************************
unsigned long
I2CSlaveStatus(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Return the slave status.
    //
    return(HWREG(ulBase + I2C_O_SCSR));
}

//*****************************************************************************
//
//! Transmits a byte from the I2C Slave.
//!
//! \param ulBase is the base address of the I2C module.
//! \param ucData data to be transmitted from the I2C Slave
//!
//! This function will place the supplied data into I2C Slave Data Register.
//!
//! \return None.
//
//*****************************************************************************
void
I2CSlaveDataPut(unsigned long ulBase, unsigned char ucData)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Write the byte.
    //
    HWREG(ulBase + I2C_O_SDR) = ucData;
}

//*****************************************************************************
//
//! Receives a byte that has been sent to the I2C Slave.
//!
//! \param ulBase is the base address of the I2C module.
//!
//! This function reads a byte of data from the I2C Slave Data Register.
//!
//! \return Returns the byte received from by the I2C Slave, cast as an
//! unsigned long.
//
//*****************************************************************************
unsigned long
I2CSlaveDataGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //

    ASSERT(I2CMasterBaseValid(ulBase));


    //
    // Read a byte.
    //
    return(HWREG(ulBase + I2C_O_SDR));
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
