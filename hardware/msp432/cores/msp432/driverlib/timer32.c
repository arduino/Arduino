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
#include <timer32.h>
#include <interrupt.h>
#include <debug.h>

void Timer32_initModule(uint32_t timer, uint32_t preScaler, uint32_t resolution,
        uint32_t mode)
{
    /* Setting up one shot or continuous mode */
    if (mode == TIMER32_PERIODIC_MODE)
        HWREGBIT8(timer + OFS_TIMER32_CONTROL1, TIMER32_CONTROL1_MODE_OFS) = 1;
    else if (mode == TIMER32_FREE_RUN_MODE)
        HWREGBIT8(timer + OFS_TIMER32_CONTROL1, TIMER32_CONTROL1_MODE_OFS) = 0;
    else
        ASSERT(false);

    /* Setting the resolution of the timer */
    if (resolution == TIMER32_1_MODULE6BIT)
        HWREGBIT8(timer + OFS_TIMER32_CONTROL1, TIMER32_CONTROL1_SIZE_OFS) = 0;
    else if (resolution == TIMER32_32BIT)
        HWREGBIT8(timer + OFS_TIMER32_CONTROL1, TIMER32_CONTROL1_SIZE_OFS) = 1;
    else
        ASSERT(false);

    /* Setting the PreScaler */
    ASSERT(
            resolution == TIMER32_PRESCALER_1
            || resolution == TIMER32_PRESCALER_16
            || resolution == TIMER32_PRESCALER_256);

    HWREG32(timer + OFS_TIMER32_CONTROL1) =
            (HWREG32(timer + OFS_TIMER32_CONTROL1)
                    & ~TIMER32_CONTROL1_PRESCALE_M) | preScaler;

}

void Timer32_setCount(uint32_t timer, uint32_t count)
{
    if (!HWREGBIT32(timer + OFS_TIMER32_CONTROL1,
            TIMER32_CONTROL1_SIZE_OFS) && (count > UINT16_MAX))
        HWREG32(timer + OFS_TIMER32_LOAD1) = UINT16_MAX;
    else
        HWREG32(timer + OFS_TIMER32_LOAD1) = count;
}

void Timer32_setCountInBackground(uint32_t timer, uint32_t count)
{
    if (!HWREGBIT32(timer + OFS_TIMER32_CONTROL1,
            TIMER32_CONTROL1_SIZE_OFS) && (count > UINT16_MAX))
        HWREG32(timer + OFS_TIMER32_BGLOAD1) = UINT16_MAX;
    else
        HWREG32(timer + OFS_TIMER32_BGLOAD1) = count;
}

uint32_t Timer32_getValue(uint32_t timer)
{
    return HWREG32(timer + OFS_TIMER32_VALUE1);
}

void Timer32_startTimer(uint32_t timer, bool oneShot)
{
    ASSERT(timer == TIMER32_0_MODULE || timer == TIMER32_1_MODULE);

    if (oneShot)
        HWREGBIT8(timer + OFS_TIMER32_CONTROL1, TIMER32_CONTROL1_ONESHOT_OFS) =
                1;
    else
        HWREGBIT8(timer + OFS_TIMER32_CONTROL1, TIMER32_CONTROL1_ONESHOT_OFS) =
                0;

    HWREG32(timer + OFS_TIMER32_CONTROL1) |= TIMER32_CONTROL1_ENABLE;
}

void Timer32_haltTimer(uint32_t timer)
{
    ASSERT(timer == TIMER32_0_MODULE || timer == TIMER32_1_MODULE);

    HWREG32(timer + OFS_TIMER32_CONTROL1) &= ~TIMER32_CONTROL1_ENABLE;
}

void Timer32_enableInterrupt(uint32_t timer)
{
    HWREG32(timer + OFS_TIMER32_CONTROL1) |= TIMER32_CONTROL1_IE;
}

void Timer32_disableInterrupt(uint32_t timer)
{
    HWREG32(timer + OFS_TIMER32_CONTROL1) &= ~TIMER32_CONTROL1_IE;
}

void Timer32_clearInterruptFlag(uint32_t timer)
{
    HWREG32(timer + OFS_TIMER32_INTCLR1) |= 0x01;
}

uint32_t Timer32_getInterruptStatus(uint32_t timer)
{
    return HWREG32(timer + OFS_TIMER32_MIS1);
}

void Timer32_registerInterrupt(uint32_t timerInterrupt,
        void (*intHandler)(void))
{
    Interrupt_registerInterrupt(timerInterrupt, intHandler);
    Interrupt_enableInterrupt(timerInterrupt);
}

void Timer32_unregisterInterrupt(uint32_t timerInterrupt)
{
    Interrupt_disableInterrupt(timerInterrupt);
    Interrupt_unregisterInterrupt(timerInterrupt);
}

