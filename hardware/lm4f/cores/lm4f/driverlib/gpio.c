//*****************************************************************************
//
// gpio.c - API for GPIO ports
//
// Copyright (c) 2005-2013 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup gpio_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
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
// A mapping of GPIO port address to interrupt number.
//
//*****************************************************************************
static const uint32_t g_ppui32GPIOIntMapBlizzard[][2] =
{
    { GPIO_PORTA_BASE, INT_GPIOA_BLIZZARD },
    { GPIO_PORTA_AHB_BASE, INT_GPIOA_BLIZZARD },
    { GPIO_PORTB_BASE, INT_GPIOB_BLIZZARD },
    { GPIO_PORTB_AHB_BASE, INT_GPIOB_BLIZZARD },
    { GPIO_PORTC_BASE, INT_GPIOC_BLIZZARD },
    { GPIO_PORTC_AHB_BASE, INT_GPIOC_BLIZZARD },
    { GPIO_PORTD_BASE,  INT_GPIOD_BLIZZARD },
    { GPIO_PORTD_AHB_BASE, INT_GPIOD_BLIZZARD },
    { GPIO_PORTE_BASE, INT_GPIOE_BLIZZARD },
    { GPIO_PORTE_AHB_BASE, INT_GPIOE_BLIZZARD },
    { GPIO_PORTF_BASE, INT_GPIOF_BLIZZARD },
    { GPIO_PORTF_AHB_BASE, INT_GPIOF_BLIZZARD },
    { GPIO_PORTG_BASE, INT_GPIOG_BLIZZARD },
    { GPIO_PORTG_AHB_BASE, INT_GPIOG_BLIZZARD },
    { GPIO_PORTH_BASE, INT_GPIOH_BLIZZARD },
    { GPIO_PORTH_AHB_BASE, INT_GPIOH_BLIZZARD },
    { GPIO_PORTJ_BASE, INT_GPIOJ_BLIZZARD },
    { GPIO_PORTJ_AHB_BASE, INT_GPIOJ_BLIZZARD },
    { GPIO_PORTK_BASE, INT_GPIOK_BLIZZARD },
    { GPIO_PORTL_BASE, INT_GPIOL_BLIZZARD },
    { GPIO_PORTM_BASE, INT_GPIOM_BLIZZARD },
    { GPIO_PORTN_BASE, INT_GPION_BLIZZARD },
    { GPIO_PORTP_BASE, INT_GPIOP0_BLIZZARD },
    { GPIO_PORTQ_BASE, INT_GPIOQ0_BLIZZARD },
};
static const uint_fast32_t g_ui32GPIOIntMapBlizzardRows =
    sizeof(g_ppui32GPIOIntMapBlizzard) / sizeof(g_ppui32GPIOIntMapBlizzard[0]);

static const uint32_t g_ppui32GPIOIntMapSnowflake[][2] =
{
    { GPIO_PORTA_BASE, INT_GPIOA_SNOWFLAKE },
    { GPIO_PORTA_AHB_BASE, INT_GPIOA_SNOWFLAKE },
    { GPIO_PORTB_BASE, INT_GPIOB_SNOWFLAKE },
    { GPIO_PORTB_AHB_BASE, INT_GPIOB_SNOWFLAKE },
    { GPIO_PORTC_BASE, INT_GPIOC_SNOWFLAKE },
    { GPIO_PORTC_AHB_BASE, INT_GPIOC_SNOWFLAKE },
    { GPIO_PORTD_BASE,  INT_GPIOD_SNOWFLAKE },
    { GPIO_PORTD_AHB_BASE, INT_GPIOD_SNOWFLAKE },
    { GPIO_PORTE_BASE, INT_GPIOE_SNOWFLAKE },
    { GPIO_PORTE_AHB_BASE, INT_GPIOE_SNOWFLAKE },
    { GPIO_PORTF_BASE, INT_GPIOF_SNOWFLAKE },
    { GPIO_PORTF_AHB_BASE, INT_GPIOF_SNOWFLAKE },
    { GPIO_PORTG_BASE, INT_GPIOG_SNOWFLAKE },
    { GPIO_PORTG_AHB_BASE, INT_GPIOG_SNOWFLAKE },
    { GPIO_PORTH_BASE, INT_GPIOH_SNOWFLAKE },
    { GPIO_PORTH_AHB_BASE, INT_GPIOH_SNOWFLAKE },
    { GPIO_PORTJ_BASE, INT_GPIOJ_SNOWFLAKE },
    { GPIO_PORTJ_AHB_BASE, INT_GPIOJ_SNOWFLAKE },
    { GPIO_PORTK_BASE, INT_GPIOK_SNOWFLAKE },
    { GPIO_PORTL_BASE, INT_GPIOL_SNOWFLAKE },
    { GPIO_PORTM_BASE, INT_GPIOM_SNOWFLAKE },
    { GPIO_PORTN_BASE, INT_GPION_SNOWFLAKE },
    { GPIO_PORTP_BASE, INT_GPIOP0_SNOWFLAKE },
    { GPIO_PORTQ_BASE, INT_GPIOQ0_SNOWFLAKE },
};
static const uint_fast32_t g_ui32GPIOIntMapSnowflakeRows =
    (sizeof(g_ppui32GPIOIntMapSnowflake) /
     sizeof(g_ppui32GPIOIntMapSnowflake[0]));

//*****************************************************************************
//
// The base addresses of all the GPIO modules.  Both the APB and AHB apertures
// are provided.
//
//*****************************************************************************
static const uint32_t g_pui32GPIOBaseAddrs[] =
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
    GPIO_PORTR_BASE, GPIO_PORTR_BASE,
    GPIO_PORTS_BASE, GPIO_PORTS_BASE,
    GPIO_PORTT_BASE, GPIO_PORTT_BASE,
};

//*****************************************************************************
//
//! \internal
//! Checks a GPIO base address.
//!
//! \param ui32Port is the base address of the GPIO port.
//!
//! This function determines if a GPIO port base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_GPIOBaseValid(uint32_t ui32Port)
{
    return((ui32Port == GPIO_PORTA_BASE) ||
           (ui32Port == GPIO_PORTA_AHB_BASE) ||
           (ui32Port == GPIO_PORTB_BASE) ||
           (ui32Port == GPIO_PORTB_AHB_BASE) ||
           (ui32Port == GPIO_PORTC_BASE) ||
           (ui32Port == GPIO_PORTC_AHB_BASE) ||
           (ui32Port == GPIO_PORTD_BASE) ||
           (ui32Port == GPIO_PORTD_AHB_BASE) ||
           (ui32Port == GPIO_PORTE_BASE) ||
           (ui32Port == GPIO_PORTE_AHB_BASE) ||
           (ui32Port == GPIO_PORTF_BASE) ||
           (ui32Port == GPIO_PORTF_AHB_BASE) ||
           (ui32Port == GPIO_PORTG_BASE) ||
           (ui32Port == GPIO_PORTG_AHB_BASE) ||
           (ui32Port == GPIO_PORTH_BASE) ||
           (ui32Port == GPIO_PORTH_AHB_BASE) ||
           (ui32Port == GPIO_PORTJ_BASE) ||
           (ui32Port == GPIO_PORTJ_AHB_BASE) ||
           (ui32Port == GPIO_PORTK_BASE) ||
           (ui32Port == GPIO_PORTL_BASE) ||
           (ui32Port == GPIO_PORTM_BASE) ||
           (ui32Port == GPIO_PORTN_BASE) ||
           (ui32Port == GPIO_PORTP_BASE) ||
           (ui32Port == GPIO_PORTQ_BASE) ||
           (ui32Port == GPIO_PORTR_BASE) ||
           (ui32Port == GPIO_PORTS_BASE) ||
           (ui32Port == GPIO_PORTT_BASE));
}
#endif

//*****************************************************************************
//
//! Gets the GPIO interrupt number.
//!
//! \param ui32Port is the base address of the GPIO port.
//!
//! Given a GPIO base address, this function returns the corresponding
//! interrupt number.
//!
//! \return Returns a GPIO interrupt number, or 0 if \e ui32Port is invalid.
//
//*****************************************************************************
static uint32_t
_GPIOIntNumberGet(uint32_t ui32Port)
{
    uint_fast32_t ui32Idx, ui32Rows;
    const uint32_t (*ppui32GPIOIntMap)[2];

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    ppui32GPIOIntMap = g_ppui32GPIOIntMapBlizzard;
    ui32Rows = g_ui32GPIOIntMapBlizzardRows;

    if(CLASS_IS_SNOWFLAKE)
    {
        ppui32GPIOIntMap = g_ppui32GPIOIntMapSnowflake;
        ui32Rows = g_ui32GPIOIntMapSnowflakeRows;
    }

    //
    // Loop through the table that maps I2C base addresses to interrupt
    // numbers.
    //
    for(ui32Idx = 0; ui32Idx < ui32Rows; ui32Idx++)
    {
        //
        // See if this base address matches.
        //
        if(ppui32GPIOIntMap[ui32Idx][0] == ui32Port)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(ppui32GPIOIntMap[ui32Idx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(0);
}

//*****************************************************************************
//
//! Sets the direction and mode of the specified pin(s).
//!
//! \param ui32Port is the base address of the GPIO port
//! \param ui8Pins is the bit-packed representation of the pin(s).
//! \param ui32PinIO is the pin direction and/or mode.
//!
//! This function configures the specified pin(s) on the selected GPIO port
//! as either input or output under software control, or it configures the
//! pin to be under hardware control.
//!
//! The parameter \e ui32PinIO is an enumerated data type that can be one of
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
GPIODirModeSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32PinIO)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));
    ASSERT((ui32PinIO == GPIO_DIR_MODE_IN) ||
           (ui32PinIO == GPIO_DIR_MODE_OUT) ||
           (ui32PinIO == GPIO_DIR_MODE_HW));

    //
    // Set the pin direction and mode.
    //
    HWREG(ui32Port + GPIO_O_DIR) = ((ui32PinIO & 1) ?
                                    (HWREG(ui32Port + GPIO_O_DIR) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_DIR) & ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_AFSEL) = ((ui32PinIO & 2) ?
                                      (HWREG(ui32Port + GPIO_O_AFSEL) |
                                       ui8Pins) :
                                      (HWREG(ui32Port + GPIO_O_AFSEL) &
                                       ~(ui8Pins)));
}

//*****************************************************************************
//
//! Gets the direction and mode of a pin.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pin is the pin number.
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
uint32_t
GPIODirModeGet(uint32_t ui32Port, uint8_t ui8Pin)
{
    uint32_t ui32Dir, ui32AFSEL;

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));
    ASSERT(ui8Pin < 8);

    //
    // Convert from a pin number to a bit position.
    //
    ui8Pin = 1 << ui8Pin;

    //
    // Return the pin direction and mode.
    //
    ui32Dir = HWREG(ui32Port + GPIO_O_DIR);
    ui32AFSEL = HWREG(ui32Port + GPIO_O_AFSEL);
    return(((ui32Dir & ui8Pin) ? 1 : 0) | ((ui32AFSEL & ui8Pin) ? 2 : 0));
}

//*****************************************************************************
//
//! Sets the interrupt type for the specified pin(s).
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//! \param ui32IntType specifies the type of interrupt trigger mechanism.
//!
//! This function sets up the various interrupt trigger mechanisms for the
//! specified pin(s) on the selected GPIO port.
//!
//! One of the following flags can be used to define the \e ui32IntType
//! parameter:
//!
//! - \b GPIO_FALLING_EDGE sets detection to edge and trigger to falling
//! - \b GPIO_RISING_EDGE sets detection to edge and trigger to rising
//! - \b GPIO_BOTH_EDGES sets detection to both edges
//! - \b GPIO_LOW_LEVEL sets detection to low level
//! - \b GPIO_HIGH_LEVEL sets detection to high level
//!
//! In addition to the above flags, the following flag can be OR'd in to the
//! \e ui32IntType parameter:
//!
//! - \b GPIO_DISCRETE_INT sets discrete interrupts for each pin on a GPIO
//! port.
//!
//! The \b GPIO_DISCRETE_INT is not available on all devices or all GPIO ports,
//! consult the data sheet to ensure that the device and the GPIO port supports
//! discrete interrupts.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note In order to avoid any spurious interrupts, the user must ensure that
//! the GPIO inputs remain stable for the duration of this function.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOIntTypeSet(uint32_t ui32Port, uint8_t ui8Pins,
               uint32_t ui32IntType)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));
    ASSERT((ui32IntType == GPIO_FALLING_EDGE) ||
           (ui32IntType == GPIO_RISING_EDGE) ||
           (ui32IntType == GPIO_BOTH_EDGES) ||
           (ui32IntType == GPIO_LOW_LEVEL) ||
           (ui32IntType == GPIO_HIGH_LEVEL));

    //
    // Set the pin interrupt type.
    //
    HWREG(ui32Port + GPIO_O_IBE) = ((ui32IntType & 1) ?
                                    (HWREG(ui32Port + GPIO_O_IBE) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_IBE) & ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_IS) = ((ui32IntType & 2) ?
                                   (HWREG(ui32Port + GPIO_O_IS) | ui8Pins) :
                                   (HWREG(ui32Port + GPIO_O_IS) & ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_IEV) = ((ui32IntType & 4) ?
                                    (HWREG(ui32Port + GPIO_O_IEV) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_IEV) & ~(ui8Pins)));

    //
    // Set or clear the discrete interrupt feature.  This is not available
    // on all parts or ports but is safe to write in all cases.
    //
    HWREG(ui32Port + GPIO_O_SI) = ((ui32IntType & 0x10000) ?
                                   (HWREG(ui32Port + GPIO_O_SI) | 0x01) :
                                   (HWREG(ui32Port + GPIO_O_SI) & ~(0x01)));
}

//*****************************************************************************
//
//! Gets the interrupt type for a pin.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pin is the pin number.
//!
//! This function gets the interrupt type for a specified pin on the selected
//! GPIO port.  The pin can be configured as a falling-edge, rising-edge, or
//! both-edges detected interrupt, or it can be configured as a low-level or
//! high-level detected interrupt.  The type of interrupt detection mechanism
//! is returned and can include the \b GPIO_DISCRETE_INT flag.
//!
//! \return Returns one of the flags described for GPIOIntTypeSet().
//
//*****************************************************************************
uint32_t
GPIOIntTypeGet(uint32_t ui32Port, uint8_t ui8Pin)
{
    uint32_t ui32IBE, ui32IS, ui32IEV, ui32SI;

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));
    ASSERT(ui8Pin < 8);

    //
    // Convert from a pin number to a bit position.
    //
    ui8Pin = 1 << ui8Pin;

    //
    // Return the pin interrupt type.
    //
    ui32IBE = HWREG(ui32Port + GPIO_O_IBE);
    ui32IS = HWREG(ui32Port + GPIO_O_IS);
    ui32IEV = HWREG(ui32Port + GPIO_O_IEV);
    ui32SI = HWREG(ui32Port + GPIO_O_SI);
    return(((ui32IBE & ui8Pin) ? 1 : 0) | ((ui32IS & ui8Pin) ? 2 : 0) |
           ((ui32IEV & ui8Pin) ? 4 : 0) | (ui32SI & 0x01) ? 0x10000 : 0);
}

//*****************************************************************************
//
//! Sets the pad configuration for the specified pin(s).
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//! \param ui32Strength specifies the output drive strength.
//! \param ui32PinType specifies the pin type.
//!
//! This function sets the drive strength and type for the specified pin(s)
//! on the selected GPIO port.  For pin(s) configured as input ports, the
//! pad is configured as requested, but the only real effect on the input
//! is the configuration of the pull-up or pull-down termination.
//!
//! The parameter \e ui32Strength can be one of the following values:
//!
//! - \b GPIO_STRENGTH_2MA
//! - \b GPIO_STRENGTH_4MA
//! - \b GPIO_STRENGTH_8MA
//! - \b GPIO_STRENGTH_8MA_SC
//! - \b GPIO_STRENGTH_6MA
//! - \b GPIO_STRENGTH_10MA
//! - \b GPIO_STRENGTH_12MA
//!
//! where \b GPIO_STRENGTH_xMA specifies either 2, 4, or 8 mA output drive
//! strength, and \b GPIO_OUT_STRENGTH_8MA_SC specifies 8 mA output drive with
//! slew control.
//!
//! Some Tiva devices also support output drive strengths of 6, 10, and 12
//! mA.
//!
//! The parameter \e ui32PinType can be one of the following values:
//!
//! - \b GPIO_PIN_TYPE_STD
//! - \b GPIO_PIN_TYPE_STD_WPU
//! - \b GPIO_PIN_TYPE_STD_WPD
//! - \b GPIO_PIN_TYPE_OD
//! - \b GPIO_PIN_TYPE_ANALOG
//! - \b GPIO_PIN_TYPE_WAKE_HIGH
//! - \b GPIO_PIN_TYPE_WAKE_LOW
//!
//! where \b GPIO_PIN_TYPE_STD* specifies a push-pull pin, \b GPIO_PIN_TYPE_OD*
//! specifies an open-drain pin, \b *_WPU specifies a weak pull-up, \b *_WPD
//! specifies a weak pull-down, and \b GPIO_PIN_TYPE_ANALOG specifies an analog
//! input.
//!
//! The \b GPIO_PIN_TYPE_WAKE_* settings specify the pin to be used as a
//! hibernation wake source.  The pin sense level can be high or low.  These
//! settings are only available on some Tiva devices.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPadConfigSet(uint32_t ui32Port, uint8_t ui8Pins,
                 uint32_t ui32Strength, uint32_t ui32PinType)
{
    uint8_t ui8Bit;

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));
    ASSERT((ui32Strength == GPIO_STRENGTH_2MA) ||
           (ui32Strength == GPIO_STRENGTH_4MA) ||
           (ui32Strength == GPIO_STRENGTH_6MA) ||
           (ui32Strength == GPIO_STRENGTH_8MA) ||
           (ui32Strength == GPIO_STRENGTH_8MA_SC) ||
           (ui32Strength == GPIO_STRENGTH_10MA) ||
           (ui32Strength == GPIO_STRENGTH_12MA));
    ASSERT((ui32PinType == GPIO_PIN_TYPE_STD) ||
           (ui32PinType == GPIO_PIN_TYPE_STD_WPU) ||
           (ui32PinType == GPIO_PIN_TYPE_STD_WPD) ||
           (ui32PinType == GPIO_PIN_TYPE_OD) ||
           (ui32PinType == GPIO_PIN_TYPE_WAKE_LOW) ||
           (ui32PinType == GPIO_PIN_TYPE_WAKE_HIGH) ||
           (ui32PinType == GPIO_PIN_TYPE_ANALOG));

    //
    // Set the output drive strength.
    //
    HWREG(ui32Port + GPIO_O_DR2R) = ((ui32Strength & 1) ?
                                     (HWREG(ui32Port + GPIO_O_DR2R) |
                                      ui8Pins) :
                                     (HWREG(ui32Port + GPIO_O_DR2R) &
                                      ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_DR4R) = ((ui32Strength & 2) ?
                                     (HWREG(ui32Port + GPIO_O_DR4R) |
                                      ui8Pins) :
                                     (HWREG(ui32Port + GPIO_O_DR4R) &
                                      ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_DR8R) = ((ui32Strength & 4) ?
                                     (HWREG(ui32Port + GPIO_O_DR8R) |
                                      ui8Pins) :
                                     (HWREG(ui32Port + GPIO_O_DR8R) &
                                      ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_SLR) = ((ui32Strength & 8) ?
                                    (HWREG(ui32Port + GPIO_O_SLR) |
                                     ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_SLR) &
                                     ~(ui8Pins)));

    //
    // Set the 12-mA drive select register and the GPIO peripheral
    // configuration register.  These registers only appear in Flurry-class
    // (and later) devices, but are harmless writes on older devices.
    //
    HWREG(ui32Port + GPIO_O_DR12R) = ((ui32Strength & 0x10) ?
                                      (HWREG(ui32Port + GPIO_O_DR12R) |
                                       ui8Pins) :
                                      (HWREG(ui32Port + GPIO_O_DR12R) &
                                       ~(ui8Pins)));
    //
    // Walk pins 0-7 and clear or set the provided PC[EDMn] encoding.
    //
    for(ui8Bit = 0; ui8Bit < 8; ui8Bit++)
    {
        if(ui8Pins & (1 << ui8Bit))
        {
            HWREG(ui32Port + GPIO_O_PC) = (HWREG(ui32Port + GPIO_O_PC) &
                                           ~(0x3 << (2 * ui8Bit)));
            HWREG(ui32Port + GPIO_O_PC) |= (((ui32Strength >> 5) & 0x3) <<
                                            (2 * ui8Bit));
        }
    }

    //
    // Set the pin type.
    //
    HWREG(ui32Port + GPIO_O_ODR) = ((ui32PinType & 1) ?
                                    (HWREG(ui32Port + GPIO_O_ODR) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_ODR) & ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_PUR) = ((ui32PinType & 2) ?
                                    (HWREG(ui32Port + GPIO_O_PUR) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_PUR) & ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_PDR) = ((ui32PinType & 4) ?
                                    (HWREG(ui32Port + GPIO_O_PDR) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_PDR) & ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_DEN) = ((ui32PinType & 8) ?
                                    (HWREG(ui32Port + GPIO_O_DEN) | ui8Pins) :
                                    (HWREG(ui32Port + GPIO_O_DEN) & ~(ui8Pins)));

    //
    // Set the wake pin enable register and the wake level register.
    // These registers only appear in Flurry-class (and later) devices, but
    // are harmless writes on older devices.
    //
    HWREG(ui32Port + GPIO_O_WAKELVL) = ((ui32PinType & 0x200) ?
                                        (HWREG(ui32Port + GPIO_O_WAKELVL) |
                                         ui8Pins) :
                                        (HWREG(ui32Port + GPIO_O_WAKELVL) &
                                         ~(ui8Pins)));
    HWREG(ui32Port + GPIO_O_WAKEPEN) = ((ui32PinType & 0x300) ?
                                        (HWREG(ui32Port + GPIO_O_WAKEPEN) |
                                         ui8Pins) :
                                        (HWREG(ui32Port + GPIO_O_WAKEPEN) &
                                         ~(ui8Pins)));

    //
    // Set the analog mode select register.
    //
    HWREG(ui32Port + GPIO_O_AMSEL) =
        ((ui32PinType == GPIO_PIN_TYPE_ANALOG) ?
         (HWREG(ui32Port + GPIO_O_AMSEL) | ui8Pins) :
         (HWREG(ui32Port + GPIO_O_AMSEL) & ~(ui8Pins)));
}

//*****************************************************************************
//
//! Gets the pad configuration for a pin.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pin is the pin number.
//! \param pui32Strength is a pointer to storage for the output drive strength.
//! \param pui32PinType is a pointer to storage for the output drive type.
//!
//! This function gets the pad configuration for a specified pin on the
//! selected GPIO port.  The values returned in \e pui32Strength and
//! \e pui32PinType correspond to the values used in GPIOPadConfigSet().  This
//! function also works for pin(s) configured as input pin(s); however, the
//! only meaningful data returned is whether the pin is terminated with a
//! pull-up or down resistor.
//!
//! \return None
//
//*****************************************************************************
void
GPIOPadConfigGet(uint32_t ui32Port, uint8_t ui8Pin,
                 uint32_t *pui32Strength, uint32_t *pui32PinType)
{
    uint32_t ui32PinType, ui32Strength;

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));
    ASSERT(ui8Pin < 8);

    //
    // Convert from a pin number to a bit position.
    //
    ui8Pin = (1 << ui8Pin);

    //
    // Get the drive strength for this pin.
    //
    ui32Strength = ((HWREG(ui32Port + GPIO_O_DR2R) & ui8Pin) ? 1 : 0);
    ui32Strength |= ((HWREG(ui32Port + GPIO_O_DR4R) & ui8Pin) ? 2 : 0);
    ui32Strength |= ((HWREG(ui32Port + GPIO_O_DR8R) & ui8Pin) ? 4 : 0);
    ui32Strength |= ((HWREG(ui32Port + GPIO_O_SLR) & ui8Pin) ? 8 : 0);
    ui32Strength |= ((HWREG(ui32Port + GPIO_O_DR12R) & ui8Pin) ? 0x10 : 0);
    ui32Strength |= (((HWREG(ui32Port + GPIO_O_PC) >>
                       (2 * ui8Pin)) & 0x3) << 5);
    *pui32Strength = ui32Strength;

    //
    // Get the pin type.
    //
    ui32PinType = ((HWREG(ui32Port + GPIO_O_ODR) & ui8Pin) ? 1 : 0);
    ui32PinType |= ((HWREG(ui32Port + GPIO_O_PUR) & ui8Pin) ? 2 : 0);
    ui32PinType |= ((HWREG(ui32Port + GPIO_O_PDR) & ui8Pin) ? 4 : 0);
    ui32PinType |= ((HWREG(ui32Port + GPIO_O_DEN) & ui8Pin) ? 8 : 0);
    if(HWREG(ui32Port + GPIO_O_WAKEPEN) & ui8Pin)
    {
        ui32PinType |= ((HWREG(ui32Port + GPIO_O_WAKELVL) & ui8Pin) ?
                        0x200 : 0x100);
    }
    *pui32PinType = ui32PinType;
}

//*****************************************************************************
//
//! Enables the specified GPIO interrupts.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui32IntFlags is the bit mask of the interrupt sources to enable.
//!
//! This function enables the indicated GPIO interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b GPIO_INT_PIN_0 - interrupt due to activity on Pin 0.
//! - \b GPIO_INT_PIN_1 - interrupt due to activity on Pin 1.
//! - \b GPIO_INT_PIN_2 - interrupt due to activity on Pin 2.
//! - \b GPIO_INT_PIN_3 - interrupt due to activity on Pin 3.
//! - \b GPIO_INT_PIN_4 - interrupt due to activity on Pin 4.
//! - \b GPIO_INT_PIN_5 - interrupt due to activity on Pin 5.
//! - \b GPIO_INT_PIN_6 - interrupt due to activity on Pin 6.
//! - \b GPIO_INT_PIN_7 - interrupt due to activity on Pin 7.
//! - \b GPIO_INT_DMA - interrupt due to DMA activity on this GPIO module.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOIntEnable(uint32_t ui32Port, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Enable the interrupts.
    //
    HWREG(ui32Port + GPIO_O_IM) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables the specified GPIO interrupts.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui32IntFlags is the bit mask of the interrupt sources to disable.
//!
//! This function disables the indicated GPIO interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b GPIO_INT_PIN_0 - interrupt due to activity on Pin 0.
//! - \b GPIO_INT_PIN_1 - interrupt due to activity on Pin 1.
//! - \b GPIO_INT_PIN_2 - interrupt due to activity on Pin 2.
//! - \b GPIO_INT_PIN_3 - interrupt due to activity on Pin 3.
//! - \b GPIO_INT_PIN_4 - interrupt due to activity on Pin 4.
//! - \b GPIO_INT_PIN_5 - interrupt due to activity on Pin 5.
//! - \b GPIO_INT_PIN_6 - interrupt due to activity on Pin 6.
//! - \b GPIO_INT_PIN_7 - interrupt due to activity on Pin 7.
//! - \b GPIO_INT_DMA - interrupt due to DMA activity on this GPIO module.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOIntDisable(uint32_t ui32Port, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Disable the interrupts.
    //
    HWREG(ui32Port + GPIO_O_IM) &= ~(ui32IntFlags);
}

//*****************************************************************************
//
//! Gets interrupt status for the specified GPIO port.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param bMasked specifies whether masked or raw interrupt status is
//! returned.
//!
//! If \e bMasked is set as \b true, then the masked interrupt status is
//! returned; otherwise, the raw interrupt status is returned.
//!
//! \return Returns the current interrupt status for the specified GPIO module.
//! The value returned is the logical OR of the \b GPIO_INT_* values that are
//! currently active.
//
//*****************************************************************************
uint32_t
GPIOIntStatus(uint32_t ui32Port, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Return the interrupt status.
    //
    if(bMasked)
    {
        return(HWREG(ui32Port + GPIO_O_MIS));
    }
    else
    {
        return(HWREG(ui32Port + GPIO_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears the specified interrupt sources.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui32IntFlags is the bit mask of the interrupt sources to disable.
//!
//! Clears the interrupt for the specified interrupt source(s).
//!
//! The \e ui32IntFlags parameter is the logical OR of the \b GPIO_INT_*
//! values.
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
GPIOIntClear(uint32_t ui32Port, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Clear the interrupts.
    //
    HWREG(ui32Port + GPIO_O_ICR) = ui32IntFlags;
}

//*****************************************************************************
//
//! Registers an interrupt handler for a GPIO port.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param pfnIntHandler is a pointer to the GPIO port interrupt handling
//! function.
//!
//! This function ensures that the interrupt handler specified by
//! \e pfnIntHandler is called when an interrupt is detected from the selected
//! GPIO port.  This function also enables the corresponding GPIO interrupt
//! in the interrupt controller; individual pin interrupts and interrupt
//! sources must be enabled with GPIOIntEnable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOIntRegister(uint32_t ui32Port, void (*pfnIntHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Get the interrupt number associated with the specified GPIO.
    //
    ui32Int = _GPIOIntNumberGet(ui32Port);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnIntHandler);

    //
    // Enable the GPIO interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Removes an interrupt handler for a GPIO port.
//!
//! \param ui32Port is the base address of the GPIO port.
//!
//! This function unregisters the interrupt handler for the specified
//! GPIO port.  This function also disables the corresponding
//! GPIO port interrupt in the interrupt controller; individual GPIO interrupts
//! and interrupt sources must be disabled with GPIOIntDisable().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOIntUnregister(uint32_t ui32Port)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Get the interrupt number associated with the specified GPIO.
    //
    ui32Int = _GPIOIntNumberGet(ui32Port);

    ASSERT(ui32Int != 0);

    //
    // Disable the GPIO interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Reads the values present of the specified pin(s).
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The values at the specified pin(s) are read, as specified by \e ui8Pins.
//! Values are returned for both input and output pin(s), and the value
//! for pin(s) that are not specified by \e ui8Pins are set to 0.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return Returns a bit-packed byte providing the state of the specified
//! pin, where bit 0 of the byte represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, and so on.  Any bit that is not specified by \e ui8Pins
//! is returned as a 0.  Bits 31:8 should be ignored.
//
//*****************************************************************************
int32_t
GPIOPinRead(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Return the pin value(s).
    //
    return(HWREG(ui32Port + (GPIO_O_DATA + (ui8Pins << 2))));
}

//*****************************************************************************
//
//! Writes a value to the specified pin(s).
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//! \param ui8Val is the value to write to the pin(s).
//!
//! Writes the corresponding bit values to the output pin(s) specified by
//! \e ui8Pins.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinWrite(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Write the pins.
    //
    HWREG(ui32Port + (GPIO_O_DATA + (ui8Pins << 2))) = ui8Val;
}

//*****************************************************************************
//
//! Configures pin(s) for use as analog-to-digital converter inputs.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The analog-to-digital converter input pins must be properly configured for
//! the analog-to-digital peripheral to function correctly.  This function
//! provides the proper configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an ADC input; it
//! only configures an ADC input pin for proper operation.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeADC(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures pin(s) for use as a CAN device.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeCAN(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as an analog comparator input.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The analog comparator input pins must be properly configured for the analog
//! comparator to function correctly.  This function provides the proper
//! configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an analog
//! comparator input; it only configures an analog comparator pin for proper
//! operation.  Devices with flexible pin muxing also require a
//! GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeComparator(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the external peripheral interface.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeEPI(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the Ethernet peripheral as LED signals.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The Ethernet peripheral provides two signals that can be used to drive
//! an LED (for example, for link status/activity).  This function provides a
//! typical configuration for the pins.
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
GPIOPinTypeEthernetLED(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the Ethernet peripheral as MII signals.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeEthernetMII(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the fan module.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeFan(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as GPIO inputs.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! GPIO inputs.  This function provides the proper configuration for those
//! pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeGPIOInput(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as GPIO outputs.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! GPIO outputs.  This function provides the proper configuration for those
//! pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeGPIOOutput(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);

    //
    // Make the pin(s) be outputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
//! Configures pin(s) for use as GPIO open drain outputs.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! GPIO outputs.  This function provides the proper configuration for those
//! pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeGPIOOutputOD(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD);

    //
    // Make the pin(s) be outputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_OUT);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the I2C peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeI2C(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for open-drain operation with a weak pull-up.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as SCL by the I2C peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeI2CSCL(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the LCD Controller.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The LCD controller pins must be properly configured for the LCD controller
//! to function correctly.  This function provides a typical configuration for
//! those pin(s); other configurations may work as well depending upon the
//! board setup (for example, using the on-chip pull-ups).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an LCD pin; it only
//! configures an LCD pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeLCD(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation and beefed up drive.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the LPC module.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeLPC(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures a pin for receive use by the PECI module.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypePECIRx(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures a pin for transmit use by the PECI module.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypePECITx(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the PWM peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypePWM(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the QEI peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeQEI(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation with a weak pull-up.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_STD_WPU);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the SSI peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeSSI(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the Timer peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeTimer(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the UART peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeUART(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the USB peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! Some USB analog pins must be properly configured for the USB peripheral to
//! function correctly.  This function provides the proper configuration for
//! any USB pin(s).  This can also be used to configure the EPEN and PFAULT
//! pins so that they are no longer used by the USB controller.
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
GPIOPinTypeUSBAnalog(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for analog operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_ANALOG);
}

//*****************************************************************************
//
//! Configures pin(s) for use by the USB peripheral.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOPinTypeUSBDigital(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as a hibernate wake-on-high source.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! hibernate wake-high inputs.  This function provides the proper
//! configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeWakeHigh(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for wake-high operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_WAKE_HIGH);
}

//*****************************************************************************
//
//! Configures pin(s) for use as a hibernate wake-on-low source.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! hibernate wake-low inputs.  This function provides the proper
//! configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeWakeLow(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) inputs.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_IN);

    //
    // Set the pad(s) for wake-high operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_WAKE_LOW);
}

//*****************************************************************************
//
//! Configures pin(s) for use as scan matrix keyboard rows (outputs).
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! scan matrix keyboard outputs.  This function provides the proper
//! configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a scan matrix
//! keyboard row pin; it only configures a scan matrix keyboard row pin for
//! proper operation.  Devices with flexible pin muxing also require a
//! GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeKBRow(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for push/pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as scan matrix keyboard columns (inputs).
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! scan matrix keyboard inputs.  This function provides the proper
//! configuration for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a scan matrix
//! keyboard column pin; it only configures a scan matrix keyboard column pin
//! for proper operation.  Devices with flexible pin muxing also require a
//! GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeKBColumn(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA,
                     GPIO_PIN_TYPE_STD_WPU);
}

//*****************************************************************************
//
//! Configures pin(s) for use as an LED sequencer output.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! LED sequencers.  This function provides the proper configuration for those
//! pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into an LED sequencer
//! output pin; it only configures an LED sequencer output pin for proper
//! operation.  Devices with flexible pin muxing also require a
//! GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeLEDSeq(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for push/pull operation and 8mA strength.  The external
    // hardware should be set up such that we sink current when the LED is
    // turned on, hence the 8mA configuration choice.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Configures pin(s) for use as Consumer Infrared inputs or outputs.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! The GPIO pins must be properly configured in order to function correctly as
//! Consumer Infrared pins.  This function provides the proper configuration
//! for those pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \note This function cannot be used to turn any pin into a CIR pin; it only
//! configures a CIR pin for proper operation.  Devices with flexible pin
//! muxing also require a GPIOPinConfigure() function call.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinTypeCIR(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Make the pin(s) be peripheral controlled.
    //
    GPIODirModeSet(ui32Port, ui8Pins, GPIO_DIR_MODE_HW);

    //
    // Set the pad(s) for standard push-pull operation.
    //
    GPIOPadConfigSet(ui32Port, ui8Pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
}

//*****************************************************************************
//
//! Retrieves the wake pins status.
//!
//! \param ui32Port is the base address of the GPIO port.
//!
//! This function returns the GPIO wake pin status values.  The returned
//! bitfield shows low or high pin state via a value of 0 or 1.
//!
//! \note This function is not available on all devices, consult the data sheet
//! to ensure that the device you are using supports GPIO wake pins.
//!
//! \return Returns the wake pin status.
//
//*****************************************************************************
uint32_t
GPIOPinWakeStatus(uint32_t ui32Port)
{
    return(ui32Port + GPIO_O_WAKESTAT);
}

//*****************************************************************************
//
//! Configures the alternate function of a GPIO pin.
//!
//! \param ui32PinConfig is the pin configuration value, specified as only one
//! of the \b GPIO_P??_??? values.
//!
//! This function configures the pin mux that selects the peripheral function
//! associated with a particular GPIO pin.  Only one peripheral function at a
//! time can be associated with a GPIO pin, and each peripheral function should
//! only be associated with a single GPIO pin at a time (despite the fact that
//! many of them can be associated with more than one GPIO pin).  To fully
//! configure a pin, a GPIOPinType*() function should also be called.
//!
//! The available mappings are supplied on a per-device basis in
//! <tt>pin_map.h</tt>.  The \b PART_IS_<partno> define enables the
//! appropriate set of defines for the device that is being used.
//!
//! \note If the same signal is assigned to two different GPIO port
//! pins, the signal is assigned to the port with the lowest letter and the
//! assignment to the higher letter port is ignored.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinConfigure(uint32_t ui32PinConfig)
{
    uint32_t ui32Base, ui32Shift;

    //
    // Check the argument.
    //
    ASSERT(((ui32PinConfig >> 16) & 0xff) < 15);
    ASSERT(((ui32PinConfig >> 8) & 0xe3) == 0);

    //
    // Extract the base address index from the input value.
    //
    ui32Base = (ui32PinConfig >> 16) & 0xff;

    //
    // Get the base address of the GPIO module, selecting either the APB or the
    // AHB aperture as appropriate.
    //
    if(HWREG(SYSCTL_GPIOHBCTL) & (1 << ui32Base))
    {
        ui32Base = g_pui32GPIOBaseAddrs[(ui32Base << 1) + 1];
    }
    else
    {
        ui32Base = g_pui32GPIOBaseAddrs[ui32Base << 1];
    }

    //
    // Extract the shift from the input value.
    //
    ui32Shift = (ui32PinConfig >> 8) & 0xff;

    //
    // Write the requested pin muxing value for this GPIO pin.
    //
    HWREG(ui32Base + GPIO_O_PCTL) = ((HWREG(ui32Base + GPIO_O_PCTL) &
                                      ~(0xf << ui32Shift)) |
                                     ((ui32PinConfig & 0xf) << ui32Shift));
}

//*****************************************************************************
//
//! Enables a GPIO pin as a trigger to start a DMA transaction.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIODMATriggerEnable(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ui32Port + GPIO_O_DMACTL) |= ui8Pins;
}

//*****************************************************************************
//
//! Disables a GPIO pin as a trigger to start a DMA transaction.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIODMATriggerDisable(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ui32Port + GPIO_O_DMACTL) &= (~ui8Pins);
}

//*****************************************************************************
//
//! Enables a GPIO pin as a trigger to start an ADC capture.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
//!
//! This function enables a GPIO pin to be used as a trigger to start an ADC
//! sequence.  Any GPIO pin can be configured to be an external trigger for an
//! ADC sequence.  The GPIO pin still generates interrupts if the interrupt is
//! enabled for the selected pin.  To enable the use of a GPIO pin to trigger
//! the ADC module, the ADCSequenceConfigure() function must be called with the
//! \b ADC_TRIGGER_EXTERNAL parameter.
//!
//! \note This function is not available on all devices, consult the data sheet
//! to ensure that the device you are using supports GPIO ADC Control.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOADCTriggerEnable(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ui32Port + GPIO_O_ADCCTL) |= ui8Pins;
}

//*****************************************************************************
//
//! Disable a GPIO pin as a trigger to start an ADC capture.
//!
//! \param ui32Port is the base address of the GPIO port.
//! \param ui8Pins is the bit-packed representation of the pin(s).
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
GPIOADCTriggerDisable(uint32_t ui32Port, uint8_t ui8Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(_GPIOBaseValid(ui32Port));

    //
    // Set the pin as a DMA trigger.
    //
    HWREG(ui32Port + GPIO_O_ADCCTL) &= (~ui8Pins);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
