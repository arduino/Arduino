/******************************************************************************
*  Filename:       flashsafe.h
*  Revised:        2015-02-03 14:18:59 +0100 (ti, 03 feb 2015)
*  Revision:       42551
*
*  Description:    Defines and prototypes for the Flash driver in
*                  Thread safe mode.
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
//! \addtogroup flashsafe_api
//! @{
//
//*****************************************************************************

#ifndef __FLASHSAFE_H__
#define __FLASHSAFE_H__

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
#include <inc/hw_types.h>
#include <inc/hw_flash.h>
#include <inc/hw_memmap.h>
#include <inc/hw_ints.h>
#include <inc/hw_fcfg1.h>
#include <driverlib/interrupt.h>
#include <driverlib/debug.h>
#include <driverlib/flash.h>
#include <driverlib/rom.h>
#include <driverlib/smph.h>

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
// Do not define DRIVERLIB_GENERATE_ROM!
//
//*****************************************************************************
#ifndef DRIVERLIB_GENERATE_ROM
    #define FlashsafeSizeGet                NOROM_FlashsafeSizeGet
    #define FlashsafeSectorSizeGet          NOROM_FlashsafeSectorSizeGet
    #define FlashsafePowerModeSet           NOROM_FlashsafePowerModeSet
    #define FlashsafePowerModeGet           NOROM_FlashsafePowerModeGet
    #define FlashsafeProtectionSet          NOROM_FlashsafeProtectionSet
    #define FlashsafeProtectionGet          NOROM_FlashsafeProtectionGet
    #define FlashsafeProtectionSave         NOROM_FlashsafeProtectionSave
    #define FlashsafeCheckFsmForError       NOROM_FlashsafeCheckFsmForError
    #define FlashsafeCheckFsmForReady       NOROM_FlashsafeCheckFsmForReady
    #define FlashsafeIntRegister            NOROM_FlashsafeIntRegister
    #define FlashsafeIntUnregister          NOROM_FlashsafeIntUnregister
    #define FlashsafeIntEnable              NOROM_FlashsafeIntEnable
    #define FlashsafeIntDisable             NOROM_FlashsafeIntDisable
    #define FlashsafeIntStatus              NOROM_FlashsafeIntStatus
    #define FlashsafeIntClear               NOROM_FlashsafeIntClear
    #define FlashsafeSectorErase            NOROM_FlashsafeSectorErase
    #define FlashsafeProgram                NOROM_FlashsafeProgram
    #define FlashsafeProgramNowait          NOROM_FlashsafeProgramNowait
    #define FlashsafeProgramNowaitRelease   NOROM_FlashsafeProgramNowaitRelease
    #define FlashsafeDisableSectorsForWrite NOROM_FlashsafeDisableSectorsForWrite
#endif

//*****************************************************************************
//
// Values that can be returned from the API functions
//
//*****************************************************************************

#define FLASHSAFE_ACCESS_DENIED 0x000000ff
#define FLASHSAFE_ACCESS_OK     0x000000ee
#define SMPH_ALLOC_FLASH   1

//*****************************************************************************
//
// Values that can be returned from the API functions
//
//*****************************************************************************
#define FAPI_STATUS_SUCCESS     0x00000000  // Function completed successfully
#define FAPI_STATUS_FSM_BUSY    0x00000001  // FSM is Busy
#define FAPI_STATUS_FSM_READY   0x00000002  // FSM is Ready
#define FAPI_STATUS_INCORRECT_DATABUFFER_LENGTH \
                                0x00000003  // Incorrect parameter value
#define FAPI_STATUS_FSM_ERROR   0x00000004  // Operation failed

//*****************************************************************************
//
// Values passed to FlashsafeIntEnable(), FlashsafeIntDisable() and FlashsafeIntClear() and
// returned from FlashsafeIntStatus().
//
//*****************************************************************************
#define FLASH_INT_FSM_DONE      0x00400000  // FSM Done Interrupt Mask
#define FLASH_INT_RV            0x00010000  // Read Verify error Interrupt Mask

//*****************************************************************************
//
// Values passed to FlashsafeSetPowerMode() and returned from FlashsafeGetPowerMode().
//
//*****************************************************************************
#define FLASH_PWR_ACTIVE_MODE   0x00000000
#define FLASH_PWR_OFF_MODE      0x00000001
#define FLASH_PWR_DEEP_STDBY_MODE \
                                0x00000002

//*****************************************************************************
//
// Values passed to FlashsafeSetProtection() and returned from FlashsafeGetProtection().
//
//*****************************************************************************
#define FLASH_NO_PROTECT        0x00000000 // Sector not protected
#define FLASH_WRITE_PROTECT     0x00000001 // Sector erase and program
                                           // protected

//*****************************************************************************
//
// Defines for values written to the FLASH_O_FSM_WR_ENA register
//
//*****************************************************************************
#define FSM_REG_WRT_ENABLE     5
#define FSM_REG_WRT_DISABLE    2

//*****************************************************************************
//
//! \brief Aquire the flash semaphore.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE bool
FlashsafeSMPHTryAcquire(void)
{
    return(SMPHTryAcquire(SMPH_ALLOC_FLASH));
}

//*****************************************************************************
//
//! \brief Release the flash semaphore.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
FlashsafeSMPHRelease(void)
{
    SMPHRelease(SMPH_ALLOC_FLASH);
}

//*****************************************************************************
//
//! \brief Get the size of the flash.
//!
//! This function returns the size of the flash main bank in number of bytes.
//!
//! \return Returns the flash size in number of bytes.
//
//*****************************************************************************
extern uint32_t FlashsafeSizeGet(void);

//*****************************************************************************
//
//! \brief Get size of a flash sector in no of bytes.
//!
//! This function will return the size of a flash sector in number of bytes.
//!
//! \return Returns size of a flash sector in number of bytes.
//
//*****************************************************************************
extern uint32_t FlashsafeSectorSizeGet(void);

//*****************************************************************************
//
//! \brief Set power mode.
//!
//! This function will set the specified power mode.
//!
//! Any access to the bank causes a reload of the specified bank grace periode
//! input value into the bank down counter. After the last access to the
//! flash bank, the down counter delays from 0 to 255 prescaled HCLK clock
//! cycles before putting the bank into one of the fallback power modes as
//! determined by \c ui32PowerMode. This value must be greater than 1 when the
//! fallback mode is not \ref FLASH_PWR_ACTIVE_MODE.
//!
//! Note: The prescaled clock used for the down counter is a clock divided by
//! 16 from input HCLK. The \c ui32BankGracePeriode parameter is ignored if
//! \c ui32PowerMode is equal to \ref FLASH_PWR_ACTIVE_MODE.
//! Any access to flash memory causes the pump grace periode down counter to
//! reload with value of \c ui32PumpGracePeriode. After the bank has gone to sleep,
//! the down counter delays this number of prescaled HCLK clock cycles before
//! entering one of the charge pump fallback power modes as determined by
//! \c ui32PowerMode. The prescaled clock used for the pump grace periode down
//! counter is a clock divided by 16 from input HCLK. This parameter is ignored
//! if \c ui32PowerMode is equal to \ref FLASH_PWR_ACTIVE_MODE.
//!
//! In current flash module design the SW application has to call the
//! \ref FlashsafePowerModeSet() funtion with the \ref FLASH_PWR_ACTIVE_MODE input parameter
//! value if the flash modules comes out of any of the two low power modes, in
//! in order to reestablish the factory configured idle reading power reduction
//! mode.
//!
//! Changing the power mode of the flash module must be a part within a
//! device power mode transition requiring configuration of multiple modules.
//! Refer to documents describing the device power modes.
//!
//! \param ui32PowerMode is the wanted power mode.
//! The defined power modes are:
//! - \ref FLASH_PWR_ACTIVE_MODE
//! - \ref FLASH_PWR_OFF_MODE
//! - \ref FLASH_PWR_DEEP_STDBY_MODE
//! \param ui32BankGracePeriode is the starting count value for the bank grace
//! periode down counter.
//! \param ui32PumpGracePeriode is the starting count value for the pump grace
//! periode down counter.
//!
//! \return Returns the status of the power mode setting:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread
//! - \ref FLASHSAFE_ACCESS_OK     : Power mode was set successfully.
//
//*****************************************************************************
extern uint32_t FlashsafePowerModeSet(uint32_t ui32PowerMode,
                                      uint32_t ui32BankGracePeriode,
                                      uint32_t ui32PumpGracePeriode);

//*****************************************************************************
//
//! \brief Get current configured power mode.
//!
//! This function will return the current configured power mode.
//! \return Returns \ref FLASHSAFE_ACCESS_DENIED if flash is blocked by another
//! thread, otherwise the current configured power mode:
//! - \ref FLASH_PWR_ACTIVE_MODE
//! - \ref FLASH_PWR_OFF_MODE
//! - \ref FLASH_PWR_DEEP_STDBY_MODE
//! - \ref FLASHSAFE_ACCESS_DENIED   : Flash is blocked by another thread.
//
//*****************************************************************************
extern uint32_t FlashsafePowerModeGet(void);

//*****************************************************************************
//
//! \brief Set sector protection.
//!
//! This function will set the specified protection on specified flash bank
//! sector. A sector can either have no protection or have write protection
//! which guards for both program and erase of that sector.
//! Sector protection can only be changed from \ref FLASH_NO_PROTECT to
//! \ref FLASH_WRITE_PROTECT!
//!
//! \note After write protecting a sector this sector can
//! only be set back to unprotected by a device reset.
//!
//! \param ui32SectorAddress is the start address of the sector to protect.
//! \param ui32ProtectMode is the enumerated sector protection mode.
//! The defined sector protection modes are:
//! - \ref FLASH_NO_PROTECT
//! - \ref FLASH_WRITE_PROTECT
//!
//! \return Returns status of the sector protection:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Sector protection successful.
//
//*****************************************************************************
extern uint32_t FlashsafeProtectionSet(uint32_t ui32SectorAddress,
                                       uint32_t ui32ProtectMode);

//*****************************************************************************
//
//! \brief Get sector protection.
//!
//! This return the protection mode for the specified flash bank sector.
//!
//! \param ui32SectorAddress is the start address of the desired sector.
//!
//! \return Returns \ref FLASHSAFE_ACCESS_DENIED if flash is used by another thread,
//! else the sector protection:
//! - \ref FLASH_NO_PROTECT
//! - \ref FLASH_WRITE_PROTECT
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is blocked by another thread.
//
//*****************************************************************************
extern uint32_t FlashsafeProtectionGet(uint32_t ui32SectorAddress);

//*****************************************************************************
//
//! \brief Save sector protection to make it permanent.
//!
//! This function will save the the current protection mode for the specified
//! flash bank sector. A write protected sector will become permanent write
//! protected!! A device reset will not change the write protection!
//!
//! \note The actual protection save function called by this function must only be
//! executed from ROM or SRAM.
//!
//! \param ui32SectorAddress is the start address of the sector to be protected.
//!
//! \return Returns status of the flash sector protection:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FAPI_STATUS_SUCCESS     : Success
//! - \ref FAPI_STATUS_FSM_ERROR   : An erase error is encountered.
//
//*****************************************************************************
extern uint32_t FlashsafeProtectionSave(uint32_t ui32SectorAddress);

//*****************************************************************************
//
//! \brief Checks if the Flashsafe state machine has detected an error.
//!
//! This function returns the status of the Flashsafe State Machine indicating if
//! an error is detected or not. Primary use is to check if an Erase or
//! Program operation has failed.
//!
//! \return Returns status of Flashsafe state machine:
//! - \ref FAPI_STATUS_FSM_ERROR
//! - \ref FAPI_STATUS_SUCCESS
//
//*****************************************************************************
extern uint32_t FlashsafeCheckFsmForError(void);

//*****************************************************************************
//
//! \brief Checks if the Flash state machine is ready.
//!
//! This function returns the status of the Flash State Machine indicating if
//! it is ready to accept a new command or not. Primary use is to check if an
//! Erase or Program operation has finished.
//!
//! \return Returns readiness status of Flash state machine:
//! - \ref FAPI_STATUS_FSM_READY
//! - \ref FAPI_STATUS_FSM_BUSY
//
//*****************************************************************************
extern uint32_t FlashsafeCheckFsmForReady(void);

//*****************************************************************************
//
//! \brief Registers an interrupt handler for the flash interrupt.
//!
//! This function does the actual registering of the interrupt handler. This
//! function enables the global interrupt in the interrupt controller; specific
//! FLASH interrupts must be enabled via \ref FlashsafeIntEnable(). It is the interrupt
//! handler's responsibility to clear the interrupt source.
//!
//! \param pfnHandler is a pointer to the function to be called when the flash
//! interrupt occurs.
//!
//! \return Returns the status of the flash registering:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Successful.
//!
//! \sa \ref IntRegister() for important information about registering interrupt
//! handlers.
//
//*****************************************************************************
extern uint32_t FlashsafeIntRegister(void (*pfnHandler)(void));

//*****************************************************************************
//
//! \brief Unregisters the interrupt handler for the flash interrupt.
//!
//! This function does the actual unregistering of the interrupt handler. It
//! clears the handler to be called when a FLASH interrupt occurs. This
//! function also masks off the interrupt in the interrupt controller so that
//! the interrupt handler no longer is called.
//!
//! \return Returns status of the flash unregistering:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Successful.
//!
//! \sa \ref IntRegister() for important information about registering interrupt
//! handlers.
//
//*****************************************************************************
extern uint32_t FlashsafeIntUnregister(void);

//*****************************************************************************
//
//! \brief Enables flash controller interrupt sources.
//!
//! This function enables the flash controller interrupt sources.
//!
//! \param ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//! The parameter is the bitwise OR of any of the following:
//! - \ref FLASH_INT_FSM_DONE : FSM Done interrupt.
//! - \ref FLASH_INT_RV       : Read verify error interrupt.
//!
//! \return Returns status of the function call:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Successful.
//
//*****************************************************************************
extern uint32_t FlashsafeIntEnable(uint32_t ui32IntFlags);

//*****************************************************************************
//
//! \brief Disables individual flash controller interrupt sources.
//!
//! This function disables the flash controller interrupt sources.
//!
//! \param ui32IntFlags is the bit mask of the interrupt sources to be disabled.
//! The parameter is the bitwise OR of any of the following:
//! - \ref FLASH_INT_FSM_DONE : FSM Done interrupt.
//! - \ref FLASH_INT_RV       : Read verify error interrupt.
//!
//! \return Returns status of function call:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Successful.
//
//*****************************************************************************
extern uint32_t FlashsafeIntDisable(uint32_t ui32IntFlags);

//*****************************************************************************
//
//! \brief Gets the current interrupt status.
//!
//! This function returns the interrupt status for the Flash.
//!
//! \return Returns the current interrupt status:
//! - \ref FLASH_INT_FSM_DONE : FSM Done interrupt.
//! - \ref FLASH_INT_RV       : Read verify error interrupt.
//
//*****************************************************************************
extern uint32_t FlashsafeIntStatus(void);

//*****************************************************************************
//
//! \brief Clears flash controller interrupt source.
//!
//! The flash controller interrupt source is cleared, so that it no longer
//! assert. This must be done in the interrupt handler to keep it from being
//! called again immediately upon exit.
//!
//! \note Because there is a write buffer in the CM3 processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared. Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \param ui32IntFlags is the bit mask of the interrupt sources to be cleared.
//! Can be any of:
//! - \ref FLASH_INT_FSM_DONE
//! - \ref FLASH_INT_RV values
//!
//! \return Returns status of the flash interrupt source clearing:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Successful.
//
//*****************************************************************************
extern uint32_t FlashsafeIntClear(uint32_t ui32IntFlags);

//*****************************************************************************
//
//! \brief Erase a flash sector.
//!
//! This function will erase the specified flash sector. The function will
//! not return until the flash sector has been erased or an error condition
//! occurred. If flash top sector is erased the function will program the
//! the device security data bytes with default values. The device security
//! data located in the customer configuration area of the flash top sector,
//! must have valid values at all times. These values affects the configuration
//! of the device during boot.
//!
//! \note Please note that code can not execute in flash while any part of the flash
//! is being programmed or erased. The actual erase function called by this
//! function must only be executed from ROM or SRAM.
//!
//! \param ui32SectorAddress is the starting address in flash of the sector to be
//! erased.
//!
//! \return Returns status of flash sector erase:
//! - \ref FAPI_STATUS_SUCCESS     : Success.
//! - \ref FAPI_STATUS_FSM_ERROR   : A programming error is encountered.
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//
//*****************************************************************************
extern uint32_t FlashsafeSectorErase(uint32_t ui32SectorAddress);

//*****************************************************************************
//
//! \brief Programs unprotected main bank flash sectors.
//!
//! This function will program a sequence of bytes into the on-chip flash.
//! Programming each location consists of the result of an AND operation
//! of the new data and the existing data; in other words bits that contain
//! 1 can remain 1 or be changed to 0, but bits that are 0 cannot be changed
//! to 1.  Therefore, a byte can be programmed multiple times as long as these
//! rules are followed; if a program operation attempts to change a 0 bit to
//! a 1 bit, that bit will not have its value changed.
//!
//! This function will not return until the data has been programmed or an
//! programming error has occurred.
//!
//! \note Please note that code can not execute in flash while any part of the flash
//! is being programmed or erased. The actual programming function called by
//! this function must only be executed from ROM or SRAM.
//!
//! The \c pui8DataBuffer pointer can not point to flash.
//!
//! \param pui8DataBuffer is a pointer to the data to be programmed.
//! \param ui32Address is the starting address in flash to be programmed.
//! \param ui32Count is the number of bytes to be programmed.
//!
//! \return Returns status of flash sector program:
//! - \ref FAPI_STATUS_SUCCESS     : Success.
//! - \ref FAPI_STATUS_FSM_ERROR   : A programming error is encountered.
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//
//*****************************************************************************
extern uint32_t FlashsafeProgram(uint8_t *pui8DataBuffer, uint32_t ui32Address,
                                 uint32_t ui32Count);

//*****************************************************************************
//
//! \brief Disables all sectors for erase and programming on the active bank.
//!
//! This function disables all sectors for erase and programming on the active
//! bank and enables the Idle Reading Power reduction mode if no low power
//! mode is configured. Furthermore, an additional level of protection from
//! erase is enabled.
//!
//! \return Returns the status of the flash sector erase disable:
//! - \ref FLASHSAFE_ACCESS_DENIED : Flash is used by another thread.
//! - \ref FLASHSAFE_ACCESS_OK     : Successful.
//
//*****************************************************************************
extern uint32_t FlashsafeDisableSectorsForWrite(void);

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#ifndef DRIVERLIB_NOROM
    #include <driverlib/rom.h>
    #ifdef ROM_FlashsafeSizeGet
        #undef  FlashsafeSizeGet
        #define FlashsafeSizeGet                ROM_FlashsafeSizeGet
    #endif
    #ifdef ROM_FlashsafeSectorSizeGet
        #undef  FlashsafeSectorSizeGet
        #define FlashsafeSectorSizeGet          ROM_FlashsafeSectorSizeGet
    #endif
    #ifdef ROM_FlashsafePowerModeSet
        #undef  FlashsafePowerModeSet
        #define FlashsafePowerModeSet           ROM_FlashsafePowerModeSet
    #endif
    #ifdef ROM_FlashsafePowerModeGet
        #undef  FlashsafePowerModeGet
        #define FlashsafePowerModeGet           ROM_FlashsafePowerModeGet
    #endif
    #ifdef ROM_FlashsafeProtectionSet
        #undef  FlashsafeProtectionSet
        #define FlashsafeProtectionSet          ROM_FlashsafeProtectionSet
    #endif
    #ifdef ROM_FlashsafeProtectionGet
        #undef  FlashsafeProtectionGet
        #define FlashsafeProtectionGet          ROM_FlashsafeProtectionGet
    #endif
    #ifdef ROM_FlashsafeProtectionSave
        #undef  FlashsafeProtectionSave
        #define FlashsafeProtectionSave         ROM_FlashsafeProtectionSave
    #endif
    #ifdef ROM_FlashsafeCheckFsmForError
        #undef  FlashsafeCheckFsmForError
        #define FlashsafeCheckFsmForError       ROM_FlashsafeCheckFsmForError
    #endif
    #ifdef ROM_FlashsafeCheckFsmForReady
        #undef  FlashsafeCheckFsmForReady
        #define FlashsafeCheckFsmForReady       ROM_FlashsafeCheckFsmForReady
    #endif
    #ifdef ROM_FlashsafeIntRegister
        #undef  FlashsafeIntRegister
        #define FlashsafeIntRegister            ROM_FlashsafeIntRegister
    #endif
    #ifdef ROM_FlashsafeIntUnregister
        #undef  FlashsafeIntUnregister
        #define FlashsafeIntUnregister          ROM_FlashsafeIntUnregister
    #endif
    #ifdef ROM_FlashsafeIntEnable
        #undef  FlashsafeIntEnable
        #define FlashsafeIntEnable              ROM_FlashsafeIntEnable
    #endif
    #ifdef ROM_FlashsafeIntDisable
        #undef  FlashsafeIntDisable
        #define FlashsafeIntDisable             ROM_FlashsafeIntDisable
    #endif
    #ifdef ROM_FlashsafeIntStatus
        #undef  FlashsafeIntStatus
        #define FlashsafeIntStatus              ROM_FlashsafeIntStatus
    #endif
    #ifdef ROM_FlashsafeIntClear
        #undef  FlashsafeIntClear
        #define FlashsafeIntClear               ROM_FlashsafeIntClear
    #endif
    #ifdef ROM_FlashsafeSectorErase
        #undef  FlashsafeSectorErase
        #define FlashsafeSectorErase            ROM_FlashsafeSectorErase
    #endif
    #ifdef ROM_FlashsafeProgram
        #undef  FlashsafeProgram
        #define FlashsafeProgram                ROM_FlashsafeProgram
    #endif
    #ifdef ROM_FlashsafeProgramNowait
        #undef  FlashsafeProgramNowait
        #define FlashsafeProgramNowait          ROM_FlashsafeProgramNowait
    #endif
    #ifdef ROM_FlashsafeProgramNowaitRelease
        #undef  FlashsafeProgramNowaitRelease
        #define FlashsafeProgramNowaitRelease   ROM_FlashsafeProgramNowaitRelease
    #endif
    #ifdef ROM_FlashsafeDisableSectorsForWrite
        #undef  FlashsafeDisableSectorsForWrite
        #define FlashsafeDisableSectorsForWrite ROM_FlashsafeDisableSectorsForWrite
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

#endif // __FLASHSAFE_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//*****************************************************************************
