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

/* UART function table pointer */
extern const UART_FxnTable UARTTiva_fxnTable;

/*!
 *  @brief Complement set of read functions to be used by the UART ISR and
 *         UARTTiva_read(). Internal use only.
 *
 *  These functions should not be used by the user and are solely intended for
 *  the UARTTiva driver.
 *  The UARTTiva_FxnSet is a pair of complement functions that are design to
 *  operate with one another in a task context and in an ISR context. The
 *  readTaskFxn is called by UARTTiva_read() to drain a circular buffer,
 *  whereas the readIsrFxn is used by the UARTTiva_hwiIntFxn to fill up the
 *  circular buffer.
 *
 *  readTaskFxn:    Function called by UART read
 *                  These variables are set and avilalable for use to the
 *                  readTaskFxn.
 *                  object->readBuf = buffer; //Pointer to a user buffer
 *                  object->readSize = size;  //Desired no. of bytes to read
 *                  object->readCount = size; //Remaining no. of bytes to read
 *
 *  readIsrFxn:     The required ISR counterpart to readTaskFxn
 */
typedef struct UARTTiva_FxnSet {
    bool (*readIsrFxn)  (UART_Handle handle);
    int  (*readTaskFxn) (UART_Handle handle);
} UARTTiva_FxnSet;

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
 *  };
 *  @endcode
 */
typedef struct UARTTiva_HWAttrs {
    /*! UART Peripheral's base address */
    unsigned int    baseAddr;
    /*! UART Peripheral's interrupt vector */
    unsigned int    intNum;
    /*! UART Peripheral's interrupt priority */
    unsigned int    intPriority;
    /*! Hardware flow control setting defined by driverlib */
    uint32_t        flowControl;
    /*! Pointer to a application ring buffer */
    unsigned char  *ringBufPtr;
    /*! Size of ringBufPtr */
    size_t          ringBufSize;
} UARTTiva_HWAttrs;

/*!
 *  @brief      UARTTiva Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UARTTiva_Object {
    /* UART state variable */
    struct {
        bool             opened:1;         /* Has the obj been opened */
        UART_Mode        readMode:1;       /* Mode for all read calls */
        UART_Mode        writeMode:1;      /* Mode for all write calls */
        UART_DataMode    readDataMode:1;   /* Type of data being read */
        UART_DataMode    writeDataMode:1;  /* Type of data being written */
        UART_ReturnMode  readReturnMode:1; /* Receive return mode */
        UART_Echo        readEcho:1;       /* Echo received data back */
        /*
         * Flag to determine if a timeout has occurred when the user called
         * UART_read(). This flag is set by the timeoutClk clock object.
         */
        bool             bufTimeout:1;
        /*
         * Flag to determine when an ISR needs to perform a callback; in both
         * UART_MODE_BLOCKING or UART_MODE_CALLBACK
         */
        bool             callCallback:1;
        /*
         * Flag to determine if the ISR is in control draining the ring buffer
         * when in UART_MODE_CALLBACK
         */
        bool             drainByISR:1;
        /* Flag to keep the state of the read ring buffer */
        bool             rxEnabled:1;
    } state;

    Clock_Struct         timeoutClk;       /* Clock object to for timeouts */
    uint32_t             baudRate;         /* Baud rate for UART */
    UART_LEN             dataLength;       /* Data length for UART */
    UART_STOP            stopBits;         /* Stop bits for UART */
    UART_PAR             parityType;       /* Parity bit type for UART */

    /* UART read variables */
    RingBuf_Object       ringBuffer;       /* local circular buffer object */
    /* A complement pair of read functions for both the ISR and UART_read() */
    UARTTiva_FxnSet      readFxns;
    unsigned char       *readBuf;          /* Buffer data pointer */
    size_t               readSize;         /* Desired number of bytes to read */
    size_t               readCount;        /* Number of bytes left to read */
    Semaphore_Struct     readSem;          /* UART read semaphore */
    unsigned int         readTimeout;      /* Timeout for read semaphore */
    UART_Callback        readCallback;     /* Pointer to read callback */

    /* UART write variables */
    const unsigned char *writeBuf;         /* Buffer data pointer */
    size_t               writeSize;        /* Desired number of bytes to write*/
    size_t               writeCount;       /* Number of bytes left to write */
    Semaphore_Struct     writeSem;         /* UART write semaphore*/
    unsigned int         writeTimeout;     /* Timeout for write semaphore */
    UART_Callback        writeCallback;    /* Pointer to write callback */

    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /* Hwi object */
} UARTTiva_Object, *UARTTiva_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTTiva__include */
