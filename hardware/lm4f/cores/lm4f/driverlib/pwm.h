//*****************************************************************************
//
// pwm.h - API function protoypes for Pulse Width Modulation (PWM) ports
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
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __PWM_H__
#define __PWM_H__

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
// The following defines are passed to PWMGenConfigure() as the ulConfig
// parameter and specify the configuration of the PWM generator.
//
//*****************************************************************************
#define PWM_GEN_MODE_DOWN       0x00000000  // Down count mode
#define PWM_GEN_MODE_UP_DOWN    0x00000002  // Up/Down count mode
#define PWM_GEN_MODE_SYNC       0x00000038  // Synchronous updates
#define PWM_GEN_MODE_NO_SYNC    0x00000000  // Immediate updates
#define PWM_GEN_MODE_DBG_RUN    0x00000004  // Continue running in debug mode
#define PWM_GEN_MODE_DBG_STOP   0x00000000  // Stop running in debug mode
#define PWM_GEN_MODE_FAULT_LATCHED \
                                0x00040000  // Fault is latched
#define PWM_GEN_MODE_FAULT_UNLATCHED \
                                0x00000000  // Fault is not latched
#define PWM_GEN_MODE_FAULT_MINPER \
                                0x00020000  // Enable min fault period
#define PWM_GEN_MODE_FAULT_NO_MINPER \
                                0x00000000  // Disable min fault period
#define PWM_GEN_MODE_FAULT_EXT  0x00010000  // Enable extended fault support
#define PWM_GEN_MODE_FAULT_LEGACY \
                                0x00000000  // Disable extended fault support
#define PWM_GEN_MODE_DB_NO_SYNC 0x00000000  // Deadband updates occur
                                            // immediately
#define PWM_GEN_MODE_DB_SYNC_LOCAL \
                                0x0000A800  // Deadband updates locally
                                            // synchronized
#define PWM_GEN_MODE_DB_SYNC_GLOBAL \
                                0x0000FC00  // Deadband updates globally
                                            // synchronized
#define PWM_GEN_MODE_GEN_NO_SYNC \
                                0x00000000  // Generator mode updates occur
                                            // immediately
#define PWM_GEN_MODE_GEN_SYNC_LOCAL \
                                0x00000280  // Generator mode updates locally
                                            // synchronized
#define PWM_GEN_MODE_GEN_SYNC_GLOBAL \
                                0x000003C0  // Generator mode updates globally
                                            // synchronized

//*****************************************************************************
//
// Defines for enabling, disabling, and clearing PWM generator interrupts and
// triggers.
//
//*****************************************************************************
#define PWM_INT_CNT_ZERO        0x00000001  // Int if COUNT = 0
#define PWM_INT_CNT_LOAD        0x00000002  // Int if COUNT = LOAD
#define PWM_INT_CNT_AU          0x00000004  // Int if COUNT = CMPA U
#define PWM_INT_CNT_AD          0x00000008  // Int if COUNT = CMPA D
#define PWM_INT_CNT_BU          0x00000010  // Int if COUNT = CMPA U
#define PWM_INT_CNT_BD          0x00000020  // Int if COUNT = CMPA D
#define PWM_TR_CNT_ZERO         0x00000100  // Trig if COUNT = 0
#define PWM_TR_CNT_LOAD         0x00000200  // Trig if COUNT = LOAD
#define PWM_TR_CNT_AU           0x00000400  // Trig if COUNT = CMPA U
#define PWM_TR_CNT_AD           0x00000800  // Trig if COUNT = CMPA D
#define PWM_TR_CNT_BU           0x00001000  // Trig if COUNT = CMPA U
#define PWM_TR_CNT_BD           0x00002000  // Trig if COUNT = CMPA D

//*****************************************************************************
//
// Defines for enabling, disabling, and clearing PWM interrupts.
//
//*****************************************************************************
#define PWM_INT_GEN_0           0x00000001  // Generator 0 interrupt
#define PWM_INT_GEN_1           0x00000002  // Generator 1 interrupt
#define PWM_INT_GEN_2           0x00000004  // Generator 2 interrupt
#define PWM_INT_GEN_3           0x00000008  // Generator 3 interrupt
#ifndef DEPRECATED
#define PWM_INT_FAULT           0x00010000  // Fault interrupt
#endif
#define PWM_INT_FAULT0          0x00010000  // Fault0 interrupt
#define PWM_INT_FAULT1          0x00020000  // Fault1 interrupt
#define PWM_INT_FAULT2          0x00040000  // Fault2 interrupt
#define PWM_INT_FAULT3          0x00080000  // Fault3 interrupt
#define PWM_INT_FAULT_M         0x000F0000  // Fault interrupt source mask

//*****************************************************************************
//
// Defines to identify the generators within a module.
//
//*****************************************************************************
#define PWM_GEN_0               0x00000040  // Offset address of Gen0
#define PWM_GEN_1               0x00000080  // Offset address of Gen1
#define PWM_GEN_2               0x000000C0  // Offset address of Gen2
#define PWM_GEN_3               0x00000100  // Offset address of Gen3

#define PWM_GEN_0_BIT           0x00000001  // Bit-wise ID for Gen0
#define PWM_GEN_1_BIT           0x00000002  // Bit-wise ID for Gen1
#define PWM_GEN_2_BIT           0x00000004  // Bit-wise ID for Gen2
#define PWM_GEN_3_BIT           0x00000008  // Bit-wise ID for Gen3

#define PWM_GEN_EXT_0           0x00000800  // Offset of Gen0 ext address range
#define PWM_GEN_EXT_1           0x00000880  // Offset of Gen1 ext address range
#define PWM_GEN_EXT_2           0x00000900  // Offset of Gen2 ext address range
#define PWM_GEN_EXT_3           0x00000980  // Offset of Gen3 ext address range

//*****************************************************************************
//
// Defines to identify the outputs within a module.
//
//*****************************************************************************
#define PWM_OUT_0               0x00000040  // Encoded offset address of PWM0
#define PWM_OUT_1               0x00000041  // Encoded offset address of PWM1
#define PWM_OUT_2               0x00000082  // Encoded offset address of PWM2
#define PWM_OUT_3               0x00000083  // Encoded offset address of PWM3
#define PWM_OUT_4               0x000000C4  // Encoded offset address of PWM4
#define PWM_OUT_5               0x000000C5  // Encoded offset address of PWM5
#define PWM_OUT_6               0x00000106  // Encoded offset address of PWM6
#define PWM_OUT_7               0x00000107  // Encoded offset address of PWM7

#define PWM_OUT_0_BIT           0x00000001  // Bit-wise ID for PWM0
#define PWM_OUT_1_BIT           0x00000002  // Bit-wise ID for PWM1
#define PWM_OUT_2_BIT           0x00000004  // Bit-wise ID for PWM2
#define PWM_OUT_3_BIT           0x00000008  // Bit-wise ID for PWM3
#define PWM_OUT_4_BIT           0x00000010  // Bit-wise ID for PWM4
#define PWM_OUT_5_BIT           0x00000020  // Bit-wise ID for PWM5
#define PWM_OUT_6_BIT           0x00000040  // Bit-wise ID for PWM6
#define PWM_OUT_7_BIT           0x00000080  // Bit-wise ID for PWM7

//*****************************************************************************
//
// Defines to identify each of the possible fault trigger conditions in
// PWM_FAULT_GROUP_0.
//
//*****************************************************************************
#define PWM_FAULT_GROUP_0       0

#define PWM_FAULT_FAULT0        0x00000001
#define PWM_FAULT_FAULT1        0x00000002
#define PWM_FAULT_FAULT2        0x00000004
#define PWM_FAULT_FAULT3        0x00000008
#define PWM_FAULT_ACMP0         0x00010000
#define PWM_FAULT_ACMP1         0x00020000
#define PWM_FAULT_ACMP2         0x00040000

//*****************************************************************************
//
// Defines to identify each of the possible fault trigger conditions in
// PWM_FAULT_GROUP_1.
//
//*****************************************************************************
#define PWM_FAULT_GROUP_1       1

#define PWM_FAULT_DCMP0         0x00000001
#define PWM_FAULT_DCMP1         0x00000002
#define PWM_FAULT_DCMP2         0x00000004
#define PWM_FAULT_DCMP3         0x00000008
#define PWM_FAULT_DCMP4         0x00000010
#define PWM_FAULT_DCMP5         0x00000020
#define PWM_FAULT_DCMP6         0x00000040
#define PWM_FAULT_DCMP7         0x00000080

//*****************************************************************************
//
// Defines to identify the sense of each of the external FAULTn signals
//
//*****************************************************************************
#define PWM_FAULT0_SENSE_HIGH   0x00000000
#define PWM_FAULT0_SENSE_LOW    0x00000001
#define PWM_FAULT1_SENSE_HIGH   0x00000000
#define PWM_FAULT1_SENSE_LOW    0x00000002
#define PWM_FAULT2_SENSE_HIGH   0x00000000
#define PWM_FAULT2_SENSE_LOW    0x00000004
#define PWM_FAULT3_SENSE_HIGH   0x00000000
#define PWM_FAULT3_SENSE_LOW    0x00000008

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void PWMGenConfigure(unsigned long ulBase, unsigned long ulGen,
                            unsigned long ulConfig);
extern void PWMGenPeriodSet(unsigned long ulBase, unsigned long ulGen,
                            unsigned long ulPeriod);
extern unsigned long PWMGenPeriodGet(unsigned long ulBase,
                                     unsigned long ulGen);
extern void PWMGenEnable(unsigned long ulBase, unsigned long ulGen);
extern void PWMGenDisable(unsigned long ulBase, unsigned long ulGen);
extern void PWMPulseWidthSet(unsigned long ulBase, unsigned long ulPWMOut,
                             unsigned long ulWidth);
extern unsigned long PWMPulseWidthGet(unsigned long ulBase,
                                      unsigned long ulPWMOut);
extern void PWMDeadBandEnable(unsigned long ulBase, unsigned long ulGen,
                              unsigned short usRise, unsigned short usFall);
extern void PWMDeadBandDisable(unsigned long ulBase, unsigned long ulGen);
extern void PWMSyncUpdate(unsigned long ulBase, unsigned long ulGenBits);
extern void PWMSyncTimeBase(unsigned long ulBase, unsigned long ulGenBits);
extern void PWMOutputState(unsigned long ulBase, unsigned long ulPWMOutBits,
                           tBoolean bEnable);
extern void PWMOutputInvert(unsigned long ulBase, unsigned long ulPWMOutBits,
                            tBoolean bInvert);
extern void PWMOutputFaultLevel(unsigned long ulBase,
                                unsigned long ulPWMOutBits,
                                tBoolean bDriveHigh);
extern void PWMOutputFault(unsigned long ulBase, unsigned long ulPWMOutBits,
                           tBoolean bFaultSuppress);
extern void PWMGenIntRegister(unsigned long ulBase, unsigned long ulGen,
                              void (*pfnIntHandler)(void));
extern void PWMGenIntUnregister(unsigned long ulBase, unsigned long ulGen);
extern void PWMFaultIntRegister(unsigned long ulBase,
                                void (*pfnIntHandler)(void));
extern void PWMFaultIntUnregister(unsigned long ulBase);
extern void PWMGenIntTrigEnable(unsigned long ulBase, unsigned long ulGen,
                                unsigned long ulIntTrig);
extern void PWMGenIntTrigDisable(unsigned long ulBase, unsigned long ulGen,
                                 unsigned long ulIntTrig);
extern unsigned long PWMGenIntStatus(unsigned long ulBase, unsigned long ulGen,
                                     tBoolean bMasked);
extern void PWMGenIntClear(unsigned long ulBase, unsigned long ulGen,
                           unsigned long ulInts);
extern void PWMIntEnable(unsigned long ulBase, unsigned long ulGenFault);
extern void PWMIntDisable(unsigned long ulBase, unsigned long ulGenFault);
extern void PWMFaultIntClear(unsigned long ulBase);
extern unsigned long PWMIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void PWMFaultIntClearExt(unsigned long ulBase,
                                unsigned long ulFaultInts);
extern void PWMGenFaultConfigure(unsigned long ulBase, unsigned long ulGen,
                                 unsigned long ulMinFaultPeriod,
                                 unsigned long ulFaultSenses);
extern void PWMGenFaultTriggerSet(unsigned long ulBase, unsigned long ulGen,
                                  unsigned long ulGroup,
                                  unsigned long ulFaultTriggers);
extern unsigned long PWMGenFaultTriggerGet(unsigned long ulBase,
                                           unsigned long ulGen,
                                           unsigned long ulGroup);
extern unsigned long PWMGenFaultStatus(unsigned long ulBase,
                                       unsigned long ulGen,
                                       unsigned long ulGroup);
extern void PWMGenFaultClear(unsigned long ulBase, unsigned long ulGen,
                             unsigned long ulGroup,
                             unsigned long ulFaultTriggers);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __PWM_H__
