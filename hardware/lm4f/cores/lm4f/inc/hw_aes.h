//*****************************************************************************
//
// hw_aes.h - Macros used when accessing the AES hardware.
//
// Copyright (c) 2012-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_AES_H__
#define __HW_AES_H__

//*****************************************************************************
//
// The following are defines for the AES register offsets.
//
//*****************************************************************************
#define AES_O_KEY2_6            0x00000000  // AES Secure Key 2_6
#define AES_O_KEY2_7            0x00000004  // AES Secure Key 2_7
#define AES_O_KEY2_4            0x00000008  // AES Secure Key 2_4
#define AES_O_KEY2_5            0x0000000C  // AES Secure Key 2_5
#define AES_O_KEY2_2            0x00000010  // AES Secure Key 2_2
#define AES_O_KEY2_3            0x00000014  // AES Secure Key 2_3
#define AES_O_KEY2_0            0x00000018  // AES Secure Key 2_0
#define AES_O_KEY2_1            0x0000001C  // AES Secure Key 2_1
#define AES_O_KEY1_6            0x00000020  // AES Secure Key 1_6
#define AES_O_KEY1_7            0x00000024  // AES Secure Key 1_7
#define AES_O_KEY1_4            0x00000028  // AES Secure Key 1_4
#define AES_O_KEY1_5            0x0000002C  // AES Secure Key 1_5
#define AES_O_KEY1_2            0x00000030  // AES Secure Key 1_2
#define AES_O_KEY1_3            0x00000034  // AES Secure Key 1_3
#define AES_O_KEY1_0            0x00000038  // AES Secure Key 1_0
#define AES_O_KEY1_1            0x0000003C  // AES Secure Key 1_1
#define AES_O_IV_IN_0           0x00000040  // AES Secure Initialization Vector
                                            // Input 0
#define AES_O_IV_IN_1           0x00000044  // AES Secure Initialization Vector
                                            // Input 1
#define AES_O_IV_IN_2           0x00000048  // AES Secure Initialization Vector
                                            // Input 2
#define AES_O_IV_IN_3           0x0000004C  // AES Initialization Vector Input
                                            // 3
#define AES_O_CTRL              0x00000050  // AES Secure Control
#define AES_O_C_LENGTH_0        0x00000054  // AES Secure Crypto Data Length 0
#define AES_O_C_LENGTH_1        0x00000058  // AES Secure Crypto Data Length 1
#define AES_O_AUTH_LENGTH       0x0000005C  // AES Secure Authentication Data
                                            // Length
#define AES_O_DATA_IN_0         0x00000060  // AES Secure Data R/W
                                            // Plaintext/Ciphertext 0
#define AES_O_DATA_IN_1         0x00000064  // AES Secure Data R/W
                                            // Plaintext/Ciphertext 1
#define AES_O_DATA_IN_2         0x00000068  // AES Secure Data R/W
                                            // Plaintext/Ciphertext 2
#define AES_O_DATA_IN_3         0x0000006C  // AES Secure Data R/W
                                            // Plaintext/Ciphertext 3
#define AES_O_TAG_OUT_0         0x00000070  // AES Secure Hash Tag Out 0
#define AES_O_TAG_OUT_1         0x00000074  // AES Secure Hash Tag Out 1
#define AES_O_TAG_OUT_2         0x00000078  // AES Secure Hash Tag Out 2
#define AES_O_TAG_OUT_3         0x0000007C  // AES Secure Hash Tag Out 3
#define AES_O_REVISION          0x00000080  // AES Secure IP Revision
                                            // Identifier
#define AES_O_SYSCONFIG         0x00000084  // AES Secure System Configuration
#define AES_O_SYSSTATUS         0x00000088  // AES Secure System Status
#define AES_O_IRQSTATUS         0x0000008C  // AES Secure Interrupt Status
#define AES_O_IRQENABLE         0x00000090  // AES Secure Interrupt Enable
#define AES_O_DIRTYBITS         0x00000094  // AES Secure Dirty Bits
#define AES_O_DMAIM             0xFFFFA020  // AES DMA Interrupt Mask
#define AES_O_DMARIS            0xFFFFA024  // AES DMA Raw Interrupt Status
#define AES_O_DMAMIS            0xFFFFA028  // AES DMA Masked Interrupt Status
#define AES_O_DMAIC             0xFFFFA02C  // AES DMA Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_6 register.
//
//*****************************************************************************
#define AES_KEY2_6_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_6_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_7 register.
//
//*****************************************************************************
#define AES_KEY2_7_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_7_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_4 register.
//
//*****************************************************************************
#define AES_KEY2_4_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_4_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_5 register.
//
//*****************************************************************************
#define AES_KEY2_5_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_5_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_2 register.
//
//*****************************************************************************
#define AES_KEY2_2_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_2_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_3 register.
//
//*****************************************************************************
#define AES_KEY2_3_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_3_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_0 register.
//
//*****************************************************************************
#define AES_KEY2_0_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_0_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY2_1 register.
//
//*****************************************************************************
#define AES_KEY2_1_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY2_1_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_6 register.
//
//*****************************************************************************
#define AES_KEY1_6_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_6_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_7 register.
//
//*****************************************************************************
#define AES_KEY1_7_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_7_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_4 register.
//
//*****************************************************************************
#define AES_KEY1_4_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_4_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_5 register.
//
//*****************************************************************************
#define AES_KEY1_5_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_5_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_2 register.
//
//*****************************************************************************
#define AES_KEY1_2_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_2_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_3 register.
//
//*****************************************************************************
#define AES_KEY1_3_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_3_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_0 register.
//
//*****************************************************************************
#define AES_KEY1_0_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_0_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_KEY1_1 register.
//
//*****************************************************************************
#define AES_KEY1_1_KEY_M        0xFFFFFFFF  // key data
#define AES_KEY1_1_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_IV_IN_0 register.
//
//*****************************************************************************
#define AES_IV_IN_0_DATA_M      0xFFFFFFFF  // Initialization vector input
#define AES_IV_IN_0_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_IV_IN_1 register.
//
//*****************************************************************************
#define AES_IV_IN_1_DATA_M      0xFFFFFFFF  // Initialization vector input
#define AES_IV_IN_1_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_IV_IN_2 register.
//
//*****************************************************************************
#define AES_IV_IN_2_DATA_M      0xFFFFFFFF  // Initialization vector input
#define AES_IV_IN_2_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_IV_IN_3 register.
//
//*****************************************************************************
#define AES_IV_IN_3_DATA_M      0xFFFFFFFF  // Initialization vector input
#define AES_IV_IN_3_DATA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_CTRL register.
//
//*****************************************************************************
#define AES_CTRL_CTXTRDY        0x80000000  // Context Data Registers Ready
#define AES_CTRL_SVCTXTRDY      0x40000000  // AES TAG/IV block(s) Ready
#define AES_CTRL_SAVE_CONTEXT   0x20000000  // TAG or Result IV Save
#define AES_CTRL_CCM_M_M        0x01C00000  // Counter with CBC-MAC (CCM)
#define AES_CTRL_CCM_L_M        0x00380000  // L Value
#define AES_CTRL_CCM_L_2        0x00080000  // width = 2
#define AES_CTRL_CCM_L_4        0x00180000  // width = 4
#define AES_CTRL_CCM_L_8        0x00380000  // width = 8
#define AES_CTRL_CCM            0x00040000  // AES-CCM Mode
#define AES_CTRL_GCM_M          0x00030000  // AES-GCM Mode Enable
#define AES_CTRL_GCM_NOP        0x00000000  // No operation
#define AES_CTRL_GCM_HLY0ZERO   0x00010000  // GHASH with H loaded and
                                            // Y0-encrypted forced to zero
#define AES_CTRL_GCM_HLY0CALC   0x00020000  // GHASH with H loaded and
                                            // Y0-encrypted calculated
                                            // internally
#define AES_CTRL_GCM_HY0CALC    0x00030000  // Autonomous GHASH (both H and
                                            // Y0-encrypted calculated
                                            // internally)
#define AES_CTRL_CBCMAC         0x00008000  // AES-CBC MAC Enable
#define AES_CTRL_F9             0x00004000  // AES f9 Mode Enable
#define AES_CTRL_F8             0x00002000  // AES f8 Mode Enable
#define AES_CTRL_XTS_M          0x00001800  // AES-XTS Operation Enabled
#define AES_CTRL_XTS_NOP        0x00000000  // No operation
#define AES_CTRL_XTS_TWEAKJL    0x00000800  // Previous/intermediate tweak
                                            // value and j loaded (value is
                                            // loaded via IV, j is loaded via
                                            // the AAD length register)
#define AES_CTRL_XTS_K2IJL      0x00001000  // Key2, i and j loaded (i is
                                            // loaded via IV, j is loaded via
                                            // the AAD length register)
#define AES_CTRL_XTS_K2ILJ0     0x00001800  // Key2 and i loaded, j=0 (i is
                                            // loaded via IV)
#define AES_CTRL_CFB            0x00000400  // Full block AES cipher feedback
                                            // mode (CFB128) Enable
#define AES_CTRL_ICM            0x00000200  // AES integer counter mode (ICM)
                                            // Enable
#define AES_CTRL_CTR_WIDTH_M    0x00000180  // AES-CTR Mode Counter Width
#define AES_CTRL_CTR_WIDTH_32   0x00000000  // Counter is 32 bits
#define AES_CTRL_CTR_WIDTH_64   0x00000080  // Counter is 64 bits
#define AES_CTRL_CTR_WIDTH_96   0x00000100  // Counter is 96 bits
#define AES_CTRL_CTR_WIDTH_128  0x00000180  // Counter is 128 bits
#define AES_CTRL_CTR            0x00000040  // Counter Mode
#define AES_CTRL_MODE           0x00000020  // ECB/CBC Mode
#define AES_CTRL_KEY_SIZE_M     0x00000018  // Key Size
#define AES_CTRL_KEY_SIZE_128   0x00000008  // Key is 128 bits
#define AES_CTRL_KEY_SIZE_192   0x00000010  // Key is 192 bits
#define AES_CTRL_KEY_SIZE_256   0x00000018  // Key is 256 bits
#define AES_CTRL_DIRECTION      0x00000004  // Encryption/Decryption Selection
#define AES_CTRL_INPUT_READY    0x00000002  // Input Ready Status
#define AES_CTRL_OUTPUT_READY   0x00000001  // Output Ready Status
#define AES_CTRL_CCM_M_S        22

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_C_LENGTH_0
// register.
//
//*****************************************************************************
#define AES_C_LENGTH_0_LENGTH_M 0xFFFFFFFF  // Data length (LSW)
#define AES_C_LENGTH_0_LENGTH_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_C_LENGTH_1
// register.
//
//*****************************************************************************
#define AES_C_LENGTH_1_LENGTH_M 0xFFFFFFFF  // Data length (LSW)
#define AES_C_LENGTH_1_LENGTH_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_AUTH_LENGTH
// register.
//
//*****************************************************************************
#define AES_AUTH_LENGTH_AUTH_M  0xFFFFFFFF  // Data
#define AES_AUTH_LENGTH_AUTH_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DATA_IN_0
// register.
//
//*****************************************************************************
#define AES_DATA_IN_0_DATA_M    0xFFFFFFFF  // Data
#define AES_DATA_IN_0_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DATA_IN_1
// register.
//
//*****************************************************************************
#define AES_DATA_IN_1_DATA_M    0xFFFFFFFF  // Data
#define AES_DATA_IN_1_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DATA_IN_2
// register.
//
//*****************************************************************************
#define AES_DATA_IN_2_DATA_M    0xFFFFFFFF  // Data
#define AES_DATA_IN_2_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DATA_IN_3
// register.
//
//*****************************************************************************
#define AES_DATA_IN_3_DATA_M    0xFFFFFFFF  // Data
#define AES_DATA_IN_3_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_TAG_OUT_0
// register.
//
//*****************************************************************************
#define AES_TAG_OUT_0_HASH_M    0xFFFFFFFF  // Hash Result
#define AES_TAG_OUT_0_HASH_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_TAG_OUT_1
// register.
//
//*****************************************************************************
#define AES_TAG_OUT_1_HASH_M    0xFFFFFFFF  // Hash Result
#define AES_TAG_OUT_1_HASH_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_TAG_OUT_2
// register.
//
//*****************************************************************************
#define AES_TAG_OUT_2_HASH_M    0xFFFFFFFF  // Hash Result
#define AES_TAG_OUT_2_HASH_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_TAG_OUT_3
// register.
//
//*****************************************************************************
#define AES_TAG_OUT_3_HASH_M    0xFFFFFFFF  // Hash Result
#define AES_TAG_OUT_3_HASH_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_REVISION register.
//
//*****************************************************************************
#define AES_REVISION_M          0xFFFFFFFF  // Revision number
#define AES_REVISION_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_SYSCONFIG
// register.
//
//*****************************************************************************
#define AES_SYSCONFIG_K3        0x00001000  // K3 Select
#define AES_SYSCONFIG_KEYENC    0x00000800  // Key Encoding
#define AES_SYSCONFIG_MAP_CONTEXT_OUT_ON_DATA_OUT                             \
                                0x00000200  // Map Context Out on Data Out
                                            // Enable
#define AES_SYSCONFIG_DMA_REQ_CONTEXT_OUT_EN                                  \
                                0x00000100  // DMA Request Context Out Enable
#define AES_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN                                   \
                                0x00000080  // DMA Request Context In Enable
#define AES_SYSCONFIG_DMA_REQ_DATA_OUT_EN                                     \
                                0x00000040  // DMA Request Data Out Enable
#define AES_SYSCONFIG_DMA_REQ_DATA_IN_EN                                      \
                                0x00000020  // DMA Request Data In Enable
#define AES_SYSCONFIG_SOFTRESET 0x00000002  // Soft reset

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_SYSSTATUS
// register.
//
//*****************************************************************************
#define AES_SYSSTATUS_RESETDONE 0x00000001  // Indicates if reset is done

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_IRQSTATUS
// register.
//
//*****************************************************************************
#define AES_IRQSTATUS_CONTEXT_OUT                                             \
                                0x00000008  // This bit indicates
                                            // authentication tag (and IV)
                                            // interrupt(s) is/are active and
                                            // triggers the interrupt output
#define AES_IRQSTATUS_DATA_OUT  0x00000004  // This bit indicates data output
                                            // interrupt is active and triggers
                                            // the interrupt output
#define AES_IRQSTATUS_DATA_IN   0x00000002  // This bit indicates data input
                                            // interrupt is active and triggers
                                            // the interrupt output
#define AES_IRQSTATUS_CONTEXT_IN                                              \
                                0x00000001  // Context In Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_IRQENABLE
// register.
//
//*****************************************************************************
#define AES_IRQENABLE_CONTEXT_OUT                                             \
                                0x00000008  // This bit indicates
                                            // authentication tag (and IV)
                                            // interrupt(s) is/are enabled
#define AES_IRQENABLE_DATA_OUT  0x00000004  // This bit indicates data output
                                            // interrupt is enabled
#define AES_IRQENABLE_DATA_IN   0x00000002  // This bit indicates data input
                                            // interrupt is enabled
#define AES_IRQENABLE_CONTEXT_IN                                              \
                                0x00000001  // Context In Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DIRTYBITS
// register.
//
//*****************************************************************************
#define AES_DIRTYBITS_S_DIRTY   0x00000002  // This bit is set to 1 by the
                                            // module if any of the AES_S_*
                                            // registers is written
#define AES_DIRTYBITS_S_ACCESS  0x00000001  // This bit is set to 1 by the
                                            // module if any of the AES_S_*
                                            // registers is read

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DMAIM register.
//
//*****************************************************************************
#define AES_DMAIM_DOUT          0x00000008  // Data Out DMA Done Interrupt Mask
#define AES_DMAIM_DIN           0x00000004  // Data In DMA Done Interrupt Mask
#define AES_DMAIM_COUT          0x00000002  // Context Out DMA Done Interrupt
                                            // Mask
#define AES_DMAIM_CIN           0x00000001  // Context In DMA Done Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DMARIS register.
//
//*****************************************************************************
#define AES_DMARIS_DOUT         0x00000008  // Data Out DMA Done Raw Interrupt
                                            // Status
#define AES_DMARIS_DIN          0x00000004  // Data In DMA Done Raw Interrupt
                                            // Status
#define AES_DMARIS_COUT         0x00000002  // Context Out DMA Done Raw
                                            // Interrupt Status
#define AES_DMARIS_CIN          0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DMAMIS register.
//
//*****************************************************************************
#define AES_DMAMIS_DOUT         0x00000008  // Data Out DMA Done Masked
                                            // Interrupt Status
#define AES_DMAMIS_DIN          0x00000004  // Data In DMA Done Masked
                                            // Interrupt Status
#define AES_DMAMIS_COUT         0x00000002  // Context Out DMA Done Masked
                                            // Interrupt Status
#define AES_DMAMIS_CIN          0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the AES_O_DMAIC register.
//
//*****************************************************************************
#define AES_DMAIC_DOUT          0x00000008  // Data Out DMA Done Interrupt
                                            // Clear
#define AES_DMAIC_DIN           0x00000004  // Data In DMA Done Interrupt Clear
#define AES_DMAIC_COUT          0x00000002  // Context Out DMA Done Masked
                                            // Interrupt Status
#define AES_DMAIC_CIN           0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

#endif // __HW_AES_H__
