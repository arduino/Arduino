//*****************************************************************************
//
// timer.c - Driver for the timer module.
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

//*****************************************************************************
//
//! \addtogroup timer_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_timer.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

//*****************************************************************************
//
// A macro used to determine whether the target part supports new
// configuration and control options.
//
//*****************************************************************************
#define NEW_TIMER_CONFIGURATION CLASS_IS_SNOWFLAKE

//*****************************************************************************
//
// A mapping of timer base address to interrupt number.
//
//*****************************************************************************
static const uint32_t g_ppui32TimerIntMap[][2] =
{
    { TIMER0_BASE, INT_TIMER0A_BLIZZARD },
    { TIMER1_BASE, INT_TIMER1A_BLIZZARD },
    { TIMER2_BASE, INT_TIMER2A_BLIZZARD },
    { TIMER3_BASE, INT_TIMER3A_BLIZZARD },
    { TIMER4_BASE, INT_TIMER4A_BLIZZARD },
    { TIMER5_BASE, INT_TIMER5A_BLIZZARD },
    { WTIMER0_BASE, INT_WTIMER0A_BLIZZARD },
    { WTIMER1_BASE, INT_WTIMER1A_BLIZZARD },
    { WTIMER2_BASE, INT_WTIMER2A_BLIZZARD },
    { WTIMER3_BASE, INT_WTIMER3A_BLIZZARD },
    { WTIMER4_BASE, INT_WTIMER4A_BLIZZARD },
    { WTIMER5_BASE, INT_WTIMER5A_BLIZZARD },
};
static const uint_fast8_t g_ui8TimerIntMapRows =
    sizeof(g_ppui32TimerIntMap) / sizeof(g_ppui32TimerIntMap[0]);

static const uint32_t g_ppui32TimerIntMapSnowflake[][2] =
{
    { TIMER0_BASE, INT_TIMER0A_SNOWFLAKE },
    { TIMER1_BASE, INT_TIMER1A_SNOWFLAKE },
    { TIMER2_BASE, INT_TIMER2A_SNOWFLAKE },
    { TIMER3_BASE, INT_TIMER3A_SNOWFLAKE },
    { TIMER4_BASE, INT_TIMER4A_SNOWFLAKE },
    { TIMER5_BASE, INT_TIMER5A_SNOWFLAKE },
    { TIMER6_BASE, INT_TIMER6A_SNOWFLAKE },
    { TIMER7_BASE, INT_TIMER7A_SNOWFLAKE },
};
static const uint_fast8_t g_ui8TimerIntMapRowsSnowflake =
    sizeof(g_ppui32TimerIntMapSnowflake) /
    sizeof(g_ppui32TimerIntMapSnowflake[0]);

//*****************************************************************************
//
//! \internal
//! Checks a timer base address.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function determines if a timer module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_TimerBaseValid(uint32_t ui32Base)
{
    return((ui32Base == TIMER0_BASE) || (ui32Base == TIMER1_BASE) ||
           (ui32Base == TIMER2_BASE) || (ui32Base == TIMER3_BASE) ||
           (ui32Base == TIMER4_BASE) || (ui32Base == TIMER5_BASE) ||
           (ui32Base == WTIMER0_BASE) || (ui32Base == WTIMER1_BASE) ||
           (ui32Base == WTIMER2_BASE) || (ui32Base == WTIMER3_BASE) ||
           (ui32Base == WTIMER4_BASE) || (ui32Base == WTIMER5_BASE));
}
#endif

//*****************************************************************************
//
//! Returns a timer modules interrupt number.
//!
//! \param ui32Base is the base address of the selected timer.
//! \param ui32Timer specifies the timer(s) to enable; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//!
//! This function returns the interrupt number for a given timer module
//! specified by the \e ui32Base and \e ui32Timer parameter.
//!
//! \return Returns a timer module's interrupt number or 0 if the interrupt
//! does not exist.
//
//*****************************************************************************
static uint32_t
_TimerIntNumberGet(uint32_t ui32Base, uint32_t ui32Timer)
{
    uint32_t ui32Int;
    uint_fast8_t ui8Idx, ui8Rows;
    const uint32_t (*ppui32SSIIntMap)[2];

    //
    // Default interrupt map.
    //
    ppui32SSIIntMap = g_ppui32TimerIntMap;
    ui8Rows = g_ui8TimerIntMapRows;

    if(CLASS_IS_SNOWFLAKE)
    {
        ppui32SSIIntMap = g_ppui32TimerIntMapSnowflake;
        ui8Rows = g_ui8TimerIntMapRowsSnowflake;
    }

    //
    // Loop through the table that maps timer base addresses to interrupt
    // numbers.
    //
    for(ui8Idx = 0; ui8Idx < ui8Rows; ui8Idx++)
    {
        //
        // See if this base address matches.
        //
        if(ppui32SSIIntMap[ui8Idx][0] == ui32Base)
        {
            ui32Int = ppui32SSIIntMap[ui8Idx][1];

            if(ui32Timer == TIMER_B)
            {
                ui32Int += 1;
            }

            //
            // Return the corresponding interrupt number.
            //
            return(ui32Int);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(0);
}

//*****************************************************************************
//
//! Enables the timer(s).
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to enable; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//!
//! This function enables operation of the timer module.  The timer must be
//! configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
void
TimerEnable(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Enable the timer(s) module.
    //
    HWREG(ui32Base + TIMER_O_CTL) |= ui32Timer & (TIMER_CTL_TAEN |
                                                  TIMER_CTL_TBEN);
}

//*****************************************************************************
//
//! Disables the timer(s).
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to disable; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//!
//! This function disables operation of the timer module.
//!
//! \return None.
//
//*****************************************************************************
void
TimerDisable(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Disable the timer module.
    //
    HWREG(ui32Base + TIMER_O_CTL) &= ~(ui32Timer &
                                       (TIMER_CTL_TAEN | TIMER_CTL_TBEN));
}

//*****************************************************************************
//
//! Configures the timer(s).
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Config is the configuration for the timer.
//!
//! This function configures the operating mode of the timer(s).  The timer
//! module is disabled before being configured and is left in the disabled
//! state.  The timer can be configured to be a single full-width timer
//! by using the \b TIMER_CFG_* values or a pair of half-width timers using the
//! \b TIMER_CFG_A_* and \b TIMER_CFG_B_* values passed in the \e ui32Config
//! parameter.
//!
//! The configuration is specified in \e ui32Config as one of the following
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
//! configured.  The first timer is configured by setting \e ui32Config to
//! the result of a logical OR operation between one of the following values
//! and \e ui32Config:
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
//! Some Tiva devices also allow configuring an action when the timers
//! reach their timeout.  Please consult the data sheet for the part you are
//! using to determine whether configuring actions on timers is available.
//!
//! One of the following can be combined with the  \b TIMER_CFG_* values to
//! enable an action on timer A:
//!
//! - \b TIMER_CFG_A_ACT_TOINTD - masks the timeout interrupt of timer A.
//! - \b TIMER_CFG_A_ACT_NONE - no additional action on timeout of timer A.
//! - \b TIMER_CFG_A_ACT_TOGGLE - toggle CCP on timeout of timer A.
//! - \b TIMER_CFG_A_ACT_SETTO - set CCP on timeout of timer A.
//! - \b TIMER_CFG_A_ACT_CLRTO - clear CCP on timeout of timer A.
//! - \b TIMER_CFG_A_ACT_SETTOGTO - set CCP immediately and then toggle it on
//!      timeout of timer A.
//! - \b TIMER_CFG_A_ACT_CLRTOGTO - clear CCP immediately and then toggle it on
//!      timeout of timer A.
//! - \b TIMER_CFG_A_ACT_SETCLRTO - set CCP immediately and then clear it on
//!      timeout of timer A.
//! - \b TIMER_CFG_A_ACT_CLRSETTO - clear CCP immediately and then set it on
//!      timeout of timer A.
//!
//! One of the following can be combined with the \b TIMER_CFG_* values to
//! enable an action on timer B:
//!
//! - \b TIMER_CFG_B_ACT_TOINTD - masks the timeout interrupt of timer B.
//! - \b TIMER_CFG_B_ACT_NONE - no additional action on timeout of timer B.
//! - \b TIMER_CFG_B_ACT_TOGGLE - toggle CCP on timeout of timer B.
//! - \b TIMER_CFG_B_ACT_SETTO - set CCP on timeout of timer B.
//! - \b TIMER_CFG_B_ACT_CLRTO - clear CCP on timeout of timer B.
//! - \b TIMER_CFG_B_ACT_SETTOGTO - set CCP immediately and then toggle it on
//!      timeout of timer B.
//! - \b TIMER_CFG_B_ACT_CLRTOGTO - clear CCP immediately and then toggle it on
//!      timeout of timer B.
//! - \b TIMER_CFG_B_ACT_SETCLRTO - set CCP immediately and then clear it on
//!      timeout of timer B.
//! - \b TIMER_CFG_B_ACT_CLRSETTO - clear CCP immediately and then set it on
//!      timeout of timer B.
//!
//! Similarly, the second timer is configured by setting \e ui32Config to
//! the result of a logical OR operation between one of the corresponding
//! \b TIMER_CFG_B_* values and \e ui32Config.
//!
//! \return None.
//
//*****************************************************************************
void
TimerConfigure(uint32_t ui32Base, uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Config == TIMER_CFG_ONE_SHOT) ||
           (ui32Config == TIMER_CFG_ONE_SHOT_UP) ||
           (ui32Config == TIMER_CFG_PERIODIC) ||
           (ui32Config == TIMER_CFG_PERIODIC_UP) ||
           (ui32Config == TIMER_CFG_RTC) ||
           ((ui32Config & 0xff000000) == TIMER_CFG_SPLIT_PAIR));
    ASSERT(((ui32Config & 0xff000000) != TIMER_CFG_SPLIT_PAIR) ||
           ((((ui32Config & 0x000000ff) == TIMER_CFG_A_ONE_SHOT) ||
             ((ui32Config & 0x000000ff) == TIMER_CFG_A_ONE_SHOT_UP) ||
             ((ui32Config & 0x000000ff) == TIMER_CFG_A_PERIODIC) ||
             ((ui32Config & 0x000000ff) == TIMER_CFG_A_PERIODIC_UP) ||
             ((ui32Config & 0x000000ff) == TIMER_CFG_A_CAP_COUNT) ||
             ((ui32Config & 0x000000ff) == TIMER_CFG_A_CAP_TIME) ||
             ((ui32Config & 0x000000ff) == TIMER_CFG_A_PWM)) &&
            (((ui32Config & 0x0000ff00) == TIMER_CFG_B_ONE_SHOT) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_ONE_SHOT_UP) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_PERIODIC) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_PERIODIC_UP) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_CAP_COUNT) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_CAP_COUNT_UP) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_CAP_TIME) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_CAP_TIME_UP) ||
             ((ui32Config & 0x0000ff00) == TIMER_CFG_B_PWM))));

    //
    // Disable the timers.
    //
    HWREG(ui32Base + TIMER_O_CTL) &= ~(TIMER_CTL_TAEN | TIMER_CTL_TBEN);

    //
    // Set the global timer configuration.
    //
    HWREG(ui32Base + TIMER_O_CFG) = ui32Config >> 24;

    //
    // Set the configuration of the A and B timers and set the TxPWMIE bit.
    // Note that the B timer configuration is ignored by the hardware in 32-bit
    // modes.
    //
    if(NEW_TIMER_CONFIGURATION)
    {
        HWREG(ui32Base + TIMER_O_TAMR) = (((ui32Config & 0x000f0000) >> 4) |
                                          (ui32Config & 0xff) |
                                          TIMER_TAMR_TAPWMIE);
        HWREG(ui32Base + TIMER_O_TBMR) = (((ui32Config & 0x00f00000) >> 8) |
                                          ((ui32Config >> 8) & 0xff) |
                                          TIMER_TBMR_TBPWMIE);
    }
    else
    {
        HWREG(ui32Base + TIMER_O_TAMR) = ((ui32Config & 255) |
                                          TIMER_TAMR_TAPWMIE);
        HWREG(ui32Base + TIMER_O_TBMR) = (((ui32Config >> 8) & 255) |
                                          TIMER_TBMR_TBPWMIE);
    }
}

//*****************************************************************************
//
//! Controls the output level.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to adjust; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
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
TimerControlLevel(uint32_t ui32Base, uint32_t ui32Timer, bool bInvert)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Set the output levels as requested.
    //
    ui32Timer &= TIMER_CTL_TAPWML | TIMER_CTL_TBPWML;
    HWREG(ui32Base + TIMER_O_CTL) = (bInvert ?
                                     (HWREG(ui32Base + TIMER_O_CTL) |
                                      ui32Timer) :
                                     (HWREG(ui32Base + TIMER_O_CTL) &
                                      ~(ui32Timer)));
}

//*****************************************************************************
//
//! Enables or disables the ADC trigger output.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer to adjust; must be one of \b TIMER_A,
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
TimerControlTrigger(uint32_t ui32Base, uint32_t ui32Timer,
                    bool bEnable)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // On newer devices the Timer time out ADC trigger enable must also
    // be set.
    //
    if(NEW_TIMER_CONFIGURATION)
    {
        uint32_t ui32Val;

        //
        // Determine which bits to set or clear in GPTMADCEV.
        //
        ui32Val = (TIMER_ADCEV_TATOADCEN | TIMER_ADCEV_TBTOADCEN);
        ui32Val &= ui32Timer;

        //
        // Write the GPTM ADC Event register to enable or disable the trigger
        // to the ADC.
        //
        HWREG(ui32Base + TIMER_O_ADCEV) = (bEnable ?
                                           (HWREG(ui32Base + TIMER_O_ADCEV) |
                                            ui32Val) :
                                           (HWREG(ui32Base + TIMER_O_ADCEV) &
                                            ~(ui32Val)));
    }

    //
    // Set the trigger output as requested.
    // Set the ADC trigger output as requested.
    //
    ui32Timer &= TIMER_CTL_TAOTE | TIMER_CTL_TBOTE;
    HWREG(ui32Base + TIMER_O_CTL) = (bEnable ?
                                     (HWREG(ui32Base + TIMER_O_CTL) |
                                      ui32Timer) :
                                     (HWREG(ui32Base + TIMER_O_CTL) &
                                      ~(ui32Timer)));
}

//*****************************************************************************
//
//! Controls the event type.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to be adjusted; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//! \param ui32Event specifies the type of event; must be one of
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
TimerControlEvent(uint32_t ui32Base, uint32_t ui32Timer,
                  uint32_t ui32Event)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Set the event type.
    //
    ui32Timer &= TIMER_CTL_TAEVENT_M | TIMER_CTL_TBEVENT_M;
    HWREG(ui32Base + TIMER_O_CTL) = ((HWREG(ui32Base + TIMER_O_CTL) &
                                      ~ui32Timer) | (ui32Event & ui32Timer));
}

//*****************************************************************************
//
//! Controls the stall handling.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to be adjusted; must be one of
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
TimerControlStall(uint32_t ui32Base, uint32_t ui32Timer,
                  bool bStall)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Set the stall mode.
    //
    ui32Timer &= TIMER_CTL_TASTALL | TIMER_CTL_TBSTALL;
    HWREG(ui32Base + TIMER_O_CTL) = (bStall ?
                                     (HWREG(ui32Base + TIMER_O_CTL) |
                                      ui32Timer) :
                                     (HWREG(ui32Base + TIMER_O_CTL) &
                                      ~(ui32Timer)));
}

//*****************************************************************************
//
//! Controls the wait on trigger handling.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to be adjusted; must be one of
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
TimerControlWaitOnTrigger(uint32_t ui32Base, uint32_t ui32Timer,
                          bool bWait)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Set the wait on trigger mode for timer A.
    //
    if((ui32Timer & TIMER_A) != 0)
    {
        if(bWait)
        {
            HWREG(ui32Base + TIMER_O_TAMR) |= TIMER_TAMR_TAWOT;
        }
        else
        {
            HWREG(ui32Base + TIMER_O_TAMR) &= ~(TIMER_TAMR_TAWOT);
        }
    }

    //
    // Set the wait on trigger mode for timer B.
    //
    if((ui32Timer & TIMER_B) != 0)
    {
        if(bWait)
        {
            HWREG(ui32Base + TIMER_O_TBMR) |= TIMER_TBMR_TBWOT;
        }
        else
        {
            HWREG(ui32Base + TIMER_O_TBMR) &= ~(TIMER_TBMR_TBWOT);
        }
    }
}

//*****************************************************************************
//
//! Enable RTC counting.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function causes the timer to start counting when in RTC mode.  If not
//! configured for RTC mode, this function does nothing.
//!
//! \return None.
//
//*****************************************************************************
void
TimerRTCEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Enable RTC counting.
    //
    HWREG(ui32Base + TIMER_O_CTL) |= TIMER_CTL_RTCEN;
}

//*****************************************************************************
//
//! Disable RTC counting.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function causes the timer to stop counting when in RTC mode.
//!
//! \return None.
//
//*****************************************************************************
void
TimerRTCDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Disable RTC counting.
    //
    HWREG(ui32Base + TIMER_O_CTL) &= ~(TIMER_CTL_RTCEN);
}

//*****************************************************************************
//
//! Sets the clock source for the specified timer module.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Source is the clock source for the timer module.
//!
//! This function sets the clock source for both timer A and timer B for the
//! given timer module.  The possible clock sources are the system clock
//! (\b TIMER_CLOCK_SYSTEM) or the precision internal oscillator
//! (\b TIMER_CLOCK_PIOSC).
//!
//! \note The ability to specify the timer clock source varies with the
//! Tiva part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerClockSourceSet(uint32_t ui32Base, uint32_t ui32Source)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Source == TIMER_CLOCK_SYSTEM) ||
           (ui32Source == TIMER_CLOCK_PIOSC));

    //
    // Set the timer clock source.
    //
    HWREG(ui32Base + TIMER_O_CC) = ui32Source;
}

//*****************************************************************************
//
//! Returns the clock source for the specified timer module.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function returns the clock source for the specified timer module.  The
//! possible clock sources are the system clock (\b TIMER_CLOCK_SYSTEM) or
//! the precision internal oscillator (\b TIMER_CLOCK_PIOSC).
//!
//! \note The ability to specify the timer clock source varies with the
//! Tiva part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return Returns either \b TIMER_CLOCK_SYSTEM or \b TIMER_CLOCK_PIOSC.
//
//*****************************************************************************
uint32_t
TimerClockSourceGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Return the timer clock source.
    //
    return(HWREG(ui32Base + TIMER_O_CC));
}

//*****************************************************************************
//
//! Set the timer prescale value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to adjust; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//! \param ui32Value is the timer prescale value which must be between 0 and
//! 255 (inclusive) for 16/32-bit timers and between 0 and 65535 (inclusive)
//! for 32/64-bit timers.
//!
//! This function configures the value of the input clock prescaler.  The
//! prescaler is only operational when in half-width mode and is used to extend
//! the range of the half-width timer modes.  The prescaler provides the least
//! significant bits when counting down in periodic and one-shot modes; in all
//! other modes, the prescaler provides the most significant bits.
//!
//! \note The availability of the prescaler varies with the Tiva part and
//! timer mode in use.  Please consult the datasheet for the part you are using
//! to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerPrescaleSet(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));
    ASSERT(ui32Value < 256);

    //
    // Set the timer A prescaler if requested.
    //
    if(ui32Timer & TIMER_A)
    {
        HWREG(ui32Base + TIMER_O_TAPR) = ui32Value;
    }

    //
    // Set the timer B prescaler if requested.
    //
    if(ui32Timer & TIMER_B)
    {
        HWREG(ui32Base + TIMER_O_TBPR) = ui32Value;
    }
}

//*****************************************************************************
//
//! Get the timer prescale value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.
//!
//! This function gets the value of the input clock prescaler.  The prescaler
//! is only operational when in half-width mode and is used to extend the range
//! of the half-width timer modes.  The prescaler provides the least
//! significant bits when counting down in periodic and one-shot modes; in all
//! other modes, the prescaler provides the most significant bits.
//!
//! \note The availability of the prescaler varies with the Tiva part and
//! timer mode in use.  Please consult the datasheet for the part you are using
//! to determine whether this support is available.
//!
//! \return The value of the timer prescaler.
//
//*****************************************************************************
uint32_t
TimerPrescaleGet(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Return the appropriate prescale value.
    //
    return((ui32Timer == TIMER_A) ? HWREG(ui32Base + TIMER_O_TAPR) :
           HWREG(ui32Base + TIMER_O_TBPR));
}

//*****************************************************************************
//
//! Set the timer prescale match value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to adjust; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.
//! \param ui32Value is the timer prescale match value which must be between 0
//! and 255 (inclusive) for 16/32-bit timers and between 0 and 65535
//! (inclusive) for 32/64-bit timers.
//!
//! This function configures the value of the input clock prescaler match
//! value.  When in a half-width mode that uses the counter match and the
//! prescaler, the prescale match effectively extends the range of the match.
//! The prescaler provides the least significant bits when counting down in
//! periodic and one-shot modes; in all other modes, the prescaler provides the
//! most significant bits.
//!
//! \note The availability of the prescaler match varies with the Tiva
//! part and timer mode in use.  Please consult the datasheet for the part you
//! are using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerPrescaleMatchSet(uint32_t ui32Base, uint32_t ui32Timer,
                      uint32_t ui32Value)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));
    ASSERT(ui32Value < 256);

    //
    // Set the timer A prescale match if requested.
    //
    if(ui32Timer & TIMER_A)
    {
        HWREG(ui32Base + TIMER_O_TAPMR) = ui32Value;
    }

    //
    // Set the timer B prescale match if requested.
    //
    if(ui32Timer & TIMER_B)
    {
        HWREG(ui32Base + TIMER_O_TBPMR) = ui32Value;
    }
}

//*****************************************************************************
//
//! Get the timer prescale match value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer; must be one of \b TIMER_A or
//! \b TIMER_B.
//!
//! This function gets the value of the input clock prescaler match value.
//! When in a half-width mode that uses the counter match and prescaler, the
//! prescale match effectively extends the range of the match.  The prescaler
//! provides the least significant bits when counting down in periodic and
//! one-shot modes; in all other modes, the prescaler provides the most
//! significant bits.
//!
//! \note The availability of the prescaler match varies with the Tiva
//! part and timer mode in use.  Please consult the datasheet for the part you
//! are using to determine whether this support is available.
//!
//! \return The value of the timer prescale match.
//
//*****************************************************************************
uint32_t
TimerPrescaleMatchGet(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Return the appropriate prescale match value.
    //
    return((ui32Timer == TIMER_A) ? HWREG(ui32Base + TIMER_O_TAPMR) :
           HWREG(ui32Base + TIMER_O_TBPMR));
}

//*****************************************************************************
//
//! Sets the timer load value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to adjust; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.  Only \b TIMER_A should be used
//! when the timer is configured for full-width operation.
//! \param ui32Value is the load value.
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
TimerLoadSet(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Set the timer A load value if requested.
    //
    if(ui32Timer & TIMER_A)
    {
        HWREG(ui32Base + TIMER_O_TAILR) = ui32Value;
    }

    //
    // Set the timer B load value if requested.
    //
    if(ui32Timer & TIMER_B)
    {
        HWREG(ui32Base + TIMER_O_TBILR) = ui32Value;
    }
}

//*****************************************************************************
//
//! Gets the timer load value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer; must be one of \b TIMER_A or
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
uint32_t
TimerLoadGet(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B));

    //
    // Return the appropriate load value.
    //
    return((ui32Timer == TIMER_A) ? HWREG(ui32Base + TIMER_O_TAILR) :
           HWREG(ui32Base + TIMER_O_TBILR));
}

//*****************************************************************************
//
//! Sets the timer load value for a 64-bit timer.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui64Value is the load value.
//!
//! This function configures the timer load value for a 64-bit timer; if the
//! timer is running, then the value is immediately loaded into the timer.
//!
//! \return None.
//
//*****************************************************************************
void
TimerLoadSet64(uint32_t ui32Base, uint64_t ui64Value)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Set the timer load value.  The upper 32-bits must be written before the
    // lower 32-bits in order to adhere to the hardware interlocks on the
    // 64-bit value.
    //
    HWREG(ui32Base + TIMER_O_TBILR) = ui64Value >> 32;
    HWREG(ui32Base + TIMER_O_TAILR) = ui64Value & 0xffffffff;
}

//*****************************************************************************
//
//! Gets the timer load value for a 64-bit timer.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function gets the currently programmed interval load value for the
//! specified 64-bit timer.
//!
//! \return Returns the load value for the timer.
//
//*****************************************************************************
uint64_t
TimerLoadGet64(uint32_t ui32Base)
{
    uint32_t ui32High1, ui32High2, ui32Low;

    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Read the 64-bit load value.  A read of the low 32-bits is performed
    // between two reads of the upper 32-bits; if the upper 32-bit values match
    // then the 64-bit value is consistent.  If they do not match, then the
    // read is performed again until they do match (it should never execute the
    // loop body more than twice).
    //
    do
    {
        ui32High1 = HWREG(ui32Base + TIMER_O_TBILR);
        ui32Low = HWREG(ui32Base + TIMER_O_TAILR);
        ui32High2 = HWREG(ui32Base + TIMER_O_TBILR);
    }
    while(ui32High1 != ui32High2);

    //
    // Return the load value.
    //
    return(((uint64_t)ui32High1 << 32) | (uint64_t)ui32Low);
}

//*****************************************************************************
//
//! Gets the current timer value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer; must be one of \b TIMER_A or
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
uint32_t
TimerValueGet(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B));

    //
    // Return the appropriate timer value.
    //
    return((ui32Timer == TIMER_A) ? HWREG(ui32Base + TIMER_O_TAR) :
           HWREG(ui32Base + TIMER_O_TBR));
}

//*****************************************************************************
//
//! Gets the current 64-bit timer value.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function reads the current value of the specified timer.
//!
//! \return Returns the current value of the timer.
//
//*****************************************************************************
uint64_t
TimerValueGet64(uint32_t ui32Base)
{
    uint32_t ui32High1, ui32High2, ui32Low;

    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Read the 64-bit timer value.  A read of the low 32-bits is performed
    // between two reads of the upper 32-bits; if the upper 32-bit values match
    // then the 64-bit value is consistent.  If they do not match, then the
    // read is performed again until they do match (it should never execute the
    // loop body more than twice).
    //
    do
    {
        ui32High1 = HWREG(ui32Base + TIMER_O_TBR);
        ui32Low = HWREG(ui32Base + TIMER_O_TAR);
        ui32High2 = HWREG(ui32Base + TIMER_O_TBR);
    }
    while(ui32High1 != ui32High2);

    //
    // Return the timer value.
    //
    return(((uint64_t)ui32High1 << 32) | (uint64_t)ui32Low);
}

//*****************************************************************************
//
//! Sets the timer match value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s) to adjust; must be one of
//! \b TIMER_A, \b TIMER_B, or \b TIMER_BOTH.  Only \b TIMER_A should be used
//! when the timer is configured for full-width operation.
//! \param ui32Value is the match value.
//!
//! This function configures the match value for a timer.  This value is used
//! in capture count mode to determine when to interrupt the processor and in
//! PWM mode to determine the duty cycle of the output signal.  On some
//! Tiva devices, match interrupts can also be generated in periodic and
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
TimerMatchSet(uint32_t ui32Base, uint32_t ui32Timer,
              uint32_t ui32Value)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Set the timer A match value if requested.
    //
    if(ui32Timer & TIMER_A)
    {
        HWREG(ui32Base + TIMER_O_TAMATCHR) = ui32Value;
    }

    //
    // Set the timer B match value if requested.
    //
    if(ui32Timer & TIMER_B)
    {
        HWREG(ui32Base + TIMER_O_TBMATCHR) = ui32Value;
    }
}

//*****************************************************************************
//
//! Gets the timer match value.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer; must be one of \b TIMER_A or
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
uint32_t
TimerMatchGet(uint32_t ui32Base, uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B));

    //
    // Return the appropriate match value.
    //
    return((ui32Timer == TIMER_A) ? HWREG(ui32Base + TIMER_O_TAMATCHR) :
           HWREG(ui32Base + TIMER_O_TBMATCHR));
}

//*****************************************************************************
//
//! Sets the timer match value for a 64-bit timer.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui64Value is the match value.
//!
//! This function configures the match value for a timer.  This value is used
//! in capture count mode to determine when to interrupt the processor and in
//! PWM mode to determine the duty cycle of the output signal.
//!
//! \return None.
//
//*****************************************************************************
void
TimerMatchSet64(uint32_t ui32Base, uint64_t ui64Value)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Set the timer match value.  The upper 32-bits must be written before the
    // lower 32-bits in order to adhere to the hardware interlocks on the
    // 64-bit value.
    //
    HWREG(ui32Base + TIMER_O_TBMATCHR) = ui64Value >> 32;
    HWREG(ui32Base + TIMER_O_TAMATCHR) = ui64Value & 0xffffffff;
}

//*****************************************************************************
//
//! Gets the timer match value for a 64-bit timer.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function gets the match value for the specified timer.
//!
//! \return Returns the match value for the timer.
//
//*****************************************************************************
uint64_t
TimerMatchGet64(uint32_t ui32Base)
{
    uint32_t ui32High1, ui32High2, ui32Low;

    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Read the 64-bit match value.  A read of the low 32-bits is performed
    // between two reads of the upper 32-bits; if the upper 32-bit values match
    // then the 64-bit value is consistent.  If they do not match, then the
    // read is performed again until they do match (it should never execute the
    // loop body more than twice).
    //
    do
    {
        ui32High1 = HWREG(ui32Base + TIMER_O_TBMATCHR);
        ui32Low = HWREG(ui32Base + TIMER_O_TAMATCHR);
        ui32High2 = HWREG(ui32Base + TIMER_O_TBMATCHR);
    }
    while(ui32High1 != ui32High2);

    //
    // Return the match value.
    //
    return(((uint64_t)ui32High1 << 32) | (uint64_t)ui32Low);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the timer interrupt.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s); must be one of \b TIMER_A,
//! \b TIMER_B, or \b TIMER_BOTH.
//! \param pfnHandler is a pointer to the function to be called when the timer
//! interrupt occurs.
//!
//! This function registers the handler to be called when a timer interrupt
//! occurs.  In addition, this function enables the global interrupt in the
//! interrupt controller; specific timer interrupts must be enabled via
//! TimerIntEnable().  It is the interrupt handler's responsibility to clear
//! the interrupt source via TimerIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntRegister(uint32_t ui32Base, uint32_t ui32Timer,
                 void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Get the interrupt number for this timer module.
    //
    ui32Int = _TimerIntNumberGet(ui32Base, ui32Timer);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the timer interrupt.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32Timer specifies the timer(s); must be one of \b TIMER_A,
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
TimerIntUnregister(uint32_t ui32Base, uint32_t ui32Timer)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));
    ASSERT((ui32Timer == TIMER_A) || (ui32Timer == TIMER_B) ||
           (ui32Timer == TIMER_BOTH));

    //
    // Get the interrupt number for this timer module.
    //
    ui32Int = _TimerIntNumberGet(ui32Base, ui32Timer);

    //
    // Disable the interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Enables individual timer interrupt sources.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated timer interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter must be the logical OR of any combination of
//! the following:
//!
//! - \b TIMER_TIMB_DMA - Timer B DMA complete
//! - \b TIMER_TIMA_DMA - Timer A DMA complete
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
TimerIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Enable the specified interrupts.
    //
    HWREG(ui32Base + TIMER_O_IMR) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables individual timer interrupt sources.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be
//! disabled.
//!
//! This function disables the indicated timer interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter has the same definition as the
//! \e ui32IntFlags parameter to TimerIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
TimerIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Disable the specified interrupts.
    //
    HWREG(ui32Base + TIMER_O_IMR) &= ~(ui32IntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ui32Base is the base address of the timer module.
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
uint32_t
TimerIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    return(bMasked ? HWREG(ui32Base + TIMER_O_MIS) :
           HWREG(ui32Base + TIMER_O_RIS));
}

//*****************************************************************************
//
//! Clears timer interrupt sources.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified timer interrupt sources are cleared, so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupt from being triggered again immediately upon exit.
//!
//! The \e ui32IntFlags parameter has the same definition as the
//! \e ui32IntFlags parameter to TimerIntEnable().
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
TimerIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ui32Base + TIMER_O_ICR) = ui32IntFlags;
}

//*****************************************************************************
//
//! Synchronizes the counters in a set of timers.
//!
//! \param ui32Base is the base address of the timer module.  This parameter
//! must be the base address of Timer0 (in other words, \b TIMER0_BASE).
//! \param ui32Timers is the set of timers to synchronize.
//!
//! This function synchronizes the counters in a specified set of timers.
//! When a timer is running in half-width mode, each half can be included or
//! excluded in the synchronization event.  When a timer is running in
//! full-width mode, only the A timer can be synchronized (specifying the B
//! timer has no effect).
//!
//! The \e ui32Timers parameter is the logical OR of any of the following
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
TimerSynchronize(uint32_t ui32Base, uint32_t ui32Timers)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == TIMER0_BASE);

    //
    // Synchronize the specified timers.
    //
    HWREG(ui32Base + TIMER_O_SYNC) = ui32Timers;
}

//*****************************************************************************
//
//! Enables the events that can cause an ADC trigger event.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32ADCEvent is a bit mask of the events that can cause an ADC
//!        trigger event.
//!
//! This function enables the timer events that can cause an ADC trigger event.
//! The ADC trigger events are specified in the \e ui32ADCEvent parameter by
//! passing in the logical OR of any of the following values:
//!
//! - \b TIMER_ADC_MODEMATCH_B - Enables the mode match ADC trigger for timer
//!   B.
//! - \b TIMER_ADC_CAPEVENT_B - Enables the capture event ADC trigger for
//!   timer B.
//! - \b TIMER_ADC_CAPMATCH_B - Enables the capture match ADC trigger for
//!   timer B.
//! - \b TIMER_ADC_TIMEOUT_B - Enables the timeout ADC trigger for timer B.
//! - \b TIMER_ADC_MODEMATCH_A - Enables the mode match ADC trigger for timer
//!   A.
//! - \b TIMER_ADC_RTC_A - Enables the RTC ADC trigger for timer A.
//! - \b TIMER_ADC_CAPEVENT_A - Enables the capture event ADC trigger for
//!   timer A.
//! - \b TIMER_ADC_CAPMATCH_A - Enables the capture match ADC trigger for
//!   timer A.
//! - \b TIMER_ADC_TIMEOUT_A - Enables the timeout ADC trigger for timer A.
//!
//! \note The ability to specify ADC event triggers varies with the Tiva
//! part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerADCEventSet(uint32_t ui32Base, uint32_t ui32ADCEvent)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Set the ADC triggers.
    //
    HWREG(ui32Base + TIMER_O_ADCEV) = ui32ADCEvent;
}

//*****************************************************************************
//
//! Returns the events that can cause an ADC trigger event.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function returns the timer events that can cause an ADC trigger event.
//! The ADC trigger events are the logical OR of any of the following values:
//!
//! - \b TIMER_ADC_MODEMATCH_B - The mode match ADC trigger for timer B is
//!   enabled.
//! - \b TIMER_ADC_CAPEVENT_B - The capture event ADC trigger for timer B is
//!   enabled.
//! - \b TIMER_ADC_CAPMATCH_B - The capture match ADC trigger for timer B is
//!   enabled.
//! - \b TIMER_ADC_TIMEOUT_B - The timeout ADC trigger for timer B is enabled.
//! - \b TIMER_ADC_MODEMATCH_A - The mode match ADC trigger for timer A is
//!   enabled.
//! - \b TIMER_ADC_RTC_A - The RTC ADC trigger for timer A is enabled.
//! - \b TIMER_ADC_CAPEVENT_A - The capture event ADC trigger for timer A is
//!   enabled.
//! - \b TIMER_ADC_CAPMATCH_A - The capture match ADC trigger for timer A is
//!   enabled.
//! - \b TIMER_ADC_TIMEOUT_A - The timeout ADC trigger for timer A is enabled.
//!
//! \note The ability to specify ADC event triggers varies with the Tiva
//! part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return The timer events that trigger the ADC.
//
//*****************************************************************************
uint32_t
TimerADCEventGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Return the current ADC triggers.
    //
    return(HWREG(ui32Base + TIMER_O_ADCEV));
}

//*****************************************************************************
//
//! Enables the events that can trigger a DMA request.
//!
//! \param ui32Base is the base address of the timer module.
//! \param ui32DMAEvent is a bit mask of the events that can trigger DMA.
//!
//! This function enables the timer events that can trigger the start of a DMA
//! sequence.  The DMA trigger events are specified in the \e ui32DMAEvent
//! parameter by passing in the logical OR of the following values:
//!
//! - \b TIMER_DMA_MODEMATCH_B - The mode match DMA trigger for timer B is
//!   enabled.
//! - \b TIMER_DMA_CAPEVENT_B - The capture event DMA trigger for timer B is
//!   enabled.
//! - \b TIMER_DMA_CAPMATCH_B - The capture match DMA trigger for timer B is
//!   enabled.
//! - \b TIMER_DMA_TIMEOUT_B - The timeout DMA trigger for timer B is enabled.
//! - \b TIMER_DMA_MODEMATCH_A - The mode match DMA trigger for timer A is
//!   enabled.
//! - \b TIMER_DMA_RTC_A - The RTC DMA trigger for timer A is enabled.
//! - \b TIMER_DMA_CAPEVENT_A - The capture event DMA trigger for timer A is
//!   enabled.
//! - \b TIMER_DMA_CAPMATCH_A - The capture match DMA trigger for timer A is
//!   enabled.
//! - \b TIMER_DMA_TIMEOUT_A - The timeout DMA trigger for timer A is enabled.
//!
//! \note The ability to specify DMA event triggers varies with the Tiva
//! part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
TimerDMAEventSet(uint32_t ui32Base, uint32_t ui32DMAEvent)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Set the DMA triggers.
    //
    HWREG(ui32Base + TIMER_O_DMAEV) = ui32DMAEvent;
}

//*****************************************************************************
//
//! Returns the events that can trigger a DMA request.
//!
//! \param ui32Base is the base address of the timer module.
//!
//! This function returns the timer events that can trigger the start of a DMA
//! sequence.  The DMA trigger events are the logical OR of the following
//! values:
//!
//! - \b TIMER_DMA_MODEMATCH_B - Enables the mode match DMA trigger for timer
//!   B.
//! - \b TIMER_DMA_CAPEVENT_B - Enables the capture event DMA trigger for
//!   timer B.
//! - \b TIMER_DMA_CAPMATCH_B - Enables the capture match DMA trigger for
//!   timer B.
//! - \b TIMER_DMA_TIMEOUT_B - Enables the timeout DMA trigger for timer B.
//! - \b TIMER_DMA_MODEMATCH_A - Enables the mode match DMA trigger for timer
//!   A.
//! - \b TIMER_DMA_RTC_A - Enables the RTC DMA trigger for timer A.
//! - \b TIMER_DMA_CAPEVENT_A - Enables the capture event DMA trigger for
//!   timer A.
//! - \b TIMER_DMA_CAPMATCH_A - Enables the capture match DMA trigger for
//!   timer A.
//! - \b TIMER_DMA_TIMEOUT_A - Enables the timeout DMA trigger for timer A.
//!
//! \note The ability to specify DMA event triggers varies with the Tiva
//! part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return The timer events that trigger the uDMA.
//
//*****************************************************************************
uint32_t
TimerDMAEventGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_TimerBaseValid(ui32Base));

    //
    // Return the current DMA triggers.
    //
    return(HWREG(ui32Base + TIMER_O_DMAEV));
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
