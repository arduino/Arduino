//*****************************************************************************
//
// timer.h - Prototypes for the timer module
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
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_TIMER_H__
#define __DRIVERLIB_TIMER_H__

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
// Values that can be passed to TimerConfigure as the ui32Config parameter.
//
//*****************************************************************************
#define TIMER_CFG_ONE_SHOT       0x00000021  // Full-width one-shot timer
#define TIMER_CFG_ONE_SHOT_UP    0x00000031  // Full-width one-shot up-count
                                            // timer
#define TIMER_CFG_PERIODIC       0x00000022  // Full-width periodic timer
#define TIMER_CFG_PERIODIC_UP    0x00000032  // Full-width periodic up-count
                                            // timer
#define TIMER_CFG_RTC            0x01000000  // Full-width RTC timer
#define TIMER_CFG_SPLIT_PAIR     0x04000000  // Two half-width timers
#define TIMER_CFG_A_ONE_SHOT     0x00000021  // Timer A one-shot timer
#define TIMER_CFG_A_ONE_SHOT_UP  0x00000031  // Timer A one-shot up-count timer
#define TIMER_CFG_A_PERIODIC     0x00000022  // Timer A periodic timer
#define TIMER_CFG_A_PERIODIC_UP  0x00000032  // Timer A periodic up-count timer
#define TIMER_CFG_A_CAP_COUNT    0x00000003  // Timer A event counter
#define TIMER_CFG_A_CAP_COUNT_UP 0x00000013  // Timer A event up-counter
#define TIMER_CFG_A_CAP_TIME     0x00000007  // Timer A event timer
#define TIMER_CFG_A_CAP_TIME_UP  0x00000017  // Timer A event up-count timer
#define TIMER_CFG_A_PWM          0x0000000A  // Timer A PWM output
#define TIMER_CFG_B_ONE_SHOT     0x00002100  // Timer B one-shot timer
#define TIMER_CFG_B_ONE_SHOT_UP  0x00003100  // Timer B one-shot up-count timer
#define TIMER_CFG_B_PERIODIC     0x00002200  // Timer B periodic timer
#define TIMER_CFG_B_PERIODIC_UP  0x00003200  // Timer B periodic up-count timer
#define TIMER_CFG_B_CAP_COUNT    0x00000300  // Timer B event counter
#define TIMER_CFG_B_CAP_COUNT_UP 0x00001300  // Timer B event up-counter
#define TIMER_CFG_B_CAP_TIME     0x00000700  // Timer B event timer
#define TIMER_CFG_B_CAP_TIME_UP  0x00001700  // Timer B event up-count timer
#define TIMER_CFG_B_PWM          0x00000A00  // Timer B PWM output
#define TIMER_CFG_A_ACT_TOINTD   0x00010000  // Timer A compare action disable
                                             // time-out interrupt.
#define TIMER_CFG_A_ACT_NONE     0x00000000  // Timer A compare action none.
#define TIMER_CFG_A_ACT_TOGGLE   0x00020000  // Timer A compare action toggle.
#define TIMER_CFG_A_ACT_CLRTO    0x00040000  // Timer A compare action CCP
                                             // clear on time-out.
#define TIMER_CFG_A_ACT_SETTO    0x00060000  // Timer A compare action CCP set
                                             // on time-out.
#define TIMER_CFG_A_ACT_SETTOGTO 0x00080000  // Timer A compare action set CCP
                                             // toggle on time-out.
#define TIMER_CFG_A_ACT_CLRTOGTO 0x000A0000  // Timer A compare action clear
                                             // CCP toggle on time-out.
#define TIMER_CFG_A_ACT_SETCLRTO 0x000C0000  // Timer A compare action set CCP
                                             // clear on time-out.
#define TIMER_CFG_A_ACT_CLRSETTO 0x000E0000  // Timer A compare action clear
                                             // CCP set on time-out.
#define TIMER_CFG_B_ACT_TOINTD   0x00100000  // Timer B compare action disable
                                             // time-out interrupt.
#define TIMER_CFG_B_ACT_NONE     0x00000000  // Timer A compare action none.
#define TIMER_CFG_B_ACT_TOGGLE   0x00200000  // Timer A compare action toggle.
#define TIMER_CFG_B_ACT_CLRTO    0x00400000  // Timer A compare action CCP
                                             // clear on time-out.
#define TIMER_CFG_B_ACT_SETTO    0x00600000  // Timer A compare action CCP set
                                             // on time-out.
#define TIMER_CFG_B_ACT_SETTOGTO 0x00800000  // Timer A compare action set CCP
                                             // toggle on time-out.
#define TIMER_CFG_B_ACT_CLRTOGTO 0x00A00000  // Timer A compare action clear
                                             // CCP toggle on time-out.
#define TIMER_CFG_B_ACT_SETCLRTO 0x00C00000  // Timer A compare action set CCP
                                             // clear on time-out.
#define TIMER_CFG_B_ACT_CLRSETTO 0x0000E000  // Timer A compare action clear
                                             // CCP set on time-out.

//*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ui32IntFlags parameter, and returned from
// TimerIntStatus.
//
//*****************************************************************************
#define TIMER_TIMB_DMA          0x00002000 // TimerB DMA Complete Interrupt.
#define TIMER_TIMB_MATCH        0x00000800  // TimerB match interrupt
#define TIMER_CAPB_EVENT        0x00000400  // CaptureB event interrupt
#define TIMER_CAPB_MATCH        0x00000200  // CaptureB match interrupt
#define TIMER_TIMB_TIMEOUT      0x00000100  // TimerB time out interrupt
#define TIMER_TIMA_DMA          0x00000020 // TimerA DMA Complete Interrupt.
#define TIMER_TIMA_MATCH        0x00000010  // TimerA match interrupt
#define TIMER_RTC_MATCH         0x00000008  // RTC interrupt mask
#define TIMER_CAPA_EVENT        0x00000004  // CaptureA event interrupt
#define TIMER_CAPA_MATCH        0x00000002  // CaptureA match interrupt
#define TIMER_TIMA_TIMEOUT      0x00000001  // TimerA time out interrupt

//*****************************************************************************
//
// Values that can be passed to TimerControlEvent as the ui32Event parameter.
//
//*****************************************************************************
#define TIMER_EVENT_POS_EDGE    0x00000000  // Count positive edges
#define TIMER_EVENT_NEG_EDGE    0x00000404  // Count negative edges
#define TIMER_EVENT_BOTH_EDGES  0x00000C0C  // Count both edges

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32Timer
// parameter.
//
//*****************************************************************************
#define TIMER_A                 0x000000ff  // Timer A
#define TIMER_B                 0x0000ff00  // Timer B
#define TIMER_BOTH              0x0000ffff  // Timer Both

//*****************************************************************************
//
// Values that can be passed to TimerSynchronize as the ui32Timers parameter.
//
//*****************************************************************************
#define TIMER_0A_SYNC           0x00000001  // Synchronize Timer 0A
#define TIMER_0B_SYNC           0x00000002  // Synchronize Timer 0B
#define TIMER_1A_SYNC           0x00000004  // Synchronize Timer 1A
#define TIMER_1B_SYNC           0x00000008  // Synchronize Timer 1B
#define TIMER_2A_SYNC           0x00000010  // Synchronize Timer 2A
#define TIMER_2B_SYNC           0x00000020  // Synchronize Timer 2B
#define TIMER_3A_SYNC           0x00000040  // Synchronize Timer 3A
#define TIMER_3B_SYNC           0x00000080  // Synchronize Timer 3B
#define TIMER_4A_SYNC           0x00000100  // Synchronize Timer 4A
#define TIMER_4B_SYNC           0x00000200  // Synchronize Timer 4B
#define TIMER_5A_SYNC           0x00000400  // Synchronize Timer 5A
#define TIMER_5B_SYNC           0x00000800  // Synchronize Timer 5B
#define WTIMER_0A_SYNC          0x00001000  // Synchronize Wide Timer 0A
#define WTIMER_0B_SYNC          0x00002000  // Synchronize Wide Timer 0B
#define WTIMER_1A_SYNC          0x00004000  // Synchronize Wide Timer 1A
#define WTIMER_1B_SYNC          0x00008000  // Synchronize Wide Timer 1B
#define WTIMER_2A_SYNC          0x00010000  // Synchronize Wide Timer 2A
#define WTIMER_2B_SYNC          0x00020000  // Synchronize Wide Timer 2B
#define WTIMER_3A_SYNC          0x00040000  // Synchronize Wide Timer 3A
#define WTIMER_3B_SYNC          0x00080000  // Synchronize Wide Timer 3B
#define WTIMER_4A_SYNC          0x00100000  // Synchronize Wide Timer 4A
#define WTIMER_4B_SYNC          0x00200000  // Synchronize Wide Timer 4B
#define WTIMER_5A_SYNC          0x00400000  // Synchronize Wide Timer 5A
#define WTIMER_5B_SYNC          0x00800000  // Synchronize Wide Timer 5B

//*****************************************************************************
//
// Values that can be passed to TimerClockSourceSet() or returned from
// TimerClockSourceGet().
//
//*****************************************************************************
#define TIMER_CLOCK_SYSTEM      0x00000000
#define TIMER_CLOCK_PIOSC       0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerDMAEventSet() or returned from
// TimerDMAEventGet().
//
//*****************************************************************************
#define TIMER_DMA_MODEMATCH_B   0x00000800
#define TIMER_DMA_CAPEVENT_B    0x00000400
#define TIMER_DMA_CAPMATCH_B    0x00000200
#define TIMER_DMA_TIMEOUT_B     0x00000100
#define TIMER_DMA_MODEMATCH_A   0x00000010
#define TIMER_DMA_RTC_A         0x00000008
#define TIMER_DMA_CAPEVENT_A    0x00000004
#define TIMER_DMA_CAPMATCH_A    0x00000002
#define TIMER_DMA_TIMEOUT_A     0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerADCEventSet() or returned from
// TimerADCEventGet().
//
//*****************************************************************************
#define TIMER_ADC_MODEMATCH_B   0x00000800
#define TIMER_ADC_CAPEVENT_B    0x00000400
#define TIMER_ADC_CAPMATCH_B    0x00000200
#define TIMER_ADC_TIMEOUT_B     0x00000100
#define TIMER_ADC_MODEMATCH_A   0x00000010
#define TIMER_ADC_RTC_A         0x00000008
#define TIMER_ADC_CAPEVENT_A    0x00000004
#define TIMER_ADC_CAPMATCH_A    0x00000002
#define TIMER_ADC_TIMEOUT_A     0x00000001

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void TimerEnable(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerDisable(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerConfigure(uint32_t ui32Base, uint32_t ui32Config);
extern void TimerControlLevel(uint32_t ui32Base, uint32_t ui32Timer,
                              bool bInvert);
extern void TimerControlTrigger(uint32_t ui32Base, uint32_t ui32Timer,
                                bool bEnable);
extern void TimerControlEvent(uint32_t ui32Base, uint32_t ui32Timer,
                              uint32_t ui32Event);
extern void TimerControlStall(uint32_t ui32Base, uint32_t ui32Timer,
                              bool bStall);
extern void TimerControlWaitOnTrigger(uint32_t ui32Base, uint32_t ui32Timer,
                                      bool bWait);
extern void TimerRTCEnable(uint32_t ui32Base);
extern void TimerRTCDisable(uint32_t ui32Base);
extern void TimerPrescaleSet(uint32_t ui32Base, uint32_t ui32Timer,
                             uint32_t ui32Value);
extern uint32_t TimerPrescaleGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerPrescaleMatchSet(uint32_t ui32Base, uint32_t ui32Timer,
                                  uint32_t ui32Value);
extern uint32_t TimerPrescaleMatchGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerLoadSet(uint32_t ui32Base, uint32_t ui32Timer,
                         uint32_t ui32Value);
extern uint32_t TimerLoadGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerLoadSet64(uint32_t ui32Base, uint64_t ui64Value);
extern uint64_t TimerLoadGet64(uint32_t ui32Base);
extern uint32_t TimerValueGet(uint32_t ui32Base, uint32_t ui32Timer);
extern uint64_t TimerValueGet64(uint32_t ui32Base);
extern void TimerMatchSet(uint32_t ui32Base, uint32_t ui32Timer,
                          uint32_t ui32Value);
extern uint32_t TimerMatchGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerMatchSet64(uint32_t ui32Base, uint64_t ui64Value);
extern uint64_t TimerMatchGet64(uint32_t ui32Base);
extern void TimerIntRegister(uint32_t ui32Base, uint32_t ui32Timer,
                             void (*pfnHandler)(void));
extern void TimerIntUnregister(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void TimerIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern uint32_t TimerIntStatus(uint32_t ui32Base, bool bMasked);
extern void TimerIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void TimerSynchronize(uint32_t ui32Base, uint32_t ui32Timers);
extern uint32_t TimerClockSourceGet(uint32_t ui32Base);
extern void TimerClockSourceSet(uint32_t ui32Base, uint32_t ui32Source);
extern uint32_t TimerADCEventGet(uint32_t ui32Base);
extern void TimerADCEventSet(uint32_t ui32Base, uint32_t ui32ADCEvent);
extern uint32_t TimerDMAEventGet(uint32_t ui32Base);
extern void TimerDMAEventSet(uint32_t ui32Base, uint32_t ui32DMAEvent);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_TIMER_H__
