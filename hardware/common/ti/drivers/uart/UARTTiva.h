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
 *  @file       UARTTiva.h
 *
 *  @brief      UART driver implementation for a Tiva UART controller
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTTiva.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTTiva__include
#define ti_drivers_uart_UARTTiva__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/RingBuf.h>

#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>

/* Return codes for SPI_control() */
#define UARTTiva_CMD_UNDEFINED      -UART_RESERVATION_BASE - 1

/* UART function table pointer */
extern const UART_FxnTable UARTTiva_fxnTable;

/*!
 *  @brief      UARTTiva Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For TivaWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *      - driverlib/uart.h
 *
 *  A sample structure is shown below:
 *  @code
 *  UARTTiva_Object uartTivaObjects[2];
 *  unsigned char uartTivaRingBuffer[2][32];
 *
 *  const UARTTiva_HWAttrs uartTivaHWAttrs[] = {
 *      {
 *          .baseAddr = UART0_BASE,
 *          .intNum = INT_UART0,
 *          .intPriority = ~0,
 *          .flowControl = UART_FLOWCONTROL_NONE,
 *          .ringBufPtr  = uartTivaRingBuffer[0],
 *          .ringBufSize = sizeof(uartTivaRingBuffer[0])
 *      },
 *      {
 *          .baseAddr = UART1_BASE,
 *          .intNum = INT_UART1,
 *          .intPriority = ~0,
 *          .flowControl = UART_FLOWCONTROL_NONE,
 *          .ringBufPtr  = uartTivaRingBuffer[1],
 *          .ringBufSize = sizeof(uartTivaRingBuffer[1])
 *      }
 *  @endcode
 */
typedef struct UARTTiva_HWAttrs {
    /*! UART Peripheral's base address */
    unsigned int baseAddr;
    /*! UART Peripheral's interrupt vector */
    unsigned int intNum;
    /*! UART Peripheral's interrupt priority */
    unsigned int intPriority;
    /*! Flow control setting provided by driverlib */
    uint32_t     flowControl;
    /*! Pointer to a application ring buffer */
    void        *ringBufPtr;
    /*! Size of ringBufPtr */
    size_t       ringBufSize;
} UARTTiva_HWAttrs;

/*!
 *  @brief      UARTTiva Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UARTTiva_Object {
    /* UART status variable */
    struct {
        bool             opened:1;         /* Has the obj been opened */
        UART_Mode        readMode:1;       /* Mode for all read calls */
        UART_Mode        writeMode:1;      /* Mode for all write calls */
        UART_DataMode    readDataMode:1;   /* Type of data being read */
        UART_DataMode    writeDataMode:1;  /* Type of data being written */
        UART_ReturnMode  readReturnMode:1; /* Receive return mode */
        UART_Echo        readEcho:1;       /* Echo received data back */
        bool             writeCR:1;        /* Write a return character */
        bool             bufTimeout:1;
        bool             callCallback:1;
    } status;

    union {
        struct {
            Clock_Struct     timeout;      /* Clock object to for timeouts */
            Semaphore_Struct readSem;      /* UART read semaphore */
            Semaphore_Struct writeSem;     /* UART write semaphore*/
            unsigned int     readTimeout;  /* Timeout for read semaphore */
            unsigned int     writeTimeout; /* Timeout for write semaphore */
        } blocking;
        struct {
            bool             inIsrControl;
        } callback;
    };

    UART_Callback        readCallback;     /* Pointer to read callback */
    UART_Callback        writeCallback;    /* Pointer to write callback */

    /* UART read variables */
    RingBuf_Object       ringBuffer;
    void                *readBuf;          /* Buffer data pointer */
    size_t               readSize;         /* Desired number of bytes to read */
    size_t               readCount;        /* Number of bytes left to read */

    /* UART write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeSize;        /* Desired number of bytes to write*/
    size_t               writeCount;       /* Number of bytes left to write */

    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /* Hwi object */
} UARTTiva_Object, *UARTTiva_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTTiva__include */
