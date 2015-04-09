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
 *  @file       SDSPIMSP432.h
 *
 *  @brief      SDSPI driver implementation using an EUSCI SPI peripheral for
 *              MSP432.
 *
 *  The SDSPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SDSPI.h>
 *  #include <ti/drivers/sdspi/SDSPIMSP432.h>
 *  @endcode
 *
 *  This SDSPI driver implementation is designed to operate on a EUSCI SPI
 *  controller in a simple polling method.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_sdspi_SDSPIMSP432__include
#define ti_drivers_sdspi_SDSPIMSP432__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ti/sysbios/fatfs/ff.h>
#include <ti/sysbios/fatfs/diskio.h>

#include <ti/drivers/SDSPI.h>

/* SDSPI function table */
extern const SDSPI_FxnTable SDSPIMSP432_fxnTable;

/*!
 *  @brief  SD Card type inserted
 */
typedef enum SDSPIMSP432_CardType {
    NOCARD = 0, /*!< Unrecognized Card */
    MMC = 1,    /*!< Multi-media Memory Card (MMC) */
    SDSC = 2,   /*!< Standard SDCard (SDSC) */
    SDHC = 3    /*!< High Capacity SDCard (SDHC) */
} SDSPIMSP432_CardType;

/*!
 *  @brief  SDSPIMSP432 Hardware attributes
 *
 *  The SDSPIMSP432 HWAttrs configuration structure contains SPI peripheral and
 *  GPIO Pin details required by the SDSPIMSP432 driver implementation.
 *
 *  The SDSPIMSP432 driver uses this information to:
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
 *  driverlib macro definitions. For TivaWare these definitions are found in:
 *      - spi.h
 *
 *  @struct SDSPIMSP432_HWAttrs
 *  An example configuration structure could look as the following:
 *  @code
 *  const SDSPIMSP432_HWAttrs sdspiMSP432HWAttrs[MSP_EXP432P401RLP_SDSPICOUNT] = {
 *      {
 *          .baseAddr = EUSCI_B0_BASE,
 *          .clockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
 *
 *          // CLK, MOSI & MISO ports & pins
 *          .portSCK = GPIO_PORT_P1,
 *          .pinSCK = GPIO_PIN5,
 *          .portMISO = GPIO_PORT_P1,
 *          .pinMISO = GPIO_PIN7,
 *          .portMOSI = GPIO_PORT_P1,
 *          .pinMOSI = GPIO_PIN6,
 *
 *          // Chip select port & pin
 *          .portCS = GPIO_PORT_P4,
 *          .pinCS = GPIO_PIN6
 *      }
 *  };
 *  @endcode
 */
typedef struct SDSPIMSP432_HWAttrs {
    uint32_t   baseAddr;     /*!< SPI Peripheral's base address */
    uint8_t    clockSource;  /*!< SPIUSCI Clock source */

    uint8_t    portSCK;      /*!< SPI port for the SCK pin */
    uint16_t   pinSCK;       /*!< SPI SCK pin */
    uint8_t    sckMode;      /*!< GPIO mode to enable SCK pin */

    uint8_t    portMISO;     /*!< SPI port for the MISO pin */
    uint16_t   pinMISO;      /*!< SPI MISO pin */
    uint8_t    misoMode;     /*!< GPIO mode to enable MISO pin */

    uint8_t    portMOSI;     /*!< SPI port for the MOSI pin */
    uint16_t   pinMOSI;      /*!< SPI MOSI pin */
    uint8_t    mosiMode;     /*!< GPIO mode to enable MOSI pin */

    uint8_t    portCS;       /*!< GPIO Port used for the chip select */
    uint16_t   pinCS;        /*!< GPIO Pin used for the chip select */
} SDSPIMSP432_HWAttrs;

/*!
 *  @brief  SDSPIMSP432 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SDSPIMSP432_Object {
    uint16_t             driveNumber;   /*!< Drive number used by FatFs */
    DSTATUS              diskState;     /*!< Disk status */
    SDSPIMSP432_CardType cardType;      /*!< SDCard Card Command Class (CCC) */
    uint32_t             bitRate;       /*!< SPI bus bit rate (Hz) */
    FATFS                filesystem;    /*!< FATFS data object */

    Power_NotifyObj      perfChangeNotify;
    uint32_t             perfConstraintMask;
} SDSPIMSP432_Object, *SDSPIMSP432_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_sdspi_SDSPIMSP432__include */
