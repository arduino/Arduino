//*****************************************************************************
//
// mpu.c - Driver for the Cortex-M3 memory protection unit (MPU).
//
// Copyright (c) 2007-2013 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup mpu_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/mpu.h"

//*****************************************************************************
//
//! Enables and configures the MPU for use.
//!
//! \param ui32MPUConfig is the logical OR of the possible configurations.
//!
//! This function enables the Cortex-M memory protection unit.  It also
//! configures the default behavior when in privileged mode and while handling
//! a hard fault or NMI.  Prior to enabling the MPU, at least one region must
//! be set by calling MPURegionSet() or else by enabling the default region for
//! privileged mode by passing the \b MPU_CONFIG_PRIV_DEFAULT flag to
//! MPUEnable().  Once the MPU is enabled, a memory management fault is
//! generated for memory access violations.
//!
//! The \e ui32MPUConfig parameter should be the logical OR of any of the
//! following:
//!
//! - \b MPU_CONFIG_PRIV_DEFAULT enables the default memory map when in
//! privileged mode and when no other regions are defined.  If this option
//! is not enabled, then there must be at least one valid region already
//! defined when the MPU is enabled.
//! - \b MPU_CONFIG_HARDFLT_NMI enables the MPU while in a hard fault or NMI
//! exception handler.  If this option is not enabled, then the MPU is
//! disabled while in one of these exception handlers and the default
//! memory map is applied.
//! - \b MPU_CONFIG_NONE chooses none of the above options.  In this case,
//! no default memory map is provided in privileged mode, and the MPU is not
//! enabled in the fault handlers.
//!
//! \return None.
//
//*****************************************************************************
void
MPUEnable(uint32_t ui32MPUConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ui32MPUConfig & ~(MPU_CONFIG_PRIV_DEFAULT |
                               MPU_CONFIG_HARDFLT_NMI)));

    //
    // Set the MPU control bits according to the flags passed by the user,
    // and also set the enable bit.
    //
    HWREG(NVIC_MPU_CTRL) = ui32MPUConfig | NVIC_MPU_CTRL_ENABLE;
}

//*****************************************************************************
//
//! Disables the MPU for use.
//!
//! This function disables the Cortex-M memory protection unit.  When the
//! MPU is disabled, the default memory map is used and memory management
//! faults are not generated.
//!
//! \return None.
//
//*****************************************************************************
void
MPUDisable(void)
{
    //
    // Turn off the MPU enable bit.
    //
    HWREG(NVIC_MPU_CTRL) &= ~NVIC_MPU_CTRL_ENABLE;
}

//*****************************************************************************
//
//! Gets the count of regions supported by the MPU.
//!
//! This function is used to get the total number of regions that are supported
//! by the MPU, including regions that are already programmed.
//!
//! \return The number of memory protection regions that are available
//! for programming using MPURegionSet().
//
//*****************************************************************************
uint32_t
MPURegionCountGet(void)
{
    //
    // Read the DREGION field of the MPU type register and mask off
    // the bits of interest to get the count of regions.
    //
    return((HWREG(NVIC_MPU_TYPE) & NVIC_MPU_TYPE_DREGION_M) >>
           NVIC_MPU_TYPE_DREGION_S);
}

//*****************************************************************************
//
//! Enables a specific region.
//!
//! \param ui32Region is the region number to enable.
//!
//! This function is used to enable a memory protection region.  The region
//! should already be configured with the MPURegionSet() function.  Once
//! enabled, the memory protection rules of the region are applied and access
//! violations cause a memory management fault.
//!
//! \return None.
//
//*****************************************************************************
void
MPURegionEnable(uint32_t ui32Region)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Region < 8);

    //
    // Select the region to modify.
    //
    HWREG(NVIC_MPU_NUMBER) = ui32Region;

    //
    // Modify the enable bit in the region attributes.
    //
    HWREG(NVIC_MPU_ATTR) |= NVIC_MPU_ATTR_ENABLE;
}

//*****************************************************************************
//
//! Disables a specific region.
//!
//! \param ui32Region is the region number to disable.
//!
//! This function is used to disable a previously enabled memory protection
//! region.  The region remains configured if it is not overwritten with
//! another call to MPURegionSet(), and can be enabled again by calling
//! MPURegionEnable().
//!
//! \return None.
//
//*****************************************************************************
void
MPURegionDisable(uint32_t ui32Region)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Region < 8);

    //
    // Select the region to modify.
    //
    HWREG(NVIC_MPU_NUMBER) = ui32Region;

    //
    // Modify the enable bit in the region attributes.
    //
    HWREG(NVIC_MPU_ATTR) &= ~NVIC_MPU_ATTR_ENABLE;
}

//*****************************************************************************
//
//! Sets up the access rules for a specific region.
//!
//! \param ui32Region is the region number to set up.
//! \param ui32Addr is the base address of the region.  It must be aligned
//! according to the size of the region specified in ui32Flags.
//! \param ui32Flags is a set of flags to define the attributes of the region.
//!
//! This function sets up the protection rules for a region.  The region has
//! a base address and a set of attributes including the size.  The base
//! address parameter, \e ui32Addr, must be aligned according to the size, and
//! the size must be a power of 2.
//!
//! The \e ui32Flags parameter is the logical OR of all of the attributes
//! of the region.  It is a combination of choices for region size,
//! execute permission, read/write permissions, disabled sub-regions,
//! and a flag to determine if the region is enabled.
//!
//! The size flag determines the size of a region and must be one of the
//! following:
//!
//! - \b MPU_RGN_SIZE_32B
//! - \b MPU_RGN_SIZE_64B
//! - \b MPU_RGN_SIZE_128B
//! - \b MPU_RGN_SIZE_256B
//! - \b MPU_RGN_SIZE_512B
//! - \b MPU_RGN_SIZE_1K
//! - \b MPU_RGN_SIZE_2K
//! - \b MPU_RGN_SIZE_4K
//! - \b MPU_RGN_SIZE_8K
//! - \b MPU_RGN_SIZE_16K
//! - \b MPU_RGN_SIZE_32K
//! - \b MPU_RGN_SIZE_64K
//! - \b MPU_RGN_SIZE_128K
//! - \b MPU_RGN_SIZE_256K
//! - \b MPU_RGN_SIZE_512K
//! - \b MPU_RGN_SIZE_1M
//! - \b MPU_RGN_SIZE_2M
//! - \b MPU_RGN_SIZE_4M
//! - \b MPU_RGN_SIZE_8M
//! - \b MPU_RGN_SIZE_16M
//! - \b MPU_RGN_SIZE_32M
//! - \b MPU_RGN_SIZE_64M
//! - \b MPU_RGN_SIZE_128M
//! - \b MPU_RGN_SIZE_256M
//! - \b MPU_RGN_SIZE_512M
//! - \b MPU_RGN_SIZE_1G
//! - \b MPU_RGN_SIZE_2G
//! - \b MPU_RGN_SIZE_4G
//!
//! The execute permission flag must be one of the following:
//!
//! - \b MPU_RGN_PERM_EXEC enables the region for execution of code
//! - \b MPU_RGN_PERM_NOEXEC disables the region for execution of code
//!
//! The read/write access permissions are applied separately for the
//! privileged and user modes.  The read/write access flags must be one
//! of the following:
//!
//! - \b MPU_RGN_PERM_PRV_NO_USR_NO - no access in privileged or user mode
//! - \b MPU_RGN_PERM_PRV_RW_USR_NO - privileged read/write, user no access
//! - \b MPU_RGN_PERM_PRV_RW_USR_RO - privileged read/write, user read-only
//! - \b MPU_RGN_PERM_PRV_RW_USR_RW - privileged read/write, user read/write
//! - \b MPU_RGN_PERM_PRV_RO_USR_NO - privileged read-only, user no access
//! - \b MPU_RGN_PERM_PRV_RO_USR_RO - privileged read-only, user read-only
//!
//! The region is automatically divided into 8 equally-sized sub-regions by
//! the MPU.  Sub-regions can only be used in regions of size 256 bytes
//! or larger.  Any of these 8 sub-regions can be disabled, allowing for
//! creation of ``holes'' in a region which can be left open, or overlaid
//! by another region with different attributes.  Any of the 8 sub-regions
//! can be disabled with a logical OR of any of the following flags:
//!
//! - \b MPU_SUB_RGN_DISABLE_0
//! - \b MPU_SUB_RGN_DISABLE_1
//! - \b MPU_SUB_RGN_DISABLE_2
//! - \b MPU_SUB_RGN_DISABLE_3
//! - \b MPU_SUB_RGN_DISABLE_4
//! - \b MPU_SUB_RGN_DISABLE_5
//! - \b MPU_SUB_RGN_DISABLE_6
//! - \b MPU_SUB_RGN_DISABLE_7
//!
//! Finally, the region can be initially enabled or disabled with one of
//! the following flags:
//!
//! - \b MPU_RGN_ENABLE
//! - \b MPU_RGN_DISABLE
//!
//! As an example, to set a region with the following attributes: size of
//! 32 KB, execution enabled, read-only for both privileged and user, one
//! sub-region disabled, and initially enabled; the \e ui32Flags parameter
//! would have the following value:
//!
//! <code>
//! (MPU_RGN_SIZE_32K | MPU_RGN_PERM_EXEC | MPU_RGN_PERM_PRV_RO_USR_RO |
//!  MPU_SUB_RGN_DISABLE_2 | MPU_RGN_ENABLE)
//! </code>
//!
//! \note This function writes to multiple registers and is not protected
//! from interrupts.  It is possible that an interrupt which accesses a
//! region may occur while that region is in the process of being changed.
//! The safest way to handle this is to disable a region before changing it.
//! Refer to the discussion of this in the API Detailed Description section.
//!
//! \return None.
//
//*****************************************************************************
void
MPURegionSet(uint32_t ui32Region, uint32_t ui32Addr, uint32_t ui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Region < 8);
    ASSERT(ui32Addr ==
           (ui32Addr & ~0 << (((ui32Flags & NVIC_MPU_ATTR_SIZE_M) >> 1) + 1)));

    //
    // Program the base address, use the region field to select the
    // region at the same time.
    //
    HWREG(NVIC_MPU_BASE) = ui32Addr | ui32Region | NVIC_MPU_BASE_VALID;

    //
    // Program the region attributes.  Set the TEX field and the S, C,
    // and B bits to fixed values that are suitable for all Tiva C and
    // E Series memory.
    //
    HWREG(NVIC_MPU_ATTR) = ((ui32Flags & ~(NVIC_MPU_ATTR_TEX_M |
                                           NVIC_MPU_ATTR_CACHEABLE)) |
                            NVIC_MPU_ATTR_SHAREABLE | NVIC_MPU_ATTR_BUFFRABLE);
}

//*****************************************************************************
//
//! Gets the current settings for a specific region.
//!
//! \param ui32Region is the region number to get.
//! \param pui32Addr points to storage for the base address of the region.
//! \param pui32Flags points to the attribute flags for the region.
//!
//! This function retrieves the configuration of a specific region.  The
//! meanings and format of the parameters is the same as that of the
//! MPURegionSet() function.
//!
//! This function can be used to save the configuration of a region for later
//! use with the MPURegionSet() function.  The region's enable state is
//! preserved in the attributes that are saved.
//!
//! \return None.
//
//*****************************************************************************
void
MPURegionGet(uint32_t ui32Region, uint32_t *pui32Addr, uint32_t *pui32Flags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Region < 8);
    ASSERT(pui32Addr);
    ASSERT(pui32Flags);

    //
    // Select the region to get.
    //
    HWREG(NVIC_MPU_NUMBER) = ui32Region;

    //
    // Read and store the base address for the region.
    //
    *pui32Addr = HWREG(NVIC_MPU_BASE) & NVIC_MPU_BASE_ADDR_M;

    //
    // Read and store the region attributes.
    //
    *pui32Flags = HWREG(NVIC_MPU_ATTR);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the memory management fault.
//!
//! \param pfnHandler is a pointer to the function to be called when the
//! memory management fault occurs.
//!
//! This function sets and enables the handler to be called when the MPU
//! generates a memory management fault due to a protection region access
//! violation.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
MPUIntRegister(void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(pfnHandler);

    //
    // Register the interrupt handler.
    //
    IntRegister(FAULT_MPU, pfnHandler);

    //
    // Enable the memory management fault.
    //
    IntEnable(FAULT_MPU);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the memory management fault.
//!
//! This function disables and clears the handler to be called when a
//! memory management fault occurs.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
MPUIntUnregister(void)
{
    //
    // Disable the interrupt.
    //
    IntDisable(FAULT_MPU);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(FAULT_MPU);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
