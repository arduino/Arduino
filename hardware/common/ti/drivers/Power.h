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
    unsigned int eventTypes;    /*!< the event type */
    Power_NotifyFxn notifyFxn;  /*!< notification function */
    uintptr_t clientArg;        /*!< argument provided by client */
} Power_NotifyObj;

/*!
 *  @brief  Enable the configured power policy to run when the CPU is idle
 *
 *  Calling this function sets a flag that will cause the configured power
 *  policy function to be invoked on each pass through the Idle loop. This
 *  runtime function call will essentially override a 'false' setting of the
 *  "enablePolicy" setting in the Power manager configuration object.
 *
 *  For some processor families automatic power transitions are at odds with
 *  the debugger, and having the policy running by default makes application
 *  debug difficult.  This convenience function allows an application to be
 *  initially configured, built, and debugged, without automatic power
 *  transitions during idle time.  When the application is found to be working,
 *  this function can be called (typically in main()) to enable the policy
 *  to run, without having to change the application configuration.  Note that
 *  there is no comparable 'disable' policy function; once the policy has
 *  been enabled to run, it will always run until the applicaiton is rebooted.
 *
 */
void Power_enablePolicy(void);

/*!
 *  @brief  Get the constraints that have been declared with Power
 *
 *  This function returns a bitmask indicating the constraints that are
 *  currently declared to the Power manager (via previous calls to
 *  Power_setConstraint()).  For each constraint that is currently declared,
 *  the corresponding bit in the bitmask will be set.  For example, if two
 *  clients have independently declared two different constraints, the returned
 *  bitmask will have two bits set.
 *
 *  Constraint identifiers are device specific, and defined in the
 *  device-specific Power include file.  For example, the constraints for
 *  MSP432 are defined in PowerMSP432.h.  The corresponding bit in the
 *  bitmask returned by this function can be derived by a left-shift using
 *  the constraint identifier.  For example, for MSP432, for the corresponding
 *  bit for the PowerMSP432_DISALLOW_SLEEP constraint, the bit position is
 *  determined by the operation: (1 << PowerMSP432_DISALLOW_SLEEP)
 *
 *  @return A bitmask of the currently declared constraints.
 *
 *  @sa     Power_setConstraint
 */
unsigned int Power_getConstraintMask(void);

/*!
 *  @brief  Get the current dependency count for a resource
 *
 *  This function returns the number of dependencies that are currently
 *  declared upon a resource.
 *
 *  Resource identifiers are device specific, and defined in the
 *  device-specific Power include file.  For example, the resources for
 *  CC3200 are defined in PowerCC3200.h.
 *
 *  @param  resourceId  resource id
 *
 *  @return The number of dependencies declared upon the resource.
 *
 *  @sa     Power_setDependency
 */
unsigned int Power_getDependencyCount(unsigned int resourceId);

/*!
 *  @brief  Get the current performance level
 *
 *  This function returns the current device performance level in effect.
 *
 *  If performance scaling is not supported for the device, this function
 *  will always indicate a performance level of zero.
 *
 *  @return The current performance level.
 *
 *  @sa     Power_setPerformanceLevel
 */
unsigned int Power_getPerformanceLevel(void);

/*!
 *  @brief  Get the hardware transition latency for a sleep state
 *
 *  This function reports the minimal hardware transition latency for a specific
 *  sleep state.  The reported latency is that for a direct transition, and does
 *  not include any additional latency that might occur due to software-based
 *  notifications.
 *
 *  Sleep states are device specific, and defined in the device-specific Power
 *  include file.  For example, the sleep states for CC3200 are defined in
 *  PowerCC3200.h.
 *
 *  This function is typically called by the power policy function. The latency
 *  is reported in units of microseconds.
 *
 *  @param  sleepState  the sleep state
 *
 *  @param  type        the latency type (Power_TOTAL or Power_RESUME)
 *
 *  @return The latency value, in units of microseconds.
 */
uint32_t Power_getTransitionLatency(unsigned int sleepState, unsigned int type);

/*!
 *  @brief  Get the current transition state of the Power manager
 *
 *  This function returns the current transition state for the Power manager.
 *  For example, when no transitions are in progress, a status of Power_ACTIVE
 *  is returned.  Power_ENTERING_SLEEP is returned during the transition to
 *  sleep, before sleep has occurred. And Power_EXITING_SLEEP will be returned
 *  after wakeup, as the device is being transtioned back to Power_ACTIVE.
 *
 *  @return The current Power manager transition state.
 */
unsigned int Power_getTransitionState(void);

/*!
 *  @brief  Power function to be added to the application idle loop
 *
 *  This function should be added to the application idle loop. (The method to
 *  do this depends upon the operating system being used.)  This function
 *  will invoke the configured power policy function when appropriate. The
 *  specific policy function to be invoked is configured as the 'policyFxn'
 *  in the application-defined Power configuration object.
 *
 */
void Power_idleFunc(void);

/*!
 *  @brief  Power initialization function
 *
 *  This function initializes Power manager internal state.  It must be called
 *  prior to any other Power API.  This function is normally called as part
 *  of TI-RTOS board initialization, for example, from within the
 *  the \<board name\>_initGeneral() function.
 */
void Power_init(void);

/*!
 *  @brief  Register a function to be called upon a specific power event
 *
 *  This function registers a function to be called when a Power event occurs.
 *  Registrations and the corresponding notifications are processed in
 *  first-in-first-out (FIFO) order. The function registered must behave as
 *  described later, below.
 *
 *  The pNotifyObj parameter is a pointer to a pre-allocated, opaque object
 *  that will be used by Power to support the notification.  This object could
 *  be dynamically allocated, or declared as a global object. This function
 *  will properly initialized the object's fields as appropriate; the caller
 *  just needs to provide a pointer to this pre-existing object.
 *
 *  The eventTypes parameter identifies the type of power event(s) for which
 *  the notify function being registered is to be called. (Event identifiers are
 *  device specific, and defined in the device-specific Power include file.
 *  For example, the events for MSP432 are defined in PowerMSP432.h.)  The
 *  eventTypes parameter for this function call is treated as a bitmask, so
 *  multiple event types can be registered at once, using a common callback
 *  function.  For example, to call the specified notifyFxn when both
 *  the entering deepsleep and awake from deepsleep events occur, eventTypes
 *  should be specified as: PowerMSP432_ENTERING_DEEPSLEEP |
 *  PowerMSP432_AWAKE_DEEPSLEEP
 *
 *  The notifyFxn parameter specifies a callback function to be called when the
 *  specified Power event occurs. The notifyFxn must implement the following
 *  signature:
 *       status = notifyFxn(eventType, eventArg, clientArg);
 *
 *  Where: eventType identifies the event being signalled, eventArg is an
 *  optional event-specific argument, and clientArg is an abitrary argument
 *  specified by the client at registration.  Note that multipe types of events
 *  can be specified when registering the notification callback function,
 *  but when the callback function is actually called by Power, only a
 *  single eventType will be specified for the callback (i.e., the current
 *  event).  The status returned by the client notification function must
 *  be one of the following constants: Power_NOTIFYDONE if the client processed
 *  the notification successfully, or Power_NOTIFYERROR if an error occurred
 *  during notification.
 *
 *  The clientArg parameter is an arbitrary, client-defined argument to be
 *  passed back to the client upon notification. This argument may allow one
 *  notify function to be used by multiple instances of a driver (that is, the
 *  clientArg can be used to identify the instance of the driver that is being
 *  notified).
 *
 *  @param  pNotifyObj      notification object (preallocated by caller)
 *
 *  @param  eventTypes      event type or types
 *
 *  @param  notifyFxn       client's callback function
 *
 *  @param  clientArg       client-specified argument to pass with notification
 *
 *  @return  Power_SOK
 *
 *  @sa     Power_unregisterNotify
 */
unsigned int Power_registerNotify(Power_NotifyObj *pNotifyObj,
                                  unsigned int eventTypes,
                                  Power_NotifyFxn notifyFxn,
                                  uintptr_t clientArg);

/*!
 *  @brief  Release a previously declared constraint
 *
 *  This function releases a constraint that was previously declared with
 *  Power_setConstraint().  For example, if a device driver is starting an I/O
 *  transaction and wants to prohibit activation of a sleep state during the
 *  transaction, it uses Power_setConstraint() to declare the constraint,
 *  before starting the transaction.  When the transaction completes, the
 *  driver calls this function to release the constraint, to allow the Power
 *  manager to once again allow transitions to sleep.
 *
 *  Constraint identifiers are device specific, and defined in the
 *  device-specific Power include file.  For example, the constraints for
 *  MSP432 are defined in PowerMSP432.h.
 *
 *  Only one constraint can be specified with each call to this function; to
 *  release multiple constraints this function must be called multiple times.
 *
 *  It is critical that clients call Power_releaseConstraint() when operational
 *  constraints no longer exists. Otherwise, Power may be left unnecessarily
 *  restricted from activating power savings.
 *
 *  @param  constraintId      constraint id
 *
 *  @sa     Power_setConstraint
 */
void Power_releaseConstraint(unsigned int constraintId);

/*!
 *  @brief  Release a previously declared dependency
 *
 *  This function releases a dependency that had been previously declared upon
 *  a resource (by a call to Power_setDependency()).
 *
 *  Resource identifiers are device specific, and defined in the
 *  device-specific Power include file.  For example, the resources for
 *  CC3200 are defined in PowerCC3200.h.
 *
 *  @param  resourceId      resource id
 *
 *  @sa     Power_setDependency
 */
void Power_releaseDependency(unsigned int resourceId);

/*!
 *  @brief  Declare an operational constraint
 *
 *  Before taking certain actions, the Power manager checks to see if the
 *  requested action would conflict with a client-declared constraint. If the
 *  action does conflict, Power will not proceed with the request.  This is the
 *  function that allows clients to declare their constraints with Power.
 *
 *  Constraint identifiers are device specific, and defined in the
 *  device-specific Power include file.  For example, the constraints for
 *  MSP432 are defined in PowerMSP432.h.
 *
 *  Only one constraint can be specified with each call to this function; to
 *  declare multiple constraints this function must be called multiple times.
 *
 *  @param  constraintId      constraint id
 *
 *  @sa     Power_releaseConstraint
 */
void Power_setConstraint(unsigned int constraintId);

/*!
 *  @brief  Declare a dependency upon a resource
 *
 *  This function declares a dependency upon a resource. For example, if a
 *  UART driver needs a specific UART peripheral, it uses this function to
 *  declare this to the Power manager.  If the resource had been inactive,
 *  then Power will activate the peripheral during this function call.
 *
 *  What is needed to make a peripheral resource 'active' will vary by device
 *  family. For some devices this may be a simple enable of a clock to the
 *  specified peripheral.  For others it may also require a power on of a
 *  power domain.  In either case, the Power manager will take care of these
 *  details, and will also implement reference counting for resources and their
 *  interdependencies.  For example, if multiple UART peripherals reside in
 *  a shared serial power domain, the Power manager will power up the serial
 *  domain when it is first needed, and then automatically power the domain off
 *  later, when all related dependencies for the relevant peripherals are
 *  released.
 *
 *  Resource identifiers are device specific, and defined in the
 *  device-specific Power include file.  For example, the resources for
 *  CC3200 are defined in PowerCC3200.h.
 *
 *  @param  resourceId      resource id
 *
 *  @sa     Power_releaseDependency
 */
void Power_setDependency(unsigned int resourceId);

/*!
 *  @brief  Set the MCU performance level
 *
 *  This function manages a transition to a new device performance level.
 *  Before the actual transition is initiated, notifications will be sent to
 *  any clients who've registered (with Power_registerNotify()) for a
 *  'start change performance level' notification.  The event name is device
 *  specific, and defined in the device-specific Power include file.  For
 *  example, for MSP432, the event is "PowerMSP432_START_CHANGE_PERF_LEVEL",
 *  which is defined in PowerMSP432.h.  Once notifications have been completed,
 *  the change to the performance level is initiated.  After the level change
 *  is completed, there is a comparable event that can be used to signal a
 *  client that the change has completed.  For example, on MSP432 the
 *  "PowerMSP432_DONE_CHANGE_PERF_LEVEL" event can be used to signal
 *  completion.
 *
 *  This function will not return until the new performance level is in effect.
 *  If performance scaling is not supported for the device, or is prohibited
 *  by an active constraint, or if the specified level is invalid, then an
 *  error status will be returned.
 *
 *  @param  level      the new performance level
 *
 *  @return Power_SOK on success.  Power_EFAIL if: performance scaling is not
 *      supported, or if the scaling routines encountered an error during
 *      initialization, or if the specified performance level is out of range
 *      of valid levels. Power_EBUSY is returned if the Power manager is
 *      already busy with another transition, or if a single constraint that
 *      locks any performance level changes has been declared.
 *      Power_ECHANGE_NOT_ALLOWED is returned if the requested level has been
 *      explicitly prohibited by a level-specific constraint.
 *
 *  @sa     Power_getPerformanceLevel
 */
unsigned int Power_setPerformanceLevel(unsigned int level);

/*!
 *  @brief  Put the device into a shutdown state
 *
 *  This function will transition the device into a shutdown state.
 *  Before the actual transition is initiated, notifications will be sent to
 *  any clients who've registered (with Power_registerNotify()) for an
 *  'entering shutdown' event.  The event name is device specific, and defined
 *  in the device-specific Power include file.  For example, for CC3200, the
 *  event is "PowerCC3200_ENTERING_SHUTDOWN", which is defined in
 *  PowerCC3200.h.  Once notifications have been completed, the device shutdown
 *  will commmence.
 *
 *  If the device is successfully transitioned to shutdown, this function
 *  call will never return.  Upon wakeup, the device and application will
 *  be rebooted (through a device reset).  If the transition is not
 *  successful, one of the error codes listed below will be returned.
 *
 *  On some devices a timed wakeup from shutdown can be specified, using
 *  the shutdownTime parameter.  This enables an autonomous application reboot
 *  at a future time.  For example, an application can go to shutdown, and then
 *  automatically reboot at a future time to do some work. And once that work
 *  is done, the application can shutdown again, for another timed interval.
 *  The time interval is specified via the shutdownTime parameter. (On devices
 *  that do not support this feature, any value specified for shutdownTime will
 *  be ignored.)  If the specified shutdownTime is less than the total
 *  shutdown latency for the device, then shutdownTime will be ignored.  The
 *  shutdown latency for the device can be found in the device-specific Power
 *  include file.  For example, for the CC3200, this latency is defined in
 *  PowerCC3200.h, as "PowerCC3200_TOTALTIMESHUTDOWN".)
 *
 *  @param  shutdownState  the device-specific shutdown state
 *
 *  @param  shutdownTime   the amount of time (in milliseconds) to keep the
 *                         the device in the shutdown state; this parameter
 *                         is not supported on all device families
 *
 *  @return An error status if the transition did not occur:
 *       Power_ECHANGE_NOT_ALLOWED if the transition is prohibited by a
 *       constraint; Power_EBUSY if the Power manager is already busy with
 *       another transition.
 */
unsigned int Power_shutdown(unsigned int shutdownState, uint32_t shutdownTime);

/*!
 *  @brief  Transition the device into a sleep state
 *
 *  This function is called from the power policy when it has made a decision
 *  to put the device in a specific sleep state.  This function returns to the
 *  caller (the policy function) once the device has awoken from sleep.
 *
 *  This function must be called with interrupts disabled, and should not be
 *  called directly by the application, or by any drivers.
 *  This function does not check declared constraints; the policy function
 *  must check constraints before calling this function to initiate sleep.
 *
 *  @param  sleepState      the sleep state
 *
 *  @return A status code indicating success or failure: Power_SOK if the
 *       device was put to sleep and then awoken; Power_EFAIL if a failure
 *       occurred during client notifications; or Power_EBUSY if the Power
 *       manager is already busy with another transition.
 */
unsigned int Power_sleep(unsigned int sleepState);

/*!
 *  @brief  Unregister previously registered notifications
 *
 *  This function unregisters for event notifications that were previously
 *  registered with Power_registerNotify().  The caller must specify a pointer
 *  to the same notification object used during registration.
 *
 *  @param  pNotifyObj    notify object
 *
 *  @sa     Power_registerNotify
 */
void Power_unregisterNotify(Power_NotifyObj *pNotifyObj);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_Power__include */
