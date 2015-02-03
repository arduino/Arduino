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
 *  @file       C3200_LP.h
 *
 *  @brief      CC3200 Board Specific APIs
 *
 *  The CC3200_LP header file should be included in an application as follows:
 *  @code
 *  #include <CC3200_LP.h>
 *  @endcode
 *
 *  ============================================================================
 */
#ifndef __CC3200_LP_H
#define __CC3200_LP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/GPIO.h>

#define CC3200_LP_LED_OFF (0)
#define CC3200_LP_LED_ON  (~0)

/* GPIO_Callbacks structure for GPIO interrupts */
extern GPIO_Callbacks CC3200_LP_gpioPortA0Callbacks;
extern GPIO_Callbacks CC3200_LP_gpioPortA1Callbacks;
extern GPIO_Callbacks CC3200_LP_gpioPortA2Callbacks;
extern GPIO_Callbacks CC3200_LP_gpioPortA3Callbacks;

/*!
 *  @def    CC3200_LP_GPIOName
 *  @brief  Enum of GPIO names on the CC3200_LP dev board
 */
typedef enum CC3200_LP_GPIOName {
    CC3200_LP_LED_D7 = 9,
    CC3200_LP_LED_D6 = 10,
    CC3200_LP_LED_D5 = 11,
    CC3200_LP_SW2 = 22,
    CC3200_LP_SW3 = 13,

    CC3200_LP_GPIOCOUNT = 32
} CC3200_LP_GPIOName;

/*!
 *  @def    CC3200_LP_I2CName
 *  @brief  Enum of I2C names on the CC3200_LP dev board
 */
typedef enum CC3200_LP_I2CName {
    CC3200_LP_I2C0 = 0,

    CC3200_LP_I2CCOUNT
} CC3200_LP_I2CName;

/*!
 *  @def    CC3200_LP_SDSPIName
 *  @brief  Enum of SDSPI names on the CC3200_LP dev board
 */
typedef enum CC3200_LP_SDSPIName {
    CC3200_LP_SDSPI0 = 0,

    CC3200_LP_SDSPICOUNT
} CC3200_LP_SDSPIName;

/*!
 *  @def    CC3200_LP_SPIName
 *  @brief  Enum of SPI names on the CC3200_LP dev board
 */
typedef enum CC3200_LP_SPIName {
    CC3200_LP_SPI0 = 0,
    CC3200_LP_SPI1,

    CC3200_LP_SPICOUNT
} CC3200_LP_SPIName;

/*!
 *  @def    CC3200_LP_UARTName
 *  @brief  Enum of UARTs on the CC3200_LP dev board
 */
typedef enum CC3200_LP_UARTName {
    CC3200_LP_UART0 = 0,
    CC3200_LP_UART1,

    CC3200_LP_UARTCOUNT
} CC3200_LP_UARTName;

/*!
 *  @def    CC3200_LP_WatchdogName
 *  @brief  Enum of Watchdogs on the CC3200_LP dev board
 */
typedef enum CC3200_LP_WatchdogName {
    CC3200_LP_WATCHDOG0 = 0,

    CC3200_LP_WATCHDOGCOUNT
} CC3200_LP_WatchdogName;

/*!
 *  @def    CC3200_LP_WiFiName
 *  @brief  Enum of WiFi names on the CC3200_LP dev board
 */
typedef enum CC3200_LP_WiFiName {
    CC3200_LP_WIFI = 0,

    CC3200_LP_WIFICOUNT
} CC3200_LP_WiFiName;

/*!
 *  @brief  Initialize board specific DMA settings
 *
 *  This function creates a hwi in case the DMA controller creates an error
 *  interrupt, enables the DMA and supplies it with a uDMA control table.
 */
extern void CC3200_LP_initDMA(void);

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings. This include
 *     - Enable clock sources for peripherals
 */
extern void CC3200_LP_initGeneral(void);

/*!
 *  @brief  Initialize board specific GPIO settings
 *
 *  This function initializes the board specific GPIO settings and
 *  then calls the GPIO_init API to initialize the GPIO module.
 *
 *  The GPIOs controlled by the GPIO module are determined by the GPIO_config
 *  variable.
 */
extern void CC3200_LP_initGPIO(void);

/*!
 *  @brief  Initialize board specific I2C settings
 *
 *  This function initializes the board specific I2C settings and then calls
 *  the I2C_init API to initialize the I2C module.
 *
 *  The I2C peripherals controlled by the I2C module are determined by the
 *  I2C_config variable.
 */
extern void CC3200_LP_initI2C(void);

/*!
 *  @brief  Initialize board specific SDSPI settings
 *
 *  This function initializes the board specific SDSPI settings and then calls
 *  the SDSPI_init API to initialize the SDSPI module.
 *
 *  The SDSPI peripherals controlled by the SDSPI module are determined by the
 *  SDSPI_config variable.
 */
extern void CC3200_LP_initSDSPI(void);

/*!
 *  @brief  Initialize board specific SPI settings
 *
 *  This function initializes the board specific SPI settings and then calls
 *  the SPI_init API to initialize the SPI module.
 *
 *  The SPI peripherals controlled by the SPI module are determined by the
 *  SPI_config variable.
 */
extern void CC3200_LP_initSPI(void);

/*!
 *  @brief  Initialize board specific UART settings
 *
 *  This function initializes the board specific UART settings and then calls
 *  the UART_init API to initialize the UART module.
 *
 *  The UART peripherals controlled by the UART module are determined by the
 *  UART_config variable.
 */
extern void CC3200_LP_initUART(void);

/*!
 *  @brief  Initialize board specific Watchdog settings
 *
 *  This function initializes the board specific Watchdog settings and then
 *  calls the Watchdog_init API to initialize the Watchdog module.
 *
 *  The Watchdog peripherals controlled by the Watchdog module are determined
 *  by the Watchdog_config variable.
 */
extern void CC3200_LP_initWatchdog(void);

/*!
 *  @brief  Initialize board specific WiFi settings
 *
 *  This function initializes the board specific WiFi settings and then calls
 *  the WiFi_init API to initialize the WiFi module.
 *
 *  The hardware resources controlled by the WiFi module are determined by the
 *  WiFi_config variable.
 */
extern void CC3200_LP_initWiFi(void);

#ifdef __cplusplus
}
#endif

#endif /* __CC3200_LP_H */
