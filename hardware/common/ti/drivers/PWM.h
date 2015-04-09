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
 *  @file       PWM.h
 *
 *  @brief      PWM driver interface
 *
 *  The PWM header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/PWM.h>
 *  @endcode
 *
 *  ## Operation #
 *
 *  The PWM driver in TI-RTOS facilitates the generation of Pulse Width
 *  Modulated signals via simple and portable APIs.  A device's PWM peripheral
 *  pins must be configured before initializing the PWM driver. The application
 *  initializes the PWM driver by calling PWM_init().  PWM instances must be
 *  opened by calling PWM_open() while passing in a PWM index and a parameters
 *  data structure.
 *
 *  The driver APIs serve as an interface to a typical TI-RTOS application. The
 *  specific peripheral implementations are responsible of creating all
 *  SYS/BIOS specific primitives to allow for thread-safe operation.
 *
 *  When a PWM instance is opened, the period, units of the duty, and polarity
 *  can be set.  The maximum period supported is device dependent; refer to the
 *  implementation specific documentation for values. A PWM instance can be
 *  configured to interpret the duty as one of three units:
 *      PWM_DUTY_COUNTS: The duty is in PWM timer ticks.
 *      PWM_DUTY_SCALAR: The duty is an integer scaled to the period where
 *                       0 corresponds to a duty of 0% and 65535 corresponds to
 *                       100% duty.
 *      PWM_DUTY_TIME: The duty is specified in microseconds.  The driver
 *                     calculates the appropriate amount of PWM timer ticks.
 *
 *  The polarity is used to set the output during the active duty portion of the
 *  period; it can be set to produce low output or a high output when active.
 *
 *  By default PWM output is set to a duty of 0.  It is the applications
 *  responsability to set the duty for each PWM output used.
 *
 *  ## Opening the driver #
 *
 *  @code
 *  PWM_Handle      handle;
 *  PWM_Params      params;
 *
 *  PWM_Params_init(&params);
 *  params.period = 20000;             // Period in microseconds
 *  params.dutyMode = PWM_DUTY_TIME;   // Duty specified in microseconds
 *  handle = PWM_open(Board_PWM0, &params);
 *  if (handle == NULL) {
 *      System_printf("PWM did not open");
 *  }
 *
 *  // Update PWM to have a duty of 3000 microseconds
 *  PWM_setDuty(handle, 3000);
 *  @endcode
 *
 *  ## Implementation #
 *
 *  This module serves as the main interface for TI-RTOS applications. Its
 *  purpose is to redirect the module APIs to specific peripheral
 *  implementations specified by a pointer to a PWM_FxnTable.
 *
 *  The PWM driver interface module is joined (at link time) to a
 *  NULL-terminated array of PWM_Config data structures named *PWM_config*.
 *  *PWM_config* is implemented in the application with each entry being an
 *  instance of a PWM peripheral. Each entry in *PWM_config* contains a:
 *  - (PWM_FxnTable *) to a set of functions that implement a PWM peripheral
 *  - (void *) data object that is associated with the PWM_FxnTable
 *  - (void *) hardware attributes that are associated to the PWM_FxnTable
 *
 *  Currently the following PWM peripheral implementations are supported:
 *  - @ref PWMTimerCC3200.h
 *  - @ref PWMTimerMSP432.h
 *  - @ref PWMTiva.h
 *  - @ref PWMTimerTiva.h
 *
 *  # Calling Context #
 *
 *  <table>
 *    <tr>
 *      <th> Function </th><th> Hwi </th><th> Swi </th><th> Task </th>
 *      <th> Main </th>
 *    </tr>
 *    <tr>
 *      <td> PWM_Params_init </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_close </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_control </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_getPeriodCounts </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_getPeriodMicroSecs </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_init </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_open </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td> PWM_setDuty </td>
 *      <td> Y </td><td> Y </td><td> Y </td><td> Y </td>
 *    </tr>
 *    <tr>
 *      <td colspan="5">
 *        <ul>
 *          <li><b>Hwi</b>: API is callable from Hwi context. </li>
 *          <li><b>Swi</b>: API is callable from Swi context. </li>
 *          <li><b>Task</b>: API is callable from a Task thread. </li>
 *          <li><b>Main</b>: API is callable from main(). </li>
 *        </ul>
 *      </td>
 *    </tr>
 *  </table>
 *
 *  # Instrumentation #
 *
 *  The PWM driver interface produces log statements if instrumentation is
 *  enabled.
 *
 *  Diagnostics Mask | Log details |
 *  ---------------- | ----------- |
 *  Diags_USER1      | basic operations performed |
 *  Diags_USER2      | detailed operations performed |
 *
 *  ============================================================================
 */

#ifndef ti_drivers_PWM__include
#define ti_drivers_PWM__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/*!
 * Common PWM_control command code reservation offset.
 * PWM driver implementations should offset command codes with PWM_CMD_RESERVED
 * growing positively
 *
 * Example implementation specific command codes:
 * @code
 * #define PWMXYZ_COMMAND0         PWM_CMD_RESERVED + 0
 * #define PWMXYZ_COMMAND1         PWM_CMD_RESERVED + 1
 * @endcode
 */
#define PWM_CMD_RESERVED            32

/*!
 * Common PWM_control status code reservation offset.
 * PWM driver implementations should offset status codes with
 * PWM_STATUS_RESERVED growing negatively.
 *
 * Example implementation specific status codes:
 * @code
 * #define PWMXYZ_STATUS_ERROR0    PWM_STATUS_RESERVED - 0
 * #define PWMXYZ_STATUS_ERROR1    PWM_STATUS_RESERVED - 1
 * #define PWMXYZ_STATUS_ERROR2    PWM_STATUS_RESERVED - 2
 * @endcode
 */
#define PWM_STATUS_RESERVED        -32

/*!
 * \brief   Successful status code returned by PWM_control().
 *
 * PWM_control() returns PWM_STATUS_SUCCESS if the control code was executed
 * successfully.
 */
#define PWM_STATUS_SUCCESS         0

/*!
 * \brief   Generic error status code returned by PWM_control().
 *
 * PWM_control() returns PWM_STATUS_ERROR if the control code was not executed
 * successfully.
 */
#define PWM_STATUS_ERROR          -1

/*!
 * \brief   An error status code returned by PWM_control() for undefined
 * command codes.
 *
 * PWM_control() returns PWM_STATUS_UNDEFINEDCMD if the control code is not
 * recognized by the driver implementation.
 */
#define PWM_STATUS_UNDEFINEDCMD   -2

/*!
 *  @brief      A handle that is returned from a PWM_open() call.
 */
typedef struct PWM_Config      *PWM_Handle;

/*!
 *  @brief
 *  Definitions for various units for specifying the PWM duty.
 */
typedef enum PWM_DutyMode {
    PWM_DUTY_COUNTS = 0,
    PWM_DUTY_SCALAR,
    PWM_DUTY_TIME
} PWM_DutyMode;

/*!
 *  @brief
 *  Definitions for various PWM output polarity.
 */
typedef enum PWM_Polarity {
    PWM_POL_ACTIVE_HIGH = 0,  /*!< PWM output active high */
    PWM_POL_ACTIVE_LOW  = 1   /*!< PWM output active low */
} PWM_Polarity;

/*!
 *  @brief PWM Parameters
 *
 *  PWM Parameters are used to with the PWM_open() call. Default values for
 *  these parameters are set using PWM_Params_init().
 *
 *  @sa     PWM_Params_init()
 */
typedef struct PWM_Params {
    uint32_t     period;         /*!< PWM period in microseconds */
    PWM_DutyMode dutyMode;       /*!< Units which duty is specified */
    PWM_Polarity polarity;       /*!< Set duty active high or active low */
    void        *custom;         /*!< Custom argument used by driver
                                      implementation */
} PWM_Params;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_close().
 */
typedef void         (*PWM_CloseFxn)             (PWM_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_control().
 */
typedef int          (*PWM_ControlFxn)           (PWM_Handle handle,
                                                  unsigned int cmd,
                                                  void *arg);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_getPeriodCounts().
 */
typedef unsigned int (*PWM_GetPeriodCountsFxn)   (PWM_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_getPeriodMicroSecs().
 */
typedef unsigned int (*PWM_GetPeriodMicroSecsFxn)(PWM_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_init().
 */
typedef void         (*PWM_InitFxn)              (PWM_Handle handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_open().
 */
typedef PWM_Handle   (*PWM_OpenFxn)              (PWM_Handle handle,
                                                  PWM_Params *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              PWM_setDuty().
 */
typedef void         (*PWM_SetDutyFxn)           (PWM_Handle handle,
                                                  uint32_t duty);

/*!
 *  @brief      The definition of a PWM function table that contains the
 *              required set of functions to control a specific PWM driver
 *              implementation.
 */
typedef struct PWM_FxnTable {
    /*! Function to close the specified peripheral */
    PWM_CloseFxn                 closeFxn;

    /*! Function to driver implementation specific control function */
    PWM_ControlFxn               controlFxn;

    /*! Function to get period in timer counts from the specified peripheral */
    PWM_GetPeriodCountsFxn       getPeriodCountsFxn;

    /*! Function to get period in microseconds from the specified peripheral */
    PWM_GetPeriodMicroSecsFxn    getPeriodMicroSecsFxn;

    /*! Function to initialize the given data object */
    PWM_InitFxn                  initFxn;

    /*! Function to open the specified peripheral */
    PWM_OpenFxn                  openFxn;

    /*! Function to set the duty cycle for a specific peripheral */
    PWM_SetDutyFxn               setDutyFxn;
} PWM_FxnTable;

/*!
 *  @brief  PWM Global configuration
 *
 *  The PWM_Config structure contains a set of pointers used to characterize
 *  the PWM driver implementation.
 *
 *  This structure needs to be defined before calling PWM_init() and it must
 *  not be changed thereafter.
 *
 *  @sa     PWM_init()
 */
typedef struct PWM_Config {
    /*! Pointer to a table of driver-specific implementations of PWM APIs */
    PWM_FxnTable const *fxnTablePtr;

    /*! Pointer to a driver specific data object */
    void               *object;

    /*! Pointer to a driver specific hardware attributes structure */
    void         const *hwAttrs;
} PWM_Config;

/*!
 *  @brief  Function to close a PWM peripheral specified by the PWM handle
 *
 *  @pre    PWM_open() has to be called first.
 *
 *  @param  handle A PWM handle returned from PWM_open()
 *
 *  @sa     PWM_open()
 */
extern void PWM_close(PWM_Handle handle);

/*!
 *  @brief  Function performs implementation specific features on a given
 *          PWM_Handle.
 *
 *  @pre    PWM_open() has to be called first.
 *
 *  @param  handle      A PWM handle returned from PWM_open()
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
 *  @sa     PWM_open()
 */
extern int PWM_control(PWM_Handle handle, unsigned int cmd, void *arg);

/*!
 *  @brief  Get the PWM handle period in timer counts.
 *
 *  @param  handle          A PWM_Handle
 *
 *  @return Period in timer counts.
 *
 *  @sa     PWM_open
 */
extern unsigned int PWM_getPeriodCounts(PWM_Handle handle);

/*!
 *  @brief  Get the PWM handle period in microseconds.
 *
 *  @param  handle          A PWM_Handle
 *
 *  @return Period in microseconds.
 *
 *  @sa     PWM_open
 */
extern unsigned int PWM_getPeriodMicroSecs(PWM_Handle handle);

/*!
 *  @brief  This function initializes the PWM module.
 *
 *  @pre    The PWM_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other PWM driver APIs. This function call does not modify any
 *          peripheral registers.
 */
extern void PWM_init(void);

/*!
 *  @brief  This function opens a given PWM peripheral.
 *
 *  @pre    PWM controller has been initialized using PWM_init()
 *
 *  @param  index         Logical peripheral number for the PWM indexed into
 *                        the PWM_config table
 *
 *  @param  params        Pointer to an parameter block, if NULL it will use
 *                        default values. All the fields in this structure are
 *                        RO (read-only).
 *
 *  @return A PWM_Handle on success or a NULL on an error or if it has been
 *          opened already.
 *
 *  @sa     PWM_init()
 *  @sa     PWM_close()
 */
extern PWM_Handle PWM_open(unsigned int index, PWM_Params *params);

/*!
 *  @brief  Function to initialize the PWM_Params struct to its defaults
 *
 *  @param  params      An pointer to PWM_Params structure for
 *                      initialization
 *
 *  Defaults values are:
 *      period   = 10000 (microseconds)
 *      dutyMode = PWM_DUTY_TIME
 *      polarity = PWM_POL_ACTIVE_HIGH
 */
extern void PWM_Params_init(PWM_Params *params);

/*!
 *  @brief  Function to set the duty cycle of the specified PWM handle.
 *
 *  @param  handle    A PWM_Handle
 *
 *  @param  duty      PWM duty cycle.
 *
 *  @sa     PWM_open
 */
extern void PWM_setDuty(PWM_Handle handle, uint32_t duty);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_PWM__include */
