//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430FR5739__)

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
// sfr.h - Driver for the SFR Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_SFR_H__
#define __MSP430WARE_SFR_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_SFR__

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
// The following are values that can be passed to the interruptMask parameter
// for functions: SFR_enableInterrupt(), and SFR_disableInterrupt(); the
// interruptFlagMask parameter for functions: SFR_getInterruptStatus(), and
// SFR_clearInterrupt() as well as returned by the SFR_getInterruptStatus()
// function.
//
//*****************************************************************************
#define SFR_JTAG_OUTBOX_INTERRUPT                                      JMBOUTIE
#define SFR_JTAG_INBOX_INTERRUPT                                        JMBINIE
#define SFR_NMI_PIN_INTERRUPT                                             NMIIE
#define SFR_VACANT_MEMORY_ACCESS_INTERRUPT                                VMAIE
#define SFR_OSCILLATOR_FAULT_INTERRUPT                                     OFIE
#define SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT                             WDTIE

//*****************************************************************************
//
// The following are values that can be passed to the pullResistorSetup
// parameter for functions: SFR_setResetPinPullResistor().
//
//*****************************************************************************
#define SFR_RESISTORDISABLE                            (!(SYSRSTRE + SYSRSTUP))
#define SFR_RESISTORENABLE_PULLUP                         (SYSRSTRE + SYSRSTUP)
#define SFR_RESISTORENABLE_PULLDOWN                                  (SYSRSTRE)

//*****************************************************************************
//
// The following are values that can be passed to the edgeDirection parameter
// for functions: SFR_setNMIEdge().
//
//*****************************************************************************
#define SFR_NMI_RISINGEDGE                                       (!(SYSNMIIES))
#define SFR_NMI_FALLINGEDGE                                         (SYSNMIIES)

//*****************************************************************************
//
// The following are values that can be passed to the resetPinFunction
// parameter for functions: SFR_setResetNMIPinFunction().
//
//*****************************************************************************
#define SFR_RESETPINFUNC_RESET                                      (!(SYSNMI))
#define SFR_RESETPINFUNC_NMI                                           (SYSNMI)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void SFR_enableInterrupt(uint8_t interruptMask);

extern void SFR_disableInterrupt(uint8_t interruptMask);

extern uint8_t SFR_getInterruptStatus(uint8_t interruptFlagMask);

extern void SFR_clearInterrupt(uint8_t interruptFlagMask);

extern void SFR_setResetPinPullResistor(uint16_t pullResistorSetup);

extern void SFR_setNMIEdge(uint16_t edgeDirection);

extern void SFR_setResetNMIPinFunction(uint8_t resetPinFunction);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_SFR_H__

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
// sfr.h - Driver for the SFR Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_SFR_H__
#define __MSP430WARE_SFR_H__

#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_SFR__

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
// The following are values that can be passed to the interruptMask parameter
// for functions: SFR_enableInterrupt(), and SFR_disableInterrupt(); the
// interruptFlagMask parameter for functions: SFR_getInterruptStatus(), and
// SFR_clearInterrupt() as well as returned by the SFR_getInterruptStatus()
// function.
//
//*****************************************************************************
#define SFR_JTAG_OUTBOX_INTERRUPT                                      JMBOUTIE
#define SFR_JTAG_INBOX_INTERRUPT                                        JMBINIE
#define SFR_NMI_PIN_INTERRUPT                                             NMIIE
#define SFR_VACANT_MEMORY_ACCESS_INTERRUPT                                VMAIE
#define SFR_OSCILLATOR_FAULT_INTERRUPT                                     OFIE
#define SFR_WATCHDOG_INTERVAL_TIMER_INTERRUPT                             WDTIE
#define SFR_FLASH_CONTROLLER_ACCESS_VIOLATION_INTERRUPT                  ACCVIE

//*****************************************************************************
//
// The following are values that can be passed to the pullResistorSetup
// parameter for functions: SFR_setResetPinPullResistor().
//
//*****************************************************************************
#define SFR_RESISTORDISABLE                            (!(SYSRSTRE + SYSRSTUP))
#define SFR_RESISTORENABLE_PULLUP                         (SYSRSTRE + SYSRSTUP)
#define SFR_RESISTORENABLE_PULLDOWN                                  (SYSRSTRE)

//*****************************************************************************
//
// The following are values that can be passed to the edgeDirection parameter
// for functions: SFR_setNMIEdge().
//
//*****************************************************************************
#define SFR_NMI_RISINGEDGE                                       (!(SYSNMIIES))
#define SFR_NMI_FALLINGEDGE                                         (SYSNMIIES)

//*****************************************************************************
//
// The following are values that can be passed to the resetPinFunction
// parameter for functions: SFR_setResetNMIPinFunction().
//
//*****************************************************************************
#define SFR_RESETPINFUNC_RESET                                      (!(SYSNMI))
#define SFR_RESETPINFUNC_NMI                                           (SYSNMI)

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void SFR_enableInterrupt(uint8_t interruptMask);

extern void SFR_disableInterrupt(uint8_t interruptMask);

extern uint8_t SFR_getInterruptStatus(uint8_t interruptFlagMask);

extern void SFR_clearInterrupt(uint8_t interruptFlagMask);

extern void SFR_setResetPinPullResistor(uint16_t pullResistorSetup);

extern void SFR_setNMIEdge(uint16_t edgeDirection);

extern void SFR_setResetNMIPinFunction(uint8_t resetPinFunction);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_SFR_H__

#endif
