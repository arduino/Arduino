//*****************************************************************************
//
// hw_hibernate.h - Defines and Macros for the Hibernation module.
//
// Copyright (c) 2007-2013 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __HW_HIBERNATE_H__
#define __HW_HIBERNATE_H__

//*****************************************************************************
//
// The following are defines for the Hibernation module register addresses.
//
//*****************************************************************************
#define HIB_RTCC                0x400FC000  // Hibernation RTC Counter
#define HIB_RTCM0               0x400FC004  // Hibernation RTC Match 0
#define HIB_RTCLD               0x400FC00C  // Hibernation RTC Load
#define HIB_CTL                 0x400FC010  // Hibernation Control
#define HIB_IM                  0x400FC014  // Hibernation Interrupt Mask
#define HIB_RIS                 0x400FC018  // Hibernation Raw Interrupt Status
#define HIB_MIS                 0x400FC01C  // Hibernation Masked Interrupt
                                            // Status
#define HIB_IC                  0x400FC020  // Hibernation Interrupt Clear
#define HIB_RTCT                0x400FC024  // Hibernation RTC Trim
#define HIB_RTCSS               0x400FC028  // Hibernation RTC Sub Seconds
#define HIB_IO                  0x400FC02C  // Hibernation IO Configuration
#define HIB_DATA                0x400FC030  // Hibernation Data
#define HIB_CALCTL              0x400FC300  // Hibernation Calendar Control
#define HIB_CAL0                0x400FC310  // Hibernation Calendar 0
#define HIB_CAL1                0x400FC314  // Hibernation Calendar 1
#define HIB_CALLD0              0x400FC320  // Hibernation Calendar Load 0
#define HIB_CALLD1              0x400FC324  // Hibernation Calendar Load
#define HIB_CALM0               0x400FC330  // Hibernation Calendar Match 0
#define HIB_CALM1               0x400FC334  // Hibernation Calendar Match 1
#define HIB_LOCK                0x400FC360  // Hibernation Lock
#define HIB_TPCTL               0x400FC400  // HIB Tamper Control
#define HIB_TPSTAT              0x400FC404  // HIB Tamper Status
#define HIB_TPIO                0x400FC410  // HIB Tamper I/O Control and
                                            // Status
#define HIB_TPLOG0              0x400FC4E0  // HIB Tamper Log 0
#define HIB_TPLOG1              0x400FC4E4  // HIB Tamper Log 1
#define HIB_TPLOG2              0x400FC4E8  // HIB Tamper Log 2
#define HIB_TPLOG3              0x400FC4EC  // HIB Tamper Log 3
#define HIB_TPLOG4              0x400FC4F0  // HIB Tamper Log 4
#define HIB_TPLOG5              0x400FC4F4  // HIB Tamper Log 5
#define HIB_TPLOG6              0x400FC4F8  // HIB Tamper Log 6
#define HIB_TPLOG7              0x400FC4FC  // HIB Tamper Log 7
#define HIB_PP                  0x400FCFC0  // Hibernation Peripheral
                                            // Properties
#define HIB_CC                  0x400FCFC8  // Hibernation Clock Control

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCC register.
//
//*****************************************************************************
#define HIB_RTCC_M              0xFFFFFFFF  // RTC Counter
#define HIB_RTCC_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCM0 register.
//
//*****************************************************************************
#define HIB_RTCM0_M             0xFFFFFFFF  // RTC Match 0
#define HIB_RTCM0_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCLD register.
//
//*****************************************************************************
#define HIB_RTCLD_M             0xFFFFFFFF  // RTC Load
#define HIB_RTCLD_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CTL register.
//
//*****************************************************************************
#define HIB_CTL_WRC             0x80000000  // Write Complete/Capable
#define HIB_CTL_RETCLR          0x40000000  // GPIO Retention/Clear
#define HIB_CTL_OSCSEL          0x00080000  // Oscillator Select
#define HIB_CTL_OSCDRV          0x00020000  // Oscillator Drive Capability
#define HIB_CTL_OSCBYP          0x00010000  // Oscillator Bypass
#define HIB_CTL_VBATSEL_M       0x00006000  // Select for Low-Battery
                                            // Comparator
#define HIB_CTL_VBATSEL_1_9V    0x00000000  // 1.9 Volts
#define HIB_CTL_VBATSEL_2_1V    0x00002000  // 2.1 Volts (default)
#define HIB_CTL_VBATSEL_2_3V    0x00004000  // 2.3 Volts
#define HIB_CTL_VBATSEL_2_5V    0x00006000  // 2.5 Volts
#define HIB_CTL_BATCHK          0x00000400  // Check Battery Status
#define HIB_CTL_BATWKEN         0x00000200  // Wake on Low Battery
#define HIB_CTL_VDD3ON          0x00000100  // VDD Powered
#define HIB_CTL_VABORT          0x00000080  // Power Cut Abort Enable
#define HIB_CTL_CLK32EN         0x00000040  // Clocking Enable
#define HIB_CTL_PINWEN          0x00000010  // External WAKE Pin Enable
#define HIB_CTL_RTCWEN          0x00000008  // RTC Wake-up Enable
#define HIB_CTL_HIBREQ          0x00000002  // Hibernation Request
#define HIB_CTL_RTCEN           0x00000001  // RTC Timer Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IM register.
//
//*****************************************************************************
#define HIB_IM_VDDFAIL          0x00000080  // VDD Fail Interrupt Mask
#define HIB_IM_RSTWK            0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_IM_PADIOWK          0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_IM_WC               0x00000010  // External Write Complete/Capable
                                            // Interrupt Mask
#define HIB_IM_EXTW             0x00000008  // External Wake-Up Interrupt Mask
#define HIB_IM_LOWBAT           0x00000004  // Low Battery Voltage Interrupt
                                            // Mask
#define HIB_IM_RTCALT0          0x00000001  // RTC Alert 0 Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RIS register.
//
//*****************************************************************************
#define HIB_RIS_VDDFAIL         0x00000080  // VDD Fail Raw Interrupt Status
#define HIB_RIS_RSTWK           0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_RIS_PADIOWK         0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_RIS_WC              0x00000010  // Write Complete/Capable Raw
                                            // Interrupt Status
#define HIB_RIS_EXTW            0x00000008  // External Wake-Up Raw Interrupt
                                            // Status
#define HIB_RIS_LOWBAT          0x00000004  // Low Battery Voltage Raw
                                            // Interrupt Status
#define HIB_RIS_RTCALT0         0x00000001  // RTC Alert 0 Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_MIS register.
//
//*****************************************************************************
#define HIB_MIS_VDDFAIL         0x00000080  // VDD Fail Interrupt Mask
#define HIB_MIS_RSTWK           0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_MIS_PADIOWK         0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_MIS_WC              0x00000010  // Write Complete/Capable Masked
                                            // Interrupt Status
#define HIB_MIS_EXTW            0x00000008  // External Wake-Up Masked
                                            // Interrupt Status
#define HIB_MIS_LOWBAT          0x00000004  // Low Battery Voltage Masked
                                            // Interrupt Status
#define HIB_MIS_RTCALT0         0x00000001  // RTC Alert 0 Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IC register.
//
//*****************************************************************************
#define HIB_IC_VDDFAIL          0x00000080  // VDD Fail Interrupt Clear
#define HIB_IC_RSTWK            0x00000040  // Reset Pad I/O Wake-Up Interrupt
                                            // Mask
#define HIB_IC_PADIOWK          0x00000020  // Pad I/O Wake-Up Interrupt Mask
#define HIB_IC_WC               0x00000010  // Write Complete/Capable Masked
                                            // Interrupt Clear
#define HIB_IC_EXTW             0x00000008  // External Wake-Up Masked
                                            // Interrupt Clear
#define HIB_IC_LOWBAT           0x00000004  // Low Battery Voltage Masked
                                            // Interrupt Clear
#define HIB_IC_RTCALT0          0x00000001  // RTC Alert0 Masked Interrupt
                                            // Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCT register.
//
//*****************************************************************************
#define HIB_RTCT_TRIM_M         0x0000FFFF  // RTC Trim Value
#define HIB_RTCT_TRIM_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_RTCSS register.
//
//*****************************************************************************
#define HIB_RTCSS_RTCSSM_M      0x7FFF0000  // RTC Sub Seconds Match
#define HIB_RTCSS_RTCSSC_M      0x00007FFF  // RTC Sub Seconds Count
#define HIB_RTCSS_RTCSSM_S      16
#define HIB_RTCSS_RTCSSC_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_IO register.
//
//*****************************************************************************
#define HIB_IO_IOWRC            0x80000000  // I/O Write Complete
#define HIB_IO_WURSTEN          0x00000010  // Reset Wake Source Enable
#define HIB_IO_WUUNLK           0x00000001  // I/O Wake Pad Configuration
                                            // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_DATA register.
//
//*****************************************************************************
#define HIB_DATA_RTD_M          0xFFFFFFFF  // Hibernation Module NV Data
#define HIB_DATA_RTD_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALCTL register.
//
//*****************************************************************************
#define HIB_CALCTL_CAL24        0x00000004  // Calendar Mode
#define HIB_CALCTL_CALEN        0x00000001  // RTC Calendar/Counter Mode Select

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CAL0 register.
//
//*****************************************************************************
#define HIB_CAL0_VALID          0x80000000  // Valid Calendar Load
#define HIB_CAL0_AMPM           0x00400000  // AM/PM Designation
#define HIB_CAL0_HR_M           0x001F0000  // Hours
#define HIB_CAL0_MIN_M          0x00003F00  // Minutes
#define HIB_CAL0_SEC_M          0x0000003F  // Seconds
#define HIB_CAL0_HR_S           16
#define HIB_CAL0_MIN_S          8
#define HIB_CAL0_SEC_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CAL1 register.
//
//*****************************************************************************
#define HIB_CAL1_VALID          0x80000000  // Valid Calendar Load
#define HIB_CAL1_DOW_M          0x07000000  // Day of Week
#define HIB_CAL1_YEAR_M         0x007F0000  // Year Value
#define HIB_CAL1_MON_M          0x00000F00  // Month
#define HIB_CAL1_DOM_M          0x0000001F  // Day of Month
#define HIB_CAL1_DOW_S          24
#define HIB_CAL1_YEAR_S         16
#define HIB_CAL1_MON_S          8
#define HIB_CAL1_DOM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALLD0 register.
//
//*****************************************************************************
#define HIB_CALLD0_AMPM         0x00400000  // AM/PM Designation
#define HIB_CALLD0_HR_M         0x001F0000  // Hours
#define HIB_CALLD0_MIN_M        0x00003F00  // Minutes
#define HIB_CALLD0_SEC_M        0x0000003F  // Seconds
#define HIB_CALLD0_HR_S         16
#define HIB_CALLD0_MIN_S        8
#define HIB_CALLD0_SEC_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALLD1 register.
//
//*****************************************************************************
#define HIB_CALLD1_DOW_M        0x07000000  // Day of Week
#define HIB_CALLD1_YEAR_M       0x007F0000  // Year Value
#define HIB_CALLD1_MON_M        0x00000F00  // Month
#define HIB_CALLD1_DOM_M        0x0000001F  // Day of Month
#define HIB_CALLD1_DOW_S        24
#define HIB_CALLD1_YEAR_S       16
#define HIB_CALLD1_MON_S        8
#define HIB_CALLD1_DOM_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALM0 register.
//
//*****************************************************************************
#define HIB_CALM0_AMPM          0x00400000  // AM/PM Designation
#define HIB_CALM0_HR_M          0x001F0000  // Hours
#define HIB_CALM0_MIN_M         0x00003F00  // Minutes
#define HIB_CALM0_SEC_M         0x0000003F  // Seconds
#define HIB_CALM0_HR_S          16
#define HIB_CALM0_MIN_S         8
#define HIB_CALM0_SEC_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CALM1 register.
//
//*****************************************************************************
#define HIB_CALM1_DOM_M         0x0000001F  // Day of Month
#define HIB_CALM1_DOM_S         0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_LOCK register.
//
//*****************************************************************************
#define HIB_LOCK_HIBLOCK_M      0xFFFFFFFF  // Hibernate Lock
#define HIB_LOCK_HIBLOCK_KEY    0xA3359554  // Hibernate Lock Key
#define HIB_LOCK_HIBLOCK_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPCTL register.
//
//*****************************************************************************
#define HIB_TPCTL_WAKE          0x00000800  // Wake from Hibernate on a Tamper
                                            // Event
#define HIB_TPCTL_MEMCLR_M      0x00000300  // HIB Memory Clear on Tamper Event
#define HIB_TPCTL_MEMCLR_NONE   0x00000000  // Do not Clear HIB memory on
                                            // tamper event
#define HIB_TPCTL_MEMCLR_LOW32  0x00000100  // Clear Lower 32 Bytes of HIB
                                            // memory on tamper event
#define HIB_TPCTL_MEMCLR_HIGH32 0x00000200  // Clear upper 32 Bytes of HIB
                                            // memory on tamper event
#define HIB_TPCTL_MEMCLR_ALL    0x00000300  // Clear all HIB memory on tamper
                                            // event
#define HIB_TPCTL_TPCLR         0x00000010  // Tamper Event Clear
#define HIB_TPCTL_TPEN          0x00000001  // Tamper Module Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPSTAT register.
//
//*****************************************************************************
#define HIB_TPSTAT_STATE_M      0x0000000C  // Tamper Module Status
#define HIB_TPSTAT_STATE_DISABLED                                             \
                                0x00000000  // Tamper disabled
#define HIB_TPSTAT_STATE_CONFIGED                                             \
                                0x00000004  // Tamper configured
#define HIB_TPSTAT_STATE_ERROR  0x00000008  // Tamper event occurred
#define HIB_TPSTAT_XOSCST       0x00000002  // External Oscillator Status
#define HIB_TPSTAT_XOSCFAIL     0x00000001  // External Oscillator Failure

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPIO register.
//
//*****************************************************************************
#define HIB_TPIO_GFLTR3         0x08000000  // TPIO3 Glitch Filtering
#define HIB_TPIO_PUEN3          0x04000000  // TPIO3 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV3           0x02000000  // TPIO3 Trigger Level
#define HIB_TPIO_EN3            0x01000000  // TPIO3 Enable
#define HIB_TPIO_GFLTR2         0x00080000  // TPIO2 Glitch Filtering
#define HIB_TPIO_PUEN2          0x00040000  // TPIO2 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV2           0x00020000  // TPIO2 Trigger Level
#define HIB_TPIO_EN2            0x00010000  // TPIO2 Enable
#define HIB_TPIO_GFLTR1         0x00000800  // TPIO1 Glitch Filtering
#define HIB_TPIO_PUEN1          0x00000400  // TPIO1 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV1           0x00000200  // TPIO1 Trigger Level
#define HIB_TPIO_EN1            0x00000100  // TPIO1Enable
#define HIB_TPIO_GFLTR0         0x00000008  // TPIO0 Glitch Filtering
#define HIB_TPIO_PUEN0          0x00000004  // TPIO0 Internal Weak Pull-up
                                            // Enable
#define HIB_TPIO_LEV0           0x00000002  // TPIO0 Trigger Level
#define HIB_TPIO_EN0            0x00000001  // TPIO0 Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG0 register.
//
//*****************************************************************************
#define HIB_TPLOG0_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG0_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG1 register.
//
//*****************************************************************************
#define HIB_TPLOG1_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG1_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG1_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG1_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG1_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG2 register.
//
//*****************************************************************************
#define HIB_TPLOG2_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG2_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG3 register.
//
//*****************************************************************************
#define HIB_TPLOG3_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG3_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG3_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG3_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG3_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG4 register.
//
//*****************************************************************************
#define HIB_TPLOG4_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG4_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG5 register.
//
//*****************************************************************************
#define HIB_TPLOG5_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG5_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG5_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG5_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG5_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG6 register.
//
//*****************************************************************************
#define HIB_TPLOG6_TIME_M       0xFFFFFFFF  // Tamper Log Calendar Information
#define HIB_TPLOG6_TIME_S       0

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_TPLOG7 register.
//
//*****************************************************************************
#define HIB_TPLOG7_XOSC         0x00010000  // Status of external 32
#define HIB_TPLOG7_TRIG3        0x00000008  // Status of TPIO[3] Trigger
#define HIB_TPLOG7_TRIG2        0x00000004  // Status of TPIO[2] Trigger
#define HIB_TPLOG7_TRIG1        0x00000002  // Status of TPIO[1] Trigger
#define HIB_TPLOG7_TRIG0        0x00000001  // Status of TPIO[0] Trigger

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_PP register.
//
//*****************************************************************************
#define HIB_PP_TAMPER           0x00000002  // Tamper Pin Presence
#define HIB_PP_WAKENC           0x00000001  // Wake Pin Presence

//*****************************************************************************
//
// The following are defines for the bit fields in the HIB_CC register.
//
//*****************************************************************************
#define HIB_CC_SYSCLKEN         0x00000001  // System Clock Enable

#endif // __HW_HIBERNATE_H__
