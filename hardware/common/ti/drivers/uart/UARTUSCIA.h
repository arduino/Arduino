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
 *  @file       UARTUSCIA.h
 *
 *  @brief      UART driver implementation for a USCIA peripheral
 *
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTUSCIA.h>
 *  @endcode
 *
 *  This UART driver implementation is designed to operate on a UCSI controller
 *  in UART mode. It uses the APIs for a USCIA controller.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTUSCIA__include
#define ti_drivers_uart_UARTUSCIA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/UART.h>

#include <ti/sysbios/knl/Semaphore.h>

/* UARTUSCIA function table pointer */
extern const UART_FxnTable UARTUSCIA_fxnTable;

/*!
 *  @brief      UARTUSCIA Baudrate configuration
 *
 *  This structure is used to specifiy the usci controller's clock divider
 *  settings to achieve the desired baudrate given the indicated clock input
 *  frequency.
 *  Divider values can be determined by referring to the MSP430 baudrate
 *  calculator.
 *  http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTUSCIA_BaudrateConfig uartUSCIABaudrates[] = {
 *   // Baudrate, input clock (Hz), Prescalar, UCBRFx, UCBRSx, Oversampling
 *      {115200,  8192000,          4,         7,      0,      1},
 *      {9600,    8192000,          53,        5,      0,      1},
 *      {9600,    32768,            3,         0,      3,      0},
 *  };
 *  @endcode
 */
typedef struct UARTUSCIA_BaudrateConfig {
    uint32_t  outputBaudrate; /*! Search criteria: desired baudrate */
    uint32_t  inputClockFreq; /*! Search criteria: given this input clock frequency */

    uint8_t   prescalar;      /*! Clock prescalar */
    uint8_t   hwRegUCBRFx;    /*! UCBRFx lookup entry */
    uint8_t   hwRegUCBRSx;    /*! UCBRSx lookup entry */
    uint8_t   sampling;       /*! Oversampling mode (1: True; 0: False) */
} UARTUSCIA_BaudrateConfig;

/*!
 *  @brief      UARTUSCIA Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - inc/hw_memmap.h
 *      - usci_a_uart.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTUSCIA_BaudrateConfig uartUSCIABaudrates[] = {
 *   // Baudrate, input clock (Hz), UCBRx, UCBRFx, UCBRSx, Oversampling
 *      {115200,  8192000,          4,     7,      0,      1},
 *      {9600,    8192000,          53,    5,      0,      1},
 *      {9600,    32768,            3,     0,      3,      0},
 *  };
 *
 *  const UARTUSCIA_HWAttrs uartUSCIAHWAttrs[] = {
 *      {
 *          USCI_A0_BASE,
 *          USCI_A_UART_CLOCKSOURCE_SMCLK,
 *          USCI_A_UART_LSB_FIRST,
 *          sizeof(uartUSCIABaudrates/UARTUSCIA_BaudrateConfig),
 *          uartUSCIABaudrates
 *      },
 *      {
 *          USCI_A1_BASE,
 *          USCI_A_UART_CLOCKSOURCE_SMCLK,
 *          USCI_A_UART_LSB_FIRST,
 *          sizeof(uartUSCIABaudrates/UARTUSCIA_BaudrateConfig),
 *          uartUSCIABaudrates
 *      },
 *  };
 *  @endcode
 */
typedef struct UARTUSCIA_HWAttrs {
    /*! USCI_A_UART Peripheral's base address */
    unsigned int baseAddr;
    /*! USCI_A_UART Clock source */
    uint8_t    clockSource;
    /*!< USCI_A_UART Bit order */
    uint32_t   bitOrder;
    /*!< Number of UARTUSCIA_BaudrateConfig entries */
    unsigned int numBaudrateEntries;
    /*!< Pointer to a table of possible UARTUSCIA_BaudrateConfig entries */
    UARTUSCIA_BaudrateConfig const *baudrateLUT;
} UARTUSCIA_HWAttrs;

/*!
 *  @brief      UARTUSCIA Object
 *
 *  Not intended to be used by the user.
 */
typedef struct UARTUSCIA_Object {
    /* UARTUSCIA control variables */
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

    /* UARTUSCIA write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeCount;       /* Number of Chars sent */
    size_t               writeSize;        /* Chars remaining in buffer */
    bool                 writeCR;          /* Write a return character */

    /* UARTUSCIA receive variables */
    void                *readBuf;          /* Buffer data pointer */
    size_t               readCount;        /* Number of Chars read */
    size_t               readSize;         /* Chars remaining in buffer */

    /* UARTUSCIA SYS/BIOS objects */
    Semaphore_Struct     writeSem;         /* UARTUSCIA write semaphore*/
    Semaphore_Struct     readSem;          /* UARTUSCIA read semaphore */
} UARTUSCIA_Object, *UARTUSCIA_Handle;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTUSCIA__include */
