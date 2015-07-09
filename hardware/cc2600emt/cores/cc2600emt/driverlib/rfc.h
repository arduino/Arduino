/******************************************************************************
*  Filename:       rfc.h
*  Revised:        2015-01-14 12:12:44 +0100 (on, 14 jan 2015)
*  Revision:       42373
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
