//*****************************************************************************
//
// hw_des.h - Macros used when accessing the DES hardware.
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

#ifndef __HW_DES_H__
#define __HW_DES_H__

//*****************************************************************************
//
// The following are defines for the DES register offsets.
//
//*****************************************************************************
#define DES_O_KEY3_L            0x00000000  // DES3DES Key 3 LSW for 192-bit
                                            // key
#define DES_O_KEY3_H            0x00000004  // DES3DES Key 3 MSW for 192-bit
                                            // key
#define DES_O_KEY2_L            0x00000008  // DES3DES Key 2 LSW for 128-bit
                                            // key
#define DES_O_KEY2_H            0x0000000C  // DES3DES Key 2 MSW for 128-bit
                                            // key
#define DES_O_KEY1_L            0x00000010  // DES3DES Key 1 LSW for 64-bit key
#define DES_O_KEY1_H            0x00000014  // DES3DES Key 1 MSW for 64-bit key
#define DES_O_IV_L              0x00000018  // DES3DES Secure Initialization
                                            // Vector
#define DES_O_IV_H              0x0000001C  // DES3DES Secure Initialization
                                            // Vector
#define DES_O_CTRL              0x00000020  // DES3DES Secure Control
#define DES_O_LENGTH            0x00000024  // DES3DES Secure Cryptographic
                                            // Data Length
#define DES_O_DATA_L            0x00000028  // DES3DES Secure LSW Data R/W
#define DES_O_DATA_H            0x0000002C  // DES3DES Secure MSW Data R/W
#define DES_O_REVISION          0x00000030  // DES3DES Secure Revision Number
#define DES_O_SYSCONFIG         0x00000034  // DES3DES Secure System
                                            // Configuration
#define DES_O_SYSSTATUS         0x00000038  // DES3DES Secure System Status
#define DES_O_IRQSTATUS         0x0000003C  // DES3DES Secure Interrupt Status
#define DES_O_IRQENABLE         0x00000040  // DES3DES Secure Interrupt Enable
#define DES_O_DIRTYBITS         0x00000044  // DES3DES Secure Dirty Bits
#define DES_O_DMAIM             0xFFFF8030  // DES DMA Interrupt Mask
#define DES_O_DMARIS            0xFFFF8034  // DES DMA Raw Interrupt Status
#define DES_O_DMAMIS            0xFFFF8038  // DES DMA Masked Interrupt Status
#define DES_O_DMAIC             0xFFFF803C  // DES DMA Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_KEY3_L register.
//
//*****************************************************************************
#define DES_KEY3_L_KEY_M        0xFFFFFFFF  // Key Data
#define DES_KEY3_L_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_KEY3_H register.
//
//*****************************************************************************
#define DES_KEY3_H_KEY_M        0xFFFFFFFF  // Key Data
#define DES_KEY3_H_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_KEY2_L register.
//
//*****************************************************************************
#define DES_KEY2_L_KEY_M        0xFFFFFFFF  // Key Data
#define DES_KEY2_L_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_KEY2_H register.
//
//*****************************************************************************
#define DES_KEY2_H_KEY_M        0xFFFFFFFF  // Key Data
#define DES_KEY2_H_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_KEY1_L register.
//
//*****************************************************************************
#define DES_KEY1_L_KEY_M        0xFFFFFFFF  // Key Data
#define DES_KEY1_L_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_KEY1_H register.
//
//*****************************************************************************
#define DES_KEY1_H_KEY_M        0xFFFFFFFF  // Key Data
#define DES_KEY1_H_KEY_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_IV_L register.
//
//*****************************************************************************
#define DES_IV_L_M              0xFFFFFFFF  // Initialization vector for CBC,
                                            // CFB modes (LSW)
#define DES_IV_L_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_IV_H register.
//
//*****************************************************************************
#define DES_IV_H_M              0xFFFFFFFF  // Initialization vector for CBC,
                                            // CFB modes (MSW)
#define DES_IV_H_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_CTRL register.
//
//*****************************************************************************
#define DES_CTRL_CONTEXT        0x80000000  // If 1, this read-only status bit
                                            // indicates that the context data
                                            // registers can be overwritten and
                                            // the host is permitted to write
                                            // the next context
#define DES_CTRL_MODE_M         0x00000030  // Select CBC, ECB or CFB mode0x0:
                                            // ECB mode0x1: CBC mode0x2: CFB
                                            // mode0x3: reserved
#define DES_CTRL_TDES           0x00000008  // Select DES or triple DES
                                            // encryption/decryption
#define DES_CTRL_DIRECTION      0x00000004  // Select encryption/decryption
                                            // 0x0: decryption is selected0x1:
                                            // Encryption is selected
#define DES_CTRL_INPUT_READY    0x00000002  // When '1', ready to
                                            // encrypt/decrypt data
#define DES_CTRL_OUTPUT_READY   0x00000001  // When '1', Data
                                            // decrypted/encrypted ready
#define DES_CTRL_MODE_S         4

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_LENGTH register.
//
//*****************************************************************************
#define DES_LENGTH_M            0xFFFFFFFF  // Cryptographic data length in
                                            // bytes for all modes
#define DES_LENGTH_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DATA_L register.
//
//*****************************************************************************
#define DES_DATA_L_M            0xFFFFFFFF  // Data for encryption/decryption,
                                            // LSW
#define DES_DATA_L_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DATA_H register.
//
//*****************************************************************************
#define DES_DATA_H_M            0xFFFFFFFF  // Data for encryption/decryption,
                                            // MSW
#define DES_DATA_H_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_REVISION register.
//
//*****************************************************************************
#define DES_REVISION_M          0xFFFFFFFF  // Revision number
#define DES_REVISION_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_SYSCONFIG
// register.
//
//*****************************************************************************
#define DES_SYSCONFIG_DMA_REQ_CONTEXT_IN_EN                                   \
                                0x00000080  // DMA Request Context In Enable
#define DES_SYSCONFIG_DMA_REQ_DATA_OUT_EN                                     \
                                0x00000040  // DMA Request Data Out Enable
#define DES_SYSCONFIG_DMA_REQ_DATA_IN_EN                                      \
                                0x00000020  // DMA Request Data In Enable
#define DES_SYSCONFIG_SIDLE_M   0x0000000C  // Sidle mode
#define DES_SYSCONFIG_SIDLE_FORCE                                             \
                                0x00000000  // Force-idle mode
#define DES_SYSCONFIG_SOFTRESET 0x00000002  // Soft reset

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_SYSSTATUS
// register.
//
//*****************************************************************************
#define DES_SYSSTATUS_RESETDONE 0x00000001  // Reset Done

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_IRQSTATUS
// register.
//
//*****************************************************************************
#define DES_IRQSTATUS_DATA_OUT  0x00000004  // This bit indicates data output
                                            // interrupt is active and triggers
                                            // the interrupt output
#define DES_IRQSTATUS_DATA_IN   0x00000002  // This bit indicates data input
                                            // interrupt is active and triggers
                                            // the interrupt output
#define DES_IRQSTATUS_CONTEX_IN 0x00000001  // This bit indicates context
                                            // interrupt is active and triggers
                                            // the interrupt output

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_IRQENABLE
// register.
//
//*****************************************************************************
#define DES_IRQENABLE_M_DATA_OUT                                              \
                                0x00000004  // If this bit is set to 1 the
                                            // secure data output interrupt is
                                            // enabled
#define DES_IRQENABLE_M_DATA_IN 0x00000002  // If this bit is set to 1 the
                                            // secure data input interrupt is
                                            // enabled
#define DES_IRQENABLE_M_CONTEX_IN                                             \
                                0x00000001  // If this bit is set to 1 the
                                            // secure context interrupt is
                                            // enabled

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DIRTYBITS
// register.
//
//*****************************************************************************
#define DES_DIRTYBITS_S_DIRTY   0x00000002  // This bit is set to 1 by the
                                            // module if any of the DES_S_*
                                            // registers is written
#define DES_DIRTYBITS_S_ACCESS  0x00000001  // This bit is set to 1 by the
                                            // module if any of the DES_S_*
                                            // registers is read

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DMAIM register.
//
//*****************************************************************************
#define DES_DMAIM_DOUT          0x00000004  // Data Out DMA Done Interrupt Mask
#define DES_DMAIM_DIN           0x00000002  // Data In DMA Done Interrupt Mask
#define DES_DMAIM_CIN           0x00000001  // Context In DMA Done Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DMARIS register.
//
//*****************************************************************************
#define DES_DMARIS_DOUT         0x00000004  // Data Out DMA Done Raw Interrupt
                                            // Status
#define DES_DMARIS_DIN          0x00000002  // Data In DMA Done Raw Interrupt
                                            // Status
#define DES_DMARIS_CIN          0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DMAMIS register.
//
//*****************************************************************************
#define DES_DMAMIS_DOUT         0x00000004  // Data Out DMA Done Masked
                                            // Interrupt Status
#define DES_DMAMIS_DIN          0x00000002  // Data In DMA Done Masked
                                            // Interrupt Status
#define DES_DMAMIS_CIN          0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the DES_O_DMAIC register.
//
//*****************************************************************************
#define DES_DMAIC_DOUT          0x00000004  // Data Out DMA Done Interrupt
                                            // Clear
#define DES_DMAIC_DIN           0x00000002  // Data In DMA Done Interrupt Clear
#define DES_DMAIC_CIN           0x00000001  // Context In DMA Done Raw
                                            // Interrupt Status

#endif // __HW_DES_H__
