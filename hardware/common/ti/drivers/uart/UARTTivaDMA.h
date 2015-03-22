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
 *  @file       UARTTivaDMA.h
 *
 *  @brief      UART driver implementation for a Tiva UART controller thay
 *              uses DMA.
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTTivaDMA.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTTivaDMA__include
#define ti_drivers_uart_UARTTivaDMA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/UART.h>

#include <ti/drivers/ports/ListP.h>
#include <ti/sysbios/knl/Semaphore.h>
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>

/* UART function table pointer */
extern const UART_FxnTable UARTTivaDMA_fxnTable;

/*!
 *  @brief      UARTTivaDMA Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For TivaWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTTivaDMA_HWAttrs uartTivaHWAttrs[] = {
 *      {
 *          UART1_BASE,
 *          INT_UART1,
 *          ~0,        // Interrupt priority
 *          UDMA_CH22_UART1RX,
 *          UDMA_CH23_UART1TX,
 *      },
 *      {
 *          UART3_BASE,
 *          INT_UART3
 *          ~0,        // Interrupt priority
 *          UDMA_CH16_UART3RX,
 *          UDMA_CH17_UART3TX,
 *      },
 *  };
 *  @endcode
 */
typedef struct UARTTivaDMA_HWAttrs {
    /*! UART Peripheral's base address */
    unsigned int baseAddr;
    /*! UART Peripheral's interrupt vector */
    unsigned int intNum;
    /*! UART Peripheral's interrupt priority */
    unsigned int intPriority;
    /*! uDMA controlTable receive channel index plus peripheral map */
    uint32_t rxChannelIndex;
    /*! uDMA controlTable transmit channel index plus peripheral map */
    uint32_t txChannelIndex;
} UARTTivaDMA_HWAttrs;

/*!
 *  @brief      UARTTivaDMA Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UARTTivaDMA_Object {
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
    UART_Echo            readEcho;         /* Echo received data back */

    /* UART write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeCount;       /* Number of Chars sent */
    size_t               writeSize;        /* Chars remaining in buffer */

    /* UART receive variables */
    void                *readBuf;          /* Buffer data pointer */
    size_t               readCount;        /* Number of Chars read */
    size_t               readSize;         /* Chars remaining in buffer */

    /* UART SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /* Hwi object */
    Semaphore_Struct     writeSem;         /* UART write semaphore*/
    Semaphore_Struct     readSem;          /* UART read semaphore */
} UARTTivaDMA_Object, *UARTTivaDMA_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTTivaDMA__include */
