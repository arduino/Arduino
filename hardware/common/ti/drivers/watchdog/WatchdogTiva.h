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
 *  @file       WatchdogTiva.h
 *
 *  @brief      Watchdog driver implementation for Tiva
 *
 *  The Watchdog header file for Tiva should be included in an application
 *  as follows:
 *  @code
 *  #include <ti/drivers/Watchdog.h>
 *  #include <ti/drivers/watchdog/WatchdogTiva.h>
 *  @endcode
 *
 *  This Watchdog driver implementation is designed to operate on a Tiva
 *  device. Once opened, Tiva Watchdog will count down from the reload
 *  value specified in the WatchdogTiva_HWAttrs. If it times out, the
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

#ifndef ti_drivers_watchdog_WatchdogTiva__include
#define ti_drivers_watchdog_WatchdogTiva__include

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

/*! @brief  Watchdog function table for Tiva */
extern const Watchdog_FxnTable WatchdogTiva_fxnTable;

/*!
 *  @brief  Watchdog hardware attributes for Tiva
 */
typedef struct WatchdogTiva_HWAttrs {
    unsigned int baseAddr;       /*!< Base adddress for Watchdog */
    unsigned int intNum;         /*!< WDT interrupt number */
    unsigned int intPriority;    /*!< WDT interrupt priority */
    uint32_t     reloadValue;    /*!< Reload value for Watchdog */
} WatchdogTiva_HWAttrs;

/*!
 *  @brief      Watchdog Object for Tiva
 *
 *  Not to be accessed by the user.
 */
typedef struct WatchdogTiva_Object {
    bool         isOpen;              /* Flag for open/close status */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;  /* Embedded Hwi Object */
} WatchdogTiva_Object;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_watchdog_WatchdogTiva__include */
