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

#include <stdint.h>
#include <stdbool.h>

/*
 * By default disable both asserts and log for this module.
 * This must be done before DebugP.h is included.
 */
#ifndef DebugP_ASSERT_ENABLED
#define DebugP_ASSERT_ENABLED 0
#endif
#ifndef DebugP_LOG_ENABLED
#define DebugP_LOG_ENABLED 0
#endif
#include <ti/drivers/ports/DebugP.h>
#include <ti/drivers/ports/HwiP.h>

#include "GPIO2.h"
#include "GPIO2MSP432.h"

/* driverlib header files */
#include <rom.h>
#include <rom_map.h>
#include <gpio.h>

/*
 * Internal function used to find the index of the left most set bit in
 * efficient way
 */
#if defined(__IAR_SYSTEMS_ICC__) || defined(DOXYGEN)
    #include <intrinsics.h>
#endif

__STATIC_INLINE uint32_t GPIOMSP432_getPinNumber(uint32_t x) {
#if defined(__TI_COMPILER_VERSION__)
    return __clz(__rbit(x));
#elif defined(codered) || defined(__GNUC__) || defined(sourcerygxx)
    return __builtin_ctz(x);
#elif defined(__IAR_SYSTEMS_ICC__) || defined(DOXYGEN)
    return __CLZ(__RBIT(x));
#elif defined(rvmdk) || defined(__ARMCC_VERSION)
    return __clz(__rbit(x));
#else
    #error "Unsupported compiler used"
#endif
}

/* 
 * Map GPIO2_INT types to corresponding MSP432 interrupt options
 */
static const uint8_t interruptType[] = {
    0,                              /* Undefined interrupt type */
    GPIO_HIGH_TO_LOW_TRANSITION,    /* 1 = Interrupt on falling edge */
    GPIO_LOW_TO_HIGH_TRANSITION,    /* 2 = Interrupt on rising edge */
    GPIO_HIGH_TO_LOW_TRANSITION |   /* 3 = Interrupt on both edges */
    GPIO_LOW_TO_HIGH_TRANSITION,
    GPIO_INPUT_PIN_LOW,             /* 4 = Interrupt on low level */
    GPIO_INPUT_PIN_HIGH             /* 5 = Interrupt on high level */
};

/*
 * Table of port interrupt vector numbers
 * Used by setCallback() to create Hwis.
 * Up to 6 port interrupts must be supported
 */
static const uint8_t GPIO2MSP432_portInterruptIds[] = {
    INT_PORT1, INT_PORT2, INT_PORT3, INT_PORT4,
    INT_PORT5, INT_PORT6
};

/*
 * bit mask used to determine if a Hwi has been created/constructed
 * for a port already.
 * up to 6 port interrupts must be supported
 */
static uint8_t GPIO2MSP432_portHwiCreatedBitMask = 0;

/*
 * Table of pin configurations, indexed by user defined indexes
 * Defined in Board.c
 */
static GPIO2_PinConfig *gpio2PinConfigs;

/*
 * Table of callback functions, indexed by user defined indexes
 * Defined in Board.c
 */
static GPIO2_CallbackFxn *gpio2CallbackFunctions;

extern GPIO2_Config GPIO2_config;

/*
 * internal variable to sanity check pin indexes passed to various APIs
 * count of pins is passed to GPIO2_init().
 */
static int GPIO2_configCount = -1; /* Also used to check status for initialization */

/*
 * Internal Hwi function used to service port/pin interrupts
 */
static void GPIO2_hwiIntFxn(uintptr_t portIndex);

/*
 * user defined pin indexes assigned to a port's 8 pins.
 * Used by port interrupt function to located callback assigned
 * to a pin.
 */
typedef struct GPIO2_PortCallbackInfo {
    uint8_t pinIndex[8];    /* the port's 8 corresponding */
                            /* user defined pinId indices */
} GPIO2_PortCallbackInfo;

/*
 * Table of 6 portCallbackInfos.
 * One for each port.
 * NOTE!!! Should this be declared/initialized in Board.c so that it can be a const?
 */
GPIO2_PortCallbackInfo gpio2CallbackInfo[6];

/* uninitialized callbackInfo pinIndex */
#define CALLBACK_INDEX_NOT_CONFIGURED 0xff

#warning Hwi priority fixed to (2), should be added as a GPIO parameter
#define GPIOMSP432_HWI_PRIORITY 2

/*
 *  ======== GPIO2_clearInt ========
 */
void GPIO2_clearInt(unsigned int index)
{
    unsigned int key;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];
    
    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);
    
    /* Make atomic update */
    key = HwiP_enterCritical();

    /* Clear GPIO interrupt flag */
    MAP_GPIO_clearInterruptFlag(config->port, config->pin);

    HwiP_exitCritical(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x interrupt flag cleared",
                port, pin);
}

/*
 *  ======== GPIO2_disableInt ========
 */
void GPIO2_disableInt(unsigned int index)
{
    unsigned int key;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];

    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);

    /* Make atomic update */
    key = HwiP_enterCritical();

    /* Disable GPIO interrupt */
    MAP_GPIO_disableInterrupt(config->port, config->pin);

    HwiP_exitCritical(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x interrupts disabled",
                port, pin);
}

/*
 *  ======== GPIO2_enableInt ========
 */
void GPIO2_enableInt(unsigned int index)
{
    unsigned int key;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];

    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);

    /* Make atomic update */
    key = HwiP_enterCritical();

    /* Enable GPIO interrupt */
    MAP_GPIO_enableInterrupt(config->port, config->pin);

    HwiP_exitCritical(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x interrupts enabled",
                port, pin);
}

/*
 *  ======== GPIO2_hwiIntFxn ========
 *  Hwi function that processes GPIO interrupts.
 */
void GPIO2_hwiIntFxn(uintptr_t portIndex)
{
    GPIO2_PortCallbackInfo *portCallbackInfo;
    uint32_t port;
    uint32_t pins;
    unsigned int i;

    portCallbackInfo = &gpio2CallbackInfo[portIndex];
    port = portIndex + 1;

    /* Find out which pins have their interrupt flags set */
    pins = MAP_GPIO_getEnabledInterruptStatus(port);

    /* Match the interrupt to its corresponding callback function */
    for (i = 0; pins; i++) {
        if (pins & 0x1) {
            MAP_GPIO_clearInterruptFlag(port, (1 << i));
            if (portCallbackInfo->pinIndex[i] != CALLBACK_INDEX_NOT_CONFIGURED) {
                gpio2CallbackFunctions[portCallbackInfo->pinIndex[i]]();
            }
        }
        pins = pins >> 1;
    }
}

/*
 *  ======== GPIO2_init ========
 */
void GPIO2_init()
{
    unsigned int i, j;

    GPIO2_configCount = GPIO2_config.numberOfPinConfigs;
    gpio2CallbackFunctions = GPIO2_config.callbacks;
    gpio2PinConfigs = GPIO2_config.pinConfigs;
    
    /*
     * NOTE!!! would like to support a const gpio2CallbackInfo definition
     * for now, initialize all entries with 'not configured' key.
     */
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            gpio2CallbackInfo[i].pinIndex[j] = CALLBACK_INDEX_NOT_CONFIGURED;
        }
    }

    /*
     * Configure pins and create Hwis per static array content
     */
    for (i = 0; i < GPIO2_configCount; i++) {
        if (gpio2PinConfigs[i] != GPIO2_DO_NOT_CONFIG) {
            GPIO2_setConfig(i, gpio2PinConfigs[i]);
            if (i < GPIO2_config.numberOfCallbacks) {
                if (gpio2CallbackFunctions[i] != NULL) {
                    /* create Hwi as necessary */
                    GPIO2_setCallback(i, gpio2CallbackFunctions[i]);
                }
            }
        }
    }
}

/*
 *  ======== GPIO2_read ========
 */
uint32_t GPIO2_read(unsigned int index)
{
    unsigned int key;
    uint32_t value;
    
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];

    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);

    /* Make atomic update */
    key = HwiP_enterCritical();
    
    value = MAP_GPIO_getInputPinValue(config->port, config->pin);

    HwiP_exitCritical(key);

    DebugP_log3("GPIO: port 0x%x, pin 0x%x read 0x%x", port,
                pin, value);

    return (value);
}

/*
 *  ======== GPIO2_setCallback ========
 */
bool GPIO2_setCallback(unsigned int index, GPIO2_CallbackFxn callback)
{
    HwiP_Status status;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];
    uint32_t portIndex, portBitMask;
    uint32_t pinNum;

    DebugP_assert(GPIO2_config.numberOfCallbacks >= 0 && (int)index < GPIO2_config.numberOfCallbacks);

    if (!(index < GPIO2_config.numberOfCallbacks)) return (1);

    portIndex = config->port - 1;
    portBitMask = 1 << portIndex;

    /* if Hwi has not already been created, do so */
    if (!GPIO2MSP432_portHwiCreatedBitMask & portBitMask) {
        /* Create Hwi object for GPIO pin */
        status = HwiP_registerCortexM(GPIO2MSP432_portInterruptIds[portIndex],
                                  GPIO2_hwiIntFxn,
                                   /* index into callBackInfo array */
                                  (uintptr_t) portIndex,
                                  GPIOMSP432_HWI_PRIORITY);
        GPIO2MSP432_portHwiCreatedBitMask |= portBitMask;
    }

    if (status != HwiP_OK) {
        /* Error creating Hwi */
        DebugP_log1("GPIO2: Error constructing Hwi for GPIO Port %d",
                    config->port);
    }

    /* 
     * plug the pin index into the corresponding 
     * port's callbackInfo pinIndex entry 
     */
    pinNum = GPIOMSP432_getPinNumber(config->pin);
    gpio2CallbackInfo[portIndex].pinIndex[pinNum] = index;

    /*
     * Only update callBackFunctions entry if different.
     * This allows the callBackFunctions array to be in flash for static systems.
     */
    if (gpio2CallbackFunctions[index] != callback) {
        gpio2CallbackFunctions[index] = callback;
    }
    
    return (0);
}

/*
 *  ======== GPIO2_setConfig ========
 */
bool GPIO2_setConfig(unsigned int index, GPIO2_PinConfig pinConfig)
{
    unsigned int key;
    uint32_t port, pin;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];

    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);

    if (!(index < GPIO2_configCount)) return (1);

    port = config->port;
    pin = config->pin;

    /* Make atomic update */
    key = HwiP_enterCritical();

    switch(pinConfig & GPIO2_IO_CONFIG_MASK) {
        case GPIO2_OUTPUT_LOW_STRENGTH:
            MAP_GPIO_setAsOutputPin(port, pin);
            MAP_GPIO_setDriveStrengthLow(port, pin);
            MAP_GPIO_setOutputLowOnPin(port, pin);
            break;

        case GPIO2_OUTPUT_HIGH_STRENGTH:
            MAP_GPIO_setAsOutputPin(port, pin);
            MAP_GPIO_setDriveStrengthHigh(port, pin);
            MAP_GPIO_setOutputLowOnPin(port, pin);
            break;

        case GPIO2_INPUT_PULLUP:
            MAP_GPIO_setAsInputPinWithPullUpResistor(port, pin);
            break;

        case GPIO2_INPUT_PULLDOWN:
            MAP_GPIO_setAsInputPinWithPullDownResistor(port, pin);
            break;
    }

    /* Set type of interrupt and then enable it */
    if (pinConfig & GPIO2_INT_CONFIG_MASK) {
        MAP_GPIO_interruptEdgeSelect(port, pin, 
             interruptType[GPIO2MSP432_getIntTypeNumber(pinConfig)]);
        MAP_GPIO_clearInterruptFlag(port, pin);
    }

    HwiP_exitCritical(key);
    
    return (0);
}

/*
 *  ======== GPIO2_toggle ========
 */
void GPIO2_toggle(unsigned int index)
{
    unsigned int key;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];

    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);

    /* Make atomic update */
    key = HwiP_enterCritical();

    MAP_GPIO_toggleOutputOnPin(config->port, config->pin);

    HwiP_exitCritical(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x toggled",
                    port, pin);
}

/*
 *  ======== GPIO2_write ========
 */
void GPIO2_write(unsigned int index, uint32_t value)
{
    unsigned int key;
    GPIO2MSP432_PinConfig *config = (GPIO2MSP432_PinConfig *)&gpio2PinConfigs[index];

    DebugP_assert(GPIO2_configCount >= 0 && (int)index < GPIO2_configCount);

    key = HwiP_enterCritical();

    if (value != 0) {
        MAP_GPIO_setOutputHighOnPin(config->port, config->pin);
    }
    else {
        MAP_GPIO_setOutputLowOnPin(config->port, config->pin);
    }

    HwiP_exitCritical(key);

    DebugP_log3("GPIO: port 0x%x, pin 0x%x wrote 0x%x",
                port, pin, value);
}
