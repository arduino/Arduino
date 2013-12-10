//*****************************************************************************
//
// crc.c - Driver for the CRC module.
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

//*****************************************************************************
//
//! \addtogroup crc_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ccm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/crc.h"
#include "driverlib/debug.h"


//*****************************************************************************
//
//! Set the configuration of CRC functionality with the EC module.
//!
//! \param ui32Base is the base address of the EC module.
//! \param ui32CRCConfig is the configuration of the CRC engine.
//!
//! This function configures the operation of the CRC engine within the EC
//! module.  The configuration is specified with the \e ui32CRCConfig argument.
//! It is the logical OR of any of the following options:
//!
//! CRC Initialization Value
//! - \b CRC_CFG_INIT_SEED - Initialize with seed value
//! - \b CRC_CFG_INIT_0 - Initialize to all '0s'
//! - \b CRC_CFG_INIT_1 - Initialize to all '1s'
//!
//! Input Data Size
//! - \b CRC_CFG_SIZE_8BIT - Input data size of 8 bits
//! - \b CRC_CFG_SIZE_32BIT - Input data size of 32 bits
//!
//! Post Process Reverse/Inverse
//! - \b CRC_CFG_RESINV - Result inverse enable
//! - \b CRC_CFG_OBR - Output reverse enable
//!
//! Input Bit Reverse
//! - \b CRC_CFG_IBR - Bit reverse enable
//!
//! Endian Control
//! - \b CRC_CFG_ENDIAN_SBHW - Swap byte in half-word
//! - \b CRC_CFG_ENDIAN_SHW - Swap half-word
//!
//! Operation Type
//! - \b CRC_CFG_TYPE_P8005 - Polynomial 0x8005
//! - \b CRC_CFG_TYPE_P1021 - Polynomial 0x1021
//! - \b CRC_CFG_TYPE_P4C11DB7 - Polynomial 0x4C11DB7
//! - \b CRC_CFG_TYPE_P1EDC6F41 - Polynomial 0x1EDC6F41
//! - \b CRC_CFG_TYPE_TCPCHKSUM - TCP checksum
//!
//! \return None.
//
//*****************************************************************************
void
CRCConfigSet(uint32_t ui32Base, uint32_t ui32CRCConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == CCM0_BASE);
    ASSERT((ui32CRCConfig & CRC_CFG_INIT_SEED) ||
           (ui32CRCConfig & CRC_CFG_INIT_0) ||
           (ui32CRCConfig & CRC_CFG_INIT_1) ||
           (ui32CRCConfig & CRC_CFG_SIZE_8BIT) ||
           (ui32CRCConfig & CRC_CFG_SIZE_32BIT) ||
           (ui32CRCConfig & CRC_CFG_RESINV) ||
           (ui32CRCConfig & CRC_CFG_OBR) ||
           (ui32CRCConfig & CRC_CFG_IBR) ||
           (ui32CRCConfig & CRC_CFG_ENDIAN_SBHW) ||
           (ui32CRCConfig & CRC_CFG_ENDIAN_SHW) ||
           (ui32CRCConfig & CRC_CFG_TYPE_P8005) ||
           (ui32CRCConfig & CRC_CFG_TYPE_P1021) ||
           (ui32CRCConfig & CRC_CFG_TYPE_P4C11DB7) ||
           (ui32CRCConfig & CRC_CFG_TYPE_P1EDC6F41) ||
           (ui32CRCConfig & CRC_CFG_TYPE_TCPCHKSUM));

    //
    // Write the control register with the configuration.
    //
    HWREG(ui32Base + CCM_O_CRCCTRL) = ui32CRCConfig;
}

//*****************************************************************************
//
//! Write the seed value for CRC operations in the EC module.
//!
//! \param ui32Base is the base address of the EC module.
//! \param ui32Seed is the seed value.
//!
//! This function writes the seed value for use with CRC operations in the
//! EC module.  This value is the start value for CRC operations.  If this
//! value is not written, then the residual seed from the previous operation
//! is used as the starting value.
//!
//! \note The seed must be written only if \b CRC_CFG_INIT_SEED is
//! set with the CRCConfigSet() function.
//
//*****************************************************************************
void
CRCSeedSet(uint32_t ui32Base, uint32_t ui32Seed)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == CCM0_BASE);

    //
    // Write the seed value to the seed register.
    //
    HWREG(ui32Base + CCM_O_CRCSEED) = ui32Seed;
}

//*****************************************************************************
//
//! Write data into the EC module for CRC operations.
//!
//! \param ui32Base is the base address of the EC module.
//! \param ui32Data is the data to be written.
//!
//! This function writes either 8 or 32 bits of data into the EC module for
//! CRC operations.  The distinction between 8 and 32 bits of data is made
//! when the \b CRC_CFG_SIZE_8BIT or \b CRC_CFG_SIZE_32BIT flag
//! is set using the CRCConfigSet() function.
//!
//! When writing 8 bits of data, ensure the data is in the least significant
//! byte position.  The remaining bytes should be written with zero.  For
//! example, when writing 0xAB, \e ui32Data should be 0x000000AB.
//!
//! \return None
//
//*****************************************************************************
void
CRCDataWrite(uint32_t ui32Base, uint32_t ui32Data)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == CCM0_BASE);

    //
    // Write the data
    //
    HWREG(ui32Base + CCM_O_CRCDIN) = ui32Data;
}

//*****************************************************************************
//
//! Reads the result of a CRC operation in the EC module.
//!
//! \param ui32Base is the base address of the EC module.
//! \param bPPResult is \b true to read the post-processed result, or \b false
//! to read the unmodified result.
//!
//! This function reads either the unmodified CRC result or the post
//! processed CRC result from the EC module.  The post-processing options
//! are selectable through \b CRC_CFG_RESINV and \b CRC_CFG_OBR
//! parameters in the CRCConfigSet() function.
//!
//! \return The CRC result.
//
//*****************************************************************************
uint32_t
CRCResultRead(uint32_t ui32Base, bool bPPResult)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == CCM0_BASE);

    //
    // Depending on the value of bPPResult, read the appropriate register and
    // return value.
    //
    if(bPPResult)
    {
        return(HWREG(ui32Base + CCM_O_CRCRSLTPP));
    }
    else
    {
        return(HWREG(ui32Base + CCM_O_CRCSEED));
    }
}

//*****************************************************************************
//
//! Process data to generate a CRC with the EC module.
//!
//! \param ui32Base is the base address of the EC module.
//! \param pui32DataIn is a pointer to an array of data that is processed.
//! \param ui32DataLength is the number of data items that are processed
//! to produce the CRC.
//! \param bPPResult is \b true to read the post-processed result, or \b false
//! to read the unmodified result.
//!
//! This function processes an array of data to produce a CRC result.
//!
//! The data in the array pointed to be \e pui32DataIn is either an array
//! of bytes or an array or words depending on the selection of the input
//! data size options \b CRC_CFG_SIZE_8BIT and
//! \b CRC_CFG_SIZE_32BIT.
//!
//! This function returns either the unmodified CRC result or the
//! post- processed CRC result from the EC module.  The post-processing
//! options are selectable through \b CRC_CFG_RESINV and
//! \b CRC_CFG_OBR parameters.
//!
//! \return The CRC result.
//
//*****************************************************************************
uint32_t
CRCDataProcess(uint32_t ui32Base, uint32_t *pui32DataIn,
               uint32_t ui32DataLength, bool bPPResult)
{
    uint8_t *pui8DataIn;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == CCM0_BASE);

    //
    // See if the CRC is operating in 8-bit or 32-bit mode.
    //
    if(HWREG(ui32Base + CCM_O_CRCCTRL) & CCM_CRCCTRL_SIZE)
    {
        //
        // The CRC is operating in 8-bit mode, so create an 8-bit pointer to
        // the data.
        //
        pui8DataIn = (uint8_t *)pui32DataIn;

        //
        // Loop through the input data.
        //
        while(ui32DataLength--)
        {
            //
            // Write the next data byte.
            //
            HWREG(ui32Base + CCM_O_CRCDIN) = *pui8DataIn++;
        }
    }
    else
    {
        //
        // The CRC is operating in 32-bit mode, so loop through the input data.
        //
        while(ui32DataLength--)
        {
            //
            // Write the next data word.
            //
            HWREG(ui32Base + CCM_O_CRCDIN) = *pui32DataIn++;
        }
    }

    //
    // Return the result.
    //
    return(CRCResultRead(ui32Base, bPPResult));
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
