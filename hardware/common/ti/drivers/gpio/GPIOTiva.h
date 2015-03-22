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
 *  @file       GPIOTiva.h
 *
 *  @brief      Tiva GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/gpio/GPIOTiva.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins via simple
 *  and portable APIs. The application is required to supply a GPIOTiva_Config
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
 *  2 LEDs on an EK_TM4C1294XL Launchpad board.
 *
 *  Board header file:
 *  @code
 *  // Enum of GPIO names on the EK_TM4C1294XL dev board
 *  typedef enum EK_TM4C1294XL_GPIOName {
 *      EK_TM4C1294XL_USR_SW1 = 0,
 *      EK_TM4C1294XL_USR_SW2,
 *      EK_TM4C1294XL_D1,
 *      EK_TM4C1294XL_D2,
 *
 *      EK_TM4C1294XL_GPIOCOUNT
 *  } EK_TM4C1294XL_GPIOName;
 *  @endcode
 *
 *  Board initialization code:
 *  @code
 *  #include <ti/drivers/GPIO.h>
 *  #include <ti/drivers/gpio/GPIOTiva.h>
 *
 *  // Array of pin configurations
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in EK_TM4C1294XL.h
 *  // NOTE: Pins not used for interrupts should be placed at the end of the
 *           array.  Callback entries can be omitted from callbacks array to
 *           reduce memory usage.
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *      // Input pins
 *      // EK_TM4C1294XL_USR_SW1
 *      GPIOTiva_PJ_0 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *      // EK_TM4C1294XL_USR_SW2
 *      GPIOTiva_PJ_1 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_RISING,
 *
 *      // Output pins
 *      // EK_TM4C1294XL_USR_D1
 *      GPIOTiva_PN_1 | GPIO_CFG_OUTPUT | GPIO_CFG_OUT_STR_HIGH,
 *      // EK_TM4C1294XL_USR_D2
 *      GPIOTiva_PN_0 | GPIO_CFG_OUTPUT | GPIO_CFG_OUT_STR_HIGH
 *  };
 *
 *  // Array of callback function pointers
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in EK_TM4C1294XL.h
 *  // NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *           reduce memory usage (if placed at end of gpioPinConfigs array).
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      NULL,       // EK_TM4C1294XL_USR_SW1
 *      NULL        // EK_TM4C1294XL_USR_SW2
 *  };
 *
 *  // The device-specific GPIO_config structure
 *  const GPIOTiva_Config GPIOTiva_config = {
 *      .pinConfigs = (GPIO_PinConfig *) gpioPinConfigs,
 *      .callbacks = (GPIO_CallbackFxn *) gpioCallbackFunctions,
 *      .numberOfPinConfigs = sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
 *      .numberOfCallbacks = sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
 *      .intPriority = (~0)
 *  };
 *
 *  // Initialize peripheral and pins
 *  void EK_TM4C1294XL_initGPIO(void)
 *  {
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
 *  On select Tiva devices, ports P & Q are capable of per-pin interrupts (each
 *  pin has its own interrupt vector).  If multiple interrupts on port P (or Q)
 *  are triggered, the first interrupt will clear all flags and execute the
 *  respective callbacks.  Interrupts for other pins on P (or Q) will run, but
 *  will not execute callbacks.
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

#ifndef ti_drivers_GPIOTiva__include
#define ti_drivers_GPIOTiva__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ti/drivers/GPIO.h>

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIOTiva_Config {
    /*! Pointer to the board's PinConfig array */
    GPIO_PinConfig *pinConfigs;

    /*! Pointer to the board's callback array */
    GPIO_CallbackFxn *callbacks;

    /*! Number of pin configs defined */
    uint32_t numberOfPinConfigs;

    /*! Number of callbacks defined */
    uint32_t numberOfCallbacks;

    /*! Interrupt priority used for call back interrupts.  Setting ~0 will
     *  configure the lowest possible priority
     */
    uint32_t intPriority;
} GPIOTiva_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within the board's pin
 *  configuration table.  These macros should be OR'd in with the respective pin
 *  configuration settings.
 */
#define GPIOTiva_EMPTY_PIN 0x0000

#define GPIOTiva_PA_0      0x0001
#define GPIOTiva_PA_1      0x0002
#define GPIOTiva_PA_2      0x0004
#define GPIOTiva_PA_3      0x0008
#define GPIOTiva_PA_4      0x0010
#define GPIOTiva_PA_5      0x0020
#define GPIOTiva_PA_6      0x0040
#define GPIOTiva_PA_7      0x0080

#define GPIOTiva_PB_0      0x0101
#define GPIOTiva_PB_1      0x0102
#define GPIOTiva_PB_2      0x0104
#define GPIOTiva_PB_3      0x0108
#define GPIOTiva_PB_4      0x0110
#define GPIOTiva_PB_5      0x0120
#define GPIOTiva_PB_6      0x0140
#define GPIOTiva_PB_7      0x0180

#define GPIOTiva_PC_0      0x0201
#define GPIOTiva_PC_1      0x0202
#define GPIOTiva_PC_2      0x0204
#define GPIOTiva_PC_3      0x0208
#define GPIOTiva_PC_4      0x0210
#define GPIOTiva_PC_5      0x0220
#define GPIOTiva_PC_6      0x0240
#define GPIOTiva_PC_7      0x0280

#define GPIOTiva_PD_0      0x0301
#define GPIOTiva_PD_1      0x0302
#define GPIOTiva_PD_2      0x0304
#define GPIOTiva_PD_3      0x0308
#define GPIOTiva_PD_4      0x0310
#define GPIOTiva_PD_5      0x0320
#define GPIOTiva_PD_6      0x0340
#define GPIOTiva_PD_7      0x0380

#define GPIOTiva_PE_0      0x0401
#define GPIOTiva_PE_1      0x0402
#define GPIOTiva_PE_2      0x0404
#define GPIOTiva_PE_3      0x0408
#define GPIOTiva_PE_4      0x0410
#define GPIOTiva_PE_5      0x0420
#define GPIOTiva_PE_6      0x0440
#define GPIOTiva_PE_7      0x0480

#define GPIOTiva_PF_0      0x0501
#define GPIOTiva_PF_1      0x0502
#define GPIOTiva_PF_2      0x0504
#define GPIOTiva_PF_3      0x0508
#define GPIOTiva_PF_4      0x0510
#define GPIOTiva_PF_5      0x0520
#define GPIOTiva_PF_6      0x0540
#define GPIOTiva_PF_7      0x0580

#define GPIOTiva_PG_0      0x0601
#define GPIOTiva_PG_1      0x0602
#define GPIOTiva_PG_2      0x0604
#define GPIOTiva_PG_3      0x0608
#define GPIOTiva_PG_4      0x0610
#define GPIOTiva_PG_5      0x0620
#define GPIOTiva_PG_6      0x0640
#define GPIOTiva_PG_7      0x0680

#define GPIOTiva_PH_0      0x0701
#define GPIOTiva_PH_1      0x0702
#define GPIOTiva_PH_2      0x0704
#define GPIOTiva_PH_3      0x0708
#define GPIOTiva_PH_4      0x0710
#define GPIOTiva_PH_5      0x0720
#define GPIOTiva_PH_6      0x0740
#define GPIOTiva_PH_7      0x0780

#define GPIOTiva_PJ_0      0x0801
#define GPIOTiva_PJ_1      0x0802
#define GPIOTiva_PJ_2      0x0804
#define GPIOTiva_PJ_3      0x0808
#define GPIOTiva_PJ_4      0x0810
#define GPIOTiva_PJ_5      0x0820
#define GPIOTiva_PJ_6      0x0840
#define GPIOTiva_PJ_7      0x0880

#define GPIOTiva_PK_0      0x0901
#define GPIOTiva_PK_1      0x0902
#define GPIOTiva_PK_2      0x0904
#define GPIOTiva_PK_3      0x0908
#define GPIOTiva_PK_4      0x0910
#define GPIOTiva_PK_5      0x0920
#define GPIOTiva_PK_6      0x0940
#define GPIOTiva_PK_7      0x0980

#define GPIOTiva_PL_0      0x0A01
#define GPIOTiva_PL_1      0x0A02
#define GPIOTiva_PL_2      0x0A04
#define GPIOTiva_PL_3      0x0A08
#define GPIOTiva_PL_4      0x0A10
#define GPIOTiva_PL_5      0x0A20
#define GPIOTiva_PL_6      0x0A40
#define GPIOTiva_PL_7      0x0A80

#define GPIOTiva_PM_0      0x0B01
#define GPIOTiva_PM_1      0x0B02
#define GPIOTiva_PM_2      0x0B04
#define GPIOTiva_PM_3      0x0B08
#define GPIOTiva_PM_4      0x0B10
#define GPIOTiva_PM_5      0x0B20
#define GPIOTiva_PM_6      0x0B40
#define GPIOTiva_PM_7      0x0B80

#define GPIOTiva_PN_0      0x0C01
#define GPIOTiva_PN_1      0x0C02
#define GPIOTiva_PN_2      0x0C04
#define GPIOTiva_PN_3      0x0C08
#define GPIOTiva_PN_4      0x0C10
#define GPIOTiva_PN_5      0x0C20
#define GPIOTiva_PN_6      0x0C40
#define GPIOTiva_PN_7      0x0C80

#if defined(TIVAWARE)
#define GPIOTiva_PP_0      0x1001
#define GPIOTiva_PP_1      0x1002
#define GPIOTiva_PP_2      0x1004
#define GPIOTiva_PP_3      0x1008
#define GPIOTiva_PP_4      0x1010
#define GPIOTiva_PP_5      0x1020
#define GPIOTiva_PP_6      0x1040
#define GPIOTiva_PP_7      0x1080

#define GPIOTiva_PQ_0      0x1101
#define GPIOTiva_PQ_1      0x1102
#define GPIOTiva_PQ_2      0x1104
#define GPIOTiva_PQ_3      0x1108
#define GPIOTiva_PQ_4      0x1110
#define GPIOTiva_PQ_5      0x1120
#define GPIOTiva_PQ_6      0x1140
#define GPIOTiva_PQ_7      0x1180

#define GPIOTiva_PR_0      0x0D01
#define GPIOTiva_PR_1      0x0D02
#define GPIOTiva_PR_2      0x0D04
#define GPIOTiva_PR_3      0x0D08
#define GPIOTiva_PR_4      0x0D10
#define GPIOTiva_PR_5      0x0D20
#define GPIOTiva_PR_6      0x0D40
#define GPIOTiva_PR_7      0x0D80

#define GPIOTiva_PS_0      0x0E01
#define GPIOTiva_PS_1      0x0E02
#define GPIOTiva_PS_2      0x0E04
#define GPIOTiva_PS_3      0x0E08
#define GPIOTiva_PS_4      0x0E10
#define GPIOTiva_PS_5      0x0E20
#define GPIOTiva_PS_6      0x0E40
#define GPIOTiva_PS_7      0x0E80

#define GPIOTiva_PT_0      0x0F01
#define GPIOTiva_PT_1      0x0F02
#define GPIOTiva_PT_2      0x0F04
#define GPIOTiva_PT_3      0x0F08

#else /* defined(MWARE) */
#define GPIOTiva_PP_0      0x0D01
#define GPIOTiva_PP_1      0x0D02
#define GPIOTiva_PP_2      0x0D04
#define GPIOTiva_PP_3      0x0D08
#define GPIOTiva_PP_4      0x0D10
#define GPIOTiva_PP_5      0x0D20
#define GPIOTiva_PP_6      0x0D40
#define GPIOTiva_PP_7      0x0D80

#define GPIOTiva_PQ_0      0x0E01
#define GPIOTiva_PQ_1      0x0E02
#define GPIOTiva_PQ_2      0x0E04
#define GPIOTiva_PQ_3      0x0E08
#define GPIOTiva_PQ_4      0x0E10
#define GPIOTiva_PQ_5      0x0E20
#define GPIOTiva_PQ_6      0x0E40
#define GPIOTiva_PQ_7      0x0E80

#define GPIOTiva_PR_0      0x0F01
#define GPIOTiva_PR_1      0x0F02
#define GPIOTiva_PR_2      0x0F04
#define GPIOTiva_PR_3      0x0F08
#define GPIOTiva_PR_4      0x0F10
#define GPIOTiva_PR_5      0x0F20
#define GPIOTiva_PR_6      0x0F40
#define GPIOTiva_PR_7      0x0F80

#define GPIOTiva_PS_0      0x1001
#define GPIOTiva_PS_1      0x1002
#define GPIOTiva_PS_2      0x1004
#define GPIOTiva_PS_3      0x1008
#define GPIOTiva_PS_4      0x1010
#define GPIOTiva_PS_5      0x1020
#define GPIOTiva_PS_6      0x1040
#define GPIOTiva_PS_7      0x1080
#endif

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIOTiva__include */
