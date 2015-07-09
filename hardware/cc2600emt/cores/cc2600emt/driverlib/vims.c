/******************************************************************************
*  Filename:       vims.c
*  Revised:        2015-03-04 13:37:39 +0100 (on, 04 mar 2015)
*  Revision:       42883
*
*  Description:    Driver for the VIMS.
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

#include <driverlib/vims.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#ifndef DRIVERLIB_GENERATE_ROM
    #undef  VIMSConfigure
    #define VIMSConfigure                   NOROM_VIMSConfigure
    #undef  VIMSModeSet
    #define VIMSModeSet                     NOROM_VIMSModeSet
    #undef  VIMSModeGet
    #define VIMSModeGet                     NOROM_VIMSModeGet
    #undef  VIMSModeSetBlocking
    #define VIMSModeSetBlocking             NOROM_VIMSModeSetBlocking
#endif

//*****************************************************************************
//
//! Configures the VIMS.
//
//*****************************************************************************
void
VIMSConfigure(uint32_t ui32Base, bool bRoundRobin, bool bPrefetch)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(VIMSBaseValid(ui32Base));

    ui32Reg = HWREG(ui32Base + VIMS_O_CTL);
    ui32Reg &= ~(VIMS_CTL_PREF_EN | VIMS_CTL_ARB_CFG);
    if(bRoundRobin)
    {
        ui32Reg |= VIMS_CTL_ARB_CFG;
    }
    if(bPrefetch)
    {
        ui32Reg |= VIMS_CTL_PREF_EN;
    }

    //
    // Set the Arbitration and prefetch mode.
    //
    HWREG(ui32Base + VIMS_O_CTL) = ui32Reg;
}

//*****************************************************************************
//
//! Set the operational mode of the VIMS
//
//*****************************************************************************
void
VIMSModeSet(uint32_t ui32Base, uint32_t ui32Mode)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(VIMSBaseValid(ui32Base));

    ASSERT((ui32Mode == VIMS_MODE_DISABLED)   ||
           (ui32Mode == VIMS_MODE_ENABLED)    ||
           (ui32Mode == VIMS_MODE_OFF)        ||
           (ui32Mode == VIMS_MODE_SPLIT));

    //
    // Set the mode.
    //
    ui32Reg = HWREG(ui32Base + VIMS_O_CTL);
    ui32Reg &= ~VIMS_CTL_MODE_M;
    ui32Reg |= (ui32Mode & VIMS_CTL_MODE_M);

    HWREG(ui32Base + VIMS_O_CTL) = ui32Reg;
}

//*****************************************************************************
//
//! Get the current operational mode of the VIMS.
//
//*****************************************************************************
uint32_t
VIMSModeGet(uint32_t ui32Base)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(VIMSBaseValid(ui32Base));

    ui32Reg = HWREG(ui32Base + VIMS_O_STAT);
    if(ui32Reg & VIMS_STAT_MODE_CHANGING)
    {
        return (VIMS_MODE_CHANGING);
    }
    else
    {
        return (ui32Reg & VIMS_STAT_MODE_M);
    }
}

//*****************************************************************************
//
// Safe setting of new VIMS mode
// - Function is blocking
// - Can be called for any mode change (also if actually not changing mode)
// Note: The shift operators (VIMS_CTL_MODE_S and VIMS_STAT_MODE_S) is not
//       used bacause we know that they both are = 0.
//
//*****************************************************************************
void
VIMSModeSetBlocking( uint32_t ui32Mode )
{
   //
   // Make sure that only the mode bits are set (just for sequirity)
   //
   ui32Mode &= VIMS_CTL_MODE_M;

   //
   // Wait for any pending change to complete
   //
   while ( HWREGBITW( VIMS_BASE + VIMS_O_STAT, VIMS_STAT_MODE_CHANGING_BITN )) {
      // Do nothing - wait for change to complete.
   }

   //
   // Request mode change
   //
   HWREG( VIMS_BASE + VIMS_O_CTL ) =
      ( HWREG( VIMS_BASE + VIMS_O_CTL ) & ~VIMS_CTL_MODE_M ) | ui32Mode;

   //
   // Wait for mode change to complete
   //
   while (( HWREG( VIMS_BASE + VIMS_O_STAT ) & VIMS_STAT_MODE_M ) != ui32Mode ) {
      // Do nothing - wait for new mode to be entered
   }
}
