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
// comp_e.c - Driver for the comp_e Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup comp_e_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_COMP_E__
#include "comp_e.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Convert Driverlib input definition to register input definition.
//!
//! \param input Driverlib defintion for input
//!
//! \return register input definition
//
//*****************************************************************************
static uint16_t __getRegisterSettingForInput(uint32_t input)
{
        switch (input) {
        case COMP_E_INPUT0:
                return CEIPSEL_0;
        case COMP_E_INPUT1:
                return CEIPSEL_1;
        case COMP_E_INPUT2:
                return CEIPSEL_2;
        case COMP_E_INPUT3:
                return CEIPSEL_3;
        case COMP_E_INPUT4:
                return CEIPSEL_4;
        case COMP_E_INPUT5:
                return CEIPSEL_5;
        case COMP_E_INPUT6:
                return CEIPSEL_6;
        case COMP_E_INPUT7:
                return CEIPSEL_7;
        case COMP_E_INPUT8:
                return CEIPSEL_8;
        case COMP_E_INPUT9:
                return CEIPSEL_9;
        case COMP_E_INPUT10:
                return CEIPSEL_10;
        case COMP_E_INPUT11:
                return CEIPSEL_11;
        case COMP_E_INPUT12:
                return CEIPSEL_12;
        case COMP_E_INPUT13:
                return CEIPSEL_13;
        case COMP_E_INPUT14:
                return CEIPSEL_14;
        case COMP_E_INPUT15:
                return CEIPSEL_15;
        case COMP_E_VREF:
                return COMP_E_VREF;
        default:
                assert(false);
                return 0x11;
        }

}

//*****************************************************************************
//
//! \brief Initializes the COMP_E Module.
//!
//! Upon successful initialization of the COMP_E module, this function will
//! have reset all necessary register bits and set the given options in the
//! registers. To actually use the COMP_E module, the COMP_E_enable() function
//! must be explicitly called before use. If a Reference Voltage is set to a
//! terminal, the Voltage should be set using the setReferenceVoltage()
//! function.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param posTerminalInput selects the input to the positive terminal.
//!        Valid values are:
//!        - \b COMP_E_INPUT0 [Default]
//!        - \b COMP_E_INPUT1
//!        - \b COMP_E_INPUT2
//!        - \b COMP_E_INPUT3
//!        - \b COMP_E_INPUT4
//!        - \b COMP_E_INPUT5
//!        - \b COMP_E_INPUT6
//!        - \b COMP_E_INPUT7
//!        - \b COMP_E_INPUT8
//!        - \b COMP_E_INPUT9
//!        - \b COMP_E_INPUT10
//!        - \b COMP_E_INPUT11
//!        - \b COMP_E_INPUT12
//!        - \b COMP_E_INPUT13
//!        - \b COMP_E_INPUT14
//!        - \b COMP_E_INPUT15
//!        - \b COMP_E_VREF
//!        \n Modified bits are \b CEPDx of \b CECTL3 register; bits \b CERSEL
//!        of \b CECTL2 register; bits \b CEIPEN and \b CEIPSEL of \b CECTL0
//!        register.
//! \param negTerminalInput selects the input to the negative terminal.
//!        Valid values are:
//!        - \b COMP_E_INPUT0 [Default]
//!        - \b COMP_E_INPUT1
//!        - \b COMP_E_INPUT2
//!        - \b COMP_E_INPUT3
//!        - \b COMP_E_INPUT4
//!        - \b COMP_E_INPUT5
//!        - \b COMP_E_INPUT6
//!        - \b COMP_E_INPUT7
//!        - \b COMP_E_INPUT8
//!        - \b COMP_E_INPUT9
//!        - \b COMP_E_INPUT10
//!        - \b COMP_E_INPUT11
//!        - \b COMP_E_INPUT12
//!        - \b COMP_E_INPUT13
//!        - \b COMP_E_INPUT14
//!        - \b COMP_E_INPUT15
//!        - \b COMP_E_VREF
//!        \n Modified bits are \b CEPDx of \b CECTL3 register; bits \b CERSEL
//!        of \b CECTL2 register; bits \b CEIMSEL of \b CECLT0 register; bits
//!        \b CEIMEN of \b CECTL0 register.
//! \param outputFilterEnableAndDelayLevel controls the output filter delay
//!        state, which is either off or enabled with a specified delay level.
//!        This parameter is device specific and delay levels should be found
//!        in the device's datasheet.
//!        Valid values are:
//!        - \b COMP_E_FILTEROUTPUT_OFF [Default]
//!        - \b COMP_E_FILTEROUTPUT_DLYLVL1
//!        - \b COMP_E_FILTEROUTPUT_DLYLVL2
//!        - \b COMP_E_FILTEROUTPUT_DLYLVL3
//!        - \b COMP_E_FILTEROUTPUT_DLYLVL4
//!        \n Modified bits are \b CEFDLY and \b CEF of \b CECTL1 register.
//! \param invertedOutputPolarity controls if the output will be inverted or
//!        not
//!        Valid values are:
//!        - \b COMP_E_NORMALOUTPUTPOLARITY - indicates the output should be
//!           normal
//!        - \b COMP_E_INVERTEDOUTPUTPOLARITY - the output should be inverted
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the initialization process
//
//*****************************************************************************
bool COMP_E_init(uint32_t baseAddress,
                 uint16_t posTerminalInput,
                 uint16_t negTerminalInput,
                 uint8_t outputFilterEnableAndDelayLevel,
                 uint16_t invertedOutputPolarity)
{
        uint8_t positiveTerminalInput = __getRegisterSettingForInput(
                posTerminalInput);
        uint8_t negativeTerminalInput = __getRegisterSettingForInput(
                negTerminalInput);

        assert(positiveTerminalInput < 0x10);
        assert(negativeTerminalInput < 0x10);
        assert(positiveTerminalInput != negativeTerminalInput);
        assert(outputFilterEnableAndDelayLevel <= COMP_E_FILTEROUTPUT_DLYLVL4);

        bool retVal = STATUS_SUCCESS;

        //Reset COMPE Control 1 & Interrupt Registers for initialization (OFS_CECTL3
        //is not reset because it controls the input buffers of the analog signals
        //and may cause parasitic effects if an analog signal is still attached and
        //the buffer is re-enabled
        HWREG16(baseAddress + OFS_CECTL0) &= 0x0000;
        HWREG16(baseAddress + OFS_CEINT)  &= 0x0000;

        //Set the Positive Terminal
        if (COMP_E_VREF != positiveTerminalInput) {
                //Enable Positive Terminal Input Mux and Set it to the appropriate input
                HWREG16(baseAddress + OFS_CECTL0) |= CEIPEN + positiveTerminalInput;

                //Disable the input buffer
                HWREG16(baseAddress + OFS_CECTL3) |= (1 << positiveTerminalInput);
        } else
                //Reset and Set COMPE Control 2 Register
                HWREG16(baseAddress + OFS_CECTL2) &= ~(CERSEL); //Set Vref to go to (+)terminal

        //Set the Negative Terminal
        if (COMP_E_VREF != negativeTerminalInput) {
                //Enable Negative Terminal Input Mux and Set it to the appropriate input
                HWREG16(baseAddress + OFS_CECTL0) |= CEIMEN + (negativeTerminalInput << 8);

                //Disable the input buffer
                HWREG16(baseAddress + OFS_CECTL3) |= (1 << negativeTerminalInput);
        } else
                //Reset and Set COMPE Control 2 Register
                HWREG16(baseAddress + OFS_CECTL2) |= CERSEL; //Set Vref to go to (-) terminal

        //Reset and Set COMPE Control 1 Register
        HWREG16(baseAddress + OFS_CECTL1) =
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
//! \param baseAddress is the base address of the COMP_E module.
//! \param supplyVoltageReferenceBase decides the source and max amount of
//!        Voltage that can be used as a reference.
//!        Valid values are:
//!        - \b COMP_E_REFERENCE_AMPLIFIER_DISABLED
//!        - \b COMP_E_VREFBASE1_2V
//!        - \b COMP_E_VREFBASE2_0V
//!        - \b COMP_E_VREFBASE2_5V
//!        \n Modified bits are \b CEREFL of \b CECTL2 register.
//! \param lowerLimitSupplyVoltageFractionOf32 is the numerator of the equation
//!        to generate the reference voltage for the lower limit reference
//!        voltage.
//!        \n Modified bits are \b CEREF0 of \b CECTL2 register.
//! \param upperLimitSupplyVoltageFractionOf32 is the numerator of the equation
//!        to generate the reference voltage for the upper limit reference
//!        voltage.
//!        \n Modified bits are \b CEREF1 of \b CECTL2 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_setReferenceVoltage(uint32_t baseAddress,
                                uint16_t supplyVoltageReferenceBase,
                                uint16_t lowerLimitSupplyVoltageFractionOf32,
                                uint16_t upperLimitSupplyVoltageFractionOf32)
{
        assert(supplyVoltageReferenceBase <= COMP_E_VREFBASE2_5V);
        assert(upperLimitSupplyVoltageFractionOf32 <= 32);
        assert(lowerLimitSupplyVoltageFractionOf32 <= 32);
        assert(upperLimitSupplyVoltageFractionOf32
               >= lowerLimitSupplyVoltageFractionOf32);

        HWREG16(baseAddress + OFS_CECTL1) &= ~(CEMRVS); //Set to VREF0

        //Reset COMPE Control 2 Bits (Except for CERSEL which is set in Comp_Init() )
        HWREG16(baseAddress + OFS_CECTL2) &= CERSEL;

        //Set Voltage Source (Vcc | Vref, resistor ladder or not)
        if (COMP_E_REFERENCE_AMPLIFIER_DISABLED == supplyVoltageReferenceBase)
                HWREG16(baseAddress + OFS_CECTL2) |= CERS_1; //Vcc with resistor ladder
        else if (lowerLimitSupplyVoltageFractionOf32 == 32) {
                //If the lower limit is 32, then the upper limit has to be 32 due to the
                //assertion that upper must be >= to the lower limit. If the numerator is
                //equal to 32, then the equation would be 32/32 == 1, therefore no resistor
                //ladder is needed
                HWREG16(baseAddress + OFS_CECTL2) |= CERS_3;    //Vref, no resistor ladder
        } else
                HWREG16(baseAddress + OFS_CECTL2) |= CERS_2;    //Vref with resistor ladder

        //Set COMPE Control 2 Register
        HWREG16(baseAddress + OFS_CECTL2) |=
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
//! \param baseAddress is the base address of the COMP_E module.
//! \param referenceAccuracy is the reference accuracy setting of the COMP_E.
//!        Valid values are:
//!        - \b COMP_E_ACCURACY_STATIC
//!        - \b COMP_E_ACCURACY_CLOCKED - for low power / low accuracy
//!        \n Modified bits are \b CEREFACC of \b CECTL2 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_setReferenceAccuracy(uint32_t baseAddress,
                                 uint16_t referenceAccuracy)
{
        assert(
                (referenceAccuracy == COMP_E_ACCURACY_STATIC) ||
                (referenceAccuracy == COMP_E_ACCURACY_CLOCKED)
                );

        HWREG16(baseAddress + OFS_CECTL2) &= ~(CEREFACC);
        HWREG16(baseAddress + OFS_CECTL2) |= referenceAccuracy;
}

//*****************************************************************************
//
//! \brief Sets the power mode
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param powerMode decides the power mode
//!        Valid values are:
//!        - \b COMP_E_HIGH_SPEED_MODE
//!        - \b COMP_E_NORMAL_MODE
//!        - \b COMP_E_ULTRA_LOW_POWER_MODE
//!        \n Modified bits are \b CEPWRMD of \b CECTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_setPowerMode(uint32_t baseAddress,
                         uint16_t powerMode)
{
        HWREG16(baseAddress + OFS_CECTL1) &= ~(COMP_E_NORMAL_MODE | COMP_E_ULTRA_LOW_POWER_MODE);

        HWREG16(baseAddress + OFS_CECTL1) |= powerMode;
}

//*****************************************************************************
//
//! \brief Enables selected COMP_E interrupt sources.
//!
//! Enables the indicated COMP_E interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor. <b>Does not clear interrupt flags.</b>
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param interruptMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_E_OUTPUT_INTERRUPT - Output interrupt
//!        - \b COMP_E_INVERTED_POLARITY_INTERRUPT - Output interrupt inverted
//!           polarity
//!        - \b COMP_E_READY_INTERRUPT - Ready interrupt
//!
//! \return None
//
//*****************************************************************************
void COMP_E_enableInterrupt(uint32_t baseAddress,
                            uint16_t interruptMask)
{
        //Set the Interrupt enable bit
        HWREG16(baseAddress + OFS_CEINT) |= interruptMask;
}

//*****************************************************************************
//
//! \brief Disables selected COMP_E interrupt sources.
//!
//! Disables the indicated COMP_E interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param interruptMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_E_OUTPUT_INTERRUPT - Output interrupt
//!        - \b COMP_E_INVERTED_POLARITY_INTERRUPT - Output interrupt inverted
//!           polarity
//!        - \b COMP_E_READY_INTERRUPT - Ready interrupt
//!
//! \return None
//
//*****************************************************************************
void COMP_E_disableInterrupt(uint32_t baseAddress,
                             uint16_t interruptMask)
{
        HWREG16(baseAddress + OFS_CEINT) &= ~(interruptMask);
}

//*****************************************************************************
//
//! \brief Clears COMP_E interrupt flags.
//!
//! The COMP_E interrupt source is cleared, so that it no longer asserts. The
//! highest interrupt flag is automatically cleared when an interrupt vector
//! generator is used.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param interruptFlagMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_E_OUTPUT_INTERRUPT_FLAG - Output interrupt flag
//!        - \b COMP_E_INTERRUPT_FLAG_INVERTED_POLARITY - Output interrupt flag
//!           inverted polarity
//!        - \b COMP_E_INTERRUPT_FLAG_READY - Ready interrupt flag
//!
//! \return None
//
//*****************************************************************************
void COMP_E_clearInterrupt(uint32_t baseAddress,
                           uint16_t interruptFlagMask)
{
        HWREG16(baseAddress + OFS_CEINT) &= ~(interruptFlagMask);
}

//*****************************************************************************
//
//! \brief Gets the current COMP_E interrupt status.
//!
//! This returns the interrupt status for the COMP_E module based on which flag
//! is passed.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param interruptFlagMask
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_E_OUTPUT_INTERRUPT_FLAG - Output interrupt flag
//!        - \b COMP_E_INTERRUPT_FLAG_INVERTED_POLARITY - Output interrupt flag
//!           inverted polarity
//!        - \b COMP_E_INTERRUPT_FLAG_READY - Ready interrupt flag
//!
//! \return Logical OR of any of the following:
//!         - \b COMP_E_OUTPUT_INTERRUPT_FLAG Output interrupt flag
//!         - \b COMP_E_INTERRUPT_FLAG_INVERTED_POLARITY Output interrupt flag
//!         inverted polarity
//!         - \b COMP_E_INTERRUPT_FLAG_READY Ready interrupt flag
//!         \n indicating the status of the masked flags
//
//*****************************************************************************
uint8_t COMP_E_getInterruptStatus(uint32_t baseAddress,
                                  uint16_t interruptFlagMask)
{
        return HWREG16(baseAddress + OFS_CEINT) & interruptFlagMask;
}

//*****************************************************************************
//
//! \brief Explicitly sets the edge direction that would trigger an interrupt.
//!
//! This function will set which direction the output will have to go, whether
//! rising or falling, to generate an interrupt based on a non-inverted
//! interrupt.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param edgeDirection determines which direction the edge would have to go
//!        to generate an interrupt based on the non-inverted interrupt flag.
//!        Valid values are:
//!        - \b COMP_E_FALLINGEDGE [Default] - sets the bit to generate an
//!           interrupt when the output of the COMP_E falls from HIGH to LOW if
//!           the normal interrupt bit is set(and LOW to HIGH if the inverted
//!           interrupt enable bit is set).
//!        - \b COMP_E_RISINGEDGE - sets the bit to generate an interrupt when
//!           the output of the COMP_E rises from LOW to HIGH if the normal
//!           interrupt bit is set(and HIGH to LOW if the inverted interrupt
//!           enable bit is set).
//!        \n Modified bits are \b CEIES of \b CECTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_interruptSetEdgeDirection(uint32_t baseAddress,
                                      uint16_t edgeDirection)
{
        assert(edgeDirection <= COMP_E_RISINGEDGE);

        //Set the edge direction that will trigger an interrupt
        if (COMP_E_RISINGEDGE == edgeDirection)
                HWREG16(baseAddress + OFS_CECTL1) |= CEIES;
        else if (COMP_E_FALLINGEDGE == edgeDirection)
                HWREG16(baseAddress + OFS_CECTL1) &= ~(CEIES);
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
//! \param baseAddress is the base address of the COMP_E module.
//!
//! Modified bits are \b CEIES of \b CECTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_interruptToggleEdgeDirection(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CECTL1) ^= CEIES;
}

//*****************************************************************************
//
//! \brief Turns on the COMP_E module.
//!
//! This function sets the bit that enables the operation of the COMP_E module.
//!
//! \param baseAddress is the base address of the COMP_E module.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_enable(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CECTL1) |= CEON;
}

//*****************************************************************************
//
//! \brief Turns off the COMP_E module.
//!
//! This function clears the CEON bit disabling the operation of the COMP_E
//! module, saving from excess power consumption.
//!
//! \param baseAddress is the base address of the COMP_E module.
//!
//! Modified bits are \b CEON of \b CECTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_disable(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CECTL1) &= ~(CEON);
}

//*****************************************************************************
//
//! \brief Shorts the two input pins chosen during initialization.
//!
//! This function sets the bit that shorts the devices attached to the input
//! pins chosen from the initialization of the COMP_E.
//!
//! \param baseAddress is the base address of the COMP_E module.
//!
//! Modified bits are \b CESHORT of \b CECTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_shortInputs(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CECTL1) |= CESHORT;
}

//*****************************************************************************
//
//! \brief Disables the short of the two input pins chosen during
//! initialization.
//!
//! This function clears the bit that shorts the devices attached to the input
//! pins chosen from the initialization of the COMP_E.
//!
//! \param baseAddress is the base address of the COMP_E module.
//!
//! Modified bits are \b CESHORT of \b CECTL1 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_unshortInputs(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CECTL1) &= ~(CESHORT);
}

//*****************************************************************************
//
//! \brief Disables the input buffer of the selected input port to effectively
//! allow for analog signals.
//!
//! This function sets the bit to disable the buffer for the specified input
//! port to allow for analog signals from any of the COMP_E input pins. This
//! bit is automatically set when the input is initialized to be used with the
//! COMP_E module. This function should be used whenever an analog input is
//! connected to one of these pins to prevent parasitic voltage from causing
//! unexpected results.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param inputPort is the port in which the input buffer will be disabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_E_INPUT0 [Default]
//!        - \b COMP_E_INPUT1
//!        - \b COMP_E_INPUT2
//!        - \b COMP_E_INPUT3
//!        - \b COMP_E_INPUT4
//!        - \b COMP_E_INPUT5
//!        - \b COMP_E_INPUT6
//!        - \b COMP_E_INPUT7
//!        - \b COMP_E_INPUT8
//!        - \b COMP_E_INPUT9
//!        - \b COMP_E_INPUT10
//!        - \b COMP_E_INPUT11
//!        - \b COMP_E_INPUT12
//!        - \b COMP_E_INPUT13
//!        - \b COMP_E_INPUT14
//!        - \b COMP_E_INPUT15
//!        - \b COMP_E_VREF
//!        \n Modified bits are \b CEPDx of \b CECTL3 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_disableInputBuffer(uint32_t baseAddress,
                               uint16_t inputPort)
{
        assert(inputPort <= COMP_E_INPUT15);

        HWREG16(baseAddress + OFS_CECTL3) |= (inputPort);
}

//*****************************************************************************
//
//! \brief Enables the input buffer of the selected input port to allow for
//! digital signals.
//!
//! This function clears the bit to enable the buffer for the specified input
//! port to allow for digital signals from any of the COMP_E input pins. This
//! should not be reset if there is an analog signal connected to the specified
//! input pin to prevent from unexpected results.
//!
//! \param baseAddress is the base address of the COMP_E module.
//! \param inputPort is the port in which the input buffer will be enabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b COMP_E_INPUT0 [Default]
//!        - \b COMP_E_INPUT1
//!        - \b COMP_E_INPUT2
//!        - \b COMP_E_INPUT3
//!        - \b COMP_E_INPUT4
//!        - \b COMP_E_INPUT5
//!        - \b COMP_E_INPUT6
//!        - \b COMP_E_INPUT7
//!        - \b COMP_E_INPUT8
//!        - \b COMP_E_INPUT9
//!        - \b COMP_E_INPUT10
//!        - \b COMP_E_INPUT11
//!        - \b COMP_E_INPUT12
//!        - \b COMP_E_INPUT13
//!        - \b COMP_E_INPUT14
//!        - \b COMP_E_INPUT15
//!        - \b COMP_E_VREF
//!        \n Modified bits are \b CEPDx of \b CECTL3 register.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_enableInputBuffer(uint32_t baseAddress, uint16_t inputPort)
{
        assert(inputPort <= COMP_E_INPUT15);

        HWREG16(baseAddress + OFS_CECTL3) &= ~(inputPort);
}

//*****************************************************************************
//
//! \brief Toggles the bit that swaps which terminals the inputs go to, while
//! also inverting the output of the COMP_E.
//!
//! This function toggles the bit that controls which input goes to which
//! terminal. After initialization, this bit is set to 0, after toggling it
//! once the inputs are routed to the opposite terminal and the output is
//! inverted.
//!
//! \param baseAddress is the base address of the COMP_E module.
//!
//! \return None
//
//*****************************************************************************
void COMP_E_IOSwap(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_CECTL1) ^= CEEX; //Toggle CEEX bit
}

//*****************************************************************************
//
//! \brief Returns the output value of the COMP_E module.
//!
//! Returns the output value of the COMP_E module.
//!
//! \param baseAddress is the base address of the COMP_E module.
//!
//! \return One of the following:
//!         - \b COMP_E_LOW
//!         - \b COMP_E_HIGH
//!         \n indicating the output value of the COMP_E module
//
//*****************************************************************************
uint16_t COMP_E_outputValue(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_CECTL1) & CEOUT;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for comp_e_api
//! @}
//
//*****************************************************************************

#endif
