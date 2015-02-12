/*
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
 */
/** ============================================================================
 *  @file       GPIO2.h
 *
 *  @brief      GPIO2 driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/GPIO2.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins and ports via
 *  simple and portable APIs. The application needs to supply a GPIO2_Config
 *  structure to the module. The application needs to initialize the GPIO
 *  hardware peripherals, setup the pins used and call GPIO2_init(). Once that is
 *  completed the other APIs can be used to access the pins.
 *
 *  Asserts are used to verify that the driver has only been initialized once,
 *  is reading/writing a valid index, and is writing to an output pin.
 *
 *  See the device specific GPIO2 header file for configuration details.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_GPIO2__include
#define ti_drivers_GPIO2__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*!
 *  @brief  GPIO interrupt type
 */
typedef uint32_t GPIO2_IntType;
#define GPIO2_INT_FALLING      (1 << 20)    /*!< Interrupt on falling edge */
#define GPIO2_INT_RISING       (2 << 20)    /*!< Interrupt on rising edge */
#define GPIO2_INT_BOTH_EDGES   (3 << 20)    /*!< Interrupt on both edges */
#define GPIO2_INT_LOW          (4 << 20)    /*!< Interrupt on low level */
#define GPIO2_INT_HIGH         (5 << 20)    /*!< Interrupt on high level */

/*!
 *  @brief  Device specific GPIO configuration
 *  Only DO_NOT_CONFIG is globally defined:
 */
typedef uint32_t GPIO2_PinConfig;
#define GPIO2_DO_NOT_CONFIG          0xffff0000

/* pin direction and configuration */
#define GPIO2_OUTPUT_LOW_STRENGTH    (1 << 16) /*! Denotes a GPIO pin is output. */
#define GPIO2_OUTPUT_HIGH_STRENGTH   (2 << 16) /*! Denotes a GPIO pin is output. */
#define GPIO2_INPUT_PULLUP           (3 << 16) /*! Denotes a GPIO pin is input with pullup. */
#define GPIO2_INPUT_PULLDOWN         (4 << 16) /*! Denotes a GPIO pin is input with pulldown. */

#define GPIO2_IO_CONFIG_MASK   0x000f0000
#define GPIO2_INT_CONFIG_MASK  0x00f00000

/*!
 *  @brief  GPIO callback function type
 */
typedef void (*GPIO2_CallbackFxn)(void);

/*!
 *  @brief      Clears the GPIO interrupt flag
 *
 *  Clears the GPIO interrupt for the specified index. For edge-triggered
 *  interrupts, this function must be called to allow any further interrupts.
 *
 *  @param      index       GPIO index
 */
extern void GPIO2_clearInt(unsigned int index);

/*!
 *  @brief      Disables GPIO interrupts
 *
 *  Disables interrupts for the specified GPIO index.
 *
 *  @param      index       GPIO index
 */
extern void GPIO2_disableInt(unsigned int index);

/*!
 *  @brief      Enables GPIO interrupts
 *
 *  Enables GPIO interrupts for the selected index to occur.
 *
 *  @param      index       GPIO index
 */
extern void GPIO2_enableInt(unsigned int index);

/*!
 *  @brief  Initializes the GPIO module
 *
 *  The application provided *GPIO2_config* must be initialized before the
 *  GPIO2_init() function is called. The *GPIO2_config* must be persistent and not
 *  changed after GPIO2_init() is called
 */
extern void GPIO2_init();

/*!
 *  @brief      Reads the value of a GPIO pin
 *
 *  The value returned will either be a zero or non-zero bit packed value of the
 *  pin(s) read.
 *
 *  @param      index  GPIO index
 *
 *  @return     Bit packed value of the GPIO pin(s)
 */
extern uint32_t GPIO2_read(unsigned int index);

/*!
 *  @brief      Bind a callback function to a GPIO pin interrupt
 *
 *  Associate an callback function with a particular GPIO pin interrupt.
 *
 *  @param      index       GPIO index
 *  @param      callback    address of the ISR function
 */
extern bool GPIO2_setCallback(unsigned int index, GPIO2_CallbackFxn callback);

/*!
 *  @brief      Configure the gpio pin
 *
 *  Configure a gpio pin to a device specific setting.
 *
 *  @param      index       GPIO index
 *  @param      pinType     device specific pin type
 */
extern bool GPIO2_setConfig(unsigned int index, GPIO2_PinConfig pinConfig);

/*!
 *  @brief      Toggles the current state of a GPIO
 *
 *  @param      index  GPIO index
 */
extern void GPIO2_toggle(unsigned int index);

/*!
 *  @brief     Writes the value to a GPIO pin
 *
 *  Value is a bit representation of the pin(s) to be changed. Only the pins
 *  specified by index will be written. If the index is for pin 2, it
 *  can be written high by passing in 0x04 or ~1 as the value. In general ~1
 *  and 0 should be used for single pins or multiple pins with the same value.
 *  Only when writing multiple pins with different values should you use a bit
 *  represented value.
 *
 *  @param      index    GPIO index
 *  @param      value    Value of the pin(s)
 */
extern void GPIO2_write(unsigned int index, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIO2__include */
