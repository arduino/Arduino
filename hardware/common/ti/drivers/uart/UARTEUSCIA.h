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
 *  @file       UARTEUSCIA.h
 *
 *  @brief      UART driver implementation for a EUSCIA peripheral
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTEUSCIA.h>
 *  @endcode
 *
 *  This UART driver implementation is designed to operate on a EUSCI controller
 *  in UART mode. It uses the APIs for a EUSCIA controller.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTEUSCIA__include
#define ti_drivers_uart_UARTEUSCIA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/UART.h>

#include <ti/sysbios/knl/Semaphore.h>

/* UARTEUSCIA function table pointer */
extern const UART_FxnTable UARTEUSCIA_fxnTable;

/*!
 *  @brief      UARTEUSCIA Baudrate configuration
 *
 *  This structure is used to specifiy the eusci controller's clock divider
 *  settings to achieve the desired baudrate given the indicated clock input
 *  frequency.
 *  Divider values can be determined by referring to the MSP430 baudrate
 *  calculator.
 *  http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTEUSCIA_BaudrateConfig uartUSCIABaudrates[] = {
 *   // Baudrate, input clock (Hz), Prescalar, UCBRFx, UCBRSx, Oversampling
 *      {115200,  8192000,          4,         7,      0,      1},
 *      {9600,    8192000,          53,        5,      0,      1},
 *      {9600,    32768,            3,         0,      3,      0},
 *  };
 *  @endcode
 */
typedef struct UARTEUSCIA_BaudrateConfig {
    uint32_t  outputBaudrate; /*! Search criteria: desired baudrate */
    uint32_t  inputClockFreq; /*! Search criteria: given this input clock frequency */

    uint8_t   prescalar;      /*! Clock prescalar */
    uint8_t   hwRegUCBRFx;    /*! UCBRFx lookup entry */
    uint8_t   hwRegUCBRSx;    /*! UCBRSx lookup entry */
    uint8_t   sampling;       /*! Oversampling mode (1: True; 0: False) */
} UARTEUSCIA_BaudrateConfig;

/*!
 *  @brief      UARTEUSCIA Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - inc/hw_memmap.h
 *      - usci_a_uart.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTEUSCIA_BaudrateConfig uartUSCIABaudrates[] = {
 *   // Baudrate, input clock (Hz), UCBRx, UCBRFx, UCBRSx, Oversampling
 *      {115200,  8192000,          4,     7,      0,      1},
 *      {9600,    8192000,          53,    5,      0,      1},
 *      {9600,    32768,            3,     0,      3,      0},
 *  };
 *
 *  const UARTEUSCIA_HWAttrs uartUSCIAHWAttrs[] = {
 *      {
 *          EUSCI_A0_BASE,
 *          EUSCI_A_UART_CLOCKSOURCE_SMCLK,
 *          EUSCI_A_UART_LSB_FIRST,
 *          sizeof(uartUSCIABaudrates/UARTEUSCIA_BaudrateConfig),
 *          uartUSCIABaudrates
 *      },
 *      {
 *          EUSCI_A1_BASE,
 *          EUSCI_A_UART_CLOCKSOURCE_SMCLK,
 *          EUSCI_A_UART_LSB_FIRST,
 *          sizeof(uartUSCIABaudrates/UARTEUSCIA_BaudrateConfig),
 *          uartUSCIABaudrates
 *      },
 *  };
 *  @endcode
 */
typedef struct UARTEUSCIA_HWAttrs {
    /*! EUSCI_A_UART Peripheral's base address */
    unsigned int baseAddr;
    /*! EUSCI_A_UART Clock source */
    uint8_t      clockSource;
    /*!< EUSCI_A_UART Bit order */
    uint32_t     bitOrder;
    /*!< Number of UARTEUSCIA_BaudrateConfig entries */
    unsigned int numBaudrateEntries;
    /*!< Pointer to a table of possible UARTEUSCIA_BaudrateConfig entries */
    UARTEUSCIA_BaudrateConfig const *baudrateLUT;
} UARTEUSCIA_HWAttrs;

/*!
 *  @brief      UARTEUSCIA Object
 *
 *  Not intended to be used by the user.
 */
typedef struct UARTEUSCIA_Object {
    /* UARTEUSCIA control variables */
    bool                 isOpen;           /* Status for open */
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

    /* UARTEUSCIA write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeCount;       /* Number of Chars sent */
    size_t               writeSize;        /* Chars remaining in buffer */
    bool                 writeCR;          /* Write a return character */

    /* UARTEUSCIA receive variables */
    void                *readBuf;          /* Buffer data pointer */
    size_t               readCount;        /* Number of Chars read */
    size_t               readSize;         /* Chars remaining in buffer */

    /* UARTEUSCIA SYS/BIOS objects */
    Semaphore_Struct     writeSem;         /* UARTEUSCIA write semaphore */
    Semaphore_Struct     readSem;          /* UARTEUSCIA read semaphore */
} UARTEUSCIA_Object, *UARTEUSCIA_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTEUSCIA__include */
