//*****************************************************************************
//
// i2s.h - Prototypes and macros for the I2S controller.
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
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __I2S_H__
#define __I2S_H__

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
// Values that can be passed to I2STxConfigSet() and I2SRxConfigSet()
//
//*****************************************************************************
#define I2S_CONFIG_FORMAT_MASK  0x3C000000  //  JST,  DLY,  SCP,  LRP
#define I2S_CONFIG_FORMAT_I2S   0x14000000  // !JST,  DLY, !SCP,  LRP
#define I2S_CONFIG_FORMAT_LEFT_JUST \
                                0x00000000  // !JST, !DLY, !SCP, !LRP
#define I2S_CONFIG_FORMAT_RIGHT_JUST \
                                0x20000000  //  JST, !DLY, !SCP, !LRP

#define I2S_CONFIG_SCLK_INVERT  0x08000000

#define I2S_CONFIG_MODE_MASK    0x03000000
#define I2S_CONFIG_MODE_DUAL    0x00000000
#define I2S_CONFIG_MODE_COMPACT_16 \
                                0x01000000
#define I2S_CONFIG_MODE_COMPACT_8 \
                                0x03000000
#define I2S_CONFIG_MODE_MONO    0x02000000

#define I2S_CONFIG_EMPTY_MASK   0x00800000
#define I2S_CONFIG_EMPTY_ZERO   0x00000000
#define I2S_CONFIG_EMPTY_REPEAT 0x00800000

#define I2S_CONFIG_CLK_MASK     0x00400000
#define I2S_CONFIG_CLK_MASTER   0x00400000
#define I2S_CONFIG_CLK_SLAVE    0x00000000

#define I2S_CONFIG_SAMPLE_SIZE_MASK \
                                0x0000FC00
#define I2S_CONFIG_SAMPLE_SIZE_32 \
                                0x00007C00
#define I2S_CONFIG_SAMPLE_SIZE_24 \
                                0x00005C00
#define I2S_CONFIG_SAMPLE_SIZE_20 \
                                0x00004C00
#define I2S_CONFIG_SAMPLE_SIZE_16 \
                                0x00003C00
#define I2S_CONFIG_SAMPLE_SIZE_8 \
                                0x00001C00

#define I2S_CONFIG_WIRE_SIZE_MASK \
                                0x000003F0
#define I2S_CONFIG_WIRE_SIZE_32 0x000001F0
#define I2S_CONFIG_WIRE_SIZE_24 0x00000170
#define I2S_CONFIG_WIRE_SIZE_20 0x00000130
#define I2S_CONFIG_WIRE_SIZE_16 0x000000F0
#define I2S_CONFIG_WIRE_SIZE_8  0x00000070

//*****************************************************************************
//
// Values that can be passed to I2SMasterClockSelect()
//
//*****************************************************************************
#define I2S_TX_MCLK_EXT         0x00000010
#define I2S_TX_MCLK_INT         0x00000000
#define I2S_RX_MCLK_EXT         0x00000020
#define I2S_RX_MCLK_INT         0x00000000

//*****************************************************************************
//
// Values that can be passed to I2SIntEnable(), I2SIntDisable(), and
// I2SIntClear()
//
//*****************************************************************************
#define I2S_INT_RXERR           0x00000020
#define I2S_INT_RXREQ           0x00000010
#define I2S_INT_TXERR           0x00000002
#define I2S_INT_TXREQ           0x00000001

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void I2STxEnable(unsigned long ulBase);
extern void I2STxDisable(unsigned long ulBase);
extern void I2STxDataPut(unsigned long ulBase, unsigned long ulData);
extern long I2STxDataPutNonBlocking(unsigned long ulBase,
                                    unsigned long ulData);
extern void I2STxConfigSet(unsigned long ulBase, unsigned long ulConfig);
extern void I2STxFIFOLimitSet(unsigned long ulBase, unsigned long ulLevel);
extern unsigned long I2STxFIFOLimitGet(unsigned long ulBase);
extern unsigned long I2STxFIFOLevelGet(unsigned long ulBase);
extern void I2SRxEnable(unsigned long ulBase);
extern void I2SRxDisable(unsigned long ulBase);
extern void I2SRxDataGet(unsigned long ulBase, unsigned long *pulData);
extern long I2SRxDataGetNonBlocking(unsigned long ulBase,
                                    unsigned long *pulData);
extern void I2SRxConfigSet(unsigned long ulBase, unsigned long ulConfig);
extern void I2SRxFIFOLimitSet(unsigned long ulBase, unsigned long ulLevel);
extern unsigned long I2SRxFIFOLimitGet(unsigned long ulBase);
extern unsigned long I2SRxFIFOLevelGet(unsigned long ulBase);
extern void I2STxRxEnable(unsigned long ulBase);
extern void I2STxRxDisable(unsigned long ulBase);
extern void I2STxRxConfigSet(unsigned long ulBase, unsigned long ulConfig);
extern void I2SMasterClockSelect(unsigned long ulBase, unsigned long ulMClock);
extern void I2SIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void I2SIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long I2SIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void I2SIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void I2SIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void I2SIntUnregister(unsigned long ulBase);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __I2S_H__
