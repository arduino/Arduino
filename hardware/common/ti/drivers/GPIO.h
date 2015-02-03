/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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
 *  @file       GPIO.h
 *
 *  @brief      GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/GPIO.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins and ports via
 *  simple and portable APIs. The application needs to supply a GPIO_Config
 *  structure to the module. The application needs to initialize the GPIO
 *  hardware peripherals, setup the pins used and call GPIO_init(). Once that is
 *  completed the other APIs can be used to access the pins.
 *
 *  Asserts are used to verify that the driver has only been initialized once,
 *  is reading/writing a valid index, and is writing to an output pin.
 *
 *  The following is an example of the code that must be implemented to use LD2
 *  without interrupts on a TMDXDOCKH52C1 board.
 *
 *  Board header:
 *  @code
 *  // LEDs on TMDXDOCKH52C1 are active low
 *  #define TMDXDOCKH52C1_LED_OFF (~0)
 *  #define TMDXDOCKH52C1_LED_ON  (0)
 *
 *  // Enum of LED names on the TMDXDOCKH52C1 dev board
 *  typedef enum TMDXDOCKH52C1_GPIOName {
 *      TMDXDOCKH52C1_LD2 = 0,
 *
 *      TMDXDOCKH52C1_GPIOCOUNT
 *  } TMDXDOCKH52C1_GPIOName;
 *  @endcode
 *
 *  Board initialization code:
 *  @code
 *  // GPIO configuration structures
 *  const GPIO_HWAttrs gpioHWAttrs[TMDXDOCKH52C1_GPIOCOUNT] = {
 *      {GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_OUTPUT},
 *  };
 *
 *  const GPIO_Config GPIO_config[] = {
 *     {&gpioHWAttrs[0]},
 *     {NULL},
 * };
 *
 *  // Initialize peripheral and pins using MWare APIs
 *  void TMDXDOCKH52C1_initGPIO(void)
 *  {
 *      GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_6);
 *
 *      //Once GPIO_init() is called, GPIO_config cannot be changed
 *      GPIO_init();
 *  }
 *  @endcode
 *
 *  Application code:
 *  @code
 *  TMDXDOCKH52C1_initGeneral(); // Initialize general board specific settings
 *  TMDXDOCKH52C1_initGPIO(); // Setup GPIO and initialize the driver
 *  GPIO_write(TMDXDOCKH52C1_LED, TMDXDOCKH52C1_LED_ON); // Turn on LED
 *  @endcode
 *
 *  ## GPIO interrupts #
 *
 *  To use GPIO interrupts on input pins use the following board initalization
 *  code.
 *
 *  @code
 *  // Callback function prototype for GPIO interrupts
 *  void buttonFxn();
 *
 *  // GPIO configuration structures
 *  const GPIO_HWAttrs gpioHWAttrs[TMDXDOCKH52C1_GPIOCOUNT] = {
 *      {GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_INPUT},
 *  };
 *
 *  //Memory for the GPIO module to construct a Hwi
 *  Hwi_Struct callbackHwi;
 *
 *  // GPIO callback structure to set callbacks for GPIO interrupts.
 *  // Pin 0 corresponds to callback function at index 0 and so on.
 *  const GPIO_Callbacks TMDXDOCKH52C1_gpioPortBCallbacks = {
 *      GPIO_PORTB_BASE, INT_GPIOB, &callbackHwi,
 *      {NULL, NULL, NULL, NULL, buttonFxn, NULL, NULL, NULL}
 *  };
 *  const GPIO_Config GPIO_config[] = {
 *      {&gpioHWAttrs[0]},
 *      {NULL},
 *  };
 *
 *  // Initialize peripheral and pins using MWare APIs
 *  void TMDXDOCKH52C1_initGPIO(void)
 *  {
 *      GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_4);
 *      GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_PIN_TYPE_STD_WPU);
 *
 *      //Once GPIO_init() is called, GPIO_config cannot be changed
 *      GPIO_init();
 *  }
 *  @endcode
 *
 *  Application code:
 *  @code
 *  // Callback function for GPIO interrupts
 *  void buttonFxn()
 *  {
 *      ....
 *  }
 *
 *  int main(void)
 *  {
 *      TMDXDOCKH52C1_initGeneral(); // Initialize general board specific settings
 *      TMDXDOCKH52C1_initGPIO(); // Setup GPIO and initialize the driver
 *
 *      GPIO_setupCallbacks(&TMDXDOCKH52C1_gpioPortBCallbacks); // Setup interrupts
 *
 *      GPIO_enableInt(TMDXDOCKH52C1_BUTTON, GPIO_INT_RISING); // Enable interrupts
 *  }
 *  @endcode
 *
 *  Keep in mind that the callback functions will be called in the context of
 *  an interrupt service routine and should be designed accordingly. Also, it
 *  is the user's responsibility to call GPIO_clearInt() to allow further
 *  interrupt to occur. The callback setup is not supported for all platforms.
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

#ifndef ti_drivers_GPIO__include
#define ti_drivers_GPIO__include

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CC26XXWARE
#include <driverlib/gpio.h>
#endif

#include <stdint.h>

/* Extern'd GPIO_IntFxn */
extern void GPIO_hwiIntFxn(uintptr_t callbacks);

/*!
 *  @brief  GPIO direction indictator
 */
typedef enum GPIO_Direction {
    /*! Denotes a GPIO pin is output. */
    GPIO_OUTPUT,

    /*! Denotes a GPIO pin is input. */
    GPIO_INPUT
} GPIO_Direction;

/*!
 *  @brief  GPIO interrupt type
 */
typedef enum GPIO_IntType {
    GPIO_INT_FALLING    = 0,    /*!< Interrupt on falling edge */
    GPIO_INT_RISING     = 1,    /*!< Interrupt on rising edge */
    GPIO_INT_BOTH_EDGES = 2,    /*!< Interrupt on both edges */
    GPIO_INT_LOW        = 3,    /*!< Interrupt on low level */
    GPIO_INT_HIGH       = 4     /*!< Interrupt on high level */
} GPIO_IntType;

#ifndef CC26XXWARE
/*!
 *  @brief  GPIO callback structure
 *
 *  This structure contains pointers to the callback functions that will be
 *  called when an interrupt occurs. Each function pointer in the callbackFxn
 *  array corresponds to a pin in the specified port (pin 0 to index 0 and so
 *  on). A GPIO_Callbacks structure must be present for each port that has one
 *  or more pins that use GPIO interrupts. This structure must exist and be
 *  persistent before it can be passed to the GPIO_setupCallbacks() API.
 */
typedef struct GPIO_Callbacks {
    uint32_t port;           /*!< GPIO port */
    unsigned int intNum;     /*!< GPIO interrupt number */
    void *hwiStruct;         /*!< Pointer to a family specific Hwi_Struct */
    /*!< Array of callbacks, one per pin */
    void (*callbackFxn[8])(void);
} GPIO_Callbacks;

/*!
 *  @brief  GPIO Hardware attributes
 *
 *  This structure characterizes a particular general purpose input/output pin.
 *  A GPIO is identified to be a particular pin on a particular GPIO port.
 *  The GPIO driver associates a GPIO port/pin pair with a input/output
 *  direction.
 *
 *  Using this information, the GPIO driver can perform basic pin read and write
 *  operations.
 */
typedef struct GPIO_HWAttrs {
    uint32_t port;              /*!< GPIO port */
    uint32_t pin;               /*!< GPIO pin(s) */
    GPIO_Direction direction;   /*!< Direction of the pin */
} GPIO_HWAttrs;

#else
/*!
 *  @brief  GPIO callback structure
 *
 *  This structure contains pointers to the callback functions that will be
 *  called when an interrupt occurs. Each function pointer in the callbackFxn
 *  array corresponds to a pin in the specified port (pin 0 to index 0 and so
 *  on). A GPIO_Callbacks structure must be present for each port that has one
 *  or more pins that use GPIO interrupts. This structure must exist and be
 *  persistent before it can be passed to the GPIO_setupCallbacks() API.
 */
typedef struct GPIO_Callbacks {
    unsigned int intNum;     /*!< GPIO interrupt number */
    void *hwiStruct;         /*!< Pointer to a family specific Hwi_Struct */
    /*!< Array of callbacks, one per pin */
    void (*callbackFxn[NUM_GPIO_PINS])(void);
} GPIO_Callbacks;

/*!
 *  @brief  GPIO Hardware attributes
 *
 *  This structure characterizes a particular general purpose input/output pin.
 *  A GPIO is identified to be a particular pin on a particular GPIO port.
 *  The GPIO driver associates a GPIO port/pin pair with a input/output
 *  direction.
 *
 *  Using this information, the GPIO driver can perform basic pin read and write
 *  operations.
 */
typedef struct GPIO_HWAttrs {
    uint32_t pin;               /*!< GPIO pin(s) */
    GPIO_Direction direction;   /*!< Direction of the pin */
    uint32_t event;             /*!< Event source(s) */
} GPIO_HWAttrs;

/*!
 *  @brief      Powers up the GPIO module.
 */
extern void GPIO_open();

/*!
 *  @brief      Powers down the GPIO module.
 */
extern void GPIO_close();

/*!
 *  @brief      Enables GPIO wake up
 *
 *  Enables GPIO wake up for the selected GPIO index. The function uses wake up
 *  event number 1 (AON_EVENT_MCU_WU1).
 *
 *  @param      index       GPIO index
 */
extern void GPIO_enableWakeUp(unsigned int index);

/*!
 *  @brief      Enables GPIO wake up specifying wake up event to be triggered
 *
 *  Enables GPIO wake up for the selected GPIO index to occur by triggering event
 *  specified by wuEvent. The function supports the 4 different wake up event
 *  registers, so up to 4 different GPIO can be used to wake up.
 *
 *  @param      wuEvent     wake up event to be triggered (0-3)
 *  @param      index       GPIO index
 */
extern void GPIO_enableWakeUpSetEvent(unsigned int wuEvent, unsigned int index);
#endif

/*!
 *  @brief  GPIO Global configuration
 */
typedef struct GPIO_Config {
    /*!< Pointer to a hardware attributes structure */
    GPIO_HWAttrs  const *hwAttrs;
} GPIO_Config;

/*!
 *  @brief      Clears the GPIO interrupt flag
 *
 *  Clears the GPIO interrupt for the specified index. For edge-triggered
 *  interrupts, this function must be called to allow any further interrupts.
 *
 *  @param      index       GPIO index
 */
extern void GPIO_clearInt(unsigned int index);

/*!
 *  @brief      Disables GPIO interrupts
 *
 *  Disables interrupts for the specified GPIO index.
 *
 *  @param      index       GPIO index
 */
extern void GPIO_disableInt(unsigned int index);

/*!
 *  @brief      Enables GPIO interrupts
 *
 *  Enables GPIO interrupts for the selected index to occur when the action
 *  specified by intType occurs.
 *
 *  @param      index       GPIO index
 *  @param      intType     Pin event that causes an interrupt
 */
extern void GPIO_enableInt(unsigned int index, GPIO_IntType intType);

/*!
 *  @brief  Initializes the GPIO module
 *
 *  The application provided *GPIO_config* must be initialized before the
 *  GPIO_init() function is called. The *GPIO_config* must be persistent and not
 *  changed after GPIO_init() is called
 */
extern void GPIO_init(void);

/*!
 *  @brief      Initializes GPIO interrupts
 *
 *  Uses the GPIO_Callbacks structure to create the hardware interrupts needed
 *  by GPIO. callbacks must be persistent before this function can be called.
 *  This function must be called before before GPIO_enableInt().
 *
 *  This function is not thread-safe. Multiple threads should not call this
 *  at the same time.
 *
 *  This function is not supported on all platforms.
 *
 *  @param      callbacks   GPIO_Callbacks structure for the port being set up
 */
extern void GPIO_setupCallbacks(GPIO_Callbacks const *callbacks);

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
extern uint32_t GPIO_read(unsigned int index);

/*!
 *  @brief      Toggles the current state of a GPIO
 *
 *  @param      index  GPIO index
 */
extern void GPIO_toggle(unsigned int index);

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
extern void GPIO_write(unsigned int index, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIO__include */
