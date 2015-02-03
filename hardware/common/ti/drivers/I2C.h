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
 *  @file       I2C.h
 *
 *  @brief      I2C driver interface
 *
 *  The I2C header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/I2C.h>
 *  @endcode
 *
 *  # Operation #
 *  The I2C driver operates as a master on a single-master I2C bus in either
 *  I2C_MODE_BLOCKING or I2C_MODE_CALLBACK.
 *  In blocking mode, the task's execution is blocked during the I2C
 *  transaction. When the transfer has completed, code execution will resume.
 *  In callback mode, the task's execution is not blocked, allowing for other
 *  transactions to be queued up or to process some other code. When the
 *  transfer has completed, the I2C driver will call a user-specified callback
 *  function (from a HWI context).
 *
 *  The APIs in this driver serve as an interface to a typical TI-RTOS
 *  application. The specific peripheral implementations are responsible to
 *  create all the SYS/BIOS specific primitives to allow for thread-safe
 *  operation.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  I2C_Handle      handle;
 *  I2C_Params      params;
 *  I2C_Transaction i2cTransaction;
 *
 *  I2C_Params_init(&params);
 *  params.transferMode  = I2C_MODE_CALLBACK;
 *  params.transferCallbackFxn = someI2CCallbackFunction;
 *  handle = I2C_open(someI2C_configIndexValue, &params);
 *  if (!handle) {
 *      System_printf("I2C did not open");
 *  }
 *  @endcode
 *
 *  ## Transferring data #
 *  A I2C transaction with a I2C peripheral is started by calling
 *  I2C_transfer(). The details of the I2C transaction is specified with a
 *  I2C_Transaction data structure. This structure allows for any of the three
 *  types of transactions: Write, Read, or Write/Read. Each transfer is
 *  performed atomically with the I2C slave peripheral.
 *
 *  @code
 *  I2C_Transaction i2cTransaction;
 *
 *  i2cTransaction.writeBuf = someWriteBuffer;
 *  i2cTransaction.writeCount = numOfBytesToWrite;
 *
 *  i2cTransaction.readBuf = someReadBuffer;
 *  i2cTransaction.readCount = numOfBytesToRead;
 *
 *  i2cTransaction.slaveAddress = some7BitI2CSlaveAddress;
 *
 *  ret = I2C_transfer(handle, &i2cTransaction);
 *  if (!ret) {
 *      System_printf("Unsuccessful I2C transfer");
 *  }
 *  @endcode
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  I2C_FxnTable.
 *
 *  The I2C driver interface module is joined (at link time) to a
 *  NULL-terminated array of I2C_Config data structures named *I2C_config*.
 *  *I2C_config* is implemented in the application with each entry being an
 *  instance of a I2C peripheral. Each entry in *I2C_config* contains a:
 *  - (I2C_FxnTable *) to a set of functions that implement a I2C peripheral
 *  - (void *) data object that is associated with the I2C_FxnTable
 *  - (void *) hardware attributes that are associated to the I2C_FxnTable
 *
 *  Currently the following I2C peripheral implementations are supported:
 *  - @ref I2CCC26XX.h
 *  - @ref I2CCC3200.h
 *  - @ref I2CEUSCIB.h
 *  - @ref I2CTiva.h
 *  - @ref I2CUSCIB.h
 *
 *  # Instrumentation #
 *  The I2C driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic I2C operations performed |
 *  Diags_USER2      | detailed I2C operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_I2C__include
#define ti_drivers_I2C__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <xdc/std.h>

/*!
 *  @brief      A handle that is returned from a I2C_open() call.
 */
typedef struct I2C_Config      *I2C_Handle;

/*!
 *  @brief  I2C transaction
 *
 *  This structure defines the nature of the I2C transaction. This structure
 *  specifies the buffer and buffer's size that is to be written to or read from
 *  the I2C slave peripheral.
 *  arg is an optional user supplied argument that will be passed
 *  to the callback function when the I2C driver is in I2C_MODE_CALLBACK.
 *  nextPtr is to be only used by the I2C driver.
 */
typedef struct I2C_Transaction {

    uint8_t   *writeBuf;    /*!< void * to a buffer containing data to be written to */
    size_t     writeCount;  /*!< Number of bytes to be written to the slave */

    uint8_t   *readBuf;     /*!< void * to a buffer to which data is to be read into */
    size_t     readCount;   /*!< Number of bytes to be read from the slave */

    uint8_t    slaveAddress;/*!< Address of the I2C slave device */

    void      *arg;         /*!< argument to be passed to the callback function */
    void      *nextPtr;     /*!< Driver uses this for queuing in I2C_MODE_CALLBACK */
} I2C_Transaction;

/*!
 *  @brief  I2C mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2C_Mode {
    I2C_IDLE_MODE = 0,  /* I2C is not performing a transaction */
    I2C_WRITE_MODE,     /* I2C is currently performing write operations */
    I2C_READ_MODE,      /* I2C is currently performing read operations */
    I2C_ERROR = 0xFF    /* I2C error has occurred, exit gracefully */
} I2C_Mode;

/*!
 *  @brief  I2C transfer mode
 *
 *  I2C_MODE_BLOCKING block task execution while a I2C transfer is in progress
 *  I2C_MODE_CALLBACK does not block task execution; but calls a callback
 *  function when the I2C transfer has completed
 */
typedef enum I2C_TransferMode {
    I2C_MODE_BLOCKING,  /*!< I2C_transfer blocks execution*/
    I2C_MODE_CALLBACK   /*!< I2C_transfer queues transactions and does not block */
} I2C_TransferMode;

/*!
 *  @brief  I2C callback function
 *
 *  User definable callback function prototype. The I2C driver will call the
 *  defined function and pass in the I2C driver's handle, the pointer to the I2C
 *  transaction that just completed, and the return value of I2C_transfer.
 *
 *  @param  I2C_Handle          I2C_Handle

 *  @param  I2C_Transaction*    Address of the I2C_Transaction performed

 *  @param  bool                Results of the I2C transaction
 */
typedef void (*I2C_CallbackFxn)(I2C_Handle, I2C_Transaction *, bool);

/*!
 *  @brief  I2C bitRate
 *
 *  Specify one of the standardized I2C bus bit rates for I2C communications.
 *  The default is I2C_100kHz.
 */
typedef enum I2C_BitRate {
    I2C_100kHz = 0,
    I2C_400kHz = 1
} I2C_BitRate;

/*!
 *  @brief  I2C Parameters
 *
 *  If I2C_TransferMode is set to I2C_MODE_BLOCKING then I2C_transfer function
 *  calls will block thread execution until the transaction has completed.
 *
 *  If I2C_TransferMode is set to I2C_MODE_CALLBACK then I2C_transfer will not
 *  block thread execution and it will call the function specified by
 *  transferCallbackFxn. Sequential calls to I2C_transfer in I2C_MODE_CALLBACK
 *  mode will put the designated transaction onto an internal queue that
 *  automatically starts queued transactions after the previous transaction has
 *  completed. (regardless of error state).
 *
 *  I2C_BitRate specifies the I2C bus rate used for I2C communications.
 */
typedef struct I2C_Params {
    I2C_TransferMode    transferMode; /*!< Blocking or Callback mode */
    I2C_CallbackFxn     transferCallbackFxn; /*!< Callback function pointer */
    I2C_BitRate         bitRate; /*!< I2C bus bit rate */
    void               *custom;  /*!< Custom argument used by driver
                                      implementation */
} I2C_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_close().
 */
typedef void        (*I2C_CloseFxn)    (I2C_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_control().
 */
typedef int         (*I2C_ControlFxn)  (I2C_Handle handle,
                                        unsigned int cmd,
                                        void *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_init().
 */
typedef void        (*I2C_InitFxn)     (I2C_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_open().
 */
typedef I2C_Handle  (*I2C_OpenFxn)     (I2C_Handle handle,
                                        I2C_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_transfer().
 */
typedef bool        (*I2C_TransferFxn) (I2C_Handle handle,
                                        I2C_Transaction *transaction);

/*!
 *  @brief      The definition of a I2C function table that contains the
 *              required set of functions to control a specific I2C driver
 *              implementation.
 */
typedef struct I2C_FxnTable {
    /*! Function to close the specified peripheral */
    I2C_CloseFxn        closeFxn;

    /*! Function to implementation specific control function */
    I2C_ControlFxn      controlFxn;

    /*! Function to initialize the given data object */
    I2C_InitFxn         initFxn;

    /*! Function to open the specified peripheral */
    I2C_OpenFxn         openFxn;

    /*! Function to initiate a I2C data transfer */
    I2C_TransferFxn     transferFxn;
} I2C_FxnTable;

/*!
 *  @brief
 *  The I2C_Config structure contains a set of pointers used to characterize
 *  the I2C driver implementation.
 */
typedef struct I2C_Config {
    /*! Pointer to a table of a driver-specific implementation of I2C functions */
    I2C_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void               *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void         const *hwAttrs;
} I2C_Config;


/*!
 *  @brief  Function to closes a given I2C peripheral specified by the I2C
 *  handle.
 *
 *  @pre    I2C_open() had to be called first.
 *
 *  @param  handle  A I2C_Handle returned from I2C_open
 *
 *  @sa     I2C_open
 */
extern void I2C_close(I2C_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          I2C_Handle.
 *
 *  @pre    I2C_open() has to be called first.
 *
 *  @param  handle A I2C handle returned from I2C_open()
 *
 *  @param  cmd    A command value defined by the driver specific implementation
 *
 *  @param  arg    An optional argument that is accompanied with cmd
 *
 *  @return Implementation specific return codes. Negative values indicate
 *          unsuccessful operations.
 *
 *  @sa     I2C_open()
 */
extern int I2C_control(I2C_Handle handle, unsigned int cmd, void *arg);

/*!
 *  @brief  Function to initializes the I2C module
 *
 *  @pre    The I2C controller needs to be powered up and clocked. The
 *          I2C_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other I2C driver APIs.
 */
extern void I2C_init(void);

/*!
 *  @brief  Function to initialize a given I2C peripheral specified by the
 *          particular index value. The parameter specifies which mode the I2C
 *          will operate.
 *
 *  @pre    I2C controller has been initialized
 *
 *  @param  index         Logical peripheral number indexed into the HWAttrs
 *                        table
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values
 *
 *  @return A I2C_Handle on success or a NULL on an error or if it has been
 *          already opened
 *
 *  @sa     I2C_close
 */
extern I2C_Handle I2C_open(unsigned int index, I2C_Params *params);

/*!
 *  @brief  Function to initialize the I2C_Params struct to its defaults
 *
 *  Defaults values are:
 *  transferMode = I2C_MODE_BLOCKING
 *  transferCallbackFxn = NULL
 *  bitRate = I2C_100kHz
 *
 *  @param  params  Parameter structure to initialize
 */
extern void I2C_Params_init(I2C_Params *params);

/*!
 *  @brief  Function that handles the I2C transfer for SYS/BIOS
 *
 *  This function will start a I2C transfer and can only be called from a Task
 *  context when in I2C_MODE_BLOCKING.
 *  The I2C transfer procedure starts with evaluating how many bytes are to be
 *  written and how many are to be read from the I2C peripheral. Due to common
 *  I2C data transfer processes, to be written will always sent before any data
 *  is read.
 *
 *  The data written to the peripheral is preceded with the peripheral's 7-bit
 *  I2C slave address (with the Write bit set).
 *  After all the data has been transmitted, the driver will evaluate if any
 *  data needs to be read from the device.
 *  If so, a Re-START bit is sent, along with the same 7-bit I2C slave address
 *  (with the Read bit). Else, the transfer is concluded with a STOP bit.
 *  After the specified number of bytes have been read by the I2C, the transfer
 *  is ended with a NACK and STOP bit.
 *
 *  In I2C_MODE_BLOCKING, I2C_transfer will block task execution until the
 *  transaction has completed.
 *
 *  In I2C_MODE_CALLBACK, I2C_transfer does not block task execution and calls a
 *  callback function specified by transferCallbackFxn. If a transfer is already
 *  taking place, the transaction is put on an internal queue. The queue is
 *  serviced in a first come first served basis.
 *  The I2C_Transaction structure must stay persistent until the I2C_transfer
 *  function has completed!
 *
 *  @param  handle      A I2C_Handle
 *
 *  @param  transaction A pointer to a I2C_Transaction
 *
 *  @return true on successful transfer
 *          false on an error, such as a I2C bus fault
 *
 *  @sa     I2C_open
 */
extern bool I2C_transfer(I2C_Handle handle, I2C_Transaction *transaction);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_I2C__include */
