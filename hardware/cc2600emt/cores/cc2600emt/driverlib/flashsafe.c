/******************************************************************************
*  Filename:       flash.c
*  Revised:        2015-02-03 14:18:59 +0100 (ti, 03 feb 2015)
*  Revision:       42551
*
*  Description:    Thread Safe Driver for the Flash.
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

#include <inc/hw_types.h>
#include <driverlib/flashsafe.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#ifndef DRIVERLIB_GENERATE_ROM
    #undef  FlashsafeSizeGet
    #define FlashsafeSizeGet                NOROM_FlashsafeSizeGet
    #undef  FlashsafeSectorSizeGet
    #define FlashsafeSectorSizeGet          NOROM_FlashsafeSectorSizeGet
    #undef  FlashsafePowerModeSet
    #define FlashsafePowerModeSet           NOROM_FlashsafePowerModeSet
    #undef  FlashsafePowerModeGet
    #define FlashsafePowerModeGet           NOROM_FlashsafePowerModeGet
    #undef  FlashsafeProtectionSet
    #define FlashsafeProtectionSet          NOROM_FlashsafeProtectionSet
    #undef  FlashsafeProtectionGet
    #define FlashsafeProtectionGet          NOROM_FlashsafeProtectionGet
    #undef  FlashsafeProtectionSave
    #define FlashsafeProtectionSave         NOROM_FlashsafeProtectionSave
    #undef  FlashsafeCheckFsmForError
    #define FlashsafeCheckFsmForError       NOROM_FlashsafeCheckFsmForError
    #undef  FlashsafeCheckFsmForReady
    #define FlashsafeCheckFsmForReady       NOROM_FlashsafeCheckFsmForReady
    #undef  FlashsafeIntRegister
    #define FlashsafeIntRegister            NOROM_FlashsafeIntRegister
    #undef  FlashsafeIntUnregister
    #define FlashsafeIntUnregister          NOROM_FlashsafeIntUnregister
    #undef  FlashsafeIntEnable
    #define FlashsafeIntEnable              NOROM_FlashsafeIntEnable
    #undef  FlashsafeIntDisable
    #define FlashsafeIntDisable             NOROM_FlashsafeIntDisable
    #undef  FlashsafeIntStatus
    #define FlashsafeIntStatus              NOROM_FlashsafeIntStatus
    #undef  FlashsafeIntClear
    #define FlashsafeIntClear               NOROM_FlashsafeIntClear
    #undef  FlashsafeSectorErase
    #define FlashsafeSectorErase            NOROM_FlashsafeSectorErase
    #undef  FlashsafeProgram
    #define FlashsafeProgram                NOROM_FlashsafeProgram
    #undef  FlashsafeProgramNowait
    #define FlashsafeProgramNowait          NOROM_FlashsafeProgramNowait
    #undef  FlashsafeProgramNowaitRelease
    #define FlashsafeProgramNowaitRelease   NOROM_FlashsafeProgramNowaitRelease
    #undef  FlashsafeDisableSectorsForWrite
    #define FlashsafeDisableSectorsForWrite NOROM_FlashsafeDisableSectorsForWrite
#endif

//*****************************************************************************
//
//! Get the size of the flash
//
//*****************************************************************************
uint32_t
FlashsafeSizeGet(void)
{
    return(FlashSizeGet());
}

//*****************************************************************************
//
//! Get size of a flash sector in no of bytes
//
//*****************************************************************************
uint32_t
FlashsafeSectorSizeGet(void)
{
    return(FlashSectorSizeGet());
}

//*****************************************************************************
//
//! Set power mode
//
//*****************************************************************************
uint32_t
FlashsafePowerModeSet(uint32_t ui32PowerMode, uint32_t ui32BankGracePeriode,
                      uint32_t ui32PumpGracePeriode)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32PowerMode == FLASH_PWR_ACTIVE_MODE ||
           ui32PowerMode == FLASH_PWR_OFF_MODE    ||
           ui32PowerMode == FLASH_PWR_DEEP_STDBY_MODE);
    ASSERT(ui32BankGracePeriode <= 0xFF);
    ASSERT(ui32PumpGracePeriode <= 0xFFFF);

    if(FlashsafeSMPHTryAcquire())
    {
        FlashPowerModeSet(ui32PowerMode, ui32BankGracePeriode,
                          ui32PumpGracePeriode);
        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Get current configured power mode
//
//*****************************************************************************
uint32_t
FlashsafePowerModeGet(void)
{
    uint32_t ui32PowerMode;

    if(FlashsafeSMPHTryAcquire())
    {
        ui32PowerMode = FlashPowerModeGet();
        FlashsafeSMPHRelease();
        return(ui32PowerMode);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Set sector protection
//
//*****************************************************************************
uint32_t
FlashsafeProtectionSet(uint32_t ui32SectorAddress, uint32_t ui32ProtectMode)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32SectorAddress <= (FLASHMEM_BASE + FlashsafeSizeGet() -
                                 FlashsafeSectorSizeGet()));
    ASSERT((ui32SectorAddress & (FlashsafeSectorSizeGet() - 1)) == 00);

    if(FlashsafeSMPHTryAcquire())
    {
        FlashProtectionSet(ui32SectorAddress, ui32ProtectMode);
        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Get sector protection
//
//*****************************************************************************
uint32_t
FlashsafeProtectionGet(uint32_t ui32SectorAddress)
{
    uint32_t ui32SectorProtect;

    //
    // Check the arguments.
    //
    ASSERT(ui32SectorAddress <= (FLASHMEM_BASE + FlashsafeSizeGet() -
                                 FlashsafeSectorSizeGet()));
    ASSERT((ui32SectorAddress & (FlashsafeSectorSizeGet() - 1)) == 00);

    if(FlashsafeSMPHTryAcquire())
    {
        ui32SectorProtect = FlashProtectionGet(ui32SectorAddress);
        FlashsafeSMPHRelease();
        return(ui32SectorProtect);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Save sector protection to make it permanent
//
//*****************************************************************************
uint32_t
FlashsafeProtectionSave(uint32_t ui32SectorAddress)
{
    uint32_t ui32ErrorReturn;

    //
    // Check the arguments.
    //
    ASSERT(ui32SectorAddress <= (FLASHMEM_BASE + FlashsafeSizeGet() -
                                 FlashsafeSectorSizeGet()));
    ASSERT((ui32SectorAddress & (FlashsafeSectorSizeGet() - 1)) == 00);

    if(FlashsafeSMPHTryAcquire())
    {
        ui32ErrorReturn = FlashProtectionSave(ui32SectorAddress);
        FlashsafeSMPHRelease();
        return(ui32ErrorReturn);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Checks if the Flashsafe state machine has detected an error
//
//*****************************************************************************
uint32_t
FlashsafeCheckFsmForError(void)
{
    if(HWREG(FLASH_BASE + FLASH_O_FMSTAT) & FLASH_FMSTAT_CSTAT)
    {
        return(FAPI_STATUS_FSM_ERROR);
    }
    else
    {
        return(FAPI_STATUS_SUCCESS);
    }
}

//*****************************************************************************
//
//! Checks if the Flash state machine is ready
//
//*****************************************************************************
uint32_t
FlashsafeCheckFsmForReady(void)
{
    if(HWREG(FLASH_BASE + FLASH_O_STAT) & FLASH_STAT_BUSY)
    {
        return(FAPI_STATUS_FSM_BUSY);
    }
    else
    {
        return(FAPI_STATUS_FSM_READY);
    }
}

//*****************************************************************************
//
//! Registers an interrupt handler for the flash interrupt.
//
//*****************************************************************************
uint32_t
FlashsafeIntRegister(void (*pfnHandler)(void))
{
    if(FlashsafeSMPHTryAcquire())
    {
        //
        // Register the interrupt handler.
        //
        IntRegister(INT_FLASH, pfnHandler);

        //
        // Enable the flash interrupt.
        //
        IntEnable(INT_FLASH);

        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Unregisters the interrupt handler for the flash interrupt.
//
//*****************************************************************************
uint32_t
FlashsafeIntUnregister(void)
{
    if(FlashsafeSMPHTryAcquire())
    {
        //
        // Disable the interrupts.
        //
        IntDisable(INT_FLASH);

        //
        // Unregister the interrupt handler.
        //
        IntUnregister(INT_FLASH);

        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Enables flash controller interrupt sources.
//
//*****************************************************************************
uint32_t
FlashsafeIntEnable(uint32_t ui32IntFlags)
{
    if(FlashsafeSMPHTryAcquire())
    {
        HWREG(FLASH_BASE + FLASH_O_FSM_WR_ENA) = FSM_REG_WRT_ENABLE;
        HWREG(FLASH_BASE + FLASH_O_FSM_ST_MACHINE) |= ui32IntFlags;
        HWREG(FLASH_BASE + FLASH_O_FSM_WR_ENA) = FSM_REG_WRT_DISABLE;

        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Disables individual flash controller interrupt sources.
//
//*****************************************************************************
uint32_t
FlashsafeIntDisable(uint32_t ui32IntFlags)
{
    if(FlashsafeSMPHTryAcquire())
    {
        HWREG(FLASH_BASE + FLASH_O_FSM_WR_ENA) = FSM_REG_WRT_ENABLE;
        HWREG(FLASH_BASE + FLASH_O_FSM_ST_MACHINE) &= ~ui32IntFlags;
        HWREG(FLASH_BASE + FLASH_O_FSM_WR_ENA) = FSM_REG_WRT_DISABLE;
        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Gets the current interrupt status
//
//*****************************************************************************
uint32_t
FlashsafeIntStatus(void)
{
    return(FlashIntStatus());
}

//*****************************************************************************
//
//! Clears flash controller interrupt source
//
//*****************************************************************************
uint32_t
FlashsafeIntClear(uint32_t ui32IntFlags)
{
    if(FlashsafeSMPHTryAcquire())
    {
        FlashIntClear(ui32IntFlags);
        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}

//*****************************************************************************
//
//! Erase a flash sector
//
//*****************************************************************************
uint32_t
FlashsafeSectorErase(uint32_t ui32SectorAddress)
{
    uint32_t ui32ErrorReturn;

    //
    // Check the arguments.
    //
    ASSERT(ui32SectorAddress <= (FLASHMEM_BASE + FlashsafeSizeGet() -
                                 FlashsafeSectorSizeGet()));
    ASSERT((ui32SectorAddress & (FlashsafeSectorSizeGet() - 1)) == 00);

    if(FlashsafeSMPHTryAcquire())
    {
        ui32ErrorReturn = FlashSectorErase(ui32SectorAddress);
        FlashsafeSMPHRelease();
        return(ui32ErrorReturn);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}


//*****************************************************************************
//
//! Programs unprotected main bank flash sectors
//
//*****************************************************************************
uint32_t
FlashsafeProgram(uint8_t *pui8DataBuffer, uint32_t ui32Address, uint32_t ui32Count)
{
    uint32_t ui32ErrorReturn;

    //
    // Check the arguments.
    //
    ASSERT((ui32Address + ui32Count) <= (FLASHMEM_BASE + FlashsafeSizeGet()));

    if(FlashsafeSMPHTryAcquire())
    {
        ui32ErrorReturn = FlashProgram(pui8DataBuffer, ui32Address, ui32Count);
        FlashsafeSMPHRelease();
        return(ui32ErrorReturn);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}


//*****************************************************************************
//
//! Disables all sectors for erase and programming on the active bank
//
//*****************************************************************************
uint32_t
FlashsafeDisableSectorsForWrite(void)
{

    if(FlashsafeSMPHTryAcquire())
    {
        FlashDisableSectorsForWrite();
        FlashsafeSMPHRelease();
        return(FLASHSAFE_ACCESS_OK);
    }

    return(FLASHSAFE_ACCESS_DENIED);
}
