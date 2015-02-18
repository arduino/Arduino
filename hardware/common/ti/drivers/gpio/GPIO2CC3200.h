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
 *  @file       GPIO2CC3200.h
 *
 *  @brief      CC3200 GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/gpio/GPIO2CC3200.h>
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
 *  The following is an example of the code that must be implemented to use
 *  the 2 switches and 4 LEDs on the CC3200 Launchpad board.
 *
 *
 *  Board header:
 *  @code
 *  // LEDs on CC3200_LP are active high.
 *  #define CC3200_LP_LED_OFF (0)
 *  #define CC3200_LP_LED_ON  (~0)
 *
 *  // Enum of GPIO names on the CC3200_LP dev board
 *  // Note that input pins with callbacks are at the beginning
 *
 *  typedef enum CC3200_LP_GPIOName {
 *      CC3200_LP_SW2 = 0,
 *      CC3200_LP_SW3,
 *      CC3200_LP_LED_D7,
 *      CC3200_LP_LED_D6,
 *      CC3200_LP_LED_D5,
 *
 *      CC3200_LP_GPIOCOUNT
 *  } CC3200_LP_GPIOName;
 *
 *  Board initialization code:
 *  @code
 *  //
 *  // Array of Pin configurations grouped with input pins that have
 *  // callback function at the beginning
 *  //
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *      // input pins with callbacks
 *
 *      // CC3200_LP_SW2
 *      {GPIO2CC3200_GPIO_22 | GPIO2_INPUT_PULLUP | GPIO2_INT_RISING},
 *      // CC3200_LP_SW3
 *      {GPIO2CC3200_GPIO_13 | GPIO2_INPUT_PULLUP | GPIO2_INT_RISING},
 *
 *      // output pins
 *
 *      // CC3200_LP_LED_D7
 *      {GPIO2CC3200_GPIO_09 | GPIO2_OUTPUT_HIGH_STRENGTH},
 *      // CC3200_LP_LED_D6
 *      {GPIO2CC3200_GPIO_10 | GPIO2_OUTPUT_HIGH_STRENGTH},
 *      // CC3200_LP_LED_D5
 *      {GPIO2CC3200_GPIO_11 | GPIO2_OUTPUT_HIGH_STRENGTH},
 *  };
 *
 *  //
 *  // The array of callback function pointers for
 *  // those input pins with callbacks
 *  //
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      // CC3200_LP_S1
 *      NULL,
 *      // CC3200_LP_S2
 *      NULL
 *  };
 *
 *  //
 *  // The device-specific GPIO_config structure
 *  //
 *  const GPIOCC3200_Config GPIOCC3200_config = {
 *      .pinConfigs = (GPIO2_PinConfig *)gpioPinConfigs,
 *      .callbacks = (GPIO2_CallbackFxn *)gpioCallbackFunctions,
 *      .numberOfPinConfigs =
 *               sizeof(gpioPinConfigs)/sizeof(GPIO2_PinConfig),
 *      .numberOfCallbacks =
 *               sizeof(gpioCallbackFunctions)/sizeof(GPIO2_CallbackFxn),
 *  };
 *
 *  // Initialize peripheral and pins
 *  void CC3200_initGPIO(void)
 *  {
 *      // set up initial GPIO pin configurations
 *      GPIO_init();
 *  }
 *  @endcode
 *
 *  Keep in mind that the callback functions will be called in the context of
 *  an interrupt service routine and should be designed accordingly.
 *
 *  # Instrumentation #
 *  The GPIO driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_GPIO2CC3200__include
#define ti_drivers_GPIO2CC3200__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIO2CC3200_Config {
    /*!< Pointer to the board's PinConfig array */
    GPIO2_PinConfig  *pinConfigs;
    /*!< Pointer to the board's callback array */
    GPIO2_CallbackFxn  *callbacks;
    /*!< number of configs defined */
    uint32_t numberOfPinConfigs;
    /*!< number of callbacks defined */
    uint32_t numberOfCallbacks;
} GPIO2CC3200_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within
 *  the board's pin configuration table.
 */
#define GPIO2CC3200_EMPTY_PIN  0x0000

#define GPIO2CC3200_GPIO_00    0x0001
#define GPIO2CC3200_GPIO_01    0x0002
#define GPIO2CC3200_GPIO_02    0x0004
#define GPIO2CC3200_GPIO_03    0x0008
#define GPIO2CC3200_GPIO_04    0x0010
#define GPIO2CC3200_GPIO_05    0x0020
#define GPIO2CC3200_GPIO_06    0x0040
#define GPIO2CC3200_GPIO_07    0x0080

#define GPIO2CC3200_GPIO_08    0x0101
#define GPIO2CC3200_GPIO_09    0x0102
#define GPIO2CC3200_GPIO_10    0x0104
#define GPIO2CC3200_GPIO_11    0x0108
#define GPIO2CC3200_GPIO_12    0x0110
#define GPIO2CC3200_GPIO_13    0x0120
#define GPIO2CC3200_GPIO_14    0x0140
#define GPIO2CC3200_GPIO_15    0x0180

#define GPIO2CC3200_GPIO_16    0x0201
#define GPIO2CC3200_GPIO_17    0x0202
#define GPIO2CC3200_GPIO_18    0x0204
#define GPIO2CC3200_GPIO_19    0x0208
#define GPIO2CC3200_GPIO_20    0x0210
#define GPIO2CC3200_GPIO_21    0x0220
#define GPIO2CC3200_GPIO_22    0x0240
#define GPIO2CC3200_GPIO_23    0x0280

#define GPIO2CC3200_GPIO_24    0x0301
#define GPIO2CC3200_GPIO_25    0x0302
#define GPIO2CC3200_GPIO_26    0x0304
#define GPIO2CC3200_GPIO_27    0x0308
#define GPIO2CC3200_GPIO_28    0x0310
#define GPIO2CC3200_GPIO_29    0x0320
#define GPIO2CC3200_GPIO_30    0x0340
#define GPIO2CC3200_GPIO_31    0x0380

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIO2CC3200__include */
