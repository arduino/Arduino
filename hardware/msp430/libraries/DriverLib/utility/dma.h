//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430F5529__) || defined(__MSP430FR5739__)

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
// dma.h - Driver for the DMA Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_DMA_H__
#define __MSP430WARE_DMA_H__

#include "inc/hw_memmap.h"

#if defined(__MSP430_HAS_DMAX_3__) || defined(__MSP430_HAS_DMAX_6__)

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
// The following are values that can be passed to the triggerSourceSelect
// parameter for functions: DMA_init().
//
//*****************************************************************************
#define DMA_TRIGGERSOURCE_0                                              (0x00)
#define DMA_TRIGGERSOURCE_1                                              (0x01)
#define DMA_TRIGGERSOURCE_2                                              (0x02)
#define DMA_TRIGGERSOURCE_3                                              (0x03)
#define DMA_TRIGGERSOURCE_4                                              (0x04)
#define DMA_TRIGGERSOURCE_5                                              (0x05)
#define DMA_TRIGGERSOURCE_6                                              (0x06)
#define DMA_TRIGGERSOURCE_7                                              (0x07)
#define DMA_TRIGGERSOURCE_8                                              (0x08)
#define DMA_TRIGGERSOURCE_9                                              (0x09)
#define DMA_TRIGGERSOURCE_10                                             (0x0A)
#define DMA_TRIGGERSOURCE_11                                             (0x0B)
#define DMA_TRIGGERSOURCE_12                                             (0x0C)
#define DMA_TRIGGERSOURCE_13                                             (0x0D)
#define DMA_TRIGGERSOURCE_14                                             (0x0E)
#define DMA_TRIGGERSOURCE_15                                             (0x0F)
#define DMA_TRIGGERSOURCE_16                                             (0x10)
#define DMA_TRIGGERSOURCE_17                                             (0x11)
#define DMA_TRIGGERSOURCE_18                                             (0x12)
#define DMA_TRIGGERSOURCE_19                                             (0x13)
#define DMA_TRIGGERSOURCE_20                                             (0x14)
#define DMA_TRIGGERSOURCE_21                                             (0x15)
#define DMA_TRIGGERSOURCE_22                                             (0x16)
#define DMA_TRIGGERSOURCE_23                                             (0x17)
#define DMA_TRIGGERSOURCE_24                                             (0x18)
#define DMA_TRIGGERSOURCE_25                                             (0x19)
#define DMA_TRIGGERSOURCE_26                                             (0x1A)
#define DMA_TRIGGERSOURCE_27                                             (0x1B)
#define DMA_TRIGGERSOURCE_28                                             (0x1C)
#define DMA_TRIGGERSOURCE_29                                             (0x1D)
#define DMA_TRIGGERSOURCE_30                                             (0x1E)
#define DMA_TRIGGERSOURCE_31                                             (0x1F)

//*****************************************************************************
//
// The following are values that can be passed to the transferModeSelect
// parameter for functions: DMA_init().
//
//*****************************************************************************
#define DMA_TRANSFER_SINGLE                                           (DMADT_0)
#define DMA_TRANSFER_BLOCK                                            (DMADT_1)
#define DMA_TRANSFER_BURSTBLOCK                                       (DMADT_2)
#define DMA_TRANSFER_REPEATED_SINGLE                                  (DMADT_4)
#define DMA_TRANSFER_REPEATED_BLOCK                                   (DMADT_5)
#define DMA_TRANSFER_REPEATED_BURSTBLOCK                              (DMADT_6)

//*****************************************************************************
//
// The following are values that can be passed to the channelSelect parameter
// for functions: DMA_init(), DMA_setTransferSize(), DMA_setSrcAddress(),
// DMA_setDstAddress(), DMA_enableTransfers(), DMA_disableTransfers(),
// DMA_startTransfer(), DMA_enableInterrupt(), DMA_disableInterrupt(),
// DMA_getInterruptStatus(), DMA_clearInterrupt(), DMA_NMIAbortStatus(), and
// DMA_clearNMIAbort().
//
//*****************************************************************************
#define DMA_CHANNEL_0                                                    (0x00)
#define DMA_CHANNEL_1                                                    (0x10)
#define DMA_CHANNEL_2                                                    (0x20)
#define DMA_CHANNEL_3                                                    (0x30)
#define DMA_CHANNEL_4                                                    (0x40)
#define DMA_CHANNEL_5                                                    (0x50)
#define DMA_CHANNEL_6                                                    (0x60)
#define DMA_CHANNEL_7                                                    (0x70)

//*****************************************************************************
//
// The following are values that can be passed to the triggerTypeSelect
// parameter for functions: DMA_init().
//
//*****************************************************************************
#define DMA_TRIGGER_RISINGEDGE                                    (!(DMALEVEL))
#define DMA_TRIGGER_HIGH                                             (DMALEVEL)

//*****************************************************************************
//
// The following are values that can be passed to the transferUnitSelect
// parameter for functions: DMA_init().
//
//*****************************************************************************
#define DMA_SIZE_SRCWORD_DSTWORD                   (!(DMASRCBYTE + DMADSTBYTE))
#define DMA_SIZE_SRCBYTE_DSTWORD                                   (DMASRCBYTE)
#define DMA_SIZE_SRCWORD_DSTBYTE                                   (DMADSTBYTE)
#define DMA_SIZE_SRCBYTE_DSTBYTE                      (DMASRCBYTE + DMADSTBYTE)

//*****************************************************************************
//
// The following are values that can be passed to the directionSelect parameter
// for functions: DMA_setSrcAddress(), and DMA_setDstAddress().
//
//*****************************************************************************
#define DMA_DIRECTION_UNCHANGED                                  (DMASRCINCR_0)
#define DMA_DIRECTION_DECREMENT                                  (DMASRCINCR_2)
#define DMA_DIRECTION_INCREMENT                                  (DMASRCINCR_3)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the DMA_getInterruptStatus() function.
//
//*****************************************************************************
#define DMA_INT_INACTIVE                                                  (0x0)
#define DMA_INT_ACTIVE                                                 (DMAIFG)

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the DMA_NMIAbortStatus() function.
//
//*****************************************************************************
#define DMA_NOTABORTED                                                    (0x0)
#define DMA_ABORTED                                                  (DMAABORT)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern bool DMA_init(uint8_t channelSelect,
                     uint16_t transferModeSelect,
                     uint16_t transferSize,
                     uint8_t triggerSourceSelect,
                     uint8_t transferUnitSelect,
                     uint8_t triggerTypeSelect);

extern void DMA_setTransferSize(uint8_t channelSelect,
                                uint16_t transferSize);

extern void DMA_setSrcAddress(uint8_t channelSelect,
                              uint32_t srcAddress,
                              uint16_t directionSelect);

extern void DMA_setDstAddress(uint8_t channelSelect,
                              uint32_t dstAddress,
                              uint16_t directionSelect);

extern void DMA_enableTransfers(uint8_t channelSelect);

extern void DMA_disableTransfers(uint8_t channelSelect);

extern void DMA_startTransfer(uint8_t channelSelect);

extern void DMA_enableInterrupt(uint8_t channelSelect);

extern void DMA_disableInterrupt(uint8_t channelSelect);

extern uint16_t DMA_getInterruptStatus(uint8_t channelSelect);

extern void DMA_clearInterrupt(uint8_t channelSelect);

extern uint16_t DMA_NMIAbortStatus(uint8_t channelSelect);

extern void DMA_clearNMIAbort(uint8_t channelSelect);

extern void DMA_disableTransferDuringReadModifyWrite(void);

extern void DMA_enableTransferDuringReadModifyWrite(void);

extern void DMA_enableRoundRobinPriority(void);

extern void DMA_disableRoundRobinPriority(void);

extern void DMA_enableNMIAbort(void);

extern void DMA_disableNMIAbort(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_DMA_H__

#endif
