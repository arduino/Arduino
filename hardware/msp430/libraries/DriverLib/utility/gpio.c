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
// gpio.c - Driver for the gpio Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup gpio_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#if defined(__MSP430_HAS_PORT1_R__) || defined(__MSP430_HAS_PORT2_R__) || \
        defined(__MSP430_HAS_PORTA_R__)
#include "gpio.h"

#include <assert.h>

//*****************************************************************************
//
//! \param selectedPort
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//!
//
//*****************************************************************************
static uint32_t privateGPIOGetBaseAddress(uint8_t selectedPort)
{
        uint32_t baseAddress = 0xFFFF;

        switch (selectedPort) {

#ifdef __MSP430_HAS_PORT1_R__
        case GPIO_PORT_P1: baseAddress = __MSP430_BASEADDRESS_PORT1_R__; break;
#endif
#ifdef __MSP430_HAS_PORT2_R__
        case GPIO_PORT_P2: baseAddress = __MSP430_BASEADDRESS_PORT2_R__; break;
#endif
#ifdef __MSP430_HAS_PORT3_R__
        case GPIO_PORT_P3: baseAddress = __MSP430_BASEADDRESS_PORT3_R__; break;
#endif
#ifdef __MSP430_HAS_PORT4_R__
        case GPIO_PORT_P4: baseAddress = __MSP430_BASEADDRESS_PORT4_R__; break;
#endif
#ifdef __MSP430_HAS_PORT5_R__
        case GPIO_PORT_P5: baseAddress = __MSP430_BASEADDRESS_PORT5_R__; break;
#endif
#ifdef __MSP430_HAS_PORT6_R__
        case GPIO_PORT_P6: baseAddress = __MSP430_BASEADDRESS_PORT6_R__; break;
#endif
#ifdef __MSP430_HAS_PORT7_R__
        case GPIO_PORT_P7: baseAddress = __MSP430_BASEADDRESS_PORT7_R__; break;
#endif
#ifdef __MSP430_HAS_PORT8_R__
        case GPIO_PORT_P8: baseAddress = __MSP430_BASEADDRESS_PORT8_R__; break;
#endif
#ifdef __MSP430_HAS_PORT9_R__
        case GPIO_PORT_P9: baseAddress = __MSP430_BASEADDRESS_PORT9_R__; break;
#endif
#ifdef __MSP430_HAS_PORT10_R__
        case GPIO_PORT_P10: baseAddress = __MSP430_BASEADDRESS_PORT10_R__; break;
#endif
#ifdef __MSP430_HAS_PORT11_R__
        case GPIO_PORT_P11: baseAddress = __MSP430_BASEADDRESS_PORT11_R__; break;
#endif
#ifdef __MSP430_HAS_PORTA_R__
        case GPIO_PORT_PA: baseAddress = __MSP430_BASEADDRESS_PORTA_R__; break;
#endif
#ifdef __MSP430_HAS_PORTB_R__
        case GPIO_PORT_PB: baseAddress = __MSP430_BASEADDRESS_PORTB_R__; break;
#endif
#ifdef __MSP430_HAS_PORTC_R__
        case GPIO_PORT_PC: baseAddress = __MSP430_BASEADDRESS_PORTC_R__; break;
#endif
#ifdef __MSP430_HAS_PORTD_R__
        case GPIO_PORT_PD: baseAddress = __MSP430_BASEADDRESS_PORTD_R__; break;
#endif
#ifdef __MSP430_HAS_PORTE_R__
        case GPIO_PORT_PE: baseAddress = __MSP430_BASEADDRESS_PORTE_R__; break;
#endif
#ifdef __MSP430_HAS_PORTF_R__
        case GPIO_PORT_PF: baseAddress = __MSP430_BASEADDRESS_PORTF_R__; break;
#endif
#ifdef __MSP430_HAS_PORTJ_R__
        case GPIO_PORT_PJ: baseAddress = __MSP430_BASEADDRESS_PORTJ_R__; break;
#endif

        }
        return baseAddress;
}

//*****************************************************************************
//
//! \brief This function configures the selected Pin as output pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsOutputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL0) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PASEL1) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function configures the selected Pin as input pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxREN register and bits of
//! \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL0) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PASEL1) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function configures the peripheral module function in the
//! output direction for the selected pin for either primary, secondary or
//! ternary module function modes
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param mode is the specified mode that the pin should be configured for the
//!        module function.
//!        Valid values are:
//!        - \b GPIO_PRIMARY_MODULE_FUNCTION
//!        - \b GPIO_SECONDARY_MODULE_FUNCTION
//!        - \b GPIO_TERNARY_MODULE_FUNCTION
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsPeripheralModuleFunctionOutputPin(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t mode
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
        {
                switch (mode) {
                case GPIO_PRIMARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P1SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1SEL1) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P1DIR) |= (uint8_t)selectedPins;
                        break;
                case GPIO_SECONDARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P1SEL0) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P1SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1DIR) |= (uint8_t)selectedPins;
                        break;
                case GPIO_TERNARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P1SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1DIR) |= (uint8_t)selectedPins;
                }
                break;
        }
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
        {
                switch (mode) {
                case GPIO_PRIMARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P2SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2SEL1) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P2DIR) |= (uint8_t)selectedPins;
                        break;
                case GPIO_SECONDARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P2SEL0) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P2SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2DIR) |= (uint8_t)selectedPins;
                        break;
                case GPIO_TERNARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P2SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2DIR) |= (uint8_t)selectedPins;
                }
                break;
        }
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
        {
                switch (mode) {
                case GPIO_PRIMARY_MODULE_FUNCTION:
                        HWREG16(baseAddress + OFS_PASEL0) |= selectedPins;
                        HWREG16(baseAddress + OFS_PASEL1) &= ~selectedPins;
                        HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                        break;
                case GPIO_SECONDARY_MODULE_FUNCTION:
                        HWREG16(baseAddress + OFS_PASEL0) &= ~selectedPins;
                        HWREG16(baseAddress + OFS_PASEL1) |= selectedPins;
                        HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                        break;
                case GPIO_TERNARY_MODULE_FUNCTION:
                        HWREG16(baseAddress + OFS_PASEL0) |= selectedPins;
                        HWREG16(baseAddress + OFS_PASEL1) |= selectedPins;
                        HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                }
                break;
        }
        }
}

//*****************************************************************************
//
//! \brief This function configures the peripheral module function in the input
//! direction for the selected pin for either primary, secondary or ternary
//! module function modes.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param mode is the specified mode that the pin should be configured for the
//!        module function.
//!        Valid values are:
//!        - \b GPIO_PRIMARY_MODULE_FUNCTION
//!        - \b GPIO_SECONDARY_MODULE_FUNCTION
//!        - \b GPIO_TERNARY_MODULE_FUNCTION
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsPeripheralModuleFunctionInputPin(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t mode
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
        {
                switch (mode) {
                case GPIO_PRIMARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P1SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1SEL1) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P1DIR) &= (uint8_t) ~selectedPins;
                        break;
                case GPIO_SECONDARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P1SEL0) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P1SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1DIR) &= (uint8_t) ~selectedPins;
                        break;
                case GPIO_TERNARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P1SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P1DIR) &= (uint8_t) ~selectedPins;
                }
                break;
        }
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
        {
                switch (mode) {
                case GPIO_PRIMARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P2SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2SEL1) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P2DIR) &= (uint8_t) ~selectedPins;
                        break;
                case GPIO_SECONDARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P2SEL0) &= (uint8_t) ~selectedPins;
                        HWREG8(baseAddress + OFS_P2SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2DIR) &= (uint8_t) ~selectedPins;
                        break;
                case GPIO_TERNARY_MODULE_FUNCTION:
                        HWREG8(baseAddress + OFS_P2SEL0) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2SEL1) |= (uint8_t)selectedPins;
                        HWREG8(baseAddress + OFS_P2DIR) &= (uint8_t) ~selectedPins;
                }
                break;
        }
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
        {
                switch (mode) {
                case GPIO_PRIMARY_MODULE_FUNCTION:
                        HWREG16(baseAddress + OFS_PASEL0) |= selectedPins;
                        HWREG16(baseAddress + OFS_PASEL1) &= ~selectedPins;
                        HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                        break;
                case GPIO_SECONDARY_MODULE_FUNCTION:
                        HWREG16(baseAddress + OFS_PASEL0) &= ~selectedPins;
                        HWREG16(baseAddress + OFS_PASEL1) |= selectedPins;
                        HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                        break;
                case GPIO_TERNARY_MODULE_FUNCTION:
                        HWREG16(baseAddress + OFS_PASEL0) |= selectedPins;
                        HWREG16(baseAddress + OFS_PASEL1) |= selectedPins;
                        HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                }
                break;
        }
        }
}

//*****************************************************************************
//
//! \brief This function sets output HIGH on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setOutputHighOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets output LOW on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setOutputLowOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function toggles the output on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_toggleOutputOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) ^= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) ^= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) ^= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the selected Pin in input Mode with Pull Down
//! resistor
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxOUT register and bits of
//! \b PxREN register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPinWithPullDownresistor(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) |= (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1OUT) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) |= (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2OUT) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL0) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PASEL1) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) |= selectedPins;
                HWREG16(baseAddress + OFS_PAOUT) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the selected Pin in input Mode with Pull Up
//! resistor
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxOUT register and bits of
//! \b PxREN register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPinWithPullUpresistor(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) |= (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1OUT) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL0) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2SEL1) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) |= (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2OUT) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL0) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PASEL1) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) |= selectedPins;
                HWREG16(baseAddress + OFS_PAOUT) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function gets the input value on the selected pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Valid values are:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! \return One of the following:
//!         - \b GPIO_INPUT_PIN_HIGH
//!         - \b GPIO_INPUT_PIN_LOW
//!         \n indicating the status of the pin
//
//*****************************************************************************
uint8_t GPIO_getInputPinValue(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );

        uint16_t inputPinValue = 0;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                inputPinValue = HWREG8(baseAddress + OFS_P1IN) & ((uint8_t)selectedPins);
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                inputPinValue = HWREG8(baseAddress + OFS_P2IN) & ((uint8_t)selectedPins);
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                inputPinValue = HWREG16(baseAddress + OFS_PAIN) & (selectedPins);
                break;
        }

        if (inputPinValue > 0)
                return GPIO_INPUT_PIN_HIGH;
        return GPIO_INPUT_PIN_LOW;
}

//*****************************************************************************
//
//! \brief This function enables the port interrupt on the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIE register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_enableInterrupt(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1IE) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2IE) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAIE) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function disables the port interrupt on the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIE register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_disableInterrupt(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;
        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1IE) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2IE) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAIE) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function gets the interrupt status of the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! \return Logical OR of any of the following:
//!         - \b GPIO_PIN0
//!         - \b GPIO_PIN1
//!         - \b GPIO_PIN2
//!         - \b GPIO_PIN3
//!         - \b GPIO_PIN4
//!         - \b GPIO_PIN5
//!         - \b GPIO_PIN6
//!         - \b GPIO_PIN7
//!         - \b GPIO_PIN8
//!         - \b GPIO_PIN9
//!         - \b GPIO_PIN10
//!         - \b GPIO_PIN11
//!         - \b GPIO_PIN12
//!         - \b GPIO_PIN13
//!         - \b GPIO_PIN14
//!         - \b GPIO_PIN15
//!         \n indicating the interrupt status of the selected pins [Default:
//!         0]
//
//*****************************************************************************
uint16_t GPIO_getInterruptStatus(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );

        uint8_t returnValue = 0x0;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                returnValue = (HWREG8(baseAddress + OFS_P1IFG) & ((uint8_t)selectedPins));
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                returnValue = (HWREG8(baseAddress + OFS_P2IFG) & ((uint8_t)selectedPins));
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                returnValue = (HWREG16(baseAddress + OFS_PAIFG) & selectedPins);
                break;
        }

        return returnValue;
}

//*****************************************************************************
//
//! \brief This function clears the interrupt flag on the selected pin. Note
//! that only Port 1,2,A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIFG register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_clearInterruptFlag(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1IFG) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2IFG) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAIFG) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function selects on what edge the port interrupt flag should be
//! set for a transition
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param edgeSelect specifies what transition sets the interrupt flag
//!        Valid values are:
//!        - \b GPIO_HIGH_TO_LOW_TRANSITION
//!        - \b GPIO_LOW_TO_HIGH_TRANSITION
//!
//! Modified bits of \b PxIES register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_interruptEdgeSelect(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t edgeSelect
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        assert((edgeSelect == GPIO_HIGH_TO_LOW_TRANSITION) ||
               (edgeSelect == GPIO_LOW_TO_HIGH_TRANSITION)
               );

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG8(baseAddress + OFS_P1IES) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P1IES) |= (uint8_t)selectedPins;
                break;

        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG8(baseAddress + OFS_P2IES) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P2IES) |= (uint8_t)selectedPins;
                break;

        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG16(baseAddress + OFS_PAIES) &= ~selectedPins;
                else
                        HWREG16(baseAddress + OFS_PAIES) |= selectedPins;
                break;
        }
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for gpio_api
//! @}
//
//*****************************************************************************

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
// gpio.c - Driver for the gpio Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup gpio_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_PORT1_R__
#include "gpio.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Private function for determining correct base address
//!
//! Private function for determing correct base address. Called at the
//! beginning of all GPIO functions.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//!
//! \return 0xFFFF if the selectedPort is invalid otherwise the baseAddress
//
//*****************************************************************************
static uint32_t privateGPIOGetBaseAddress(uint8_t selectedPort)
{
        uint32_t baseAddress = 0xFFFF;

        switch (selectedPort) {

#ifdef __MSP430_HAS_PORT1_R__
        case GPIO_PORT_P1: baseAddress = __MSP430_BASEADDRESS_PORT1_R__; break;
#endif
#ifdef __MSP430_HAS_PORT2_R__
        case GPIO_PORT_P2: baseAddress = __MSP430_BASEADDRESS_PORT2_R__; break;
#endif
#ifdef __MSP430_HAS_PORT3_R__
        case GPIO_PORT_P3: baseAddress = __MSP430_BASEADDRESS_PORT3_R__; break;
#endif
#ifdef __MSP430_HAS_PORT4_R__
        case GPIO_PORT_P4: baseAddress = __MSP430_BASEADDRESS_PORT4_R__; break;
#endif
#ifdef __MSP430_HAS_PORT5_R__
        case GPIO_PORT_P5: baseAddress = __MSP430_BASEADDRESS_PORT5_R__; break;
#endif
#ifdef __MSP430_HAS_PORT6_R__
        case GPIO_PORT_P6: baseAddress = __MSP430_BASEADDRESS_PORT6_R__; break;
#endif
#ifdef __MSP430_HAS_PORT7_R__
        case GPIO_PORT_P7: baseAddress = __MSP430_BASEADDRESS_PORT7_R__; break;
#endif
#ifdef __MSP430_HAS_PORT8_R__
        case GPIO_PORT_P8: baseAddress = __MSP430_BASEADDRESS_PORT8_R__; break;
#endif
#ifdef __MSP430_HAS_PORT9_R__
        case GPIO_PORT_P9: baseAddress = __MSP430_BASEADDRESS_PORT9_R__; break;
#endif
#ifdef __MSP430_HAS_PORT10_R__
        case GPIO_PORT_P10: baseAddress = __MSP430_BASEADDRESS_PORT10_R__; break;
#endif
#ifdef __MSP430_HAS_PORT11_R__
        case GPIO_PORT_P11: baseAddress = __MSP430_BASEADDRESS_PORT11_R__; break;
#endif
#ifdef __MSP430_HAS_PORTA_R__
        case GPIO_PORT_PA: baseAddress = __MSP430_BASEADDRESS_PORTA_R__; break;
#endif
#ifdef __MSP430_HAS_PORTB_R__
        case GPIO_PORT_PB: baseAddress = __MSP430_BASEADDRESS_PORTB_R__; break;
#endif
#ifdef __MSP430_HAS_PORTC_R__
        case GPIO_PORT_PC: baseAddress = __MSP430_BASEADDRESS_PORTC_R__; break;
#endif
#ifdef __MSP430_HAS_PORTD_R__
        case GPIO_PORT_PD: baseAddress = __MSP430_BASEADDRESS_PORTD_R__; break;
#endif
#ifdef __MSP430_HAS_PORTE_R__
        case GPIO_PORT_PE: baseAddress = __MSP430_BASEADDRESS_PORTE_R__; break;
#endif
#ifdef __MSP430_HAS_PORTF_R__
        case GPIO_PORT_PF: baseAddress = __MSP430_BASEADDRESS_PORTF_R__; break;
#endif
#ifdef __MSP430_HAS_PORTJ_R__
        case GPIO_PORT_PJ: baseAddress = __MSP430_BASEADDRESS_PORTJ_R__; break;
#endif
        default:
                baseAddress = 0xFFFF;
        }
        return baseAddress;
}

//*****************************************************************************
//
//! \brief This function configures the selected Pin as output pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsOutputPin( uint8_t selectedPort,
                          uint16_t selectedPins
                          )
{

        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {

        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &= (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                break;
        }

}

//*****************************************************************************
//
//! \brief This function configures the selected Pin as input pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function configures the peripheral module function in output
//! direction for the selected pin.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsPeripheralModuleFunctionOutputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) |= selectedPins;
                HWREG16(baseAddress + OFS_PADIR) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function configures the peripheral module function in input
//! direction for the selected pin.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register and bits of \b PxSEL register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsPeripheralModuleFunctionInputPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) |= selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets output HIGH on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setOutputHighOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets output LOW on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setOutputLowOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function toggles the output on the selected Pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxOUT register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_toggleOutputOnPin(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) ||
               (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) ||
               (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) ||
               (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) ||
               (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) ||
               (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) ||
               (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) ||
               (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) ||
               (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1OUT) ^=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2OUT) ^=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PAOUT) ^= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the selected Pin in input Mode with Pull Down
//! resistor
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxOUT register and bits of
//! \b PxREN register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPinWithPullDownresistor(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2OUT) &=  (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) |= selectedPins;
                HWREG16(baseAddress + OFS_PAOUT) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the selected Pin in input Mode with Pull Up
//! resistor
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxDIR register, bits of \b PxOUT register and bits of
//! \b PxREN register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setAsInputPinWithPullUpresistor(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                HWREG8(baseAddress + OFS_P1SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P1REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P1OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                HWREG8(baseAddress + OFS_P2SEL) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2DIR) &=  (uint8_t) ~selectedPins;
                HWREG8(baseAddress + OFS_P2REN) |=  (uint8_t)selectedPins;
                HWREG8(baseAddress + OFS_P2OUT) |=  (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                HWREG16(baseAddress + OFS_PASEL) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PADIR) &= ~selectedPins;
                HWREG16(baseAddress + OFS_PAREN) |= selectedPins;
                HWREG16(baseAddress + OFS_PAOUT) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function gets the input value on the selected pin
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! \return One of the following:
//!         - \b GPIO_INPUT_PIN_HIGH
//!         - \b GPIO_INPUT_PIN_LOW
//!         \n indicating the input value of the pin
//
//*****************************************************************************
uint8_t GPIO_getInputPinValue(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );

        uint16_t inputPinValue = 0;

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                inputPinValue = HWREG8(baseAddress + OFS_P1IN) &  ((uint8_t)selectedPins);
                break;
        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                inputPinValue = HWREG8(baseAddress + OFS_P2IN) & ((uint8_t)selectedPins);
                break;
        case GPIO_PORT_PA:
        case GPIO_PORT_PB:
        case GPIO_PORT_PC:
        case GPIO_PORT_PD:
        case GPIO_PORT_PE:
        case GPIO_PORT_PF:
        case GPIO_PORT_PJ:
        case GPIO_PORT_P11:
                inputPinValue = HWREG16(baseAddress + OFS_PAIN) & selectedPins;
                break;
        }

        if (inputPinValue > 0)
                return GPIO_INPUT_PIN_HIGH;
        return GPIO_INPUT_PIN_LOW;
}

//*****************************************************************************
//
//! \brief This function enables the port interrupt on the selected pin. Note
//! that only Port 1,2, A have this capability. Does not clear interrupt flags.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIE register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_enableInterrupt(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
                HWREG8(baseAddress + OFS_P1IE) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_P2:
                HWREG8(baseAddress + OFS_P2IE) |= (uint8_t)selectedPins;
                break;
        case GPIO_PORT_PA:
                HWREG16(baseAddress + OFS_PAIE) |= selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function disables the port interrupt on the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIE register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_disableInterrupt(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;
        switch (selectedPort) {
        case GPIO_PORT_P1:
                HWREG8(baseAddress + OFS_P1IE) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
                HWREG8(baseAddress + OFS_P2IE) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
                HWREG16(baseAddress + OFS_PAIE) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function gets the interrupt status of the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! \return Logical OR of any of the following:
//!         - \b GPIO_PIN0
//!         - \b GPIO_PIN1
//!         - \b GPIO_PIN2
//!         - \b GPIO_PIN3
//!         - \b GPIO_PIN4
//!         - \b GPIO_PIN5
//!         - \b GPIO_PIN6
//!         - \b GPIO_PIN7
//!         - \b GPIO_PIN8
//!         - \b GPIO_PIN9
//!         - \b GPIO_PIN10
//!         - \b GPIO_PIN11
//!         - \b GPIO_PIN12
//!         - \b GPIO_PIN13
//!         - \b GPIO_PIN14
//!         - \b GPIO_PIN15
//!         \n indicating the interrupt status of the selected pins [Default:
//!         0]
//
//*****************************************************************************
uint16_t GPIO_getInterruptStatus(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );

        uint8_t returnValue = 0x0;

        switch (selectedPort) {
        case GPIO_PORT_P1:
                returnValue = (HWREG8(baseAddress + OFS_P1IFG) & ((uint8_t)selectedPins));
                break;
        case GPIO_PORT_P2:
                returnValue = (HWREG8(baseAddress + OFS_P2IFG) & ((uint8_t)selectedPins));
                break;
        case GPIO_PORT_PA:
                returnValue = (HWREG16(baseAddress + OFS_PAIFG) & ((uint8_t)selectedPins));
                break;
        }

        return returnValue;
}

//*****************************************************************************
//
//! \brief This function clears the interrupt flag on the selected pin. Note
//! that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_PA
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//!
//! Modified bits of \b PxIFG register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_clearInterruptFlag(
        uint8_t selectedPort,
        uint16_t selectedPins
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_PA == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        switch (selectedPort) {
        case GPIO_PORT_P1:
                HWREG8(baseAddress + OFS_P1IFG) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_P2:
                HWREG8(baseAddress + OFS_P2IFG) &= (uint8_t) ~selectedPins;
                break;
        case GPIO_PORT_PA:
                HWREG16(baseAddress + OFS_PAIFG) &= ~selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function selects on what edge the port interrupt flag should be
//! set for a transition Note that only Port 1,2, A have this capability
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param edgeSelect specifies what transition sets the interrupt flag
//!        Valid values are:
//!        - \b GPIO_HIGH_TO_LOW_TRANSITION
//!        - \b GPIO_LOW_TO_HIGH_TRANSITION
//!
//! Modified bits of \b PxIES register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_interruptEdgeSelect(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t edgeSelect
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;

        assert((edgeSelect == GPIO_HIGH_TO_LOW_TRANSITION) ||
               (edgeSelect == GPIO_LOW_TO_HIGH_TRANSITION)
               );

        switch (selectedPort) {
        case GPIO_PORT_P1:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG8(baseAddress + OFS_P1IES) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P1IES) |= (uint8_t)selectedPins;
                break;

        case GPIO_PORT_P2:
                if (GPIO_LOW_TO_HIGH_TRANSITION == edgeSelect)
                        HWREG8(baseAddress + OFS_P2IES) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P2IES) |= (uint8_t)selectedPins;
                break;
        }
}

//*****************************************************************************
//
//! \brief This function sets the drive strength for the selected port pin.
//!
//! \param selectedPort is the selected port.
//!        Valid values are:
//!        - \b GPIO_PORT_P1
//!        - \b GPIO_PORT_P2
//!        - \b GPIO_PORT_P3
//!        - \b GPIO_PORT_P4
//!        - \b GPIO_PORT_P5
//!        - \b GPIO_PORT_P6
//!        - \b GPIO_PORT_P7
//!        - \b GPIO_PORT_P8
//!        - \b GPIO_PORT_P9
//!        - \b GPIO_PORT_P10
//!        - \b GPIO_PORT_P11
//!        - \b GPIO_PORT_PA
//!        - \b GPIO_PORT_PB
//!        - \b GPIO_PORT_PC
//!        - \b GPIO_PORT_PD
//!        - \b GPIO_PORT_PE
//!        - \b GPIO_PORT_PF
//!        - \b GPIO_PORT_PJ
//! \param selectedPins is the specified pin in the selected port.
//!        Mask value is the logical OR of any of the following:
//!        - \b GPIO_PIN0
//!        - \b GPIO_PIN1
//!        - \b GPIO_PIN2
//!        - \b GPIO_PIN3
//!        - \b GPIO_PIN4
//!        - \b GPIO_PIN5
//!        - \b GPIO_PIN6
//!        - \b GPIO_PIN7
//!        - \b GPIO_PIN8
//!        - \b GPIO_PIN9
//!        - \b GPIO_PIN10
//!        - \b GPIO_PIN11
//!        - \b GPIO_PIN12
//!        - \b GPIO_PIN13
//!        - \b GPIO_PIN14
//!        - \b GPIO_PIN15
//! \param driveStrength specifies the drive strength of the pin
//!        Valid values are:
//!        - \b GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH
//!        - \b GPIO_FULL_OUTPUT_DRIVE_STRENGTH
//!
//! Modified bits of \b PxDS register.
//!
//! \return None
//
//*****************************************************************************
void GPIO_setDriveStrength(
        uint8_t selectedPort,
        uint16_t selectedPins,
        uint8_t driveStrength
        )
{
        assert((GPIO_PORT_P1 == selectedPort) || (GPIO_PORT_P2 == selectedPort) ||
               (GPIO_PORT_P3 == selectedPort) || (GPIO_PORT_P4 == selectedPort) ||
               (GPIO_PORT_P5 == selectedPort) || (GPIO_PORT_P6 == selectedPort) ||
               (GPIO_PORT_P7 == selectedPort) || (GPIO_PORT_P8 == selectedPort) ||
               (GPIO_PORT_P9 == selectedPort) || (GPIO_PORT_P10 == selectedPort) ||
               (GPIO_PORT_P11 == selectedPort) || (GPIO_PORT_PA == selectedPort) ||
               (GPIO_PORT_PB == selectedPort) || (GPIO_PORT_PC == selectedPort) ||
               (GPIO_PORT_PD == selectedPort) || (GPIO_PORT_PE == selectedPort) ||
               (GPIO_PORT_PF == selectedPort) || (GPIO_PORT_PJ == selectedPort)
               );

        assert(0x00 != (selectedPins & (GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 +
                                        GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 +
                                        GPIO_PIN6 + GPIO_PIN7 + GPIO_PIN8 +
                                        GPIO_PIN9 + GPIO_PIN10 + GPIO_PIN11 +
                                        GPIO_PIN12 + GPIO_PIN13 + GPIO_PIN14 +
                                        GPIO_PIN15
                                        )));

        uint32_t baseAddress  = privateGPIOGetBaseAddress(selectedPort);

        assert((0xFFFF != baseAddress) );
        if (0xFFFF == baseAddress)
                return;
        assert((driveStrength == GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH) ||
               (driveStrength == GPIO_FULL_OUTPUT_DRIVE_STRENGTH)
               );

        switch (selectedPort) {
        case GPIO_PORT_P1:
        case GPIO_PORT_P3:
        case GPIO_PORT_P5:
        case GPIO_PORT_P7:
        case GPIO_PORT_P9:
                if (GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH == driveStrength)
                        HWREG8(baseAddress + OFS_P1DS) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P1DS) |= (uint8_t)selectedPins;
                break;

        case GPIO_PORT_P2:
        case GPIO_PORT_P4:
        case GPIO_PORT_P6:
        case GPIO_PORT_P8:
        case GPIO_PORT_P10:
                if (GPIO_REDUCED_OUTPUT_DRIVE_STRENGTH == driveStrength)
                        HWREG8(baseAddress + OFS_P2DS) &= (uint8_t) ~selectedPins;
                else
                        HWREG8(baseAddress + OFS_P2DS) |= (uint8_t)selectedPins;
                break;
        }
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for gpio_api
//! @}
//
//*****************************************************************************

#endif
