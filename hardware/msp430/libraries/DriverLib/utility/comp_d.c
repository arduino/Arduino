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
// comp_d.c - Driver for the comp_d Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup comp_d_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_COMPD__
#include "comp_d.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Initializes the COMP_D Module.
//!
//! Upon successful initialization of the COMP_D module, this function will
//! have reset all necessary register bits and set the given options in the
//! registers. To actually use the COMP_D module, the COMP_D_enable() function
//! must be explicitly called before use. If a Reference Voltage is set to a
//! terminal, the Voltage should be set using the setReferenceVoltage()
//! function.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param positiveTerminalInput selects the input to the positive terminal.
//!        Valid values are:
//!        - \b COMP_D_INPUT0 [Default]
//!        - \b COMP_D_INPUT1
//!        - \b COMP_D_INPUT2
//!        - \b COMP_D_INPUT3
//!        - \b COMP_D_INPUT4
//!        - \b COMP_D_INPUT5
//!        - \b COMP_D_INPUT6
//!        - \b COMP_D_INPUT7
//!        - \b COMP_D_INPUT8
//!        - \b COMP_D_INPUT9
//!        - \b COMP_D_INPUT10
//!        - \b COMP_D_INPUT11
//!        - \b COMP_D_INPUT12
//!        - \b COMP_D_INPUT13
//!        - \b COMP_D_INPUT14
//!        - \b COMP_D_INPUT15
//!        - \b COMP_D_VREF
//!        \n Modified bits are \b CDRSEL of \b CDCTL2 register; bits \b CDPDx
//!        of \b CDCTL3 register; bits \b CDIPEN of \b CDCTL0 register.
//! \param negativeTerminalInput selects the input to the negative terminal.
//!        Valid values are:
//!        - \b COMP_D_INPUT0 [Default]
//!        - \b COMP_D_INPUT1
//!        - \b COMP_D_INPUT2
//!        - \b COMP_D_INPUT3
//!        - \b COMP_D_INPUT4
//!        - \b COMP_D_INPUT5
//!        - \b COMP_D_INPUT6
//!        - \b COMP_D_INPUT7
//!        - \b COMP_D_INPUT8
//!        - \b COMP_D_INPUT9
//!        - \b COMP_D_INPUT10
//!        - \b COMP_D_INPUT11
//!        - \b COMP_D_INPUT12
//!        - \b COMP_D_INPUT13
//!        - \b COMP_D_INPUT14
//!        - \b COMP_D_INPUT15
//!        - \b COMP_D_VREF
//!        \n Modified bits are \b CDRSEL of \b CDCTL2 register; bits \b CDPDx
//!        of \b CDCTL3 register; bits \b CDIMEN of \b CDCTL0 register.
//! \param outputFilterEnableAndDelayLevel controls the output filter delay
//!        state, which is either off or enabled with a specified delay level.
//!        This parameter is device specific and delay levels should be found
//!        in the device's datasheet.
//!        Valid values are:
//!        - \b COMP_D_FILTEROUTPUT_OFF [Default]
//!        - \b COMP_D_FILTEROUTPUT_DLYLVL1
//!        - \b COMP_D_FILTEROUTPUT_DLYLVL2
//!        - \b COMP_D_FILTEROUTPUT_DLYLVL3
//!        - \b COMP_D_FILTEROUTPUT_DLYLVL4
//!        \n Modified bits are \b CDFDLY of \b CDCTL1 register.
//! \param invertedOutputPolarity controls if the output will be inverted or
//!        not
//!        Valid values are:
//!        - \b COMP_D_NORMALOUTPUTPOLARITY [Default]
//!        - \b COMP_D_INVERTEDOUTPUTPOLARITY
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the initialization process
//
//*****************************************************************************
bool COMP_D_init(uint32_t baseAddress,
                 uint8_t positiveTerminalInput,
                 uint8_t negativeTerminalInput,
                 uint8_t outputFilterEnableAndDelayLevel,
                 uint16_t invertedOutputPolarity)
{
        assert(positiveTerminalInput <= COMP_D_VREF);
        assert(negativeTerminalInput <= COMP_D_VREF);
        assert(positiveTerminalInput != negativeTerminalInput);
        assert(outputFilterEnableAndDelayLevel <= COMP_D_FILTEROUTPUT_DLYLVL4);

        bool retVal = STATUS_SUCCESS;

        //Reset COMPD Control 1 & Interrupt Registers for initialization (OFS_CDCTL3
        //is not reset because it controls the input buffers of the analog signals
        //and may cause parasitic effects if an analog signal is still attached and
        //the buffer is re-enabled
        HWREG16(baseAddress + OFS_CDCTL0) &= 0x0000;
        HWREG16(baseAddress + OFS_CDINT)  &= 0x0000;

        //Set the Positive Terminal
        if (COMP_D_VREF != positiveTerminalInput) {
                //Enable Positive Terminal Input Mux and Set it to the appropriate input
                HWREG16(baseAddress + OFS_CDCTL0) |= CDIPEN + positiveTerminalInput;

                //Disable the input buffer
                HWREG16(baseAddress + OFS_CDCTL3) |= (1 << positiveTerminalInput);
        } else
                //Reset and Set COMPD Control 2 Register
                HWREG16(baseAddress + OFS_CDCTL2) &= ~(CDRSEL); //Set Vref to go to (+)terminal

        //Set the Negative Terminal
        if (COMP_D_VREF != negativeTerminalInput) {
                //Enable Negative Terminal Input Mux and Set it to the appropriate input
                HWREG16(baseAddress + OFS_CDCTL0) |= CDIMEN + (negativeTerminalInput << 8);

                //Disable the input buffer
                HWREG16(baseAddress + OFS_CDCTL3) |= (1 << negativeTerminalInput);
        } else
                //Reset and Set COMPD Control 2 Register
                HWREG16(baseAddress + OFS_CDCTL2) |= CDRSEL; //Set Vref to go to (-) terminal

        //Reset and Set COMPD Control 1 Register
        HWREG16(baseAddress + OFS_CDCTL1) =
                +outputFilterEnableAndDelayLevel        //Set the filter enable bit and delay
                + invertedOutputPolarity;               //Set the polarity of the output

        return retVal;
}

//*****************************************************************************
//
//! \brief Generates a Reference Voltage to the terminal selected during
//! initialization.
//!
//! Use this function to generate a voltage to serve as a reference to the
//! terminal selected at initialization. The voltage is determined by the
//! equation: Vbase * (Numerator / 32). If the upper and lower limit voltage
//! numerators are equal, then a static reference is defined, whereas they are
//! different then a hysteresis effect is generated.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param supplyVoltageReferenceBase decides the source and max amount of
//!        Voltage that can be used as a reference.
//!        Valid values are:
//!        - \b COMP_D_REFERENCE_AMPLIFIER_DISABLED
//!        - \b COMP_D_VREFBASE1_5V
//!        - \b COMP_D_VREFBASE2_0V
//!        - \b COMP_D_VREFBASE2_5V
//!        \n Modified bits are \b CDREFL of \b CDCTL2 register.
//! \param lowerLimitSupplyVoltageFractionOf32 is the numerator of the equation
//!        to generate the reference voltage for the lower limit reference
//!        voltage.
//!        \n Modified bits are \b CDREF0 of \b CDCTL2 register.
//! \param upperLimitSupplyVoltageFractionOf32 is the numerator of the equation
//!        to generate the reference voltage for the upper limit reference
//!        voltage.
//!        \n Modified bits are \b CDREF1 of \b CDCTL2 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_setReferenceVoltage(uint32_t baseAddress,
                                uint16_t supplyVoltageReferenceBase,
                                uint16_t lowerLimitSupplyVoltageFractionOf32,
                                uint16_t upperLimitSupplyVoltageFractionOf32)
{
        assert(supplyVoltageReferenceBase <= COMP_D_VREFBASE2_5V);
        assert(upperLimitSupplyVoltageFractionOf32 <= 32);
        assert(lowerLimitSupplyVoltageFractionOf32 <= 32);
        assert(upperLimitSupplyVoltageFractionOf32
               >= lowerLimitSupplyVoltageFractionOf32);

        HWREG16(baseAddress + OFS_CDCTL1) &= ~(CDMRVS); //Set to VREF0

        //Reset COMPD Control 2 Bits (Except for CDRSEL which is set in Comp_Init() )
        HWREG16(baseAddress + OFS_CDCTL2) &= CDRSEL;

        //Set Voltage Source (Vcc | Vref, resistor ladder or not)
        if (COMP_D_VREFBASE_VCC == supplyVoltageReferenceBase)
                HWREG16(baseAddress + OFS_CDCTL2) |= CDRS_1; //Vcc with resistor ladder
        else if (lowerLimitSupplyVoltageFractionOf32 == 32) {
                //If the lower limit is 32, then the upper limit has to be 32 due to the
                //assertion that upper must be >= to the lower limit. If the numerator is
                //equal to 32, then the equation would be 32/32 == 1, therefore no resistor
                //ladder is needed
                HWREG16(baseAddress + OFS_CDCTL2) |= CDRS_3;    //Vref, no resistor ladder
        } else
                HWREG16(baseAddress + OFS_CDCTL2) |= CDRS_2;    //Vref with resistor ladder

        //Set COMPD Control 2 Register
        HWREG16(baseAddress + OFS_CDCTL2) |=
                supplyVoltageReferenceBase                              //Set Supply Voltage Base
                + ((upperLimitSupplyVoltageFractionOf32 - 1) << 8)      //Set Supply Voltage Num.
                + (lowerLimitSupplyVoltageFractionOf32 - 1);
}

//*****************************************************************************
//
//! \brief Sets the reference accuracy
//!
//! The reference accuracy is set to the desired setting. Clocked is better for
//! low power operations but has a lower accuracy.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param referenceAccuracy is the reference accuracy setting of the
//!        comparator. Clocked is for low power/low accuracy.
//!        Valid values are:
//!        - \b COMP_D_ACCURACY_STATIC
//!        - \b COMP_D_ACCURACY_CLOCKED
//!        \n Modified bits are \b CDREFACC of \b CDCTL2 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_setReferenceAccuracy(uint32_t baseAddress,
                                 uint16_t referenceAccuracy)
{
        assert(
                (referenceAccuracy == COMP_D_ACCURACY_STATIC) ||
                (referenceAccuracy == COMP_D_ACCURACY_CLOCKED)
                );

        HWREG16(baseAddress + OFS_CDCTL2) &= ~(CDREFACC);
        HWREG16(baseAddress + OFS_CDCTL2) |= referenceAccuracy;
}

//*****************************************************************************
//
//! \brief Enables selected Comparator interrupt sources.
//!
//! Enables the indicated Comparator interrupt sources.  Only the sources that
//! are enabled can be reflected to the processor interrupt; disabled sources
//! have no effect on the processor. <b>Does not clear interrupt flags.</b>
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param interruptMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_D_INTERRUPT - Output interrupt
//!        - \b COMP_D_INTERRUPT_INVERTED_POLARITY - Output interrupt inverted
//!           polarity
//!
//
//*****************************************************************************
void COMP_D_enableInterrupt(uint32_t baseAddress,
                            uint16_t interruptMask)
{
        //Set the Interrupt enable bit
        HWREG16(baseAddress + OFS_CDINT) |= interruptMask;
}

//*****************************************************************************
//
//! \brief Disables selected Comparator interrupt sources.
//!
//! Disables the indicated Comparator interrupt sources.  Only the sources that
//! are enabled can be reflected to the processor interrupt; disabled sources
//! have no effect on the processor.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param interruptMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_D_INTERRUPT - Output interrupt
//!        - \b COMP_D_INTERRUPT_INVERTED_POLARITY - Output interrupt inverted
//!           polarity
//!
//
//*****************************************************************************
void COMP_D_disableInterrupt(uint32_t baseAddress,
                             uint16_t interruptMask)
{
        HWREG16(baseAddress + OFS_CDINT) &= ~(interruptMask);
}

//*****************************************************************************
//
//! \brief Clears Comparator interrupt flags.
//!
//! The Comparator interrupt source is cleared, so that it no longer
//! asserts.The highest interrupt flag is automatically cleared when an
//! interrupt vector generator is used.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param interruptFlagMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_D_INTERRUPT_FLAG - Output interrupt flag
//!        - \b COMP_D_INTERRUPT_FLAG_INVERTED_POLARITY - Output interrupt flag
//!           inverted polarity
//!
//
//*****************************************************************************
void COMP_D_clearInterrupt(uint32_t baseAddress,
                           uint16_t interruptFlagMask)
{
        HWREG16(baseAddress + OFS_CDINT) &= ~(interruptFlagMask);
}

//*****************************************************************************
//
//! \brief Gets the current Comparator interrupt status.
//!
//! This returns the interrupt status for the Comparator module based on which
//! flag is passed.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param interruptFlagMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_D_INTERRUPT_FLAG - Output interrupt flag
//!        - \b COMP_D_INTERRUPT_FLAG_INVERTED_POLARITY - Output interrupt flag
//!           inverted polarity
//!
//
//*****************************************************************************
uint8_t COMP_D_getInterruptStatus(uint32_t baseAddress,
                                  uint16_t interruptFlagMask)
{
        return HWREG16(baseAddress + OFS_CDINT) & interruptFlagMask;
}

//*****************************************************************************
//
//! \brief Explicitly sets the edge direction that would trigger an interrupt.
//!
//! This function will set which direction the output will have to go, whether
//! rising or falling, to generate an interrupt based on a non-inverted
//! interrupt.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param edgeDirection determines which direction the edge would have to go
//!        to generate an interrupt based on the non-inverted interrupt flag.
//!        Valid values are:
//!        - \b COMP_D_FALLINGEDGE [Default] - sets the bit to generate an
//!           interrupt when the output of the comparator falls from HIGH to
//!           LOW if the normal interrupt bit is set(and LOW to HIGH if the
//!           inverted interrupt enable bit is set).
//!        - \b COMP_D_RISINGEDGE - sets the bit to generate an interrupt when
//!           the output of the comparator rises from LOW to HIGH if the normal
//!           interrupt bit is set(and HIGH to LOW if the inverted interrupt
//!           enable bit is set).
//!        \n Modified bits are \b CDIES of \b CDCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_interruptSetEdgeDirection(uint32_t baseAddress,
                                      uint16_t edgeDirection)
{
        assert(edgeDirection <= COMP_D_RISINGEDGE);

        //Set the edge direction that will trigger an interrupt
        if (COMP_D_RISINGEDGE == edgeDirection)
                HWREG16(baseAddress + OFS_CDCTL1) |= CDIES;
        else if (COMP_D_FALLINGEDGE == edgeDirection)
                HWREG16(baseAddress + OFS_CDCTL1) &= ~(CDIES);
}

//*****************************************************************************
//
//! \brief Toggles the edge direction that would trigger an interrupt.
//!
//! This function will toggle which direction the output will have to go,
//! whether rising or falling, to generate an interrupt based on a non-inverted
//! interrupt. If the direction was rising, it is now falling, if it was
//! falling, it is now rising.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_interruptToggleEdgeDirection(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CDCTL1) ^= CDIES;
}

//*****************************************************************************
//
//! \brief Turns on the Comparator module.
//!
//! This function sets the bit that enables the operation of the Comparator
//! module.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_enable(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CDCTL1) |= CDON;
}

//*****************************************************************************
//
//! \brief Turns off the Comparator module.
//!
//! This function clears the CDON bit disabling the operation of the Comparator
//! module, saving from excess power consumption.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_disable(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CDCTL1) &= ~(CDON);
}

//*****************************************************************************
//
//! \brief Shorts the two input pins chosen during initialization.
//!
//! This function sets the bit that shorts the devices attached to the input
//! pins chosen from the initialization of the comparator.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_shortInputs(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CDCTL1) |= CDSHORT;
}

//*****************************************************************************
//
//! \brief Disables the short of the two input pins chosen during
//! initialization.
//!
//! This function clears the bit that shorts the devices attached to the input
//! pins chosen from the initialization of the comparator.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_unshortInputs(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CDCTL1) &= ~(CDSHORT);
}

//*****************************************************************************
//
//! \brief Disables the input buffer of the selected input port to effectively
//! allow for analog signals.
//!
//! This function sets the bit to disable the buffer for the specified input
//! port to allow for analog signals from any of the comparator input pins.
//! This bit is automatically set when the input is initialized to be used with
//! the comparator module. This function should be used whenever an analog
//! input is connected to one of these pins to prevent parasitic voltage from
//! causing unexpected results.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param inputPort is the port in which the input buffer will be disabled.
//!        Valid values are:
//!        - \b COMP_D_INPUT0 [Default]
//!        - \b COMP_D_INPUT1
//!        - \b COMP_D_INPUT2
//!        - \b COMP_D_INPUT3
//!        - \b COMP_D_INPUT4
//!        - \b COMP_D_INPUT5
//!        - \b COMP_D_INPUT6
//!        - \b COMP_D_INPUT7
//!        - \b COMP_D_INPUT8
//!        - \b COMP_D_INPUT9
//!        - \b COMP_D_INPUT10
//!        - \b COMP_D_INPUT11
//!        - \b COMP_D_INPUT12
//!        - \b COMP_D_INPUT13
//!        - \b COMP_D_INPUT14
//!        - \b COMP_D_INPUT15
//!        - \b COMP_D_VREF
//!        \n Modified bits are \b CDPDx of \b CDCTL3 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_disableInputBuffer(uint32_t baseAddress,
                               uint8_t inputPort)
{
        assert(inputPort <= COMP_D_INPUT15);

        HWREG16(baseAddress + OFS_CDCTL3) |= (1 << inputPort);
}

//*****************************************************************************
//
//! \brief Enables the input buffer of the selected input port to allow for
//! digital signals.
//!
//! This function clears the bit to enable the buffer for the specified input
//! port to allow for digital signals from any of the comparator input pins.
//! This should not be reset if there is an analog signal connected to the
//! specified input pin to prevent from unexpected results.
//!
//! \param baseAddress is the base address of the COMP_D module.
//! \param inputPort is the port in which the input buffer will be enabled.
//!        Valid values are:
//!        - \b COMP_D_INPUT0 [Default]
//!        - \b COMP_D_INPUT1
//!        - \b COMP_D_INPUT2
//!        - \b COMP_D_INPUT3
//!        - \b COMP_D_INPUT4
//!        - \b COMP_D_INPUT5
//!        - \b COMP_D_INPUT6
//!        - \b COMP_D_INPUT7
//!        - \b COMP_D_INPUT8
//!        - \b COMP_D_INPUT9
//!        - \b COMP_D_INPUT10
//!        - \b COMP_D_INPUT11
//!        - \b COMP_D_INPUT12
//!        - \b COMP_D_INPUT13
//!        - \b COMP_D_INPUT14
//!        - \b COMP_D_INPUT15
//!        - \b COMP_D_VREF
//!        \n Modified bits are \b CDPDx of \b CDCTL3 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_enableInputBuffer(uint32_t baseAddress,
                              uint8_t inputPort)
{
        assert(inputPort <= COMP_D_INPUT15);

        HWREG16(baseAddress + OFS_CDCTL3) &= ~(1 << inputPort);
}

//*****************************************************************************
//
//! \brief Toggles the bit that swaps which terminals the inputs go to, while
//! also inverting the output of the comparator.
//!
//! This function toggles the bit that controls which input goes to which
//! terminal. After initialization, this bit is set to 0, after toggling it
//! once the inputs are routed to the opposite terminal and the output is
//! inverted.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return None
//
//*****************************************************************************
void COMP_D_IOSwap(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CDCTL1) ^= CDEX; //Toggle CDEX bit
}

//*****************************************************************************
//
//! \brief Returns the output value of the COMP_D module.
//!
//! Returns the output value of the COMP_D module.
//!
//! \param baseAddress is the base address of the COMP_D module.
//!
//! \return COMP_D_HIGH or COMP_D_LOW as the output value of the Comparator
//!         module.
//!         Return one of the following:
//!         - \b COMP_D_HIGH
//!         - \b COMP_D_LOW
//!         \n indicates the output should be normal
//
//*****************************************************************************
uint16_t COMP_D_outputValue(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_CDCTL1) & CDOUT;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for comp_d_api
//! @}
//
//*****************************************************************************

#endif
