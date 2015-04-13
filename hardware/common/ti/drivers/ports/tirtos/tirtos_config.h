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
/*
 *  ======== tirtos_config.h ========
 *  This file allows a user to modify the behavior of the TI-RTOS
 *  implementation for the driver RTOS port.
 */

#ifndef ti_drivers_ports_tirtos_tirtos_config__include
#define ti_drivers_ports_tirtos_tirtos_config__include

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  Uncomment the following line if no dynamic allocation is required.
 *  The ports library must be then rebuilt. Please note this feature has
 *  not been ran through regression tests and should be considered at
 *  "alpha" quality. In a future release, this feature will be completely
 *  tested and documented.
 */
//#define TIRTOS_CONFIG_DRIVERS_USE_STATIC_ALLOCATION

#ifdef TIRTOS_CONFIG_DRIVERS_USE_STATIC_ALLOCATION
#warn Static TI-RTOS kernel object allocation has not been completely \
tested. Please consider it at alpha quality.

/* Set the number of SemaphoreP_Handles */
#ifndef TIRTOS_CONFIG_NUM_SEMAPHORE
#define TIRTOS_CONFIG_NUM_SEMAPHORE 8
#endif

/* Set the number of MutexP_Handles */
#ifndef TIRTOS_CONFIG_NUM_MUTEX
#define TIRTOS_CONFIG_NUM_MUTEX 8
#endif

/* Set the number of ClockP_Handles */
#ifndef TIRTOS_CONFIG_NUM_CLOCK
#define TIRTOS_CONFIG_NUM_CLOCK 8
#endif

/* Set the number of HwiP_Handles */
#ifndef TIRTOS_CONFIG_NUM_HWI
#define TIRTOS_CONFIG_NUM_HWI 8
#endif

#endif /* TIRTOS_CONFIG_DRIVERS_USE_STATIC_ALLOCATION */

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_ports_tirtos_tirtos_config__include */
