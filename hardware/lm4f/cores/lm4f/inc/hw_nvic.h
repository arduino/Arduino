//*****************************************************************************
//
// hw_nvic.h - Macros used when accessing the NVIC hardware.
//
// Copyright (c) 2005-2013 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __HW_NVIC_H__
#define __HW_NVIC_H__

//*****************************************************************************
//
// The following are defines for the NVIC register addresses.
//
//*****************************************************************************
#define NVIC_ACTLR              0xE000E008  // Auxiliary Control
#define NVIC_ST_CTRL            0xE000E010  // SysTick Control and Status
                                            // Register
#define NVIC_ST_RELOAD          0xE000E014  // SysTick Reload Value Register
#define NVIC_ST_CURRENT         0xE000E018  // SysTick Current Value Register
#define NVIC_EN0                0xE000E100  // Interrupt 0-31 Set Enable
#define NVIC_EN1                0xE000E104  // Interrupt 32-54 Set Enable
#define NVIC_EN2                0xE000E108  // Interrupt 64-95 Set Enable
#define NVIC_EN3                0xE000E10C  // Interrupt 96-127 Set Enable
#define NVIC_EN4                0xE000E110  // Interrupt 128-131 Set Enable
#define NVIC_DIS0               0xE000E180  // Interrupt 0-31 Clear Enable
#define NVIC_DIS1               0xE000E184  // Interrupt 32-54 Clear Enable
#define NVIC_DIS2               0xE000E188  // Interrupt 64-95 Clear Enable
#define NVIC_DIS3               0xE000E18C  // Interrupt 96-127 Clear Enable
#define NVIC_DIS4               0xE000E190  // Interrupt 128-131 Clear Enable
#define NVIC_PEND0              0xE000E200  // Interrupt 0-31 Set Pending
#define NVIC_PEND1              0xE000E204  // Interrupt 32-54 Set Pending
#define NVIC_PEND2              0xE000E208  // Interrupt 64-95 Set Pending
#define NVIC_PEND3              0xE000E20C  // Interrupt 96-127 Set Pending
#define NVIC_PEND4              0xE000E210  // Interrupt 128-131 Set Pending
#define NVIC_UNPEND0            0xE000E280  // Interrupt 0-31 Clear Pending
#define NVIC_UNPEND1            0xE000E284  // Interrupt 32-54 Clear Pending
#define NVIC_UNPEND2            0xE000E288  // Interrupt 64-95 Clear Pending
#define NVIC_UNPEND3            0xE000E28C  // Interrupt 96-127 Clear Pending
#define NVIC_UNPEND4            0xE000E290  // Interrupt 128-131 Clear Pending
#define NVIC_ACTIVE0            0xE000E300  // Interrupt 0-31 Active Bit
#define NVIC_ACTIVE1            0xE000E304  // Interrupt 32-54 Active Bit
#define NVIC_ACTIVE2            0xE000E308  // Interrupt 64-95 Active Bit
#define NVIC_ACTIVE3            0xE000E30C  // Interrupt 96-127 Active Bit
#define NVIC_ACTIVE4            0xE000E310  // Interrupt 128-131 Active Bit
#define NVIC_PRI0               0xE000E400  // Interrupt 0-3 Priority
#define NVIC_PRI1               0xE000E404  // Interrupt 4-7 Priority
#define NVIC_PRI2               0xE000E408  // Interrupt 8-11 Priority
#define NVIC_PRI3               0xE000E40C  // Interrupt 12-15 Priority
#define NVIC_PRI4               0xE000E410  // Interrupt 16-19 Priority
#define NVIC_PRI5               0xE000E414  // Interrupt 20-23 Priority
#define NVIC_PRI6               0xE000E418  // Interrupt 24-27 Priority
#define NVIC_PRI7               0xE000E41C  // Interrupt 28-31 Priority
#define NVIC_PRI8               0xE000E420  // Interrupt 32-35 Priority
#define NVIC_PRI9               0xE000E424  // Interrupt 36-39 Priority
#define NVIC_PRI10              0xE000E428  // Interrupt 40-43 Priority
#define NVIC_PRI11              0xE000E42C  // Interrupt 44-47 Priority
#define NVIC_PRI12              0xE000E430  // Interrupt 48-51 Priority
#define NVIC_PRI13              0xE000E434  // Interrupt 52-55 Priority
#define NVIC_PRI14              0xE000E438  // Interrupt 56-59 Priority
#define NVIC_PRI15              0xE000E43C  // Interrupt 60-63 Priority
#define NVIC_PRI16              0xE000E440  // Interrupt 64-67 Priority
#define NVIC_PRI17              0xE000E444  // Interrupt 68-71 Priority
#define NVIC_PRI18              0xE000E448  // Interrupt 72-75 Priority
#define NVIC_PRI19              0xE000E44C  // Interrupt 76-79 Priority
#define NVIC_PRI20              0xE000E450  // Interrupt 80-83 Priority
#define NVIC_PRI21              0xE000E454  // Interrupt 84-87 Priority
#define NVIC_PRI22              0xE000E458  // Interrupt 88-91 Priority
#define NVIC_PRI23              0xE000E45C  // Interrupt 92-95 Priority
#define NVIC_PRI24              0xE000E460  // Interrupt 96-99 Priority
#define NVIC_PRI25              0xE000E464  // Interrupt 100-103 Priority
#define NVIC_PRI26              0xE000E468  // Interrupt 104-107 Priority
#define NVIC_PRI27              0xE000E46C  // Interrupt 108-111 Priority
#define NVIC_PRI28              0xE000E470  // Interrupt 112-115 Priority
#define NVIC_PRI29              0xE000E474  // Interrupt 116-119 Priority
#define NVIC_PRI30              0xE000E478  // Interrupt 120-123 Priority
#define NVIC_PRI31              0xE000E47C  // Interrupt 124-127 Priority
#define NVIC_PRI32              0xE000E480  // Interrupt 128-131 Priority
#define NVIC_PRI33              0xE000E484  // Interrupt 132-135 Priority
#define NVIC_PRI34              0xE000E488  // Interrupt 136-138 Priority
#define NVIC_CPUID              0xE000ED00  // CPU ID Base
#define NVIC_INT_CTRL           0xE000ED04  // Interrupt Control and State
#define NVIC_VTABLE             0xE000ED08  // Vector Table Offset
#define NVIC_APINT              0xE000ED0C  // Application Interrupt and Reset
                                            // Control
#define NVIC_SYS_CTRL           0xE000ED10  // System Control
#define NVIC_CFG_CTRL           0xE000ED14  // Configuration and Control
#define NVIC_SYS_PRI1           0xE000ED18  // System Handler Priority 1
#define NVIC_SYS_PRI2           0xE000ED1C  // System Handler Priority 2
#define NVIC_SYS_PRI3           0xE000ED20  // System Handler Priority 3
#define NVIC_SYS_HND_CTRL       0xE000ED24  // System Handler Control and State
#define NVIC_FAULT_STAT         0xE000ED28  // Configurable Fault Status
#define NVIC_HFAULT_STAT        0xE000ED2C  // Hard Fault Status
#define NVIC_DEBUG_STAT         0xE000ED30  // Debug Status Register
#define NVIC_MM_ADDR            0xE000ED34  // Memory Management Fault Address
#define NVIC_FAULT_ADDR         0xE000ED38  // Bus Fault Address
#define NVIC_CPAC               0xE000ED88  // Coprocessor Access Control
#define NVIC_MPU_TYPE           0xE000ED90  // MPU Type
#define NVIC_MPU_CTRL           0xE000ED94  // MPU Control
#define NVIC_MPU_NUMBER         0xE000ED98  // MPU Region Number
#define NVIC_MPU_BASE           0xE000ED9C  // MPU Region Base Address
#define NVIC_MPU_ATTR           0xE000EDA0  // MPU Region Attribute and Size
#define NVIC_MPU_BASE1          0xE000EDA4  // MPU Region Base Address Alias 1
#define NVIC_MPU_ATTR1          0xE000EDA8  // MPU Region Attribute and Size
                                            // Alias 1
#define NVIC_MPU_BASE2          0xE000EDAC  // MPU Region Base Address Alias 2
#define NVIC_MPU_ATTR2          0xE000EDB0  // MPU Region Attribute and Size
                                            // Alias 2
#define NVIC_MPU_BASE3          0xE000EDB4  // MPU Region Base Address Alias 3
#define NVIC_MPU_ATTR3          0xE000EDB8  // MPU Region Attribute and Size
                                            // Alias 3
#define NVIC_DBG_CTRL           0xE000EDF0  // Debug Control and Status Reg
#define NVIC_DBG_XFER           0xE000EDF4  // Debug Core Reg. Transfer Select
#define NVIC_DBG_DATA           0xE000EDF8  // Debug Core Register Data
#define NVIC_DBG_INT            0xE000EDFC  // Debug Reset Interrupt Control
#define NVIC_SW_TRIG            0xE000EF00  // Software Trigger Interrupt
#define NVIC_FPCC               0xE000EF34  // Floating-Point Context Control
#define NVIC_FPCA               0xE000EF38  // Floating-Point Context Address
#define NVIC_FPDSC              0xE000EF3C  // Floating-Point Default Status
                                            // Control

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTLR register.
//
//*****************************************************************************
#define NVIC_ACTLR_DISOOFP      0x00000200  // Disable Out-Of-Order Floating
                                            // Point
#define NVIC_ACTLR_DISFPCA      0x00000100  // Disable CONTROL
#define NVIC_ACTLR_DISFOLD      0x00000004  // Disable IT Folding
#define NVIC_ACTLR_DISWBUF      0x00000002  // Disable Write Buffer
#define NVIC_ACTLR_DISMCYC      0x00000001  // Disable Interrupts of Multiple
                                            // Cycle Instructions

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CTRL register.
//
//*****************************************************************************
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count Flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt Enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_RELOAD register.
//
//*****************************************************************************
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Reload Value
#define NVIC_ST_RELOAD_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CURRENT
// register.
//
//*****************************************************************************
#define NVIC_ST_CURRENT_M       0x00FFFFFF  // Current Value
#define NVIC_ST_CURRENT_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN0 register.
//
//*****************************************************************************
#define NVIC_EN0_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN1 register.
//
//*****************************************************************************
#define NVIC_EN1_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN2 register.
//
//*****************************************************************************
#define NVIC_EN2_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN3 register.
//
//*****************************************************************************
#define NVIC_EN3_INT_M          0xFFFFFFFF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_EN4 register.
//
//*****************************************************************************
#define NVIC_EN4_INT_M          0x000007FF  // Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS0 register.
//
//*****************************************************************************
#define NVIC_DIS0_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS1 register.
//
//*****************************************************************************
#define NVIC_DIS1_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS2 register.
//
//*****************************************************************************
#define NVIC_DIS2_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS3 register.
//
//*****************************************************************************
#define NVIC_DIS3_INT_M         0xFFFFFFFF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DIS4 register.
//
//*****************************************************************************
#define NVIC_DIS4_INT_M         0x000007FF  // Interrupt Disable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND0 register.
//
//*****************************************************************************
#define NVIC_PEND0_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND1 register.
//
//*****************************************************************************
#define NVIC_PEND1_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND2 register.
//
//*****************************************************************************
#define NVIC_PEND2_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND3 register.
//
//*****************************************************************************
#define NVIC_PEND3_INT_M        0xFFFFFFFF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PEND4 register.
//
//*****************************************************************************
#define NVIC_PEND4_INT_M        0x000007FF  // Interrupt Set Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND0 register.
//
//*****************************************************************************
#define NVIC_UNPEND0_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND1 register.
//
//*****************************************************************************
#define NVIC_UNPEND1_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND2 register.
//
//*****************************************************************************
#define NVIC_UNPEND2_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND3 register.
//
//*****************************************************************************
#define NVIC_UNPEND3_INT_M      0xFFFFFFFF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_UNPEND4 register.
//
//*****************************************************************************
#define NVIC_UNPEND4_INT_M      0x000007FF  // Interrupt Clear Pending

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE0 register.
//
//*****************************************************************************
#define NVIC_ACTIVE0_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE1 register.
//
//*****************************************************************************
#define NVIC_ACTIVE1_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE2 register.
//
//*****************************************************************************
#define NVIC_ACTIVE2_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE3 register.
//
//*****************************************************************************
#define NVIC_ACTIVE3_INT_M      0xFFFFFFFF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ACTIVE4 register.
//
//*****************************************************************************
#define NVIC_ACTIVE4_INT_M      0x000007FF  // Interrupt Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI0 register.
//
//*****************************************************************************
#define NVIC_PRI0_INT3_M        0xE0000000  // Interrupt 3 Priority Mask
#define NVIC_PRI0_INT2_M        0x00E00000  // Interrupt 2 Priority Mask
#define NVIC_PRI0_INT1_M        0x0000E000  // Interrupt 1 Priority Mask
#define NVIC_PRI0_INT0_M        0x000000E0  // Interrupt 0 Priority Mask
#define NVIC_PRI0_INT3_S        29
#define NVIC_PRI0_INT2_S        21
#define NVIC_PRI0_INT1_S        13
#define NVIC_PRI0_INT0_S        5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI1 register.
//
//*****************************************************************************
#define NVIC_PRI1_INT7_M        0xE0000000  // Interrupt 7 Priority Mask
#define NVIC_PRI1_INT6_M        0x00E00000  // Interrupt 6 Priority Mask
#define NVIC_PRI1_INT5_M        0x0000E000  // Interrupt 5 Priority Mask
#define NVIC_PRI1_INT4_M        0x000000E0  // Interrupt 4 Priority Mask
#define NVIC_PRI1_INT7_S        29
#define NVIC_PRI1_INT6_S        21
#define NVIC_PRI1_INT5_S        13
#define NVIC_PRI1_INT4_S        5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI2 register.
//
//*****************************************************************************
#define NVIC_PRI2_INT11_M       0xE0000000  // Interrupt 11 Priority Mask
#define NVIC_PRI2_INT10_M       0x00E00000  // Interrupt 10 Priority Mask
#define NVIC_PRI2_INT9_M        0x0000E000  // Interrupt 9 Priority Mask
#define NVIC_PRI2_INT8_M        0x000000E0  // Interrupt 8 Priority Mask
#define NVIC_PRI2_INT11_S       29
#define NVIC_PRI2_INT10_S       21
#define NVIC_PRI2_INT9_S        13
#define NVIC_PRI2_INT8_S        5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI3 register.
//
//*****************************************************************************
#define NVIC_PRI3_INT15_M       0xE0000000  // Interrupt 15 Priority Mask
#define NVIC_PRI3_INT14_M       0x00E00000  // Interrupt 14 Priority Mask
#define NVIC_PRI3_INT13_M       0x0000E000  // Interrupt 13 Priority Mask
#define NVIC_PRI3_INT12_M       0x000000E0  // Interrupt 12 Priority Mask
#define NVIC_PRI3_INT15_S       29
#define NVIC_PRI3_INT14_S       21
#define NVIC_PRI3_INT13_S       13
#define NVIC_PRI3_INT12_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI4 register.
//
//*****************************************************************************
#define NVIC_PRI4_INT19_M       0xE0000000  // Interrupt 19 Priority Mask
#define NVIC_PRI4_INT18_M       0x00E00000  // Interrupt 18 Priority Mask
#define NVIC_PRI4_INT17_M       0x0000E000  // Interrupt 17 Priority Mask
#define NVIC_PRI4_INT16_M       0x000000E0  // Interrupt 16 Priority Mask
#define NVIC_PRI4_INT19_S       29
#define NVIC_PRI4_INT18_S       21
#define NVIC_PRI4_INT17_S       13
#define NVIC_PRI4_INT16_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI5 register.
//
//*****************************************************************************
#define NVIC_PRI5_INT23_M       0xE0000000  // Interrupt 23 Priority Mask
#define NVIC_PRI5_INT22_M       0x00E00000  // Interrupt 22 Priority Mask
#define NVIC_PRI5_INT21_M       0x0000E000  // Interrupt 21 Priority Mask
#define NVIC_PRI5_INT20_M       0x000000E0  // Interrupt 20 Priority Mask
#define NVIC_PRI5_INT23_S       29
#define NVIC_PRI5_INT22_S       21
#define NVIC_PRI5_INT21_S       13
#define NVIC_PRI5_INT20_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI6 register.
//
//*****************************************************************************
#define NVIC_PRI6_INT27_M       0xE0000000  // Interrupt 27 Priority Mask
#define NVIC_PRI6_INT26_M       0x00E00000  // Interrupt 26 Priority Mask
#define NVIC_PRI6_INT25_M       0x0000E000  // Interrupt 25 Priority Mask
#define NVIC_PRI6_INT24_M       0x000000E0  // Interrupt 24 Priority Mask
#define NVIC_PRI6_INT27_S       29
#define NVIC_PRI6_INT26_S       21
#define NVIC_PRI6_INT25_S       13
#define NVIC_PRI6_INT24_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI7 register.
//
//*****************************************************************************
#define NVIC_PRI7_INT31_M       0xE0000000  // Interrupt 31 Priority Mask
#define NVIC_PRI7_INT30_M       0x00E00000  // Interrupt 30 Priority Mask
#define NVIC_PRI7_INT29_M       0x0000E000  // Interrupt 29 Priority Mask
#define NVIC_PRI7_INT28_M       0x000000E0  // Interrupt 28 Priority Mask
#define NVIC_PRI7_INT31_S       29
#define NVIC_PRI7_INT30_S       21
#define NVIC_PRI7_INT29_S       13
#define NVIC_PRI7_INT28_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI8 register.
//
//*****************************************************************************
#define NVIC_PRI8_INT35_M       0xE0000000  // Interrupt 35 Priority Mask
#define NVIC_PRI8_INT34_M       0x00E00000  // Interrupt 34 Priority Mask
#define NVIC_PRI8_INT33_M       0x0000E000  // Interrupt 33 Priority Mask
#define NVIC_PRI8_INT32_M       0x000000E0  // Interrupt 32 Priority Mask
#define NVIC_PRI8_INT35_S       29
#define NVIC_PRI8_INT34_S       21
#define NVIC_PRI8_INT33_S       13
#define NVIC_PRI8_INT32_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI9 register.
//
//*****************************************************************************
#define NVIC_PRI9_INT39_M       0xE0000000  // Interrupt 39 Priority Mask
#define NVIC_PRI9_INT38_M       0x00E00000  // Interrupt 38 Priority Mask
#define NVIC_PRI9_INT37_M       0x0000E000  // Interrupt 37 Priority Mask
#define NVIC_PRI9_INT36_M       0x000000E0  // Interrupt 36 Priority Mask
#define NVIC_PRI9_INT39_S       29
#define NVIC_PRI9_INT38_S       21
#define NVIC_PRI9_INT37_S       13
#define NVIC_PRI9_INT36_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI10 register.
//
//*****************************************************************************
#define NVIC_PRI10_INT43_M      0xE0000000  // Interrupt 43 Priority Mask
#define NVIC_PRI10_INT42_M      0x00E00000  // Interrupt 42 Priority Mask
#define NVIC_PRI10_INT41_M      0x0000E000  // Interrupt 41 Priority Mask
#define NVIC_PRI10_INT40_M      0x000000E0  // Interrupt 40 Priority Mask
#define NVIC_PRI10_INT43_S      29
#define NVIC_PRI10_INT42_S      21
#define NVIC_PRI10_INT41_S      13
#define NVIC_PRI10_INT40_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI11 register.
//
//*****************************************************************************
#define NVIC_PRI11_INT47_M      0xE0000000  // Interrupt 47 Priority Mask
#define NVIC_PRI11_INT46_M      0x00E00000  // Interrupt 46 Priority Mask
#define NVIC_PRI11_INT45_M      0x0000E000  // Interrupt 45 Priority Mask
#define NVIC_PRI11_INT44_M      0x000000E0  // Interrupt 44 Priority Mask
#define NVIC_PRI11_INT47_S      29
#define NVIC_PRI11_INT46_S      21
#define NVIC_PRI11_INT45_S      13
#define NVIC_PRI11_INT44_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI12 register.
//
//*****************************************************************************
#define NVIC_PRI12_INT51_M      0xE0000000  // Interrupt 51 Priority Mask
#define NVIC_PRI12_INT50_M      0x00E00000  // Interrupt 50 Priority Mask
#define NVIC_PRI12_INT49_M      0x0000E000  // Interrupt 49 Priority Mask
#define NVIC_PRI12_INT48_M      0x000000E0  // Interrupt 48 Priority Mask
#define NVIC_PRI12_INT51_S      29
#define NVIC_PRI12_INT50_S      21
#define NVIC_PRI12_INT49_S      13
#define NVIC_PRI12_INT48_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI13 register.
//
//*****************************************************************************
#define NVIC_PRI13_INT55_M      0xE0000000  // Interrupt 55 Priority Mask
#define NVIC_PRI13_INT54_M      0x00E00000  // Interrupt 54 Priority Mask
#define NVIC_PRI13_INT53_M      0x0000E000  // Interrupt 53 Priority Mask
#define NVIC_PRI13_INT52_M      0x000000E0  // Interrupt 52 Priority Mask
#define NVIC_PRI13_INT55_S      29
#define NVIC_PRI13_INT54_S      21
#define NVIC_PRI13_INT53_S      13
#define NVIC_PRI13_INT52_S      5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI14 register.
//
//*****************************************************************************
#define NVIC_PRI14_INTD_M       0xE0000000  // Interrupt 59 Priority Mask
#define NVIC_PRI14_INTC_M       0x00E00000  // Interrupt 58 Priority Mask
#define NVIC_PRI14_INTB_M       0x0000E000  // Interrupt 57 Priority Mask
#define NVIC_PRI14_INTA_M       0x000000E0  // Interrupt 56 Priority Mask
#define NVIC_PRI14_INTD_S       29
#define NVIC_PRI14_INTC_S       21
#define NVIC_PRI14_INTB_S       13
#define NVIC_PRI14_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI15 register.
//
//*****************************************************************************
#define NVIC_PRI15_INTD_M       0xE0000000  // Interrupt 63 Priority Mask
#define NVIC_PRI15_INTC_M       0x00E00000  // Interrupt 62 Priority Mask
#define NVIC_PRI15_INTB_M       0x0000E000  // Interrupt 61 Priority Mask
#define NVIC_PRI15_INTA_M       0x000000E0  // Interrupt 60 Priority Mask
#define NVIC_PRI15_INTD_S       29
#define NVIC_PRI15_INTC_S       21
#define NVIC_PRI15_INTB_S       13
#define NVIC_PRI15_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI16 register.
//
//*****************************************************************************
#define NVIC_PRI16_INTD_M       0xE0000000  // Interrupt 67 Priority Mask
#define NVIC_PRI16_INTC_M       0x00E00000  // Interrupt 66 Priority Mask
#define NVIC_PRI16_INTB_M       0x0000E000  // Interrupt 65 Priority Mask
#define NVIC_PRI16_INTA_M       0x000000E0  // Interrupt 64 Priority Mask
#define NVIC_PRI16_INTD_S       29
#define NVIC_PRI16_INTC_S       21
#define NVIC_PRI16_INTB_S       13
#define NVIC_PRI16_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI17 register.
//
//*****************************************************************************
#define NVIC_PRI17_INTD_M       0xE0000000  // Interrupt 71 Priority Mask
#define NVIC_PRI17_INTC_M       0x00E00000  // Interrupt 70 Priority Mask
#define NVIC_PRI17_INTB_M       0x0000E000  // Interrupt 69 Priority Mask
#define NVIC_PRI17_INTA_M       0x000000E0  // Interrupt 68 Priority Mask
#define NVIC_PRI17_INTD_S       29
#define NVIC_PRI17_INTC_S       21
#define NVIC_PRI17_INTB_S       13
#define NVIC_PRI17_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI18 register.
//
//*****************************************************************************
#define NVIC_PRI18_INTD_M       0xE0000000  // Interrupt 75 Priority Mask
#define NVIC_PRI18_INTC_M       0x00E00000  // Interrupt 74 Priority Mask
#define NVIC_PRI18_INTB_M       0x0000E000  // Interrupt 73 Priority Mask
#define NVIC_PRI18_INTA_M       0x000000E0  // Interrupt 72 Priority Mask
#define NVIC_PRI18_INTD_S       29
#define NVIC_PRI18_INTC_S       21
#define NVIC_PRI18_INTB_S       13
#define NVIC_PRI18_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI19 register.
//
//*****************************************************************************
#define NVIC_PRI19_INTD_M       0xE0000000  // Interrupt 79 Priority Mask
#define NVIC_PRI19_INTC_M       0x00E00000  // Interrupt 78 Priority Mask
#define NVIC_PRI19_INTB_M       0x0000E000  // Interrupt 77 Priority Mask
#define NVIC_PRI19_INTA_M       0x000000E0  // Interrupt 76 Priority Mask
#define NVIC_PRI19_INTD_S       29
#define NVIC_PRI19_INTC_S       21
#define NVIC_PRI19_INTB_S       13
#define NVIC_PRI19_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI20 register.
//
//*****************************************************************************
#define NVIC_PRI20_INTD_M       0xE0000000  // Interrupt 83 Priority Mask
#define NVIC_PRI20_INTC_M       0x00E00000  // Interrupt 82 Priority Mask
#define NVIC_PRI20_INTB_M       0x0000E000  // Interrupt 81 Priority Mask
#define NVIC_PRI20_INTA_M       0x000000E0  // Interrupt 80 Priority Mask
#define NVIC_PRI20_INTD_S       29
#define NVIC_PRI20_INTC_S       21
#define NVIC_PRI20_INTB_S       13
#define NVIC_PRI20_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI21 register.
//
//*****************************************************************************
#define NVIC_PRI21_INTD_M       0xE0000000  // Interrupt 87 Priority Mask
#define NVIC_PRI21_INTC_M       0x00E00000  // Interrupt 86 Priority Mask
#define NVIC_PRI21_INTB_M       0x0000E000  // Interrupt 85 Priority Mask
#define NVIC_PRI21_INTA_M       0x000000E0  // Interrupt 84 Priority Mask
#define NVIC_PRI21_INTD_S       29
#define NVIC_PRI21_INTC_S       21
#define NVIC_PRI21_INTB_S       13
#define NVIC_PRI21_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI22 register.
//
//*****************************************************************************
#define NVIC_PRI22_INTD_M       0xE0000000  // Interrupt 91 Priority Mask
#define NVIC_PRI22_INTC_M       0x00E00000  // Interrupt 90 Priority Mask
#define NVIC_PRI22_INTB_M       0x0000E000  // Interrupt 89 Priority Mask
#define NVIC_PRI22_INTA_M       0x000000E0  // Interrupt 88 Priority Mask
#define NVIC_PRI22_INTD_S       29
#define NVIC_PRI22_INTC_S       21
#define NVIC_PRI22_INTB_S       13
#define NVIC_PRI22_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI23 register.
//
//*****************************************************************************
#define NVIC_PRI23_INTD_M       0xE0000000  // Interrupt 95 Priority Mask
#define NVIC_PRI23_INTC_M       0x00E00000  // Interrupt 94 Priority Mask
#define NVIC_PRI23_INTB_M       0x0000E000  // Interrupt 93 Priority Mask
#define NVIC_PRI23_INTA_M       0x000000E0  // Interrupt 92 Priority Mask
#define NVIC_PRI23_INTD_S       29
#define NVIC_PRI23_INTC_S       21
#define NVIC_PRI23_INTB_S       13
#define NVIC_PRI23_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI24 register.
//
//*****************************************************************************
#define NVIC_PRI24_INTD_M       0xE0000000  // Interrupt 99 Priority Mask
#define NVIC_PRI24_INTC_M       0x00E00000  // Interrupt 98 Priority Mask
#define NVIC_PRI24_INTB_M       0x0000E000  // Interrupt 97 Priority Mask
#define NVIC_PRI24_INTA_M       0x000000E0  // Interrupt 96 Priority Mask
#define NVIC_PRI24_INTD_S       29
#define NVIC_PRI24_INTC_S       21
#define NVIC_PRI24_INTB_S       13
#define NVIC_PRI24_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI25 register.
//
//*****************************************************************************
#define NVIC_PRI25_INTD_M       0xE0000000  // Interrupt 103 Priority Mask
#define NVIC_PRI25_INTC_M       0x00E00000  // Interrupt 102 Priority Mask
#define NVIC_PRI25_INTB_M       0x0000E000  // Interrupt 101 Priority Mask
#define NVIC_PRI25_INTA_M       0x000000E0  // Interrupt 100 Priority Mask
#define NVIC_PRI25_INTD_S       29
#define NVIC_PRI25_INTC_S       21
#define NVIC_PRI25_INTB_S       13
#define NVIC_PRI25_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI26 register.
//
//*****************************************************************************
#define NVIC_PRI26_INTD_M       0xE0000000  // Interrupt 107 Priority Mask
#define NVIC_PRI26_INTC_M       0x00E00000  // Interrupt 106 Priority Mask
#define NVIC_PRI26_INTB_M       0x0000E000  // Interrupt 105 Priority Mask
#define NVIC_PRI26_INTA_M       0x000000E0  // Interrupt 104 Priority Mask
#define NVIC_PRI26_INTD_S       29
#define NVIC_PRI26_INTC_S       21
#define NVIC_PRI26_INTB_S       13
#define NVIC_PRI26_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI27 register.
//
//*****************************************************************************
#define NVIC_PRI27_INTD_M       0xE0000000  // Interrupt 111 Priority Mask
#define NVIC_PRI27_INTC_M       0x00E00000  // Interrupt 110 Priority Mask
#define NVIC_PRI27_INTB_M       0x0000E000  // Interrupt 109 Priority Mask
#define NVIC_PRI27_INTA_M       0x000000E0  // Interrupt 108 Priority Mask
#define NVIC_PRI27_INTD_S       29
#define NVIC_PRI27_INTC_S       21
#define NVIC_PRI27_INTB_S       13
#define NVIC_PRI27_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI28 register.
//
//*****************************************************************************
#define NVIC_PRI28_INTD_M       0xE0000000  // Interrupt 115 Priority Mask
#define NVIC_PRI28_INTC_M       0x00E00000  // Interrupt 114 Priority Mask
#define NVIC_PRI28_INTB_M       0x0000E000  // Interrupt 113 Priority Mask
#define NVIC_PRI28_INTA_M       0x000000E0  // Interrupt 112 Priority Mask
#define NVIC_PRI28_INTD_S       29
#define NVIC_PRI28_INTC_S       21
#define NVIC_PRI28_INTB_S       13
#define NVIC_PRI28_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI29 register.
//
//*****************************************************************************
#define NVIC_PRI29_INTD_M       0xE0000000  // Interrupt 119 Priority Mask
#define NVIC_PRI29_INTC_M       0x00E00000  // Interrupt 118 Priority Mask
#define NVIC_PRI29_INTB_M       0x0000E000  // Interrupt 117 Priority Mask
#define NVIC_PRI29_INTA_M       0x000000E0  // Interrupt 116 Priority Mask
#define NVIC_PRI29_INTD_S       29
#define NVIC_PRI29_INTC_S       21
#define NVIC_PRI29_INTB_S       13
#define NVIC_PRI29_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI30 register.
//
//*****************************************************************************
#define NVIC_PRI30_INTD_M       0xE0000000  // Interrupt 123 Priority Mask
#define NVIC_PRI30_INTC_M       0x00E00000  // Interrupt 122 Priority Mask
#define NVIC_PRI30_INTB_M       0x0000E000  // Interrupt 121 Priority Mask
#define NVIC_PRI30_INTA_M       0x000000E0  // Interrupt 120 Priority Mask
#define NVIC_PRI30_INTD_S       29
#define NVIC_PRI30_INTC_S       21
#define NVIC_PRI30_INTB_S       13
#define NVIC_PRI30_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI31 register.
//
//*****************************************************************************
#define NVIC_PRI31_INTD_M       0xE0000000  // Interrupt 127 Priority Mask
#define NVIC_PRI31_INTC_M       0x00E00000  // Interrupt 126 Priority Mask
#define NVIC_PRI31_INTB_M       0x0000E000  // Interrupt 125 Priority Mask
#define NVIC_PRI31_INTA_M       0x000000E0  // Interrupt 124 Priority Mask
#define NVIC_PRI31_INTD_S       29
#define NVIC_PRI31_INTC_S       21
#define NVIC_PRI31_INTB_S       13
#define NVIC_PRI31_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI32 register.
//
//*****************************************************************************
#define NVIC_PRI32_INTD_M       0xE0000000  // Interrupt 131 Priority Mask
#define NVIC_PRI32_INTC_M       0x00E00000  // Interrupt 130 Priority Mask
#define NVIC_PRI32_INTB_M       0x0000E000  // Interrupt 129 Priority Mask
#define NVIC_PRI32_INTA_M       0x000000E0  // Interrupt 128 Priority Mask
#define NVIC_PRI32_INTD_S       29
#define NVIC_PRI32_INTC_S       21
#define NVIC_PRI32_INTB_S       13
#define NVIC_PRI32_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI33 register.
//
//*****************************************************************************
#define NVIC_PRI33_INTD_M       0xE0000000  // Interrupt Priority for Interrupt
                                            // [4n+3]
#define NVIC_PRI33_INTC_M       0x00E00000  // Interrupt Priority for Interrupt
                                            // [4n+2]
#define NVIC_PRI33_INTB_M       0x0000E000  // Interrupt Priority for Interrupt
                                            // [4n+1]
#define NVIC_PRI33_INTA_M       0x000000E0  // Interrupt Priority for Interrupt
                                            // [4n]
#define NVIC_PRI33_INTD_S       29
#define NVIC_PRI33_INTC_S       21
#define NVIC_PRI33_INTB_S       13
#define NVIC_PRI33_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_PRI34 register.
//
//*****************************************************************************
#define NVIC_PRI34_INTD_M       0xE0000000  // Interrupt Priority for Interrupt
                                            // [4n+3]
#define NVIC_PRI34_INTC_M       0x00E00000  // Interrupt Priority for Interrupt
                                            // [4n+2]
#define NVIC_PRI34_INTB_M       0x0000E000  // Interrupt Priority for Interrupt
                                            // [4n+1]
#define NVIC_PRI34_INTA_M       0x000000E0  // Interrupt Priority for Interrupt
                                            // [4n]
#define NVIC_PRI34_INTD_S       29
#define NVIC_PRI34_INTC_S       21
#define NVIC_PRI34_INTB_S       13
#define NVIC_PRI34_INTA_S       5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CPUID register.
//
//*****************************************************************************
#define NVIC_CPUID_IMP_M        0xFF000000  // Implementer Code
#define NVIC_CPUID_IMP_ARM      0x41000000  // ARM
#define NVIC_CPUID_VAR_M        0x00F00000  // Variant Number
#define NVIC_CPUID_CON_M        0x000F0000  // Constant
#define NVIC_CPUID_PARTNO_M     0x0000FFF0  // Part Number
#define NVIC_CPUID_PARTNO_CM4   0x0000C240  // Cortex-M4 processor
#define NVIC_CPUID_REV_M        0x0000000F  // Revision Number

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_INT_CTRL register.
//
//*****************************************************************************
#define NVIC_INT_CTRL_NMI_SET   0x80000000  // NMI Set Pending
#define NVIC_INT_CTRL_PEND_SV   0x10000000  // PendSV Set Pending
#define NVIC_INT_CTRL_UNPEND_SV 0x08000000  // PendSV Clear Pending
#define NVIC_INT_CTRL_PENDSTSET 0x04000000  // SysTick Set Pending
#define NVIC_INT_CTRL_PENDSTCLR 0x02000000  // SysTick Clear Pending
#define NVIC_INT_CTRL_ISR_PRE   0x00800000  // Debug Interrupt Handling
#define NVIC_INT_CTRL_ISR_PEND  0x00400000  // Interrupt Pending
#define NVIC_INT_CTRL_VEC_PEN_M 0x000FF000  // Interrupt Pending Vector Number
#define NVIC_INT_CTRL_VEC_PEN_NMI                                             \
                                0x00002000  // NMI
#define NVIC_INT_CTRL_VEC_PEN_HARD                                            \
                                0x00003000  // Hard fault
#define NVIC_INT_CTRL_VEC_PEN_MEM                                             \
                                0x00004000  // Memory management fault
#define NVIC_INT_CTRL_VEC_PEN_BUS                                             \
                                0x00005000  // Bus fault
#define NVIC_INT_CTRL_VEC_PEN_USG                                             \
                                0x00006000  // Usage fault
#define NVIC_INT_CTRL_VEC_PEN_SVC                                             \
                                0x0000B000  // SVCall
#define NVIC_INT_CTRL_VEC_PEN_PNDSV                                           \
                                0x0000E000  // PendSV
#define NVIC_INT_CTRL_VEC_PEN_TICK                                            \
                                0x0000F000  // SysTick
#define NVIC_INT_CTRL_RET_BASE  0x00000800  // Return to Base
#define NVIC_INT_CTRL_VEC_ACT_M 0x000000FF  // Interrupt Pending Vector Number
#define NVIC_INT_CTRL_VEC_ACT_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_VTABLE register.
//
//*****************************************************************************
#define NVIC_VTABLE_OFFSET_M    0xFFFFFC00  // Vector Table Offset
#define NVIC_VTABLE_OFFSET_S    10

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_APINT register.
//
//*****************************************************************************
#define NVIC_APINT_VECTKEY_M    0xFFFF0000  // Register Key
#define NVIC_APINT_VECTKEY      0x05FA0000  // Vector key
#define NVIC_APINT_ENDIANESS    0x00008000  // Data Endianess
#define NVIC_APINT_PRIGROUP_M   0x00000700  // Interrupt Priority Grouping
#define NVIC_APINT_PRIGROUP_7_1 0x00000000  // Priority group 7.1 split
#define NVIC_APINT_PRIGROUP_6_2 0x00000100  // Priority group 6.2 split
#define NVIC_APINT_PRIGROUP_5_3 0x00000200  // Priority group 5.3 split
#define NVIC_APINT_PRIGROUP_4_4 0x00000300  // Priority group 4.4 split
#define NVIC_APINT_PRIGROUP_3_5 0x00000400  // Priority group 3.5 split
#define NVIC_APINT_PRIGROUP_2_6 0x00000500  // Priority group 2.6 split
#define NVIC_APINT_PRIGROUP_1_7 0x00000600  // Priority group 1.7 split
#define NVIC_APINT_PRIGROUP_0_8 0x00000700  // Priority group 0.8 split
#define NVIC_APINT_SYSRESETREQ  0x00000004  // System Reset Request
#define NVIC_APINT_VECT_CLR_ACT 0x00000002  // Clear Active NMI / Fault
#define NVIC_APINT_VECT_RESET   0x00000001  // System Reset

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_CTRL register.
//
//*****************************************************************************
#define NVIC_SYS_CTRL_SEVONPEND 0x00000010  // Wake Up on Pending
#define NVIC_SYS_CTRL_SLEEPDEEP 0x00000004  // Deep Sleep Enable
#define NVIC_SYS_CTRL_SLEEPEXIT 0x00000002  // Sleep on ISR Exit

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CFG_CTRL register.
//
//*****************************************************************************
#define NVIC_CFG_CTRL_STKALIGN  0x00000200  // Stack Alignment on Exception
                                            // Entry
#define NVIC_CFG_CTRL_BFHFNMIGN 0x00000100  // Ignore Bus Fault in NMI and
                                            // Fault
#define NVIC_CFG_CTRL_DIV0      0x00000010  // Trap on Divide by 0
#define NVIC_CFG_CTRL_UNALIGNED 0x00000008  // Trap on Unaligned Access
#define NVIC_CFG_CTRL_MAIN_PEND 0x00000002  // Allow Main Interrupt Trigger
#define NVIC_CFG_CTRL_BASE_THR  0x00000001  // Thread State Control

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI1 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI1_USAGE_M   0x00E00000  // Usage Fault Priority
#define NVIC_SYS_PRI1_BUS_M     0x0000E000  // Bus Fault Priority
#define NVIC_SYS_PRI1_MEM_M     0x000000E0  // Memory Management Fault Priority
#define NVIC_SYS_PRI1_USAGE_S   21
#define NVIC_SYS_PRI1_BUS_S     13
#define NVIC_SYS_PRI1_MEM_S     5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI2 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI2_SVC_M     0xE0000000  // SVCall Priority
#define NVIC_SYS_PRI2_SVC_S     29

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_PRI3 register.
//
//*****************************************************************************
#define NVIC_SYS_PRI3_TICK_M    0xE0000000  // SysTick Exception Priority
#define NVIC_SYS_PRI3_PENDSV_M  0x00E00000  // PendSV Priority
#define NVIC_SYS_PRI3_DEBUG_M   0x000000E0  // Debug Priority
#define NVIC_SYS_PRI3_TICK_S    29
#define NVIC_SYS_PRI3_PENDSV_S  21
#define NVIC_SYS_PRI3_DEBUG_S   5

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SYS_HND_CTRL
// register.
//
//*****************************************************************************
#define NVIC_SYS_HND_CTRL_USAGE 0x00040000  // Usage Fault Enable
#define NVIC_SYS_HND_CTRL_BUS   0x00020000  // Bus Fault Enable
#define NVIC_SYS_HND_CTRL_MEM   0x00010000  // Memory Management Fault Enable
#define NVIC_SYS_HND_CTRL_SVC   0x00008000  // SVC Call Pending
#define NVIC_SYS_HND_CTRL_BUSP  0x00004000  // Bus Fault Pending
#define NVIC_SYS_HND_CTRL_MEMP  0x00002000  // Memory Management Fault Pending
#define NVIC_SYS_HND_CTRL_USAGEP                                              \
                                0x00001000  // Usage Fault Pending
#define NVIC_SYS_HND_CTRL_TICK  0x00000800  // SysTick Exception Active
#define NVIC_SYS_HND_CTRL_PNDSV 0x00000400  // PendSV Exception Active
#define NVIC_SYS_HND_CTRL_MON   0x00000100  // Debug Monitor Active
#define NVIC_SYS_HND_CTRL_SVCA  0x00000080  // SVC Call Active
#define NVIC_SYS_HND_CTRL_USGA  0x00000008  // Usage Fault Active
#define NVIC_SYS_HND_CTRL_BUSA  0x00000002  // Bus Fault Active
#define NVIC_SYS_HND_CTRL_MEMA  0x00000001  // Memory Management Fault Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FAULT_STAT
// register.
//
//*****************************************************************************
#define NVIC_FAULT_STAT_DIV0    0x02000000  // Divide-by-Zero Usage Fault
#define NVIC_FAULT_STAT_UNALIGN 0x01000000  // Unaligned Access Usage Fault
#define NVIC_FAULT_STAT_NOCP    0x00080000  // No Coprocessor Usage Fault
#define NVIC_FAULT_STAT_INVPC   0x00040000  // Invalid PC Load Usage Fault
#define NVIC_FAULT_STAT_INVSTAT 0x00020000  // Invalid State Usage Fault
#define NVIC_FAULT_STAT_UNDEF   0x00010000  // Undefined Instruction Usage
                                            // Fault
#define NVIC_FAULT_STAT_BFARV   0x00008000  // Bus Fault Address Register Valid
#define NVIC_FAULT_STAT_BLSPERR 0x00002000  // Bus Fault on Floating-Point Lazy
                                            // State Preservation
#define NVIC_FAULT_STAT_BSTKE   0x00001000  // Stack Bus Fault
#define NVIC_FAULT_STAT_BUSTKE  0x00000800  // Unstack Bus Fault
#define NVIC_FAULT_STAT_IMPRE   0x00000400  // Imprecise Data Bus Error
#define NVIC_FAULT_STAT_PRECISE 0x00000200  // Precise Data Bus Error
#define NVIC_FAULT_STAT_IBUS    0x00000100  // Instruction Bus Error
#define NVIC_FAULT_STAT_MMARV   0x00000080  // Memory Management Fault Address
                                            // Register Valid
#define NVIC_FAULT_STAT_MLSPERR 0x00000020  // Memory Management Fault on
                                            // Floating-Point Lazy State
                                            // Preservation
#define NVIC_FAULT_STAT_MSTKE   0x00000010  // Stack Access Violation
#define NVIC_FAULT_STAT_MUSTKE  0x00000008  // Unstack Access Violation
#define NVIC_FAULT_STAT_DERR    0x00000002  // Data Access Violation
#define NVIC_FAULT_STAT_IERR    0x00000001  // Instruction Access Violation

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_HFAULT_STAT
// register.
//
//*****************************************************************************
#define NVIC_HFAULT_STAT_DBG    0x80000000  // Debug Event
#define NVIC_HFAULT_STAT_FORCED 0x40000000  // Forced Hard Fault
#define NVIC_HFAULT_STAT_VECT   0x00000002  // Vector Table Read Fault

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DEBUG_STAT
// register.
//
//*****************************************************************************
#define NVIC_DEBUG_STAT_EXTRNL  0x00000010  // EDBGRQ asserted
#define NVIC_DEBUG_STAT_VCATCH  0x00000008  // Vector catch
#define NVIC_DEBUG_STAT_DWTTRAP 0x00000004  // DWT match
#define NVIC_DEBUG_STAT_BKPT    0x00000002  // Breakpoint instruction
#define NVIC_DEBUG_STAT_HALTED  0x00000001  // Halt request

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MM_ADDR register.
//
//*****************************************************************************
#define NVIC_MM_ADDR_M          0xFFFFFFFF  // Fault Address
#define NVIC_MM_ADDR_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FAULT_ADDR
// register.
//
//*****************************************************************************
#define NVIC_FAULT_ADDR_M       0xFFFFFFFF  // Fault Address
#define NVIC_FAULT_ADDR_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_CPAC register.
//
//*****************************************************************************
#define NVIC_CPAC_CP11_M        0x00C00000  // CP11 Coprocessor Access
                                            // Privilege
#define NVIC_CPAC_CP11_DIS      0x00000000  // Access Denied
#define NVIC_CPAC_CP11_PRIV     0x00400000  // Privileged Access Only
#define NVIC_CPAC_CP11_FULL     0x00C00000  // Full Access
#define NVIC_CPAC_CP10_M        0x00300000  // CP10 Coprocessor Access
                                            // Privilege
#define NVIC_CPAC_CP10_DIS      0x00000000  // Access Denied
#define NVIC_CPAC_CP10_PRIV     0x00100000  // Privileged Access Only
#define NVIC_CPAC_CP10_FULL     0x00300000  // Full Access

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_TYPE register.
//
//*****************************************************************************
#define NVIC_MPU_TYPE_IREGION_M 0x00FF0000  // Number of I Regions
#define NVIC_MPU_TYPE_DREGION_M 0x0000FF00  // Number of D Regions
#define NVIC_MPU_TYPE_SEPARATE  0x00000001  // Separate or Unified MPU
#define NVIC_MPU_TYPE_IREGION_S 16
#define NVIC_MPU_TYPE_DREGION_S 8

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_CTRL register.
//
//*****************************************************************************
#define NVIC_MPU_CTRL_PRIVDEFEN 0x00000004  // MPU Default Region
#define NVIC_MPU_CTRL_HFNMIENA  0x00000002  // MPU Enabled During Faults
#define NVIC_MPU_CTRL_ENABLE    0x00000001  // MPU Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_NUMBER
// register.
//
//*****************************************************************************
#define NVIC_MPU_NUMBER_M       0x00000007  // MPU Region to Access
#define NVIC_MPU_NUMBER_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE register.
//
//*****************************************************************************
#define NVIC_MPU_BASE_ADDR_M    0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE_VALID     0x00000010  // Region Number Valid
#define NVIC_MPU_BASE_REGION_M  0x00000007  // Region Number
#define NVIC_MPU_BASE_ADDR_S    5
#define NVIC_MPU_BASE_REGION_S  0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR_XN        0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR_AP_M      0x07000000  // Access Privilege
#define NVIC_MPU_ATTR_AP_NO_NO  0x00000000  // prv: no access, usr: no access
#define NVIC_MPU_ATTR_AP_RW_NO  0x01000000  // prv: rw, usr: none
#define NVIC_MPU_ATTR_AP_RW_RO  0x02000000  // prv: rw, usr: read-only
#define NVIC_MPU_ATTR_AP_RW_RW  0x03000000  // prv: rw, usr: rw
#define NVIC_MPU_ATTR_AP_RO_NO  0x05000000  // prv: ro, usr: none
#define NVIC_MPU_ATTR_AP_RO_RO  0x06000000  // prv: ro, usr: ro
#define NVIC_MPU_ATTR_TEX_M     0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR_SHAREABLE 0x00040000  // Shareable
#define NVIC_MPU_ATTR_CACHEABLE 0x00020000  // Cacheable
#define NVIC_MPU_ATTR_BUFFRABLE 0x00010000  // Bufferable
#define NVIC_MPU_ATTR_SRD_M     0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR_SRD_0     0x00000100  // Sub-region 0 disable
#define NVIC_MPU_ATTR_SRD_1     0x00000200  // Sub-region 1 disable
#define NVIC_MPU_ATTR_SRD_2     0x00000400  // Sub-region 2 disable
#define NVIC_MPU_ATTR_SRD_3     0x00000800  // Sub-region 3 disable
#define NVIC_MPU_ATTR_SRD_4     0x00001000  // Sub-region 4 disable
#define NVIC_MPU_ATTR_SRD_5     0x00002000  // Sub-region 5 disable
#define NVIC_MPU_ATTR_SRD_6     0x00004000  // Sub-region 6 disable
#define NVIC_MPU_ATTR_SRD_7     0x00008000  // Sub-region 7 disable
#define NVIC_MPU_ATTR_SIZE_M    0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR_SIZE_32B  0x00000008  // Region size 32 bytes
#define NVIC_MPU_ATTR_SIZE_64B  0x0000000A  // Region size 64 bytes
#define NVIC_MPU_ATTR_SIZE_128B 0x0000000C  // Region size 128 bytes
#define NVIC_MPU_ATTR_SIZE_256B 0x0000000E  // Region size 256 bytes
#define NVIC_MPU_ATTR_SIZE_512B 0x00000010  // Region size 512 bytes
#define NVIC_MPU_ATTR_SIZE_1K   0x00000012  // Region size 1 Kbytes
#define NVIC_MPU_ATTR_SIZE_2K   0x00000014  // Region size 2 Kbytes
#define NVIC_MPU_ATTR_SIZE_4K   0x00000016  // Region size 4 Kbytes
#define NVIC_MPU_ATTR_SIZE_8K   0x00000018  // Region size 8 Kbytes
#define NVIC_MPU_ATTR_SIZE_16K  0x0000001A  // Region size 16 Kbytes
#define NVIC_MPU_ATTR_SIZE_32K  0x0000001C  // Region size 32 Kbytes
#define NVIC_MPU_ATTR_SIZE_64K  0x0000001E  // Region size 64 Kbytes
#define NVIC_MPU_ATTR_SIZE_128K 0x00000020  // Region size 128 Kbytes
#define NVIC_MPU_ATTR_SIZE_256K 0x00000022  // Region size 256 Kbytes
#define NVIC_MPU_ATTR_SIZE_512K 0x00000024  // Region size 512 Kbytes
#define NVIC_MPU_ATTR_SIZE_1M   0x00000026  // Region size 1 Mbytes
#define NVIC_MPU_ATTR_SIZE_2M   0x00000028  // Region size 2 Mbytes
#define NVIC_MPU_ATTR_SIZE_4M   0x0000002A  // Region size 4 Mbytes
#define NVIC_MPU_ATTR_SIZE_8M   0x0000002C  // Region size 8 Mbytes
#define NVIC_MPU_ATTR_SIZE_16M  0x0000002E  // Region size 16 Mbytes
#define NVIC_MPU_ATTR_SIZE_32M  0x00000030  // Region size 32 Mbytes
#define NVIC_MPU_ATTR_SIZE_64M  0x00000032  // Region size 64 Mbytes
#define NVIC_MPU_ATTR_SIZE_128M 0x00000034  // Region size 128 Mbytes
#define NVIC_MPU_ATTR_SIZE_256M 0x00000036  // Region size 256 Mbytes
#define NVIC_MPU_ATTR_SIZE_512M 0x00000038  // Region size 512 Mbytes
#define NVIC_MPU_ATTR_SIZE_1G   0x0000003A  // Region size 1 Gbytes
#define NVIC_MPU_ATTR_SIZE_2G   0x0000003C  // Region size 2 Gbytes
#define NVIC_MPU_ATTR_SIZE_4G   0x0000003E  // Region size 4 Gbytes
#define NVIC_MPU_ATTR_ENABLE    0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE1 register.
//
//*****************************************************************************
#define NVIC_MPU_BASE1_ADDR_M   0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE1_VALID    0x00000010  // Region Number Valid
#define NVIC_MPU_BASE1_REGION_M 0x00000007  // Region Number
#define NVIC_MPU_BASE1_ADDR_S   5
#define NVIC_MPU_BASE1_REGION_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR1 register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR1_XN       0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR1_AP_M     0x07000000  // Access Privilege
#define NVIC_MPU_ATTR1_TEX_M    0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR1_SHAREABLE                                              \
                                0x00040000  // Shareable
#define NVIC_MPU_ATTR1_CACHEABLE                                              \
                                0x00020000  // Cacheable
#define NVIC_MPU_ATTR1_BUFFRABLE                                              \
                                0x00010000  // Bufferable
#define NVIC_MPU_ATTR1_SRD_M    0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR1_SIZE_M   0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR1_ENABLE   0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE2 register.
//
//*****************************************************************************
#define NVIC_MPU_BASE2_ADDR_M   0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE2_VALID    0x00000010  // Region Number Valid
#define NVIC_MPU_BASE2_REGION_M 0x00000007  // Region Number
#define NVIC_MPU_BASE2_ADDR_S   5
#define NVIC_MPU_BASE2_REGION_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR2 register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR2_XN       0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR2_AP_M     0x07000000  // Access Privilege
#define NVIC_MPU_ATTR2_TEX_M    0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR2_SHAREABLE                                              \
                                0x00040000  // Shareable
#define NVIC_MPU_ATTR2_CACHEABLE                                              \
                                0x00020000  // Cacheable
#define NVIC_MPU_ATTR2_BUFFRABLE                                              \
                                0x00010000  // Bufferable
#define NVIC_MPU_ATTR2_SRD_M    0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR2_SIZE_M   0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR2_ENABLE   0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_BASE3 register.
//
//*****************************************************************************
#define NVIC_MPU_BASE3_ADDR_M   0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE3_VALID    0x00000010  // Region Number Valid
#define NVIC_MPU_BASE3_REGION_M 0x00000007  // Region Number
#define NVIC_MPU_BASE3_ADDR_S   5
#define NVIC_MPU_BASE3_REGION_S 0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_MPU_ATTR3 register.
//
//*****************************************************************************
#define NVIC_MPU_ATTR3_XN       0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR3_AP_M     0x07000000  // Access Privilege
#define NVIC_MPU_ATTR3_TEX_M    0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR3_SHAREABLE                                              \
                                0x00040000  // Shareable
#define NVIC_MPU_ATTR3_CACHEABLE                                              \
                                0x00020000  // Cacheable
#define NVIC_MPU_ATTR3_BUFFRABLE                                              \
                                0x00010000  // Bufferable
#define NVIC_MPU_ATTR3_SRD_M    0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR3_SIZE_M   0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR3_ENABLE   0x00000001  // Region Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_CTRL register.
//
//*****************************************************************************
#define NVIC_DBG_CTRL_DBGKEY_M  0xFFFF0000  // Debug key mask
#define NVIC_DBG_CTRL_DBGKEY    0xA05F0000  // Debug key
#define NVIC_DBG_CTRL_S_RESET_ST                                              \
                                0x02000000  // Core has reset since last read
#define NVIC_DBG_CTRL_S_RETIRE_ST                                             \
                                0x01000000  // Core has executed insruction
                                            // since last read
#define NVIC_DBG_CTRL_S_LOCKUP  0x00080000  // Core is locked up
#define NVIC_DBG_CTRL_S_SLEEP   0x00040000  // Core is sleeping
#define NVIC_DBG_CTRL_S_HALT    0x00020000  // Core status on halt
#define NVIC_DBG_CTRL_S_REGRDY  0x00010000  // Register read/write available
#define NVIC_DBG_CTRL_C_SNAPSTALL                                             \
                                0x00000020  // Breaks a stalled load/store
#define NVIC_DBG_CTRL_C_MASKINT 0x00000008  // Mask interrupts when stepping
#define NVIC_DBG_CTRL_C_STEP    0x00000004  // Step the core
#define NVIC_DBG_CTRL_C_HALT    0x00000002  // Halt the core
#define NVIC_DBG_CTRL_C_DEBUGEN 0x00000001  // Enable debug

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_XFER register.
//
//*****************************************************************************
#define NVIC_DBG_XFER_REG_WNR   0x00010000  // Write or not read
#define NVIC_DBG_XFER_REG_SEL_M 0x0000001F  // Register
#define NVIC_DBG_XFER_REG_R0    0x00000000  // Register R0
#define NVIC_DBG_XFER_REG_R1    0x00000001  // Register R1
#define NVIC_DBG_XFER_REG_R2    0x00000002  // Register R2
#define NVIC_DBG_XFER_REG_R3    0x00000003  // Register R3
#define NVIC_DBG_XFER_REG_R4    0x00000004  // Register R4
#define NVIC_DBG_XFER_REG_R5    0x00000005  // Register R5
#define NVIC_DBG_XFER_REG_R6    0x00000006  // Register R6
#define NVIC_DBG_XFER_REG_R7    0x00000007  // Register R7
#define NVIC_DBG_XFER_REG_R8    0x00000008  // Register R8
#define NVIC_DBG_XFER_REG_R9    0x00000009  // Register R9
#define NVIC_DBG_XFER_REG_R10   0x0000000A  // Register R10
#define NVIC_DBG_XFER_REG_R11   0x0000000B  // Register R11
#define NVIC_DBG_XFER_REG_R12   0x0000000C  // Register R12
#define NVIC_DBG_XFER_REG_R13   0x0000000D  // Register R13
#define NVIC_DBG_XFER_REG_R14   0x0000000E  // Register R14
#define NVIC_DBG_XFER_REG_R15   0x0000000F  // Register R15
#define NVIC_DBG_XFER_REG_FLAGS 0x00000010  // xPSR/Flags register
#define NVIC_DBG_XFER_REG_MSP   0x00000011  // Main SP
#define NVIC_DBG_XFER_REG_PSP   0x00000012  // Process SP
#define NVIC_DBG_XFER_REG_DSP   0x00000013  // Deep SP
#define NVIC_DBG_XFER_REG_CFBP  0x00000014  // Control/Fault/BasePri/PriMask

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_DATA register.
//
//*****************************************************************************
#define NVIC_DBG_DATA_M         0xFFFFFFFF  // Data temporary cache
#define NVIC_DBG_DATA_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_DBG_INT register.
//
//*****************************************************************************
#define NVIC_DBG_INT_HARDERR    0x00000400  // Debug trap on hard fault
#define NVIC_DBG_INT_INTERR     0x00000200  // Debug trap on interrupt errors
#define NVIC_DBG_INT_BUSERR     0x00000100  // Debug trap on bus error
#define NVIC_DBG_INT_STATERR    0x00000080  // Debug trap on usage fault state
#define NVIC_DBG_INT_CHKERR     0x00000040  // Debug trap on usage fault check
#define NVIC_DBG_INT_NOCPERR    0x00000020  // Debug trap on coprocessor error
#define NVIC_DBG_INT_MMERR      0x00000010  // Debug trap on mem manage fault
#define NVIC_DBG_INT_RESET      0x00000008  // Core reset status
#define NVIC_DBG_INT_RSTPENDCLR 0x00000004  // Clear pending core reset
#define NVIC_DBG_INT_RSTPENDING 0x00000002  // Core reset is pending
#define NVIC_DBG_INT_RSTVCATCH  0x00000001  // Reset vector catch

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_SW_TRIG register.
//
//*****************************************************************************
#define NVIC_SW_TRIG_INTID_M    0x000000FF  // Interrupt ID
#define NVIC_SW_TRIG_INTID_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FPCC register.
//
//*****************************************************************************
#define NVIC_FPCC_ASPEN         0x80000000  // Automatic State Preservation
                                            // Enable
#define NVIC_FPCC_LSPEN         0x40000000  // Lazy State Preservation Enable
#define NVIC_FPCC_MONRDY        0x00000100  // Monitor Ready
#define NVIC_FPCC_BFRDY         0x00000040  // Bus Fault Ready
#define NVIC_FPCC_MMRDY         0x00000020  // Memory Management Fault Ready
#define NVIC_FPCC_HFRDY         0x00000010  // Hard Fault Ready
#define NVIC_FPCC_THREAD        0x00000008  // Thread Mode
#define NVIC_FPCC_USER          0x00000002  // User Privilege Level
#define NVIC_FPCC_LSPACT        0x00000001  // Lazy State Preservation Active

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FPCA register.
//
//*****************************************************************************
#define NVIC_FPCA_ADDRESS_M     0xFFFFFFF8  // Address
#define NVIC_FPCA_ADDRESS_S     3

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_FPDSC register.
//
//*****************************************************************************
#define NVIC_FPDSC_AHP          0x04000000  // AHP Bit Default
#define NVIC_FPDSC_DN           0x02000000  // DN Bit Default
#define NVIC_FPDSC_FZ           0x01000000  // FZ Bit Default
#define NVIC_FPDSC_RMODE_M      0x00C00000  // RMODE Bit Default
#define NVIC_FPDSC_RMODE_RN     0x00000000  // Round to Nearest (RN) mode
#define NVIC_FPDSC_RMODE_RP     0x00400000  // Round towards Plus Infinity (RP)
                                            // mode
#define NVIC_FPDSC_RMODE_RM     0x00800000  // Round towards Minus Infinity
                                            // (RM) mode
#define NVIC_FPDSC_RMODE_RZ     0x00C00000  // Round towards Zero (RZ) mode

#endif // __HW_NVIC_H__
