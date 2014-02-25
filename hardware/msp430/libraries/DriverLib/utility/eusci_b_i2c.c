//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// eusci_b_i2c.c - Driver for the eusci_b_i2c Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup eusci_b_i2c_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_EUSCI_Bx__
#include "eusci_b_i2c.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Initializes the I2C Master block.
//!
//! This function initializes operation of the I2C Master block. Upon
//! successful initialization of the I2C block, this function will have set the
//! bus speed for the master; however I2C module is still disabled till
//! EUSCI_B_I2C_enable is invoked.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param selectClockSource is the clocksource.
//!        Valid values are:
//!        - \b EUSCI_B_I2C_CLOCKSOURCE_ACLK
//!        - \b EUSCI_B_I2C_CLOCKSOURCE_SMCLK
//! \param i2cClk is the rate of the clock supplied to the I2C module (the
//!        frequency in Hz of the clock source specified in selectClockSource).
//! \param dataRate setup for selecting data transfer rate.
//!        Valid values are:
//!        - \b EUSCI_B_I2C_SET_DATA_RATE_400KBPS
//!        - \b EUSCI_B_I2C_SET_DATA_RATE_100KBPS
//! \param byteCounterThreshold sets threshold for automatic STOP or UCSTPIFG
//! \param autoSTOPGeneration sets up the STOP condition generation.
//!        Valid values are:
//!        - \b EUSCI_B_I2C_NO_AUTO_STOP
//!        - \b EUSCI_B_I2C_SET_BYTECOUNT_THRESHOLD_FLAG
//!        - \b EUSCI_B_I2C_SEND_STOP_AUTOMATICALLY_ON_BYTECOUNT_THRESHOLD
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterInit(uint32_t baseAddress,
                            uint8_t selectClockSource,
                            uint32_t i2cClk,
                            uint32_t dataRate,
                            uint8_t byteCounterThreshold,
                            uint8_t autoSTOPGeneration
                            )
{
        uint16_t preScalarValue;

        assert((EUSCI_B_I2C_CLOCKSOURCE_ACLK == selectClockSource) ||
               (EUSCI_B_I2C_CLOCKSOURCE_SMCLK == selectClockSource)
               );

        assert((EUSCI_B_I2C_SET_DATA_RATE_400KBPS == dataRate) ||
               (EUSCI_B_I2C_SET_DATA_RATE_100KBPS == dataRate)
               );

        assert((EUSCI_B_I2C_NO_AUTO_STOP == autoSTOPGeneration) ||
               (EUSCI_B_I2C_SET_BYTECOUNT_THRESHOLD_FLAG == autoSTOPGeneration) ||
               (EUSCI_B_I2C_SEND_STOP_AUTOMATICALLY_ON_BYTECOUNT_THRESHOLD == autoSTOPGeneration)
               );

        //Disable the USCI module and clears the other bits of control register
        HWREG16(baseAddress + OFS_UCBxCTLW0) = UCSWRST;

        //Configure Automatic STOP condition generation
        HWREG16(baseAddress + OFS_UCBxCTLW1) &= ~UCASTP_3;
        HWREG16(baseAddress + OFS_UCBxCTLW1) |= autoSTOPGeneration;

        //Byte Count Threshold
        HWREG16(baseAddress + OFS_UCBxTBCNT) = byteCounterThreshold;
        /*
         * Configure as I2C master mode.
         * UCMST = Master mode
         * UCMODE_3 = I2C mode
         * UCSYNC = Synchronous mode
         */
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCMST + UCMODE_3 + UCSYNC;

        //Configure I2C clock source
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= (selectClockSource + UCSWRST );

        /*
         * Compute the clock divider that achieves the fastest speed less than or
         * equal to the desired speed.  The numerator is biased to favor a larger
         * clock divider so that the resulting clock is always less than or equal
         * to the desired clock, never greater.
         */
        preScalarValue = (uint16_t)(i2cClk / dataRate);
        HWREG16(baseAddress + OFS_UCBxBRW) = preScalarValue;
}

//*****************************************************************************
//
//! \brief Initializes the I2C Slave block.
//!
//! This function initializes operation of the I2C as a Slave mode. Upon
//! successful initialization of the I2C blocks, this function will have set
//! the slave address but the I2C module is still disabled till
//! EUSCI_B_I2C_enable is invoked.
//!
//! \param baseAddress is the base address of the I2C Slave module.
//! \param slaveAddress 7-bit slave address
//! \param slaveAddressOffset Own address Offset referred to- 'x' value of
//!        UCBxI2COAx.
//!        Valid values are:
//!        - \b EUSCI_B_I2C_OWN_ADDRESS_OFFSET0
//!        - \b EUSCI_B_I2C_OWN_ADDRESS_OFFSET1
//!        - \b EUSCI_B_I2C_OWN_ADDRESS_OFFSET2
//!        - \b EUSCI_B_I2C_OWN_ADDRESS_OFFSET3
//! \param slaveOwnAddressEnable selects if the specified address is enabled or
//!        disabled.
//!        Valid values are:
//!        - \b EUSCI_B_I2C_OWN_ADDRESS_DISABLE
//!        - \b EUSCI_B_I2C_OWN_ADDRESS_ENABLE
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_slaveInit(uint32_t baseAddress,
                           uint8_t slaveAddress,
                           uint8_t slaveAddressOffset,
                           uint32_t slaveOwnAddressEnable
                           )
{
        assert((EUSCI_B_I2C_OWN_ADDRESS_OFFSET0 == slaveAddressOffset) ||
               (EUSCI_B_I2C_OWN_ADDRESS_OFFSET1 == slaveAddressOffset) ||
               (EUSCI_B_I2C_OWN_ADDRESS_OFFSET2 == slaveAddressOffset) ||
               (EUSCI_B_I2C_OWN_ADDRESS_OFFSET3 == slaveAddressOffset)
               );

        //Disable the USCI module
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCSWRST;

        //Clear USCI master mode
        HWREG16(baseAddress + OFS_UCBxCTLW0) &= ~UCMST;

        //Configure I2C as Slave and Synchronous mode
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCMODE_3 + UCSYNC;

        //Set up the slave address.
        HWREG16(baseAddress + OFS_UCBxI2COA0 + slaveAddressOffset)
                = slaveAddress + slaveOwnAddressEnable;
}

//*****************************************************************************
//
//! \brief Enables the I2C block.
//!
//! This will enable operation of the I2C block.
//!
//! \param baseAddress is the base address of the USCI I2C module.
//!
//! Modified bits are \b UCSWRST of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_enable(uint32_t baseAddress)
{
        //Reset the UCSWRST bit to enable the USCI Module
        HWREG16(baseAddress + OFS_UCBxCTLW0) &= ~(UCSWRST);
}

//*****************************************************************************
//
//! \brief Disables the I2C block.
//!
//! This will disable operation of the I2C block.
//!
//! \param baseAddress is the base address of the USCI I2C module.
//!
//! Modified bits are \b UCSWRST of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_disable(uint32_t baseAddress)
{
        //Set the UCSWRST bit to disable the USCI Module
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCSWRST;
}

//*****************************************************************************
//
//! \brief Sets the address that the I2C Master will place on the bus.
//!
//! This function will set the address that the I2C Master will place on the
//! bus when initiating a transaction.
//!
//! \param baseAddress is the base address of the USCI I2C module.
//! \param slaveAddress 7-bit slave address
//!
//! Modified bits of \b UCBxI2CSA register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_setSlaveAddress(uint32_t baseAddress,
                                 uint8_t slaveAddress
                                 )
{
        //Set the address of the slave with which the master will communicate.
        HWREG16(baseAddress + OFS_UCBxI2CSA) = (slaveAddress);
}

//*****************************************************************************
//
//! \brief Sets the mode of the I2C device
//!
//! When the receive parameter is set to EUSCI_B_I2C_TRANSMIT_MODE, the address
//! will indicate that the I2C module is in receive mode; otherwise, the I2C
//! module is in send mode.
//!
//! \param baseAddress is the base address of the USCI I2C module.
//! \param mode Mode for the EUSCI_B_I2C module
//!        Valid values are:
//!        - \b EUSCI_B_I2C_TRANSMIT_MODE [Default]
//!        - \b EUSCI_B_I2C_RECEIVE_MODE
//!
//! Modified bits are \b UCTR of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_setMode(uint32_t baseAddress,
                         uint8_t mode
                         )
{
        assert((EUSCI_B_I2C_TRANSMIT_MODE == mode) ||
               (EUSCI_B_I2C_RECEIVE_MODE == mode)
               );

        HWREG16(baseAddress + OFS_UCBxCTLW0) &= ~EUSCI_B_I2C_TRANSMIT_MODE;
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= mode;
}

//*****************************************************************************
//
//! \brief Gets the mode of the I2C device
//!
//! Current I2C transmit/receive mode.
//!
//! \param baseAddress is the base address of the I2C module.
//!
//! Modified bits are \b UCTR of \b UCBxCTLW0 register.
//!
//! \return None
//!         Return one of the following:
//!         - \b EUSCI_B_I2C_TRANSMIT_MODE
//!         - \b EUSCI_B_I2C_RECEIVE_MODE
//!         \n indicating the current mode
//
//*****************************************************************************
uint8_t EUSCI_B_I2C_getMode(uint32_t baseAddress)
{
        //Read the I2C mode.
        return (HWREG16(baseAddress + OFS_UCBxCTLW0) & UCTR);

}
//*****************************************************************************
//
//! \brief Transmits a byte from the I2C Module.
//!
//! This function will place the supplied data into I2C transmit data register
//! to start transmission.
//!
//! \param baseAddress is the base address of the I2C Slave module.
//! \param transmitData data to be transmitted from the I2C module
//!
//! Modified bits of \b UCBxTXBUF register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_slaveDataPut(uint32_t baseAddress,
                              uint8_t transmitData
                              )
{
        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = transmitData;
}

//*****************************************************************************
//
//! \brief Receives a byte that has been sent to the I2C Module.
//!
//! This function reads a byte of data from the I2C receive data Register.
//!
//! \param baseAddress is the base address of the I2C Slave module.
//!
//! \return Returns the byte received from by the I2C module, cast as an
//!         uint8_t.
//
//*****************************************************************************
uint8_t EUSCI_B_I2C_slaveDataGet(uint32_t baseAddress)
{
        //Read a byte.
        return HWREG16(baseAddress + OFS_UCBxRXBUF);
}

//*****************************************************************************
//
//! \brief Indicates whether or not the I2C bus is busy.
//!
//! This function returns an indication of whether or not the I2C bus is busy.
//! This function checks the status of the bus via UCBBUSY bit in UCBxSTAT
//! register.
//!
//! \param baseAddress is the base address of the I2C module.
//!
//! \return One of the following:
//!         - \b EUSCI_B_I2C_BUS_BUSY
//!         - \b EUSCI_B_I2C_BUS_NOT_BUSY
//!         \n indicating whether the bus is busy
//
//*****************************************************************************
uint16_t EUSCI_B_I2C_isBusBusy(uint32_t baseAddress)
{
        //Return the bus busy status.
        return HWREG16(baseAddress + OFS_UCBxSTATW) & UCBBUSY;
}

//*****************************************************************************
//
//! \brief Indicates whether STOP got sent.
//!
//! This function returns an indication of whether or not STOP got sent This
//! function checks the status of the bus via UCTXSTP bit in UCBxCTL1 register.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! \return One of the following:
//!         - \b EUSCI_B_I2C_STOP_SEND_COMPLETE
//!         - \b EUSCI_B_I2C_SENDING_STOP
//!         \n indicating whether the stop was sent
//
//*****************************************************************************
uint16_t EUSCI_B_I2C_masterIsStopSent(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_UCBxCTLW0) & UCTXSTP;
}

//*****************************************************************************
//
//! \brief Indicates whether Start got sent.
//!
//! This function returns an indication of whether or not Start got sent This
//! function checks the status of the bus via UCTXSTT bit in UCBxCTL1 register.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! \return One of the following:
//!         - \b EUSCI_B_I2C_START_SEND_COMPLETE
//!         - \b EUSCI_B_I2C_SENDING_START
//!         \n indicating whether the start was sent
//
//*****************************************************************************
uint16_t EUSCI_B_I2C_masterIsStartSent(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_UCBxCTLW0) & UCTXSTT;
}

//*****************************************************************************
//
//! \brief Enables individual I2C interrupt sources.
//!
//! Enables the indicated I2C interrupt sources. Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! \param baseAddress is the base address of the I2C module.
//! \param mask is the bit mask of the interrupt sources to be enabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b EUSCI_B_I2C_NAK_INTERRUPT - Not-acknowledge interrupt
//!        - \b EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT - Arbitration lost
//!           interrupt
//!        - \b EUSCI_B_I2C_STOP_INTERRUPT - STOP condition interrupt
//!        - \b EUSCI_B_I2C_START_INTERRUPT - START condition interrupt
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT0 - Transmit interrupt0
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT1 - Transmit interrupt1
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT2 - Transmit interrupt2
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT3 - Transmit interrupt3
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT0 - Receive interrupt0
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT1 - Receive interrupt1
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT2 - Receive interrupt2
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT3 - Receive interrupt3
//!        - \b EUSCI_B_I2C_BIT9_POSITION_INTERRUPT - Bit position 9 interrupt
//!        - \b EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT - Clock low timeout
//!           interrupt enable
//!        - \b EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT - Byte counter interrupt
//!           enable
//!
//! Modified bits of \b UCBxIE register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_enableInterrupt(uint32_t baseAddress,
                                 uint16_t mask
                                 )
{
        assert( 0x00 == ( mask & ~(EUSCI_B_I2C_STOP_INTERRUPT +
                                   EUSCI_B_I2C_START_INTERRUPT +
                                   EUSCI_B_I2C_NAK_INTERRUPT +
                                   EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT +
                                   EUSCI_B_I2C_BIT9_POSITION_INTERRUPT +
                                   EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT +
                                   EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT1 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT2 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT3 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT0 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT1 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT2 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT3
                                   ))
                );

        //Enable the interrupt masked bit
        HWREG16(baseAddress + OFS_UCBxIE) |= mask;
}

//*****************************************************************************
//
//! \brief Disables individual I2C interrupt sources.
//!
//! Disables the indicated I2C interrupt sources. Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! \param baseAddress is the base address of the I2C module.
//! \param mask is the bit mask of the interrupt sources to be disabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b EUSCI_B_I2C_NAK_INTERRUPT - Not-acknowledge interrupt
//!        - \b EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT - Arbitration lost
//!           interrupt
//!        - \b EUSCI_B_I2C_STOP_INTERRUPT - STOP condition interrupt
//!        - \b EUSCI_B_I2C_START_INTERRUPT - START condition interrupt
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT0 - Transmit interrupt0
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT1 - Transmit interrupt1
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT2 - Transmit interrupt2
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT3 - Transmit interrupt3
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT0 - Receive interrupt0
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT1 - Receive interrupt1
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT2 - Receive interrupt2
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT3 - Receive interrupt3
//!        - \b EUSCI_B_I2C_BIT9_POSITION_INTERRUPT - Bit position 9 interrupt
//!        - \b EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT - Clock low timeout
//!           interrupt enable
//!        - \b EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT - Byte counter interrupt
//!           enable
//!
//! Modified bits of \b UCBxIE register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_disableInterrupt(uint32_t baseAddress,
                                  uint16_t mask
                                  )
{
        assert( 0x00 == ( mask & ~(EUSCI_B_I2C_STOP_INTERRUPT +
                                   EUSCI_B_I2C_START_INTERRUPT +
                                   EUSCI_B_I2C_NAK_INTERRUPT +
                                   EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT +
                                   EUSCI_B_I2C_BIT9_POSITION_INTERRUPT +
                                   EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT +
                                   EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT1 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT2 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT3 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT0 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT1 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT2 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT3
                                   ))
                );

        //Disable the interrupt masked bit
        HWREG16(baseAddress + OFS_UCBxIE) &= ~(mask);
}

//*****************************************************************************
//
//! \brief Clears I2C interrupt sources.
//!
//! The I2C interrupt source is cleared, so that it no longer asserts. The
//! highest interrupt flag is automatically cleared when an interrupt vector
//! generator is used.
//!
//! \param baseAddress is the base address of the I2C module.
//! \param mask is a bit mask of the interrupt sources to be cleared.
//!        Mask value is the logical OR of any of the following:
//!        - \b EUSCI_B_I2C_NAK_INTERRUPT - Not-acknowledge interrupt
//!        - \b EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT - Arbitration lost
//!           interrupt
//!        - \b EUSCI_B_I2C_STOP_INTERRUPT - STOP condition interrupt
//!        - \b EUSCI_B_I2C_START_INTERRUPT - START condition interrupt
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT0 - Transmit interrupt0
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT1 - Transmit interrupt1
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT2 - Transmit interrupt2
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT3 - Transmit interrupt3
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT0 - Receive interrupt0
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT1 - Receive interrupt1
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT2 - Receive interrupt2
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT3 - Receive interrupt3
//!        - \b EUSCI_B_I2C_BIT9_POSITION_INTERRUPT - Bit position 9 interrupt
//!        - \b EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT - Clock low timeout
//!           interrupt enable
//!        - \b EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT - Byte counter interrupt
//!           enable
//!
//! Modified bits of \b UCBxIFG register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_clearInterruptFlag(uint32_t baseAddress,
                                    uint16_t mask
                                    )
{
        assert( 0x00 == ( mask & ~(EUSCI_B_I2C_STOP_INTERRUPT +
                                   EUSCI_B_I2C_START_INTERRUPT +
                                   EUSCI_B_I2C_NAK_INTERRUPT +
                                   EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT +
                                   EUSCI_B_I2C_BIT9_POSITION_INTERRUPT +
                                   EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT +
                                   EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT1 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT2 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT3 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT0 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT1 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT2 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT3
                                   ))
                );
        //Clear the I2C interrupt source.
        HWREG16(baseAddress + OFS_UCBxIFG) &= ~(mask);
}

//*****************************************************************************
//
//! \brief Gets the current I2C interrupt status.
//!
//! This returns the interrupt status for the I2C module based on which flag is
//! passed.
//!
//! \param baseAddress is the base address of the I2C module.
//! \param mask is the masked interrupt flag status to be returned.
//!        Mask value is the logical OR of any of the following:
//!        - \b EUSCI_B_I2C_NAK_INTERRUPT - Not-acknowledge interrupt
//!        - \b EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT - Arbitration lost
//!           interrupt
//!        - \b EUSCI_B_I2C_STOP_INTERRUPT - STOP condition interrupt
//!        - \b EUSCI_B_I2C_START_INTERRUPT - START condition interrupt
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT0 - Transmit interrupt0
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT1 - Transmit interrupt1
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT2 - Transmit interrupt2
//!        - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT3 - Transmit interrupt3
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT0 - Receive interrupt0
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT1 - Receive interrupt1
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT2 - Receive interrupt2
//!        - \b EUSCI_B_I2C_RECEIVE_INTERRUPT3 - Receive interrupt3
//!        - \b EUSCI_B_I2C_BIT9_POSITION_INTERRUPT - Bit position 9 interrupt
//!        - \b EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT - Clock low timeout
//!           interrupt enable
//!        - \b EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT - Byte counter interrupt
//!           enable
//!
//! \return Logical OR of any of the following:
//!         - \b EUSCI_B_I2C_NAK_INTERRUPT Not-acknowledge interrupt
//!         - \b EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT Arbitration lost
//!         interrupt
//!         - \b EUSCI_B_I2C_STOP_INTERRUPT STOP condition interrupt
//!         - \b EUSCI_B_I2C_START_INTERRUPT START condition interrupt
//!         - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT0 Transmit interrupt0
//!         - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT1 Transmit interrupt1
//!         - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT2 Transmit interrupt2
//!         - \b EUSCI_B_I2C_TRANSMIT_INTERRUPT3 Transmit interrupt3
//!         - \b EUSCI_B_I2C_RECEIVE_INTERRUPT0 Receive interrupt0
//!         - \b EUSCI_B_I2C_RECEIVE_INTERRUPT1 Receive interrupt1
//!         - \b EUSCI_B_I2C_RECEIVE_INTERRUPT2 Receive interrupt2
//!         - \b EUSCI_B_I2C_RECEIVE_INTERRUPT3 Receive interrupt3
//!         - \b EUSCI_B_I2C_BIT9_POSITION_INTERRUPT Bit position 9 interrupt
//!         - \b EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT Clock low timeout
//!         interrupt enable
//!         - \b EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT Byte counter interrupt
//!         enable
//!         \n indicating the status of the masked interrupts
//
//*****************************************************************************
uint16_t EUSCI_B_I2C_getInterruptStatus(uint32_t baseAddress,
                                        uint16_t mask
                                        )
{
        assert( 0x00 == ( mask & ~(EUSCI_B_I2C_STOP_INTERRUPT +
                                   EUSCI_B_I2C_START_INTERRUPT +
                                   EUSCI_B_I2C_NAK_INTERRUPT +
                                   EUSCI_B_I2C_ARBITRATIONLOST_INTERRUPT +
                                   EUSCI_B_I2C_BIT9_POSITION_INTERRUPT +
                                   EUSCI_B_I2C_CLOCK_LOW_TIMEOUT_INTERRUPT +
                                   EUSCI_B_I2C_BYTE_COUNTER_INTERRUPT +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT0 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT1 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT2 +
                                   EUSCI_B_I2C_TRANSMIT_INTERRUPT3 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT0 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT1 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT2 +
                                   EUSCI_B_I2C_RECEIVE_INTERRUPT3
                                   ))
                );
        //Return the interrupt status of the request masked bit.
        return HWREG16(baseAddress + OFS_UCBxIFG) & mask;
}

//*****************************************************************************
//
//! \brief Does single byte transmission from Master to Slave
//!
//! This function is used by the Master module to send a single byte. This
//! function sends a start, then transmits the byte to the slave and then sends
//! a stop.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the data byte to be transmitted
//!
//! Modified bits of \b UCBxTXBUF register, bits of \b UCBxCTLW0 register, bits
//! of \b UCBxIE register and bits of \b UCBxIFG register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterSendSingleByte(uint32_t baseAddress,
                                      uint8_t txData
                                      )
{
        //Store current TXIE status
        uint16_t txieStatus = HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE;

        //Disable transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) &= ~(UCTXIE);

        //Send start condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTR + UCTXSTT;

        //Poll for transmit interrupt flag.
        while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        //Poll for transmit interrupt flag.
        while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;

        //Clear transmit interrupt flag before enabling interrupt again
        HWREG16(baseAddress + OFS_UCBxIFG) &= ~(UCTXIFG);

        //Reinstate transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) |= txieStatus;
}

//*****************************************************************************
//
//! \brief Does single byte reception from Slave
//!
//! This function is used by the Master module to receive a single byte. This
//! function sends start and stop, waits for data reception and then receives
//! the data from the slave
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! Modified bits of \b UCBxTXBUF register, bits of \b UCBxCTLW0 register, bits
//! of \b UCBxIE register and bits of \b UCBxIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the transmission process.
//
//*****************************************************************************
uint8_t EUSCI_B_I2C_masterReceiveSingleByte(uint32_t baseAddress)
{
        //Set USCI in Receive mode
        HWREG16(baseAddress + OFS_UCBxCTLW0) &= ~UCTR;
        //Send start
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= (UCTXSTT + UCTXSTP);

        //Poll for receive interrupt flag.
        while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCRXIFG)) ;

        //Send single byte data.
        return HWREG16(baseAddress + OFS_UCBxRXBUF);
}

//*****************************************************************************
//
//! \brief Does single byte transmission from Master to Slave with timeout
//!
//! This function is used by the Master module to send a single byte. This
//! function sends a start, then transmits the byte to the slave and then sends
//! a stop.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the data byte to be transmitted
//! \param timeout is the amount of time to wait until giving up
//!
//! Modified bits of \b UCBxTXBUF register, bits of \b UCBxCTLW0 register, bits
//! of \b UCBxIE register and bits of \b UCBxIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the transmission process.
//
//*****************************************************************************
bool EUSCI_B_I2C_masterSendSingleByteWithTimeout(uint32_t baseAddress,
                                                 uint8_t txData,
                                                 uint32_t timeout
                                                 )
{
        assert(timeout > 0);

        // Creating variable for second timeout scenario
        uint32_t timeout2 = timeout;

        //Store current TXIE status
        uint16_t txieStatus = HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE;

        //Disable transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) &= ~(UCTXIE);

        //Send start condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTR + UCTXSTT;

        //Poll for transmit interrupt flag.
        while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout) ;

        //Check if transfer timed out
        if (timeout == 0)
                return STATUS_FAIL;

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        //Poll for transmit interrupt flag.
        while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout2) ;

        //Check if transfer timed out
        if (timeout2 == 0)
                return STATUS_FAIL;

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;

        //Clear transmit interrupt flag before enabling interrupt again
        HWREG16(baseAddress + OFS_UCBxIFG) &= ~(UCTXIFG);

        //Reinstate transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) |= txieStatus;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Starts multi-byte transmission from Master to Slave
//!
//! This function is used by the master module to start a multi byte
//! transaction.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the first data byte to be transmitted
//!
//! Modified bits of \b UCBxTXBUF register, bits of \b UCBxCTLW0 register, bits
//! of \b UCBxIE register and bits of \b UCBxIFG register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterMultiByteSendStart(uint32_t baseAddress,
                                          uint8_t txData
                                          )
{
        //Store current transmit interrupt enable
        uint16_t txieStatus = HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE;

        //Disable transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) &= ~(UCTXIE);

        //Send start condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTR +  UCTXSTT;

        //Poll for transmit interrupt flag.
        while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        //Reinstate transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) |= txieStatus;
}

//*****************************************************************************
//
//! \brief Starts multi-byte transmission from Master to Slave with timeout
//!
//! This function is used by the master module to start a multi byte
//! transaction.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the first data byte to be transmitted
//! \param timeout is the amount of time to wait until giving up
//!
//! Modified bits of \b UCBxTXBUF register, bits of \b UCBxCTLW0 register, bits
//! of \b UCBxIE register and bits of \b UCBxIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the transmission process.
//
//*****************************************************************************
bool EUSCI_B_I2C_masterMultiByteSendStartWithTimeout(uint32_t baseAddress,
                                                     uint8_t txData,
                                                     uint32_t timeout
                                                     )
{
        assert(timeout > 0);

        //Store current transmit interrupt enable
        uint16_t txieStatus = HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE;

        //Disable transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) &= ~(UCTXIE);

        //Send start condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTR +  UCTXSTT;

        //Poll for transmit interrupt flag.
        while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout) ;

        //Check if transfer timed out
        if (timeout == 0)
                return STATUS_FAIL;

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        //Reinstate transmit interrupt enable
        HWREG16(baseAddress + OFS_UCBxIE) |= txieStatus;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Continues multi-byte transmission from Master to Slave
//!
//! This function is used by the Master module continue each byte of a multi-
//! byte transmission. This function transmits each data byte of a multi-byte
//! transmission to the slave.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the next data byte to be transmitted
//!
//! Modified bits of \b UCBxTXBUF register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterMultiByteSendNext(uint32_t baseAddress,
                                         uint8_t txData
                                         )
{
        //If interrupts are not used, poll for flags
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE))
                //Poll for transmit interrupt flag.
                while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;
}

//*****************************************************************************
//
//! \brief Continues multi-byte transmission from Master to Slave with timeout
//!
//! This function is used by the Master module continue each byte of a multi-
//! byte transmission. This function transmits each data byte of a multi-byte
//! transmission to the slave.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the next data byte to be transmitted
//! \param timeout is the amount of time to wait until giving up
//!
//! Modified bits of \b UCBxTXBUF register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the transmission process.
//
//*****************************************************************************
bool EUSCI_B_I2C_masterMultiByteSendNextWithTimeout(uint32_t baseAddress,
                                                    uint8_t txData,
                                                    uint32_t timeout
                                                    )
{
        assert(timeout > 0);

        //If interrupts are not used, poll for flags
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE)) {
                //Poll for transmit interrupt flag.
                while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout) ;

                //Check if transfer timed out
                if (timeout == 0)
                        return STATUS_FAIL;
        }

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Finishes multi-byte transmission from Master to Slave
//!
//! This function is used by the Master module to send the last byte and STOP.
//! This function transmits the last data byte of a multi-byte transmission to
//! the slave and then sends a stop.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the last data byte to be transmitted in a multi-byte
//!        transmission
//!
//! Modified bits of \b UCBxTXBUF register and bits of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterMultiByteSendFinish(uint32_t baseAddress,
                                           uint8_t txData
                                           )
{
        //If interrupts are not used, poll for flags
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE))
                //Poll for transmit interrupt flag.
                while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        //Poll for transmit interrupt flag.
        while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;
}

//*****************************************************************************
//
//! \brief Finishes multi-byte transmission from Master to Slave with timeout
//!
//! This function is used by the Master module to send the last byte and STOP.
//! This function transmits the last data byte of a multi-byte transmission to
//! the slave and then sends a stop.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is the last data byte to be transmitted in a multi-byte
//!        transmission
//! \param timeout is the amount of time to wait until giving up
//!
//! Modified bits of \b UCBxTXBUF register and bits of \b UCBxCTLW0 register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the transmission process.
//
//*****************************************************************************
bool EUSCI_B_I2C_masterMultiByteSendFinishWithTimeout(uint32_t baseAddress,
                                                      uint8_t txData,
                                                      uint32_t timeout
                                                      )
{
        uint32_t timeout2 = timeout;

        assert(timeout > 0);

        //If interrupts are not used, poll for flags
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE)) {
                //Poll for transmit interrupt flag.
                while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout) ;

                //Check if transfer timed out
                if (timeout == 0)
                        return STATUS_FAIL;
        }

        //Send single byte data.
        HWREG16(baseAddress + OFS_UCBxTXBUF) = txData;

        //Poll for transmit interrupt flag.
        while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout2) ;

        //Check if transfer timed out
        if (timeout2 == 0)
                return STATUS_FAIL;

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief This function is used by the Master module to initiate START
//!
//! This function is used by the Master module to initiate START
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! Modified bits are \b UCTXSTT of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterSendStart(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTT;
}

//*****************************************************************************
//
//! \brief Send STOP byte at the end of a multi-byte transmission from Master
//! to Slave
//!
//! This function is used by the Master module send STOP at the end of a multi-
//! byte transmission. This function sends a stop after current transmission is
//! complete.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! Modified bits are \b UCTXSTP of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterMultiByteSendStop(uint32_t baseAddress)
{
        //If interrupts are not used, poll for flags
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE))
                //Poll for transmit interrupt flag.
                while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) ;

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;
}

//*****************************************************************************
//
//! \brief Send STOP byte at the end of a multi-byte transmission from Master
//! to Slave with timeout
//!
//! This function is used by the Master module send STOP at the end of a multi-
//! byte transmission. This function sends a stop after current transmission is
//! complete.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param timeout is the amount of time to wait until giving up
//!
//! Modified bits are \b UCTXSTP of \b UCBxCTLW0 register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the transmission process.
//
//*****************************************************************************
bool EUSCI_B_I2C_masterMultiByteSendStopWithTimeout(uint32_t baseAddress,
                                                    uint32_t timeout)
{
        assert(timeout > 0);

        //If interrupts are not used, poll for flags
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCTXIE)) {
                //Poll for transmit interrupt flag.
                while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCTXIFG)) && --timeout) ;

                //Check if transfer timed out
                if (timeout == 0)
                        return STATUS_FAIL;
        }

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Starts reception at the Master end
//!
//! This function is used by the Master module initiate reception of a single
//! byte. This function sends a start.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! Modified bits are \b UCTXSTT of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterReceiveStart(uint32_t baseAddress)
{
        //Set USCI in Receive mode
        HWREG16(baseAddress + OFS_UCBxCTLW0) &= ~UCTR;
        //Send start
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTT;
}

//*****************************************************************************
//
//! \brief Starts multi-byte reception at the Master end one byte at a time
//!
//! This function is used by the Master module to receive each byte of a multi-
//! byte reception. This function reads currently received byte.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! \return Received byte at Master end.
//
//*****************************************************************************
uint8_t EUSCI_B_I2C_masterMultiByteReceiveNext(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_UCBxRXBUF);
}

//*****************************************************************************
//
//! \brief Finishes multi-byte reception at the Master end
//!
//! This function is used by the Master module to initiate completion of a
//! multi-byte reception. This function receives the current byte and initiates
//! the STOP from master to slave.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! Modified bits are \b UCTXSTP of \b UCBxCTLW0 register.
//!
//! \return Received byte at Master end.
//
//*****************************************************************************
uint8_t EUSCI_B_I2C_masterMultiByteReceiveFinish(uint32_t baseAddress)
{
        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;

        //Wait for Stop to finish
        while (HWREG16(baseAddress + OFS_UCBxCTLW0) & UCTXSTP)

                // Wait for RX buffer
                while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCRXIFG)) ;

        //Capture data from receive buffer after setting stop bit due to
        //MSP430 I2C critical timing.
        return HWREG16(baseAddress + OFS_UCBxRXBUF);
}

//*****************************************************************************
//
//! \brief Finishes multi-byte reception at the Master end with timeout
//!
//! This function is used by the Master module to initiate completion of a
//! multi-byte reception. This function receives the current byte and initiates
//! the STOP from master to slave.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param txData is a pointer to the location to store the received byte at
//!        master end
//! \param timeout is the amount of time to wait until giving up
//!
//! Modified bits are \b UCTXSTP of \b UCBxCTLW0 register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the reception process
//
//*****************************************************************************
bool EUSCI_B_I2C_masterMultiByteReceiveFinishWithTimeout(uint32_t baseAddress,
                                                         uint8_t *txData,
                                                         uint32_t timeout
                                                         )
{
        assert(timeout > 0);

        uint32_t timeout2 = timeout;

        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;

        //Wait for Stop to finish
        while ((HWREG16(baseAddress + OFS_UCBxCTLW0) & UCTXSTP) && --timeout) ;

        //Check if transfer timed out
        if (timeout == 0)
                return STATUS_FAIL;

        // Wait for RX buffer
        while ((!(HWREG16(baseAddress + OFS_UCBxIFG) & UCRXIFG)) && --timeout2) ;

        //Check if transfer timed out
        if (timeout2 == 0)
                return STATUS_FAIL;

        //Capture data from receive buffer after setting stop bit due to
        //MSP430 I2C critical timing.
        *txData = (HWREG8(baseAddress + OFS_UCBxRXBUF));

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Sends the STOP at the end of a multi-byte reception at the Master
//! end
//!
//! This function is used by the Master module to initiate STOP
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! Modified bits are \b UCTXSTP of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_masterMultiByteReceiveStop(uint32_t baseAddress)
{
        //Send stop condition.
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCTXSTP;
}

//*****************************************************************************
//
//! \brief Enables Multi Master Mode
//!
//! At the end of this function, the I2C module is still disabled till
//! EUSCI_B_I2C_enable is invoked
//!
//! \param baseAddress is the base address of the I2C module.
//!
//! Modified bits are \b UCSWRST and \b UCMM of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_enableMultiMasterMode(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCSWRST;
        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCMM;
}

//*****************************************************************************
//
//! \brief Disables Multi Master Mode
//!
//! At the end of this function, the I2C module is still disabled till
//! EUSCI_B_I2C_enable is invoked
//!
//! \param baseAddress is the base address of the I2C module.
//!
//! Modified bits are \b UCSWRST and \b UCMM of \b UCBxCTLW0 register.
//!
//! \return None
//
//*****************************************************************************
void EUSCI_B_I2C_disableMultiMasterMode(uint32_t baseAddress)
{

        HWREG16(baseAddress + OFS_UCBxCTLW0) |= UCSWRST;
        HWREG16(baseAddress + OFS_UCBxCTLW0) &= ~UCMM;
}

//*****************************************************************************
//
//! \brief receives a byte that has been sent to the I2C Master Module.
//!
//! This function reads a byte of data from the I2C receive data Register.
//!
//! \param baseAddress is the base address of the I2C Master module.
//!
//! \return Returns the byte received from by the I2C module, cast as an
//!         uint8_t.
//
//*****************************************************************************
uint8_t EUSCI_B_I2C_masterSingleReceive(uint32_t baseAddress)
{
        //Polling RXIFG0 if RXIE is not enabled
        if (!(HWREG16(baseAddress + OFS_UCBxIE) & UCRXIE0))
                while (!(HWREG16(baseAddress + OFS_UCBxIFG) & UCRXIFG0)) ;

        //Read a byte.
        return HWREG16(baseAddress + OFS_UCBxRXBUF);
}

//*****************************************************************************
//
//! \brief Returns the address of the RX Buffer of the I2C for the DMA module.
//!
//! Returns the address of the I2C RX Buffer. This can be used in conjunction
//! with the DMA to store the received data directly to memory.
//!
//! \param baseAddress is the base address of the I2C module.
//!
//! \return The address of the I2C RX Buffer
//
//*****************************************************************************
uint32_t EUSCI_B_I2C_getReceiveBufferAddress(uint32_t baseAddress)
{
        return baseAddress + OFS_UCBxRXBUF;
}

//*****************************************************************************
//
//! \brief Returns the address of the TX Buffer of the I2C for the DMA module.
//!
//! Returns the address of the I2C TX Buffer. This can be used in conjunction
//! with the DMA to obtain transmitted data directly from memory.
//!
//! \param baseAddress is the base address of the I2C module.
//!
//! \return The address of the I2C TX Buffer
//
//*****************************************************************************
uint32_t EUSCI_B_I2C_getTransmitBufferAddress(uint32_t baseAddress)
{
        return baseAddress + OFS_UCBxTXBUF;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for eusci_b_i2c_api
//! @}
//
//*****************************************************************************

#endif
