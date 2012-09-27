//*****************************************************************************
//
// i2c.c - Driver for Inter-IC (I2C) bus block.
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
//! \addtogroup i2c_api
//! @{
//
//*****************************************************************************

#include "inc/hw_i2c.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
// A mapping of I2C base address to interupt number.
//
//*****************************************************************************
static const unsigned long g_ppulI2CIntMap[][2] =
{
    { I2C0_MASTER_BASE, INT_I2C0 },
    { I2C1_MASTER_BASE, INT_I2C1 },
    { I2C2_MASTER_BASE, INT_I2C2 },
    { I2C3_MASTER_BASE, INT_I2C3 },
    { I2C4_MASTER_BASE, INT_I2C4 },
    { I2C5_MASTER_BASE, INT_I2C5 },
};

//*****************************************************************************
//
//! \internal
//! Checks a I2C master base address.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function determines if a I2C master module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
I2CMasterBaseValid(unsigned long ulBase)
{
    return((ulBase == I2C0_MASTER_BASE) || (ulBase == I2C1_MASTER_BASE) ||
           (ulBase == I2C2_MASTER_BASE) || (ulBase == I2C3_MASTER_BASE) ||
           (ulBase == I2C4_MASTER_BASE) || (ulBase == I2C5_MASTER_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Checks a I2C slave base address.
//!
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This function determines if a I2C slave module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
I2CSlaveBaseValid(unsigned long ulBase)
{
    return((ulBase == I2C0_SLAVE_BASE) || (ulBase == I2C1_SLAVE_BASE) ||
           (ulBase == I2C2_SLAVE_BASE) || (ulBase == I2C3_SLAVE_BASE) ||
           (ulBase == I2C4_SLAVE_BASE) || (ulBase == I2C5_SLAVE_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Gets the I2C interrupt number.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! Given a I2C base address, this function returns the corresponding
//! interrupt number.
//!
//! \return Returns an I2C interrupt number, or -1 if \e ulBase is invalid.
//
//*****************************************************************************
static long
I2CIntNumberGet(unsigned long ulBase)
{
    unsigned long ulIdx;

    //
    // Loop through the table that maps I2C base addresses to interrupt
    // numbers.
    //
    for(ulIdx = 0; ulIdx < (sizeof(g_ppulI2CIntMap) /
                            sizeof(g_ppulI2CIntMap[0])); ulIdx++)
    {
        //
        // See if this base address matches.
        //
        if(g_ppulI2CIntMap[ulIdx][0] == ulBase)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(g_ppulI2CIntMap[ulIdx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(-1);
}

//*****************************************************************************
//
//! Initializes the I2C Master block.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ulI2CClk is the rate of the clock supplied to the I2C module.
//! \param bFast set up for fast data transfers.
//!
//! This function initializes operation of the I2C Master block by configuring
//! the bus speed for the master and enabling the I2C Master block.
//!
//! If the parameter \e bFast is \b true, then the master block is set up to
//! transfer data at 400 Kbps; otherwise, it is set up to transfer data at
//! 100 Kbps.  If Fast Mode Plus (1 Mbps) is desired, software should manually
//! write the I2CMTPR after calling this function.  For High Speed (3.4 Mbps)
//! mode, a specific command is used to switch to the faster clocks after the
//! initial communication with the slave is done at either 100 Kbps or
//! 400 Kbps.
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
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

    //
    // Check to see if this I2C peripheral is High-Speed enabled.  If yes, also
    // choose the fastest speed that is less than or equal to 3.4 Mbps.
    //
    if(HWREG(ulBase + I2C_O_PP) & I2C_PP_HS)
    {
        ulTPR = ((ulI2CClk + (2 * 3 * 3400000) - 1) /
                (2 * 3 * 3400000)) - 1;
        HWREG(ulBase + I2C_O_MTPR) = I2C_MTPR_HS | ulTPR;
    }
}

//*****************************************************************************
//
//! Initializes the I2C Slave block.
//!
//! \param ulBase is the base address of the I2C Slave module.
//! \param ucSlaveAddr 7-bit slave address
//!
//! This function initializes operation of the I2C Slave block by configuring
//! the slave address and enabling the I2C Slave block.
//!
//! The parameter \e ucSlaveAddr is the value that is compared against the
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
    ASSERT(I2CSlaveBaseValid(ulBase));
    ASSERT(!(ucSlaveAddr & 0x80));

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
//! \param ulBase is the base address of the I2C Slave module.
//! \param ucAddrNum determines which slave address is set.
//! \param ucSlaveAddr is the 7-bit slave address
//!
//! This function writes the specified slave address.  The \e ulAddrNum field
//! dictates which slave address is configured.  For example, a value of 0
//! configures the primary address and a value of 1 configures the secondary.
//!
//! \note Not all Stellaris devices support a secondary address.  Please
//! consult the device data sheet to determine if this feature is supported.
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
    ASSERT(I2CSlaveBaseValid(ulBase));
    ASSERT(!(ucAddrNum > 1));
    ASSERT(!(ucSlaveAddr & 0x80));

    //
    // Determine which slave address is being set.
    //
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
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function enables operation of the I2C Master block.
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
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This fucntion enables operation of the I2C Slave block.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Enable the clock to the slave block.
    //
    HWREG(ulBase - I2C0_SLAVE_BASE + I2C0_MASTER_BASE + I2C_O_MCR) |=
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
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function disables operation of the I2C master block.
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
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This function disables operation of the I2C slave block.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Disable the slave.
    //
    HWREG(ulBase + I2C_O_SCSR) = 0;

    //
    // Disable the clock to the slave block.
    //
    HWREG(ulBase - I2C0_SLAVE_BASE + I2C0_MASTER_BASE + I2C_O_MCR) &=
        ~(I2C_MCR_SFE);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the I2C module.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param pfnHandler is a pointer to the function to be called when the
//! I2C interrupt occurs.
//!
//! This function sets the handler to be called when an I2C interrupt occurs.
//! This function enables the global interrupt in the interrupt controller;
//! specific I2C interrupts must be enabled via I2CMasterIntEnable() and
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
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function clears the handler to be called when an I2C interrupt
//! occurs.  This function also masks off the interrupt in the interrupt r
//! controlle so that the interrupt handler no longer is called.
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
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function enables the I2C Master interrupt source.
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
//! Enables individual I2C Master interrupt sources.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated I2C Master interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b I2C_MASTER_INT_TIMEOUT - Clock Timeout interrupt
//! - \b I2C_MASTER_INT_DATA - Data interrupt
//!
//! \note Not all Stellaris devices support all of the listed interrupt
//! sources.  Please consult the device data sheet to determine if these
//! features are supported.
//!
//! \return None.
//
//*****************************************************************************
void
I2CMasterIntEnableEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CMasterBaseValid(ulBase));

    //
    // Enable the master interrupt.
    //
    HWREG(ulBase + I2C_O_MIMR) |= ulIntFlags;
}

//*****************************************************************************
//
//! Enables the I2C Slave interrupt.
//!
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This function enables the I2C Slave interrupt source.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Enable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) |= I2C_SLAVE_INT_DATA;
}

//*****************************************************************************
//
//! Enables individual I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C Slave module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated I2C Slave interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b I2C_SLAVE_INT_STOP - Stop condition detected interrupt
//! - \b I2C_SLAVE_INT_START - Start condition detected interrupt
//! - \b I2C_SLAVE_INT_DATA - Data interrupt
//!
//! \note Not all Stellaris devices support the all of the listed interrupts.
//! Please consult the device data sheet to determine if these features are
//! supported.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Enable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables the I2C Master interrupt.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function disables the I2C Master interrupt source.
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
//! \param ulBase is the base address of the I2C Master module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated I2C Master interrupt sources.  Only
//! the sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CMasterIntEnableEx().
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
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This function disables the I2C Slave interrupt source.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Disable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) &= ~I2C_SLAVE_INT_DATA;
}

//*****************************************************************************
//
//! Disables individual I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C Slave module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated I2C Slave interrupt sources.  Only
//! the sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CSlaveIntEnableEx().
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Disable the slave interrupt.
    //
    HWREG(ulBase + I2C_O_SIMR) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the current I2C Master interrupt status.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This function returns the interrupt status for the I2C Master module.
//! Either the raw interrupt status or the status of interrupts that are allowed to
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
        return((HWREG(ulBase + I2C_O_MMIS)) ? true : false);
    }
    else
    {
        return((HWREG(ulBase + I2C_O_MRIS)) ? true : false);
    }
}

//*****************************************************************************
//
//! Gets the current I2C Master interrupt status.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This function returns the interrupt status for the I2C Master module.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
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
//! \param ulBase is the base address of the I2C Slave module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This function returns the interrupt status for the I2C Slave module.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

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
//! \param ulBase is the base address of the I2C Slave module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This function returns the interrupt status for the I2C Slave module.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! values described in I2CSlaveIntEnableEx().
//
//*****************************************************************************
unsigned long
I2CSlaveIntStatusEx(unsigned long ulBase, tBoolean bMasked)
{
    unsigned long ulValue;

    //
    // Check the arguments.
    //
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        //
        // Workaround for I2C slave masked interrupt status register errata
        // (7.1) for Dustdevil Rev A0 devices.
        //
        if(CLASS_IS_DUSTDEVIL && REVISION_IS_A0)
        {
            ulValue = HWREG(ulBase + I2C_O_SRIS);
            return(ulValue & HWREG(ulBase + I2C_O_SIMR));
        }
        else
        {
            return(HWREG(ulBase + I2C_O_SMIS));
        }
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
//! \param ulBase is the base address of the I2C Master module.
//!
//! The I2C Master interrupt source is cleared, so that it no longer asserts.
//! This function must be called in the interrupt handler to keep the interrupt
//! from being triggered again immediately upon exit.
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
//! \param ulBase is the base address of the I2C Master module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified I2C Master interrupt sources are cleared, so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep the interrupt from being triggered again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CMasterIntEnableEx().
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
//! \param ulBase is the base address of the I2C Slave module.
//!
//! The I2C Slave interrupt source is cleared, so that it no longer asserts.
//! This function must be called in the interrupt handler to keep the interrupt
//! from being triggered again immediately upon exit.
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
I2CSlaveIntClear(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Clear the I2C slave interrupt source.
    //
    HWREG(ulBase + I2C_O_SICR) = I2C_SICR_DATAIC;
}

//*****************************************************************************
//
//! Clears I2C Slave interrupt sources.
//!
//! \param ulBase is the base address of the I2C Slave module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified I2C Slave interrupt sources are cleared, so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep the interrupt from being triggered again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to I2CSlaveIntEnableEx().
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
I2CSlaveIntClearEx(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Clear the I2C slave interrupt source.
    //
    HWREG(ulBase + I2C_O_SICR) = ulIntFlags;
}

//*****************************************************************************
//
//! Sets the address that the I2C Master places on the bus.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ucSlaveAddr 7-bit slave address
//! \param bReceive flag indicating the type of communication with the slave
//!
//! This function configures the address that the I2C Master places on the
//! bus when initiating a transaction.  When the \e bReceive parameter is set
//! to \b true, the address indicates that the I2C Master is initiating a
//! read from the slave; otherwise the address indicates that the I2C
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
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function returns the state of the I2C bus by providing the real time
//! values of the SDA and SCL pins.
//!
//! \note Not all Stellaris devices support this function.  Please consult the
//! device data sheet to determine if this feature is supported.
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
//! Indicates whether or not the I2C Master is busy.
//!
//! \param ulBase is the base address of the I2C Master module.
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
//! \param ulBase is the base address of the I2C Master module.
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
//! Controls the state of the I2C Master module.
//!
//! \param ulBase is the base address of the I2C Master module.
//! \param ulCmd command to be issued to the I2C Master module.
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
//! - \b I2C_MASTER_CMD_QUICK_COMMAND
//! - \b I2C_MASTER_CMD_HS_MASTER_CODE_SEND
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
           (ulCmd == I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP) ||
           (ulCmd == I2C_MASTER_CMD_QUICK_COMMAND) ||
           (ulCmd == I2C_MASTER_CMD_HS_MASTER_CODE_SEND));

    //
    // Send the command.
    //
    HWREG(ulBase + I2C_O_MCS) = ulCmd;
}

//*****************************************************************************
//
//! Gets the error status of the I2C Master module.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This function is used to obtain the error status of the Master module send
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
    if(ulErr & (I2C_MCS_ERROR | I2C_MCS_ARBLST))
    {
        return(ulErr & (I2C_MCS_ARBLST | I2C_MCS_DATACK | I2C_MCS_ADRACK));
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
//! \param ulBase is the base address of the I2C Master module.
//! \param ucData data to be transmitted from the I2C Master.
//!
//! This function places the supplied data into I2C Master Data Register.
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
//! \param ulBase is the base address of the I2C Master module.
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
//! \param ulBase is the base address of the I2C Master module.
//! \param ulValue is the number of I2C clocks before the timeout is asserted.
//!
//! This function enables and configures the clock low timeout feature in the
//! I2C peripheral.  This feature is implemented as a 12-bit counter, with the
//! upper 8-bits being programmable.  For example, to program a timeout of 20ms
//! with a 100kHz SCL frequency, \e ulValue would be 0x7d.
//!
//! \note Not all Stellaris devices support this function.  Please consult the
//! device data sheet to determine if this feature is supported.
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
//! \param ulBase is the base address of the I2C Slave module.
//! \param bEnable enables or disables ACK override.
//!
//! This function enables or disables ACK override, allowing the user
//! application to drive the value on SDA during the ACK cycle.
//!
//! \note Not all Stellaris devices support this function.  Please consult the
//! device data sheet to determine if this feature is supported.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

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
//! \param ulBase is the base address of the I2C Slave module.
//! \param bACK chooses whether to ACK (true) or NACK (false) the transfer.
//!
//! This function puts the desired ACK value on SDA during the ACK cycle.  The
//! value written is only valid when ACK override is enabled using
//! I2CSlaveACKOverride().
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
    ASSERT(I2CSlaveBaseValid(ulBase));

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
//! Gets the I2C Slave module status
//!
//! \param ulBase is the base address of the I2C Slave module.
//!
//! This function returns the action requested from a master, if any.
//! Possible values are:
//!
//! - \b I2C_SLAVE_ACT_NONE
//! - \b I2C_SLAVE_ACT_RREQ
//! - \b I2C_SLAVE_ACT_TREQ
//! - \b I2C_SLAVE_ACT_RREQ_FBR
//! - \b I2C_SLAVE_ACT_OWN2SEL
//! - \b I2C_SLAVE_ACT_QCMD
//! - \b I2C_SLAVE_ACT_QCMD_DATA
//!
//! \note Not all Stellaris devices support the second I2C slave's own address
//! or the quick command function.  Please consult the device data sheet to
//! determine if these features are supported.
//!
//! \return Returns \b I2C_SLAVE_ACT_NONE to indicate that no action has been
//! requested of the I2C Slave module, \b I2C_SLAVE_ACT_RREQ to indicate that
//! an I2C master has sent data to the I2C Slave module, \b I2C_SLAVE_ACT_TREQ
//! to indicate that an I2C master has requested that the I2C Slave module send
//! data, \b I2C_SLAVE_ACT_RREQ_FBR to indicate that an I2C master has sent
//! data to the I2C slave and the first byte following the slave's own address
//! has been received, \b I2C_SLAVE_ACT_OWN2SEL to indicate that the second I2C
//! slave address was matched, \b I2C_SLAVE_ACT_QCMD to indicate that a quick
//! command was received, and \b I2C_SLAVE_ACT_QCMD_DATA to indicate that the
//! data bit was set when the quick command was received.
//
//*****************************************************************************
unsigned long
I2CSlaveStatus(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Return the slave status.
    //
    return(HWREG(ulBase + I2C_O_SCSR));
}

//*****************************************************************************
//
//! Transmits a byte from the I2C Slave.
//!
//! \param ulBase is the base address of the I2C Slave module.
//! \param ucData is the data to be transmitted from the I2C Slave
//!
//! This function places the supplied data into I2C Slave Data Register.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

    //
    // Write the byte.
    //
    HWREG(ulBase + I2C_O_SDR) = ucData;
}

//*****************************************************************************
//
//! Receives a byte that has been sent to the I2C Slave.
//!
//! \param ulBase is the base address of the I2C Slave module.
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
    ASSERT(I2CSlaveBaseValid(ulBase));

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
