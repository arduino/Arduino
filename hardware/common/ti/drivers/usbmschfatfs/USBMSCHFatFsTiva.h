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
 *  @file       USBMSCHFatFsTiva.h
 *
 *  @brief      USBMSCHFatFs driver implementation for a Tiva USB
 *              controller used with the USBMSCHFatFs driver.
 *
 *  The USBMSCHFatFs header file should be included in an application as
 *  follows:
 *  @code
 *  #include <ti/drivers/USBMSCHFatFs.h>
 *  #include <ti/drivers/usbmschfatfs/USBMSCHFatFsTiva.h>
 *  @endcode
 *
 *  This USBMSCHFatFs driver implementation is designed to operate with a
 *  Tiva' USB library. Only 1 instance of the USBMSCHFatFsTiva driver
 *  is supported.
 *
 *  ============================================================================
 */

#ifndef ti_drivers_usbmschfatfs_USBMSCHFatFsTiva__include
#define ti_drivers_usbmschfatfs_USBMSCHFatFsTiva__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drivers/USBMSCHFatFs.h>

#include <ti/sysbios/gates/GateMutex.h>

#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/fatfs/ff.h>
#include <ti/sysbios/fatfs/diskio.h>

#if defined(TIVAWARE)
#include <usblib/host/usbhmsc.h>
typedef tUSBHMSCInstance   *USBMSCType;
#else /* MWARE */
typedef unsigned long       USBMSCType;
#endif

/* Memory for the Host Class Driver */
#define HCDMEMORYPOOLSIZE   128

/* USBMSCHFatFs function table */
extern const USBMSCHFatFs_FxnTable USBMSCHFatFsTiva_fxnTable;

/*!
 *  @brief      USBMSCHFatFsTiva_USBState
 */
typedef enum USBMSCHFatFsTiva_USBState {
    USBMSCHFatFsTiva_NO_DEVICE,        /*!< No device is present. */

    USBMSCHFatFsTiva_CONNECTED,        /*!<
                                             *   Mass storage device is being
                                             *   enumerated.
                                             */

    USBMSCHFatFsTiva_UNKNOWN,          /*!<
                                             *   An unsupported device has been
                                             *   attached.
                                             */

    USBMSCHFatFsTiva_POWER_FAULT /*!< A power fault has occurred. */
} USBMSCHFatFsTiva_USBState;

/*!
 *  @brief      USBMSCHFatFsTiva Hardware attributes
 */
typedef struct USBMSCHFatFsTiva_HWAttrs {
    unsigned int       intNum;             /*!< USB interrupt vector */
    unsigned int       intPriority;        /*!< USB interrupt priority */
} USBMSCHFatFsTiva_HWAttrs;

/*!
 *  @brief      USBMSCHFatFsTiva Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct USBMSCHFatFsTiva_Object {
    uint32_t            driveNumber;        /*!< Drive number used by FatFs */
    USBMSCHFatFsTiva_USBState volatile state; /*!< USB state */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /*!< Hwi handle */
    Task_Struct         taskHCDMain;        /*!< Task handle */
    GateMutex_Struct    gateUSBWait;        /*!< Gate handle */
    GateMutex_Struct    gateUSBLibAccess;   /*!< Gate handle */
    Semaphore_Struct    semUSBConnected;    /*!< Semaphore handle */
    USBMSCType          MSCInstance;        /*!< USB MSC instance handle */
    uint8_t             memPoolHCD[HCDMEMORYPOOLSIZE]; /* MSC memory buffer */
    FATFS               filesystem;         /*!< FATFS data object */
} USBMSCHFatFsTiva_Object, *USBMSCHFatFsTiva_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_usbmschfatfs_USBMSCHFatFsTiva__include */
