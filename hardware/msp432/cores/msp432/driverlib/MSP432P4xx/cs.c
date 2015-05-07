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
#include <cs.h>
#include <debug.h>
#include <sysctl.h>
#include <interrupt.h>

/* Statics */
static uint32_t hfxtFreq;
static uint32_t lfxtFreq;

#ifdef DEBUG

bool _CSIsClockDividerValid(uint8_t divider)
{
    return ((divider == CS_CLOCK_DIVIDER_1) || (divider == CS_CLOCK_DIVIDER_2)
            || (divider == CS_CLOCK_DIVIDER_4) || (divider == CS_CLOCK_DIVIDER_8)
            || (divider == CS_CLOCK_DIVIDER_16) || (divider == CS_CLOCK_DIVIDER_32)
            || (divider == CS_CLOCK_DIVIDER_64) || (divider == CS_CLOCK_DIVIDER_128));
}

#endif

static uint32_t _CSGetHFXTFrequency()
{
    if (hfxtFreq >= CS_1MHZ && hfxtFreq <= CS_4MHZ)
        return HFXTFREQ_0;
    else if (hfxtFreq > CS_4MHZ && hfxtFreq <= CS_8MHZ)
        return HFXTFREQ_1;
    else if (hfxtFreq > CS_8MHZ && hfxtFreq <= CS_16MHZ)
        return HFXTFREQ_2;
    else if (hfxtFreq > CS_16MHZ && hfxtFreq <= CS_24MHZ)
        return HFXTFREQ_3;
    else if (hfxtFreq > CS_24MHZ && hfxtFreq <= CS_32MHZ)
        return HFXTFREQ_4;
    else if (hfxtFreq > CS_32MHZ && hfxtFreq <= CS_40MHZ)
        return HFXTFREQ_5;
    else if (hfxtFreq > CS_40MHZ && hfxtFreq <= CS_48MHZ)
        return HFXTFREQ_5;
    else
    {
        ASSERT(false);
        return 0;
    }

}

static uint32_t _CSGetDividerValue(uint32_t wDivider)
{
    switch (wDivider)
    {
    case CS_CLOCK_DIVIDER_1:
        return 1;
    case CS_CLOCK_DIVIDER_2:
        return 2;
    case CS_CLOCK_DIVIDER_4:
        return 4;
    case CS_CLOCK_DIVIDER_8:
        return 8;
    case CS_CLOCK_DIVIDER_16:
        return 16;
    case CS_CLOCK_DIVIDER_32:
        return 32;
    case CS_CLOCK_DIVIDER_64:
        return 64;
    case CS_CLOCK_DIVIDER_128:
        return 128;
    default:
        ASSERT(false);
        return 1;
    }
}

static uint32_t _CSComputeCLKFrequency(uint32_t wClockSource, uint32_t wDivider)
{
    uint8_t bDivider;

    bDivider = _CSGetDividerValue(wDivider);

    switch (wClockSource)
    {
    case CS_LFXTCLK_SELECT:
    {
        if (BITBAND_PERI(CS->rIFG.r, LFXTIFG_OFS))
        {
            CS_clearInterruptFlag(CS_LFXT_FAULT);

            if (BITBAND_PERI(CS->rIFG.r, LFXTIFG_OFS))
            {
                if (BITBAND_PERI(CS->rCLKEN.r, REFOFSEL_OFS))
                    return (128000 / bDivider);
                else
                    return (32000 / bDivider);
            }
        }
        return lfxtFreq / bDivider;
    }
    case CS_HFXTCLK_SELECT:
    {
        if (BITBAND_PERI(CS->rIFG.r, HFXTIFG_OFS))
        {
            CS_clearInterruptFlag(CS_HFXT_FAULT);

            if (BITBAND_PERI(CS->rIFG.r, HFXTIFG_OFS))
            {
                if (BITBAND_PERI(CS->rCLKEN.r, REFOFSEL_OFS))
                    return (128000 / bDivider);
                else
                    return (32000 / bDivider);
            }
        }
        return hfxtFreq / bDivider;
    }
    case CS_VLOCLK_SELECT:
        return CS_VLOCLK_FREQUENCY / bDivider;
    case CS_REFOCLK_SELECT:
    {
        if (BITBAND_PERI(CS->rCLKEN.r, REFOFSEL_OFS))
            return (128000 / bDivider);
        else
            return (32000 / bDivider);
    }
    case CS_DCOCLK_SELECT:
        return (CS_getDCOFrequency() / bDivider);
    case CS_MODOSC_SELECT:
        return CS_MODCLK_FREQUENCY / bDivider;
    default:
        ASSERT(false);
        return 0;
    }
}

//******************************************************************************
// Internal function for getting DCO nominal frequency
//******************************************************************************
static uint32_t _CSGetDOCFrequency(void)
{
    uint32_t dcoFreq;

    switch (CS->rCTL0.r & DCORSEL_M)
    {
    case DCORSEL_0:
        dcoFreq = 1500000;
        break;
    case DCORSEL_1:
        dcoFreq = 3000000;
        break;
    case DCORSEL_2:
        dcoFreq = 6000000;
        break;
    case DCORSEL_3:
        dcoFreq = 12000000;
        break;
    case DCORSEL_4:
        dcoFreq = 24000000;
        break;
    case DCORSEL_5:
        dcoFreq = 48000000;
        break;
    default:
        dcoFreq = 0;
    }

    return (dcoFreq);
}

void CS_setExternalClockSourceFrequency(uint32_t lfxt_XT_CLK_frequency,
        uint32_t hfxt_XT_CLK_frequency)
{
    hfxtFreq = hfxt_XT_CLK_frequency;
    lfxtFreq = lfxt_XT_CLK_frequency;
}

void CS_initClockSignal(uint32_t selectedClockSignal, uint32_t clockSource,
        uint32_t clockSourceDivider)
{
    ASSERT(_CSIsClockDividerValid(clockSourceDivider));

    /* Unlocking the CS Module */
    CS->rKEY.r = CS_KEY;

    switch (selectedClockSignal)
    {
    case CS_ACLK:
    {
        /* Making sure that the clock signal for ACLK isn't set to anything
         * invalid
         */
        ASSERT(
                (selectedClockSignal != CS_DCOCLK_SELECT)
                && (selectedClockSignal != CS_MODOSC_SELECT)
                && (selectedClockSignal != CS_HFXTCLK_SELECT));

        /* Waiting for the clock source ready bit to be valid before
         * changing */
        while (!BITBAND_PERI(CS->rSTAT.r, ACLK_READY_OFS))
            ;

        /* Setting the divider and source */
        CS->rCTL1.r = ((clockSourceDivider >> CS_ACLK_DIV_BITPOS)
                | (clockSource << CS_ACLK_SRC_BITPOS))
                | (CS->rCTL1.r & ~(SELA_M | DIVA_M));

        /* Waiting for ACLK to be ready again */
        while (!BITBAND_PERI(CS->rSTAT.r, ACLK_READY_OFS))
            ;

        break;
    }
    case CS_MCLK:
    {

        /* Waiting for the clock source ready bit to be valid before
         * changing */
        while (!BITBAND_PERI(CS->rSTAT.r, MCLK_READY_OFS))
            ;

        CS->rCTL1.r = ((clockSourceDivider >> CS_MCLK_DIV_BITPOS)
                | (clockSource << CS_MCLK_SRC_BITPOS))
                | (CS->rCTL1.r & ~(SELM_M | DIVM_M));

        /* Waiting for MCLK to be ready */
        while (!BITBAND_PERI(CS->rSTAT.r, MCLK_READY_OFS))
            ;

        break;
    }
    case CS_SMCLK:
    {
        /* Waiting for the clock source ready bit to be valid before
         * changing */
        while (!BITBAND_PERI(CS->rSTAT.r, SMCLK_READY_OFS))
            ;

        CS->rCTL1.r = ((clockSourceDivider >> CS_SMCLK_DIV_BITPOS)
                | (clockSource << CS_HSMCLK_SRC_BITPOS))
                | (CS->rCTL1.r & ~(DIVS_M | SELS_M));

        /* Waiting for SMCLK to be ready */
        while (!BITBAND_PERI(CS->rSTAT.r, SMCLK_READY_OFS))
            ;

        break;
    }
    case CS_HSMCLK:
    {
        /* Waiting for the clock source ready bit to be valid before
         * changing */
        while (!BITBAND_PERI(CS->rSTAT.r, HSMCLK_READY_OFS))
            ;

        CS->rCTL1.r = ((clockSourceDivider >> CS_HSMCLK_DIV_BITPOS)
                | (clockSource << CS_HSMCLK_SRC_BITPOS))
                | (CS->rCTL1.r & ~(DIVHS_M | SELS_M));

        /* Waiting for HSMCLK to be ready */
        while (!BITBAND_PERI(CS->rSTAT.r, HSMCLK_READY_OFS))
            ;

        break;
    }
    case CS_BCLK:
    {

        /* Waiting for the clock source ready bit to be valid before
         * changing */
        while (!BITBAND_PERI(CS->rSTAT.r, BCLK_READY_OFS))
            ;

        /* Setting the clock source and then returning
         * (cannot divide CLK)
         */
        if (clockSource == CS_LFXTCLK_SELECT)
            BITBAND_PERI(CS->rCTL1.r, SELB_OFS) = 0;
        else if (clockSource == CS_REFOCLK_SELECT)
            BITBAND_PERI(CS->rCTL1.r, SELB_OFS) = 1;
        else
            ASSERT(false);

        /* Waiting for BCLK to be ready */
        while (!BITBAND_PERI(CS->rSTAT.r, BCLK_READY_OFS))
            ;

        break;
    }
    default:
    {
        /* Should never get here */
        ASSERT(false);
    }
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_startHFXT(bool bypassMode)
{
    CS_startHFXTWithTimeout(bypassMode, 0);
}

void CS_startHFXTWithTimeout(bool bypassMode, uint32_t timeout)
{
    uint32_t wHFFreqRange;
    uint8_t bNMIStatus;
    bool boolTimeout;

    /* Unlocking the CS Module */
    CS->rKEY.r = CS_KEY;

    /* Saving status and temporarily disabling NMIs for UCS faults */
    bNMIStatus = SysCtl_getNMISourceStatus() & SYSCTL_CS_SRC;
    SysCtl_disableNMISource(SYSCTL_CS_SRC);

    /* Determining which frequency range to use */
    wHFFreqRange = _CSGetHFXTFrequency();
    boolTimeout = (timeout == 0) ? false : true;

    /* Setting to maximum drive strength  */
    BITBAND_PERI(CS->rCTL2.r, HFXTDRIVE_OFS) = 1;
    CS->rCTL2.r = (CS->rCTL2.r & (~HFXTFREQ_M)) | (wHFFreqRange);

    if (bypassMode)
    {
        BITBAND_PERI(CS->rCTL2.r, HFXTBYPASS_OFS) = 1;
    } else
    {
        BITBAND_PERI(CS->rCTL2.r, HFXTBYPASS_OFS) = 0;
    }

    /* Starting and Waiting for frequency stabilization */
    BITBAND_PERI(CS->rCTL2.r, HFXT_EN_OFS) = 1;
    while (BITBAND_PERI(CS->rIFG.r, HFXTIFG_OFS))
    {
        if (boolTimeout && ((--timeout) == 0))
            break;

        BITBAND_PERI(CS->rCLRIFG.r,CLR_HFXTIFG_OFS) = 1;
    }

    /* Setting the drive strength */
    if (!bypassMode)
    {
        if (wHFFreqRange != HFXTFREQ_0)
            BITBAND_PERI(CS->rCTL2.r, HFXTDRIVE_OFS) = 1;
        else
            BITBAND_PERI(CS->rCTL2.r, HFXTDRIVE_OFS) = 0;
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;

    /* Enabling the NMI state */
    SysCtl_enableNMISource(bNMIStatus);

}

void CS_startLFXT(uint32_t xtDrive)
{
    CS_startLFXTWithTimeout(xtDrive, 0);
}

void CS_startLFXTWithTimeout(uint32_t xtDrive, uint32_t timeout)
{
    uint8_t bNMIStatus;
    bool boolBypassMode, boolTimeout;

    ASSERT(lfxtFreq != 0)
    ASSERT(
            (xtDrive == CS_LFXT_DRIVE0) || (xtDrive == CS_LFXT_DRIVE1)
            || (xtDrive == CS_LFXT_DRIVE2)
            || (xtDrive == CS_LFXT_DRIVE3)
            || (xtDrive == CS_LFXT_BYPASS));

    /* Unlocking the CS Module */
    CS->rKEY.r = CS_KEY;

    /* Saving status and temporarily disabling NMIs for UCS faults */
    bNMIStatus = SysCtl_getNMISourceStatus() & SYSCTL_CS_SRC;
    SysCtl_disableNMISource(SYSCTL_CS_SRC);
    boolBypassMode = (xtDrive == CS_LFXT_BYPASS) ? true : false;
    boolTimeout = (timeout == 0) ? false : true;

    /* Setting to maximum drive strength  */
    if (boolBypassMode)
    {
        BITBAND_PERI(CS->rCTL2.r, LFXTBYPASS_OFS) = 1;
    } else
    {
        CS->rCTL2.r |= (CS_LFXT_DRIVE3);
        BITBAND_PERI(CS->rCTL2.r, LFXTBYPASS_OFS) = 0;
    }

    /* Waiting for frequency stabilization */
    BITBAND_PERI(CS->rCTL2.r, LFXT_EN_OFS) = 1;

    while (BITBAND_PERI(CS->rIFG.r, LFXTIFG_OFS))
    {
        if (boolTimeout && ((--timeout) == 0))
            break;

        BITBAND_PERI(CS->rCLRIFG.r,CLR_LFXTIFG_OFS) = 1;
    }

    /* Setting the drive strength */
    if (!boolBypassMode)
    {
        CS->rCTL2.r = ((CS->rCTL2.r & ~CS_LFXT_DRIVE3) | xtDrive);
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;

    /* Enabling the NMI state */
    SysCtl_enableNMISource(bNMIStatus);
}

void CS_enableClockRequest(uint32_t selectClock)
{
    ASSERT(
            selectClock == CS_ACLK || selectClock == CS_HSMCLK
            || selectClock == CS_SMCLK || selectClock == CS_MCLK);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    CS->rCLKEN.r |= selectClock;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_disableClockRequest(uint32_t selectClock)
{
    ASSERT(
            selectClock == CS_ACLK || selectClock == CS_HSMCLK
            || selectClock == CS_SMCLK || selectClock == CS_MCLK);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    CS->rCLKEN.r &= ~selectClock;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_setReferenceOscillatorFrequency(uint8_t referenceFrequency)
{
    ASSERT(
            referenceFrequency == CS_REFO_32KHZ
            || referenceFrequency == CS_REFO_128KHZ);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    BITBAND_PERI(CS->rCLKEN.r, REFOFSEL_OFS) = referenceFrequency;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_enableDCOExternalResistor(void)
{
    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    BITBAND_PERI(CS->rCTL0.r,DCORES_OFS) = 1;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_setDCOExternalResistorCalibration(uint_fast8_t uiCalData)
{
    CS->rDCOERCAL.r = (uiCalData);
}

void CS_disableDCOExternalResistor(void)
{
    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    BITBAND_PERI(CS->rCTL0.r,DCORES_OFS) = 0;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_setDCOCenteredFrequency(uint32_t dcoFreq)
{
    ASSERT(
            dcoFreq == CS_DCO_FREQUENCY_1_5 || dcoFreq == CS_DCO_FREQUENCY_3
            || dcoFreq == CS_DCO_FREQUENCY_6
            || dcoFreq == CS_DCO_FREQUENCY_12
            || dcoFreq == CS_DCO_FREQUENCY_24
            || dcoFreq == CS_DCO_FREQUENCY_48);

    /* Unlocking the CS Module */
    CS->rKEY.r = CS_KEY;

    /* Resetting Tuning Parameters and Setting the frequency */
    CS->rCTL0.r = ((CS->rCTL0.r & ~DCORSEL_M) | dcoFreq);

    /* Locking the CS Module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_tuneDCOFrequency(int16_t tuneParameter)
{
    CS->rKEY.r = CS_KEY;

    if (tuneParameter < 0)
    {
         CS->rCTL0.r = ((CS->rCTL0.r & ~DCOTUNE_M) | (tuneParameter & DCOTUNE_M)
                 | 0x1000);
    } 
    else
    {
        CS->rCTL0.r =
                ((CS->rCTL0.r & ~DCOTUNE_M) | (tuneParameter & DCOTUNE_M));

    }
     
     BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

uint32_t CS_getDCOFrequency(void)
{
    float dcoConst;
    int32_t calVal;
    uint32_t centeredFreq;
    int16_t dcoTune;

    dcoTune = CS->rCTL0.b.bDCOTUNE;
    centeredFreq = _CSGetDOCFrequency();

    if (dcoTune == 0)
        return (uint32_t) centeredFreq;

    /* Checking to see if we need to do signed conversion */
    if (dcoTune & 0x1000)
    {
        dcoTune = dcoTune | 0xF000;
    }
    
    /* DCORSEL = 5, in final silicon this will have a different calibration
        value, but currently DCORSEL5 calibration is not populated 
    if (centeredFreq == 48000000)
    {
         External Resistor 
        if (BITBAND_PERI(CS->rCTL0.r, DCORES_OFS))
        {
            dcoConst = *((float *) &TLV->rDCOER_CONSTK_RSEL5);
            calVal = TLV->rDCOER_FCAL_RSEL5;
        }
        Internal Resistor 
        else
        {
            dcoConst = *((float *) &TLV->rDCOIR_CONSTK_RSEL5);
            calVal = TLV->rDCOIR_FCAL_RSEL5;
        }
    }
     DCORSEL = 4 
    else
    {*/
        /* External Resistor */
        if (BITBAND_PERI(CS->rCTL0.r, DCORES_OFS))
        {
            dcoConst = *((float *) &TLV->rDCOER_CONSTK_RSEL04);
            calVal = TLV->rDCOER_FCAL_RSEL04;
        }
        /* Internal Resistor */
        else
        {
            dcoConst = *((float *) &TLV->rDCOIR_CONSTK_RSEL04);
            calVal = TLV->rDCOIR_FCAL_RSEL04;
        }
    /*}*/

    return (uint32_t) ((centeredFreq)
            / (1
                    - ((dcoConst * dcoTune)
                            / (8 * (1 + dcoConst * (768 - calVal))))));
}

void CS_setDCOFrequency(uint32_t dcoFrequency)
{
    int32_t nomFreq, calVal, dcoSigned;
    int16_t dcoTune;
    float dcoConst;
 // bool rsel5 = false;
    dcoSigned = (int32_t) dcoFrequency;

    if (dcoFrequency < 2000000)
    {
        nomFreq = CS_15MHZ;
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_1_5);
    } else if (dcoFrequency < 4000000)
    {
        nomFreq = CS_3MHZ;
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_3);
    } else if (dcoFrequency < 8000000)
    {
        nomFreq = CS_6MHZ;
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_6);
    } else if (dcoFrequency < 16000000)
    {
        nomFreq = CS_12MHZ;
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);
    } else if (dcoFrequency < 32000000)
    {
        nomFreq = CS_24MHZ;
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);
    } else if (dcoFrequency < 640000001)
    {
        nomFreq = CS_48MHZ;
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
      //  rsel5 = true;
    } else
    {
        ASSERT(false);
        return;
    }
    
    if(dcoFrequency == nomFreq)
    {
       CS_tuneDCOFrequency(0);
       return;
    }

    /* DCORSEL = 5, in final silicon this will have a different calibration
        value, but currently DCORSEL5 calibration is not populated 
    if (rsel5)
    {
        External Resistor 
        if (BITBAND_PERI(CS->rCTL0.r, DCORES_OFS))
        {
            dcoConst = *((float *) &TLV->rDCOER_CONSTK_RSEL5);
            calVal = TLV->rDCOER_FCAL_RSEL5;
        }
        Internal Resistor
        else
        {
            dcoConst = *((float *) &TLV->rDCOIR_CONSTK_RSEL5);
            calVal = TLV->rDCOIR_FCAL_RSEL5;
        }
    }
    DCORSEL = 4
    else
    {*/
        /* External Resistor */
        if (BITBAND_PERI(CS->rCTL0.r, DCORES_OFS))
        {
            dcoConst = *((float *) &TLV->rDCOER_CONSTK_RSEL04);
            calVal = TLV->rDCOER_FCAL_RSEL04;
        }
        /* Internal Resistor */
        else
        {
            dcoConst = *((float *) &TLV->rDCOIR_CONSTK_RSEL04);
            calVal = TLV->rDCOIR_FCAL_RSEL04;
        }
    /*}*/

    dcoTune = (int16_t) (((dcoSigned - nomFreq)
            * (1.0 + dcoConst * (768.0 - calVal)) * 8.0)
            / (dcoSigned * dcoConst));

    CS_tuneDCOFrequency(dcoTune);

}

uint32_t CS_getBCLK(void)
{
    if (BITBAND_PERI(CS->rCTL1.r, SELB_OFS))
        return _CSComputeCLKFrequency(CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    else
        return _CSComputeCLKFrequency(CS_LFXTCLK_SELECT, CS_CLOCK_DIVIDER_1);
}

uint32_t CS_getHSMCLK(void)
{
    uint32_t wSource, wDivider;

    wSource = (CS->rCTL1.r & SELS_M) >> CS_HSMCLK_SRC_BITPOS;
    wDivider = ((CS->rCTL1.r & DIVHS_M) << CS_HSMCLK_DIV_BITPOS);

    return _CSComputeCLKFrequency(wSource, wDivider);
}

uint32_t CS_getACLK(void)
{
    uint32_t wSource, wDivider;

    wSource = (CS->rCTL1.r & SELA_M) >> CS_ACLK_SRC_BITPOS;
    wDivider = ((CS->rCTL1.r & DIVA_M) << CS_ACLK_DIV_BITPOS);

    return _CSComputeCLKFrequency(wSource, wDivider);
}

uint32_t CS_getSMCLK(void)
{
    uint32_t wDivider, wSource;

    wSource = (CS->rCTL1.r & SELS_M) >> CS_HSMCLK_SRC_BITPOS;
    wDivider = ((CS->rCTL1.r & DIVS_M));

    return _CSComputeCLKFrequency(wSource, wDivider);

}

uint32_t CS_getMCLK(void)
{
    uint32_t wSource, wDivider;

    wSource = (CS->rCTL1.r & SELM_M) << CS_MCLK_SRC_BITPOS;
    wDivider = ((CS->rCTL1.r & DIVM_M) << CS_MCLK_DIV_BITPOS);

    return _CSComputeCLKFrequency(wSource, wDivider);
}

void CS_enableFaultCounter(uint_fast8_t counterSelect)
{
    ASSERT(counterSelect == CS_HFXT_FAULT_COUNTER ||
            counterSelect == CS_HFXT_FAULT_COUNTER);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    if (counterSelect == CS_HFXT_FAULT_COUNTER)
    {
        BITBAND_PERI(CS->rCTL3.r, FCNTHF_EN_OFS) = 1;
    } else
    {
        BITBAND_PERI(CS->rCTL3.r, FCNTLF_EN_OFS) = 1;
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_disableFaultCounter(uint_fast8_t counterSelect)
{
    ASSERT(counterSelect == CS_HFXT_FAULT_COUNTER ||
            counterSelect == CS_HFXT_FAULT_COUNTER);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    if (counterSelect == CS_HFXT_FAULT_COUNTER)
    {
        BITBAND_PERI(CS->rCTL3.r, FCNTHF_EN_OFS) = 0;
    } else
    {
        BITBAND_PERI(CS->rCTL3.r, FCNTLF_EN_OFS) = 0;
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_resetFaultCounter(uint_fast8_t counterSelect)
{
    ASSERT(counterSelect == CS_HFXT_FAULT_COUNTER ||
            counterSelect == CS_HFXT_FAULT_COUNTER);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    if (counterSelect == CS_HFXT_FAULT_COUNTER)
    {
        BITBAND_PERI(CS->rCTL3.r, RFCNTHF_OFS) = 1;
    } else
    {
        BITBAND_PERI(CS->rCTL3.r, RFCNTLF_OFS) = 1;
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_startFaultCounter(uint_fast8_t counterSelect, uint_fast8_t countValue)
{
    ASSERT(counterSelect == CS_HFXT_FAULT_COUNTER ||
            counterSelect == CS_HFXT_FAULT_COUNTER);

    ASSERT(countValue == CS_FAULT_COUNTER_4096_CYCLES ||
            countValue == CS_FAULT_COUNTER_8192_CYCLES ||
            countValue == CS_FAULT_COUNTER_16384_CYCLES ||
            countValue == CS_FAULT_COUNTER_32768_CYCLES);

    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    if (counterSelect == CS_HFXT_FAULT_COUNTER)
    {
        CS->rCTL3.r = ((CS->rCTL3.r & ~FCNTHF_M) | (countValue << 4));
    } else
    {
        CS->rCTL3.r = ((CS->rCTL3.r & ~FCNTLF_M) | (countValue));
    }

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_enableInterrupt(uint32_t flags)
{
    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    CS->rIE.r |= flags;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_disableInterrupt(uint32_t flags)
{
    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    CS->rIE.r &= ~flags;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

uint32_t CS_getInterruptStatus(void)
{
    return CS->rIFG.r;
}

uint32_t CS_getEnabledInterruptStatus(void)
{
    return CS_getInterruptStatus() & CS->rIE.r;
}

void CS_clearInterruptFlag(uint32_t flags)
{
    /* Unlocking the module */
    CS->rKEY.r = CS_KEY;

    CS->rCLRIFG.r |= flags;

    /* Locking the module */
    BITBAND_PERI(CS->rKEY.r, CSKEY_OFS) = 1;
}

void CS_registerInterrupt(void (*intHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    Interrupt_registerInterrupt(INT_CS, intHandler);

    //
    // Enable the system control interrupt.
    //
    Interrupt_enableInterrupt(INT_CS);
}

void CS_unregisterInterrupt(void)
{
    //
    // Disable the interrupt.
    //
    Interrupt_disableInterrupt(INT_CS);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregisterInterrupt(INT_CS);
}

