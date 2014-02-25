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
// rtc_b.c - Driver for the rtc_b Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup rtc_b_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_RTC_B__
#include "rtc_b.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Starts the RTC.
//!
//! This function clears the RTC main hold bit to allow the RTC to function.
//!
//! \param baseAddress is the base address of the RTC_B module.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_startClock(uint32_t baseAddress)
{
        HWREG8(baseAddress + OFS_RTCCTL01_H) &= ~(RTCHOLD_H);
}

//*****************************************************************************
//
//! \brief Holds the RTC.
//!
//! This function sets the RTC main hold bit to disable RTC functionality.
//!
//! \param baseAddress is the base address of the RTC_B module.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_holdClock(uint32_t baseAddress)
{
        HWREG8(baseAddress + OFS_RTCCTL01_H) |= RTCHOLD_H;
}

//*****************************************************************************
//
//! \brief Allows and Sets the frequency output to RTCCLK pin for calibration
//! measurement.
//!
//! This function sets a frequency to measure at the RTCCLK output pin. After
//! testing the set frequency, the calibration could be set accordingly.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param frequencySelect is the frequency output to RTCCLK.
//!        Valid values are:
//!        - \b RTC_B_CALIBRATIONFREQ_OFF [Default] - turn off calibration
//!           output
//!        - \b RTC_B_CALIBRATIONFREQ_512HZ - output signal at 512Hz for
//!           calibration
//!        - \b RTC_B_CALIBRATIONFREQ_256HZ - output signal at 256Hz for
//!           calibration
//!        - \b RTC_B_CALIBRATIONFREQ_1HZ - output signal at 1Hz for
//!           calibration
//!        \n Modified bits are \b RTCCALF of \b RTCCTL3 register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_setCalibrationFrequency(uint32_t baseAddress,
                                   uint16_t frequencySelect)
{
        HWREG16(baseAddress + OFS_RTCCTL23) &= ~(RTCCALF_3);
        HWREG16(baseAddress + OFS_RTCCTL23) |= frequencySelect;
}

//*****************************************************************************
//
//! \brief Sets the specified calibration for the RTC.
//!
//! This function sets the calibration offset to make the RTC as accurate as
//! possible. The offsetDirection can be either +4-ppm or -2-ppm, and the
//! offsetValue should be from 1-63 and is multiplied by the direction setting
//! (i.e. +4-ppm * 8 (offsetValue) = +32-ppm). Please note, when measuring the
//! frequency after setting the calibration, you will only see a change on the
//! 1Hz frequency.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param offsetDirection is the direction that the calibration offset will
//!        go.
//!        Valid values are:
//!        - \b RTC_B_CALIBRATION_DOWN2PPM - calibrate at steps of -2
//!        - \b RTC_B_CALIBRATION_UP4PPM - calibrate at steps of +4
//!        \n Modified bits are \b RTCCALS of \b RTCCTL2 register.
//! \param offsetValue is the value that the offset will be a factor of; a
//!        valid value is any integer from 1-63.
//!        \n Modified bits are \b RTCCAL of \b RTCCTL2 register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_setCalibrationData(uint32_t baseAddress,
                              uint8_t offsetDirection,
                              uint8_t offsetValue)
{
        HWREG8(baseAddress + OFS_RTCCTL23_L) = offsetValue + offsetDirection;
}

//*****************************************************************************
//
//! \brief Initializes the settings to operate the RTC in calendar mode
//!
//! This function initializes the Calendar mode of the RTC module.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param CalendarTime is the pointer to the structure containing the values
//!        for the Calendar to be initialized to. Valid values should be of
//!        type pointer to Calendar and should contain the following members
//!        and corresponding values: \b Seconds between 0-59 \b Minutes between
//!        0-59 \b Hours between 0-24 \b DayOfWeek between 0-6 \b DayOfMonth
//!        between 0-31 \b Year between 0-4095 NOTE: Values beyond the ones
//!        specified may result in erratic behavior.
//! \param formatSelect is the format for the Calendar registers to use.
//!        Valid values are:
//!        - \b RTC_B_FORMAT_BINARY [Default]
//!        - \b RTC_B_FORMAT_BCD
//!        \n Modified bits are \b RTCBCD of \b RTCCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_initCalendar(uint32_t baseAddress,
                        Calendar *CalendarTime,
                        uint16_t formatSelect)
{
        HWREG8(baseAddress + OFS_RTCCTL01_H) |= RTCHOLD;

        HWREG16(baseAddress + OFS_RTCCTL01) &= ~(RTCBCD);
        HWREG16(baseAddress + OFS_RTCCTL01) |= formatSelect;

        HWREG8(baseAddress + OFS_RTCTIM0_L) = CalendarTime->Seconds;
        HWREG8(baseAddress + OFS_RTCTIM0_H) = CalendarTime->Minutes;
        HWREG8(baseAddress + OFS_RTCTIM1_L) = CalendarTime->Hours;
        HWREG8(baseAddress + OFS_RTCTIM1_H) = CalendarTime->DayOfWeek;
        HWREG8(baseAddress + OFS_RTCDATE_L) = CalendarTime->DayOfMonth;
        HWREG8(baseAddress + OFS_RTCDATE_H) = CalendarTime->Month;
        HWREG16(baseAddress + OFS_RTCYEAR) = CalendarTime->Year;
}

//*****************************************************************************
//
//! \brief Deprecated - Initializes the settings to operate the RTC in calendar
//! mode.
//!
//! This function initializes the Calendar mode of the RTC module.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param CalendarTime is the structure containing the values for the Calendar
//!        to be initialized to. Valid values should be of type Calendar and
//!        should contain the following members and corresponding values: \b
//!        Seconds between 0-59 \b Minutes between 0-59 \b Hours between 0-24
//!        \b DayOfWeek between 0-6 \b DayOfMonth between 0-31 \b Year between
//!        0-4095 NOTE: Values beyond the ones specified may result in erratic
//!        behavior.
//! \param formatSelect is the format for the Calendar registers to use.
//!        Valid values are:
//!        - \b RTC_B_FORMAT_BINARY [Default]
//!        - \b RTC_B_FORMAT_BCD
//!        \n Modified bits are \b RTCBCD of \b RTCCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_calendarInit(uint32_t baseAddress,
                        Calendar CalendarTime,
                        uint16_t formatSelect)
{
        HWREG8(baseAddress + OFS_RTCCTL01_H) |= RTCHOLD;

        HWREG16(baseAddress + OFS_RTCCTL01) &= ~(RTCBCD);
        HWREG16(baseAddress + OFS_RTCCTL01) |= formatSelect;

        HWREG8(baseAddress + OFS_RTCTIM0_L) = CalendarTime.Seconds;
        HWREG8(baseAddress + OFS_RTCTIM0_H) = CalendarTime.Minutes;
        HWREG8(baseAddress + OFS_RTCTIM1_L) = CalendarTime.Hours;
        HWREG8(baseAddress + OFS_RTCTIM1_H) = CalendarTime.DayOfWeek;
        HWREG8(baseAddress + OFS_RTCDATE_L) = CalendarTime.DayOfMonth;
        HWREG8(baseAddress + OFS_RTCDATE_H) = CalendarTime.Month;
        HWREG16(baseAddress + OFS_RTCYEAR) = CalendarTime.Year;
} //*****************************************************************************
//
//! \brief Returns the Calendar Time stored in the Calendar registers of the
//! RTC.
//!
//! This function returns the current Calendar time in the form of a Calendar
//! structure.
//!
//! \param baseAddress is the base address of the RTC_B module.
//!
//! \return A Calendar structure containing the current time.
//
//*****************************************************************************
Calendar RTC_B_getCalendarTime(uint32_t baseAddress)
{
        Calendar tempCal;

        while ( !(HWREG16(baseAddress + OFS_RTCCTL01) & RTCRDY) ) ;

        tempCal.Seconds    = HWREG8(baseAddress + OFS_RTCTIM0_L);
        tempCal.Minutes    = HWREG8(baseAddress + OFS_RTCTIM0_H);
        tempCal.Hours      = HWREG8(baseAddress + OFS_RTCTIM1_L);
        tempCal.DayOfWeek  = HWREG8(baseAddress + OFS_RTCTIM1_H);
        tempCal.DayOfMonth = HWREG8(baseAddress + OFS_RTCDATE_L);
        tempCal.Month      = HWREG8(baseAddress + OFS_RTCDATE_H);
        tempCal.Year       = HWREG16(baseAddress + OFS_RTCYEAR);

        return tempCal;
}

//*****************************************************************************
//
//! \brief Sets and Enables the desired Calendar Alarm settings.
//!
//! This function sets a Calendar interrupt condition to assert the RTCAIFG
//! interrupt flag. The condition is a logical and of all of the parameters.
//! For example if the minutes and hours alarm is set, then the interrupt will
//! only assert when the minutes AND the hours change to the specified setting.
//! Use the RTC_B_ALARM_OFF for any alarm settings that should not be apart of
//! the alarm condition.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param minutesAlarm is the alarm condition for the minutes.
//!        Valid values are:
//!        - \b RTC_B_ALARMCONDITION_OFF [Default]
//!        - \b An integer between 0-59
//! \param hoursAlarm is the alarm condition for the hours.
//!        Valid values are:
//!        - \b RTC_B_ALARMCONDITION_OFF [Default]
//!        - \b An integer between 0-24
//! \param dayOfWeekAlarm is the alarm condition for the day of week.
//!        Valid values are:
//!        - \b RTC_B_ALARMCONDITION_OFF [Default]
//!        - \b An integer between 0-6
//! \param dayOfMonthAlarm is the alarm condition for the day of the month.
//!        Valid values are:
//!        - \b RTC_B_ALARMCONDITION_OFF [Default]
//!        - \b An integer between 0-31
//!
//! \return None
//
//*****************************************************************************
void RTC_B_setCalendarAlarm(uint32_t baseAddress,
                            uint8_t minutesAlarm,
                            uint8_t hoursAlarm,
                            uint8_t dayOfWeekAlarm,
                            uint8_t dayOfMonthAlarm)
{
        //Each of these is XORed with 0x80 to turn on if an integer is passed,
        //or turn OFF if RTC_B_ALARM_OFF (0x80) is passed.
        HWREG8(baseAddress + OFS_RTCAMINHR_L) = (minutesAlarm ^ 0x80);
        HWREG8(baseAddress + OFS_RTCAMINHR_H) = (hoursAlarm ^ 0x80);
        HWREG8(baseAddress + OFS_RTCADOWDAY_L) = (dayOfWeekAlarm ^ 0x80);
        HWREG8(baseAddress + OFS_RTCADOWDAY_H) = (dayOfMonthAlarm ^ 0x80);
}

//*****************************************************************************
//
//! \brief Sets a single specified Calendar interrupt condition
//!
//! This function sets a specified event to assert the RTCTEVIFG interrupt.
//! This interrupt is independent from the Calendar alarm interrupt.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param eventSelect is the condition selected.
//!        Valid values are:
//!        - \b RTC_B_CALENDAREVENT_MINUTECHANGE - assert interrupt on every
//!           minute
//!        - \b RTC_B_CALENDAREVENT_HOURCHANGE - assert interrupt on every hour
//!        - \b RTC_B_CALENDAREVENT_NOON - assert interrupt when hour is 12
//!        - \b RTC_B_CALENDAREVENT_MIDNIGHT - assert interrupt when hour is 0
//!        \n Modified bits are \b RTCTEV of \b RTCCTL register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_setCalendarEvent(uint32_t baseAddress,
                            uint16_t eventSelect)
{
        HWREG16(baseAddress + OFS_RTCCTL01) &= ~(RTCTEV_3); //Reset bits
        HWREG16(baseAddress + OFS_RTCCTL01) |= eventSelect;
}

//*****************************************************************************
//
//! \brief Sets up an interrupt condition for the selected Prescaler.
//!
//! This function sets the condition for an interrupt to assert based on the
//! individual prescalers.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param prescaleSelect is the prescaler to define an interrupt for.
//!        Valid values are:
//!        - \b RTC_B_PRESCALE_0
//!        - \b RTC_B_PRESCALE_1
//! \param prescaleEventDivider is a divider to specify when an interrupt can
//!        occur based on the clock source of the selected prescaler. (Does not
//!        affect timer of the selected prescaler).
//!        Valid values are:
//!        - \b RTC_B_PSEVENTDIVIDER_2 [Default]
//!        - \b RTC_B_PSEVENTDIVIDER_4
//!        - \b RTC_B_PSEVENTDIVIDER_8
//!        - \b RTC_B_PSEVENTDIVIDER_16
//!        - \b RTC_B_PSEVENTDIVIDER_32
//!        - \b RTC_B_PSEVENTDIVIDER_64
//!        - \b RTC_B_PSEVENTDIVIDER_128
//!        - \b RTC_B_PSEVENTDIVIDER_256
//!        \n Modified bits are \b RTxIP of \b RTCPSxCTL register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_definePrescaleEvent(uint32_t baseAddress,
                               uint8_t prescaleSelect,
                               uint8_t prescaleEventDivider)
{
        HWREG8(baseAddress + OFS_RTCPS0CTL_L + prescaleSelect) &= ~(RT0IP_7);
        HWREG8(baseAddress + OFS_RTCPS0CTL_L +
               prescaleSelect) |= prescaleEventDivider;
}

//*****************************************************************************
//
//! \brief Returns the selected prescaler value.
//!
//! This function returns the value of the selected prescale counter register.
//! The counter should be held before reading. If in counter mode, the
//! individual prescaler can be held, while in Calendar mode the whole RTC must
//! be held.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param prescaleSelect is the prescaler to obtain the value of.
//!        Valid values are:
//!        - \b RTC_B_PRESCALE_0
//!        - \b RTC_B_PRESCALE_1
//!
//! \return The value of the specified prescaler count register
//
//*****************************************************************************
uint8_t RTC_B_getPrescaleValue(uint32_t baseAddress,
                               uint8_t prescaleSelect)
{
        if (RTC_B_PRESCALE_0 == prescaleSelect)
                return HWREG8(baseAddress + OFS_RTCPS_L);
        else if (RTC_B_PRESCALE_1 == prescaleSelect)
                return HWREG8(baseAddress + OFS_RTCPS_H);
        else
                return 0;
}

//*****************************************************************************
//
//! \brief Sets the selected prescaler value.
//!
//! This function sets the prescale counter value. Before setting the prescale
//! counter, it should be held.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param prescaleSelect is the prescaler to set the value for.
//!        Valid values are:
//!        - \b RTC_B_PRESCALE_0
//!        - \b RTC_B_PRESCALE_1
//! \param prescaleCounterValue is the specified value to set the prescaler to.
//!        Valid values are any integer between 0-255
//!        \n Modified bits are \b RTxPS of \b RTxPS register.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_setPrescaleCounterValue(uint32_t baseAddress,
                                   uint8_t prescaleSelect,
                                   uint8_t prescaleCounterValue)
{
        if (RTC_B_PRESCALE_0 == prescaleSelect)
                HWREG8(baseAddress + OFS_RTCPS_L) = prescaleCounterValue;
        else if (RTC_B_PRESCALE_1 == prescaleSelect)
                HWREG8(baseAddress + OFS_RTCPS_H) = prescaleCounterValue;
}

//*****************************************************************************
//
//! \brief Enables selected RTC interrupt sources.
//!
//! This function enables the selected RTC interrupt source.  Only the sources
//! that are enabled can be reflected to the processor interrupt; disabled
//! sources have no effect on the processor. Does not clear interrupt flags.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param interruptMask is a bit mask of the interrupts to enable.
//!        Mask value is the logical OR of any of the following:
//!        - \b RTC_B_TIME_EVENT_INTERRUPT - asserts when counter overflows in
//!           counter mode or when Calendar event condition defined by
//!           defineCalendarEvent() is met.
//!        - \b RTC_B_CLOCK_ALARM_INTERRUPT - asserts when alarm condition in
//!           Calendar mode is met.
//!        - \b RTC_B_CLOCK_READ_READY_INTERRUPT - asserts when Calendar
//!           registers are settled.
//!        - \b RTC_B_PRESCALE_TIMER0_INTERRUPT - asserts when Prescaler 0
//!           event condition is met.
//!        - \b RTC_B_PRESCALE_TIMER1_INTERRUPT - asserts when Prescaler 1
//!           event condition is met.
//!        - \b RTC_B_OSCILLATOR_FAULT_INTERRUPT - asserts if there is a
//!           problem with the 32kHz oscillator, while the RTC is running.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_enableInterrupt(uint32_t baseAddress,
                           uint8_t interruptMask)
{
        if ( interruptMask & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE) )
                HWREG8(baseAddress + OFS_RTCCTL01_L) |=
                        (interruptMask & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE));

        if (interruptMask & RTC_B_PRESCALE_TIMER0_INTERRUPT)
                HWREG8(baseAddress + OFS_RTCPS0CTL) |= RT0PSIE;

        if (interruptMask & RTC_B_PRESCALE_TIMER1_INTERRUPT)
                HWREG8(baseAddress + OFS_RTCPS1CTL) |= RT1PSIE;
}

//*****************************************************************************
//
//! \brief Disables selected RTC interrupt sources.
//!
//! This function disables the selected RTC interrupt source. Only the sources
//! that are enabled can be reflected to the processor interrupt; disabled
//! sources have no effect on the processor.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param interruptMask is a bit mask of the interrupts to disable.
//!        Mask value is the logical OR of any of the following:
//!        - \b RTC_B_TIME_EVENT_INTERRUPT - asserts when counter overflows in
//!           counter mode or when Calendar event condition defined by
//!           defineCalendarEvent() is met.
//!        - \b RTC_B_CLOCK_ALARM_INTERRUPT - asserts when alarm condition in
//!           Calendar mode is met.
//!        - \b RTC_B_CLOCK_READ_READY_INTERRUPT - asserts when Calendar
//!           registers are settled.
//!        - \b RTC_B_PRESCALE_TIMER0_INTERRUPT - asserts when Prescaler 0
//!           event condition is met.
//!        - \b RTC_B_PRESCALE_TIMER1_INTERRUPT - asserts when Prescaler 1
//!           event condition is met.
//!        - \b RTC_B_OSCILLATOR_FAULT_INTERRUPT - asserts if there is a
//!           problem with the 32kHz oscillator, while the RTC is running.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_disableInterrupt(uint32_t baseAddress,
                            uint8_t interruptMask)
{
        if ( interruptMask & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE) )
                HWREG8(baseAddress + OFS_RTCCTL01_L) &=
                        ~(interruptMask & (RTCOFIE + RTCTEVIE + RTCAIE + RTCRDYIE));

        if (interruptMask & RTC_B_PRESCALE_TIMER0_INTERRUPT)
                HWREG8(baseAddress + OFS_RTCPS0CTL) &= ~(RT0PSIE);

        if (interruptMask & RTC_B_PRESCALE_TIMER1_INTERRUPT)
                HWREG8(baseAddress + OFS_RTCPS1CTL) &= ~(RT1PSIE);
}

//*****************************************************************************
//
//! \brief Returns the status of the selected interrupts flags.
//!
//! This function returns the status of the interrupt flag for the selected
//! channel.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param interruptFlagMask is a bit mask of the interrupt flags to return the
//!        status of.
//!        Mask value is the logical OR of any of the following:
//!        - \b RTC_B_TIME_EVENT_INTERRUPT - asserts when counter overflows in
//!           counter mode or when Calendar event condition defined by
//!           defineCalendarEvent() is met.
//!        - \b RTC_B_CLOCK_ALARM_INTERRUPT - asserts when alarm condition in
//!           Calendar mode is met.
//!        - \b RTC_B_CLOCK_READ_READY_INTERRUPT - asserts when Calendar
//!           registers are settled.
//!        - \b RTC_B_PRESCALE_TIMER0_INTERRUPT - asserts when Prescaler 0
//!           event condition is met.
//!        - \b RTC_B_PRESCALE_TIMER1_INTERRUPT - asserts when Prescaler 1
//!           event condition is met.
//!        - \b RTC_B_OSCILLATOR_FAULT_INTERRUPT - asserts if there is a
//!           problem with the 32kHz oscillator, while the RTC is running.
//!
//! \return Logical OR of any of the following:
//!         - \b RTC_B_TIME_EVENT_INTERRUPT asserts when counter overflows in
//!         counter mode or when Calendar event condition defined by
//!         defineCalendarEvent() is met.
//!         - \b RTC_B_CLOCK_ALARM_INTERRUPT asserts when alarm condition in
//!         Calendar mode is met.
//!         - \b RTC_B_CLOCK_READ_READY_INTERRUPT asserts when Calendar
//!         registers are settled.
//!         - \b RTC_B_PRESCALE_TIMER0_INTERRUPT asserts when Prescaler 0 event
//!         condition is met.
//!         - \b RTC_B_PRESCALE_TIMER1_INTERRUPT asserts when Prescaler 1 event
//!         condition is met.
//!         - \b RTC_B_OSCILLATOR_FAULT_INTERRUPT asserts if there is a problem
//!         with the 32kHz oscillator, while the RTC is running.
//!         \n indicating the status of the masked interrupts
//
//*****************************************************************************
uint8_t RTC_B_getInterruptStatus(uint32_t baseAddress,
                                 uint8_t interruptFlagMask)
{
        uint8_t tempInterruptFlagMask = 0x0000;

        tempInterruptFlagMask |= (HWREG8(baseAddress + OFS_RTCCTL01_L)
                                  & ((interruptFlagMask >> 4)
                                     & (RTCOFIFG +
                                        RTCTEVIFG +
                                        RTCAIFG +
                                        RTCRDYIFG)));

        tempInterruptFlagMask = tempInterruptFlagMask << 4;

        if (interruptFlagMask & RTC_B_PRESCALE_TIMER0_INTERRUPT)
                if ( HWREG8(baseAddress + OFS_RTCPS0CTL) & RT0PSIFG)
                        tempInterruptFlagMask |= RTC_B_PRESCALE_TIMER0_INTERRUPT;

        if (interruptFlagMask & RTC_B_PRESCALE_TIMER1_INTERRUPT)
                if ( HWREG8(baseAddress + OFS_RTCPS1CTL) & RT1PSIFG)
                        tempInterruptFlagMask |= RTC_B_PRESCALE_TIMER1_INTERRUPT;

        return tempInterruptFlagMask;
}

//*****************************************************************************
//
//! \brief Clears selected RTC interrupt flags.
//!
//! This function clears the RTC interrupt flag is cleared, so that it no
//! longer asserts.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param interruptFlagMask is a bit mask of the interrupt flags to be
//!        cleared.
//!        Mask value is the logical OR of any of the following:
//!        - \b RTC_B_TIME_EVENT_INTERRUPT - asserts when counter overflows in
//!           counter mode or when Calendar event condition defined by
//!           defineCalendarEvent() is met.
//!        - \b RTC_B_CLOCK_ALARM_INTERRUPT - asserts when alarm condition in
//!           Calendar mode is met.
//!        - \b RTC_B_CLOCK_READ_READY_INTERRUPT - asserts when Calendar
//!           registers are settled.
//!        - \b RTC_B_PRESCALE_TIMER0_INTERRUPT - asserts when Prescaler 0
//!           event condition is met.
//!        - \b RTC_B_PRESCALE_TIMER1_INTERRUPT - asserts when Prescaler 1
//!           event condition is met.
//!        - \b RTC_B_OSCILLATOR_FAULT_INTERRUPT - asserts if there is a
//!           problem with the 32kHz oscillator, while the RTC is running.
//!
//! \return None
//
//*****************************************************************************
void RTC_B_clearInterrupt(uint32_t baseAddress,
                          uint8_t interruptFlagMask)
{
        if ( interruptFlagMask & (RTC_B_TIME_EVENT_INTERRUPT +
                                  RTC_B_CLOCK_ALARM_INTERRUPT +
                                  RTC_B_CLOCK_READ_READY_INTERRUPT +
                                  RTC_B_OSCILLATOR_FAULT_INTERRUPT) ) {

                HWREG8(baseAddress + OFS_RTCCTL01_L) &=
                        ~((interruptFlagMask >> 4) & (RTCOFIFG +
                                                      RTCTEVIFG +
                                                      RTCAIFG +
                                                      RTCRDYIFG));
        }

        if (interruptFlagMask & RTC_B_PRESCALE_TIMER0_INTERRUPT)
                HWREG8(baseAddress + OFS_RTCPS0CTL) &= ~(RT0PSIFG);

        if (interruptFlagMask & RTC_B_PRESCALE_TIMER1_INTERRUPT)
                HWREG8(baseAddress + OFS_RTCPS1CTL) &= ~(RT1PSIFG);
}

//*****************************************************************************
//
//! \brief Returns the given BCD value in Binary Format.
//!
//! This function converts BCD values to Binary format.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param valueToConvert is the raw value in BCD format to convert to Binary.
//!        \n Modified bits are \b BCD2BIN of \b BCD2BIN register.
//!
//! \return The Binary version of the valueToConvert parameter.
//
//*****************************************************************************
uint16_t RTC_B_convertBCDToBinary(uint32_t baseAddress,
                                  uint16_t valueToConvert)
{
        HWREG16(baseAddress + OFS_BCD2BIN) = valueToConvert;
        return HWREG16(baseAddress + OFS_BCD2BIN);
}

//*****************************************************************************
//
//! \brief Returns the given Binary value in BCD Format.
//!
//! This function converts Binary values to BCD format.
//!
//! \param baseAddress is the base address of the RTC_B module.
//! \param valueToConvert is the raw value in Binary format to convert to BCD.
//!        \n Modified bits are \b BIN2BCD of \b BIN2BCD register.
//!
//! \return The BCD version of the valueToConvert parameter.
//
//*****************************************************************************
uint16_t RTC_B_convertBinaryToBCD(uint32_t baseAddress,
                                  uint16_t valueToConvert)
{
        HWREG16(baseAddress + OFS_BIN2BCD) = valueToConvert;
        return HWREG16(baseAddress + OFS_BIN2BCD);
}


#endif
//*****************************************************************************
//
//! Close the doxygen group for rtc_b_api
//! @}
//
//*****************************************************************************

#endif
