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

I2C_Handle I2C_init(void *pMemory, const size_t num_bytes)
{
    I2C_Handle i2cHandle;
    if (num_bytes < sizeof(I2C_Obj)) return ((I2C_Handle)NULL);
    // assign the handle
    i2cHandle = (I2C_Handle)pMemory;
    return (i2cHandle);
} // end of I2C_init() function

//Note final clock must be between 7 and 12MHz for propper I2C operation
void I2C_setupClock(I2C_Handle i2cHandle, const uint16_t preScalar,
                    const  uint16_t bitTimeLow, const uint16_t bitTimeHigh)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    i2c->I2CPSC = (preScalar - 1) & I2C_I2CPSC_IPSC_BITS;
    i2c->I2CCLKL = bitTimeLow;
    i2c->I2CCLKH = bitTimeHigh;
}

void I2C_set10BitAddress(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_XA_BIT;
}

void I2C_set7BitAddress(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_XA_BIT;
}


void I2C_setMode(I2C_Handle i2cHandle, unsigned int bitMask)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CMDR = bitMask;
    return;
}

void I2C_setRptMode(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_RM_BIT;
}

void I2C_clearRptMode(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_RM_BIT;
}

void I2C_setDigitalLoopback(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_DLB_BIT;
}

void I2C_clearDigitalLoopback(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_DLB_BIT;
}

int I2C_getBusBusy(I2C_Handle i2cHandle)
{
    int BB_state;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    BB_state = i2c->I2CSTR & I2C_I2CSTR_BB_BITS;
    BB_state >>= 12;
    return BB_state;
}

int I2C_getRxReady(I2C_Handle i2cHandle)
{
    int RRDY_state;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Get the RRDY status
    RRDY_state = i2c->I2CSTR & I2C_I2CSTR_RRDY_BITS;
    RRDY_state >>= 3;
    return RRDY_state;
}



int I2C_getStopCondition(I2C_Handle i2cHandle)
{
    int STP_state;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Retrieve the STP stop condition bit status.
    // The caller will need to call this function to see if this bit is cleared
    // from any previous master communication.
    // Clearing of this bit by the module is delayed until after the SCD bit is
    // set. If this bit is not checked prior to initiating a new message, the
    // I2C could get confused.
    STP_state = i2c->I2CMDR & I2C_I2CMDR_STP_BIT;
    STP_state >>= 11;
    return STP_state;
}

int I2C_getStopCondDetected(I2C_Handle i2cHandle)
{
    int SCD_state;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    SCD_state = i2c->I2CSTR & I2C_I2CSTR_SCD_BITS;
    SCD_state >>= 5;
    return SCD_state;
}

void I2C_clearModuleReset(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_IRS_BIT;
}

void I2C_setModuleReset(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_IRS_BIT;
}

void I2C_setExtendedStart(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_STB_BIT;
}

void I2C_setNormalStart(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_STB_BIT;
}

void I2C_setFreeDataFormat(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_FDF_BIT;
}

void I2C_clearFreeDataFormat(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_FDF_BIT;
}

void I2C_setTransmit(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_TRX_BIT;
}

void I2C_setReceive(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_TRX_BIT;
}

void I2C_setStop(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_STP_BIT;
}

void I2C_clearStop(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_STP_BIT;
}

void I2C_setStart(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR |= I2C_I2CMDR_STT_BIT;
}

void I2C_clearStart(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CMDR &= ~I2C_I2CMDR_STT_BIT;
}

void I2C_setDataCount(I2C_Handle i2cHandle, int dcount)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the I2C peripheral
    i2c->I2CCNT = dcount;
}

//*****************************************************************************
//! Disable the I2C Master block.
//!
//! \param ulBase is the base address of the I2C Master module.
//!
//! This will disable operation of the I2C Master block.
//!
//! \return None.
//*****************************************************************************
void I2C_disable(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Enable the slave.
    i2c->I2CMDR &= ~I2C_I2CMDR_MST_BIT;
}

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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable all interrupt bits first
    i2c->I2CIER &= ~0x7F;
    // Enable selected interrupt bits
    i2c->I2CIER |= interrupts;
}

void I2C_enableFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Enable the fifo
    i2c->I2CFFTX |= I2C_I2CFFTX_FFEN_BIT;
}

void I2C_clearTxFifoInt(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the FIFO interrupt
    i2c->I2CFFTX |= I2C_I2CFFTX_TXFFINTCLR_BIT;
}

void I2C_clearRxFifoInt(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the FIFO interrupt
    i2c->I2CFFRX |= I2C_I2CFFRX_RXFFINTCLR_BIT;
}

void I2C_disableFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable the fifo
    i2c->I2CFFTX &= ~I2C_I2CFFTX_FFEN_BIT;
}

void I2C_resetTxFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Reset the TX FIFO
    i2c->I2CFFTX |= I2C_I2CFFTX_TXFFRST_BIT;
}

void I2C_resetRxFifo(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Reset the RX FIFO
    i2c->I2CFFRX |= I2C_I2CFFRX_RXFFRST_BIT;
}


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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Disable interrupts
    i2c->I2CIER &= ~interrupts;
}

//*****************************************************************************
//! Gets the current I2C interrupt source.
//!
//! \param ulBase is the base address of the I2C module.
//! \param bMasked is false if the raw interrupt status is requested and
//! true if the masked interrupt status is requested.
//!
//! This returns the interrupt source for the I2C module.  
//!
//! \return The current interrupt source as an INTCODE (I2C_IntSource_e enum value)
//*****************************************************************************
I2C_IntSource_e I2C_getIntSource(I2C_Handle i2cHandle)
{
    I2C_IntSource_e retval;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Return the i2c status
    retval = (I2C_IntSource_e)(i2c->I2CISRC);
    return retval;
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
//! \return Current interrupt status as a bit mask (use I2C_I2CSTR_xxx_BITS to mask off)
//*****************************************************************************
uint16_t I2C_getStatus(I2C_Handle i2cHandle)
{
    uint16_t retval;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Return the i2c status
    retval = i2c->I2CSTR;
    return retval;
}

void I2C_clearArbLost(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the status bit
    i2c->I2CSTR &= ~I2C_CLR_AL_BIT;
}

void I2C_clearNACK(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the status bit
    i2c->I2CSTR &= ~I2C_CLR_NACK_BIT;
}

void I2C_clearAccessReady(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the status bit
    i2c->I2CSTR &= ~I2C_CLR_ARDY_BIT;
}

void I2C_clearReceiveDataReady(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the status bit
    i2c->I2CSTR &= ~I2C_CLR_RRDY_BIT;
}

void I2C_clearStopCondDetected(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Clear the status bit
    i2c->I2CSTR &= ~I2C_CLR_SCD_BIT;
}

I2C_FifoStatus_e I2C_getTxFifoStatus(I2C_Handle i2cHandle)
{
    I2C_FifoStatus_e retval;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Return the i2c status
    retval = (I2C_FifoStatus_e)((i2c->I2CFFTX) & 0x1F00);
    return retval;
}

I2C_FifoStatus_e I2C_getRxFifoStatus(I2C_Handle i2cHandle)
{
    I2C_FifoStatus_e retval;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Return the i2c status
    retval = (I2C_FifoStatus_e)((i2c->I2CFFRX) & 0x1F00);
    return retval;
}

int I2C_getRxFifoInt(I2C_Handle i2cHandle)
{
    int FFRX_cond;
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Get the RX FFINT condition
    FFRX_cond = i2c->I2CFFRX & I2C_I2CFFRX_RXFFINT_BIT;
    FFRX_cond >>= 7;
    return FFRX_cond;
}

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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Must enable the device before doing anything else.
    I2C_enable(i2cHandle);
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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Return the busy status.
    if (i2c->I2CSTR & I2C_I2CSTR_BB_BITS)
    {
        return (true);
    } else
    {
        return (false);
    }
}

void I2C_setNackmod(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Set the bit
    i2c->I2CMDR |= I2C_I2CMDR_NAKMOD_BIT;
}

void I2C_clearNackmod(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Set the bit
    i2c->I2CMDR &= ~I2C_I2CMDR_NAKMOD_BIT;
}

void I2C_setDebugFree(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Set the bit
    i2c->I2CMDR |= I2C_I2CMDR_FREE_BIT;
}

void I2C_clearDebugFree(I2C_Handle i2cHandle)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Set the bit
    i2c->I2CMDR &= (~I2C_I2CMDR_FREE_BIT);
}

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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
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
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // Read the byte.
    return (i2c->I2CDRR);
}

void I2C_setRxFifoIntLevel(I2C_Handle i2cHandle, const I2C_FifoLevel_e fifoLevel)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CFFRX |= fifoLevel;
    return;
}

void I2C_setTxFifoIntLevel(I2C_Handle i2cHandle, const I2C_FifoLevel_e fifoLevel)
{
    // Check the arguments.
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CFFTX |= fifoLevel;
    return;
}

void I2C_enableTxFifoInt(I2C_Handle i2cHandle)
{
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CFFTX |= I2C_I2CFFTX_TXFFIENA_BIT;
    return;
} // end of I2C_enableTxFifoInt() function

void I2C_disableTxFifoInt(I2C_Handle i2cHandle)
{
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CFFTX &= ~I2C_I2CFFTX_TXFFIENA_BIT;
    return;
} // end of I2C_enableTxFifoInt() function

void I2C_enableRxFifoInt(I2C_Handle i2cHandle)
{
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CFFRX |= I2C_I2CFFRX_RXFFIENA_BIT;
    return;
} // end of I2C_enableRxFifoInt() function

void I2C_disableRxFifoInt(I2C_Handle i2cHandle)
{
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CFFRX &= ~I2C_I2CFFRX_RXFFIENA_BIT;
    return;
} // end of I2C_enableRxFifoInt() function

void I2C_setCharLength(I2C_Handle i2cHandle, const I2C_BitCount_e charLength)
{
    I2C_Obj *i2c = (I2C_Obj * )i2cHandle;
    // set the bits
    i2c->I2CMDR = charLength;
    return;
} // SCI_setCharLength() function

//*****************************************************************************
// Close the Doxygen group.
//! @}
//*****************************************************************************


