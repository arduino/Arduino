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
 *  @file       SPICC26XX.h
 *
 *  @brief      SPI driver implementation for a CC26XXSPIcontroller
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SPI.h>
 *  #include <ti/drivers/spi/SPICC26XX.h>
 *  @endcode
 *
 *  This SPI driver implementation is designed to operate on a CC26XX SPI
 *  controller
 *
 *  ## SPI Chip Select #
 *  This SPI controller supports a hardware chip select pin. Refer to the
 *  device's user manual on how this hardware chip select pin behaves in regards
 *  to the SPI frame format.
 *
 *  <table>
 *  <tr>
 *  <th>Chip select type</th>
 *  <th>SPI_MASTER mode</th>
 *  <th>SPI_SLAVE mode</th>
 *  </tr>
 *  <tr>
 *  <td>Hardware chip select</td>
 *  <td>No action is needed by the application to select the peripheral.</td>
 *  <td>See the device documentation on it's chip select requirements.</td>
 *  </tr>
 *  <tr>
 *  <td>Software chip select</td>
 *  <td>The application is responsible to ensure that correct SPI slave is
 *      selected before performing a SPI_transfer().</td>
 *  <td>See the device documentation on it's chip select requirements.</td>
 *  </tr>
 *  </table>
 *
 *  ## SPI data frames #
 *
 *  SPI data frames can be any size from 4-bits to 16-bits. If the dataSize in
 *  ::SPI_Params is greater that 8-bits, then the SPICC26XX driver
 *  implementation will assume that the ::SPI_Transaction txBuf and rxBuf
 *  point to an array of 16-bit uint16_t elements.
 *
 *  dataSize  | buffer element size |
 *  --------  | ------------------- |
 *  4-8 bits  | uint8_t             |
 *  9-16 bits | uint16_t            |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_spi_SPICC26XX__include
#define ti_drivers_spi_SPICC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/SPI.h>
#include <ti/sysbios/family/arm/cc26xx/Power.h>

#include <ti/sysbios/knl/Semaphore.h>
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>

/* Return codes for SPI_control() */
#define SPICC26XX_CMD_UNDEFINED    -1

typedef unsigned long               SPIDataType;

/* SPI buffer size */
#define SPI_BUFFER_SIZE     8

/* SPI function table pointer */
extern const SPI_FxnTable SPICC26XX_fxnTable;

/*!
 *  @brief      SPICC26XX Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For CC26XXWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const SPICC26XX_HWAttrs uartCC26XXHWAttrs[] = {
 *      {
 *          SPI0_BASE,
 *          INT_SPI0
 *          PERIPH_SPI0
 *      },
 *      {
 *          SPI1_BASE,
 *          INT_SPI1
 *          PERIPH_SPI1
 *      },
 *  };
 *  @endcode
 */
typedef struct SPICC26XX_HWAttrs {
    /*! SPI Peripheral's base address */
    unsigned long   baseAddr;
    /*! SPI Peripheral's interrupt vector */
    int             intNum;
    /*! SPI Peripheral's power manager ID */
    unsigned long   powerMngrId;
} SPICC26XX_HWAttrs;

/*!
 *  @brief      SPICC26XX Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SPICC26XX_Object {
    /* SPI control variables */
    SPI_TransferMode    transferMode;        /*!< Blocking or Callback mode */
    SPI_CallbackFxn     transferCallbackFxn; /*!< Callback function pointer */
    SPI_Mode            mode;                /*!< Master or Slave mode */
    unsigned int        bitRate;             /*!< SPI bit rate in Hz */
    unsigned int        dataSize;            /*!< SPI data frame size in bits */
    SPI_FrameFormat     frameFormat;         /*!< SPI frame format */

    /* SPI SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /*!< Hwi object handle */
    Semaphore_Struct     transferComplete;   /*!< Notify finished SPICC26XX transfer */

    /* SPI current transaction */
    SPI_Transaction     *currentTransaction; /*!< Ptr to the current transaction */
    unsigned int        txBufCount;          /*!< Internal dec. writeCounter */
    unsigned int        rxBufCount;          /*!< Internal dec. readCounter */
    void                *rxBuf;              /*!< RX buffer pointer */
    void                *txBuf;              /*!< TX buffer pointer */

    /* SPI pin mapping */
    unsigned int        spiMiso;             /*!< SPI MISO pin */
    unsigned int        spiMosi;             /*!< SPI MOSI pin */
    unsigned int        spiClk;              /*!< SPI CLK pin  */
    unsigned int        spiCsn;              /*!< SPI CS_N pin */

    /* SPI pre- and post notification functions */
    void                *spiPreFxn;          /*!< SPI pre-notification function pointer */
    void                *spiPostFxn;         /*!< SPI post-notification function pointer */
    Power_NotifyObj     spiPreObj;           /*!< SPI pre-notification object */
    Power_NotifyObj     spiPostObj;          /*!< SPI post-notification object */

    bool         isOpen;              /*!< Has the object been opened */
} SPICC26XX_Object, *SPICC26XX_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_spi_SPICC26XX__include */
