/******************************************************************************
*  Filename:       rom_crypto.h
*  Revised:        2015-07-16 12:12:04 +0200 (Thu, 16 Jul 2015)
*  Revision:       44151
*
*  Description:    This header file is the API to the AES, ECC and SHA256
*                  functions built into ROM on the CC26xx.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/

//*****************************************************************************
//
//! \addtogroup peripheral_group
//! @{
//! \addtogroup rom_crypto_api
//! @{
//
//*****************************************************************************

#ifndef ROM_CRYPTO_H
#define ROM_CRYPTO_H

#ifdef __cplusplus
extern "C"
{
#endif

///////////////////////////////////* AES-128 *//////////////////////////////////

//*****************************************************************************
/*!
 * \brief Use a random 128 bit key to encrypt data with the AES.
 *
 * \param text    Pointer to data to encrypt.
 * \param textLen Length of text.
 * \param aesKey  Pointer to 128 bit key used to encrypt text.
 *
 * \return None
 */
//*****************************************************************************
extern void AES_ECB_EncryptData(uint8_t *text, uint16_t textLen, uint8_t *aesKey);

//*****************************************************************************
/*!
 * \brief Use a random 128 bit key to decrypt data with the AES.
 *
 * \param text    Pointer to data to decrypt.
 * \param textLen Length of text.
 * \param aesKey  Pointer to 128 bit key used to decrypt. This is the same key
 *                that was used to originally encrypt this data.
 *
 * \return None
 */
//*****************************************************************************
extern void AES_ECB_DecryptData(uint8_t *text, uint16_t textLen, uint8_t *aesKey);

//*****************************************************************************
/*!
 * \brief Authenticate and optionally encrypt message plainText.
 *
 * \param encryptFlag  Encryption flag.
 * - set to \c true for authentication with encryption.
 * - set to \c false for authentication only.
 * \param MACLen       Length of MAC in bytes.
 * \param nonce        Pointer to random nonce. Nonce length = 15 - ccmLVal.
 * \param plainText    Pointer to text to encrypt, input and output.
 * \param textLen      Length of text to encrypt.
 * \param addDataBuf   Pointer to additional data for authentication
 * \param addBufLen    Additional authentication buffer length.
 * \param aesKey       Pointer to the AES key or key expansion buffer.
 * \param MAC          Pointer to 16 byte Message Authentication Code output buffer.
 * \param ccmLVal      CCM L value to be used. Values {2,3}.
 *
 * \return Zero when successful.
 */
//*****************************************************************************
extern int8_t AES_CCM_EncryptData(uint8_t encryptFlag, uint8_t MACLen, uint8_t *nonce,
                                  uint8_t *plainText, uint16_t textLen,
                                  uint8_t *addDataBuf, uint16_t addBufLen,
                                  uint8_t *aesKey, uint8_t *MAC, uint8_t ccmLVal);

//*****************************************************************************
/*!
 * \brief Authenticate and optionally decrypt message cipherText.
 *
 * \param decryptFlag Decryption flag.
 * - \c true for authentication with decryption.
 * - \c false for authentication only.
 * \param MACLen      Length of MAC in bytes.
 * \param nonce       Pointer to random nonce. Nonce length = 15 - ccmLVal.
 * \param cipherText  Pointer to text to decrypt, input and output.
 * \param textLen     Length of text to decrypt.
 * \param addDataBuf  Pointer to additional data for authentication
 * \param addBufLen   Additional authentication buffer length.
 * \param aesKey      Pointer to the AES key or key expansion buffer.
 * \param MAC         Pointer to 16 byte Message Authentication Code output buffer.
 * \param ccmLVal     CCM L value to be used. Values {2,3}.
 *
 * \return Zero when Successful.
 */
//*****************************************************************************
extern int8_t AES_CCM_DecryptData(uint8_t decryptFlag, uint8_t MACLen, uint8_t *nonce,
                                  uint8_t *cipherText, uint16_t textLen,
                                  uint8_t *addDataBuf, uint16_t addBufLen,
                                  uint8_t *aesKey, uint8_t *MAC, uint8_t ccmLVal);

//*****************************************************************************
/*!
 * \brief Encrypt plaintext using the AES key, nonce and initialization vector.
 *
 * \param plainText  Pointer to text to encrypt.
 * \param textLen    Length of text.
 * \param aesKey     Pointer to 128 bit key used to encrypt text.
 * \param nonce      Pointer to 4 byte nonce.
 * \param initVector Pointer to 8 byte random initialization vector.
 *
 * \return None
 */
//*****************************************************************************
extern uint8_t AES_CTR_EncryptData(uint8_t *plainText, uint16_t textLen,
                                   uint8_t *aesKey, uint8_t *nonce,
                                   uint8_t *initVector);

//*****************************************************************************
/*!
 * \brief Decrypt ciphertext using the AES key, nonce and initialization vector.
 *
 * \param cipherText Pointer to text to decrypt
 * \param textLen    Length of text.
 * \param aesKey     Pointer to 128 bit key used to encrypt text.
 * \param nonce      Pointer to 4 byte nonce.
 * \param initVector Pointer to 8 byte random initialization vector.
 *
 * \return None
 */
//*****************************************************************************
extern uint8_t AES_CTR_DecryptData(uint8_t *cipherText, uint16_t textLen,
                                   uint8_t *aesKey, uint8_t *nonce,
                                   uint8_t *initVector);

////////////////////////////////////* ECC */////////////////////////////////////

/* Window size, valid values are 2,3,4,5.
 * Higher the value, faster the computation at the expense of memory usage.
 *
 * Recommended workzone size (in 4-byte words)
 * Window size: 3, Workzone size: 275
 *
 */
#define ECC_WINDOW_SIZE 3

/*
 * ECC Supported Curves, define one:
 * ECC_PRIME_NIST256_CURVE
 */
#define ECC_PRIME_NIST256_CURVE

/*
 * ECC Return Status Flags.
 */
// Scalar multiplication status
#define ECC_MODULUS_EVEN                   0xDC
#define ECC_MODULUS_LARGER_THAN_255_WORDS  0xD2
#define ECC_MODULUS_LENGTH_ZERO            0x08
#define ECC_MODULUS_MSW_IS_ZERO            0x30
#define ECC_SCALAR_TOO_LONG                0x35
#define ECC_SCALAR_LENGTH_ZERO             0x53
#define ECC_ORDER_TOO_LONG                 0xC6
#define ECC_ORDER_LENGTH_ZERO              0x6C
#define ECC_X_COORD_TOO_LONG               0x3C
#define ECC_X_COORD_LENGTH_ZERO            0xC3
#define ECC_Y_COORD_TOO_LONG               0x65
#define ECC_Y_COORD_LENGTH_ZERO            0x56
#define ECC_A_COEF_TOO_LONG                0x5C
#define ECC_A_COEF_LENGTH_ZERO             0xC5
#define ECC_BAD_WINDOW_SIZE                0x66
#define ECC_SCALAR_MUL_OK                  0x99

// ECDSA and ECDH status
#define ECC_ORDER_LARGER_THAN_255_WORDS    0x28
#define ECC_ORDER_EVEN                     0x82
#define ECC_ORDER_MSW_IS_ZERO              0x23
#define ECC_ECC_KEY_TOO_LONG               0x25
#define ECC_ECC_KEY_LENGTH_ZERO            0x52
#define ECC_DIGEST_TOO_LONG                0x27
#define ECC_DIGEST_LENGTH_ZERO             0x72
#define ECC_ECDSA_SIGN_OK                  0x32
#define ECC_ECDSA_INVALID_SIGNATURE        0x5A
#define ECC_ECDSA_VALID_SIGNATURE          0xA5
#define ECC_SIG_P1_TOO_LONG                0x11
#define ECC_SIG_P1_LENGTH_ZERO             0x12
#define ECC_SIG_P2_TOO_LONG                0x22
#define ECC_SIG_P2_LENGTH_ZERO             0x21

#define ECC_ECDSA_KEYGEN_OK                ECC_SCALAR_MUL_OK
#define ECC_ECDH_KEYGEN_OK                 ECC_SCALAR_MUL_OK
#define ECC_ECDH_COMMON_KEY_OK             ECC_SCALAR_MUL_OK

//*****************************************************************************
/*!
 * \brief Pass pointer to ECC memory allocation to ECC engine.
 *
 * This function can be called again to point the ECC workzone at
 * a different memory buffer.
 *
 * \param pWorkzone Pointer to memory allocated for computations, input.
 *                  See description at beginning of ECC section for
 *                  memory requirements.
 *
 * \return None
 */
//*****************************************************************************
 extern void ECC_initialize(uint32_t *pWorkzone);

//*****************************************************************************
 /*!
 * \brief Generate a key.
 *
 * This is used for both ECDH and ECDSA.
 *
 * \param randString  Pointer to random string, input.
 * \param privateKey  Pointer to the private key, output.
 * \param publicKey_x Pointer to public key X-coordinate, output.
 * \param publicKey_y Pointer to public key Y-coordinate, output.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t ECC_generateKey(uint32_t *randString, uint32_t *privateKey,
                               uint32_t *publicKey_x, uint32_t *publicKey_y);

//*****************************************************************************
/*!
 * \brief Sign data.
 *
 * \param secretKey  Pointer to the secret key, input.
 * \param text       Pointer to the message, input.
 * \param randString Pointer to random string, input.
 * \param sign1      Pointer to signature part 1, output.
 * \param sign2      Pointer to signature part 2, output.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t ECC_ECDSA_sign(uint32_t *secretKey, uint32_t *text, uint32_t *randString,
                              uint32_t *sign1, uint32_t *sign2);

//*****************************************************************************
/*!
 * \brief Verify signature.
 *
 * \param publicKey_x Pointer to public key X-coordinate, input.
 * \param publicKey_y Pointer to public key Y-coordinate, input.
 * \param text        Pointer to message data, input.
 * \param sign1       Pointer to signature part 1, input.
 * \param sign2       Pointer to signature part 2, input.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t ECC_ECDSA_verify(uint32_t *publicKey_x, uint32_t *publicKey_y,
                                uint32_t *text, uint32_t *sign1, uint32_t *sign2);

//*****************************************************************************
/*!
 * \brief Compute the shared secret.
 *
 * \param privateKey     Pointer to private key, input.
 * \param publicKey_x    Pointer to public key X-coordinate, input.
 * \param publicKey_y    Pointer to public key Y-coordinate, input.
 * \param sharedSecret_x Pointer to shared secret X-coordinate, output.
 * \param sharedSecret_y Pointer to shared secret Y-coordinate, output.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t ECC_ECDH_computeSharedSecret(uint32_t *privateKey,
                                            uint32_t *publicKey_x,
                                            uint32_t *publicKey_y,
                                            uint32_t *sharedSecret_x,
                                            uint32_t *sharedSecret_y);


///////////////////////////////////* SHA-256 *//////////////////////////////////

//! \brief A SHA256_memory_t variable of this type must be allocated before running any
//!        SHA256 functions.
typedef struct
{
  uint32_t state[8];
  uint32_t textLen[2];
  uint32_t W[16];
} SHA256_memory_t;

//*****************************************************************************
/*!
 * \brief Perform SHA256 on the the input data.
 *
 * The input and output buffer can point to the same memory.
 * This is the equivalent of calling \ref SHA256_initialize(),
 * \ref SHA256_execute() and \ref SHA256_output() sequentially.
 *
 * \param memory  Pointer to memory for operations, input.
 * \param pBufIn  Pointer to input buffer, input.
 * \param bufLen  Length of input.
 * \param pBufOut Pointer to output buffer, output.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t SHA256_runFullAlgorithm(SHA256_memory_t *memory, uint8_t *pBufIn,
                                       uint32_t bufLen, uint8_t *pBufOut);

//*****************************************************************************
/*!
 * \brief Intializes the SHA256 engine.
 *
 * This function must be called once before all other SHA256 functions other than
 * \ref SHA256_runFullAlgorithm().
 *
 * \param workZone Pointer to memory for operations, input.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t SHA256_initialize(SHA256_memory_t *workZone);

//*****************************************************************************
/*!
 * \brief Perform SHA256.
 *
 * Must call \ref SHA256_output() to receive output from this operation.
 *
 * \param config Pointer to memory for operations, input.
 * \param pBufIn Pointer to input text, input.
 * \param bufLen Length of input, input.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t SHA256_execute(SHA256_memory_t *config, uint8_t *pBufIn,
                              uint32_t bufLen);

//*****************************************************************************
/*!
 * \brief Complete the process by passing the modified data back.
 *
 * \param memory  Pointer to memory for operations, input.
 * \param pBufOut Pointer to output buffer, output. Buffer must be at least 32 bytes long.
 *
 * \return Status
 */
//*****************************************************************************
extern uint8_t SHA256_output(SHA256_memory_t *memory, uint8_t *pBufOut);

#ifdef __cplusplus
}
#endif

#endif /* ROM_CRYPTO_H */

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//*****************************************************************************
