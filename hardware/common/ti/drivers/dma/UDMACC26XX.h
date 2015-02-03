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
 *  @file       UDMACC26XX.h
 *
 *  @brief      UDMACC26XX driver
 *
 *  The UDMACC26XX header file should be included in an application as follows:
 *  @code
 *  #include <ti/drivers/dma/UDMACC26XX.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  ============================================================================
 */

#ifndef ti_drivers_UDMACC26XX__include
#define ti_drivers_UDMACC26XX__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct UDMACC26XX_Object {
    /* UDMA pre- and post notification functions */
    void             *udmaPreFxn;   /*!< UDMA pre-notification function pointer */
    void             *udmaPostFxn;  /*!< UDMA post-notification function pointer */
    Power_NotifyObj  udmaPreObj;    /*!< UDMA pre-notification object  */
    Power_NotifyObj  udmaPostObj;   /*!< UDMA post-notification object   */

    bool             isOpen;           /*!< Flag for open/close status */
    bool             isInitialized;    /*!< Flag for initialization status */
    ti_sysbios_family_arm_m3_Hwi_Struct hwi;  /*!< Embedded Hwi Object */
} UDMACC26XX_Object;

/*!
 *  @brief  UDMACC26XX hardware attributes
 */
typedef struct UDMACC26XX_HWAttrs {
    unsigned long   baseAddr;    /*!< Base adddress for UDMACC26XX */
    unsigned int    intNum;      /*!< UDMACC26XX error interrupt number */
    unsigned long   powerMngrId; /*!< UDMACC26XX Peripheral's power manager ID */
} UDMACC26XX_HWAttrs;

/*!
 *  @brief      UDMACC26XX Global configuration
 */
typedef struct UDMACC26XX_Config {
    void              *object;            /*!< Pointer to UDMACC26XX object */
    void const        *hwAttrs;           /*!< Pointer to hardware attribute */
} UDMACC26XX_Config;

/*!
 *  @brief      A handle that is returned from a UDMACC26XX_open() call.
 */
typedef struct UDMACC26XX_Config      *UDMACC26XX_Handle;

/* Extern'd hwiIntFxn */
extern void UDMACC26XX_hwiIntFxn(UArg callbacks);

/*!
 *  @brief      Initializes the driver.
 */
extern void UDMACC26XX_init();

/*!
 *  @brief      Powers up the UDMACC26XX module.
 */
extern void UDMACC26XX_open();

/*!
 *  @brief      Configures the UDMA to perform a basic transfer.
 */
extern void UDMACC26XX_basicTransfer(uint32_t channelIndex, uint32_t channelControlOptions,
                                     void *sourceAddress, void *destinationAddress, uint16_t transferSize);

/*!
 *  @brief      Checks if the current channel is done.
 */
bool UDMACC26XX_transferDone(uint32_t channelIndex);

/*!
 *  @brief      Cancels current transfer and returns number of remaining bytes.
 */
uint32_t UDMACC26XX_cancelTransfer(uint32_t channelIndex);

/*!
 *  @brief      Clears the UDMA done interrupt.
 */
void UDMACC26XX_clearInterrupt(uint32_t channelIndex);

/*!
 *  @brief      Powers down the UDMACC26XX module.
 */
extern void UDMACC26XX_close();

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_UDMACC26XX__include */
