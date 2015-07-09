/******************************************************************************
*  Filename:       gpio.h
*  Revised:        2015-01-14 12:12:44 +0100 (on, 14 jan 2015)
*  Revision:       42373
*
*  Description:    Defines and prototypes for the GPIO.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

//****************************************************************************
//
//! \addtogroup gpio_api
//! @{
//
//****************************************************************************

#ifndef __GPIO_H__
#define __GPIO_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <inc/hw_gpio.h>
#include <driverlib/debug.h>

//*****************************************************************************
//
// Number of GPIO pins
//
//*****************************************************************************
#define NUM_GPIO_PINS 32

//*****************************************************************************
//
// The following values define the bit field for the GPIO Pins in a port.
//
//*****************************************************************************
#define GPIO_PIN_0              0x00000001  // GPIO pin 0
#define GPIO_PIN_1              0x00000002  // GPIO pin 1
#define GPIO_PIN_2              0x00000004  // GPIO pin 2
#define GPIO_PIN_3              0x00000008  // GPIO pin 3
#define GPIO_PIN_4              0x00000010  // GPIO pin 4
#define GPIO_PIN_5              0x00000020  // GPIO pin 5
#define GPIO_PIN_6              0x00000040  // GPIO pin 6
#define GPIO_PIN_7              0x00000080  // GPIO pin 7
#define GPIO_PIN_8              0x00000100  // GPIO pin 8
#define GPIO_PIN_9              0x00000200  // GPIO pin 9
#define GPIO_PIN_10             0x00000400  // GPIO pin 10
#define GPIO_PIN_11             0x00000800  // GPIO pin 11
#define GPIO_PIN_12             0x00001000  // GPIO pin 12
#define GPIO_PIN_13             0x00002000  // GPIO pin 13
#define GPIO_PIN_14             0x00004000  // GPIO pin 14
#define GPIO_PIN_15             0x00008000  // GPIO pin 15
#define GPIO_PIN_16             0x00010000  // GPIO pin 16
#define GPIO_PIN_17             0x00020000  // GPIO pin 17
#define GPIO_PIN_18             0x00040000  // GPIO pin 18
#define GPIO_PIN_19             0x00080000  // GPIO pin 19
#define GPIO_PIN_20             0x00100000  // GPIO pin 20
#define GPIO_PIN_21             0x00200000  // GPIO pin 21
#define GPIO_PIN_22             0x00400000  // GPIO pin 22
#define GPIO_PIN_23             0x00800000  // GPIO pin 23
#define GPIO_PIN_24             0x01000000  // GPIO pin 24
#define GPIO_PIN_25             0x02000000  // GPIO pin 25
#define GPIO_PIN_26             0x04000000  // GPIO pin 26
#define GPIO_PIN_27             0x08000000  // GPIO pin 27
#define GPIO_PIN_28             0x10000000  // GPIO pin 28
#define GPIO_PIN_29             0x20000000  // GPIO pin 29
#define GPIO_PIN_30             0x40000000  // GPIO pin 30
#define GPIO_PIN_31             0x80000000  // GPIO pin 31
#define GPIO_PIN_UNUSED         0x00000000  // GPIO pin unused
#define GPIO_PIN_MASK           0xFFFFFFFF  // GPIO pin mask

//*****************************************************************************
//
// Values that can be passed to GPIODirModeSet as the ui32PinIO parameter, and
// returned from GPIODirModeGet.
//
//*****************************************************************************
#define GPIO_DIR_MODE_IN        0x00000000  // Pin is a GPIO input
#define GPIO_DIR_MODE_OUT       0x00000001  // Pin is a GPIO output

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//****************************************************************************
//
//! \brief Sets the direction of the specified pin(s).
//!
//! This function will set the specified pin(s) on the GPIO port
//! as either an input or output under software control.
//!
//! \param ui32Pins is the bit-packed representation of the pin(s)
//! The parameter must be a bitwise OR'ed combination of the following:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//! \param ui32Dir is the direction of the pin(s):
//! - \ref GPIO_DIR_MODE_IN  : Software controlled input.
//! - \ref GPIO_DIR_MODE_OUT : Software controlled output.
//!
//! \return None
//
//****************************************************************************
__STATIC_INLINE void
GPIODirModeSet(uint32_t ui32Pins, uint32_t ui32Dir)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(ui32Pins & GPIO_PIN_MASK);
    ASSERT((ui32Dir == GPIO_DIR_MODE_IN) ||
           (ui32Dir == GPIO_DIR_MODE_OUT));

    //
    // Update the output pin enable bit.
    //
    ui32Reg = HWREG(GPIO_BASE + GPIO_O_DOE31_0);
    if(ui32Dir == GPIO_DIR_MODE_IN)
    {
        ui32Reg &= ~ui32Pins;
    }
    else
    {
        ui32Reg |= ui32Pins;
    }
    HWREG(GPIO_BASE + GPIO_O_DOE31_0) = ui32Reg;
}

//*****************************************************************************
//
//! \brief Gets the direction of a pin.
//!
//! This function gets the direction and control mode for a specified pin on
//! the selected GPIO port. The pin can be configured as either an input or
//! output under software control.
//!
//! \param ui32Pin is the pin number.
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//!
//! \return Returns one of the enumerated data types:
//! - \ref GPIO_DIR_MODE_IN  : Software controlled input.
//! - \ref GPIO_DIR_MODE_OUT : Software controlled output.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
GPIODirModeGet(uint32_t ui32Pin)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT((ui32Pin >= GPIO_PIN_0) && (ui32Pin <= GPIO_PIN_31));

    //
    // Return the pin direction.
    //
    ui32Reg = HWREG(GPIO_BASE + GPIO_O_DOE31_0);
    return((ui32Reg & ui32Pin) ? GPIO_DIR_MODE_OUT : GPIO_DIR_MODE_IN);
}

//****************************************************************************
//
//! \brief Write to pin(s).
//!
//!
//! All the specified pins will be set to the same value, either '0' or '1'.
//!
//! \param ui32Pins is the bit-packed representation of the GPIO(s) to set.
//! The parameter must be a bitwise OR'ed combination of the following:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//! \param ui32Val is the value to write on the specified GPIO(s):
//! - 0 : Set the GPIO(s) to 0 (low).
//! - 1 : Set the GPIO(s) to 1 (high).
//!
//! \return None
//
//****************************************************************************
__STATIC_INLINE void
GPIOPinWrite(uint32_t ui32Pins, uint32_t ui32Val)
{
    uint32_t ui32Addr;

    //
    // Check the arguments.
    //
    ASSERT(ui32Pins & GPIO_PIN_MASK);

    //
    // Write to the port.
    //
    if(ui32Val)
    {
        ui32Addr = GPIO_BASE + GPIO_O_DOUTSET31_0;
    }
    else
    {
        ui32Addr = GPIO_BASE + GPIO_O_DOUTCLR31_0;
    }
    HWREG(ui32Addr) = ui32Pins;
}

//****************************************************************************
//
//! \brief Read the value of specific pin(s).
//!
//! \param ui32Pins is the bit-packed representation of the pin(s) to read.
//! The parameter must be a bitwise OR'ed combination of the following:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//!
//! \return Returns the value of the specified pin(s).
//
//****************************************************************************
__STATIC_INLINE uint32_t
GPIOPinRead(uint32_t ui32Pins)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Pins >= GPIO_PIN_0) && (ui32Pins <= GPIO_PIN_31));

    //
    // Return the value of the pin(s).
    //
    return (HWREG(GPIO_BASE + GPIO_O_DIN31_0) & ui32Pins);
}

//****************************************************************************
//
//! \brief Clear specific pin(s).
//!
//! \param ui32Pins are the pins to clear
//! The parameter must be a bitwise OR'ed combination of the following:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//!
//! \return None
//
//****************************************************************************
__STATIC_INLINE void
GPIOPinClear(uint32_t ui32Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Pins & GPIO_PIN_MASK);

    //
    // Clear the pin(s).
    //
    HWREG(GPIO_BASE + GPIO_O_DOUTCLR31_0) = ui32Pins;
}

//****************************************************************************
//
//! \brief Toggle specific pin(s).
//!
//! \param ui32Pins is the pins to toggle.
//! The parameter must be a bitwise OR'ed combination of the following:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//!
//! \return None
//
//****************************************************************************
__STATIC_INLINE void
GPIOPinToggle(uint32_t ui32Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Pins & GPIO_PIN_MASK);

    //
    // Toggle the pin.
    //
    HWREG(GPIO_BASE + GPIO_O_DOUTTGL31_0) = ui32Pins;
}

//****************************************************************************
//
//! \brief Get the event status of a specific pin.
//!
//! \param ui32Pin is the pins to toggle.
//! The parameter must be one of:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//!
//! \return Returns the current event status on a specific GPIO
//
//****************************************************************************
__STATIC_INLINE uint32_t
GPIOEventGet(uint32_t ui32Pin)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Pin & GPIO_PIN_MASK);

    //
    // Return the event status.
    //
    return ((HWREG(GPIO_BASE + GPIO_O_EVFLAGS31_0) & ui32Pin) ? 1 : 0);
}

//****************************************************************************
//
//! \brief Clear an IO event on a pin.
//!
//! \param ui32Pins specifies the pins to clear the events on.
//! The parameter must be a bitwise OR'ed combination of the following:
//! - \ref GPIO_PIN_0
//! - ...
//! - \ref GPIO_PIN_31
//!
//! \return None
//
//****************************************************************************
__STATIC_INLINE void
GPIOEventClear(uint32_t ui32Pins)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Pins & GPIO_PIN_MASK);

    //
    // Toggle the pin.
    //
    HWREG(GPIO_BASE + GPIO_O_EVFLAGS31_0) = ui32Pins;
}

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __GPIO_H__

//****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//****************************************************************************
