/******************************************************************************
*  Filename:       interrupt.h
*  Revised:        2015-07-24 15:00:55 +0200 (Fri, 24 Jul 2015)
*  Revision:       44203
*
*  Description:    Defines and prototypes for the NVIC Interrupt Controller
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

//*****************************************************************************
//
//! \addtogroup system_cpu_group
//! @{
//! \addtogroup interrupt_api
//! @{
//
//*****************************************************************************

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

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

#include <stdbool.h>
#include <stdint.h>
#include <inc/hw_ints.h>
#include <inc/hw_types.h>
#include <inc/hw_nvic.h>
#include <driverlib/debug.h>
#include <driverlib/cpu.h>

//*****************************************************************************
//
// Support for DriverLib in ROM:
// This section renames all functions that are not "static inline", so that
// calling these functions will default to implementation in flash. At the end
// of this file a second renaming will change the defaults to implementation in
// ROM for available functions.
//
// To force use of the implementation in flash, e.g. for debugging:
// - Globally: Define DRIVERLIB_NOROM at project level
// - Per function: Use prefix "NOROM_" when calling the function
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #define IntRegister                     NOROM_IntRegister
    #define IntUnregister                   NOROM_IntUnregister
    #define IntPriorityGroupingSet          NOROM_IntPriorityGroupingSet
    #define IntPriorityGroupingGet          NOROM_IntPriorityGroupingGet
    #define IntPrioritySet                  NOROM_IntPrioritySet
    #define IntPriorityGet                  NOROM_IntPriorityGet
    #define IntEnable                       NOROM_IntEnable
    #define IntDisable                      NOROM_IntDisable
    #define IntPendSet                      NOROM_IntPendSet
    #define IntPendGet                      NOROM_IntPendGet
    #define IntPendClear                    NOROM_IntPendClear
#endif

//*****************************************************************************
//
// Macro to generate an interrupt priority mask based on the number of bits
// of priority supported by the hardware. For CC26xx the number of priority
// bit is 3 as defined in <tt>hw_types.h</tt>. The priority mask is
// defined as
//
// INT_PRIORITY_MASK = ((0xFF << (8 - NUM_PRIORITY_BITS)) & 0xFF)
//
//*****************************************************************************
#define INT_PRIORITY_MASK       0x000000E0
#define INT_PRI_LEVEL0          0x00000000
#define INT_PRI_LEVEL1          0x00000020
#define INT_PRI_LEVEL2          0x00000040
#define INT_PRI_LEVEL3          0x00000060
#define INT_PRI_LEVEL4          0x00000080
#define INT_PRI_LEVEL5          0x000000A0
#define INT_PRI_LEVEL6          0x000000C0
#define INT_PRI_LEVEL7          0x000000E0

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Enables the processor interrupt.
//!
//! Allows the processor to respond to interrupts. This does not affect the
//! set of interrupts enabled in the interrupt controller; it just gates the
//! single interrupt from the controller to the processor.
//!
//! \return Returns:
//! - \c true  : Interrupts were disabled and are now enabled.
//! - \c false : Interrupts were already enabled when the function was called.
//
//*****************************************************************************
__STATIC_INLINE bool
IntMasterEnable(void)
{
    //
    // Enable processor interrupts.
    //
    return(CPUcpsie());
}

//*****************************************************************************
//
//! \brief Disables the processor interrupt.
//!
//! Prevents the processor from receiving interrupts. This does not affect the
//! set of interrupts enabled in the interrupt controller; it just gates the
//! single interrupt from the controller to the processor.
//!
//! \return Returns:
//! - \c true  : Interrupts were already disabled when the function was called.
//! - \c false : Interrupts were enabled and are now disabled.
//
//*****************************************************************************
__STATIC_INLINE bool
IntMasterDisable(void)
{
    //
    // Disable processor interrupts.
    //
    return(CPUcpsid());
}

//*****************************************************************************
//
//! \brief Registers a function to be called when an interrupt occurs.
//!
//! This function is used to specify the handler function to be called when the
//! given interrupt is asserted to the processor. When the interrupt occurs,
//! if it is enabled (via \ref IntEnable()), the handler function will be called in
//! interrupt context. Since the handler function can preempt other code, care
//! must be taken to protect memory or peripherals that are accessed by the
//! handler and other non-handler code.
//!
//! \note The use of this function (directly or indirectly via a peripheral
//! driver interrupt register function) moves the interrupt vector table from
//! flash to SRAM. Therefore, care must be taken when linking the application
//! to ensure that the SRAM vector table is located at the beginning of SRAM;
//! otherwise NVIC will not look in the correct portion of memory for the
//! vector table (it requires the vector table be on a 1 kB memory alignment).
//! Normally, the SRAM vector table is so placed via the use of linker scripts.
//!
//! \param ui32Interrupt specifies the interrupt in question.
//! \param pfnHandler is a pointer to the function to be called.
//!
//! \return None.
//
//*****************************************************************************
extern void IntRegister(uint32_t ui32Interrupt, void (*pfnHandler)(void));

//*****************************************************************************
//
//! \brief Unregisters the function to be called when an interrupt occurs.
//!
//! This function is used to indicate that no handler should be called when the
//! given interrupt is asserted to the processor. The interrupt source will be
//! automatically disabled (via \ref IntDisable()) if necessary.
//!
//! \param ui32Interrupt specifies the interrupt in question.
//!
//! \return None.
//!
//! \sa \ref IntRegister() for important information about registering interrupt
//! handlers.
//
//*****************************************************************************
extern void IntUnregister(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Sets the priority grouping of the interrupt controller.
//!
//! This function specifies the split between preemptable priority levels and
//! subpriority levels in the interrupt priority specification. The range of
//! the grouping values are dependent upon the hardware implementation; on
//! the CC26xx family, three bits are available for hardware interrupt
//! prioritization and therefore priority grouping values of three through
//! seven have the same effect.
//!
//! \param ui32Bits specifies the number of bits of preemptable priority.
//!
//! \return None
//
//*****************************************************************************
extern void IntPriorityGroupingSet(uint32_t ui32Bits);

//*****************************************************************************
//
//! \brief Gets the priority grouping of the interrupt controller.
//!
//! This function returns the split between preemptable priority levels and
//! subpriority levels in the interrupt priority specification.
//!
//! \return Returns the number of bits of preemptable priority.
//
//*****************************************************************************
extern uint32_t IntPriorityGroupingGet(void);

//*****************************************************************************
//
//! \brief Sets the priority of an interrupt.
//!
//! This function is used to set the priority of an interrupt. When multiple
//! interrupts are asserted simultaneously, the ones with the highest priority
//! are processed before the lower priority interrupts. Smaller numbers
//! correspond to higher interrupt priorities; priority 0 is the highest
//! interrupt priority.
//!
//! The hardware priority mechanism will only look at the upper N bits of the
//! priority level (where N is 3 for cc26xx), so any prioritization must be
//! performed in those bits. The remaining bits can be used to sub-prioritize
//! the interrupt sources, and may be used by the hardware priority mechanism
//! on a future part. This arrangement allows priorities to migrate to
//! different NVIC implementations without changing the gross prioritization
//! of the interrupts.
//!
//! \param ui32Interrupt specifies the interrupt in question.
//! \param ui8Priority specifies the priority of the interrupt.
//! - \ref INT_PRI_LEVEL0 : Highest priority.
//! - \ref INT_PRI_LEVEL1
//! - \ref INT_PRI_LEVEL2
//! - \ref INT_PRI_LEVEL3
//! - \ref INT_PRI_LEVEL4
//! - \ref INT_PRI_LEVEL5
//! - \ref INT_PRI_LEVEL6
//! - \ref INT_PRI_LEVEL7 : Lowest priority.
//!
//! \return None
//
//*****************************************************************************
extern void IntPrioritySet(uint32_t ui32Interrupt, uint8_t ui8Priority);

//*****************************************************************************
//
//! \brief Gets the priority of an interrupt.
//!
//! This function gets the priority of an interrupt.
//!
//! \param ui32Interrupt specifies the interrupt in question.
//!
//! \return Returns the interrupt priority:
//! - (-1)                : Invalid interrupt specified as parameter!
//! - \ref INT_PRI_LEVEL0 : Highest priority.
//! - \ref INT_PRI_LEVEL1
//! - \ref INT_PRI_LEVEL2
//! - \ref INT_PRI_LEVEL3
//! - \ref INT_PRI_LEVEL4
//! - \ref INT_PRI_LEVEL5
//! - \ref INT_PRI_LEVEL6
//! - \ref INT_PRI_LEVEL7 : Lowest priority.
//
//*****************************************************************************
extern int32_t IntPriorityGet(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Enables an interrupt.
//!
//! The specified interrupt is enabled in the interrupt controller. Other
//! enables for the interrupt (such as at the peripheral level) are unaffected
//! by this function.
//!
//! \param ui32Interrupt specifies the interrupt to be enabled.
//!
//! \return None
//
//*****************************************************************************
extern void IntEnable(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Disables an interrupt.
//!
//! The specified interrupt is disabled in the interrupt controller. Other
//! enables for the interrupt (such as at the peripheral level) are unaffected
//! by this function.
//!
//! \param ui32Interrupt specifies the interrupt to be disabled.
//!
//! \return None
//
//*****************************************************************************
extern void IntDisable(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Pends an interrupt.
//!
//! The specified interrupt is pended in the interrupt controller. This will
//! cause the interrupt controller to execute the corresponding interrupt
//! handler at the next available time, based on the current interrupt state
//! priorities. For example, if called by a higher priority interrupt handler,
//! the specified interrupt handler will not be called until after the current
//! interrupt handler has completed execution. The interrupt must have been
//! enabled for it to be called.
//!
//! \param ui32Interrupt specifies the interrupt to be pended.
//!
//! \return None
//
//*****************************************************************************
extern void IntPendSet(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Query whether an interrupt is pending.
//!
//! This function will check whether the specified interrupt is pending in the
//! interrupt controller. The interrupt must have been enabled for it to be
//! called, so an interrupt can very well be pending waiting to be enabled or
//! waiting for an interrupt of higher priority to be done executing.
//!
//! \note This function does not support the lower 16 IRQ vectors which are
//! hardware defined for the System CPU.
//!
//! \param ui32Interrupt specifies the interrupt to be queried.
//!
//! \return Returns:
//! - \c true  : Specified interrupt is pending.
//! - \c false : Specified interrupt is not pending.
//
//*****************************************************************************
extern bool IntPendGet(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Unpends an interrupt.
//!
//! The specified interrupt is unpended in the interrupt controller. This will
//! cause any previously generated interrupts that have not been handled yet
//! (due to higher priority interrupts or the interrupt no having been enabled
//! yet) to be discarded.
//!
//! \param ui32Interrupt specifies the interrupt to be unpended.
//!
//! \return None
//
//*****************************************************************************
extern void IntPendClear(uint32_t ui32Interrupt);

//*****************************************************************************
//
//! \brief Sets the priority masking level.
//!
//! This function sets the interrupt priority masking level so that all
//! interrupts at the specified or lesser priority level are masked. This
//! can be used to globally disable a set of interrupts with priority below
//! a predetermined threshold. A value of 0 disables priority
//! masking.
//!
//! Smaller numbers correspond to higher interrupt priorities. So for example
//! a priority level mask of 4 will allow interrupts of priority level 0-3,
//! and interrupts with a numerical priority of 4 and greater will be blocked.
//!
//! The hardware priority mechanism will only look at the upper N bits of the
//! priority level (where N is 3 for the CC26xx family), so any
//! prioritization must be performed in those bits.
//!
//! \param ui32PriorityMask is the priority level that will be masked.
//!
//! \return None.
//
//*****************************************************************************
__STATIC_INLINE void
IntPriorityMaskSet(uint32_t ui32PriorityMask)
{
    CPUbasepriSet(ui32PriorityMask);
}

//*****************************************************************************
//
//! \brief Gets the priority masking level.
//!
//! This function gets the current setting of the interrupt priority masking
//! level. The value returned is the priority level such that all interrupts
//! of that and lesser priority are masked. A value of 0 means that priority
//! masking is disabled.
//!
//! Smaller numbers correspond to higher interrupt priorities. So for example
//! a priority level mask of 4 will allow interrupts of priority level 0-3,
//! and interrupts with a numerical priority of 4 and greater will be blocked.
//!
//! The hardware priority mechanism will only look at the upper N bits of the
//! priority level (where N is 3 for the CC26xx family), so any
//! prioritization must be performed in those bits.
//!
//! \return Returns the value of the interrupt priority level mask.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
IntPriorityMaskGet(void)
{
    return(CPUbasepriGet());
}

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#if !defined(DRIVERLIB_NOROM) && !defined(DOXYGEN)
    #include <driverlib/rom.h>
    #ifdef ROM_IntRegister
        #undef  IntRegister
        #define IntRegister                     ROM_IntRegister
    #endif
    #ifdef ROM_IntUnregister
        #undef  IntUnregister
        #define IntUnregister                   ROM_IntUnregister
    #endif
    #ifdef ROM_IntPriorityGroupingSet
        #undef  IntPriorityGroupingSet
        #define IntPriorityGroupingSet          ROM_IntPriorityGroupingSet
    #endif
    #ifdef ROM_IntPriorityGroupingGet
        #undef  IntPriorityGroupingGet
        #define IntPriorityGroupingGet          ROM_IntPriorityGroupingGet
    #endif
    #ifdef ROM_IntPrioritySet
        #undef  IntPrioritySet
        #define IntPrioritySet                  ROM_IntPrioritySet
    #endif
    #ifdef ROM_IntPriorityGet
        #undef  IntPriorityGet
        #define IntPriorityGet                  ROM_IntPriorityGet
    #endif
    #ifdef ROM_IntEnable
        #undef  IntEnable
        #define IntEnable                       ROM_IntEnable
    #endif
    #ifdef ROM_IntDisable
        #undef  IntDisable
        #define IntDisable                      ROM_IntDisable
    #endif
    #ifdef ROM_IntPendSet
        #undef  IntPendSet
        #define IntPendSet                      ROM_IntPendSet
    #endif
    #ifdef ROM_IntPendGet
        #undef  IntPendGet
        #define IntPendGet                      ROM_IntPendGet
    #endif
    #ifdef ROM_IntPendClear
        #undef  IntPendClear
        #define IntPendClear                    ROM_IntPendClear
    #endif
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __INTERRUPT_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//*****************************************************************************
