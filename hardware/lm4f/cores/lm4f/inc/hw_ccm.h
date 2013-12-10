//*****************************************************************************
//
// hw_ccm.h - Macros used when accessing the CCM hardware.
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

#ifndef __HW_CCM_H__
#define __HW_CCM_H__

//*****************************************************************************
//
// The following are defines for the EC register offsets.
//
//*****************************************************************************
#define CCM_O_CRCCTRL           0x00000400  // CRC Control
#define CCM_O_CRCSEED           0x00000410  // CRC SEED/Context
#define CCM_O_CRCDIN            0x00000414  // CRC Data Input
#define CCM_O_CRCRSLTPP         0x00000418  // CRC Post Processing Result

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCCTRL register.
//
//*****************************************************************************
#define CCM_CRCCTRL_INIT_M      0x00006000  // CRC Initialization
#define CCM_CRCCTRL_INIT_SEED   0x00000000  // Use the EC_S_CRC_SEED register
                                            // context as the starting value
#define CCM_CRCCTRL_INIT_0      0x00004000  // Initialize to all '0s'
#define CCM_CRCCTRL_INIT_1      0x00006000  // Initialize to all '1s'
#define CCM_CRCCTRL_SIZE        0x00001000  // Input Data Size
#define CCM_CRCCTRL_RESINV      0x00000200  // Result Inverse Enable
#define CCM_CRCCTRL_OBR         0x00000100  // Output Reverse Enable
#define CCM_CRCCTRL_BR          0x00000080  // Bit reverse enable
#define CCM_CRCCTRL_ENDIAN_M    0x00000030  // Endian Control
#define CCM_CRCCTRL_ENDIAN_SBHW 0x00000000  // Configuration unchanged. (B3,
                                            // B2, B1, B0)
#define CCM_CRCCTRL_ENDIAN_SHW  0x00000010  // Bytes are swapped in half-words
                                            // but half-words are not swapped
                                            // (B2, B3, B0, B1)
#define CCM_CRCCTRL_ENDIAN_SHWNB                                              \
                                0x00000020  // Half-words are swapped but bytes
                                            // are not swapped in half-word.
                                            // (B1, B0, B3, B2)
#define CCM_CRCCTRL_ENDIAN_SBSW 0x00000030  // Bytes are swapped in half-words
                                            // and half-words are swapped. (B0,
                                            // B1, B2, B3)
#define CCM_CRCCTRL_TYPE_M      0x0000000F  // Operation Type
#define CCM_CRCCTRL_TYPE_P8055  0x00000000  // Polynomial 0x8005
#define CCM_CRCCTRL_TYPE_P1021  0x00000001  // Polynomial 0x1021
#define CCM_CRCCTRL_TYPE_P4C11DB7                                             \
                                0x00000002  // Polynomial 0x4C11DB7
#define CCM_CRCCTRL_TYPE_P1EDC6F41                                            \
                                0x00000003  // Polynomial 0x1EDC6F41
#define CCM_CRCCTRL_TYPE_TCPCHKSUM                                            \
                                0x00000008  // TCP checksum

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCSEED register.
//
//*****************************************************************************
#define CCM_CRCSEED_SEED_M      0xFFFFFFFF  // SEED/Context Value
#define CCM_CRCSEED_SEED_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCDIN register.
//
//*****************************************************************************
#define CCM_CRCDIN_DATAIN_M     0xFFFFFFFF  // Data Input
#define CCM_CRCDIN_DATAIN_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the CCM_O_CRCRSLTPP
// register.
//
//*****************************************************************************
#define CCM_CRCRSLTPP_RSLTPP_M  0xFFFFFFFF  // Post Processing Result
#define CCM_CRCRSLTPP_RSLTPP_S  0

#endif // __HW_CCM_H__
