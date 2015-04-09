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
 *  @file       SDSPICC3200.h
 *
 *  @brief      SDSPI driver implementation for a CC3200 SPI peripheral used
 *              with the SDSPI driver.
 *
 *  The SDSPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SDSPI.h>
 *  #include <ti/drivers/sdspi/SDSPICC3200.h>
 *  @endcode
 *
 *  This SDSPI driver implementation is designed to operate on a CC3200 SPI
 *  controller using a polling method.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_sdspi_SDSPICC3200__include
#define ti_drivers_sdspi_SDSPICC3200__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/SDSPI.h>

#include <ti/sysbios/fatfs/ff.h>
#include <ti/sysbios/fatfs/diskio.h>

typedef unsigned long SDSPIBaseAddrType;
typedef unsigned long SDSPIDataType;

/* SDSPI function table */
extern const SDSPI_FxnTable SDSPICC3200_fxnTable;

/*!
 *  @brief  SD Card type inserted
 */
typedef enum SDSPICC3200_CardType {
    NOCARD = 0, /*!< Unrecognized Card */
    MMC = 1,    /*!< Multi-media Memory Card (MMC) */
    SDSC = 2,   /*!< Standard SDCard (SDSC) */
    SDHC = 3    /*!< High Capacity SDCard (SDHC) */
} SDSPICC3200_CardType;

/*!
 *  @brief  SDSPICC3200 Hardware attributes
 *
 *  The SDSPICC3200 configuration structure describes to the SDSPICC3200
 *  driver implementation hardware specifies on which SPI peripheral, GPIO Pins
 *  and Ports are to be used.
 *
 *  The SDSPICC3200 driver uses this information to:
 *  - configure and reconfigure specific ports/pins to initialize the SD Card
 *    for SPI mode
 *  - identify which SPI peripheral is used for data communications
 *  - identify which GPIO port and pin is used for the SPI chip select
 *    mechanism
 *  - identify which GPIO port and pin is concurrently located on the SPI's MOSI
 *    (TX) pin.
 *
 *  @remark
 *  To initialize the SD Card into SPI mode, the SDSPI driver changes the SPI's
 *  MOSI pin into a GPIO pin so it can kept driven HIGH while the SPI SCK pin
 *  can toggle. After the initialization, the TX pin is reverted back to the SPI
 *  MOSI mode.
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For CCWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *      - driverlib/gpio.h
 *      - driverlib/pin.h
 *      - driverlib/prcm.h
 *
 *  @struct SDSPICC3200_HWAttrs
 *  An example configuration structure could look as the following:
 *  @code
 *  const SDSPICC3200_HWAttrs sdspiCC3200HWattrs = {
 *      {
 *            GSPI_BASE,      // SSI Peripheral's base address
 *            PRCM_GSPI,      // SPI PRCM peripheral number
 *
 *            GPIOA0_BASE,    // CS GPIO base
 *            GPIO_PIN_7,     // CS GPIO pin number
 *
 *            GPIOA2_BASE,    // GPIO base addr when using MOSI as GPIO
 *            GPIO_PIN_0,     // GPIO pin number when using MOSI as GPIO
 *            PIN_MODE_0,     // GPIO pin mode to use MOSI as GPIO
 *            PIN_MODE_7,     // Pin mode to use MOSI
 *            PIN_07,         // Package pin number
 *      }
 *  };
 *  @endcode
 */
typedef struct SDSPICC3200_HWAttrs {
    /*!< SPI Peripheral base address */
    uint32_t baseAddr;

    /*! SPI PRCM peripheral number */
    uint32_t spiPRCM;

    /*!< CS GPIO base */
    uint32_t csGPIOBase;
    /*!< CS GPIO pin number */
    uint32_t csGPIOPin;

    /*!< GPIO base addr when using MOSI as GPIO */
    uint32_t txGPIOBase;
    /*!< GPIO pin number when using MOSI as GPIO */
    uint32_t txGPIOPin;
    /*!< GPIO pin mode to use MOSI as GPIO */
    uint32_t txGPIOMode;
    /*!< Pin mode to use MOSI */
    uint32_t txSPIMode;
    /*!< Package pin number */
    uint32_t txPackPin;
} SDSPICC3200_HWAttrs;

/*!
 *  @brief  SDSPICC3200 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SDSPICC3200_Object {
    uint32_t              driveNumber;   /*!< Drive number used by FatFs */
    DSTATUS               diskState;     /*!< Disk status */
    SDSPICC3200_CardType  cardType;      /*!< SDCard Card Command Class (CCC) */
    uint32_t              bitRate;       /*!< SPI bus bit rate (Hz) */
    FATFS                 filesystem;    /*!< FATFS data object */
} SDSPICC3200_Object, *SDSPICC3200_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_sdspi_SDSPICC3200__include */
