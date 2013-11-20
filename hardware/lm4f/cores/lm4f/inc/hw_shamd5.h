//*****************************************************************************
//
// hw_shamd5.h - Macros used when accessing the SHA/MD5 hardware.
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

#ifndef __HW_SHAMD5_H__
#define __HW_SHAMD5_H__

//*****************************************************************************
//
// The following are defines for the SHA/MD5 register offsets.
//
//*****************************************************************************
#define SHAMD5_O_ODIGEST_A      0x00000000  // SHA Secure Outer Digest A
#define SHAMD5_O_ODIGEST_B      0x00000004  // SHA Secure Outer Digest B
#define SHAMD5_O_ODIGEST_C      0x00000008  // SHA Secure Outer Digest C
#define SHAMD5_O_ODIGEST_D      0x0000000C  // SHA Secure Outer Digest D
#define SHAMD5_O_ODIGEST_E      0x00000010  // SHA Secure Outer Digest E
#define SHAMD5_O_ODIGEST_F      0x00000014  // SHA Secure Outer Digest F
#define SHAMD5_O_ODIGEST_G      0x00000018  // SHA Secure Outer Digest G
#define SHAMD5_O_ODIGEST_H      0x0000001C  // SHA Secure Outer Digest H
#define SHAMD5_O_IDIGEST_A      0x00000020  // SHA Secure Inner Digest A
#define SHAMD5_O_IDIGEST_B      0x00000024  // SHA Secure Inner Digest B
#define SHAMD5_O_IDIGEST_C      0x00000028  // SHA Secure Inner Digest C
#define SHAMD5_O_IDIGEST_D      0x0000002C  // SHA Secure Inner Digest D
#define SHAMD5_O_IDIGEST_E      0x00000030  // SHA Secure Inner Digest E
#define SHAMD5_O_IDIGEST_F      0x00000034  // SHA Secure Inner Digest F
#define SHAMD5_O_IDIGEST_G      0x00000038  // SHA Secure Inner Digest G
#define SHAMD5_O_IDIGEST_H      0x0000003C  // SHA Secure Inner Digest H
#define SHAMD5_O_DIGEST_COUNT   0x00000040  // SHA Secure Digest Count
#define SHAMD5_O_MODE           0x00000044  // SHA Secure Mode
#define SHAMD5_O_LENGTH         0x00000048  // SHA Secure Mode
#define SHAMD5_O_DATA_0_IN      0x00000080  // SHA Secure Data 0 Input
#define SHAMD5_O_DATA_1_IN      0x00000084  // SHA Secure Data 1 Input
#define SHAMD5_O_DATA_2_IN      0x00000088  // SHA Secure Data 2 Input
#define SHAMD5_O_DATA_3_IN      0x0000008C  // SHA Secure Data 3 Input
#define SHAMD5_O_DATA_4_IN      0x00000090  // SHA Secure Data 4 Input
#define SHAMD5_O_DATA_5_IN      0x00000094  // SHA Secure Data 5 Input
#define SHAMD5_O_DATA_6_IN      0x00000098  // SHA Secure Data 6 Input
#define SHAMD5_O_DATA_7_IN      0x0000009C  // SHA Secure Data 7 Input
#define SHAMD5_O_DATA_8_IN      0x000000A0  // SHA Secure Data 8 Input
#define SHAMD5_O_DATA_9_IN      0x000000A4  // SHA Secure Data 9 Input
#define SHAMD5_O_DATA_10_IN     0x000000A8  // SHA Secure Data 10 Input
#define SHAMD5_O_DATA_11_IN     0x000000AC  // SHA Secure Data 11 Input
#define SHAMD5_O_DATA_12_IN     0x000000B0  // SHA Secure Data 12 Input
#define SHAMD5_O_DATA_13_IN     0x000000B4  // SHA Secure Data 13 Input
#define SHAMD5_O_DATA_14_IN     0x000000B8  // SHA Secure Data 14 Input
#define SHAMD5_O_DATA_15_IN     0x000000BC  // SHA Secure Data 15 Input
#define SHAMD5_O_REVISION       0x00000100  // SHA Secure Revision
#define SHAMD5_O_SYSCONFIG      0x00000110  // SHA Secure System Configuration
#define SHAMD5_O_SYSSTATUS      0x00000114  // SHA Secure System Status
#define SHAMD5_O_IRQSTATUS      0x00000118  // SHA Secure Interrupt Status
#define SHAMD5_O_IRQENABLE      0x0000011C  // SHA Secure Interrupt Enable
#define SHAMD5_O_DMAIM          0xFFFFC010  // SHA DMA Interrupt Mask
#define SHAMD5_O_DMARIS         0xFFFFC014  // SHA DMA Raw Interrupt Status
#define SHAMD5_O_DMAMIS         0xFFFFC018  // SHA DMA Masked Interrupt Status
#define SHAMD5_O_DMAIC          0xFFFFC01C  // SHA DMA Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_A
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_A_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_A_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_B
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_B_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_B_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_C
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_C_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_C_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_D
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_D_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_D_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_E
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_E_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_E_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_F
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_F_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_F_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_G
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_G_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_G_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_ODIGEST_H
// register.
//
//*****************************************************************************
#define SHAMD5_ODIGEST_H_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_ODIGEST_H_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_A
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_A_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_A_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_B
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_B_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_B_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_C
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_C_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_C_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_D
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_D_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_D_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_E
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_E_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_E_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_F
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_F_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_F_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_G
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_G_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_G_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IDIGEST_H
// register.
//
//*****************************************************************************
#define SHAMD5_IDIGEST_H_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_IDIGEST_H_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DIGEST_COUNT
// register.
//
//*****************************************************************************
#define SHAMD5_DIGEST_COUNT_M   0xFFFFFFFF  // Data
#define SHAMD5_DIGEST_COUNT_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_MODE register.
//
//*****************************************************************************
#define SHAMD5_MODE_HMAC_OUTER_HASH                                           \
                                0x00000080  // The HMAC Outer Hash is performed
                                            // on the hash digest when the
                                            // inner hash has finished (block
                                            // length exhausted and final hash
                                            // performed if close_hash is 1)
#define SHAMD5_MODE_HMAC_KEY_PROC                                             \
                                0x00000020  // Performs HMAC key processing on
                                            // the 512 bit HMAC key loaded into
                                            // the SHA_S_IDIGEST_{A to H} and
                                            // SHA_S_ODIGEST_{A to H} register
                                            // block
#define SHAMD5_MODE_CLOSE_HASH  0x00000010  // Performs the padding, the
                                            // Hash/HMAC will be 'closed' at
                                            // the end of the block, as per
                                            // MD5/SHA-1/SHA-2 specification (i
#define SHAMD5_MODE_ALGO_CONSTANT                                             \
                                0x00000008  // The initial digest register will
                                            // be overwritten with the
                                            // algorithm constants for the
                                            // selected algorithm when hashing
                                            // and the initial digest count
                                            // register will be reset to 0
#define SHAMD5_MODE_ALGO_M      0x00000007  // Hash Algorithm
#define SHAMD5_MODE_ALGO_MD5    0x00000000  // MD5
#define SHAMD5_MODE_ALGO_SHA1   0x00000002  // SHA-1
#define SHAMD5_MODE_ALGO_SHA224 0x00000004  // SHA-224
#define SHAMD5_MODE_ALGO_SHA256 0x00000006  // SHA-256

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_LENGTH
// register.
//
//*****************************************************************************
#define SHAMD5_LENGTH_M         0xFFFFFFFF  // Data
#define SHAMD5_LENGTH_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_0_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_0_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_0_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_1_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_1_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_1_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_2_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_2_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_2_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_3_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_3_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_3_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_4_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_4_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_4_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_5_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_5_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_5_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_6_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_6_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_6_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_7_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_7_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_7_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_8_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_8_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_8_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_9_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_9_IN_DATA_M 0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_9_IN_DATA_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_10_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_10_IN_DATA_M                                              \
                                0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_10_IN_DATA_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_11_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_11_IN_DATA_M                                              \
                                0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_11_IN_DATA_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_12_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_12_IN_DATA_M                                              \
                                0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_12_IN_DATA_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_13_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_13_IN_DATA_M                                              \
                                0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_13_IN_DATA_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_14_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_14_IN_DATA_M                                              \
                                0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_14_IN_DATA_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DATA_15_IN
// register.
//
//*****************************************************************************
#define SHAMD5_DATA_15_IN_DATA_M                                              \
                                0xFFFFFFFF  // Digest/Key Data
#define SHAMD5_DATA_15_IN_DATA_S                                              \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_REVISION
// register.
//
//*****************************************************************************
#define SHAMD5_REVISION_M       0xFFFFFFFF  // Revision Number
#define SHAMD5_REVISION_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_SYSCONFIG
// register.
//
//*****************************************************************************
#define SHAMD5_SYSCONFIG_SADVANCED                                            \
                                0x00000080  // Secure World Advanced Mode
                                            // Enable
#define SHAMD5_SYSCONFIG_SIDLE_M                                              \
                                0x00000030  // Sidle mode
#define SHAMD5_SYSCONFIG_SIDLE_FORCE                                          \
                                0x00000000  // Force-idle mode
#define SHAMD5_SYSCONFIG_DMA_EN 0x00000008  // uDMA Request Enable
#define SHAMD5_SYSCONFIG_IT_EN  0x00000004  // Interrupt Enable
#define SHAMD5_SYSCONFIG_SOFTRESET                                            \
                                0x00000002  // Soft reset

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_SYSSTATUS
// register.
//
//*****************************************************************************
#define SHAMD5_SYSSTATUS_RESETDONE                                            \
                                0x00000001  // Reset done status

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IRQSTATUS
// register.
//
//*****************************************************************************
#define SHAMD5_IRQSTATUS_CONTEXT_READY                                        \
                                0x00000008  // Indicates that the HIB1 context
                                            // input registers are available
                                            // for a new context for the next
                                            // packet to be processed
#define SHAMD5_IRQSTATUS_INPUT_READY                                          \
                                0x00000002  // Indicates that the HIB1 data
                                            // FIFO is ready to receive the
                                            // next 64 byte data block
#define SHAMD5_IRQSTATUS_OUTPUT_READY                                         \
                                0x00000001  // Indicates that a (partial)
                                            // result or saved context is
                                            // available from the HIB1 context
                                            // output registers

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_IRQENABLE
// register.
//
//*****************************************************************************
#define SHAMD5_IRQENABLE_CONTEXT_READY                                        \
                                0x00000008  // Mask for context ready interrupt
#define SHAMD5_IRQENABLE_INPUT_READY                                          \
                                0x00000002  // Mask for input ready interrupt
#define SHAMD5_IRQENABLE_OUTPUT_READY                                         \
                                0x00000001  // Mask for output ready interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DMAIM register.
//
//*****************************************************************************
#define SHAMD5_DMAIM_COUT       0x00000004  // Context Out DMA Done Interrupt
                                            // Mask
#define SHAMD5_DMAIM_DIN        0x00000002  // Data In DMA Done Interrupt Mask
#define SHAMD5_DMAIM_CIN        0x00000001  // Context In DMA Done Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DMARIS
// register.
//
//*****************************************************************************
#define SHAMD5_DMARIS_COUT      0x00000004  // Context Out DMA Done Raw
                                            // Interrupt Status
#define SHAMD5_DMARIS_DIN       0x00000002  // Data In DMA Done Raw Interrupt
                                            // Status
#define SHAMD5_DMARIS_CIN       0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DMAMIS
// register.
//
//*****************************************************************************
#define SHAMD5_DMAMIS_COUT      0x00000004  // Context Out DMA Done Masked
                                            // Interrupt Status
#define SHAMD5_DMAMIS_DIN       0x00000002  // Data In DMA Done Masked
                                            // Interrupt Status
#define SHAMD5_DMAMIS_CIN       0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SHAMD5_O_DMAIC register.
//
//*****************************************************************************
#define SHAMD5_DMAIC_COUT       0x00000004  // Context Out DMA Done Masked
                                            // Interrupt Status
#define SHAMD5_DMAIC_DIN        0x00000002  // Data In DMA Done Interrupt Clear
#define SHAMD5_DMAIC_CIN        0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

#endif // __HW_SHAMD5_H__
