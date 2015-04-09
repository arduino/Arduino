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
 *  @file       USBMSCHFatFs.h
 *
 *  @brief      USBMSCHFatFs driver interface.
 *
 *  The USBMSCHFatFs header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/USBMSCHFatFs.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The USBMSCHFatFs driver is a driver designed to hook into FatFs. It
 *  implements a set of functions that FatFs needs to call to perform basic
 *  block data transfers.
 *
 *  This driver is designed to work with the USB Library. Because it is running
 *  in host mode, we need to add protection when accessing the USB Library. A
 *  gate was added to prevent the task servicing the USB library to preempt any
 *  other task accessing the USB Library.
 *
 *  Once the driver has been opened, the application may used the FatFs APIs or
 *  the standard C runtime file I/O calls (fopen, fclose, etc...). Once the
 *  driver has been closed, ensure the application does NOT make any file I/O
 *  calls.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  USBMSCHFatFs_Handle      handle;
 *  USBMSCHFatFs_Params      params;
 *
 *  USBMSCHFatFs_Params_init(&params);
 *  params.servicePriority  = somePriority;
 *  handle = USBMSCHFatFs_open(someUSBMSCHFatFs_configIndexValue, &params);
 *  if (!handle) {
 *      System_printf("USBMSCHFatFs did not open");
 *  }
 *  @endcode
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  USBMSCHFatFs_FxnTable.
 *
 *  The USBMSCHFatFs driver interface module is joined (at link
 *  time) to a NULL-terminated array of USBMSCHFatFs_Config data structures
 *  named *USBMSCHFatFs_config*. *USBMSCHFatFs_config* is implemented in the
 *  application with each entry being an instance of a USBMSCHFatFs peripheral.
 *  Each entry in *USBMSCHFatFs_config* contains a:
 *  - (USBMSCHFatFs_FxnTable *) to a set of functions that implement a
 *    USBMSCHFatFs peripheral
 *  - (void *) data object that is associated with the USBMSCHFatFs_FxnTable
 *  - (void *) hardware attributes that are associated to the
 *    USBMSCHFatFs_FxnTable
 *
 *  Currently the following USBMSCHFatFs peripheral implementations are
 *  supported:
 *  - @ref USBMSCHFatFsTiva.h
 *
 *  # Instrumentation #
 *
 *  The USBMSCHFatFs driver interface produces log statements if
 *  instrumentation is enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *  Diags_USER2      | detailed operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_USBMSCHFATFS__include
#define ti_drivers_USBMSCHFATFS__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*!
 * Common USBMSCHFatFs_control command code reservation offset.
 * USBMSCHFatFs driver implementations should offset command codes with
 * USBMSCHFatFs_CMD_RESERVED growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define USBMSCHFatFsXYZ_COMMAND0             USBMSCHFatFs_CMD_RESERVED + 0
 * #define USBMSCHFatFsXYZ_COMMAND1             USBMSCHFatFs_CMD_RESERVED + 1
 * @endcode
 */
#define USBMSCHFatFs_CMD_RESERVED                32

/*!
 * Common USBMSCHFatFs_control status code reservation offset.
 * USBMSCHFatFs driver implementations should offset status codes with
 * USBMSCHFatFs_STATUS_RESERVED growing negatively.
 *
 * Example implementation specific status codes:
 * @code
 * #define USBMSCHFatFsXYZ_STATUS_ERROR0        USBMSCHFatFs_STATUS_RESERVED - 0
 * #define USBMSCHFatFsXYZ_STATUS_ERROR1        USBMSCHFatFs_STATUS_RESERVED - 1
 * #define USBMSCHFatFsXYZ_STATUS_ERROR2        USBMSCHFatFs_STATUS_RESERVED - 2
 * @endcode
 */
#define USBMSCHFatFs_STATUS_RESERVED            -32

/*!
 * \brief   Successful status code returned by USBMSCHFatFs_control().
 *
 * USBMSCHFatFs_control() returns USBMSCHFatFs_STATUS_SUCCESS if the control
 * code was executed successfully.
 */
#define USBMSCHFatFs_STATUS_SUCCESS             0

/*!
 * \brief   Generic error status code returned by USBMSCHFatFs_control().
 *
 * USBMSCHFatFs_control() returns USBMSCHFatFs_STATUS_ERROR if the control code
 * was not executed successfully.
 */
#define USBMSCHFatFs_STATUS_ERROR              -1

/*!
 * \brief   An error status code returned by USBMSCHFatFs_control() for
 *          undefined command codes.
 *
 * USBMSCHFatFs_control() returns USBMSCHFatFs_STATUS_UNDEFINEDCMD if the
 * control code is not recognized by the driver implementation.
 */
#define USBMSCHFatFs_STATUS_UNDEFINEDCMD       -2

/*!
 *  @brief      USBMSCHFatFs Handler
 */
typedef struct USBMSCHFatFs_Config *USBMSCHFatFs_Handle;

/*!
 *  @brief      USBMSCHFatFs Parameters
 *
 *  USBMSCHFatFs parameters are used to with the USBMSCHFatFs_open() call.
 *  Default values for these parameters are set using
 *  USBMSCHFatFs_Params_init().
 *
 *  @sa     USBMSCHFatFs_Params_init()
 */
typedef struct USBMSCHFatFs_Params {
    unsigned int servicePriority;      /*!< USB service Task priority. Default
                                            is highest Task priority */
    void        *serviceTaskStackPtr;  /*!< USB service Task stack pointer.
                                            Default is NULL */
    size_t       serviceTaskStackSize; /*!< USB service Task stack size.
                                            Default is Task module's
                                            Task_defaultStackSize */
    void        *custom;               /*!< Custom argument used by driver
                                            implementation */
} USBMSCHFatFs_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USBMSCHFatFs_init().
 */
typedef void (*USBMSCHFatFs_InitFxn) (USBMSCHFatFs_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USBMSCHFatFs_open().
 */
typedef USBMSCHFatFs_Handle (*USBMSCHFatFs_OpenFxn) (USBMSCHFatFs_Handle handle,
                                                     unsigned char drv,
                                                     USBMSCHFatFs_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USBMSCHFatFs_close().
 */
typedef void (*USBMSCHFatFs_CloseFxn) (USBMSCHFatFs_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USBMSCHFatFs_control().
 */
typedef int  (*USBMSCHFatFs_ControlFxn) (USBMSCHFatFs_Handle handle,
                                         unsigned int cmd,
                                         void *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              USBMSCHFatFs_waitForConnect().
 */
typedef bool (*USBMSCHFatFs_waitForconnectFxn) (USBMSCHFatFs_Handle handle,
                                                unsigned int timeout);

/*!
 *  @brief      The definition of a USBMSCHFatFs function table that contains
 *              the required set of functions to control a specific USBMSCHFatFs
 *              driver implementation.
 */
typedef struct USBMSCHFatFs_FxnTable {
    /*! Function to initialized the given data object */
    USBMSCHFatFs_InitFxn         initFxn;

    /*! Function to open the specified peripheral */
    USBMSCHFatFs_OpenFxn         openFxn;

    /*! Function to close the specified peripheral */
    USBMSCHFatFs_CloseFxn        closeFxn;

    /*! Function to implementation specific control function */
    USBMSCHFatFs_ControlFxn      controlFxn;

    /*! Function to call waitForConnect */
    USBMSCHFatFs_waitForconnectFxn waitForConnectFxn;
} USBMSCHFatFs_FxnTable;

/*!
 *  @brief  USBMSCHFatFs Global configuration
 *
 *  The USBMSCHFatFs_Config structure contains a set of pointers used to
 *  characterize the USBMSCHFatFs driver implementation.
 *
 *  This structure needs to be defined before calling USBMSCHFatFs_init() and
 *  it must not be changed thereafter.
 *
 *  @sa     USBMSCHFatFs_init()
 */
typedef struct USBMSCHFatFs_Config {
    /*!
     * Pointer to a table of driver-specific implementations of USBMSCHFatFs
     * APIs
     */
    USBMSCHFatFs_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                        *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void const                  *hwAttrs;
} USBMSCHFatFs_Config;

/*!
 *  @brief  Function to closes a given USBMSCHFatFs peripheral specified by the
 *          USBMSCHFatFs handle. This function unmounts the file system mounted
 *          by USBMSCHFatFs_open and unregisters the USBMSCHFatFs driver from
 *          BIOS' FatFs module.
 *
 *  @pre    USBMSCHFatFs_open() had to be called first.
 *
 *  @post   After calling this function, it is safe to remove the USB drive
 *
 *  @param  handle      A USBMSCHFatFs_Handle returned from USBMSCHFatFs_open
 *
 *  @sa     USBMSCHFatFs_open()
 */
extern void USBMSCHFatFs_close(USBMSCHFatFs_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          USBMSCHFatFs_Handle.
 *
 *  @pre    USBMSCHFatFs_open() has to be called first.
 *
 *  @param  handle      A USBMSCHFatFs handle returned from USBMSCHFatFs_open()
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
 *  @sa     USBMSCHFatFs_open()
 */
extern int USBMSCHFatFs_control(USBMSCHFatFs_Handle handle,
                                unsigned int cmd,
                                void *arg);

/*!
 *  @brief  Function to initialize the USBMSCHFatFs module.
 *
 *  @pre    The USBMSCHFatFs_config structure must exist and be persistent
 *          before this function can be called. This function must also be
 *          called before any other USBMSCHFatFs driver APIs. This function call
 *          does not modify any peripheral registers.
 */
extern void USBMSCHFatFs_init(void);

/*!
 *  @brief  This function registers the USBMSCHFatFs driver with BIOS' FatFs
 *          module and mounts the FatFs file system.
 *
 *  @pre    USBMSCHFatFs_Params_init() has been called
 *
 *  @param  index         Logical peripheral number for the USBMSCHFatFs indexed
 *                        into the USBMSCHFatFs_config table
 *
 *  @param  drv           Drive number to be associated with the USBMSCHFatFs
 *                        FatFs driver
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *
 *  @return A pointer to a USBMSCHFatFs_Handle on success or a NULL it was
 *          already opened
 *
 *  @sa     USBMSCHFatFs_init()
 *  @sa     USBMSCHFatFs_close()
 */
extern USBMSCHFatFs_Handle USBMSCHFatFs_open(unsigned int index,
                                             unsigned char drv,
                                             USBMSCHFatFs_Params *params);

/*!
 *  @brief  Function to initialize the USBMSCHFatFs_Params structure to its
 *          defaults
 *
 *  @param  params      An pointer to USBMSCHFatFs_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      servicePriority = Task_numPriorities - 1;
 */
extern void USBMSCHFatFs_Params_init(USBMSCHFatFs_Params *params);

/*!
 *  @brief  Function blocks task execution while no USB drive is enumerated.
 *          After the USBMSCHFatFs driver has been opened this functino is used
 *          to determine when a USB drive is has been enumerated.
 *
 *  @param  handle      A USBMSCHFatFs handle
 *
 *  @param  timeout     Timeout period in system ticks for the task to block
 *
 *  @return status:
 *          - true: Successful
 *          - false: timed out
 */
extern bool USBMSCHFatFs_waitForConnect(USBMSCHFatFs_Handle handle,
                                        unsigned int timeout);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_USBMSCHFATFS__include */
