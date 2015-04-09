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
 *  @file       SPIMSP432DMA.h
 *
 *  @brief      SPI driver implementation for a EUSCI peripheral on MSP432
 *              using the micro DMA controller.
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SPI.h>
 *  #include <ti/drivers/spi/SPIMSP432DMA.h>
 *  @endcode
 *
 *  This SPI driver implementation is designed to operate on a EUCSI controller
 *  in SPI mode.
 *
 *  ## SPI Chip Select #
 *
 *  The SPIMSP432DMA operates the controller in 3-pin mode; therefore it is not
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
 *  The MSP432 DMA controller has 4 interrupt vectors to handle all DMA
 *  related IRQ. Due to the "shared" nature of the DMA interrupts, this driver
 *  implementation requires each SPI instance to explicitly use a single DMA
 *  interrupt.  It is up to the application to ensure no two peripherals are
 *  configured to respond to a given DMA interrupt at any moment.
 *
 *  ## Scratch Buffers #
 *  A uint32_t scratch buffer is used to allow SPI_transfers where txBuf or
 *  rxBuf are NULL. Rather than requiring txBuf or rxBuf to have a dummy buffer
 *  of size of the transfer count, a single DMA accessible uint32_t scratch
 *  buffer is used. When txBuf is NULL, an internal scratch buffer is
 *  initialized to the defaultTxBufValue so the DMA will send some known value.
 *  Each SPI driver instance should uses its own scratch buffer.
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
 *  The DMA contoller only supports data transfers of upto 1024
 *  data frames.  Each SPI driver instance requires 2 DMA channels (Tx and Rx)
 *  to operate.
 *
 *  ## DMA accessible memory #
 *
 *  Ensure that the txBuf and rxBuf (in ::SPI_Transaction) point to memory that
 *  is accessible by the DMA.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_spi_SPIMSP432DMA__include
#define ti_drivers_spi_SPIMSP432DMA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ti/drivers/ports/HwiP.h>
#include <ti/drivers/ports/SemaphoreP.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/SPI.h>

/* SPI function table pointer */
extern const SPI_FxnTable SPIMSP432DMA_fxnTable;

/*!
 *  @brief  SPIMSP432DMA Hardware attributes
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - dma.h
 *      - spi.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const SPIMSP432DMA_HWAttrs spiMSP432DMAHWAttrs[] = {
 *      {
 *          .baseAddr = EUSCI_B0_BASE,
 *          .clockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
 *          .bitOrder = EUSCI_B_SPI_MSB_FIRST,
 *
 *          .defaultTxBufValue = 0,
 *
 *          .dmaIntNum = INT_DMA_INT1,
 *          .intPriority = ~0,
 *          .rxDMAChannelIndex = DMA_CH1_EUSCIB0RX0,
 *          .txDMAChannelIndex = DMA_CH0_EUSCIB0TX0
 *      },
 *      {
 *          .baseAddr = EUSCI_B2_BASE,
 *          .clockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
 *          .bitOrder = EUSCI_B_SPI_MSB_FIRST,
 *
 *          .defaultTxBufValue = 0,
 *
 *          .dmaIntNum = INT_DMA_INT2,
 *          .intPriority = ~0,
 *          .rxDMAChannelIndex = DMA_CH5_EUSCIB2RX0,
 *          .txDMAChannelIndex = DMA_CH4_EUSCIB2TX0
 *      }
 *  };
 *  @endcode
 */
typedef struct SPIMSP432DMA_HWAttrs {
    uint32_t baseAddr;           /*!< EUSCI_B_SPI Peripheral's base address */
    uint16_t bitOrder;           /*!< EUSCI_B_SPI Bit order */
    uint8_t  clockSource;        /*!< EUSCI_B_SPI Clock source */

    uint8_t  defaultTxBufValue;  /*! Default TX value if txBuf == NULL */

    uint8_t  dmaIntNum;          /*!< DMA interrupt number */
    uint32_t intPriority;        /*!< DMA interrupt priority */
    uint32_t rxDMAChannelIndex;  /*!< DMA rxDMAChannel for Rx data */
    uint32_t txDMAChannelIndex;  /*!< DMA txDMAChannel for Tx data */
} SPIMSP432DMA_HWAttrs;

/*!
 *  @brief  SPIMSP432DMA Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SPIMSP432DMA_Object {
    SemaphoreP_Handle transferComplete;    /* Notify finished SPI transfer */
    HwiP_Handle       hwiHandle;

    SPI_CallbackFxn   transferCallbackFxn; /* Callback fxn in CALLBACK mode */
    SPI_Transaction  *transaction;         /* Ptr to the current transaction*/

    SPI_TransferMode  transferMode;        /* SPI transfer mode */
    SPI_Mode          spiMode;             /* Master or Slave mode */
    uint8_t           scratchBuffer;       /* Scratch buffer */

    bool              isOpen;

    uint32_t          bitRate;             /* SPI bit rate in Hz */
    uint16_t          clockPhase;
    uint16_t          clockPolarity;

    Power_NotifyObj   perfChangeNotify;
    uint32_t          perfConstraintMask;

} SPIMSP432DMA_Object, *SPIMSP432DMA_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_spi_SPIMSP432DMA__include */
