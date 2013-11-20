//*****************************************************************************
//
// pwm.c - API for the PWM modules
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
//! \addtogroup pwm_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_pwm.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/pwm.h"

//*****************************************************************************
//
// Misc macros for manipulating the encoded generator and output defines used
// by the API.
//
//*****************************************************************************
#define PWM_GEN_BADDR(_mod_, _gen_)                                           \
                                ((_mod_) + (_gen_))
#define PWM_GEN_EXT_BADDR(_mod_, _gen_)                                       \
                                ((_mod_) + PWM_GEN_EXT_0 +                    \
                                 ((_gen_) - PWM_GEN_0) * 2)
#define PWM_OUT_BADDR(_mod_, _out_)                                           \
                                ((_mod_) + ((_out_) & 0xFFFFFFC0))
#define PWM_IS_OUTPUT_ODD(_out_)                                              \
                                ((_out_) & 0x00000001)

//*****************************************************************************
//
//! \internal
//! Checks a PWM generator number.
//!
//! \param ui32Gen is the generator number.
//!
//! This function determines if a PWM generator number is valid.
//!
//! \return Returnes \b true if the generator number is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_PWMGenValid(uint32_t ui32Gen)
{
    return((ui32Gen == PWM_GEN_0) || (ui32Gen == PWM_GEN_1) ||
           (ui32Gen == PWM_GEN_2) || (ui32Gen == PWM_GEN_3));
}
#endif

//*****************************************************************************
//
//! \internal
//! Checks a PWM output number.
//!
//! \param ui32PWMOut is the output number.
//!
//! This function determines if a PWM output number is valid.
//!
//! \return Returns \b true if the output number is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_PWMOutValid(uint32_t ui32PWMOut)
{
    return((ui32PWMOut == PWM_OUT_0) || (ui32PWMOut == PWM_OUT_1) ||
           (ui32PWMOut == PWM_OUT_2) || (ui32PWMOut == PWM_OUT_3) ||
           (ui32PWMOut == PWM_OUT_4) || (ui32PWMOut == PWM_OUT_5) ||
           (ui32PWMOut == PWM_OUT_6) || (ui32PWMOut == PWM_OUT_7));
}
#endif

//*****************************************************************************
//
//! Configures a PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to configure.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Config is the configuration for the PWM generator.
//!
//! This function is used to set the mode of operation for a PWM generator.
//! The counting mode, synchronization mode, and debug behavior are all
//! configured.  After configuration, the generator is left in the disabled
//! state.
//!
//! A PWM generator can count in two different modes:  count down mode or count
//! up/down mode.  In count down mode, it counts from a value down to zero,
//! and then resets to the preset value, producing left-aligned PWM
//! signals (that is, the rising edge of the two PWM signals produced by the
//! generator occur at the same time).  In count up/down mode, it counts up
//! from zero to the preset value, counts back down to zero, and then repeats
//! the process, producing center-aligned PWM signals (that is,
//! the middle of the high/low period of the PWM signals produced by the
//! generator occurs at the same time).
//!
//! When the PWM generator parameters (period and pulse width) are modified,
//! their effect on the output PWM signals can be delayed.  In synchronous
//! mode, the parameter updates are not applied until a synchronization event
//! occurs.  This mode allows multiple parameters to be modified and take
//! effect simultaneously, instead of one at a time.  Additionally, parameters
//! to multiple PWM generators in synchronous mode can be updated
//! simultaneously, allowing them to be treated as if they were a unified
//! generator.  In non-synchronous mode, the parameter updates are not delayed
//! until a synchronization event.  In either mode, the parameter updates only
//! occur when the counter is at zero to help prevent oddly formed PWM signals
//! during the update (that is, a PWM pulse that is too short or too long).
//!
//! The PWM generator can either pause or continue running when the processor
//! is stopped via the debugger.  If configured to pause, it continues to
//! count until it reaches zero, at which point it pauses until the
//! processor is restarted.  If configured to continue running, it keeps
//! counting as if nothing had happened.
//!
//! The \e ui32Config parameter contains the desired configuration.  It is the
//! logical OR of the following:
//!
//! - \b PWM_GEN_MODE_DOWN or \b PWM_GEN_MODE_UP_DOWN to specify the counting
//!   mode
//! - \b PWM_GEN_MODE_SYNC or \b PWM_GEN_MODE_NO_SYNC to specify the counter
//!   load and comparator update synchronization mode
//! - \b PWM_GEN_MODE_DBG_RUN or \b PWM_GEN_MODE_DBG_STOP to specify the debug
//!   behavior
//! - \b PWM_GEN_MODE_GEN_NO_SYNC, \b PWM_GEN_MODE_GEN_SYNC_LOCAL, or
//!   \b PWM_GEN_MODE_GEN_SYNC_GLOBAL to specify the update synchronization
//!   mode for generator counting mode changes
//! - \b PWM_GEN_MODE_DB_NO_SYNC, \b PWM_GEN_MODE_DB_SYNC_LOCAL, or
//!   \b PWM_GEN_MODE_DB_SYNC_GLOBAL to specify the deadband parameter
//!   synchronization mode
//! - \b PWM_GEN_MODE_FAULT_LATCHED or \b PWM_GEN_MODE_FAULT_UNLATCHED to
//!   specify whether fault conditions are latched or not
//! - \b PWM_GEN_MODE_FAULT_MINPER or \b PWM_GEN_MODE_FAULT_NO_MINPER to
//!   specify whether minimum fault period support is required
//! - \b PWM_GEN_MODE_FAULT_EXT or \b PWM_GEN_MODE_FAULT_LEGACY to specify
//!   whether extended fault source selection support is enabled or not
//!
//! Setting \b PWM_GEN_MODE_FAULT_MINPER allows an application to set the
//! minimum duration of a PWM fault signal.  Faults are signaled for at
//! least this time even if the external fault pin deasserts earlier.  Care
//! should be taken when using this mode because during the fault signal
//! period, the fault interrupt from the PWM generator remains asserted.  The
//! fault interrupt handler may, therefore, reenter immediately if it exits
//! prior to expiration of the fault timer.
//!
//! \note Changes to the counter mode affect the period of the PWM signals
//! produced.  PWMGenPeriodSet() and PWMPulseWidthSet() should be called after
//! any changes to the counter mode of a generator.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenConfigure(uint32_t ui32Base, uint32_t ui32Gen,
                uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Compute the generator's base address.
    //
    ui32Gen = PWM_GEN_BADDR(ui32Base, ui32Gen);

    //
    // Change the global configuration of the generator.
    //
    HWREG(ui32Gen + PWM_O_X_CTL) = ((HWREG(ui32Gen + PWM_O_X_CTL) &
                                     ~(PWM_X_CTL_MODE | PWM_X_CTL_DEBUG |
                                       PWM_X_CTL_LATCH | PWM_X_CTL_MINFLTPER |
                                       PWM_X_CTL_FLTSRC |
                                       PWM_X_CTL_DBFALLUPD_M |
                                       PWM_X_CTL_DBRISEUPD_M |
                                       PWM_X_CTL_DBCTLUPD_M |
                                       PWM_X_CTL_GENBUPD_M |
                                       PWM_X_CTL_GENAUPD_M |
                                       PWM_X_CTL_LOADUPD | PWM_X_CTL_CMPAUPD |
                                       PWM_X_CTL_CMPBUPD)) | ui32Config);

    //
    // Set the individual PWM generator controls.
    //
    if(ui32Config & PWM_X_CTL_MODE)
    {
        //
        // In up/down count mode, set the signal high on up count comparison
        // and low on down count comparison (that is, center align the
        // signals).
        //
        HWREG(ui32Gen + PWM_O_X_GENA) = (PWM_X_GENA_ACTCMPAU_ONE |
                                         PWM_X_GENA_ACTCMPAD_ZERO);
        HWREG(ui32Gen + PWM_O_X_GENB) = (PWM_X_GENB_ACTCMPBU_ONE |
                                         PWM_X_GENB_ACTCMPBD_ZERO);
    }
    else
    {
        //
        // In down count mode, set the signal high on load and low on count
        // comparison (that is, left align the signals).
        //
        HWREG(ui32Gen + PWM_O_X_GENA) = (PWM_X_GENA_ACTLOAD_ONE |
                                         PWM_X_GENA_ACTCMPAD_ZERO);
        HWREG(ui32Gen + PWM_O_X_GENB) = (PWM_X_GENB_ACTLOAD_ONE |
                                         PWM_X_GENB_ACTCMPBD_ZERO);
    }
}

//*****************************************************************************
//
//! Sets the period of a PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to be modified.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Period specifies the period of PWM generator output, measured
//! in clock ticks.
//!
//! This function sets the period of the specified PWM generator block, where
//! the period of the generator block is defined as the number of PWM clock
//! ticks between pulses on the generator block zero signal.
//!
//! \note Any subsequent calls made to this function before an update occurs
//! cause the previous values to be overwritten.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenPeriodSet(uint32_t ui32Base, uint32_t ui32Gen,
                uint32_t ui32Period)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Compute the generator's base address.
    //
    ui32Gen = PWM_GEN_BADDR(ui32Base, ui32Gen);

    //
    // Set the reload register based on the mode.
    //
    if(HWREG(ui32Gen + PWM_O_X_CTL) & PWM_X_CTL_MODE)
    {
        //
        // In up/down count mode, set the reload register to half the requested
        // period.
        //
        ASSERT((ui32Period / 2) < 65536);
        HWREG(ui32Gen + PWM_O_X_LOAD) = ui32Period / 2;
    }
    else
    {
        //
        // In down count mode, set the reload register to the requested period
        // minus one.
        //
        ASSERT((ui32Period <= 65536) && (ui32Period != 0));
        HWREG(ui32Gen + PWM_O_X_LOAD) = ui32Period - 1;
    }
}

//*****************************************************************************
//
//! Gets the period of a PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to query.  This parameter must be one
//! of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//!
//! This function gets the period of the specified PWM generator block.  The
//! period of the generator block is defined as the number of PWM clock ticks
//! between pulses on the generator block zero signal.
//!
//! If the update of the counter for the specified PWM generator has yet
//! to be completed, the value returned may not be the active period.  The
//! value returned is the programmed period, measured in PWM clock ticks.
//!
//! \return Returns the programmed period of the specified generator block
//! in PWM clock ticks.
//
//*****************************************************************************
uint32_t
PWMGenPeriodGet(uint32_t ui32Base, uint32_t ui32Gen)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Compute the generator's base address.
    //
    ui32Gen = PWM_GEN_BADDR(ui32Base, ui32Gen);

    //
    // Figure out the counter mode.
    //
    if(HWREG(ui32Gen + PWM_O_X_CTL) & PWM_X_CTL_MODE)
    {
        //
        // The period is twice the reload register value.
        //
        return(HWREG(ui32Gen + PWM_O_X_LOAD) * 2);
    }
    else
    {
        //
        // The period is the reload register value plus one.
        //
        return(HWREG(ui32Gen + PWM_O_X_LOAD) + 1);
    }
}

//*****************************************************************************
//
//! Enables the timer/counter for a PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to be enabled.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//!
//! This function allows the PWM clock to drive the timer/counter for the
//! specified generator block.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenEnable(uint32_t ui32Base, uint32_t ui32Gen)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Enable the PWM generator.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_CTL) |= PWM_X_CTL_ENABLE;
}

//*****************************************************************************
//
//! Disables the timer/counter for a PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to be disabled.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//!
//! This function blocks the PWM clock from driving the timer/counter for the
//! specified generator block.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenDisable(uint32_t ui32Base, uint32_t ui32Gen)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Disable the PWM generator.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_CTL) &=
        ~(PWM_X_CTL_ENABLE);
}

//*****************************************************************************
//
//! Sets the pulse width for the specified PWM output.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOut is the PWM output to modify.  This parameter must be one
//! of \b PWM_OUT_0, \b PWM_OUT_1, \b PWM_OUT_2, \b PWM_OUT_3, \b PWM_OUT_4,
//! \b PWM_OUT_5, \b PWM_OUT_6, or \b PWM_OUT_7.
//! \param ui32Width specifies the width of the positive portion of the pulse.
//!
//! This function sets the pulse width for the specified PWM output, where the
//! pulse width is defined as the number of PWM clock ticks.
//!
//! \note Any subsequent calls made to this function before an update occurs
//! cause the previous values to be overwritten.
//!
//! \return None.
//
//*****************************************************************************
void
PWMPulseWidthSet(uint32_t ui32Base, uint32_t ui32PWMOut,
                 uint32_t ui32Width)
{
    uint32_t ui32GenBase, ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMOutValid(ui32PWMOut));

    //
    // Compute the generator's base address.
    //
    ui32GenBase = PWM_OUT_BADDR(ui32Base, ui32PWMOut);

    //
    // If the counter is in up/down count mode, divide the width by two.
    //
    if(HWREG(ui32GenBase + PWM_O_X_CTL) & PWM_X_CTL_MODE)
    {
        ui32Width /= 2;
    }

    //
    // Get the period.
    //
    ui32Reg = HWREG(ui32GenBase + PWM_O_X_LOAD);

    //
    // Make sure the width is not too large.
    //
    ASSERT(ui32Width < ui32Reg);

    //
    // Compute the compare value.
    //
    ui32Reg = ui32Reg - ui32Width;

    //
    // Write to the appropriate registers.
    //
    if(PWM_IS_OUTPUT_ODD(ui32PWMOut))
    {
        HWREG(ui32GenBase + PWM_O_X_CMPB) = ui32Reg;
    }
    else
    {
        HWREG(ui32GenBase + PWM_O_X_CMPA) = ui32Reg;
    }
}

//*****************************************************************************
//
//! Gets the pulse width of a PWM output.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOut is the PWM output to query.  This parameter must be one
//! of \b PWM_OUT_0, \b PWM_OUT_1, \b PWM_OUT_2, \b PWM_OUT_3, \b PWM_OUT_4,
//! \b PWM_OUT_5, \b PWM_OUT_6, or \b PWM_OUT_7.
//!
//! This function gets the currently programmed pulse width for the specified
//! PWM output.  If the update of the comparator for the specified output has
//! yet to be completed, the value returned may not be the active pulse width.
//! The value returned is the programmed pulse width, measured in PWM clock
//! ticks.
//!
//! \return Returns the width of the pulse in PWM clock ticks.
//
//*****************************************************************************
uint32_t
PWMPulseWidthGet(uint32_t ui32Base, uint32_t ui32PWMOut)
{
    uint32_t ui32GenBase, ui32Reg, ui32Load;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMOutValid(ui32PWMOut));

    //
    // Compute the generator's base address.
    //
    ui32GenBase = PWM_OUT_BADDR(ui32Base, ui32PWMOut);

    //
    // Then compute the pulse width.  If mode is UpDown, set
    // width = (load - compare) * 2.  Otherwise, set width = load - compare.
    //
    ui32Load = HWREG(ui32GenBase + PWM_O_X_LOAD);
    if(PWM_IS_OUTPUT_ODD(ui32PWMOut))
    {
        ui32Reg = HWREG(ui32GenBase + PWM_O_X_CMPB);
    }
    else
    {
        ui32Reg = HWREG(ui32GenBase + PWM_O_X_CMPA);
    }
    ui32Reg = ui32Load - ui32Reg;

    //
    // If in up/down count mode, double the pulse width.
    //
    if(HWREG(ui32GenBase + PWM_O_X_CTL) & PWM_X_CTL_MODE)
    {
        ui32Reg = ui32Reg * 2;
    }

    //
    // Return the pulse width.
    //
    return(ui32Reg);
}

//*****************************************************************************
//
//! Enables the PWM dead band output and sets the dead band delays.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to modify.  This parameter must be one
//! of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui16Rise specifies the width of delay from the rising edge.
//! \param ui16Fall specifies the width of delay from the falling edge.
//!
//! This function sets the dead bands for the specified PWM generator, where
//! the dead bands are defined as the number of \b PWM clock ticks from the
//! rising or falling edge of the generator's \b OutA signal.  Note that this
//! function causes the coupling of \b OutB to \b OutA.
//!
//! \return None.
//
//*****************************************************************************
void
PWMDeadBandEnable(uint32_t ui32Base, uint32_t ui32Gen,
                  uint16_t ui16Rise, uint16_t ui16Fall)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT(ui16Rise < 4096);
    ASSERT(ui16Fall < 4096);

    //
    // Compute the generator's base address.
    //
    ui32Gen = PWM_GEN_BADDR(ui32Base, ui32Gen);

    //
    // Write the dead band delay values.
    //
    HWREG(ui32Gen + PWM_O_X_DBRISE) = ui16Rise;
    HWREG(ui32Gen + PWM_O_X_DBFALL) = ui16Fall;

    //
    // Enable the deadband functionality.
    //
    HWREG(ui32Gen + PWM_O_X_DBCTL) |= PWM_X_DBCTL_ENABLE;
}

//*****************************************************************************
//
//! Disables the PWM dead band output.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to modify.  This parameter must be one
//! of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//!
//! This function disables the dead band mode for the specified PWM generator.
//! Doing so decouples the \b OutA and \b OutB signals.
//!
//! \return None.
//
//*****************************************************************************
void
PWMDeadBandDisable(uint32_t ui32Base, uint32_t ui32Gen)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Disable the deadband functionality.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_DBCTL) &=
        ~(PWM_X_DBCTL_ENABLE);
}

//*****************************************************************************
//
//! Synchronizes all pending updates.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32GenBits are the PWM generator blocks to be updated.  This
//! parameter must be the logical OR of any of \b PWM_GEN_0_BIT,
//! \b PWM_GEN_1_BIT, \b PWM_GEN_2_BIT, or \b PWM_GEN_3_BIT.
//!
//! For the selected PWM generators, this function causes all queued updates to
//! the period or pulse width to be applied the next time the corresponding
//! counter becomes zero.
//!
//! \return None.
//
//*****************************************************************************
void
PWMSyncUpdate(uint32_t ui32Base, uint32_t ui32GenBits)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32GenBits & ~(PWM_GEN_0_BIT | PWM_GEN_1_BIT | PWM_GEN_2_BIT |
                             PWM_GEN_3_BIT)));

    //
    // Synchronize pending PWM register changes.
    //
    HWREG(ui32Base + PWM_O_CTL) = ui32GenBits;
}

//*****************************************************************************
//
//! Synchronizes the counters in one or multiple PWM generator blocks.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32GenBits are the PWM generator blocks to be synchronized.  This
//! parameter must be the logical OR of any of \b PWM_GEN_0_BIT,
//! \b PWM_GEN_1_BIT, \b PWM_GEN_2_BIT, or \b PWM_GEN_3_BIT.
//!
//! For the selected PWM module, this function synchronizes the time base of
//! the generator blocks by causing the specified generator counters to be
//! reset to zero.
//!
//! \return None.
//
//*****************************************************************************
void
PWMSyncTimeBase(uint32_t ui32Base, uint32_t ui32GenBits)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32GenBits & ~(PWM_GEN_0_BIT | PWM_GEN_1_BIT | PWM_GEN_2_BIT |
                             PWM_GEN_3_BIT)));

    //
    // Synchronize the counters in the specified generators by writing to the
    // module's synchronization register.
    //
    HWREG(ui32Base + PWM_O_SYNC) = ui32GenBits;
}

//*****************************************************************************
//
//! Enables or disables PWM outputs.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOutBits are the PWM outputs to be modified.  This parameter
//! must be the logical OR of any of \b PWM_OUT_0_BIT, \b PWM_OUT_1_BIT,
//! \b PWM_OUT_2_BIT, \b PWM_OUT_3_BIT, \b PWM_OUT_4_BIT, \b PWM_OUT_5_BIT,
//! \b PWM_OUT_6_BIT, or \b PWM_OUT_7_BIT.
//! \param bEnable determines if the signal is enabled or disabled.
//!
//! This function enables or disables the selected PWM outputs.  The outputs
//! are selected using the parameter \e ui32PWMOutBits.  The parameter \e
//! bEnable determines the state of the selected outputs.  If \e bEnable is
//! \b true, then the selected PWM outputs are enabled, or placed in the active
//! state.  If \e bEnable is \b false, then the selected outputs are disabled
//! or placed in the inactive state.
//!
//! \return None.
//
//*****************************************************************************
void
PWMOutputState(uint32_t ui32Base, uint32_t ui32PWMOutBits,
               bool bEnable)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32PWMOutBits & ~(PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT |
                                PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT |
                                PWM_OUT_6_BIT | PWM_OUT_7_BIT)));

    //
    // Read the module's ENABLE output control register and set or clear the
    // requested bits.
    //
    if(bEnable == true)
    {
        HWREG(ui32Base + PWM_O_ENABLE) |= ui32PWMOutBits;
    }
    else
    {
        HWREG(ui32Base + PWM_O_ENABLE) &= ~(ui32PWMOutBits);
    }
}

//*****************************************************************************
//
//! Selects the inversion mode for PWM outputs.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOutBits are the PWM outputs to be modified.  This parameter
//! must be the logical OR of any of \b PWM_OUT_0_BIT, \b PWM_OUT_1_BIT,
//! \b PWM_OUT_2_BIT, \b PWM_OUT_3_BIT, \b PWM_OUT_4_BIT, \b PWM_OUT_5_BIT,
//! \b PWM_OUT_6_BIT, or \b PWM_OUT_7_BIT.
//! \param bInvert determines if the signal is inverted or passed through.
//!
//! This function is used to select the inversion mode for the selected PWM
//! outputs.  The outputs are selected using the parameter \e ui32PWMOutBits.
//! The parameter \e bInvert determines the inversion mode for the selected
//! outputs.  If \e bInvert is \b true, this function causes the specified
//! PWM output signals to be inverted or made active low.  If \e bInvert is
//! \b false, the specified outputs are passed through as is or made active
//! high.
//!
//! \return None.
//
//*****************************************************************************
void
PWMOutputInvert(uint32_t ui32Base, uint32_t ui32PWMOutBits,
                bool bInvert)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32PWMOutBits & ~(PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT |
                                PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT |
                                PWM_OUT_6_BIT | PWM_OUT_7_BIT)));

    //
    // Read the module's INVERT output control register and set or clear the
    // requested bits.
    //
    if(bInvert == true)
    {
        HWREG(ui32Base + PWM_O_INVERT) |= ui32PWMOutBits;
    }
    else
    {
        HWREG(ui32Base + PWM_O_INVERT) &= ~(ui32PWMOutBits);
    }
}

//*****************************************************************************
//
//! Specifies the level of PWM outputs suppressed in response to a fault
//! condition.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOutBits are the PWM outputs to be modified.  This parameter
//! must be the logical OR of any of \b PWM_OUT_0_BIT, \b PWM_OUT_1_BIT,
//! \b PWM_OUT_2_BIT, \b PWM_OUT_3_BIT, \b PWM_OUT_4_BIT, \b PWM_OUT_5_BIT,
//! \b PWM_OUT_6_BIT, or \b PWM_OUT_7_BIT.
//! \param bDriveHigh determines if the signal is driven high or low during an
//! active fault condition.
//!
//! This function determines whether a PWM output pin that is suppressed in
//! response to a fault condition is driven high or low.  The affected outputs
//! are selected using the parameter \e ui32PWMOutBits.  The parameter
//! \e bDriveHigh determines the output level for the pins identified by
//! \e ui32PWMOutBits.  If \e bDriveHigh is \b true then the selected outputs
//! are driven high when a fault is detected.  If it is \e false, the pins are
//! driven low.
//!
//! In a fault condition, pins which have not been configured to be suppressed
//! via a call to PWMOutputFault() are unaffected by this function.
//!
//! \note This function is available only on devices which support extended
//! PWM fault handling.
//!
//! \return None.
//
//*****************************************************************************
void
PWMOutputFaultLevel(uint32_t ui32Base, uint32_t ui32PWMOutBits,
                    bool bDriveHigh)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32PWMOutBits & ~(PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT |
                                PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT |
                                PWM_OUT_6_BIT | PWM_OUT_7_BIT)));

    //
    // Read the module's FAULT output control register and set or clear the
    // requested bits.
    //
    if(bDriveHigh == true)
    {
        HWREG(ui32Base + PWM_O_FAULTVAL) |= ui32PWMOutBits;
    }
    else
    {
        HWREG(ui32Base + PWM_O_FAULTVAL) &= ~(ui32PWMOutBits);
    }
}

//*****************************************************************************
//
//! Specifies the state of PWM outputs in response to a fault condition.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOutBits are the PWM outputs to be modified.  This parameter
//! must be the  logical OR of any of \b PWM_OUT_0_BIT, \b PWM_OUT_1_BIT,
//! \b PWM_OUT_2_BIT, \b PWM_OUT_3_BIT, \b PWM_OUT_4_BIT, \b PWM_OUT_5_BIT,
//! \b PWM_OUT_6_BIT, or \b PWM_OUT_7_BIT.
//! \param bFaultSuppress determines if the signal is suppressed or passed
//! through during an active fault condition.
//!
//! This function sets the fault handling characteristics of the selected PWM
//! outputs.  The outputs are selected using the parameter \e ui32PWMOutBits.
//! The parameter \e bFaultSuppress determines the fault handling
//! characteristics for the selected outputs.  If \e bFaultSuppress is \b true,
//! then the selected outputs are made inactive.  If \e bFaultSuppress is
//! \b false, then the selected outputs are unaffected by the detected fault.
//!
//! On devices supporting extended PWM fault handling, the state the affected
//! output pins are driven to can be configured with PWMOutputFaultLevel().  If
//! not configured, or if the device does not support extended PWM fault
//! handling, affected outputs are driven low on a fault condition.
//!
//! \return None.
//
//*****************************************************************************
void
PWMOutputFault(uint32_t ui32Base, uint32_t ui32PWMOutBits,
               bool bFaultSuppress)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32PWMOutBits & ~(PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT |
                                PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT |
                                PWM_OUT_6_BIT | PWM_OUT_7_BIT)));

    //
    // Read the module's FAULT output control register and set or clear the
    // requested bits.
    //
    if(bFaultSuppress == true)
    {
        HWREG(ui32Base + PWM_O_FAULT) |= ui32PWMOutBits;
    }
    else
    {
        HWREG(ui32Base + PWM_O_FAULT) &= ~(ui32PWMOutBits);
    }
}

//*****************************************************************************
//
//! Gets the PWM generator interrupt number.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator in question.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//!
//! This function returns the interrupt number of the corresponding PWM
//! generator.
//!
//! \return Returns the interrupt number.
//
//*****************************************************************************
static uint32_t
_PWMGenIntNumberGet(uint32_t ui32Base, uint32_t ui32Gen)
{
    //
    // Determine the generator and PWM module in question.
    //
    switch(ui32Base + ui32Gen)
    {
        //
        // The first PWM generator in the first PWM module.
        //
        case PWM0_BASE + PWM_GEN_0:
        {
            if(CLASS_IS_BLIZZARD)
            {
                return(INT_PWM0_0_BLIZZARD);
            }
            else if(CLASS_IS_SNOWFLAKE)
            {
                return(INT_PWM0_0_SNOWFLAKE);
            }
            else
            {
                return(0);
            }
        }

        //
        // The second PWM generator in the first PWM module.
        //
        case PWM0_BASE + PWM_GEN_1:
        {
            if(CLASS_IS_SNOWFLAKE)
            {
                return(INT_PWM0_1_SNOWFLAKE);
            }
            else
            {
                return(0);
            }
        }

        //
        // The third PWM generator in the first PWM module.
        //
        case PWM0_BASE + PWM_GEN_2:
        {
            if(CLASS_IS_SNOWFLAKE)
            {
                return(INT_PWM0_2_SNOWFLAKE);
            }
            else
            {
                return(0);
            }
        }

        //
        // The fourth PWM generator in the first PWM module.
        //
        case PWM0_BASE + PWM_GEN_3:
        {
            if(CLASS_IS_SNOWFLAKE)
            {
                return(INT_PWM0_3_SNOWFLAKE);
            }
            else
            {
                return(0);
            }
        }

        //
        // The first PWM generator in the second PWM module.
        //
        case PWM1_BASE + PWM_GEN_0:
        {
            if(CLASS_IS_BLIZZARD)
            {
                return(INT_PWM1_0_BLIZZARD);
            }
            else
            {
                return(0);
            }
        }

        //
        // The first PWM generator in the second PWM module.
        //
        case PWM1_BASE + PWM_GEN_1:
        {
            if(CLASS_IS_BLIZZARD)
            {
                return(INT_PWM1_1_BLIZZARD);
            }
            else
            {
                return(0);
            }
        }

        //
        // The first PWM generator in the second PWM module.
        //
        case PWM1_BASE + PWM_GEN_2:
        {
            if(CLASS_IS_BLIZZARD)
            {
                return(INT_PWM1_2_BLIZZARD);
            }
            else
            {
                return(0);
            }
        }

        //
        // The first PWM generator in the second PWM module.
        //
        case PWM1_BASE + PWM_GEN_3:
        {
            if(CLASS_IS_BLIZZARD)
            {
                return(INT_PWM1_3_BLIZZARD);
            }
            else
            {
                return(0);
            }
        }

        //
        // An unknown PWM module/generator was specified.
        //
        default:
        {
            return(0);
        }
    }
}

//*****************************************************************************
//
//! Registers an interrupt handler for the specified PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator in question.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param pfnIntHandler is a pointer to the function to be called when the PWM
//! generator interrupt occurs.
//!
//! This function ensures that the interrupt handler specified by
//! \e pfnIntHandler is called when an interrupt is detected for the specified
//! PWM generator block.  This function also enables the corresponding
//! PWM generator interrupt in the interrupt controller; individual generator
//! interrupts and interrupt sources must be enabled with PWMIntEnable() and
//! PWMGenIntTrigEnable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenIntRegister(uint32_t ui32Base, uint32_t ui32Gen,
                  void (*pfnIntHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Get the interrupt number associated with the specified generator.
    //
    ui32Int = _PWMGenIntNumberGet(ui32Base, ui32Gen);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnIntHandler);

    //
    // Enable the PWMx interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Removes an interrupt handler for the specified PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator in question.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//!
//! This function unregisters the interrupt handler for the specified
//! PWM generator block.  This function also disables the corresponding
//! PWM generator interrupt in the interrupt controller; individual generator
//! interrupts and interrupt sources must be disabled with PWMIntDisable() and
//! PWMGenIntTrigDisable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenIntUnregister(uint32_t ui32Base, uint32_t ui32Gen)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Get the interrupt number associated with the specified generator.
    //
    ui32Int = _PWMGenIntNumberGet(ui32Base, ui32Gen);

    ASSERT(ui32Int != 0);

    //
    // Disable the PWMx interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Gets the PWM fault interrupt number.
//!
//! \param ui32Base is the base address of the PWM module.
//!
//! This function returns the fault interrupt number of the corresponding
//! PWM module.
//!
//! \return Returns the interrupt number.
//
//*****************************************************************************
static uint32_t
_PWMFaultIntNumberGet(uint32_t ui32Base)
{
    //
    // Return the fault interrupt number.
    //
    if(CLASS_IS_BLIZZARD)
    {
        return((ui32Base == PWM0_BASE) ? INT_PWM0_FAULT_BLIZZARD :
               INT_PWM1_FAULT_BLIZZARD);
    }
    else if(CLASS_IS_SNOWFLAKE)
    {
        return((ui32Base == PWM0_BASE) ? INT_PWM0_FAULT_SNOWFLAKE : 0);
    }
    else
    {
        return(0);
    }
}

//*****************************************************************************
//
//! Registers an interrupt handler for a fault condition detected in a PWM
//! module.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param pfnIntHandler is a pointer to the function to be called when the PWM
//! fault interrupt occurs.
//!
//! This function ensures that the interrupt handler specified by
//! \e pfnIntHandler is called when a fault interrupt is detected for the
//! selected PWM module.  This function also enables the PWM fault
//! interrupt in the NVIC; the PWM fault interrupt must also be enabled at the
//! module level using PWMIntEnable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
PWMFaultIntRegister(uint32_t ui32Base, void (*pfnIntHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));

    //
    // Get the interrupt number associated with the specified module.
    //
    ui32Int = _PWMFaultIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler, returning an error if one occurs.
    //
    IntRegister(ui32Int, pfnIntHandler);

    //
    // Enable the PWM fault interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Removes the PWM fault condition interrupt handler.
//!
//! \param ui32Base is the base address of the PWM module.
//!
//! This function removes the interrupt handler for a PWM fault interrupt
//! from the selected PWM module.  This function also disables the PWM
//! fault interrupt in the NVIC; the PWM fault interrupt must also be disabled
//! at the module level using PWMIntDisable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
PWMFaultIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));

    //
    // Get the interrupt number associated with the specified module.
    //
    ui32Int = _PWMFaultIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Disable the PWM fault interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler, returning an error if one occurs.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Enables interrupts and triggers for the specified PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to have interrupts and triggers
//! enabled.  This parameter must be one of \b PWM_GEN_0, \b PWM_GEN_1,
//! \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32IntTrig specifies the interrupts and triggers to be enabled.
//!
//! This function unmasks the specified interrupt(s) and trigger(s) by setting
//! the specified bits of the interrupt/trigger enable register for the
//! specified PWM generator.  The \e ui32IntTrig parameter is the logical OR of
//! \b PWM_INT_CNT_ZERO, \b PWM_INT_CNT_LOAD, \b PWM_INT_CNT_AU,
//! \b PWM_INT_CNT_AD, \b PWM_INT_CNT_BU, \b PWM_INT_CNT_BD,
//! \b PWM_TR_CNT_ZERO, \b PWM_TR_CNT_LOAD, \b PWM_TR_CNT_AU, \b PWM_TR_CNT_AD,
//! \b PWM_TR_CNT_BU, or \b PWM_TR_CNT_BD.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenIntTrigEnable(uint32_t ui32Base, uint32_t ui32Gen,
                    uint32_t ui32IntTrig)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32IntTrig & ~(PWM_INT_CNT_ZERO | PWM_INT_CNT_LOAD |
                            PWM_INT_CNT_AU | PWM_INT_CNT_AD | PWM_INT_CNT_BU |
                            PWM_INT_CNT_BD | PWM_TR_CNT_ZERO |
                            PWM_TR_CNT_LOAD | PWM_TR_CNT_AU | PWM_TR_CNT_AD |
                            PWM_TR_CNT_BU | PWM_TR_CNT_BD)) == 0);

    //
    // Enable the specified interrupts/triggers.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_INTEN) |= ui32IntTrig;
}

//*****************************************************************************
//
//! Disables interrupts for the specified PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to have interrupts and triggers
//! disabled.  This parameter must be one of \b PWM_GEN_0, \b PWM_GEN_1,
//! \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32IntTrig specifies the interrupts and triggers to be disabled.
//!
//! This function masks the specified interrupt(s) and trigger(s) by clearing
//! the specified bits of the interrupt/trigger enable register for the
//! specified PWM generator.  The \e ui32IntTrig parameter is the logical OR of
//! \b PWM_INT_CNT_ZERO, \b PWM_INT_CNT_LOAD, \b PWM_INT_CNT_AU,
//! \b PWM_INT_CNT_AD, \b PWM_INT_CNT_BU, \b PWM_INT_CNT_BD,
//! \b PWM_TR_CNT_ZERO, \b PWM_TR_CNT_LOAD, \b PWM_TR_CNT_AU, \b PWM_TR_CNT_AD,
//! \b PWM_TR_CNT_BU, or \b PWM_TR_CNT_BD.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenIntTrigDisable(uint32_t ui32Base, uint32_t ui32Gen,
                     uint32_t ui32IntTrig)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32IntTrig & ~(PWM_INT_CNT_ZERO | PWM_INT_CNT_LOAD |
                            PWM_INT_CNT_AU | PWM_INT_CNT_AD | PWM_INT_CNT_BU |
                            PWM_INT_CNT_BD | PWM_TR_CNT_ZERO |
                            PWM_TR_CNT_LOAD | PWM_TR_CNT_AU | PWM_TR_CNT_AD |
                            PWM_TR_CNT_BU | PWM_TR_CNT_BD)) == 0);

    //
    // Disable the specified interrupts/triggers.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_INTEN) &= ~(ui32IntTrig);
}

//*****************************************************************************
//
//! Gets interrupt status for the specified PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to query.  This parameter must be one
//! of \b PWM_GEN_0,  \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param bMasked specifies whether masked or raw interrupt status is
//! returned.
//!
//! If \e bMasked is set as \b true, then the masked interrupt status is
//! returned; otherwise, the raw interrupt status is returned.
//!
//! \return Returns the contents of the interrupt status register or the
//! contents of the raw interrupt status register for the specified
//! PWM generator.
//
//*****************************************************************************
uint32_t
PWMGenIntStatus(uint32_t ui32Base, uint32_t ui32Gen, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));

    //
    // Compute the generator's base address.
    //
    ui32Gen = PWM_GEN_BADDR(ui32Base, ui32Gen);

    //
    // Read and return the specified generator's raw or enabled interrupt
    // status.
    //
    if(bMasked == true)
    {
        return(HWREG(ui32Gen + PWM_O_X_ISC));
    }
    else
    {
        return(HWREG(ui32Gen + PWM_O_X_RIS));
    }
}

//*****************************************************************************
//
//! Clears the specified interrupt(s) for the specified PWM generator block.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to query.  This parameter must be one
//! of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Ints specifies the interrupts to be cleared.
//!
//! This function clears the specified interrupt(s) by writing a 1 to the
//! specified bits of the interrupt status register for the specified PWM
//! generator.  The \e ui32Ints parameter is the logical OR of
//! \b PWM_INT_CNT_ZERO, \b PWM_INT_CNT_LOAD, \b PWM_INT_CNT_AU,
//! \b PWM_INT_CNT_AD, \b PWM_INT_CNT_BU, or \b PWM_INT_CNT_BD.
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
PWMGenIntClear(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Ints)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32Ints &
            ~(PWM_INT_CNT_ZERO | PWM_INT_CNT_LOAD | PWM_INT_CNT_AU |
              PWM_INT_CNT_AD | PWM_INT_CNT_BU | PWM_INT_CNT_BD)) == 0);

    //
    // Clear the requested interrupts by writing ones to the specified bit
    // of the module's interrupt enable register.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_ISC) = ui32Ints;
}

//*****************************************************************************
//
//! Enables generator and fault interrupts for a PWM module.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32GenFault contains the interrupts to be enabled.  This parameter
//! must be a logical OR of any of \b PWM_INT_GEN_0, \b PWM_INT_GEN_1,
//! \b PWM_INT_GEN_2, \b PWM_INT_GEN_3, \b PWM_INT_FAULT0, \b PWM_INT_FAULT1,
//! \b PWM_INT_FAULT2, or \b PWM_INT_FAULT3.
//!
//! This function unmasks the specified interrupt(s) by setting the specified
//! bits of the interrupt enable register for the selected PWM module.
//!
//! \return None.
//
//*****************************************************************************
void
PWMIntEnable(uint32_t ui32Base, uint32_t ui32GenFault)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT((ui32GenFault & ~(PWM_INT_GEN_0 | PWM_INT_GEN_1 | PWM_INT_GEN_2 |
                             PWM_INT_GEN_3 | PWM_INT_FAULT0 | PWM_INT_FAULT1 |
                             PWM_INT_FAULT2 | PWM_INT_FAULT3)) == 0);

    //
    // Read the module's interrupt enable register and enable interrupts
    // for the specified PWM generators.
    //
    HWREG(ui32Base + PWM_O_INTEN) |= ui32GenFault;
}

//*****************************************************************************
//
//! Disables generator and fault interrupts for a PWM module.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32GenFault contains the interrupts to be disabled.  This parameter
//! must be a logical OR of any of \b PWM_INT_GEN_0, \b PWM_INT_GEN_1,
//! \b PWM_INT_GEN_2, \b PWM_INT_GEN_3, \b PWM_INT_FAULT0, \b PWM_INT_FAULT1,
//! \b PWM_INT_FAULT2, or \b PWM_INT_FAULT3.
//!
//! This function masks the specified interrupt(s) by clearing the specified
//! bits of the interrupt enable register for the selected PWM module.
//!
//! \return None.
//
//*****************************************************************************
void
PWMIntDisable(uint32_t ui32Base, uint32_t ui32GenFault)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT((ui32GenFault & ~(PWM_INT_GEN_0 | PWM_INT_GEN_1 | PWM_INT_GEN_2 |
                             PWM_INT_GEN_3 | PWM_INT_FAULT0 | PWM_INT_FAULT1 |
                             PWM_INT_FAULT2 | PWM_INT_FAULT3)) == 0);

    //
    // Read the module's interrupt enable register and disable interrupts
    // for the specified PWM generators.
    //
    HWREG(ui32Base + PWM_O_INTEN) &= ~(ui32GenFault);
}

//*****************************************************************************
//
//! Clears the fault interrupt for a PWM module.
//!
//! \param ui32Base is the base address of the PWM module.
//!
//! This function clears the fault interrupt by writing to the appropriate bit
//! of the interrupt status register for the selected PWM module.
//!
//! This function clears only the FAULT0 interrupt and is retained for
//! backwards compatibility.  It is recommended that PWMFaultIntClearExt() be
//! used instead because it supports all fault interrupts supported on devices
//! with and without extended PWM fault handling support.
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
PWMFaultIntClear(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));

    //
    // Write the only writeable bit in the module's interrupt register.
    //
    HWREG(ui32Base + PWM_O_ISC) = PWM_ISC_INTFAULT0;
}

//*****************************************************************************
//
//! Gets the interrupt status for a PWM module.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param bMasked specifies whether masked or raw interrupt status is
//! returned.
//!
//! If \e bMasked is set as \b true, then the masked interrupt status is
//! returned; otherwise, the raw interrupt status is returned.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! \b PWM_INT_GEN_0, \b PWM_INT_GEN_1, \b PWM_INT_GEN_2, \b PWM_INT_GEN_3,
//! \b PWM_INT_FAULT0, \b PWM_INT_FAULT1, \b PWM_INT_FAULT2, and
//! \b PWM_INT_FAULT3.
//!
//*****************************************************************************
uint32_t
PWMIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));

    //
    // Read and return either the module's raw or enabled interrupt status.
    //
    if(bMasked == true)
    {
        return(HWREG(ui32Base + PWM_O_ISC));
    }
    else
    {
        return(HWREG(ui32Base + PWM_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears the fault interrupt for a PWM module.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32FaultInts specifies the fault interrupts to clear.
//!
//! This function clears one or more fault interrupts by writing to the
//!  appropriate bit of the PWM interrupt status register.  The parameter
//! \e ui32FaultInts must be the logical OR of any of \b PWM_INT_FAULT0,
//! \b PWM_INT_FAULT1, \b PWM_INT_FAULT2, or \b PWM_INT_FAULT3.
//!
//! When running on a device supporting extended PWM fault handling, the fault
//! interrupts are derived by performing a logical OR of each of the configured
//! fault trigger signals for a given generator.  Therefore, these interrupts
//! are not directly related to the four possible FAULTn inputs to the device
//! but indicate that a fault has been signaled to one of the four possible PWM
//! generators.  On a device without extended PWM fault handling, the interrupt
//! is directly related to the state of the single FAULT pin.
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
PWMFaultIntClearExt(uint32_t ui32Base, uint32_t ui32FaultInts)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT((ui32FaultInts & ~(PWM_INT_FAULT0 | PWM_INT_FAULT1 |
                              PWM_INT_FAULT2 | PWM_INT_FAULT3)) == 0);

    //
    // Clear the supplied fault bits.
    //
    HWREG(ui32Base + PWM_O_ISC) = ui32FaultInts;
}

//*****************************************************************************
//
//! Configures the minimum fault period and fault pin senses for a given
//! PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator for which fault configuration is being
//! set.  This function must be one of \b PWM_GEN_0, \b PWM_GEN_1,
//! \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32MinFaultPeriod is the minimum fault active period expressed in
//! PWM clock cycles.
//! \param ui32FaultSenses indicates which sense of each FAULT input should be
//! considered the ``asserted'' state.  Valid values are logical OR
//! combinations of \b PWM_FAULTn_SENSE_HIGH and \b PWM_FAULTn_SENSE_LOW.
//!
//! This function configures the minimum fault period for a given generator
//! along with the sense of each of the 4 possible fault inputs.  The minimum
//! fault period is expressed in PWM clock cycles and takes effect only if
//! PWMGenConfigure() is called with flag \b PWM_GEN_MODE_FAULT_PER set in the
//! \e ui32Config parameter.  When a fault input is asserted, the minimum fault
//! period timer ensures that it remains asserted for at least the number of
//! clock cycles specified.
//!
//! \note This function is only available on devices supporting extended PWM
//! fault handling.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenFaultConfigure(uint32_t ui32Base, uint32_t ui32Gen,
                     uint32_t ui32MinFaultPeriod,
                     uint32_t ui32FaultSenses)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT(ui32MinFaultPeriod < PWM_X_MINFLTPER_M);
    ASSERT((ui32FaultSenses & ~(PWM_FAULT0_SENSE_HIGH | PWM_FAULT0_SENSE_LOW |
                                PWM_FAULT1_SENSE_HIGH | PWM_FAULT1_SENSE_LOW |
                                PWM_FAULT2_SENSE_HIGH | PWM_FAULT2_SENSE_LOW |
                                PWM_FAULT3_SENSE_HIGH |
                                PWM_FAULT3_SENSE_LOW)) == 0);

    //
    // Write the minimum fault period.
    //
    HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_MINFLTPER) =
        ui32MinFaultPeriod;

    //
    // Write the fault senses.
    //
    HWREG(PWM_GEN_EXT_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSEN) =
        ui32FaultSenses;
}

//*****************************************************************************
//
//! Configures the set of fault triggers for a given PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator for which fault triggers are being set.
//! This parameter must be one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or
//! \b PWM_GEN_3.
//! \param ui32Group indicates the subset of possible faults that are to be
//! configured.  This parameter must be \b PWM_FAULT_GROUP_0 or
//! \b PWM_FAULT_GROUP_1.
//! \param ui32FaultTriggers defines the set of inputs that are to contribute
//! towards generation of the fault signal to the given PWM generator.  For
//! \b PWM_FAULT_GROUP_0, this is the logical OR of \b PWM_FAULT_FAULT0,
//! \b PWM_FAULT_FAULT1, \b PWM_FAULT_FAULT2, or \b PWM_FAULT_FAULT3.  For
//! \b PWM_FAULT_GROUP_1, this is the logical OR of \b PWM_FAULT_DCMP0,
//! \b PWM_FAULT_DCMP1, \b PWM_FAULT_DCMP2, \b PWM_FAULT_DCMP3,
//! \b PWM_FAULT_DCMP4, \b PWM_FAULT_DCMP5, \b PWM_FAULT_DCMP6, or
//! \b PWM_FAULT_DCMP7.
//!
//! This function allows selection of the set of fault inputs that is combined
//! to generate a fault condition to a given PWM generator.  By default, all
//! generators use only FAULT0 (for backwards compatibility) but if
//! PWMGenConfigure() is called with flag \b PWM_GEN_MODE_FAULT_SRC in the
//! \e ui32Config parameter, extended fault handling is enabled and this
//! function must be called to configure the fault triggers.
//!
//! The fault signal to the PWM generator is generated by ORing together each
//! of the signals specified in the \e ui32FaultTriggers parameter after having
//! adjusted the sense of each FAULTn input based on the configuration
//! previously set using a call to PWMGenFaultConfigure().
//!
//! \note This function is only available on devices supporting extended PWM
//! fault handling.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenFaultTriggerSet(uint32_t ui32Base, uint32_t ui32Gen,
                      uint32_t ui32Group, uint32_t ui32FaultTriggers)
{
    //
    // Check for valid parameters.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32Group == PWM_FAULT_GROUP_0) ||
           (ui32Group == PWM_FAULT_GROUP_1));
    ASSERT((ui32Group == PWM_FAULT_GROUP_0) &&
           ((ui32FaultTriggers & ~(PWM_FAULT_FAULT0 | PWM_FAULT_FAULT1 |
                                   PWM_FAULT_FAULT2 | PWM_FAULT_FAULT3)) ==
            0));
    ASSERT((ui32Group == PWM_FAULT_GROUP_1) &&
           ((ui32FaultTriggers & ~(PWM_FAULT_DCMP0 | PWM_FAULT_DCMP1 |
                                   PWM_FAULT_DCMP2 | PWM_FAULT_DCMP3 |
                                   PWM_FAULT_DCMP4 | PWM_FAULT_DCMP5 |
                                   PWM_FAULT_DCMP6 | PWM_FAULT_DCMP7)) == 0));

    //
    // Write the fault triggers to the appropriate register.
    //
    if(ui32Group == PWM_FAULT_GROUP_0)
    {
        HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSRC0) =
            ui32FaultTriggers;
    }
    else
    {
        HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSRC1) =
            ui32FaultTriggers;
    }
}

//*****************************************************************************
//
//! Returns the set of fault triggers currently configured for a given PWM
//! generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator for which fault triggers are being
//! queried.  This parameter must be one of \b PWM_GEN_0, \b PWM_GEN_1,
//! \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Group indicates the subset of faults that are being queried.
//! This parameter must be \b PWM_FAULT_GROUP_0 or \b PWM_FAULT_GROUP_1.
//!
//! This function allows an application to query the current set of inputs that
//! contribute to the generation of a fault condition to a given PWM generator.
//!
//! \note This function is only available on devices supporting extended PWM
//! fault handling.
//!
//! \return Returns the current fault triggers configured for the fault group
//! provided.  For \b PWM_FAULT_GROUP_0, the returned value is a logical OR of
//! \b PWM_FAULT_FAULT0, \b PWM_FAULT_FAULT1, \b PWM_FAULT_FAULT2, or
//! \b PWM_FAULT_FAULT3.  For \b PWM_FAULT_GROUP_1, the return value is the
//! logical OR of \b PWM_FAULT_DCMP0, \b PWM_FAULT_DCMP1,
//! \b PWM_FAULT_DCMP2, \b PWM_FAULT_DCMP3, \b PWM_FAULT_DCMP4,
//! \b PWM_FAULT_DCMP5, \b PWM_FAULT_DCMP6, or \b PWM_FAULT_DCMP7.
//
//*****************************************************************************
uint32_t
PWMGenFaultTriggerGet(uint32_t ui32Base, uint32_t ui32Gen,
                      uint32_t ui32Group)
{
    //
    // Check for valid parameters.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32Group == PWM_FAULT_GROUP_0) ||
           (ui32Group == PWM_FAULT_GROUP_1));

    //
    // Return the current fault triggers.
    //
    if(ui32Group == PWM_FAULT_GROUP_0)
    {
        return(HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSRC0));
    }
    else
    {
        return(HWREG(PWM_GEN_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSRC1));
    }
}

//*****************************************************************************
//
//! Returns the current state of the fault triggers for a given PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator for which fault trigger states are
//! being queried.  This parameter must be one of \b PWM_GEN_0, \b PWM_GEN_1,
//! \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Group indicates the subset of faults that are being queried.
//! This parameter must be \b PWM_FAULT_GROUP_0 or \b PWM_FAULT_GROUP_1.
//!
//! This function allows an application to query the current state of each of
//! the fault trigger inputs to a given PWM generator.  The current state of
//! each fault trigger input is returned unless PWMGenConfigure() has
//! previously been called with flag \b PWM_GEN_MODE_FAULT_LATCHED in the
//! \e ui32Config parameter, in which case the returned status is the latched
//! fault trigger status.
//!
//! If latched faults are configured, the application must call
//! PWMGenFaultClear() to clear each trigger.
//!
//! \note This function is only available on devices supporting extended PWM
//! fault handling.
//!
//! \return Returns the current state of the fault triggers for the given PWM
//! generator.  A set bit indicates that the associated trigger is active.
//! For \b PWM_FAULT_GROUP_0, the returned value is a logical OR of
//! \b PWM_FAULT_FAULT0, \b PWM_FAULT_FAULT1, \b PWM_FAULT_FAULT2, or
//! \b PWM_FAULT_FAULT3.  For \b PWM_FAULT_GROUP_1, the return value is the
//! logical OR of \b PWM_FAULT_DCMP0, \b PWM_FAULT_DCMP1,
//! \b PWM_FAULT_DCMP2, \b PWM_FAULT_DCMP3, \b PWM_FAULT_DCMP4,
//! \b PWM_FAULT_DCMP5, \b PWM_FAULT_DCMP6, or \b PWM_FAULT_DCMP7.
//
//*****************************************************************************
uint32_t
PWMGenFaultStatus(uint32_t ui32Base, uint32_t ui32Gen,
                  uint32_t ui32Group)
{
    //
    // Check for valid parameters.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32Group == PWM_FAULT_GROUP_0) ||
           (ui32Group == PWM_FAULT_GROUP_1));

    //
    // Return the current fault status.
    //
    if(ui32Group == PWM_FAULT_GROUP_0)
    {
        return(HWREG(PWM_GEN_EXT_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSTAT0));
    }
    else
    {
        return(HWREG(PWM_GEN_EXT_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSTAT1));
    }
}

//*****************************************************************************
//
//! Clears one or more latched fault triggers for a given PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator for which fault trigger states are
//! being queried.  This parameter must be one of \b PWM_GEN_0, \b PWM_GEN_1,
//! \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Group indicates the subset of faults that are being queried.
//! This parameter must be \b PWM_FAULT_GROUP_0 or \b PWM_FAULT_GROUP_1.
//! \param ui32FaultTriggers is the set of fault triggers which are to be
//! cleared.
//!
//! This function allows an application to clear the fault triggers for a
//! given PWM generator.  This function is only required if PWMGenConfigure()
//! has previously been called with flag \b PWM_GEN_MODE_FAULT_LATCHED in
//! parameter \e ui32Config.
//!
//! \note This function is only available on devices supporting extended PWM
//! fault handling.
//!
//! \return None.
//
//*****************************************************************************
void
PWMGenFaultClear(uint32_t ui32Base, uint32_t ui32Gen,
                 uint32_t ui32Group, uint32_t ui32FaultTriggers)
{
    //
    // Check for valid parameters.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(_PWMGenValid(ui32Gen));
    ASSERT((ui32Group == PWM_FAULT_GROUP_0) ||
           (ui32Group == PWM_FAULT_GROUP_1));
    ASSERT((ui32Group == PWM_FAULT_GROUP_0) &&
           ((ui32FaultTriggers & ~(PWM_FAULT_FAULT0 | PWM_FAULT_FAULT1 |
                                   PWM_FAULT_FAULT2 | PWM_FAULT_FAULT3)) ==
            0));
    ASSERT((ui32Group == PWM_FAULT_GROUP_1) &&
           ((ui32FaultTriggers & ~(PWM_FAULT_DCMP0 | PWM_FAULT_DCMP1 |
                                   PWM_FAULT_DCMP2 | PWM_FAULT_DCMP3 |
                                   PWM_FAULT_DCMP4 | PWM_FAULT_DCMP5 |
                                   PWM_FAULT_DCMP6 | PWM_FAULT_DCMP7)) == 0));

    //
    // Clear the given faults.
    //
    if(ui32Group == PWM_FAULT_GROUP_0)
    {
        HWREG(PWM_GEN_EXT_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSTAT0) =
            ui32FaultTriggers;
    }
    else
    {
        HWREG(PWM_GEN_EXT_BADDR(ui32Base, ui32Gen) + PWM_O_X_FLTSTAT1) =
            ui32FaultTriggers;
    }
}

//*****************************************************************************
///
//! Sets the PWM clock configuration.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Config is the configuration for the PWM clock; it must be one of
//! \b PWM_SYSCLK_DIV_1, \b PWM_SYSCLK_DIV_2, \b PWM_SYSCLK_DIV_4,
//! \b PWM_SYSCLK_DIV_8, \b PWM_SYSCLK_DIV_16, \b PWM_SYSCLK_DIV_32, or
//! \b PWM_SYSCLK_DIV_64.
//!
//! This function sets the PWM clock divider as the PWM clock source.  It also
//! configures the clock frequency to the PWM module as a division of the
//! system clock.  This clock is used by the PWM module to generate PWM
//! signals; its rate forms the basis for all PWM signals.
//!
//! \note This function should only be used with Snowflake class devices.  For
//! other class devices SysCtlPWMClockSet() function should be used.
//!
//! \note The clocking of the PWM is dependent upon the system clock rate as
//! configured by SysCtlClockFreqSet().
//!
//! \return None.
//
//*****************************************************************************
void
PWMClockSet(uint32_t ui32Base, uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT((ui32Config == PWM_SYSCLK_DIV_2) ||
           (ui32Config == PWM_SYSCLK_DIV_4) ||
           (ui32Config == PWM_SYSCLK_DIV_8) ||
           (ui32Config == PWM_SYSCLK_DIV_16) ||
           (ui32Config == PWM_SYSCLK_DIV_32) ||
           (ui32Config == PWM_SYSCLK_DIV_64));

    //
    // Set the PWM clock configuration into the PWM clock configuration
    // register.
    //
    HWREG(ui32Base + PWM_O_CC) = ((HWREG(ui32Base + PWM_O_CC) &
                                   ~(PWM_CC_USEPWM | PWM_CC_PWMDIV_M)) |
                                  ui32Config);
}

//*****************************************************************************
//
//! Gets the current PWM clock configuration.
//!
//! \param ui32Base is the base address of the PWM module.
//!
//! This function returns the current PWM clock configuration.
//!
//! \note This function should only be used with Snowflake class devices.  For
//! other class devices SysCtlPWMClockGet() function should be used.
//!
//! \return Returns the current PWM clock configuration; is one of
//! \b PWM_SYSCLK_DIV_1, \b PWM_SYSCLK_DIV_2, \b PWM_SYSCLK_DIV_4,
//! \b PWM_SYSCLK_DIV_8, \b PWM_SYSCLK_DIV_16, \b PWM_SYSCLK_DIV_32,
//! or \b PWM_SYSCLK_DIV_64.
//
//*****************************************************************************
uint32_t
PWMClockGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));

    //
    // Return the current PWM clock configuration.  Make sure that
    // PWM_SYSCLK_DIV_1 is returned in all cases where the divider is disabled.
    //
    if(!(HWREG(ui32Base + PWM_O_CC) & PWM_CC_USEPWM))
    {
        //
        // The divider is not active so reflect this in the value we return.
        //
        return(PWM_SYSCLK_DIV_1);
    }
    else
    {
        //
        // The divider is active so directly return the masked register value.
        //
        return(HWREG(ui32Base + PWM_O_CC) & (PWM_CC_USEPWM | PWM_CC_PWMDIV_M));
    }
}

//*****************************************************************************
//
//! Sets the update mode or synchronization mode to the PWM outputs.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32PWMOutBits are the PWM outputs to be modified.  This parameter
//! must be the logical OR of any of \b PWM_OUT_0_BIT, \b PWM_OUT_1_BIT,
//! \b PWM_OUT_2_BIT, \b PWM_OUT_3_BIT, \b PWM_OUT_4_BIT, \b PWM_OUT_5_BIT,
//! \b PWM_OUT_6_BIT, or \b PWM_OUT_7_BIT.
//! \param ui32Mode specifies the enable update mode to use when enabling or
//! disabling PWM outputs.
//!
//! This function sets one of three possible update modes to enable or disable
//! the requested PWM outputs.  The \e ui32Mode parameter controls when changes
//! made via calls to PWMOutputState() take effect.  Possible values are:
//!
//! - \b PWM_OUTPUT_MODE_NO_SYNC, which enables/disables changes to take effect
//! immediately.
//! - \b PWM_OUTPUT_MODE_SYNC_LOCAL, which causes changes to take effect when
//! the local PWM generator's count next reaches 0.
//! - \b PWM_OUTPUT_MODE_SYNC_GLOBAL, which causes changes to take effect when
//! the local PWM generator's count next reaches 0 following a call to
//! PWMSyncUpdate() which specifies the same generator in its \e ui32GenBits
//! parameter.
//!
//! \note This function is only available on Snowflake class devices.
//!
//! \return None.
//
//*****************************************************************************
void
PWMOutputUpdateMode(uint32_t ui32Base, uint32_t ui32PWMOutBits,
                    uint32_t ui32Mode)
{
    uint_fast8_t ui8Index;
    uint32_t ui32PWMOutputMask;
    uint32_t ui32UpdateValueMask;
    uint32_t ui32UpdateValue;
    uint32_t ui32Temp;

    //
    // Check the arguments.
    //
    ASSERT((ui32Base == PWM0_BASE) || (ui32Base == PWM1_BASE));
    ASSERT(!(ui32PWMOutBits & ~(PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT |
                                PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT |
                                PWM_OUT_6_BIT | PWM_OUT_7_BIT)));
    ASSERT((ui32Mode == PWM_OUTPUT_MODE_NO_SYNC) ||
           (ui32Mode == PWM_OUTPUT_MODE_SYNC_LOCAL) ||
           (ui32Mode == PWM_OUTPUT_MODE_SYNC_GLOBAL));

    //
    // Initialize the local variables
    //
    ui8Index = 0;
    ui32PWMOutputMask = 1;
    ui32UpdateValue = 0;
    ui32UpdateValueMask = 0;

    //
    // Loop to find out which PWM outputs are to be modified.
    //
    while(ui8Index < 8)
    {
        //
        // Check if this PWM output is to be modified.
        //
        if(ui32PWMOutputMask & ui32PWMOutBits)
        {
            //
            // Set the update mode value for the requested PWM output by
            // writing to the appropriate field.
            //
            ui32UpdateValue |= ui32Mode << (ui8Index * 2);

            //
            // Compute the mask for the bits to be updated.
            //
            ui32UpdateValueMask |= 3 << (ui8Index * 2);
        }

        //
        // Update the PWM output to be checked and the index.
        //
        ui32PWMOutputMask = ui32PWMOutputMask << 1;
        ui8Index++;
    }

    //
    // Read the Enable Update register and mask the bits that are to be
    // updated.
    //
    ui32Temp = ~ui32UpdateValueMask & HWREG(ui32Base + PWM_O_ENUPD);

    //
    // Write the updated values to Enable Update register.
    //
    HWREG(ui32Base + PWM_O_ENUPD) = ui32Temp | ui32UpdateValue;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
