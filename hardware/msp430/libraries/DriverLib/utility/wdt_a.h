//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430F5529__) || defined(__MSP430FR5739__)

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
// wdt_a.h - Driver for the WDT_A Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_WDT_A_H__
#define __MSP430WARE_WDT_A_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_WDT_A__

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

//*****************************************************************************
//
// The following are values that can be passed to the clockSelect parameter for
// functions: WDT_A_watchdogTimerInit(), and WDT_A_intervalTimerInit().
//
//*****************************************************************************
#define WDT_A_CLOCKSOURCE_SMCLK                                     (WDTSSEL_0)
#define WDT_A_CLOCKSOURCE_ACLK                                      (WDTSSEL_1)
#define WDT_A_CLOCKSOURCE_VLOCLK                                    (WDTSSEL_2)
#define WDT_A_CLOCKSOURCE_XCLK                                      (WDTSSEL_3)

//*****************************************************************************
//
// The following are values that can be passed to the clockDivider parameter
// for functions: WDT_A_watchdogTimerInit(), and WDT_A_intervalTimerInit().
//
//*****************************************************************************
#define WDT_A_CLOCKDIVIDER_2G                                         (WDTIS_0)
#define WDT_A_CLOCKDIVIDER_128M                                       (WDTIS_1)
#define WDT_A_CLOCKDIVIDER_8192K                                      (WDTIS_2)
#define WDT_A_CLOCKDIVIDER_512K                                       (WDTIS_3)
#define WDT_A_CLOCKDIVIDER_32K                                        (WDTIS_4)
#define WDT_A_CLOCKDIVIDER_8192                                       (WDTIS_5)
#define WDT_A_CLOCKDIVIDER_512                                        (WDTIS_6)
#define WDT_A_CLOCKDIVIDER_64                                         (WDTIS_7)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void WDT_A_hold(uint32_t baseAddress);

extern void WDT_A_start(uint32_t baseAddress);

extern void WDT_A_resetTimer(uint32_t baseAddress);

extern void WDT_A_watchdogTimerInit(uint32_t baseAddress,
                                    uint8_t clockSelect,
                                    uint8_t clockDivider);

extern void WDT_A_intervalTimerInit(uint32_t baseAddress,
                                    uint8_t clockSelect,
                                    uint8_t clockDivider);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_WDT_A_H__

#endif
