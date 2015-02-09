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
#include <stdbool.h>

/* DriverLib Includes */
#include <adc14.h>
#include <debug.h>
#include <interrupt.h>

/* Statics */
static volatile uint32_t* const _ctlRegs[32] =
{ &ADC14->rMCTL0.r, &ADC14->rMCTL1.r, &ADC14->rMCTL2.r, &ADC14->rMCTL3.r,
        &ADC14->rMCTL4.r, &ADC14->rMCTL5.r, &ADC14->rMCTL6.r, &ADC14->rMCTL7.r,
        &ADC14->rMCTL8.r, &ADC14->rMCTL9.r, &ADC14->rMCTL10.r,
        &ADC14->rMCTL11.r, &ADC14->rMCTL12.r, &ADC14->rMCTL13.r,
        &ADC14->rMCTL14.r, &ADC14->rMCTL15.r, &ADC14->rMCTL16.r,
        &ADC14->rMCTL17.r, &ADC14->rMCTL18.r, &ADC14->rMCTL19.r,
        &ADC14->rMCTL20.r, &ADC14->rMCTL21.r, &ADC14->rMCTL22.r,
        &ADC14->rMCTL23.r, &ADC14->rMCTL24.r, &ADC14->rMCTL25.r,
        &ADC14->rMCTL26.r, &ADC14->rMCTL27.r, &ADC14->rMCTL28.r,
        &ADC14->rMCTL29.r, &ADC14->rMCTL30.r, &ADC14->rMCTL31.r };

static uint_fast8_t _getIndexForMemRegister(uint32_t reg)
{
    switch (reg)
    {
    case ADC_MEM0:
        return 0;
    case ADC_MEM1:
        return 1;
    case ADC_MEM2:
        return 2;
    case ADC_MEM3:
        return 3;
    case ADC_MEM4:
        return 4;
    case ADC_MEM5:
        return 5;
    case ADC_MEM6:
        return 6;
    case ADC_MEM7:
        return 7;
    case ADC_MEM8:
        return 8;
    case ADC_MEM9:
        return 9;
    case ADC_MEM10:
        return 10;
    case ADC_MEM11:
        return 11;
    case ADC_MEM12:
        return 12;
    case ADC_MEM13:
        return 13;
    case ADC_MEM14:
        return 14;
    case ADC_MEM15:
        return 15;
    case ADC_MEM16:
        return 16;
    case ADC_MEM17:
        return 17;
    case ADC_MEM18:
        return 18;
    case ADC_MEM19:
        return 19;
    case ADC_MEM20:
        return 20;
    case ADC_MEM21:
        return 21;
    case ADC_MEM22:
        return 22;
    case ADC_MEM23:
        return 23;
    case ADC_MEM24:
        return 24;
    case ADC_MEM25:
        return 25;
    case ADC_MEM26:
        return 26;
    case ADC_MEM27:
        return 27;
    case ADC_MEM28:
        return 28;
    case ADC_MEM29:
        return 29;
    case ADC_MEM30:
        return 30;
    case ADC_MEM31:
        return 31;
    default:
        ASSERT(false);
        return ADC_INVALID_MEM;

    }
}

//*****************************************************************************
//
//!
//! Returns a boolean value that tells if conversion is active/running or is
//! not acMSP432 ted.
//!
//! Originally a public function, but moved to static. External customers should
//! use the ADC14_isBusy function.
//!
//! \return true if conversion is active, false otherwise
//
//*****************************************************************************
static bool ADCIsConversionRunning(void)
{
    return BITBAND_PERI(ADC14->rCTL0.r, ADC14BUSY_OFS);
}

void ADC14_enableModule(void)
{
    BITBAND_PERI(ADC14->rCTL0.r, ADC14ON_OFS) = 1;
}

bool ADC14_disableModule(void)
{
    if (ADCIsConversionRunning())
        return false;

    BITBAND_PERI(ADC14->rCTL0.r, ADC14ON_OFS) = 0;

    return true;
}

bool ADC14_enableSampleTimer(uint32_t multiSampleConvert)
{
    if (ADCIsConversionRunning())
        return false;

    BITBAND_PERI(ADC14->rCTL0.r, ADC14SHP_OFS) = 1;

    if (multiSampleConvert == ADC_MANUAL_ITERATION)
    {
        BITBAND_PERI(ADC14->rCTL0.r, ADC14MSC_OFS) = 0;
    } else
    {
        BITBAND_PERI(ADC14->rCTL0.r, ADC14MSC_OFS) = 1;
    }

    return true;
}

bool ADC14_disableSampleTimer(void)
{
    if (ADCIsConversionRunning())
        return false;

    BITBAND_PERI(ADC14->rCTL0.r, ADC14SHP_OFS) = 0;

    return true;
}

bool ADC14_initModule(uint32_t clockSource, uint32_t clockPredivider,
        uint32_t clockDivider, uint32_t internalChannelMask)
{
    ASSERT(
            clockSource == ADC_CLOCKSOURCE_ADCOSC
            || clockSource == ADC_CLOCKSOURCE_SYSOSC
            || clockSource == ADC_CLOCKSOURCE_ACLK
            || clockSource == ADC_CLOCKSOURCE_MCLK
            || clockSource == ADC_CLOCKSOURCE_SMCLK
            || clockSource == ADC_CLOCKSOURCE_HSMCLK);

    ASSERT(
            clockPredivider == ADC_PREDIVIDER_1
            || clockPredivider == ADC_PREDIVIDER_4
            || clockPredivider == ADC_PREDIVIDER_32
            || clockPredivider == ADC_PREDIVIDER_64);

    ASSERT(
            clockDivider == ADC_DIVIDER_1 || clockDivider == ADC_DIVIDER_2
            || clockDivider == ADC_DIVIDER_3
            || clockDivider == ADC_DIVIDER_4
            || clockDivider == ADC_DIVIDER_5
            || clockDivider == ADC_DIVIDER_6
            || clockDivider == ADC_DIVIDER_7
            || clockDivider == ADC_DIVIDER_8);

    ASSERT(
            !(internalChannelMask
                    & ~(ADC_MAPINTCH3 | ADC_MAPINTCH2 | ADC_MAPINTCH1
                            | ADC_MAPINTCH0 | ADC_TEMPSENSEMAP | ADC_BATTMAP)));

    if (ADCIsConversionRunning())
        return false;

    ADC14->rCTL0.r = (ADC14->rCTL0.r
            & ~(ADC14PDIV_M | ADC14DIV_M | ADC14SSEL_M))
            | clockDivider | clockPredivider | clockSource;

    ADC14->rCTL1.r = (ADC14->rCTL1.r
            & ~(ADC_MAPINTCH3 | ADC_MAPINTCH2 | ADC_MAPINTCH1 | ADC_MAPINTCH0
                    | ADC_TEMPSENSEMAP | ADC_BATTMAP)) | internalChannelMask;

    return true;
}

void ADC14_setResolution(uint32_t resolution)
{
    ASSERT(
            resolution == ADC_8BIT || resolution == ADC_10BIT
            || resolution == ADC_12BIT || resolution == ADC_14BIT);

    ADC14->rCTL1.r = (ADC14->rCTL1.r & ~ADC14RES_M) |  resolution;
}

uint_fast32_t ADC14_getResolution(void)
{
    return ADC14->rCTL1.r & ADC14RES_M;
}

bool ADC14_setSampleHoldTrigger(uint32_t source, bool invertSignal)
{

    ASSERT(
            source == ADC_TRIGGER_ADCSC || source == ADC_TRIGGER_SOURCE1
            || source == ADC_TRIGGER_SOURCE2
            || source == ADC_TRIGGER_SOURCE3
            || source == ADC_TRIGGER_SOURCE4
            || source == ADC_TRIGGER_SOURCE5
            || source == ADC_TRIGGER_SOURCE6
            || source == ADC_TRIGGER_SOURCE7);

    if (ADCIsConversionRunning())
        return false;

    if (invertSignal)
    {
        ADC14->rCTL0.r = (ADC14->rCTL0.r
                & ~(ADC14ISSH | ADC14SHS_M)) | source
                | ADC14ISSH;
    } else
    {
        ADC14->rCTL0.r = (ADC14->rCTL0.r
                & ~(ADC14ISSH | ADC14SHS_M)) | source;
    }

    return true;
}

bool ADC14_setSampleHoldTime(uint32_t firstPulseWidth,
        uint32_t secondPulseWidth)
{
    ASSERT(
            firstPulseWidth == ADC_PULSE_WIDTH_4
            || firstPulseWidth == ADC_PULSE_WIDTH_8
            || firstPulseWidth == ADC_PULSE_WIDTH_16
            || firstPulseWidth == ADC_PULSE_WIDTH_32
            || firstPulseWidth == ADC_PULSE_WIDTH_64
            || firstPulseWidth == ADC_PULSE_WIDTH_96
            || firstPulseWidth == ADC_PULSE_WIDTH_128
            || firstPulseWidth == ADC_PULSE_WIDTH_192);

    ASSERT(
            secondPulseWidth == ADC_PULSE_WIDTH_4
            || secondPulseWidth == ADC_PULSE_WIDTH_8
            || secondPulseWidth == ADC_PULSE_WIDTH_16
            || secondPulseWidth == ADC_PULSE_WIDTH_32
            || secondPulseWidth == ADC_PULSE_WIDTH_64
            || secondPulseWidth == ADC_PULSE_WIDTH_96
            || secondPulseWidth == ADC_PULSE_WIDTH_128
            || secondPulseWidth == ADC_PULSE_WIDTH_192);

    if (ADCIsConversionRunning())
        return false;

    ADC14->rCTL0.r = (ADC14->rCTL0.r
            & ~(ADC14SHT0_M | ADC14SHT1_M)) | secondPulseWidth
            | (firstPulseWidth >> 4);

    return true;
}

bool ADC14_configureMultiSequenceMode(uint32_t memoryStart, uint32_t memoryEnd,
bool repeatMode)
{
    uint32_t ii;

    ASSERT(
            _getIndexForMemRegister(memoryStart) != ADC_INVALID_MEM
            && _getIndexForMemRegister(memoryEnd) != ADC_INVALID_MEM);

    if (ADCIsConversionRunning())
        return false;

    /* Clearing out any lingering EOS */
    for (ii = 0; ii < 32; ii++)
    {
        BITBAND_PERI(*(_ctlRegs[ii]), ADC14EOS_OFS) = 0;
    }

    /* Setting Start/Stop locations */
    BITBAND_PERI(
            (*(_ctlRegs[_getIndexForMemRegister(memoryEnd)])),
            ADC14EOS_OFS) = 1;

    ADC14->rCTL1.r = (ADC14->rCTL1.r & ~(ADC14CSTARTADD_M))
                    | (_getIndexForMemRegister(memoryStart) << 16);

    /* Setting multiple sample mode */
    if (!repeatMode)
    {
        ADC14->rCTL0.r = (ADC14->rCTL0.r & ~(ADC14CONSEQ_M))
                | (ADC14CONSEQ_1);
    } else
    {
        ADC14->rCTL0.r = (ADC14->rCTL0.r & ~(ADC14CONSEQ_M))
                | (ADC14CONSEQ_3);
    }

    return true;
}

bool ADC14_configureSingleSampleMode(uint32_t memoryDestination,
bool repeatMode)
{
    ASSERT(_getIndexForMemRegister(memoryDestination) != 32);

    if (ADCIsConversionRunning())
        return false;

    /* Setting the destination register */
    ADC14->rCTL1.r = (ADC14->rCTL1.r & ~(ADC14CSTARTADD_M))
            | (_getIndexForMemRegister(memoryDestination) << 16);

    /* Setting single sample mode */
    if (!repeatMode)
    {
        ADC14->rCTL0.r = (ADC14->rCTL0.r & ~(ADC14CONSEQ_M))
                | (ADC14CONSEQ_0);
    } else
    {
        ADC14->rCTL0.r = (ADC14->rCTL0.r & ~(ADC14CONSEQ_M))
                | (ADC14CONSEQ_2);
    }

    return true;
}

bool ADC14_enableConversion(void)
{
    if (ADCIsConversionRunning() || !BITBAND_PERI(ADC14->rCTL0.r, ADC14ON_OFS))
        return false;

    ADC14->rCTL0.r |= (ADC14ENC);

    return true;
}

bool ADC14_toggleConversionTrigger(void)
{
    if (!BITBAND_PERI(ADC14->rCTL0.r, ADC14ON_OFS))
        return false;

    if (BITBAND_PERI(ADC14->rCTL0.r, ADC14SC_OFS))
    {
        BITBAND_PERI(ADC14->rCTL0.r, ADC14SC_OFS) = 0;
    } else
    {
        BITBAND_PERI(ADC14->rCTL0.r, ADC14SC_OFS) = 1;
    }

    return true;
}

void ADC14_disableConversion(void)
{
    ADC14->rCTL0.r &= ~(ADC14SC | ADC14ENC);
}

bool ADC14_isBusy(void)
{
    return BITBAND_PERI(ADC14->rCTL0.r, ADC14BUSY_OFS);
}

bool ADC14_configureConversionMemory(uint32_t memorySelect, uint32_t refSelect,
        uint32_t channelSelect, bool differntialMode)
{
    uint32_t currentReg, ii;
    uint32_t *curReg;

    /* Initialization */
    ii = 1;
    currentReg = 0x01;

    if (ADCIsConversionRunning())
        return false;

    while (memorySelect != 0)
    {
        if (!(memorySelect & ii))
        {
            ii = ii << 1;
            continue;
        }

        currentReg = memorySelect & ii;
        memorySelect &= ~ii;
        ii = ii << 1;

        curReg = (uint32_t*) _ctlRegs[_getIndexForMemRegister(currentReg)];

        if (differntialMode)
        {
            (*curReg) = ((*curReg)
                    & ~(ADC14VRSEL_M | ADC14INCH_M
                            | ADC14DIF))
                    | (channelSelect | refSelect | ADC14DIF);
        } else
        {
            (*curReg) = ((*curReg)
                    & ~(ADC14VRSEL_M | ADC14INCH_M
                            | ADC14DIF)) | (channelSelect | refSelect);
        }

    }

    return true;
}

bool ADC14_enableComparatorWindow(uint32_t memorySelect, uint32_t windowSelect)
{
    uint32_t currentReg, ii;
    uint32_t *curRegPoint;

    /* Initialization */
    ii = 1;
    currentReg = 0x01;

    if (ADCIsConversionRunning())
        return false;

    while (memorySelect != 0)
    {
        if (!(memorySelect & ii))
        {
            ii = ii << 1;
            continue;
        }

        currentReg = memorySelect & ii;
        memorySelect &= ~ii;
        ii = ii << 1;

        curRegPoint =
                (uint32_t*) _ctlRegs[_getIndexForMemRegister(currentReg)];

        if (windowSelect == ADC_COMP_WINDOW0)
        {
            (*curRegPoint) = ((*curRegPoint)
                    & ~(ADC14WINC | ADC14WINCTH))
                    | (ADC14WINC);
        } else if (windowSelect == ADC_COMP_WINDOW1)
        {
            (*curRegPoint) |= ADC14WINC | ADC14WINCTH;
        }

    }

    return true;
}

bool ADC14_disableComparatorWindow(uint32_t memorySelect)
{
    uint32_t currentReg, ii;

    /* Initialization */
    ii = 1;
    currentReg = 0x01;

    if (ADCIsConversionRunning())
        return false;

    while (memorySelect != 0)
    {
        if (!(memorySelect & ii))
        {
            ii = ii << 1;
            continue;
        }

        currentReg = memorySelect & ii;
        memorySelect &= ~ii;
        ii = ii << 1;

        (*(_ctlRegs[_getIndexForMemRegister(currentReg)])) &=
                ~ADC14WINC;

    }

    return true;
}

bool ADC14_setComparatorWindowValue(uint32_t window, int16_t low, int16_t high)
{
    if (ADCIsConversionRunning())
        return false;

    if (window == ADC_COMP_WINDOW0)
    {
        ADC14->rHI0.r = (high);
        ADC14->rLO0.r = (low);

    } else if (window == ADC_COMP_WINDOW1)
    {
        ADC14->rHI1.r = (high);
        ADC14->rLO1.r = (low);

    } else
    {
        ASSERT(false);
    }

    return true;
}

bool ADC14_setResultFormat(uint32_t resultFormat)
{
    if (ADCIsConversionRunning())
        return false;

    if (resultFormat == ADC_UNSIGNED_BINARY)
    {
        BITBAND_PERI(ADC14->rCTL1.r, ADC14DF_OFS) = 0;
    } else if (resultFormat == ADC_SIGNED_BINARY)
    {
        BITBAND_PERI(ADC14->rCTL1.r, ADC14DF_OFS) = 1;
    } else
    {
        ASSERT(false);
    }

    return true;
}

uint_fast16_t ADC14_getResult(uint32_t memorySelect)
{
    return *((uint16_t*) (_ctlRegs[_getIndexForMemRegister(memorySelect)]
            + 0x80));
}

void ADC14_getMultiSequenceResult(uint16_t* res)
{
    uint32_t *startAddr, *curAddr;
    uint32_t ii;

    startAddr = (uint32_t*) _ctlRegs[(ADC14->rCTL1.r & ADC14CSTARTADD_M)
            >> 16];

    curAddr = startAddr;

    for (ii = 0; ii < 32; ii++)
    {
        res[ii] = *(((uint16_t*) curAddr) + 0x80);

        if (BITBAND_PERI((*curAddr), ADC14EOS_OFS))
            break;

        if (curAddr == _ctlRegs[31])
            curAddr = (uint32_t*) _ctlRegs[0];
        else
            curAddr += 0x04;
    }

}

void ADC14_getResultArray(uint32_t memoryStart, uint32_t memoryEnd,
        uint16_t* res)
{
    uint32_t ii = 0;
    uint32_t *firstPoint, *secondPoint;

    bool foundEnd = false;

    ASSERT(
            _getIndexForMemRegister(memoryStart) != ADC_INVALID_MEM
            && _getIndexForMemRegister(memoryEnd) != ADC_INVALID_MEM);

    firstPoint = (uint32_t*) _ctlRegs[_getIndexForMemRegister(memoryStart)];
    secondPoint = (uint32_t*) _ctlRegs[_getIndexForMemRegister(memoryEnd)];

    while (!foundEnd)
    {
        if (firstPoint == secondPoint)
        {
            foundEnd = true;
        }

        res[ii] = *(((uint16_t*) firstPoint) + 0x80);

        if (firstPoint == _ctlRegs[31])
            firstPoint = (uint32_t*) _ctlRegs[0];
        else
            firstPoint += 0x04;
    }
}

bool ADC14_enableReferenceBurst(void)
{
    if (ADCIsConversionRunning())
        return false;

    BITBAND_PERI(ADC14->rCTL1.r, ADC14REFBURST_OFS) = 1;

    return true;
}

bool ADC14_disableReferenceBurst(void)
{
    if (ADCIsConversionRunning())
        return false;

    BITBAND_PERI(ADC14->rCTL1.r, ADC14REFBURST_OFS) = 0;

    return true;
}

bool ADC14_setPowerMode(uint32_t adcPowerMode)
{
    if (ADCIsConversionRunning())
        return false;

    switch (adcPowerMode)
    {
    case ADC_UNRESTRICTED_POWER_MODE:
        ADC14->rCTL1.r = (ADC14->rCTL1.r & ~(ADC14PWRMD_M))
                | (ADC14PWRMD_0);
        break;
    case ADC_ULTRA_LOW_POWER_MODE:
        ADC14->rCTL1.r = (ADC14->rCTL1.r & ~(ADC14PWRMD_M))
                | (ADC14PWRMD_2);
        break;
    default:
        ASSERT(false);
        return false;
    }

    return true;
}

void ADC14_enableInterrupt(uint_fast64_t mask)
{
    uint32_t stat = mask & 0xFFFFFFFF;

    ADC14->rIER0.r |= stat;
    stat = (mask >> 32);
    ADC14->rIER1.r |= (stat);
}

void ADC14_disableInterrupt(uint_fast64_t mask)
{
    uint32_t stat = mask & 0xFFFFFFFF;

    ADC14->rIER0.r &= ~stat;
    stat = (mask >> 32);
    ADC14->rIER1.r &= ~(stat);
}

uint_fast64_t ADC14_getInterruptStatus(void)
{
    uint_fast64_t status = ADC14->rIFGR1.r;
    return ((status << 32) | ADC14->rIFGR0.r);
}

uint_fast64_t ADC14_getEnabledInterruptStatus(void)
{
    uint_fast64_t stat = ADC14->rIER1.r;

    return ADC14_getInterruptStatus() & ((stat << 32) | ADC14->rIER0.r);

}

void ADC14_clearInterruptFlag(uint_fast64_t mask)
{
    uint32_t stat = mask & 0xFFFFFFFF;

    ADC14->rCLRIFGR0.r |= stat;
    stat = (mask >> 32);
    ADC14->rCLRIFGR1.r |= (stat);
}

void ADC14_registerInterrupt(void (*intHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    Interrupt_registerInterrupt(INT_ADC14, intHandler);

    //
    // Enable the ADC interrupt.
    //
    Interrupt_enableInterrupt(INT_ADC14);
}

void ADC14_unregisterInterrupt(void)
{
    //
    // Disable the interrupt.
    //
    Interrupt_disableInterrupt(INT_ADC14);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregisterInterrupt(INT_ADC14);
}

