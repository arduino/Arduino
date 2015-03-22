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
 *  @file       GPIOCC3200.h
 *
 *  @brief      CC3200 GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/gpio/GPIOCC3200.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins via simple
 *  and portable APIs. The application is required to supply a GPIOCC3200_Config
 *  structure to the module (see example below). This structure communicates to
 *  the GPIO module how to configure the pins used by the application (See the
 *  description of GPIO_PinConfig in the GPIO.h file).
 *
 *  The application is required to call GPIO_init(). This function will
 *  initialize all the GPIO pins defined in the GPIO_PinConfig table to the
 *  configurations specified. Once completed the other APIs can be used to
 *  access the pins.
 *
 *  Asserts are used to verify that the driver has been initialized, and is
 *  reading/writing a valid index.
 *
 *  The following is an example of the code required to use the 2 switches and
 *  4 LEDs on the CC3200 Launchpad board.
 *
 *  Board header:
 *  @code
 *  // Enum of GPIO names on the CC3200_LP dev board
 *  typedef enum CC3200_LP_GPIOName {
 *      // input pins with callbacks first
 *      CC3200_LP_SW2 = 0,
 *      CC3200_LP_SW3,
 *      // output pins
 *      CC3200_LP_LED_D7,
 *      CC3200_LP_LED_D6,
 *      CC3200_LP_LED_D5,
 *
 *      CC3200_LP_GPIOCOUNT
 *  } CC3200_LP_GPIOName;
 *  @endcode
 *
 *  Board initialization code:
 *  @code
 *  #include <ti/drivers/GPIO.h>
 *  #include <ti/drivers/gpio/GPIOCC3200.h>
 *
 *  // Array of Pin configurations
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in CC3200_LP.h
 *  // NOTE: Pins not used for interrupts should be placed at the end of the
 *           array.  Callback entries can be omitted from callbacks array to
 *           reduce memory usage.
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *      // input pins with callbacks
 *
 *      // CC3200_LP_SW2
 *      GPIOCC3200_GPIO_22 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *      // CC3200_LP_SW3
 *      GPIOCC3200_GPIO_13 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *
 *      // output pins
 *
 *      // CC3200_LP_LED_D7
 *      GPIOCC3200_GPIO_09 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
 *      // CC3200_LP_LED_D6
 *      GPIOCC3200_GPIO_10 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
 *      // CC3200_LP_LED_D5
 *      GPIOCC3200_GPIO_11 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
 *  };
 *
 *  // Array of callback function pointers
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in CC3200_LP.h
 *  // NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *           reduce memory usage (if placed at end of gpioPinConfigs array).
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      // CC3200_LP_SW2
 *      NULL,
 *      // CC3200_LP_SW3
 *      NULL
 *  };
 *
 *  //
 *  // The device-specific GPIO_config structure
 *  //
 *  const GPIOCC3200_Config GPIOCC3200_config = {
 *      .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
 *      .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
 *      .numberOfPinConfigs =
 *               sizeof(gpioPinConfigs)/sizeof(GPIO_PinConfig),
 *      .numberOfCallbacks =
 *               sizeof(gpioCallbackFunctions)/sizeof(GPIO_CallbackFxn),
 *      .intPriority = ~0
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
 *  an interrupt service routine and should be designed accordingly.  When an
 *  interrupt is triggered, the interrupt status of all (interrupt enabled) pins
 *  on a port will be read, cleared, and the respective callbacks will be
 *  executed.  Callbacks will be called in order from least significant bit to
 *  most significant bit.
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

#ifndef ti_drivers_GPIOCC3200__include
#define ti_drivers_GPIOCC3200__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/GPIO.h>

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIOCC3200_Config {
    /*! Pointer to the board's GPIO_PinConfig array */
    GPIO_PinConfig  *pinConfigs;

    /*! Pointer to the board's GPIO_CallbackFxn array */
    GPIO_CallbackFxn  *callbacks;

    /*! Number of GPIO_PinConfigs defined */
    uint32_t numberOfPinConfigs;

    /*! Number of GPIO_Callbacks defined */
    uint32_t numberOfCallbacks;

    /*!
     * Interrupt priority used for call back interrupts.  Setting ~0 will
     * configure the lowest possible priority
     */
    uint32_t intPriority;
} GPIOCC3200_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within
 *  the board's pin configuration table.
 */
#define GPIOCC3200_EMPTY_PIN  0x0000

#define GPIOCC3200_GPIO_00    0x0001
#define GPIOCC3200_GPIO_01    0x0002
#define GPIOCC3200_GPIO_02    0x0004
#define GPIOCC3200_GPIO_03    0x0008
#define GPIOCC3200_GPIO_04    0x0010
#define GPIOCC3200_GPIO_05    0x0020
#define GPIOCC3200_GPIO_06    0x0040
#define GPIOCC3200_GPIO_07    0x0080

#define GPIOCC3200_GPIO_08    0x0101
#define GPIOCC3200_GPIO_09    0x0102
#define GPIOCC3200_GPIO_10    0x0104
#define GPIOCC3200_GPIO_11    0x0108
#define GPIOCC3200_GPIO_12    0x0110
#define GPIOCC3200_GPIO_13    0x0120
#define GPIOCC3200_GPIO_14    0x0140
#define GPIOCC3200_GPIO_15    0x0180

#define GPIOCC3200_GPIO_16    0x0201
#define GPIOCC3200_GPIO_17    0x0202
#define GPIOCC3200_GPIO_18    0x0204
#define GPIOCC3200_GPIO_19    0x0208
#define GPIOCC3200_GPIO_20    0x0210
#define GPIOCC3200_GPIO_21    0x0220
#define GPIOCC3200_GPIO_22    0x0240
#define GPIOCC3200_GPIO_23    0x0280

#define GPIOCC3200_GPIO_24    0x0301
#define GPIOCC3200_GPIO_25    0x0302
#define GPIOCC3200_GPIO_26    0x0304
#define GPIOCC3200_GPIO_27    0x0308
#define GPIOCC3200_GPIO_28    0x0310
#define GPIOCC3200_GPIO_29    0x0320
#define GPIOCC3200_GPIO_30    0x0340
#define GPIOCC3200_GPIO_31    0x0380

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIOCC3200__include */
