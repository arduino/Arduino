//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430F5529__)

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
// usci_b_spi.c - Driver for the usci_b_spi Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup usci_b_spi_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_USCI_Bx__
#include "usci_b_spi.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Initializes the SPI Master block.
//!
//! Upon successful initialization of the SPI master block, this function will
//! have set the bus speed for the master, but the SPI Master block still
//! remains disabled and must be enabled with USCI_B_SPI_enable()
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param selectClockSource selects Clock source.
//!        Valid values are:
//!        - \b USCI_B_SPI_CLOCKSOURCE_ACLK
//!        - \b USCI_B_SPI_CLOCKSOURCE_SMCLK
//! \param clockSourceFrequency is the frequency of the selected clock source
//! \param desiredSpiClock is the desired clock rate for SPI communication
//! \param msbFirst controls the direction of the receive and transmit shift
//!        register.
//!        Valid values are:
//!        - \b USCI_B_SPI_MSB_FIRST
//!        - \b USCI_B_SPI_LSB_FIRST [Default]
//! \param clockPhase is clock phase select.
//!        Valid values are:
//!        - \b USCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT
//!           [Default]
//!        - \b USCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT
//! \param clockPolarity
//!        Valid values are:
//!        - \b USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH
//!        - \b USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW [Default]
//!
//! Modified bits are \b UCSSELx and \b UCSWRST of \b UCBxCTL1 register; bits
//! \b UCCKPH, \b UCCKPL, \b UC7BIT and \b UCMSB of \b UCBxCTL0 register.
//!
//! \return STATUS_SUCCESS
//
//*****************************************************************************
bool USCI_B_SPI_masterInit(uint32_t baseAddress,
                           uint8_t selectClockSource,
                           uint32_t clockSourceFrequency,
                           uint32_t desiredSpiClock,
                           uint8_t msbFirst,
                           uint8_t clockPhase,
                           uint8_t clockPolarity
                           )
{
        assert(
                (USCI_B_SPI_CLOCKSOURCE_ACLK == selectClockSource) ||
                (USCI_B_SPI_CLOCKSOURCE_SMCLK == selectClockSource)
                );

        assert(  (USCI_B_SPI_MSB_FIRST == msbFirst) ||
                 (USCI_B_SPI_LSB_FIRST == msbFirst)
                 );

        assert(  (USCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT == clockPhase) ||
                 (USCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT == clockPhase)
                 );

        assert(  (USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH == clockPolarity) ||
                 (USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW == clockPolarity)
                 );

        //Disable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) |= UCSWRST;

        //Reset OFS_UCBxCTL0 values
        HWREG8(baseAddress + OFS_UCBxCTL0) &= ~(UCCKPH + UCCKPL + UC7BIT + UCMSB +
                                                UCMST + UCMODE_3 + UCSYNC);

        //Reset OFS_UCBxCTL1 values
        HWREG8(baseAddress + OFS_UCBxCTL1) &= ~(UCSSEL_3);

        //Select Clock
        HWREG8(baseAddress + OFS_UCBxCTL1) |= selectClockSource;

        HWREG8(baseAddress + OFS_UCBxBRW) =
                (uint16_t)(clockSourceFrequency / desiredSpiClock);

        /*
         * Configure as SPI master mode.
         * Clock phase select, polarity, msb
         * UCMST = Master mode
         * UCSYNC = Synchronous mode
         * UCMODE_0 = 3-pin SPI
         */
        HWREG8(baseAddress + OFS_UCBxCTL0) |= (
                msbFirst +
                clockPhase +
                clockPolarity +
                UCMST +
                UCSYNC +
                UCMODE_0
                );

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Initializes the SPI Master clock.At the end of this function call,
//! SPI module is left enabled.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param clockSourceFrequency is the frequency of the selected clock source
//! \param desiredSpiClock is the desired clock rate for SPI communication
//!
//! Modified bits of \b UCAxBRW register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_masterChangeClock(uint32_t baseAddress,
                                  uint32_t clockSourceFrequency,
                                  uint32_t desiredSpiClock
                                  )
{
        //Disable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) |= UCSWRST;

        HWREG8(baseAddress + OFS_UCBxBRW) =
                (uint16_t)(clockSourceFrequency / desiredSpiClock);

        //Reset the UCSWRST bit to enable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) &= ~(UCSWRST);
}

//*****************************************************************************
//
//! \brief Initializes the SPI Slave block.
//!
//! Upon successful initialization of the SPI slave block, this function will
//! have initialized the slave block, but the SPI Slave block still remains
//! disabled and must be enabled with USCI_B_SPI_enable()
//!
//! \param baseAddress is the base address of the SPI Slave module.
//! \param msbFirst controls the direction of the receive and transmit shift
//!        register.
//!        Valid values are:
//!        - \b USCI_B_SPI_MSB_FIRST
//!        - \b USCI_B_SPI_LSB_FIRST [Default]
//! \param clockPhase is clock phase select.
//!        Valid values are:
//!        - \b USCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT
//!           [Default]
//!        - \b USCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT
//! \param clockPolarity
//!        Valid values are:
//!        - \b USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH
//!        - \b USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW [Default]
//!
//! Modified bits are \b UCSWRST of \b UCBxCTL1 register; bits \b UCMSB, \b
//! UCMST, \b UC7BIT, \b UCCKPL, \b UCCKPH and \b UCMODE of \b UCBxCTL0
//! register.
//!
//! \return STATUS_SUCCESS
//
//*****************************************************************************
bool USCI_B_SPI_slaveInit(uint32_t baseAddress,
                          uint8_t msbFirst,
                          uint8_t clockPhase,
                          uint8_t clockPolarity
                          )
{
        assert(
                (USCI_B_SPI_MSB_FIRST == msbFirst) ||
                (USCI_B_SPI_LSB_FIRST == msbFirst)
                );

        assert(
                (USCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT == clockPhase) ||
                (USCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT == clockPhase)
                );

        assert(
                (USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH == clockPolarity) ||
                (USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW == clockPolarity)
                );

        //Disable USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1)  |= UCSWRST;

        //Reset OFS_UCBxCTL0 register
        HWREG8(baseAddress + OFS_UCBxCTL0) &= ~(UCMSB +
                                                UC7BIT +
                                                UCMST +
                                                UCCKPL +
                                                UCCKPH +
                                                UCMODE_3
                                                );

        //Clock polarity, phase select, msbFirst, SYNC, Mode0
        HWREG8(baseAddress + OFS_UCBxCTL0) |= ( clockPhase +
                                                clockPolarity +
                                                msbFirst +
                                                UCSYNC +
                                                UCMODE_0
                                                );

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Changes the SPI clock phase and polarity.At the end of this function
//! call, SPI module is left enabled.
//!
//! \param baseAddress is the base address of the I2C Master module.
//! \param clockPhase is clock phase select.
//!        Valid values are:
//!        - \b USCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT
//!           [Default]
//!        - \b USCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT
//! \param clockPolarity
//!        Valid values are:
//!        - \b USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH
//!        - \b USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW [Default]
//!
//! Modified bits are \b UCCKPL and \b UCCKPH of \b UCAxCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_changeClockPhasePolarity(uint32_t baseAddress,
                                         uint8_t clockPhase,
                                         uint8_t clockPolarity
                                         )
{

        assert(  (USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH == clockPolarity) ||
                 (USCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW == clockPolarity)
                 );

        //Disable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) |= UCSWRST;

        HWREG8(baseAddress + OFS_UCBxCTL0) &= ~(UCCKPH + UCCKPL);

        HWREG8(baseAddress + OFS_UCBxCTL0) |= (
                clockPhase +
                clockPolarity
                );

        //Reset the UCSWRST bit to enable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) &= ~(UCSWRST);
}

//*****************************************************************************
//
//! \brief Transmits a byte from the SPI Module.
//!
//! This function will place the supplied data into SPI transmit data register
//! to start transmission
//!
//! \param baseAddress is the base address of the SPI module.
//! \param transmitData data to be transmitted from the SPI module
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_transmitData( uint32_t baseAddress,
                              uint8_t transmitData
                              )
{
        HWREG8(baseAddress + OFS_UCBxTXBUF) = transmitData;
}

//*****************************************************************************
//
//! \brief Receives a byte that has been sent to the SPI Module.
//!
//! This function reads a byte of data from the SPI receive data Register.
//!
//! \param baseAddress is the base address of the SPI module.
//!
//! \return Returns the byte received from by the SPI module, cast as an
//!         uint8_t.
//
//*****************************************************************************
uint8_t USCI_B_SPI_receiveData(uint32_t baseAddress)
{
        return HWREG8(baseAddress + OFS_UCBxRXBUF);
}

//*****************************************************************************
//
//! \brief Enables individual SPI interrupt sources.
//!
//! Enables the indicated SPI interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor. <b>Does not clear interrupt flags.
//!
//! \param baseAddress is the base address of the SPI module.
//! \param mask is the bit mask of the interrupt sources to be enabled.
//!        Valid values are:
//!        - \b USCI_B_SPI_TRANSMIT_INTERRUPT
//!        - \b USCI_B_SPI_RECEIVE_INTERRUPT
//!
//! Modified bits of \b UCBxIE register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_enableInterrupt(uint32_t baseAddress,
                                uint8_t mask
                                )
{
        assert( 0x00 != mask && (USCI_B_SPI_RECEIVE_INTERRUPT +
                                 USCI_B_SPI_TRANSMIT_INTERRUPT
                                 ));

        HWREG8(baseAddress + OFS_UCBxIE) |= mask;
}

//*****************************************************************************
//
//! \brief Disables individual SPI interrupt sources.
//!
//! Disables the indicated SPI interrupt sources. Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! \param baseAddress is the base address of the SPI module.
//! \param mask is the bit mask of the interrupt sources to be disabled.
//!        Valid values are:
//!        - \b USCI_B_SPI_TRANSMIT_INTERRUPT
//!        - \b USCI_B_SPI_RECEIVE_INTERRUPT
//!
//! Modified bits of \b UCBxIE register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_disableInterrupt(uint32_t baseAddress,
                                 uint8_t mask
                                 )
{
        assert( 0x00 != mask && (USCI_B_SPI_RECEIVE_INTERRUPT +
                                 USCI_B_SPI_TRANSMIT_INTERRUPT
                                 ));

        HWREG8(baseAddress + OFS_UCBxIE) &= ~mask;
}

//*****************************************************************************
//
//! \brief Gets the current SPI interrupt status.
//!
//! This returns the interrupt status for the SPI module based on which flag is
//! passed.
//!
//! \param baseAddress is the base address of the SPI module.
//! \param mask is the masked interrupt flag status to be returned.
//!        Valid values are:
//!        - \b USCI_B_SPI_TRANSMIT_INTERRUPT
//!        - \b USCI_B_SPI_RECEIVE_INTERRUPT
//!
//! \return The current interrupt status as the mask of the set flags
//!         Return Logical OR of any of the following:
//!         - \b USCI_B_SPI_TRANSMIT_INTERRUPT
//!         - \b USCI_B_SPI_RECEIVE_INTERRUPT
//!         \n indicating the status of the masked interrupts
//
//*****************************************************************************
uint8_t USCI_B_SPI_getInterruptStatus(uint32_t baseAddress,
                                      uint8_t mask
                                      )
{
        assert( 0x00 != mask && (USCI_B_SPI_RECEIVE_INTERRUPT +
                                 USCI_B_SPI_TRANSMIT_INTERRUPT
                                 ));

        return HWREG8(baseAddress + OFS_UCBxIFG) & mask;
}

//*****************************************************************************
//
//! \brief Clears the selected SPI interrupt status flag.
//!
//! \param baseAddress is the base address of the SPI module.
//! \param mask is the masked interrupt flag to be cleared.
//!        Valid values are:
//!        - \b USCI_B_SPI_TRANSMIT_INTERRUPT
//!        - \b USCI_B_SPI_RECEIVE_INTERRUPT
//!
//! Modified bits of \b UCBxIFG register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_clearInterruptFlag(uint32_t baseAddress,
                                   uint8_t mask
                                   )
{
        assert( 0x00 != mask && (USCI_B_SPI_RECEIVE_INTERRUPT +
                                 USCI_B_SPI_TRANSMIT_INTERRUPT
                                 ));

        HWREG8(baseAddress + OFS_UCBxIFG) &=  ~mask;
}

//*****************************************************************************
//
//! \brief Enables the SPI block.
//!
//! This will enable operation of the SPI block.
//!
//! \param baseAddress is the base address of the USCI SPI module.
//!
//! Modified bits are \b UCSWRST of \b UCBxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_enable(uint32_t baseAddress)
{
        //Reset the UCSWRST bit to enable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) &= ~(UCSWRST);
}

//*****************************************************************************
//
//! \brief Disables the SPI block.
//!
//! This will disable operation of the SPI block.
//!
//! \param baseAddress is the base address of the USCI SPI module.
//!
//! Modified bits are \b UCSWRST of \b UCBxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_B_SPI_disable(uint32_t baseAddress)
{
        //Set the UCSWRST bit to disable the USCI Module
        HWREG8(baseAddress + OFS_UCBxCTL1) |= UCSWRST;
}

//*****************************************************************************
//
//! \brief Returns the address of the RX Buffer of the SPI for the DMA module.
//!
//! Returns the address of the SPI RX Buffer. This can be used in conjunction
//! with the DMA to store the received data directly to memory.
//!
//! \param baseAddress is the base address of the SPI module.
//!
//! \return The address of the SPI RX buffer
//
//*****************************************************************************
uint32_t USCI_B_SPI_getReceiveBufferAddressForDMA(uint32_t baseAddress)
{
        return baseAddress + OFS_UCBxRXBUF;
}

//*****************************************************************************
//
//! \brief Returns the address of the TX Buffer of the SPI for the DMA module.
//!
//! Returns the address of the SPI TX Buffer. This can be used in conjunction
//! with the DMA to obtain transmitted data directly from memory.
//!
//! \param baseAddress is the base address of the SPI module.
//!
//! \return The address of the SPI TX buffer
//
//*****************************************************************************
uint32_t USCI_B_SPI_getTransmitBufferAddressForDMA(uint32_t baseAddress)
{
        return baseAddress + OFS_UCBxTXBUF;
}

//*****************************************************************************
//
//! \brief Indicates whether or not the SPI bus is busy.
//!
//! This function returns an indication of whether or not the SPI bus is
//! busy.This function checks the status of the bus via UCBBUSY bit
//!
//! \param baseAddress is the base address of the SPI module.
//!
//! \return USCI_B_SPI_BUSY if the SPI module transmitting or receiving is
//!         busy; otherwise, returns USCI_B_SPI_NOT_BUSY.
//!         Return one of the following:
//!         - \b USCI_B_SPI_BUSY
//!         - \b USCI_B_SPI_NOT_BUSY
//!         \n indicating if the USCI_B_SPI is busy
//
//*****************************************************************************
uint8_t USCI_B_SPI_isBusy(uint32_t baseAddress)
{
        //Return the bus busy status.
        return HWREG8(baseAddress + OFS_UCBxSTAT) & UCBUSY;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for usci_b_spi_api
//! @}
//
//*****************************************************************************

#endif
