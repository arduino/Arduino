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
 *  @file       I2CCC26XX.h
 *
 *  @brief      I2C driver implementation for a CC26XX I2C controller.
 *
 *  # Driver Include #
 *  The I2C header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/I2C.h>
 *  #include <ti/drivers/i2c/I2CCC26XX.h>
 *  @endcode
 *
 * # Overview #
 * The general I2C API is normally used in application code, e.g. I2C_open()
 * is used instead of I2CCC26XX_open(). The board file will define the device
 * specific config, and casting in the general API will ensure that the correct
 * device specific functions are called.
 * This is also reflected in the example code in [Use Cases](@ref I2C_USE_CASES).
 *
 * ## General Behavior #
 * Before using the I2C in CC26XX:
 *   - The I2C driver is initialized by calling I2C_init().
 *   - The I2C HW is configured and flags system dependencies (e.g. IOs,
 *     power, etc.) by calling I2C_open().
 *   .
 * The following is true for receive operation:
 *   - RX is enabled by calling I2C_transfer().
 *     The readCount of the ::I2C_Transaction must be set to a non-zero value.
 *   - If the I2C_transfer() succeeds, the I2C remains enabled.
 *   - The application must check the return value from I2C_transfer()
 *     to verify that the transfer succeeded.
 *   .
 * The following apply for transmit operation:
 *   - TX is enabled by calling I2C_transfer().
 *     The writeCount of the ::I2C_Transaction must be set to a non-zero value.
 *   - If the I2C_transfer() succeeds, the I2C remains enabled.
 *   - The application must check the return value from I2C_transfer()
 *     to verify that the transfer succeeded.
 *   .
 * After I2C operation has ended:
 *   - Release system dependencies for I2C by calling I2C_close().
 *
 * ## Error handling #
 * If an error occurs during operation:
 *   - The I2C Master transmits a stop bit and remains enabled.
 *   .
 *
 * ## Power Management #
 *  The I2CCC26XX driver is setting a power constraint during operation to keep
 *  the device out of standby, i.e. device will enter idle mode when no tasks
 *  are active. When the operation has finished, the power
 *  constraint is released.
 *  The following statements are valid:
 *    - After I2C_open() call: I2C is enabled, there is no active I2C
 *      transactions, the device can enter standby.
 *    - After I2C_transfer() call: active I2C transactions exist , the device
 *      might enter idle, not standby (set constraint).
 *    - If I2C_transfer() returns successfully or with error: I2C remains enabled,
 *      but device can enter standby.
 *    - After I2C_close() call: I2C is disabled
 *
 * ## Supported Functions ##
 *  | Generic API Function | API Function             | Description                                       |
 *  |--------------------- |------------------------- |---------------------------------------------------|
 *  | I2C_init()           | I2CCC26XX_init()         | Initialize I2C driver                             |
 *  | I2C_open()           | I2CCC26XX_open()         | Initialize I2C HW and set system dependencies     |
 *  | I2C_close()          | I2CCC26XX_close()        | Disable I2C HW and release system dependencies    |
 *  | I2C_transfer()       | I2CCC26XX_transfer()     | Start I2C transfer                                |
 *
 *  @note All calls should go through the generic API.
 *
 *  ## Unsupported Functionality #
 *  The CC26XX I2C driver currently does not support:
 *    - Multi-master mode
 *    - I2C slave mode
 *
 * ## Use Cases \anchor I2C_USE_CASES ##
 * ### Basic Receive #
 *  Receive 10 bytes over I2C in ::I2C_MODE_BLOCKING.
 *  @code
 *  // Locals
 *  I2C_Handle handle;
 *  I2C_Params params;
 *  I2C_Transaction i2cTrans;
 *  uint8_t rxBuf[32];      // Receive buffer
 *  uint8_t txBuf[32];      // Transmit buffer
 *
 *  // Configure I2C parameters.
 *  I2C_Params_init(&params);
 *
 *  // Initialize master I2C transaction structure
 *  i2cTrans.writeCount   = 0;
 *  i2cTrans.writeBuf     = txBuf;
 *  i2cTrans.readCount    = 10;
 *  i2cTrans.readBuf      = rxBuf;
 *  i2cTrans.slaveAddress = 0x3C;
 *
 *  // Open I2C
 *  handle = I2C_open(Board_I2C, &params);
 *
 *  // Do I2C transfer receive
 *  I2C_transfer(handle, &i2cTrans);
 *  @endcode
 *
 * ### Basic Transmit #
 *  Transmit 16 bytes over I2C in ::I2C_MODE_CALLBACK.
 *  @code
 *  uint8_t rxBuffer[32];            // Receive buffer
 *  uint8_t txBuffer[32];            // Transmit buffer
 *  bool transferDone = false;
 *
 *  static void transferCallback(I2C_Handle handle, I2C_Transaction *transac, bool result)
 *  {
 *      // Set length bytes
 *      if (result) {
 *          transferDone = true;
 *      } else {
 *          // Transaction failed, act accordingly...
 *          .
 *          .
 *      }
 *  }
 *
 *  static void taskFxn(UArg a0, UArg a1)
 *  {
 *      // Locals
 *      I2C_Handle handle;
 *      I2C_Params params;
 *      I2C_Transaction i2cTrans;
 *
 *      // Configure I2C parameters.
 *      I2C_Params_init(&params);
 *      params.transferMode = I2C_MODE_CALLBACK;
 *      params.transferCallbackFxn = transferCallback;
 *
 *      // Prepare data to send, send 0x00, 0x01, 0x02, ...0xFF, 0x00, 0x01...
 *      for(uint32_t i = 0; i < numTxBytes; i++)
 *          txBuffer[i] = (uint8_t) i;
 *
 *      // Initialize master I2C transaction structure
 *      i2cTrans.writeCount   = 16;
 *      i2cTrans.writeBuf     = txBuffer;
 *      i2cTrans.readCount    = 0;
 *      i2cTrans.readBuf      = rxBuffer;
 *      i2cTrans.slaveAddress = 0x3C;
 *
 *      // Open I2C
 *      handle = I2C_open(Board_I2C, &params);
 *
 *      // Do I2C transfer (in callback mode)
 *      I2C_transfer(handle, &i2cTrans);
 *
 *      // Do other stuff while I2C is handling the transfer
 *      .
 *      .
 *
 *      // Do something if I2C transfer is finished
 *      if(transferDone) {
 *          .
 *          .
 *      }
 *
 *      // Continue...
 *      .
 *      .
 *  }
 *  @endcode
 *
 * ### Chained Transactions #
 *  Transmit 10 bytes and then 32 bytes over I2C in ::I2C_MODE_CALLBACK.
 *  @code
 *  uint8_t rxBuffer[32];            // Receive buffer
 *  uint8_t txBuffer[32];            // Transmit buffer
 *  uint8_t rxBuffer2[64];           // 2. Receive buffer
 *  uint8_t txBuffer2[64];           // 2. Transmit buffer
 *  bool transferDone = false;
 *
 *  static void writeCallbackDefault(I2C_Handle handle, I2C_Transaction *transac, bool result)
 *  {
 *      // Set length bytes
 *      if (result) {
 *          transferDone = true;
 *      } else {
 *          // Transaction failed, act accordingly...
 *          .
 *          .
 *      }
 *  }
 *
 *  static void taskFxn(UArg a0, UArg a1)
 *  {
 *      // Locals
 *      I2C_Handle handle;
 *      I2C_Params params;
 *      I2C_Transaction i2cTrans;
 *      I2C_Transaction i2cTrans2;
 *
 *      // Configure I2C parameters.
 *      I2C_Params_init(&params);
 *      params.transferMode = I2C_MODE_CALLBACK;
 *      params.transferCallbackFxn = writeCallbackDefault;
 *
 *      // Prepare data to send, send 0x00, 0x01, 0x02, ...0xFF, 0x00, 0x01...
 *      for(uint32_t i = 0; i < numTxBytes; i++)
 *          txBuffer[i] = (uint8_t) i;
 *
 *      // Initialize first master I2C transaction structure
 *      i2cTrans.writeCount   = 10;
 *      i2cTrans.writeBuf     = txBuffer;
 *      i2cTrans.readCount    = 0;
 *      i2cTrans.readBuf      = rxBuffer;
 *      i2cTrans.slaveAddress = 0x3C;
 *
 *      // Second transaction
 *      i2cTrans2.writeCount   = 32;
 *      i2cTrans2.writeBuf     = txBuffer2;
 *      i2cTrans2.readCount    = 0;
 *      i2cTrans2.readBuf      = rxBuffer2;
 *      i2cTrans2.slaveAddress = 0x2E;
 *
 *      // Open I2C
 *      handle = I2C_open(Board_I2C, &params);
 *
 *      // Do chained I2C transfers (in callback mode).
 *      I2C_transfer(handle, &i2cTrans);
 *      I2C_transfer(handle, &i2cTrans2);
 *
 *      // Do other stuff while I2C is handling the transfers
 *      .
 *      .
 *
 *      // Do something if I2C transfers are finished
 *      if(transferDone) {
 *          .
 *          .
 *      }
 *
 *      // Continue...
 *      .
 *      .
 *  }
 *  @endcode
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

#ifndef ti_drivers_i2c_I2CCC26XX__include
#define ti_drivers_i2c_I2CCC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/I2C.h>
#include <ti/sysbios/family/arm/cc26xx/Power.h>

#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>

/*! I2C Base Address type.*/
typedef unsigned long   I2CBaseAddrType;
/*! @internal I2C Data type.*/
typedef unsigned long   I2CDataType;

/*! @internal @brief I2C function table pointer */
extern const I2C_FxnTable I2CCC26XX_fxnTable;

/*!
 *  @brief  I2CCC26XX Pin Configuration
 *
 *  Pin configuration that holds non-default pins. The default pin configuration
 *  is typically defined in ::I2CCC26XX_HWAttrs placed in the board file.
 *  The pin configuration structure is used by setting the custom void
 *  pointer in the ::I2C_Params to point to this struct. If the custom
 *  void pointer is NULL, the ::I2CCC26XX_HWAttrs pin mapping will be used.
 *  @code
 *  I2C_Handle handle;
 *  I2C_Params i2cParams;
 *  I2CCC26XX_I2CPinCfg pinCfg;
 *
 *  I2C_Params_init(&i2cParams);     // sets custom to NULL
 *  pinCfg.pinSDA = Board_I2C0_SDA1;
 *  pinCfg.pinSCL = Board_I2C0_SCL1;
 *  i2cParams.custom = &pinCfg;
 *
 *  handle = I2C_open(Board_I2C, &i2cParams);
 *  @endcode
 */
typedef struct I2CCC26XX_I2CPinCfg {
    uint8_t pinSDA;
    uint8_t pinSCL;
} I2CCC26XX_I2CPinCfg;

/*!
 *  @brief  I2CCC26XX mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2CCC26XX_Mode {
    I2CCC26XX_IDLE_MODE = 0,  /* I2C is not performing a transaction */
    I2CCC26XX_WRITE_MODE,     /* I2C is currently performing write operations */
    I2CCC26XX_READ_MODE,      /* I2C is currently performing read operations */
    I2CCC26XX_ERROR = 0xFF    /* I2C error has occurred, exit gracefully */
} I2CCC26XX_Mode;

/*!
 *  @brief  I2CCC26XX Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For cc26xxware these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const I2CCC26XX_HWAttrs i2cCC26XXHWAttrs[] = {
 *      {
 *         .baseAddr = I2C0_BASE,
 *         .intNum = INT_I2C,
 *         .powerMngrId = PERIPH_I2C0,
 *         .sdaPin = Board_I2C_SDA,
 *         .sclPin = Board_I2C_SCL,
 *      },
 *  };
 *  @endcode
 */
typedef struct I2CCC26XX_HWAttrs {
    /*! I2C Peripheral's base address */
    I2CBaseAddrType     baseAddr;
    /*! I2C Peripheral's interrupt vector */
    int                 intNum;
    /*! I2C Peripheral's power manager ID */
    unsigned long       powerMngrId;
    /*! I2C SDA pin mapping */
    uint8_t             sdaPin;
    /*! I2C SCL pin mapping */
    uint8_t             sclPin;
} I2CCC26XX_HWAttrs;

/*!
 *  @brief  I2CCC26XX Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2CCC26XX_Object {
    /* I2C control variables */
    I2C_TransferMode    transferMode;        /*!< Blocking or Callback mode */
    I2C_CallbackFxn     transferCallbackFxn; /*!< Callback function pointer */
    volatile I2CCC26XX_Mode mode;            /*!< Stores the I2C state */
    uint32_t            bitRate;             /*!< Bitrate of the I2C module */

    /* I2C SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;/*!< Hwi object handle */
    Semaphore_Struct    mutex;              /*!< Grants exclusive access to I2C */
    Semaphore_Struct    transferComplete;   /*!< Notify finished I2C transfer */

    /* I2C current transaction */
    I2C_Transaction     *currentTransaction; /*!< Ptr to current I2C transaction */
    uint8_t             *writeBufIdx;        /*!< Internal inc. writeBuf index */
    unsigned int        writeCountIdx;       /*!< Internal dec. writeCounter */
    uint8_t             *readBufIdx;         /*!< Internal inc. readBuf index */
    unsigned int        readCountIdx;        /*!< Internal dec. readCounter */

    /* I2C transaction pointers for I2C_MODE_CALLBACK */
    I2C_Transaction     *headPtr;            /*!< Head ptr for queued transactions */
    I2C_Transaction     *tailPtr;            /*!< Tail ptr for queued transactions */

    /* I2C power notification */
    void                *i2cPostFxn;        /*!< I2C post-notification Function pointer */
    Power_NotifyObj     i2cPostObj;         /*!< I2C post-notification object */

    bool                isOpen;             /*!< flag to indicate module is open */
} I2CCC26XX_Object;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_i2c_I2CCC26XX__include */
