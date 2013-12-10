//*****************************************************************************
//
// watchdog.c - Driver for the Watchdog Timer Module.
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
//! \addtogroup watchdog_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_watchdog.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/watchdog.h"

//*****************************************************************************
//
//! Determines if the watchdog timer is enabled.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function checks to see if the watchdog timer is enabled.
//!
//! \return Returns \b true if the watchdog timer is enabled and \b false
//! if it is not.
//
//*****************************************************************************
bool
WatchdogRunning(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // See if the watchdog timer module is enabled, and return.
    //
    return(HWREG(ui32Base + WDT_O_CTL) & WDT_CTL_INTEN);
}

//*****************************************************************************
//
//! Enables the watchdog timer.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function enables the watchdog timer counter and interrupt.
//!
//! \note This function has no effect if the watchdog timer has been locked.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Enable the watchdog timer module.
    //
    HWREG(ui32Base + WDT_O_CTL) |= WDT_CTL_INTEN;
}

//*****************************************************************************
//
//! Enables the watchdog timer reset.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function enables the capability of the watchdog timer to issue a reset
//! to the processor after a second timeout condition.
//!
//! \note This function has no effect if the watchdog timer has been locked.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogResetEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Enable the watchdog reset.
    //
    HWREG(ui32Base + WDT_O_CTL) |= WDT_CTL_RESEN;
}

//*****************************************************************************
//
//! Disables the watchdog timer reset.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function disables the capability of the watchdog timer to issue a
//! reset to the processor after a second timeout condition.
//!
//! \note This function has no effect if the watchdog timer has been locked.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogResetDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Disable the watchdog reset.
    //
    HWREG(ui32Base + WDT_O_CTL) &= ~(WDT_CTL_RESEN);
}

//*****************************************************************************
//
//! Enables the watchdog timer lock mechanism.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function locks out write access to the watchdog timer configuration
//! registers.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogLock(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Lock out watchdog register writes.  Writing anything to the WDT_O_LOCK
    // register causes the lock to go into effect.
    //
    HWREG(ui32Base + WDT_O_LOCK) = WDT_LOCK_LOCKED;
}

//*****************************************************************************
//
//! Disables the watchdog timer lock mechanism.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function enables write access to the watchdog timer configuration
//! registers.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogUnlock(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Unlock watchdog register writes.
    //
    HWREG(ui32Base + WDT_O_LOCK) = WDT_LOCK_UNLOCK;
}

//*****************************************************************************
//
//! Gets the state of the watchdog timer lock mechanism.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function returns the lock state of the watchdog timer registers.
//!
//! \return Returns \b true if the watchdog timer registers are locked, and
//! \b false if they are not locked.
//
//*****************************************************************************
bool
WatchdogLockState(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Get the lock state.
    //
    return((HWREG(ui32Base + WDT_O_LOCK) == WDT_LOCK_LOCKED) ? true : false);
}

//*****************************************************************************
//
//! Sets the watchdog timer reload value.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//! \param ui32LoadVal is the load value for the watchdog timer.
//!
//! This function configures the value to load into the watchdog timer when the
//! count reaches zero for the first time; if the watchdog timer is running
//! when this function is called, then the value is immediately loaded into the
//! watchdog timer counter.  If the \e ui32LoadVal parameter is 0, then an
//! interrupt is immediately generated.
//!
//! \note This function has no effect if the watchdog timer has been locked.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogReloadSet(uint32_t ui32Base, uint32_t ui32LoadVal)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Set the load register.
    //
    HWREG(ui32Base + WDT_O_LOAD) = ui32LoadVal;
}

//*****************************************************************************
//
//! Gets the watchdog timer reload value.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function gets the value that is loaded into the watchdog timer when
//! the count reaches zero for the first time.
//!
//! \return None.
//
//*****************************************************************************
uint32_t
WatchdogReloadGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Get the load register.
    //
    return(HWREG(ui32Base + WDT_O_LOAD));
}

//*****************************************************************************
//
//! Gets the current watchdog timer value.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function reads the current value of the watchdog timer.
//!
//! \return Returns the current value of the watchdog timer.
//
//*****************************************************************************
uint32_t
WatchdogValueGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Get the current watchdog timer register value.
    //
    return(HWREG(ui32Base + WDT_O_VALUE));
}

//*****************************************************************************
//
//! Registers an interrupt handler for the watchdog timer interrupt.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//! \param pfnHandler is a pointer to the function to be called when the
//! watchdog timer interrupt occurs.
//!
//! This function does the actual registering of the interrupt handler.  This
//! function also enables the global interrupt in the interrupt controller; the
//! watchdog timer interrupt must be enabled via WatchdogEnable().  It is the
//! interrupt handler's responsibility to clear the interrupt source via
//! WatchdogIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \note For parts with a watchdog timer module that has the ability to
//! generate an NMI instead of a standard interrupt, this function registers
//! the standard watchdog interrupt handler.  To register the NMI watchdog
//! handler, use IntRegister() to register the handler for the
//! \b FAULT_NMI interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_WATCHDOG_BLIZZARD, pfnHandler);

    //
    // Enable the watchdog timer interrupt.
    //
    IntEnable(INT_WATCHDOG_BLIZZARD);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the watchdog timer interrupt.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function does the actual unregistering of the interrupt handler.  This
//! function clears the handler to be called when a watchdog timer interrupt
//! occurs.  This function also masks off the interrupt in the interrupt
//! controller so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \note For parts with a watchdog timer module that has the ability to
//! generate an NMI instead of a standard interrupt, this function unregisters
//! the standard watchdog interrupt handler.  To unregister the NMI watchdog
//! handler, use IntUnregister() to unregister the handler for the
//! \b FAULT_NMI interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogIntUnregister(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Disable the interrupt.
    //
    IntDisable(INT_WATCHDOG_BLIZZARD);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_WATCHDOG_BLIZZARD);
}

//*****************************************************************************
//
//! Enables the watchdog timer interrupt.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function enables the watchdog timer interrupt.
//!
//! \note This function has no effect if the watchdog timer has been locked.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogIntEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Enable the watchdog interrupt.
    //
    HWREG(ui32Base + WDT_O_CTL) |= WDT_CTL_INTEN;
}

//*****************************************************************************
//
//! Gets the current watchdog timer interrupt status.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//! \param bMasked is \b false if the raw interrupt status is required and
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the watchdog timer module.
//! Either the raw interrupt status or the status of interrupt that is allowed
//! to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, where a 1 indicates that the
//! watchdog interrupt is active, and a 0 indicates that it is not active.
//
//*****************************************************************************
uint32_t
WatchdogIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ui32Base + WDT_O_MIS));
    }
    else
    {
        return(HWREG(ui32Base + WDT_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears the watchdog timer interrupt.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! The watchdog timer interrupt source is cleared, so that it no longer
//! asserts.
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
WatchdogIntClear(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Clear the interrupt source.
    //
    HWREG(ui32Base + WDT_O_ICR) = WDT_RIS_WDTRIS;
}

//*****************************************************************************
//
//! Sets the type of interrupt generated by the watchdog.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//! \param ui32Type is the type of interrupt to generate.
//!
//! This function sets the type of interrupt that is generated if the watchdog
//! timer expires.  \e ui32Type can be either \b WATCHDOG_INT_TYPE_INT to
//! generate a standard interrupt (the default) or \b WATCHDOG_INT_TYPE_NMI to
//! generate a non-maskable interrupt (NMI).
//!
//! When configured to generate an NMI, the watchdog interrupt must still be
//! enabled with WatchdogIntEnable(), and it must still be cleared inside the
//! NMI handler with WatchdogIntClear().
//!
//! \note The ability to select an NMI interrupt varies with the Tiva part
//! in use.  Please consult the datasheet for the part you are using to
//! determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogIntTypeSet(uint32_t ui32Base, uint32_t ui32Type)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));
    ASSERT((ui32Type == WATCHDOG_INT_TYPE_INT) ||
           (ui32Type == WATCHDOG_INT_TYPE_NMI));

    //
    // Set the interrupt type.
    //
    HWREG(ui32Base + WDT_O_CTL) = (HWREG(ui32Base + WDT_O_CTL) &
                                   ~WDT_CTL_INTTYPE) | ui32Type;
}

//*****************************************************************************
//
//! Enables stalling of the watchdog timer during debug events.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function allows the watchdog timer to stop counting when the processor
//! is stopped by the debugger.  By doing so, the watchdog is prevented from
//! expiring (typically almost immediately from a human time perspective) and
//! resetting the system (if reset is enabled).  The watchdog instead expires
//! after the appropriate number of processor cycles have been executed while
//! debugging (or at the appropriate time after the processor has been
//! restarted).
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogStallEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Enable timer stalling.
    //
    HWREG(ui32Base + WDT_O_TEST) |= WDT_TEST_STALL;
}

//*****************************************************************************
//
//! Disables stalling of the watchdog timer during debug events.
//!
//! \param ui32Base is the base address of the watchdog timer module.
//!
//! This function disables the debug mode stall of the watchdog timer.  By
//! doing so, the watchdog timer continues to count regardless of the processor
//! debug state.
//!
//! \return None.
//
//*****************************************************************************
void
WatchdogStallDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == WATCHDOG0_BASE) || (ui32Base == WATCHDOG1_BASE));

    //
    // Disable timer stalling.
    //
    HWREG(ui32Base + WDT_O_TEST) &= ~(WDT_TEST_STALL);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
