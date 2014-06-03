//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__)

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
// pmm.h - Driver for the PMM Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_PMM_H__
#define __MSP430WARE_PMM_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_PMM_FRAM__

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
// The following are values that can be passed to the mask parameter for
// functions: PMM_clearInterrupt(), and PMM_getInterruptStatus().
//
//*****************************************************************************
#define PMM_PMMBORIFG                                                 PMMBORIFG
#define PMM_PMMRSTIFG                                                 PMMRSTIFG
#define PMM_PMMPORIFG                                                 PMMPORIFG
#define PMM_SVSHIFG                                                     SVSHIFG
#define PMM_SVSLIFG                                                     SVSLIFG
#define PMM_PMMLPM5IFG                                               PMMLPM5IFG
#define PMM_ALL                                                          (0xB7)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void PMM_enableLowPowerReset(void);

extern void PMM_disableLowPowerReset(void);

extern void PMM_enableSVSH(void);

extern void PMM_disableSVSH(void);

extern void PMM_regOn(void);

extern void PMM_regOff(void);

extern void PMM_trigPOR(void);

extern void PMM_trigBOR(void);

extern void PMM_clearInterrupt(uint16_t mask);

extern uint16_t PMM_getInterruptStatus(uint16_t mask);

extern void PMM_lockLPM5(void);

extern void PMM_unlockLPM5(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_PMM_H__

#endif
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
// pmm.h - Driver for the PMM Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_PMM_H__
#define __MSP430WARE_PMM_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_PMM__

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
// The following are values that can be passed to the level parameter for
// functions: PMM_setVCoreUp(), PMM_setVCoreDown(), and PMM_setVCore().
//
//*****************************************************************************
#define PMM_CORE_LEVEL_0                                             PMMCOREV_0
#define PMM_CORE_LEVEL_1                                             PMMCOREV_1
#define PMM_CORE_LEVEL_2                                             PMMCOREV_2
#define PMM_CORE_LEVEL_3                                             PMMCOREV_3

//*****************************************************************************
//
// The following are values that can be passed to the mask parameter for
// functions: PMM_getInterruptStatus() as well as returned by the
// PMM_getInterruptStatus() function.
//
//*****************************************************************************
#define PMM_SVSMLDLYIFG                                             SVSMLDLYIFG
#define PMM_SVMLIFG                                                     SVMLIFG
#define PMM_SVMLVLRIFG                                               SVMLVLRIFG
#define PMM_SVSMHDLYIFG                                             SVSMHDLYIFG
#define PMM_SVMHIFG                                                     SVMHIFG
#define PMM_SVMHVLRIFG                                               SVMHVLRIFG
#define PMM_PMMBORIFG                                                 PMMBORIFG
#define PMM_PMMRSTIFG                                                 PMMRSTIFG
#define PMM_PMMPORIFG                                                 PMMPORIFG
#define PMM_SVSHIFG                                                     SVSHIFG
#define PMM_SVSLIFG                                                     SVSLIFG
#define PMM_PMMLPM5IFG                                               PMMLPM5IFG

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void PMM_enableSvsL(void);

extern void PMM_disableSvsL(void);

extern void PMM_enableSvmL(void);

extern void PMM_disableSvmL(void);

extern void PMM_enableSvsH(void);

extern void PMM_disableSvsH(void);

extern void PMM_enableSvmH(void);

extern void PMM_disableSvmH(void);

extern void PMM_enableSvsLSvmL(void);

extern void PMM_disableSvsLSvmL(void);

extern void PMM_enableSvsHSvmH(void);

extern void PMM_disableSvsHSvmH(void);

extern void PMM_enableSvsLReset(void);

extern void PMM_disableSvsLReset(void);

extern void PMM_enableSvmLInterrupt(void);

extern void PMM_disableSvmLInterrupt(void);

extern void PMM_enableSvsHReset(void);

extern void PMM_disableSvsHReset(void);

extern void PMM_enableSvmHInterrupt(void);

extern void PMM_disableSvmHInterrupt(void);

extern void PMM_clearPMMIFGS(void);

extern void PMM_SvsLEnabledInLPMFastWake(void);

extern void PMM_SvsLEnabledInLPMSlowWake(void);

extern void PMM_SvsLDisabledInLPMFastWake(void);

extern void PMM_SvsLDisabledInLPMSlowWake(void);

extern void PMM_SvsHEnabledInLPMNormPerf(void);

extern void PMM_SvsHEnabledInLPMFullPerf(void);

extern void PMM_SvsHDisabledInLPMNormPerf(void);

extern void PMM_SvsHDisabledInLPMFullPerf(void);

extern void PMM_SvsLOptimizedInLPMFastWake(void);

extern void PMM_SvsHOptimizedInLPMFullPerf(void);

extern uint16_t PMM_setVCoreUp(uint8_t level);

extern uint16_t PMM_setVCoreDown(uint8_t level);

extern bool PMM_setVCore(uint8_t level);

extern uint16_t PMM_getInterruptStatus(uint16_t mask);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_PMM_H__

#endif
//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5739__)

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
// pmm.h - Driver for the PMM Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_PMM_H__
#define __MSP430WARE_PMM_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_PMM_FR5xx__

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
// The following are values that can be passed to the mask parameter for
// functions: PMM_clearInterrupt(), and PMM_getInterruptStatus() as well as
// returned by the PMM_getInterruptStatus() function.
//
//*****************************************************************************
#define PMM_PMMBORIFG           PMMBORIFG               /* PMM Software BOR interrupt flag */
#define PMM_PMMRSTIFG              PMMRSTIFG            /* PMM RESET pin interrupt flag */
#define PMM_PMMPORIFG           PMMPORIFG               /* PMM Software POR interrupt flag */
#define PMM_SVSLIFG                                                           \
        SVSLIFG                                         /* SVS low side interrupt flag, NOT available for FR58xx/59xx */
#define PMM_SVSHIFG                 SVSHIFG             /* SVS high side interrupt flag */
#define PMM_PMMLPM5IFG                   PMMLPM5IFG     /* LPM5 indication Flag */
#define PMM_ALL                                                          (0xB7)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void PMM_enableSVSL(void);

extern void PMM_disableSVSL(void);

extern void PMM_enableSVSH(void);

extern void PMM_disableSVSH(void);

extern void PMM_regOn(void);

extern void PMM_regOff(void);

extern void PMM_trigPOR(void);

extern void PMM_trigBOR(void);

extern void PMM_clearInterrupt(uint16_t mask);

extern uint16_t PMM_getInterruptStatus(uint16_t mask);

extern void PMM_lockLPM5(void);

extern void PMM_unlockLPM5(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_PMM_H__

#endif
