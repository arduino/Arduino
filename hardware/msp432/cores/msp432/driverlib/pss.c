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
/* Standard Includes */
#include <stdint.h>

/* DriverLib Includes */
#include <pss.h>
#include <interrupt.h>
#include <debug.h>
#include <cpu.h>

static void __PSSUnlock()
{
    PSS->rKEY.r = PSS_KEY_VALUE;
}

static void __PSSLock()
{
    PSS->rKEY.r = 0;
}

void PSS_enableHighSidePinToggle(bool activeLow)
{
    __PSSUnlock();

    if (activeLow)
        PSS->rCTL0.r |= (SVMHOE | SVMHOUTPOLAL);
    else
    {
        BITBAND_PERI(PSS->rCTL0.r, SVMHOUTPOLAL_OFS) = 0;
        BITBAND_PERI(PSS->rCTL0.r, SVMHOE_OFS) = 1;
    }

    __PSSLock();
}

void PSS_disableHighSidePinToggle(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVMHOE_OFS) = 0;

    __PSSLock();
}

void PSS_enableHighSide(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVSMHOFF_OFS) = 0;

    __PSSLock();
}

void PSS_disableHighSide(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVSMHOFF_OFS) = 1;

    __PSSLock();
}

void PSS_setHighSidePerformanceMode(uint_fast8_t powerMode)
{
    __PSSUnlock();

    if (powerMode == PSS_FULL_PERFORMANCE_MODE)
        BITBAND_PERI(PSS->rCTL0.r, SVSMHLP_OFS) = 0;
    else
        BITBAND_PERI(PSS->rCTL0.r, SVSMHLP_OFS) = 1;

    __PSSLock();
}

uint_fast8_t PSS_getHighSidePerformanceMode(void)
{
    if (BITBAND_PERI(PSS->rCTL0.r, SVSMHLP_OFS))
        return PSS_NORMAL_PERFORMANCE_MODE;
    else
        return PSS_FULL_PERFORMANCE_MODE;
}

void PSS_enableHighSideMonitor(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVSMHS_OFS) = 1;

    __PSSLock();
}

void PSS_disableHighSideMonitor(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVSMHS_OFS) = 0;

    __PSSLock();
}

void PSS_setHighSideVoltageTrigger(uint_fast8_t triggerVoltage)
{
    __PSSUnlock();

    ASSERT(!(triggerVoltage & 0xF8))

    PSS->rCTL0.b.bSVSMHTH = triggerVoltage & 0x07;

    __PSSLock();
}

uint_fast8_t PSS_getHighSideVoltageTrigger(void)
{
    return PSS->rCTL0.b.bSVSMHTH;
}


void PSS_enableLowSide(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVSLOFF_OFS) = 0;

    __PSSLock();
}

void PSS_disableLowSide(void)
{
    __PSSUnlock();

    BITBAND_PERI(PSS->rCTL0.r, SVSLOFF_OFS) = 1;

    __PSSLock();
}


void PSS_setLowSidePerformanceMode(uint_fast8_t ui8PowerMode)
{
    __PSSUnlock();

    if (ui8PowerMode == PSS_FULL_PERFORMANCE_MODE)
        BITBAND_PERI(PSS->rCTL0.r, SVSLLP_OFS) = 0;
    else
        BITBAND_PERI(PSS->rCTL0.r, SVSLLP_OFS) = 1;

    __PSSLock();
}

uint_fast8_t PSS_getLowSidePerformanceMode(void)
{
    if (BITBAND_PERI(PSS->rCTL0.r, SVSLLP_OFS))
        return PSS_NORMAL_PERFORMANCE_MODE;
    else
        return PSS_FULL_PERFORMANCE_MODE;
}


void PSS_enableInterrupt(void)
{
    __PSSUnlock();
    BITBAND_PERI(PSS->rIE.r,SVSMHIE_OFS) = 1;
    __PSSLock();
}

void PSS_disableInterrupt(void)
{
    __PSSUnlock();
    BITBAND_PERI(PSS->rIE.r,SVSMHIE_OFS) = 0;
    __PSSLock();
}

uint32_t PSS_getInterruptStatus(void)
{
    return PSS->rIFG.r;
}

void PSS_clearInterruptFlag(void)
{
    __PSSUnlock();
    BITBAND_PERI(PSS->rCLRIFG.r,CLRSVSMHIFG_OFS) = 0;
    __PSSLock();
}

void PSS_registerInterrupt(void (*intHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    Interrupt_registerInterrupt(INT_PSS, intHandler);

    //
    // Enable the system control interrupt.
    //
    Interrupt_enableInterrupt(INT_PSS);
}

void PSS_unregisterInterrupt(void)
{
    //
    // Disable the interrupt.
    //
    Interrupt_disableInterrupt(INT_PSS);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregisterInterrupt(INT_PSS);
}
