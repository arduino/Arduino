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
 *  @file       GPIO2MSP432.h
 *
 *  @brief      MSP432 GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/gpio/GPIO2MSP432.h>
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
 *  the 2 switches and 4 LEDs on the MSP432 Launchpad board.
 *
 *
 *  Board header:
 *  @code
 *  // LEDs on MSP_EXP432P401RLP are active high.
 *  #define MSP_EXP432P401RLP_LED_OFF (0)
 *  #define MSP_EXP432P401RLP_LED_ON  (~0)
 *
 *  // Enum of GPIO names on the MSP_EXP432P401RLP dev board
 *  // Note that input pins with callbacks are at the beginning
 *
 *  typedef enum MSP_EXP432P401RLP_GPIOName {
 *      MSP_EXP432P401RLP_S1 = 0,
 *      MSP_EXP432P401RLP_S2,
 *      MSP_EXP432P401RLP_LED1,
 *      MSP_EXP432P401RLP_LED_RED,
 *      MSP_EXP432P401RLP_LED_GREEN,
 *      MSP_EXP432P401RLP_LED_BLUE,
 *      MSP_EXP432P401RLP_GPIOCOUNT
 *  } MSP_EXP432P401RLP_GPIOName;
 *
 *  Board initialization code:
 *  @code
 *  //
 *  // Array of Pin configurations grouped with input pins that have
 *  // callback function at the beginning
 *  //
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *      // Input pins with callbacks
 *
 *      // MSP_EXP432P401RLP_S1
 *      GPIO2MSP432_P1_1 | GPIO2MSP432_INPUT_PULLUP,
 *      // MSP_EXP432P401RLP_S2
 *      GPIO2MSP432_P1_4 | GPIO2MSP432_INPUT_PULLUP,
 *
 *      // output pins
 *
 *      // MSP_EXP432P401RLP_LED1
 *      GPIO2MSP432_P1_0 | GPIO2MSP432_OUTPUT_HIGH_STRENGTH,
 *      // MSP_EXP432P401RLP_LED_RED
 *      GPIO2MSP432_P2_0 | GPIO2MSP432_OUTPUT_HIGH_STRENGTH,
 *      // MSP_EXP432P401RLP_LED_GREEN
 *      GPIO2MSP432_P2_1 | GPIO2MSP432_OUTPUT_HIGH_STRENGTH,
 *      // MSP_EXP432P401RLP_LED_BLUE
 *      GPIO2MSP432_P2_2 | GPIO2MSP432_OUTPUT_HIGH_STRENGTH
 *  };
 *
 *  //
 *  // The array of callback function pointers for
 *  // those input pins with callbacks
 *  //
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      // MSP_EXP432P401RLP_S1
 *      NULL,
 *      // MSP_EXP432P401RLP_S2
 *      NULL
 *  };
 *
 *  //
 *  // The device-specific GPIO2_config structure
 *  //
 *  const GPIO2MSP432_Config GPIO2MSP432_config = {
 *      .pinConfigs = (GPIO2_PinConfig *)gpioPinConfigs,
 *      .callbacks = (GPIO2_CallbackFxn *)gpioCallbackFunctions,
 *      .numberOfPinConfigs =
 *               sizeof(gpioPinConfigs)/sizeof(GPIO2_PinConfig),
 *      .numberOfCallbacks =
 *               sizeof(gpioCallbackFunctions)/sizeof(GPIO2_CallbackFxn),
 *  };
 *
 *  // Initialize peripheral and pins
 *  void MSP432_initGPIO(void)
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

#ifndef ti_drivers_GPIO2MSP432__include
#define ti_drivers_GPIO2MSP432__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIO2MSP432_Config {
    /*!< Pointer to the board's PinConfig array */
    GPIO2_PinConfig  *pinConfigs;
    /*!< Pointer to the board's callback array */
    GPIO2_CallbackFxn  *callbacks;
    /*!< number of configs defined */
    uint32_t numberOfPinConfigs;
    /*!< number of callbacks defined */
    uint32_t numberOfCallbacks;
} GPIO2MSP432_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within
 *  the board's pin configuration table.
 */
#define GPIO2MSP432_EMPTY_PIN 0x0000

#define GPIO2MSP432_P1_0    0x101
#define GPIO2MSP432_P1_1    0x102
#define GPIO2MSP432_P1_2    0x104
#define GPIO2MSP432_P1_3    0x108
#define GPIO2MSP432_P1_4    0x110
#define GPIO2MSP432_P1_5    0x120
#define GPIO2MSP432_P1_6    0x140
#define GPIO2MSP432_P1_7    0x180

#define GPIO2MSP432_P2_0    0x201
#define GPIO2MSP432_P2_1    0x202
#define GPIO2MSP432_P2_2    0x204
#define GPIO2MSP432_P2_3    0x208
#define GPIO2MSP432_P2_4    0x210
#define GPIO2MSP432_P2_5    0x220
#define GPIO2MSP432_P2_6    0x240
#define GPIO2MSP432_P2_7    0x280

#define GPIO2MSP432_P3_0    0x301
#define GPIO2MSP432_P3_1    0x302
#define GPIO2MSP432_P3_2    0x304
#define GPIO2MSP432_P3_3    0x308
#define GPIO2MSP432_P3_4    0x310
#define GPIO2MSP432_P3_5    0x320
#define GPIO2MSP432_P3_6    0x340
#define GPIO2MSP432_P3_7    0x380

#define GPIO2MSP432_P4_0    0x401
#define GPIO2MSP432_P4_1    0x402
#define GPIO2MSP432_P4_2    0x404
#define GPIO2MSP432_P4_3    0x408
#define GPIO2MSP432_P4_4    0x410
#define GPIO2MSP432_P4_5    0x420
#define GPIO2MSP432_P4_6    0x440
#define GPIO2MSP432_P4_7    0x480

#define GPIO2MSP432_P5_0    0x501
#define GPIO2MSP432_P5_1    0x502
#define GPIO2MSP432_P5_2    0x504
#define GPIO2MSP432_P5_3    0x508
#define GPIO2MSP432_P5_4    0x510
#define GPIO2MSP432_P5_5    0x520
#define GPIO2MSP432_P5_6    0x540
#define GPIO2MSP432_P5_7    0x580

#define GPIO2MSP432_P6_0    0x601
#define GPIO2MSP432_P6_1    0x602
#define GPIO2MSP432_P6_2    0x604
#define GPIO2MSP432_P6_3    0x608
#define GPIO2MSP432_P6_4    0x610
#define GPIO2MSP432_P6_5    0x620
#define GPIO2MSP432_P6_6    0x640
#define GPIO2MSP432_P6_7    0x680

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIO2MSP432__include */
