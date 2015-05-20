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
 *  @file       I2CMSP432.h
 *
 *  @brief      I2C driver implementation for the EUSCI controller on MSP432
 *
 *  This I2C driver implementation is designed to operate on a EUCSI controller
 *  in I2C mode.  The I2CMSP432 header file should be included in an application
 *  as follows:
 *  @code
 *  #include <ti/drivers/I2C.h>
 *  #include <ti/drivers/I2CMSP432.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_i2c_I2CMSP432__include
#define ti_drivers_i2c_I2CMSP432__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include <ti/drivers/I2C.h>
#include <ti/drivers/ports/HwiP.h>
#include <ti/drivers/ports/SemaphoreP.h>
#include <ti/drivers/Power.h>

/* I2C function table pointer */
extern const I2C_FxnTable I2CMSP432_fxnTable;

/*!
 *  @brief  I2CMSP432 mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2CMSP432_Mode {
    I2CMSP432_IDLE_MODE = 0,  /* I2C is not performing a transaction */
    I2CMSP432_WRITE_MODE,     /* I2C is currently performing write operations */
    I2CMSP432_READ_MODE,      /* I2C is currently performing read operations */
    I2CMSP432_ERROR = 0xFF    /* I2C error has occurred, exit gracefully */
} I2CMSP432_Mode;

/*!
 *  @brief  I2CMSP432 Hardware attributes
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - i2c.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const I2CMSP432_HWAttrs i2cMSP432HWAttrs[] = {
 *      {
 *          .baseAddr = EUSCI_B0_BASE,
 *          .intNum = INT_EUSCIB0,
 *          .intPriority = ~0,
 *          .clockSource = EUSCI_B_I2C_CLOCKSOURCE_SMCLK
 *      }
 *  };
 *  @endcode
 */
typedef struct I2CMSP432_HWAttrs {
    uint32_t baseAddr;       /*! EUSCI_B_I2C Peripheral's base address */
    uint32_t intNum;         /*! EUSCI_B_I2C Peripheral's interrupt vector */
    uint32_t intPriority;    /*! EUSCI_B_I2C Peripheral's interrupt priority */
    uint8_t  clockSource;    /*! EUSCI_B_I2C Clock source */
} I2CMSP432_HWAttrs;

/*!
 *  @brief  I2CMSP432 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2CMSP432_Object {
    SemaphoreP_Handle mutex;                /* Grants exclusive access to I2C */
    SemaphoreP_Handle transferComplete;     /* Notify finished I2C transfer */

    HwiP_Handle       hwiHandle;

    I2C_Transaction  *currentTransaction;   /* Ptr to current I2C transaction */
    I2C_CallbackFxn   transferCallbackFxn;  /* Callback function pointer */

    /* I2C transaction pointers for I2C_MODE_CALLBACK */
    I2C_Transaction  *headPtr;              /* Head ptr for queued transactions */
    I2C_Transaction  *tailPtr;              /* Tail ptr for queued transactions */

    uint8_t          *writeBufIdx;          /* Internal inc. writeBuf index */
    size_t            writeCountIdx;        /* Internal dec. writeCounter */

    uint8_t          *readBufIdx;           /* Internal inc. readBuf index */
    size_t            readCountIdx;         /* Internal dec. readCounter */

    Power_NotifyObj   perfChangeNotify;
    uint32_t          perfConstraintMask;

    volatile I2CMSP432_Mode mode;           /* Stores the I2C state */
    I2C_TransferMode  transferMode;         /* Blocking or Callback mode */
    I2C_BitRate       bitRate;              /* SPI bit rate in Hz */
    bool              isOpen;               /* To determine if the SPI is open */
} I2CMSP432_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_i2c_I2CMSP432__include */
