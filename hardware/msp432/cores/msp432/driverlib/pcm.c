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
#include <pcm.h>
#include <debug.h>
#include <interrupt.h>
#include <cpu.h>

bool PCM_setCoreVoltageLevel(uint_fast8_t voltageLevel)
{
    return PCM_setCoreVoltageLevelWithTimeout(voltageLevel, 0);
}

bool PCM_setCoreVoltageLevelWithTimeout(uint_fast8_t voltageLevel,
        uint32_t timeOut)
{
    uint8_t powerMode, bCurrentVoltageLevel;
    uint32_t regValue;
    bool boolTimeout;

    ASSERT(voltageLevel == PCM_VCORE0 || voltageLevel == PCM_VCORE1);

    /* Getting current power mode and level */
    powerMode = PCM_getPowerMode();
    bCurrentVoltageLevel = PCM_getCoreVoltageLevel();

    boolTimeout = timeOut > 0 ? true : false;

    /* If we are already at the power mode they requested, return */
    if (bCurrentVoltageLevel == voltageLevel)
        return true;

    while (bCurrentVoltageLevel != voltageLevel)
    {
        regValue = PCM->rCTL0.r;

        switch (PCM_getPowerState())
        {
        case PCM_AM_LF_VCORE1:
        case PCM_AM_DCDC_VCORE1:
        case PCM_AM_LDO_VCORE0:
            PCM->rCTL0.r = (PCM_KEY | (PCM_AM_LDO_VCORE1)
                    | (regValue & ~(PCMKEY_M | AMR_M)));
            break;
        case PCM_AM_LF_VCORE0:
        case PCM_AM_DCDC_VCORE0:
        case PCM_AM_LDO_VCORE1:
            PCM->rCTL0.r = (PCM_KEY | (PCM_AM_LDO_VCORE0)
                    | (regValue & ~(PCMKEY_M | AMR_M)));
            break;
        default:
            ASSERT(false);
        }

        while (BITBAND_PERI(PCM->rCTL1.r, PMR_BUSY_OFS))
        {
            if (boolTimeout && !(--timeOut))
                return false;

        }

        bCurrentVoltageLevel = PCM_getCoreVoltageLevel();
    }

    /* Changing the power mode if we are stuck in LDO mode */
    if (powerMode != PCM_getPowerMode())
    {
        if (powerMode == PCM_DCDC_MODE)
            return PCM_setPowerMode(PCM_DCDC_MODE);
        else
            return PCM_setPowerMode(PCM_LF_MODE);
    }

    return true;

}

bool PCM_setPowerMode(uint_fast8_t powerMode)
{
    return PCM_setPowerModeWithTimeout(powerMode, 0);
}

uint8_t PCM_getPowerMode(void)
{
    uint8_t currentPowerState;

    currentPowerState = PCM_getPowerState();

    switch (currentPowerState)
    {
    case PCM_AM_LDO_VCORE0:
    case PCM_AM_LDO_VCORE1:
    case PCM_LPM0_LDO_VCORE0:
    case PCM_LPM0_LDO_VCORE1:
        return PCM_LDO_MODE;
    case PCM_AM_DCDC_VCORE0:
    case PCM_AM_DCDC_VCORE1:
    case PCM_LPM0_DCDC_VCORE0:
    case PCM_LPM0_DCDC_VCORE1:
        return PCM_DCDC_MODE;
    case PCM_LPM0_LF_VCORE0:
    case PCM_LPM0_LF_VCORE1:
    case PCM_AM_LF_VCORE1:
    case PCM_AM_LF_VCORE0:
        return PCM_LF_MODE;
    default:
        ASSERT(false);
        return false;

    }
}

uint8_t PCM_getCoreVoltageLevel(void)
{
    uint8_t currentPowerState = PCM_getPowerState();

    switch (currentPowerState)
    {
    case PCM_AM_LDO_VCORE0:
    case PCM_AM_DCDC_VCORE0:
    case PCM_AM_LF_VCORE0:
    case PCM_LPM0_LDO_VCORE0:
    case PCM_LPM0_DCDC_VCORE0:
    case PCM_LPM0_LF_VCORE0:
        return PCM_VCORE0;
    case PCM_AM_LDO_VCORE1:
    case PCM_AM_DCDC_VCORE1:
    case PCM_AM_LF_VCORE1:
    case PCM_LPM0_LDO_VCORE1:
    case PCM_LPM0_DCDC_VCORE1:
    case PCM_LPM0_LF_VCORE1:
        return PCM_VCORE1;
    case PCM_LPM3:
        return PCM_VCORELPM3;
    default:
        ASSERT(false);
        return false;

    }
}

bool PCM_setPowerModeWithTimeout(uint_fast8_t powerMode, uint32_t timeOut)
{
    uint8_t bCurrentPowerMode, bCurrentPowerState;
    uint32_t regValue;
    bool boolTimeout;

    ASSERT(
            powerMode == PCM_LDO_MODE || powerMode == PCM_DCDC_MODE
            || powerMode == PCM_LF_MODE);

    /* Getting Current Power Mode */
    bCurrentPowerMode = PCM_getPowerMode();

    /* If the power mode being set it the same as the current mode, return */
    if (powerMode == bCurrentPowerMode)
        return true;

    bCurrentPowerState = PCM_getPowerState();

    boolTimeout = timeOut > 0 ? true : false;

    /* Go through the while loop while we haven't achieved the power mode */
    while (bCurrentPowerMode != powerMode)
    {
        regValue = PCM->rCTL0.r;

        switch (bCurrentPowerState)
        {
        case PCM_AM_DCDC_VCORE0:
        case PCM_AM_LF_VCORE0:
            PCM->rCTL0.r = (PCM_KEY | PCM_AM_LDO_VCORE0
                    | (regValue & ~(PCMKEY_M | AMR_M)));
            break;
        case PCM_AM_LF_VCORE1:
        case PCM_AM_DCDC_VCORE1:
            PCM->rCTL0.r = (PCM_KEY | PCM_AM_LDO_VCORE1
                    | (regValue & ~(PCMKEY_M | AMR_M)));
            break;
        case PCM_AM_LDO_VCORE1:
        {
            if (powerMode == PCM_DCDC_MODE)
            {
                PCM->rCTL0.r = (PCM_KEY | PCM_AM_DCDC_VCORE1
                        | (regValue & ~(PCMKEY_M | AMR_M)));
            } else if (powerMode == PCM_LF_MODE)
            {
                PCM->rCTL0.r = (PCM_KEY | PCM_AM_LF_VCORE1
                        | (regValue & ~(PCMKEY_M | AMR_M)));
            } else
                ASSERT(false);

            break;
        }
        case PCM_AM_LDO_VCORE0:
        {
            if (powerMode == PCM_DCDC_MODE)
            {
                PCM->rCTL0.r = (PCM_KEY | PCM_AM_DCDC_VCORE0
                        | (regValue & ~(PCMKEY_M | AMR_M)));
            } else if (powerMode == PCM_LF_MODE)
            {
                PCM->rCTL0.r = (PCM_KEY | PCM_AM_LF_VCORE0
                        | (regValue & ~(PCMKEY_M | AMR_M)));
            } else
                ASSERT(false);

            break;
        }
        default:
            ASSERT(false);
        }

        while (BITBAND_PERI(PCM->rCTL1.r, PMR_BUSY_OFS))
        {
            if (boolTimeout && !(--timeOut))
                return false;

        }

        bCurrentPowerMode = PCM_getPowerMode();
        bCurrentPowerState = PCM_getPowerState();
    }

    return true;

}

bool PCM_setPowerState(uint_fast8_t powerState)
{
    return PCM_setPowerStateWithTimeout(powerState, 0);
}

bool PCM_setPowerStateWithTimeout(uint_fast8_t powerState, uint32_t timeout)
{
    uint8_t bCurrentPowerState;
    bCurrentPowerState = PCM_getPowerState();

    ASSERT(
            powerState == PCM_AM_LDO_VCORE0 || powerState == PCM_AM_LDO_VCORE1
            || powerState == PCM_AM_DCDC_VCORE0 || powerState == PCM_AM_DCDC_VCORE1
            || powerState == PCM_AM_LF_VCORE0 || powerState == PCM_AM_LF_VCORE1
            || powerState == PCM_LPM0_LDO_VCORE0 || powerState == PCM_LPM0_LDO_VCORE1
            || powerState == PCM_LPM0_DCDC_VCORE0 || powerState == PCM_LPM0_DCDC_VCORE1
            || powerState == PCM_LPM3 || powerState == PCM_LPM35_VCORE0
            || powerState == PCM_LPM45);

    if (bCurrentPowerState == powerState)
        return true;

    switch (powerState)
    {
    case PCM_AM_LDO_VCORE0:
        return (PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE0, timeout)
                && PCM_setPowerModeWithTimeout(PCM_LDO_MODE, timeout));
    case PCM_AM_LDO_VCORE1:
        return (PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE1, timeout)
                && PCM_setPowerModeWithTimeout(PCM_LDO_MODE, timeout));
    case PCM_AM_DCDC_VCORE0:
        return (PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE0, timeout)
                && PCM_setPowerModeWithTimeout(PCM_DCDC_MODE, timeout));
    case PCM_AM_DCDC_VCORE1:
        return (PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE1, timeout)
                && PCM_setPowerModeWithTimeout(PCM_DCDC_MODE, timeout));
    case PCM_AM_LF_VCORE0:
        return (PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE0, timeout)
                && PCM_setPowerModeWithTimeout(PCM_LF_MODE, timeout));
    case PCM_AM_LF_VCORE1:
        return (PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE1, timeout)
                && PCM_setPowerModeWithTimeout(PCM_LF_MODE, timeout));
    case PCM_LPM0_LDO_VCORE0:
        if (!PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE0, timeout)
                || !PCM_setPowerModeWithTimeout(PCM_LDO_MODE, timeout))
            break;
        return PCM_gotoLPM0();
    case PCM_LPM0_LDO_VCORE1:
        if (!PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE1, timeout)
                || !PCM_setPowerModeWithTimeout(PCM_LDO_MODE, timeout))
            break;
        return PCM_gotoLPM0();
    case PCM_LPM0_DCDC_VCORE0:
        if (!PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE0, timeout)
                || !PCM_setPowerModeWithTimeout(PCM_DCDC_MODE, timeout))
            break;
        return PCM_gotoLPM0();
    case PCM_LPM0_DCDC_VCORE1:
        if (!PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE1, timeout)
                || !PCM_setPowerModeWithTimeout(PCM_DCDC_MODE, timeout))
            break;
        return PCM_gotoLPM0();
    case PCM_LPM0_LF_VCORE0:
        if (!PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE0, timeout)
                || !PCM_setPowerModeWithTimeout(PCM_LF_MODE, timeout))
            break;
        return PCM_gotoLPM0();
    case PCM_LPM0_LF_VCORE1:
        if (!PCM_setCoreVoltageLevelWithTimeout(PCM_VCORE1, timeout)
                || !PCM_setPowerModeWithTimeout(PCM_LF_MODE, timeout))
            break;
        return PCM_gotoLPM0();
    case PCM_LPM3:
        return PCM_gotoLPM3();
    case PCM_LPM45:
        return PCM_shutdownDevice(PCM_LPM45);
    case PCM_LPM35_VCORE0:
        return PCM_shutdownDevice(PCM_LPM35_VCORE0);
    default:
        ASSERT(false);
        return false;
    }

    return false;

}

bool PCM_shutdownDevice(uint32_t shutdownMode)
{
    uint32_t shutdownModeBits = (shutdownMode == PCM_LPM45) ? LPMR_12 : LPMR_10;

    ASSERT(
            shutdownMode == PCM_SHUTDOWN_PARTIAL
            || shutdownMode == PCM_SHUTDOWN_COMPLETE);

    /* If a power transition is occuring, return false */
    if (BITBAND_PERI(PCM->rCTL1.r, PMR_BUSY_OFS))
        return false;

    /* Initiating the shutdown */
    HWREG32(SCS_BASE + OFS_SCB_SCR) |= (SCB_SCR_SLEEPDEEP);
    PCM->rCTL0.r = (PCM_KEY | shutdownModeBits
            | (PCM->rCTL0.r & ~(PCMKEY_M | LPMR_M)));

    CPU_wfi();

    return true;
}

bool PCM_gotoLPM0(void)
{

    /* If we are in the middle of a state transition, return false */
    if (BITBAND_PERI(PCM->rCTL1.r, PMR_BUSY_OFS))
        return false;

    HWREG32(SCS_BASE + OFS_SCB_SCR) &= ~(SCB_SCR_SLEEPDEEP);

    CPU_wfi();

    return true;
}

bool PCM_gotoLPM0InterruptSafe(void)
{

    bool slHappenedCorrect;

    /* Disabling master interrupts. In Cortex M, if an interrupt is enabled but 
     master interrupts are disabled and a WFI happens the WFI will
     immediately exit. */
    Interrupt_disableMaster();

    slHappenedCorrect = PCM_gotoLPM0();

    /* Enabling and Disabling Interrupts very quickly so that the
     processor catches any pending interrupts */
    Interrupt_enableMaster();
    Interrupt_disableMaster();

    return slHappenedCorrect;
}

bool PCM_gotoLPM3(void)
{
    uint_fast8_t bCurrentPowerState;
    uint_fast8_t currentPowerMode;

    /* If we are in the middle of a state transition, return false */
    if (BITBAND_PERI(PCM->rCTL1.r, PMR_BUSY_OFS))
        return false;

    /* If we are in the middle of a shutdown, return false */
    if ((PCM->rCTL0.r & LPMR_M) == LPMR_10 || (PCM->rCTL0.r & LPMR_M) == LPMR_12)
        return false;

    currentPowerMode = PCM_getPowerMode();
    bCurrentPowerState = PCM_getPowerState();

    if (currentPowerMode == PCM_DCDC_MODE || currentPowerMode == PCM_LF_MODE)
        PCM_setPowerMode(PCM_LDO_MODE);

    /* Clearing the SDR */
    PCM->rCTL0.r = (PCM->rCTL0.r & ~(PCMKEY_M | LPMR_M)) | PCM_KEY;

    /* Setting the sleep deep bit */
    HWREG32(SCS_BASE + OFS_SCB_SCR) |= (SCB_SCR_SLEEPDEEP);

    CPU_wfi();

    HWREG32(SCS_BASE + OFS_SCB_SCR) &= ~(SCB_SCR_SLEEPDEEP);

    return PCM_setPowerState(bCurrentPowerState);
}

bool PCM_gotoLPM3InterruptSafe(void)
{
    bool dslHappenedCorrect;

    /* Disabling master interrupts. In Cortex M, if an interrupt is enabled but 
     master interrupts are disabled and a WFI happens the WFI will
     immediately exit. */
    Interrupt_disableMaster();

    dslHappenedCorrect = PCM_gotoLPM3();

    /* Enabling and Disabling Interrupts very quickly so that the
     processor catches any pending interrupts */
    Interrupt_enableMaster();
    Interrupt_disableMaster();

    return dslHappenedCorrect;
}

uint8_t PCM_getPowerState(void)
{
    return PCM->rCTL0.b.bCPM;
}

void PCM_enableRudeMode(void)
{

    PCM->rCTL1.r = (PCM->rCTL1.r & ~(PCMKEY_M)) | PCM_KEY | FORCE_LPM_ENTRY;
}

void PCM_disableRudeMode(void)
{
    PCM->rCTL1.r = (PCM->rCTL1.r & ~(PCMKEY_M | FORCE_LPM_ENTRY)) | PCM_KEY;
}

void PCM_enableInterrupt(uint32_t flags)
{
    PCM->rIE.r |= flags;
}

void PCM_disableInterrupt(uint32_t flags)
{
    PCM->rIE.r &= ~flags;
}

uint32_t PCM_getInterruptStatus(void)
{
    return PCM->rIFG.r;
}

uint32_t PCM_getEnabledInterruptStatus(void)
{
    return PCM_getInterruptStatus() & PCM->rIE.r;
}

void PCM_clearInterruptFlag(uint32_t flags)
{
    PCM->rCLRIFG.r |= flags;
}

void PCM_registerInterrupt(void (*intHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    Interrupt_registerInterrupt(INT_PCM, intHandler);

    //
    // Enable the system control interrupt.
    //
    Interrupt_enableInterrupt(INT_PCM);
}

void PCM_unregisterInterrupt(void)
{
    //
    // Disable the interrupt.
    //
    Interrupt_disableInterrupt(INT_PCM);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregisterInterrupt(INT_PCM);
}
