//*****************************************************************************
//
// peci.c - Driver for the Platform Environment Control Interface (PECI)
//          module.
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

//*****************************************************************************
//
//! \addtogroup peci_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_peci.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/peci.h"

//*****************************************************************************
//
// The following defines provide characteristics of the PECI module that are
// important to the driver but which can not be gleaned from the register
// definitions.  Note that the maximum baud rate here is set higher than
// specified to allow callers to achieve 1Mbps on a slow part.
//
//*****************************************************************************
#define PECI_MAX_BAUD      4000000                      // Max baud rate
#define PECI_MIN_BAUD      2000                         // Min baud rate
#define PECI_MIN_RATIO     (CLASS_IS_BLIZZARD ? 10 : 1) // Min baud rate divider
#define PECI_MAX_RATIO     65535                        // Max baud rate divider
#define PECI_POLL_PRESCALE 4096                    // Polling timer prescaler
#define PECI_MIN_POLL      2                       // Min polling interval (ms)
#define PECI_MAX_POLL      1000                    // Max polling interval (ms)

//*****************************************************************************
//
//! \internal
//! Checks a PECI domain.
//!
//! \param ulDomain is the PECI domain identifier.
//!
//! This function determines if a domain identifier is valid.
//!
//! \return Returns \b true if the domain identifier is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
PECIDomainValid(unsigned long ulDomain)
{
    return((ulDomain == PECI_DOMAIN_M0D0) ||
           (ulDomain == PECI_DOMAIN_M0D1) ||
           (ulDomain == PECI_DOMAIN_M1D0) ||
           (ulDomain == PECI_DOMAIN_M1D1));
}
#endif

//*****************************************************************************
//
//! Sets the configuration of the PECI module.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulPECIClk is the rate of the clock supplied to the PECI module.
//! \param ulBaud is the bit rate that should be used for the PECI transfers.
//! \param ulPoll is the polling rate, in ms, that should be used for the
//! time between PECI polls.
//! \param ulOffset is the offset to be applied to all temperature values to
//! convert from relative to absolute.
//! \param ulRetry is the number of retry attempts for a PECI transaction.
//!
//! This function initializes operation of the PECI block.  It programs the bit
//! rate, polling rate and retry counts for PECI transactions.  It also
//! programs the offset value to be used to translate relative temperature
//! values from PECI transactions to absolute values.  At the end of this
//! function, no host/domain combinations are enabled.  Each desired
//! host/domain combination can be configured/enabled with a call to
//! PECIDomainEnable().
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
//!
//! The \e ulBaud parameter defines the starting bit rate for the PECI
//! transactions.  This value is used to calculate a divisor value based on
//! the specified \e ulPECIClk.  If the exact baud rate cannot be achieved
//! (due to rounding), the baud rate is programmed to the nearest value that
//! is less than the specified value.  Note that, due to client clock
//! stretching and delays through external components, the actual baud rate
//! observed on the PECI bus will always be lower than the value specified in
//! this parameter.
//!
//! The \e ulPoll parameter defines the polling rate, in milliseconds, used
//! for PECI transactions.  For generation of the polling rate, the \e
//! ulPECIClk is pre-divided by \b 4096.  A value of 0 disables the polling
//! feature.  If the exact polling rate cannot be achieved (due to rounding),
//! the polling rate is programmed to the nearest value that is greater than
//! the specified value.
//!
//! The \e ulRetry parameter defines the number of PECI transactions that are
//! attempted before indicating an error condition.
//!
//! \return None.
//
//*****************************************************************************
void
PECIConfigSet(unsigned long ulBase, unsigned long ulPECIClk,
              unsigned long ulBaud, unsigned long ulPoll,
              unsigned long ulOffset, unsigned long ulRetry)
{
    unsigned long ulTemp, ulDiv;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(ulPECIClk != 0);
    ASSERT((ulBaud != 0) && (ulBaud <= PECI_MAX_BAUD) &&
           (ulBaud >= PECI_MIN_BAUD) &&
           ((ulBaud * 4 * PECI_MIN_RATIO) < ulPECIClk));
    ASSERT((ulPoll == 0) ||
           ((ulPoll >= PECI_MIN_POLL) && (ulPoll <= PECI_MAX_POLL)));

    //
    // Generate value for the PECI Control Register.
    //
    ulTemp = ((ulOffset << PECI_CTL_OFFSET_S) & PECI_CTL_OFFSET_M);
    ulTemp |= ((ulRetry << PECI_CTL_CRETRY_S) & PECI_CTL_CRETRY_M);
    HWREG(ulBase + PECI_O_CTL) = ulTemp;

    //
    // Compute the divisor for the PECI baud rate clock.
    // Round up, to ensure programmed baud rate is <= specified rate.
    // Ensure that proper ratio is maintained for clock:baud.
    //
    ulDiv = (ulPECIClk + (4 * ulBaud) - 1) / (4 * ulBaud);
    ulDiv = (ulDiv < PECI_MIN_RATIO) ? PECI_MIN_RATIO : ulDiv;
    ulDiv = (ulDiv > PECI_MAX_RATIO) ? PECI_MAX_RATIO : ulDiv;
    ulTemp = ((ulDiv << PECI_DIV_BAUD_S) & PECI_DIV_BAUD_M);

    //
    // Compute the divisor for the PECI polling rate.
    // Round up, to ensure programmed polling rate is >= specified rate.
    // Note that the order of calculation is important here since ulPECIClk is
    // in the 10s of MHz range and ulPoll can be several thousand for slow
    // polling rates.  If we change the order, the calculation can overflow
    // resulting in incorrect polling rates.
    //
    ulDiv = ((ulPoll == 0) ? 0 : ((((ulPECIClk / 1000) * ulPoll) +
                                   (PECI_POLL_PRESCALE - 1)) /
                                  PECI_POLL_PRESCALE));
    ulTemp |= ((ulDiv << PECI_DIV_POLL_S) & PECI_DIV_POLL_M);;
    HWREG(ulBase + PECI_O_DIV) = ulTemp;
}

//*****************************************************************************
//
//! Gets the current configuration of the PECI module.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulPECIClk is the rate of the clock supplied to the PECI module.
//! \param pulBaud is a pointer to storage for the bit rate.
//! \param pulPoll is a pointer to storage for the polling rate.
//! \param pulOffset is a pointer to storage for the offset.
//! \param pulRetry is a pointer to storage for the retry count.
//!
//! The baud rate and poll rate for the PECI module are determined, given an
//! explicitly provided peripheral clock.  The returned rates are the actual
//! rates being used; they may not be the same as the requested rates, due to
//! rounding in the calculations.
//!
//! The peripheral clock is the same as the processor clock.  This value is
//! returned by SysCtlClockGet(), or it can be explicitly hard coded if it is
//! constant and known (to save the code/execution overhead of a call to
//! SysCtlClockGet()).
//!
//! The baud rate returned in \e *pulBaud represents the rate at which the
//! peripheral starts PECI transactions.  Due to client clock stretching and
//! delays associated with external components, the actual baud rate observed
//! will always be lower than this value.
//!
//! \return None.
//
//*****************************************************************************
void
PECIConfigGet(unsigned long ulBase, unsigned long ulPECIClk,
              unsigned long *pulBaud, unsigned long *pulPoll,
              unsigned long *pulOffset, unsigned long *pulRetry)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(ulPECIClk != 0);
    ASSERT(pulBaud != 0);
    ASSERT(pulPoll != 0);
    ASSERT(pulOffset != 0);
    ASSERT(pulRetry != 0);

    //
    // Retrieve the Offset and Retry values
    //
    ulTemp = HWREG(ulBase + PECI_O_CTL);
    *pulOffset = ((ulTemp & PECI_CTL_OFFSET_M) >> PECI_CTL_OFFSET_S);
    *pulRetry = ((ulTemp & PECI_CTL_CRETRY_M) >> PECI_CTL_CRETRY_S);

    //
    // Calculate the baud rate.
    //
    ulTemp = HWREG(ulBase + PECI_O_DIV);
    *pulBaud = (ulPECIClk / (4 * ((ulTemp & PECI_DIV_BAUD_M) >>
                                  PECI_DIV_BAUD_S)));

    //
    // Compute the divisor for the PECI polling rate.
    // Round up, to ensure programmed polling rate is >= specified rate.
    //
    *pulPoll = ((((ulTemp & PECI_DIV_POLL_M) >> PECI_DIV_POLL_S) * 1000) /
                (ulPECIClk / PECI_POLL_PRESCALE));
}

//*****************************************************************************
//
//! Enables bypassing of negotiation errors.
//!
//! \param ulBase is the base address of the PECI module.
//!
//! This function enables bypassing of negotiation errors that might occur
//! during a PECI transaction.  When enabled, negotiation errors are ignored.
//!
//! \return None.
//
//*****************************************************************************
void
PECIBypassEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Enable bypass.
    //
    HWREG(ulBase + PECI_O_CTL) |= PECI_CTL_BYERR;
}

//*****************************************************************************
//
//! Disables bypassing of negotiation errors.
//!
//! \param ulBase is the base address of the PECI module.
//!
//! This function disables bypassing of negotiation errors that might occur
//! during a PECI transaction.  When disabled, negotiation errors are reported
//! and the remainder of the transaction is aborted.
//!
//! \return None.
//
//*****************************************************************************
void
PECIBypassDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Disable bypass.
    //
    HWREG(ulBase + PECI_O_CTL) &= ~PECI_CTL_BYERR;
}

//*****************************************************************************
//
//! Sets the configuration of the specified PECI domain.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be configured.
//! \param ulHigh is the high temperature threshold value.
//! \param ulLow is the low temperature threshold value.
//!
//! This function configures the specified PECI domain for temperature
//! monitoring  operations.  The values for \e ulHigh and \e ulLow can be
//! specified as values relative to the maximum temperature allowed, or they
//! can be specified as absolute temperatures if an offset was programmed
//! in the PECIConfigSet() function.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIDomainConfigSet(unsigned long ulBase, unsigned long ulDomain,
                    unsigned long ulHigh, unsigned long ulLow)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));
    ASSERT(ulHigh <= 0xFFFF);
    ASSERT(ulLow <= 0xFFFF);
    ASSERT(ulHigh > ulLow);

    //
    // Set the HTHRESH and LTHRESH fields in the domain control/status
    // register.
    //
    HWREG(ulBase + PECI_O_M0D0C + (ulDomain * 4)) =
        (((ulHigh << PECI_M0D0C_HITHR_S) & PECI_M0D0C_HITHR_M) |
         ((ulLow << PECI_M0D0C_LOTHR_S) & PECI_M0D0C_LOTHR_M));
}

//*****************************************************************************
//
//! Gets the configuration of the specified PECI domain.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be configured.
//! \param pulHigh is a pointer to storage for the high threshold.
//! \param pulLow is a pointer to storage for the low threshold.
//!
//! This function configures the specified PECI domain for temperature
//! monitoring  operations.  The values for \e ulHigh and \e ulLow can be
//! specified as values relative to the maximum temperature allowed, or they
//! can be specified as absolute temperatures if an offset was programmed
//! in the PECIConfigSet() function.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIDomainConfigGet(unsigned long ulBase, unsigned long ulDomain,
                    unsigned long *pulHigh, unsigned long *pulLow)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));
    ASSERT(pulHigh != 0);
    ASSERT(pulLow != 0);

    //
    // Get the HTHRESH and LTHRESH fields in the domain control/status
    // register.
    //
    ulTemp = HWREG(ulBase + PECI_O_M0D0C + (ulDomain * 4));
    *pulHigh = ((ulTemp && PECI_M0D0C_HITHR_M) >> PECI_M0D0C_HITHR_S);
    *pulLow = ((ulTemp && PECI_M0D0C_LOTHR_M) >> PECI_M0D0C_LOTHR_S);
}

//*****************************************************************************
//
//! Enables a domain within the PECI module.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be enabled.
//!
//! This function enables the specified PECI domain for temperature monitoring
//! operations.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIDomainEnable(unsigned long ulBase, unsigned long ulDomain)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));

    //
    // Enable the specified domain.
    //
    HWREG(ulBase + PECI_O_CTL) |= (1 << ulDomain);
}

//*****************************************************************************
//
//! Disables a domain within the PECI module.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be disabled.
//!
//! This function disables the specified PECI domain.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIDomainDisable(unsigned long ulBase, unsigned long ulDomain)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));

    //
    // Disable the specified domain.
    //
    HWREG(ulBase + PECI_O_CTL) &= ~(1 << ulDomain);
}

//*****************************************************************************
//
//! Reads the current temperature value for the specified domain.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be disabled.
//!
//! This function returns the most recently read temperature value from the
//! specified domain.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
unsigned long
PECIDomainValueGet(unsigned long ulBase, unsigned long ulDomain)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));

    //
    // Return the most recently polled temperature value
    //
    return(((HWREG(ulBase + PECI_O_M0D0 + (ulDomain * 4)) &
             PECI_M0D0_VALUE_M)));
}

//*****************************************************************************
//
//! Reads the maximum/error value for the specified domain.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be disabled.
//!
//! This function returns the maximum temperature value for the specified
//! domain.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
unsigned long
PECIDomainMaxReadGet(unsigned long ulBase, unsigned long ulDomain)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));

    //
    // Return the most recently polled temperature value
    //
    return(((HWREG(ulBase + PECI_O_M0D0 + (ulDomain * 4)) &
             PECI_M0D0_MAXREAD_M) >> PECI_M0D0_MAXREAD_S));
}

//*****************************************************************************
//
//! Clears the current temperature value for the specified domain.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be disabled.
//!
//! This function clears the current temperature value for the specified
//! domain.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIDomainValueClear(unsigned long ulBase, unsigned long ulDomain)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));

    //
    // Clear the temperature value.
    //
    HWREG(ulBase + PECI_O_M0D0 + (ulDomain * 4) ) &= ~PECI_M0D0_VALUE_M;
}

//*****************************************************************************
//
//! Clears the maximum/error value for the specified domain.
//!
//! \param ulBase is the base address of the PECI module.
//! \param ulDomain is the PECI domain that should be disabled.
//!
//! This function clears the maximum temperature measurement value for the
//! specified domain.
//!
//! The \e ulDomain parameter can be one of the following values:
//! \b PECI_DOMAIN_M0D0, \b PECI_DOMAIN_M0D1, \b PECI_DOMAIN_M1D0, or
//! \b PECI_DOMAIN_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIDomainMaxReadClear(unsigned long ulBase, unsigned long ulDomain)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(PECIDomainValid(ulDomain));

    //
    // Clear the maximum/error value.
    //
    HWREG(ulBase + PECI_O_M0D0 + (ulDomain * 4) ) &= ~PECI_M0D0_MAXREAD_M;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the PECI module.
//!
//! \param ulBase specifies the PECI module base address.
//! \param pfnHandler is a pointer to the function to be called when the
//! PECI interrupt occurs.
//!
//! This function registers the handler to be called when an PECI interrupt
//! occurs. This function enables the global interrupt in the interrupt
//! controller; specific PECI interrupts must be enabled via PECIIntEnable().
//! If necessary, it is the interrupt handler's responsibility to clear the
//! interrupt source via PECIIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
PECIIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);
    ASSERT(pfnHandler != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_PECI0, pfnHandler);

    //
    // Enable the PECI interrupt.
    //
    IntEnable(INT_PECI0);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the PECI module.
//!
//! \param ulBase specifies the PECI module base address.
//!
//! This function unregisters the handler to be called when a PECI interrupt
//! occurs.  This function also masks off the interrupt in the interrupt
//! controller so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
PECIIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Disable the PECI interrupt.
    //
    IntDisable(INT_PECI0);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_PECI0);
}

//*****************************************************************************
//
//! Enables individual PECI interrupt sources.
//!
//! \param ulBase specifies the PECI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//! \param ulIntMode is the mode for the PECI domain interrupts.
//!
//! This function enables the indicated PECI interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter can be any of the following values:
//! \b PECI_READ, \b PECI_ERR, \b PECI_AC, \b PECI_M0D0, \b PECI_M0D1,
//! \b PECI_M1D0, or \b PECI_M1D1.
//!
//! The \e ulIntMode parameter is used to configure the interrupt mode for
//! the corresponding \b PECI_DOMAIN_MnDm field, and can be any of the
//! following values:  \b PECI_M0D0_MODE1, \b PECI_M0D0_MODE2,
//! \b PECI_M0D0_MODE3, \b PECI_M0D1_MODE1, \b PECI_M0D1_MODE2,
//! \b PECI_M0D1_MODE3. \b PECI_M1D0_MODE1, \b PECI_M1D0_MODE2,
//! \b PECI_M1D0_MODE3, \b PECI_M1D1_MODE1, \b PECI_M1D1_MODE2, or
//! \b PECI_M1D1_MODE3.
//!
//! \return None.
//
//*****************************************************************************
void
PECIIntEnable(unsigned long ulBase, unsigned long ulIntFlags,
              unsigned long ulIntMode)
{
    unsigned long ulTemp;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Get the current mask value.
    //
    ulTemp = HWREG(ulBase + PECI_O_IM);

    //
    // Clear the bit/bit-fields that are configured, based on the value
    // in the flags parameter.
    //
    ulTemp &= ~ulIntFlags;

    //
    // Set/Enable the bit/bit-fields based on the value in the flags and mode
    // parameter.  The flags parameter alters the bits in the lower half
    // of the mask, while the mode alters the bit fields in the upper
    // half of the mask.
    //
    ulTemp |= (0x0000FFFF & ulIntFlags);
    ulTemp |= (0xFFFF0000 & ulIntMode);
    HWREG(ulBase + PECI_O_IM) = ulTemp;
}

//*****************************************************************************
//
//! Disables individual PECI interrupt sources.
//!
//! \param ulBase specifies the PECI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated PECI interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter can be any of the following values:
//! \b PECI_READ, \b PECI_ERR, \b PECI_AC, \b PECI_M0D0, \b PECI_M0D1,
//! \b PECI_M1D0, or \b PECI_M1D1.
//!
//! \return None.
//
//*****************************************************************************
void
PECIIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Disable the specified interrupts.
    //
    HWREG(ulBase + PECI_O_IM) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase specifies the PECI module base address.
//! \param bMasked is \b false if the raw interrupt status is required or
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the PECI module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! The interpretation of the PECI_DOMAIN_MnDm fields vary based on the mode
//! value programed using the PECIIntEnable() function for the field.  Each
//! field may take on one of the following values:
//! \b PECI_MnDm_MODE1_HIGH, \b PECI_MnDm_MODE2_MID, \b PECI_MnDm_MODE2_HIGH,
//! \b PECI_MnDm_MODE3_LOW, \b PECI_MnDm_MODE3_MID, or \b PECI_MnDm_MODE3_HIGH.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! \b PECI_READ, \b PECI_ERR, \b PECI_AC, \b PECI_M0D0, \b PECI_M0D1,
//! \b PECI_M1D0, or \b PECI_M1D1.
//
//*****************************************************************************
unsigned long
PECIIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + PECI_O_MIS));
    }
    else
    {
        return(HWREG(ulBase + PECI_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears PECI interrupt sources.
//!
//! \param ulBase specifies the PECI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! This function clears the specified PECI interrupt sources so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep the interrupts from being recognized again immediately upon exit.
//! The \e ulIntFlags parameter can consist of any combination of the
//! \b PECI_READ, \b PECI_ERR, \b PECI_AC, \b PECI_M0D0, \b PECI_M0D1,
//! \b PECI_M1D0, or \b PECI_M1D1 values.
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
PECIIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + PECI_O_IC) = ulIntFlags;
}

//*****************************************************************************
//
//! Sends a PECI Advanced Command.
//!
//! \param ulBase specifies the PECI module base address.
//!
//! This function sends a PECI Advanced Command.  If the interface is not IDLE,
//! it waits for the interface to become IDLE then sends the command.  The
//! function parameters are used to populate the message control fields before
//! activating the command.
//!
//! \return None.
//
//*****************************************************************************
void
PECIAdvCmdSend(unsigned long ulBase, unsigned char ucCmd,
               unsigned char ucHidRe, unsigned char ucDomain,
               unsigned char ucProcAdd, unsigned long ulArg,
               unsigned char ucSize, unsigned long ulData0,
               unsigned long ulData1)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Wait for the interface to be idle.
    //
    while(HWREG(ulBase + PECI_O_ACCODE) == 0xFFFFFFFF)
    {
    }

    //
    // Fill in the registers for the advanced command.
    //
    HWREG(ulBase + PECI_O_ACARG) = ulArg;
    HWREG(ulBase + PECI_O_ACRDWR0) = ulData0;
    HWREG(ulBase + PECI_O_ACRDWR1) = ulData1;
    HWREG(ulBase + PECI_O_ACADDR) = (ucHidRe << 24) |
                                    (ucSize  << 16) |
                                    (ucDomain << 8) |
                                    (ucProcAdd << 0);

    //
    // Now, issue the command.
    //
    HWREG(ulBase + PECI_O_ACCMD) = ucCmd;
}

//*****************************************************************************
//
//! Sends a PECI Advanced Command (non blocking).
//!
//! \param ulBase specifies the PECI module base address.
//!
//! This function sends a PECI Advanced Command.  If the interface is not IDLE,
//! it returns immediately.  Otherwise, it sends the the command.  The function
//! parameters are used to populate the message control fields before
//! activating the command.
//!
//! \return None.
//
//*****************************************************************************
unsigned long
PECIAdvCmdSendNonBlocking(unsigned long ulBase, unsigned char ucCmd,
                          unsigned char ucHidRe, unsigned char ucDomain,
                          unsigned char ucProcAdd, unsigned long ulArg,
                          unsigned char ucSize, unsigned long ulData0,
                          unsigned long ulData1)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // Check for the interface to be idle.
    // If not, return immediately.
    //
    if(HWREG(ulBase + PECI_O_ACCODE) == 0xFFFFFFFF)
    {
        return(0);
    }

    //
    // Send the command.
    //
    PECIAdvCmdSend(ulBase, ucCmd, ucHidRe, ucDomain, ucProcAdd, ulArg,
                   ucSize, ulData0, ulData1);

    //
    // Return, indicating that the command has been issued.
    //
    return(1);
}

//*****************************************************************************
//
//! Obtains status of previous PECI Advanced Command.
//!
//! \param ulBase specifies the PECI module base address.
//!
//! This function gets the status of a previously issued PECI Advanced Command.
//! If the command has completed, and the data pointers are non-zero, the data
//! registers are read and saved.
//!
//! \return -1 if command has not yet been completed, otherwise, the return
//! code associated with the Advanced Command.
//
//*****************************************************************************
unsigned long
PECIAdvCmdStatusGet(unsigned long ulBase, unsigned long *pulData0,
                    unsigned long *pulData1)
{
    unsigned long ulCode;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == PECI0_BASE);

    //
    // If the command has completed, optionally read and save the data
    // registers.
    //
    ulCode = HWREG(ulBase + PECI_O_ACCODE);
    if(ulCode != 0xFFFFFFFF)
    {
        if(pulData0 != (void *)0)
        {
            *pulData0 = HWREG(ulBase + PECI_O_ACRDWR0);
        }
        if(pulData1 != (void *)0)
        {
            *pulData1 = HWREG(ulBase + PECI_O_ACRDWR1);
        }
    }

    //
    // Return the command code from the most recently completed command.
    //
    return(ulCode);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
