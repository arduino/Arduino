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
 *  @file       Power.h
 *
 *  @brief      Power manager interface
 *
 *  The Power header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/Power.h>
 *  @endcode
 *
 *  # Operation #
 *  The Power manager facilitates the transition of the MCU from active state
 *  to one of the sleep states and vice versa.  It provides drivers the
 *  ability to set and release dependencies on hardware resources and keeps
 *  a reference count on each resource to know when to enable or disable the
 *  peripheral clock to the resource.  It provides drivers the ability to
 *  register a callback function upon a specific power event.  In addition,
 *  drivers and apps can set or release constraints to prevent the MCU from
 *  transitioning into a particular sleep state.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_Power__include
#define ti_drivers_Power__include

#include <stdint.h>
#include <ti/drivers/ports/ListP.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Power latency types */
#define Power_TOTAL                 1   /*!< total latency */
#define Power_RESUME                2   /*!< resume latency */

/* Power notify responses */
#define Power_NOTIFYDONE            0   /*!< OK, notify completed */
#define Power_NOTIFYERROR           1   /*!< an error occurred during notify */

/* Power status */
#define Power_SOK                   0   /*!< OK, operation succeeded */
#define Power_EFAIL                 1   /*!< general failure */
#define Power_EINVALIDPOINTER       2   /*!< invalid pointer */
#define Power_ECHANGE_NOT_ALLOWED   3   /*!< change is not allowed */
#define Power_EBUSY                 4   /*!< busy with another transition */

/* Power transition states */
#define Power_ACTIVE                1   /*!< normal active state */
#define Power_ENTERING_SLEEP        2   /*!< entering a sleep state */
#define Power_EXITING_SLEEP         3   /*!< exiting a sleep state */
#define Power_ENTERING_SHUTDOWN     4   /*!< entering a shutdown state */
#define Power_CHANGING_PERF_LEVEL   5   /*!< moving to new performance level */


/*!
 *  @brief      Power policy initialization function pointer
 */
typedef void (*Power_PolicyInitFxn)(void);

/*!
 *  @brief      Power policy function pointer
 */
typedef void (*Power_PolicyFxn)(void);

/*!
 *  @brief      Power notify function pointer
 */
typedef int (*Power_NotifyFxn)(unsigned int eventType, uintptr_t eventArg,
                               uintptr_t clientArg);

/*!
 *  @brief      Power notify object structure.
 *
 *  This struct specification is for internal use.  Notification clients must
 *  pre-allocate a notify object when registering for a notification;
 *  Power_registerNotify() will take care initializing the internal elements
 *  appropriately.
 */
typedef struct Power_NotifyObj {
    ListP_Elem link;            /*!< for placing on the notify list */
    unsigned int eventTypes;        /*!< the event type */
    Power_NotifyFxn notifyFxn;  /*!< notification function */
    uintptr_t clientArg;        /*!< argument provided by client */
} Power_NotifyObj;

/*!
 *  @brief  Enable the configured power policy to run when the CPU is idle
 */
void Power_enablePolicy(void);

/*!
 *  @brief  Get the constraints that have been declared with Power
 *
 *  @return A bitmask of declared constraints
 *
 *  @sa     Power_setContraint
 */
unsigned int Power_getConstraintMask(void);

/*!
 *  @brief  Get the current dependency count for a resource
 *
 *  @param  resourceId  resource id
 *
 *  @return dependency count on resource
 *
 *  @sa     Power_setDependency
 */
unsigned int Power_getDependencyCount(unsigned int resourceId);

/*!
 *  @brief  Get the current performance level
 */
unsigned int Power_getPerformanceLevel(void);

/*!
 *  @brief  Get the hardware transition latency for a sleep state
 *
 *  The latency is reported in units of microseconds.
 *  This function is called by the power policy function.
 *  The latency for any software-based notifications is not included in
 *  the returned value.
 *
 *  @param  sleepState  the sleep state
 *
 *  @param  type        the latency type {Power_TOTAL, Power_RESUME}
 *
 *  @return the latency value in units of microseconds
 */
uint32_t Power_getTransitionLatency(unsigned int sleepState, unsigned int type);

/*!
 *  @brief  Get the current transition state for Power
 *
 *  This function returns the current transition state for the power manager.
 *  For example, when no transitions are in progress, a status of Power_ACTIVE
 *  is returned; when the device is being transitioned into a sleep state,
 *  the status Power_ENTERING_SLEEP is returned, etc.
 *
 *  @return the current power transition state
 */
unsigned int Power_getTransitionState(void);

/*!
 *  @brief  Power function to be added to the application idle loop
 *
 *  Add this function to the application's idle loop. (The method to do this
 *  depends upon the operating system being used.)  When invoked, this
 *  function will call the configured power policy function, once on each
 *  pass through the idle loop.  The specific policy function to be called
 *  is configured as the 'policyFxn' in the application-defined Power
 *  configuration object.
 */
void Power_idleFunc(void);

/*!
 *  @brief  Power initialization function
 *
 *  This function initializes Power manager internal state.  It must be called
 *  prior to any other Power API.
 */
void Power_init(void);

/*!
 *  @brief  Register a function to be called upon a specific power event
 *
 *  @param  pNotifyObj      notification object (preallocated by caller)
 *
 *  @param  eventTypes      event type
 *
 *  @param  notifyFxn       client's callback function
 *
 *  @param  clientArg       client-specified argument to pass with notification
 *
 *  @return status
 *
 *  @sa     Power_unregisterNotify
 */
unsigned int Power_registerNotify(Power_NotifyObj *pNotifyObj,
    unsigned int eventTypes, Power_NotifyFxn notifyFxn, uintptr_t clientArg);

/*!
 *  @brief  Release a previously declared constraint
 *
 *  @param  constraintId      constraint id
 *
 *  @sa     Power_setContraint
 */
void Power_releaseConstraint(unsigned int constraintId);

/*!
 *  @brief  Release a previously declared dependency
 *
 *  @param  resourceId      resource id
 *
 *  @sa     Power_setDependency
 */
void Power_releaseDependency(unsigned int resourceId);

/*!
 *  @brief  Declare an operational constraint
 *
 *  Only one constraint can be specified with each call to this function; to
 *  declare multiple constraints this function must be called multiple times.
 *
 *  @param  constraintId      constraint id
 *
 *  @sa     Power_releaseContraint
 */
void Power_setConstraint(unsigned int constraintId);

/*!
 *  @brief  Declare a dependency upon a resource
 *
 *  @param  resourceId      resource id
 *
 *  @sa     Power_releaseDependency
 */
void Power_setDependency(unsigned int resourceId);

/*!
 *  @brief  Set the MCU performance level
 *
 *  This function manages a transition to a new MCU performance level.  The
 *  function will not return until the new performance level is in effect.
 *  If performance scaling is not supported for the device, or is prohibited
 *  by an active constraint, or if the specified level is invalid, then a
 *  status of Power_ECHANGE_NOT_ALLOWED will returned.
 *
 *  @param  level      the new performance level
 *
 *  @sa     Power_getPerformanceLevel
 *
 *  @return status
 */
unsigned int Power_setPerformanceLevel(unsigned int level);

/*!
 *  @brief  Put the device in a shutdown state
 *
 *  This function will transition the device into a shutdown state.  If a
 *  wakeup trigger is configured, the application will be rebooted (through
 *  a device reset) when the trigger occurs.  On some devices a timed wakeup
 *  can be configured; where this is supported, this time can be specified via
 *  the shutdownTime parameter.
 *
 *  @param  shutdownState  the shutdown state
 *
 *  @param  shutdownTime   amount of time (in milliseconds) to keep the
 *                         the device in the shutdown state
 *
 *  @return status
 */
unsigned int Power_shutdown(unsigned int shutdownState, uint32_t shutdownTime);

/*!
 *  @brief  Transition the device into a sleep state
 *
 *  This function is called from the power policy when it has made a decision
 *  to put the device in a specific sleep state.  This function returns to the
 *  caller (the policy function) once the device has awoken from sleep.
 *  This function must be called with interrupts disabled, and should not be
 *  called directly by the application, or by any drivers.
 *  This function does not check declared constraints; the policy function
 *  must check constraints before calling this function to initiate sleep.
 *
 *  @param  sleepState      the sleep state
 *
 *  @return status
 */
unsigned int Power_sleep(unsigned int sleepState);

/*!
 *  @brief  Unregister previously registered notifications
 *
 *  @param  pNotifyObj    notify object (used when registering for notification)
 */
void Power_unregisterNotify(Power_NotifyObj *pNotifyObj);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_Power__include */
