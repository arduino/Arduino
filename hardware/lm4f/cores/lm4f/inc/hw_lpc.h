//*****************************************************************************
//
// hw_lpc.h - Macros used when accessing the LPC hardware.
//
// Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __HW_LPC_H__
#define __HW_LPC_H__

//*****************************************************************************
//
// The following are defines for the LPC register addresses.
//
//*****************************************************************************
#define LPC_O_CTL               0x00000000  // LPC Control
#define LPC_O_STS               0x00000004  // LPC Status
#define LPC_O_IRQCTL            0x00000008  // LPC IRQ Control
#define LPC_O_IRQST             0x0000000C  // LPC IRQ Status
#define LPC_O_CH0CTL            0x00000010  // LPC Channel 0 Control
#define LPC_O_CH0ST             0x00000014  // LPC Channel 0 Status
#define LPC_O_CH0ADR            0x00000018  // LPC Channel 0 Address
#define LPC_O_CH1CTL            0x00000020  // LPC Channel 1 Control
#define LPC_O_CH1ST             0x00000024  // LPC Channel 1 Status
#define LPC_O_CH1ADR            0x00000028  // LPC Channel 1 Address
#define LPC_O_CH2CTL            0x00000030  // LPC Channel 2 Control
#define LPC_O_CH2ST             0x00000034  // LPC Channel 2 Status
#define LPC_O_CH2ADR            0x00000038  // LPC Channel 2 Address
#define LPC_O_CH3CTL            0x00000040  // LPC Channel 3 Control
#define LPC_O_CH3ST             0x00000044  // LPC Channel 3 Status
#define LPC_O_CH3ADR            0x00000048  // LPC Channel 3 Address
#define LPC_O_CH4CTL            0x00000050  // LPC Channel 4 Control
#define LPC_O_CH4ST             0x00000054  // LPC Channel 4 Status
#define LPC_O_CH4ADR            0x00000058  // LPC Channel 4 Address
#define LPC_O_CH5CTL            0x00000060  // LPC Channel 5 Control
#define LPC_O_CH5ST             0x00000064  // LPC Channel 5 Status
#define LPC_O_CH5ADR            0x00000068  // LPC Channel 5 Address
#define LPC_O_CH6CTL            0x00000070  // LPC Channel 6 Control
#define LPC_O_CH6ST             0x00000074  // LPC Channel 6 Status
#define LPC_O_CH6ADR            0x00000078  // LPC Channel 6 Address
#define LPC_O_CH7CTL            0x00000080  // LPC Channel 7 / COMx Control
#define LPC_O_CH7ST             0x00000084  // LPC Channel 7 / COMx Status
#define LPC_O_CH7ADR            0x00000088  // LPC Channel 7 / COMx Address
#define LPC_O_STSADDR           0x000000A0  // LPC Status Block Address
#define LPC_O_IM                0x00000100  // LPC Interrupt Mask
#define LPC_O_RIS               0x00000104  // LPC Raw Interrupt Status
#define LPC_O_MIS               0x00000108  // LPC Masked Interrupt Status
#define LPC_O_IC                0x0000010C  // LPC Interrupt Clear
#define LPC_O_DMACX             0x00000120  // LPC DMA and COMx Control
#define LPC_O_POOL              0x00000400  // LPC Register Pool
#define LPC_O_PP                0x00000FC0  // LPC Peripheral Properties

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CTL register.
//
//*****************************************************************************
#define LPC_CTL_SCICNT_M        0x00000C00  // LPC0SCI Pulse Length
#define LPC_CTL_SCICNT_0        0x00000000  // No pulse occurs on the LPC0SCI
                                            // pin
#define LPC_CTL_SCICNT_2        0x00000400  // The pulse on the LPC0SCI pin is
                                            // 2 LPC0CLK periods
#define LPC_CTL_SCICNT_4        0x00000800  // The pulse on the LPC0SCI pin is
                                            // 4 LPC0CLK periods
#define LPC_CTL_SCICNT_8        0x00000C00  // The pulse on the LPC0SCI pin is
                                            // 8 LPC0CLK periods
#define LPC_CTL_SCI             0x00000200  // Start SCI Pulse
#define LPC_CTL_WAKE            0x00000100  // Wake or Keep Awake the LPC Bus
#define LPC_CTL_CE7             0x00000080  // Enable Channel 7
#define LPC_CTL_CE6             0x00000040  // Enable Channel 6
#define LPC_CTL_CE5             0x00000020  // Enable Channel 5
#define LPC_CTL_CE4             0x00000010  // Enable Channel 4
#define LPC_CTL_CE3             0x00000008  // Enable Channel 3
#define LPC_CTL_CE2             0x00000004  // Enable Channel 2
#define LPC_CTL_CE1             0x00000002  // Enable Channel 1
#define LPC_CTL_CE0             0x00000001  // Enable Channel 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_STS register.
//
//*****************************************************************************
#define LPC_STS_CHCNT_M         0x00700000  // Number of Channels
#define LPC_STS_POOLSZ_M        0x00070000  // Register Pool Size
#define LPC_STS_POOLSZ_256      0x00010000  // 256 bytes
#define LPC_STS_POOLSZ_512      0x00020000  // 512 bytes
#define LPC_STS_POOLSZ_768      0x00030000  // 768 bytes
#define LPC_STS_POOLSZ_1024     0x00040000  // 1024 bytes
#define LPC_STS_RST             0x00000400  // LPC Bus is in Reset
#define LPC_STS_BUSY            0x00000200  // LPC is Busy
#define LPC_STS_SLEEP           0x00000100  // LPC is in Sleep Mode
#define LPC_STS_CA7             0x00000080  // Channel 7 Active
#define LPC_STS_CA6             0x00000040  // Channel 6 Active
#define LPC_STS_CA5             0x00000020  // Channel 5 Active
#define LPC_STS_CA4             0x00000010  // Channel 4 Active
#define LPC_STS_CA3             0x00000008  // Channel 3 Active
#define LPC_STS_CA2             0x00000004  // Channel 2 Active
#define LPC_STS_CA1             0x00000002  // Channel 1 Active
#define LPC_STS_CA0             0x00000001  // Channel 0 Active
#define LPC_STS_CHCNT_S         20

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_IRQCTL register.
//
//*****************************************************************************
#define LPC_IRQCTL_I15          0x80000000  // Manual IRQ15 State
#define LPC_IRQCTL_I14          0x40000000  // Manual IRQ14 State
#define LPC_IRQCTL_I13          0x20000000  // Manual IRQ13 State
#define LPC_IRQCTL_I12          0x10000000  // Manual IRQ12 State
#define LPC_IRQCTL_I11          0x08000000  // Manual IRQ11 State
#define LPC_IRQCTL_I10          0x04000000  // Manual IRQ10 State
#define LPC_IRQCTL_I9           0x02000000  // Manual IRQ9 State
#define LPC_IRQCTL_I8           0x01000000  // Manual IRQ8 State
#define LPC_IRQCTL_I7           0x00800000  // Manual IRQ7 State
#define LPC_IRQCTL_I6           0x00400000  // Manual IRQ6 State
#define LPC_IRQCTL_I5           0x00200000  // Manual IRQ5 State
#define LPC_IRQCTL_I4           0x00100000  // Manual IRQ4 State
#define LPC_IRQCTL_I3           0x00080000  // Manual IRQ3 State
#define LPC_IRQCTL_I2           0x00040000  // Manual IRQ2 State
#define LPC_IRQCTL_I1           0x00020000  // Manual IRQ1 State
#define LPC_IRQCTL_AH           0x00010000  // Active High Control
#define LPC_IRQCTL_PULSE        0x00000004  // Pulse IRQ States
#define LPC_IRQCTL_ONCHG        0x00000002  // Initiate on Change
#define LPC_IRQCTL_SND          0x00000001  // Initiate Immediately

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_IRQST register.
//
//*****************************************************************************
#define LPC_IRQST_I15           0x80000000  // Host IRQ15 State
#define LPC_IRQST_I14           0x40000000  // IRQ14 State
#define LPC_IRQST_I13           0x20000000  // IRQ13 State
#define LPC_IRQST_I12           0x10000000  // IRQ12 State
#define LPC_IRQST_I11           0x08000000  // IRQ11 State
#define LPC_IRQST_I10           0x04000000  // IRQ10 State
#define LPC_IRQST_I9            0x02000000  // IRQ9 State
#define LPC_IRQST_I8            0x01000000  // IRQ8 State
#define LPC_IRQST_I7            0x00800000  // IRQ7 State
#define LPC_IRQST_I6            0x00400000  // IRQ6 State
#define LPC_IRQST_I5            0x00200000  // IRQ5 State
#define LPC_IRQST_I4            0x00100000  // IRQ4 State
#define LPC_IRQST_I3            0x00080000  // IRQ3 State
#define LPC_IRQST_I2            0x00040000  // IRQ2 State
#define LPC_IRQST_I1            0x00020000  // IRQ1 State
#define LPC_IRQST_I0            0x00010000  // IRQ0 State
#define LPC_IRQST_SIRQ          0x00000004  // Pulse IRQ States
#define LPC_IRQST_CONT          0x00000001  // Initiate Immediately

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH0CTL register.
//
//*****************************************************************************
#define LPC_CH0CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH0CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH0CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH0CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH0CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH0CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH0CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH0CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH0CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH0CTL_IRQEN0_TRIG2 0x00020000  // Trigger 2
#define LPC_CH0CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH0CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH0CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH0CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH0CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH0CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH0CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH0CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH0CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH0CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH0CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH0CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH0CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH0CTL_IRQSEL2_S    28
#define LPC_CH0CTL_IRQSEL1_S    24
#define LPC_CH0CTL_IRQSEL0_S    20
#define LPC_CH0CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH0ST register.
//
//*****************************************************************************
#define LPC_CH0ST_USER_M        0x00001F00  // User Data
#define LPC_CH0ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH0ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH0ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH0ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH0ST_CMD           0x00000008  // Command or Data
#define LPC_CH0ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH0ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH0ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH0ADR register.
//
//*****************************************************************************
#define LPC_CH0ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH0ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH0ADR_ADDRL1       0x00000002  // Endpoint Match Bit 1
#define LPC_CH0ADR_ADDRH_S      16
#define LPC_CH0ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH1CTL register.
//
//*****************************************************************************
#define LPC_CH1CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH1CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH1CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH1CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH1CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH1CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH1CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH1CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH1CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH1CTL_IRQEN0_TRGI2 0x00020000  // Trigger 2
#define LPC_CH1CTL_IRQEN0_TRGI3 0x00030000  // Trigger 3
#define LPC_CH1CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH1CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH1CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH1CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH1CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH1CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH1CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH1CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH1CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH1CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH1CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH1CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH1CTL_IRQSEL2_S    28
#define LPC_CH1CTL_IRQSEL1_S    24
#define LPC_CH1CTL_IRQSEL0_S    20
#define LPC_CH1CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH1ST register.
//
//*****************************************************************************
#define LPC_CH1ST_USER_M        0x00001F00  // User Data
#define LPC_CH1ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH1ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH1ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH1ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH1ST_CMD           0x00000008  // Command or Data
#define LPC_CH1ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH1ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH1ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH1ADR register.
//
//*****************************************************************************
#define LPC_CH1ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH1ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH1ADR_ADDRL1       0x00000002  // Endpoint Match Bit 1
#define LPC_CH1ADR_ADDRH_S      16
#define LPC_CH1ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH2CTL register.
//
//*****************************************************************************
#define LPC_CH2CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH2CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH2CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH2CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH2CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH2CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH2CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH2CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH2CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH2CTL_IRQEN0_TRIG2 0x00020000  // Trigger 2
#define LPC_CH2CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH2CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH2CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH2CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH2CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH2CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH2CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH2CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH2CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH2CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH2CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH2CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH2CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH2CTL_IRQSEL2_S    28
#define LPC_CH2CTL_IRQSEL1_S    24
#define LPC_CH2CTL_IRQSEL0_S    20
#define LPC_CH2CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH2ST register.
//
//*****************************************************************************
#define LPC_CH2ST_USER_M        0x00001F00  // User Data
#define LPC_CH2ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH2ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH2ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH2ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH2ST_CMD           0x00000008  // Command or Data
#define LPC_CH2ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH2ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH2ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH2ADR register.
//
//*****************************************************************************
#define LPC_CH2ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH2ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH2ADR_ADDRL1       0x00000002  // Endpoint Match Bit 1
#define LPC_CH2ADR_ADDRH_S      16
#define LPC_CH2ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH3CTL register.
//
//*****************************************************************************
#define LPC_CH3CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH3CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH3CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH3CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH3CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH3CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH3CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH3CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH3CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH3CTL_IRQEN0_TRIG2 0x00020000  // Trigger 2
#define LPC_CH3CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH3CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH3CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH3CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH3CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH3CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH3CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH3CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH3CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH3CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH3CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH3CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH3CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH3CTL_IRQSEL2_S    28
#define LPC_CH3CTL_IRQSEL1_S    24
#define LPC_CH3CTL_IRQSEL0_S    20
#define LPC_CH3CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH3ST register.
//
//*****************************************************************************
#define LPC_CH3ST_USER_M        0x00001F00  // User Data
#define LPC_CH3ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH3ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH3ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH3ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH3ST_CMD           0x00000008  // Command or Data
#define LPC_CH3ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH3ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH3ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH3ADR register.
//
//*****************************************************************************
#define LPC_CH3ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH3ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH3ADR_ADDRL1       0x00000002  // Endpoint Match Bit 1
#define LPC_CH3ADR_ADDRH_S      16
#define LPC_CH3ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH4CTL register.
//
//*****************************************************************************
#define LPC_CH4CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH4CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH4CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH4CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH4CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH4CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH4CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH4CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH4CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH4CTL_IRQEN0_TRIG2 0x00020000  // Trigger 2
#define LPC_CH4CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH4CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH4CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH4CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH4CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH4CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH4CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH4CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH4CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH4CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH4CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH4CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH4CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH4CTL_IRQSEL2_S    28
#define LPC_CH4CTL_IRQSEL1_S    24
#define LPC_CH4CTL_IRQSEL0_S    20
#define LPC_CH4CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH4ST register.
//
//*****************************************************************************
#define LPC_CH4ST_USER_M        0x00001F00  // User Data
#define LPC_CH4ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH4ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH4ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH4ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH4ST_CMD           0x00000008  // Command or Data
#define LPC_CH4ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH4ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH4ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH4ADR register.
//
//*****************************************************************************
#define LPC_CH4ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH4ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH4ADR_ADDRH_S      16
#define LPC_CH4ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH5CTL register.
//
//*****************************************************************************
#define LPC_CH5CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH5CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH5CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH5CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH5CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH5CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH5CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH5CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH5CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH5CTL_IRQEN0_TRIG2 0x00020000  // Trigger 2
#define LPC_CH5CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH5CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH5CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH5CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH5CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH5CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH5CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH5CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH5CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH5CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH5CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH5CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH5CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH5CTL_IRQSEL2_S    28
#define LPC_CH5CTL_IRQSEL1_S    24
#define LPC_CH5CTL_IRQSEL0_S    20
#define LPC_CH5CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH5ST register.
//
//*****************************************************************************
#define LPC_CH5ST_USER_M        0x00001F00  // User Data
#define LPC_CH5ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH5ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH5ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH5ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH5ST_CMD           0x00000008  // Command or Data
#define LPC_CH5ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH5ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH5ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH5ADR register.
//
//*****************************************************************************
#define LPC_CH5ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH5ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH5ADR_ADDRH_S      16
#define LPC_CH5ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH6CTL register.
//
//*****************************************************************************
#define LPC_CH6CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH6CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH6CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH6CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH6CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH6CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH6CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH6CTL_IRQEN0_DIS   0x00000000  // Trigger disabled
#define LPC_CH6CTL_IRQEN0_TRIG1 0x00010000  // Trigger 1
#define LPC_CH6CTL_IRQEN0_TRIG2 0x00020000  // Trigger 2
#define LPC_CH6CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH6CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH6CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH6CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH6CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH6CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH6CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH6CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH6CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH6CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH6CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH6CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH6CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH6CTL_IRQSEL2_S    28
#define LPC_CH6CTL_IRQSEL1_S    24
#define LPC_CH6CTL_IRQSEL0_S    20
#define LPC_CH6CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH6ST register.
//
//*****************************************************************************
#define LPC_CH6ST_USER_M        0x00001F00  // User Data
#define LPC_CH6ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH6ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH6ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH6ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH6ST_CMD           0x00000008  // Command or Data
#define LPC_CH6ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH6ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH6ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH6ADR register.
//
//*****************************************************************************
#define LPC_CH6ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH6ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH6ADR_ADDRH_S      16
#define LPC_CH6ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH7CTL register.
//
//*****************************************************************************
#define LPC_CH7CTL_IRQSEL2_M    0xF0000000  // IRQ Select 2
#define LPC_CH7CTL_IRQSEL1_M    0x0F000000  // IRQ Select 1
#define LPC_CH7CTL_IRQSEL0_M    0x00F00000  // IRQ Select 0
#define LPC_CH7CTL_CX           0x00080000  // IRQ Enable 2
#define LPC_CH7CTL_IRQEN2       0x00080000  // IRQ Enable 2
#define LPC_CH7CTL_IRQEN1       0x00040000  // IRQ Enable 1
#define LPC_CH7CTL_IRQEN0_M     0x00030000  // IRQ Enable 0
#define LPC_CH7CTL_IRQEN0_AUTO  0x00000000  // The automatic IRQ trigger is
                                            // disabled
#define LPC_CH7CTL_IRQEN0_MST   0x00010000  // If TYPE is set, the IRQ selected
                                            // by IRQSEL0 is triggered when the
                                            // master wins arbitration (the
                                            // HW1ST bit is set)
#define LPC_CH7CTL_IRQEN0_SLV   0x00020000  // If TYPE is set, the IRQ selected
                                            // by IRQSEL0 is triggered when the
                                            // slave wins arbitration (the
                                            // SW1ST bit is set)
#define LPC_CH7CTL_IRQEN0_TRIG3 0x00030000  // Trigger 3
#define LPC_CH7CTL_ARBDIS       0x00008000  // Arbitration Disabled
#define LPC_CH7CTL_OFFSET_M     0x00003FE0  // Base Offset in Register Pool
#define LPC_CH7CTL_AMASK_M      0x0000001C  // Address Mask for Ranges
#define LPC_CH7CTL_AMASK_4      0x00000000  // 4 bytes
#define LPC_CH7CTL_AMASK_8      0x00000004  // 8 bytes
#define LPC_CH7CTL_AMASK_16     0x00000008  // 16 bytes
#define LPC_CH7CTL_AMASK_32     0x0000000C  // 32 bytes
#define LPC_CH7CTL_AMASK_64     0x00000010  // 64 bytes
#define LPC_CH7CTL_AMASK_128    0x00000014  // 128 bytes
#define LPC_CH7CTL_AMASK_256    0x00000018  // 256 bytes
#define LPC_CH7CTL_AMASK_512    0x0000001C  // 512 bytes
#define LPC_CH7CTL_TYPE         0x00000001  // Channel Type
#define LPC_CH7CTL_IRQSEL2_S    28
#define LPC_CH7CTL_IRQSEL1_S    24
#define LPC_CH7CTL_IRQSEL0_S    20
#define LPC_CH7CTL_OFFSET_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH7ST register.
//
//*****************************************************************************
#define LPC_CH7ST_USER_M        0x00001F00  // User Data
#define LPC_CH7ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH7ST_HW1ST         0x00000040  // Host Wrote First
#define LPC_CH7ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH7ST_SW1ST         0x00000010  // Slave Wrote First
#define LPC_CH7ST_CMD           0x00000008  // Command or Data
#define LPC_CH7ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH7ST_TOH           0x00000001  // To-Host Transaction
#define LPC_CH7ST_USER_S        8

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_CH7ADR register.
//
//*****************************************************************************
#define LPC_CH7ADR_ADDRH_M      0xFFFF0000  // Upper Address Match
#define LPC_CH7ADR_ADDRL_M      0x0000FFF8  // Lower Address Match
#define LPC_CH7ADR_ADDRH_S      16
#define LPC_CH7ADR_ADDRL_S      3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_STSADDR register.
//
//*****************************************************************************
#define LPC_STSADDR_ADDRH_M     0xFFFF0000  // Upper Address Match
#define LPC_STSADDR_ADDRL_M     0x0000FFF8  // Lower Address Match
#define LPC_STSADDR_ENA         0x00000001  // Enable Status Block
#define LPC_STSADDR_ADDRH_S     16
#define LPC_STSADDR_ADDRL_S     3

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_IM register.
//
//*****************************************************************************
#define LPC_IM_RSTIM            0x80000000  // Reset State Interrupt Mask
#define LPC_IM_SLEEPIM          0x40000000  // Sleep State Interrupt Mask
#define LPC_IM_COMXIM           0x20000000  // COMx Interrupt Mask
#define LPC_IM_SIRQIM           0x10000000  // SERIRQ Frame Complete Interrupt
                                            // Mask
#define LPC_IM_CH6IM3           0x08000000  // Channel 6 Interrupt Mask 3
#define LPC_IM_CH6IM2           0x04000000  // Channel 6 Interrupt Mask 2
#define LPC_IM_CH6IM1           0x02000000  // Channel 6 Interrupt Mask 1
#define LPC_IM_CH6IM0           0x01000000  // Channel 6 Interrupt Mask 0
#define LPC_IM_CH5IM3           0x00800000  // Channel 5 Interrupt Mask 3
#define LPC_IM_CH5IM2           0x00400000  // Channel 5 Interrupt Mask 2
#define LPC_IM_CH5IM1           0x00200000  // Channel 5 Interrupt Mask 1
#define LPC_IM_CH5IM0           0x00100000  // Channel 5 Interrupt Mask 0
#define LPC_IM_CH4IM3           0x00080000  // Channel 4 Interrupt Mask 3
#define LPC_IM_CH4IM2           0x00040000  // Channel 4 Interrupt Mask 2
#define LPC_IM_CH4IM1           0x00020000  // Channel 4 Interrupt Mask 1
#define LPC_IM_CH4IM0           0x00010000  // Channel 4 Interrupt Mask 0
#define LPC_IM_CH3IM3           0x00008000  // Channel 3 Interrupt Mask 3
#define LPC_IM_CH3IM2           0x00004000  // Channel 3 Interrupt Mask 2
#define LPC_IM_CH3IM1           0x00002000  // Channel 3 Interrupt Mask 1
#define LPC_IM_CH3IM0           0x00001000  // Channel 3 Interrupt Mask 0
#define LPC_IM_CH2IM3           0x00000800  // Channel 2 Interrupt Mask 3
#define LPC_IM_CH2IM2           0x00000400  // Channel 2 Interrupt Mask 2
#define LPC_IM_CH2IM1           0x00000200  // Channel 2 Interrupt Mask 1
#define LPC_IM_CH2IM0           0x00000100  // Channel 2 Interrupt Mask 0
#define LPC_IM_CH1IM3           0x00000080  // Channel 1 Interrupt Mask 3
#define LPC_IM_CH1IM2           0x00000040  // Channel 1 Interrupt Mask 2
#define LPC_IM_CH1IM1           0x00000020  // Channel 1 Interrupt Mask 1
#define LPC_IM_CH1IM0           0x00000010  // Channel 1 Interrupt Mask 0
#define LPC_IM_CH0IM3           0x00000008  // Channel 0 Interrupt Mask 3
#define LPC_IM_CH0IM2           0x00000004  // Channel 0 Interrupt Mask 2
#define LPC_IM_CH0IM1           0x00000002  // Channel 0 Interrupt Mask 1
#define LPC_IM_CH0IM0           0x00000001  // Channel 0 Interrupt Mask 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_RIS register.
//
//*****************************************************************************
#define LPC_RIS_RSTRIS          0x80000000  // Reset State Raw Interrupt Status
#define LPC_RIS_SLEEPRIS        0x40000000  // Sleep State Raw Interrupt Status
#define LPC_RIS_COMXRIS         0x20000000  // COMx Raw Interrupt Status
#define LPC_RIS_SIRQRIS         0x10000000  // SERIRQ Frame Complete Raw
                                            // Interrupt Status
#define LPC_RIS_CH6RIS3         0x08000000  // Channel 6 Raw Interrupt Status 3
#define LPC_RIS_CH6RIS2         0x04000000  // Channel 6 Raw Interrupt Status 2
#define LPC_RIS_CH6RIS1         0x02000000  // Channel 6 Raw Interrupt Status 1
#define LPC_RIS_CH6RIS0         0x01000000  // Channel 6 Raw Interrupt Status 0
#define LPC_RIS_CH5RIS3         0x00800000  // Channel 5 Raw Interrupt Status 3
#define LPC_RIS_CH5RIS2         0x00400000  // Channel 5 Raw Interrupt Status 2
#define LPC_RIS_CH5RIS1         0x00200000  // Channel 5 Raw Interrupt Status 1
#define LPC_RIS_CH5RIS0         0x00100000  // Channel 5 Raw Interrupt Status 0
#define LPC_RIS_CH4RIS3         0x00080000  // Channel 4 Raw Interrupt Status 3
#define LPC_RIS_CH4RIS2         0x00040000  // Channel 4 Raw Interrupt Status 2
#define LPC_RIS_CH4RIS1         0x00020000  // Channel 4 Raw Interrupt Status 1
#define LPC_RIS_CH4RIS0         0x00010000  // Channel 4 Raw Interrupt Status 0
#define LPC_RIS_CH3RIS3         0x00008000  // Channel 3 Raw Interrupt Status 3
#define LPC_RIS_CH3RIS2         0x00004000  // Channel 3 Raw Interrupt Status 2
#define LPC_RIS_CH3RIS1         0x00002000  // Channel 3 Raw Interrupt Status 1
#define LPC_RIS_CH3RIS0         0x00001000  // Channel 3 Raw Interrupt Status 0
#define LPC_RIS_CH2RIS3         0x00000800  // Channel 2 Raw Interrupt Status 3
#define LPC_RIS_CH2RIS2         0x00000400  // Channel 2 Raw Interrupt Status 2
#define LPC_RIS_CH2RIS1         0x00000200  // Channel 2 Raw Interrupt Status 1
#define LPC_RIS_CH2RIS0         0x00000100  // Channel 2 Raw Interrupt Status 0
#define LPC_RIS_CH1RIS3         0x00000080  // Channel 1 Raw Interrupt Status 3
#define LPC_RIS_CH1RIS2         0x00000040  // Channel 1 Raw Interrupt Status 2
#define LPC_RIS_CH1RIS1         0x00000020  // Channel 1 Raw Interrupt Status 1
#define LPC_RIS_CH1RIS0         0x00000010  // Channel 1 Raw Interrupt Status 0
#define LPC_RIS_CH0RIS3         0x00000008  // Channel 0 Raw Interrupt Status 3
#define LPC_RIS_CH0RIS2         0x00000004  // Channel 0 Raw Interrupt Status 2
#define LPC_RIS_CH0RIS1         0x00000002  // Channel 0 Raw Interrupt Status 1
#define LPC_RIS_CH0RIS0         0x00000001  // Channel 0 Raw Interrupt Status 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_MIS register.
//
//*****************************************************************************
#define LPC_MIS_RSTMIS          0x80000000  // Reset State Masked Interrupt
                                            // Status
#define LPC_MIS_SLEEPMIS        0x40000000  // Sleep State Masked Interrupt
                                            // Status
#define LPC_MIS_COMXMIS         0x20000000  // COMx Masked Interrupt Status
#define LPC_MIS_SIRQMIS         0x10000000  // SERIRQ Frame Complete Masked
                                            // Interrupt Status
#define LPC_MIS_CH6MIS3         0x08000000  // Channel 6 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH6MIS2         0x04000000  // Channel 6 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH6MIS1         0x02000000  // Channel 6 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH6MIS0         0x01000000  // Channel 6 Masked Interrupt
                                            // Status 0
#define LPC_MIS_CH5MIS3         0x00800000  // Channel 5 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH5MIS2         0x00400000  // Channel 5 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH5MIS1         0x00200000  // Channel 5 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH5MIS0         0x00100000  // Channel 5 Masked Interrupt
                                            // Status 0
#define LPC_MIS_CH4MIS3         0x00080000  // Channel 4 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH4MIS2         0x00040000  // Channel 4 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH4MIS1         0x00020000  // Channel 4 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH4MIS0         0x00010000  // Channel 4 Masked Interrupt
                                            // Status 0
#define LPC_MIS_CH3MIS3         0x00008000  // Channel 3 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH3MIS2         0x00004000  // Channel 3 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH3MIS1         0x00002000  // Channel 3 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH3MIS0         0x00001000  // Channel 3 Masked Interrupt
                                            // Status 0
#define LPC_MIS_CH2MIS3         0x00000800  // Channel 2 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH2MIS2         0x00000400  // Channel 2 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH2MIS1         0x00000200  // Channel 2 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH2MIS0         0x00000100  // Channel 2 Masked Interrupt
                                            // Status 0
#define LPC_MIS_CH1MIS3         0x00000080  // Channel 1 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH1MIS2         0x00000040  // Channel 1 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH1MIS1         0x00000020  // Channel 1 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH1MIS0         0x00000010  // Channel 1 Masked Interrupt
                                            // Status 0
#define LPC_MIS_CH0MIS3         0x00000008  // Channel 0 Masked Interrupt
                                            // Status 3
#define LPC_MIS_CH0MIS2         0x00000004  // Channel 0 Masked Interrupt
                                            // Status 2
#define LPC_MIS_CH0MIS1         0x00000002  // Channel 0 Masked Interrupt
                                            // Status 1
#define LPC_MIS_CH0MIS0         0x00000001  // Channel 0 Masked Interrupt
                                            // Status 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_IC register.
//
//*****************************************************************************
#define LPC_IC_RSTIC            0x80000000  // Reset State Interrupt Clear
#define LPC_IC_SLEEPIC          0x40000000  // Sleep State Interrupt Clear
#define LPC_IC_COMXIC           0x20000000  // COMx Interrupt Clear
#define LPC_IC_SIRQRIC          0x10000000  // SERIRQ Frame Complete Interrupt
                                            // Clear
#define LPC_IC_CH6IC3           0x08000000  // Channel 6 Interrupt Clear 3
#define LPC_IC_CH6IC2           0x04000000  // Channel 6 Interrupt Clear 2
#define LPC_IC_CH6IC1           0x02000000  // Channel 6 Interrupt Clear 1
#define LPC_IC_CH6IC0           0x01000000  // Channel 6 Interrupt Clear 0
#define LPC_IC_CH5IC3           0x00800000  // Channel 5 Interrupt Clear 3
#define LPC_IC_CH5IC2           0x00400000  // Channel 5 Interrupt Clear 2
#define LPC_IC_CH5IC1           0x00200000  // Channel 5 Interrupt Clear 1
#define LPC_IC_CH5IC0           0x00100000  // Channel 5 Interrupt Clear 0
#define LPC_IC_CH4IC3           0x00080000  // Channel 4 Interrupt Clear 3
#define LPC_IC_CH4IC2           0x00040000  // Channel 4 Interrupt Clear 2
#define LPC_IC_CH4IC1           0x00020000  // Channel 4 Interrupt Clear 1
#define LPC_IC_CH4IC0           0x00010000  // Channel 4 Interrupt Clear 0
#define LPC_IC_CH3IC3           0x00008000  // Channel 3 Interrupt Clear 3
#define LPC_IC_CH3IC2           0x00004000  // Channel 3 Interrupt Clear 2
#define LPC_IC_CH3IC1           0x00002000  // Channel 3 Interrupt Clear 1
#define LPC_IC_CH3IC0           0x00001000  // Channel 3 Interrupt Clear 0
#define LPC_IC_CH2IC3           0x00000800  // Channel 2 Interrupt Clear 3
#define LPC_IC_CH2IC2           0x00000400  // Channel 2 Interrupt Clear 2
#define LPC_IC_CH2IC1           0x00000200  // Channel 2 Interrupt Clear 1
#define LPC_IC_CH2IC0           0x00000100  // Channel 2 Interrupt Clear 0
#define LPC_IC_CH1IC3           0x00000080  // Channel 1 Interrupt Clear 3
#define LPC_IC_CH1IC2           0x00000040  // Channel 1 Interrupt Clear 2
#define LPC_IC_CH1IC1           0x00000020  // Channel 1 Interrupt Clear 1
#define LPC_IC_CH1IC0           0x00000010  // Channel 1 Interrupt Clear 0
#define LPC_IC_CH0IC3           0x00000008  // Channel 0 Interrupt Clear 3
#define LPC_IC_CH0IC2           0x00000004  // Channel 0 Interrupt Clear 2
#define LPC_IC_CH0IC1           0x00000002  // Channel 0 Interrupt Clear 1
#define LPC_IC_CH0IC0           0x00000001  // Channel 0 Interrupt Clear 0

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_DMACX register.
//
//*****************************************************************************
#define LPC_DMACX_CXRES         0x02000000  // Raw Event State for COMx
#define LPC_DMACX_CXTXRES       0x01000000  // Raw Event State for COMx TX
#define LPC_DMACX_CXRXRES       0x00800000  // Raw Event State for COMx RX
#define LPC_DMACX_CXEM          0x00200000  // Event Mask for COMx
#define LPC_DMACX_CXTXEM        0x00100000  // Event Mask for COMx TX
#define LPC_DMACX_CXRXEM        0x00080000  // Event Mask for COMx RX
#define LPC_DMACX_CXACT_M       0x00060000  // COMx Action
#define LPC_DMACX_CXACT_FRMHNML 0x00000000  // Treat as normal FRMH model and
                                            // let be full (and so marked as
                                            // full)
#define LPC_DMACX_CXACT_FRMHIGN 0x00020000  // Ignore FRMH bytes and continue
                                            // to mark FRMH as empty
#define LPC_DMACX_CXACT_FRMHDMA 0x00040000  // COMx DMA on FRMH byte (e.g. to
                                            // memory)
#define LPC_DMACX_CXACT_UARTDMA 0x00060000  // COMx DMA model with UART
#define LPC_DMACX_COMX          0x00010000  // COMx Handling
#define LPC_DMACX_C3W           0x00000080  // Channel 3 Write Control
#define LPC_DMACX_C3R           0x00000040  // Channel 3 Read Control
#define LPC_DMACX_C2W           0x00000020  // Channel 2 Write Control
#define LPC_DMACX_C2R           0x00000010  // Channel 2 Read Control
#define LPC_DMACX_C1W           0x00000008  // Channel 1 Write Control
#define LPC_DMACX_C1R           0x00000004  // Channel 1 Read Control
#define LPC_DMACX_C0W           0x00000002  // Channel 0 Write Control
#define LPC_DMACX_C0R           0x00000001  // Channel 0 Read Control

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_POOL register.
//
//*****************************************************************************
#define LPC_POOL_BYTE3_M        0xFF000000  // Byte 3
#define LPC_POOL_BYTE2_M        0x00FF0000  // Byte 2
#define LPC_POOL_BYTE1_M        0x0000FF00  // Byte 1
#define LPC_POOL_BYTE0_M        0x000000FF  // Byte 0
#define LPC_POOL_BYTE3_S        24
#define LPC_POOL_BYTE2_S        16
#define LPC_POOL_BYTE1_S        8
#define LPC_POOL_BYTE0_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the LPC_O_PP register.
//
//*****************************************************************************
#define LPC_PP_COMX             0x00000010  // COMx Support Available
#define LPC_PP_CHANCNT_M        0x0000000F  // Number of Channels (Excluding
                                            // COMx)
#define LPC_PP_CHANCNT_S        0

#endif // __HW_LPC_H__
