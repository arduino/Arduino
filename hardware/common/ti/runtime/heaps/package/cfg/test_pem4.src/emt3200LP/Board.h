/** ===========================================================================
 *  @file       Board.h
 *
 *  @brief      Tink2 Board Specific APIs
 *
 *  This header file "extends" the declarations provided by
 *  ti/drivers/bsp/Board.h with declarations that are specific to the
 *  CC3200 Launch Pad hardware platform.
 *
 *  ===========================================================================
 */
#ifndef __ti_platforms_tink2_Board_H
#define __ti_platforms_tink2_Board_H

#include <ti/drivers/bsp/Board.h>
#include <ti/drivers/GPIO.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @def    Board_GPIOName
 *  @brief  Enum of GPIO names on the CC3200 LaunchPad (LP) dev board
 */
typedef enum Board_GPIOName {
    Board_GPIO3 = 0, 	/* Wiring id 2 (LP P1.2) */
    Board_GPIO_P1_2 = Board_GPIO3,

    Board_GPIO13 = 1, 	/* Wiring id 3 (LP P1.3) LaunchPad SW3 on P1.3 */
    Board_GPIO_P1_3 = Board_GPIO13,
    Board_BUTTON1 = Board_GPIO13, 	/* LaunchPad SW3 on P1.3 */

    Board_GPIO4 = 2, 	/* Wiring id 6 (LP P1.6) */
    Board_GPIO_P1_6 = Board_GPIO4,

    Board_GPIO10 = 3, 	/* Wiring id 9 (LP P1.9) */
    Board_GPIO_P1_9 = Board_GPIO10,

    Board_GPIO11 = 4, 	/* Wiring id 10 (LP P1.10) */
    Board_GPIO_P1_10 = Board_GPIO11,

    Board_GPIO22 = 5, 	/* Wiring id 11 (LP P2.10) LaunchPad SW2 button on P2.10 */
    Board_GPIO_P2_10 = Board_GPIO22,
    Board_BUTTON0 = Board_GPIO22, 	/* LaunchPad SW2 button on P2.10 */

    Board_GPIO9 = 6, 	/* Wiring id 29 (LP P3.9) Red LED_D7 */
    Board_GPIO_P3_9 = Board_GPIO9,
    Board_LED_RED = Board_GPIO9, 	/* Red LED_D7 */

    Board_GPIOCOUNT
} Board_GPIOName;

/*!
 *  @def    Board_I2CName
 *  @brief  Enum of I2C names on the CC3200_LP dev board
 */
typedef enum Board_I2CName {
    Board_I2C0 = 0,

    Board_I2CCOUNT
} Board_I2CName;

/*!
 *  @def    Board_PWMName
 *  @brief  Enum of PWM pin names on the CC3200_LP dev board
 */
typedef enum Board_PWMName {
    Board_PWM0 = 0, /* PWM output from TIMERA0 side A */
    Board_PWM1 = 1, /* PWM output from TIMERA0 side B */
    Board_PWM2 = 2, /* PWM output from TIMERA1 side A */
    Board_PWM3 = 3, /* PWM output from TIMERA1 side B */
    Board_PWM4 = 4, /* PWM output from TIMERA2 side A */
    Board_PWM5 = 5, /* PWM output from TIMERA2 side B */
    Board_PWM6 = 6, /* PWM output from TIMERA3 side A */
    Board_PWM7 = 7, /* PWM output from TIMERA3 side B */
    Board_PWMCOUNT
} Board_PWMName;

/*!
 *  @def    Board_SDSPIName
 *  @brief  Enum of SDSPI names on the CC3200_LP dev board
 */
typedef enum Board_SDSPIName {
    Board_SDSPICOUNT
} Board_SDSPIName;

/*!
 *  @def    Board_SPIName
 *  @brief  Enum of SPI names on the CC3200_LP dev board
 */
typedef enum Board_SPIName {
    Board_SPI0 = 0, /* MISO: wire ?, MOSI: wire ?, CLK: wire ?, CS: wire ? */
    Board_GSPI = Board_SPI0,

    Board_SPICOUNT
} Board_SPIName;

/*!
 *  @def    Board_UARTName
 *  @brief  Enum of UARTs on the CC3200_LP dev board
 */
typedef enum Board_UARTName {
    Board_UART0 = 0,
    Board_UART1,

    Board_UARTCOUNT
} Board_UARTName;

/*!
 *  @def    Board_WatchdogName
 *  @brief  Enum of Watchdogs on the CC3200_LP dev board
 */
typedef enum Board_WatchdogName {
    Board_WATCHDOGCOUNT
} Board_WatchdogName;

/*!
 *  @brief  I2C address for the LaunchPad's temperature sensor
 */
#define Board_TMP006_ADDR        (0x41)

/*!
 *  @brief  I2C bus address for Tink2's MPU9150 accelerometer
 */
#define Board_MPU9150_ADDR       (0x68)

/*!
 *  @brief  TI-RTOS I2C driver's index for Tink2's MPU9150 accelerometer
 */
#define Board_MPU9150_I2C         Board_I2C0

#ifdef __cplusplus
}
#endif

#endif /* __ti_platforms_tink2_Board_H */
