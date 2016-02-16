/******************************************************************************
*  Filename:       rfc.h
*  Revised:        2016-01-28 11:10:16 +0100 (Thu, 28 Jan 2016)
*  Revision:       45566
*
*  Description:    Defines and prototypes for the RF Core.
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
//! \addtogroup rfc_api
//! @{
//
//*****************************************************************************

#ifndef __RFC_H__
#define __RFC_H__

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
#include <inc/hw_memmap.h>
#include <inc/hw_rfc_pwr.h>
#include <inc/hw_rfc_dbell.h>

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
    #define RFCCpeIntGetAndClear            NOROM_RFCCpeIntGetAndClear
    #define RFCDoorbellSendTo               NOROM_RFCDoorbellSendTo
    #define RFCSynthPowerDown               NOROM_RFCSynthPowerDown
#endif

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Enable the RF core clocks.
//!
//! As soon as the RF core is started it will handle clock control
//! autonomously. No check should be performed to check the clocks. Instead
//! the radio can be ping'ed through the command interface.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
RFCClockEnable(void)
{
    //
    // Enable all clocks
    //
    HWREG(RFC_PWR_NONBUF_BASE + RFC_PWR_O_PWMCLKEN) =
                                 RFC_PWR_PWMCLKEN_RFCTRC |
                                 RFC_PWR_PWMCLKEN_FSCA |
                                 RFC_PWR_PWMCLKEN_PHA |
                                 RFC_PWR_PWMCLKEN_RAT |
                                 RFC_PWR_PWMCLKEN_RFERAM |
                                 RFC_PWR_PWMCLKEN_RFE |
                                 RFC_PWR_PWMCLKEN_MDMRAM |
                                 RFC_PWR_PWMCLKEN_MDM |
                                 RFC_PWR_PWMCLKEN_CPERAM |
                                 RFC_PWR_PWMCLKEN_CPE |
                                 RFC_PWR_PWMCLKEN_RFC;
}

//*****************************************************************************
//
//! \brief Disable the RF core clocks.
//!
//! As soon as the RF core is started it will handle clock control
//! autonomously. No check should be performed to check the clocks. Instead
//! the radio can be ping'ed through the command interface.
//!
//! When disabling clocks it is the programmers responsibility that the
//! RF core clocks can be safely gated. I.e. the RF core should be safely
//! 'parked'.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
RFCClockDisable(void)
{
    //
    // Disable all clocks
    //
    HWREG(RFC_PWR_NONBUF_BASE + RFC_PWR_O_PWMCLKEN) = 0x0;
}

//*****************************************************************************
//
//! Enable CPE0 interrupt
//
//*****************************************************************************
__STATIC_INLINE void
RFCCpe0IntEnable(uint32_t ui32Mask)
{
  //
  // Multiplex RF Core interrupts to CPE0 IRQ.
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEISL) &= ~ui32Mask;

  do
  {
    //
    // Clear any pending interrupts.
    //
    HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIFG) = 0x0;
  }while(HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIFG) != 0x0);

  //
  //  Enable the masked interrupts
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIEN) |= ui32Mask;
}


//*****************************************************************************
//
//! Enable CPE1 interrupt
//
//*****************************************************************************
__STATIC_INLINE void
RFCCpe1IntEnable(uint32_t ui32Mask)
{
  //
  // Multiplex RF Core interrupts to CPE1 IRQ.
  //
  HWREG( RFC_DBELL_BASE + RFC_DBELL_O_RFCPEISL) |= ui32Mask;

  do
  {
    //
    // Clear any pending interrupts.
    //
    HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIFG) = 0x0;
  }while(HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIFG) != 0x0);

  //
  //  Enable the masked interrupts
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIEN) |= ui32Mask;
}


//*****************************************************************************
//
//! This function is used to map only HW interrupts, and
//! clears/unmasks them. These interrupts are then enabled.
//
//*****************************************************************************
__STATIC_INLINE void
RFCHwIntEnable(uint32_t ui32Mask)
{
  //
  // Clear any pending interrupts.
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFHWIFG) = 0x0;

  //
  //  Enable the masked interrupts
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFHWIEN) |= ui32Mask;
}


//*****************************************************************************
//
//! Disable CPE interrupt
//
//*****************************************************************************
__STATIC_INLINE void
RFCCpeIntDisable(uint32_t ui32Mask)
{
  //
  //  Disable the masked interrupts
  //
  HWREG( RFC_DBELL_BASE + RFC_DBELL_O_RFCPEIEN ) &= ~ui32Mask;
}


//*****************************************************************************
//
//! Disable HW interrupt
//
//*****************************************************************************
__STATIC_INLINE void
RFCHwIntDisable(uint32_t ui32Mask)
{
  //
  //  Disable the masked interrupts
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFHWIEN) &= ~ui32Mask;
}


//*****************************************************************************
//
//! Get and clear CPE interrupt flags
//
//*****************************************************************************
extern uint32_t RFCCpeIntGetAndClear(void);


//*****************************************************************************
//
//! Clear interrupt flags
//
//*****************************************************************************
__STATIC_INLINE void
RFCCpeIntClear(uint32_t ui32Mask)
{
  do
  {
    //
    // Clear interrupts that may now be pending
    //
    HWREG(RFC_DBELL_BASE+RFC_DBELL_O_RFCPEIFG) = ~ui32Mask;
  }while (HWREG(RFC_DBELL_BASE+RFC_DBELL_O_RFCPEIFG) & ui32Mask);
}


//*****************************************************************************
//
//! Clear interrupt flags
//
//*****************************************************************************
__STATIC_INLINE void
RFCHwIntClear(uint32_t ui32Mask)
{
  //
  // Clear pending interrupts.
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFHWIFG) = ~ui32Mask;
}


//*****************************************************************************
//
//! Clear interrupt flags
//
//*****************************************************************************
__STATIC_INLINE void
RFCAckIntClear(void)
{
  //
  // Clear any pending interrupts.
  //
  HWREG(RFC_DBELL_BASE + RFC_DBELL_O_RFACKIFG) = 0x0;
}


//*****************************************************************************
//
//! Send command to doorbell and wait for ack
//
//*****************************************************************************
extern uint32_t RFCDoorbellSendTo(uint32_t pOp);


//*****************************************************************************
//
//! Turn off synth, NOTE: Radio will no longer respond to commands!
//
//*****************************************************************************
extern void RFCSynthPowerDown(void);


//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#if !defined(DRIVERLIB_NOROM) && !defined(DOXYGEN)
    #include <driverlib/rom.h>
    #ifdef ROM_RFCCpeIntGetAndClear
        #undef  RFCCpeIntGetAndClear
        #define RFCCpeIntGetAndClear            ROM_RFCCpeIntGetAndClear
    #endif
    #ifdef ROM_RFCDoorbellSendTo
        #undef  RFCDoorbellSendTo
        #define RFCDoorbellSendTo               ROM_RFCDoorbellSendTo
    #endif
    #ifdef ROM_RFCSynthPowerDown
        #undef  RFCSynthPowerDown
        #define RFCSynthPowerDown               ROM_RFCSynthPowerDown
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

#endif //  __RFC_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//*****************************************************************************
