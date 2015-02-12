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

#ifdef __cplusplus
extern "C" {
#endif

/* 
 * Use intrinsics for ALL C6x and ARM 32bit targets (excluding arm M3)
 */

#if defined(xdc_target__isaCompatible_arp32)
#include <arp32.h>
#endif

#if defined(xdc_target__isaCompatible_62) \
    || defined(xdc_target__isaCompatible_64T) \
    || defined(xdc_target__isaCompatible_arp32)

/*
 * These intrinsic prototypes are missing from <c6x.h>.
 * Add them here to keep Coverity happy.
 */
extern unsigned int _disable_interrupts(void);
extern unsigned int _enable_interrupts(void);
extern void _restore_interrupts(unsigned int key);

/*
 *  ======== Hwi_disable ========
 */
#define ti_sysbios_hal_Hwi_disable() _disable_interrupts()

/*
 *  ======== Hwi_enable ========
 */
#define ti_sysbios_hal_Hwi_enable() _enable_interrupts()

/*
 *  ======== Hwi_restore ========
 */
#define ti_sysbios_hal_Hwi_restore(key) _restore_interrupts(key)

#else
#if defined(xdc_target__isaCompatible_470) \
    && defined(__32bis__) \
    && !defined(xdc_target__isaCompatible_v7M)

/*
 *  ======== Hwi_disable ========
 */
#define ti_sysbios_hal_Hwi_disable() _disable_IRQ()

/*
 *  ======== Hwi_enable ========
 */
#define ti_sysbios_hal_Hwi_enable() _enable_IRQ()

/*
 *  ======== Hwi_restore ========
 */
#define ti_sysbios_hal_Hwi_restore(key) _restore_interrupts(key)

#else

#if defined(xdc_target__isaCompatible_v7M) || defined(xdc_target__isaCompatible_v7M4)

#include "ti/sysbios/family/arm/m3/Hwi.h"

#ifndef ti_sysbios_Build_useHwiMacros

/* Use function call implementations */

/*
 *  ======== Hwi_disable ========
 */
#define ti_sysbios_hal_Hwi_disable() ti_sysbios_family_arm_m3_Hwi_disableFxn()

/*
 *  ======== Hwi_enable ========
 */
#define ti_sysbios_hal_Hwi_enable() ti_sysbios_family_arm_m3_Hwi_enableFxn()

/*
 *  ======== Hwi_restore ========
 */
#define ti_sysbios_hal_Hwi_restore(key) ti_sysbios_family_arm_m3_Hwi_restoreFxn(key)

#else /* ti_sysbios_Build_useHwiMacros */

/* Use macro/inline implementations */

#if defined(__ti__)

/*
 *  ======== Hwi_disable ========
 */
#define ti_sysbios_hal_Hwi_disable() _set_interrupt_priority(ti_sysbios_family_arm_m3_Hwi_disablePriority)

/*
 *  ======== Hwi_enable ========
 */
#define ti_sysbios_hal_Hwi_enable() _set_interrupt_priority(0) 

/*
 *  ======== Hwi_restore ========
 */
#define ti_sysbios_hal_Hwi_restore(key) _set_interrupt_priority(key) 

#else /* defined(__ti__) */

/*
 *  ======== Hwi_disable ========
 */
static inline UInt ti_sysbios_hal_Hwi_disable()
{
    UInt key;

#if defined(__IAR_SYSTEMS_ICC__)
    asm volatile (
#else /* !__IAR_SYSTEMS_ICC__ */
    __asm__ __volatile__ (
#endif
            "mrs %0, basepri\n\t"
            "msr basepri, %1"
            : "=&r" (key)
            : "r" (ti_sysbios_family_arm_m3_Hwi_disablePriority)
            );
    return key;
}

/*
 *  ======== Hwi_enable ========
 */
static inline UInt ti_sysbios_hal_Hwi_enable()
{
    UInt key;

#if defined(__IAR_SYSTEMS_ICC__)
    asm volatile (
#else /* !__IAR_SYSTEMS_ICC__ */
    __asm__ __volatile__ (
#endif
            "movw r12, #0\n\t"
            "mrs %0, basepri\n\t"
            "msr basepri, r12"
            : "=r" (key)
            :: "r12"
            );
    return key;
}

/*
 *  ======== Hwi_restore ========
 */
static inline Void ti_sysbios_hal_Hwi_restore(UInt key)
{
#if defined(__IAR_SYSTEMS_ICC__)
    asm volatile (
#else /* !__IAR_SYSTEMS_ICC__ */
    __asm__ __volatile__ (
#endif
            "msr basepri, %0"
            :: "r" (key)
            );
}

#endif /* defined(__ti__) */

#endif /* ti_sysbios_Build_useHwiMacros */

#else
#if defined(xdc_target__isaCompatible_430) \
    || defined(xdc_target__isaCompatible_430X)

#if defined(__IAR_SYSTEMS_ICC__)
#include <intrinsics.h>
#endif

#define GIE_BIT  0x8    /* GIE bit position in Status Register (SR) */ 

/*
 *  ======== Hwi_disable ========
 */
#if defined(__IAR_SYSTEMS_ICC__)
#pragma inline=forced
UInt ti_sysbios_hal_Hwi_disable()
#else
inline UInt ti_sysbios_hal_Hwi_disable()
#endif
{
    UInt state;
    state = __get_SR_register();
    __disable_interrupt();
    return (state);
}


/*
 *  ======== Hwi_enable ========
 */
#if defined(__IAR_SYSTEMS_ICC__)
#pragma inline=forced
UInt ti_sysbios_hal_Hwi_enable()
#else
inline UInt ti_sysbios_hal_Hwi_enable()
#endif
{
    UInt state;
    state = __get_SR_register();
    __enable_interrupt();
    return (state);
}

/*
 *  ======== Hwi_restore ========
 */
#if defined(__IAR_SYSTEMS_ICC__)
#pragma inline=forced
Void ti_sysbios_hal_Hwi_restore(UInt key)
#else
inline Void ti_sysbios_hal_Hwi_restore(UInt key)
#endif
{
    if (key & GIE_BIT) {
        __enable_interrupt();
    }
    else {
        __disable_interrupt();
    }
}

#else
#if defined(xdc_target__isaCompatible_28)

#include "ti/sysbios/family/c28/Hwi.h"

extern UInt ti_sysbios_family_c28_Hwi_enable__E();
extern UInt ti_sysbios_family_c28_Hwi_disable__E();
extern Void ti_sysbios_family_c28_Hwi_restore__E(UInt key);

/*
 *  ======== Hwi_disable ========
 */
inline UInt ti_sysbios_hal_Hwi_disable()
{
#ifdef ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__D
 #if ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__D == 0
    return (_disable_interrupts());
 #else
    return (ti_sysbios_family_c28_Hwi_disable__E());
 #endif
#else
    return (ti_sysbios_family_c28_Hwi_disable__E());
#endif
}

/*
 *  ======== Hwi_enable ========
 */
inline UInt ti_sysbios_hal_Hwi_enable()
{
#ifdef ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__D
 #if ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__D == 0
    return (_enable_interrupts());
 #else
    return (ti_sysbios_family_c28_Hwi_enable__E());
 #endif
#else
    return (ti_sysbios_family_c28_Hwi_enable__E());
#endif
}

/*
 *  ======== Hwi_restore ========
 */
inline Void ti_sysbios_hal_Hwi_restore(UInt key)
{
#ifdef ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__D
 #if ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__D == 0
    _restore_interrupts(key);
 #else
    ti_sysbios_family_c28_Hwi_restore__E(key);
 #endif
#else
    ti_sysbios_family_c28_Hwi_restore__E(key);
#endif
}

#else
#if defined(xdc_target__isaCompatible_v7A15)

#include "ti/sysbios/family/arm/gic/Hwi.h"

#ifndef ti_sysbios_Build_useHwiMacros
/* Use function call implementations */

/*
 *  ======== Hwi_disable ========
 */
#define ti_sysbios_hal_Hwi_disable() ti_sysbios_family_arm_gic_Hwi_disableFxn()

/*
 *  ======== Hwi_enable ========
 */
#define ti_sysbios_hal_Hwi_enable() ti_sysbios_family_arm_gic_Hwi_enableFxn()

/*
 *  ======== Hwi_restore ========
 */
#define ti_sysbios_hal_Hwi_restore(key) ti_sysbios_family_arm_gic_Hwi_restoreFxn(key)

#else /* ti_sysbios_Build_useHwiMacros */
/*
 *  ======== Hwi_disable ========
 */
static inline UInt ti_sysbios_hal_Hwi_disable()
{
    UInt key;
    /*
     * Note: Inline assembly follows GNU format and may not
     *       be compatible with TI compiler.
     */
    __asm__ __volatile__ (
            "mrs %0, cpsr_cf\n\t"
            "cpsid i"
            : "=r" (key)
            :: "cc", "memory"
            );
    return key;
}

/*
 *  ======== Hwi_enable ========
 */
static inline UInt ti_sysbios_hal_Hwi_enable()
{
    UInt key;
    /*
     * Note: Inline assembly follows GNU format and may not
     *       be compatible with TI compiler.
     */
    __asm__ __volatile__ (
            "mrs %0, cpsr_cf\n\t"
            "cpsie i"
            : "=r" (key)
            :: "cc", "memory"
            );
    return key;
}

/*
 *  ======== Hwi_restore ========
 */
static inline Void ti_sysbios_hal_Hwi_restore(UInt key)
{
    __asm__ __volatile__ (
            "and r12, %0, #128\n\t"
            "mrs r0, cpsr_cf\n\t"
            "bic r0, r0, #128\n\t"
            "orr r12, r12, r0\n\t"
            "msr cpsr_cf, r12"
            :: "r" (key)
            : "r0", "r12", "cc", "memory"
            );
}

#endif /* !ti_sysbios_Build_useHwiMacros */

#else
#if ((defined(xdc_target__isaCompatible_v7A9)) || \
     (defined(xdc_target__isaCompatible_v7A8)))

/*
 *  ======== Hwi_disable ========
 */
static inline UInt ti_sysbios_hal_Hwi_disable()
{
    UInt key;
    /*
     * Note: Inline assembly follows GNU format and may not
     *       be compatible with TI compiler.
     */
    __asm__ __volatile__ (
            "mrs %0, cpsr_cf\n\t"
            "cpsid i"
            : "=r" (key)
            :: "cc", "memory"
            );
    return key;
}

/*
 *  ======== Hwi_enable ========
 */
static inline UInt ti_sysbios_hal_Hwi_enable()
{
    UInt key;
    /*
     * Note: Inline assembly follows GNU format and may not
     *       be compatible with TI compiler.
     */
    __asm__ __volatile__ (
            "mrs %0, cpsr_cf\n\t"
            "cpsie i"
            : "=r" (key)
            :: "cc", "memory"
            );
    return key;
}

/*
 *  ======== Hwi_restore ========
 */
static inline Void ti_sysbios_hal_Hwi_restore(UInt key)
{
    __asm__ __volatile__ (
            "and r12, %0, #128\n\t"
            "mrs r0, cpsr_cf\n\t"
            "bic r0, r0, #128\n\t"
            "orr r12, r12, r0\n\t"
            "msr cpsr_cf, r12"
            :: "r" (key)
            : "r0", "r12", "cc", "memory"
            );
}

#else

/*
 *  ======== Hwi_disable ========
 */
#define ti_sysbios_hal_Hwi_disable() ti_sysbios_hal_Hwi_HwiProxy_disable()

/*
 *  ======== Hwi_enable ========
 */
#define ti_sysbios_hal_Hwi_enable() ti_sysbios_hal_Hwi_HwiProxy_enable()

/*
 *  ======== Hwi_restore ========
 */
#define ti_sysbios_hal_Hwi_restore(key) ti_sysbios_hal_Hwi_HwiProxy_restore(key)

#endif

#endif

#endif

#endif

#endif

#endif

#endif

#ifdef __cplusplus
}
#endif
