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
// usci_a_uart.c - Driver for the usci_a_uart Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup usci_a_uart_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_USCI_Ax__
#include "usci_a_uart.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Advanced initialization routine for the UART block. The values to be
//! written into the clockPrescalar, firstModReg, secondModReg and overSampling
//! parameters should be pre-computed and passed into the initialization
//! function.
//!
//! Upon successful initialization of the UART block, this function will have
//! initialized the module, but the UART block still remains disabled and must
//! be enabled with USCI_A_UART_enable(). To calculate values for
//! clockPrescalar, firstModReg, secondModReg and overSampling please use the
//! link below.
//!
//! http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param selectClockSource selects Clock source.
//!        Valid values are:
//!        - \b USCI_A_UART_CLOCKSOURCE_SMCLK
//!        - \b USCI_A_UART_CLOCKSOURCE_ACLK
//! \param clockPrescalar is the value to be written into UCBRx bits
//! \param firstModReg is First modulation stage register setting. This value
//!        is a pre-calculated value which can be obtained from the Device
//!        Users Guide. This value is written into UCBRFx bits of UCAxMCTLW.
//! \param secondModReg is Second modulation stage register setting. This value
//!        is a pre-calculated value which can be obtained from the Device
//!        Users Guide. This value is written into UCBRSx bits of UCAxMCTLW.
//! \param parity is the desired parity.
//!        Valid values are:
//!        - \b USCI_A_UART_NO_PARITY [Default]
//!        - \b USCI_A_UART_ODD_PARITY
//!        - \b USCI_A_UART_EVEN_PARITY
//! \param msborLsbFirst controls direction of receive and transmit shift
//!        register.
//!        Valid values are:
//!        - \b USCI_A_UART_MSB_FIRST
//!        - \b USCI_A_UART_LSB_FIRST [Default]
//! \param numberofStopBits indicates one/two STOP bits
//!        Valid values are:
//!        - \b USCI_A_UART_ONE_STOP_BIT [Default]
//!        - \b USCI_A_UART_TWO_STOP_BITS
//! \param uartMode selects the mode of operation
//!        Valid values are:
//!        - \b USCI_A_UART_MODE [Default]
//!        - \b USCI_A_UART_IDLE_LINE_MULTI_PROCESSOR_MODE
//!        - \b USCI_A_UART_ADDRESS_BIT_MULTI_PROCESSOR_MODE
//!        - \b USCI_A_UART_AUTOMATIC_BAUDRATE_DETECTION_MODE
//! \param overSampling indicates low frequency or oversampling baud generation
//!        Valid values are:
//!        - \b USCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
//!        - \b USCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION
//!
//! Modified bits are \b UCPEN, \b UCPAR, \b UCMSB, \b UC7BIT, \b UCSPB, \b
//! UCMODEx and \b UCSYNC of \b UCAxCTL0 register; bits \b UCSSELx and \b
//! UCSWRST of \b UCAxCTL1 register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL of the initialization process
//
//*****************************************************************************
bool USCI_A_UART_initAdvance( uint32_t baseAddress,
                              uint8_t selectClockSource,
                              uint16_t clockPrescalar,
                              uint8_t firstModReg,
                              uint8_t secondModReg,
                              uint8_t parity,
                              uint8_t msborLsbFirst,
                              uint8_t numberofStopBits,
                              uint8_t uartMode,
                              uint8_t overSampling
                              )
{
        assert(
                (USCI_A_UART_MODE == uartMode) ||
                (USCI_A_UART_IDLE_LINE_MULTI_PROCESSOR_MODE == uartMode) ||
                (USCI_A_UART_ADDRESS_BIT_MULTI_PROCESSOR_MODE == uartMode) ||
                (USCI_A_UART_AUTOMATIC_BAUDRATE_DETECTION_MODE == uartMode)
                );

        assert(
                (USCI_A_UART_CLOCKSOURCE_ACLK == selectClockSource) ||
                (USCI_A_UART_CLOCKSOURCE_SMCLK == selectClockSource)
                );

        assert(
                (USCI_A_UART_MSB_FIRST == msborLsbFirst) ||
                (USCI_A_UART_LSB_FIRST == msborLsbFirst)
                );

        assert(
                (USCI_A_UART_ONE_STOP_BIT == numberofStopBits) ||
                (USCI_A_UART_TWO_STOP_BITS == numberofStopBits)
                );

        assert(
                (USCI_A_UART_NO_PARITY == parity) ||
                (USCI_A_UART_ODD_PARITY == parity) ||
                (USCI_A_UART_EVEN_PARITY == parity)
                );

        bool retVal = STATUS_SUCCESS;

        //Disable the USCI Module
        HWREG8(baseAddress + OFS_UCAxCTL1) |= UCSWRST;

        //Clock source select
        HWREG8(baseAddress + OFS_UCAxCTL1) &= ~UCSSEL_3;
        HWREG8(baseAddress + OFS_UCAxCTL1) |= selectClockSource;

        //MSB, LSB select
        HWREG8(baseAddress + OFS_UCAxCTL0) &= ~UCMSB;
        HWREG8(baseAddress + OFS_UCAxCTL0) |= msborLsbFirst;

        //UCSPB = 0(1 stop bit) OR 1(2 stop bits)
        HWREG8(baseAddress + OFS_UCAxCTL0) &= ~UCSPB;
        HWREG8(baseAddress + OFS_UCAxCTL0) |= numberofStopBits;

        //Parity
        switch (parity) {
        case USCI_A_UART_NO_PARITY:
                //No Parity
                HWREG8(baseAddress + OFS_UCAxCTL0) &= ~UCPEN;
                break;
        case USCI_A_UART_ODD_PARITY:
                //Odd Parity
                HWREG8(baseAddress + OFS_UCAxCTL0) |= UCPEN;
                HWREG8(baseAddress + OFS_UCAxCTL0) &= ~UCPAR;
                break;
        case USCI_A_UART_EVEN_PARITY:
                //Even Parity
                HWREG8(baseAddress + OFS_UCAxCTL0) |= UCPEN;
                HWREG8(baseAddress + OFS_UCAxCTL0) |= UCPAR;
                break;
        }

        //Modulation Control Registers
        HWREG8(baseAddress + OFS_UCAxBRW ) = clockPrescalar;
        HWREG8(baseAddress + OFS_UCAxMCTL) = ((firstModReg << 4) + (secondModReg << 1) +
                                              overSampling );

        //Asynchronous mode & 8 bit character select & clear mode
        HWREG8(baseAddress + OFS_UCAxCTL0) &=  ~(UCSYNC +
                                                 UC7BIT +
                                                 UCMODE_3
                                                 );

        //Configure  UART mode.
        HWREG8(baseAddress + OFS_UCAxCTL0) |= uartMode;

        //Reset UCRXIE, UCBRKIE, UCDORM, UCTXADDR, UCTXBRK
        HWREG8(baseAddress + OFS_UCAxCTL1)  &= ~(UCRXEIE + UCBRKIE + UCDORM +
                                                 UCTXADDR + UCTXBRK
                                                 );

        return retVal;
}

//*****************************************************************************
//
//! \brief Transmits a byte from the UART Module.
//!
//! This function will place the supplied data into UART transmit data register
//! to start transmission
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param transmitData data to be transmitted from the UART module
//!
//! Modified bits of \b UCAxTXBUF register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_transmitData( uint32_t baseAddress,
                               uint8_t transmitData
                               )
{
        //If interrupts are not used, poll for flags
        if (!(HWREG8(baseAddress + OFS_UCAxIE) & UCTXIE))
                //Poll for transmit interrupt flag
                while (!(HWREG8(baseAddress + OFS_UCAxIFG) & UCTXIFG)) ;

        HWREG8(baseAddress + OFS_UCAxTXBUF) = transmitData;
}

//*****************************************************************************
//
//! \brief Receives a byte that has been sent to the UART Module.
//!
//! This function reads a byte of data from the UART receive data Register.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! Modified bits of \b UCAxRXBUF register.
//!
//! \return Returns the byte received from by the UART module, cast as an
//!         uint8_t.
//
//*****************************************************************************
uint8_t USCI_A_UART_receiveData(uint32_t baseAddress)
{
        //If interrupts are not used, poll for flags
        if (!(HWREG8(baseAddress + OFS_UCAxIE) & UCRXIE))
                //Poll for receive interrupt flag
                while (!(HWREG8(baseAddress + OFS_UCAxIFG) & UCRXIFG)) ;

        return HWREG8(baseAddress + OFS_UCAxRXBUF);
}

//*****************************************************************************
//
//! \brief Enables individual UART interrupt sources.
//!
//! Enables the indicated UART interrupt sources.  The interrupt flag is first
//! and then the corresponding interrupt is enabled. Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor. Does not clear interrupt flags.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param mask is the bit mask of the interrupt sources to be enabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b USCI_A_UART_RECEIVE_INTERRUPT - Receive interrupt
//!        - \b USCI_A_UART_TRANSMIT_INTERRUPT - Transmit interrupt
//!        - \b USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT - Receive
//!           erroneous-character interrupt enable
//!        - \b USCI_A_UART_BREAKCHAR_INTERRUPT - Receive break character
//!           interrupt enable
//!
//! Modified bits of \b UCAxCTL1 register and bits of \b UCAxIE register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_enableInterrupt(uint32_t baseAddress,
                                 uint8_t mask
                                 )
{
        assert(!(mask & ~(USCI_A_UART_RECEIVE_INTERRUPT
                          | USCI_A_UART_TRANSMIT_INTERRUPT
                          | USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT
                          | USCI_A_UART_BREAKCHAR_INTERRUPT)));

        uint8_t locMask;

        locMask = (mask & (USCI_A_UART_RECEIVE_INTERRUPT
                           | USCI_A_UART_TRANSMIT_INTERRUPT));
        HWREG8(baseAddress + OFS_UCAxIE) |= locMask;

        locMask = (mask & (USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT
                           | USCI_A_UART_BREAKCHAR_INTERRUPT));
        HWREG8(baseAddress + OFS_UCAxCTL1) |= locMask;
}

//*****************************************************************************
//
//! \brief Disables individual UART interrupt sources.
//!
//! Disables the indicated UART interrupt sources. Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param mask is the bit mask of the interrupt sources to be disabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b USCI_A_UART_RECEIVE_INTERRUPT - Receive interrupt
//!        - \b USCI_A_UART_TRANSMIT_INTERRUPT - Transmit interrupt
//!        - \b USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT - Receive
//!           erroneous-character interrupt enable
//!        - \b USCI_A_UART_BREAKCHAR_INTERRUPT - Receive break character
//!           interrupt enable
//!
//! Modified bits of \b UCAxCTL1 register and bits of \b UCAxIE register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_disableInterrupt(uint32_t baseAddress,
                                  uint8_t mask
                                  )
{
        assert(!(mask & ~(USCI_A_UART_RECEIVE_INTERRUPT
                          | USCI_A_UART_TRANSMIT_INTERRUPT
                          | USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT
                          | USCI_A_UART_BREAKCHAR_INTERRUPT)));

        uint8_t locMask;

        if (locMask = (mask & (USCI_A_UART_RECEIVE_INTERRUPT
                               | USCI_A_UART_TRANSMIT_INTERRUPT)))
                HWREG8(baseAddress + OFS_UCAxIE) &= ~locMask;

        if (locMask = (mask & (USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT
                               | USCI_A_UART_BREAKCHAR_INTERRUPT)))
                HWREG8(baseAddress + OFS_UCAxCTL1) &= ~locMask;
}

//*****************************************************************************
//
//! \brief Gets the current UART interrupt status.
//!
//! This returns the interrupt status for the UART module based on which flag
//! is passed.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param mask is the masked interrupt flag status to be returned.
//!        Mask value is the logical OR of any of the following:
//!        - \b USCI_A_UART_RECEIVE_INTERRUPT_FLAG - Receive interrupt flag
//!        - \b USCI_A_UART_TRANSMIT_INTERRUPT_FLAG - Transmit interrupt flag
//!
//! Modified bits of \b UCAxIFG register.
//!
//! \return Logical OR of any of the following:
//!         - \b USCI_A_UART_RECEIVE_INTERRUPT_FLAG Receive interrupt flag
//!         - \b USCI_A_UART_TRANSMIT_INTERRUPT_FLAG Transmit interrupt flag
//!         \n indicating the status of the masked flags
//
//*****************************************************************************
uint8_t USCI_A_UART_getInterruptStatus(uint32_t baseAddress,
                                       uint8_t mask)
{
        assert(!(mask & ~(USCI_A_UART_RECEIVE_INTERRUPT_FLAG
                          | USCI_A_UART_TRANSMIT_INTERRUPT_FLAG)));

        return HWREG8(baseAddress + OFS_UCAxIFG) & mask;
}

//*****************************************************************************
//
//! \brief Clears UART interrupt sources.
//!
//! The UART interrupt source is cleared, so that it no longer asserts. The
//! highest interrupt flag is automatically cleared when an interrupt vector
//! generator is used.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param mask is a bit mask of the interrupt sources to be cleared.
//!        Mask value is the logical OR of any of the following:
//!        - \b USCI_A_UART_RECEIVE_INTERRUPT_FLAG - Receive interrupt flag
//!        - \b USCI_A_UART_TRANSMIT_INTERRUPT_FLAG - Transmit interrupt flag
//!
//! Modified bits of \b UCAxIFG register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_clearInterruptFlag(uint32_t baseAddress, uint8_t mask)
{
        assert(!(mask & ~(USCI_A_UART_RECEIVE_INTERRUPT_FLAG
                          | USCI_A_UART_TRANSMIT_INTERRUPT_FLAG)));

        //Clear the UART interrupt source.
        HWREG8(baseAddress + OFS_UCAxIFG) &= ~(mask);
}

//*****************************************************************************
//
//! \brief Enables the UART block.
//!
//! This will enable operation of the UART block.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! Modified bits are \b UCSWRST of \b UCAxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_enable(uint32_t baseAddress)
{
        //Reset the UCSWRST bit to enable the USCI Module
        HWREG8(baseAddress + OFS_UCAxCTL1) &= ~(UCSWRST);
}

//*****************************************************************************
//
//! \brief Disables the UART block.
//!
//! This will disable operation of the UART block.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! Modified bits are \b UCSWRST of \b UCAxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_disable(uint32_t baseAddress)
{
        //Set the UCSWRST bit to disable the USCI Module
        HWREG8(baseAddress + OFS_UCAxCTL1) |= UCSWRST;
}

//*****************************************************************************
//
//! \brief Gets the current UART status flags.
//!
//! This returns the status for the UART module based on which flag is passed.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param mask is the masked interrupt flag status to be returned.
//!        Mask value is the logical OR of any of the following:
//!        - \b USCI_A_UART_LISTEN_ENABLE
//!        - \b USCI_A_UART_FRAMING_ERROR
//!        - \b USCI_A_UART_OVERRUN_ERROR
//!        - \b USCI_A_UART_PARITY_ERROR
//!        - \b USCI_A_UART_BREAK_DETECT
//!        - \b USCI_A_UART_RECEIVE_ERROR
//!        - \b USCI_A_UART_ADDRESS_RECEIVED
//!        - \b USCI_A_UART_IDLELINE
//!        - \b USCI_A_UART_BUSY
//!
//! Modified bits of \b UCAxSTAT register.
//!
//! \return Logical OR of any of the following:
//!         - \b USCI_A_UART_LISTEN_ENABLE
//!         - \b USCI_A_UART_FRAMING_ERROR
//!         - \b USCI_A_UART_OVERRUN_ERROR
//!         - \b USCI_A_UART_PARITY_ERROR
//!         - \b USCI_A_UART_BREAK_DETECT
//!         - \b USCI_A_UART_RECEIVE_ERROR
//!         - \b USCI_A_UART_ADDRESS_RECEIVED
//!         - \b USCI_A_UART_IDLELINE
//!         - \b USCI_A_UART_BUSY
//!         \n indicating the status of the masked interrupt flags
//
//*****************************************************************************
uint8_t USCI_A_UART_queryStatusFlags(uint32_t baseAddress,
                                     uint8_t mask)
{
        assert(0x00 != mask && (USCI_A_UART_LISTEN_ENABLE +
                                USCI_A_UART_FRAMING_ERROR +
                                USCI_A_UART_OVERRUN_ERROR +
                                USCI_A_UART_PARITY_ERROR +
                                USCI_A_UART_BREAK_DETECT +
                                USCI_A_UART_RECEIVE_ERROR +
                                USCI_A_UART_ADDRESS_RECEIVED +
                                USCI_A_UART_IDLELINE +
                                USCI_A_UART_BUSY
                                ));

        return HWREG8(baseAddress + OFS_UCAxSTAT) & mask;
}

//*****************************************************************************
//
//! \brief Sets the UART module in dormant mode
//!
//! Puts USCI in sleep mode. Only characters that are preceded by an idle-line
//! or with address bit set UCRXIFG. In UART mode with automatic baud-rate
//! detection, only the combination of a break and sync field sets UCRXIFG.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! Modified bits of \b UCAxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_setDormant(uint32_t baseAddress)
{
        HWREG8(baseAddress + OFS_UCAxCTL1) |= UCDORM;
}

//*****************************************************************************
//
//! \brief Re-enables UART module from dormant mode
//!
//! Not dormant. All received characters set UCRXIFG.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! Modified bits are \b UCDORM of \b UCAxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_resetDormant(uint32_t baseAddress)
{
        HWREG8(baseAddress + OFS_UCAxCTL1) &= ~UCDORM;
}

//*****************************************************************************
//
//! \brief Transmits the next byte to be transmitted marked as address
//! depending on selected multiprocessor mode
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//! \param transmitAddress is the next byte to be transmitted
//!
//! Modified bits of \b UCAxTXBUF register and bits of \b UCAxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_transmitAddress(uint32_t baseAddress,
                                 uint8_t transmitAddress)
{
        //Set UCTXADDR bit
        HWREG8(baseAddress + OFS_UCAxCTL1) |= UCTXADDR;

        //Place next byte to be sent into the transmit buffer
        HWREG8(baseAddress + OFS_UCAxTXBUF) = transmitAddress;
}

//*****************************************************************************
//
//! \brief Transmit break.
//!
//! Transmits a break with the next write to the transmit buffer. In UART mode
//! with automatic baud-rate detection,
//! USCI_A_UART_AUTOMATICBAUDRATE_SYNC(0x55) must be written into UCAxTXBUF to
//! generate the required break/sync fields. Otherwise, DEFAULT_SYNC(0x00) must
//! be written into the transmit buffer. Also ensures module is ready for
//! transmitting the next data.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! Modified bits of \b UCAxTXBUF register and bits of \b UCAxCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void USCI_A_UART_transmitBreak(uint32_t baseAddress)
{
        //Set UCTXADDR bit
        HWREG8(baseAddress + OFS_UCAxCTL1) |= UCTXBRK;

        //If current mode is automatic baud-rate detection
        if (USCI_A_UART_AUTOMATIC_BAUDRATE_DETECTION_MODE ==
            (HWREG8(baseAddress + OFS_UCAxCTL0) &
             USCI_A_UART_AUTOMATIC_BAUDRATE_DETECTION_MODE))
                HWREG8(baseAddress + OFS_UCAxTXBUF) = USCI_A_UART_AUTOMATICBAUDRATE_SYNC;
        else
                HWREG8(baseAddress + OFS_UCAxTXBUF) = DEFAULT_SYNC;

        //If interrupts are not used, poll for flags
        if (!(HWREG8(baseAddress + OFS_UCAxIE) & UCTXIE))
                //Poll for transmit interrupt flag
                while (!(HWREG8(baseAddress + OFS_UCAxIFG) & UCTXIFG)) ;
}

//*****************************************************************************
//
//! \brief Returns the address of the RX Buffer of the UART for the DMA module.
//!
//! Returns the address of the UART RX Buffer. This can be used in conjunction
//! with the DMA to store the received data directly to memory.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! \return Address of RX Buffer
//
//*****************************************************************************
uint32_t USCI_A_UART_getReceiveBufferAddressForDMA(uint32_t baseAddress)
{
        return baseAddress + OFS_UCAxRXBUF;
}

//*****************************************************************************
//
//! \brief Returns the address of the TX Buffer of the UART for the DMA module.
//!
//! Returns the address of the UART TX Buffer. This can be used in conjunction
//! with the DMA to obtain transmitted data directly from memory.
//!
//! \param baseAddress is the base address of the USCI_A_UART module.
//!
//! \return Address of TX Buffer
//
//*****************************************************************************
uint32_t USCI_A_UART_getTransmitBufferAddressForDMA(uint32_t baseAddress)
{
        return baseAddress + OFS_UCAxTXBUF;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for usci_a_uart_api
//! @}
//
//*****************************************************************************

#endif
