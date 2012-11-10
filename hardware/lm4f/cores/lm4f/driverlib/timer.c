//*****************************************************************************
//
// timer.c - Driver for the timer module.
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

//*****************************************************************************
//
//! \addtogroup timer_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_timer.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

//*****************************************************************************
//
// A mapping of timer base address to interrupt number.
//
//*****************************************************************************
static const unsigned long g_ppulTimerIntMap[][2] =
{
    { TIMER0_BASE, INT_TIMER0A },
    { TIMER1_BASE, INT_TIMER1A },
    { TIMER2_BASE, INT_TIMER2A },
    { TIMER3_BASE, INT_TIMER3A },
    { TIMER4_BASE, INT_TIMER4A },
    { TIMER5_BASE, INT_TIMER5A },
    { WTIMER0_BASE, INT_WTIMER0A },
    { WTIMER1_BASE, INT_WTIMER1A },
    { WTIMER2_BASE, INT_WTIMER2A },
    { WTIMER3_BASE, INT_WTIMER3A },
    { WTIMER4_BASE, INT_WTIMER4A },
    { WTIMER5_BASE, INT_WTIMER5A },
};

//*****************************************************************************
//
//! \internal
//! Checks a timer base address.
//!
//! \param ulBase is the base address of the timer module.
//!
//! This function determines if a timer module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
TimerBaseValid(unsigned long ulBase)
{
    return((ulBase == TIMER0_BASE) || (ulBase == TIMER1_BASE) ||
           (ulBase == TIMER2_BASE) || (ulBase == TIMER3_BASE) ||
           (ulBase == TIMER4_BASE) || (ulBase == TIMER5_BASE) ||
           (ulBase == WTIMER0_BASE) || (ulBase == WTIMER1_BASE) ||
           (ulBase == WTIMER2_BASE) || (ulBase == WTIMER3_BASE) ||
           (ulBase == WTIMER4_BASE) || (ulBase == WTIMER5_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Gets the timer interrupt number.
//!
//! \param ulBase is the base address of the timer module.
//!
//! Given a timer base address, this function returns the corresponding
//! interrupt number.
//!
//! \return Returns a timer interrupt number, or -1 if \e ulBase is invalid.
//
//*****************************************************************************
static long
TimerIntNumberGet(unsigned long ulBase)
{
    unsigned long ulIdx;

    //
    // Loop through the table that maps timer base addresses to interrupt
    // numbers.
    //
    for(ulIdx = 0; ulIdx < (sizeof(g_ppulTimerIntMap) /
                            sizeof(g_ppulTimerIntMap[0])); ulIdx++)
    {
        //
        // See if this base address matches.
        //
        if(g_ppulTimerIntMap[ulIdx][0] == ulBase)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(g_ppulTimerIntMap[ulIdx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(-1);
}

//*****************************************************************************
//
//! Enables the timer(s).
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to enable; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//!
//! This function enables operation of the timer module.  The timer must be
//! configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
void
TimerEnable(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Enable the timer(s) module.
    //
    HWREG(ulBase + TIMER_O_CTL) |= ulTimer & (TIMER_CTL_TAEN | TIMER_CTL_TBEN);
}

//*****************************************************************************
//
//! Disables the timer(s).
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to disable; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//!
//! This function disables operation of the timer module.
//!
//! \return None.
//
//*****************************************************************************
void
TimerDisable(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Disable the timer module.
    //
    HWREG(ulBase + TIMER_O_CTL) &= ~(ulTimer &
                                     (TIMER_CTL_TAEN | TIMER_CTL_TBEN));
}

//*****************************************************************************
//
//! Configures the timer(s).
//!
//! \param ulBase is the base address of the timer module.
//! \param ulConfig is the configuration for the timer.
//!
//! This function configures the operating mode of the timer(s).  The timer
//! module is disabled before being configured and is left in the disabled
//! state.  The timer can be configured to be a single full-width timer
//! by using the \b TIMER_CFG_* values or a pair of half-width timers using the
//! \b TIMER_CFG_A_* and \b TIMER_CFG_B_* values passed in the \e ulConfig
//! parameter.
//!
//! The configuration is specified in \e ulConfig as one of the following
//! values:
//!
//! - \b TIMER_CFG_ONE_SHOT - Full-width one-shot timer
//! - \b TIMER_CFG_ONE_SHOT_UP - Full-width one-shot timer that counts up
//!   instead of down (not available on all parts)
//! - \b TIMER_CFG_PERIODIC - Full-width periodic timer
//! - \b TIMER_CFG_PERIODIC_UP - Full-width periodic timer that counts up
//!   instead of down (not available on all parts)
//! - \b TIMER_CFG_RTC - Full-width real time clock timer
//! - \b TIMER_CFG_SPLIT_PAIR - Two half-width timers
//!
//! When configured for a pair of half-width timers, each timer is separately
//! configured.  The first timer is configured by setting \e ulConfig to
//! the result of a logical OR operation between one of the following values
//! and \e ulConfig:
//!
//! - \b TIMER_CFG_A_ONE_SHOT - Half-width one-shot timer
//! - \b TIMER_CFG_A_ONE_SHOT_UP - Half-width one-shot timer that counts up
//!   instead of down (not available on all parts)
//! - \b TIMER_CFG_A_PERIODIC - Half-width periodic timer
//! - \b TIMER_CFG_A_PERIODIC_UP - Half-width periodic timer that counts up
//!   instead of down (not available on all parts)
//! - \b TIMER_CFG_A_CAP_COUNT - Half-width edge count capture
//! - \b TIMER_CFG_A_CAP_COUNT_UP - Half-width edge count capture that counts
//!   up instead of down (not available on all parts)
//! - \b TIMER_CFG_A_CAP_TIME - Half-width edge time capture
//! - \b TIMER_CFG_A_CAP_TIME_UP - Half-width edge time capture that counts up
//!   instead of down (not available on all parts)
//! - \b TIMER_CFG_A_PWM - Half-width PWM output
//!
//! Similarly, the second timer is configured by setting \e ulConfig to
//! the result of a logical OR operation between one of the corresponding
//! \b TIMER_CFG_B_* values and \e ulConfig.
//!
//! \return None.
//
//*****************************************************************************
void
TimerConfigure(unsigned long ulBase, unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulConfig == TIMER_CFG_ONE_SHOT) ||
           (ulConfig == TIMER_CFG_ONE_SHOT_UP) ||
           (ulConfig == TIMER_CFG_PERIODIC) ||
           (ulConfig == TIMER_CFG_PERIODIC_UP) ||
           (ulConfig == TIMER_CFG_RTC) ||
           ((ulConfig & 0xff000000) == TIMER_CFG_SPLIT_PAIR));
    ASSERT(((ulConfig & 0xff000000) != TIMER_CFG_SPLIT_PAIR) ||
           ((((ulConfig & 0x000000ff) == TIMER_CFG_A_ONE_SHOT) ||
             ((ulConfig & 0x000000ff) == TIMER_CFG_A_ONE_SHOT_UP) ||
             ((ulConfig & 0x000000ff) == TIMER_CFG_A_PERIODIC) ||
             ((ulConfig & 0x000000ff) == TIMER_CFG_A_PERIODIC_UP) ||
             ((ulConfig & 0x000000ff) == TIMER_CFG_A_CAP_COUNT) ||
             ((ulConfig & 0x000000ff) == TIMER_CFG_A_CAP_TIME) ||
             ((ulConfig & 0x000000ff) == TIMER_CFG_A_PWM)) &&
            (((ulConfig & 0x0000ff00) == TIMER_CFG_B_ONE_SHOT) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_ONE_SHOT_UP) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_PERIODIC) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_PERIODIC_UP) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_CAP_COUNT) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_CAP_COUNT_UP) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_CAP_TIME) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_CAP_TIME_UP) ||
             ((ulConfig & 0x0000ff00) == TIMER_CFG_B_PWM))));

    //
    // Disable the timers.
    //
    HWREG(ulBase + TIMER_O_CTL) &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);

    //
    // Set the global timer configuration.
    //
    HWREG(ulBase + TIMER_O_CFG) = ulConfig >> 24;

    //
    // Set the configuration of the A and B timers.  Note that the B timer
    // configuration is ignored by the hardware in 32-bit modes.
    //
    HWREG(ulBase + TIMER_O_TAMR) = (ulConfig & 255) | TIMER_TAMR_TAPWMIE;
    HWREG(ulBase + TIMER_O_TBMR) =
        ((ulConfig >> 8) & 255) | TIMER_TBMR_TBPWMIE;
}

//*****************************************************************************
//
//! Controls the output level.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to adjust; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//! \param bInvert specifies the output level.
//!
//! This function configures the PWM output level for the specified timer.  If
//! the \e bInvert parameter is \b true, then the timer's output is made active
//! low; otherwise, it is made active high.
//!
//! \return None.
//
//*****************************************************************************
void
TimerControlLevel(unsigned long ulBase, unsigned long ulTimer,
                  tBoolean bInvert)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the output levels as requested.
    //
    ulTimer &= TIMER_CTL_TAPWML | TIMER_CTL_TBPWML;
    HWREG(ulBase + TIMER_O_CTL) = (bInvert ?
                                   (HWREG(ulBase + TIMER_O_CTL) | ulTimer) :
                                   (HWREG(ulBase + TIMER_O_CTL) & ~(ulTimer)));
}

//*****************************************************************************
//
//! Enables or disables the ADC trigger output.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer to adjust; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//! \param bEnable specifies the desired ADC trigger state.
//!
//! This function controls the ADC trigger output for the specified timer.  If
//! the \e bEnable parameter is \b true, then the timer's ADC output trigger is
//! enabled; otherwise it is disabled.
//!
//! \return None.
//
//*****************************************************************************
void
TimerControlTrigger(unsigned long ulBase, unsigned long ulTimer,
                    tBoolean bEnable)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the trigger output as requested.
    // Set the ADC trigger output as requested.
    //
    ulTimer &= TIMER_CTL_TAOTE | TIMER_CTL_TBOTE;
    HWREG(ulBase + TIMER_O_CTL) = (bEnable ?
                                   (HWREG(ulBase + TIMER_O_CTL) | ulTimer) :
                                   (HWREG(ulBase + TIMER_O_CTL) & ~(ulTimer)));
}

//*****************************************************************************
//
//! Controls the event type.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to be adjusted; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//! \param ulEvent specifies the type of event; must be one of
//! \b TIMER_EVENT_POS_EDGE, \b TIMER_EVENT_NEG_EDGE, or
//! \b TIMER_EVENT_BOTH_EDGES.
//!
//! This function configures the signal edge(s) that triggers the timer when
//! in capture mode.
//!
//! \return None.
//
//*****************************************************************************
void
TimerControlEvent(unsigned long ulBase, unsigned long ulTimer,
                  unsigned long ulEvent)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the event type.
    //
    ulTimer &= TIMER_CTL_TAEVENT_M | TIMER_CTL_TBEVENT_M;
    HWREG(ulBase + TIMER_O_CTL) = ((HWREG(ulBase + TIMER_O_CTL) & ~ulTimer) |
                                   (ulEvent & ulTimer));
}

//*****************************************************************************
//
//! Controls the stall handling.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to be adjusted; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//! \param bStall specifies the response to a stall signal.
//!
//! This function controls the stall response for the specified timer.  If the
//! \e bStall parameter is \b true, then the timer stops counting if the
//! processor enters debug mode; otherwise the timer keeps running while in
//! debug mode.
//!
//! \return None.
//
//*****************************************************************************
void
TimerControlStall(unsigned long ulBase, unsigned long ulTimer,
                  tBoolean bStall)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the stall mode.
    //
    ulTimer &= TIMER_CTL_TASTALL | TIMER_CTL_TBSTALL;
    HWREG(ulBase + TIMER_O_CTL) = (bStall ?
                                   (HWREG(ulBase + TIMER_O_CTL) | ulTimer) :
                                   (HWREG(ulBase + TIMER_O_CTL) & ~(ulTimer)));
}

//*****************************************************************************
//
//! Controls the wait on trigger handling.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to be adjusted; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//! \param bWait specifies if the timer should wait for a trigger input.
//!
//! This function controls whether or not a timer waits for a trigger input to
//! start counting.  When enabled, the previous timer in the trigger chain must
//! count to its timeout in order for this timer to start counting.  Refer to
//! the part's data sheet for a description of the trigger chain.
//!
//! \note This functionality is not available on all parts.  This function
//! should not be used for Timer 0A or Wide Timer 0A.
//!
//! \return None.
//
//*****************************************************************************
void
TimerControlWaitOnTrigger(unsigned long ulBase, unsigned long ulTimer,
                          tBoolean bWait)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the wait on trigger mode for timer A.
    //
    if((ulTimer & TIMER_A) != 0)
    {
        if(bWait)
        {
            HWREG(ulBase + TIMER_O_TAMR) |= TIMER_TAMR_TAWOT;
        }
        else
        {
            HWREG(ulBase + TIMER_O_TAMR) &= ~(TIMER_TAMR_TAWOT);
        }
    }

    //
    // Set the wait on trigger mode for timer B.
    //
    if((ulTimer & TIMER_B) != 0)
    {
        if(bWait)
        {
            HWREG(ulBase + TIMER_O_TBMR) |= TIMER_TBMR_TBWOT;
        }
        else
        {
            HWREG(ulBase + TIMER_O_TBMR) &= ~(TIMER_TBMR_TBWOT);
        }
    }
}

//*****************************************************************************
//
//! Enable RTC counting.
//!
//! \param ulBase is the base address of the timer module.
//!
//! This function causes the timer to start counting when in RTC mode.  If not
//! configured for RTC mode, this function does nothing.
//!
//! \return None.
//
//*****************************************************************************
void
TimerRTCEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Enable RTC counting.
    //
    HWREG(ulBase + TIMER_O_CTL) |= TIMER_CTL_RTCEN;
}

//*****************************************************************************
//
//! Disable RTC counting.
//!
//! \param ulBase is the base address of the timer module.
//!
//! This function causes the timer to stop counting when in RTC mode.
//!
//! \return None.
//
//*****************************************************************************
void
TimerRTCDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Disable RTC counting.
    //
    HWREG(ulBase + TIMER_O_CTL) &= ~(TIMER_CTL_RTCEN);
}

//*****************************************************************************
//
//! Set the timer prescale value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to adjust; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//! \param ulValue is the timer prescale value which must be between 0 and 255
//! (inclusive) for 16/32-bit timers and between 0 and 65535 (inclusive) for
//! 32/64-bit timers.
//!
//! This function configures the value of the input clock prescaler.  The
//! prescaler is only operational when in half-width mode and is used to extend
//! the range of the half-width timer modes. The prescaler provides the least
//! significant bits when counting down in periodic and one-shot modes; in all
//! other modes, the prescaler provides the most significant bits.
//!
//! \note The availability of the prescaler varies with the Stellaris part and
//! timer mode in use.  Please consult the datasheet for the part you are using
//! to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerPrescaleSet(unsigned long ulBase, unsigned long ulTimer,
                 unsigned long ulValue)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));
    ASSERT(ulValue < 256);

    //
    // Set the timer A prescaler if requested.
    //
    if(ulTimer & TIMER_A)
    {
        HWREG(ulBase + TIMER_O_TAPR) = ulValue;
    }

    //
    // Set the timer B prescaler if requested.
    //
    if(ulTimer & TIMER_B)
    {
        HWREG(ulBase + TIMER_O_TBPR) = ulValue;
    }
}

//*****************************************************************************
//
//! Get the timer prescale value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.
//!
//! This function gets the value of the input clock prescaler.  The prescaler
//! is only operational when in half-width mode and is used to extend the range
//! of the half-width timer modes. The prescaler provides the least significant
//! bits when counting down in periodic and one-shot modes; in all other modes,
//! the prescaler provides the most significant bits.
//!
//! \note The availability of the prescaler varies with the Stellaris part and
//! timer mode in use.  Please consult the datasheet for the part you are using
//! to determine whether this support is available.
//!
//! \return The value of the timer prescaler.
//
//*****************************************************************************
unsigned long
TimerPrescaleGet(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Return the appropriate prescale value.
    //
    return((ulTimer == TIMER_A) ? HWREG(ulBase + TIMER_O_TAPR) :
           HWREG(ulBase + TIMER_O_TBPR));
}

//*****************************************************************************
//
//! Set the timer prescale match value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to adjust; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//! \param ulValue is the timer prescale match value which must be between 0
//! and 255 (inclusive) for 16/32-bit timers and between 0 and 65535
//! (inclusive) for 32/64-bit timers.
//!
//! This function configures the value of the input clock prescaler match
//! value. When in a half-width mode that uses the counter match and the
//! prescaler, the prescale match effectively extends the range of the match.
//! The prescaler provides the least significant bits when counting down in
//! periodic and one-shot modes; in all other modes, the prescaler provides the
//! most significant bits.
//!
//! \note The availability of the prescaler match varies with the Stellaris
//! part and timer mode in use.  Please consult the datasheet for the part you
//! are using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerPrescaleMatchSet(unsigned long ulBase, unsigned long ulTimer,
                      unsigned long ulValue)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));
    ASSERT(ulValue < 256);

    //
    // Set the timer A prescale match if requested.
    //
    if(ulTimer & TIMER_A)
    {
        HWREG(ulBase + TIMER_O_TAPMR) = ulValue;
    }

    //
    // Set the timer B prescale match if requested.
    //
    if(ulTimer & TIMER_B)
    {
        HWREG(ulBase + TIMER_O_TBPMR) = ulValue;
    }
}

//*****************************************************************************
//
//! Get the timer prescale match value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.
//!
//! This function gets the value of the input clock prescaler match value.
//! When in a half-width mode that uses the counter match and prescaler, the
//! prescale match effectively extends the range of the match. The prescaler
//! provides the least significant bits when counting down in periodic and
//! one-shot modes; in all other modes, the prescaler provides the most
//! significant bits.
//!
//! \note The availability of the prescaler match varies with the Stellaris
//! part and timer mode in use.  Please consult the datasheet for the part you
//! are using to determine whether this support is available.
//!
//! \return The value of the timer prescale match.
//
//*****************************************************************************
unsigned long
TimerPrescaleMatchGet(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Return the appropriate prescale match value.
    //
    return((ulTimer == TIMER_A) ? HWREG(ulBase + TIMER_O_TAPMR) :
           HWREG(ulBase + TIMER_O_TBPMR));
}

//*****************************************************************************
//
//! Sets the timer load value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to adjust; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.  Only \b TIMER_A should be used when the
//! timer is configured for full-width operation.
//! \param ulValue is the load value.
//!
//! This function configures the timer load value; if the timer is running then
//! the value is immediately loaded into the timer.
//!
//! \note This function can be used for both full- and half-width modes of
//! 16/32-bit timers and for half-width modes of 32/64-bit timers.  Use
//! TimerLoadSet64() for full-width modes of 32/64-bit timers.
//!
//! \return None.
//
//*****************************************************************************
void
TimerLoadSet(unsigned long ulBase, unsigned long ulTimer,
             unsigned long ulValue)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the timer A load value if requested.
    //
    if(ulTimer & TIMER_A)
    {
        HWREG(ulBase + TIMER_O_TAILR) = ulValue;
    }

    //
    // Set the timer B load value if requested.
    //
    if(ulTimer & TIMER_B)
    {
        HWREG(ulBase + TIMER_O_TBILR) = ulValue;
    }
}

//*****************************************************************************
//
//! Gets the timer load value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.  Only \b TIMER_A should be used when the timer is configured
//! for full-width operation.
//!
//! This function gets the currently programmed interval load value for the
//! specified timer.
//!
//! \note This function can be used for both full- and half-width modes of
//! 16/32-bit timers and for half-width modes of 32/64-bit timers.  Use
//! TimerLoadGet64() for full-width modes of 32/64-bit timers.
//!
//! \return Returns the load value for the timer.
//
//*****************************************************************************
unsigned long
TimerLoadGet(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B));

    //
    // Return the appropriate load value.
    //
    return((ulTimer == TIMER_A) ? HWREG(ulBase + TIMER_O_TAILR) :
           HWREG(ulBase + TIMER_O_TBILR));
}

//*****************************************************************************
//
//! Sets the timer load value for a 64-bit timer.
//!
//! \param ulBase is the base address of the timer module.
//! \param ullValue is the load value.
//!
//! This function configures the timer load value for a 64-bit timer; if the
//! timer is running, then the value is immediately loaded into the timer.
//!
//! \return None.
//
//*****************************************************************************
void
TimerLoadSet64(unsigned long ulBase, unsigned long long ullValue)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Set the timer load value.  The upper 32-bits must be written before the
    // lower 32-bits in order to adhere to the hardware interlocks on the
    // 64-bit value.
    //
    HWREG(ulBase + TIMER_O_TBILR) = ullValue >> 32;
    HWREG(ulBase + TIMER_O_TAILR) = ullValue & 0xffffffff;
}

//*****************************************************************************
//
//! Gets the timer load value for a 64-bit timer.
//!
//! \param ulBase is the base address of the timer module.
//!
//! This function gets the currently programmed interval load value for the
//! specified 64-bit timer.
//!
//! \return Returns the load value for the timer.
//
//*****************************************************************************
unsigned long long
TimerLoadGet64(unsigned long ulBase)
{
    unsigned long ulHigh1, ulHigh2, ulLow;

    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Read the 64-bit load value.  A read of the low 32-bits is performed
    // between two reads of the upper 32-bits; if the upper 32-bit values match
    // then the 64-bit value is consistent.  If they do not match, then the
    // read is performed again until they do match (it should never execute the
    // loop body more than twice).
    //
    do
    {
        ulHigh1 = HWREG(ulBase + TIMER_O_TBILR);
        ulLow = HWREG(ulBase + TIMER_O_TAILR);
        ulHigh2 = HWREG(ulBase + TIMER_O_TBILR);
    }
    while(ulHigh1 != ulHigh2);

    //
    // Return the load value.
    //
    return(((unsigned long long)ulHigh1 << 32) | (unsigned long long)ulLow);
}

//*****************************************************************************
//
//! Gets the current timer value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.  Only \b TIMER_A should be used when the timer is configured
//! for full-width operation.
//!
//! This function reads the current value of the specified timer.
//!
//! \note This function can be used for both full- and half-width modes of
//! 16/32-bit timers and for half-width modes of 32/64-bit timers.  Use
//! TimerValueGet64() for full-width modes of 32/64-bit timers.
//!
//! \return Returns the current value of the timer.
//
//*****************************************************************************
unsigned long
TimerValueGet(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B));

    //
    // Return the appropriate timer value.
    //
    return((ulTimer == TIMER_A) ? HWREG(ulBase + TIMER_O_TAR) :
           HWREG(ulBase + TIMER_O_TBR));
}

//*****************************************************************************
//
//! Gets the current 64-bit timer value.
//!
//! \param ulBase is the base address of the timer module.
//!
//! This function reads the current value of the specified timer.
//!
//! \return Returns the current value of the timer.
//
//*****************************************************************************
unsigned long long
TimerValueGet64(unsigned long ulBase)
{
    unsigned long ulHigh1, ulHigh2, ulLow;

    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Read the 64-bit timer value.  A read of the low 32-bits is performed
    // between two reads of the upper 32-bits; if the upper 32-bit values match
    // then the 64-bit value is consistent.  If they do not match, then the
    // read is performed again until they do match (it should never execute the
    // loop body more than twice).
    //
    do
    {
        ulHigh1 = HWREG(ulBase + TIMER_O_TBR);
        ulLow = HWREG(ulBase + TIMER_O_TAR);
        ulHigh2 = HWREG(ulBase + TIMER_O_TBR);
    }
    while(ulHigh1 != ulHigh2);

    //
    // Return the timer value.
    //
    return(((unsigned long long)ulHigh1 << 32) | (unsigned long long)ulLow);
}

//*****************************************************************************
//
//! Sets the timer match value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s) to adjust; must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.  Only \b TIMER_A should be used when the
//! timer is configured for full-width operation.
//! \param ulValue is the match value.
//!
//! This function configures the match value for a timer.  This value is used
//! in capture count mode to determine when to interrupt the processor and in
//! PWM mode to determine the duty cycle of the output signal. On some
//! Stellaris devices, match interrupts can also be generated in periodic and
//! one-shot modes.
//!
//! \note This function can be used for both full- and half-width modes of
//! 16/32-bit timers and for half-width modes of 32/64-bit timers.  Use
//! TimerMatchSet64() for full-width modes of 32/64-bit timers.
//!
//! \return None.
//
//*****************************************************************************
void
TimerMatchSet(unsigned long ulBase, unsigned long ulTimer,
              unsigned long ulValue)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Set the timer A match value if requested.
    //
    if(ulTimer & TIMER_A)
    {
        HWREG(ulBase + TIMER_O_TAMATCHR) = ulValue;
    }

    //
    // Set the timer B match value if requested.
    //
    if(ulTimer & TIMER_B)
    {
        HWREG(ulBase + TIMER_O_TBMATCHR) = ulValue;
    }
}

//*****************************************************************************
//
//! Gets the timer match value.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.  Only \b TIMER_A should be used when the timer is configured
//! for full-width operation.
//!
//! This function gets the match value for the specified timer.
//!
//! \note This function can be used for both full- and half-width modes of
//! 16/32-bit timers and for half-width modes of 32/64-bit timers.  Use
//! TimerMatchGet64() for full-width modes of 32/64-bit timers.
//!
//! \return Returns the match value for the timer.
//
//*****************************************************************************
unsigned long
TimerMatchGet(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B));

    //
    // Return the appropriate match value.
    //
    return((ulTimer == TIMER_A) ? HWREG(ulBase + TIMER_O_TAMATCHR) :
           HWREG(ulBase + TIMER_O_TBMATCHR));
}

//*****************************************************************************
//
//! Sets the timer match value for a 64-bit timer.
//!
//! \param ulBase is the base address of the timer module.
//! \param ullValue is the match value.
//!
//! This function configures the match value for a timer.  This value is used
//! in capture count mode to determine when to interrupt the processor and in
//! PWM mode to determine the duty cycle of the output signal.
//!
//! \return None.
//
//*****************************************************************************
void
TimerMatchSet64(unsigned long ulBase, unsigned long long ullValue)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Set the timer match value.  The upper 32-bits must be written before the
    // lower 32-bits in order to adhere to the hardware interlocks on the
    // 64-bit value.
    //
    HWREG(ulBase + TIMER_O_TBMATCHR) = ullValue >> 32;
    HWREG(ulBase + TIMER_O_TAMATCHR) = ullValue & 0xffffffff;
}

//*****************************************************************************
//
//! Gets the timer match value for a 64-bit timer.
//!
//! \param ulBase is the base address of the timer module.
//!
//! This function gets the match value for the specified timer.
//!
//! \return Returns the match value for the timer.
//
//*****************************************************************************
unsigned long long
TimerMatchGet64(unsigned long ulBase)
{
    unsigned long ulHigh1, ulHigh2, ulLow;

    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Read the 64-bit match value.  A read of the low 32-bits is performed
    // between two reads of the upper 32-bits; if the upper 32-bit values match
    // then the 64-bit value is consistent.  If they do not match, then the
    // read is performed again until they do match (it should never execute the
    // loop body more than twice).
    //
    do
    {
        ulHigh1 = HWREG(ulBase + TIMER_O_TBMATCHR);
        ulLow = HWREG(ulBase + TIMER_O_TAMATCHR);
        ulHigh2 = HWREG(ulBase + TIMER_O_TBMATCHR);
    }
    while(ulHigh1 != ulHigh2);

    //
    // Return the match value.
    //
    return(((unsigned long long)ulHigh1 << 32) | (unsigned long long)ulLow);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the timer interrupt.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s); must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//! \param pfnHandler is a pointer to the function to be called when the timer
//! interrupt occurs.
//!
//! This function registers the handler to be called when a timer interrupt
//! occurs. In addition, this function enables the global interrupt in the
//! interrupt controller; specific timer interrupts must be enabled via
//! TimerIntEnable(). It is the interrupt handler's responsibility to clear the
//! interrupt source via TimerIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntRegister(unsigned long ulBase, unsigned long ulTimer,
                 void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Get the interrupt number for this timer module.
    //
    ulBase = TimerIntNumberGet(ulBase);

    //
    // Register an interrupt handler for timer A if requested.
    //
    if(ulTimer & TIMER_A)
    {
        //
        // Register the interrupt handler.
        //
        IntRegister(ulBase, pfnHandler);

        //
        // Enable the interrupt.
        //
        IntEnable(ulBase);
    }

    //
    // Register an interrupt handler for timer B if requested.
    //
    if(ulTimer & TIMER_B)
    {
        //
        // Register the interrupt handler.
        //
        IntRegister(ulBase + 1, pfnHandler);

        //
        // Enable the interrupt.
        //
        IntEnable(ulBase + 1);
    }
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the timer interrupt.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulTimer specifies the timer(s); must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//!
//! This function unregisters the handler to be called when a timer interrupt
//! occurs.  This function also masks off the interrupt in the interrupt
//! controller so that the interrupt handler is no longer called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntUnregister(unsigned long ulBase, unsigned long ulTimer)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));
    ASSERT((ulTimer == TIMER_A) || (ulTimer == TIMER_B) ||
           (ulTimer == TIMER_BOTH));

    //
    // Get the interrupt number for this timer module.
    //
    ulBase = TimerIntNumberGet(ulBase);

    //
    // Unregister the interrupt handler for timer A if requested.
    //
    if(ulTimer & TIMER_A)
    {
        //
        // Disable the interrupt.
        //
        IntDisable(ulBase);

        //
        // Unregister the interrupt handler.
        //
        IntUnregister(ulBase);
    }

    //
    // Unregister the interrupt handler for timer B if requested.
    //
    if(ulTimer & TIMER_B)
    {
        //
        // Disable the interrupt.
        //
        IntDisable(ulBase + 1);

        //
        // Unregister the interrupt handler.
        //
        IntUnregister(ulBase + 1);
    }
}

//*****************************************************************************
//
//! Enables individual timer interrupt sources.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated timer interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter must be the logical OR of any combination of
//! the following:
//!
//! - \b TIMER_CAPB_EVENT  - Capture B event interrupt
//! - \b TIMER_CAPB_MATCH  - Capture B match interrupt
//! - \b TIMER_TIMB_TIMEOUT  - Timer B timeout interrupt
//! - \b TIMER_RTC_MATCH  - RTC interrupt mask
//! - \b TIMER_CAPA_EVENT  - Capture A event interrupt
//! - \b TIMER_CAPA_MATCH  - Capture A match interrupt
//! - \b TIMER_TIMA_TIMEOUT  - Timer A timeout interrupt
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Enable the specified interrupts.
    //
    HWREG(ulBase + TIMER_O_IMR) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual timer interrupt sources.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated timer interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to TimerIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + TIMER_O_IMR) &= ~(ulIntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase is the base address of the timer module.
//! \param bMasked is false if the raw interrupt status is required and true if
//! the masked interrupt status is required.
//!
//! This function returns the interrupt status for the timer module.  Either
//! the raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! values described in TimerIntEnable().
//
//*****************************************************************************
unsigned long
TimerIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    return(bMasked ? HWREG(ulBase + TIMER_O_MIS) :
           HWREG(ulBase + TIMER_O_RIS));
}

//*****************************************************************************
//
//! Clears timer interrupt sources.
//!
//! \param ulBase is the base address of the timer module.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified timer interrupt sources are cleared, so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupt from being triggered again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to TimerIntEnable().
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + TIMER_O_ICR) = ulIntFlags;
}

//*****************************************************************************
//
//! Synchronizes the counters in a set of timers.
//!
//! \param ulBase is the base address of the timer module.  This parameter must
//! be the base address of Timer0 (in other words, \b TIMER0_BASE).
//! \param ulTimers is the set of timers to synchronize.
//!
//! This function synchronizes the counters in a specified set of timers.
//! When a timer is running in half-width mode, each half can be included or
//! excluded in the synchronization event.  When a timer is running in
//! full-width mode, only the A timer can be synchronized (specifying the B
//! timer has no effect).
//!
//! The \e ulTimers parameter is the logical OR of any of the following
//! defines:
//!
//! - \b TIMER_0A_SYNC
//! - \b TIMER_0B_SYNC
//! - \b TIMER_1A_SYNC
//! - \b TIMER_1B_SYNC
//! - \b TIMER_2A_SYNC
//! - \b TIMER_2B_SYNC
//! - \b TIMER_3A_SYNC
//! - \b TIMER_3B_SYNC
//! - \b TIMER_4A_SYNC
//! - \b TIMER_4B_SYNC
//! - \b TIMER_5A_SYNC
//! - \b TIMER_5B_SYNC
//! - \b WTIMER_0A_SYNC
//! - \b WTIMER_0B_SYNC
//! - \b WTIMER_1A_SYNC
//! - \b WTIMER_1B_SYNC
//! - \b WTIMER_2A_SYNC
//! - \b WTIMER_2B_SYNC
//! - \b WTIMER_3A_SYNC
//! - \b WTIMER_3B_SYNC
//! - \b WTIMER_4A_SYNC
//! - \b WTIMER_4B_SYNC
//! - \b WTIMER_5A_SYNC
//! - \b WTIMER_5B_SYNC
//!
//! \note This functionality is not available on all parts.
//!
//! \return None.
//
//*****************************************************************************
void
TimerSynchronize(unsigned long ulBase, unsigned long ulTimers)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == TIMER0_BASE);

    //
    // Synchronize the specified timers.
    //
    HWREG(ulBase + TIMER_O_SYNC) = ulTimers;
}

//*****************************************************************************
//
// Puts the timer into its reset state.
//
// \param ulBase is the base address of the timer module.
//
// This function disables the specified timer, and all its interrupts are
// disabled, cleared, and unregistered.  Then the timer registers are set to
// their reset value.
//
// \return None.
//
//*****************************************************************************
#ifndef DEPRECATED
void
TimerQuiesce(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(TimerBaseValid(ulBase));

    //
    // Disable the timer.
    //
    HWREG(ulBase + TIMER_O_CTL) = TIMER_RV_CTL;

    //
    // Disable all the timer interrupts.
    //
    HWREG(ulBase + TIMER_O_IMR) = TIMER_RV_IMR;

    //
    // Clear all the timer interrupts.
    //
    HWREG(ulBase + TIMER_O_ICR) = 0xFFFFFFFF;

    //
    // Unregister the interrupt handler, which also disables interrupts to the
    // core.
    //
    TimerIntUnregister(ulBase, TIMER_BOTH);

    //
    // Set all the registers to their reset value.
    //
    HWREG(ulBase + TIMER_O_CFG) = TIMER_RV_CFG;
    HWREG(ulBase + TIMER_O_TAMR) = TIMER_RV_TAMR;
    HWREG(ulBase + TIMER_O_TBMR) = TIMER_RV_TBMR;
    HWREG(ulBase + TIMER_O_RIS) = TIMER_RV_RIS;
    HWREG(ulBase + TIMER_O_MIS) = TIMER_RV_MIS;
    HWREG(ulBase + TIMER_O_TAILR) = TIMER_RV_TAILR;
    HWREG(ulBase + TIMER_O_TBILR) = TIMER_RV_TBILR;
    HWREG(ulBase + TIMER_O_TAMATCHR) = TIMER_RV_TAMATCHR;
    HWREG(ulBase + TIMER_O_TBMATCHR) = TIMER_RV_TBMATCHR;
    HWREG(ulBase + TIMER_O_TAPR) = TIMER_RV_TAPR;
    HWREG(ulBase + TIMER_O_TBPR) = TIMER_RV_TBPR;
    HWREG(ulBase + TIMER_O_TAPMR) = TIMER_RV_TAPMR;
    HWREG(ulBase + TIMER_O_TBPMR) = TIMER_RV_TBPMR;
    HWREG(ulBase + TIMER_O_TAR) = TIMER_RV_TAR;
    HWREG(ulBase + TIMER_O_TBR) = TIMER_RV_TBR;
}
#endif // DEPRECATED

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
