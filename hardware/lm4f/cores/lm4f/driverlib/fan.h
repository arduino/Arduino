//*****************************************************************************
//
// fan.h - Prototypes and macros for the Fan controller.
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
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __FAN_H__
#define __FAN_H__

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
// Fan status values that can be returned from the FanChannelStatus() function.
//
//*****************************************************************************
#define FAN_STATUS_STALLED      0
#define FAN_STATUS_CHANGING     1
#define FAN_STATUS_LOCKED       2
#define FAN_STATUS_NOATTAIN     3

//*****************************************************************************
//
// Configuration flags to be used with FanChannelConfigManual() and
// FanChannelConfigAuto().
//
//*****************************************************************************
#define FAN_CONFIG_RESTART      (1 << 15)
#define FAN_CONFIG_NORESTART    (0 << 15)
#define FAN_CONFIG_ACCEL_FAST   (1 << 14)
#define FAN_CONFIG_ACCEL_SLOW   (0 << 14)
#define FAN_CONFIG_HYST_1       (0 << 11)
#define FAN_CONFIG_HYST_2       (1 << 11)
#define FAN_CONFIG_HYST_4       (2 << 11)
#define FAN_CONFIG_HYST_8       (3 << 11)
#define FAN_CONFIG_HYST_16      (4 << 11)
#define FAN_CONFIG_HYST_32      (5 << 11)
#define FAN_CONFIG_HYST_64      (6 << 11)
#define FAN_CONFIG_HYST_128     (7 << 11)
#define FAN_CONFIG_START_2      (0 << 8)
#define FAN_CONFIG_START_4      (1 << 8)
#define FAN_CONFIG_START_8      (2 << 8)
#define FAN_CONFIG_START_16     (3 << 8)
#define FAN_CONFIG_START_32     (4 << 8)
#define FAN_CONFIG_START_64     (5 << 8)
#define FAN_CONFIG_START_128    (6 << 8)
#define FAN_CONFIG_START_256    (7 << 8)
#define FAN_CONFIG_START_DUTY_OFF \
                                (0 << 6)
#define FAN_CONFIG_START_DUTY_50 \
                                (1 << 6)
#define FAN_CONFIG_START_DUTY_75 \
                                (2 << 6)
#define FAN_CONFIG_START_DUTY_100 \
                                (3 << 6)
#define FAN_CONFIG_AVG_NONE     (0 << 4)
#define FAN_CONFIG_AVG_2        (1 << 4)
#define FAN_CONFIG_AVG_4        (2 << 4)
#define FAN_CONFIG_AVG_8        (3 << 4)
#define FAN_CONFIG_TACH_1       (0 << 2)
#define FAN_CONFIG_TACH_2       (1 << 2)
#define FAN_CONFIG_TACH_4       (2 << 2)
#define FAN_CONFIG_TACH_8       (3 << 2)

//*****************************************************************************
//
// Interrupt configuration/status flags to be used with the following
// functions: FanIntEnable(), FanIntDisable(), FanIntStatus(), FanIntClear().
//
//*****************************************************************************
#define FAN_CH5_INT_AUTO_SPEED_OK \
                                (1 << 22)
#define FAN_CH5_INT_MANUAL_SPEED_CHANGE \
                                (1 << 22)
#define FAN_CH5_INT_AUTO_SPEED_ERROR \
                                (1 << 21)
#define FAN_CH5_INT_MANUAL_SPEED_UPDATE \
                                (1 << 21)
#define FAN_CH5_INT_STALL       (1 << 20)
#define FAN_CH4_INT_AUTO_SPEED_OK \
                                (1 << 18)
#define FAN_CH4_INT_MANUAL_SPEED_CHANGE \
                                (1 << 18)
#define FAN_CH4_INT_AUTO_SPEED_ERROR \
                                (1 << 17)
#define FAN_CH4_INT_MANUAL_SPEED_UPDATE \
                                (1 << 17)
#define FAN_CH4_INT_STALL       (1 << 16)
#define FAN_CH3_INT_AUTO_SPEED_OK \
                                (1 << 14)
#define FAN_CH3_INT_MANUAL_SPEED_CHANGE \
                                (1 << 14)
#define FAN_CH3_INT_AUTO_SPEED_ERROR \
                                (1 << 13)
#define FAN_CH3_INT_MANUAL_SPEED_UPDATE \
                                (1 << 13)
#define FAN_CH3_INT_STALL       (1 << 12)
#define FAN_CH2_INT_AUTO_SPEED_OK \
                                (1 << 10)
#define FAN_CH2_INT_MANUAL_SPEED_CHANGE \
                                (1 << 10)
#define FAN_CH2_INT_AUTO_SPEED_ERROR \
                                (1 << 9)
#define FAN_CH2_INT_MANUAL_SPEED_UPDATE \
                                (1 << 9)
#define FAN_CH2_INT_STALL       (1 << 8)
#define FAN_CH1_INT_AUTO_SPEED_OK \
                                (1 << 6)
#define FAN_CH1_INT_MANUAL_SPEED_CHANGE \
                                (1 << 6)
#define FAN_CH1_INT_AUTO_SPEED_ERROR \
                                (1 << 5)
#define FAN_CH1_INT_MANUAL_SPEED_UPDATE \
                                (1 << 5)
#define FAN_CH1_INT_STALL       (1 << 4)
#define FAN_CH0_INT_AUTO_SPEED_OK \
                                (1 << 2)
#define FAN_CH0_INT_MANUAL_SPEED_CHANGE \
                                (1 << 2)
#define FAN_CH0_INT_AUTO_SPEED_ERROR \
                                (1 << 1)
#define FAN_CH0_INT_MANUAL_SPEED_UPDATE \
                                (1 << 1)
#define FAN_CH0_INT_STALL       (1 << 0)
#define FAN_CHx_INT_AUTO_SPEED_OK(x) \
                                (1 << (((x) * 4) + 2))
#define FAN_CHx_INT_MANUAL_SPEED_CHANGE(x) \
                                (1 << (((x) * 4) + 2))
#define FAN_CHx_INT_AUTO_SPEED_ERROR(x) \
                                (1 << (((x) * 4) + 1))
#define FAN_CHx_INT_MANUAL_SPEED_UPDATE(x) \
                                (1 << (((x) * 4) + 1))
#define FAN_CHx_INT_STALL(x)    (1 << ((x) * 4))

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void FanChannelEnable(unsigned long ulBase, unsigned long ulChannel);
extern void FanChannelDisable(unsigned long ulBase, unsigned long ulChannel);
extern unsigned long FanChannelStatus(unsigned long ulBase,
                                      unsigned long ulChannel);
extern void FanChannelConfigManual(unsigned long ulBase, 
                                   unsigned long ulChannel,
                                   unsigned long ulConfig);
extern void FanChannelConfigAuto(unsigned long ulBase, unsigned long ulChannel,
                                 unsigned long ulConfig);
extern void FanChannelDutySet(unsigned long ulBase, unsigned long ulChannel,
                              unsigned long ulDuty);
extern unsigned long FanChannelDutyGet(unsigned long ulBase,
                                       unsigned long ulChannel);
extern void FanChannelRPMSet(unsigned long ulBase, unsigned long ulChannel,
                             unsigned long ulRPM);
extern unsigned long FanChannelRPMGet(unsigned long ulBase,
                                      unsigned long ulChannel);
extern void FanIntEnable(unsigned long ulBase, unsigned long ulFlags);
extern void FanIntDisable(unsigned long ulBase, unsigned long ulFlags);
extern unsigned long FanIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void FanIntClear(unsigned long ulBase, unsigned long ulFlags);
extern void FanIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void FanIntUnregister(unsigned long ulBase);
extern unsigned long FanChannelsGet(unsigned long ulBase);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __FAN_H__
