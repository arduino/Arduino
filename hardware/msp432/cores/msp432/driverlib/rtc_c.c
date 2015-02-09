/*
 * -------------------------------------------
 *    MSP432 DriverLib - v01_04_00_18 
 * -------------------------------------------
 *
 * --COPYRIGHT--,BSD,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
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
#include <rtc_c.h>
#include <interrupt.h>
#include <debug.h>

void RTC_C_startClock(void)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;
    BITBAND_PERI(RTC_C->rCTL13.r, RTCHOLD_OFS) = 0;
    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

void RTC_C_holdClock(void)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;
    BITBAND_PERI(RTC_C->rCTL13.r, RTCHOLD_OFS) = 1;
    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

void RTC_C_setCalibrationFrequency(uint_fast16_t frequencySelect)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;
    RTC_C->rCTL13.r = (RTC_C->rCTL13.r & ~(RTCCALF_3)) | frequencySelect;
    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

void RTC_C_setCalibrationData(uint_fast8_t offsetDirection,
        uint_fast8_t offsetValue)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;
    RTC_C->rOCAL.r = offsetValue + offsetDirection;
    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

bool RTC_C_setTemperatureCompensation(uint_fast16_t offsetDirection,
        uint_fast8_t offsetValue)
{
    while (!BITBAND_PERI(RTC_C->rTCMP.r, RTCTCRDY_OFS))
        ;

    RTC_C->rTCMP.r = offsetValue + offsetDirection;

    if (BITBAND_PERI(RTC_C->rTCMP.r, RTCTCOK_OFS))
        return true;
    else
        return false;
}

void RTC_C_initCalendar(const RTC_C_Calendar *calendarTime,
        uint_fast16_t formatSelect)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;

    BITBAND_PERI(RTC_C->rCTL13.r, RTCHOLD_OFS) = 1;

    if (formatSelect)
        BITBAND_PERI(RTC_C->rCTL13.r, RTCBCD_OFS) = 1;
    else
        BITBAND_PERI(RTC_C->rCTL13.r, RTCBCD_OFS) = 0;

    RTC_C->rTIM0.b.bSEC = calendarTime->seconds;
    RTC_C->rTIM0.b.bMIN = calendarTime->minutes;
    RTC_C->rTIM1.b.bHOUR = calendarTime->hours;
    RTC_C->rTIM1.b.bDOW = calendarTime->dayOfWeek;
    RTC_C->rDATE.b.bDAY = calendarTime->dayOfmonth;
    RTC_C->rDATE.b.bMON = calendarTime->month;
    RTC_C->rYEAR.r = calendarTime->year;

    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

RTC_C_Calendar RTC_C_getCalendarTime(void)
{
    RTC_C_Calendar tempCal;

    while (!(BITBAND_PERI(RTC_C->rCTL13.r, RTCRDY_OFS)))
        ;

    tempCal.seconds = RTC_C->rTIM0.b.bSEC;
    tempCal.minutes = RTC_C->rTIM0.b.bMIN;
    tempCal.hours = RTC_C->rTIM1.b.bHOUR;
    tempCal.dayOfWeek = RTC_C->rTIM1.b.bDOW;
    tempCal.dayOfmonth = RTC_C->rDATE.b.bDAY;
    tempCal.month = RTC_C->rDATE.b.bMON;
    tempCal.year = RTC_C->rYEAR.r;

    return (tempCal);
}

void RTC_C_setCalendarAlarm(uint_fast8_t minutesAlarm, uint_fast8_t hoursAlarm,
        uint_fast8_t dayOfWeekAlarm, uint_fast8_t dayOfmonthAlarm)
{
    //Each of these is XORed with 0x80 to turn on if an integer is passed,
    //or turn OFF if RTC_ALARM_OFF (0x80) is passed.
    HWREG8(RTC_C_BASE + OFS_RTCAMINHR) = (minutesAlarm ^ 0x80);
    HWREG8(RTC_C_BASE + OFS_RTCAMINHR + 1) = (hoursAlarm ^ 0x80);
    HWREG8(RTC_C_BASE + OFS_RTCADOWDAY) = (dayOfWeekAlarm ^ 0x80);
    HWREG8(RTC_C_BASE + OFS_RTCADOWDAY + 1) = (dayOfmonthAlarm ^ 0x80);
}

void RTC_C_setCalendarEvent(uint_fast16_t eventSelect)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;
    RTC_C->rCTL13.r = (RTC_C->rCTL13.r & ~(RTCTEV_3)) | eventSelect;
    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

void RTC_C_definePrescaleEvent(uint_fast8_t prescaleSelect,
        uint_fast8_t prescaleEventDivider)
{
    HWREG8(RTC_C_BASE + OFS_RTCPS0CTL + prescaleSelect) &= ~(RT0IP_7);
    HWREG8(RTC_C_BASE + OFS_RTCPS0CTL + prescaleSelect) |=
            prescaleEventDivider;
}

uint_fast8_t RTC_C_getPrescaleValue(uint_fast8_t prescaleSelect)
{
    if (RTC_C_PRESCALE_0 == prescaleSelect)
    {
        return (RTC_C->rPS.b.bRT0PS);
    } else if (RTC_C_PRESCALE_1 == prescaleSelect)
    {
        return (RTC_C->rPS.b.bRT1PS);
    } else
    {
        return (0);
    }
}

void RTC_C_setPrescaleValue(uint_fast8_t prescaleSelect,
        uint_fast8_t prescaleCounterValue)
{
    RTC_C->rCTL0.b.bKEY = RTCKEY_H;

    if (RTC_C_PRESCALE_0 == prescaleSelect)
    {
        RTC_C->rPS.b.bRT0PS = prescaleCounterValue;
    } else if (RTC_C_PRESCALE_1 == prescaleSelect)
    {
        RTC_C->rPS.b.bRT1PS = prescaleCounterValue;
    }

    BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
}

uint16_t RTC_C_convertBCDToBinary(uint16_t valueToConvert)
{
    RTC_C->rBCD2BIN = valueToConvert;
    return (RTC_C->rBCD2BIN);
}

uint16_t RTC_C_convertBinaryToBCD(uint16_t valueToConvert)
{
    RTC_C->rBIN2BCD = valueToConvert;
    return (RTC_C->rBIN2BCD);
}

void RTC_C_enableInterrupt(uint8_t interruptMask)
{
    if (interruptMask & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE))
    {
        RTC_C->rCTL0.r = RTCKEY | (interruptMask
                & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE));
        BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
    }

    if (interruptMask & RTC_C_PRESCALE_TIMER0_INTERRUPT)
    {
        BITBAND_PERI(RTC_C->rPS0CTL.r,RT0PSIE_OFS) = 1;
    }

    if (interruptMask & RTC_C_PRESCALE_TIMER1_INTERRUPT)
    {
        BITBAND_PERI(RTC_C->rPS1CTL.r,RT1PSIE_OFS) = 1;
    }
}

void RTC_C_disableInterrupt(uint8_t interruptMask)
{
    if (interruptMask & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE))
    {
        RTC_C->rCTL0.r = RTCKEY
                | (RTC_C->rCTL0.r
                        & ~((interruptMask | RTCKEY_M)
                                & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE)));
        BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
    }

    if (interruptMask & RTC_C_PRESCALE_TIMER0_INTERRUPT)
    {
        BITBAND_PERI(RTC_C->rPS0CTL.r,RT0PSIE_OFS) = 0;
    }

    if (interruptMask & RTC_C_PRESCALE_TIMER1_INTERRUPT)
    {
        BITBAND_PERI(RTC_C->rPS1CTL.r,RT1PSIE_OFS) = 0;
    }
}

uint_fast8_t RTC_C_getInterruptStatus(void)
{
    uint_fast8_t tempInterruptFlagMask = 0x00;
    uint_fast8_t interruptFlagMask = RTC_C_TIME_EVENT_INTERRUPT
            | RTC_C_CLOCK_ALARM_INTERRUPT | RTC_C_CLOCK_READ_READY_INTERRUPT
            | RTC_C_PRESCALE_TIMER0_INTERRUPT | RTC_C_PRESCALE_TIMER1_INTERRUPT
            | RTC_C_OSCILLATOR_FAULT_INTERRUPT;

    tempInterruptFlagMask |= (RTC_C->rCTL0.r & (interruptFlagMask >> 4));

    tempInterruptFlagMask = tempInterruptFlagMask << 4;

    if (interruptFlagMask & RTC_C_PRESCALE_TIMER0_INTERRUPT)
    {
        if (BITBAND_PERI(RTC_C->rPS0CTL.r, RT0PSIFG_OFS))
        {
            tempInterruptFlagMask |= RTC_C_PRESCALE_TIMER0_INTERRUPT;
        }
    }

    if (interruptFlagMask & RTC_C_PRESCALE_TIMER1_INTERRUPT)
    {
        if (BITBAND_PERI(RTC_C->rPS1CTL.r, RT1PSIFG_OFS))
        {
            tempInterruptFlagMask |= RTC_C_PRESCALE_TIMER1_INTERRUPT;
        }
    }

    return (tempInterruptFlagMask);
}

uint_fast8_t RTC_C_getEnabledInterruptStatus(void)
{

    uint32_t intStatus = RTC_C_getInterruptStatus();

    if (!BITBAND_PERI(RTC_C->rCTL0.r, RTCOFIE_OFS))
    {
        intStatus &= ~RTC_C_OSCILLATOR_FAULT_INTERRUPT;
    }

    if (!BITBAND_PERI(RTC_C->rCTL0.r, RTCTEVIE_OFS))
    {
        intStatus &= ~RTC_C_TIME_EVENT_INTERRUPT;
    }

    if (!BITBAND_PERI(RTC_C->rCTL0.r, RTCAIE_OFS))
    {
        intStatus &= ~RTC_C_CLOCK_ALARM_INTERRUPT;
    }

    if (!BITBAND_PERI(RTC_C->rCTL0.r, RTCRDYIE_OFS))
    {
        intStatus &= ~RTC_C_CLOCK_READ_READY_INTERRUPT;
    }

    if (!BITBAND_PERI(RTC_C->rPS0CTL, RT0PSIE_OFS))
    {
        intStatus &= ~RTC_C_PRESCALE_TIMER0_INTERRUPT;
    }

    if (!BITBAND_PERI(RTC_C->rPS1CTL.r, RT1PSIE_OFS))
    {
        intStatus &= ~RTC_C_PRESCALE_TIMER1_INTERRUPT;
    }

    return intStatus;
}

void RTC_C_clearInterruptFlag(uint_fast8_t interruptFlagMask)
{
    if (interruptFlagMask
            & (RTC_C_TIME_EVENT_INTERRUPT + RTC_C_CLOCK_ALARM_INTERRUPT
                    + RTC_C_CLOCK_READ_READY_INTERRUPT
                    + RTC_C_OSCILLATOR_FAULT_INTERRUPT))
    {
        RTC_C->rCTL0.r = RTCKEY
                | (RTC_C->rCTL0.r & ~((interruptFlagMask >> 4) | RTCKEY_M));
        BITBAND_PERI(RTC_C->rCTL0.r, RTCKEY_OFS) = 0;
    }

    if (interruptFlagMask & RTC_C_PRESCALE_TIMER0_INTERRUPT)
    {
        BITBAND_PERI(RTC_C->rPS0CTL.r,RT0PSIFG_OFS) = 0;
    }

    if (interruptFlagMask & RTC_C_PRESCALE_TIMER1_INTERRUPT)
    {
        BITBAND_PERI(RTC_C->rPS1CTL.r, RT1PSIFG_OFS) = 0;
    }
}

void RTC_C_registerInterrupt(void (*intHandler)(void))
{
    Interrupt_registerInterrupt(INT_RTC_C, intHandler);
    Interrupt_enableInterrupt(INT_RTC_C);
}

void RTC_C_unregisterInterrupt(void)
{
    Interrupt_disableInterrupt(INT_RTC_C);
    Interrupt_unregisterInterrupt(INT_RTC_C);
}

