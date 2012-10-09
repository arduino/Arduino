//*****************************************************************************
//
// hw_epi.h - Macros for use in accessing the EPI registers.
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

#ifndef __HW_EPI_H__
#define __HW_EPI_H__

//*****************************************************************************
//
// The following are defines for the External Peripheral Interface register
// offsets.
//
//*****************************************************************************
#define EPI_O_CFG               0x00000000  // EPI Configuration
#define EPI_O_BAUD              0x00000004  // EPI Main Baud Rate
#define EPI_O_HB16CFG           0x00000010  // EPI Host-Bus 16 Configuration
#define EPI_O_GPCFG             0x00000010  // EPI General-Purpose
                                            // Configuration
#define EPI_O_SDRAMCFG          0x00000010  // EPI SDRAM Configuration
#define EPI_O_HB8CFG            0x00000010  // EPI Host-Bus 8 Configuration
#define EPI_O_HB8CFG2           0x00000014  // EPI Host-Bus 8 Configuration 2
#define EPI_O_HB16CFG2          0x00000014  // EPI Host-Bus 16 Configuration 2
#define EPI_O_GPCFG2            0x00000014  // EPI General-Purpose
                                            // Configuration 2
#define EPI_O_ADDRMAP           0x0000001C  // EPI Address Map
#define EPI_O_RSIZE0            0x00000020  // EPI Read Size 0
#define EPI_O_RADDR0            0x00000024  // EPI Read Address 0
#define EPI_O_RPSTD0            0x00000028  // EPI Non-Blocking Read Data 0
#define EPI_O_RSIZE1            0x00000030  // EPI Read Size 1
#define EPI_O_RADDR1            0x00000034  // EPI Read Address 1
#define EPI_O_RPSTD1            0x00000038  // EPI Non-Blocking Read Data 1
#define EPI_O_STAT              0x00000060  // EPI Status
#define EPI_O_RFIFOCNT          0x0000006C  // EPI Read FIFO Count
#define EPI_O_READFIFO0         0x00000070  // EPI Read FIFO
#define EPI_O_READFIFO          0x00000070  // EPI Read FIFO
#define EPI_O_READFIFO1         0x00000074  // EPI Read FIFO Alias 1
#define EPI_O_READFIFO2         0x00000078  // EPI Read FIFO Alias 2
#define EPI_O_READFIFO3         0x0000007C  // EPI Read FIFO Alias 3
#define EPI_O_READFIFO4         0x00000080  // EPI Read FIFO Alias 4
#define EPI_O_READFIFO5         0x00000084  // EPI Read FIFO Alias 5
#define EPI_O_READFIFO6         0x00000088  // EPI Read FIFO Alias 6
#define EPI_O_READFIFO7         0x0000008C  // EPI Read FIFO Alias 7
#define EPI_O_FIFOLVL           0x00000200  // EPI FIFO Level Selects
#define EPI_O_WFIFOCNT          0x00000204  // EPI Write FIFO Count
#define EPI_O_IM                0x00000210  // EPI Interrupt Mask
#define EPI_O_RIS               0x00000214  // EPI Raw Interrupt Status
#define EPI_O_MIS               0x00000218  // EPI Masked Interrupt Status
#define EPI_O_EISC              0x0000021C  // EPI Error and Interrupt Status
                                            // and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_CFG register.
//
//*****************************************************************************
#define EPI_CFG_BLKEN           0x00000010  // Block Enable
#define EPI_CFG_MODE_M          0x0000000F  // Mode Select
#define EPI_CFG_MODE_NONE       0x00000000  // General Purpose
#define EPI_CFG_MODE_SDRAM      0x00000001  // SDRAM
#define EPI_CFG_MODE_HB8        0x00000002  // 8-Bit Host-Bus (HB8)
#define EPI_CFG_MODE_HB16       0x00000003  // 16-Bit Host-Bus (HB16)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_BAUD register.
//
//*****************************************************************************
#define EPI_BAUD_COUNT1_M       0xFFFF0000  // Baud Rate Counter 1
#define EPI_BAUD_COUNT0_M       0x0000FFFF  // Baud Rate Counter 0
#define EPI_BAUD_COUNT1_S       16
#define EPI_BAUD_COUNT0_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG register.
//
//*****************************************************************************
#define EPI_HB16CFG_XFFEN       0x00800000  // External FIFO FULL Enable
#define EPI_HB16CFG_XFEEN       0x00400000  // External FIFO EMPTY Enable
#define EPI_HB16CFG_WRHIGH      0x00200000  // WRITE Strobe Polarity
#define EPI_HB16CFG_RDHIGH      0x00100000  // READ Strobe Polarity
#define EPI_HB16CFG_MAXWAIT_M   0x0000FF00  // Maximum Wait
#define EPI_HB16CFG_WRWS_M      0x000000C0  // Write Wait States
#define EPI_HB16CFG_WRWS_0      0x00000000  // No wait states
#define EPI_HB16CFG_WRWS_1      0x00000040  // 1 wait state
#define EPI_HB16CFG_WRWS_2      0x00000080  // 2 wait states
#define EPI_HB16CFG_WRWS_3      0x000000C0  // 3 wait states
#define EPI_HB16CFG_RDWS_M      0x00000030  // Read Wait States
#define EPI_HB16CFG_RDWS_0      0x00000000  // No wait states
#define EPI_HB16CFG_RDWS_1      0x00000010  // 1 wait state
#define EPI_HB16CFG_RDWS_2      0x00000020  // 2 wait states
#define EPI_HB16CFG_RDWS_3      0x00000030  // 3 wait states
#define EPI_HB16CFG_BSEL        0x00000004  // Byte Select Configuration
#define EPI_HB16CFG_MODE_M      0x00000003  // Host Bus Sub-Mode
#define EPI_HB16CFG_MODE_ADMUX  0x00000000  // ADMUX - AD[15:0]
#define EPI_HB16CFG_MODE_ADNMUX 0x00000001  // ADNONMUX - D[15:0]
#define EPI_HB16CFG_MODE_SRAM   0x00000002  // Continuous Read - D[15:0]
#define EPI_HB16CFG_MODE_XFIFO  0x00000003  // XFIFO - D[15:0]
#define EPI_HB16CFG_MAXWAIT_S   8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG register.
//
//*****************************************************************************
#define EPI_GPCFG_CLKPIN        0x80000000  // Clock Pin
#define EPI_GPCFG_CLKGATE       0x40000000  // Clock Gated
#define EPI_GPCFG_RDYEN         0x10000000  // Ready Enable
#define EPI_GPCFG_FRMPIN        0x08000000  // Framing Pin
#define EPI_GPCFG_FRM50         0x04000000  // 50/50 Frame
#define EPI_GPCFG_FRMCNT_M      0x03C00000  // Frame Count
#define EPI_GPCFG_RW            0x00200000  // Read and Write
#define EPI_GPCFG_WR2CYC        0x00080000  // 2-Cycle Writes
#define EPI_GPCFG_RD2CYC        0x00040000  // 2-Cycle Reads
#define EPI_GPCFG_MAXWAIT_M     0x0000FF00  // Maximum Wait
#define EPI_GPCFG_ASIZE_M       0x00000030  // Address Bus Size
#define EPI_GPCFG_ASIZE_NONE    0x00000000  // No address
#define EPI_GPCFG_ASIZE_4BIT    0x00000010  // Up to 4 bits wide
#define EPI_GPCFG_ASIZE_12BIT   0x00000020  // Up to 12 bits wide. This size
                                            // cannot be used with 24-bit data
#define EPI_GPCFG_ASIZE_20BIT   0x00000030  // Up to 20 bits wide. This size
                                            // cannot be used with data sizes
                                            // other than 8
#define EPI_GPCFG_DSIZE_M       0x00000003  // Size of Data Bus
#define EPI_GPCFG_DSIZE_4BIT    0x00000000  // 8 Bits Wide (EPI0S0 to EPI0S7)
#define EPI_GPCFG_DSIZE_16BIT   0x00000001  // 16 Bits Wide (EPI0S0 to EPI0S15)
#define EPI_GPCFG_DSIZE_24BIT   0x00000002  // 24 Bits Wide (EPI0S0 to EPI0S23)
#define EPI_GPCFG_DSIZE_32BIT   0x00000003  // 32 Bits Wide (EPI0S0 to EPI0S31)
#define EPI_GPCFG_FRMCNT_S      22
#define EPI_GPCFG_MAXWAIT_S     8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_SDRAMCFG register.
//
//*****************************************************************************
#define EPI_SDRAMCFG_FREQ_M     0xC0000000  // EPI Frequency Range
#define EPI_SDRAMCFG_FREQ_NONE  0x00000000  // 0 - 15 MHz
#define EPI_SDRAMCFG_FREQ_15MHZ 0x40000000  // 15 - 30 MHz
#define EPI_SDRAMCFG_FREQ_30MHZ 0x80000000  // 30 - 50 MHz
#define EPI_SDRAMCFG_RFSH_M     0x07FF0000  // Refresh Counter
#define EPI_SDRAMCFG_SLEEP      0x00000200  // Sleep Mode
#define EPI_SDRAMCFG_SIZE_M     0x00000003  // Size of SDRAM
#define EPI_SDRAMCFG_SIZE_8MB   0x00000000  // 64 megabits (8MB)
#define EPI_SDRAMCFG_SIZE_16MB  0x00000001  // 128 megabits (16MB)
#define EPI_SDRAMCFG_SIZE_32MB  0x00000002  // 256 megabits (32MB)
#define EPI_SDRAMCFG_SIZE_64MB  0x00000003  // 512 megabits (64MB)
#define EPI_SDRAMCFG_RFSH_S     16

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG register.
//
//*****************************************************************************
#define EPI_HB8CFG_XFFEN        0x00800000  // External FIFO FULL Enable
#define EPI_HB8CFG_XFEEN        0x00400000  // External FIFO EMPTY Enable
#define EPI_HB8CFG_WRHIGH       0x00200000  // WRITE Strobe Polarity
#define EPI_HB8CFG_RDHIGH       0x00100000  // READ Strobe Polarity
#define EPI_HB8CFG_MAXWAIT_M    0x0000FF00  // Maximum Wait
#define EPI_HB8CFG_WRWS_M       0x000000C0  // Write Wait States
#define EPI_HB8CFG_WRWS_0       0x00000000  // No wait states
#define EPI_HB8CFG_WRWS_1       0x00000040  // 1 wait state
#define EPI_HB8CFG_WRWS_2       0x00000080  // 2 wait states
#define EPI_HB8CFG_WRWS_3       0x000000C0  // 3 wait states
#define EPI_HB8CFG_RDWS_M       0x00000030  // Read Wait States
#define EPI_HB8CFG_RDWS_0       0x00000000  // No wait states
#define EPI_HB8CFG_RDWS_1       0x00000010  // 1 wait state
#define EPI_HB8CFG_RDWS_2       0x00000020  // 2 wait states
#define EPI_HB8CFG_RDWS_3       0x00000030  // 3 wait states
#define EPI_HB8CFG_MODE_M       0x00000003  // Host Bus Sub-Mode
#define EPI_HB8CFG_MODE_MUX     0x00000000  // ADMUX - AD[7:0]
#define EPI_HB8CFG_MODE_NMUX    0x00000001  // ADNONMUX - D[7:0]
#define EPI_HB8CFG_MODE_SRAM    0x00000002  // Continuous Read - D[7:0]
#define EPI_HB8CFG_MODE_FIFO    0x00000003  // XFIFO - D[7:0]
#define EPI_HB8CFG_MAXWAIT_S    8

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB8CFG2 register.
//
//*****************************************************************************
#define EPI_HB8CFG2_WORD        0x80000000  // Word Access Mode
#define EPI_HB8CFG2_CSBAUD      0x04000000  // Chip Select Baud Rate
#define EPI_HB8CFG2_CSCFG_M     0x03000000  // Chip Select Configuration
#define EPI_HB8CFG2_CSCFG_ALE   0x00000000  // ALE Configuration
#define EPI_HB8CFG2_CSCFG_CS    0x01000000  // CSn Configuration
#define EPI_HB8CFG2_CSCFG_DCS   0x02000000  // Dual CSn Configuration
#define EPI_HB8CFG2_CSCFG_ADCS  0x03000000  // ALE with Dual CSn Configuration
#define EPI_HB8CFG2_WRHIGH      0x00200000  // CS1n WRITE Strobe Polarity
#define EPI_HB8CFG2_RDHIGH      0x00100000  // CS1n READ Strobe Polarity
#define EPI_HB8CFG2_WRWS_M      0x000000C0  // CS1n Write Wait States
#define EPI_HB8CFG2_WRWS_0      0x00000000  // No wait states
#define EPI_HB8CFG2_WRWS_1      0x00000040  // 1 wait state
#define EPI_HB8CFG2_WRWS_2      0x00000080  // 2 wait states
#define EPI_HB8CFG2_WRWS_3      0x000000C0  // 3 wait states
#define EPI_HB8CFG2_RDWS_M      0x00000030  // CS1n Read Wait States
#define EPI_HB8CFG2_RDWS_0      0x00000000  // No wait states
#define EPI_HB8CFG2_RDWS_1      0x00000010  // 1 wait state
#define EPI_HB8CFG2_RDWS_2      0x00000020  // 2 wait states
#define EPI_HB8CFG2_RDWS_3      0x00000030  // 3 wait states

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_HB16CFG2 register.
//
//*****************************************************************************
#define EPI_HB16CFG2_WORD       0x80000000  // Word Access Mode
#define EPI_HB16CFG2_CSBAUD     0x04000000  // Chip Select Baud Rate
#define EPI_HB16CFG2_CSCFG_M    0x03000000  // Chip Select Configuration
#define EPI_HB16CFG2_CSCFG_ALE  0x00000000  // ALE Configuration
#define EPI_HB16CFG2_CSCFG_CS   0x01000000  // CSn Configuration
#define EPI_HB16CFG2_CSCFG_DCS  0x02000000  // Dual CSn Configuration
#define EPI_HB16CFG2_CSCFG_ADCS 0x03000000  // ALE with Dual CSn Configuration
#define EPI_HB16CFG2_WRHIGH     0x00200000  // CS1n WRITE Strobe Polarity
#define EPI_HB16CFG2_RDHIGH     0x00100000  // CS1n READ Strobe Polarity
#define EPI_HB16CFG2_WRWS_M     0x000000C0  // CS1n Write Wait States
#define EPI_HB16CFG2_WRWS_0     0x00000000  // No wait states
#define EPI_HB16CFG2_WRWS_1     0x00000040  // 1 wait state
#define EPI_HB16CFG2_WRWS_2     0x00000080  // 2 wait states
#define EPI_HB16CFG2_WRWS_3     0x000000C0  // 3 wait states
#define EPI_HB16CFG2_RDWS_M     0x00000030  // CS1n Read Wait States
#define EPI_HB16CFG2_RDWS_0     0x00000000  // No wait states
#define EPI_HB16CFG2_RDWS_1     0x00000010  // 1 wait state
#define EPI_HB16CFG2_RDWS_2     0x00000020  // 2 wait states
#define EPI_HB16CFG2_RDWS_3     0x00000030  // 3 wait states

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_GPCFG2 register.
//
//*****************************************************************************
#define EPI_GPCFG2_WORD         0x80000000  // Word Access Mode

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_ADDRMAP register.
//
//*****************************************************************************
#define EPI_ADDRMAP_EPSZ_M      0x000000C0  // External Peripheral Size
#define EPI_ADDRMAP_EPSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_EPSZ_64KB   0x00000040  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_EPSZ_16MB   0x00000080  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_EPSZ_512MB  0x000000C0  // 512 MB; lower address range:
                                            // 0x000.0000 to 0x1FFF.FFFF
#define EPI_ADDRMAP_EPADR_M     0x00000030  // External Peripheral Address
#define EPI_ADDRMAP_EPADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_EPADR_A000  0x00000010  // At 0xA000.0000
#define EPI_ADDRMAP_EPADR_C000  0x00000020  // At 0xC000.0000
#define EPI_ADDRMAP_ERSZ_M      0x0000000C  // External RAM Size
#define EPI_ADDRMAP_ERSZ_256B   0x00000000  // 256 bytes; lower address range:
                                            // 0x00 to 0xFF
#define EPI_ADDRMAP_ERSZ_64KB   0x00000004  // 64 KB; lower address range:
                                            // 0x0000 to 0xFFFF
#define EPI_ADDRMAP_ERSZ_16MB   0x00000008  // 16 MB; lower address range:
                                            // 0x00.0000 to 0xFF.FFFF
#define EPI_ADDRMAP_ERSZ_512MB  0x0000000C  // 512 MB; lower address range:
                                            // 0x000.0000 to 0x1FFF.FFFF
#define EPI_ADDRMAP_ERADR_M     0x00000003  // External RAM Address
#define EPI_ADDRMAP_ERADR_NONE  0x00000000  // Not mapped
#define EPI_ADDRMAP_ERADR_6000  0x00000001  // At 0x6000.0000
#define EPI_ADDRMAP_ERADR_8000  0x00000002  // At 0x8000.0000

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE0 register.
//
//*****************************************************************************
#define EPI_RSIZE0_SIZE_M       0x00000003  // Current Size
#define EPI_RSIZE0_SIZE_8BIT    0x00000001  // Byte (8 bits)
#define EPI_RSIZE0_SIZE_16BIT   0x00000002  // Half-word (16 bits)
#define EPI_RSIZE0_SIZE_32BIT   0x00000003  // Word (32 bits)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR0 register.
//
//*****************************************************************************
#define EPI_RADDR0_ADDR_M       0x1FFFFFFF  // Current Address
#define EPI_RADDR0_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD0 register.
//
//*****************************************************************************
#define EPI_RPSTD0_POSTCNT_M    0x00001FFF  // Post Count
#define EPI_RPSTD0_POSTCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RSIZE1 register.
//
//*****************************************************************************
#define EPI_RSIZE1_SIZE_M       0x00000003  // Current Size
#define EPI_RSIZE1_SIZE_8BIT    0x00000001  // Byte (8 bits)
#define EPI_RSIZE1_SIZE_16BIT   0x00000002  // Half-word (16 bits)
#define EPI_RSIZE1_SIZE_32BIT   0x00000003  // Word (32 bits)

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RADDR1 register.
//
//*****************************************************************************
#define EPI_RADDR1_ADDR_M       0x1FFFFFFF  // Current Address
#define EPI_RADDR1_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RPSTD1 register.
//
//*****************************************************************************
#define EPI_RPSTD1_POSTCNT_M    0x00001FFF  // Post Count
#define EPI_RPSTD1_POSTCNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_STAT register.
//
//*****************************************************************************
#define EPI_STAT_CELOW          0x00000200  // Clock Enable Low
#define EPI_STAT_XFFULL         0x00000100  // External FIFO Full
#define EPI_STAT_XFEMPTY        0x00000080  // External FIFO Empty
#define EPI_STAT_INITSEQ        0x00000040  // Initialization Sequence
#define EPI_STAT_WBUSY          0x00000020  // Write Busy
#define EPI_STAT_NBRBUSY        0x00000010  // Non-Blocking Read Busy
#define EPI_STAT_ACTIVE         0x00000001  // Register Active

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RFIFOCNT register.
//
//*****************************************************************************
#define EPI_RFIFOCNT_COUNT_M    0x0000000F  // FIFO Count
#define EPI_RFIFOCNT_COUNT_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO0
// register.
//
//*****************************************************************************
#define EPI_READFIFO0_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO0_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO register.
//
//*****************************************************************************
#define EPI_READFIFO_DATA_M     0xFFFFFFFF  // Reads Data
#define EPI_READFIFO_DATA_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO1
// register.
//
//*****************************************************************************
#define EPI_READFIFO1_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO1_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO2
// register.
//
//*****************************************************************************
#define EPI_READFIFO2_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO2_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO3
// register.
//
//*****************************************************************************
#define EPI_READFIFO3_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO3_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO4
// register.
//
//*****************************************************************************
#define EPI_READFIFO4_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO4_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO5
// register.
//
//*****************************************************************************
#define EPI_READFIFO5_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO5_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO6
// register.
//
//*****************************************************************************
#define EPI_READFIFO6_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO6_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_READFIFO7
// register.
//
//*****************************************************************************
#define EPI_READFIFO7_DATA_M    0xFFFFFFFF  // Reads Data
#define EPI_READFIFO7_DATA_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_FIFOLVL register.
//
//*****************************************************************************
#define EPI_FIFOLVL_WFERR       0x00020000  // Write Full Error
#define EPI_FIFOLVL_RSERR       0x00010000  // Read Stall Error
#define EPI_FIFOLVL_WRFIFO_M    0x00000070  // Write FIFO
#define EPI_FIFOLVL_WRFIFO_EMPT 0x00000000  // Trigger when there are any
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_1_4  0x00000020  // Trigger when there are up to 3
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_1_2  0x00000030  // Trigger when there are up to 2
                                            // spaces available in the WFIFO
#define EPI_FIFOLVL_WRFIFO_3_4  0x00000040  // Trigger when there is 1 space
                                            // available in the WFIFO
#define EPI_FIFOLVL_RDFIFO_M    0x00000007  // Read FIFO
#define EPI_FIFOLVL_RDFIFO_EMPT 0x00000000  // Empty
#define EPI_FIFOLVL_RDFIFO_1_8  0x00000001  // Trigger when there are 1 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_1_4  0x00000002  // Trigger when there are 2 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_1_2  0x00000003  // Trigger when there are 4 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_3_4  0x00000004  // Trigger when there are 6 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_7_8  0x00000005  // Trigger when there are 7 or more
                                            // entries in the NBRFIFO
#define EPI_FIFOLVL_RDFIFO_FULL 0x00000006  // Trigger when there are 8 entries
                                            // in the NBRFIFO

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_WFIFOCNT register.
//
//*****************************************************************************
#define EPI_WFIFOCNT_WTAV_M     0x00000007  // Available Write Transactions
#define EPI_WFIFOCNT_WTAV_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_IM register.
//
//*****************************************************************************
#define EPI_IM_WRIM             0x00000004  // Write FIFO Empty Interrupt Mask
#define EPI_IM_RDIM             0x00000002  // Read FIFO Full Interrupt Mask
#define EPI_IM_ERRIM            0x00000001  // Error Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_RIS register.
//
//*****************************************************************************
#define EPI_RIS_WRRIS           0x00000004  // Write Raw Interrupt Status
#define EPI_RIS_RDRIS           0x00000002  // Read Raw Interrupt Status
#define EPI_RIS_ERRRIS          0x00000001  // Error Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_MIS register.
//
//*****************************************************************************
#define EPI_MIS_WRMIS           0x00000004  // Write Masked Interrupt Status
#define EPI_MIS_RDMIS           0x00000002  // Read Masked Interrupt Status
#define EPI_MIS_ERRMIS          0x00000001  // Error Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the EPI_O_EISC register.
//
//*****************************************************************************
#define EPI_EISC_WTFULL         0x00000004  // Write FIFO Full Error
#define EPI_EISC_RSTALL         0x00000002  // Read Stalled Error
#define EPI_EISC_TOUT           0x00000001  // Timeout Error

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the EPI_O_BAUD
// register.
//
//*****************************************************************************
#define EPI_BAUD_COUNT_M        0x0000FFFF  // Baud Rate Counter
#define EPI_BAUD_COUNT_S        0

#endif

#endif // __HW_EPI_H__
