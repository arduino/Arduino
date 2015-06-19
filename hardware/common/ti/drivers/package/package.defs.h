/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_drivers__
#define ti_drivers__


/*
 * ======== module ti.drivers.EMAC ========
 */

typedef struct ti_drivers_EMAC_EMAC_Config ti_drivers_EMAC_EMAC_Config;
typedef struct ti_drivers_EMAC_EMACTiva_Object ti_drivers_EMAC_EMACTiva_Object;
typedef struct ti_drivers_EMAC_EMACTiva_HWAttrs ti_drivers_EMAC_EMACTiva_HWAttrs;
typedef struct ti_drivers_EMAC_EMACSnow_HWAttrs ti_drivers_EMAC_EMACSnow_HWAttrs;
typedef struct ti_drivers_EMAC_EMACSnow_Data ti_drivers_EMAC_EMACSnow_Data;
typedef struct ti_drivers_EMAC_EMACSnow_Object ti_drivers_EMAC_EMACSnow_Object;

/*
 * ======== module ti.drivers.GPIO ========
 */

typedef struct ti_drivers_GPIO_GPIO_Config ti_drivers_GPIO_GPIO_Config;

/*
 * ======== module ti.drivers.I2C ========
 */

typedef struct ti_drivers_I2C_I2C_Config ti_drivers_I2C_I2C_Config;
typedef struct ti_drivers_I2C_I2C_Transaction ti_drivers_I2C_I2C_Transaction;
typedef struct ti_drivers_I2C_I2C_Params ti_drivers_I2C_I2C_Params;
typedef struct ti_drivers_I2C_I2CTiva_HWAttrs ti_drivers_I2C_I2CTiva_HWAttrs;
typedef struct ti_drivers_I2C_I2CTiva_Object ti_drivers_I2C_I2CTiva_Object;
typedef struct ti_drivers_I2C_I2CCC3200_HWAttrs ti_drivers_I2C_I2CCC3200_HWAttrs;
typedef struct ti_drivers_I2C_I2CCC3200_Object ti_drivers_I2C_I2CCC3200_Object;
typedef struct ti_drivers_I2C_I2CMSP432_HWAttrs ti_drivers_I2C_I2CMSP432_HWAttrs;
typedef struct ti_drivers_I2C_I2CMSP432_Object ti_drivers_I2C_I2CMSP432_Object;
typedef struct ti_drivers_I2C_I2CUSCIB_HWAttrs ti_drivers_I2C_I2CUSCIB_HWAttrs;
typedef struct ti_drivers_I2C_I2CEUSCIB_HWAttrs ti_drivers_I2C_I2CEUSCIB_HWAttrs;
typedef struct ti_drivers_I2C_I2CUSCIB_Object ti_drivers_I2C_I2CUSCIB_Object;
typedef struct ti_drivers_I2C_I2CEUSCIB_Object ti_drivers_I2C_I2CEUSCIB_Object;

/*
 * ======== module ti.drivers.Power ========
 */


/*
 * ======== module ti.drivers.PWM ========
 */

typedef struct ti_drivers_PWM_PWM_Config ti_drivers_PWM_PWM_Config;
typedef struct ti_drivers_PWM_PWM_Params ti_drivers_PWM_PWM_Params;
typedef struct ti_drivers_PWM_PWMTimerCC3200_HWAttrs ti_drivers_PWM_PWMTimerCC3200_HWAttrs;
typedef struct ti_drivers_PWM_PWMTimerCC3200_Object ti_drivers_PWM_PWMTimerCC3200_Object;
typedef struct ti_drivers_PWM_PWMTiva_Status ti_drivers_PWM_PWMTiva_Status;
typedef struct ti_drivers_PWM_PWMTiva_HWAttrs ti_drivers_PWM_PWMTiva_HWAttrs;
typedef struct ti_drivers_PWM_PWMTiva_Object ti_drivers_PWM_PWMTiva_Object;
typedef struct ti_drivers_PWM_PWMTimerTiva_HWAttrs ti_drivers_PWM_PWMTimerTiva_HWAttrs;
typedef struct ti_drivers_PWM_PWMTimerTiva_Object ti_drivers_PWM_PWMTimerTiva_Object;
typedef struct ti_drivers_PWM_PWMTimerMSP432_Status ti_drivers_PWM_PWMTimerMSP432_Status;
typedef struct ti_drivers_PWM_PWMTimerMSP432_HWAttrs ti_drivers_PWM_PWMTimerMSP432_HWAttrs;
typedef struct ti_drivers_PWM_PWMTimerMSP432_Object ti_drivers_PWM_PWMTimerMSP432_Object;

/*
 * ======== module ti.drivers.SDSPI ========
 */

typedef struct ti_drivers_SDSPI_SDSPI_Config ti_drivers_SDSPI_SDSPI_Config;
typedef struct ti_drivers_SDSPI_SDSPITiva_HWAttrs ti_drivers_SDSPI_SDSPITiva_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPITiva_Object ti_drivers_SDSPI_SDSPITiva_Object;
typedef struct ti_drivers_SDSPI_SDSPIUSCIA_HWAttrs ti_drivers_SDSPI_SDSPIUSCIA_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPIUSCIB_HWAttrs ti_drivers_SDSPI_SDSPIUSCIB_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPIUSCIA_Object ti_drivers_SDSPI_SDSPIUSCIA_Object;
typedef struct ti_drivers_SDSPI_SDSPIUSCIB_Object ti_drivers_SDSPI_SDSPIUSCIB_Object;
typedef struct ti_drivers_SDSPI_SDSPIEUSCIA_HWAttrs ti_drivers_SDSPI_SDSPIEUSCIA_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPIEUSCIB_HWAttrs ti_drivers_SDSPI_SDSPIEUSCIB_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPIEUSCIA_Object ti_drivers_SDSPI_SDSPIEUSCIA_Object;
typedef struct ti_drivers_SDSPI_SDSPIEUSCIB_Object ti_drivers_SDSPI_SDSPIEUSCIB_Object;
typedef struct ti_drivers_SDSPI_SDSPICC3200_HWAttrs ti_drivers_SDSPI_SDSPICC3200_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPICC3200_Object ti_drivers_SDSPI_SDSPICC3200_Object;
typedef struct ti_drivers_SDSPI_SDSPIMSP432_HWAttrs ti_drivers_SDSPI_SDSPIMSP432_HWAttrs;
typedef struct ti_drivers_SDSPI_SDSPIMSP432_Object ti_drivers_SDSPI_SDSPIMSP432_Object;

/*
 * ======== module ti.drivers.SPI ========
 */

typedef struct ti_drivers_SPI_SPI_Config ti_drivers_SPI_SPI_Config;
typedef struct ti_drivers_SPI_SPI_Transaction ti_drivers_SPI_SPI_Transaction;
typedef struct ti_drivers_SPI_SPITivaDMA_HWAttrs ti_drivers_SPI_SPITivaDMA_HWAttrs;
typedef struct ti_drivers_SPI_SPITivaDMA_Object ti_drivers_SPI_SPITivaDMA_Object;
typedef struct ti_drivers_SPI_SPICC3200DMA_HWAttrs ti_drivers_SPI_SPICC3200DMA_HWAttrs;
typedef struct ti_drivers_SPI_SPICC3200DMA_Object ti_drivers_SPI_SPICC3200DMA_Object;
typedef struct ti_drivers_SPI_SPIUSCIADMA_HWAttrs ti_drivers_SPI_SPIUSCIADMA_HWAttrs;
typedef struct ti_drivers_SPI_SPIUSCIADMA_Object ti_drivers_SPI_SPIUSCIADMA_Object;
typedef struct ti_drivers_SPI_SPIUSCIBDMA_HWAttrs ti_drivers_SPI_SPIUSCIBDMA_HWAttrs;
typedef struct ti_drivers_SPI_SPIUSCIBDMA_Object ti_drivers_SPI_SPIUSCIBDMA_Object;
typedef struct ti_drivers_SPI_SPIEUSCIADMA_HWAttrs ti_drivers_SPI_SPIEUSCIADMA_HWAttrs;
typedef struct ti_drivers_SPI_SPIEUSCIADMA_Object ti_drivers_SPI_SPIEUSCIADMA_Object;
typedef struct ti_drivers_SPI_SPIEUSCIBDMA_HWAttrs ti_drivers_SPI_SPIEUSCIBDMA_HWAttrs;
typedef struct ti_drivers_SPI_SPIEUSCIBDMA_Object ti_drivers_SPI_SPIEUSCIBDMA_Object;
typedef struct ti_drivers_SPI_SPIMSP432DMA_HWAttrs ti_drivers_SPI_SPIMSP432DMA_HWAttrs;
typedef struct ti_drivers_SPI_SPIMSP432DMA_Object ti_drivers_SPI_SPIMSP432DMA_Object;

/*
 * ======== module ti.drivers.UART ========
 */

typedef struct ti_drivers_UART_UART_Config ti_drivers_UART_UART_Config;
typedef struct ti_drivers_UART_UARTTiva_HWAttrs ti_drivers_UART_UARTTiva_HWAttrs;
typedef struct ti_drivers_UART_UARTTivaDMA_HWAttrs ti_drivers_UART_UARTTivaDMA_HWAttrs;
typedef struct ti_drivers_UART_UARTTiva_Object ti_drivers_UART_UARTTiva_Object;
typedef struct ti_drivers_UART_UARTCC3200_HWAttrs ti_drivers_UART_UARTCC3200_HWAttrs;
typedef struct ti_drivers_UART_UARTCC3200DMA_HWAttrs ti_drivers_UART_UARTCC3200DMA_HWAttrs;
typedef struct ti_drivers_UART_UARTCC3200_Object ti_drivers_UART_UARTCC3200_Object;
typedef struct ti_drivers_UART_UARTTivaDMA_Object ti_drivers_UART_UARTTivaDMA_Object;
typedef struct ti_drivers_UART_UARTCC3200DMA_Object ti_drivers_UART_UARTCC3200DMA_Object;
typedef struct ti_drivers_UART_UARTUSCIA_HWAttrs ti_drivers_UART_UARTUSCIA_HWAttrs;
typedef struct ti_drivers_UART_UARTUSCIA_Object ti_drivers_UART_UARTUSCIA_Object;
typedef struct ti_drivers_UART_UARTEUSCIA_HWAttrs ti_drivers_UART_UARTEUSCIA_HWAttrs;
typedef struct ti_drivers_UART_UARTEUSCIA_Object ti_drivers_UART_UARTEUSCIA_Object;
typedef struct ti_drivers_UART_UARTMSP432_HWAttrs ti_drivers_UART_UARTMSP432_HWAttrs;
typedef struct ti_drivers_UART_UARTMSP432_Object ti_drivers_UART_UARTMSP432_Object;

/*
 * ======== module ti.drivers.USBMSCHFatFs ========
 */

typedef struct ti_drivers_USBMSCHFatFs_USBMSCHFatFs_Config ti_drivers_USBMSCHFatFs_USBMSCHFatFs_Config;
typedef struct ti_drivers_USBMSCHFatFs_USBMSCHFatFsTiva_HWAttrs ti_drivers_USBMSCHFatFs_USBMSCHFatFsTiva_HWAttrs;
typedef struct ti_drivers_USBMSCHFatFs_USBMSCHFatFsTiva_Object ti_drivers_USBMSCHFatFs_USBMSCHFatFsTiva_Object;

/*
 * ======== module ti.drivers.Watchdog ========
 */

typedef struct ti_drivers_Watchdog_WatchdogTiva_HWAttrs ti_drivers_Watchdog_WatchdogTiva_HWAttrs;
typedef struct ti_drivers_Watchdog_WatchdogTiva_Object ti_drivers_Watchdog_WatchdogTiva_Object;
typedef struct ti_drivers_Watchdog_WatchdogCC3200_HWAttrs ti_drivers_Watchdog_WatchdogCC3200_HWAttrs;
typedef struct ti_drivers_Watchdog_WatchdogCC3200_Object ti_drivers_Watchdog_WatchdogCC3200_Object;
typedef struct ti_drivers_Watchdog_WatchdogMSP430_HWAttrs ti_drivers_Watchdog_WatchdogMSP430_HWAttrs;
typedef struct ti_drivers_Watchdog_WatchdogMSP430_Object ti_drivers_Watchdog_WatchdogMSP430_Object;
typedef struct ti_drivers_Watchdog_WatchdogMSP432_HWAttrs ti_drivers_Watchdog_WatchdogMSP432_HWAttrs;
typedef struct ti_drivers_Watchdog_WatchdogMSP432_Object ti_drivers_Watchdog_WatchdogMSP432_Object;
typedef struct ti_drivers_Watchdog_Watchdog_Config ti_drivers_Watchdog_Watchdog_Config;

/*
 * ======== module ti.drivers.WiFi ========
 */

typedef struct ti_drivers_WiFi_WiFi_Config ti_drivers_WiFi_WiFi_Config;
typedef struct ti_drivers_WiFi_WiFiCC3100_HWAttrs ti_drivers_WiFi_WiFiCC3100_HWAttrs;
typedef struct ti_drivers_WiFi_WiFiCC3100_Object ti_drivers_WiFi_WiFiCC3100_Object;


#endif /* ti_drivers__ */ 
