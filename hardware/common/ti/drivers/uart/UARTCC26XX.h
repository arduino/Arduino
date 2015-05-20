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
 *  @file       UARTCC26XX.h
 *
 *  @brief      UART driver implementation for a CC26XX UART controller
 *
 * # Driver include #
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTCC26XX.h>
 *  @endcode
 *
 * # Overview #
 * The general UART API should used in application code, i.e. UART_open()
 * is used instead of UARTCC26XX_open(). The board file will define the device
 * specific config, and casting in the general API will ensure that the correct
 * device specific functions are called.
 * This is also reflected in the example code in [Use Cases](@ref USE_CASES).
 *
 * # General Behavior #
 * Before using the UART in CC26XX:
 *   - The UART driver is initialized by calling UART_init().
 *   - The UART HW is configured and flags system dependencies (e.g. IOs,
 *     power, etc.) by calling UART_open().
 *   - The RX and TX can operate independently of each other.
 *   .
 * The following is true for receive operation:
 *   - RX is enabled by calling UART_read().
 *   - All received bytes are ignored after UART_open() is called, until
 *     the first UART_read().
 *   - If an RX error occur, RX is turned off and all bytes received before the
 *     error occured are returned.
 *   - After a successful read, RX remains on. UART_read() must be called
 *     again before FIFO goes full in order to avoid overflow. It is safe to
 *     call another UART_read() from the read callback, See
 *     [Receive Continously] (@ref USE_CASE_CB) use case below.
 *   - If a read times out (in ::UART_MODE_BLOCKING mode), RX will remain on.
 *     UART_read() must be called again before FIFO goes full in order to avoid overflow.
 *   - The UART_read() supports partial return, that can be used if the
 *     receive size is unknown. See [Use Cases](@ref USE_CASES) below.
 *   .
 * The following apply for transmit operation:
 *   - TX is enabled by calling UART_write().
 *   - If the UART_write() succeeds, the TX is disabled.
 *   .
 * If UART is no longer needed by application:
 *   - Release system dependencies for UART by calling UART_close().
 *
 * # Error handling #
 * ## Read errors ##
 * If an error occurs during read operation:
 *   - All bytes received up until an error occurs will be returned, with the
 *     error signaled in the ::UARTCC26XX_Object.status field. The RX is then turned off
 *     and all bytes will be ignored until a new read is issued. Note that only
 *     the read is cancelled when the error occurs. If a write was active
 *     while the RX error occurred, it will complete.
 *   - If a RX break error occurs, an extra 0 byte will also be returned by the
 *     UART_read().
 *   .
 *
 * ## Write errors##
 * If a timeout occurs during a write, an UART_ERROR will be returned and the
 * UART_Object.status will be set to ::UART_TIMED_OUT. All bytes that are not
 * transmitted, will be flushed.
 * If flow control is not enabled, the ::UARTCC26XX_Object.writeTimeout should
 * be kept at default value, BIOS_WAIT_FOREVER. The write call will return after
 * all bytes are transmitted.
 * If flow control is enabled, the timeout should be set by the application in
 * order to recover if the receiver gets stuck.
 *
 * ## General timeout ##
 * A timeout value can only be specified for reads and writes in ::UART_MODE_BLOCKING.
 * If a timeout occurs during a read when in ::UART_MODE_BLOCKING, the number of bytes received will be
 * returned and the UART_Object.status will be set to ::UART_TIMED_OUT.
 * After a read timeout, RX will remain on, but device is allowed to enter standby.
 * For more details see [Power Management](@ref POWER_MANAGEMENT) chapter below.
 *
 * In ::UART_MODE_CALLBACK there is no timeout and the application must call
 * UART_readCancel() or UART_writeCancel() to abort the operation.
 *
 * @note A new read or write will reset the UART_Object.status to UART_OK.
 *       Caution must be taken when doing parallell reads and writes.
 *
 * # Power Management \anchor POWER_MANAGEMENT #
 * The TI-RTOS power management framework will try to put the device into the most
 * power efficient mode whenever possible. Please see the technical reference
 * manual for further details on each power mode.
 *
 * The UARTCC26XX driver is setting a power constraint during operation to keep
 * the device out of standby. When the operation has finished, the power
 * constraint is released.
 * The following statements are valid:
 *   - After UART_open(): the device is still allowed to enter standby.
 *   - During UART_read(): the device cannot enter standby.
 *   - After an RX error (overrun, break, parity, framing): device is allowed to enter standby.
 *   - After a successful UART_read():
 *     The device is allowed to enter standby, but RX remains on.
 *       - _Note_: Device might enter standby while a byte is being
 *         received if UART_read() is not called again after a successful
 *         read. This could result in corrupt data being received.
 *       - _Note_: Application thread should typically either issue another read after
 *         UART_read() completes successfully, or call
 *         UART_readCancel() to disable RX and thus assuring that no data
 *         is received while entering standby.
 *   - After UART_read() times out in ::UART_MODE_BLOCKING:
 *     The device is allowed to enter standby, but RX remains on.
 *       - _Note_: Device might enter standby while a byte is being
 *         received if UART_read() is not called again after a timeout.
 *         This could result in corrupt data being received.
 *       - _Note_: Application thread should typically either issue another read after
 *         UART_read() times out to continue reception.
 *       .
 *   - During UART_write(): the device cannot enter standby.
 *   - After UART_write() succeeds: the device can enter standby.
 *   - If UART_writeCancel() is called: the device can enter standby.
 *   - After write timeout: the device can enter standby.
 *
 * # Flow Control #
 * To enable Flow Control, the RTS and CTS pins must be assigned in the
 * ::UARTCC26XX_HWAttrs:
 *  @code
 *  const UARTCC26XX_HWAttrs uartCC26xxHWAttrs[] = {
 *      {
 *          .baseAddr    = UART0_BASE,
 *          .intNum      = INT_UART0,
 *          .powerMngrId = PERIPH_UART0,
 *          .txPin       = Board_UART_TX,
 *          .rxPin       = Board_UART_RX,
 *          .ctsPin      = Board_UART_CTS,
 *          .rtsPin      = Board_UART_RTS
 *      }
 *  };
 *  @endcode
 *
 * If the RTS and CTS pins are set to ::PIN_UNASSIGNED, the flow control is
 * disabled. An example is shown in the ::UARTCC26XX_HWAttrs description.
 *
 * # Supported Functions #
 * | Generic API function | API function             | Description                                       |
 * |----------------------|--------------------------|------------------------
 * | UART_init()          | UARTCC26XX_init()        | Initialize UART driver                            |
 * | UART_open()          | UARTCC26XX_open()        | Initialize UART HW and set system dependencies    |
 * | UART_close()         | UARTCC26XX_close()       | Disable UART HW and release system dependencies   |
 * | UART_control()       | UARTCC26XX_control()     | Configure an already opened UART handle           |
 * | UART_read()          | UARTCC26XX_read()        | Start read from UART                              |
 * | UART_readCancel()    | UARTCC26XX_readCancel()  | Cancel ongoing read from UART                     |
 * | UART_write()         | UARTCC26XX_write()       | Start write to UART                               |
 * | UART_writeCancel()   | UARTCC26XX_writeCancel() | Cancel ongoing write to UART                      |
 *
 *  @note All calls should go through the generic API
 *
 *  # Not Supported Functionality #
 *  The CC26XX UART driver currently does not support:
 *    - ::UART_ECHO_ON
 *    - ::UART_DATA_TEXT
 *    - UART_readPolling()
 *    - UART_writePolling()
 *    - Configurable TX FIFO Threshold (currently set to 1/8 full, i.e. 4 bytes)
 *    - Configurable RX FIFO Threshold (currently set to 4/8 full, i.e. 16 bytes)
 *
 * # Use Cases \anchor USE_CASES #
 * ## Basic Receive #
 *  Receive 100 bytes over UART in ::UART_MODE_BLOCKING.
 *  @code
 *  UART_Handle handle;
 *  UART_Params params;
 *  uint8_t rxBuf[100];         // Receive buffer
 *  uint32_t timeoutUs = 5000;  // 5ms timeout, default timeout is no timeout (BIOS_WAIT_FOREVER)
 *
 *  // Init UART and specify non-default parameters
 *  UART_Params_init(&params);
 *  params.baudRate      = 9600;
 *  params.writeDataMode = UART_DATA_BINARY;
 *  params.readTimeout   = timeoutUs / Clock_tickPeriod; // Default tick period is 10us
 *
 *  // Open the UART and do the read
 *  handle = UART_open(Board_UART, &params);
 *  int rxBytes = UART_read(handle, rxBuf, 100);
 *  @endcode
 *
 * ## Receive with Return Partial #
 *  This use case will read in ::UART_MODE_BLOCKING until the wanted amount of bytes is
 *  received or until a started reception is inactive for a 32-bit period.
 *  This UART_read() call can also be used when unknown amount of bytes shall
 *  be read. Note: The partial return is also possible in ::UART_MODE_CALLBACK mode.
 *  @code
 *  UART_Handle handle;
 *  UART_Params params;
 *  uint8_t rxBuf[100];      // Receive buffer
 *
 *  // Init UART and specify non-default parameters
 *  UART_Params_init(&params);
 *  params.baudRate      = 9600;
 *  params.writeDataMode = UART_DATA_BINARY;
 *
 *  // Open the UART and initiate the partial read
 *  handle = UART_open(Board_UART, &params);
 *  // Enable RETURN_PARTIAL
 *  UART_control(handle, UARTCC26XX_CMD_RETURN_PARTIAL_ENABLE, NULL);
 *  // Begin read
 *  int rxBytes = UART_read(handle, rxBuf, 100));
 *  @endcode
 *
 * ## Basic Transmit #
 *  This case will configure the UART to send the data in txBuf in
 *  BLOCKING_MODE.
 *  @code
 *  UART_Handle handle;
 *  UART_Params params;
 *  uint8_t txBuf[] = "Hello World";    // Transmit buffer
 *
 *  // Init UART and specify non-default parameters
 *  UART_Params_init(&params);
 *  params.baudRate      = 9600;
 *  params.writeDataMode = UART_DATA_BINARY;
 *
 *  // Open the UART and do the write
 *  handle = UART_open(Board_UART, &params);
 *  UART_write(handle, txBuf, sizeof(txBuf));
 *  @endcode
 *
 * ## Receive Continously in ::UART_MODE_CALLBACK \anchor USE_CASE_CB #
 *  This case will configure the UART to receive continously in
 *  ::UART_MODE_CALLBACK, 16 bytes at the time and transmit them back via UART TX.
 *  Note that UART_Params.readTimeout is not in use when using ::UART_MODE_CALLBACK mode.
 *  @code
 *  #define MAX_NUM_RX_BYTES    1000   // Maximum RX bytes to receive in one go
 *  #define MAX_NUM_TX_BYTES    1000   // Maximum TX bytes to send in one go
 *
 *  uint32_t wantedRxBytes;            // Number of bytes received so far
 *  uint8_t rxBuf[MAX_NUM_RX_BYTES];   // Receive buffer
 *  uint8_t txBuf[MAX_NUM_TX_BYTES];   // Transmit buffer
 *
 *  // Callback function
 *  static void readCallback(UART_Handle handle, void *rxBuf, size_t size)
 *  {
 *      // Copy bytes from RX buffer to TX buffer
 *      for(size_t i = 0; i < size; i++)
 *          txBuf[i] = ((uint8_t*)rxBuf)[i];
 *
 *      // Echo the bytes received back to transmitter
 *      UART_write(handle, txBuf, size);
 *
 *      // Start another read, with size the same as it was during first call to
 *      // UART_read()
 *      UART_read(handle, rxBuf, wantedRxBytes);
 *  }
 *
 *  static void taskFxn(UArg a0, UArg a1)
 *  {
 *      UART_Handle handle;
 *      UART_Params params;
 *
 *      // Init UART and specify non-default parameters
 *      UART_Params_init(&params);
 *      params.baudRate      = 9600;
 *      params.writeDataMode = UART_DATA_BINARY;
 *      params.readMode      = UART_MODE_CALLBACK;
 *      params.readDataMode  = UART_DATA_BINARY;
 *      params.readCallback  = readCallback;
 *
 *      // Open the UART and initiate the first read
 *      handle = UART_open(Board_UART, &params);
 *      wantedRxBytes = 16;
 *      int rxBytes = UART_read(handle, rxBuf, wantedRxBytes);
 *
 *      while(true); // Wait forever
 *  }
 *  @endcode
 *
 *  # Instrumentation #
 *  The UART driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic UART operations performed |
 *  Diags_USER2      | detailed UART operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTCC26XX__include
#define ti_drivers_uart_UARTCC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/UART.h>
#include <ti/sysbios/family/arm/cc26xx/Power.h>
#include <driverlib/uart.h>

/*
 * The following allows this header file to be included in an application file
 * which also includes ti/sysbios/hal/Hwi.h.
 */
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>

/*! Enable RETURN_PARTIAL, used as cmd to UART_control() */
#define UARTCC26XX_CMD_RETURN_PARTIAL_ENABLE    UART_CMD_RESERVED + 0
/*! Disable RETURN_PARTIAL, used as cmd to UART_control() */
#define UARTCC26XX_CMD_RETURN_PARTIAL_DISABLE   UART_CMD_RESERVED + 1
/*! Size of the TX and RX FIFOs is 32 items */
#define UARTCC26XX_FIFO_SIZE 32

/* BACKWARDS COMPATIBILITY */
#define UARTCC26XX_RETURN_PARTIAL_ENABLE    UARTCC26XX_CMD_RETURN_PARTIAL_ENABLE
#define UARTCC26XX_RETURN_PARTIAL_DISABLE   UARTCC26XX_CMD_RETURN_PARTIAL_DISABLE
/* END BACKWARDS COMPATIBILITY */

/* UART function table pointer */
extern const UART_FxnTable UARTCC26XX_fxnTable;

/*!
 *  @brief      UARTCC26XX Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For CC26xxWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const UARTCC26XX_HWAttrs uartCC26xxHWAttrs[] = {
 *      {
 *          .baseAddr = UART0_BASE,
 *          .intNum = INT_UART0,
 *          .powerMngrId = PERIPH_UART0,
 *          .txPin = Board_UART_TX,
 *          .rxPin = Board_UART_RX,
 *          .ctsPin = PIN_UNASSIGNED,
 *          .rtsPin = PIN_UNASSIGNED
 *      }
 *  };
 *  @endcode
 *
 *  The .ctsPin and .rtsPin must be assigned to enable flow control.
 */
typedef struct UARTCC26XX_HWAttrs {
    uint32_t   baseAddr;    /*!< UART Peripheral's base address */
    int        intNum;      /*!< UART Peripheral's interrupt vector */
    uint32_t   powerMngrId; /*!< UART Peripheral's power manager ID */
    uint8_t    txPin;       /*!< UART TX pin */
    uint8_t    rxPin;       /*!< UART RX pin */
    uint8_t    ctsPin;      /*!< UART CTS pin */
    uint8_t    rtsPin;      /*!< UART RTS pin */
} UARTCC26XX_HWAttrs;

/*!
 *  @brief    UART status
 *
 *  The UART Status is used to flag the different Receive Errors.
 */
typedef enum UART_Status {
    UART_TIMED_OUT     = 0x10,                 /*!< UART timed out */
    UART_PARITY_ERROR  = UART_RXERROR_PARITY,  /*!< UART Parity error */
    UART_BRAKE_ERROR   = UART_RXERROR_BREAK,   /*!< UART Break error */
    UART_OVERRUN_ERROR = UART_RXERROR_OVERRUN, /*!< UART overrun error */
    UART_FRAMING_ERROR = UART_RXERROR_FRAMING, /*!< UART Framing error */
    UART_OK            = 0x0                   /*!< UART OK */
} UART_Status;

/*!
 *  @brief    UART FIFO threshold
 *
 *  Mapping of FIFO thresholds from level to number of bytes.
 */
typedef enum UART_FifoThreshold {
    UART_TH_FIFO_1_8 = 4,         /*!< RX FIFO threshold of 1/8 = 4 bytes */
    UART_TH_FIFO_2_8 = 8,         /*!< RX FIFO threshold of 2/8 = 8 bytes */
    UART_TH_FIFO_4_8 = 16,        /*!< RX FIFO threshold of 4/8 = 16 bytes */
    UART_TH_FIFO_6_8 = 24,        /*!< RX FIFO threshold of 6/8 = 24 bytes */
    UART_TH_FIFO_7_8 = 28         /*!< RX FIFO threshold of 7/8 = 28 bytes */
} UART_FifoThreshold;

/*!
 *  @brief      UARTCC26XX Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UARTCC26XX_Object {
    /* UART control variables */
    bool                opened;         /*!< Has the obj been opened */
    UART_Mode           readMode;       /*!< Mode for all read calls */
    UART_Mode           writeMode;      /*!< Mode for all write calls */
    unsigned int        readTimeout;    /*!< Timeout for read semaphore in BLOCKING mode*/
    unsigned int        writeTimeout;   /*!< Timeout for write semaphore in BLOCKING mode*/
    UART_Callback       readCallback;   /*!< Pointer to read callback */
    UART_Callback       writeCallback;  /*!< Pointer to write callback */
    UART_ReturnMode     readReturnMode; /*!< Receive return mode */
    UART_DataMode       readDataMode;   /*!< Type of data being read */
    UART_DataMode       writeDataMode;  /*!< Type of data being written */
    uint32_t            baudRate;       /*!< Baud rate for UART */
    UART_LEN            dataLength;     /*!< Data length for UART */
    UART_STOP           stopBits;       /*!< Stop bits for UART */
    UART_PAR            parityType;     /*!< Parity bit type for UART */
    UART_Status         status;         /*!< Status variable */

    /* UART write variables */
    const void         *writeBuf;       /*!< Buffer data pointer */
    size_t              writeCount;     /*!< Number of Chars sent */
    size_t              writeSize;      /*!< Chars remaining in buffer */
    bool                writeCR;        /*!< Write a return character */

    /* UART receive variables */
    bool                  readRetPartial;     /*! Return partial RX data if timeout occurs */
    void                  *readBuf;           /*!< Buffer data pointer */
    size_t                readCount;          /*!< Number of Chars read */
    size_t                readSize;           /*!< Chars remaining in buffer */
    UART_FifoThreshold    readFifoThreshold;  /*! Threshold for generating RX IRQ */
    uint8_t               writeFifoThreshold; /*! Threshold for generating TX IRQ */

    /*! UART post-notification function pointer */
    void             *uartPostFxn;
    /*!< UART post-notification object */
    Power_NotifyObj  uartPostObj;

    /* UART SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /*!< Hwi object */
    Semaphore_Struct     writeSem;           /*!< UART write semaphore*/
    Semaphore_Struct     readSem;            /*!< UART read semaphore */
    Clock_Struct         txFifoEmptyClk;     /*!< UART TX FIFO empty clock */
} UARTCC26XX_Object, *UARTCC26XX_Handle;



/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTCC26XX__include */
