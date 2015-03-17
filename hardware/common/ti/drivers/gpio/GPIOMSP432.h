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
 *  @file       GPIOMSP432.h
 *
 *  @brief      MSP432 GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/gpio/GPIOMSP432.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins via simple
 *  and portable APIs. The application needs to supply a GPIOMSP432_Config
 *  structure to the module (see example below). This structure communicates to
 *  the GPIO module how to configure the pins used by the application (See the
 *  description of GPIO_PinConfig in the GPIO.h file).
 *
 *  The application is required to call GPIO_init(). This function will
 *  initialize all the GPIO pins defined in the GPIO_PinConfig table to the
 *  configurations specified. Once completed the other APIs can be used to
 *  access the pins.
 *
 *  Asserts are used to verify that the driver has only been initialized, and
 *  is reading/writing a valid index.
 *
 *  The following is an example of the code required to use the 2 switches and
 *  4 LEDs on the MSP432 Launchpad board.
 *
 *  Board header:
 *  @code
 *  // Enum of GPIO names on the MSP_EXP432P401RLP dev board
 *  typedef enum MSP_EXP432P401RLP_GPIOName {
 *      // input pins with callbacks first
 *      MSP_EXP432P401RLP_S1 = 0,
 *      MSP_EXP432P401RLP_S2,
 *      // output pins
 *      MSP_EXP432P401RLP_LED1,
 *      MSP_EXP432P401RLP_LED_RED,
 *      MSP_EXP432P401RLP_LED_GREEN,
 *      MSP_EXP432P401RLP_LED_BLUE,
 *
 *      MSP_EXP432P401RLP_GPIOCOUNT
 *  } MSP_EXP432P401RLP_GPIOName;
 *  @endcode
 *
 *  Board initialization code:
 *  @code
 *  #include <ti/drivers/GPIO.h>
 *  #include <ti/drivers/gpio/GPIOMSP432.h>
 *
 *  // Array of Pin configurations
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in MSP_EXP432P401RLP.h
 *  // NOTE: Pins not used for interrupts should be placed at the end of the
 *           array.  Callback entries can be omitted from callbacks array to
 *           reduce memory usage.
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *
 *      // Input pins
 *
 *      // MSP_EXP432P401RLP_S1
 *      GPIOMSP432_P1_1 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *      // MSP_EXP432P401RLP_S2
 *      GPIOMSP432_P1_4 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *
 *      // Output pins
 *
 *      // MSP_EXP432P401RLP_LED1
 *      GPIOMSP432_P1_0 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
 *      // MSP_EXP432P401RLP_LED_RED
 *      GPIOMSP432_P2_0 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
 *      // MSP_EXP432P401RLP_LED_GREEN
 *      GPIOMSP432_P2_1 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,
 *      // MSP_EXP432P401RLP_LED_BLUE
 *      GPIOMSP432_P2_2 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW
 *  };
 *
 *  // Array of callback function pointers
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in MSP_EXP432P401RLP.h
 *  // NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *           reduce memory usage (if placed at end of gpioPinConfigs array).
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      // MSP_EXP432P401RLP_S1
 *      NULL,
 *      // MSP_EXP432P401RLP_S2
 *      NULL
 *  };
 *
 *  //
 *  // The device-specific GPIO_config structure
 *  //
 *  const GPIOMSP432_Config GPIOMSP432_config = {
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
 *  void MSP_EXP432P401RLP_initGPIO(void)
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

#ifndef ti_drivers_GPIOMSP432__include
#define ti_drivers_GPIOMSP432__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/GPIO.h>

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIOMSP432_Config {
    /*! Pointer to the board's GPIO_PinConfig array */
    GPIO_PinConfig  *pinConfigs;

    /*! Pointer to the board's GPIO_CallbackFxn array */
    GPIO_CallbackFxn  *callbacks;

    /*! number of GPIO_PinConfigs defined */
    uint32_t numberOfPinConfigs;

    /*! number of GPIO_Callbacks defined */
    uint32_t numberOfCallbacks;

    /*! interrupt priority used for call back interrupts */
    /*! a setting of ~0 will configure the lowest possible priority */
    uint32_t intPriority;
} GPIOMSP432_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within
 *  the board's pin configuration table. These macros should
 *  be or'd in with the respective pin configuration settings.
 */
#define GPIOMSP432_EMPTY_PIN 0x0000

/*
 *  Only ports 1-6 support interrupts
 *  and can be configured with callbacks
 */
#define GPIOMSP432_P1_0    0x101
#define GPIOMSP432_P1_1    0x102
#define GPIOMSP432_P1_2    0x104
#define GPIOMSP432_P1_3    0x108
#define GPIOMSP432_P1_4    0x110
#define GPIOMSP432_P1_5    0x120
#define GPIOMSP432_P1_6    0x140
#define GPIOMSP432_P1_7    0x180

#define GPIOMSP432_P2_0    0x201
#define GPIOMSP432_P2_1    0x202
#define GPIOMSP432_P2_2    0x204
#define GPIOMSP432_P2_3    0x208
#define GPIOMSP432_P2_4    0x210
#define GPIOMSP432_P2_5    0x220
#define GPIOMSP432_P2_6    0x240
#define GPIOMSP432_P2_7    0x280

#define GPIOMSP432_P3_0    0x301
#define GPIOMSP432_P3_1    0x302
#define GPIOMSP432_P3_2    0x304
#define GPIOMSP432_P3_3    0x308
#define GPIOMSP432_P3_4    0x310
#define GPIOMSP432_P3_5    0x320
#define GPIOMSP432_P3_6    0x340
#define GPIOMSP432_P3_7    0x380

#define GPIOMSP432_P4_0    0x401
#define GPIOMSP432_P4_1    0x402
#define GPIOMSP432_P4_2    0x404
#define GPIOMSP432_P4_3    0x408
#define GPIOMSP432_P4_4    0x410
#define GPIOMSP432_P4_5    0x420
#define GPIOMSP432_P4_6    0x440
#define GPIOMSP432_P4_7    0x480

#define GPIOMSP432_P5_0    0x501
#define GPIOMSP432_P5_1    0x502
#define GPIOMSP432_P5_2    0x504
#define GPIOMSP432_P5_3    0x508
#define GPIOMSP432_P5_4    0x510
#define GPIOMSP432_P5_5    0x520
#define GPIOMSP432_P5_6    0x540
#define GPIOMSP432_P5_7    0x580

#define GPIOMSP432_P6_0    0x601
#define GPIOMSP432_P6_1    0x602
#define GPIOMSP432_P6_2    0x604
#define GPIOMSP432_P6_3    0x608
#define GPIOMSP432_P6_4    0x610
#define GPIOMSP432_P6_5    0x620
#define GPIOMSP432_P6_6    0x640
#define GPIOMSP432_P6_7    0x680

/*
 *  Ports 7-10 and 'J' do NOT support interrupts
 *  and therefore can not be configured with
 *  callbacks
 */
#define GPIOMSP432_P7_0    0x701
#define GPIOMSP432_P7_1    0x702
#define GPIOMSP432_P7_2    0x704
#define GPIOMSP432_P7_3    0x708
#define GPIOMSP432_P7_4    0x710
#define GPIOMSP432_P7_5    0x720
#define GPIOMSP432_P7_6    0x740
#define GPIOMSP432_P7_7    0x780

#define GPIOMSP432_P8_0    0x801
#define GPIOMSP432_P8_1    0x802
#define GPIOMSP432_P8_2    0x804
#define GPIOMSP432_P8_3    0x808
#define GPIOMSP432_P8_4    0x810
#define GPIOMSP432_P8_5    0x820
#define GPIOMSP432_P8_6    0x840
#define GPIOMSP432_P8_7    0x880

#define GPIOMSP432_P9_0    0x901
#define GPIOMSP432_P9_1    0x902
#define GPIOMSP432_P9_2    0x904
#define GPIOMSP432_P9_3    0x908
#define GPIOMSP432_P9_4    0x910
#define GPIOMSP432_P9_5    0x920
#define GPIOMSP432_P9_6    0x940
#define GPIOMSP432_P9_7    0x980

#define GPIOMSP432_P10_0   0xa01
#define GPIOMSP432_P10_1   0xa02
#define GPIOMSP432_P10_2   0xa04
#define GPIOMSP432_P10_3   0xa08
#define GPIOMSP432_P10_4   0xa10
#define GPIOMSP432_P10_5   0xa20
#define GPIOMSP432_P10_6   0xa40
#define GPIOMSP432_P10_7   0xa80

#define GPIOMSP432_PJ_0    0xb01
#define GPIOMSP432_PJ_1    0xb02
#define GPIOMSP432_PJ_2    0xb04
#define GPIOMSP432_PJ_3    0xb08
#define GPIOMSP432_PJ_4    0xb10
#define GPIOMSP432_PJ_5    0xb20
#define GPIOMSP432_PJ_6    0xb40
#define GPIOMSP432_PJ_7    0xb80

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIOMSP432__include */
