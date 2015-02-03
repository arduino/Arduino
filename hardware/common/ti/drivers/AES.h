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
 *  @file       AES.h
 *
 *  @brief      AES driver interface
 *
 *  The AES header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/AES.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  NOTE: This driver should be considered experimental, and not fully verified!
 *
 *  The AES driver simplifies reading and writing to any of the AES
 *  peripherals on the board with multiple modes of operation and performance.
 *  These include blocking, non-blocking, and polling as well as text/binary
 *  mode, echo and return characters. The boards AES peripheral and pins must
 *  be configured before initializing the AES driver. The application
 *  initializes the AES driver by calling AES_init() and is then ready to
 *  open a AES by calling AES_open() and passing in a AES parameters data
 *  structure.
 *
 *  The APIs in this driver serve as an interface to a typical TI-RTOS
 *  application. The specific peripheral implementations are responsible to
 *  create all the SYS/BIOS specific primitives to allow for thread-safe
 *  operation.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  AES_Handle      handle;
 *  AES_Params      params;
 *
 *  AES_Params_init(&params);
 *  params.mode = AES_ECHO_OFF;
 *  handle = AES_open(Board_AES, &params);
 *  if (!handle) {
 *      System_printf("AES did not open");
 *  }
 *  @endcode
 *
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  AES_FxnTable.
 *
 *  The AES driver interface module is joined (at link time) to a
 *  NULL-terminated array of AES_Config data structures named *AES_config*.
 *  *AES_config* is implemented in the application with each entry being an
 *  instance of a AES peripheral. Each entry in *AES_config* contains a:
 *  - (AES_FxnTable *) to a set of functions that implement a AES peripheral
 *  - (Void *) data object that is associated with the AES_FxnTable
 *  - (Void *) hardware attributes that are associated to the AES_FxnTable
 *
 *  Currently the following AES peripheral implementations are supported:
 *  - @ref AESCC26XX.h
 *
 *  # Instrumentation #
 *  The AES driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details                       |
 *  ---------------- | --------------------------------- |
 *  Diags_USER1      | basic AES operations performed    |
 *  Diags_USER2      | detailed AES operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_AES__include
#define ti_drivers_AES__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#include <driverlib/crypto.h>

#define AES_ERROR   -1
#define AES_TIMEOUT 20

/*!
 *  @brief      A handle that is returned from a AES_open() call.
 */
typedef struct AES_Config      *AES_Handle;

/*!
 *  @brief      AES mode settings
 *
 *  This enum defines the read and write modes for the
 *  configured AES.
 */
typedef enum AES_Mode {
    /*!
      *  Uses a semaphore to block while data is being sent.  Context of the call
      *  must be a Task.
      */
    AES_MODE_BLOCKING,

    /*!
      *  Non-blocking and will return immediately.  When the transfer by the Hwi
      *  is finished the configured callback function is called.
      */
    AES_MODE_POLLING
} AES_Mode;

/*!
 *  @brief    AES key store location
 *
 *  This enumeration defines the AES parity types.
 */
typedef enum AES_KeyLocation {
    AES_KEY_0 = CRYPTO_KEY_AREA_0,
    AES_KEY_1 = CRYPTO_KEY_AREA_1,
    AES_KEY_2 = CRYPTO_KEY_AREA_2,
    AES_KEY_3 = CRYPTO_KEY_AREA_3,
    AES_KEY_4 = CRYPTO_KEY_AREA_4,
    AES_KEY_5 = CRYPTO_KEY_AREA_5,
    AES_KEY_6 = CRYPTO_KEY_AREA_6,
    AES_KEY_7 = CRYPTO_KEY_AREA_7
} AES_KeyLocation;


/*!
 *  @brief    Basic AES Parameters
 */
typedef struct AES_Params {
    AES_Mode         mode;         /*!< Mode blocking or callback */
    uint32_t         timeout;      /*!< Timeout for read semaphore */
    void            *custom;       /*!< Custom argument used by driver
                                        implementation */
} AES_Params;

/*!
 *  @brief  AES - CCM transaction
 *
 *  This structure defines the nature of the CCM transaction.
 */
typedef struct AESCCM_Transaction {
    uint32_t        authLength;      /* Is the the length of the authentication field - */
                                     /* 0, 2, 4, 6, 8, 10, 12, 14 or 16 octets. */
    char            *nonce;          /* A pointer to 13-byte or 12-byte Nonce. */
    char            *plainText;      /* A poiner to the octet string input message */
    uint32_t        plainTextLength; /* The length of the message */
    char            *header;         /* The Additional Authentication Data or AAD */
    uint32_t        headerLength;    /* The length of the header in octets */
    uint32_t        fieldLength;     /* he size of the length field (2 or 3) */
    AES_KeyLocation keyLocation;     /* A keystore entry number */
} AESCCM_Transaction;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_CloseFxn().
 */
typedef void       (*AES_CloseFxn)          (AES_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_control().
 */
typedef int         (*AES_ControlFxn)        (AES_Handle handle,
                                               unsigned int cmd,
                                               void *arg);
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_init().
 */
typedef void       (*AES_InitFxn)           (AES_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_OpenFxn().
 */
typedef AES_Handle (*AES_OpenFxn)           (AES_Handle handle,
                                             AES_Params *params);
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_LoadKEy().
 */
typedef int        (*AES_LoadKeyFxn)        (AES_Handle handle,
                                             const char *keySrc,
                                             AES_KeyLocation keyLocation);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_ECB().
 */
typedef int        (*AES_ECBFxn)            (AES_Handle handle,
                                             char *msgIn,
                                             char *msgOut,
                                             AES_KeyLocation keyLocation,
                                             bool encrypt);

 /*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_CCM().
 */
typedef int        (*AES_CCMFxn)            (AES_Handle handle,
                                             AESCCM_Transaction *transaction,
                                             char *msgOut,
                                             bool encrypt);

 /*!
 *  @brief      A function pointer to a driver specific implementation of
 *              AES_CCMInv().
 */
typedef int        (*AES_CCMInvFxn)         (AES_Handle handle,
                                             AESCCM_Transaction *transaction,
                                             char *msgOut,
                                             bool decrypt);

/*!
 *  @brief      The definition of a AES function table that contains the
 *              required set of functions to control a specific AES driver
 *              implementation.
 */
typedef struct AES_FxnTable {
    /*! Function to close the specified peripheral */
    AES_CloseFxn           closeFxn;

    /*! Function to implementation specific control function */
    AES_ControlFxn         controlFxn;

    /*! Function to initialize the given data object */
    AES_InitFxn            initFxn;

    /*! Function to open the specified peripheral */
    AES_OpenFxn            openFxn;

    /*! Function to load key into keystore */
    AES_LoadKeyFxn         loadKeyFxn;

    /*! Function to execute AES-ECB */
    AES_ECBFxn             ecbFxn;

    /*! Function to execute AES-CCM */
    AES_CCMFxn             ccmFxn;

    /*! Function to execute AES-CCM Inverse operation */
    AES_CCMInvFxn          ccmInvFxn;
} AES_FxnTable;

/*! @brief AES Global configuration */
typedef struct AES_Config {
    /*! Pointer to a table of a driver-specific implementation of AES functions */
    AES_FxnTable const    *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                   *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void          const    *hwAttrs;
} AES_Config;


/*!
 *  @brief  Function to closes a given AES peripheral specified by the AES
 *  handle.
 *
 *  @pre    AES_open() had to be called first.
 *
 *  @param  handle  A AES_Handle returned from AES_open
 *
 *  @sa     AES_open
 */
extern void AES_close(AES_Handle handle);

/*!
 *  @brief  Function to initializes the AES module
 *
 *  @pre    The AES controller needs to be powered up and clocked. The
 *          AES_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other AES driver APIs.
 */
extern void AES_init(void);

/*!
 *  @brief  Function to initialize a given AES peripheral specified by the
 *          particular index value. The parameter specifies which mode the AES
 *          will operate.
 *
 *  @pre    AES controller has been initialized
 *
 *  @param  index         Logical peripheral number indexed into the HWAttrs
 *                        table
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values
 *
 *  @return A AES_Handle on success or a NULL on an error or if it has been
 *          already opened
 *
 *  @sa     AES_close
 */
extern AES_Handle AES_open(unsigned int index, AES_Params *params);

/*!
 *  @brief  Function to initialize the AES_Params struct to its defaults
 *
 *  Defaults values are:
 *  mode = AES_MODE_BLOCKING;
 *  timeout = BIOS_WAIT_FOREVER;
 *
 *  @param  params  Parameter structure to initialize
 */
extern void AES_Params_init(AES_Params *params);


///*!
// *  @brief  Function that writes a key into the AES Key store RAM
// *
// *  This function initiates an operation to write a key into one of the
// *  keystore RAM entries.
// *
// *  @param  handle       A AES_Handle
// *
// *  @param  keySrc       A pointer to buffer containing key to be written
// *
// *  @param  keyLocation  A keystore entry number
// *
// *  @return Returns AES_SUCCESS if successful, otherwise will return
// *          AES_KEYSTORE_READ_ERROR.
// */
extern int AES_loadKey(AES_Handle handle, const char *keySrc, AES_KeyLocation keyLocation);

///*!
// *  @brief  Function to do an AES-ECB operation (encryption or decryption).
// *
// *  This function initiates an AES-ECB operation .....
// *
// *  In AES_MODE_BLOCKING, AES_ECB will block task execution until all
// *  the data has been encrypted or decrypted, a task switch could be done
// *  when pening on semaphore.
// *
// *  In AES_MODE_POLLING, AES_ECB blocks task execution and does not pend
// *  on a semaphore, consequently no task switch will be done as a result of
// *  pending.
// *
// *  @param  handle      An AES_Handle
// *
// *  @param  msgIn       A pointer to input data
// *
// *  @param  msgOut       A pointer to output data
// *
// *  @param  keyLocation A keystore entry number
// *
// *  @param  encrypt     Should be set to 'true' to encrypt or set 'false' to decrypt.
// *
// *  @return Returns AES_SUCCESS if successful
// */
extern int AES_ECB(AES_Handle handle, char *msgIn, char *msgOut, AES_KeyLocation keyLocation, bool encrypt);

///*!
// *  @brief  Function to do an AES-CCM operation (encryption or decryption).
// *
// *  This function initiates an AES-CCM operation .....
// *
// *  In AES_MODE_BLOCKING, AES_CCM will block task execution until all
// *  the data has been encrypted or decrypted, a task switch could be done
// *  when pening on semaphore.
// *
// *  In AES_MODE_POLLING, AES_CCM blocks task execution and does not pend
// *  on a semaphore, consequently no task switch will be done as a result of
// *  pending.
// *
// *  @param  handle          An AES_Handle
// *
// *  @param  transaction     Pointer to a CCM transaction descriptor
// *
// *  @param  msgOut          Pointer to result of encryption/decryption
// *
// *  @param  encrypt         Should be set to 'true' to encrypt or set
// *                          'false' to decrypt.
// *
// *  @return Returns AES_SUCCESS if successful
// */
extern int AES_CCM(AES_Handle handle, AESCCM_Transaction *transaction, char *msgOut, bool encrypt);

///*!
// *  @brief  Function to do an AES-CCM Inversion operation (encryption or decryption).
// *
// *  This function initiates an AES-CCM Inverse operation .....
// *
// *  In AES_MODE_BLOCKING, AES_CCM will block task execution until all
// *  the data has been encrypted or decrypted, a task switch could be done
// *  when pening on semaphore.
// *
// *  In AES_MODE_POLLING, AES_CCM blocks task execution and does not pend
// *  on a semaphore, consequently no task switch will be done as a result of
// *  pending.
// *
// *  @param  handle          An AES_Handle
// *
// *  @param  transaction     Pointer to a CCM transaction descriptor
// *
// *  @param  msgOut          Pointer to result of encryption/decryption
// *
// *  @param  decrypt         Should be set to 'true' to run decryption
// *
// *  @return Returns AES_SUCCESS if successful
// */
extern int AES_CCMInv(AES_Handle handle, AESCCM_Transaction *transaction, char *msgOut, bool decrypt);
#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_AES__include */
