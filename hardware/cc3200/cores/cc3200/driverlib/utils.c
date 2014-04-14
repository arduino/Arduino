//*****************************************************************************
//
// utils.c - Utility APIs
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup Utils_api
//! @{
//
//*****************************************************************************

#include "utils.h"


//*****************************************************************************
//
//! Provides a small delay.
//!
//! \param ulCount is the number of delay loop iterations to perform.
//!
//! This function provides a means of generating a constant length delay.  It
//! is written in assembly to keep the delay consistent across tool chains,
//! avoiding the need to tune the delay based on the tool chain in use.
//!
//! The loop takes 3 cycles/loop.
//!
//! \return None.
//
//*****************************************************************************
#if defined(ewarm) || defined(DOXYGEN)
void
UtilsDelay(unsigned long ulCount)
{
    __asm("    subs    r0, #1\n"
          "    bne.n   UtilsDelay\n"
          "    bx      lr");
}
#endif
//
// For CCS implement this function in pure assembly.  This prevents the TI
// compiler from doing funny things with the optimizer.
//
#if defined(ccs)
    __asm("    .sect \".text:UtilsDelay\"\n"
          "    .clink\n"
          "    .thumbfunc UtilsDelay\n"
          "    .thumb\n"
          "    .global UtilsDelay\n"
          "UtilsDelay:\n"
          "    subs r0, #1\n"
          "    bne.n UtilsDelay\n"
          "    bx lr\n");
#endif

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
