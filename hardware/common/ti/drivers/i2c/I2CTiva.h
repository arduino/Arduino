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
 *  @file       I2CTiva.h
 *
 *  @brief      I2C driver implementation for a Tiva I2C controller.
 *
 *  The I2C header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/I2C.h>
 *  #include <ti/drivers/i2c/I2CTiva.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_i2c_I2CTiva__include
#define ti_drivers_i2c_I2CTiva__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/I2C.h>

#include <ti/sysbios/knl/Semaphore.h>
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>

/* I2C function table pointer */
extern const I2C_FxnTable I2CTiva_fxnTable;

/*!
 *  @brief  I2CTiva mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2CTiva_Mode {
    I2CTiva_IDLE_MODE = 0,  /* I2C is not performing a transaction */
    I2CTiva_WRITE_MODE,     /* I2C is currently performing write operations */
    I2CTiva_READ_MODE,      /* I2C is currently performing read operations */
    I2CTiva_ERROR = 0xFF    /* I2C error has occurred, exit gracefully */
} I2CTiva_Mode;

/*!
 *  @brief  I2CTiva Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For TivaWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const I2CTiva_HWAttrs i2cTivaHWAttrs[] = {
 *      {
 *          I2C1_BASE,
 *          INT_I2C1,
 *          ~0               // Interrupt priority
 *      },
 *      {
 *          I2C3_BASE,
 *          INT_I2C3,
 *          ~0               // Interrupt priority
 *      },
 *  };
 *  @endcode
 */
typedef struct I2CTiva_HWAttrs {
    /*! I2C Peripheral's base address */
    unsigned int baseAddr;
    /*! I2C Peripheral's interrupt vector */
    unsigned int intNum;
    /*! I2C Peripheral's interrupt priority */
    unsigned int intPriority;
} I2CTiva_HWAttrs;

/*!
 *  @brief  I2CTiva Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2CTiva_Object {
    Semaphore_Struct    mutex;            /* Grants exclusive access to I2C */
    Semaphore_Struct    transferComplete; /* Notify finished I2C transfer */

    I2C_TransferMode    transferMode;        /* Blocking or Callback mode */
    I2C_CallbackFxn     transferCallbackFxn; /* Callback function pointer */

    ti_sysbios_family_arm_m3_Hwi_Struct hwi;  /* Hwi object handle */

    volatile I2CTiva_Mode mode;         /* Stores the I2C state */

    I2C_Transaction    *currentTransaction; /* Pointer to current I2C transaction */

    uint8_t            *writeBufIdx;    /* Internal inc. writeBuf index */
    size_t              writeCountIdx;  /* Internal dec. writeCounter */

    uint8_t            *readBufIdx;     /* Internal inc. readBuf index */
    size_t              readCountIdx;   /* Internal dec. readCounter */

    /* I2C transaction pointers for I2C_MODE_CALLBACK */
    I2C_Transaction    *headPtr;        /* Head ptr for queued transactions */
    I2C_Transaction    *tailPtr;        /* Tail ptr for queued transactions */

    bool                isOpen;         /* flag to indicate module is open */
} I2CTiva_Object;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_i2c_I2CTiva__include */
