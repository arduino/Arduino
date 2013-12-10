//*****************************************************************************
//
// shamd5.c - Driver for the SHA/MD5 module.
//
// Copyright (c) 2012-2013 Texas Instruments Incorporated.  All rights reserved.
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

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_shamd5.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/shamd5.h"

//*****************************************************************************
//
//! \addtogroup shamd5_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Resets the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//!
//! This function performs a soft-reset of the SHA/MD5 module using the
//! SYSCONFIG register.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5Reset(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Set the soft-reset bit.
    //
    HWREG(ui32Base + SHAMD5_O_SYSCONFIG) |= SHAMD5_SYSCONFIG_SOFTRESET;

    //
    // Wait for the reset to complete.
    //
    while((HWREG(ui32Base + SHAMD5_O_SYSSTATUS) &
           SHAMD5_SYSSTATUS_RESETDONE) == 0)
    {
    }

    //
    // Force idle mode.
    //
    HWREG(ui32Base + SHAMD5_O_SYSCONFIG) =
        ((HWREG(ui32Base + SHAMD5_O_SYSCONFIG) & ~SHAMD5_SYSCONFIG_SIDLE_M) |
         SHAMD5_SYSCONFIG_SIDLE_FORCE);
}

//*****************************************************************************
//
//! Enables the uDMA requests in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//!
//! This function configures the DMA options of the SHA/MD5 module.
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5DMAEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Write the new configuration into the register.
    //
    HWREG(ui32Base + SHAMD5_O_SYSCONFIG) |=
        SHAMD5_SYSCONFIG_SADVANCED | SHAMD5_SYSCONFIG_DMA_EN;
}

//*****************************************************************************
//
//! Disables the uDMA requests in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//!
//! This function configures the DMA options of the SHA/MD5 module.
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5DMADisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Write the new configuration into the register.
    //
    HWREG(ui32Base + SHAMD5_O_SYSCONFIG) &=
        ~(SHAMD5_SYSCONFIG_SADVANCED | SHAMD5_SYSCONFIG_DMA_EN);
}

//*****************************************************************************
//
//! Get the interrupt status of the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param bMasked is \b false if the raw interrupt status is required and
//! \b true if the masked interrupt status is required.
//!
//! This function returns the current value of the IRQSTATUS register.  The
//! value will be a logical OR of the following:
//!
//! - \b SHAMD5_INT_CONTEXT_READY - Context input registers are ready.
//! - \b SHAMD5_INT_PARTHASH_READY - Context output registers are ready after
//!   a context switch.
//! - \b SHAMD5_INT_INPUT_READY - Data FIFO is ready to receive data.
//! - \b SHAMD5_INT_OUTPUT_READY - Context output registers are ready.
//!
//! \return Interrupt status
//
//*****************************************************************************
uint32_t
SHAMD5IntStatus(uint32_t ui32Base, bool bMasked)
{
    uint32_t ui32Status, ui32Enable, ui32Temp;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Return the value of the IRQSTATUS register.
    //
    ui32Status = HWREG(ui32Base + SHAMD5_O_IRQSTATUS);
    if(bMasked)
    {
        ui32Enable = HWREG(ui32Base + SHAMD5_O_IRQENABLE);
        ui32Temp = HWREG(ui32Base + SHAMD5_O_DMAMIS);
        return((ui32Status & ui32Enable) |
               ((ui32Temp & 0x00000001) << 19) |
               ((ui32Temp & 0x00000002) << 16) |
               ((ui32Temp & 0x00000004) << 14));
    }
    else
    {
        ui32Temp = HWREG(ui32Base + SHAMD5_O_DMARIS);
        return(ui32Status |
               ((ui32Temp & 0x00000001) << 19) |
               ((ui32Temp & 0x00000002) << 16) |
               ((ui32Temp & 0x00000004) << 14));
    }
}

//*****************************************************************************
//
//! Enable interrupt sources in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param ui32IntFlags contains desired interrupts to enable.
//!
//! This function enables interrupt sources in the SHA/MD5 module.
//! ui32IntFlags must be a logical OR of one or more of the following
//! values:
//!
//! - \b SHAMD5_INT_CONTEXT_READY - Context input registers are ready.
//! - \b SHAMD5_INT_PARTHASH_READY - Context output registers are ready after
//!   a context switch.
//! - \b SHAMD5_INT_INPUT_READY - Data FIFO is ready to receive data.
//! - \b SHAMD5_INT_OUTPUT_READY - Context output registers are ready.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5IntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);
    ASSERT((ui32IntFlags == SHAMD5_INT_CONTEXT_READY) ||
           (ui32IntFlags == SHAMD5_INT_PARTHASH_READY) ||
           (ui32IntFlags == SHAMD5_INT_INPUT_READY) ||
           (ui32IntFlags == SHAMD5_INT_OUTPUT_READY));

    //
    // Enable the interrupt sources.
    //
    HWREG(ui32Base + SHAMD5_O_DMAIM) |= (((ui32IntFlags & 0x00010000) >> 14) |
                                         ((ui32IntFlags & 0x00020000) >> 16) |
                                         ((ui32IntFlags & 0x00040000) >> 19));
    HWREG(ui32Base + SHAMD5_O_IRQENABLE) |= ui32IntFlags & 0x0000ffff;

    //
    // Enable all interrupts.
    //
    HWREG(ui32Base + SHAMD5_O_SYSCONFIG) |= SHAMD5_SYSCONFIG_IT_EN;
}

//*****************************************************************************
//
//! Disable interrupt sources in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param ui32IntFlags contains desired interrupts to disable.
//!
//! \e ui32IntFlags must be a logical OR of one or more of the following
//! values:
//!
//! - \b SHAMD5_INT_CONTEXT_READY - Context input registers are ready.
//! - \b SHAMD5_INT_PARTHASH_READY - Context output registers are ready after
//!   a context switch.
//! - \b SHAMD5_INT_INPUT_READY - Data FIFO is ready to receive data.
//! - \b SHAMD5_INT_OUTPUT_READY - Context output registers are ready.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5IntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);
    ASSERT((ui32IntFlags == SHAMD5_INT_CONTEXT_READY) ||
           (ui32IntFlags == SHAMD5_INT_PARTHASH_READY) ||
           (ui32IntFlags == SHAMD5_INT_INPUT_READY) ||
           (ui32IntFlags == SHAMD5_INT_OUTPUT_READY));

    //
    // Clear the corresponding flags disabling the interrupt sources.
    //
    HWREG(ui32Base + SHAMD5_O_DMAIM) &= ~(((ui32IntFlags & 0x00010000) >> 14) |
                                          ((ui32IntFlags & 0x00020000) >> 16) |
                                          ((ui32IntFlags & 0x00040000) >> 19));
    HWREG(ui32Base + SHAMD5_O_IRQENABLE) &= ~(ui32IntFlags & 0x0000ffff);

    //
    // If there are no interrupts enabled, then disable all interrupts.
    //
    if(HWREG(ui32Base + SHAMD5_O_IRQENABLE) == 0x0)
    {
        HWREG(ui32Base + SHAMD5_O_SYSCONFIG) &= ~SHAMD5_SYSCONFIG_IT_EN;
    }
}

//*****************************************************************************
//
//! Clears interrupt sources in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param ui32IntFlags contains desired interrupts to disable.
//!
//! \e ui32IntFlags must be a logical OR of one or more of the following
//! values:
//!
//! - \b SHAMD5_INT_CONTEXT_READY - Context input registers are ready.
//! - \b SHAMD5_INT_PARTHASH_READY - Context output registers are ready after
//!   a context switch.
//! - \b SHAMD5_INT_INPUT_READY - Data FIFO is ready to receive data.
//! - \b SHAMD5_INT_OUTPUT_READY - Context output registers are ready.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5IntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);
    ASSERT((ui32IntFlags == SHAMD5_INT_CONTEXT_READY) ||
           (ui32IntFlags == SHAMD5_INT_PARTHASH_READY) ||
           (ui32IntFlags == SHAMD5_INT_INPUT_READY) ||
           (ui32IntFlags == SHAMD5_INT_OUTPUT_READY));

    //
    // Clear the corresponding flags disabling the interrupt sources.
    //
    HWREG(ui32Base + SHAMD5_O_DMAIC) = (((ui32IntFlags & 0x00010000) >> 14) |
                                        ((ui32IntFlags & 0x00020000) >> 16) |
                                        ((ui32IntFlags & 0x00040000) >> 19));
}

//*****************************************************************************
//
//! Registers an interrupt handler for the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pfnHandler is a pointer to the function to be called when the
//! enabled SHA/MD5 interrupts occur.
//!
//! This function registers the interrupt handler in the interrupt vector
//! table, and enables SHA/MD5 interrupts on the interrupt controller;
//! specific SHA/MD5 interrupt sources must be enabled using
//! SHAMD5IntEnable().  The interrupt handler being registered must clear
//! the source of the interrupt using SHAMD5IntClear().
//!
//! If the application is using a static interrupt vector table stored in
//! flash, then it is not necessary to register the interrupt handler this way.
//! Instead, IntEnable() should be used to enable SHA/MD5 interrupts on the
//! interrupt controller.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5IntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_SHA0_SNOWFLAKE, pfnHandler);

    //
    // Enable the interrupt
    //
    IntEnable(INT_SHA0_SNOWFLAKE);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//!
//! This function unregisters the previously registered interrupt handler and
//! disables the interrupt in the interrupt controller.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5IntUnregister(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Disable the interrupt.
    //
    IntDisable(INT_SHA0_SNOWFLAKE);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_SHA0_SNOWFLAKE);
}

//*****************************************************************************
//
//! Write the hash length to the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param ui32Length is the hash length in bytes.
//!
//! This function writes the length of the hash data of the current operation
//! to the SHA/MD5 module.  The value must be a multiple of 64 if the close
//! hash is not set in the mode register.
//!
//! \note When this register is written, hash processing is triggered.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5HashLengthSet(uint32_t ui32Base, uint32_t ui32Length)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Set the LENGTH register and start processing.
    //
    HWREG(ui32Base + SHAMD5_O_LENGTH) = ui32Length;
}

//*****************************************************************************
//
//! Writes the mode in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param ui32Mode is the mode of the SHA/MD5 module.
//!
//! This function writes the mode register configuring the SHA/MD5 module.
//!
//! The ui32Mode parameter is a bit-wise OR of values:
//!
//! - \b SHAMD5_ALGO_MD5 - Regular hash with MD5
//! - \b SHAMD5_ALGO_SHA1 - Regular hash with SHA-1
//! - \b SHAMD5_ALGO_SHA224 - Regular hash with SHA-224
//! - \b SHAMD5_ALGO_SHA256 - Regular hash with SHA-256
//! - \b SHAMD5_ALGO_HMAC_MD5 - HMAC with MD5
//! - \b SHAMD5_ALGO_HMAC_SHA1 - HMAC with SHA-1
//! - \b SHAMD5_ALGO_HMAC_SHA224 - HMAC with SHA-224
//! - \b SHAMD5_ALGO_HMAC_SHA256 - HMAC with SHA-256
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5ConfigSet(uint32_t ui32Base, uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);
    ASSERT((ui32Mode == SHAMD5_ALGO_MD5) ||
           (ui32Mode == SHAMD5_ALGO_SHA1) ||
           (ui32Mode == SHAMD5_ALGO_SHA224) ||
           (ui32Mode == SHAMD5_ALGO_SHA256) ||
           (ui32Mode == SHAMD5_ALGO_HMAC_MD5) ||
           (ui32Mode == SHAMD5_ALGO_HMAC_SHA1) ||
           (ui32Mode == SHAMD5_ALGO_HMAC_SHA224) ||
           (ui32Mode == SHAMD5_ALGO_HMAC_SHA256));

    //
    // Write the value in the MODE register.
    //
    HWREG(ui32Base + SHAMD5_O_MODE) = ui32Mode;
}

//*****************************************************************************
//
//! Perform a non-blocking write of 16 words of data to the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32Src is the pointer to the 16-word array of data that will be
//! written.
//!
//! This function writes 16 words of data into the data register regardless
//! of whether or not the module is ready to accept the data.
//!
//! \return This function returns true if the write completed successfully.
//! It returns false if the module was not ready.
//
//*****************************************************************************
bool
SHAMD5DataWriteNonBlocking(uint32_t ui32Base, uint32_t *pui32Src)
{
    uint32_t ui32Counter;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Check that the SHA/MD5 module is ready for data.  If not, return false.
    //
    if((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_INPUT_READY) == 0)
    {
        return(false);
    }

    //
    // Write the 16 words of data.
    //
    for(ui32Counter = 0; ui32Counter < 64; ui32Counter += 4)
    {
        HWREG(ui32Base + SHAMD5_O_DATA_0_IN + ui32Counter) = *pui32Src++;
    }

    //
    // Return true as a sign of successfully completing the function.
    //
    return(true);
}

//*****************************************************************************
//
//! Perform a blocking write of 16 words of data to the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32Src is the pointer to the 16-word array of data that will be
//! written.
//!
//! This function does not return until the module is ready to accept data and
//! the data has been written.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5DataWrite(uint32_t ui32Base, uint32_t *pui32Src)
{
    uint32_t ui32Counter;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Wait for the module to be ready to accept data.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_INPUT_READY) == 0)
    {
    }

    //
    // Write the 16 words of data.
    //
    for(ui32Counter = 0; ui32Counter < 64; ui32Counter += 4)
    {
        HWREG(ui32Base + SHAMD5_O_DATA_0_IN + ui32Counter) = *pui32Src++;
    }
}

//*****************************************************************************
//
//! Reads the result of a hashing operation.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32Dest is the pointer to the 16-word array of data that will be
//! written.
//!
//! This function does not return until the module is ready to accept data and
//! the data has been written.
//!
//! \return None.
//
//*****************************************************************************
void
SHAMD5ResultRead(uint32_t ui32Base, uint32_t *pui32Dest)
{
    uint32_t ui32Idx, ui32Count;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Determine the number of bytes in the result, based on the hash type.
    //
    switch(HWREG(ui32Base + SHAMD5_O_MODE) & SHAMD5_MODE_ALGO_M)
    {
        //
        // The MD5 hash is being used.
        //
        case SHAMD5_MODE_ALGO_MD5:
        {
            //
            // There are 16 bytes in the MD5 hash.
            //
            ui32Count = 16;

            //
            // Done.
            //
            break;
        }

        //
        // The SHA-1 hash is being used.
        //
        case SHAMD5_MODE_ALGO_SHA1:
        {
            //
            // There are 20 bytes in the SHA-1 hash.
            //
            ui32Count = 20;

            //
            // Done.
            //
            break;
        }

        //
        // The SHA-224 hash is being used.
        //
        case SHAMD5_MODE_ALGO_SHA224:
        {
            //
            // There are 28 bytes in the SHA-224 hash.
            //
            ui32Count = 28;

            //
            // Done.
            //
            break;
        }

        //
        // The SHA-256 hash is being used.
        //
        case SHAMD5_MODE_ALGO_SHA256:
        {
            //
            // There are 32 bytes in the SHA-256 hash.
            //
            ui32Count = 32;

            //
            // Done.
            //
            break;
        }

        //
        // The hash type is not recognized.
        //
        default:
        {
            //
            // Return without reading a result since the hardware appears to be
            // misconfigured.
            //
            return;
        }
    }

    //
    // Read the hash result.
    //
    for(ui32Idx = 0; ui32Idx < ui32Count; ui32Idx += 4)
    {
        *pui32Dest++ = HWREG(ui32Base + SHAMD5_O_IDIGEST_A + ui32Idx);
    }
}

//*****************************************************************************
//
//! Writes multiple words of data into the SHA/MD5 data registers.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32DataSrc is a pointer to an array of data to be written.
//! \param ui32DataLength is the length of the data to be written in bytes.
//!
//! This function writes a variable number of words into the SHA/MD5 data
//! registers.  The function waits for each block of data to be processed
//! before another is written.  The \e ui32DataLength parameter must be a
//! multiple of 4 to fall on a word boundry.
//!
//! \note This function is used by SHAMD5DataProcess() and SHAMD5HMACProcess()
//! to process data.
//!
//! \return None.
//
//*****************************************************************************
static void
_SHAMD5DataWriteMultiple(uint32_t ui32Base, uint32_t *pui32DataSrc,
                         uint32_t ui32DataLength)
{
    uint32_t ui32Idx, ui32Count;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Calculate the number of blocks of data.
    //
    ui32Count = ui32DataLength / 64;

    //
    // Loop through all the blocks and write them into the data registers
    // making sure to block additional operations until we can write the
    // next 16 words.
    //
    for(ui32Idx = 0; ui32Idx < ui32Count; ui32Idx++)
    {
        //
        // Write the block of data.
        //
        SHAMD5DataWrite(ui32Base, pui32DataSrc);

        //
        // Increment the pointer to next block of data.
        //
        pui32DataSrc += 16;
    }

    //
    // Calculate the remaining bytes of data that don't make up a full block.
    //
    ui32Count = ui32DataLength % 64;

    //
    // If there are bytes that do not make up a whole block, then
    // write them separately.
    //
    if(ui32Count)
    {
        //
        // Wait until the engine has finished processing the previous block.
        //
        while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) &
               SHAMD5_INT_INPUT_READY) == 0)
        {
        }

        //
        // Loop through the remaining words.
        //
        for(ui32Idx = 0; ui32Idx < ui32Count; ui32Idx += 4)
        {
            //
            // Write the word into the data register.
            //
            HWREG(ui32Base + SHAMD5_O_DATA_0_IN + ui32Idx) = *pui32DataSrc++;
        }
    }
}

//*****************************************************************************
//
//! Compute a hash using the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32DataSrc is a pointer to an array of data that contains the
//! data that will be hashed.
//! \param ui32DataLength specifies the length of the data to be hashed in
//! bytes.
//! \param pui32HashResult is a pointer to an array that holds the result
//! of the hashing operation.
//!
//! This function computes the hash of an array of data using the SHA/MD5
//! module.
//!
//! The length of the hash result is dependent on the algorithm that is in use.
//! The following table shows the correct array size for each algorithm:
//!
//! -----------------------------------------
//! | Algorithm | Number of Words in Result |
//! -----------------------------------------
//! | MD5       | 4 Words (128 bits)        |
//! | SHA-1     | 5 Words (160 bits)        |
//! | SHA-224   | 7 Words (224 bits)        |
//! | SHA-256   | 8 Words (256 bits)        |
//! -----------------------------------------
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5DataProcess(uint32_t ui32Base, uint32_t *pui32DataSrc,
                  uint32_t ui32DataLength, uint32_t *pui32HashResult)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);
    ASSERT((ui32DataLength % 64) == 0);

    //
    // Wait for the context to be ready before writing the mode.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_CONTEXT_READY) ==
          0)
    {
    }

    //
    // Write the length.
    //
    SHAMD5HashLengthSet(ui32Base, ui32DataLength);

    //
    // Write the data.
    //
    _SHAMD5DataWriteMultiple(ui32Base, pui32DataSrc, ui32DataLength);

    //
    // Wait for the output to be ready.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_OUTPUT_READY) ==
          0)
    {
    }

    //
    // Read the result.
    //
    SHAMD5ResultRead(ui32Base, pui32HashResult);
}

//*****************************************************************************
//
//! Compute a HMAC with key pre-processing using the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32DataSrc is a pointer to an array of data that contains the
//! data that is to be hashed.
//! \param ui32DataLength specifies the length of the data to be hashed in
//! bytes.
//! \param pui32HashResult is a pointer to an array that holds the result
//! of the hashing operation.
//!
//! This function computes a HMAC with the given data using the SHA/MD5
//! module with a preprocessed key.
//!
//! The length of the hash result is dependent on the algorithm that is
//! selected with the \e ui32Algo argument.  The following table shows the
//! correct array size for each algorithm:
//!
//! -----------------------------------------
//! | Algorithm | Number of Words in Result |
//! -----------------------------------------
//! | MD5       | 4 Words (128 bits)        |
//! | SHA-1     | 5 Words (160 bits)        |
//! | SHA-224   | 7 Words (224 bits)        |
//! | SHA-256   | 8 Words (256 bits)        |
//! -----------------------------------------
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5HMACProcess(uint32_t ui32Base, uint32_t *pui32DataSrc,
                  uint32_t ui32DataLength, uint32_t *pui32HashResult)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Wait for the context to be ready before writing the mode.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_CONTEXT_READY) ==
          0)
    {
    }

    //
    // Write the length.
    //
    SHAMD5HashLengthSet(ui32Base, ui32DataLength);

    //
    // Write the data in the registers.
    //
    _SHAMD5DataWriteMultiple(ui32Base, pui32DataSrc, ui32DataLength);

    //
    // Wait for the output to be ready.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_OUTPUT_READY) ==
          0)
    {
    }

    //
    // Read the result.
    //
    SHAMD5ResultRead(ui32Base, pui32HashResult);
}

//*****************************************************************************
//
//! Process an HMAC key using the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32Key is a pointer to an array that contains the key to be
//! processed.
//! \param pui32PPKey is the pointer to the array that contains the
//! pre-processed key.
//!
//! This function processes an HMAC key using the SHA/MD5.  The resultant
//! pre-processed key can then be used with later HMAC operations to speed
//! processing time.
//!
//! The \e pui32Key array must be 16 words (512 bits) long.  If the key is less
//! than 512 bits, it must be padded with zeros.  The \e pui32PPKey array must
//! each be 16 words (512 bits) long.
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5HMACPPKeyGenerate(uint32_t ui32Base, uint32_t *pui32Key,
                        uint32_t *pui32PPKey)
{
    uint32_t ui32Index;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Wait for the context to be ready before writing the mode.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_CONTEXT_READY) ==
          0)
    {
    }

    //
    // Write the HMAC key.
    //
    for(ui32Index = 0; ui32Index < 64; ui32Index += 4)
    {
        HWREG(ui32Base + SHAMD5_O_ODIGEST_A + ui32Index) = *pui32Key++;
    }

    //
    // Set the flag to cause the HMAC key to be pre-processed.
    //
    HWREG(ui32Base + SHAMD5_O_MODE) |= SHAMD5_MODE_HMAC_KEY_PROC;

    //
    // Set the length to zero to start the HMAC key pre-processing.
    //
    HWREG(ui32Base + SHAMD5_O_LENGTH) = 0;

    //
    // Wait for key to be processed.
    //
    while((HWREG(ui32Base + SHAMD5_O_IRQSTATUS) & SHAMD5_INT_OUTPUT_READY) ==
          0)
    {
    }

    //
    // Read the pre-processed key from the SHA/MD5 module.
    //
    for(ui32Index = 0; ui32Index < 64; ui32Index += 4)
    {
        *pui32PPKey++ = HWREG(ui32Base + SHAMD5_O_ODIGEST_A + ui32Index);
    }
}

//*****************************************************************************
//
//! Writes an HMAC key to the digest registers in the SHA/MD5 module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32Src is the pointer to the 16-word array of the HMAC key.
//!
//! This function is used to write HMAC key to the digest registers for
//! key preprocessing.  The size of pui32Src must be 512 bytes.  If the key is
//! less than 512 bytes, then it must be padded with zeros.
//!
//! \note It is recommended to use the SHAMD5IntStatus() function to check
//! whether the context is ready before writing the key.
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5HMACKeySet(uint32_t ui32Base, uint32_t *pui32Src)
{
    uint32_t ui32Idx;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Write the key to the digest registers.
    //
    for(ui32Idx = 0; ui32Idx < 64; ui32Idx += 4)
    {
        HWREG(ui32Base + SHAMD5_O_ODIGEST_A + ui32Idx) = *pui32Src++;
    }

    //
    // Configure the SHA engine for HMAC operation.
    //
    HWREG(ui32Base + SHAMD5_O_MODE) |= (SHAMD5_MODE_HMAC_OUTER_HASH |
                                        SHAMD5_MODE_HMAC_KEY_PROC |
                                        SHAMD5_MODE_CLOSE_HASH);
}

//*****************************************************************************
//
//! Writes a pre-processed HMAC key to the digest registers in the SHA/MD5
//! module.
//!
//! \param ui32Base is the base address of the SHA/MD5 module.
//! \param pui32Src is the pointer to the 16-word array of the HMAC key.
//!
//! This function is used to write HMAC key to the digest registers for
//! key preprocessing.  The size of pui32Src must be 512 bytes.  If the key is
//! less than 512 bytes, then it must be padded with zeros.
//!
//! \note It is recommended to use the SHAMD5IntStatus() function to check
//! whether the context is ready before writing the key.
//!
//! \return None
//
//*****************************************************************************
void
SHAMD5HMACPPKeySet(uint32_t ui32Base, uint32_t *pui32Src)
{
    uint32_t ui32Idx;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == SHAMD5_BASE);

    //
    // Write the key to the digest registers.
    //
    for(ui32Idx = 0; ui32Idx < 64; ui32Idx += 4)
    {
        HWREG(ui32Base + SHAMD5_O_ODIGEST_A + ui32Idx) = *pui32Src++;
    }

    //
    // Configure the SHA engine to continue the HMAC.
    //
    HWREG(ui32Base + SHAMD5_O_MODE) |= (SHAMD5_MODE_HMAC_OUTER_HASH |
                                        SHAMD5_MODE_CLOSE_HASH);

    //
    // Write the digest count to 64 to account for the preprocessed key.
    //
    HWREG(ui32Base + SHAMD5_O_DIGEST_COUNT) = 64;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
