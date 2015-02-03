/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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
 *  @file       AESCC26XX.h
 *
 *  @brief      AES driver implementation for a CC26XX AES controller
 *
 *  The AES header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/AES.h>
 *  #include <ti/drivers/aes/AESCC26XX.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_drivers_crypto_AESCC26XX__include
#define ti_drivers_crypto_AESCC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/drivers/AES.h>
/*
 * The following allows this header file to be included in an application file
 * which also includes ti/sysbios/hal/Hwi.h.
 */
#define ti_sysbios_family_arm_m3_Hwi__nolocalnames
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>

/* AES function table pointer */
extern const AES_FxnTable AESCC26XX_fxnTable;

/* Return codes for AES_control() */
#define AESCC26XX_CMD_UNDEFINED      -1

/*!
 *  @brief      AESCC26XX Hardware attributes
 *
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions. For CC26XXWare these definitions are found in:
 *      - inc/hw_memmap.h
 *      - inc/hw_ints.h
 *
 *  A sample structure is shown below:
 *  @code
 *  const AESCC26XX_HWAttrs cryptoCC26XXHWAttrs[] = {
 *      {
 *          CRYPTO_BASE,
 *          INT_CRYPTO,
 *          PERIPH_CRYPTO
 *      }
 *  };
 *  @endcode
 */
typedef struct AESCC26XX_HWAttrs {
    /*! AES Peripheral's base address */
    unsigned long baseAddr;
    /*! AES Peripheral's interrupt vector */
    int           intNum;
    /*! AES Peripheral's power manager ID */
    unsigned long powerMngrId;
} AESCC26XX_HWAttrs;

/*!
 *  @brief      AESCC26XX Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct AESCC26XX_Object {
    /* AES control variables */
    bool                opened;           /*!< Has the obj been opened */
    AES_Mode            mode;             /*!< Mode for all read calls */
    uint32_t            timeout;          /*!< Timeout for semaphore */
    bool                inuse;            /*!< used to block for multiple use */

    /* AES pre- and post notification functions */
    void             *aesPreFxn;
    void             *aesPostFxn;
    Power_NotifyObj   aesPreObj;
    Power_NotifyObj   aesPostObj;

    /* AES SYS/BIOS objects */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi; /*!< Hwi object */
    Semaphore_Struct    sem;                 /*!< AES write semaphore*/
} AESCC26XX_Object, *AESCC26XX_Handle;

/* Do not interfere with the app if they include the family Hwi module */
#undef ti_sysbios_family_arm_m3_Hwi__nolocalnames

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_crypto_AESCC26XX__include */
