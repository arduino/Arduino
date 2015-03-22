/*
 * Copyright (c) 2014-2015, Texas Instruments Incorporated
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
 *  @file       UARTCC3200DMA.h
 *
 *  @brief      UART driver implementation for a CC3200 UART controller, using
 *              the micro DMA controller.
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTCC3200DMA.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTCC3200DMA__include
#define ti_drivers_uart_UARTCC3200DMA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include <ti/drivers/ports/ClockP.h>
#include <ti/drivers/ports/HwiP.h>
#include <ti/drivers/ports/ListP.h>
#include <ti/drivers/ports/SemaphoreP.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/UART.h>

/* UART function table pointer */
extern const UART_FxnTable UARTCC3200DMA_fxnTable;

/*!
 *  @brief      UARTCC3200DMA Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For CC3200Ware these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTCC3200DMA_HWAttrs uartCC3200HWAttrs[] = {
 *      {
 *          UARTA0_BASE,
 *          INT_UARTA0,
 *          ~0,          // Interrupt priority
 *          UDMA_CH8_UARTA0_RX,
 *          UDMA_CH9_UARTA0_TX
 *      },
 *      {
 *          UARTA1_BASE,
 *          INT_UARTA1,
 *          ~0,          // Interrupt priority
 *          UDMA_CH10_UARTA1_RX,
 *          UDMA_CH11_UARTA1_TX
 *      },
 *  };
 *  @endcode
 */
typedef struct UARTCC3200DMA_HWAttrs {
    /*! UART Peripheral's base address */
    unsigned int baseAddr;
    /*! UART Peripheral's interrupt vector */
    unsigned int intNum;
    /*! UART Peripheral's interrupt priority */
    unsigned int intPriority;
    /*! uDMA controlTable receive channel index */
    unsigned long rxChannelIndex;
    /*! uDMA controlTable transmit channel index */
    unsigned long txChannelIndex;
} UARTCC3200DMA_HWAttrs;

/*!
 *  @brief      UARTCC3200DMA Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UARTCC3200DMA_Object {
    /* UART control variables */
    bool                 opened;           /* Has the obj been opened */
    UART_Mode            readMode;         /* Mode for all read calls */
    UART_Mode            writeMode;        /* Mode for all write calls */
    unsigned int         readTimeout;      /* Timeout for read semaphore */
    unsigned int         writeTimeout;     /* Timeout for write semaphore */
    UART_Callback        readCallback;     /* Pointer to read callback */
    UART_Callback        writeCallback;    /* Pointer to write callback */
    UART_ReturnMode      readReturnMode;   /* Receive return mode */
    UART_DataMode        readDataMode;     /* Type of data being read */
    UART_DataMode        writeDataMode;    /* Type of data being written */
    uint32_t             baudRate;         /*!< Baud rate for UART */
    UART_LEN             dataLength;       /*!< Data length for UART */
    UART_STOP            stopBits;         /*!< Stop bits for UART */
    UART_PAR             parityType;       /*!< Parity bit type for UART */
    UART_Echo            readEcho;         /* Echo received data back */

    /* UART write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeCount;       /* Number of Chars sent */
    size_t               writeSize;        /* Chars remaining in buffer */

    /* UART receive variables */
    void                *readBuf;          /* Buffer data pointer */
    size_t               readCount;        /* Number of Chars read */
    size_t               readSize;         /* Chars remaining in buffer */

    /* Semaphores for blocking mode */
    SemaphoreP_Handle    writeSem;         /* UART write semaphore */
    SemaphoreP_Handle    readSem;          /* UART read semaphore */

    HwiP_Handle    hwiHandle;

    /* For Power management */
    ClockP_Handle        txFifoEmptyClk;   /*!< UART TX FIFO empty clock */
    Power_NotifyObj      postNotify;       /*!< LPDS wake-up notify object */
} UARTCC3200DMA_Object, *UARTCC3200DMA_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTCC3200DMA__include */
