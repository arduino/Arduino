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
 *  @file       CryptoCC26XX.h
 *
 *  @brief      Crypto driver implementation for a CC26XX Crypto controller
 *
 *  # Driver Include #
 *  The Crypto header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/crypto/CryptoCC26XX.h>
 *  @endcode
 *
 *  # Overview #
 *
 *  The CryptoCC26XX driver simplifies reading and writing to the CryptoCC26XX
 *  peripheral on the board with multiple modes of operation and performance.
 *  These include blocking and polling. A timeout can be configured in blocking mode.
 *  The driver supports encryption and decryption for both AES-ECB and AES-CCM.
 *
 *  ## General Behavior #
 *  For code examples, see [Use Cases](@ref CRYPTO_USE_CASES) below.
 *
 *  ### Opening the driver #
 *  - The application initializes the CryptoCC26XX driver by
 *    calling CryptoCC26XX_init() and is then ready to open a CryptoCC26XX by calling
 *    CryptoCC26XX_open().
 *  - If one client (the first) calls the CryptoCC26XX_open() with the exclusiveAccess
 *    flag set, all subsequent calls to open will fail (i.e. return a NULL pointer).
 *    The first client can use the Crypto module exclusively.
 *  - Only one client can call CryptoCC26XX_open() at the same time, a second client
 *    will pend until the first client's call will release a semaphore.
 *  - The number of clients are counted with openCnt in ::CryptoCC26XX_Object.
 *  .
 *  @code
 *  CryptoCC26XX_Handle      handle;
 *  CryptoCC26XX_Params      params;
 *  bool                     exclusiveAccess = false;
 *
 *  CryptoCC26XX_Params_init(&params);
 *
 *  handle = CryptoCC26XX_open(Board_CRYPTO, exclusiveAccess, &params);
 *  if (!handle) {
 *      System_printf("CryptoCC26XX did not open");
 *  }
 *  @endcode
 *
 *  ### Before starting a crypto operation #
 *  - Before any encryption/decryption operation starts, the key store must have at
 *    least one key loaded.
 *  - To get access to a location in the key store, the caller must allocated it by
 *    calling CryptoCC26XX_allocateKey().
 *  - If the requested key location is available, the client will get a key index
 *    (uint8_t) returned.
 *  - If the requested key location is already occupied, the CryptoCC26XX_allocateKey()
 *    will fail and return ::CRYPTOCC26XX_STATUS_ERROR.
 *  - The key locations available are defined in ::CryptoCC26XX_KeyLocation.
 *  - To select any available key location, call the allocate function with key
 *    location set to ::CRYPTOCC26XX_KEY_ANY.
 *  .
 *  ### Performing a crypto operation #
 *  - The supported crypto operations are defined in ::CryptoCC26XX_Operation.
 *  - The operation is initiated by calling a transaction function.
 *  - The type of operation is decided by the transaction pointer passed to the
 *    transaction function.
 *  - The mode of the transaction (i.e. blocking/polling) is decided by selecting the
 *    corresponding transact function (see Supported transaction modes below).
 *  - The key index is passed to the encryption/decryption transaction functions as
 *    part of the transaction object.
 *  - When a transaction starts, a semaphore is used to ensure that only one transaction
 *    is performed at a given time. The polling transaction is using 0 wait time, and
 *    will return immediately with ::CRYPTOCC26XX_STATUS_ERROR if the semaphore is not granted.
 *  - In blocking mode a constraint is set to ensure that the device only enters idle mode
 *    if the CPU becomes inactive.
 *  - When the transaction ends, the device might enter standby.
 *  - A key location can be deallocated by calling CryptoCC26XX_releaseKey().
 *  .
 *  ### Supported transaction modes #
 *  - ::CRYPTOCC26XX_MODE_BLOCKING, typically used from task context. Selected by calling the
 *    CryptoCC26XX_transact() function.
 *  - ::CRYPTOCC26XX_MODE_POLLING, typically used from hwi/swi context. Selected by calling the
 *    CryptoCC26XX_transactPolling() function. This mode should be replaced by a
 *    callback mode in a future release.
 *  .
 *  ### Closing the driver #
 *  The crypto driver is closed by calling CryptoCC26XX_close() function. When the openCnt
 *  is decremented to zero, the crypto related bios modules are destructed.
 *  @code
 *  CryptoCC26XX_close(handle);
 *  @endcode
 *
 *  ## Error handling ##
 *  If an error occur during encryption/decryption, the operation will return the
 *  error code and the device might enter standby.
 *
 *  ## Power Management ##
 *  During a transaction in blocking mode, the Power_SB_DISALLOW constraint is set
 *  to block the system from entering standby mode. During this period the system will
 *  enter idle mode if no tasks are running.
 *
 *  A system dependency on crypto will be active as long as there are
 *  clients with an open handle to the crypto.
 *
 *  @note When coming out of standby the key store RAM has lost it's content, so the
 *  keyStore in ::CryptoCC26XX_Object will be cleared and the clients will have to
 *  allocate the key over again.
 *
 *  ## Supported Functions ##
 *  | API function                   | Description                                       |
 *  |------------------------------- |---------------------------------------------------|
 *  | CryptoCC26XX_init()            | Function to initializes bios modules needed by CryptoCC26XX module |
 *  | CryptoCC26XX_open()            | Initialize Crypto and get crypto handle           |
 *  | CryptoCC26XX_close()           | Disable Crypto HW and destruct bios modules used by transactions |
 *  | CryptoCC26XX_Params_init()     | Initialize Crypto parameters                      |
 *  | CryptoCC26XX_Transac_init()    | Initialize Crypto transaction                     |
 *  | CryptoCC26XX_allocateKey()     | Allocate a key for current client and write key into one of the Crypto RAM locations            |
 *  | CryptoCC26XX_releaseKey()      | Release/deallocate a key for current client       |
 *  | CryptoCC26XX_transact()        | Start a crypto operation in blocking mode         |
 *  | CryptoCC26XX_transactPolling() | Start a crypto operation in polling mode          |
 *
 *  ## Unsupported functionality:
 *  Functionality that currently not supported:
 *  - Callback mode
 *  - Queued transactions for use in callback mode
 *
 *  ## Supported Operations ##
 *  | Operation Type                       | Description                                       |
 *  |--------------------------------------|---------------------------------------------------|
 *  | ::CRYPTOCC26XX_OP_AES_CCM            | AES-CCM Operation with Cryptation                 |
 *  | ::CRYPTOCC26XX_OP_AES_CCM_NOCRYPT    | AES-CCM Operation without Cryptation              |
 *  | ::CRYPTOCC26XX_OP_AES_CCMINV         | AES-CCM Inverse Operation with Cryptation         |
 *  | ::CRYPTOCC26XX_OP_AES_CCMINV_NOCRYPT | AES-CCM Inverse Operation without Cryptation      |
 *  | ::CRYPTOCC26XX_OP_AES_ECB            | AES-ECB Operation with Cryptation                 |
 *  | ::CRYPTOCC26XX_OP_AES_ECB_NOCRYPT    | AES-ECB Operation without Cryptation              |
 *
 *  ## Use Cases \anchor CRYPTO_USE_CASES ##
 *  ### AES ECB operation #
 *  Do a crypto operation with AES-ECB in ::CRYPTOCC26XX_MODE_BLOCKING.
 *  @code
 *  // AES-ECB example struct
 *  typedef struct
 *  {
 *      uint8_t ui8AESKey[16];                      // Stores the Aes Key
 *      CryptoCC26XX_KeyLocation ui8AESKeyLocation; // Location in Key RAM
 *      uint8_t ui8AESClearText[16];                // Input message - clear text
 *      uint8_t ui8AESMsgOut[16];                   // Output message
 *      uint8_t ui8IntEnable;                       // Set to true/false to enable/
 *                                                  // disable interrupts
 *  } tAESECBExample;
 *
 *  // AES ECB example data
 *  tAESECBExample sAESexample =
 *  {
 *      { 0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,
 *      0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C },
 *      CRYPTOCC26XX_KEY_0,
 *      { 0x6B, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96,
 *      0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A },
 *      { 0x3A, 0xD7, 0x7B, 0xB4, 0x0D, 0x7A, 0x36, 0x60,
 *      0xA8, 0x9E, 0xCA, 0xF3, 0x24, 0x66, 0xEF, 0x97 },
 *      true,
 *  };
 *
 *  // Declaration (typically done in a task)
 *  CryptoCC26XX_Handle             handle;
 *  CryptoCC26XX_Params             params;
 *  uint8_t                         keyIndex;
 *  CryptoCC26XX_AESECB_Transaction trans;
 *
 *  // Configure CryptoCC26XX parameters.
 *  CryptoCC26XX_Params_init(&params);
 *
 *  // Initialize transaction
 *  CryptoCC26XX_Transac_init((CryptoCC26XX_Transaction *) &trans, CRYPTOCC26XX_OP_AES_ECB);
 *
 *  // Attempt to open CryptoCC26XX.
 *  handle = CryptoCC26XX_open(Board_CRYPTO, false, &params);
 *
 *  if (!handle) {
 *      System_printf("CryptoCC26XX did not open");
 *  } else {
 *
 *      keyIndex = CryptoCC26XX_allocateKey(handle, sAESexample.ui8AESKeyLocation,
 *                                           (const uint32_t *) sAESexample.ui8AESKey);
 *
 *      if (keyIndex != CRYPTOCC26XX_STATUS_ERROR) {
 *          // Setup transaction
 *          trans.keyIndex         = keyIndex;
 *          trans.msgIn            = (uint32_t *) sAESexample.ui8AESClearText;
 *          trans.msgOut           = (uint32_t *) sAESexample.ui8AESMsgOut;
 *
 *          // Do AES-ECB operation
 *          res = CryptoCC26XX_transact(handle, (CryptoCC26XX_Transaction *) &trans);
 *
 *          CryptoCC26XX_releaseKey(handle);
 *      } else {
 *          System_printf("Key Location was not allocated.");
 *      }
 *  }
 *  @endcode
 *
 *  # Instrumentation #
 *  The CryptoCC26XX driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details                                |
 *  ---------------- | ------------------------------------------ |
 *  Diags_USER1      | Basic CryptoCC26XX operations performed    |
 *  Diags_USER2      | Detailed CryptoCC26XX operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_crypto_CryptoCC26XX__include
#define ti_drivers_crypto_CryptoCC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <driverlib/crypto.h>

#define CRYPTOCC26XX_TIMEOUT 20        /*!< Timeout Return Code           */

#define CRYPTOCC26XX_STATUS_SUCCESS        0  /*!< Success Return Code           */
#define CRYPTOCC26XX_STATUS_ERROR         -1  /*!< Error Return Code             */
#define CRYPTOCC26XX_STATUS_UNDEFINEDCMD  -2  /*!< Command Undefined Return Code */

#define CRYPTOCC26XX_OP_AES_CCM            0  /*!< AES-CCM Operation with Cryptation           */
#define CRYPTOCC26XX_OP_AES_CCM_NOCRYPT    1  /*!< AES-CCM Operation without Cryptation        */
#define CRYPTOCC26XX_OP_AES_CCMINV         2  /*!< AES-CCM Inverse Operation with Cryptation   */
#define CRYPTOCC26XX_OP_AES_CCMINV_NOCRYPT 3  /*!< AES-CCM Inverse Operation without Cryptation*/
#define CRYPTOCC26XX_OP_AES_ECB            4  /*!< AES-ECB Operation with Cryptation           */
#define CRYPTOCC26XX_OP_AES_ECB_NOCRYPT    5  /*!< AES-ECB Operation without Cryptation        */

/*! Macro for selecting the operation type, i.e. omitting the crypt bit */
#define OP_TYPE(x)                 ((x)&0xFE)
/*! Macro for getting cryptation flag from the operation type */
#define DO_CRYPT(x)                ((x)&0x01?false:true)

/*
 * The following allows this header file to be included in an application file
 * which also includes ti/sysbios/hal/Hwi.h.
 */
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>

/*!
 *  @brief      A handle that is returned from a CryptoCC26XX_open() call.
 */
typedef struct CryptoCC26XX_Config      *CryptoCC26XX_Handle;

/*!
 *  @brief      CryptoCC26XX Mode Settings
 *
 *  This enum defines the read and write modes for the
 *  configured CryptoCC26XX.
 */
typedef enum CryptoCC26XX_Mode {
    /*!
      *  Uses a semaphore to block while data is being sent. Context of the call
      *  must be a Task.
      */
    CRYPTOCC26XX_MODE_BLOCKING,

    /*!
      *  Will return when the operation has finished. Call can be made from
      *  hwi and swi context.
      */
    CRYPTOCC26XX_MODE_POLLING
} CryptoCC26XX_Mode;

/*!
 *  @brief    CryptoCC26XX Operation Type
 *
 *  This type holds the CryptoCC26XX operation.
 *
 *  Currently supported types are
 *  ::CRYPTOCC26XX_OP_AES_CCM, ::CRYPTOCC26XX_OP_AES_CCMINV,
 *  ::CRYPTOCC26XX_OP_AES_ECB, ::CRYPTOCC26XX_OP_AES_CCM_NOCRYPT,
 *  ::CRYPTOCC26XX_OP_AES_CCMINV_NOCRYPT and ::CRYPTOCC26XX_OP_AES_ECB_NOCRYPT.
 */
typedef uint8_t CryptoCC26XX_Operation;

/*!
 *  @brief    CryptoCC26XX Key Store Location
 *
 *  This enumeration defines the possible key locations in CryptoCC26XX.
 *
 */
typedef enum CryptoCC26XX_KeyLocation {
    CRYPTOCC26XX_KEY_0 = 0,
    CRYPTOCC26XX_KEY_1,
    CRYPTOCC26XX_KEY_2,
    CRYPTOCC26XX_KEY_3,
    CRYPTOCC26XX_KEY_4,
    CRYPTOCC26XX_KEY_5,
    CRYPTOCC26XX_KEY_6,
    CRYPTOCC26XX_KEY_7,
    CRYPTOCC26XX_KEY_COUNT,
    CRYPTOCC26XX_KEY_ANY,
} CryptoCC26XX_KeyLocation;

/*!
 *  @brief    CryptoCC26XX Parameters
 */
typedef struct CryptoCC26XX_Params {
    uint32_t        timeout;  /*!< Timeout for read semaphore */
} CryptoCC26XX_Params;

/*!
 *  @brief  CryptoCC26XX Key
 *
 *  This holds allocation information for the keys in the key store.
 */
typedef uint8_t CryptoCC26XX_KeyStore;

/*!
 *  @brief  CryptoCC26XX Transaction
 *
 *  This structure defines the nature of a general crypto transaction. An operation
 *  specific object, e.g. CryptoCC26XX_AESCCM_Transaction, must be used by the clients.
 *  All transaction must be typecasted to this common type when calling the transact
 *  functions. The first data of all transactions must hold a type field indicating
 *  which type of transaction to be performed.
 */
typedef struct CryptoCC26XX_Transaction {
    CryptoCC26XX_Operation    opType;          /*!< The type of the crypto operation */
    CryptoCC26XX_Mode         mode;            /*!< The mode of current transaction */
    uint8_t                   data[];          /*!< A void pointer to rest of transaction (transac. specific) */
} CryptoCC26XX_Transaction;

/*!
 *  @brief  CryptoCC26XX AES-CCM Transaction
 *
 *  This structure defines the nature of the AES-CCM transaction. An object of this structure must
 *  be initialized by calling CryptoCC26XX_Transac_init().
 */
typedef struct CryptoCC26XX_AESCCM_Transaction {
    CryptoCC26XX_Operation  opType;         /*!< The type of the crypto operation */
    CryptoCC26XX_Mode       mode;           /*!< The mode of current transaction. Set by transact function. */
    uint8_t                 keyIndex;       /*!< The key store index to be used */
    uint8_t                 authLength;     /*!< Is the the length of the authentication field - */
                                            /*!< 0, 2, 4, 6, 8, 10, 12, 14 or 16 octets. */
    char                   *nonce;          /*!< A pointer to 13-byte or 12-byte Nonce. */
    char                   *msgIn;          /*!< A pointer to the octet string input message */
    char                   *header;         /*!< The Additional Authentication Data or AAD */
    void                   *msgOut;         /*!< A pointer to the output message location */
    uint8_t                 fieldLength;    /*!< The size of the length field (2 or 3) */
    uint16_t                msgInLength;/*!< The length of the message */
    uint16_t                headerLength;   /*!< The length of the header in octets */
} CryptoCC26XX_AESCCM_Transaction;

/*!
 *  @brief  CryptoCC26XX AES-ECB Transaction
 *
 *  This structure defines the nature of the AES-ECB transaction. An object of this structure must
 *  be initialized by calling CryptoCC26XX_Transac_init().
 */
typedef struct CryptoCC26XX_AESECB_Transaction {
    CryptoCC26XX_Operation    opType;    /*!< The type of the crypto operation */
    CryptoCC26XX_Mode         mode;      /*!< The mode of current transaction. Set by transact function. */
    uint8_t                   keyIndex;  /*!< The key store index to be used. */
    void                     *msgIn;     /*!< A poiner to the octet string input message */
    void                     *msgOut;    /*!< A pointer to the output message location */
} CryptoCC26XX_AESECB_Transaction;

/*!
 *  @brief      CryptoCC26XX Hardware Attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For CC26XXWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const CryptoCC26XX_HWAttrs cryptoCC26XXHWAttrs[] = {
 *      {
 *          CRYPTO_BASE,
 *          INT_CRYPTO,
 *          PERIPH_CRYPTO
 *      }
 *  };
 *  @endcode
 */
typedef struct CryptoCC26XX_HWAttrs {
    /*! Crypto Peripheral's base address */
    uint32_t   baseAddr;
    /*! Crypto Peripheral's interrupt vector */
    int        intNum;
    /*! Crypto Peripheral's power manager ID */
    int        powerMngrId;
} CryptoCC26XX_HWAttrs;

/*!
 *  @brief      CryptoCC26XX Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct CryptoCC26XX_Object {
    /* CryptoCC26XX control variables */
    int                       openCnt;          /*!< Counting number of clients */
    uint32_t                  timeout;          /*!< Timeout for encrypt/decrypt operation */
    CryptoCC26XX_KeyStore     keyStore;         /*!< Key store for Crypto */
    CryptoCC26XX_Transaction *currentTransact;  /*!< Pointer to ongoing transaction */

    /* Crypto transaction pointers for CryptoCC26XX_MODE_CALLBACK */
    CryptoCC26XX_Transaction *headPtr;          /*!< head pointer for queued transactions */
    CryptoCC26XX_Transaction *tailPtr;          /*!< tail pointer for queued transactions */

    /*! Crypto notification object */
    Power_NotifyObj           cryptoNotiObj;

    /* CryptoCC26XX SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;      /*!< Hwi object */
    Semaphore_Struct                    transSem; /*!< CryptoCC26XX transaction semaphore */
    Semaphore_Struct                    waitSem;  /*!< Semaphore for use in blocking mode*/
} CryptoCC26XX_Object;

/*! @brief CryptoCC26XX Global Configuration */
typedef struct CryptoCC26XX_Config {
    /*! Pointer to a driver specific data object */
    void                   *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void          const    *hwAttrs;
} CryptoCC26XX_Config;

/*!
 *  @brief  Function to closes a given CryptoCC26XX peripheral specified by the CryptoCC26XX
 *  handle.
 *
 *  @pre    CryptoCC26XX_open() had to be called first.
 *          Calling context: Task
 *
 *  @param  handle  A CryptoCC26XX_Handle returned from CryptoCC26XX_open().
 *
 *  @return Returns CRYPTOCC26XX_STATUS_SUCCESS if successful, otherwise will return
 *          CRYPTOCC26XX_STATUS_ERROR.
 *
 *  @sa     CryptoCC26XX_open
 */
int CryptoCC26XX_close(CryptoCC26XX_Handle handle);

/*!
 *  @brief  Function to initializes bios modules needed by CryptoCC26XX module.
 *
 *  @pre    This function must be called before any other CryptoCC26XX driver APIs.
 *          Calling context: Task and Main.
 *
 */
void CryptoCC26XX_init(void);

/*!
 *  @brief  Function to initialize a given CryptoCC26XX peripheral specified by the
 *          particular index value. The parameter specifies which mode the CryptoCC26XX
 *          will operate.
 *
 *  @pre    The CryptoCC26XX_Config structure must exist and be persistent before this
 *          function can be called. CryptoCC26XX has been initialized with CryptoCC26XX_init().
 *          Calling context: Task.
 *
 *  @param  index         Logical peripheral number indexed into the HWAttrs
 *                        table.
 *
 *  @param  exclusiveAccess Boolean flag to get exclusive access, if true all
 *                          subsequent calls to CryptoCC26XX_open() will fail.
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values.
 *
 *  @return A CryptoCC26XX_Handle on success or a NULL on an error or if it has been
 *          already opened with exclusiveAccess set.
 *
 *  @sa     CryptoCC26XX_close(), CryptoCC26XX_init()
 */
CryptoCC26XX_Handle CryptoCC26XX_open(unsigned int index, bool exclusiveAccess, CryptoCC26XX_Params *params);

/*!
 *  @brief  Function to initialize the CryptoCC26XX_Params struct to its defaults.
 *
 *  @pre    Calling context: Hwi, Swi and Task.
 *
 *  Defaults values are:
 *  timeout = BIOS_WAIT_FOREVER;
 *
 *  @param  params  Parameter structure to initialize.
 */
void CryptoCC26XX_Params_init(CryptoCC26XX_Params *params);

/*!
 *  @brief  Function to initialize the CryptoCC26XX_Transaction struct to its defaults.
 *
 *  @pre    Calling context: Hwi, Swi and Task.
 *
 *  @param  trans   Transaction structure to initialize.
 *
 *  @param  opType  Cryto Operation type to perform in the transaction. See
 *                  ::CryptoCC26XX_Operation for currently supported types.
 */
void CryptoCC26XX_Transac_init(CryptoCC26XX_Transaction *trans, CryptoCC26XX_Operation opType);

/*!
 *  @brief  Function that allocates key, writes key into key store RAM and returns
 *          a handle to CryptoCC26XX Key.
 *
 *  This function try to allocate the wanted key location, initiates an operation to
 *  write a key into one of the keystore RAM entries and returns a key index integer
 *  to the calling client. The allocated key index shall be used when building a
 *  transaction data object, e.g. ::CryptoCC26XX_AESCCM_Transaction.keyIndex.
 *
 *  @pre    CryptoCC26XX_open() has to be called first.
 *          Calling context: Hwi, Swi and Task.
 *
 *  @param  handle       A CryptoCC26XX_Handle returned by CryptoCC26XX_open().
 *
 *  @param  keyLocation  The key location in key store to allocate. If set to
 *                       CRYPTOCC26XX_KEY_ANY, the first available key, starting
 *                       from highest index, will be allocated.
 *
 *  @param  keySrc       A pointer to buffer containing key to be written.
 *
 *  @return An integer representing the index allocated in key store or a
 *  CRYPTOCC26XX_STATUS_ERROR on an error.
 *
 *  @sa     CryptoCC26XX_releaseKey()
 */
int CryptoCC26XX_allocateKey(CryptoCC26XX_Handle handle, CryptoCC26XX_KeyLocation keyLocation, const uint32_t *keySrc);

/*!
 *  @brief  Function that releases the specified CryptoCC26XX Key.
 *
 *  This function releases the crypto key, so it can be used by other clients.
 *
 *  @pre    Driver must have been opened and the key must have been allocated first.
 *          Calling context: Hwi, Swi and Task.
 *
 *  @param  handle       A CryptoCC26XX_Handle returned by CryptoCC26XX_open().
 *
 *  @param  keyIndex     A pointer to the keyIndex to be released.
 *
 *  @return Returns CRYPTOCC26XX_STATUS_SUCCESS if successful, otherwise will return
 *          CRYPTOCC26XX_STATUS_ERROR.
 *
 *  @sa     CryptoCC26XX_allocateKey()
 */
int CryptoCC26XX_releaseKey(CryptoCC26XX_Handle handle, int *keyIndex);

/*!
 *  @brief  Function to do a Crypto operation (encryption or decryption) in blocking mode.
 *
 *  This function initiates a blocking crypto operation.
 *
 *  CryptoCC26XX_transact() will block task execution until all
 *  the data has been encrypted or decrypted, a task switch could be done
 *  when pending on a semaphore.
 *
 *  @pre    Driver must have been opened and a key must have been allocated first.
 *          Calling context: Task.
 *
 *  @param  handle          A CryptoCC26XX_Handle returned by CryptoCC26XX_open().
 *
 *  @param  transaction     Pointer to a transaction descriptor.
 *
 *  @return Returns CRYPTOCC26XX_STATUS_SUCCESS if successful, error code if not.
 *
 *  @sa     CryptoCC26XX_open(), CryptoCC26XX_allocateKey(), CryptoCC26XX_transactPolling()
 */
int CryptoCC26XX_transact(CryptoCC26XX_Handle handle, CryptoCC26XX_Transaction *transaction);

/*!
 *  @brief  Function to do a Crypto transaction operation (encryption or decryption) in polling mode.
 *
 *  This function initiates a polling crypto operation.
 *
 *  CryptoCC26XX_transactPolling() blocks task execution and does not pend
 *  on a semaphore, consequently no task switch will be done as a result of pending.
 *
 *  @pre    Driver must have been opened and a key must have been allocated first.
 *          Calling context: Hwi, Swi and Task.
 *
 *  @param  handle          An CryptoCC26XX_Handle returned by CryptoCC26XX_open().
 *
 *  @param  transaction     Pointer to a transaction descriptor.
 *
 *  @return Returns CRYPTOCC26XX_STATUS_SUCCESS if successful, error code if not.
 *
 *  @sa     CryptoCC26XX_open(), CryptoCC26XX_allocateKey(), CryptoCC26XX_transact()
 */
int CryptoCC26XX_transactPolling(CryptoCC26XX_Handle handle, CryptoCC26XX_Transaction *transaction);

/*!
 *  @brief  Function to do a Crypto transaction operation (encryption or decryption) in
 *          callback mode. Currently not supported.
 *
 *  This function initiates a callback crypto operation.
 *
 *  CryptoCC26XX_transactCallback() will continue task execution (i.e. does not pend
 *  on a semaphore). A callback function must be defined, and will be called when the
 *  crypto operation has finished.
 *
 *  @pre    Driver must have been opened and a key must have been allocated first.
 *          Calling context: Hwi, Swi and Task.
 *
 *  @param  handle          An CryptoCC26XX_Handle returned by CryptoCC26XX_open().
 *
 *  @param  transaction     Pointer to a transaction descriptor.
 *
 *  @return Returns CRYPTOCC26XX_STATUS_SUCCESS if successful, error code if not.
 *
 *  @note Currently not supported. Will replace CryptoCC26XX_transactPolling in the future.
 *
 *  @sa     CryptoCC26XX_open(), CryptoCC26XX_allocateKey(), CryptoCC26XX_transact()
 */
int CryptoCC26XX_transactCallback(CryptoCC26XX_Handle handle, CryptoCC26XX_Transaction *transaction);


/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_crypto_CryptoCC26XX__include */
