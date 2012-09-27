//*****************************************************************************
//
// hw_i2s.h - Macros for use in accessing the I2S registers.
//
// Copyright (c) 2008-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Firmware Development Package.
//
//*****************************************************************************

#ifndef __HW_I2S_H__
#define __HW_I2S_H__

//*****************************************************************************
//
// The following are defines for the Inter-Integrated Circuit Sound register
// offsets.
//
//*****************************************************************************
#define I2S_O_TXFIFO            0x00000000  // I2S Transmit FIFO Data
#define I2S_O_TXFIFOCFG         0x00000004  // I2S Transmit FIFO Configuration
#define I2S_O_TXCFG             0x00000008  // I2S Transmit Module
                                            // Configuration
#define I2S_O_TXLIMIT           0x0000000C  // I2S Transmit FIFO Limit
#define I2S_O_TXISM             0x00000010  // I2S Transmit Interrupt Status
                                            // and Mask
#define I2S_O_TXLEV             0x00000018  // I2S Transmit FIFO Level
#define I2S_O_RXFIFO            0x00000800  // I2S Receive FIFO Data
#define I2S_O_RXFIFOCFG         0x00000804  // I2S Receive FIFO Configuration
#define I2S_O_RXCFG             0x00000808  // I2S Receive Module Configuration
#define I2S_O_RXLIMIT           0x0000080C  // I2S Receive FIFO Limit
#define I2S_O_RXISM             0x00000810  // I2S Receive Interrupt Status and
                                            // Mask
#define I2S_O_RXLEV             0x00000818  // I2S Receive FIFO Level
#define I2S_O_CFG               0x00000C00  // I2S Module Configuration
#define I2S_O_IM                0x00000C10  // I2S Interrupt Mask
#define I2S_O_RIS               0x00000C14  // I2S Raw Interrupt Status
#define I2S_O_MIS               0x00000C18  // I2S Masked Interrupt Status
#define I2S_O_IC                0x00000C1C  // I2S Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXFIFO register.
//
//*****************************************************************************
#define I2S_TXFIFO_M            0xFFFFFFFF  // TX Data
#define I2S_TXFIFO_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXFIFOCFG
// register.
//
//*****************************************************************************
#define I2S_TXFIFOCFG_CSS       0x00000002  // Compact Stereo Sample Size
#define I2S_TXFIFOCFG_LRS       0x00000001  // Left-Right Sample Indicator

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXCFG register.
//
//*****************************************************************************
#define I2S_TXCFG_JST           0x20000000  // Justification of Output Data
#define I2S_TXCFG_DLY           0x10000000  // Data Delay
#define I2S_TXCFG_SCP           0x08000000  // SCLK Polarity
#define I2S_TXCFG_LRP           0x04000000  // Left/Right Clock Polarity
#define I2S_TXCFG_WM_M          0x03000000  // Write Mode
#define I2S_TXCFG_WM_DUAL       0x00000000  // Stereo mode
#define I2S_TXCFG_WM_COMPACT    0x01000000  // Compact Stereo mode
#define I2S_TXCFG_WM_MONO       0x02000000  // Mono mode
#define I2S_TXCFG_FMT           0x00800000  // FIFO Empty
#define I2S_TXCFG_MSL           0x00400000  // SCLK Master/Slave
#define I2S_TXCFG_SSZ_M         0x0000FC00  // Sample Size
#define I2S_TXCFG_SDSZ_M        0x000003F0  // System Data Size
#define I2S_TXCFG_SSZ_S         10
#define I2S_TXCFG_SDSZ_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXLIMIT register.
//
//*****************************************************************************
#define I2S_TXLIMIT_LIMIT_M     0x0000001F  // FIFO Limit
#define I2S_TXLIMIT_LIMIT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXISM register.
//
//*****************************************************************************
#define I2S_TXISM_FFI           0x00010000  // Transmit FIFO Service Request
                                            // Interrupt
#define I2S_TXISM_FFM           0x00000001  // FIFO Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_TXLEV register.
//
//*****************************************************************************
#define I2S_TXLEV_LEVEL_M       0x0000001F  // Number of Audio Samples
#define I2S_TXLEV_LEVEL_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXFIFO register.
//
//*****************************************************************************
#define I2S_RXFIFO_M            0xFFFFFFFF  // RX Data
#define I2S_RXFIFO_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXFIFOCFG
// register.
//
//*****************************************************************************
#define I2S_RXFIFOCFG_FMM       0x00000004  // FIFO Mono Mode
#define I2S_RXFIFOCFG_CSS       0x00000002  // Compact Stereo Sample Size
#define I2S_RXFIFOCFG_LRS       0x00000001  // Left-Right Sample Indicator

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXCFG register.
//
//*****************************************************************************
#define I2S_RXCFG_JST           0x20000000  // Justification of Input Data
#define I2S_RXCFG_DLY           0x10000000  // Data Delay
#define I2S_RXCFG_SCP           0x08000000  // SCLK Polarity
#define I2S_RXCFG_LRP           0x04000000  // Left/Right Clock Polarity
#define I2S_RXCFG_RM            0x01000000  // Read Mode
#define I2S_RXCFG_MSL           0x00400000  // SCLK Master/Slave
#define I2S_RXCFG_SSZ_M         0x0000FC00  // Sample Size
#define I2S_RXCFG_SDSZ_M        0x000003F0  // System Data Size
#define I2S_RXCFG_SSZ_S         10
#define I2S_RXCFG_SDSZ_S        4

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXLIMIT register.
//
//*****************************************************************************
#define I2S_RXLIMIT_LIMIT_M     0x0000001F  // FIFO Limit
#define I2S_RXLIMIT_LIMIT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXISM register.
//
//*****************************************************************************
#define I2S_RXISM_FFI           0x00010000  // Receive FIFO Service Request
                                            // Interrupt
#define I2S_RXISM_FFM           0x00000001  // FIFO Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RXLEV register.
//
//*****************************************************************************
#define I2S_RXLEV_LEVEL_M       0x0000001F  // Number of Audio Samples
#define I2S_RXLEV_LEVEL_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_CFG register.
//
//*****************************************************************************
#define I2S_CFG_RXSLV           0x00000020  // Use External I2S0RXMCLK
#define I2S_CFG_TXSLV           0x00000010  // Use External I2S0TXMCLK
#define I2S_CFG_RXEN            0x00000002  // Serial Receive Engine Enable
#define I2S_CFG_TXEN            0x00000001  // Serial Transmit Engine Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_IM register.
//
//*****************************************************************************
#define I2S_IM_RXRE             0x00000020  // Receive FIFO Read Error
#define I2S_IM_RXFSR            0x00000010  // Receive FIFO Service Request
#define I2S_IM_TXWE             0x00000002  // Transmit FIFO Write Error
#define I2S_IM_TXFSR            0x00000001  // Transmit FIFO Service Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_RIS register.
//
//*****************************************************************************
#define I2S_RIS_RXRE            0x00000020  // Receive FIFO Read Error
#define I2S_RIS_RXFSR           0x00000010  // Receive FIFO Service Request
#define I2S_RIS_TXWE            0x00000002  // Transmit FIFO Write Error
#define I2S_RIS_TXFSR           0x00000001  // Transmit FIFO Service Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_MIS register.
//
//*****************************************************************************
#define I2S_MIS_RXRE            0x00000020  // Receive FIFO Read Error
#define I2S_MIS_RXFSR           0x00000010  // Receive FIFO Service Request
#define I2S_MIS_TXWE            0x00000002  // Transmit FIFO Write Error
#define I2S_MIS_TXFSR           0x00000001  // Transmit FIFO Service Request

//*****************************************************************************
//
// The following are defines for the bit fields in the I2S_O_IC register.
//
//*****************************************************************************
#define I2S_IC_RXRE             0x00000020  // Receive FIFO Read Error
#define I2S_IC_TXWE             0x00000002  // Transmit FIFO Write Error

#endif // __HW_I2S_H__
