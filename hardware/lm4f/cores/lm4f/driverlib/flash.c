//*****************************************************************************
//
// flash.c - Driver for programming the on-chip flash.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup flash_api
//! @{
//
//*****************************************************************************

#include "inc/hw_flash.h"
#include "inc/hw_ints.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/flash.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
// An array that maps the specified memory bank to the appropriate Flash
// Memory Protection Program Enable (FMPPE) register.
//
//*****************************************************************************
static const unsigned long g_pulFMPPERegs[] =
{
    FLASH_FMPPE,
    FLASH_FMPPE1,
    FLASH_FMPPE2,
    FLASH_FMPPE3
};

//*****************************************************************************
//
// An array that maps the specified memory bank to the appropriate Flash
// Memory Protection Read Enable (FMPRE) register.
//
//*****************************************************************************
static const unsigned long g_pulFMPRERegs[] =
{
    FLASH_FMPRE,
    FLASH_FMPRE1,
    FLASH_FMPRE2,
    FLASH_FMPRE3
};

//*****************************************************************************
//
//! Gets the number of processor clocks per micro-second.
//!
//! This function returns the number of clocks per micro-second, as presently
//! known by the flash controller. This function is only valid on Sandstorm-
//! and Fury-class devices.
//!
//! \return Returns the number of processor clocks per micro-second.
//
//*****************************************************************************
unsigned long
FlashUsecGet(void)
{
    //
    // Return the number of clocks per micro-second.
    //
    return(HWREG(FLASH_USECRL) + 1);
}

//*****************************************************************************
//
//! Sets the number of processor clocks per micro-second.
//!
//! \param ulClocks is the number of processor clocks per micro-second.
//!
//! This function is used to tell the flash controller the number of processor
//! clocks per micro-second.  This value must be programmed correctly or the
//! flash most likely will not program correctly; it has no affect on reading
//! flash. This function is only valid on Sandstorm- and Fury-class devices.
//!
//! \return None.
//
//*****************************************************************************
void
FlashUsecSet(unsigned long ulClocks)
{
    //
    // Set the number of clocks per micro-second.
    //
    HWREG(FLASH_USECRL) = ulClocks - 1;
}

//*****************************************************************************
//
//! Erases a block of flash.
//!
//! \param ulAddress is the start address of the flash block to be erased.
//!
//! This function erases a 1-kB block of the on-chip flash.  After erasing,
//! the block is filled with 0xFF bytes.  Read-only and execute-only blocks
//! cannot be erased.
//!
//! This function does not return until the block has been erased.
//!
//! \return Returns 0 on success, or -1 if an invalid block address was
//! specified or the block is write-protected.
//
//*****************************************************************************
long
FlashErase(unsigned long ulAddress)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ulAddress & (FLASH_ERASE_SIZE - 1)));

    //
    // Clear the flash access and error interrupts.
    //
    HWREG(FLASH_FCMISC) = (FLASH_FCMISC_AMISC | FLASH_FCMISC_VOLTMISC |
                           FLASH_FCMISC_ERMISC);

    //
    // Erase the block.
    //
    HWREG(FLASH_FMA) = ulAddress;
    HWREG(FLASH_FMC) = FLASH_FMC_WRKEY | FLASH_FMC_ERASE;

    //
    // Wait until the block has been erased.
    //
    while(HWREG(FLASH_FMC) & FLASH_FMC_ERASE)
    {
    }

    //
    // Return an error if an access violation or erase error occurred.
    //
    if(HWREG(FLASH_FCRIS) & (FLASH_FCRIS_ARIS | FLASH_FCRIS_VOLTRIS |
                             FLASH_FCRIS_ERRIS))
    {
        return(-1);
    }

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Programs flash.
//!
//! \param pulData is a pointer to the data to be programmed.
//! \param ulAddress is the starting address in flash to be programmed.  Must
//! be a multiple of four.
//! \param ulCount is the number of bytes to be programmed.  Must be a multiple
//! of four.
//!
//! This function programs a sequence of words into the on-chip flash.
//! Each word in a page of flash can only be programmed one time between an
//! erase of that page; programming a word multiple times results in an
//! unpredictable value in that word of flash.
//!
//! Because the flash is programmed one word at a time, the starting address
//! and byte count must both be multiples of four.  It is up to the caller to
//! verify the programmed contents, if such verification is required.
//!
//! This function does not return until the data has been programmed.
//!
//! \return Returns 0 on success, or -1 if a programming error is encountered.
//
//*****************************************************************************
long
FlashProgram(unsigned long *pulData, unsigned long ulAddress,
             unsigned long ulCount)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ulAddress & 3));
    ASSERT(!(ulCount & 3));

    //
    // Clear the flash access and error interrupts.
    //
    HWREG(FLASH_FCMISC) = (FLASH_FCMISC_AMISC | FLASH_FCMISC_VOLTMISC |
                           FLASH_FCMISC_INVDMISC | FLASH_FCMISC_PROGMISC);

    //
    // See if this device has a write buffer.
    //
    if(HWREG(SYSCTL_NVMSTAT) & SYSCTL_NVMSTAT_FWB)
    {
        //
        // Loop over the words to be programmed.
        //
        while(ulCount)
        {
            //
            // Set the address of this block of words.
            //
            HWREG(FLASH_FMA) = ulAddress & ~(0x7f);

            //
            // Loop over the words in this 32-word block.
            //
            while(((ulAddress & 0x7c) || (HWREG(FLASH_FWBVAL) == 0)) &&
                  (ulCount != 0))
            {
                //
                // Write this word into the write buffer.
                //
                HWREG(FLASH_FWBN + (ulAddress & 0x7c)) = *pulData++;
                ulAddress += 4;
                ulCount -= 4;
            }

            //
            // Program the contents of the write buffer into flash.
            //
            HWREG(FLASH_FMC2) = FLASH_FMC2_WRKEY | FLASH_FMC2_WRBUF;

            //
            // Wait until the write buffer has been programmed.
            //
            while(HWREG(FLASH_FMC2) & FLASH_FMC2_WRBUF)
            {
            }
        }
    }
    else
    {
        //
        // Loop over the words to be programmed.
        //
        while(ulCount)
        {
            //
            // Program the next word.
            //
            HWREG(FLASH_FMA) = ulAddress;
            HWREG(FLASH_FMD) = *pulData;
            HWREG(FLASH_FMC) = FLASH_FMC_WRKEY | FLASH_FMC_WRITE;

            //
            // Wait until the word has been programmed.
            //
            while(HWREG(FLASH_FMC) & FLASH_FMC_WRITE)
            {
            }

            //
            // Increment to the next word.
            //
            pulData++;
            ulAddress += 4;
            ulCount -= 4;
        }
    }

    //
    // Return an error if an access violation occurred.
    //
    if(HWREG(FLASH_FCRIS) & (FLASH_FCRIS_ARIS | FLASH_FCRIS_VOLTRIS |
                             FLASH_FCRIS_INVDRIS | FLASH_FCRIS_PROGRIS))
    {
        return(-1);
    }

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Gets the protection setting for a block of flash.
//!
//! \param ulAddress is the start address of the flash block to be queried.
//!
//! This function gets the current protection for the specified 2-kB block
//! of flash.  Each block can be read/write, read-only, or execute-only.
//! Read/write blocks can be read, executed, erased, and programmed.  Read-only
//! blocks can be read and executed.  Execute-only blocks can only be executed;
//! processor and debugger data reads are not allowed.
//!
//! \return Returns the protection setting for this block.  See
//! FlashProtectSet() for possible values.
//
//*****************************************************************************
tFlashProtection
FlashProtectGet(unsigned long ulAddress)
{
    unsigned long ulFMPRE, ulFMPPE;
    unsigned long ulBank;

    //
    // Check the argument.
    //
    ASSERT(!(ulAddress & (FLASH_PROTECT_SIZE - 1)));

    //
    // Calculate the Flash Bank from Base Address, and mask off the Bank
    // from ulAddress for subsequent reference.
    //
    ulBank = (((ulAddress / FLASH_PROTECT_SIZE) / 32) % 4);
    ulAddress &= ((FLASH_PROTECT_SIZE * 32) - 1);

    //
    // Read the appropriate flash protection registers for the specified
    // flash bank.
    //
    ulFMPRE = HWREG(g_pulFMPRERegs[ulBank]);
    ulFMPPE = HWREG(g_pulFMPPERegs[ulBank]);

    //
    // For Stellaris Sandstorm-class devices, revision C1 and C2, the upper
    // bits of the FMPPE register are used for JTAG protect options, and are
    // not available for the FLASH protection scheme.  When Querying Block
    // Protection, assume these bits are 1.
    //
    if(CLASS_IS_SANDSTORM && (REVISION_IS_C1 || REVISION_IS_C2))
    {
        ulFMPRE |= (FLASH_FMP_BLOCK_31 | FLASH_FMP_BLOCK_30);
    }

    //
    // Check the appropriate protection bits for the block of memory that
    // is specified by the address.
    //
    switch((((ulFMPRE >> (ulAddress / FLASH_PROTECT_SIZE)) &
             FLASH_FMP_BLOCK_0) << 1) |
           ((ulFMPPE >> (ulAddress / FLASH_PROTECT_SIZE)) & FLASH_FMP_BLOCK_0))
    {
        //
        // This block is marked as execute only (that is, it can not be erased
        // or programmed, and the only reads allowed are via the instruction
        // fetch interface).
        //
        case 0:
        case 1:
        {
            return(FlashExecuteOnly);
        }

        //
        // This block is marked as read only (that is, it can not be erased or
        // programmed).
        //
        case 2:
        {
            return(FlashReadOnly);
        }

        //
        // This block is read/write; it can be read, erased, and programmed.
        //
        case 3:
        default:
        {
            return(FlashReadWrite);
        }
    }
}

//*****************************************************************************
//
//! Sets the protection setting for a block of flash.
//!
//! \param ulAddress is the start address of the flash block to be protected.
//! \param eProtect is the protection to be applied to the block.  Can be one
//! of \b FlashReadWrite, \b FlashReadOnly, or \b FlashExecuteOnly.
//!
//! This function sets the protection for the specified 2-kB block of
//! flash.  Blocks that are read/write can be made read-only or execute-only.
//! Blocks that are read-only can be made execute-only.  Blocks that are
//! execute-only cannot have their protection modified.  Attempts to make the
//! block protection less stringent (that is, read-only to read/write)
//! result in a failure (and are prevented by the hardware).
//!
//! Changes to the flash protection are maintained only until the next reset.
//! This protocol allows the application to be executed in the desired flash
//! protection environment to check for inappropriate flash access (via the
//! flash interrupt).  To make the flash protection permanent, use the
//! FlashProtectSave() function.
//!
//! \return Returns 0 on success, or -1 if an invalid address or an invalid
//! protection was specified.
//
//*****************************************************************************
long
FlashProtectSet(unsigned long ulAddress, tFlashProtection eProtect)
{
    unsigned long ulProtectRE, ulProtectPE;
    unsigned long ulBank;

    //
    // Check the argument.
    //
    ASSERT(!(ulAddress & (FLASH_PROTECT_SIZE - 1)));
    ASSERT((eProtect == FlashReadWrite) || (eProtect == FlashReadOnly) ||
           (eProtect == FlashExecuteOnly));

    //
    // Convert the address into a block number.
    //
    ulAddress /= FLASH_PROTECT_SIZE;

    //
    // ulAddress contains a "raw" block number.  Derive the Flash Bank from
    // the "raw" block number, and convert ulAddress to a "relative"
    // block number.
    //
    ulBank = ((ulAddress / 32) % 4);
    ulAddress %= 32;

    //
    // Get the current protection for the specified flash bank.
    //
    ulProtectRE = HWREG(g_pulFMPRERegs[ulBank]);
    ulProtectPE = HWREG(g_pulFMPPERegs[ulBank]);

    //
    // For Stellaris Sandstorm-class devices, revision C1 and C2, the upper
    // bits of the FMPPE register are used for JTAG protect options, and are
    // not available for the FLASH protection scheme.  When setting protection,
    // check to see if block 30 or 31 and protection is FlashExecuteOnly.  If
    // so, return an error condition.
    //
    if(CLASS_IS_SANDSTORM && (REVISION_IS_C1 || REVISION_IS_C2))
    {
        if((ulAddress >= 30) && (eProtect == FlashExecuteOnly))
        {
            return(-1);
        }
    }

    //
    // Set the protection based on the requested proection.
    //
    switch(eProtect)
    {
        //
        // Make this block execute only.
        //
        case FlashExecuteOnly:
        {
            //
            // Turn off the read and program bits for this block.
            //
            ulProtectRE &= ~(FLASH_FMP_BLOCK_0 << ulAddress);
            ulProtectPE &= ~(FLASH_FMP_BLOCK_0 << ulAddress);

            //
            // We're done handling this protection.
            //
            break;
        }

        //
        // Make this block read only.
        //
        case FlashReadOnly:
        {
            //
            // The block can not be made read only if it is execute only.
            //
            if(((ulProtectRE >> ulAddress) & FLASH_FMP_BLOCK_0) !=
               FLASH_FMP_BLOCK_0)
            {
                return(-1);
            }

            //
            // Make this block read only.
            //
            ulProtectPE &= ~(FLASH_FMP_BLOCK_0 << ulAddress);

            //
            // We're done handling this protection.
            //
            break;
        }

        //
        // Make this block read/write.
        //
        case FlashReadWrite:
        default:
        {
            //
            // The block can not be made read/write if it is not already
            // read/write.
            //
            if((((ulProtectRE >> ulAddress) & FLASH_FMP_BLOCK_0) !=
                FLASH_FMP_BLOCK_0) ||
               (((ulProtectPE >> ulAddress) & FLASH_FMP_BLOCK_0) !=
                FLASH_FMP_BLOCK_0))
            {
                return(-1);
            }

            //
            // The block is already read/write, so there is nothing to do.
            //
            return(0);
        }
    }

    //
    // For Stellaris Sandstorm-class devices, revision C1 and C2, the upper
    // bits of the FMPPE register are used for JTAG options, and are not
    // available for the FLASH protection scheme.  When setting block
    // protection, ensure that these bits are not altered.
    //
    if(CLASS_IS_SANDSTORM && (REVISION_IS_C1 || REVISION_IS_C2))
    {
        ulProtectRE &= ~(FLASH_FMP_BLOCK_31 | FLASH_FMP_BLOCK_30);
        ulProtectRE |= (HWREG(g_pulFMPRERegs[ulBank]) &
                        (FLASH_FMP_BLOCK_31 | FLASH_FMP_BLOCK_30));
    }

    //
    // Set the new protection for the specified flash bank.
    //
    HWREG(g_pulFMPRERegs[ulBank]) = ulProtectRE;
    HWREG(g_pulFMPPERegs[ulBank]) = ulProtectPE;

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Saves the flash protection settings.
//!
//! This function makes the currently programmed flash protection settings
//! permanent.  On some devices, this operation is non-reversible; a chip reset
//! or power cycle does not change the flash protection.
//!
//! This function does not return until the protection has been saved.
//!
//! \return Returns 0 on success, or -1 if a hardware error is encountered.
//
//*****************************************************************************
long
FlashProtectSave(void)
{
    unsigned long ulTemp, ulLimit;

    //
    // If running on a Sandstorm-class device, only trigger a save of the first
    // two protection registers (FMPRE and FMPPE).  Otherwise, save the
    // entire bank of flash protection registers.
    //
    ulLimit = CLASS_IS_SANDSTORM ? 2 : 8;
    for(ulTemp = 0; ulTemp < ulLimit; ulTemp++)
    {
        //
        // Tell the flash controller to write the flash protection register.
        //
        HWREG(FLASH_FMA) = ulTemp;
        HWREG(FLASH_FMC) = FLASH_FMC_WRKEY | FLASH_FMC_COMT;

        //
        // Wait until the write has completed.
        //
        while(HWREG(FLASH_FMC) & FLASH_FMC_COMT)
        {
        }
    }

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Gets the user registers.
//!
//! \param pulUser0 is a pointer to the location to store USER Register 0.
//! \param pulUser1 is a pointer to the location to store USER Register 1.
//!
//! This function reads the contents of user registers (0 and 1), and
//! stores them in the specified locations.
//!
//! \return Returns 0 on success, or -1 if a hardware error is encountered.
//
//*****************************************************************************
long
FlashUserGet(unsigned long *pulUser0, unsigned long *pulUser1)
{
    //
    // Verify that the pointers are valid.
    //
    ASSERT(pulUser0 != 0);
    ASSERT(pulUser1 != 0);

    //
    // Verify that hardware supports user registers.
    //
    if(CLASS_IS_SANDSTORM)
    {
        return(-1);
    }

    //
    // Get and store the current value of the user registers.
    //
    *pulUser0 = HWREG(FLASH_USERREG0);
    *pulUser1 = HWREG(FLASH_USERREG1);

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Sets the user registers.
//!
//! \param ulUser0 is the value to store in USER Register 0.
//! \param ulUser1 is the value to store in USER Register 1.
//!
//! This function sets the contents of the user registers (0 and 1) to
//! the specified values.
//!
//! \return Returns 0 on success, or -1 if a hardware error is encountered.
//
//*****************************************************************************
long
FlashUserSet(unsigned long ulUser0, unsigned long ulUser1)
{
    //
    // Verify that hardware supports user registers.
    //
    if(CLASS_IS_SANDSTORM)
    {
        return(-1);
    }

    //
    // Save the new values into the user registers.
    //
    HWREG(FLASH_USERREG0) = ulUser0;
    HWREG(FLASH_USERREG1) = ulUser1;

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Saves the user registers.
//!
//! This function makes the currently programmed user register settings
//! permanent.  On some devices, this operation is non-reversible; a chip reset
//! or power cycle does not change this setting.
//!
//! This function does not return until the protection has been saved.
//!
//! \return Returns 0 on success, or -1 if a hardware error is encountered.
//
//*****************************************************************************
long
FlashUserSave(void)
{
    //
    // Verify that hardware supports user registers.
    //
    if(CLASS_IS_SANDSTORM)
    {
        return(-1);
    }

    //
    // Setting the MSB of FMA will trigger a permanent save of a USER
    // register.  Bit 0 will indicate User 0 (0) or User 1 (1).
    //
    HWREG(FLASH_FMA) = 0x80000000;
    HWREG(FLASH_FMC) = FLASH_FMC_WRKEY | FLASH_FMC_COMT;

    //
    // Wait until the write has completed.
    //
    while(HWREG(FLASH_FMC) & FLASH_FMC_COMT)
    {
    }

    //
    // Tell the flash controller to write the USER1 Register.
    //
    HWREG(FLASH_FMA) = 0x80000001;
    HWREG(FLASH_FMC) = FLASH_FMC_WRKEY | FLASH_FMC_COMT;

    //
    // Wait until the write has completed.
    //
    while(HWREG(FLASH_FMC) & FLASH_FMC_COMT)
    {
    }

    //
    // Success.
    //
    return(0);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the flash interrupt.
//!
//! \param pfnHandler is a pointer to the function to be called when the flash
//! interrupt occurs.
//!
//! This function sets the handler to be called when the flash interrupt
//! occurs.  The flash controller can generate an interrupt when an invalid
//! flash access occurs, such as trying to program or erase a read-only block,
//! or trying to read from an execute-only block.  It can also generate an
//! interrupt when a program or erase operation has completed.  The interrupt
//! is automatically enabled when the handler is registered.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
FlashIntRegister(void (*pfnHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(INT_FLASH, pfnHandler);

    //
    // Enable the flash interrupt.
    //
    IntEnable(INT_FLASH);
}

//*****************************************************************************
//
//! Unregisters the interrupt handler for the flash interrupt.
//!
//! This function clears the handler to be called when the flash interrupt
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
FlashIntUnregister(void)
{
    //
    // Disable the interrupt.
    //
    IntDisable(INT_FLASH);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_FLASH);
}

//*****************************************************************************
//
//! Enables individual flash controller interrupt sources.
//!
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//! Can be any of the \b FLASH_INT_PROGRAM or \b FLASH_INT_ACCESS values.
//!
//! This function enables the indicated flash controller interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! \return None.
//
//*****************************************************************************
void
FlashIntEnable(unsigned long ulIntFlags)
{
    //
    // Enable the specified interrupts.
    //
    HWREG(FLASH_FCIM) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables individual flash controller interrupt sources.
//!
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//! Can be any of the \b FLASH_INT_PROGRAM or \b FLASH_INT_ACCESS values.
//!
//! This function disables the indicated flash controller interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! \return None.
//
//*****************************************************************************
void
FlashIntDisable(unsigned long ulIntFlags)
{
    //
    // Disable the specified interrupts.
    //
    HWREG(FLASH_FCIM) &= ~(ulIntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param bMasked is false if the raw interrupt status is required and true if
//! the masked interrupt status is required.
//!
//! This function returns the interrupt status for the flash controller.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! \b FLASH_INT_PROGRAM and \b FLASH_INT_ACCESS.
//
//*****************************************************************************
unsigned long
FlashIntStatus(tBoolean bMasked)
{
    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(FLASH_FCMISC));
    }
    else
    {
        return(HWREG(FLASH_FCRIS));
    }
}

//*****************************************************************************
//
//! Clears flash controller interrupt sources.
//!
//! \param ulIntFlags is the bit mask of the interrupt sources to be cleared.
//! Can be any of the \b FLASH_INT_PROGRAM or \b FLASH_INT_AMISC values.
//!
//! The specified flash controller interrupt sources are cleared, so that they
//! no longer assert.  This function must be called in the interrupt handler
//! to keep the interrupt from being triggered again immediately upon exit.
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
FlashIntClear(unsigned long ulIntFlags)
{
    //
    // Clear the flash interrupt.
    //
    HWREG(FLASH_FCMISC) = ulIntFlags;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
