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
 *  @file       WatchdogCC26XX.h
 *
 *  @brief      Watchdog driver implementation for CC26XX
 *
 *  # Driver include #
 *  The Watchdog header file for CC26XX should be included in an application
 *  as follows:
 *  @code
 *  #include <ti/drivers/Watchdog.h>
 *  #include <ti/drivers/watchdog/WatchdogCC26XX.h>
 *  @endcode
 *
 *  # Overview #
 *  ## Note that the watchdog driver has not been fully validated, and thus should be considered experimental. ##
 *
 *  The general SPI API should be used in application code, i.e. SPI_open()
 *  should be used instead of SPICC26XXDMA_open(). The board file will define the device
 *  specific config, and casting in the general API will ensure that the correct
 *  device specific functions are called.
 *
 *  # General Behavior #
 *  This Watchdog driver implementation is designed to operate on a CC26XX
 *  device. Once opened, CC26XX Watchdog will count down from the reload
 *  value specified in the WatchdogCC26XX_HWAttrs. If it times out, the
 *  Watchdog interrupt flag will be set, and a user-provided callback function
 *  will be called. If resets have been enabled in the Watchdog_Params and
 *  the Watchdog Timer is allowed to time out again while the interrupt flag is
 *  still pending, a reset signal will be generated. To prevent a reset,
 *  Watchdog_clear() must be called to clear the interrupt flag.
 *
 *  The reload value from which the Watchdog Timer counts down may be changed
 *  during runtime using Watchdog_setReload().
 *
 *  Watchdog_close() is <b>not</b> supported by this driver implementation.
 *
 *  By default the Watchdog driver has resets turned on. However, they may be
 *  turned off in the Watchdog_Params which allows the Watchdog Timer to be
 *  used like another timer interrupt. This functionality is <b>not</b> supported by
 *  all platforms, refer to device specific documentation for details.
 *
 *  # Error handling #
 *  Tbd
 *
 *  # Power Management #
 *  Tbd
 *
 *  # Supported Functions #
 *  Tbd
 *
 *  # Use Cases #
 *  To have a user-defined function run at the warning interrupt, first define
 *  a void-type function that takes a Watchdog_Handle cast to a UArg as an
 *  argument such as the one shown below.
 *
 *  @code
 *  void callback(UArg handle);
 *
 *  ...
 *
 *  Watchdog_Handle handle;
 *  Watchdog_Params params;
 *
 *  Watchdog_Params_init(&params);
 *  params.callbackFxn = callback;
 *  handle = Watchdog_open(Watchdog_configIndex, &params);
 *  @endcode
 *  ============================================================================
 */

#ifndef ti_drivers_watchdog_WatchdogCC26XX__include
#define ti_drivers_watchdog_WatchdogCC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/Watchdog.h>
/*
 * The following allows this header file to be included in an application file
 * which also includes ti/sysbios/hal/Hwi.h.
 */
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>

/*! @brief  Watchdog function table for CC26XX */
extern const Watchdog_FxnTable WatchdogCC26XX_fxnTable;

/*!
 *  @brief  Watchdog hardware attributes for CC26XX
 */
typedef struct WatchdogCC26XX_HWAttrs {
    unsigned int baseAddr;       /*!< Base adddress for Watchdog */
    unsigned int intNum;         /*!< WDT interrupt number */
} WatchdogCC26XX_HWAttrs;

/*!
 *  @brief      Watchdog Object for CC26XX
 *
 *  Not to be accessed by the user.
 */
typedef struct WatchdogCC26XX_Object {
    bool                isOpen;             /*!< Flag for open/close status */
    unsigned long       reloadValue;        /*!< Reload value for Watchdog */
    Watchdog_Callback   callbackFxn;        /*!< Pointer to callback. Not supported
                                                 on all targets. */
    Watchdog_ResetMode  resetMode;          /*!< Mode to enable resets.
                                                  Not supported on all targets. */
    Watchdog_DebugMode  debugStallMode;     /*!< Mode to stall WDT at breakpoints.
                                                  Not supported on all targets. */
    /* WatchDog pre- and post notification functions */
    void                *watchdogPreFxn;    /*!< Watchdog Pre-notify function pointer. */
    void                *watchdogPostFxn;   /*!< Watchdog Post-notify function pointer. */
    Power_NotifyObj     watchdogPreObj;     /*!< Watchdog Pre-notify object. */
    Power_NotifyObj     watchdogPostObj;    /*!< Watchdog Post-notify object. */

    /* Watchdog SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;  /*!< Embedded Hwi Object */
} WatchdogCC26XX_Object;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_watchdog_WatchdogCC26XX__include */
