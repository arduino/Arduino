//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// rtc_b.h - Driver for the RTC_B Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_RTC_B_H__
#define __MSP430WARE_RTC_B_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_RTC_B__

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
// The following is a struct that can be passed to RTC_B_CalendarInit() in the
// CalendarTime parameter, as well as returned by RTC_B_getCalendarTime()
//
//*****************************************************************************
typedef struct {
        uint8_t Seconds;
        uint8_t Minutes;
        uint8_t Hours;
        uint8_t DayOfWeek;
        uint8_t DayOfMonth;
        uint8_t Month;
        uint16_t Year;
} Calendar;

//*****************************************************************************
//
// The following are values that can be passed to the frequencySelect parameter
// for functions: RTC_B_setCalibrationFrequency().
//
//*****************************************************************************
#define RTC_B_CALIBRATIONFREQ_OFF                                   (RTCCALF_0)
#define RTC_B_CALIBRATIONFREQ_512HZ                                 (RTCCALF_1)
#define RTC_B_CALIBRATIONFREQ_256HZ                                 (RTCCALF_2)
#define RTC_B_CALIBRATIONFREQ_1HZ                                   (RTCCALF_3)

//*****************************************************************************
//
// The following are values that can be passed to the offsetDirection parameter
// for functions: RTC_B_setCalibrationData().
//
//*****************************************************************************
#define RTC_B_CALIBRATION_DOWN2PPM                                 (!(RTCCALS))
#define RTC_B_CALIBRATION_UP4PPM                                      (RTCCALS)

//*****************************************************************************
//
// The following are values that can be passed to the formatSelect parameter
// for functions: RTC_B_initCalendar(), and RTC_B_calendarInit().
//
//*****************************************************************************
#define RTC_B_FORMAT_BINARY                                         (!(RTCBCD))
#define RTC_B_FORMAT_BCD                                               (RTCBCD)

//*****************************************************************************
//
// The following are values that can be passed to the minutesAlarm parameter
// for functions: RTC_B_setCalendarAlarm(); the dayOfMonthAlarm parameter for
// functions: RTC_B_setCalendarAlarm(); the hoursAlarm parameter for functions:
// RTC_B_setCalendarAlarm(); the dayOfWeekAlarm parameter for functions:
// RTC_B_setCalendarAlarm().
//
//*****************************************************************************
#define RTC_B_ALARMCONDITION_OFF                                         (0x80)

//*****************************************************************************
//
// The following are values that can be passed to the eventSelect parameter for
// functions: RTC_B_setCalendarEvent().
//
//*****************************************************************************
#define RTC_B_CALENDAREVENT_MINUTECHANGE                             (RTCTEV_0)
#define RTC_B_CALENDAREVENT_HOURCHANGE                               (RTCTEV_1)
#define RTC_B_CALENDAREVENT_NOON                                     (RTCTEV_2)
#define RTC_B_CALENDAREVENT_MIDNIGHT                                 (RTCTEV_3)

//*****************************************************************************
//
// The following are values that can be passed to the prescaleEventDivider
// parameter for functions: RTC_B_definePrescaleEvent().
//
//*****************************************************************************
#define RTC_B_PSEVENTDIVIDER_2                                        (RT0IP_0)
#define RTC_B_PSEVENTDIVIDER_4                                        (RT0IP_1)
#define RTC_B_PSEVENTDIVIDER_8                                        (RT0IP_2)
#define RTC_B_PSEVENTDIVIDER_16                                       (RT0IP_3)
#define RTC_B_PSEVENTDIVIDER_32                                       (RT0IP_4)
#define RTC_B_PSEVENTDIVIDER_64                                       (RT0IP_5)
#define RTC_B_PSEVENTDIVIDER_128                                      (RT0IP_6)
#define RTC_B_PSEVENTDIVIDER_256                                      (RT0IP_7)

//*****************************************************************************
//
// The following are values that can be passed to the prescaleSelect parameter
// for functions: RTC_B_definePrescaleEvent(), RTC_B_getPrescaleValue(), and
// RTC_B_setPrescaleCounterValue().
//
//*****************************************************************************
#define RTC_B_PRESCALE_0                                                  (0x0)
#define RTC_B_PRESCALE_1                                                  (0x2)

//*****************************************************************************
//
// The following are values that can be passed to the interruptMask parameter
// for functions: RTC_B_enableInterrupt(), and RTC_B_disableInterrupt(); the
// interruptFlagMask parameter for functions: RTC_B_getInterruptStatus(), and
// RTC_B_clearInterrupt() as well as returned by the RTC_B_getInterruptStatus()
// function.
//
//*****************************************************************************
#define RTC_B_TIME_EVENT_INTERRUPT                                     RTCTEVIE
#define RTC_B_CLOCK_ALARM_INTERRUPT                                      RTCAIE
#define RTC_B_CLOCK_READ_READY_INTERRUPT                               RTCRDYIE
#define RTC_B_PRESCALE_TIMER0_INTERRUPT                                    0x02
#define RTC_B_PRESCALE_TIMER1_INTERRUPT                                    0x01
#define RTC_B_OSCILLATOR_FAULT_INTERRUPT                                RTCOFIE

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void RTC_B_startClock(uint32_t baseAddress);

extern void RTC_B_holdClock(uint32_t baseAddress);

extern void RTC_B_setCalibrationFrequency(uint32_t baseAddress,
                                          uint16_t frequencySelect);

extern void RTC_B_setCalibrationData(uint32_t baseAddress,
                                     uint8_t offsetDirection,
                                     uint8_t offsetValue);

extern void RTC_B_initCalendar(uint32_t baseAddress,
                               Calendar *CalendarTime,
                               uint16_t formatSelect);

extern void RTC_B_calendarInit(uint32_t baseAddress,
                               Calendar CalendarTime,
                               uint16_t formatSelect);

extern Calendar RTC_B_getCalendarTime(uint32_t baseAddress);

extern void RTC_B_setCalendarAlarm(uint32_t baseAddress,
                                   uint8_t minutesAlarm,
                                   uint8_t hoursAlarm,
                                   uint8_t dayOfWeekAlarm,
                                   uint8_t dayOfMonthAlarm);

extern void RTC_B_setCalendarEvent(uint32_t baseAddress,
                                   uint16_t eventSelect);

extern void RTC_B_definePrescaleEvent(uint32_t baseAddress,
                                      uint8_t prescaleSelect,
                                      uint8_t prescaleEventDivider);

extern uint8_t RTC_B_getPrescaleValue(uint32_t baseAddress,
                                      uint8_t prescaleSelect);

extern void RTC_B_setPrescaleCounterValue(uint32_t baseAddress,
                                          uint8_t prescaleSelect,
                                          uint8_t prescaleCounterValue);

extern void RTC_B_enableInterrupt(uint32_t baseAddress,
                                  uint8_t interruptMask);

extern void RTC_B_disableInterrupt(uint32_t baseAddress,
                                   uint8_t interruptMask);

extern uint8_t RTC_B_getInterruptStatus(uint32_t baseAddress,
                                        uint8_t interruptFlagMask);

extern void RTC_B_clearInterrupt(uint32_t baseAddress,
                                 uint8_t interruptFlagMask);

extern uint16_t RTC_B_convertBCDToBinary(uint32_t baseAddress,
                                         uint16_t valueToConvert);

extern uint16_t RTC_B_convertBinaryToBCD(uint32_t baseAddress,
                                         uint16_t valueToConvert);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_RTC_B_H__

#endif
