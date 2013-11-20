//*****************************************************************************
//
// fpu.c - Routines for manipulating the floating-point unit in the Cortex-M
//         processor.
//
// Copyright (c) 2011-2013 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup fpu_api
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"

//*****************************************************************************
//
//! Enables the floating-point unit.
//!
//! This function enables the floating-point unit, allowing the floating-point
//! instructions to be executed.  This function must be called prior to
//! performing any hardware floating-point operations; failure to do so results
//! in a NOCP usage fault.
//!
//! \return None.
//
//*****************************************************************************
void
FPUEnable(void)
{
    //
    // Enable the coprocessors used by the floating-point unit.
    //
    HWREG(NVIC_CPAC) = ((HWREG(NVIC_CPAC) &
                         ~(NVIC_CPAC_CP10_M | NVIC_CPAC_CP11_M)) |
                        NVIC_CPAC_CP10_FULL | NVIC_CPAC_CP11_FULL);
}

//*****************************************************************************
//
//! Disables the floating-point unit.
//!
//! This function disables the floating-point unit, preventing floating-point
//! instructions from executing (generating a NOCP usage fault instead).
//!
//! \return None.
//
//*****************************************************************************
void
FPUDisable(void)
{
    //
    // Disable the coprocessors used by the floating-point unit.
    //
    HWREG(NVIC_CPAC) = ((HWREG(NVIC_CPAC) &
                         ~(NVIC_CPAC_CP10_M | NVIC_CPAC_CP11_M)) |
                        NVIC_CPAC_CP10_DIS | NVIC_CPAC_CP11_DIS);
}

//*****************************************************************************
//
//! Enables the stacking of floating-point registers.
//!
//! This function enables the stacking of floating-point registers s0-s15 when
//! an interrupt is handled.  When enabled, space is reserved on the stack for
//! the floating-point context and the floating-point state is saved into this
//! stack space.  Upon return from the interrupt, the floating-point context is
//! restored.
//!
//! If the floating-point registers are not stacked, floating-point
//! instructions cannot be safely executed in an interrupt handler because the
//! values of s0-s15 are not likely to be preserved for the interrupted code.
//! On the other hand, stacking the floating-point registers increases the
//! stacking operation from 8 words to 26 words, also increasing the interrupt
//! response latency.
//!
//! \return None.
//
//*****************************************************************************
void
FPUStackingEnable(void)
{
    //
    // Enable automatic state preservation for the floating-point unit, and
    // disable lazy state preservation (meaning that the floating-point state
    // is always stacked when floating-point instructions are used).
    //
    HWREG(NVIC_FPCC) = (HWREG(NVIC_FPCC) & ~NVIC_FPCC_LSPEN) | NVIC_FPCC_ASPEN;
}

//*****************************************************************************
//
//! Enables the lazy stacking of floating-point registers.
//!
//! This function enables the lazy stacking of floating-point registers s0-s15
//! when an interrupt is handled.  When lazy stacking is enabled, space is
//! reserved on the stack for the floating-point context, but the
//! floating-point state is not saved.  If a floating-point instruction is
//! executed from within the interrupt context, the floating-point context is
//! first saved into the space reserved on the stack.  On completion of the
//! interrupt handler, the floating-point context is only restored if it was
//! saved (as the result of executing a floating-point instruction).
//!
//! This method provides a compromise between fast interrupt response (because
//! the floating-point state is not saved on interrupt entry) and the ability
//! to use floating-point in interrupt handlers (because the floating-point
//! state is saved if floating-point instructions are used).
//!
//! \return None.
//
//*****************************************************************************
void
FPULazyStackingEnable(void)
{
    //
    // Enable automatic and lazy state preservation for the floating-point
    // unit.
    //
    HWREG(NVIC_FPCC) |= NVIC_FPCC_ASPEN | NVIC_FPCC_LSPEN;
}

//*****************************************************************************
//
//! Disables the stacking of floating-point registers.
//!
//! This function disables the stacking of floating-point registers s0-s15 when
//! an interrupt is handled.  When floating-point context stacking is disabled,
//! floating-point operations performed in an interrupt handler destroy the
//! floating-point context of the main thread of execution.
//!
//! \return None.
//
//*****************************************************************************
void
FPUStackingDisable(void)
{
    //
    // Disable automatic and lazy state preservation for the floating-point
    // unit.
    //
    HWREG(NVIC_FPCC) &= ~(NVIC_FPCC_ASPEN | NVIC_FPCC_LSPEN);
}

//*****************************************************************************
//
//! Selects the format of half-precision floating-point values.
//!
//! \param ui32Mode is the format for half-precision floating-point value,
//! which is either \b FPU_HALF_IEEE or \b FPU_HALF_ALTERNATE.
//!
//! This function selects between the IEEE half-precision floating-point
//! representation and the Cortex-M processor alternative representation.  The
//! alternative representation has a larger range but does not have a way to
//! encode infinity (positive or negative) or NaN (quiet or signaling).  The
//! default setting is the IEEE format.
//!
//! \note Unless this function is called prior to executing any floating-point
//! instructions, the default mode is used.
//!
//! \return None.
//
//*****************************************************************************
void
FPUHalfPrecisionModeSet(uint32_t ui32Mode)
{
    //
    // Set the half-precision floating-point format.
    //
    HWREG(NVIC_FPDSC) = (HWREG(NVIC_FPDSC) & ~(NVIC_FPDSC_AHP)) | ui32Mode;
}

//*****************************************************************************
//
//! Selects the NaN mode.
//!
//! \param ui32Mode is the mode for NaN results; which is either
//! \b FPU_NAN_PROPAGATE or \b FPU_NAN_DEFAULT.
//!
//! This function selects the handling of NaN results during floating-point
//! computations.  NaNs can either propagate (the default), or they can return
//! the default NaN.
//!
//! \note Unless this function is called prior to executing any floating-point
//! instructions, the default mode is used.
//!
//! \return None.
//
//*****************************************************************************
void
FPUNaNModeSet(uint32_t ui32Mode)
{
    //
    // Set the NaN mode.
    //
    HWREG(NVIC_FPDSC) = (HWREG(NVIC_FPDSC) & ~(NVIC_FPDSC_DN)) | ui32Mode;
}

//*****************************************************************************
//
//! Selects the flush-to-zero mode.
//!
//! \param ui32Mode is the flush-to-zero mode; which is either
//! \b FPU_FLUSH_TO_ZERO_DIS or \b FPU_FLUSH_TO_ZERO_EN.
//!
//! This function enables or disables the flush-to-zero mode of the
//! floating-point unit.  When disabled (the default), the floating-point unit
//! is fully IEEE compliant.  When enabled, values close to zero are treated as
//! zero, greatly improving the execution speed at the expense of some accuracy
//! (as well as IEEE compliance).
//!
//! \note Unless this function is called prior to executing any floating-point
//! instructions, the default mode is used.
//!
//! \return None.
//
//*****************************************************************************
void
FPUFlushToZeroModeSet(uint32_t ui32Mode)
{
    //
    // Set the flush-to-zero mode.
    //
    HWREG(NVIC_FPDSC) = (HWREG(NVIC_FPDSC) & ~(NVIC_FPDSC_FZ)) | ui32Mode;
}

//*****************************************************************************
//
//! Selects the rounding mode for floating-point results.
//!
//! \param ui32Mode is the rounding mode.
//!
//! This function selects the rounding mode for floating-point results.  After
//! a floating-point operation, the result is rounded toward the specified
//! value.  The default mode is \b FPU_ROUND_NEAREST.
//!
//! The following rounding modes are available (as specified by \e ui32Mode):
//!
//! - \b FPU_ROUND_NEAREST - round toward the nearest value
//! - \b FPU_ROUND_POS_INF - round toward positive infinity
//! - \b FPU_ROUND_NEG_INF - round toward negative infinity
//! - \b FPU_ROUND_ZERO - round toward zero
//!
//! \note Unless this function is called prior to executing any floating-point
//! instructions, the default mode is used.
//!
//! \return None.
//
//*****************************************************************************
void
FPURoundingModeSet(uint32_t ui32Mode)
{
    //
    // Set the rounding mode.
    //
    HWREG(NVIC_FPDSC) = (HWREG(NVIC_FPDSC) & ~(NVIC_FPDSC_RMODE_M)) | ui32Mode;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
