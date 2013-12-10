//*****************************************************************************
//
// comp.c - Driver for the analog comparator.
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
//! \addtogroup comp_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_comp.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/comp.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
//! Configures a comparator.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator to configure.
//! \param ui32Config is the configuration of the comparator.
//!
//! This function configures a comparator.  The \e ui32Config parameter is the
//! result of a logical OR operation between the \b COMP_TRIG_xxx,
//! \b COMP_INT_xxx, \b COMP_ASRCP_xxx, and \b COMP_OUTPUT_xxx values.
//!
//! The \b COMP_TRIG_xxx term can take on the following values:
//!
//! - \b COMP_TRIG_NONE to have no trigger to the ADC.
//! - \b COMP_TRIG_HIGH to trigger the ADC when the comparator output is high.
//! - \b COMP_TRIG_LOW to trigger the ADC when the comparator output is low.
//! - \b COMP_TRIG_FALL to trigger the ADC when the comparator output goes low.
//! - \b COMP_TRIG_RISE to trigger the ADC when the comparator output goes
//! high.
//! - \b COMP_TRIG_BOTH to trigger the ADC when the comparator output goes low
//! or high.
//!
//! The \b COMP_INT_xxx term can take on the following values:
//!
//! - \b COMP_INT_HIGH to generate an interrupt when the comparator output is
//! high.
//! - \b COMP_INT_LOW to generate an interrupt when the comparator output is
//! low.
//! - \b COMP_INT_FALL to generate an interrupt when the comparator output goes
//! low.
//! - \b COMP_INT_RISE to generate an interrupt when the comparator output goes
//! high.
//! - \b COMP_INT_BOTH to generate an interrupt when the comparator output goes
//! low or high.
//!
//! The \b COMP_ASRCP_xxx term can take on the following values:
//!
//! - \b COMP_ASRCP_PIN to use the dedicated Comp+ pin as the reference
//! voltage.
//! - \b COMP_ASRCP_PIN0 to use the Comp0+ pin as the reference voltage (this
//! the same as \b COMP_ASRCP_PIN for the comparator 0).
//! - \b COMP_ASRCP_REF to use the internally generated voltage as the
//! reference voltage.
//!
//! The \b COMP_OUTPUT_xxx term can take on the following values:
//!
//! - \b COMP_OUTPUT_NORMAL to enable a non-inverted output from the comparator
//! to a device pin.
//! - \b COMP_OUTPUT_INVERT to enable an inverted output from the comparator to
//! a device pin.
//!
//! \return None.
//
//*****************************************************************************
void
ComparatorConfigure(uint32_t ui32Base, uint32_t ui32Comp, uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Configure this comparator.
    //
    HWREG(ui32Base + (ui32Comp * 0x20) + COMP_O_ACCTL0) = ui32Config;
}

//*****************************************************************************
//
//! Sets the internal reference voltage.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Ref is the desired reference voltage.
//!
//! This function sets the internal reference voltage value.  The voltage is
//! specified as one of the following values:
//!
//! - \b COMP_REF_OFF to turn off the reference voltage
//! - \b COMP_REF_0V to set the reference voltage to 0 V
//! - \b COMP_REF_0_1375V to set the reference voltage to 0.1375 V
//! - \b COMP_REF_0_275V to set the reference voltage to 0.275 V
//! - \b COMP_REF_0_4125V to set the reference voltage to 0.4125 V
//! - \b COMP_REF_0_55V to set the reference voltage to 0.55 V
//! - \b COMP_REF_0_6875V to set the reference voltage to 0.6875 V
//! - \b COMP_REF_0_825V to set the reference voltage to 0.825 V
//! - \b COMP_REF_0_928125V to set the reference voltage to 0.928125 V
//! - \b COMP_REF_0_9625V to set the reference voltage to 0.9625 V
//! - \b COMP_REF_1_03125V to set the reference voltage to 1.03125 V
//! - \b COMP_REF_1_134375V to set the reference voltage to 1.134375 V
//! - \b COMP_REF_1_1V to set the reference voltage to 1.1 V
//! - \b COMP_REF_1_2375V to set the reference voltage to 1.2375 V
//! - \b COMP_REF_1_340625V to set the reference voltage to 1.340625 V
//! - \b COMP_REF_1_375V to set the reference voltage to 1.375 V
//! - \b COMP_REF_1_44375V to set the reference voltage to 1.44375 V
//! - \b COMP_REF_1_5125V to set the reference voltage to 1.5125 V
//! - \b COMP_REF_1_546875V to set the reference voltage to 1.546875 V
//! - \b COMP_REF_1_65V to set the reference voltage to 1.65 V
//! - \b COMP_REF_1_753125V to set the reference voltage to 1.753125 V
//! - \b COMP_REF_1_7875V to set the reference voltage to 1.7875 V
//! - \b COMP_REF_1_85625V to set the reference voltage to 1.85625 V
//! - \b COMP_REF_1_925V to set the reference voltage to 1.925 V
//! - \b COMP_REF_1_959375V to set the reference voltage to 1.959375 V
//! - \b COMP_REF_2_0625V to set the reference voltage to 2.0625 V
//! - \b COMP_REF_2_165625V to set the reference voltage to 2.165625 V
//! - \b COMP_REF_2_26875V to set the reference voltage to 2.26875 V
//! - \b COMP_REF_2_371875V to set the reference voltage to 2.371875 V
//!
//! \return None.
//
//*****************************************************************************
void
ComparatorRefSet(uint32_t ui32Base, uint32_t ui32Ref)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);

    //
    // Set the voltage reference voltage as requested.
    //
    HWREG(ui32Base + COMP_O_ACREFCTL) = ui32Ref;
}

//*****************************************************************************
//
//! Gets the current comparator output value.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//!
//! This function retrieves the current value of the comparator output.
//!
//! \return Returns \b true if the comparator output is high and \b false if
//! the comparator output is low.
//
//*****************************************************************************
bool
ComparatorValueGet(uint32_t ui32Base, uint32_t ui32Comp)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Return the appropriate value based on the comparator's present output
    // value.
    //
    if(HWREG(ui32Base + (ui32Comp * 0x20) + COMP_O_ACSTAT0) &
       COMP_ACSTAT0_OVAL)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//*****************************************************************************
//
//! Registers an interrupt handler for the comparator interrupt.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//! \param pfnHandler is a pointer to the function to be called when the
//! comparator interrupt occurs.
//!
//! This function sets the handler to be called when the comparator interrupt
//! occurs and enables the interrupt in the interrupt controller.  It is the
//! interrupt handler's responsibility to clear the interrupt source via
//! ComparatorIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
ComparatorIntRegister(uint32_t ui32Base, uint32_t ui32Comp,
                      void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(INT_COMP0_BLIZZARD + ui32Comp, pfnHandler);

    //
    // Enable the interrupt in the interrupt controller.
    //
    IntEnable(INT_COMP0_BLIZZARD + ui32Comp);

    //
    // Enable the comparator interrupt.
    //
    HWREG(ui32Base + COMP_O_ACINTEN) |= 1 << ui32Comp;
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for a comparator interrupt.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//!
//! This function clears the handler to be called when a comparator interrupt
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
ComparatorIntUnregister(uint32_t ui32Base, uint32_t ui32Comp)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Disable the comparator interrupt.
    //
    HWREG(ui32Base + COMP_O_ACINTEN) &= ~(1 << ui32Comp);

    //
    // Disable the interrupt in the interrupt controller.
    //
    IntDisable(INT_COMP0_BLIZZARD + ui32Comp);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_COMP0_BLIZZARD + ui32Comp);
}

//*****************************************************************************
//
//! Enables the comparator interrupt.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//!
//! This function enables generation of an interrupt from the specified
//! comparator.  Only enabled comparator interrupts can be reflected
//! to the processor.
//!
//! \return None.
//
//*****************************************************************************
void
ComparatorIntEnable(uint32_t ui32Base, uint32_t ui32Comp)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Enable the comparator interrupt.
    //
    HWREG(ui32Base + COMP_O_ACINTEN) |= 1 << ui32Comp;
}

//*****************************************************************************
//
//! Disables the comparator interrupt.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//!
//! This function disables generation of an interrupt from the specified
//! comparator.  Only enabled comparator interrupts can be reflected
//! to the processor.
//!
//! \return None.
//
//*****************************************************************************
void
ComparatorIntDisable(uint32_t ui32Base, uint32_t ui32Comp)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Disable the comparator interrupt.
    //
    HWREG(ui32Base + COMP_O_ACINTEN) &= ~(1 << ui32Comp);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//! \param bMasked is \b false if the raw interrupt status is required and
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the comparator.  Either the
//! raw or the masked interrupt status can be returned.
//!
//! \return \b true if the interrupt is asserted and \b false if it is not
//! asserted.
//
//*****************************************************************************
bool
ComparatorIntStatus(uint32_t ui32Base, uint32_t ui32Comp, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(((HWREG(ui32Base + COMP_O_ACMIS) >> ui32Comp) & 1) ? true :
               false);
    }
    else
    {
        return(((HWREG(ui32Base + COMP_O_ACRIS) >> ui32Comp) & 1) ? true :
               false);
    }
}

//*****************************************************************************
//
//! Clears a comparator interrupt.
//!
//! \param ui32Base is the base address of the comparator module.
//! \param ui32Comp is the index of the comparator.
//!
//! The comparator interrupt is cleared, so that it no longer asserts.  This
//! fucntion must be called in the interrupt handler to keep the handler from
//! being called again immediately upon exit.  Note that for a level-triggered
//! interrupt, the interrupt cannot be cleared until it stops asserting.
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
ComparatorIntClear(uint32_t ui32Base, uint32_t ui32Comp)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == COMP_BASE);
    ASSERT(ui32Comp < 3);

    //
    // Clear the interrupt.
    //
    HWREG(ui32Base + COMP_O_ACMIS) = 1 << ui32Comp;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
