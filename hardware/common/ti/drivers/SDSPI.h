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
 *  @file       SDSPI.h
 *
 *  @brief      SDSPI driver interface
 *
 *  The SDSPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/SDSPI.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The SDSPI driver is a driver designed to hook into FatFs. It implements a
 *  set of functions that FatFs needs to call to perform basic block data
 *  transfers.
 *
 *  A SDSPI driver peripheral implementation doesn't require RTOS protection
 *  primitives due to the resource protection provided with FatFs. The only
 *  functions that can be called by the application are the standard driver
 *  framework functions (_open, _close, etc...).
 *
 *  Once the driver has been opened, the application may used the FatFs APIs or
 *  the standard C runtime file I/O calls (fopen, fclose, etc...). Once the
 *  driver has been closed, ensure the application does NOT make any file I/O
 *  calls.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  SDSPI_Handle      handle;
 *  SDSPI_Params      params;
 *
 *  SDSPI_Params_init(&params);
 *  params.bitRate  = someNewBitRate;
 *  handle = SDSPI_open(someSDSPI_configIndexValue, &params);
 *  if (!handle) {
 *      System_printf("SDSPI did not open");
 *  }
 *  @endcode
 *
 *  # Implementation #
 *
 *  This module serves as the main interface for TI-RTOS
 *  applications. Its purpose is to redirect the module's APIs to specific
 *  peripheral implementations which are specified using a pointer to a
 *  SDSPI_FxnTable.
 *
 *  The SDSPI driver interface module is joined (at link time) to a
 *  NULL-terminated array of SDSPI_Config data structures named *SDSPI_config*.
 *  *SDSPI_config* is implemented in the application with each entry being an
 *  instance of a SDSPI peripheral. Each entry in *SDSPI_config* contains a:
 *  - (SDSPI_FxnTable *) to a set of functions that implement a SDSPI peripheral
 *  - (void *) data object that is associated with the SDSPI_FxnTable
 *  - (void *) hardware attributes that are associated to the SDSPI_FxnTable
 *
 *  Currently the following SDSPI peripheral implementations are supported:
 *  - @ref SDSPITiva.h
 *  - @ref SDSPICC3200.h
 *  - @ref SDSPIUSCIA.h
 *  - @ref SDSPIUSCIB.h
 *  - @ref SDSPIEUSCIA.h
 *  - @ref SDSPIEUSCIB.h
 *  - @ref SDSPIMSP432.h
 *
 *  # Instrumentation #
 *
 *  The SDSPI driver interface produces log statements if
 *  instrumentation is enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *  Diags_USER2      | detailed operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_SDSPI__include
#define ti_drivers_SDSPI__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*!
 * Common SDSPI_control command code reservation offset.
 * SDSPI driver implementations should offset command codes with
 * SDSPI_CMD_RESERVED growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define SDSPIXYZ_COMMAND0        SDSPI_CMD_RESERVED + 0
 * #define SDSPIXYZ_COMMAND1        SDSPI_CMD_RESERVED + 1
 * @endcode
 */
#define SDSPI_CMD_RESERVED           32

/*!
 * Common SDSPI_control status code reservation offset.
 * SDSPI driver implementations should offset status codes with
 * SDSPI_STATUS_RESERVED growing negatively.
 *
 * Example implementation specific status codes:
 * @code
 * #define SDSPIXYZ_STATUS_ERROR0   SDSPI_STATUS_RESERVED - 0
 * #define SDSPIXYZ_STATUS_ERROR1   SDSPI_STATUS_RESERVED - 1
 * #define SDSPIXYZ_STATUS_ERROR2   SDSPI_STATUS_RESERVED - 2
 * @endcode
 */
#define SDSPI_STATUS_RESERVED       -32

/*!
 * \brief   Successful status code returned by SDSPI_control().
 *
 * SDSPI_control() returns SDSPI_STATUS_SUCCESS if the control code was executed
 * successfully.
 */
#define SDSPI_STATUS_SUCCESS        0

/*!
 * \brief   Generic error status code returned by SDSPI_control().
 *
 * SDSPI_control() returns SDSPI_STATUS_ERROR if the control code was not
 * executed successfully.
 */
#define SDSPI_STATUS_ERROR         -1

/*!
 * \brief   An error status code returned by SDSPI_control() for undefined
 * command codes.
 *
 * SDSPI_control() returns SDSPI_STATUS_UNDEFINEDCMD if the control code is not
 * recognized by the driver implementation.
 */
#define SDSPI_STATUS_UNDEFINEDCMD  -2

/*!
 *  @brief      A handle that is returned from a SDSPI_open() call.
 */
typedef struct SDSPI_Config      *SDSPI_Handle;


/*!
 *  @brief SDSPI Parameters
 *
 *  SDSPI Parameters are used to with the SDSPI_open() call. Default values for
 *  these parameters are set using SDSPI_Params_init().
 *
 *  @sa         SDSPI_Params_init()
 */
typedef struct SDSPI_Params {
    uint32_t bitRate; /*!< SPI bit rate in Hz */
    void    *custom;  /*!< Custom argument used by driver implementation */
} SDSPI_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              SDSPI_init().
 */
typedef void        (*SDSPI_InitFxn)     (SDSPI_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              SDSPI_open().
 */
typedef SDSPI_Handle (*SDSPI_OpenFxn)   (SDSPI_Handle handle,
                                         unsigned char drv,
                                         SDSPI_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              SDSPI_close().
 */
typedef void        (*SDSPI_CloseFxn)    (SDSPI_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              SDSPI_control().
 */
typedef int         (*SDSPI_ControlFxn)  (SDSPI_Handle handle,
                                          unsigned int cmd,
                                          void *arg);

/*!
 *  @brief      The definition of a SDSPI function table that contains the
 *              required set of functions to control a specific SDSPI driver
 *              implementation.
 */
typedef struct SDSPI_FxnTable {
    /*! Function to initialized the given data object */
    SDSPI_InitFxn         initFxn;

    /*! Function to open the specified peripheral */
    SDSPI_OpenFxn         openFxn;

    /*! Function to close the specified peripheral */
    SDSPI_CloseFxn        closeFxn;

    /*! Function to implementation specific control function */
    SDSPI_ControlFxn      controlFxn;
} SDSPI_FxnTable;

/*!
 *  @brief  SDSPI Global configuration
 *
 *  The SDSPI_Config structure contains a set of pointers used to characterize
 *  the SDSPI driver implementation.
 *
 *  This structure needs to be defined before calling SDSPI_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     SDSPI_init()
 */
typedef struct SDSPI_Config {
    /*! Pointer to a table of driver-specific implementations of SDSPI APIs */
    SDSPI_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void                 *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void           const *hwAttrs;
} SDSPI_Config;

/*!
 *  @brief  Function to close a SDSPI peripheral specified by the SDSPI handle.
 *          This function unmounts the file system mounted by SDSPI_open and
 *          unregisters the SDSPI driver from BIOS' FatFs module.
 *
 *  @pre    SDSPI_open() had to be called first.
 *
 *  @param  handle A SDSPI handle returned from SDSPI_open
 *
 *  @sa     SDSPI_open()
 */
extern void SDSPI_close(SDSPI_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          SDSPI_Handle.
 *
 *  @pre    SDSPI_open() has to be called first.
 *
 *  @param  handle      A SDSPI handle returned from SDSPI_open()
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
 *  @sa     SDSPI_open()
 */
extern int SDSPI_control(SDSPI_Handle handle, unsigned int cmd, void *arg);

/*!
 *  @brief  This function initializes the SDSPI driver module.
 *
 *  @pre    The SDSPI_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other SDSPI driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern void SDSPI_init(void);

/*!
 *  @brief  This function registers the SDSPI driver with BIOS' FatFs module
 *          and mounts the FatFs file system.
 *
 *  @pre    SDSPI controller has been initialized using SDSPI_init()
 *
 *  @param  index         Logical peripheral number for the SDSPI indexed into
 *                        the SDSPI_config table
 *
 *  @param  drv           Drive number to be associated with the SDSPI FatFs
 *                        driver
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *
 *  @return A SDSPI_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     SDSPI_init()
 *  @sa     SDSPI_close()
 */
extern SDSPI_Handle SDSPI_open(unsigned int index, unsigned char drv,
                               SDSPI_Params *params);

/*!
 *  @brief  Function to initialize the SDSPI_Params struct to its defaults
 *
 *  @param  params      An pointer to SDSPI_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      bitRate             = 12500000 (Hz)
 */
extern void SDSPI_Params_init(SDSPI_Params *params);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_SDSPI__include */
