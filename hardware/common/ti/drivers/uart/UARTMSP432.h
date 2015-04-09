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
 *  @file       UARTMSP432.h
 *
 *  @brief      UART driver implementation for a EUSCIA peripheral for MSP432
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTMSP432.h>
 *  @endcode
 *
 *  This UART driver implementation is designed to operate on a EUSCI controller
 *  in UART mode for MSP432 devices.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTMSP432__include
#define ti_drivers_uart_UARTMSP432__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include <ti/drivers/ports/ClockP.h>
#include <ti/drivers/ports/HwiP.h>
#include <ti/drivers/ports/SemaphoreP.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/RingBuf.h>

/* UART function table pointer */
extern const UART_FxnTable UARTMSP432_fxnTable;

/*!
 *  @brief Complement set of read functions to be used by the UART ISR and
 *         UARTMSP432_read(). Internal use only.
 *
 *  These functions should not be used by the user and are solely intended for
 *  the UARTMSP432 driver.
 *  The UARTMSP432_FxnSet is a pair of complement functions that are design to
 *  operate with one another in a task context and in an ISR context. The
 *  readTaskFxn is called by UARTMSP432_read() to drain a circular buffer,
 *  whereas the readIsrFxn is used by the UARTMSP432_hwiIntFxn to fill up the
 *  circular buffer.
 *
 *  readTaskFxn:    Function called by UART read
 *                  These variables are set and available for use to the
 *                  readTaskFxn.
 *                  object->readBuf = buffer; //Pointer to a user buffer
 *                  object->readSize = size;  //Desired no. of bytes to read
 *                  object->readCount = size; //Remaining no. of bytes to read
 *
 *  readIsrFxn:     The required ISR counterpart to readTaskFxn
 */
typedef struct UARTMSP432_FxnSet {
    bool (*readIsrFxn)  (UART_Handle handle);
    int  (*readTaskFxn) (UART_Handle handle);
} UARTMSP432_FxnSet;

/*!
 *  @brief      UARTMSP432 Baudrate configuration
 *
 *  This structure is used to specifiy the EUSCI controller's clock divider
 *  settings to achieve the desired baudrate given the a clock input frequency.
 *  Divider values can be determined by referring to the MSP430 baudrate
 *  calculator.
 *  http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTMSP432_BaudrateConfig uartBaudrates[] = {
 *      // {baudrate, input clock, prescalar, UCBRFx, UCBRSx, oversampling}
 *      {115200, 12000000,  6,  8,  32, 1},
 *      {115200, 6000000,   3,  4,   2, 1},
 *      {115200, 3000000,   1, 10,   0, 1},
 *      {9600,   12000000, 78,  2,   0, 1},
 *      {9600,   6000000,  39,  1,   0, 1},
 *      {9600,   3000000,  19,  8,  85, 1},
 *      {9600,   32768,     3,  0, 146, 0}
 *  };
 *  @endcode
 */
typedef struct UARTMSP432_BaudrateConfig {
    uint32_t  outputBaudrate; /*! Search criteria: desired baudrate */
    uint32_t  inputClockFreq; /*! Search criteria: given this input clock frequency */

    uint16_t  prescalar;      /*! Clock prescalar */
    uint8_t   hwRegUCBRFx;    /*! UCBRFx lookup entry */
    uint8_t   hwRegUCBRSx;    /*! UCBRSx lookup entry */
    uint8_t   sampling;       /*! Oversampling mode (1: True; 0: False) */
} UARTMSP432_BaudrateConfig;

/*!
 *  @brief      UARTMSP432 Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP432Ware these definitions are found in:
 *      - uart.h
 *
 *  A sample structure is shown below:
 *  @code
 *
 *  unsigned char uartMSP432RingBuffer0[32];
 *  unsigned char uartMSP432RingBuffer1[32];
 *
 *  const UARTMSP432_HWAttrs uartMSP432HWAttrs[MSP_EXP432P401RLP_UARTCOUNT] = {
 *      {
 *          .baseAddr = EUSCI_A0_BASE,
 *          .intNum = INT_EUSCIA0,
 *          .intPriority = ~0,
 *          .clockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK,
 *          .bitOrder = EUSCI_A_UART_LSB_FIRST,
 *          .numBaudrateEntries = sizeof(uartMSP432Baudrates) /
 *                                sizeof(UARTMSP432_BaudrateConfig),
 *          .baudrateLUT = uartMSP432Baudrates,
 *          .ringBufPtr  = uartMSP432RingBuffer0,
 *          .ringBufSize = sizeof(uartMSP432RingBuffer0)
 *      },
 *      {
 *          .baseAddr = EUSCI_A2_BASE,
 *          .intNum = INT_EUSCIA2,
 *          .intPriority = ~0,
 *          .clockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK,
 *          .bitOrder = EUSCI_A_UART_LSB_FIRST,
 *          .numBaudrateEntries = sizeof(uartMSP432Baudrates) /
 *                                sizeof(UARTMSP432_BaudrateConfig),
 *          .baudrateLUT = uartMSP432Baudrates
 *          .ringBufPtr  = uartMSP432RingBuffer1,
 *          .ringBufSize = sizeof(uartMSP432RingBuffer1)
 *      }
 *  };
 *  @endcode
 */
typedef struct UARTMSP432_HWAttrs {
    /*! UART Peripheral's base address */
    unsigned int    baseAddr;
    /*! UART Peripheral's interrupt vector */
    unsigned int    intNum;
    /*! UART Peripheral's interrupt priority */
    unsigned int    intPriority;
    /*! UART Clock source */
    uint8_t         clockSource;
    /*!< UART Bit order */
    uint32_t        bitOrder;
    /*!< Number of UARTMSP432_BaudrateConfig entries */
    uint8_t         numBaudrateEntries;
    /*!< Pointer to a table of possible UARTMSP432_BaudrateConfig entries */
    UARTMSP432_BaudrateConfig const *baudrateLUT;
    /*! Pointer to a application ring buffer */
    unsigned char  *ringBufPtr;
    /*! Size of ringBufPtr */
    size_t          ringBufSize;
} UARTMSP432_HWAttrs;

/*!
 *  @brief      UARTMSP432 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UARTMSP432_Object {
    /* UART state variable */
    struct {
        bool             opened:1;         /* Has the obj been opened */
        UART_Mode        readMode:1;       /* Mode for all read calls */
        UART_Mode        writeMode:1;      /* Mode for all write calls */
        UART_DataMode    readDataMode:1;   /* Type of data being read */
        UART_DataMode    writeDataMode:1;  /* Type of data being written */
        UART_ReturnMode  readReturnMode:1; /* Receive return mode */
        UART_Echo        readEcho:1;       /* Echo received data back */
        bool             writeCR:1;        /* Write a return character */
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
        /* Flag to keep the state of the read Power constraints */
        bool             rxEnabled:1;
        /* Flag to keep the state of the write Power constraints */
        bool             txEnabled:1;
    } state;

    HwiP_Handle          hwiHandle;        /* Hwi handle for interrupts */
    ClockP_Handle        timeoutClk;       /* Clock object to for timeouts */
    uint32_t             baudRate;         /* Baud rate for UART */
    UART_STOP            stopBits;         /* Stop bits for UART */
    UART_PAR             parityType;       /* Parity bit type for UART */

    /* UART read variables */
    RingBuf_Object       ringBuffer;       /* local circular buffer object */
    /* A complement pair of read functions for both the ISR and UART_read() */
    UARTMSP432_FxnSet    readFxns;
    unsigned char       *readBuf;          /* Buffer data pointer */
    size_t               readSize;         /* Desired number of bytes to read */
    size_t               readCount;        /* Number of bytes left to read */
    SemaphoreP_Handle    readSem;          /* UART read semaphore */
    unsigned int         readTimeout;      /* Timeout for read semaphore */
    UART_Callback        readCallback;     /* Pointer to read callback */

    /* UART write variables */
    const unsigned char *writeBuf;         /* Buffer data pointer */
    size_t               writeSize;        /* Desired number of bytes to write*/
    size_t               writeCount;       /* Number of bytes left to write */
    SemaphoreP_Handle    writeSem;         /* UART write semaphore*/
    unsigned int         writeTimeout;     /* Timeout for write semaphore */
    UART_Callback        writeCallback;    /* Pointer to write callback */
    unsigned int         writeEmptyClkTimeout; /* TX FIFO timeout tick count */

    Power_NotifyObj      perfChangeNotify;
    uint32_t             perfConstraintMask;
} UARTMSP432_Object, *UARTMSP432_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTMSP432__include */
