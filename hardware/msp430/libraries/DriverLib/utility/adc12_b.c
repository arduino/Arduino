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
// adc12_b.c - Driver for the adc12_b Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup adc12_b_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_ADC12_B__
#include "adc12_b.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Initializes the ADC12B Module.
//!
//! This function initializes the ADC module to allow for analog-to-digital
//! conversions. Specifically this function sets up the sample-and-hold signal
//! and clock sources for the ADC core to use for conversions. Upon successful
//! completion of the initialization all of the ADC control registers will be
//! reset, excluding the memory controls and reference module bits, the given
//! parameters will be set, and the ADC core will be turned on (Note, that the
//! ADC core only draws power during conversions and remains off when not
//! converting).Note that sample/hold signal sources are device dependent. Note
//! that if re-initializing the ADC after starting a conversion with the
//! startConversion() function, the disableConversion() must be called BEFORE
//! this function can be called.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param sampleHoldSignalSourceSelect is the signal that will trigger a
//!        sample-and-hold for an input signal to be converted.
//!        Valid values are:
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_SC [Default]
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_1
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_2
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_3
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_4
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_5
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_6
//!        - \b ADC12_B_SAMPLEHOLDSOURCE_7 - This parameter is device specific
//!           and sources should be found in the device's datasheet.
//!        \n Modified bits are \b ADC12SHSx of \b ADC12CTL1 register.
//! \param clockSourceSelect selects the clock that will be used by the ADC12B
//!        core, and the sampling timer if a sampling pulse mode is enabled.
//!        Valid values are:
//!        - \b ADC12_B_CLOCKSOURCE_ADC12OSC [Default] - MODOSC 5 MHz
//!           oscillator from the UCS
//!        - \b ADC12_B_CLOCKSOURCE_ACLK - The Auxiliary Clock
//!        - \b ADC12_B_CLOCKSOURCE_MCLK - The Master Clock
//!        - \b ADC12_B_CLOCKSOURCE_SMCLK - The Sub-Master Clock
//!        \n Modified bits are \b ADC12SSELx of \b ADC12CTL1 register.
//! \param clockSourceDivider selects the amount that the clock will be
//!        divided.
//!        Valid values are:
//!        - \b ADC12_B_CLOCKDIVIDER_1 [Default]
//!        - \b ADC12_B_CLOCKDIVIDER_2
//!        - \b ADC12_B_CLOCKDIVIDER_3
//!        - \b ADC12_B_CLOCKDIVIDER_4
//!        - \b ADC12_B_CLOCKDIVIDER_5
//!        - \b ADC12_B_CLOCKDIVIDER_6
//!        - \b ADC12_B_CLOCKDIVIDER_7
//!        - \b ADC12_B_CLOCKDIVIDER_8
//!        \n Modified bits are \b ADC12DIVx of \b ADC12CTL1 register.
//! \param clockSourcePredivider selects the amount that the clock will be
//!        predivided.
//!        Valid values are:
//!        - \b ADC12_B_CLOCKPREDIVIDER__1 [Default]
//!        - \b ADC12_B_CLOCKPREDIVIDER__4
//!        - \b ADC12_B_CLOCKPREDIVIDER__32
//!        - \b ADC12_B_CLOCKPREDIVIDER__64
//!        \n Modified bits are \b ADC12PDIV of \b ADC12CTL1 register.
//! \param internalChannelMap selects what internal channel to map for ADC
//!        input channels
//!        Valid values are:
//!        - \b ADC12_B_MAPINTCH3
//!        - \b ADC12_B_MAPINTCH2
//!        - \b ADC12_B_MAPINTCH1
//!        - \b ADC12_B_MAPINTCH0
//!        - \b ADC12_B_TEMPSENSEMAP
//!        - \b ADC12_B_BATTMAP
//!        - \b ADC12_B_NOINTCH
//!        \n Modified bits of \b ADC12CTL3 register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the initialization process.
//
//*****************************************************************************
bool ADC12_B_init(uint32_t baseAddress,
                  uint16_t sampleHoldSignalSourceSelect,
                  uint8_t clockSourceSelect,
                  uint16_t clockSourceDivider,
                  uint16_t clockSourcePredivider,
                  uint16_t internalChannelMap)
{

        assert(sampleHoldSignalSourceSelect <= ADC12_B_SAMPLEHOLDSOURCE_3);
        assert(clockSourceSelect <= ADC12_B_CLOCKSOURCE_SMCLK);
        assert(clockSourceDivider <= ADC12_B_CLOCKDIVIDER_8);
        assert(internalChannelMap <= ADC12_B_BATTMAP);
        assert((clockSourcePredivider == ADC12_B_CLOCKPREDIVIDER__1) ||
               (clockSourcePredivider == ADC12_B_CLOCKPREDIVIDER__4) ||
               (clockSourcePredivider == ADC12_B_CLOCKPREDIVIDER__32) ||
               (clockSourcePredivider == ADC12_B_CLOCKPREDIVIDER__64)
               );

        //Make sure the ENC bit is cleared before initializing the ADC12
        HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ENC;

        bool retVal = STATUS_SUCCESS;

        //Turn OFF ADC12B Module & Clear Interrupt Registers
        HWREG16(baseAddress + OFS_ADC12CTL0) &= ~(ADC12ON + ADC12ENC + ADC12SC);
        HWREG16(baseAddress + OFS_ADC12IER0)  &= 0x0000; //Reset ALL interrupt enables
        HWREG16(baseAddress + OFS_ADC12IER1)  &= 0x0000;
        HWREG16(baseAddress + OFS_ADC12IER2)  &= 0x0000;
        HWREG16(baseAddress + OFS_ADC12IFGR0)  &= 0x0000; //Reset ALL interrupt flags
        HWREG16(baseAddress + OFS_ADC12IFGR1)  &= 0x0000;
        HWREG16(baseAddress + OFS_ADC12IFGR2)  &= 0x0000;

        //Set ADC12B Control 1
        HWREG16(baseAddress + OFS_ADC12CTL1) =
                sampleHoldSignalSourceSelect            //Setup the Sample-and-Hold Source
                + (clockSourceDivider & ADC12DIV_7)     //Set Clock Divider
                + (clockSourcePredivider & ADC12PDIV__64)
                + clockSourceSelect;                    //Setup Clock Source

        //Set ADC12B Control 2
        HWREG16(baseAddress + OFS_ADC12CTL2) =
                ADC12RES_2; //Default resolution to 12-bits

        //Set ADC12B Control 3
        HWREG16(baseAddress + OFS_ADC12CTL3) =
                internalChannelMap; // Map internal channels

        return retVal;
}

//*****************************************************************************
//
//! \brief Enables the ADC12B block.
//!
//! This will enable operation of the ADC12B block.
//!
//! \param baseAddress is the base address of the ADC12B module.
//!
//! Modified bits are \b ADC12ON of \b ADC12CTL0 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_enable(uint32_t baseAddress)
{
        // Clear ENC bit
        HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ENC;

        //Enable the ADC12B Module
        HWREG8(baseAddress + OFS_ADC12CTL0_L) |= ADC12ON;
}

//*****************************************************************************
//
//! \brief Disables the ADC12B block.
//!
//! This will disable operation of the ADC12B block.
//!
//! \param baseAddress is the base address of the ADC12B module.
//!
//! Modified bits are \b ADC12ON of \b ADC12CTL0 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_disable(uint32_t baseAddress)
{
        // Clear ENC bit
        HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ENC;

        //Disable ADC12B module
        HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ON;
}

//*****************************************************************************
//
//! \brief Sets up and enables the Sampling Timer Pulse Mode.
//!
//! This function sets up the sampling timer pulse mode which allows the
//! sample/hold signal to trigger a sampling timer to sample-and-hold an input
//! signal for a specified number of clock cycles without having to hold the
//! sample/hold signal for the entire period of sampling. Note that if a
//! conversion has been started with the startConversion() function, then a
//! call to disableConversions() is required before this function may be
//! called.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param clockCycleHoldCountLowMem sets the amount of clock cycles to sample-
//!        and-hold for the higher memory buffers 0-7.
//!        Valid values are:
//!        - \b ADC12_B_CYCLEHOLD_4_CYCLES [Default]
//!        - \b ADC12_B_CYCLEHOLD_8_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_16_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_32_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_64_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_96_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_128_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_192_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_256_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_384_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_512_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_768_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_1024_CYCLES
//!        \n Modified bits are \b ADC12SHT0x of \b ADC12CTL0 register.
//! \param clockCycleHoldCountHighMem sets the amount of clock cycles to
//!        sample-and-hold for the higher memory buffers 8-15.
//!        Valid values are:
//!        - \b ADC12_B_CYCLEHOLD_4_CYCLES [Default]
//!        - \b ADC12_B_CYCLEHOLD_8_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_16_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_32_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_64_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_96_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_128_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_192_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_256_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_384_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_512_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_768_CYCLES
//!        - \b ADC12_B_CYCLEHOLD_1024_CYCLES
//!        \n Modified bits are \b ADC12SHT1x of \b ADC12CTL0 register.
//! \param multipleSamplesEnabled allows multiple conversions to start without
//!        a trigger signal from the sample/hold signal
//!        Valid values are:
//!        - \b ADC12_B_MULTIPLESAMPLESDISABLE [Default] - a timer trigger will
//!           be needed to start every ADC conversion.
//!        - \b ADC12_B_MULTIPLESAMPLESENABLE - during a sequenced and/or
//!           repeated conversion mode, after the first conversion, no
//!           sample/hold signal is necessary to start subsequent sample/hold
//!           and convert processes.
//!        \n Modified bits are \b ADC12MSC of \b ADC12CTL0 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_setupSamplingTimer(uint32_t baseAddress,
                                uint16_t clockCycleHoldCountLowMem,
                                uint16_t clockCycleHoldCountHighMem,
                                uint16_t multipleSamplesEnabled)
{
        //Make sure the ENC bit is cleared before setting up sampling pulse mode
        assert( !(HWREG8(baseAddress + OFS_ADC12CTL0_L) & ADC12ENC) );

        assert(clockCycleHoldCountLowMem <= ADC12_B_CYCLEHOLD_1024_CYCLES);
        assert(clockCycleHoldCountHighMem <= ADC12_B_CYCLEHOLD_1024_CYCLES);

        HWREG16(baseAddress + OFS_ADC12CTL1) |= ADC12SHP;

        //Reset clock cycle hold counts and msc bit before setting them
        HWREG16(baseAddress + OFS_ADC12CTL0) &=
                ~(ADC12SHT0_15 + ADC12SHT1_15 + ADC12MSC);

        //Set clock cycle hold counts and msc bit
        HWREG16(baseAddress + OFS_ADC12CTL0) |= clockCycleHoldCountLowMem
                                                + (clockCycleHoldCountHighMem << 4)
                                                + multipleSamplesEnabled;
}

//*****************************************************************************
//
//! \brief Disables Sampling Timer Pulse Mode.
//!
//! Disables the Sampling Timer Pulse Mode. Note that if a conversion has been
//! started with the startConversion() function, then a call to
//! disableConversions() is required before this function may be called.
//!
//! \param baseAddress is the base address of the ADC12B module.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_disableSamplingTimer(uint32_t baseAddress)
{
        //Make sure the ENC bit is cleared before disabling sampling pulse mode
        assert( !(HWREG8(baseAddress + OFS_ADC12CTL0_L) & ADC12ENC) );

        HWREG16(baseAddress + OFS_ADC12CTL1) &= ~(ADC12SHP);
}

//*****************************************************************************
//
//! \brief Configures the controls of the selected memory buffer.
//!
//! Maps an input signal conversion into the selected memory buffer, as well as
//! the positive and negative reference voltages for each conversion being
//! stored into this memory buffer. If the internal reference is used for the
//! positive reference voltage, the internal REF module must be used to control
//! the voltage level. Note that if a conversion has been started with the
//! startConversion() function, then a call to disableConversions() is required
//! before this function may be called.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param memoryBufferControlIndex is the selected memory buffer to set the
//!        configuration for.
//!        Valid values are:
//!        - \b ADC12_B_MEMORY_0
//!        - \b ADC12_B_MEMORY_1
//!        - \b ADC12_B_MEMORY_2
//!        - \b ADC12_B_MEMORY_3
//!        - \b ADC12_B_MEMORY_4
//!        - \b ADC12_B_MEMORY_5
//!        - \b ADC12_B_MEMORY_6
//!        - \b ADC12_B_MEMORY_7
//!        - \b ADC12_B_MEMORY_8
//!        - \b ADC12_B_MEMORY_9
//!        - \b ADC12_B_MEMORY_10
//!        - \b ADC12_B_MEMORY_11
//!        - \b ADC12_B_MEMORY_12
//!        - \b ADC12_B_MEMORY_13
//!        - \b ADC12_B_MEMORY_14
//!        - \b ADC12_B_MEMORY_15
//!        - \b ADC12_B_MEMORY_16
//!        - \b ADC12_B_MEMORY_17
//!        - \b ADC12_B_MEMORY_18
//!        - \b ADC12_B_MEMORY_19
//!        - \b ADC12_B_MEMORY_20
//!        - \b ADC12_B_MEMORY_21
//!        - \b ADC12_B_MEMORY_22
//!        - \b ADC12_B_MEMORY_23
//!        - \b ADC12_B_MEMORY_24
//!        - \b ADC12_B_MEMORY_25
//!        - \b ADC12_B_MEMORY_26
//!        - \b ADC12_B_MEMORY_27
//!        - \b ADC12_B_MEMORY_28
//!        - \b ADC12_B_MEMORY_29
//!        - \b ADC12_B_MEMORY_30
//!        - \b ADC12_B_MEMORY_31
//! \param inputSourceSelect is the input that will store the converted data
//!        into the specified memory buffer.
//!        Valid values are:
//!        - \b ADC12_B_INPUT_A0 [Default]
//!        - \b ADC12_B_INPUT_A1
//!        - \b ADC12_B_INPUT_A2
//!        - \b ADC12_B_INPUT_A3
//!        - \b ADC12_B_INPUT_A4
//!        - \b ADC12_B_INPUT_A5
//!        - \b ADC12_B_INPUT_A6
//!        - \b ADC12_B_INPUT_A7
//!        - \b ADC12_B_INPUT_A8
//!        - \b ADC12_B_INPUT_A9
//!        - \b ADC12_B_INPUT_A10
//!        - \b ADC12_B_INPUT_A11
//!        - \b ADC12_B_INPUT_A12
//!        - \b ADC12_B_INPUT_A13
//!        - \b ADC12_B_INPUT_A14
//!        - \b ADC12_B_INPUT_A15
//!        - \b ADC12_B_INPUT_A16
//!        - \b ADC12_B_INPUT_A17
//!        - \b ADC12_B_INPUT_A18
//!        - \b ADC12_B_INPUT_A19
//!        - \b ADC12_B_INPUT_A20
//!        - \b ADC12_B_INPUT_A21
//!        - \b ADC12_B_INPUT_A22
//!        - \b ADC12_B_INPUT_A23
//!        - \b ADC12_B_INPUT_A24
//!        - \b ADC12_B_INPUT_A25
//!        - \b ADC12_B_INPUT_A26
//!        - \b ADC12_B_INPUT_A27
//!        - \b ADC12_B_INPUT_A28
//!        - \b ADC12_B_INPUT_A29
//!        - \b ADC12_B_INPUT_TCMAP
//!        - \b ADC12_B_INPUT_BATMAP
//!        \n Modified bits are \b ADC12INCHx of \b ADC12MCTLx register.
//! \param refVoltageSourceSelect is the reference voltage source to set as the
//!        upper/lower limits for the conversion stored in the specified
//!        memory.
//!        Valid values are:
//!        - \b ADC12_B_VREFPOS_AVCC_VREFNEG_VSS [Default]
//!        - \b ADC12_B_VREFPOS_INTBUF_VREFNEG_VSS
//!        - \b ADC12_B_VREFPOS_EXTNEG_VREFNEG_VSS
//!        - \b ADC12_B_VREFPOS_EXTBUF_VREFNEG_VSS
//!        - \b ADC12_B_VREFPOS_EXTPOS_VREFNEG_VSS
//!        - \b ADC12_B_VREFPOS_AVCC_VREFNEG_EXTBUF
//!        - \b ADC12_B_VREFPOS_AVCC_VREFNEG_EXTPOS
//!        - \b ADC12_B_VREFPOS_INTBUF_VREFNEG_EXTPOS
//!        - \b ADC12_B_VREFPOS_AVCC_VREFNEG_INTBUF
//!        - \b ADC12_B_VREFPOS_EXTPOS_VREFNEG_INTBUF
//!        - \b ADC12_B_VREFPOS_AVCC_VREFNEG_EXTNEG
//!        - \b ADC12_B_VREFPOS_INTBUF_VREFNEG_EXTNEG
//!        - \b ADC12_B_VREFPOS_EXTPOS_VREFNEG_EXTNEG
//!        - \b ADC12_B_VREFPOS_EXTBUF_VREFNEG_EXTNEG
//!        \n Modified bits are \b ADC12VRSEL of \b ADC12MCTLx register.
//! \param endOfSequence indicates that the specified memory buffer will be the
//!        end of the sequence if a sequenced conversion mode is selected
//!        Valid values are:
//!        - \b ADC12_B_NOTENDOFSEQUENCE [Default] - The specified memory
//!           buffer will NOT be the end of the sequence OR a sequenced
//!           conversion mode is not selected.
//!        - \b ADC12_B_ENDOFSEQUENCE - The specified memory buffer will be the
//!           end of the sequence.
//!        \n Modified bits are \b ADC12EOS of \b ADC12MCTLx register.
//! \param windowComparatorSelect sets the window comparator mode
//!        Valid values are:
//!        - \b ADC12_B_WINDOW_COMPARATOR_DISABLE [Default]
//!        - \b ADC12_B_WINDOW_COMPARATOR_ENABLE
//! \param differentialModeSelect sets the differential mode
//!        Valid values are:
//!        - \b ADC12_B_DIFFERENTIAL_MODE_DISABLE [Default]
//!        - \b ADC12_B_DIFFERENTIAL_MODE_ENABLE
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_memoryConfigure(uint32_t baseAddress,
                             uint8_t memoryBufferControlIndex,
                             uint8_t inputSourceSelect,
                             uint16_t refVoltageSourceSelect,
                             uint16_t endOfSequence,
                             uint16_t windowComparatorSelect,
                             uint16_t differentialModeSelect
                             )
{
        //Make sure the ENC bit is cleared before configuring a Memory Buffer Control
        assert( !(HWREG8(baseAddress + OFS_ADC12CTL0_L) & ADC12ENC) );

        assert(inputSourceSelect <= ADC12_B_INPUT_BATMAP);
        assert(refVoltageSourceSelect <= ADC12_B_VREFPOS_EXTBUF_VREFNEG_EXTNEG);

        assert(
                (ADC12_B_MEMORY_0 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_1 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_2 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_3 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_4 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_5 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_6 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_7 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_8 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_9 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_10 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_11 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_12 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_13 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_14 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_15 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_16 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_17 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_18 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_19 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_20 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_21 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_22 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_23 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_24 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_25 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_26 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_27 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_28 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_29 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_30 == memoryBufferControlIndex) ||
                (ADC12_B_MEMORY_31 == memoryBufferControlIndex)
                );

        //Set the offset in respect to ADC12MCTL0
        uint16_t memoryBufferControlOffset =
                (OFS_ADC12MCTL0 + memoryBufferControlIndex);

        //Reset the memory buffer control and Set the input source
        HWREG16(baseAddress + memoryBufferControlOffset) =
                inputSourceSelect               //Set Input Source
                + refVoltageSourceSelect        //Set Vref+/-
                + endOfSequence;                //Set End of Sequence

        HWREG16(baseAddress + memoryBufferControlOffset)
                &= ~(ADC12WINC);

        HWREG16(baseAddress + memoryBufferControlOffset)
                |= windowComparatorSelect;
        //(OFS_ADC12MCTL0_H + memoryIndex) == offset of OFS_ADC12MCTLX_H

        HWREG16(baseAddress + memoryBufferControlOffset)
                &= ~(ADC12DIF);

        HWREG16(baseAddress + memoryBufferControlOffset)
                |= differentialModeSelect;
        //(OFS_ADC12MCTL0_H + memoryIndex) == offset of OFS_ADC12MCTLX_H
}

//*****************************************************************************
//
//! \brief Sets the high and low threshold for the window comparator feature.
//!
//! Sets the high and low threshold for the window comparator feature. Use the
//! ADC12HIIE, ADC12INIE, ADC12LOIE interrupts to utilize this feature.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param highThreshold is the upper bound that could trip an interrupt for
//!        the window comparator.
//! \param lowThreshold is the lower bound that could trip on interrupt for the
//!        window comparator.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_setWindowCompAdvanced(uint32_t baseAddress,
                                   uint16_t highThreshold,
                                   uint16_t lowThreshold)
{
        HWREG16(baseAddress + OFS_ADC12HI) = highThreshold;
        HWREG16(baseAddress + OFS_ADC12LO) = lowThreshold;
}

//*****************************************************************************
//
//! \brief Enables selected ADC12B interrupt sources.
//!
//! Enables the indicated ADC12B interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor. <b>Does not clear interrupt flags.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param interruptMask0 is the bit mask of the memory buffer and overflow
//!        interrupt sources to be enabled. If the desired interrupt is not
//!        available in the selection for interruptMask0, then simply pass in a
//!        '0' for this value.
//!        Valid values are:
//!        - \b ADC12_B_IE0
//!        - \b ADC12_B_IE1
//!        - \b ADC12_B_IE2
//!        - \b ADC12_B_IE3
//!        - \b ADC12_B_IE4
//!        - \b ADC12_B_IE5
//!        - \b ADC12_B_IE6
//!        - \b ADC12_B_IE7
//!        - \b ADC12_B_IE8
//!        - \b ADC12_B_IE9
//!        - \b ADC12_B_IE10
//!        - \b ADC12_B_IE11
//!        - \b ADC12_B_IE12
//!        - \b ADC12_B_IE13
//!        - \b ADC12_B_IE14
//!        - \b ADC12_B_IE15
//! \param interruptMask1 is the bit mask of the memory buffer and overflow
//!        interrupt sources to be enabled. If the desired interrupt is not
//!        available in the selection for interruptMask1, then simply pass in a
//!        '0' for this value.
//!        Valid values are:
//!        - \b ADC12_B_IE16
//!        - \b ADC12_B_IE17
//!        - \b ADC12_B_IE18
//!        - \b ADC12_B_IE19
//!        - \b ADC12_B_IE20
//!        - \b ADC12_B_IE21
//!        - \b ADC12_B_IE22
//!        - \b ADC12_B_IE23
//!        - \b ADC12_B_IE24
//!        - \b ADC12_B_IE25
//!        - \b ADC12_B_IE26
//!        - \b ADC12_B_IE27
//!        - \b ADC12_B_IE28
//!        - \b ADC12_B_IE29
//!        - \b ADC12_B_IE30
//!        - \b ADC12_B_IE31
//! \param interruptMask2 is the bit mask of the memory buffer and overflow
//!        interrupt sources to be enabled. If the desired interrupt is not
//!        available in the selection for interruptMask2, then simply pass in a
//!        '0' for this value.
//!        Valid values are:
//!        - \b ADC12_B_INIE - Interrupt enable for a conversion in the result
//!           register is either greater than the ADC12LO or lower than the
//!           ADC12HI threshold. GIE bit must be set to enable the interrupt.
//!        - \b ADC12_B_LOIE - Interrupt enable for the falling short of the
//!           lower limit interrupt of the window comparator for the result
//!           register. GIE bit must be set to enable the interrupt.
//!        - \b ADC12_B_HIIE - Interrupt enable for the exceeding the upper
//!           limit of the window comparator for the result register. GIE bit
//!           must be set to enable the interrupt.
//!        - \b ADC12_B_OVIE - Interrupt enable for a conversion that is about
//!           to save to a memory buffer that has not been read out yet. GIE
//!           bit must be set to enable the interrupt.
//!        - \b ADC12_B_TOVIE - enable for a conversion that is about to start
//!           before the previous conversion has been completed. GIE bit must
//!           be set to enable the interrupt.
//!        - \b ADC12_B_RDYIE - enable for the local buffered reference ready
//!           signal. GIE bit must be set to enable the interrupt.
//!
//! Modified bits of \b ADC12IERx register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_enableInterrupt(uint32_t baseAddress,
                             uint16_t interruptMask0,
                             uint16_t interruptMask1,
                             uint16_t interruptMask2)
{
        assert(interruptMask2 <= (
                       ADC12_B_INIE + ADC12_B_LOIE + ADC12_B_HIIE + ADC12_B_OVIE
                       + ADC12_B_TOVIE + ADC12_B_RDYIE
                       ));

        HWREG16(baseAddress + OFS_ADC12IER0) |= interruptMask0;
        HWREG16(baseAddress + OFS_ADC12IER1) |= interruptMask1;
        HWREG16(baseAddress + OFS_ADC12IER2) |= interruptMask2;
}

//*****************************************************************************
//
//! \brief Disables selected ADC12B interrupt sources.
//!
//! Disables the indicated ADC12B interrupt sources. Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param interruptMask0 is the bit mask of the memory buffer and overflow
//!        interrupt sources to be disabled. If the desired interrupt is not
//!        available in the selection for interruptMask0, then simply pass in a
//!        '0' for this value.
//!        Valid values are:
//!        - \b ADC12_B_IE0
//!        - \b ADC12_B_IE1
//!        - \b ADC12_B_IE2
//!        - \b ADC12_B_IE3
//!        - \b ADC12_B_IE4
//!        - \b ADC12_B_IE5
//!        - \b ADC12_B_IE6
//!        - \b ADC12_B_IE7
//!        - \b ADC12_B_IE8
//!        - \b ADC12_B_IE9
//!        - \b ADC12_B_IE10
//!        - \b ADC12_B_IE11
//!        - \b ADC12_B_IE12
//!        - \b ADC12_B_IE13
//!        - \b ADC12_B_IE14
//!        - \b ADC12_B_IE15
//! \param interruptMask1 is the bit mask of the memory buffer and overflow
//!        interrupt sources to be disabled. If the desired interrupt is not
//!        available in the selection for interruptMask1, then simply pass in a
//!        '0' for this value.
//!        Valid values are:
//!        - \b ADC12_B_IE16
//!        - \b ADC12_B_IE17
//!        - \b ADC12_B_IE18
//!        - \b ADC12_B_IE19
//!        - \b ADC12_B_IE20
//!        - \b ADC12_B_IE21
//!        - \b ADC12_B_IE22
//!        - \b ADC12_B_IE23
//!        - \b ADC12_B_IE24
//!        - \b ADC12_B_IE25
//!        - \b ADC12_B_IE26
//!        - \b ADC12_B_IE27
//!        - \b ADC12_B_IE28
//!        - \b ADC12_B_IE29
//!        - \b ADC12_B_IE30
//!        - \b ADC12_B_IE31
//! \param interruptMask2 is the bit mask of the memory buffer and overflow
//!        interrupt sources to be disabled. If the desired interrupt is not
//!        available in the selection for interruptMask2, then simply pass in a
//!        '0' for this value.
//!        Valid values are:
//!        - \b ADC12_B_INIE - Interrupt enable for a conversion in the result
//!           register is either greater than the ADC12LO or lower than the
//!           ADC12HI threshold. GIE bit must be set to enable the interrupt.
//!        - \b ADC12_B_LOIE - Interrupt enable for the falling short of the
//!           lower limit interrupt of the window comparator for the result
//!           register. GIE bit must be set to enable the interrupt.
//!        - \b ADC12_B_HIIE - Interrupt enable for the exceeding the upper
//!           limit of the window comparator for the result register. GIE bit
//!           must be set to enable the interrupt.
//!        - \b ADC12_B_OVIE - Interrupt enable for a conversion that is about
//!           to save to a memory buffer that has not been read out yet. GIE
//!           bit must be set to enable the interrupt.
//!        - \b ADC12_B_TOVIE - enable for a conversion that is about to start
//!           before the previous conversion has been completed. GIE bit must
//!           be set to enable the interrupt.
//!        - \b ADC12_B_RDYIE - enable for the local buffered reference ready
//!           signal. GIE bit must be set to enable the interrupt.
//!
//! Modified bits of \b ADC12IERx register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_disableInterrupt(uint32_t baseAddress,
                              uint16_t interruptMask0,
                              uint16_t interruptMask1,
                              uint16_t interruptMask2)
{
        assert(interruptMask2 <= (
                       ADC12_B_INIE + ADC12_B_LOIE + ADC12_B_HIIE + ADC12_B_OVIE
                       + ADC12_B_TOVIE + ADC12_B_RDYIE
                       ));

        HWREG16(baseAddress + OFS_ADC12IER0) &= ~(interruptMask0);
        HWREG16(baseAddress + OFS_ADC12IER1) &= ~(interruptMask1);
        HWREG16(baseAddress + OFS_ADC12IER2) &= ~(interruptMask2);
}

//*****************************************************************************
//
//! \brief Clears ADC12B selected interrupt flags.
//!
//! Modified registers are ADC12IFG .
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param interruptRegisterChoice is either 0, 1, or 2, to choose the correct
//!        interrupt register to update
//! \param memoryInterruptFlagMask is the bit mask of the memory buffer and
//!        overflow interrupt flags to be cleared.
//!        Valid values are:
//!        - \b ADC12_B_IFG0 - interruptRegisterChoice = 0
//!        - \b ADC12_B_IFG1
//!        - \b ADC12_B_IFG2
//!        - \b ADC12_B_IFG3
//!        - \b ADC12_B_IFG4
//!        - \b ADC12_B_IFG5
//!        - \b ADC12_B_IFG6
//!        - \b ADC12_B_IFG7
//!        - \b ADC12_B_IFG8
//!        - \b ADC12_B_IFG9
//!        - \b ADC12_B_IFG10
//!        - \b ADC12_B_IFG11
//!        - \b ADC12_B_IFG12
//!        - \b ADC12_B_IFG13
//!        - \b ADC12_B_IFG14
//!        - \b ADC12_B_IFG15
//!        - \b ADC12_B_IFG16 - interruptRegisterChoice = 1
//!        - \b ADC12_B_IFG17
//!        - \b ADC12_B_IFG18
//!        - \b ADC12_B_IFG19
//!        - \b ADC12_B_IFG20
//!        - \b ADC12_B_IFG21
//!        - \b ADC12_B_IFG22
//!        - \b ADC12_B_IFG23
//!        - \b ADC12_B_IFG24
//!        - \b ADC12_B_IFG25
//!        - \b ADC12_B_IFG26
//!        - \b ADC12_B_IFG27
//!        - \b ADC12_B_IFG28
//!        - \b ADC12_B_IFG29
//!        - \b ADC12_B_IFG30
//!        - \b ADC12_B_IFG31
//!        - \b ADC12_B_INIFG - interruptRegisterChoice = 2
//!        - \b ADC12_B_LOIFG
//!        - \b ADC12_B_HIIFG
//!        - \b ADC12_B_OVIFG
//!        - \b ADC12_B_TOVIFG
//!        - \b ADC12_B_RDYIFG - The selected ADC12B interrupt flags are
//!           cleared, so that it no longer asserts. The memory buffer
//!           interrupt flags are only cleared when the memory buffer is
//!           accessed. Note that the overflow interrupts do not have an
//!           interrupt flag to clear; they must be accessed directly from the
//!           interrupt vector.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_clearInterrupt(uint32_t baseAddress,
                            uint8_t interruptRegisterChoice,
                            uint16_t memoryInterruptFlagMask)
{
        HWREG16(baseAddress + OFS_ADC12IFGR0 + 2 * interruptRegisterChoice) &=
                memoryInterruptFlagMask;

}

//*****************************************************************************
//
//! \brief Returns the status of the selected memory interrupt flags.
//!
//! Returns the status of the selected memory interrupt flags. Note that the
//! overflow interrupts do not have an interrupt flag to clear; they must be
//! accessed directly from the interrupt vector.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param interruptRegisterChoice is either 0, 1, or 2, to choose the correct
//!        interrupt register to update
//! \param memoryInterruptFlagMask is the bit mask of the memory buffer and
//!        overflow interrupt flags to be cleared.
//!        Valid values are:
//!        - \b ADC12_B_IFG0 - interruptRegisterChoice = 0
//!        - \b ADC12_B_IFG1
//!        - \b ADC12_B_IFG2
//!        - \b ADC12_B_IFG3
//!        - \b ADC12_B_IFG4
//!        - \b ADC12_B_IFG5
//!        - \b ADC12_B_IFG6
//!        - \b ADC12_B_IFG7
//!        - \b ADC12_B_IFG8
//!        - \b ADC12_B_IFG9
//!        - \b ADC12_B_IFG10
//!        - \b ADC12_B_IFG11
//!        - \b ADC12_B_IFG12
//!        - \b ADC12_B_IFG13
//!        - \b ADC12_B_IFG14
//!        - \b ADC12_B_IFG15
//!        - \b ADC12_B_IFG16 - interruptRegisterChoice = 1
//!        - \b ADC12_B_IFG17
//!        - \b ADC12_B_IFG18
//!        - \b ADC12_B_IFG19
//!        - \b ADC12_B_IFG20
//!        - \b ADC12_B_IFG21
//!        - \b ADC12_B_IFG22
//!        - \b ADC12_B_IFG23
//!        - \b ADC12_B_IFG24
//!        - \b ADC12_B_IFG25
//!        - \b ADC12_B_IFG26
//!        - \b ADC12_B_IFG27
//!        - \b ADC12_B_IFG28
//!        - \b ADC12_B_IFG29
//!        - \b ADC12_B_IFG30
//!        - \b ADC12_B_IFG31
//!        - \b ADC12_B_INIFG - interruptRegisterChoice = 2
//!        - \b ADC12_B_LOIFG
//!        - \b ADC12_B_HIIFG
//!        - \b ADC12_B_OVIFG
//!        - \b ADC12_B_TOVIFG
//!        - \b ADC12_B_RDYIFG - The selected ADC12B interrupt flags are
//!           cleared, so that it no longer asserts. The memory buffer
//!           interrupt flags are only cleared when the memory buffer is
//!           accessed. Note that the overflow interrupts do not have an
//!           interrupt flag to clear; they must be accessed directly from the
//!           interrupt vector.
//!
//! \return The current interrupt flag status for the corresponding mask.
//
//*****************************************************************************
uint16_t ADC12_B_getInterruptStatus(uint32_t baseAddress,
                                    uint8_t interruptRegisterChoice,
                                    uint16_t memoryInterruptFlagMask)
{
        return HWREG16(baseAddress + OFS_ADC12IFGR0 + 2 * interruptRegisterChoice)
               & memoryInterruptFlagMask;
}

//*****************************************************************************
//
//! \brief Enables/Starts an Analog-to-Digital Conversion.
//!
//! Enables/starts the conversion process of the ADC. If the sample/hold signal
//! source chosen during initialization was ADC12OSC, then the conversion is
//! started immediately, otherwise the chosen sample/hold signal source starts
//! the conversion by a rising edge of the signal. Keep in mind when selecting
//! conversion modes, that for sequenced and/or repeated modes, to keep the
//! sample/hold-and-convert process continuing without a trigger from the
//! sample/hold signal source, the multiple samples must be enabled using the
//! ADC12_B_setupSamplingTimer() function. Note that after this function is
//! called, the ADC12_B_stopConversions() has to be called to re-initialize the
//! ADC, reconfigure a memory buffer control, enable/disable the sampling
//! timer, or to change the internal reference voltage.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param startingMemoryBufferIndex is the memory buffer that will hold the
//!        first or only conversion.
//!        Valid values are:
//!        - \b ADC12_B_START_AT_ADC12MEM0 [Default]
//!        - \b ADC12_B_START_AT_ADC12MEM1
//!        - \b ADC12_B_START_AT_ADC12MEM2
//!        - \b ADC12_B_START_AT_ADC12MEM3
//!        - \b ADC12_B_START_AT_ADC12MEM4
//!        - \b ADC12_B_START_AT_ADC12MEM5
//!        - \b ADC12_B_START_AT_ADC12MEM6
//!        - \b ADC12_B_START_AT_ADC12MEM7
//!        - \b ADC12_B_START_AT_ADC12MEM8
//!        - \b ADC12_B_START_AT_ADC12MEM9
//!        - \b ADC12_B_START_AT_ADC12MEM10
//!        - \b ADC12_B_START_AT_ADC12MEM11
//!        - \b ADC12_B_START_AT_ADC12MEM12
//!        - \b ADC12_B_START_AT_ADC12MEM13
//!        - \b ADC12_B_START_AT_ADC12MEM14
//!        - \b ADC12_B_START_AT_ADC12MEM15
//!        - \b ADC12_B_START_AT_ADC12MEM16
//!        - \b ADC12_B_START_AT_ADC12MEM17
//!        - \b ADC12_B_START_AT_ADC12MEM18
//!        - \b ADC12_B_START_AT_ADC12MEM19
//!        - \b ADC12_B_START_AT_ADC12MEM20
//!        - \b ADC12_B_START_AT_ADC12MEM21
//!        - \b ADC12_B_START_AT_ADC12MEM22
//!        - \b ADC12_B_START_AT_ADC12MEM23
//!        - \b ADC12_B_START_AT_ADC12MEM24
//!        - \b ADC12_B_START_AT_ADC12MEM25
//!        - \b ADC12_B_START_AT_ADC12MEM26
//!        - \b ADC12_B_START_AT_ADC12MEM27
//!        - \b ADC12_B_START_AT_ADC12MEM28
//!        - \b ADC12_B_START_AT_ADC12MEM29
//!        - \b ADC12_B_START_AT_ADC12MEM30
//!        - \b ADC12_B_START_AT_ADC12MEM31
//!        \n Modified bits are \b ADC12CSTARTADDx of \b ADC12CTL1 register.
//! \param conversionSequenceModeSelect determines the ADC operating mode.
//!        Valid values are:
//!        - \b ADC12_B_SINGLECHANNEL [Default] - one-time conversion of a
//!           single channel into a single memory buffer.
//!        - \b ADC12_B_SEQOFCHANNELS - one time conversion of multiple
//!           channels into the specified starting memory buffer and each
//!           subsequent memory buffer up until the conversion is stored in a
//!           memory buffer dedicated as the end-of-sequence by the memory's
//!           control register.
//!        - \b ADC12_B_REPEATED_SINGLECHANNEL - repeated conversions of one
//!           channel into a single memory buffer.
//!        - \b ADC12_B_REPEATED_SEQOFCHANNELS - repeated conversions of
//!           multiple channels into the specified starting memory buffer and
//!           each subsequent memory buffer up until the conversion is stored
//!           in a memory buffer dedicated as the end-of-sequence by the
//!           memory's control register.
//!        \n Modified bits are \b ADC12CONSEQx of \b ADC12CTL1 register.
//!
//! Modified bits of \b ADC12CTL1 register and bits of \b ADC12CTL0 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_startConversion(uint32_t baseAddress,
                             uint16_t startingMemoryBufferIndex,
                             uint8_t conversionSequenceModeSelect)
{
        assert(startingMemoryBufferIndex <= ADC12_B_MEMORY_15);
        assert(conversionSequenceModeSelect <= ADC12_B_REPEATED_SEQOFCHANNELS);

        //Reset the ENC bit to set the starting memory address and conversion mode
        //sequence
        HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~(ADC12ENC);
        //Reset the bits about to be set
        HWREG16(baseAddress + OFS_ADC12CTL3) &= ~(ADC12CSTARTADD_31);
        HWREG16(baseAddress + OFS_ADC12CTL1) &= ~(ADC12CONSEQ_3);

        HWREG16(baseAddress + OFS_ADC12CTL3) |= startingMemoryBufferIndex;
        HWREG16(baseAddress + OFS_ADC12CTL1) |= conversionSequenceModeSelect;
        HWREG8(baseAddress + OFS_ADC12CTL0_L) |= ADC12ENC + ADC12SC;
}

//*****************************************************************************
//
//! \brief Disables the ADC from converting any more signals.
//!
//! Disables the ADC from converting any more signals. If there is a conversion
//! in progress, this function can stop it immediately if the preempt parameter
//! is set as ADC12_B_PREEMPTCONVERSION, by changing the conversion mode to
//! single-channel, single-conversion and disabling conversions. If the
//! conversion mode is set as single-channel, single-conversion and this
//! function is called without preemption, then the ADC core conversion status
//! is polled until the conversion is complete before disabling conversions to
//! prevent unpredictable data. If the ADC12_B_startConversion() has been
//! called, then this function has to be called to re-initialize the ADC,
//! reconfigure a memory buffer control, enable/disable the sampling pulse
//! mode, or change the internal reference voltage.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param preempt specifies if the current conversion should be preemptively
//!        stopped before the end of the conversion.
//!        Valid values are:
//!        - \b ADC12_B_COMPLETECONVERSION - Allows the ADC12B to end the
//!           current conversion before disabling conversions.
//!        - \b ADC12_B_PREEMPTCONVERSION - Stops the ADC12B immediately, with
//!           unpredictable results of the current conversion.
//!
//! Modified bits of \b ADC12CTL1 register and bits of \b ADC12CTL0 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_disableConversions(uint32_t baseAddress, bool preempt)
{
        if (ADC12_B_PREEMPTCONVERSION == preempt)
                HWREG8(baseAddress + OFS_ADC12CTL1_L) &= ~(ADC12CONSEQ_3);
                //Reset conversion sequence mode to single-channel, single-conversion
        else if (~(HWREG8(baseAddress + OFS_ADC12CTL1_L) & ADC12CONSEQ_3)) {
                //To prevent preemption of a single-channel, single-conversion we must
                //wait for the ADC core to finish the conversion.
                while (ADC12_B_isBusy(baseAddress)) ;
        }

        HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~(ADC12ENC);
}

//*****************************************************************************
//
//! \brief Returns the raw contents of the specified memory buffer.
//!
//! Returns the raw contents of the specified memory buffer. The format of the
//! content depends on the read-back format of the data: if the data is in
//! signed 2's complement format then the contents in the memory buffer will be
//! left-justified with the least-significant bits as 0's, whereas if the data
//! is in unsigned format then the contents in the memory buffer will be right-
//! justified with the most-significant bits as 0's.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param memoryBufferIndex is the specified memory buffer to read.
//!        Valid values are:
//!        - \b ADC12_B_MEMORY_0
//!        - \b ADC12_B_MEMORY_1
//!        - \b ADC12_B_MEMORY_2
//!        - \b ADC12_B_MEMORY_3
//!        - \b ADC12_B_MEMORY_4
//!        - \b ADC12_B_MEMORY_5
//!        - \b ADC12_B_MEMORY_6
//!        - \b ADC12_B_MEMORY_7
//!        - \b ADC12_B_MEMORY_8
//!        - \b ADC12_B_MEMORY_9
//!        - \b ADC12_B_MEMORY_10
//!        - \b ADC12_B_MEMORY_11
//!        - \b ADC12_B_MEMORY_12
//!        - \b ADC12_B_MEMORY_13
//!        - \b ADC12_B_MEMORY_14
//!        - \b ADC12_B_MEMORY_15
//!        - \b ADC12_B_MEMORY_16
//!        - \b ADC12_B_MEMORY_17
//!        - \b ADC12_B_MEMORY_18
//!        - \b ADC12_B_MEMORY_19
//!        - \b ADC12_B_MEMORY_20
//!        - \b ADC12_B_MEMORY_21
//!        - \b ADC12_B_MEMORY_22
//!        - \b ADC12_B_MEMORY_23
//!        - \b ADC12_B_MEMORY_24
//!        - \b ADC12_B_MEMORY_25
//!        - \b ADC12_B_MEMORY_26
//!        - \b ADC12_B_MEMORY_27
//!        - \b ADC12_B_MEMORY_28
//!        - \b ADC12_B_MEMORY_29
//!        - \b ADC12_B_MEMORY_30
//!        - \b ADC12_B_MEMORY_31
//!
//! \return A signed integer of the contents of the specified memory buffer.
//
//*****************************************************************************
uint16_t ADC12_B_getResults(uint32_t baseAddress, uint8_t memoryBufferIndex)
{
        assert(memoryBufferIndex <= ADC12_B_MEMORY_31);

        return HWREG16(baseAddress + (OFS_ADC12MEM0 + memoryBufferIndex));
        //(0x60 + memoryBufferIndex) == offset of ADC12MEMx
}

//*****************************************************************************
//
//! \brief Use to change the resolution of the converted data.
//!
//! This function can be used to change the resolution of the converted data
//! from the default of 12-bits.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param resolutionSelect determines the resolution of the converted data.
//!        Valid values are:
//!        - \b ADC12_B_RESOLUTION_8BIT
//!        - \b ADC12_B_RESOLUTION_10BIT
//!        - \b ADC12_B_RESOLUTION_12BIT [Default]
//!        \n Modified bits are \b ADC12RESx of \b ADC12CTL2 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_setResolution(uint32_t baseAddress,
                           uint8_t resolutionSelect)
{
        assert(resolutionSelect <= ADC12_B_RESOLUTION_12BIT);

        HWREG8(baseAddress + OFS_ADC12CTL2_L) &= ~(ADC12RES_3);
        HWREG8(baseAddress + OFS_ADC12CTL2_L) |= resolutionSelect;
}

//*****************************************************************************
//
//! \brief Use to invert or un-invert the sample/hold signal.
//!
//! This function can be used to invert or un-invert the sample/hold signal.
//! Note that if a conversion has been started with the startConversion()
//! function, then a call to disableConversions() is required before this
//! function may be called.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param invertedSignal set if the sample/hold signal should be inverted
//!        Valid values are:
//!        - \b ADC12_B_NONINVERTEDSIGNAL [Default] - a sample-and-hold of an
//!           input signal for conversion will be started on a rising edge of
//!           the sample/hold signal.
//!        - \b ADC12_B_INVERTEDSIGNAL - a sample-and-hold of an input signal
//!           for conversion will be started on a falling edge of the
//!           sample/hold signal.
//!        \n Modified bits are \b ADC12ISSH of \b ADC12CTL1 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_setSampleHoldSignalInversion(uint32_t baseAddress,
                                          uint16_t invertedSignal)
{
        //Make sure the ENC bit is cleared before using this function
        assert( !(HWREG8(baseAddress + OFS_ADC12CTL0_L) & ADC12ENC) );

        HWREG16(baseAddress + OFS_ADC12CTL1) &= ~(ADC12ISSH);
        HWREG16(baseAddress + OFS_ADC12CTL1) |= invertedSignal;
}

//*****************************************************************************
//
//! \brief Use to set the read-back format of the converted data.
//!
//! Sets the format of the converted data: how it will be stored into the
//! memory buffer, and how it should be read back. The format can be set as
//! right-justified (default), which indicates that the number will be
//! unsigned, or left-justified, which indicates that the number will be signed
//! in 2's complement format. This change affects all memory buffers for
//! subsequent conversions.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param readBackFormat is the specified format to store the conversions in
//!        the memory buffer.
//!        Valid values are:
//!        - \b ADC12_B_UNSIGNED_BINARY [Default]
//!        - \b ADC12_B_SIGNED_2SCOMPLEMENT
//!        \n Modified bits are \b ADC12DF of \b ADC12CTL2 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_setDataReadBackFormat(uint32_t baseAddress,
                                   uint8_t readBackFormat)
{
        assert(readBackFormat <= ADC12_B_SIGNED_2SCOMPLEMENT);

        HWREG8(baseAddress + OFS_ADC12CTL2_L) &= ~(ADC12DF);
        HWREG8(baseAddress + OFS_ADC12CTL2_L) |= readBackFormat;
}

//*****************************************************************************
//
//! \brief Use to set the ADC's power conservation mode if the sampling rate is
//! at 50-ksps or less.
//!
//! Sets ADC's power mode. If the user has a sampling rate greater than
//! 50-ksps, then he/she can only enable ADC12_B_REGULARPOWERMODE. If the
//! sampling rate is 50-ksps or less, the user can enable ADC12_B_LOWPOWERMODE
//! granting additional power savings.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param powerMode is the specified maximum sampling rate.
//!        Valid values are:
//!        - \b ADC12_B_REGULARPOWERMODE [Default] - If sampling rate is
//!           greater than 50-ksps, there is no power saving feature available.
//!        - \b ADC12_B_LOWPOWERMODE - If sampling rate is less than or equal
//!           to 50-ksps, select this value to save power
//!        \n Modified bits are \b ADC12SR of \b ADC12CTL2 register.
//!
//! \return None
//
//*****************************************************************************
void ADC12_B_setAdcPowerMode(uint32_t baseAddress,
                             uint8_t powerMode)
{
        assert((powerMode == ADC12_B_REGULARPOWERMODE) ||
               (powerMode == ADC12_B_LOWPOWERMODE)
               );

        HWREG8(baseAddress + OFS_ADC12CTL2_L) &= ~(ADC12PWRMD);
        HWREG8(baseAddress + OFS_ADC12CTL2_L) |= powerMode;
}

//*****************************************************************************
//
//! \brief Returns the address of the specified memory buffer for the DMA
//! module.
//!
//! Returns the address of the specified memory buffer. This can be used in
//! conjunction with the DMA to store the converted data directly to memory.
//!
//! \param baseAddress is the base address of the ADC12B module.
//! \param memoryIndex is the memory buffer to return the address of.
//!        Valid values are:
//!        - \b ADC12_B_MEMORY_0
//!        - \b ADC12_B_MEMORY_1
//!        - \b ADC12_B_MEMORY_2
//!        - \b ADC12_B_MEMORY_3
//!        - \b ADC12_B_MEMORY_4
//!        - \b ADC12_B_MEMORY_5
//!        - \b ADC12_B_MEMORY_6
//!        - \b ADC12_B_MEMORY_7
//!        - \b ADC12_B_MEMORY_8
//!        - \b ADC12_B_MEMORY_9
//!        - \b ADC12_B_MEMORY_10
//!        - \b ADC12_B_MEMORY_11
//!        - \b ADC12_B_MEMORY_12
//!        - \b ADC12_B_MEMORY_13
//!        - \b ADC12_B_MEMORY_14
//!        - \b ADC12_B_MEMORY_15
//!        - \b ADC12_B_MEMORY_16
//!        - \b ADC12_B_MEMORY_17
//!        - \b ADC12_B_MEMORY_18
//!        - \b ADC12_B_MEMORY_19
//!        - \b ADC12_B_MEMORY_20
//!        - \b ADC12_B_MEMORY_21
//!        - \b ADC12_B_MEMORY_22
//!        - \b ADC12_B_MEMORY_23
//!        - \b ADC12_B_MEMORY_24
//!        - \b ADC12_B_MEMORY_25
//!        - \b ADC12_B_MEMORY_26
//!        - \b ADC12_B_MEMORY_27
//!        - \b ADC12_B_MEMORY_28
//!        - \b ADC12_B_MEMORY_29
//!        - \b ADC12_B_MEMORY_30
//!        - \b ADC12_B_MEMORY_31
//!
//! \return address of the specified memory buffer
//
//*****************************************************************************
uint32_t ADC12_B_getMemoryAddressForDMA(uint32_t baseAddress,
                                        uint8_t memoryIndex)
{
        return baseAddress + (OFS_ADC12MEM0 + memoryIndex);
        //(0x60 + memoryIndex) == offset of ADC12MEMx
}

//*****************************************************************************
//
//! \brief Returns the busy status of the ADC12B core.
//!
//! Returns the status of the ADC core if there is a conversion currently
//! taking place.
//!
//! \param baseAddress is the base address of the ADC12B module.
//!
//! \return ADC12_B_BUSY or ADC12_B_NOTBUSY dependent if there is a conversion
//!         currently taking place.
//!         Return one of the following:
//!         - \b ADC12_B_NOTBUSY
//!         - \b ADC12_B_BUSY
//!         \n indicating if a conversion is taking place
//
//*****************************************************************************
uint8_t ADC12_B_isBusy(uint32_t baseAddress)
{
        return HWREG8(baseAddress + OFS_ADC12CTL1_L) & ADC12BUSY;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for adc12_b_api
//! @}
//
//*****************************************************************************

#endif
