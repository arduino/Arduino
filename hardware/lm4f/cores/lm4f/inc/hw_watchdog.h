//*****************************************************************************
//
// hw_watchdog.h - Macros used when accessing the Watchdog Timer hardware.
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

#ifndef __HW_WATCHDOG_H__
#define __HW_WATCHDOG_H__

//*****************************************************************************
//
// The following are defines for the Watchdog Timer register offsets.
//
//*****************************************************************************
#define WDT_O_LOAD              0x00000000  // Watchdog Load
#define WDT_O_VALUE             0x00000004  // Watchdog Value
#define WDT_O_CTL               0x00000008  // Watchdog Control
#define WDT_O_ICR               0x0000000C  // Watchdog Interrupt Clear
#define WDT_O_RIS               0x00000010  // Watchdog Raw Interrupt Status
#define WDT_O_MIS               0x00000014  // Watchdog Masked Interrupt Status
#define WDT_O_TEST              0x00000418  // Watchdog Test
#define WDT_O_LOCK              0x00000C00  // Watchdog Lock

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOAD register.
//
//*****************************************************************************
#define WDT_LOAD_M              0xFFFFFFFF  // Watchdog Load Value
#define WDT_LOAD_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_VALUE register.
//
//*****************************************************************************
#define WDT_VALUE_M             0xFFFFFFFF  // Watchdog Value
#define WDT_VALUE_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_CTL register.
//
//*****************************************************************************
#define WDT_CTL_WRC             0x80000000  // Write Complete
#define WDT_CTL_INTTYPE         0x00000004  // Watchdog Interrupt Type
#define WDT_CTL_RESEN           0x00000002  // Watchdog Reset Enable
#define WDT_CTL_INTEN           0x00000001  // Watchdog Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_ICR register.
//
//*****************************************************************************
#define WDT_ICR_M               0xFFFFFFFF  // Watchdog Interrupt Clear
#define WDT_ICR_S               0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_RIS register.
//
//*****************************************************************************
#define WDT_RIS_WDTRIS          0x00000001  // Watchdog Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_MIS register.
//
//*****************************************************************************
#define WDT_MIS_WDTMIS          0x00000001  // Watchdog Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_TEST register.
//
//*****************************************************************************
#define WDT_TEST_STALL          0x00000100  // Watchdog Stall Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOCK register.
//
//*****************************************************************************
#define WDT_LOCK_M              0xFFFFFFFF  // Watchdog Lock
#define WDT_LOCK_UNLOCKED       0x00000000  // Unlocked
#define WDT_LOCK_LOCKED         0x00000001  // Locked
#define WDT_LOCK_UNLOCK         0x1ACCE551  // Unlocks the watchdog timer

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_ISR, WDT_RIS, and
// WDT_MIS registers.
//
//*****************************************************************************
#define WDT_INT_TIMEOUT         0x00000001  // Watchdog timer expired

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the Watchdog Timer register
// offsets.
//
//*****************************************************************************
#define WDT_O_PeriphID4         0x00000FD0
#define WDT_O_PeriphID5         0x00000FD4
#define WDT_O_PeriphID6         0x00000FD8
#define WDT_O_PeriphID7         0x00000FDC
#define WDT_O_PeriphID0         0x00000FE0
#define WDT_O_PeriphID1         0x00000FE4
#define WDT_O_PeriphID2         0x00000FE8
#define WDT_O_PeriphID3         0x00000FEC
#define WDT_O_PCellID0          0x00000FF0
#define WDT_O_PCellID1          0x00000FF4
#define WDT_O_PCellID2          0x00000FF8
#define WDT_O_PCellID3          0x00000FFC

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the WDT_O_TEST
// register.
//
//*****************************************************************************
#define WDT_TEST_STALL_EN       0x00000100  // Watchdog stall enable

//*****************************************************************************
//
// The following are deprecated defines for the reset values for the WDT
// registers.
//
//*****************************************************************************
#define WDT_RV_VALUE            0xFFFFFFFF  // Current value register
#define WDT_RV_LOAD             0xFFFFFFFF  // Load register
#define WDT_RV_PCellID1         0x000000F0
#define WDT_RV_PCellID3         0x000000B1
#define WDT_RV_PeriphID1        0x00000018
#define WDT_RV_PeriphID2        0x00000018
#define WDT_RV_PCellID0         0x0000000D
#define WDT_RV_PCellID2         0x00000005
#define WDT_RV_PeriphID0        0x00000005
#define WDT_RV_PeriphID3        0x00000001
#define WDT_RV_PeriphID5        0x00000000
#define WDT_RV_RIS              0x00000000  // Raw interrupt status register
#define WDT_RV_CTL              0x00000000  // Control register
#define WDT_RV_PeriphID4        0x00000000
#define WDT_RV_PeriphID6        0x00000000
#define WDT_RV_PeriphID7        0x00000000
#define WDT_RV_LOCK             0x00000000  // Lock register
#define WDT_RV_MIS              0x00000000  // Masked interrupt status register

#endif

#endif // __HW_WATCHDOG_H__
