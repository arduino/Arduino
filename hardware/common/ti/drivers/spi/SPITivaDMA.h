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
 *  @file       SPITivaDMA.h
 *
 *  @brief      SPI driver implementation for a TivaSPIcontroller using
 *              the micro DMA controller.
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SPI.h>
 *  #include <ti/drivers/spi/SPITivaDMA.h>
 *  @endcode
 *
 *  This SPI driver implementation is designed to operate on a Tiva SPI
 *  controller using a micro DMA controller.
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
 *  ## DMA Interrupts #
 *  This driver is designed to operation on a micro DMA. The micro DMA generates
 *  IRQ on the perpheral's interrupt vector. This implementation automatically
 *  installs a DMA aware Hwi (interrupt) to service the assigned micro DMA
 *  channels.
 *
 *  ## Scratch Buffers #
 *  A uint32_t scratch buffer is used to allow SPI_transfers where txBuf or rxBuf
 *  are NULL. Rather than requiring txBuf or rxBuf to have a dummy buffer of size
 *  of the transfer count, a single DMA accessible uint32_t scratch buffer is used.
 *  When rxBuf is NULL, the uDMA will transfer all the SPI data receives into the
 *  scratch buffer as a "bit-bucket".
 *  When rxBuf is NULL, the scratch buffer is initialized to defaultTxBufValue
 *  so the uDMA will send some known value.
 *  Each SPI driver instance should uses its own scratch buffer.
 *
 *  ## SPI data frames #
 *
 *  SPI data frames can be any size from 4-bits to 16-bits. If the dataSize in
 *  ::SPI_Params is greater that 8-bits, then the SPITivaDMA driver
 *  implementation will assume that the ::SPI_Transaction txBuf and rxBuf
 *  point to an array of 16-bit uint16_t elements.
 *
 *  dataSize  | buffer element size |
 *  --------  | ------------------- |
 *  4-8 bits  | uint8_t             |
 *  9-16 bits | uint16_t            |
 *
 *  ## DMA transfer size limit #
 *
 *  The Tiva micro DMA contoller only supports data transfers of upto 1024
 *  data frames. A data frame can be 4 to 16 bits in length.
 *
 *  ## DMA accessible memory #
 *
 *  As this driver uses uDMA to transfer data/from data buffers, it is the
 *  responsibility of the application to ensure that theses buffers reside in
 *  memory that is accessible by the DMA.
 *
 *  For example, on Concerto devices local SRAM C0 and C1 are NOT accessible the
 *  DMA.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_spi_SPITivaDMA__include
#define ti_drivers_spi_SPITivaDMA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/SPI.h>

#include <ti/sysbios/knl/Semaphore.h>
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>

#if defined(TIVAWARE)
/* c99 types required by TivaWare */
#include <stdint.h>
typedef uint32_t            SPIBaseAddrType;
typedef uint32_t            SPIDataType;
#else /* MWARE */
typedef unsigned long       SPIBaseAddrType;
typedef unsigned long       SPIDataType;
#endif

/* SPI function table pointer */
extern const SPI_FxnTable SPITivaDMA_fxnTable;

/*!
 *  @brief
 *  SPITivaDMA data frame size is used to determine how to configure the
 *  DMA data transfers. This field is to be only used internally.
 *
 *  SPITivaDMA_8bit:  txBuf and rxBuf are arrays of uint8_t elements
 *  SPITivaDMA_16bit: txBuf and rxBuf are arrays of uint16_t elements
 */
typedef enum SPITivaDMA_FrameSize {
    SPITivaDMA_8bit  = 0,
    SPITivaDMA_16bit = 1
} SPITivaDMA_FrameSize;

/*!
 *  @brief  SPITivaDMA Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For TivaWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *      - driverlib/udma.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const SPITivaDMA_HWAttrs spiTivaDMAobjects[] = {
 *      {   // Used by TivaWare (Tiva devices!!!)
 *          SSI0_BASE,
 *          INT_SSI0,
 *          ~0,         // Interrupt priority
 *          &scratchBuffer[0],
 *          0,
 *          UDMA_CHANNEL_SSI0RX,
 *          UDMA_CHANNEL_SSI0TX,
 *          uDMAChannelAssign,
 *          UDMA_CH10_SSI0RX,
 *          UDMA_CH11_SSI0TX
 *      },
 *      {   // Used by MWare (Concerto devices!!!)
 *          SSI1_BASE,
 *          INT_SSI1,
 *          ~0,         // Interrupt priority
 *          &scratchBuffer[1],
 *          0,
 *          UDMA_CHANNEL_SSI1RX,
 *          UDMA_CHANNEL_SSI1TX,
 *          uDMAChannel24_31SelectDefault,
 *          UDMA_CHAN24_DEF_SSI1RX_M,
 *          UDMA_CHAN25_DEF_SSI1TX_M
 *      },
 *  };
 *  @endcode
 */
typedef struct SPITivaDMA_HWAttrs {
    /*! SSI Peripheral's base address */
    SPIBaseAddrType   baseAddr;
    /*! SSI TivaDMA Peripheral's interrupt vector */
    unsigned int      intNum;

    /*! SPITivaDMA Peripheral's interrupt priority */
    uint32_t   intPriority;

    /*! Address of a scratch buffer of size uint32_t */
    uint32_t         *scratchBufPtr;
    /*! Default TX value if txBuf == NULL */
    uint32_t          defaultTxBufValue;
    /*! uDMA controlTable channel index */
    uint32_t          rxChannelIndex;
    /*! uDMA controlTable channel index */
    uint32_t          txChannelIndex;

    /*! uDMA mapping function that maps the SPI trigger to the DMA channel */
    void  (*channelMappingFxn)(SPIDataType);
    /*! uDMA MappingFxn arg to map the Tx channel */
    uint32_t          rxChannelMappingFxnArg;
    /*! uDMA MappingFxn arg to map the Rx channel */
    uint32_t          txChannelMappingFxnArg;
} SPITivaDMA_HWAttrs;

/*!
 *  @brief  SPITivaDMA Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SPITivaDMA_Object {
    Semaphore_Struct      transferComplete;    /* Notify finished SPITivaDMA transfer */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;   /* Hwi object handle */

    SPI_TransferMode      transferMode;        /* SPITivaDMA transfer mode */
    SPI_CallbackFxn       transferCallbackFxn; /* Callback fxn in CALLBACK mode */
    uint32_t              transferTimeout;     /* Transfer timeout in system ticks */

    SPI_Transaction      *transaction;         /* void * to the current transaction*/

    SPITivaDMA_FrameSize  frameSize;           /* Data frame size variable */

    bool                  isOpen;              /* flag to indicate module is open */
} SPITivaDMA_Object, *SPITivaDMA_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_spi_SPITivaDMA__include */
