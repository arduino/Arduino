/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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
 *  The UART header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UART.h>
 *  #include <ti/drivers/uart/UARTCC26XX.h>
 *  @endcode
 *
 * # Overview #
 * The general UART API is normally used in application code, i.e. UART_open()
 * is used instead of UARTCC26XX_open(). The board file will define the device
 * specific config, and casting in the general API will ensure that the correct
 * device specific functions are called.
 * This is also reflected in the example code in [Use Cases](@ref USE_CASES).
 *
 * ## General Behavior #
 * Before using the UART in CC26XX:
 *   - The UART driver is initialized by calling UARTCC26XX_init(). This should
 *     be done in main before BIOS_start() is called.
 *   - The UART HW is configured and flags system dependencies (e.g. IOs,
 *     power, etc.) by calling UARTCC26XX_open().
 *   - The RX and TX can operate independently of each other.
 *   .
 * The following is true for receive operation:
 *   - RX is enabled by calling UARTCC26XX_read().
 *   - All received bytes are ignored after UARTCC26XX_open() is called, until
 *     the first UARTCC26XX_read().
 *   - If an RX error occur, RX is turned off and all bytes are ignored.
 *   - After a successful read, RX remains on. UARTCC26XX_read() must be called
 *     again before FIFO goes full in order to avoid overflow. It is safe to
 *     call another UARTCC26XX_read() from the read callback, See
 *     [Receive Continously] (@ref USE_CASE_CB) use case below.
 *   - The UARTCC26XX_read() supports partial return, that can be used if the
 *     receive size is unknown. See [Use Cases](@ref USE_CASES) below.
 *   .
 * The following apply for transmit operation:
 *   - TX is enabled by calling UARTCC26XX_write().
 *   - If the UARTCC26XX_write() succeeds, the TX is disabled.
 *   .
 * After UART operation has ended:
 *   - Release system dependencies for UART by calling UARTCC26XX_close().
 *
 * ## Error handling #
 * If an error occurs during read operation:
 *   - All bytes received up until an error occurs will be returned, with the
 *     error signaled in the ::UARTCC26XX_Object.status field. The RX is then turned off
 *     and all bytes will be ignored until a new read is issued. Note that only
 *     the read is cancelled when the error occurs. If a write was active
 *     while the RX error occurred, it will complete.
 *   - If a RX break error occurs, an extra 0 byte will also be returned by the
 *     UARTCC26XX_read().
 *   .
 *
 * ## Power Management #
 *  The UARTCC26XX driver is setting a power constraint during operation to keep
 *  the device out of standby. When the operation has finished, the power
 *  constraint is released.
 *  The following statements are valid:
 *    - After UARTCC26XX_open(): the device is still allowed to enter standby.
 *    - During UARTCC26XX_read(): the device cannot enter standby.
 *    - After an RX error: device is allowed to enter standby.
 *    - After a successful UARTCC26XX_read(): the device is allowed
 *      to enter standby, but RX remains on.
 *        - _Note_: Device might enter standby while a byte is being
 *          received if UARTCC26XX_read() is not called again after a successful
 *          read. This could result in corrupt data being received.
 *        - Application thread should typically either issue another read after
 *          UARTCC26XX_read() completes successfully, or call
 *          UARTCC26XX_readCancel() to disable RX and thus assuring that no data
 *          is received while entering standby.
 *        .
 *    - During UARTCC26XX_write(): the device cannot enter standby.
 *    - After UARTCC26XX_write() succeeds: the device can enter standby.
 *    - If UARTCC26XX_writeCancel() is called: the device can enter standby.
 *
 * ## Supported Functions ##
 *  | API function             | Description                                       |
 *  |------------------------- |---------------------------------------------------|
 *  | UARTCC26XX_init()        | Initialize UART driver                            |
 *  | UARTCC26XX_open()        | Initialize UART HW and set system dependencies    |
 *  | UARTCC26XX_close()       | Disable UART HW and release system dependencies   |
 *  | UARTCC26XX_control()     | Configure an already opened UART handle           |
 *  | UARTCC26XX_read()        | Start read from UART                              |
 *  | UARTCC26XX_readCancel()  | Cancel ongoing read from UART                     |
 *  | UARTCC26XX_write()       | Start write to UART                               |
 *  | UARTCC26XX_writeCancel() | Cancel ongoing write to UART                      |
 *
 *  ## Not Supported Functionality #
 *  The CC26XX UART driver does not support:
 *    - ::UART_ECHO_ON
 *    - ::UART_DATA_TEXT
 *    - UART_readPolling()
 *    - UART_writePolling()
 *
 *  Functionality which will be supported in later releases:
 *    - Flow control
 *    - Configurable TX FIFO Threshold (currently set to 1/8 full, i.e. 4 bytes)
 *    - Configurable RX FIFO Threshold (currently set to 4/8 full, i.e. 16 bytes)
 *
 * ## Use Cases \anchor USE_CASES ##
 * ### Basic Receive #
 *  Receive 100 bytes over UART in ::UART_MODE_BLOCKING.
 *  @code
 *  UART_Handle handle;
 *  UART_Params params;
 *  uint8_t rxBuf[100];     // Receive buffer
 *
 *  // Init UART and specify non-default parameters
 *  UART_Params_init(&params);
 *  params.baudRate      = 9600;
 *  params.writeDataMode = UART_DATA_BINARY;
 *
 *  // Open the UART and do the read
 *  handle = UART_open(Board_UART, &params);
 *  int rxBytes = UART_read(handle, rxBuf, 100);
 *  @endcode
 *
 * ### Receive with Return Partial #
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
 *  UART_control(handle, UARTCC26XX_RETURN_PARTIAL_ENABLE, NULL);
 *  // Begin read
 *  int rxBytes = UART_read(handle, rxBuf, 100));
 *  @endcode
 *
 * ### Basic Transmit #
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
 * ### Receive Continously in ::UART_MODE_CALLBACK \anchor USE_CASE_CB #
 *  This case will configure the UART to receive continously in
 *  ::UART_MODE_CALLBACK, 16 bytes at the time and transmit them back via UART TX.
 *  @code
 *  #define MAX_NUM_RX_BYTES    1000   // Maximum RX bytes to receive in one go
 *
 *  uint32_t wantedRxBytes;            // Number of bytes received so far
 *  uint8_t rxBuf[MAX_NUM_RX_BYTES];   // Receive buffer
 *  uint8_t txBuf[MAX_NUM_RX_BYTES];   // Transmit buffer
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

/*! Return code when UART_control() was successful. */
#define UARTCC26XX_CMD_SUCCESS              0
/*! Return code when a UART command or function is undefined/not-implemented. */
#define UARTCC26XX_CMD_UNDEFINED            -1

/*! Enable RETURN_PARTIAL, used as cmd to UART_control() */
#define UARTCC26XX_RETURN_PARTIAL_ENABLE    0
/*! Disable RETURN_PARTIAL, used as cmd to UART_control() */
#define UARTCC26XX_RETURN_PARTIAL_DISABLE   1

#define UARTCC26XX_FIFO_SIZE 32

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
 *          UART0_BASE,
 *          INT_UART0
 *          PERIPH_UART0,
 *          1,
 *          2,
 *          3,
 *          4
 *      }
 *  };
 *  @endcode
 */
typedef struct UARTCC26XX_HWAttrs {
    unsigned long   baseAddr;    /*!< UART Peripheral's base address */
    int             intNum;      /*!< UART Peripheral's interrupt vector */
    unsigned long   powerMngrId; /*!< UART Peripheral's power manager ID */
    uint8_t         txPin;       /*!< UART TX pin */
    uint8_t         rxPin;       /*!< UART RX pin */
    uint8_t         ctsPin;      /*!< UART CTS pin */
    uint8_t         rtsPin;      /*!< UART RTS pin */
} UARTCC26XX_HWAttrs;

/*!
 *  @brief    UART status
 *
 *  The UART Status is used to flag the different Receive Errors.
 */
typedef enum UART_Status {
    UART_PARITY_ERROR  = UART_RXERROR_PARITY,  /*!< UART Parity error */
    UART_BRAKE_ERROR   = UART_RXERROR_BREAK,   /*!< UART Break error */
    UART_OVERRUN_ERROR = UART_RXERROR_OVERRUN, /*!< UART overrun error */
    UART_FRAMING_ERROR = UART_RXERROR_FRAMING, /*!< UART Framing error */
    UART_OK            = 0x0                   /*!< UART OK */
} UART_Status;

/*!
 *  @brief    UART RX FIFO threshold
 *
 *  Mapping of RX FIFO thresholds from level to number of bytes.
 */
typedef enum UART_RxFifoThreshold {
    UART_TH_FIFO_RX1_8 = 4,
    UART_TH_FIFO_RX2_8 = 8,
    UART_TH_FIFO_RX4_8 = 16,
    UART_TH_FIFO_RX6_8 = 24,
    UART_TH_FIFO_RX7_8 = 32
} UART_RxFifoThreshold;

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
    unsigned int        readTimeout;    /*!< Timeout for read semaphore */
    unsigned int        writeTimeout;   /*!< Timeout for write semaphore */
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
    /*! Threshold for generating RX IRQ */
    UART_RxFifoThreshold  readFifoThreshold;
    /*! Threshold for generating TX IRQ */
    uint8_t               writeFifoThreshold;

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

/*!
 *  @brief UART CC26XX initialization
 *
 *  @param handle  A UART_Handle
 *
 */
extern void         UARTCC26XX_init(UART_Handle handle);

/*!
 *  @brief  Function to initialize the CC26XX UART peripheral specified by the
 *          particular handle. The parameter specifies which mode the UART
 *          will operate.
 *
 *  The function will set a dependency on it power domain, i.e. power up the
 *  module and enable the clock. The IOs are allocated. Neither the RX nor TX
 *  will be enabled, and none of the interrupts are enabled.
 *
 *  @pre    UART controller has been initialized
 *
 *  @param  handle        A UART_Handle
 *
 *  @param  params        Pointer to a parameter block, if NULL it will use
 *                        default values
 *
 *  @return A UART_Handle on success or a NULL on an error or if it has been
 *          already opened
 *
 *  @sa     UARTCC26XX_close()
 */
extern UART_Handle  UARTCC26XX_open(UART_Handle handle, UART_Params *params);

/*!
 *  @brief  Function to close a given CC26XX UART peripheral specified by the
 *          UART handle.
 *
 *  Will disable the UART, disable all UART interrupts and release the
 *  dependency on the corresponding power domain.
 *
 *  @pre    UARTCC26XX_open() had to be called first.
 *
 *  @param  handle  A UART_Handle returned from UART_open()
 *
 *  @sa     UARTCC26XX_open
 */
extern void         UARTCC26XX_close(UART_Handle handle);

/*!
 *  @brief  Function for reading from UART interface.
 *
 *  The function will enable the RX, enable all RX interrupts and disallow
 *  chip from going into standby.
 *
 *  @pre    UARTCC26XX_open() has to be called first.
 *
 *  @param  handle A UART handle returned from UARTCC26XX_open()
 *
 *  @param  *buffer  Pointer to read buffer
 *
*  @param  size  Number of bytes to read. If ::UARTCC26XX_RETURN_PARTIAL_ENABLE
 *                has been set, the read will
 *                return if the reception is inactive for a 32-bit period
 *                (i.e. before all bytes are received).
 *
 *  @return Number of samples read
 *
 *  @sa     UARTCC26XX_open(), UARTCC26XX_readCancel()
 */
extern int       UARTCC26XX_read(UART_Handle handle, void *buffer, size_t size);

/*!
 *  @brief  Function for setting control parameters of the UART
 *          after it has been opened.
 *
 *  @pre    UARTCC26XX_open() has to be called first.
 *
 *  @param  handle A UART handle returned from UARTCC26XX_open()
 *
 *  @param  cmd  The command to execute, supported commands are:
 *              | Command                               | Description             |
 *              |-------------------------------------- |-------------------------|
 *              | ::UARTCC26XX_RETURN_PARTIAL_ENABLE    | Enable RETURN_PARTIAL   |
 *              | ::UARTCC26XX_RETURN_PARTIAL_DISABLE   | Disable RETURN_PARTIAL  |
 *
 *  @param  *arg  Pointer to command arguments, currently not in use, set to NULL.
 *
*  @return ::UARTCC26XX_CMD_SUCCESS if success, or error code if error.
 */
int          UARTCC26XX_control(UART_Handle handle, unsigned int cmd, void *arg);


/*!
 *  @brief Function that cancel UART read. Will disable all RX interrupt,
 *         disable
 *         RX and allow standby. Should also be called after a succeeding UART
 *         read if no more bytes are expected and standby is wanted.
 *
 *  @pre    UARTCC26XX_open() has to be called first.
 *
 *  @param handle         The UART_Handle for ongoing write.
 */
extern void         UARTCC26XX_readCancel(UART_Handle handle);

/*!
 *  @brief  Function that writes data to a UART
 *
 *  This function initiates an operation to write data to CC26XX UART
 *  controller.
 *
 *  In ::UART_MODE_BLOCKING, UART_write will block task execution until all
 *  the data in buffer has been written.
 *
 *  In ::UART_MODE_CALLBACK, UART_write does not block task execution, but calls a
 *  callback function specified by writeCallback when the data has been written.
 *
 *  When the write function is called, TX is enabled, TX interrupt is enabled,
 *  and standby is not allowed.
 *
 *  @pre    UARTCC26XX_open() has to be called first.
 *
 *  @param  handle      A UART_Handle returned from UARTCC26XX_open()
 *
 *  @param  buffer      A pointer to buffer containing data to be written
 *
 *  @param  size        The number of bytes in buffer that should be written
 *                      onto the UART.
 *
 *  @return Returns the number of bytes that have been written to the UART,
 *          UART_ERROR on an error.
 *
 */
extern int          UARTCC26XX_write(UART_Handle handle, const void *buffer,
                            size_t size);

/*!
 *  @brief Function that cancel UART write. Will disable TX interrupt, disable
 *         TX and allow standby.
 *
 *  @pre    UARTCC26XX_open() and has to be called first.
 *
 *  @param handle         The UART_Handle for ongoing write.
 */
extern void         UARTCC26XX_writeCancel(UART_Handle handle);

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTCC26XX__include */
