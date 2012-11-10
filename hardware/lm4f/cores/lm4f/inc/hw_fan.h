//*****************************************************************************
//
// hw_fan.h - Macros used when accessing the fan control hardware.
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

#ifndef __HW_FAN_H__
#define __HW_FAN_H__

//*****************************************************************************
//
// The following are defines for the Fan Control register offsets.
//
//*****************************************************************************
#define FAN_O_STS               0x00000000  // FAN Status
#define FAN_O_CTL               0x00000004  // FAN Control
#define FAN_O_CH0               0x00000010  // FAN Channel Setup
#define FAN_O_CMD0              0x00000014  // FAN Channel Command
#define FAN_O_CST0              0x00000018  // FAN Channel Status
#define FAN_O_CH1               0x00000020  // FAN Channel Setup
#define FAN_O_CMD1              0x00000024  // FAN Channel Command
#define FAN_O_CST1              0x00000028  // FAN Channel Status
#define FAN_O_CH2               0x00000030  // FAN Channel Setup
#define FAN_O_CMD2              0x00000034  // FAN Channel Command
#define FAN_O_CST2              0x00000038  // FAN Channel Status
#define FAN_O_CH3               0x00000040  // FAN Channel Setup
#define FAN_O_CMD3              0x00000044  // FAN Channel Command
#define FAN_O_CST3              0x00000048  // FAN Channel Status
#define FAN_O_CH4               0x00000050  // FAN Channel Setup
#define FAN_O_CMD4              0x00000054  // FAN Channel Command
#define FAN_O_CST4              0x00000058  // FAN Channel Status
#define FAN_O_CH5               0x00000060  // FAN Channel Setup
#define FAN_O_CMD5              0x00000064  // FAN Channel Command
#define FAN_O_CST5              0x00000068  // FAN Channel Status
#define FAN_O_CH6               0x00000070  // FAN Channel Setup
#define FAN_O_CMD6              0x00000074  // FAN Channel Command
#define FAN_O_CST6              0x00000078  // FAN Channel Status
#define FAN_O_CH7               0x00000080  // FAN Channel Setup
#define FAN_O_CMD7              0x00000084  // FAN Channel Command
#define FAN_O_CST7              0x00000088  // FAN Channel Status
#define FAN_O_IM                0x00000090  // FAN Interrupt Mask
#define FAN_O_RIS               0x00000094  // FAN Raw Interrupt Status
#define FAN_O_MIS               0x00000098  // FAN Masked Interrupt Status
#define FAN_O_IC                0x0000009C  // FAN Interrupt Clear
#define FAN_O_PP                0x00000FC0  // FAN Peripheral Properties

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_STS register.
//
//*****************************************************************************
#define FAN_STS_FANCNT_M        0x000F0000  // Fan Count
#define FAN_STS_ST5_M           0x00000C00  // Fan 5 Status
#define FAN_STS_ST5_STALLED     0x00000000  // Stalled
#define FAN_STS_ST5_CHANGING    0x00000400  // Changing
#define FAN_STS_ST5_LOCKED      0x00000800  // Locked
#define FAN_STS_ST5_NOATTAIN    0x00000C00  // No Attain
#define FAN_STS_ST4_M           0x00000300  // Fan 4 Status
#define FAN_STS_ST4_STALLED     0x00000000  // Stalled
#define FAN_STS_ST4_CHANGING    0x00000100  // Changing
#define FAN_STS_ST4_LOCKED      0x00000200  // Locked
#define FAN_STS_ST4_NOATTAIN    0x00000300  // No Attain
#define FAN_STS_ST3_M           0x000000C0  // Fan 3 Status
#define FAN_STS_ST3_STALLED     0x00000000  // Stalled
#define FAN_STS_ST3_CHANGING    0x00000040  // Changing
#define FAN_STS_ST3_LOCKED      0x00000080  // Locked
#define FAN_STS_ST3_NOATTAIN    0x000000C0  // No Attain
#define FAN_STS_ST2_M           0x00000030  // Fan 2 Status
#define FAN_STS_ST2_STALLED     0x00000000  // Stalled
#define FAN_STS_ST2_CHANGING    0x00000010  // Changing
#define FAN_STS_ST2_LOCKED      0x00000020  // Locked
#define FAN_STS_ST2_NOATTAIN    0x00000030  // No Attain
#define FAN_STS_ST1_M           0x0000000C  // Fan 1 Status
#define FAN_STS_ST1_STALLED     0x00000000  // Stalled
#define FAN_STS_ST1_CHANGING    0x00000004  // Changing
#define FAN_STS_ST1_LOCKED      0x00000008  // Locked
#define FAN_STS_ST1_NOATTAIN    0x0000000C  // No Attain
#define FAN_STS_ST0_M           0x00000003  // Fan 0 Status
#define FAN_STS_ST0_STALLED     0x00000000  // Stalled
#define FAN_STS_ST0_CHANGING    0x00000001  // Changing
#define FAN_STS_ST0_LOCKED      0x00000002  // Locked
#define FAN_STS_ST0_NOATTAIN    0x00000003  // No Attain
#define FAN_STS_FANCNT_S        16

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CTL register.
//
//*****************************************************************************
#define FAN_CTL_E5              0x00000020  // Fan 5 Enable
#define FAN_CTL_E4              0x00000010  // Fan 4 Enable
#define FAN_CTL_E3              0x00000008  // Fan 3 Enable
#define FAN_CTL_E2              0x00000004  // Fan 2 Enable
#define FAN_CTL_E1              0x00000002  // Fan 1 Enable
#define FAN_CTL_E0              0x00000001  // Fan 0 Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH0 register.
//
//*****************************************************************************
#define FAN_CH0_ASTART          0x00008000  // Auto Restart
#define FAN_CH0_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH0_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH0_STPER_M         0x00000700  // Start Period
#define FAN_CH0_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH0_START_NOFAST    0x00000000  // No fast start
#define FAN_CH0_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH0_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH0_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH0_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH0_AVG_0           0x00000000  // No averaging
#define FAN_CH0_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH0_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH0_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH0_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH0_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH0_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH0_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH0_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH0_MAN             0x00000001  // Control Type
#define FAN_CH0_HYST_S          11
#define FAN_CH0_STPER_S         8

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD0 register.
//
//*****************************************************************************
#define FAN_CMD0_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD0_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD0_DC_S           16
#define FAN_CMD0_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST0 register.
//
//*****************************************************************************
#define FAN_CST0_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST0_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST0_COUNT_S        16
#define FAN_CST0_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH1 register.
//
//*****************************************************************************
#define FAN_CH1_ASTART          0x00008000  // Auto Restart
#define FAN_CH1_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH1_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH1_STPER_M         0x00000700  // Start Period
#define FAN_CH1_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH1_START_NOFAST    0x00000000  // No fast start
#define FAN_CH1_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH1_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH1_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH1_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH1_AVG_0           0x00000000  // No averaging
#define FAN_CH1_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH1_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH1_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH1_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH1_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH1_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH1_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH1_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH1_MAN             0x00000001  // Control Type
#define FAN_CH1_HYST_S          11
#define FAN_CH1_STPER_S         8

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD1 register.
//
//*****************************************************************************
#define FAN_CMD1_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD1_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD1_DC_S           16
#define FAN_CMD1_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST1 register.
//
//*****************************************************************************
#define FAN_CST1_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST1_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST1_COUNT_S        16
#define FAN_CST1_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH2 register.
//
//*****************************************************************************
#define FAN_CH2_ASTART          0x00008000  // Auto Restart
#define FAN_CH2_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH2_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH2_STPER_M         0x00000700  // Start Period
#define FAN_CH2_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH2_START_NOFAST    0x00000000  // No fast start
#define FAN_CH2_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH2_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH2_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH2_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH2_AVG_0           0x00000000  // No averaging
#define FAN_CH2_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH2_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH2_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH2_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH2_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH2_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH2_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH2_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH2_MAN             0x00000001  // Control Type
#define FAN_CH2_HYST_S          11
#define FAN_CH2_STPER_S         8

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD2 register.
//
//*****************************************************************************
#define FAN_CMD2_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD2_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD2_DC_S           16
#define FAN_CMD2_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST2 register.
//
//*****************************************************************************
#define FAN_CST2_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST2_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST2_COUNT_S        16
#define FAN_CST2_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH3 register.
//
//*****************************************************************************
#define FAN_CH3_ASTART          0x00008000  // Auto Restart
#define FAN_CH3_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH3_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH3_STPER_M         0x00000700  // Start Period
#define FAN_CH3_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH3_START_NOFAST    0x00000000  // No fast start
#define FAN_CH3_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH3_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH3_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH3_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH3_AVG_0           0x00000000  // No averaging
#define FAN_CH3_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH3_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH3_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH3_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH3_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH3_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH3_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH3_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH3_MAN             0x00000001  // Control Type
#define FAN_CH3_HYST_S          11
#define FAN_CH3_STPER_S         8

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD3 register.
//
//*****************************************************************************
#define FAN_CMD3_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD3_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD3_DC_S           16
#define FAN_CMD3_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST3 register.
//
//*****************************************************************************
#define FAN_CST3_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST3_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST3_COUNT_S        16
#define FAN_CST3_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH4 register.
//
//*****************************************************************************
#define FAN_CH4_ASTART          0x00008000  // Auto Restart
#define FAN_CH4_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH4_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH4_STPER_M         0x00000700  // Start Period
#define FAN_CH4_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH4_START_NOFAST    0x00000000  // No fast start
#define FAN_CH4_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH4_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH4_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH4_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH4_AVG_0           0x00000000  // No averaging
#define FAN_CH4_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH4_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH4_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH4_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH4_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH4_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH4_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH4_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH4_MAN             0x00000001  // Control Type
#define FAN_CH4_HYST_S          11
#define FAN_CH4_STPER_S         8

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD4 register.
//
//*****************************************************************************
#define FAN_CMD4_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD4_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD4_DC_S           16
#define FAN_CMD4_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST4 register.
//
//*****************************************************************************
#define FAN_CST4_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST4_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST4_COUNT_S        16
#define FAN_CST4_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH5 register.
//
//*****************************************************************************
#define FAN_CH5_ASTART          0x00008000  // Auto Restart
#define FAN_CH5_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH5_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH5_STPER_M         0x00000700  // Start Period
#define FAN_CH5_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH5_START_NOFAST    0x00000000  // No fast start
#define FAN_CH5_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH5_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH5_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH5_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH5_AVG_0           0x00000000  // No averaging
#define FAN_CH5_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH5_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH5_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH5_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH5_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH5_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH5_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH5_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH5_MAN             0x00000001  // Control Type
#define FAN_CH5_HYST_S          11
#define FAN_CH5_STPER_S         8

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD5 register.
//
//*****************************************************************************
#define FAN_CMD5_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD5_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD5_DC_S           16
#define FAN_CMD5_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST5 register.
//
//*****************************************************************************
#define FAN_CST5_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST5_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST5_COUNT_S        16
#define FAN_CST5_RPM_S          0

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH6 register.
//
//*****************************************************************************
#define FAN_CH6_MAN             0x00000001  // Control Type
#define FAN_CH6_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH6_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH6_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH6_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH6_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH6_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH6_AVG_0           0x00000000  // No averaging
#define FAN_CH6_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH6_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH6_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH6_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH6_START_NOFAST    0x00000000  // No fast start
#define FAN_CH6_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH6_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH6_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH6_STPER_M         0x00000700  // Start Period
#define FAN_CH6_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH6_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH6_ASTART          0x00008000  // Auto Restart
#define FAN_CH6_STPER_S         8
#define FAN_CH6_HYST_S          11

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD6 register.
//
//*****************************************************************************
#define FAN_CMD6_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD6_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD6_RPM_S          0
#define FAN_CMD6_DC_S           16

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST6 register.
//
//*****************************************************************************
#define FAN_CST6_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST6_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST6_RPM_S          0
#define FAN_CST6_COUNT_S        16

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CH7 register.
//
//*****************************************************************************
#define FAN_CH7_MAN             0x00000001  // Control Type
#define FAN_CH7_PPR_M           0x0000000C  // Pulse per Revolution on
                                            // Tachometer
#define FAN_CH7_PPR_1           0x00000000  // 1 pulse per revolution
#define FAN_CH7_PPR_2           0x00000004  // 2 pulses per revolution
#define FAN_CH7_PPR_4           0x00000008  // 4 pulses per revolution
#define FAN_CH7_PPR_8           0x0000000C  // 8 pulses per revolution
#define FAN_CH7_AVG_M           0x00000030  // Averaging of Tachometer
#define FAN_CH7_AVG_0           0x00000000  // No averaging
#define FAN_CH7_AVG_2           0x00000010  // Average 2 edges
#define FAN_CH7_AVG_4           0x00000020  // Average 4 edges
#define FAN_CH7_AVG_8           0x00000030  // Average 8 edges
#define FAN_CH7_START_M         0x000000C0  // Fast Start Rule
#define FAN_CH7_START_NOFAST    0x00000000  // No fast start
#define FAN_CH7_START_50DC      0x00000040  // 50% duty cycle
#define FAN_CH7_START_75DC      0x00000080  // 75% duty cycle
#define FAN_CH7_START_100DC     0x000000C0  // 100% duty cycle
#define FAN_CH7_STPER_M         0x00000700  // Start Period
#define FAN_CH7_HYST_M          0x00003800  // Hysteresis Adjustment on PID
                                            // Adjust
#define FAN_CH7_ACCEL           0x00004000  // Acceleration and Deceleration
                                            // Rule
#define FAN_CH7_ASTART          0x00008000  // Auto Restart
#define FAN_CH7_STPER_S         8
#define FAN_CH7_HYST_S          11

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CMD7 register.
//
//*****************************************************************************
#define FAN_CMD7_RPM_M          0x00001FFF  // Fan Speed (in RPM)
#define FAN_CMD7_DC_M           0x01FF0000  // PWM Duty Cycle
#define FAN_CMD7_RPM_S          0
#define FAN_CMD7_DC_S           16

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_CST7 register.
//
//*****************************************************************************
#define FAN_CST7_RPM_M          0x00001FFF  // Last Read RPM Speed Computed
#define FAN_CST7_COUNT_M        0x07FF0000  // Last Read Tachometer Count
#define FAN_CST7_RPM_S          0
#define FAN_CST7_COUNT_S        16

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_IM register.
//
//*****************************************************************************
#define FAN_IM_C5INT1IM         0x00400000  // Channel 5 Interrupt 1 Mask
#define FAN_IM_C5INT0IM         0x00200000  // Channel 5 Interrupt 0 Mask
#define FAN_IM_C5STALLIM        0x00100000  // Channel 5 Stall Interrupt Mask
#define FAN_IM_C4INT1IM         0x00040000  // Channel 4 Interrupt 1 Mask
#define FAN_IM_C4INT0IM         0x00020000  // Channel 4 Interrupt 0 Mask
#define FAN_IM_C4STALLIM        0x00010000  // Channel 4 Stall Interrupt Mask
#define FAN_IM_C3INT1IM         0x00004000  // Channel 3 Interrupt 1 Mask
#define FAN_IM_C3INT0IM         0x00002000  // Channel 3 Interrupt 0 Mask
#define FAN_IM_C3STALLIM        0x00001000  // Channel 3 Stall Interrupt Mask
#define FAN_IM_C2INT1IM         0x00000400  // Channel 2 Interrupt 1 Mask
#define FAN_IM_C2INT0IM         0x00000200  // Channel 2 Interrupt 0 Mask
#define FAN_IM_C2STALLIM        0x00000100  // Channel 2 Stall Interrupt Mask
#define FAN_IM_C1INT1IM         0x00000040  // Channel 1 Interrupt 1 Mask
#define FAN_IM_C1INT0IM         0x00000020  // Channel 1 Interrupt 0 Mask
#define FAN_IM_C1STALLIM        0x00000010  // Channel 1 Stall Interrupt Mask
#define FAN_IM_C0INT1IM         0x00000004  // Channel 0 Interrupt 1 Mask
#define FAN_IM_C0INT0IM         0x00000002  // Channel 0 Interrupt 0 Mask
#define FAN_IM_C0STALLIM        0x00000001  // Channel 0 Stall Interrupt Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_RIS register.
//
//*****************************************************************************
#define FAN_RIS_C5INT1RIS       0x00400000  // Channel 5 Raw Interrupt 1 Status
#define FAN_RIS_C5INT0RIS       0x00200000  // Channel 5 Raw Interrupt 0 Status
#define FAN_RIS_C5STALLRIS      0x00100000  // Channel 5 Raw Stall Interrupt
                                            // Status
#define FAN_RIS_C4INT1RIS       0x00040000  // Channel 4 Raw Interrupt 1 Status
#define FAN_RIS_C4INT0RIS       0x00020000  // Channel 4 Raw Interrupt 0 Status
#define FAN_RIS_C4STALLRIS      0x00010000  // Channel 4 Raw Stall Interrupt
                                            // Status
#define FAN_RIS_C3INT1RIS       0x00004000  // Channel 3 Raw Interrupt 1 Status
#define FAN_RIS_C3INT0RIS       0x00002000  // Channel 3 Raw Interrupt 0 Status
#define FAN_RIS_C3STALLRIS      0x00001000  // Channel 3 Stall Raw Interrupt
                                            // Status
#define FAN_RIS_C2INT1RIS       0x00000400  // Channel 2 Raw Interrupt 1 Status
#define FAN_RIS_C2INT0RIS       0x00000200  // Channel 2 Raw Interrupt 0 Status
#define FAN_RIS_C2STALLRIS      0x00000100  // Channel 2 Stall Raw Interrupt
                                            // Status
#define FAN_RIS_C1INT1RIS       0x00000040  // Channel 1 Raw Interrupt 1 Status
#define FAN_RIS_C1INT0RIS       0x00000020  // Channel 1 Raw Interrupt 0 Status
#define FAN_RIS_C1STALLRIS      0x00000010  // Channel 1 Stall Raw Interrupt
                                            // Status
#define FAN_RIS_C0INT1RIS       0x00000004  // Channel 0 Raw Interrupt 1 Status
#define FAN_RIS_C0INT0RIS       0x00000002  // Channel 0 Raw Interrupt 0 Status
#define FAN_RIS_C0STALLRIS      0x00000001  // Channel 0 Stall Raw Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_MIS register.
//
//*****************************************************************************
#define FAN_MIS_C5INT1MIS       0x00400000  // Channel 5 Masked Interrupt 1
                                            // Status
#define FAN_MIS_C5INT0MIS       0x00200000  // Channel 5 Masked Interrupt 0
                                            // Status
#define FAN_MIS_C5STALLMIS      0x00100000  // Channel 5 Masked Stall Interrupt
                                            // Status
#define FAN_MIS_C4NT1MIS        0x00040000  // Channel 4 Masked Interrupt 1
                                            // Status
#define FAN_MIS_C4INT0MIS       0x00020000  // Channel 4 Masked Interrupt 0
                                            // Status
#define FAN_MIS_C4STALLMIS      0x00010000  // Channel 4 Masked Stall Interrupt
                                            // Status
#define FAN_MIS_C3INT1MIS       0x00004000  // Channel 3 Masked Interrupt 1
                                            // Status
#define FAN_MIS_C3INT0MIS       0x00002000  // Channel 3 Masked Interrupt 0
                                            // Status
#define FAN_MIS_C3STALLMIS      0x00001000  // Channel 3 Stall Masked Interrupt
                                            // Status
#define FAN_MIS_C2INT1MIS       0x00000400  // Channel 2 Masked Interrupt 1
                                            // Status
#define FAN_MIS_C2INT0MIS       0x00000200  // Channel 2 Masked Interrupt 0
                                            // Status
#define FAN_MIS_C2STALLMIS      0x00000100  // Channel 2 Stall Masked Interrupt
                                            // Status
#define FAN_MIS_C1INT1MIS       0x00000040  // Channel 1 Masked Interrupt 1
                                            // Status
#define FAN_MIS_C1INT0MIS       0x00000020  // Channel 1 Masked Interrupt 0
                                            // Status
#define FAN_MIS_C1STALLMIS      0x00000010  // Channel 1 Stall Masked Interrupt
                                            // Status
#define FAN_MIS_C0INT1MIS       0x00000004  // Channel 0 Masked Interrupt 1
                                            // Status
#define FAN_MIS_C0INT0MIS       0x00000002  // Channel 0 Masked Interrupt 0
                                            // Status
#define FAN_MIS_C0STALLMIS      0x00000001  // Channel 0 Stall Masked Interrupt
                                            // Status

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_IC register.
//
//*****************************************************************************
#define FAN_IC_C5INT1IC         0x00400000  // Channel 5 Interrupt 1 Clear
#define FAN_IC_C5INT0IC         0x00200000  // Channel 5 Interrupt 0 Clear
#define FAN_IC_C5STALLIC        0x00100000  // Channel 5 Stall Interrupt Clear
#define FAN_IC_C4INT1IC         0x00040000  // Channel 4 Interrupt 1 Clear
#define FAN_IC_C4INT0IC         0x00020000  // Channel 4 Interrupt 0 Clear
#define FAN_IC_C4STALLIC        0x00010000  // Channel 4 Stall Interrupt Clear
#define FAN_IC_C3INT1IC         0x00004000  // Channel 3 Interrupt 1 Clear
#define FAN_IC_C53INT0IC        0x00002000  // Channel 3 Interrupt 0 Clear
#define FAN_IC_C3STALLIC        0x00001000  // Channel 3 Stall Interrupt Clear
#define FAN_IC_C2INT1IC         0x00000400  // Channel 2 Interrupt 1 Clear
#define FAN_IC_C2INT0IC         0x00000200  // Channel 2 Interrupt 0 Clear
#define FAN_IC_C2STALLIC        0x00000100  // Channel 2 Stall Interrupt Clear
#define FAN_IC_C1INT1IC         0x00000040  // Channel 1 Interrupt 1 Clear
#define FAN_IC_C1INT0IC         0x00000020  // Channel 1 Interrupt 0 Clear
#define FAN_IC_C1STALLIC        0x00000010  // Channel 1 Stall Interrupt Clear
#define FAN_IC_C0INT1IC         0x00000004  // Channel 0 Interrupt 1 Clear
#define FAN_IC_C0INT0IC         0x00000002  // Channel 0 Interrupt 0 Clear
#define FAN_IC_C0STALLIC        0x00000001  // Channel 0 Stall Interrupt Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the FAN_O_PP register.
//
//*****************************************************************************
#define FAN_PP_CHAN_M           0x0000000F  // Channel Count
#define FAN_PP_CHAN_S           0

//*****************************************************************************
//
// The following definitions are deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED

//*****************************************************************************
//
// The following are deprecated defines for the bit fields in the FAN_O_STS
// register.
//
//*****************************************************************************
#define FAN_STS_ST5_UNBALANCED  0x00000C00  // Unbalanced Spin
#define FAN_STS_ST4_S           8
#define FAN_STS_ST3_S           6
#define FAN_STS_ST2_S           4
#define FAN_STS_ST1_S           2
#define FAN_STS_ST0_S           0

#endif

#endif // __HW_FAN_H__
