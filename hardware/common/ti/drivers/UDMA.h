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
 *  @file       UDMA.h
 *
 *  @brief      UDMA driver
 *
 *  The UDMA header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/UDMA.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  ============================================================================
 */

#ifndef ti_drivers_UDMA__include
#define ti_drivers_UDMA__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct UDMA_Object {
    /* UART pre- and post notification functions */
    void                *udmaPreFxn;
    void                *udmaPostFxn;
    Power_NotifyObj     udmaPreObj;
    Power_NotifyObj     udmaPostObj;

    bool                isOpen;               /*!< Flag for open/close status */
    bool                isInitialized;        /*!< Flag for initialization status */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;  /*!< Embedded Hwi Object */
} UDMA_Object;

/*!
 *  @brief  UDMA hardware attributes
 */
typedef struct UDMA_HWAttrs {
    unsigned long   baseAddr;       /*!< Base adddress for UDMA */
    unsigned int    intNum;         /*!< UDMA error interrupt number */
    unsigned long   powerMngrId;    /*!< UDMA Peripheral's power manager ID */
} UDMA_HWAttrs;

/*!
 *  @brief      UDMA Global configuration
 */
typedef struct UDMA_Config {
    void              *object;            /*!< Pointer to UDMA object */
    void const        *hwAttrs;           /*!< Pointer to hardware attribute */
} UDMA_Config;

/*!
 *  @brief      A handle that is returned from a UDMA_open() call.
 */
typedef struct UDMA_Config      *UDMA_Handle;

/* Extern'd hwiIntFxn */
extern void UDMA_hwiIntFxn(UArg callbacks);

/*!
 *  @brief      Initializes the driver.
 */
extern void UDMA_init();

/*!
 *  @brief      Powers up the UDMA module.
 */
extern void UDMA_open();

/*!
 *  @brief      Powers down the UDMA module.
 */
extern void UDMA_close();

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_UDMA__include */
