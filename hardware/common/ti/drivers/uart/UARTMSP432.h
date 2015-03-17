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

#include <ti/drivers/UART.h>
#include <ti/drivers/uart/RingBuf.h>
#include <ti/drivers/ports/ClockP.h>
#include <ti/drivers/ports/HwiP.h>
#include <ti/drivers/ports/SemaphoreP.h>

/* Return codes for UART_control() */
#define UARTMSP432_CMD_UNDEFINED    -UART_RESERVATION_BASE - 1

/* UARTMSP432 function table pointer */
extern const UART_FxnTable UARTMSP432_fxnTable;

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

/*
 *  @brief      UARTMSP432 Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP432Ware these definitions are found in:
 *      - uart.h
 *
 *  A sample structure is shown below:
 *  @code
 *
 *  unsigned char uartMSP432RingBuffer[2][32];
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
 *          .ringBufPtr  = uartMSP432RingBuffer[0],
 *          .ringBufSize = sizeof(uartMSP432RingBuffer[0])
 *      },
 *      {
 *          .baseAddr = EUSCI_A2_BASE,
 *          .clockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK,
 *          .bitOrder = EUSCI_A_UART_LSB_FIRST,
 *          .numBaudrateEntries = sizeof(uartMSP432Baudrates) /
 *                                sizeof(UARTMSP432_BaudrateConfig),
 *          .baudrateLUT = uartMSP432Baudrates
 *          .ringBufPtr  = uartMSP432RingBuffer[1],
 *          .ringBufSize = sizeof(uartMSP432RingBuffer[1])
 *      }
 *  };
 *  @endcode
 */
typedef struct UARTMSP432_HWAttrs {
    /*! UART Peripheral's base address */
    uint32_t baseAddr;
    /*! UART Peripheral's interrupt vector */
    uint8_t  intNum;
    /*! UART Peripheral's interrupt priority */
    uint8_t  intPriority;
    /*! UART Clock source */
    uint8_t  clockSource;
    /*!< UART Bit order */
    uint32_t bitOrder;
    /*!< Number of UARTMSP432_BaudrateConfig entries */
    uint8_t  numBaudrateEntries;
    /*!< Pointer to a table of possible UARTMSP432_BaudrateConfig entries */
    UARTMSP432_BaudrateConfig const *baudrateLUT;
    /*! Pointer to a application ring buffer */
    void        *ringBufPtr;
    /*! Size of ringBufPtr */
    size_t       ringBufSize;
} UARTMSP432_HWAttrs;

/*!
 *  @brief      UARTMSP432 Object
 *
 *  Not intended to be used by the user.
 */
typedef struct UARTMSP432_Object {
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
            ClockP_Handle     timeoutClk;   /* Clock object to for timeouts */
            SemaphoreP_Handle readSem;      /* UART read semaphore */
            SemaphoreP_Handle writeSem;     /* UART write semaphore*/
            unsigned int      readTimeout;  /* Timeout for read semaphore */
            unsigned int      writeTimeout; /* Timeout for write semaphore */
        } blocking;
        struct {
            bool             inIsrControl;
        } callback;
    };

    HwiP_Handle          hwiHandle;

    UART_Callback        readCallback;     /* Pointer to read callback */
    UART_Callback        writeCallback;    /* Pointer to write callback */

    uint32_t             baudRate;         /*!< Baud rate for UART */
    UART_LEN             dataLength;       /*!< Data length for UART */
    UART_STOP            stopBits;         /*!< Stop bits for UART */
    UART_PAR             parityType;       /*!< Parity bit type for UART */

    /* UART read variables */
    RingBuf_Object       ringBuffer;
    void                *readBuf;          /* Buffer data pointer */
    size_t               readSize;         /* Desired number of bytes to read */
    size_t               readCount;        /* Number of bytes left to read */

    /* UART write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeSize;        /* Desired number of bytes to write*/
    size_t               writeCount;       /* Number of bytes left to write */

} UARTMSP432_Object, *UARTMSP432_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTMSP432__include */
