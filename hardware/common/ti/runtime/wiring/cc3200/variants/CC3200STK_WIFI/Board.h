/** ===========================================================================
 *  @file       Board.h
 *
 *  @brief      CC3200 LP Board Specific APIs
 *
 *  This header file "extends" the declarations provided by
 *  ti/drivers/bsp/Board.h with declarations that are specific to the
 *  CC3200 Launch Pad hardware platform.
 *
 *  ===========================================================================
 */
#ifndef __ti_platforms_emt3200lp_Board_H
#define __ti_platforms_emt3200lp_Board_H

#include <ti/drivers/bsp/Board.h>
#include <ti/drivers/GPIO.h>

#ifdef __cplusplus
extern "C" {
#endif

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

    Board_UARTCOUNT
} Board_UARTName;

/*!
 *  @def    Board_WatchdogName
 *  @brief  Enum of Watchdogs on the CC3200_LP dev board
 */
typedef enum Board_WatchdogName {
    Board_WATCHDOGCOUNT
} Board_WatchdogName;

#ifdef __cplusplus
}
#endif

#endif /* __ti_platforms_emt3200lp_Board_H */
