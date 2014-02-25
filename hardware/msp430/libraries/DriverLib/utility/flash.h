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
// flash.h - Driver for the FLASH Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_FLASH_H__
#define __MSP430WARE_FLASH_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_FLASH__

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
// The following are values that can be passed to the mask parameter for
// functions: FLASH_status() as well as returned by the FLASH_status()
// function.
//
//*****************************************************************************
#define FLASH_READY_FOR_NEXT_WRITE                                       WAIT_L
#define FLASH_ACCESS_VIOLATION_INTERRUPT_FLAG                         ACCVIFG_L
#define FLASH_PASSWORD_WRITTEN_INCORRECTLY                               KEYV_L
#define FLASH_BUSY                                                       BUSY_L

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void FLASH_segmentErase(uint8_t *flash_ptr);

extern void FLASH_bankErase(uint8_t *flash_ptr);

extern bool FLASH_eraseCheck(uint8_t *flash_ptr,
                             uint16_t numberOfBytes);

extern void FLASH_write8(uint8_t *data_ptr,
                         uint8_t *flash_ptr,
                         uint16_t count);

extern void FLASH_write16(uint16_t *data_ptr,
                          uint16_t *flash_ptr,
                          uint16_t count);

extern void FLASH_write32(uint32_t *data_ptr,
                          uint32_t *flash_ptr,
                          uint16_t count);

extern void FLASH_memoryFill32(uint32_t value,
                               uint32_t *flash_ptr,
                               uint16_t count);

extern uint8_t FLASH_status(uint8_t mask);

extern void FLASH_lockInfoA(void);

extern void FLASH_unlockInfoA(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_FLASH_H__

#endif
