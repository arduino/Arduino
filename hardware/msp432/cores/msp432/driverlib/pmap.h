/*
 * -------------------------------------------
 *    MSP432 DriverLib - v01_04_00_18 
 * -------------------------------------------
 *
 * --COPYRIGHT--,BSD,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
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
#ifndef __PMAP_H__
#define __PMAP_H__

//*****************************************************************************
//
//! \addtogroup pmap_api
//! @{
//
//*****************************************************************************

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

#include <stdint.h>
#include <msp.h>

//*****************************************************************************
//
//The following are values that can be passed to the PMAP_configurePorts() API
//as the portMapReconfigure parameter.
//
//*****************************************************************************
#define PMAP_ENABLE_RECONFIGURATION     PMAPRECFG
#define PMAP_DISABLE_RECONFIGURATION    0x00

//*****************************************************************************
//
//The following are values that can be passed to the PMAP_configurePorts() API
//as the portMapReconfigure parameter.
//
//*****************************************************************************
#define P1MAP OFS_P1MAP01
#define P2MAP OFS_P2MAP01
#define P3MAP OFS_P3MAP01
#define P4MAP OFS_P4MAP01
#define P5MAP OFS_P5MAP01
#define P6MAP OFS_P6MAP01
#define P7MAP OFS_P7MAP01


//*****************************************************************************
//
//Prototypes for the APIs.
//
//*****************************************************************************

//*****************************************************************************
//
//! This function configures the MSP432 Port Mapper
//!
//! \param portMapping is the pointer to init Data
//! \param pxMAPy is the Port Mapper to initialize
//! \param numberOfPorts is the number of Ports to initialize
//! \param portMapReconfigure is used to enable/disable reconfiguration
//!             Valid values are
//!             \b PMAP_ENABLE_RECONFIGURATION
//!             \b PMAP_DISABLE_RECONFIGURATION [Default value]
//! Modified registers are \b PMAPKEYID, \b PMAPCTL
//!
//! \return None
//
//*****************************************************************************
extern void PMAP_configurePorts(const uint8_t *portMapping, uint8_t pxMAPy,
        uint8_t numberOfPorts, uint8_t portMapReconfigure);

/* Defines for future devices that might have multiple instances */
#define PMAP_configurePortsMultipleInstance(a,b,c,d,e) PMAP_configurePorts(b,c,d,e)

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif
