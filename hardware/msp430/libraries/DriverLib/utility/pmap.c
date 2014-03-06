//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430F5529__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// pmap.c - Driver for the pmap Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup pmap_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_PORT_MAPPING__
#include "pmap.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief This function configures the MSP430 Port Mapper
//!
//! This function port maps a set of pins to a new set.
//!
//! \param baseAddress is the base address of the PMAP control module.
//! \param portMapping is the pointer to init Data
//! \param PxMAPy is the pointer start of first PMAP to initialize
//! \param numberOfPorts is the number of Ports to initialize
//! \param portMapReconfigure is used to enable/disable reconfiguration
//!        Valid values are:
//!        - \b PMAP_ENABLE_RECONFIGURATION
//!        - \b PMAP_DISABLE_RECONFIGURATION [Default]
//!
//! Modified bits of \b PMAPKETID register and bits of \b PMAPCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMAP_configurePorts( uint32_t baseAddress,
                          const uint8_t *portMapping,
                          uint8_t *PxMAPy,
                          uint8_t numberOfPorts,
                          uint8_t portMapReconfigure
                          )
{
        assert((portMapReconfigure == PMAP_ENABLE_RECONFIGURATION) ||
               (portMapReconfigure == PMAP_DISABLE_RECONFIGURATION)
               );

        //Store current interrupt state, then disable all interrupts
        uint16_t globalInterruptState = __get_SR_register() & GIE;
        __disable_interrupt();

        //Get write-access to port mapping registers:
        HWREG16(baseAddress + OFS_PMAPKEYID) = PMAPPW;

        //Enable/Disable reconfiguration during runtime
        HWREG8(baseAddress + OFS_PMAPCTL) &= ~PMAPRECFG;
        HWREG8(baseAddress + OFS_PMAPCTL) |= portMapReconfigure;

        //Configure Port Mapping:
        uint16_t i;
        for (i = 0; i < numberOfPorts * 8; i++)
                PxMAPy[i] = portMapping[i];

        //Disable write-access to port mapping registers:
        HWREG8(baseAddress + OFS_PMAPKEYID) = 0;

        //Restore previous interrupt state
        __bis_SR_register(globalInterruptState);
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for pmap_api
//! @}
//
//*****************************************************************************

#endif
