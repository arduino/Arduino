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
// eusci_a_spi.h - Driver for the EUSCI_A_SPI Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_EUSCI_A_SPI_H__
#define __MSP430WARE_EUSCI_A_SPI_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_EUSCI_Ax__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// The following are values that can be passed to the clockPhase parameter for
// functions: EUSCI_A_SPI_masterInit(), EUSCI_A_SPI_slaveInit(), and
// EUSCI_A_SPI_changeClockPhasePolarity().
//
//*****************************************************************************
#define EUSCI_A_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT            0x00
#define EUSCI_A_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT          UCCKPH

//*****************************************************************************
//
// The following are values that can be passed to the msbFirst parameter for
// functions: EUSCI_A_SPI_masterInit(), and EUSCI_A_SPI_slaveInit().
//
//*****************************************************************************
#define EUSCI_A_SPI_MSB_FIRST                                             UCMSB
#define EUSCI_A_SPI_LSB_FIRST                                              0x00

//*****************************************************************************
//
// The following are values that can be passed to the clockPolarity parameter
// for functions: EUSCI_A_SPI_masterInit(), EUSCI_A_SPI_slaveInit(), and
// EUSCI_A_SPI_changeClockPhasePolarity().
//
//*****************************************************************************
#define EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_HIGH                        UCCKPL
#define EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_LOW                           0x00

//*****************************************************************************
//
// The following are values that can be passed to the selectClockSource
// parameter for functions: EUSCI_A_SPI_masterInit().
//
//*****************************************************************************
#define EUSCI_A_SPI_CLOCKSOURCE_ACLK                               UCSSEL__ACLK
#define EUSCI_A_SPI_CLOCKSOURCE_SMCLK                             UCSSEL__SMCLK

//*****************************************************************************
//
// The following are values that can be passed to the spiMode parameter for
// functions: EUSCI_A_SPI_masterInit(), and EUSCI_A_SPI_slaveInit().
//
//*****************************************************************************
#define EUSCI_A_SPI_3PIN                                               UCMODE_0
#define EUSCI_A_SPI_4PIN_UCxSTE_ACTIVE_HIGH                            UCMODE_1
#define EUSCI_A_SPI_4PIN_UCxSTE_ACTIVE_LOW                             UCMODE_2

//*****************************************************************************
//
// The following are values that can be passed to the select4PinFunctionality
// parameter for functions: EUSCI_A_SPI_select4PinFunctionality().
//
//*****************************************************************************
#define EUSCI_A_SPI_PREVENT_CONFLICTS_WITH_OTHER_MASTERS                   0x00
#define EUSCI_A_SPI_ENABLE_SIGNAL_FOR_4WIRE_SLAVE                        UCSTEM

//*****************************************************************************
//
// The following are values that can be passed to the mask parameter for
// functions: EUSCI_A_SPI_enableInterrupt(), EUSCI_A_SPI_disableInterrupt(),
// EUSCI_A_SPI_getInterruptStatus(), and EUSCI_A_SPI_clearInterruptFlag() as
// well as returned by the EUSCI_A_SPI_getInterruptStatus() function.
//
//*****************************************************************************
#define EUSCI_A_SPI_TRANSMIT_INTERRUPT                                   UCTXIE
#define EUSCI_A_SPI_RECEIVE_INTERRUPT                                    UCRXIE

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the EUSCI_A_SPI_isBusy() function.
//
//*****************************************************************************
#define EUSCI_A_SPI_BUSY                                                 UCBUSY
#define EUSCI_A_SPI_NOT_BUSY                                               0x00

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void EUSCI_A_SPI_masterInit(uint32_t baseAddress,
                                   uint8_t selectClockSource,
                                   uint32_t clockSourceFrequency,
                                   uint32_t desiredSpiClock,
                                   uint16_t msbFirst,
                                   uint16_t clockPhase,
                                   uint16_t clockPolarity,
                                   uint16_t spiMode);

extern void EUSCI_A_SPI_select4PinFunctionality(uint32_t baseAddress,
                                                uint8_t select4PinFunctionality);

extern void EUSCI_A_SPI_masterChangeClock(uint32_t baseAddress,
                                          uint32_t clockSourceFrequency,
                                          uint32_t desiredSpiClock);

extern void EUSCI_A_SPI_slaveInit(uint32_t baseAddress,
                                  uint16_t msbFirst,
                                  uint16_t clockPhase,
                                  uint16_t clockPolarity,
                                  uint16_t spiMode);

extern void EUSCI_A_SPI_changeClockPhasePolarity(uint32_t baseAddress,
                                                 uint16_t clockPhase,
                                                 uint16_t clockPolarity);

extern void EUSCI_A_SPI_transmitData(uint32_t baseAddress,
                                     uint8_t transmitData);

extern uint8_t EUSCI_A_SPI_receiveData(uint32_t baseAddress);

extern void EUSCI_A_SPI_enableInterrupt(uint32_t baseAddress,
                                        uint8_t mask);

extern void EUSCI_A_SPI_disableInterrupt(uint32_t baseAddress,
                                         uint8_t mask);

extern uint8_t EUSCI_A_SPI_getInterruptStatus(uint32_t baseAddress,
                                              uint8_t mask);

extern void EUSCI_A_SPI_clearInterruptFlag(uint32_t baseAddress,
                                           uint8_t mask);

extern void EUSCI_A_SPI_enable(uint32_t baseAddress);

extern void EUSCI_A_SPI_disable(uint32_t baseAddress);

extern uint32_t EUSCI_A_SPI_getReceiveBufferAddress(uint32_t baseAddress);

extern uint32_t EUSCI_A_SPI_getTransmitBufferAddress(uint32_t baseAddress);

extern uint16_t EUSCI_A_SPI_isBusy(uint32_t baseAddress);

//*****************************************************************************
//
// The following are deprecated APIs.
//
//*****************************************************************************
#define EUSCI_A_SPI_getTransmitBufferAddressForDMA                            \
        EUSCI_A_SPI_getTransmitBufferAddress

//*****************************************************************************
//
// The following are deprecated APIs.
//
//*****************************************************************************
#define EUSCI_A_SPI_getReceiveBufferAddressForDMA                             \
        EUSCI_A_SPI_getReceiveBufferAddress

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_EUSCI_A_SPI_H__

#endif
