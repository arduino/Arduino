//#############################################################################
//
//! \file   f2802x_common/source/i2c.c
//!
//! \brief  Contains the various functions related to the inter-integrated 
//!         circuit (I2C) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

//*****************************************************************************
//! \addtogroup i2c_api
//! @{
//*****************************************************************************

#include "DSP28x_Project.h"
#include "f2802x_common/include/i2c.h"



//*****************************************************************************
//
//! \internal
//! Checks an I2C base address.
//!
//! \param spiHandle specifies the I2C module base address.
//!
//! This function determines if a I2C module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifndef NDEBUG
bool_t I2C_isHandleValid(I2C_Handle i2cHandle)

{
    return ((i2cHandle == (I2C_Handle) &I2caRegs));
}
#endif

I2C_Handle I2C_init(void *pMemory)
{
    assert(pMemory == (void *)I2CA_BASE_ADDR);
    
    I2C_Handle i2cHandle;

    // assign the handle
    i2cHandle = (I2C_Handle)pMemory;
    
    return (i2cHandle);
} // end of I2C_init() function


//Note final clock must be between 7 and 12MHz for propper I2C operation
void I2C_setupClock(I2C_Handle i2cHandle, const uint16_t preScalar, 
        const  uint16_t bitTimeLow, const uint16_t bitTimeHigh)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;
    
    i2c->I2CPSC = (preScalar - 1) & I2C_I2CPSC_IPSC_BITS;
    i2c->I2CCLKL = bitTimeLow;
    i2c->I2CCLKH = bitTimeHigh;
    
}


////*****************************************************************************
////! Initializes the I2C Master block.
////!
////! \param ulBase is the base address of the I2C Master module.
////! \param ulI2CClk is the rate of the clock supplied to the I2C module.
////! \param bFast set up for fast data transfers
////!
////! This function initializes operation of the I2C Master block.  Upon
////! successful initialization of the I2C block, this function will have set the
////! bus speed for the master, and will have enabled the I2C Master block.
////!
////! If the parameter \e bFast is \b true, then the master block will be set up
////! to transfer data at 400 kbps; otherwise, it will be set up to transfer data
////! at 100 kbps.
////!
////! The peripheral clock will be the same as the processor clock.  This will be
////! the value returned by SysCtlClockGet(), or it can be explicitly hard coded
////! if it is constant and known (to save the code/execution overhead of a call
////! to SysCtlClockGet()).
////!
////! This function replaces the original I2CMasterInit() API and performs the
////! same actions.  A macro is provided in <tt>i2c.h</tt> to map the original
////! API to this API.
////!
////! \return None.
////*****************************************************************************
//void
//I2CMasterInitExpClk(unsigned long ulBase, unsigned long ulI2CClk, 
//                    tBoolean bFast)
//{
//    unsigned long ulSCLFreq;
//    unsigned long ulTPR;
//
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Must enable the device before doing anything else.
//    I2CMasterEnable(ulBase);
//
//    // Get the desired SCL speed.
//    if(bFast == true)
//    {
//        ulSCLFreq = 400000;
//    }
//    else
//    {
//        ulSCLFreq = 100000;
//    }
//
//    // Compute the clock divider that achieves the fastest speed less than or
//    // equal to the desired speed.  The numerator is biased to favor a larger
//    // clock divider so that the resulting clock is always less than or equal
//    // to the desired clock, never greater.
//    ulTPR = ((ulI2CClk + (2 * 10 * ulSCLFreq) - 1) / (2 * 10 * ulSCLFreq)) - 1;
//    HWREG(ulBase + I2C_O_MTPR) = ulTPR;
//}

//*****************************************************************************
//! Disable the I2C Master block.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This will enable operation of the I2C Master block.
//!
//! \return None.
//*****************************************************************************
void I2C_disable(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_IRS_BIT;
}

//*****************************************************************************
//! Enables the I2C Master block.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This will enable operation of the I2C Master block.
//!
//! \return None.
//*****************************************************************************
void I2C_enable(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Enable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_IRS_BIT;
}

//*****************************************************************************
//! Enables the I2C Master block.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This will enable operation of the I2C Master block.
//!
//! \return None.
//*****************************************************************************
void I2C_setMaster(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Enable the master block.
    i2c->I2CMDR |= I2C_I2CMDR_MST_BIT;
}

//*****************************************************************************
//! Enables the I2C Slave block.
//!
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This will enable operation of the I2C Slave block.
//!
//! \return None.
//*****************************************************************************
void I2C_setSlave(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Enable the slave.
    i2c->I2CMDR &= ~I2C_I2CMDR_MST_BIT;
}

////*****************************************************************************
////! Disables the I2C master block.
////!
////! \param ulBase is the base address of the I2C Master module.
////!
////! This will disable operation of the I2C master block.
////!
////! \return None.
////*****************************************************************************
//void
//I2CMasterDisable(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Disable the master block.
//    HWREG(ulBase + I2C_O_MCR) &= ~(I2C_MCR_MFE);
//}
//
////*****************************************************************************
////! Disables the I2C slave block.
////!
////! \param ulBase is the base address of the I2C Slave module.
////!
////! This will disable operation of the I2C slave block.
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveDisable(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Disable the slave.
//    HWREG(ulBase + I2C_O_SCSR) = 0;
//
//    // Disable the clock to the slave block.
//    HWREG(ulBase - I2C0_SLAVE_BASE + I2C0_MASTER_BASE + I2C_O_MCR) &=
//        ~(I2C_MCR_SFE);
//}

////*****************************************************************************
////! Registers an interrupt handler for the I2C module.
////!
////! \param ulBase is the base address of the I2C Master module.
////! \param pfnHandler is a pointer to the function to be called when the
////! I2C interrupt occurs.
////!
////! This sets the handler to be called when an I2C interrupt occurs.  This will
////! enable the global interrupt in the interrupt controller; specific I2C
////! interrupts must be enabled via I2CMasterIntEnable() and
////! I2CSlaveIntEnable().  If necessary, it is the interrupt handler's
////! responsibility to clear the interrupt source via I2CMasterIntClear() and
////! I2CSlaveIntClear().
////!
////! \sa IntRegister() for important information about registering interrupt
////! handlers.
////!
////! \return None.
////*****************************************************************************
//void
//I2CIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
//{
//    unsigned long ulInt;
//
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Determine the interrupt number based on the I2C port.
//    ulInt = (ulBase == I2C0_MASTER_BASE) ? INT_I2C0 : INT_I2C1;
//
//    // Register the interrupt handler, returning an error if an error occurs.
//    IntRegister(ulInt, pfnHandler);
//
//    // Enable the I2C interrupt.
//    IntEnable(ulInt);
//}
//
////*****************************************************************************
////! Unregisters an interrupt handler for the I2C module.
////!
////! \param ulBase is the base address of the I2C Master module.
////!
////! This function will clear the handler to be called when an I2C interrupt
////! occurs.  This will also mask off the interrupt in the interrupt controller
////! so that the interrupt handler no longer is called.
////!
////! \sa IntRegister() for important information about registering interrupt
////! handlers.
////!
////! \return None.
////*****************************************************************************
//void
//I2CIntUnregister(unsigned long ulBase)
//{
//    unsigned long ulInt;
//
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Determine the interrupt number based on the I2C port.
//    ulInt = (ulBase == I2C0_MASTER_BASE) ? INT_I2C0 : INT_I2C1;
//
//    // Disable the interrupt.
//    IntDisable(ulInt);
//
//    // Unregister the interrupt handler.
//    IntUnregister(ulInt);
//}

//*****************************************************************************
//! Enables the I2C interrupts
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! Enables the I2C Master interrupt source.
//!
//! \return None.
//*****************************************************************************
void I2C_enableInt(I2C_Handle i2cHandle, const I2C_IntEnable_e interrupts)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Enable interrupts
    i2c->I2CIER |= interrupts;
}

void I2C_enableFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Enable the fifo
    i2c->I2CFFTX |= I2C_I2CFFTX_FFEN_BIT;
}

void I2C_clearTxFifoInt(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Clear the FIFO interrupt
    i2c->I2CFFTX |= I2C_I2CFFTX_TXFFINTCLR_BIT;
}

void I2C_clearRxFifoInt(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Clear the FIFO interrupt
    i2c->I2CFFRX |= I2C_I2CFFRX_RXFFINTCLR_BIT;
}

void I2C_disableFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Disable the fifo
    i2c->I2CFFTX &= ~I2C_I2CFFTX_FFEN_BIT;
}

void I2C_resetTxFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Reset the TX FIFO
    i2c->I2CFFTX |= I2C_I2CFFTX_TXFFRST_BIT;
}

void I2C_resetRxFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Reset the RX FIFO
    i2c->I2CFFRX |= I2C_I2CFFRX_RXFFRST_BIT;
}

////*****************************************************************************
////! Enables the I2C Slave interrupt.
////!
////! \param ulBase is the base address of the I2C Slave module.
////!
////! Enables the I2C Slave interrupt source.
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveIntEnable(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Enable the slave interrupt.
//    HWREG(ulBase + I2C_O_SIMR) |= I2C_SLAVE_INT_DATA;
//}
//
////*****************************************************************************
////! Enables individual I2C Slave interrupt sources.
////!
////! \param ulBase is the base address of the I2C Slave module.
////! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
////!
////! Enables the indicated I2C Slave interrupt sources.  Only the sources that
////! are enabled can be reflected to the processor interrupt; disabled sources
////! have no effect on the processor.
////!
////! The \e ulIntFlags parameter is the logical OR of any of the following:
////!
////! - \b I2C_SLAVE_INT_STOP - Stop condition detected interrupt
////! - \b I2C_SLAVE_INT_START - Start condition detected interrupt
////! - \b I2C_SLAVE_INT_DATA - Data interrupt
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveIntEnableEx(unsigned long ulBase, unsigned long ulIntFlags)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Enable the slave interrupt.
//    HWREG(ulBase + I2C_O_SIMR) |= ulIntFlags;
//}

//*****************************************************************************
//! Disables the I2C Master interrupt.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! Disables the I2C Master interrupt source.
//!
//! \return None.
//*****************************************************************************
void I2C_disableInt(I2C_Handle i2cHandle, const I2C_IntEnable_e interrupts)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Disable interrupts
    i2c->I2CIER &= ~interrupts;
}

////*****************************************************************************
////! Disables the I2C Slave interrupt.
////!
////! \param ulBase is the base address of the I2C Slave module.
////!
////! Disables the I2C Slave interrupt source.
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveIntDisable(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Disable the slave interrupt.
//    HWREG(ulBase + I2C_O_SIMR) &= ~I2C_SLAVE_INT_DATA;
//}
//
////*****************************************************************************
////! Disables individual I2C Slave interrupt sources.
////!
////! \param ulBase is the base address of the I2C Slave module.
////! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
////!
////! Disables the indicated I2C Slave interrupt sources.  Only the sources that
////! are enabled can be reflected to the processor interrupt; disabled sources
////! have no effect on the processor.
////!
////! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
////! parameter to I2CSlaveIntEnableEx().
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveIntDisableEx(unsigned long ulBase, unsigned long ulIntFlags)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Disable the slave interrupt.
//    HWREG(ulBase + I2C_O_SIMR) &= ~ulIntFlags;
//}

//*****************************************************************************
//! Gets the current I2C Master interrupt status.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt status for the I2C Master module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return The current interrupt status, returned as \b true if active
//! or \b false if not active.
//*****************************************************************************
I2C_IntSource_e I2C_getIntSource(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Return the i2c status 
    return ((I2C_IntSource_e)(i2c->I2CISRC));
}

//*****************************************************************************
//! Gets the current I2C Master interrupt status.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt status for the I2C Master module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return The current interrupt status, returned as \b true if active
//! or \b false if not active.
//*****************************************************************************
I2C_Status_e I2C_getStatus(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Return the i2c status 
    return ((I2C_Status_e)(i2c->I2CSTR));
}
//
////*****************************************************************************
////! Gets the current I2C Slave interrupt status.
////!
////! \param ulBase is the base address of the I2C Slave module.
////! \param bMasked is false if the raw interrupt status is requested and
////! true if the masked interrupt status is requested.
////!
////! This returns the interrupt status for the I2C Slave module.  Either the raw
////! interrupt status or the status of interrupts that are allowed to reflect to
////! the processor can be returned.
////!
////! \return The current interrupt status, returned as \b true if active
////! or \b false if not active.
////*****************************************************************************
//tBoolean
//I2CSlaveIntStatus(unsigned long ulBase, tBoolean bMasked)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Return either the interrupt status or the raw interrupt status as
//    // requested.
//    if(bMasked)
//    {
//        return((HWREG(ulBase + I2C_O_SMIS)) ? true : false);
//    }
//    else
//    {
//        return((HWREG(ulBase + I2C_O_SRIS)) ? true : false);
//    }
//}
//
////*****************************************************************************
////! Gets the current I2C Slave interrupt status.
////!
////! \param ulBase is the base address of the I2C Slave module.
////! \param bMasked is false if the raw interrupt status is requested and
////! true if the masked interrupt status is requested.
////!
////! This returns the interrupt status for the I2C Slave module.  Either the raw
////! interrupt status or the status of interrupts that are allowed to reflect to
////! the processor can be returned.
////!
////! \return Returns the current interrupt status, enumerated as a bit field of
////! values described in I2CSlaveIntEnableEx().
////*****************************************************************************
//unsigned long
//I2CSlaveIntStatusEx(unsigned long ulBase, tBoolean bMasked)
//{
//
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Return either the interrupt status or the raw interrupt status as
//    // requested.
//    if(bMasked)
//    {
//        return(HWREG(ulBase + I2C_O_SMIS));
//    }
//    else
//    {
//        return(HWREG(ulBase + I2C_O_SRIS));
//    }
//}

////*****************************************************************************
////! Clears I2C Master interrupt sources.
////!
////! \param ulBase is the base address of the I2C Master module.
////!
////! The I2C Master interrupt source is cleared, so that it no longer asserts.
////! This must be done in the interrupt handler to keep it from being called
////! again immediately upon exit.
////!
////! \note Because there is a write buffer in the Cortex-M3 processor, it may
////! take several clock cycles before the interrupt source is actually cleared.
////! Therefore, it is recommended that the interrupt source be cleared early in
////! the interrupt handler (as opposed to the very last action) to avoid
////! returning from the interrupt handler before the interrupt source is
////! actually cleared.  Failure to do so may result in the interrupt handler
////! being immediately reentered (because the interrupt controller still sees
////! the interrupt source asserted).
////!
////! \return None.
////*****************************************************************************
//void
//I2CMasterIntClear(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Clear the I2C master interrupt source.
//    HWREG(ulBase + I2C_O_MICR) = I2C_MICR_IC;
//
//}
//
////*****************************************************************************
////! Clears I2C Slave interrupt sources.
////!
////! \param ulBase is the base address of the I2C Slave module.
////!
////! The I2C Slave interrupt source is cleared, so that it no longer asserts.
////! This must be done in the interrupt handler to keep it from being called
////! again immediately upon exit.
////!
////! \note Because there is a write buffer in the Cortex-M3 processor, it may
////! take several clock cycles before the interrupt source is actually cleared.
////! Therefore, it is recommended that the interrupt source be cleared early in
////! the interrupt handler (as opposed to the very last action) to avoid
////! returning from the interrupt handler before the interrupt source is
////! actually cleared.  Failure to do so may result in the interrupt handler
////! being immediately reentered (because the interrupt controller still sees
////! the interrupt source asserted).
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveIntClear(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Clear the I2C slave interrupt source.
//    HWREG(ulBase + I2C_O_SICR) = I2C_SICR_DATAIC;
//}
//
////*****************************************************************************
////! Clears I2C Slave interrupt sources.
////!
////! \param ulBase is the base address of the I2C Slave module.
////! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
////!
////! The specified I2C Slave interrupt sources are cleared, so that they no
////! longer assert.  This must be done in the interrupt handler to keep it from
////! being called again immediately upon exit.
////!
////! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
////! parameter to I2CSlaveIntEnableEx().
////!
////! \note Because there is a write buffer in the Cortex-M3 processor, it may
////! take several clock cycles before the interrupt source is actually cleared.
////! Therefore, it is recommended that the interrupt source be cleared early in
////! the interrupt handler (as opposed to the very last action) to avoid
////! returning from the interrupt handler before the interrupt source is
////! actually cleared.  Failure to do so may result in the interrupt handler
////! being immediately reentered (because the interrupt controller still sees
////! the interrupt source asserted).
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveIntClearEx(unsigned long ulBase, unsigned long ulIntFlags)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Clear the I2C slave interrupt source.
//    HWREG(ulBase + I2C_O_SICR) = ulIntFlags;
//}

//*****************************************************************************
//! Initializes the I2C Slave block.
//!
//! \param ulBase is the base address of the I2C Slave module.
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
//*****************************************************************************
void I2C_setSlaveAddress(I2C_Handle i2cHandle, const uint16_t slaveAddress)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;
    

    // Must enable the device before doing anything else.
    I2C_setSlave(i2cHandle);

    // Set up the slave address.
    i2c->I2COAR = slaveAddress;
}

//*****************************************************************************
//! Sets the address that the I2C Master will place on the bus.
//!
//! \param ulBase is the base address of the I2C Master module.
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
//*****************************************************************************
void I2C_setMasterSlaveAddr(I2C_Handle i2cHandle, const uint16_t slaveAddress)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Set the address of the slave with which the master will communicate.
    i2c->I2CSAR = slaveAddress;
}

//*****************************************************************************
//! Indicates whether or not the I2C Master is busy.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function returns an indication of whether or not the I2C Master is
//! busy transmitting or receiving data.
//!
//! \return Returns \b true if the I2C Master is busy; otherwise, returns
//! \b false.
//*****************************************************************************
bool_t I2C_isMasterBusy(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Return the busy status.
    if(i2c->I2CSTR & I2C_I2CSTR_BB_BITS)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

////*****************************************************************************
////! Indicates whether or not the I2C bus is busy.
////!
////! \param ulBase is the base address of the I2C Master module.
////!
////! This function returns an indication of whether or not the I2C bus is busy.
////! This function can be used in a multi-master environment to determine if
////! another master is currently using the bus.
////!
////! \return Returns \b true if the I2C bus is busy; otherwise, returns
////! \b false.
////*****************************************************************************
//tBoolean
//I2CMasterBusBusy(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Return the bus busy status.
//    if(HWREG(ulBase + I2C_O_MCS) & I2C_MCS_BUSBSY)
//    {
//        return(true);
//    }
//    else
//    {
//        return(false);
//    }
//}

//*****************************************************************************
//! Controls the state of the I2C Master module.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ulCmd command to be issued to the I2C Master module
//!
//! This function is used to control the state of the Master module send and
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
//*****************************************************************************
void I2C_MasterControl(I2C_Handle i2cHandle, I2C_Control_e action, uint16_t bitCount, uint16_t bytes)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    assert(bitCount <= 7);
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;
    
    // Write the number of bytes to send or receive
    i2c->I2CCNT = bytes;

    // Send the command.
    i2c->I2CMDR = action | bitCount;
}

////*****************************************************************************
////! Gets the error status of the I2C Master module.
////!
////! \param ulBase is the base address of the I2C Master module.
////!
////! This function is used to obtain the error status of the Master module send
////! and receive operations.
////!
////! \return Returns the error status, as one of \b I2C_MASTER_ERR_NONE, 
////! \b I2C_MASTER_ERR_ADDR_ACK, \b I2C_MASTER_ERR_DATA_ACK, or
////! \b I2C_MASTER_ERR_ARB_LOST.
////*****************************************************************************
//unsigned long
//I2CMasterErr(unsigned long ulBase)
//{
//    unsigned long ulErr;
//
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE));
//
//    // Get the raw error state
//    ulErr = HWREG(ulBase + I2C_O_MCS);
//
//    // If the I2C master is busy, then all the other bit are invalid, and
//    // don't have an error to report.
//    if(ulErr & I2C_MCS_BUSY)
//    {
//        return(I2C_MASTER_ERR_NONE);
//    }
//
//    // Check for errors.
//    if(ulErr & (I2C_MCS_ERROR | I2C_MCS_ARBLST))
//    {
//        return(ulErr & (I2C_MCS_ARBLST | I2C_MCS_DATACK | I2C_MCS_ADRACK));
//    }
//    else
//    {
//        return(I2C_MASTER_ERR_NONE);
//    }
//}

//*****************************************************************************
//! Transmits a byte from the I2C Master.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ucData data to be transmitted from the I2C Master
//!
//! This function will place the supplied data into I2C Master Data Register.
//!
//! \return None.
//*****************************************************************************
void I2C_putData(I2C_Handle i2cHandle, uint16_t data)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Write the byte.
    i2c->I2CDXR = data;
}

//*****************************************************************************
//! Receives a byte that has been sent to the I2C Master.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function reads a byte of data from the I2C Master Data Register.
//!
//! \return Returns the byte received from by the I2C Master, cast as an
//! unsigned long.
//*****************************************************************************
uint16_t I2C_getData(I2C_Handle i2cHandle)
{
    // Check the arguments.
    assert(I2C_isHandleValid(i2cHandle));
    
    I2C_Obj *i2c = (I2C_Obj *)i2cHandle;

    // Read the byte.
    return (i2c->I2CDRR);
}


////*****************************************************************************
////! Transmits a byte from the I2C Slave.
////!
////! \param ulBase is the base address of the I2C Slave module.
////! \param ucData data to be transmitted from the I2C Slave
////!
////! This function will place the supplied data into I2C Slave Data Register.
////!
////! \return None.
////*****************************************************************************
//void
//I2CSlaveDataPut(unsigned long ulBase, unsigned char ucData)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Write the byte.
//    HWREG(ulBase + I2C_O_SDR) = ucData;
//}
//
////*****************************************************************************
////! Receives a byte that has been sent to the I2C Slave.
////!
////! \param ulBase is the base address of the I2C Slave module.
////!
////! This function reads a byte of data from the I2C Slave Data Register.
////!
////! \return Returns the byte received from by the I2C Slave, cast as an
////! unsigned long.
////*****************************************************************************
//unsigned long
//I2CSlaveDataGet(unsigned long ulBase)
//{
//    // Check the arguments.
//    ASSERT((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE));
//
//    // Read a byte.
//    return(HWREG(ulBase + I2C_O_SDR));
//}

//*****************************************************************************
// Close the Doxygen group.
//! @}
//*****************************************************************************


