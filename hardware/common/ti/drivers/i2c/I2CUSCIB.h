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
 *  @file       I2CUSCIB.h
 *
 *  @brief      I2CUSCIB driver implementation for a USCIB controller
 *
 *  The I2CUSCIB header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/I2C.h>
 *  #include <ti/drivers/I2CUSCIB.h>
 *  @endcode
 *
 *  This I2C driver implementation is designed to operate on a UCSI controller
 *  in I2C mode.
 *
 *  ## Interrupts #
 *  This driver is interrupt driven. For MSP430 devices, it requires the user to
 *  statically (.cfg) create a Hwi for the accocated USCI controller and have it
 *  call the I2CUSCIB's Hwi interrupt function I2CUSCIB_hwiIntFxn().
 *
 *  The following information is needed to create the Hwi:
 *   -# Interrupt vector\n
 *      The interrupt vector number can be found in a given MSP430 device
 *      specific header file (e.g. msp430f5529.h).
 *   -# Hwi function pointer\n
 *      Call I2CUSCIB_hwiIntFxn()
 *   -# Hwi function argument\n
 *      This argument to the Hwi indexes into the I2C_config[] data structure.
 *      Ensure you are indexing into the I2C_config[] element that uses a
 *      ::I2CUSCIB_fxnTable pointer.
 *
 *  @code
 *  // Statically create a I2CUSCIB Hwi in the .cfg file
 *  var hwi0Params = new Hwi.Params();
 *  hwi0Params.instance.name = "hwi0";
 *  hwi0Params.arg = 0;  // I2C_config[0];
 *  Program.global.hwi0 = Hwi.create(45, "&I2CUSCIB_hwiIntFxn", hwi0Params);
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_i2c_I2CUSCIB__include
#define ti_drivers_i2c_I2CUSCIB__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/I2C.h>

#include <ti/sysbios/knl/Semaphore.h>

/* I2C function table pointer */
extern const I2C_FxnTable I2CUSCIB_fxnTable;

/*!
 *  @brief  I2CUSCIB mode
 *
 *  This enum defines the state of the I2C driver's state-machine. Do not
 *  modify.
 */
typedef enum I2CUSCIB_Mode {
    I2CUSCIB_IDLE_MODE = 0,  /* I2C is not performing a transaction */
    I2CUSCIB_WRITE_MODE,     /* I2C is currently performing write operations */
    I2CUSCIB_READ_MODE,      /* I2C is currently performing read operations */
    I2CUSCIB_ERROR = 0xFF    /* I2C error has occurred, exit gracefully */
} I2CUSCIB_Mode;

/*!
 *  @brief  I2CUSCIB Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For MSP430Ware these definitions are found in:
 *      - inc/hw_memmap.h
 *      - usci_b_i2c.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const I2CUSCIB_HWAttrs i2cUSCIBHWAttrs[] = {
 *      {
 *          USCI_B0_BASE,
 *          USCI_B_SPI_CLOCKSOURCE_SMCLK
 *      },
 *      {
 *          USCI_B1_BASE,
 *          USCI_B_SPI_CLOCKSOURCE_SMCLK
 *      },
 *  };
 *  @endcode
 */
typedef struct I2CUSCIB_HWAttrs {
    /*! USCI_B_I2C Peripheral's base address */
    uint32_t    baseAddr;
    /*! USCI_B_I2C Clock source */
    uint8_t     clockSource;
} I2CUSCIB_HWAttrs;

/*!
 *  @brief  I2CUSCIB Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct I2CUSCIB_Object {
    bool                isOpen;         /* To determine if the SPI is open */

    Semaphore_Struct    mutex;          /* Grants exclusive access to I2C */
    Semaphore_Struct    transferComplete; /* Notify finished I2C transfer */

    I2C_TransferMode    transferMode;   /* Blocking or Callback mode */
    I2C_CallbackFxn     transferCallbackFxn; /* Callback function pointer */

    volatile I2CUSCIB_Mode mode;        /* Stores the I2C state */

    I2C_Transaction    *currentTransaction; /* Pointer to current I2C transaction */

    uint8_t            *writeBufIdx;    /* Internal inc. writeBuf index */
    size_t              writeCountIdx;  /* Internal dec. writeCounter */

    uint8_t            *readBufIdx;     /* Internal inc. readBuf index */
    size_t              readCountIdx;   /* Internal dec. readCounter */

    /* I2C transaction pointers for I2C_MODE_CALLBACK */
    I2C_Transaction    *headPtr;        /* Head ptr for queued transactions */
    I2C_Transaction    *tailPtr;        /* Tail ptr for queued transactions */

} I2CUSCIB_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_i2c_I2CUSCIB__include */
