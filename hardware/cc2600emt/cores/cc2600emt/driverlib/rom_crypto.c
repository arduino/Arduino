/*******************************************************************************
*  Filename:       rom_crypto.c
*  Revised:        2015-09-09 11:55:59 +0200 (Wed, 09 Sep 2015)
*  Revision:       44536
*
*  Description:    This is the implementation for the API to the AES, ECC and
*                  SHA256 functions built into ROM on the CC26xx.
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

#include <stdint.h>
#include <driverlib/rom_crypto.h>

///////////////////////////////////* AES-128 *//////////////////////////////////

/* AES - ECB */
typedef void(*aes_ecb_encrypt_t)(uint8_t *, uint16_t, uint8_t *);
aes_ecb_encrypt_t aes_ecb_encrypt = (aes_ecb_encrypt_t)(0x10018a99);

typedef void(*aes_ecb_decrypt_t)(uint8_t *, uint16_t, uint8_t *);
aes_ecb_decrypt_t aes_ecb_decrypt= (aes_ecb_decrypt_t)(0x10018ac5);

//*****************************************************************************
// AES_ECB_EncryptData
//*****************************************************************************
void
AES_ECB_EncryptData(uint8_t *text, uint16_t textLen, uint8_t *aesKey)
{
  aes_ecb_encrypt(text, textLen, aesKey);
}

//*****************************************************************************
// AES_ECB_DecryptData
//*****************************************************************************
void
AES_ECB_DecryptData(uint8_t *text, uint16_t textLen, uint8_t *aesKey)
{
  aes_ecb_decrypt(text, textLen, aesKey);
}

/* AES - CCM */
typedef int8_t(*aes_ccm_encrypt_t)(uint8_t, uint8_t, uint8_t *, uint8_t *,
                                   uint16_t, uint8_t *, uint16_t, uint8_t *,
                                   uint8_t *, uint8_t);
aes_ccm_encrypt_t aes_ccm_encrypt = (aes_ccm_encrypt_t)(0x10018a19);

typedef int8_t(*aes_ccm_decrypt_t)(uint8_t, uint8_t, uint8_t *, uint8_t *,
                                   uint16_t, uint8_t *, uint16_t, uint8_t *,
                                   uint8_t *, uint8_t);
aes_ccm_decrypt_t aes_ccm_decrypt= (aes_ccm_decrypt_t)(0x10018a35);

//*****************************************************************************
// AES_CCM_EncryptData
//*****************************************************************************
int8_t
AES_CCM_EncryptData(uint8_t encryptFlag, uint8_t MACLen, uint8_t *nonce,
                    uint8_t *plainText, uint16_t textLen,
                    uint8_t *addDataBuf, uint16_t addBufLen,
                    uint8_t *aesKey, uint8_t *MAC, uint8_t ccmLVal)
{
  return aes_ccm_encrypt(encryptFlag, MACLen, nonce, plainText, textLen,
                         addDataBuf, addBufLen, aesKey, MAC, ccmLVal);
}

//*****************************************************************************
// AES_CCM_DecryptData
//*****************************************************************************
int8_t
AES_CCM_DecryptData(uint8_t decryptFlag, uint8_t MACLen, uint8_t *nonce,
                    uint8_t *cipherText, uint16_t textLen,
                    uint8_t *addDataBuf, uint16_t addBufLen,
                    uint8_t *aesKey, uint8_t *MAC, uint8_t ccmLVal)
{
  return aes_ccm_decrypt(decryptFlag, MACLen, nonce, cipherText, textLen,
                         addDataBuf, addBufLen, aesKey, MAC, ccmLVal);

}

/* AES - CTR */
typedef uint8_t(*aes_ctr_encrypt_t)(uint8_t *, uint16_t, uint8_t *, uint8_t *,
                                    uint8_t *);
aes_ctr_encrypt_t aes_ctr_encrypt = (aes_ctr_encrypt_t)(0x100175ed);

typedef uint8_t(*aes_ctr_decrypt_t)(uint8_t *, uint16_t, uint8_t *, uint8_t *,
                                    uint8_t *);
aes_ctr_decrypt_t aes_ctr_decrypt= (aes_ctr_decrypt_t)(0x10017771);

//*****************************************************************************
// AES_CTR_EncryptData
//*****************************************************************************
uint8_t
AES_CTR_EncryptData(uint8_t *plainText, uint16_t textLen,
                    uint8_t *aesKey, uint8_t *nonce,
                    uint8_t *initVector)
{
  return aes_ctr_encrypt(plainText, textLen, aesKey, nonce, initVector);
}

//*****************************************************************************
// AES_CTR_DecryptData
//*****************************************************************************
uint8_t
AES_CTR_DecryptData(uint8_t *cipherText, uint16_t textLen,
                    uint8_t *aesKey, uint8_t *nonce,
                    uint8_t *initVector)
{
  return aes_ctr_decrypt(cipherText, textLen, aesKey, nonce, initVector);
}

////////////////////////////////////* ECC *////////////////////////////////////
#ifdef ECC_PRIME_NIST256_CURVE
//#define TEST_NIST256
//#define PARAM_P NIST256_p;
#define PARAM_P 0x10018b0c;

//#define PARAM_R NIST256_r;
#define PARAM_R 0x10018b30;

//#define PARAM_A NIST256_a;
#define PARAM_A 0x10018b54;

//#define PARAM_B NIST256_b;
#define PARAM_B 0x10018b78;

//#define PARAM_GX NIST256_Gx;
#define PARAM_GX 0x10018b9c;

//#define PARAM_GY NIST256_Gy;
#define PARAM_GY 0x10018bc0;

#endif


//*****************************************************************************
// ECC_initialize
//*****************************************************************************
void
ECC_initialize(uint32_t *pWorkzone)
{
  // Initialize curve parameters
  //data_p  = (uint32_t *)PARAM_P;
  *((uint32_t **)0x20004f48) = (uint32_t *)PARAM_P;

  //data_r  = (uint32_t *)PARAM_R;
  *((uint32_t **)0x20004f4c) = (uint32_t *)PARAM_R;

  //data_a  = (uint32_t *)PARAM_A;
  *((uint32_t **)0x20004f50) = (uint32_t *)PARAM_A;

  //data_b  = (uint32_t *)PARAM_B;
  *((uint32_t **)0x20004fa8) = (uint32_t *)PARAM_B;

  //data_Gx = (uint32_t *)PARAM_GX;
  *((uint32_t **)0x20004fa0) = (uint32_t *)PARAM_GX;

  //data_Gy = (uint32_t *)PARAM_GY;
  *((uint32_t **)0x20004fa4) = (uint32_t *)PARAM_GY;

  // Initialize window size
  //win = (uint8_t) ECC_WINDOW_SIZE;
  *((uint8_t *)0x20004f40) = (uint8_t) ECC_WINDOW_SIZE;

  // Initialize work zone
  //workzone = (uint32_t *) pWorkzone;
  *((uint32_t **)0x20004f44) = (uint32_t *) pWorkzone;
}

typedef uint8_t(*ecc_keygen_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *);
ecc_keygen_t ecc_generatekey = (ecc_keygen_t)(0x10017dbd);

typedef uint8_t(*ecdsa_sign_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *, uint32_t *);
ecdsa_sign_t ecc_ecdsa_sign = (ecdsa_sign_t)(0x10017969);

typedef uint8_t(*ecdsa_verify_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *, uint32_t *);
ecdsa_verify_t ecc_ecdsa_verify = (ecdsa_verify_t)(0x10017b01);

typedef uint8_t(*ecdh_computeSharedSecret_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *, uint32_t *);
ecdh_computeSharedSecret_t ecdh_computeSharedSecret = (ecdh_computeSharedSecret_t)(0x10017ded);

//*****************************************************************************
// ECC_generateKey
//*****************************************************************************
uint8_t
ECC_generateKey(uint32_t *randString, uint32_t *privateKey,
                uint32_t *publicKey_x, uint32_t *publicKey_y)
{
  return (uint8_t)ecc_generatekey((uint32_t*)randString, (uint32_t*)privateKey,
                                  (uint32_t*)publicKey_x, (uint32_t*)publicKey_y);

}

//*****************************************************************************
// ECC_ECDSA_sign
//*****************************************************************************
uint8_t
ECC_ECDSA_sign(uint32_t *secretKey, uint32_t *text, uint32_t *randString,
               uint32_t *sign1, uint32_t *sign2)
{
  return (uint8_t)ecc_ecdsa_sign((uint32_t*)secretKey, (uint32_t*)text, (uint32_t*)randString,
                             (uint32_t*)sign1, (uint32_t*)sign2);
}

//*****************************************************************************
// ECC_ECDSA_verify
//*****************************************************************************
uint8_t
ECC_ECDSA_verify(uint32_t *publicKey_x, uint32_t *publicKey_y,
                 uint32_t *text, uint32_t *sign1, uint32_t *sign2)
{
  return (uint8_t)ecc_ecdsa_verify((uint32_t*)publicKey_x, (uint32_t*)publicKey_y, (uint32_t*)text,
                              (uint32_t*)sign1, (uint32_t*)sign2);
}

//*****************************************************************************
// ECC_ECDH_computeSharedSecret
//*****************************************************************************
uint8_t
ECC_ECDH_computeSharedSecret(uint32_t *privateKey, uint32_t *publicKey_x,
                             uint32_t *publicKey_y, uint32_t *sharedSecret_x,
                             uint32_t *sharedSecret_y)
{
  return (uint8_t)ecdh_computeSharedSecret((uint32_t*)privateKey, (uint32_t*)publicKey_x,
                                 (uint32_t*)publicKey_y, (uint32_t*)sharedSecret_x,
                                 (uint32_t*)sharedSecret_y);
}


//////////////////////////////////* SHA-256 *///////////////////////////////////

typedef uint8_t(*sha256_full_t)(SHA256_memory_t *, uint8_t *, uint8_t *, uint32_t);
sha256_full_t sha256_runfullalg = (sha256_full_t)(0x10018129);

typedef uint8_t(*sha256_init_t)(SHA256_memory_t *);
sha256_init_t sha256_initialize = (sha256_init_t)(0x10017ffd);

typedef uint8_t(*sha256_process_t)(SHA256_memory_t *, uint8_t *, uint32_t);
sha256_process_t sha256_execute = (sha256_process_t)(0x10018019);

typedef uint8_t(*sha256_final_t)(SHA256_memory_t *, uint8_t *);
sha256_final_t sha256_output = (sha256_final_t)(0x10018089);

//*****************************************************************************
// SHA256_runFullAlgorithm
//*****************************************************************************
uint8_t
SHA256_runFullAlgorithm(SHA256_memory_t *memory, uint8_t *pBufIn,
                        uint32_t bufLen, uint8_t *pBufOut)
{
  return (uint8_t)sha256_runfullalg(memory, pBufOut, pBufIn, bufLen);
}

//*****************************************************************************
// SHA256_initialize
//*****************************************************************************
uint8_t
SHA256_initialize(SHA256_memory_t *memory)
{
  return (uint8_t)sha256_initialize(memory);
}

//*****************************************************************************
// SHA256_execute
//*****************************************************************************
uint8_t
SHA256_execute(SHA256_memory_t *memory, uint8_t *pBufIn, uint32_t bufLen)
{
  return (uint8_t)sha256_execute(memory,pBufIn, bufLen);
}

//*****************************************************************************
// SHA256_output
//*****************************************************************************
uint8_t
SHA256_output(SHA256_memory_t *memory, uint8_t *pBufOut)
{
  return (uint8_t)sha256_output(memory, pBufOut);
}
