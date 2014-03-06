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
// aes256.c - Driver for the aes256 Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup aes256_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_AES256__
#include "aes256.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Loads a 128, 192 or 256 bit cipher key to AES256 module.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param cipherKey is a pointer to an uint8_t array with a length of 16 bytes
//!        that contains a 128 bit cipher key.
//! \param keyLength is the length of the key.
//!        Valid values are:
//!        - \b AES256_KEYLENGTH_128BIT
//!        - \b AES256_KEYLENGTH_192BIT
//!        - \b AES256_KEYLENGTH_256BIT
//!
//! \return STATUS_SUCCESS or STATUS_FAIL of key loading
//
//*****************************************************************************
uint8_t AES256_setCipherKey(uint32_t baseAddress,
                            const uint8_t * cipherKey,
                            uint16_t keyLength)
{
        uint8_t i;
        uint16_t sCipherKey;

        HWREG16(baseAddress + OFS_AESACTL0) &= (~(AESKL_1 + AESKL_2));

        switch (keyLength) {
        case AES256_KEYLENGTH_128BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__128;
                break;

        case AES256_KEYLENGTH_192BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__192;
                break;

        case AES256_KEYLENGTH_256BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__256;
                break;

        default:
                return STATUS_FAIL;
        }

        keyLength = keyLength / 8;

        for (i = 0; i < keyLength; i = i + 2) {
                sCipherKey = (uint16_t)(cipherKey[i]);
                sCipherKey = sCipherKey | ((uint16_t)(cipherKey[i + 1]) << 8);
                HWREG16(baseAddress + OFS_AESAKEY) = sCipherKey;
        }

        // Wait until key is written
        while (0x00 == (HWREG16(baseAddress + OFS_AESASTAT) & AESKEYWR )) ;
        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Encrypts a block of data using the AES256 module.
//!
//! The cipher key that is used for encryption should be loaded in advance by
//! using function AES256_setCipherKey()
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param data is a pointer to an uint8_t array with a length of 16 bytes that
//!        contains data to be encrypted.
//! \param encryptedData is a pointer to an uint8_t array with a length of 16
//!        bytes in that the encrypted data will be written.
//!
//! \return None
//
//*****************************************************************************
void AES256_encryptData(uint32_t baseAddress,
                        const uint8_t * data,
                        uint8_t * encryptedData)
{
        uint8_t i;
        uint16_t tempData = 0;
        uint16_t tempVariable = 0;

        // Set module to encrypt mode
        HWREG16(baseAddress + OFS_AESACTL0) &= ~AESOP_3;

        // Write data to encrypt to module
        for (i = 0; i < 16; i = i + 2) {
                tempVariable = (uint16_t)(data[i]);
                tempVariable = tempVariable | ((uint16_t)(data[i + 1]) << 8);
                HWREG16(baseAddress + OFS_AESADIN) = tempVariable;
        }

        // Key that is already written shall be used
        // Encryption is initialized by setting AESKEYWR to 1
        HWREG16(baseAddress + OFS_AESASTAT) |= AESKEYWR;

        // Wait unit finished ~167 MCLK
        while (AESBUSY == (HWREG16(baseAddress + OFS_AESASTAT) & AESBUSY) ) ;

        // Write encrypted data back to variable
        for (i = 0; i < 16; i = i + 2) {
                tempData = HWREG16(baseAddress + OFS_AESADOUT);
                *(encryptedData + i) = (uint8_t)tempData;
                *(encryptedData + i + 1) = (uint8_t)(tempData >> 8);

        }
}

//*****************************************************************************
//
//! \brief Decrypts a block of data using the AES256 module.
//!
//! This function requires a pregenerated decryption key. A key can be loaded
//! and pregenerated by using function AES256_setDecipherKey() or
//! AES256_startSetDecipherKey(). The decryption takes 167 MCLK.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param data is a pointer to an uint8_t array with a length of 16 bytes that
//!        contains encrypted data to be decrypted.
//! \param decryptedData is a pointer to an uint8_t array with a length of 16
//!        bytes in that the decrypted data will be written.
//!
//! \return None
//
//*****************************************************************************
void AES256_decryptData(uint32_t baseAddress,
                        const uint8_t * data,
                        uint8_t * decryptedData)
{
        uint8_t i;
        uint16_t tempData = 0;
        uint16_t tempVariable = 0;

        // Set module to decrypt mode
        HWREG16(baseAddress + OFS_AESACTL0) |= (AESOP_3);

        // Write data to decrypt to module
        for (i = 0; i < 16; i = i + 2) {
                tempVariable = (uint16_t)(data[i + 1] << 8);
                tempVariable = tempVariable | ((uint16_t)(data[i]));
                HWREG16(baseAddress + OFS_AESADIN) = tempVariable;
        }

        // Key that is already written shall be used
        // Now decryption starts
        HWREG16(baseAddress + OFS_AESASTAT) |= AESKEYWR;

        // Wait unit finished ~167 MCLK
        while (AESBUSY == (HWREG16(baseAddress + OFS_AESASTAT) & AESBUSY )) ;

        // Write encrypted data back to variable
        for (i = 0; i < 16; i = i + 2) {
                tempData = HWREG16(baseAddress + OFS_AESADOUT);
                *(decryptedData + i) = (uint8_t)tempData;
                *(decryptedData + i + 1) = (uint8_t)(tempData >> 8);
        }
}

//*****************************************************************************
//
//! \brief Sets the decipher key.
//!
//! The API AES256_startSetDecipherKey or AES256_setDecipherKey must be invoked
//! before invoking AES256_startDecryptData.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param cipherKey is a pointer to an uint8_t array with a length of 16 bytes
//!        that contains a 128 bit cipher key.
//! \param keyLength is the length of the key.
//!        Valid values are:
//!        - \b AES256_KEYLENGTH_128BIT
//!        - \b AES256_KEYLENGTH_192BIT
//!        - \b AES256_KEYLENGTH_256BIT
//!
//! \return STATUS_SUCCESS or STATUS_FAIL of key loading
//
//*****************************************************************************
uint8_t AES256_setDecipherKey(uint32_t baseAddress,
                              const uint8_t * cipherKey,
                              uint16_t keyLength
                              )
{
        uint8_t i;
        uint16_t tempVariable = 0;

        // Set module to decrypt mode
        HWREG16(baseAddress + OFS_AESACTL0) &= ~(AESOP0);
        HWREG16(baseAddress + OFS_AESACTL0) |= AESOP1;

        switch (keyLength) {
        case AES256_KEYLENGTH_128BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__128;
                break;

        case AES256_KEYLENGTH_192BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__192;
                break;

        case AES256_KEYLENGTH_256BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__256;
                break;

        default:
                return STATUS_FAIL;
        }

        keyLength = keyLength / 8;

        // Write cipher key to key register
        for (i = 0; i < keyLength; i = i + 2) {
                tempVariable = (uint16_t)(cipherKey[i]);
                tempVariable = tempVariable | ((uint16_t)(cipherKey[i + 1]) << 8);
                HWREG16(baseAddress + OFS_AESAKEY) = tempVariable;
        }

        // Wait until key is processed ~52 MCLK
        while ((HWREG16(baseAddress + OFS_AESASTAT) & AESBUSY) == AESBUSY) ;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Clears the AES256 ready interrupt flag.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! Modified bits are \b AESRDYIFG of \b AESACTL0 register.
//!
//! \return None
//
//*****************************************************************************
void AES256_clearInterruptFlag(uint32_t baseAddress )
{
        HWREG16(baseAddress + OFS_AESACTL0) &=  ~AESRDYIFG;
}

//*****************************************************************************
//
//! \brief Gets the AES256 ready interrupt flag status.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! \return One of the following:
//!         - \b AES256_READY_INTERRUPT
//!         - \b AES256_NOTREADY_INTERRUPT
//!         \n indicating the status of the AES256 ready status
//
//*****************************************************************************
uint32_t AES256_getInterruptFlagStatus(uint32_t baseAddress)
{
        return (HWREG16(baseAddress + OFS_AESACTL0) & AESRDYIFG) << 0x04;
}

//*****************************************************************************
//
//! \brief Enables AES256 ready interrupt.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! Modified bits are \b AESRDYIE of \b AESACTL0 register.
//!
//! \return None
//
//*****************************************************************************
void AES256_enableInterrupt(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_AESACTL0) |=  AESRDYIE;
}

//*****************************************************************************
//
//! \brief Disables AES256 ready interrupt.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! Modified bits are \b AESRDYIE of \b AESACTL0 register.
//!
//! \return None
//
//*****************************************************************************
void AES256_disableInterrupt(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_AESACTL0) &=  ~AESRDYIE;
}

//*****************************************************************************
//
//! \brief Resets AES256 Module immediately.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! Modified bits are \b AESSWRST of \b AESACTL0 register.
//!
//! \return None
//
//*****************************************************************************
void AES256_reset(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_AESACTL0) |=  AESSWRST;
}

//*****************************************************************************
//
//! \brief Starts an encryption process on the AES256 module.
//!
//! The cipher key that is used for decryption should be loaded in advance by
//! using function AES256_setCipherKey(). This is a non-blocking equivalent of
//! AES256_encryptData(). It is recommended to use the interrupt functionality
//! to check for procedure completion then use the AES256_getDataOut() API to
//! retrieve the encrypted data.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param data is a pointer to an uint8_t array with a length of 16 bytes that
//!        contains data to be encrypted.
//!
//! \return None
//
//*****************************************************************************
void AES256_startEncryptData(uint32_t baseAddress,
                             const uint8_t * data)
{
        uint8_t i;
        uint16_t tempVariable = 0;

        // Set module to encrypt mode
        HWREG16(baseAddress + OFS_AESACTL0) &= ~AESOP_3;

        // Write data to encrypt to module
        for (i = 0; i < 16; i = i + 2) {
                tempVariable = (uint16_t)(data[i]);
                tempVariable = tempVariable | ((uint16_t)(data[i + 1 ]) << 8);
                HWREG16(baseAddress + OFS_AESADIN) = tempVariable;
        }

        // Key that is already written shall be used
        // Encryption is initialized by setting AESKEYWR to 1
        HWREG16(baseAddress + OFS_AESASTAT) |= AESKEYWR;
}

//*****************************************************************************
//
//! \brief Decrypts a block of data using the AES256 module.
//!
//! This is the non-blocking equivalent of AES256_decryptData(). This function
//! requires a pregenerated decryption key. A key can be loaded and
//! pregenerated by using function AES256_setDecipherKey() or
//! AES256_startSetDecipherKey(). The decryption takes 167 MCLK. It is
//! recommended to use interrupt to check for procedure completion then use the
//! AES256_getDataOut() API to retrieve the decrypted data.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param data is a pointer to an uint8_t array with a length of 16 bytes that
//!        contains encrypted data to be decrypted.
//!
//! \return None
//
//*****************************************************************************
void AES256_startDecryptData(uint32_t baseAddress,
                             const uint8_t * data)
{
        uint8_t i;
        uint16_t tempVariable = 0;

        // Set module to decrypt mode
        HWREG16(baseAddress + OFS_AESACTL0) |= (AESOP_3);

        // Write data to decrypt to module
        for (i = 0; i < 16; i = i + 2) {
                tempVariable = (uint16_t)(data[i + 1] << 8);
                tempVariable = tempVariable | ((uint16_t)(data[i]));
                HWREG16(baseAddress + OFS_AESADIN) = tempVariable;
        }

        // Key that is already written shall be used
        // Now decryption starts
        HWREG16(baseAddress + OFS_AESASTAT) |= AESKEYWR;
}

//*****************************************************************************
//
//! \brief Sets the decipher key
//!
//! The API AES256_startSetDecipherKey() or AES256_setDecipherKey() must be
//! invoked before invoking AES256_startDecryptData.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param cipherKey is a pointer to an uint8_t array with a length of 16 bytes
//!        that contains a 128 bit cipher key.
//! \param keyLength is the length of the key.
//!        Valid values are:
//!        - \b AES256_KEYLENGTH_128BIT
//!        - \b AES256_KEYLENGTH_192BIT
//!        - \b AES256_KEYLENGTH_256BIT
//!
//! \return STATUS_SUCCESS or STATUS_FAIL of key loading
//
//*****************************************************************************
uint8_t AES256_startSetDecipherKey(uint32_t baseAddress,
                                   const uint8_t * cipherKey,
                                   uint16_t keyLength)
{
        uint8_t i;
        uint16_t tempVariable = 0;

        HWREG16(baseAddress + OFS_AESACTL0) &= ~(AESOP0);
        HWREG16(baseAddress + OFS_AESACTL0) |= AESOP1;

        switch (keyLength) {
        case AES256_KEYLENGTH_128BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__128;
                break;

        case AES256_KEYLENGTH_192BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__192;
                break;

        case AES256_KEYLENGTH_256BIT:
                HWREG16(baseAddress + OFS_AESACTL0) |= AESKL__256;
                break;

        default:
                return STATUS_FAIL;
        }

        keyLength = keyLength / 8;

        // Write cipher key to key register
        for (i = 0; i < keyLength; i = i + 2) {
                tempVariable = (uint16_t)(cipherKey[i]);
                tempVariable = tempVariable | ((uint16_t)(cipherKey[i + 1]) << 8);
                HWREG16(baseAddress + OFS_AESAKEY) = tempVariable;
        }

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Reads back the output data from AES256 module.
//!
//! This function is meant to use after an encryption or decryption process
//! that was started and finished by initiating an interrupt by use of
//! AES256_startEncryptData or AES256_startDecryptData functions.
//!
//! \param baseAddress is the base address of the AES256 module.
//! \param outputData is a pointer to an uint8_t array with a length of 16
//!        bytes in that the data will be written.
//!
//! \return STATUS_SUCCESS if data is valid, otherwise STATUS_FAIL
//
//*****************************************************************************
uint8_t  AES256_getDataOut(uint32_t baseAddress,
                           uint8_t *outputData
                           )
{
        uint8_t i;
        uint16_t tempData = 0;

        // If module is busy, exit and return failure
        if ( AESBUSY == (HWREG16(baseAddress + OFS_AESASTAT) & AESBUSY))
                return STATUS_FAIL;

        // Write encrypted data back to variable
        for (i = 0; i < 16; i = i + 2) {
                tempData = HWREG16(baseAddress + OFS_AESADOUT);
                *(outputData + i ) = (uint8_t)tempData;
                *(outputData + i + 1) = (uint8_t)(tempData >> 8);
        }

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Gets the AES256 module busy status.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! \return One of the following:
//!         - \b AES256_BUSY
//!         - \b AES256_NOT_BUSY
//!         \n indicating if the AES256 module is busy
//
//*****************************************************************************
uint16_t AES256_isBusy(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_AESASTAT) & AESBUSY;
}

//*****************************************************************************
//
//! \brief Clears the AES256 error flag.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! Modified bits are \b AESERRFG of \b AESACTL0 register.
//!
//! \return None
//
//*****************************************************************************
void AES256_clearErrorFlag(uint32_t baseAddress )
{
        HWREG16(baseAddress + OFS_AESACTL0) &=  ~AESERRFG;
}

//*****************************************************************************
//
//! \brief Gets the AES256 error flag status.
//!
//! \param baseAddress is the base address of the AES256 module.
//!
//! \return One of the following:
//!         - \b AES256_ERROR_OCCURRED
//!         - \b AES256_NO_ERROR
//!         \n indicating the error flag status
//
//*****************************************************************************
uint32_t AES256_getErrorFlagStatus(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_AESACTL0) & AESERRFG;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for aes256_api
//! @}
//
//*****************************************************************************

#endif
