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
 *  @file       HwiP.h
 *
 *  @brief      Hardware Interrupt interface for the OSAL
 *
 *  TODO...mention key and nesting
 *  ============================================================================
 */

#ifndef ti_drivers_ports_HwiP__include
#define ti_drivers_ports_HwiP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*!
 *  @brief    Opaque client reference to an instance of a HwiP
 *
 *  A HwiP_Handle returned from the ::HwiP_create represents that instance.
 */
typedef  void *HwiP_Handle;

/*!
 *  @brief    Status codes for HwiP APIs
 */
typedef enum HwiP_Status {
    HwiP_OK = 0,
    HwiP_FAILURE = -1
} HwiP_Status;

/*!
 *  @brief  Prototype for the entry function for a hardware interrupt
 */
typedef void (*HwiP_Fxn)(uintptr_t arg);

/*!
 *  @brief    Basic HwiP Parameters
 *
 *  Structure that contains the parameters passed into ::HwiP_create
 *  when creating a HwiP instance. The ::HwiP_Params_init function should
 *  be used to initialize the fields to default values before the application sets
 *  the fields manually. The HwiP default parameters are noted in
 *  HwiP_Params_init.
 */
typedef struct HwiP_Params {
    char      *name;      /*!< Name of the clock instance. Memory must
                               persist for the life of the clock instance.
                               This can be used for debugging purposes, or
                               set to NULL if not needed. */
    uintptr_t  arg;       /*!< Argument passed into the Hwi function. */
    uint32_t   priority;  /*!< Device specific priority. */
} HwiP_Params;

/*!
 *  @brief  Function to register an interrupt on CortexM devices
 *
 *  TODO more detail
 *
 *  @param  interruptNum Interrupt Vector Id
 *
 *  @param  hwiFxn entry function of the hardware interrupt
 *
 *  @param  params    Pointer to the instance configuration parameters. NULL
 *                    denotes to use the default parameters. The HwiP default
 *                    parameters are noted in ::HwiP_Params_init.
 *
 *  @return
 */
extern HwiP_Handle HwiP_create(int interruptNum, HwiP_Fxn hwiFxn,
                               HwiP_Params *params);

/*!
 *  @brief  Function to deregister a interrupt on CortexM devices
 *
 *  TODO more detail
 *
 *  @param  handle returned from the HwiP_create call
 *
 *  @return
 */
extern HwiP_Status HwiP_delete(HwiP_Handle handle);

/*!
 *  @brief  Function to clear a single interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 */
extern void HwiP_clearInterrupt(int interruptNum);

/*!
 *  @brief  Function to disable a single interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 */
extern void HwiP_disableInterrupt(int interruptNum);

/*!
 *  @brief  Function to enable a single interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 */
extern void HwiP_enableInterrupt(int interruptNum);

/*!
 *  @brief  Function to disable interrupts to enter a critical region
 *
 *  TODO more details
 *
 *  @return todo key
 */
extern uintptr_t HwiP_disable(void);

/*!
 *  @brief  Initialize params structure to default values.
 *
 *  The default parameters are:
 *   - name: NULL
 *   - arg: 0
 *   - priority: ~0
 *
 *  @param params  Pointer to the instance configuration parameters.
 */
extern void HwiP_Params_init(HwiP_Params *params);

/*!
 *  @brief  Function to restore interrupts to exit a critical region
 *
 *  TODO more details
 *
 *  @param  key
 */
extern void HwiP_restore(uintptr_t key);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_ports_HwiP__include */
