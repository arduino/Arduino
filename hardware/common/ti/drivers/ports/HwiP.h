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
 *  @brief    Status codes for HwiP APIs
 */
typedef enum HwiP_Status {
    HwiP_OK = 0,
    HwiP_FAILURE = -1
} HwiP_Status;

/*!
 *  @brief  Prototype for the entry function for a hardware interrupt
 */
typedef void (*HwiP_EntryFxn)(uintptr_t arg);

/*!
 *  @brief  Function to register an interrupt on CortexM devices
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 *
 *  @param  entry entry function of the hardware interrupt
 *
 *  @param  arg  argument passed into hte entry function
 *
 *  @param  priority
 *
 *  @return
 */
extern HwiP_Status HwiP_registerCortexM(int interruptNum,
                                        HwiP_EntryFxn entry,
                                        uintptr_t arg,
                                        unsigned char priority);

/*!
 *  @brief  Function to deregister a interrupt on CortexM devices
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 *
 *  @return
 */
extern HwiP_Status HwiP_deregisterCortexM(int interruptNum);

/*!
 *  @brief  Function to clear a single interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 */
extern void HwiP_clearCortexM(int interruptNum);

/*!
 *  @brief  Function to disable a single interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 */
extern void HwiP_disableCortexM(int interruptNum);

/*!
 *  @brief  Function to enable a single interrupt
 *
 *  TODO more detail
 *
 *  @param  interruptNum
 */
extern void HwiP_enableCortexM(int interruptNum);

/*!
 *  @brief  Function to disable interrupts to enter a critical region
 *
 *  TODO more details
 *
 *  @return todo key
 */
extern unsigned int HwiP_enterCritical(void);

/*!
 *  @brief  Function to restore interrupts to exit a critical region
 *
 *  TODO more details
 *
 *  @param  key
 */
extern void HwiP_exitCritical(unsigned int key);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_ports_HwiP__include */
