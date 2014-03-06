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
// usci_b_i2c.h - Driver for the USCI_B_I2C Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_USCI_B_I2C_H__
#define __MSP430WARE_USCI_B_I2C_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_USCI_Bx__

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
// The following are values that can be passed to the selectClockSource
// parameter for functions: USCI_B_I2C_masterInit().
//
//*****************************************************************************
#define USCI_B_I2C_CLOCKSOURCE_ACLK                                UCSSEL__ACLK
#define USCI_B_I2C_CLOCKSOURCE_SMCLK                              UCSSEL__SMCLK

//*****************************************************************************
//
// The following are values that can be passed to the dataRate parameter for
// functions: USCI_B_I2C_masterInit().
//
//*****************************************************************************
#define USCI_B_I2C_SET_DATA_RATE_400KBPS                                 400000
#define USCI_B_I2C_SET_DATA_RATE_100KBPS                                 100000

//*****************************************************************************
//
// The following are values that can be passed to the mode parameter for
// functions: USCI_B_I2C_setMode().
//
//*****************************************************************************
#define USCI_B_I2C_TRANSMIT_MODE                                           UCTR
#define USCI_B_I2C_RECEIVE_MODE                                            0x00

//*****************************************************************************
//
// The following are values that can be passed to the mask parameter for
// functions: USCI_B_I2C_enableInterrupt(), USCI_B_I2C_disableInterrupt(),
// USCI_B_I2C_clearInterruptFlag(), and USCI_B_I2C_getInterruptStatus() as well
// as returned by the USCI_B_I2C_getInterruptStatus() function.
//
//*****************************************************************************
#define USCI_B_I2C_STOP_INTERRUPT                                       UCSTPIE
#define USCI_B_I2C_START_INTERRUPT                                      UCSTTIE
#define USCI_B_I2C_RECEIVE_INTERRUPT                                     UCRXIE
#define USCI_B_I2C_TRANSMIT_INTERRUPT                                    UCTXIE
#define USCI_B_I2C_NAK_INTERRUPT                                       UCNACKIE
#define USCI_B_I2C_ARBITRATIONLOST_INTERRUPT                             UCALIE

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the USCI_B_I2C_isBusy() function and the
// USCI_B_I2C_isBusBusy() function.
//
//*****************************************************************************
#define USCI_B_I2C_BUS_BUSY                                             UCBBUSY
#define USCI_B_I2C_BUS_NOT_BUSY                                            0x00

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the USCI_B_I2C_masterIsStartSent() function.
//
//*****************************************************************************
#define USCI_B_I2C_SENDING_START                                        UCTXSTT
#define USCI_B_I2C_START_SEND_COMPLETE                                     0x00

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the USCI_B_I2C_masterIsStopSent() function.
//
//*****************************************************************************
#define USCI_B_I2C_SENDING_STOP                                         UCTXSTP
#define USCI_B_I2C_STOP_SEND_COMPLETE                                      0x00

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void USCI_B_I2C_masterInit(uint32_t baseAddress,
                                  uint8_t selectClockSource,
                                  uint32_t i2cClk,
                                  uint32_t dataRate);

extern void USCI_B_I2C_slaveInit(uint32_t baseAddress,
                                 uint8_t slaveAddress);

extern void USCI_B_I2C_enable(uint32_t baseAddress);

extern void USCI_B_I2C_disable(uint32_t baseAddress);

extern void USCI_B_I2C_setSlaveAddress(uint32_t baseAddress,
                                       uint8_t slaveAddress);

extern void USCI_B_I2C_setMode(uint32_t baseAddress,
                               uint8_t mode);

extern void USCI_B_I2C_slaveDataPut(uint32_t baseAddress,
                                    uint8_t transmitData);

extern uint8_t USCI_B_I2C_slaveDataGet(uint32_t baseAddress);

extern uint8_t USCI_B_I2C_isBusBusy(uint32_t baseAddress);

extern uint8_t USCI_B_I2C_isBusy(uint32_t baseAddress);

extern uint8_t USCI_B_I2C_masterIsStopSent(uint32_t baseAddress);

extern uint8_t USCI_B_I2C_masterIsStartSent(uint32_t baseAddress);

extern void USCI_B_I2C_masterSendStart(uint32_t baseAddress);

extern void USCI_B_I2C_enableInterrupt(uint32_t baseAddress,
                                       uint8_t mask);

extern void USCI_B_I2C_disableInterrupt(uint32_t baseAddress,
                                        uint8_t mask);

extern void USCI_B_I2C_clearInterruptFlag(uint32_t baseAddress,
                                          uint8_t mask);

extern uint8_t USCI_B_I2C_getInterruptStatus(uint32_t baseAddress,
                                             uint8_t mask);

extern void USCI_B_I2C_masterSendSingleByte(uint32_t baseAddress,
                                            uint8_t txData);

extern bool USCI_B_I2C_masterSendSingleByteWithTimeout(uint32_t baseAddress,
                                                       uint8_t txData,
                                                       uint32_t timeout);

extern void USCI_B_I2C_masterMultiByteSendStart(uint32_t baseAddress,
                                                uint8_t txData);

extern bool USCI_B_I2C_masterMultiByteSendStartWithTimeout(uint32_t baseAddress,
                                                           uint8_t txData,
                                                           uint32_t timeout);

extern void USCI_B_I2C_masterMultiByteSendNext(uint32_t baseAddress,
                                               uint8_t txData);

extern bool USCI_B_I2C_masterMultiByteSendNextWithTimeout(uint32_t baseAddress,
                                                          uint8_t txData,
                                                          uint32_t timeout);

extern void USCI_B_I2C_masterMultiByteSendFinish(uint32_t baseAddress,
                                                 uint8_t txData);

extern bool USCI_B_I2C_masterMultiByteSendFinishWithTimeout(uint32_t baseAddress,
                                                            uint8_t txData,
                                                            uint32_t timeout);

extern void USCI_B_I2C_masterMultiByteSendStop(uint32_t baseAddress);

extern bool USCI_B_I2C_masterMultiByteSendStopWithTimeout(uint32_t baseAddress,
                                                          uint32_t timeout);

extern void USCI_B_I2C_masterMultiByteReceiveStart(uint32_t baseAddress);

extern uint8_t USCI_B_I2C_masterMultiByteReceiveNext(uint32_t baseAddress);

extern uint8_t USCI_B_I2C_masterMultiByteReceiveFinish(uint32_t baseAddress);

extern bool USCI_B_I2C_masterMultiByteReceiveFinishWithTimeout(uint32_t baseAddress,
                                                               uint8_t *rxData,
                                                               uint32_t timeout);

extern void USCI_B_I2C_masterMultiByteReceiveStop(uint32_t baseAddress);

extern void USCI_B_I2C_masterSingleReceiveStart(uint32_t baseAddress);

extern bool USCI_B_I2C_masterSingleReceiveStartWithTimeout(uint32_t baseAddress,
                                                           uint32_t timeout);

extern uint8_t USCI_B_I2C_masterSingleReceive(uint32_t baseAddress);

extern uint32_t USCI_B_I2C_getReceiveBufferAddressForDMA(uint32_t baseAddress);

extern uint32_t USCI_B_I2C_getTransmitBufferAddressForDMA(uint32_t baseAddress);

//*****************************************************************************
//
// DEPRECATED APIS.
//
//*****************************************************************************
#define USCI_B_I2C_masterIsSTOPSent                 USCI_B_I2C_masterIsStopSent

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_USCI_B_I2C_H__

#endif
