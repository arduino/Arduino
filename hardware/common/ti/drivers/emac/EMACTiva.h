/*
 * Copyright (c) 2014-2015, Texas Instruments Incorporated
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
 *  @file       EMACTiva.h
 *
 *  @brief      EMACTiva Driver
 *
 *  The EMACTiva header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/EMAC.h>
 *  #include <ti/drivers/emac/EMACTiva.h>
 *  @endcode
 *
 *  The EMACTiva driver produces log statements using the instrumented library.
 *  The following masks are used:
 *   - Diags_USER1 mask logs basic information (started, stopped,
 *     dropped packet, etc.)
 *   - Diags_USER2 mask logs more detailed information (received/sent
 *     packet, etc.)
 *
 *  ============================================================================
 */

#ifndef ti_drivers_emac_EMACTiva__include
#define ti_drivers_emac_EMACTiva__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/sysbios/knl/Swi.h>

#ifndef _INCLUDE_NIMU_CODE
#define _INCLUDE_NIMU_CODE
#endif
#include <ti/ndk/inc/stkmain.h>

/*! @brief  EMACTiva function table */
extern const EMAC_FxnTable EMACTiva_fxnTable;

/*!
 *  @brief  EMACTiva Hardware attributes
 */
typedef struct EMACTiva_HWAttrs {
    unsigned int intNum;         /*!< Interrupt Vector Id */
    unsigned int intPriority;    /*!< Interrupt priority */
    uint8_t *macAddress;         /*!< Pointer to MAC address */
} EMACTiva_HWAttrs;

/*!
 *  @brief  EMACTiva Object
 *
 *  This structure should not be directly accessed. It is specified
 *  here to allow the application to supply the needed memory to the
 *  EMACTiva module.
 */
typedef struct EMACTiva_Object {
    Swi_Handle      swi;
    Hwi_Handle      hwi;
    uint32_t        rxCount;
    uint32_t        rxDropped;
    uint32_t        txSent;
    uint32_t        txDropped;
    uint32_t        linkUp;
    PBMQ            PBMQ_tx;
    PBMQ            PBMQ_rx;
    STKEVENT_Handle hEvent;
} EMACTiva_Object;

/*!
 *  @brief  This function sets the EMACTiva driver
 *
 *  This function must be called before the NDK stack thread is started.
 *
 *  The EMAC_config structure must be present and initialized before this function
 *  is called.
 */
extern void EMACTiva_init(uint32_t index);

/*!
 *  @brief  This function returns if the link is up
 *
 *  @return true is the link is up. false if it is down.
 */
extern bool EMACTiva_isLinkUp(uint32_t index);

/*!
 *  @brief  This function is needed in the NIMUDeviceTable that is required
 *          by the NDK.
 */
extern int EMACTiva_NIMUInit(STKEVENT_Handle hEvent);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_emac_EMACTiva__include */
