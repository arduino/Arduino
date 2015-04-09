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
 *  @file       SPIEUSCIBDMA.h
 *
 *  @brief      SPI driver implementation for a USCIB peripheral using
 *              the micro DMA controller.
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SPI.h>
 *  #include <ti/drivers/spi/SPIEUSCIBDMA.h>
 *  @endcode
 *
 *  This SPI driver implementation is designed to operate on a UCSI controller
 *  in SPI mode. It uses the APIs for a USCIB controller.
 *
 *  ## SPI Chip Select #
 *
 *  The SPIEUSCIBDMA operates the controller in 3-pin mode; therefore it is not
 *  safe to use in a multi-master SPI bus environment. It is the application's
 *  responsibility to assert and de-assert a GPIO pin for chip select purposes.
 *
 *  <table>
 *  <tr>
 *  <th>Chip select type</th>
 *  <th>SPI_MASTER mode</th>
 *  <th>SPI_SLAVE mode</th>
 *  </tr>
 *  <tr>
 *  <td>Hardware chip select</td>
 *  <td>Not available on this peripheral.</td>
 *  </tr>
 *  <tr>
 *  <td>Software chip select</td>
 *  <td>The application is responsible to ensure that correct SPI slave is
 *      selected before performing a SPI_transfer().</td>
 *  <td>Up to the application's implementation.</td>
 *  </tr>
 *  </table>
 *
 *  ## DMA Interrupts #
 *  The MSP430 DMA controller uses a single interrupt vector to handle all DMA
 *  related IRQ. Because of the "shared" nature, of the DMA's ISR, this driver
 *  implementation provides a simple ISR function SPIEUSCIBDMA_hwiIntFxn() which
 *  needs to be called from within the DMA's ISR.
 *  SPIEUSCIBDMA_hwiIntFxn() will only service DMA channel interrupts that are
 *  associated with the SPI_Handle. Each SPIEUSCIBDMA instance will require a
 *  call from within the DMA's ISR.
 *
 *  @code
 *  SPI_Handle spi0uscidma;
 *  SPI_Handle spi1uscidma;
 *
 *  // As this DMA controller uses a single interrupt vector for all DMA
 *  // channels (regardless of the triggering source), its left up to the user
 *  // to call SPI_serviceISR() to service its associated DMA channels.
 *  Void myDMAISR(UArg arg)
 *  {
 *      // Services and clears its assigned DMA channel interrupts
 *      SPI_serviceISR(spi0uscidma);
 *
 *      // Services and clears its assigned DMA channel interrupts
 *      SPI_serviceISR(spi1uscidma);
 *
 *      // some other user application code that's not related to the SPI driver,
 *      // but is used to service remaining DMA channels
 *  }
 *
 *  spi0uscidma = SPI_open(someSPI_configIndexValue, &params);
 *  ...
 *
 *  spi1uscidma = SPI_open(someSPI_configIndexValue, &params);
 *  ....
 *  @endcode
 *
 *  ## SPI data frames #
 *
 *  The EUSCI controller only supports 8-bit data frames.
 *
 *  dataSize  | buffer element size |
 *  --------  | ------------------- |
 *  8 bits    | uint8_t             |
 *
 *  ## DMA transfer size limit #
 *
 *  The MSP430 DMA controller supports 2^16 data frames per transfer. Each
 *  SPI driver instance requires 2 DMA channels (Tx and Rx) to operate.
 *
 *  ## DMA accessible memory #
 *
 *  Ensure that the txBuf and rxBuf (in ::SPI_Transaction) point to memory that
 *  is accessible by the DMA.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_spi_SPIEUSCIBDMA__include
#define ti_drivers_spi_SPIEUSCIBDMA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/SPI.h>

#include <ti/sysbios/knl/Semaphore.h>

/* SPI function table pointer */
extern const SPI_FxnTable SPIEUSCIBDMA_fxnTable;

/*!
 *  @brief  SPIEUSCIBDMA Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - inc/hw_memmap.h
 *      - usci_b_spi.h
 *      - dma.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const SPIEUSCIBDMA_HWAttrs spiEUSCIBDMAHWAttrs[] = {
 *      {
 *          EUSCI_B1_BASE,
 *          EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
 *          EUSCI_B_SPI_MSB_FIRST,
 *
 *          // DMA base address
 *          DMA_BASE,
 *          // Rx Channel
 *          DMA_CHANNEL_1,
 *          DMA_TRIGGERSOURCE_22,
 *          // Tx Channel
 *          DMA_CHANNEL_0,
 *          DMA_TRIGGERSOURCE_23
 *      },
 *      {
 *          EUSCI_B1_BASE,
 *          EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
 *          EUSCI_B_SPI_MSB_FIRST,
 *
 *          // DMA base address
 *          DMA_BASE,
 *          // Rx Channel
 *          DMA_CHANNEL_1,
 *          DMA_TRIGGERSOURCE_18,
 *          // Tx Channel
 *          DMA_CHANNEL_0,
 *          DMA_TRIGGERSOURCE_19
 *      },
 *  };
 *  @endcode
 */
typedef struct SPIEUSCIBDMA_HWAttrs {
    /*!< EUSCI_B_SPI Peripheral's base address */
    uint32_t baseAddr;
    /*!< EUSCI_B_SPI Clock source */
    uint8_t  clockSource;
    /*!< EUSCI_B_SPI Bit order */
    uint16_t bitOrder;
    /*! Address of a scratch buffer of size uint32_t */
    uint8_t *scratchBufPtr;
    /*! Default TX value if txBuf == NULL */
    uint8_t  defaultTxBufValue;

    /*!< DMA Peripheral's base address */
    uint32_t  dmaBaseAddr;
    /*!< DMA rxDMAChannel for Rx data */
    uint8_t   rxDMAChannelIndex;
    /*!< DMA trigger source for Rx data */
    uint8_t   rxDMASourceTrigger;
    /*!< DMA txDMAChannel for Tx data */
    uint8_t   txDMAChannelIndex;
    /*!< DMA trigger source for Tx data */
    uint8_t   txDMASourceTrigger;
} SPIEUSCIBDMA_HWAttrs;

/*!
 *  @brief  SPIEUSCIBDMA Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SPIEUSCIBDMA_Object {
    bool                isOpen;             /* Variable to determine if the SPI is open */

    Semaphore_Struct    transferComplete;   /* Notify finished SPI transfer */

    SPI_TransferMode    transferMode;       /* SPI transfer mode */
    SPI_CallbackFxn     transferCallbackFxn;/* Callback fxn in CALLBACK mode */

    SPI_Transaction    *transaction;        /* Ptr to the current transaction*/

} SPIEUSCIBDMA_Object, *SPIEUSCIBDMA_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_spi_SPIEUSCIBDMA__include */
