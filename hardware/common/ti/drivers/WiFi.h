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
 *  @file   WiFi.h
 *
 *  @brief  WiFi driver interface
 *
 *  The WiFi header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/WiFi.h>
 *  @endcode
 *
 *  # Operation #
 *  The TI-RTOS WiFi driver implements many of the crucial elements necessary
 *  to communicate with a TI Wi-Fi device. It uses the TI-RTOS SPI module and
 *  implements a state machine to send and receive commands, data, and events
 *  to and from a Wi-Fi device.
 *
 *  The APIs in this driver give the user the ability to open a WiFi driver
 *  instance that will communicate with the Wi-Fi device's host driver without
 *  further direct calls to the driver from the application.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  WiFi_Handle      handle;
 *  WiFi_Params      params;
 *
 *  WiFi_Params_init(&params);
 *  params.bitRate  = bitRateValue;
 *  handle = WiFi_open(WiFi_configIndex, SPI_configIndex, callbackPtr,
 *                     &params);
 *  if (!handle) {
 *      System_printf("WiFi did not open");
 *  }
 *
 *  // Wi-Fi device's host driver APIs (such as socket()) may now be used
 *  @endcode
 *
 *  ## Configuration #
 *  ### SimpleLink CC3100 device #
 *  The SimpleLink Host Driver for CC3100 the device requires a mechanism
 *  to allow functions to execute in a temporary context.  A SpawnTask is
 *  dynamically created to meet satisfy this requirement.  The priority for the
 *  SpawnTask can be changed via the graphical editor, or by editing the script
 *  as a text file, with the following line of code:
 *  @code
 *  WiFi.spawnTaskPriority = 3;
 *  @endcode
 *  The default will create the SpawnTask with the priority set to 3.
 *
 *  # Implementation #
 *  The WiFi driver interface module is joined (at link time) to a
 *  NULL-terminated array of WiFi_Config data structures named *WiFi_config*.
 *  *WiFi_config* is implemented in the application with each entry being an
 *  instance of a WiFi driver. Each entry in *WiFi_config* contains a:
 *  - (WiFi_FxnTable *) to a set of functions that implement a WiFi driver
 *  - (void *) data object that is associated with the WiFi_FxnTable
 *  - (void *) hardware attributes that are associated to the WiFi_FxnTable
 *
 *  The WiFi driver currently only supports one instance of the module. This
 *  means that the WiFi_config structure may only contain one non-NULL entry,
 *  and it must be located at index 0.
 *
 *  Currently the following WiFi implementations are supported:
 *  - @ref WiFiCC3100.h
 *
 *  # Instrumentation #
 *  The WiFi driver interface produces log statements if
 *  instrumentation is enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *  Diags_USER2      | detailed operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_WiFi__include
#define ti_drivers_WiFi__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*!
 * Common WiFi_control command code reservation offset.
 * WiFi driver implementations should offset command codes with WiFi_CMD_RESERVED
 * growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define WiFiXYZ_COMMAND0         WiFi_CMD_RESERVED + 0
 * #define WiFiXYZ_COMMAND1         WiFi_CMD_RESERVED + 1
 * @endcode
 */
#define WiFi_CMD_RESERVED            32

/*!
 * Common WiFi_control status code reservation offset.
 * WiFi driver implementations should offset status codes with
 * WiFi_STATUS_RESERVED growing negatively.
 *
 * Example implementation specific status codes:
 * @code
 * #define WiFiXYZ_STATUS_ERROR0    WiFi_STATUS_RESERVED - 0
 * #define WiFiXYZ_STATUS_ERROR1    WiFi_STATUS_RESERVED - 1
 * #define WiFiXYZ_STATUS_ERROR2    WiFi_STATUS_RESERVED - 2
 * @endcode
 */
#define WiFi_STATUS_RESERVED        -32

/*!
 * \brief   Successful status code returned by WiFi_control().
 *
 * WiFi_control() returns WiFi_STATUS_SUCCESS if the control code was executed
 * successfully.
 */
#define WiFi_STATUS_SUCCESS         0

/*!
 * \brief   Generic error status code returned by WiFi_control().
 *
 * WiFi_control() returns WiFi_STATUS_ERROR if the control code was not executed
 * successfully.
 */
#define WiFi_STATUS_ERROR          -1

/*!
 * \brief   An error status code returned by WiFi_control() for undefined
 * command codes.
 *
 * WiFi_control() returns WiFi_STATUS_UNDEFINEDCMD if the control code is not
 * recognized by the driver implementation.
 */
#define WiFi_STATUS_UNDEFINEDCMD   -2

/*!
 *  @brief  A typedef to a an unsolicited event callback function
 *
 *  This is the definition describing the function that is to be called when
 *  the Wi-Fi device has informed the host MCU that an event has occurred. For
 *  more details, see Doxygen documentation for the specific driver\
 *  implementation in use.
 *
 *  @param eventType    Type of event
 *
 *  @param data         Pointer to extra data that some events may supply
 *
 *  @param length       Length of data
 */
typedef void (*WiFi_evntCallback) (long eventType, char *data, unsigned char length);

/*!
 *  @brief  A handle that is returned from a WiFi_open() call
 */
typedef struct WiFi_Config *WiFi_Handle;

/*!
 *  @brief WiFi Parameters
 *
 *  WiFi parameters are used to with the WiFi_open() call. Default values for
 *  these parameters are set using WiFi_Params_init().
 *
 *  @sa     WiFi_Params_init()
 */
typedef struct WiFi_Params {
    uint32_t         bitRate;       /*!< SPI bit rate in Hz */
    void            *custom;        /*!< Custom argument used by driver
                                         implementation */
} WiFi_Params;

/*!
 *  @brief  A function pointer to a driver specific implementation of
 *          WiFi_init().
 */
typedef void (*WiFi_InitFxn) (WiFi_Handle handle);

/*!
 *  @brief  A function pointer to a driver specific implementation of
 *          WiFi_open().
 */
typedef WiFi_Handle (*WiFi_OpenFxn) (WiFi_Handle handle, unsigned int spiIndex,
                                     WiFi_evntCallback evntCallback,
                                     WiFi_Params *params);

/*!
 *  @brief  A function pointer to a driver specific implementation of
 *          WiFi_close().
 */
typedef void (*WiFi_CloseFxn) (WiFi_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              WiFi_control().
 */
typedef int  (*WiFi_ControlFxn) (WiFi_Handle handle,
                                 unsigned int cmd,
                                 void *arg);

/*!
 *  @brief  The definition of a WiFi function table that contains the required
 *          set of functions to control a specific WiFi driver implementation.
 */
typedef struct WiFi_FxnTable {
    /*! Function to close the specified peripheral */
    WiFi_CloseFxn     closeFxn;

    /*! Function to implementation specific control function */
    WiFi_ControlFxn   controlFxn;

    /*! Function to initialize the given data object */
    WiFi_InitFxn      initFxn;

    /*! Function to open the specified peripheral */
    WiFi_OpenFxn      openFxn;
} WiFi_FxnTable;

/*!
 *  @brief  WiFi Global configuration
 *
 *  The WiFi_Config structure contains a set of pointers used to
 *  characterize the WiFi driver implementation.
 *
 *  This structure needs to be defined before calling WiFi_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     WiFi_init()
 */
typedef struct WiFi_Config {
    /*! Pointer to a table of driver-specific implementations of WiFi APIs */
    WiFi_FxnTable const   *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                  *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void const            *hwAttrs;
} WiFi_Config;

/*!
 *  @brief  Function to close a WiFi peripheral specified by the WiFi handle
 *
 *  @pre    WiFi_open() has to be called first.
 *
 *  @param  handle  A WiFi_Handle returned from WiFi_open
 *
 *  @sa     WiFi_open()
 */
extern void WiFi_close(WiFi_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          WiFi_Handle.
 *
 *  @pre    WiFi_open() has to be called first.
 *
 *  @param  handle      A WiFi handle returned from WiFi_open()
 *
 *  @param  cmd         A command value defined by the driver specific
 *                      implementation
 *
 *  @param  arg         An optional R/W (read/write) argument that is
 *                      accompanied with cmd
 *
 *  @return Implementation specific return codes. Negative values indicate
 *          unsuccessful operations.
 *
 *  @sa     WiFi_open()
 */
extern int WiFi_control(WiFi_Handle handle, unsigned int cmd, void *arg);

/*!
 *  @brief  Function to initialize the WiFi module
 *
 *  @pre    The WiFi_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other WiFi driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern void WiFi_init(void);

/*!
 *  @brief  Function to initialize a given WiFi peripheral
 *
 *  Function to initialize a given WiFi peripheral specified by the
 *  particular index value. It initializes the specified SPI peripheral and
 *  registers the callbacks that the Wi-Fi device's host driver requires.
 *  WiFi_open() may only be called in the context of a Task.
 *
 *  @pre    WiFi_init() has been called
 *
 *  @param  wifiIndex   Logical peripheral number for the WiFi indexed into
 *                      the WiFi_config table
 *
 *  @param  spiIndex    Logical peripheral number for SPI to be used with
 *                      the WiFi indexed into the SPI_config table
 *
 *  @param  evntCallback Pointer to callback function to handle unsolicited
 *                      events from the WiFi device. For details, see
 *                      WiFi_evntCallback and the Doxygen documentation for
 *                      the specific driver implementation in use.
 *
 *  @param  params      Pointer to an parameter block, if NULL it will use
 *                      default values. All the fields in this structure are RO
 *                      (read-only).
 *
 *  @return A WiFi_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     WiFi_init()
 *  @sa     WiFi_close()
 */
extern WiFi_Handle WiFi_open(unsigned int wifiIndex, unsigned int spiIndex,
                             WiFi_evntCallback evntCallback,
                             WiFi_Params *params);

/*!
 *  @brief  Function to initialize the WiFi_Params structure to its defaults
 *
 *  @param  params      An pointer to WiFi_Params structure for
 *                      initialization
 *
 *  Default values are:
 *      bitRate = 1000000;
 */
extern void WiFi_Params_init(WiFi_Params *params);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_WiFi__include */
