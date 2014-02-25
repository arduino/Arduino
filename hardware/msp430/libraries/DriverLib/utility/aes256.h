//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__)

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
// aes256.h - Driver for the AES256 Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_AES256_H__
#define __MSP430WARE_AES256_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_AES256__

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
// The following are values that can be passed to the keyLength parameter for
// functions: AES256_setCipherKey(), AES256_setDecipherKey(), and
// AES256_startSetDecipherKey().
//
//*****************************************************************************
#define AES256_KEYLENGTH_128BIT                                             128
#define AES256_KEYLENGTH_192BIT                                             192
#define AES256_KEYLENGTH_256BIT                                             256

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the AES256_getErrorFlagStatus() function.
//
//*****************************************************************************
#define AES256_ERROR_OCCURRED                                          AESERRFG
#define AES256_NO_ERROR                                                    0x00

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the AES256_isBusy() function.
//
//*****************************************************************************
#define AES256_BUSY                                                     AESBUSY
#define AES256_NOT_BUSY                                                    0x00

//*****************************************************************************
//
// The following are values that can be passed toThe following are values that
// can be returned by the AES256_getInterruptFlagStatus() function.
//
//*****************************************************************************
#define AES256_READY_INTERRUPT                                         AESRDYIE
#define AES256_NOTREADY_INTERRUPT                                          0x00

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern uint8_t AES256_setCipherKey(uint32_t baseAddress,
                                   const uint8_t *cipherKey,
                                   uint16_t keyLength);

extern void AES256_encryptData(uint32_t baseAddress,
                               const uint8_t *data,
                               uint8_t *encryptedData);

extern void AES256_decryptData(uint32_t baseAddress,
                               const uint8_t *data,
                               uint8_t *decryptedData);

extern uint8_t AES256_setDecipherKey(uint32_t baseAddress,
                                     const uint8_t *cipherKey,
                                     uint16_t keyLength);

extern void AES256_clearInterruptFlag(uint32_t baseAddress);

extern uint32_t AES256_getInterruptFlagStatus(uint32_t baseAddress);

extern void AES256_enableInterrupt(uint32_t baseAddress);

extern void AES256_disableInterrupt(uint32_t baseAddress);

extern void AES256_reset(uint32_t baseAddress);

extern void AES256_startEncryptData(uint32_t baseAddress,
                                    const uint8_t *data);

extern void AES256_startDecryptData(uint32_t baseAddress,
                                    const uint8_t *data);

extern uint8_t AES256_startSetDecipherKey(uint32_t baseAddress,
                                          const uint8_t *cipherKey,
                                          uint16_t keyLength);

extern uint8_t AES256_getDataOut(uint32_t baseAddress,
                                 uint8_t *outputData);

extern uint16_t AES256_isBusy(uint32_t baseAddress);

extern void AES256_clearErrorFlag(uint32_t baseAddress);

extern uint32_t AES256_getErrorFlagStatus(uint32_t baseAddress);

//*****************************************************************************
//
// The following are deprecated values. Please refer to documentation for the
// correct values to use.
//
//*****************************************************************************
#define Key_128BIT                                                          128
#define Key_192BIT                                                          192
#define Key_256BIT                                                          256

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_AES256_H__

#endif
