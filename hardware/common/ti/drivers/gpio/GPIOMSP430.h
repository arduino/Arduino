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
 *  @file       GPIOMSP430.h
 *
 *  @brief      MSP430 GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/gpio/GPIOMSP430.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins via simple
 *  and portable APIs. The application is required to supply a GPIOMSP430_Config
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
 *  The following is an example of the code required to use 2 switches and
 *  2 LEDs on an MSP_EXP430F5529 Launchpad board.
 *
 *  Board header file:
 *  @code
 *  // Enum of GPIO names on the MSP_EXP430F5529LP dev board
 *  typedef enum MSP_EXP430F5529LP_GPIOName {
 *      MSP_EXP430F5529LP_S1 = 0,
 *      MSP_EXP430F5529LP_S2,
 *      MSP_EXP430F5529LP_LED1,
 *      MSP_EXP430F5529LP_LED2,
 *
 *      MSP_EXP430F5529LP_GPIOCOUNT
 *  } MSP_EXP430F5529LP_GPIOName;
 *  @endcode
 *
 *  Board initialization code:
 *  @code
 *  #include <ti/drivers/GPIO.h>
 *  #include <ti/drivers/gpio/GPIOMSP430.h>
 *
 *  // Array of pin configurations
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in MSP_EXP4305529LP.h
 *  // NOTE: Pins not used for interrupts should be placed at the end of the
 *  //       array.  Callback entries can be omitted from callbacks array to
 *  //       reduce memory usage.
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *      // Input pins
 *      // MSP_EXP430F5529LP_S1
 *      GPIOMSP430_P2_1 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *      // MSP_EXP430F5529LP_S2
 *      GPIOMSP430_P1_1 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *
 *      // Output pins
 *      // MSP_EXP430F5529LP_LED1
 *      GPIOMSP430_P1_0 | GPIO_CFG_OUTPUT,
 *      // MSP_EXP430F5529LP_LED2
 *      GPIOMSP430_P4_7 | GPIO_CFG_OUTPUT
 *  };
 *
 *  // Array of callback function pointers
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in MSP_EXP4305529LP.h
 *  // NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *  //       reduce memory usage (if placed at end of gpioPinConfigs array).
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      NULL,       // MSP_EXP430F5529LP_S1
 *      NULL        // MSP_EXP430F5529LP_S2
 *  };
 *
 *  // The device-specific GPIO_config structure
 *  const GPIOMSP430_Config GPIOMSP430_config = {
 *      .pinConfigs = (GPIO_PinConfig *) gpioPinConfigs,
 *      .callbacks = (GPIO_CallbackFxn *) gpioCallbackFunctions,
 *      .numberOfPinConfigs = sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
 *      .numberOfCallbacks = sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn)
 *  };
 *
 *  // Initialize peripheral and pins
 *  void MSP_EXP430F5529LP_initGPIO(void)
 *  {
 *      GPIO_init();
 *  }
 *  @endcode
 *
 *  MSP430 devices require GPIO interrupts to be statically created in the
 *  application specific configuration.  The interrupt service routine for
 *  the Hwi must be set to "GPIO_hwiIntFxn".  Additionally, the GPIO port
 *  number must be provided as a Hwi parameter.  When an interrupt is triggered,
 *  the interrupt status of all (interrupt enabled) pins on a port will be read,
 *  cleared, and the respective callbacks will be executed.  Callbacks will be
 *  called in order from least significant bit to most significant bit.  Keep
 *  in mind that the callback functions will be called in the context of an
 *  interrupt service routine and should be designed accordingly.
 *  The following  is an example for creating a Hwi for Port 2.
 *
 *  Application configuration file:
 *  @code
 *  // All Hwis must be created statically; including those for TI-RTOS drivers.
 *  var hwiParams = new Hwi.Params();
 *
 *  // Add the GPIO port number as a Hwi argument.
 *  hwiParams.arg = 2;
 *
 *  // Create the Hwi with GPIO Port interrupt number and using GPIO_hwiIntFxn
 *  // as the Hwi function.
 *  Program.global.hwi0 = Hwi.create(42, "&GPIO_hwiIntFxn", hwiParams);
 *  @endcode
 *
 *  Callback functions can be assigned to interrupt enabled input pins on
 *  Port 2.
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

#ifndef ti_drivers_GPIOMSP430__include
#define ti_drivers_GPIOMSP430__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ti/drivers/GPIO.h>

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIOMSP430_Config {
    /*! Pointer to the board's PinConfig array */
    GPIO_PinConfig *pinConfigs;

    /*! Pointer to the board's callback array */
    GPIO_CallbackFxn *callbacks;

    /*! Number of configs defined */
    uint32_t numberOfPinConfigs;

    /*! Number of callbacks defined */
    uint32_t numberOfCallbacks;
} GPIOMSP430_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within
 *  the board's pin configuration table.
 */
#define GPIOMSP430_EMPTY_PIN 0x0000

#define GPIOMSP430_P1_0      0x0101
#define GPIOMSP430_P1_1      0x0102
#define GPIOMSP430_P1_2      0x0104
#define GPIOMSP430_P1_3      0x0108
#define GPIOMSP430_P1_4      0x0110
#define GPIOMSP430_P1_5      0x0120
#define GPIOMSP430_P1_6      0x0140
#define GPIOMSP430_P1_7      0x0180

#define GPIOMSP430_P2_0      0x0201
#define GPIOMSP430_P2_1      0x0202
#define GPIOMSP430_P2_2      0x0204
#define GPIOMSP430_P2_3      0x0208
#define GPIOMSP430_P2_4      0x0210
#define GPIOMSP430_P2_5      0x0220
#define GPIOMSP430_P2_6      0x0240
#define GPIOMSP430_P2_7      0x0280

#define GPIOMSP430_P3_0      0x0301
#define GPIOMSP430_P3_1      0x0302
#define GPIOMSP430_P3_2      0x0304
#define GPIOMSP430_P3_3      0x0308
#define GPIOMSP430_P3_4      0x0310
#define GPIOMSP430_P3_5      0x0320
#define GPIOMSP430_P3_6      0x0340
#define GPIOMSP430_P3_7      0x0380

#define GPIOMSP430_P4_0      0x0401
#define GPIOMSP430_P4_1      0x0402
#define GPIOMSP430_P4_2      0x0404
#define GPIOMSP430_P4_3      0x0408
#define GPIOMSP430_P4_4      0x0410
#define GPIOMSP430_P4_5      0x0420
#define GPIOMSP430_P4_6      0x0440
#define GPIOMSP430_P4_7      0x0480

#define GPIOMSP430_P5_0      0x0501
#define GPIOMSP430_P5_1      0x0502
#define GPIOMSP430_P5_2      0x0504
#define GPIOMSP430_P5_3      0x0508
#define GPIOMSP430_P5_4      0x0510
#define GPIOMSP430_P5_5      0x0520
#define GPIOMSP430_P5_6      0x0540
#define GPIOMSP430_P5_7      0x0580

#define GPIOMSP430_P6_0      0x0601
#define GPIOMSP430_P6_1      0x0602
#define GPIOMSP430_P6_2      0x0604
#define GPIOMSP430_P6_3      0x0608
#define GPIOMSP430_P6_4      0x0610
#define GPIOMSP430_P6_5      0x0620
#define GPIOMSP430_P6_6      0x0640
#define GPIOMSP430_P6_7      0x0680

#define GPIOMSP430_P7_0      0x0701
#define GPIOMSP430_P7_1      0x0702
#define GPIOMSP430_P7_2      0x0704
#define GPIOMSP430_P7_3      0x0708
#define GPIOMSP430_P7_4      0x0710
#define GPIOMSP430_P7_5      0x0720
#define GPIOMSP430_P7_6      0x0740
#define GPIOMSP430_P7_7      0x0780

#define GPIOMSP430_P8_0      0x0801
#define GPIOMSP430_P8_1      0x0802
#define GPIOMSP430_P8_2      0x0804
#define GPIOMSP430_P8_3      0x0808
#define GPIOMSP430_P8_4      0x0810
#define GPIOMSP430_P8_5      0x0820
#define GPIOMSP430_P8_6      0x0840
#define GPIOMSP430_P8_7      0x0880

#define GPIOMSP430_P9_0      0x0901
#define GPIOMSP430_P9_1      0x0902
#define GPIOMSP430_P9_2      0x0904
#define GPIOMSP430_P9_3      0x0908
#define GPIOMSP430_P9_4      0x0910
#define GPIOMSP430_P9_5      0x0920
#define GPIOMSP430_P9_6      0x0940
#define GPIOMSP430_P9_7      0x0980

#define GPIOMSP430_P10_0     0x0A01
#define GPIOMSP430_P10_1     0x0A02
#define GPIOMSP430_P10_2     0x0A04
#define GPIOMSP430_P10_3     0x0A08
#define GPIOMSP430_P10_4     0x0A10
#define GPIOMSP430_P10_5     0x0A20
#define GPIOMSP430_P10_6     0x0A40
#define GPIOMSP430_P10_7     0x0A80

#define GPIOMSP430_P11_0     0x0B01
#define GPIOMSP430_P11_1     0x0B02
#define GPIOMSP430_P11_2     0x0B04
#define GPIOMSP430_P11_3     0x0B08
#define GPIOMSP430_P11_4     0x0B10
#define GPIOMSP430_P11_5     0x0B20
#define GPIOMSP430_P11_6     0x0B40
#define GPIOMSP430_P11_7     0x0B80

/* Port J skips to 0xDxx because MSPWare defines port number to 13 (0xD) */
#define GPIOMSP430_PJ_0      0x0D01
#define GPIOMSP430_PJ_1      0x0D02
#define GPIOMSP430_PJ_2      0x0D04
#define GPIOMSP430_PJ_3      0x0D08
#define GPIOMSP430_PJ_4      0x0D10
#define GPIOMSP430_PJ_5      0x0D20
#define GPIOMSP430_PJ_6      0x0D40
#define GPIOMSP430_PJ_7      0x0D80

#endif /* ti_drivers_GPIOMSP430__include */
