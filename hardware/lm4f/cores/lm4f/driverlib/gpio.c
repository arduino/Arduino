//*****************************************************************************
//
// gpio.c - API for GPIO ports
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup gpio_api
//! @{
//
//*****************************************************************************

#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
// The base addresses of all the GPIO modules.  Both the APB and AHB apertures
// are provided.
//
//*****************************************************************************
static const unsigned long g_pulGPIOBaseAddrs[] =
{
    GPIO_PORTA_BASE, GPIO_PORTA_AHB_BASE,
    GPIO_PORTB_BASE, GPIO_PORTB_AHB_BASE,
    GPIO_PORTC_BASE, GPIO_PORTC_AHB_BASE,
    GPIO_PORTD_BASE, GPIO_PORTD_AHB_BASE,
    GPIO_PORTE_BASE, GPIO_PORTE_AHB_BASE,
    GPIO_PORTF_BASE, GPIO_PORTF_AHB_BASE,
    GPIO_PORTG_BASE, GPIO_PORTG_AHB_BASE,
    GPIO_PORTH_BASE, GPIO_PORTH_AHB_BASE,
    GPIO_PORTJ_BASE, GPIO_PORTJ_AHB_BASE,
    GPIO_PORTK_BASE, GPIO_PORTK_BASE,
    GPIO_PORTL_BASE, GPIO_PORTL_BASE,
    GPIO_PORTM_BASE, GPIO_PORTM_BASE,
    GPIO_PORTN_BASE, GPIO_PORTN_BASE,
    GPIO_PORTP_BASE, GPIO_PORTP_BASE,
    GPIO_PORTQ_BASE, GPIO_PORTQ_BASE,
};

//*****************************************************************************
//
//! \internal
//! Checks a GPIO base address.
//!
//! \param ulPort is the base address of the GPIO port.
//!
//! This function determines if a GPIO port base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
GPIOBaseValid(unsigned long ulPort)
{
    return((ulPort == GPIO_PORTA_BASE) || (ulPort == GPIO_PORTA_AHB_BASE) ||
           (ulPort == GPIO_PORTB_BASE) || (ulPort == GPIO_PORTB_AHB_BASE) ||
           (ulPort == GPIO_PORTC_BASE) || (ulPort == GPIO_PORTC_AHB_BASE) ||
           (ulPort == GPIO_PORTD_BASE) || (ulPort == GPIO_PORTD_AHB_BASE) ||
           (ulPort == GPIO_PORTE_BASE) || (ulPort == GPIO_PORTE_AHB_BASE) ||
           (ulPort == GPIO_PORTF_BASE) || (ulPort == GPIO_PORTF_AHB_BASE) ||
           (ulPort == GPIO_PORTG_BASE) || (ulPort == GPIO_PORTG_AHB_BASE) ||
           (ulPort == GPIO_PORTH_BASE) || (ulPort == GPIO_PORTH_AHB_BASE) ||
           (ulPort == GPIO_PORTJ_BASE) || (ulPort == GPIO_PORTJ_AHB_BASE) ||
           (ulPort == GPIO_PORTK_BASE) || (ulPort == GPIO_PORTL_BASE) ||
           (ulPort == GPIO_PORTM_BASE) || (ulPort == GPIO_PORTN_BASE) ||
           (ulPort == GPIO_PORTP_BASE) || (ulPort == GPIO_PORTQ_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Gets the GPIO interrupt number.
//!
//! \param ulPort is the base address of the GPIO port.
//!
//! Given a GPIO base address, this function returns the corresponding
//! interrupt number.
//!
//! \return Returns a GPIO interrupt number, or -1 if \e ulPort is invalid.
//
//*****************************************************************************
static long
GPIOGetIntNumber(unsigned long ulPort)
{
    long lInt;

    //
    // Determine the GPIO interrupt number for the given module.
    //
    switch(ulPort)
    {
        case GPIO_PORTA_BASE:
        case GPIO_PORTA_AHB_BASE:
        {
            lInt = INT_GPIOA;
            break;
        }

        case GPIO_PORTB_BASE:
        case GPIO_PORTB_AHB_BASE:
        {
            lInt = INT_GPIOB;
            break;
        }

        case GPIO_PORTC_BASE:
        case GPIO_PORTC_AHB_BASE:
        {
            lInt = INT_GPIOC;
            break;
        }

        case GPIO_PORTD_BASE:
        case GPIO_PORTD_AHB_BASE:
        {
            lInt = INT_GPIOD;
            break;
        }

        case GPIO_PORTE_BASE:
        case GPIO_PORTE_AHB_BASE:
        {
            lInt = INT_GPIOE;
            break;
        }

        case GPIO_PORTF_BASE:
        case GPIO_PORTF_AHB_BASE:
        {
            lInt = INT_GPIOF;
            break;
        }

        case GPIO_PORTG_BASE:
        case GPIO_PORTG_AHB_BASE:
        {
            lInt = INT_GPIOG;
            break;
        }

        case GPIO_PORTH_BASE:
        case GPIO_PORTH_AHB_BASE:
        {
            lInt = INT_GPIOH;
            break;
        }

        case GPIO_PORTJ_BASE:
        case GPIO_PORTJ_AHB_BASE:
        {
            lInt = INT_GPIOJ;
            break;
        }

        case GPIO_PORTK_BASE:
        {
            lInt = INT_GPIOK;
            break;
        }

        case GPIO_PORTL_BASE:
        {
            lInt = INT_GPIOL;
            break;
        }

        case GPIO_PORTM_BASE:
        {
            lInt = INT_GPIOM;
            break;
        }

        case GPIO_PORTN_BASE:
        {
            lInt = INT_GPION;
            break;
        }

        case GPIO_PORTP_BASE:
        {
            lInt = INT_GPIOP0;
            break;
        }

        case GPIO_PORTQ_BASE:
        {
            lInt = INT_GPIOQ0;
            break;
        }

        default:
        {
            return(-1);
        }
    }

    //
    // Return GPIO interrupt number.
    //
    return(lInt);
}

//*****************************************************************************
//
//! Sets the direction and mode of the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! \param ucPins is the bit-packed representation of the pin(s).
//! \param ulPinIO is the pin direction and/or mode.
//!
//! This function configures the specified pin(s) on the selected GPIO port
//! as either input or output under software control, or it configures the
//! pin to be under hardware control.
//!
//! The parameter \e ulPinIO is an enumerated data type that can be one of
//! the following values:
//!
//! - \b GPIO_DIR_MODE_IN
//! - \b GPIO_DIR_MODE_OUT
//! - \b GPIO_DIR_MODE_HW
//!
//! where \b GPIO_DIR_MODE_IN specifies that the pin is programmed as a
//! software controlled input, \b GPIO_DIR_MODE_OUT specifies that the pin is
//! programmed as a software controlled output, and \b GPIO_DIR_MODE_HW
//! specifies that the pin is placed under hardware control.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note GPIOPadConfigSet() must also be used to configure the corresponding
//! pad(s) in order for them to propagate the signal to/from the GPIO.
//!
//! \return None.
//
//*****************************************************************************
void
GPIODirModeSet(unsigned long ulPort, unsigned char ucPins,
               unsigned long ulPinIO)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));
    ASSERT((ulPinIO == GPIO_DIR_MODE_IN) || (ulPinIO == GPIO_DIR_MODE_OUT) ||
           (ulPinIO == GPIO_DIR_MODE_HW));

    //
    // Set the pin direction and mode.
    //
    HWREG(ulPort + GPIO_O_DIR) = ((ulPinIO & 1) ?
                                  (HWREG(ulPort + GPIO_O_DIR) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_DIR) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_AFSEL) = ((ulPinIO & 2) ?
                                    (HWREG(ulPort + GPIO_O_AFSEL) | ucPins) :
                                    (HWREG(ulPort + GPIO_O_AFSEL) &
                                     ~(ucPins)));
}

//*****************************************************************************
//
//! Gets the direction and mode of a pin.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPin is the pin number.
//!
//! This function gets the direction and control mode for a specified pin on
//! the selected GPIO port.  The pin can be configured as either an input or
//! output under software control, or it can be under hardware control.  The
//! type of control and direction are returned as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIODirModeSet().
//
//*****************************************************************************
unsigned long
GPIODirModeGet(unsigned long ulPort, unsigned char ucPin)
{
    unsigned long ulDir, ulAFSEL;

    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));
    ASSERT(ucPin < 8);

    //
    // Convert from a pin number to a bit position.
    //
    ucPin = 1 << ucPin;

    //
    // Return the pin direction and mode.
    //
    ulDir = HWREG(ulPort + GPIO_O_DIR);
    ulAFSEL = HWREG(ulPort + GPIO_O_AFSEL);
    return(((ulDir & ucPin) ? 1 : 0) | ((ulAFSEL & ucPin) ? 2 : 0));
}

//*****************************************************************************
//
//! Sets the interrupt type for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//! \param ulIntType specifies the type of interrupt trigger mechanism.
//!
//! This function sets up the various interrupt trigger mechanisms for the
//! specified pin(s) on the selected GPIO port.
//!
//! The parameter \e ulIntType is an enumerated data type that can be one of
//! the following values:
//!
//! - \b GPIO_FALLING_EDGE
//! - \b GPIO_RISING_EDGE
//! - \b GPIO_BOTH_EDGES
//! - \b GPIO_LOW_LEVEL
//! - \b GPIO_HIGH_LEVEL
//! - \b GPIO_DISCRETE_INT
//!
//! where the different values describe the interrupt detection mechanism
//! (edge or level) and the particular triggering event (falling, rising,
//! or both edges for edge detect, low or high for level detect).
//!
//! Some devices also support discrete interrupts for each pin on a GPIO port,
//! giving each pin a separate interrupt vector.  To use this feature, the
//! \b GPIO_DISCRETE_INT can be included to enable an interrupt per pin.  The
//! \b GPIO_DISCRETE_INT is not available on all devices or all GPIO ports,
//! consult the data sheet to ensure that the device and the GPIO port supports
//! discrete interrupts.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note In order to avoid any spurious interrupts, the user must
//! ensure that the GPIO inputs remain stable for the duration of
//! this function.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOIntTypeSet(unsigned long ulPort, unsigned char ucPins,
               unsigned long ulIntType)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));
    ASSERT((ulIntType == GPIO_FALLING_EDGE) ||
           (ulIntType == GPIO_RISING_EDGE) || (ulIntType == GPIO_BOTH_EDGES) ||
           (ulIntType == GPIO_LOW_LEVEL) || (ulIntType == GPIO_HIGH_LEVEL));

    //
    // Set the pin interrupt type.
    //
    HWREG(ulPort + GPIO_O_IBE) = ((ulIntType & 1) ?
                                  (HWREG(ulPort + GPIO_O_IBE) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_IBE) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_IS) = ((ulIntType & 2) ?
                                 (HWREG(ulPort + GPIO_O_IS) | ucPins) :
                                 (HWREG(ulPort + GPIO_O_IS) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_IEV) = ((ulIntType & 4) ?
                                  (HWREG(ulPort + GPIO_O_IEV) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_IEV) & ~(ucPins)));
}

//*****************************************************************************
//
//! Gets the interrupt type for a pin.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPin is the pin number.
//!
//! This function gets the interrupt type for a specified pin on the selected
//! GPIO port.  The pin can be configured as a falling-edge, rising-edge, or
//! both-edges detected interrupt, or it can be configured as a low-level or
//! high-level detected interrupt.  The type of interrupt detection mechanism
//! is returned as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIOIntTypeSet().
//
//*****************************************************************************
unsigned long
GPIOIntTypeGet(unsigned long ulPort, unsigned char ucPin)
{
    unsigned long ulIBE, ulIS, ulIEV;

    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));
    ASSERT(ucPin < 8);

    //
    // Convert from a pin number to a bit position.
    //
    ucPin = 1 << ucPin;

    //
    // Return the pin interrupt type.
    //
    ulIBE = HWREG(ulPort + GPIO_O_IBE);
    ulIS = HWREG(ulPort + GPIO_O_IS);
    ulIEV = HWREG(ulPort + GPIO_O_IEV);
    return(((ulIBE & ucPin) ? 1 : 0) | ((ulIS & ucPin) ? 2 : 0) |
           ((ulIEV & ucPin) ? 4 : 0));
}

//*****************************************************************************
//
//! Sets the pad configuration for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//! \param ulStrength specifies the output drive strength.
//! \param ulPinType specifies the pin type.
//!
//! This function sets the drive strength and type for the specified pin(s)
//! on the selected GPIO port.  For pin(s) configured as input ports, the
//! pad is configured as requested, but the only real effect on the input
//! is the configuration of the pull-up or pull-down termination.
//!
//! The parameter \e ulStrength can be one of the following values:
//!
//! - \b GPIO_STRENGTH_2MA
//! - \b GPIO_STRENGTH_4MA
//! - \b GPIO_STRENGTH_8MA
//! - \b GPIO_STRENGTH_8MA_SC
//!
//! where \b GPIO_STRENGTH_xMA specifies either 2, 4, or 8 mA output drive
//! strength, and \b GPIO_OUT_STRENGTH_8MA_SC specifies 8 mA output drive with
//! slew control.
//!
//! Some Stellaris devices also support output drive strengths of 6, 10, and 12
//! mA.
//!
//! The parameter \e ulPinType can be one of the following values:
//!
//! - \b GPIO_PIN_TYPE_STD
//! - \b GPIO_PIN_TYPE_STD_WPU
//! - \b GPIO_PIN_TYPE_STD_WPD
//! - \b GPIO_PIN_TYPE_OD
//! - \b GPIO_PIN_TYPE_OD_WPU
//! - \b GPIO_PIN_TYPE_OD_WPD
//! - \b GPIO_PIN_TYPE_ANALOG
//!
//! where \b GPIO_PIN_TYPE_STD* specifies a push-pull pin, \b GPIO_PIN_TYPE_OD*
//! specifies an open-drain pin, \b *_WPU specifies a weak pull-up, \b *_WPD
//! specifies a weak pull-down, and \b GPIO_PIN_TYPE_ANALOG specifies an analog
//! input.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPadConfigSet(unsigned long ulPort, unsigned char ucPins,
                 unsigned long ulStrength, unsigned long ulPinType)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));
    ASSERT((ulStrength == GPIO_STRENGTH_2MA) ||
           (ulStrength == GPIO_STRENGTH_4MA) ||
           (ulStrength == GPIO_STRENGTH_8MA) ||
           (ulStrength == GPIO_STRENGTH_8MA_SC));
    ASSERT((ulPinType == GPIO_PIN_TYPE_STD) ||
           (ulPinType == GPIO_PIN_TYPE_STD_WPU) ||
           (ulPinType == GPIO_PIN_TYPE_STD_WPD) ||
           (ulPinType == GPIO_PIN_TYPE_OD) ||
           (ulPinType == GPIO_PIN_TYPE_OD_WPU) ||
           (ulPinType == GPIO_PIN_TYPE_OD_WPD) ||
           (ulPinType == GPIO_PIN_TYPE_ANALOG));

    //
    // Set the output drive strength.
    //
    HWREG(ulPort + GPIO_O_DR2R) = ((ulStrength & 1) ?
                                   (HWREG(ulPort + GPIO_O_DR2R) | ucPins) :
                                   (HWREG(ulPort + GPIO_O_DR2R) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_DR4R) = ((ulStrength & 2) ?
                                   (HWREG(ulPort + GPIO_O_DR4R) | ucPins) :
                                   (HWREG(ulPort + GPIO_O_DR4R) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_DR8R) = ((ulStrength & 4) ?
                                   (HWREG(ulPort + GPIO_O_DR8R) | ucPins) :
                                   (HWREG(ulPort + GPIO_O_DR8R) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_SLR) = ((ulStrength & 8) ?
                                  (HWREG(ulPort + GPIO_O_SLR) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_SLR) & ~(ucPins)));

    //
    // Set the pin type.
    //
    HWREG(ulPort + GPIO_O_ODR) = ((ulPinType & 1) ?
                                  (HWREG(ulPort + GPIO_O_ODR) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_ODR) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_PUR) = ((ulPinType & 2) ?
                                  (HWREG(ulPort + GPIO_O_PUR) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_PUR) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_PDR) = ((ulPinType & 4) ?
                                  (HWREG(ulPort + GPIO_O_PDR) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_PDR) & ~(ucPins)));
    HWREG(ulPort + GPIO_O_DEN) = ((ulPinType & 8) ?
                                  (HWREG(ulPort + GPIO_O_DEN) | ucPins) :
                                  (HWREG(ulPort + GPIO_O_DEN) & ~(ucPins)));

    //
    // Set the analog mode select register.  This register only appears in
    // DustDevil-class (and later) devices, but is a harmless write on
    // Sandstorm- and Fury-class devices.
    //
    HWREG(ulPort + GPIO_O_AMSEL) =
        ((ulPinType == GPIO_PIN_TYPE_ANALOG) ?
         (HWREG(ulPort + GPIO_O_AMSEL) | ucPins) :
         (HWREG(ulPort + GPIO_O_AMSEL) & ~(ucPins)));
}

//*****************************************************************************
//
//! Gets the pad configuration for a pin.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPin is the pin number.
//! \param pulStrength is a pointer to storage for the output drive strength.
//! \param pulPinType is a pointer to storage for the output drive type.
//!
//! This function gets the pad configuration for a specified pin on the
//! selected GPIO port.  The values returned in \e pulStrength and
//! \e pulPinType correspond to the values used in GPIOPadConfigSet().  This
//! function also works for pin(s) configured as input pin(s); however, the
//! only meaningful data returned is whether the pin is terminated with a
//! pull-up or down resistor.
//!
//! \return None
//
//*****************************************************************************
void
GPIOPadConfigGet(unsigned long ulPort, unsigned char ucPin,
                 unsigned long *pulStrength, unsigned long *pulPinType)
{
    unsigned long ulPinType, ulStrength;

    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));
    ASSERT(ucPin < 8);

    //
    // Convert from a pin number to a bit position.
    //
    ucPin = (1 << ucPin);

    //
    // Get the drive strength for this pin.
    //
    ulStrength = ((HWREG(ulPort + GPIO_O_DR2R) & ucPin) ? 1 : 0);
    ulStrength |= ((HWREG(ulPort + GPIO_O_DR4R) & ucPin) ? 2 : 0);
    ulStrength |= ((HWREG(ulPort + GPIO_O_DR8R) & ucPin) ? 4 : 0);
    ulStrength |= ((HWREG(ulPort + GPIO_O_SLR) & ucPin) ? 8 : 0);
    *pulStrength = ulStrength;

    //
    // Get the pin type.
    //
    ulPinType = ((HWREG(ulPort + GPIO_O_ODR) & ucPin) ? 1 : 0);
    ulPinType |= ((HWREG(ulPort + GPIO_O_PUR) & ucPin) ? 2 : 0);
    ulPinType |= ((HWREG(ulPort + GPIO_O_PDR) & ucPin) ? 4 : 0);
    ulPinType |= ((HWREG(ulPort + GPIO_O_DEN) & ucPin) ? 8 : 0);
    *pulPinType = ulPinType;
}

//*****************************************************************************
//
//! Enables interrupts for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! Unmasks the interrupt for the specified pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinIntEnable(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Enable the interrupts.
    //
    HWREG(ulPort + GPIO_O_IM) |= ucPins;
}

//*****************************************************************************
//
//! Disables interrupts for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! Masks the interrupt for the specified pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinIntDisable(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Disable the interrupts.
    //
    HWREG(ulPort + GPIO_O_IM) &= ~(ucPins);
}

//*****************************************************************************
//
//! Gets interrupt status for the specified GPIO port.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param bMasked specifies whether masked or raw interrupt status is
//! returned.
//!
//! If \e bMasked is set as \b true, then the masked interrupt status is
//! returned; otherwise, the raw interrupt status is returned.
//!
//! \return Returns a bit-packed byte, where each bit that is set identifies
//! an active masked or raw interrupt, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//! Bits 31:8 should be ignored.
//
//*****************************************************************************
long
GPIOPinIntStatus(unsigned long ulPort, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Return the interrupt status.
    //
    if(bMasked)
    {
        return(HWREG(ulPort + GPIO_O_MIS));
    }
    else
    {
        return(HWREG(ulPort + GPIO_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears the interrupt for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! Clears the interrupt for the specified pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinIntClear(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Clear the interrupts.
    //
    HWREG(ulPort + GPIO_O_ICR) = ucPins;
}

//*****************************************************************************
//
//! Registers an interrupt handler for a GPIO port.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param pfnIntHandler is a pointer to the GPIO port interrupt handling
//! function.
//!
//! This function ensures that the interrupt handler specified by
//! \e pfnIntHandler is called when an interrupt is detected from the selected
//! GPIO port.  This function also enables the corresponding GPIO interrupt
//! in the interrupt controller; individual pin interrupts and interrupt
//! sources must be enabled with GPIOPinIntEnable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPortIntRegister(unsigned long ulPort, void (*pfnIntHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Get the interrupt number associated with the specified GPIO.
    //
    ulPort = GPIOGetIntNumber(ulPort);

    //
    // Register the interrupt handler.
    //
    IntRegister(ulPort, pfnIntHandler);

    //
    // Enable the GPIO interrupt.
    //
    IntEnable(ulPort);
}

//*****************************************************************************
//
//! Removes an interrupt handler for a GPIO port.
//!
//! \param ulPort is the base address of the GPIO port.
//!
//! This function unregisters the interrupt handler for the specified
//! GPIO port.  This function also disables the corresponding
//! GPIO port interrupt in the interrupt controller; individual GPIO interrupts
//! and interrupt sources must be disabled with GPIOPinIntDisable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPortIntUnregister(unsigned long ulPort)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Get the interrupt number associated with the specified GPIO.
    //
    ulPort = GPIOGetIntNumber(ulPort);

    //
    // Disable the GPIO interrupt.
    //
    IntDisable(ulPort);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ulPort);
}

//*****************************************************************************
//
//! Reads the values present of the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The values at the specified pin(s) are read, as specified by \e ucPins.
//! Values are returned for both input and output pin(s), and the value
//! for pin(s) that are not specified by \e ucPins are set to 0.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return Returns a bit-packed byte providing the state of the specified
//! pin, where bit 0 of the byte represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, and so on.  Any bit that is not specified by \e ucPins
//! is returned as a 0.  Bits 31:8 should be ignored.
//
//*****************************************************************************
long
GPIOPinRead(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Return the pin value(s).
    //
    return(HWREG(ulPort + (GPIO_O_DATA + (ucPins << 2))));
}

//*****************************************************************************
//
//! Writes a value to the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//! \param ucVal is the value to write to the pin(s).
//!
//! Writes the corresponding bit values to the output pin(s) specified by
//! \e ucPins.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinWrite(unsigned long ulPort, unsigned char ucPins, unsigned char ucVal)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Write the pins.
    //
    HWREG(ulPort + (GPIO_O_DATA + (ucPins << 2))) = ucVal;
}

//*****************************************************************************
//
//! Configures pin(s) for use as analog-to-digital converter inputs.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The analog-to-digital converter input pins must be properly configured
//! to function correctly on devices that are not Sandstorm- or Fury-class.
//! This function provides the proper configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an ADC input; it
//! only configures an ADC input pin for proper operation.  Devices with
//! flexible pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeADC(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures pin(s) for use as a CAN device.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The CAN pins must be properly configured for the CAN peripherals to
//! function correctly.  This function provides a typical configuration for
//! those pin(s); other configurations may work as well depending upon the
//! board setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a CAN pin; it only
//! configures a CAN pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeCAN(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as an analog comparator input.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The analog comparator input pins must be properly configured for the analog
//! comparator to function correctly.  This function provides the proper
//! configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an analog comparator
//! input; it only configures an analog comparator pin for proper operation.
//! Devices with flexible pin muxing also require a GPIOPinConfigure()
//! function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeComparator(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the external peripheral interface.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The external peripheral interface pins must be properly configured for the
//! external peripheral interface to function correctly.  This function
//! provides a typical configuration for those pin(s); other configurations may
//! work as well depending upon the board setup (for example, using the on-chip
//! pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an external
//! peripheral interface pin; it only configures an external peripheral
//! interface pin for proper operation.  Devices with flexible pin muxing also
//! require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeEPI(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the Ethernet peripheral as LED signals.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The Ethernet peripheral provides two signals that can be used to drive
//! an LED (e.g. for link status/activity).  This function provides a typical
//! configuration for the pins.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an Ethernet LED
//! pin; it only configures an Ethernet LED pin for proper operation.  Devices
//! with flexible pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeEthernetLED(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the Ethernet peripheral as MII signals.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The Ethernet peripheral on some parts provides a set of MII signals that
//! are used to connect to an external PHY.  This function provides a typical
//! configuration for the pins.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an Ethernet MII
//! pin; it only configures an Ethernet MII pin for proper operation.  Devices
//! with flexible pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeEthernetMII(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the fan module.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The fan pins must be properly configured for the fan controller to function
//! correctly.  This function provides a typical configuration for those
//! pin(s); other configurations may work as well depending upon the board
//! setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a fan pin; it only
//! configures a fan pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeFan(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as GPIO inputs.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! GPIO inputs; this is especially true of Fury-class devices where the
//! digital input enable is turned off by default.  This function provides the
//! proper configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeGPIOInput(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as GPIO outputs.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! GPIO outputs; this is especially true of Fury-class devices where the
//! digital input enable is turned off by default.  This function provides the
//! proper configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeGPIOOutput(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);

    //
    // Make the pin(s) be outputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
//! Configures pin(s) for use as GPIO open drain outputs.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! GPIO outputs; this is especially true of Fury-class devices where the
//! digital input enable is turned off by default.  This function provides the
//! proper configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeGPIOOutputOD(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD);

    //
    // Make the pin(s) be outputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the I2C peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The I2C pins must be properly configured for the I2C peripheral to function
//! correctly.  This function provides the proper configuration for those
//! pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an I2C pin; it
//! only configures an I2C pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeI2C(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for open-drain operation with a weak pull-up.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD_WPU);
}

//*****************************************************************************
//
//! Configures pin(s) for use as SCL by the I2C peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The I2C pins must be properly configured for the I2C peripheral to function
//! correctly.  This function provides the proper configuration for the SCL
//! pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function should only be used for Blizzard-class devices.  It
//! cannot be used to turn any pin into an I2C SCL pin; it only configures an
//! I2C SCL pin for proper operation.  Devices with flexible pin muxing also
//! require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeI2CSCL(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for open-drain operation with a weak pull-up.
    //
    if(CLASS_IS_SANDSTORM || CLASS_IS_FURY || CLASS_IS_DUSTDEVIL ||
       CLASS_IS_TEMPEST || CLASS_IS_FIRESTORM)
    {
        GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD);
    }
    else
    {
        GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    }
}

//*****************************************************************************
//
//! Configures pin(s) for use by the I2S peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! Some I2S pins must be properly configured for the I2S peripheral to
//! function correctly.  This function provides a typical configuration for
//! the digital I2S pin(s); other configurations may work as well depending
//! upon the board setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a I2S pin; it only
//! configures a I2S pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeI2S(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the LPC module.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The LPC pins must be properly configured for the LPC module to function
//! correctly.  This function provides a typical configuration for those
//! pin(s); other configurations may work as well depending upon the board
//! setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an LPC pin; it only
//! configures an LPC pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeLPC(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures a pin for receive use by the PECI module.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The PECI receive pin must be properly configured for the PECI module to
//! function correctly.  This function provides a typical configuration for
//! that pin.
//!
//! The pin is specified using a bit-packed byte, where each bit that is set
//! identifies the pin to be accessed, and where bit 0 of the byte represents
//! GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a PECI receive pin;
//! it only configures a PECI receive pin for proper operation.  Devices with
//! flexible pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypePECIRx(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures a pin for transmit use by the PECI module.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The PECI transmit pin must be properly configured for the PECI module to
//! function correctly.  This function provides a typical configuration for
//! that pin.
//!
//! The pin is specified using a bit-packed byte, where each bit that is set
//! identifies the pin to be accessed, and where bit 0 of the byte represents
//! GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a PECI transmit
//! pin; it only configures a PECI transmit pin for proper operation.  Devices
//! with flexible pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypePECITx(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the PWM peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The PWM pins must be properly configured for the PWM peripheral to function
//! correctly.  This function provides a typical configuration for those
//! pin(s); other configurations may work as well depending upon the board
//! setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a PWM pin; it only
//! configures a PWM pin for proper operation.  Devices wtih flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypePWM(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the QEI peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The QEI pins must be properly configured for the QEI peripheral to function
//! correctly.  This function provides a typical configuration for those
//! pin(s); other configurations may work as well depending upon the board
//! setup (for example, not using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a QEI pin; it only
//! configures a QEI pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeQEI(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation with a weak pull-up.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the SSI peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The SSI pins must be properly configured for the SSI peripheral to function
//! correctly.  This function provides a typical configuration for those
//! pin(s); other configurations may work as well depending upon the board
//! setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a SSI pin; it only
//! configures a SSI pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeSSI(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the Timer peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The CCP pins must be properly configured for the timer peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin(s); other configurations may work as well depending upon the
//! board setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a timer pin; it
//! only configures a timer pin for proper operation.  Devices with flexible
//! pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeTimer(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the UART peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! The UART pins must be properly configured for the UART peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin(s); other configurations may work as well depending upon the
//! board setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a UART pin; it
//! only configures a UART pin for proper operation.  Devices with flexible
//! pin muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeUART(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the USB peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! Some USB analog pins must be properly configured for the USB peripheral to
//! function correctly.  This function provides the proper configuration for
//! any USB pin(s).  This can also be used to configure the EPEN and PFAULT pins
//! so that they are no longer used by the USB controller.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a USB pin; it only
//! configures a USB pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeUSBAnalog(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the USB peripheral.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! Some USB digital pins must be properly configured for the USB peripheral to
//! function correctly.  This function provides a typical configuration for
//! the digital USB pin(s); other configurations may work as well depending
//! upon the board setup (for example, using the on-chip pull-ups).
//!
//! This function should only be used with EPEN and PFAULT pins as all other
//! USB pins are analog in nature or are not used in devices without OTG
//! functionality.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a USB pin; it only
//! configures a USB pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeUSBDigital(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ulPort, ucPins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ulPort, ucPins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures the alternate function of a GPIO pin.
//!
//! \param ulPinConfig is the pin configuration value, specified as only one of
//! the \b GPIO_P??_??? values.
//!
//! This function configures the pin mux that selects the peripheral function
//! associated with a particular GPIO pin.  Only one peripheral function at a
//! time can be associated with a GPIO pin, and each peripheral function should
//! only be associated with a single GPIO pin at a time (despite the fact that
//! many of them can be associated with more than one GPIO pin). To fully
//! configure a pin, a GPIOPinType*() function should also be called.
//!
//! The available mappings are supplied on a per-device basis in
//! <tt>pin_map.h</tt>.  The \b PART_IS_<partno> define enables the
//! appropriate set of defines for the device that is being used.
//!
//! \note This function is not valid on Sandstorm, Fury, and Dustdevil-class
//! devices. Also, if the same signal is assigned to two different GPIO port
//! pins, the signal is assigned to the port with the lowest letter and the
//! assignment to the higher letter port is ignored.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinConfigure(unsigned long ulPinConfig)
{
    unsigned long ulBase, ulShift;

    //
    // Check the argument.
    //
    ASSERT(((ulPinConfig >> 16) & 0xff) < 15);
    ASSERT(((ulPinConfig >> 8) & 0xe3) == 0);

    //
    // Extract the base address index from the input value.
    //
    ulBase = (ulPinConfig >> 16) & 0xff;

    //
    // Get the base address of the GPIO module, selecting either the APB or the
    // AHB aperture as appropriate.
    //
    if(HWREG(SYSCTL_GPIOHBCTL) & (1 << ulBase))
    {
        ulBase = g_pulGPIOBaseAddrs[(ulBase << 1) + 1];
    }
    else
    {
        ulBase = g_pulGPIOBaseAddrs[ulBase << 1];
    }

    //
    // Extract the shift from the input value.
    //
    ulShift = (ulPinConfig >> 8) & 0xff;

    //
    // Write the requested pin muxing value for this GPIO pin.
    //
    HWREG(ulBase + GPIO_O_PCTL) = ((HWREG(ulBase + GPIO_O_PCTL) &
                                    ~(0xf << ulShift)) |
                                   ((ulPinConfig & 0xf) << ulShift));
}

//*****************************************************************************
//
//! Enables a GPIO pin as a trigger to start a DMA transaction.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! This function enables a GPIO pin to be used as a trigger to start a uDMA
//! transaction.  Any GPIO pin can be configured to be an external trigger for
//! the uDMA.  The GPIO pin still generates interrupts if the interrupt is
//! enabled for the selected pin.
//!
//! \note This function is not available on all devices, consult the data sheet
//! to ensure that the device you are using supports GPIO DMA Control.
//!
//! \return None.
//
//*****************************************************************************
void
GPIODMATriggerEnable(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ulPort + GPIO_O_DMACTL) |= ucPins;
}

//*****************************************************************************
//
//! Disables a GPIO pin as a trigger to start a DMA transaction.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! This function disables a GPIO pin from being used as a trigger to start a
//! uDMA transaction.  This function can be used to disable this feature if it
//! was enabled via a call to GPIODMATriggerEnable().
//!
//! \note This function is not available on all devices, consult the data sheet
//! to ensure that the device you are using supports GPIO DMA Control.
//!
//! \return None.
//
//*****************************************************************************
void
GPIODMATriggerDisable(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ulPort + GPIO_O_DMACTL) &= (~ucPins);
}

//*****************************************************************************
//
//! Enables a GPIO pin as a trigger to start an ADC capture.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! This function enables a GPIO pin to be used as a trigger to start an ADC
//! sequence.  Any GPIO pin can be configured to be an external trigger for
//! an ADC sequence.  The GPIO pin still generates interrupts if the
//! interrupt is enabled for the selected pin. To enable the use of a GPIO pin
//! to trigger the ADC module, the ADCSequenceConfigure() function must be called
//! with the ADC_TRIGGER_EXTERNAL parameter.
//!
//! \note This function is not available on all devices, consult the data sheet
//! to ensure that the device you are using supports GPIO ADC Control.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOADCTriggerEnable(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ulPort + GPIO_O_ADCCTL) |= ucPins;
}

//*****************************************************************************
//
//! Disable a GPIO pin as a trigger to start an ADC capture.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ucPins is the bit-packed representation of the pin(s).
//!
//! This function disables a GPIO pin to be used as a trigger to start an ADC
//! sequence.  This function can be used to disable this feature if it was
//! enabled via a call to GPIOADCTriggerEnable().
//!
//! \note This function is not available on all devices, consult the data sheet
//! to ensure that the device you are using supports GPIO ADC Control.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOADCTriggerDisable(unsigned long ulPort, unsigned char ucPins)
{
    //
    // Check the arguments.
    //
    ASSERT(GPIOBaseValid(ulPort));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ulPort + GPIO_O_ADCCTL) &= (~ucPins);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
