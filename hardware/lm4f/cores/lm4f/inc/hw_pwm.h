//*****************************************************************************
//
// hw_pwm.h - Defines and Macros for Pulse Width Modulation (PWM) ports.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __HW_PWM_H__
#define __HW_PWM_H__

//*****************************************************************************
//
// The following are defines for the PWM register offsets.
//
//*****************************************************************************
#define PWM_O_CTL               0x00000000  // PWM Master Control
#define PWM_O_SYNC              0x00000004  // PWM Time Base Sync
#define PWM_O_ENABLE            0x00000008  // PWM Output Enable
#define PWM_O_INVERT            0x0000000C  // PWM Output Inversion
#define PWM_O_FAULT             0x00000010  // PWM Output Fault
#define PWM_O_INTEN             0x00000014  // PWM Interrupt Enable
#define PWM_O_RIS               0x00000018  // PWM Raw Interrupt Status
#define PWM_O_ISC               0x0000001C  // PWM Interrupt Status and Clear
#define PWM_O_STATUS            0x00000020  // PWM Status
#define PWM_O_FAULTVAL          0x00000024  // PWM Fault Condition Value
#define PWM_O_ENUPD             0x00000028  // PWM Enable Update
#define PWM_O_0_CTL             0x00000040  // PWM0 Control
#define PWM_O_0_INTEN           0x00000044  // PWM0 Interrupt and Trigger
                                            // Enable
#define PWM_O_0_RIS             0x00000048  // PWM0 Raw Interrupt Status
#define PWM_O_0_ISC             0x0000004C  // PWM0 Interrupt Status and Clear
#define PWM_O_0_LOAD            0x00000050  // PWM0 Load
#define PWM_O_0_COUNT           0x00000054  // PWM0 Counter
#define PWM_O_0_CMPA            0x00000058  // PWM0 Compare A
#define PWM_O_0_CMPB            0x0000005C  // PWM0 Compare B
#define PWM_O_0_GENA            0x00000060  // PWM0 Generator A Control
#define PWM_O_0_GENB            0x00000064  // PWM0 Generator B Control
#define PWM_O_0_DBCTL           0x00000068  // PWM0 Dead-Band Control
#define PWM_O_0_DBRISE          0x0000006C  // PWM0 Dead-Band Rising-Edge Delay
#define PWM_O_0_DBFALL          0x00000070  // PWM0 Dead-Band
                                            // Falling-Edge-Delay
#define PWM_O_0_FLTSRC0         0x00000074  // PWM0 Fault Source 0
#define PWM_O_0_FLTSRC1         0x00000078  // PWM0 Fault Source 1
#define PWM_O_0_MINFLTPER       0x0000007C  // PWM0 Minimum Fault Period
#define PWM_O_1_CTL             0x00000080  // PWM1 Control
#define PWM_O_1_INTEN           0x00000084  // PWM1 Interrupt and Trigger
                                            // Enable
#define PWM_O_1_RIS             0x00000088  // PWM1 Raw Interrupt Status
#define PWM_O_1_ISC             0x0000008C  // PWM1 Interrupt Status and Clear
#define PWM_O_1_LOAD            0x00000090  // PWM1 Load
#define PWM_O_1_COUNT           0x00000094  // PWM1 Counter
#define PWM_O_1_CMPA            0x00000098  // PWM1 Compare A
#define PWM_O_1_CMPB            0x0000009C  // PWM1 Compare B
#define PWM_O_1_GENA            0x000000A0  // PWM1 Generator A Control
#define PWM_O_1_GENB            0x000000A4  // PWM1 Generator B Control
#define PWM_O_1_DBCTL           0x000000A8  // PWM1 Dead-Band Control
#define PWM_O_1_DBRISE          0x000000AC  // PWM1 Dead-Band Rising-Edge Delay
#define PWM_O_1_DBFALL          0x000000B0  // PWM1 Dead-Band
                                            // Falling-Edge-Delay
#define PWM_O_1_FLTSRC0         0x000000B4  // PWM1 Fault Source 0
#define PWM_O_1_FLTSRC1         0x000000B8  // PWM1 Fault Source 1
#define PWM_O_1_MINFLTPER       0x000000BC  // PWM1 Minimum Fault Period
#define PWM_O_2_CTL             0x000000C0  // PWM2 Control
#define PWM_O_2_INTEN           0x000000C4  // PWM2 Interrupt and Trigger
                                            // Enable
#define PWM_O_2_RIS             0x000000C8  // PWM2 Raw Interrupt Status
#define PWM_O_2_ISC             0x000000CC  // PWM2 Interrupt Status and Clear
#define PWM_O_2_LOAD            0x000000D0  // PWM2 Load
#define PWM_O_2_COUNT           0x000000D4  // PWM2 Counter
#define PWM_O_2_CMPA            0x000000D8  // PWM2 Compare A
#define PWM_O_2_CMPB            0x000000DC  // PWM2 Compare B
#define PWM_O_2_GENA            0x000000E0  // PWM2 Generator A Control
#define PWM_O_2_GENB            0x000000E4  // PWM2 Generator B Control
#define PWM_O_2_DBCTL           0x000000E8  // PWM2 Dead-Band Control
#define PWM_O_2_DBRISE          0x000000EC  // PWM2 Dead-Band Rising-Edge Delay
#define PWM_O_2_DBFALL          0x000000F0  // PWM2 Dead-Band
                                            // Falling-Edge-Delay
#define PWM_O_2_FLTSRC0         0x000000F4  // PWM2 Fault Source 0
#define PWM_O_2_FLTSRC1         0x000000F8  // PWM2 Fault Source 1
#define PWM_O_2_MINFLTPER       0x000000FC  // PWM2 Minimum Fault Period
#define PWM_O_3_CTL             0x00000100  // PWM3 Control
#define PWM_O_3_INTEN           0x00000104  // PWM3 Interrupt and Trigger
                                            // Enable
#define PWM_O_3_RIS             0x00000108  // PWM3 Raw Interrupt Status
#define PWM_O_3_ISC             0x0000010C  // PWM3 Interrupt Status and Clear
#define PWM_O_3_LOAD            0x00000110  // PWM3 Load
#define PWM_O_3_COUNT           0x00000114  // PWM3 Counter
#define PWM_O_3_CMPA            0x00000118  // PWM3 Compare A
#define PWM_O_3_CMPB            0x0000011C  // PWM3 Compare B
#define PWM_O_3_GENA            0x00000120  // PWM3 Generator A Control
#define PWM_O_3_GENB            0x00000124  // PWM3 Generator B Control
#define PWM_O_3_DBCTL           0x00000128  // PWM3 Dead-Band Control
#define PWM_O_3_DBRISE          0x0000012C  // PWM3 Dead-Band Rising-Edge Delay
#define PWM_O_3_DBFALL          0x00000130  // PWM3 Dead-Band
                                            // Falling-Edge-Delay
#define PWM_O_3_FLTSRC0         0x00000134  // PWM3 Fault Source 0
#define PWM_O_3_FLTSRC1         0x00000138  // PWM3 Fault Source 1
#define PWM_O_3_MINFLTPER       0x0000013C  // PWM3 Minimum Fault Period
#define PWM_O_0_FLTSEN          0x00000800  // PWM0 Fault Pin Logic Sense
#define PWM_O_0_FLTSTAT0        0x00000804  // PWM0 Fault Status 0
#define PWM_O_0_FLTSTAT1        0x00000808  // PWM0 Fault Status 1
#define PWM_O_1_FLTSEN          0x00000880  // PWM1 Fault Pin Logic Sense
#define PWM_O_1_FLTSTAT0        0x00000884  // PWM1 Fault Status 0
#define PWM_O_1_FLTSTAT1        0x00000888  // PWM1 Fault Status 1
#define PWM_O_2_FLTSEN          0x00000900  // PWM2 Fault Pin Logic Sense
#define PWM_O_2_FLTSTAT0        0x00000904  // PWM2 Fault Status 0
#define PWM_O_2_FLTSTAT1        0x00000908  // PWM2 Fault Status 1
#define PWM_O_3_FLTSEN          0x00000980  // PWM3 Fault Pin Logic Sense
#define PWM_O_3_FLTSTAT0        0x00000984  // PWM3 Fault Status 0
#define PWM_O_3_FLTSTAT1        0x00000988  // PWM3 Fault Status 1
#define PWM_O_PP                0x00000FC0  // PWM Peripheral Properties
#define PWM_O_PC                0x00000FC4  // PWM Peripheral Configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_CTL register.
//
//*****************************************************************************
#define PWM_CTL_GLOBALSYNC3     0x00000008  // Update PWM Generator 3
#define PWM_CTL_GLOBALSYNC2     0x00000004  // Update PWM Generator 2
#define PWM_CTL_GLOBALSYNC1     0x00000002  // Update PWM Generator 1
#define PWM_CTL_GLOBALSYNC0     0x00000001  // Update PWM Generator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_SYNC register.
//
//*****************************************************************************
#define PWM_SYNC_SYNC3          0x00000008  // Reset Generator 3 Counter
#define PWM_SYNC_SYNC2          0x00000004  // Reset Generator 2 Counter
#define PWM_SYNC_SYNC1          0x00000002  // Reset Generator 1 Counter
#define PWM_SYNC_SYNC0          0x00000001  // Reset Generator 0 Counter

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_ENABLE register.
//
//*****************************************************************************
#define PWM_ENABLE_PWM7EN       0x00000080  // PWM7 Output Enable
#define PWM_ENABLE_PWM6EN       0x00000040  // PWM6 Output Enable
#define PWM_ENABLE_PWM5EN       0x00000020  // PWM5 Output Enable
#define PWM_ENABLE_PWM4EN       0x00000010  // PWM4 Output Enable
#define PWM_ENABLE_PWM3EN       0x00000008  // PWM3 Output Enable
#define PWM_ENABLE_PWM2EN       0x00000004  // PWM2 Output Enable
#define PWM_ENABLE_PWM1EN       0x00000002  // PWM1 Output Enable
#define PWM_ENABLE_PWM0EN       0x00000001  // PWM0 Output Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_INVERT register.
//
//*****************************************************************************
#define PWM_INVERT_PWM7INV      0x00000080  // Invert PWM7 Signal
#define PWM_INVERT_PWM6INV      0x00000040  // Invert PWM6 Signal
#define PWM_INVERT_PWM5INV      0x00000020  // Invert PWM5 Signal
#define PWM_INVERT_PWM4INV      0x00000010  // Invert PWM4 Signal
#define PWM_INVERT_PWM3INV      0x00000008  // Invert PWM3 Signal
#define PWM_INVERT_PWM2INV      0x00000004  // Invert PWM2 Signal
#define PWM_INVERT_PWM1INV      0x00000002  // Invert PWM1 Signal
#define PWM_INVERT_PWM0INV      0x00000001  // Invert PWM0 Signal

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_FAULT register.
//
//*****************************************************************************
#define PWM_FAULT_FAULT7        0x00000080  // PWM7 Fault
#define PWM_FAULT_FAULT6        0x00000040  // PWM6 Fault
#define PWM_FAULT_FAULT5        0x00000020  // PWM5 Fault
#define PWM_FAULT_FAULT4        0x00000010  // PWM4 Fault
#define PWM_FAULT_FAULT3        0x00000008  // PWM3 Fault
#define PWM_FAULT_FAULT2        0x00000004  // PWM2 Fault
#define PWM_FAULT_FAULT1        0x00000002  // PWM1 Fault
#define PWM_FAULT_FAULT0        0x00000001  // PWM0 Fault

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_INTEN register.
//
//*****************************************************************************
#define PWM_INTEN_INTFAULT3     0x00080000  // Interrupt Fault 3
#define PWM_INTEN_INTFAULT2     0x00040000  // Interrupt Fault 2
#define PWM_INTEN_INTFAULT1     0x00020000  // Interrupt Fault 1
#define PWM_INTEN_INTFAULT      0x00010000  // Fault Interrupt Enable
#define PWM_INTEN_INTFAULT0     0x00010000  // Interrupt Fault 0
#define PWM_INTEN_INTPWM3       0x00000008  // PWM3 Interrupt Enable
#define PWM_INTEN_INTPWM2       0x00000004  // PWM2 Interrupt Enable
#define PWM_INTEN_INTPWM1       0x00000002  // PWM1 Interrupt Enable
#define PWM_INTEN_INTPWM0       0x00000001  // PWM0 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_RIS register.
//
//*****************************************************************************
#define PWM_RIS_INTFAULT3       0x00080000  // Interrupt Fault PWM 3
#define PWM_RIS_INTFAULT2       0x00040000  // Interrupt Fault PWM 2
#define PWM_RIS_INTFAULT1       0x00020000  // Interrupt Fault PWM 1
#define PWM_RIS_INTFAULT0       0x00010000  // Interrupt Fault PWM 0
#define PWM_RIS_INTFAULT        0x00010000  // Fault Interrupt Asserted
#define PWM_RIS_INTPWM3         0x00000008  // PWM3 Interrupt Asserted
#define PWM_RIS_INTPWM2         0x00000004  // PWM2 Interrupt Asserted
#define PWM_RIS_INTPWM1         0x00000002  // PWM1 Interrupt Asserted
#define PWM_RIS_INTPWM0         0x00000001  // PWM0 Interrupt Asserted

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_ISC register.
//
//*****************************************************************************
#define PWM_ISC_INTFAULT3       0x00080000  // FAULT3 Interrupt Asserted
#define PWM_ISC_INTFAULT2       0x00040000  // FAULT2 Interrupt Asserted
#define PWM_ISC_INTFAULT1       0x00020000  // FAULT1 Interrupt Asserted
#define PWM_ISC_INTFAULT        0x00010000  // Fault Interrupt Asserted
#define PWM_ISC_INTFAULT0       0x00010000  // FAULT0 Interrupt Asserted
#define PWM_ISC_INTPWM3         0x00000008  // PWM3 Interrupt Status
#define PWM_ISC_INTPWM2         0x00000004  // PWM2 Interrupt Status
#define PWM_ISC_INTPWM1         0x00000002  // PWM1 Interrupt Status
#define PWM_ISC_INTPWM0         0x00000001  // PWM0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_STATUS register.
//
//*****************************************************************************
#define PWM_STATUS_FAULT3       0x00000008  // Generator 3 Fault Status
#define PWM_STATUS_FAULT2       0x00000004  // Generator 2 Fault Status
#define PWM_STATUS_FAULT1       0x00000002  // Generator 1 Fault Status
#define PWM_STATUS_FAULT0       0x00000001  // Generator 0 Fault Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_FAULTVAL register.
//
//*****************************************************************************
#define PWM_FAULTVAL_PWM7       0x00000080  // PWM7 Fault Value
#define PWM_FAULTVAL_PWM6       0x00000040  // PWM6 Fault Value
#define PWM_FAULTVAL_PWM5       0x00000020  // PWM5 Fault Value
#define PWM_FAULTVAL_PWM4       0x00000010  // PWM4 Fault Value
#define PWM_FAULTVAL_PWM3       0x00000008  // PWM3 Fault Value
#define PWM_FAULTVAL_PWM2       0x00000004  // PWM2 Fault Value
#define PWM_FAULTVAL_PWM1       0x00000002  // PWM1 Fault Value
#define PWM_FAULTVAL_PWM0       0x00000001  // PWM0 Fault Value

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_ENUPD register.
//
//*****************************************************************************
#define PWM_ENUPD_ENUPD7_M      0x0000C000  // PWM7 Enable Update Mode
#define PWM_ENUPD_ENUPD7_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD7_LSYNC  0x00008000  // Locally Synchronized
#define PWM_ENUPD_ENUPD7_GSYNC  0x0000C000  // Globally Synchronized
#define PWM_ENUPD_ENUPD6_M      0x00003000  // PWM6 Enable Update Mode
#define PWM_ENUPD_ENUPD6_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD6_LSYNC  0x00002000  // Locally Synchronized
#define PWM_ENUPD_ENUPD6_GSYNC  0x00003000  // Globally Synchronized
#define PWM_ENUPD_ENUPD5_M      0x00000C00  // PWM5 Enable Update Mode
#define PWM_ENUPD_ENUPD5_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD5_LSYNC  0x00000800  // Locally Synchronized
#define PWM_ENUPD_ENUPD5_GSYNC  0x00000C00  // Globally Synchronized
#define PWM_ENUPD_ENUPD4_M      0x00000300  // PWM4 Enable Update Mode
#define PWM_ENUPD_ENUPD4_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD4_LSYNC  0x00000200  // Locally Synchronized
#define PWM_ENUPD_ENUPD4_GSYNC  0x00000300  // Globally Synchronized
#define PWM_ENUPD_ENUPD3_M      0x000000C0  // PWM3 Enable Update Mode
#define PWM_ENUPD_ENUPD3_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD3_LSYNC  0x00000080  // Locally Synchronized
#define PWM_ENUPD_ENUPD3_GSYNC  0x000000C0  // Globally Synchronized
#define PWM_ENUPD_ENUPD2_M      0x00000030  // PWM2 Enable Update Mode
#define PWM_ENUPD_ENUPD2_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD2_LSYNC  0x00000020  // Locally Synchronized
#define PWM_ENUPD_ENUPD2_GSYNC  0x00000030  // Globally Synchronized
#define PWM_ENUPD_ENUPD1_M      0x0000000C  // PWM1 Enable Update Mode
#define PWM_ENUPD_ENUPD1_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD1_LSYNC  0x00000008  // Locally Synchronized
#define PWM_ENUPD_ENUPD1_GSYNC  0x0000000C  // Globally Synchronized
#define PWM_ENUPD_ENUPD0_M      0x00000003  // PWM0 Enable Update Mode
#define PWM_ENUPD_ENUPD0_IMM    0x00000000  // Immediate
#define PWM_ENUPD_ENUPD0_LSYNC  0x00000002  // Locally Synchronized
#define PWM_ENUPD_ENUPD0_GSYNC  0x00000003  // Globally Synchronized

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_CTL register.
//
//*****************************************************************************
#define PWM_0_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_0_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_0_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_0_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_0_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_0_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_0_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_0_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_0_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_0_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_0_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_0_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_0_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_0_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_0_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_0_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_0_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_0_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_0_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_0_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_0_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_0_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_0_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_0_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_0_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_0_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_0_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_0_CTL_MODE          0x00000002  // Counter Mode
#define PWM_0_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_INTEN register.
//
//*****************************************************************************
#define PWM_0_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_0_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_0_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_0_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_0_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_0_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_0_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_0_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_0_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_0_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_0_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_0_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_RIS register.
//
//*****************************************************************************
#define PWM_0_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_0_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_0_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_0_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_0_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_0_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_ISC register.
//
//*****************************************************************************
#define PWM_0_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_0_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_0_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_0_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_0_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_0_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_LOAD register.
//
//*****************************************************************************
#define PWM_0_LOAD_M            0x0000FFFF  // Counter Load Value
#define PWM_0_LOAD_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_COUNT register.
//
//*****************************************************************************
#define PWM_0_COUNT_M           0x0000FFFF  // Counter Value
#define PWM_0_COUNT_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_CMPA register.
//
//*****************************************************************************
#define PWM_0_CMPA_M            0x0000FFFF  // Comparator A Value
#define PWM_0_CMPA_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_CMPB register.
//
//*****************************************************************************
#define PWM_0_CMPB_M            0x0000FFFF  // Comparator B Value
#define PWM_0_CMPB_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_GENA register.
//
//*****************************************************************************
#define PWM_0_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_0_GENA_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_0_GENA_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_0_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_0_GENA_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_0_GENA_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_0_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_0_GENA_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_0_GENA_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_0_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_0_GENA_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_0_GENA_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_0_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_0_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_0_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_0_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_0_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_0_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_0_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_0_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_0_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_0_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_0_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_GENB register.
//
//*****************************************************************************
#define PWM_0_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_0_GENB_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_0_GENB_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_0_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_0_GENB_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_0_GENB_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_0_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_0_GENB_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_0_GENB_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_0_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_0_GENB_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_0_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_0_GENB_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_0_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_0_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_0_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_0_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_0_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_0_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_0_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_0_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_0_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_0_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_0_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_DBCTL register.
//
//*****************************************************************************
#define PWM_0_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_DBRISE register.
//
//*****************************************************************************
#define PWM_0_DBRISE_DELAY_M    0x00000FFF  // Dead-Band Rise Delay
#define PWM_0_DBRISE_DELAY_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_DBFALL register.
//
//*****************************************************************************
#define PWM_0_DBFALL_DELAY_M    0x00000FFF  // Dead-Band Fall Delay
#define PWM_0_DBFALL_DELAY_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_0_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_0_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_0_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_0_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_0_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_0_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_0_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_0_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_0_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_0_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_0_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_0_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_0_MINFLTPER_M       0x0000FFFF  // Minimum Fault Period
#define PWM_0_MINFLTPER_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_CTL register.
//
//*****************************************************************************
#define PWM_1_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_1_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_1_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_1_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_1_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_1_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_1_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_1_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_1_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_1_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_1_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_1_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_1_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_1_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_1_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_1_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_1_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_1_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_1_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_1_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_1_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_1_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_1_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_1_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_1_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_1_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_1_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_1_CTL_MODE          0x00000002  // Counter Mode
#define PWM_1_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_INTEN register.
//
//*****************************************************************************
#define PWM_1_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_1_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_1_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_1_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_1_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_1_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_1_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_1_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_1_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_1_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_1_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_1_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_RIS register.
//
//*****************************************************************************
#define PWM_1_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_1_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_1_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_1_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_1_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_1_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_ISC register.
//
//*****************************************************************************
#define PWM_1_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_1_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_1_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_1_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_1_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_1_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_LOAD register.
//
//*****************************************************************************
#define PWM_1_LOAD_LOAD_M       0x0000FFFF  // Counter Load Value
#define PWM_1_LOAD_LOAD_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_COUNT register.
//
//*****************************************************************************
#define PWM_1_COUNT_COUNT_M     0x0000FFFF  // Counter Value
#define PWM_1_COUNT_COUNT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_CMPA register.
//
//*****************************************************************************
#define PWM_1_CMPA_COMPA_M      0x0000FFFF  // Comparator A Value
#define PWM_1_CMPA_COMPA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_CMPB register.
//
//*****************************************************************************
#define PWM_1_CMPB_COMPB_M      0x0000FFFF  // Comparator B Value
#define PWM_1_CMPB_COMPB_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_GENA register.
//
//*****************************************************************************
#define PWM_1_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_1_GENA_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_1_GENA_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_1_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_1_GENA_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_1_GENA_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_1_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_1_GENA_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_1_GENA_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_1_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_1_GENA_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_1_GENA_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_1_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_1_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_1_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_1_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_1_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_1_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_1_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_1_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_1_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_1_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_1_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_GENB register.
//
//*****************************************************************************
#define PWM_1_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_1_GENB_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_1_GENB_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_1_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_1_GENB_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_1_GENB_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_1_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_1_GENB_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_1_GENB_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_1_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_1_GENB_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_1_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_1_GENB_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_1_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_1_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_1_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_1_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_1_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_1_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_1_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_1_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_1_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_1_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_1_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_DBCTL register.
//
//*****************************************************************************
#define PWM_1_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_DBRISE register.
//
//*****************************************************************************
#define PWM_1_DBRISE_RISEDELAY_M \
                                0x00000FFF  // Dead-Band Rise Delay
#define PWM_1_DBRISE_RISEDELAY_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_DBFALL register.
//
//*****************************************************************************
#define PWM_1_DBFALL_FALLDELAY_M \
                                0x00000FFF  // Dead-Band Fall Delay
#define PWM_1_DBFALL_FALLDELAY_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_1_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_1_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_1_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_1_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_1_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_1_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_1_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_1_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_1_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_1_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_1_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_1_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_1_MINFLTPER_MFP_M   0x0000FFFF  // Minimum Fault Period
#define PWM_1_MINFLTPER_MFP_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_CTL register.
//
//*****************************************************************************
#define PWM_2_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_2_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_2_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_2_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_2_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_2_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_2_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_2_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_2_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_2_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_2_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_2_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_2_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_2_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_2_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_2_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_2_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_2_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_2_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_2_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_2_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_2_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_2_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_2_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_2_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_2_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_2_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_2_CTL_MODE          0x00000002  // Counter Mode
#define PWM_2_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_INTEN register.
//
//*****************************************************************************
#define PWM_2_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_2_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_2_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_2_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_2_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_2_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_2_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_2_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_2_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_2_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_2_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_2_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_RIS register.
//
//*****************************************************************************
#define PWM_2_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_2_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_2_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_2_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_2_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_2_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_ISC register.
//
//*****************************************************************************
#define PWM_2_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_2_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_2_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_2_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_2_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_2_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_LOAD register.
//
//*****************************************************************************
#define PWM_2_LOAD_LOAD_M       0x0000FFFF  // Counter Load Value
#define PWM_2_LOAD_LOAD_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_COUNT register.
//
//*****************************************************************************
#define PWM_2_COUNT_COUNT_M     0x0000FFFF  // Counter Value
#define PWM_2_COUNT_COUNT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_CMPA register.
//
//*****************************************************************************
#define PWM_2_CMPA_COMPA_M      0x0000FFFF  // Comparator A Value
#define PWM_2_CMPA_COMPA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_CMPB register.
//
//*****************************************************************************
#define PWM_2_CMPB_COMPB_M      0x0000FFFF  // Comparator B Value
#define PWM_2_CMPB_COMPB_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_GENA register.
//
//*****************************************************************************
#define PWM_2_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_2_GENA_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_2_GENA_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_2_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_2_GENA_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_2_GENA_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_2_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_2_GENA_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_2_GENA_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_2_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_2_GENA_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_2_GENA_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_2_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_2_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_2_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_2_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_2_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_2_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_2_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_2_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_2_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_2_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_2_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_GENB register.
//
//*****************************************************************************
#define PWM_2_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_2_GENB_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_2_GENB_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_2_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_2_GENB_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_2_GENB_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_2_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_2_GENB_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_2_GENB_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_2_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_2_GENB_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_2_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_2_GENB_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_2_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_2_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_2_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_2_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_2_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_2_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_2_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_2_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_2_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_2_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_2_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_DBCTL register.
//
//*****************************************************************************
#define PWM_2_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_DBRISE register.
//
//*****************************************************************************
#define PWM_2_DBRISE_RISEDELAY_M \
                                0x00000FFF  // Dead-Band Rise Delay
#define PWM_2_DBRISE_RISEDELAY_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_DBFALL register.
//
//*****************************************************************************
#define PWM_2_DBFALL_FALLDELAY_M \
                                0x00000FFF  // Dead-Band Fall Delay
#define PWM_2_DBFALL_FALLDELAY_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_2_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_2_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_2_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_2_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_2_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_2_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_2_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_2_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_2_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_2_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_2_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_2_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_2_MINFLTPER_MFP_M   0x0000FFFF  // Minimum Fault Period
#define PWM_2_MINFLTPER_MFP_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_CTL register.
//
//*****************************************************************************
#define PWM_3_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_3_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_3_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_3_CTL_DBFALLUPD_M   0x0000C000  // Specifies the update mode for
                                            // the PWMnDBFALL register
#define PWM_3_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_3_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_3_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_3_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_3_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_3_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_3_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_3_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_3_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_3_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_3_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_3_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_3_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_3_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_3_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_3_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_3_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_3_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_3_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_3_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_3_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_3_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_3_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_3_CTL_MODE          0x00000002  // Counter Mode
#define PWM_3_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_INTEN register.
//
//*****************************************************************************
#define PWM_3_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=Comparator B
                                            // Down
#define PWM_3_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=Comparator B
                                            // Up
#define PWM_3_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=Comparator A
                                            // Down
#define PWM_3_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=Comparator A
                                            // Up
#define PWM_3_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=Load
#define PWM_3_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_3_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=Comparator
                                            // B Down
#define PWM_3_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=Comparator
                                            // B Up
#define PWM_3_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=Comparator
                                            // A Down
#define PWM_3_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=Comparator
                                            // A Up
#define PWM_3_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=Load
#define PWM_3_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_RIS register.
//
//*****************************************************************************
#define PWM_3_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_3_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_3_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_3_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_3_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_3_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_ISC register.
//
//*****************************************************************************
#define PWM_3_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_3_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_3_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_3_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_3_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_3_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_LOAD register.
//
//*****************************************************************************
#define PWM_3_LOAD_LOAD_M       0x0000FFFF  // Counter Load Value
#define PWM_3_LOAD_LOAD_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_COUNT register.
//
//*****************************************************************************
#define PWM_3_COUNT_COUNT_M     0x0000FFFF  // Counter Value
#define PWM_3_COUNT_COUNT_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_CMPA register.
//
//*****************************************************************************
#define PWM_3_CMPA_COMPA_M      0x0000FFFF  // Comparator A Value
#define PWM_3_CMPA_COMPA_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_CMPB register.
//
//*****************************************************************************
#define PWM_3_CMPB_COMPB_M      0x0000FFFF  // Comparator B Value
#define PWM_3_CMPB_COMPB_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_GENA register.
//
//*****************************************************************************
#define PWM_3_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_3_GENA_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_3_GENA_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_3_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_3_GENA_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_3_GENA_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_3_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_3_GENA_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_3_GENA_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_3_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_3_GENA_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENA_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_3_GENA_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_3_GENA_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_3_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_3_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_3_GENA_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_3_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_3_GENA_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_3_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_3_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_3_GENA_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_3_GENA_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_3_GENA_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_GENB register.
//
//*****************************************************************************
#define PWM_3_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_3_GENB_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPBD_INV 0x00000400  // Invert the output signal
#define PWM_3_GENB_ACTCMPBD_ZERO \
                                0x00000800  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_3_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_3_GENB_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPBU_INV 0x00000100  // Invert the output signal
#define PWM_3_GENB_ACTCMPBU_ZERO \
                                0x00000200  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPBU_ONE 0x00000300  // Set the output signal to 1
#define PWM_3_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_3_GENB_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPAD_INV 0x00000040  // Invert the output signal
#define PWM_3_GENB_ACTCMPAD_ZERO \
                                0x00000080  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_3_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_3_GENB_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_3_GENB_ACTCMPAU_INV 0x00000010  // Invert the output signal
#define PWM_3_GENB_ACTCMPAU_ZERO \
                                0x00000020  // Set the output signal to 0
#define PWM_3_GENB_ACTCMPAU_ONE 0x00000030  // Set the output signal to 1
#define PWM_3_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=Load
#define PWM_3_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_3_GENB_ACTLOAD_INV  0x00000004  // Invert the output signal
#define PWM_3_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM_3_GENB_ACTLOAD_ONE  0x0000000C  // Set the output signal to 1
#define PWM_3_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_3_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_3_GENB_ACTZERO_INV  0x00000001  // Invert the output signal
#define PWM_3_GENB_ACTZERO_ZERO 0x00000002  // Set the output signal to 0
#define PWM_3_GENB_ACTZERO_ONE  0x00000003  // Set the output signal to 1

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_DBCTL register.
//
//*****************************************************************************
#define PWM_3_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_DBRISE register.
//
//*****************************************************************************
#define PWM_3_DBRISE_RISEDELAY_M \
                                0x00000FFF  // Dead-Band Rise Delay
#define PWM_3_DBRISE_RISEDELAY_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_DBFALL register.
//
//*****************************************************************************
#define PWM_3_DBFALL_FALLDELAY_M \
                                0x00000FFF  // Dead-Band Fall Delay
#define PWM_3_DBFALL_FALLDELAY_S \
                                0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_3_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_3_FLTSRC0_FAULT2    0x00000004  // Fault2
#define PWM_3_FLTSRC0_FAULT1    0x00000002  // Fault1
#define PWM_3_FLTSRC0_FAULT0    0x00000001  // Fault0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_3_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_3_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_3_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_3_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_3_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_3_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_3_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_3_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_3_MINFLTPER_MFP_M   0x0000FFFF  // Minimum Fault Period
#define PWM_3_MINFLTPER_MFP_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSEN register.
//
//*****************************************************************************
#define PWM_0_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_0_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_0_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_0_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_0_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_0_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_0_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_0_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_0_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_0_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_0_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_0_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_0_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_0_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_0_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_0_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_0_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSEN register.
//
//*****************************************************************************
#define PWM_1_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_1_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_1_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_1_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_1_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_1_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_1_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_1_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_1_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_1_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_1_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_1_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_1_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_1_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_1_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_1_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_1_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSEN register.
//
//*****************************************************************************
#define PWM_2_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_2_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_2_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_2_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_2_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_2_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_2_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_2_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_2_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_2_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_2_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_2_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_2_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_2_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_2_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_2_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_2_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSEN register.
//
//*****************************************************************************
#define PWM_3_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_3_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_3_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_3_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_3_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_3_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_3_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_3_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_3_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_3_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_3_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_3_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_3_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_3_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_3_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_3_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_3_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_PP register.
//
//*****************************************************************************
#define PWM_PP_GCNT_M           0x0000000F  // Generators
#define PWM_PP_FCNT_M           0x000000F0  // Fault Inputs
#define PWM_PP_ESYNC            0x00000100  // Extended Synchronization
#define PWM_PP_EFAULT           0x00000200  // Extended Fault
#define PWM_PP_ONE              0x00000400  // One-Shot Mode
#define PWM_PP_GCNT_S           0
#define PWM_PP_FCNT_S           4

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_PC register.
//
//*****************************************************************************
#define PWM_PC_PWMDIV_M         0x000000FF  // PWM Clock Divisor
#define PWM_PC_PWMDIV_2         0x00000000  // /2
#define PWM_PC_PWMDIV_4         0x00000001  // /4
#define PWM_PC_PWMDIV_8         0x00000002  // /8
#define PWM_PC_PWMDIV_16        0x00000003  // /16
#define PWM_PC_PWMDIV_32        0x00000004  // /32
#define PWM_PC_PWMDIV_64        0x00000007  // /64 (default)
#define PWM_PC_USEPWMDIV        0x00000100  // Enable PWM Clock Divisor

//*****************************************************************************
//
// The following are defines for the PWM Generator standard offsets.
//
//*****************************************************************************
#define PWM_O_X_CTL             0x00000000  // Gen Control Reg
#define PWM_O_X_INTEN           0x00000004  // Gen Int/Trig Enable Reg
#define PWM_O_X_RIS             0x00000008  // Gen Raw Int Status Reg
#define PWM_O_X_ISC             0x0000000C  // Gen Int Status Reg
#define PWM_O_X_LOAD            0x00000010  // Gen Load Reg
#define PWM_O_X_COUNT           0x00000014  // Gen Counter Reg
#define PWM_O_X_CMPA            0x00000018  // Gen Compare A Reg
#define PWM_O_X_CMPB            0x0000001C  // Gen Compare B Reg
#define PWM_O_X_GENA            0x00000020  // Gen Generator A Ctrl Reg
#define PWM_O_X_GENB            0x00000024  // Gen Generator B Ctrl Reg
#define PWM_O_X_DBCTL           0x00000028  // Gen Dead Band Ctrl Reg
#define PWM_O_X_DBRISE          0x0000002C  // Gen DB Rising Edge Delay Reg
#define PWM_O_X_DBFALL          0x00000030  // Gen DB Falling Edge Delay Reg
#define PWM_O_X_FLTSRC0         0x00000034  // Fault pin, comparator condition
#define PWM_O_X_FLTSRC1         0x00000038  // Digital comparator condition
#define PWM_O_X_MINFLTPER       0x0000003C  // Fault minimum period extension
#define PWM_GEN_0_OFFSET        0x00000040  // PWM0 base
#define PWM_GEN_1_OFFSET        0x00000080  // PWM1 base
#define PWM_GEN_2_OFFSET        0x000000C0  // PWM2 base
#define PWM_GEN_3_OFFSET        0x00000100  // PWM3 base

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_CTL register.
//
//*****************************************************************************
#define PWM_X_CTL_LATCH         0x00040000  // Latch Fault Input
#define PWM_X_CTL_MINFLTPER     0x00020000  // Minimum Fault Period
#define PWM_X_CTL_FLTSRC        0x00010000  // Fault Condition Source
#define PWM_X_CTL_DBFALLUPD_M   0x0000C000  // PWMnDBFALL Update Mode
#define PWM_X_CTL_DBFALLUPD_I   0x00000000  // Immediate
#define PWM_X_CTL_DBFALLUPD_LS  0x00008000  // Locally Synchronized
#define PWM_X_CTL_DBFALLUPD_GS  0x0000C000  // Globally Synchronized
#define PWM_X_CTL_DBRISEUPD_M   0x00003000  // PWMnDBRISE Update Mode
#define PWM_X_CTL_DBRISEUPD_I   0x00000000  // Immediate
#define PWM_X_CTL_DBRISEUPD_LS  0x00002000  // Locally Synchronized
#define PWM_X_CTL_DBRISEUPD_GS  0x00003000  // Globally Synchronized
#define PWM_X_CTL_DBCTLUPD_M    0x00000C00  // PWMnDBCTL Update Mode
#define PWM_X_CTL_DBCTLUPD_I    0x00000000  // Immediate
#define PWM_X_CTL_DBCTLUPD_LS   0x00000800  // Locally Synchronized
#define PWM_X_CTL_DBCTLUPD_GS   0x00000C00  // Globally Synchronized
#define PWM_X_CTL_GENBUPD_M     0x00000300  // PWMnGENB Update Mode
#define PWM_X_CTL_GENBUPD_I     0x00000000  // Immediate
#define PWM_X_CTL_GENBUPD_LS    0x00000200  // Locally Synchronized
#define PWM_X_CTL_GENBUPD_GS    0x00000300  // Globally Synchronized
#define PWM_X_CTL_GENAUPD_M     0x000000C0  // PWMnGENA Update Mode
#define PWM_X_CTL_GENAUPD_I     0x00000000  // Immediate
#define PWM_X_CTL_GENAUPD_LS    0x00000080  // Locally Synchronized
#define PWM_X_CTL_GENAUPD_GS    0x000000C0  // Globally Synchronized
#define PWM_X_CTL_CMPBUPD       0x00000020  // Comparator B Update Mode
#define PWM_X_CTL_CMPAUPD       0x00000010  // Comparator A Update Mode
#define PWM_X_CTL_LOADUPD       0x00000008  // Load Register Update Mode
#define PWM_X_CTL_DEBUG         0x00000004  // Debug Mode
#define PWM_X_CTL_MODE          0x00000002  // Counter Mode
#define PWM_X_CTL_ENABLE        0x00000001  // PWM Block Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_INTEN register.
//
//*****************************************************************************
#define PWM_X_INTEN_TRCMPBD     0x00002000  // Trigger for Counter=PWMnCMPB
                                            // Down
#define PWM_X_INTEN_TRCMPBU     0x00001000  // Trigger for Counter=PWMnCMPB Up
#define PWM_X_INTEN_TRCMPAD     0x00000800  // Trigger for Counter=PWMnCMPA
                                            // Down
#define PWM_X_INTEN_TRCMPAU     0x00000400  // Trigger for Counter=PWMnCMPA Up
#define PWM_X_INTEN_TRCNTLOAD   0x00000200  // Trigger for Counter=PWMnLOAD
#define PWM_X_INTEN_TRCNTZERO   0x00000100  // Trigger for Counter=0
#define PWM_X_INTEN_INTCMPBD    0x00000020  // Interrupt for Counter=PWMnCMPB
                                            // Down
#define PWM_X_INTEN_INTCMPBU    0x00000010  // Interrupt for Counter=PWMnCMPB
                                            // Up
#define PWM_X_INTEN_INTCMPAD    0x00000008  // Interrupt for Counter=PWMnCMPA
                                            // Down
#define PWM_X_INTEN_INTCMPAU    0x00000004  // Interrupt for Counter=PWMnCMPA
                                            // Up
#define PWM_X_INTEN_INTCNTLOAD  0x00000002  // Interrupt for Counter=PWMnLOAD
#define PWM_X_INTEN_INTCNTZERO  0x00000001  // Interrupt for Counter=0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_RIS register.
//
//*****************************************************************************
#define PWM_X_RIS_INTCMPBD      0x00000020  // Comparator B Down Interrupt
                                            // Status
#define PWM_X_RIS_INTCMPBU      0x00000010  // Comparator B Up Interrupt Status
#define PWM_X_RIS_INTCMPAD      0x00000008  // Comparator A Down Interrupt
                                            // Status
#define PWM_X_RIS_INTCMPAU      0x00000004  // Comparator A Up Interrupt Status
#define PWM_X_RIS_INTCNTLOAD    0x00000002  // Counter=Load Interrupt Status
#define PWM_X_RIS_INTCNTZERO    0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_ISC register.
//
//*****************************************************************************
#define PWM_X_ISC_INTCMPBD      0x00000020  // Comparator B Down Interrupt
#define PWM_X_ISC_INTCMPBU      0x00000010  // Comparator B Up Interrupt
#define PWM_X_ISC_INTCMPAD      0x00000008  // Comparator A Down Interrupt
#define PWM_X_ISC_INTCMPAU      0x00000004  // Comparator A Up Interrupt
#define PWM_X_ISC_INTCNTLOAD    0x00000002  // Counter=Load Interrupt
#define PWM_X_ISC_INTCNTZERO    0x00000001  // Counter=0 Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_LOAD register.
//
//*****************************************************************************
#define PWM_X_LOAD_M            0x0000FFFF  // Counter Load Value
#define PWM_X_LOAD_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_COUNT register.
//
//*****************************************************************************
#define PWM_X_COUNT_M           0x0000FFFF  // Counter Value
#define PWM_X_COUNT_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_CMPA register.
//
//*****************************************************************************
#define PWM_X_CMPA_M            0x0000FFFF  // Comparator A Value
#define PWM_X_CMPA_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_CMPB register.
//
//*****************************************************************************
#define PWM_X_CMPB_M            0x0000FFFF  // Comparator B Value
#define PWM_X_CMPB_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_GENA register.
//
//*****************************************************************************
#define PWM_X_GENA_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_X_GENA_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPBD_INV 0x00000400  // Invert pwmA
#define PWM_X_GENA_ACTCMPBD_ZERO \
                                0x00000800  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPBD_ONE 0x00000C00  // Drive pwmA High
#define PWM_X_GENA_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_X_GENA_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPBU_INV 0x00000100  // Invert pwmA
#define PWM_X_GENA_ACTCMPBU_ZERO \
                                0x00000200  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPBU_ONE 0x00000300  // Drive pwmA High
#define PWM_X_GENA_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_X_GENA_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPAD_INV 0x00000040  // Invert pwmA
#define PWM_X_GENA_ACTCMPAD_ZERO \
                                0x00000080  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPAD_ONE 0x000000C0  // Drive pwmA High
#define PWM_X_GENA_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_X_GENA_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPAU_INV 0x00000010  // Invert pwmA
#define PWM_X_GENA_ACTCMPAU_ZERO \
                                0x00000020  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPAU_ONE 0x00000030  // Drive pwmA High
#define PWM_X_GENA_ACTLOAD_M    0x0000000C  // Action for Counter=LOAD
#define PWM_X_GENA_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_X_GENA_ACTLOAD_INV  0x00000004  // Invert pwmA
#define PWM_X_GENA_ACTLOAD_ZERO 0x00000008  // Drive pwmA Low
#define PWM_X_GENA_ACTLOAD_ONE  0x0000000C  // Drive pwmA High
#define PWM_X_GENA_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_X_GENA_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_X_GENA_ACTZERO_INV  0x00000001  // Invert pwmA
#define PWM_X_GENA_ACTZERO_ZERO 0x00000002  // Drive pwmA Low
#define PWM_X_GENA_ACTZERO_ONE  0x00000003  // Drive pwmA High

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_GENB register.
//
//*****************************************************************************
#define PWM_X_GENB_ACTCMPBD_M   0x00000C00  // Action for Comparator B Down
#define PWM_X_GENB_ACTCMPBD_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPBD_INV 0x00000400  // Invert pwmB
#define PWM_X_GENB_ACTCMPBD_ZERO \
                                0x00000800  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPBD_ONE 0x00000C00  // Drive pwmB High
#define PWM_X_GENB_ACTCMPBU_M   0x00000300  // Action for Comparator B Up
#define PWM_X_GENB_ACTCMPBU_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPBU_INV 0x00000100  // Invert pwmB
#define PWM_X_GENB_ACTCMPBU_ZERO \
                                0x00000200  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPBU_ONE 0x00000300  // Drive pwmB High
#define PWM_X_GENB_ACTCMPAD_M   0x000000C0  // Action for Comparator A Down
#define PWM_X_GENB_ACTCMPAD_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPAD_INV 0x00000040  // Invert pwmB
#define PWM_X_GENB_ACTCMPAD_ZERO \
                                0x00000080  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPAD_ONE 0x000000C0  // Drive pwmB High
#define PWM_X_GENB_ACTCMPAU_M   0x00000030  // Action for Comparator A Up
#define PWM_X_GENB_ACTCMPAU_NONE \
                                0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPAU_INV 0x00000010  // Invert pwmB
#define PWM_X_GENB_ACTCMPAU_ZERO \
                                0x00000020  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPAU_ONE 0x00000030  // Drive pwmB High
#define PWM_X_GENB_ACTLOAD_M    0x0000000C  // Action for Counter=LOAD
#define PWM_X_GENB_ACTLOAD_NONE 0x00000000  // Do nothing
#define PWM_X_GENB_ACTLOAD_INV  0x00000004  // Invert pwmB
#define PWM_X_GENB_ACTLOAD_ZERO 0x00000008  // Drive pwmB Low
#define PWM_X_GENB_ACTLOAD_ONE  0x0000000C  // Drive pwmB High
#define PWM_X_GENB_ACTZERO_M    0x00000003  // Action for Counter=0
#define PWM_X_GENB_ACTZERO_NONE 0x00000000  // Do nothing
#define PWM_X_GENB_ACTZERO_INV  0x00000001  // Invert pwmB
#define PWM_X_GENB_ACTZERO_ZERO 0x00000002  // Drive pwmB Low
#define PWM_X_GENB_ACTZERO_ONE  0x00000003  // Drive pwmB High

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_DBCTL register.
//
//*****************************************************************************
#define PWM_X_DBCTL_ENABLE      0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_DBRISE register.
//
//*****************************************************************************
#define PWM_X_DBRISE_DELAY_M    0x00000FFF  // Dead-Band Rise Delay
#define PWM_X_DBRISE_DELAY_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_DBFALL register.
//
//*****************************************************************************
#define PWM_X_DBFALL_DELAY_M    0x00000FFF  // Dead-Band Fall Delay
#define PWM_X_DBFALL_DELAY_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_FLTSRC0
// register.
//
//*****************************************************************************
#define PWM_X_FLTSRC0_FAULT3    0x00000008  // Fault3 Input
#define PWM_X_FLTSRC0_FAULT2    0x00000004  // Fault2 Input
#define PWM_X_FLTSRC0_FAULT1    0x00000002  // Fault1 Input
#define PWM_X_FLTSRC0_FAULT0    0x00000001  // Fault0 Input

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_FLTSRC1
// register.
//
//*****************************************************************************
#define PWM_X_FLTSRC1_DCMP7     0x00000080  // Digital Comparator 7
#define PWM_X_FLTSRC1_DCMP6     0x00000040  // Digital Comparator 6
#define PWM_X_FLTSRC1_DCMP5     0x00000020  // Digital Comparator 5
#define PWM_X_FLTSRC1_DCMP4     0x00000010  // Digital Comparator 4
#define PWM_X_FLTSRC1_DCMP3     0x00000008  // Digital Comparator 3
#define PWM_X_FLTSRC1_DCMP2     0x00000004  // Digital Comparator 2
#define PWM_X_FLTSRC1_DCMP1     0x00000002  // Digital Comparator 1
#define PWM_X_FLTSRC1_DCMP0     0x00000001  // Digital Comparator 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_MINFLTPER
// register.
//
//*****************************************************************************
#define PWM_X_MINFLTPER_M       0x0000FFFF  // Minimum Fault Period
#define PWM_X_MINFLTPER_S       0

//*****************************************************************************
//
// The following are defines for the PWM Generator extended offsets.
//
//*****************************************************************************
#define PWM_O_X_FLTSEN          0x00000000  // Fault logic sense
#define PWM_O_X_FLTSTAT0        0x00000004  // Pin and comparator status
#define PWM_O_X_FLTSTAT1        0x00000008  // Digital comparator status
#define PWM_EXT_0_OFFSET        0x00000800  // PWM0 extended base
#define PWM_EXT_1_OFFSET        0x00000880  // PWM1 extended base
#define PWM_EXT_2_OFFSET        0x00000900  // PWM2 extended base
#define PWM_EXT_3_OFFSET        0x00000980  // PWM3 extended base

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_FLTSEN register.
//
//*****************************************************************************
#define PWM_X_FLTSEN_FAULT3     0x00000008  // Fault3 Sense
#define PWM_X_FLTSEN_FAULT2     0x00000004  // Fault2 Sense
#define PWM_X_FLTSEN_FAULT1     0x00000002  // Fault1 Sense
#define PWM_X_FLTSEN_FAULT0     0x00000001  // Fault0 Sense

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_FLTSTAT0
// register.
//
//*****************************************************************************
#define PWM_X_FLTSTAT0_FAULT3   0x00000008  // Fault Input 3
#define PWM_X_FLTSTAT0_FAULT2   0x00000004  // Fault Input 2
#define PWM_X_FLTSTAT0_FAULT1   0x00000002  // Fault Input 1
#define PWM_X_FLTSTAT0_FAULT0   0x00000001  // Fault Input 0

//*****************************************************************************
//
// The following are defines for the bit fields in the PWM_O_X_FLTSTAT1
// register.
//
//*****************************************************************************
#define PWM_X_FLTSTAT1_DCMP7    0x00000080  // Digital Comparator 7 Trigger
#define PWM_X_FLTSTAT1_DCMP6    0x00000040  // Digital Comparator 6 Trigger
#define PWM_X_FLTSTAT1_DCMP5    0x00000020  // Digital Comparator 5 Trigger
#define PWM_X_FLTSTAT1_DCMP4    0x00000010  // Digital Comparator 4 Trigger
#define PWM_X_FLTSTAT1_DCMP3    0x00000008  // Digital Comparator 3 Trigger
#define PWM_X_FLTSTAT1_DCMP2    0x00000004  // Digital Comparator 2 Trigger
#define PWM_X_FLTSTAT1_DCMP1    0x00000002  // Digital Comparator 1 Trigger
#define PWM_X_FLTSTAT1_DCMP0    0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the PWM_O_CTL
// register.
//
//*****************************************************************************
#define PWM_CTL_GLOBAL_SYNC2    0x00000004  // Global sync generator 2
#define PWM_CTL_GLOBAL_SYNC1    0x00000002  // Global sync generator 1
#define PWM_CTL_GLOBAL_SYNC0    0x00000001  // Global sync generator 0

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the PWM_O_STATUS
// register.
//
//*****************************************************************************
#define PWM_STATUS_FAULT        0x00000001  // Fault Interrupt Status

//*****************************************************************************
//
// The following are deprecated defines for the PWM Interrupt Register bit
// definitions.
//
//*****************************************************************************
#define PWM_INT_INTFAULT        0x00010000  // Fault interrupt pending

//*****************************************************************************
//
// The following are deprecated defines for the PWM_X Interrupt Status Register
// bit definitions.
//
//*****************************************************************************
#define PWM_X_INT_INTCMPBD      0x00000020  // PWM_X_COUNT = PWM_X_CMPB D rcvd
#define PWM_X_INT_INTCMPBU      0x00000010  // PWM_X_COUNT = PWM_X_CMPB U rcvd
#define PWM_X_INT_INTCMPAD      0x00000008  // PWM_X_COUNT = PWM_X_CMPA D rcvd
#define PWM_X_INT_INTCMPAU      0x00000004  // PWM_X_COUNT = PWM_X_CMPA U rcvd
#define PWM_X_INT_INTCNTLOAD    0x00000002  // PWM_X_COUNT = PWM_X_LOAD rcvd
#define PWM_X_INT_INTCNTZERO    0x00000001  // PWM_X_COUNT = 0 received

//*****************************************************************************
//
// The following are deprecated defines for the PWM_X Generator A/B Control
// Register bit definitions.
//
//*****************************************************************************
#define PWM_X_GEN_Y_ACTCMPBD    0x00000C00  // Act PWM_X_COUNT = PWM_X_CMPB D
#define PWM_X_GEN_Y_ACTCMPBU    0x00000300  // Act PWM_X_COUNT = PWM_X_CMPB U
#define PWM_X_GEN_Y_ACTCMPAD    0x000000C0  // Act PWM_X_COUNT = PWM_X_CMPA D
#define PWM_X_GEN_Y_ACTCMPAU    0x00000030  // Act PWM_X_COUNT = PWM_X_CMPA U
#define PWM_X_GEN_Y_ACTLOAD     0x0000000C  // Act PWM_X_COUNT = PWM_X_LOAD
#define PWM_X_GEN_Y_ACTZERO     0x00000003  // Act PWM_X_COUNT = 0

//*****************************************************************************
//
// The following are deprecated defines for the PWM_X Generator A/B Control
// Register action definitions.
//
//*****************************************************************************
#define PWM_GEN_ACT_ONE         0x00000003  // Set the output signal to one
#define PWM_GEN_ACT_ZERO        0x00000002  // Set the output signal to zero
#define PWM_GEN_ACT_INV         0x00000001  // Invert the output signal
#define PWM_GEN_ACT_NONE        0x00000000  // Do nothing
#define PWM_GEN_ACT_B_DN_SHIFT  10          // Shift amount for the B dn action
#define PWM_GEN_ACT_B_UP_SHIFT  8           // Shift amount for the B up action
#define PWM_GEN_ACT_A_DN_SHIFT  6           // Shift amount for the A dn action
#define PWM_GEN_ACT_A_UP_SHIFT  4           // Shift amount for the A up action
#define PWM_GEN_ACT_LOAD_SHIFT  2           // Shift amount for the load action
#define PWM_GEN_ACT_ZERO_SHIFT  0           // Shift amount for the zero action

//*****************************************************************************
//
// The following are deprecated defines for the PWM_X Dead Band Control
// Register bit definitions.
//
//*****************************************************************************
#define PWM_DBCTL_ENABLE        0x00000001  // Enable dead band insertion

//*****************************************************************************
//
// The following are deprecated defines for the PWM Register reset values.
//
//*****************************************************************************
#define PWM_RV_X_DBCTL          0x00000000  // Control the dead band generator
#define PWM_RV_STATUS           0x00000000  // Status
#define PWM_RV_X_ISC            0x00000000  // Interrupt status and clearing
#define PWM_RV_X_RIS            0x00000000  // Raw interrupt status
#define PWM_RV_X_CTL            0x00000000  // Master control of the PWM
                                            // generator block
#define PWM_RV_SYNC             0x00000000  // Counter synch for PWM generators
#define PWM_RV_X_DBFALL         0x00000000  // The dead band falling edge delay
                                            // count
#define PWM_RV_X_INTEN          0x00000000  // Interrupt and trigger enable
#define PWM_RV_X_LOAD           0x00000000  // The load value for the counter
#define PWM_RV_X_GENA           0x00000000  // Controls PWM generator A
#define PWM_RV_CTL              0x00000000  // Master control of the PWM module
#define PWM_RV_FAULT            0x00000000  // Fault handling for the PWM
                                            // output pins
#define PWM_RV_RIS              0x00000000  // Raw interrupt status
#define PWM_RV_X_CMPA           0x00000000  // The comparator A value
#define PWM_RV_INVERT           0x00000000  // Inversion control for PWM output
                                            // pins
#define PWM_RV_X_DBRISE         0x00000000  // The dead band rising edge delay
                                            // count
#define PWM_RV_ENABLE           0x00000000  // Master enable for the PWM output
                                            // pins
#define PWM_RV_X_GENB           0x00000000  // Controls PWM generator B
#define PWM_RV_X_CMPB           0x00000000  // The comparator B value
#define PWM_RV_ISC              0x00000000  // Interrupt status and clearing
#define PWM_RV_INTEN            0x00000000  // Interrupt enable
#define PWM_RV_X_COUNT          0x00000000  // The current counter value

#endif

#endif // __HW_PWM_H__
