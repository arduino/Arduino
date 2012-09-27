//*****************************************************************************
//
// epi.h - Prototypes and macros for the EPI module.
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

#ifndef __EPI_H__
#define __EPI_H__

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
// Values that can be passed to EPIModeSet()
//
//*****************************************************************************
#define EPI_MODE_GENERAL                0x00000010
#define EPI_MODE_SDRAM                  0x00000011
#define EPI_MODE_HB8                    0x00000012
#define EPI_MODE_HB16                   0x00000013
#define EPI_MODE_DISABLE                0x00000000

//*****************************************************************************
//
// Values that can be passed to EPIConfigSDRAMSet()
//
//*****************************************************************************
#define EPI_SDRAM_CORE_FREQ_0_15        0x00000000
#define EPI_SDRAM_CORE_FREQ_15_30       0x40000000
#define EPI_SDRAM_CORE_FREQ_30_50       0x80000000
#define EPI_SDRAM_CORE_FREQ_50_100      0xC0000000
#define EPI_SDRAM_LOW_POWER             0x00000200
#define EPI_SDRAM_FULL_POWER            0x00000000
#define EPI_SDRAM_SIZE_64MBIT           0x00000000
#define EPI_SDRAM_SIZE_128MBIT          0x00000001
#define EPI_SDRAM_SIZE_256MBIT          0x00000002
#define EPI_SDRAM_SIZE_512MBIT          0x00000003

//*****************************************************************************
//
// Values that can be passed to EPIConfigGPModeSet()
//
//*****************************************************************************
#define EPI_GPMODE_CLKPIN               0x80000000
#define EPI_GPMODE_CLKGATE              0x40000000
#define EPI_GPMODE_RDYEN                0x10000000
#define EPI_GPMODE_FRAMEPIN             0x08000000
#define EPI_GPMODE_FRAME50              0x04000000
#define EPI_GPMODE_READWRITE            0x00200000
#define EPI_GPMODE_WRITE2CYCLE          0x00080000
#define EPI_GPMODE_READ2CYCLE           0x00040000
#define EPI_GPMODE_ASIZE_NONE           0x00000000
#define EPI_GPMODE_ASIZE_4              0x00000010
#define EPI_GPMODE_ASIZE_12             0x00000020
#define EPI_GPMODE_ASIZE_20             0x00000030
#define EPI_GPMODE_DSIZE_8              0x00000000
#define EPI_GPMODE_DSIZE_16             0x00000001
#define EPI_GPMODE_DSIZE_24             0x00000002
#define EPI_GPMODE_DSIZE_32             0x00000003
#define EPI_GPMODE_WORD_ACCESS          0x00000100

//*****************************************************************************
//
// Values that can be passed to EPIConfigHB8ModeSet()
//
//*****************************************************************************
#define EPI_HB8_USE_TXEMPTY             0x00800000
#define EPI_HB8_USE_RXFULL              0x00400000
#define EPI_HB8_WRHIGH                  0x00200000
#define EPI_HB8_RDHIGH                  0x00100000
#define EPI_HB8_WRWAIT_0                0x00000000
#define EPI_HB8_WRWAIT_1                0x00000040
#define EPI_HB8_WRWAIT_2                0x00000080
#define EPI_HB8_WRWAIT_3                0x000000C0
#define EPI_HB8_RDWAIT_0                0x00000000
#define EPI_HB8_RDWAIT_1                0x00000010
#define EPI_HB8_RDWAIT_2                0x00000020
#define EPI_HB8_RDWAIT_3                0x00000030
#define EPI_HB8_MODE_ADMUX              0x00000000
#define EPI_HB8_MODE_ADDEMUX            0x00000001
#define EPI_HB8_MODE_SRAM               0x00000002
#define EPI_HB8_MODE_FIFO               0x00000003
#define EPI_HB8_WORD_ACCESS             0x00000100
#define EPI_HB8_CSCFG_ALE               0x00000000
#define EPI_HB8_CSCFG_CS                0x00000200
#define EPI_HB8_CSCFG_DUAL_CS           0x00000400
#define EPI_HB8_CSCFG_ALE_DUAL_CS       0x00000600
#define EPI_HB8_CSBAUD_DUAL             0x00000800

#define EPI_HB8_CSCFG_MASK              0x00000600

//*****************************************************************************
//
// Values that can be passed to EPIConfigHB16ModeSet()
//
//*****************************************************************************
#define EPI_HB16_USE_TXEMPTY            0x00800000
#define EPI_HB16_USE_RXFULL             0x00400000
#define EPI_HB16_WRHIGH                 0x00200000
#define EPI_HB16_RDHIGH                 0x00100000
#define EPI_HB16_WRWAIT_0               0x00000000
#define EPI_HB16_WRWAIT_1               0x00000040
#define EPI_HB16_WRWAIT_2               0x00000080
#define EPI_HB16_WRWAIT_3               0x000000C0
#define EPI_HB16_RDWAIT_0               0x00000000
#define EPI_HB16_RDWAIT_1               0x00000010
#define EPI_HB16_RDWAIT_2               0x00000020
#define EPI_HB16_RDWAIT_3               0x00000030
#define EPI_HB16_MODE_ADMUX             0x00000000
#define EPI_HB16_MODE_ADDEMUX           0x00000001
#define EPI_HB16_MODE_SRAM              0x00000002
#define EPI_HB16_MODE_FIFO              0x00000003
#define EPI_HB16_BSEL                   0x00000004
#define EPI_HB16_WORD_ACCESS            0x00000100
#define EPI_HB16_CSCFG_ALE              0x00000000
#define EPI_HB16_CSCFG_CS               0x00000200
#define EPI_HB16_CSCFG_DUAL_CS          0x00000400
#define EPI_HB16_CSCFG_ALE_DUAL_CS      0x00000600
#define EPI_HB16_CSBAUD_DUAL            0x00000800

#define EPI_HB16_CSCFG_MASK             0x00000600

//*****************************************************************************
//
// Values that can be passed to EPIConfigSDRAMSet()
//
//*****************************************************************************
#define EPI_ADDR_PER_SIZE_256B          0x00000000
#define EPI_ADDR_PER_SIZE_64KB          0x00000040
#define EPI_ADDR_PER_SIZE_16MB          0x00000080
#define EPI_ADDR_PER_SIZE_256MB         0x000000C0
#define EPI_ADDR_PER_BASE_NONE          0x00000000
#define EPI_ADDR_PER_BASE_A             0x00000010
#define EPI_ADDR_PER_BASE_C             0x00000020
#define EPI_ADDR_RAM_SIZE_256B          0x00000000
#define EPI_ADDR_RAM_SIZE_64KB          0x00000004
#define EPI_ADDR_RAM_SIZE_16MB          0x00000008
#define EPI_ADDR_RAM_SIZE_256MB         0x0000000C
#define EPI_ADDR_RAM_BASE_NONE          0x00000000
#define EPI_ADDR_RAM_BASE_6             0x00000001
#define EPI_ADDR_RAM_BASE_8             0x00000002

//*****************************************************************************
//
// Values that can be passed to EPINonBlockingReadConfigure()
//
//*****************************************************************************
#define EPI_NBCONFIG_SIZE_8             1
#define EPI_NBCONFIG_SIZE_16            2
#define EPI_NBCONFIG_SIZE_32            3

//*****************************************************************************
//
// Values that can be passed to EPIFIFOConfig()
//
//*****************************************************************************
#define EPI_FIFO_CONFIG_WTFULLERR       0x00020000
#define EPI_FIFO_CONFIG_RSTALLERR       0x00010000
#define EPI_FIFO_CONFIG_TX_EMPTY        0x00000000
#define EPI_FIFO_CONFIG_TX_1_4          0x00000020
#define EPI_FIFO_CONFIG_TX_1_2          0x00000030
#define EPI_FIFO_CONFIG_TX_3_4          0x00000040
#define EPI_FIFO_CONFIG_RX_1_8          0x00000001
#define EPI_FIFO_CONFIG_RX_1_4          0x00000002
#define EPI_FIFO_CONFIG_RX_1_2          0x00000003
#define EPI_FIFO_CONFIG_RX_3_4          0x00000004
#define EPI_FIFO_CONFIG_RX_7_8          0x00000005
#define EPI_FIFO_CONFIG_RX_FULL         0x00000006

//*****************************************************************************
//
// Values that can be passed to EPIIntEnable(), EPIIntDisable(), or returned
// as flags from EPIIntStatus()
//
//*****************************************************************************
#define EPI_INT_TXREQ                   0x00000004
#define EPI_INT_RXREQ                   0x00000002
#define EPI_INT_ERR                     0x00000001

//*****************************************************************************
//
// Values that can be passed to EPIIntErrorClear(), or returned as flags from
// EPIIntErrorStatus()
//
//*****************************************************************************
#define EPI_INT_ERR_WTFULL              0x00000004
#define EPI_INT_ERR_RSTALL              0x00000002
#define EPI_INT_ERR_TIMEOUT             0x00000001

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void EPIModeSet(unsigned long ulBase, unsigned long ulMode);
extern void EPIDividerSet(unsigned long ulBase, unsigned long ulDivider);
extern void EPIConfigSDRAMSet(unsigned long ulBase, unsigned long ulConfig,
                              unsigned long ulRefresh);
extern void EPIConfigGPModeSet(unsigned long ulBase, unsigned long ulConfig,
                               unsigned long ulFrameCount,
                               unsigned long ulMaxWait);
extern void EPIConfigHB8Set(unsigned long ulBase, unsigned long ulConfig,
                            unsigned long ulMaxWait);
extern void EPIConfigHB16Set(unsigned long ulBase, unsigned long ulConfig,
                             unsigned long ulMaxWait);
extern void EPIAddressMapSet(unsigned long ulBase, unsigned long ulMap);
extern void EPINonBlockingReadConfigure(unsigned long ulBase,
                                        unsigned long ulChannel,
                                        unsigned long ulDataSize,
                                        unsigned long ulAddress);
extern void EPINonBlockingReadStart(unsigned long ulBase,
                                    unsigned long ulChannel,
                                    unsigned long ulCount);
extern void EPINonBlockingReadStop(unsigned long ulBase,
                                   unsigned long ulChannel);
extern unsigned long EPINonBlockingReadCount(unsigned long ulBase,
                                             unsigned long ulChannel);
extern unsigned long EPINonBlockingReadAvail(unsigned long ulBase);
extern unsigned long EPINonBlockingReadGet32(unsigned long ulBase,
                                             unsigned long ulCount,
                                             unsigned long *pulBuf);
extern unsigned long EPINonBlockingReadGet16(unsigned long ulBase,
                                             unsigned long ulCount,
                                             unsigned short *pusBuf);
extern unsigned long EPINonBlockingReadGet8(unsigned long ulBase,
                                            unsigned long ulCount,
                                            unsigned char *pucBuf);
extern void EPIFIFOConfig(unsigned long ulBase, unsigned long ulConfig);
extern unsigned long EPIWriteFIFOCountGet(unsigned long ulBase);
extern void EPIIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void EPIIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long EPIIntStatus(unsigned long ulBase, tBoolean bMasked);
extern unsigned long EPIIntErrorStatus(unsigned long ulBase);
extern void EPIIntErrorClear(unsigned long ulBase, unsigned long ulErrFlags);
extern void EPIIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void EPIIntUnregister(unsigned long ulBase);

//*****************************************************************************
//
// Several EPI APIs and labels have been renamed, with the original definition
// name being deprecated.  These defines provide backward compatibility.
//
//*****************************************************************************
#ifndef DEPRECATED
#define EPI_MODE_NONE           EPI_MODE_GENERAL
#define EPI_NONMODE_CLKPIN      EPI_GPMODE_CLKPIN
#define EPI_NONMODE_CLKSTOP     EPI_GPMODE_CLKGATE
#define EPI_NONMODE_CLKENA      EPI_GPMODE_RDYEN
#define EPI_NONMODE_FRAMEPIN    EPI_GPMODE_FRAMEPIN
#define EPI_NONMODE_FRAME50     EPI_GPMODE_FRAME50
#define EPI_NONMODE_READWRITE   EPI_GPMODE_READWRITE
#define EPI_NONMODE_WRITE2CYCLE EPI_GPMODE_WRITE2CYCLE
#define EPI_NONMODE_READ2CYCLE  EPI_GPMODE_READ2CYCLE
#define EPI_NONMODE_ASIZE_NONE  EPI_GPMODE_ASIZE_NONE
#define EPI_NONMODE_ASIZE_4     EPI_GPMODE_ASIZE_4
#define EPI_NONMODE_ASIZE_12    EPI_GPMODE_ASIZE_12
#define EPI_NONMODE_ASIZE_20    EPI_GPMODE_ASIZE_20
#define EPI_NONMODE_DSIZE_8     EPI_GPMODE_DSIZE_8
#define EPI_NONMODE_DSIZE_16    EPI_GPMODE_DSIZE_16
#define EPI_NONMODE_DSIZE_24    EPI_GPMODE_DSIZE_24
#define EPI_NONMODE_DSIZE_32    EPI_GPMODE_DSIZE_32
#define EPI_NONMODE_WORD_ACCESS EPI_GPMODE_WORD_ACCESS

#define EPINonBlockingWriteCount(a) EPIWriteFIFOCountGet(a)
#define EPIConfigNoModeSet(a, b, c, d) EPIConfigGPModeSet((a), (b), (c), (d))
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __EPI_H__
