/*
 * Copyright (c) 2013-2014, Texas Instruments Incorporated
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

#if defined(xdc_target__isaCompatible_62) \
    || defined(xdc_target__isaCompatible_64T) \
    || defined(xdc_target__isaCompatible_t16)

#include <c6x.h>

/*
 *  ======== Intrinsics_maxbit ========
 */
#define ti_sysbios_knl_Intrinsics_maxbit(bits) (31 - _lmbd(1, bits))

#elif defined(xdc_target__isaCompatible_arp32)

#include <arp32.h>

/*
 *  ======== Intrinsics_maxbit ========
 */
#define ti_sysbios_knl_Intrinsics_maxbit(bits) (31 - _lmbd(1, bits))

#else
#if defined(xdc_target__isaCompatible_470) \
    && defined(__32bis__) \
    && !defined(xdc_target__isaCompatible_v7M)

/*
 *  ======== Intrinsics_maxbit ========
 */
#define ti_sysbios_knl_Intrinsics_maxbit(bits) (31 - _norm(bits))

#else
#if defined(xdc_target__isaCompatible_v7M)

/*
 *  ======== Intrinsics_maxbit ========
 */
#if defined(__ti__)
#define ti_sysbios_knl_Intrinsics_maxbit(bits) (31 - _norm(bits))
#else
static inline UInt ti_sysbios_knl_Intrinsics_maxbit(UInt bits)
{
    UInt retVal;
    asm volatile (
            "clz %0, %1\n\t"
            "rsb %0, %0, #31"
            : "=r" (retVal)
            : "r" (bits)
            : "cc"
            );
    return retVal;
}
#endif

#else
#if defined(xdc_target__isaCompatible_430)

#if defined(__IAR_SYSTEMS_ICC__)
#include <intrinsics.h>
#endif

extern const UInt IntrinsicsSupport_maxbitTable[];

#if defined(__IAR_SYSTEMS_ICC__)
#pragma inline=forced
UInt ti_sysbios_knl_Intrinsics_maxbit(UInt bits)
#else
inline UInt ti_sysbios_knl_Intrinsics_maxbit(UInt bits)
#endif
{
    if (bits & 0xf000) {
        return (IntrinsicsSupport_maxbitTable[bits >> 12] + 12);
    }
    if (bits & 0x0f00) {
        return (IntrinsicsSupport_maxbitTable[bits >> 8] + 8);
    }
    if (bits & 0x00f0) {
        return (IntrinsicsSupport_maxbitTable[bits >> 4] + 4);
    }
    else {
        return (IntrinsicsSupport_maxbitTable[bits]);
    }
}

#else
#if defined(xdc_target__isaCompatible_28)
extern UInt ti_sysbios_family_c28_IntrinsicsSupport_maxbit__E(UInt bits);

#define ti_sysbios_knl_Intrinsics_maxbit(bits) ti_sysbios_family_c28_IntrinsicsSupport_maxbit__E(bits)

#else

#if ((defined(xdc_target__isaCompatible_v7A15)) || \
     (defined(xdc_target__isaCompatible_v7A9)))

/*
 *  ======== Intrinsics_maxbit ========
 */
static inline UInt ti_sysbios_knl_Intrinsics_maxbit(UInt bits)
{
    UInt retVal;
    __asm__ __volatile__ (
            "clz %0, %1\n\t"
            "rsb %0, %0, #31"
            : "=r" (retVal)
            : "r" (bits)
            : "cc"
            );
    return retVal;
}

#else

/*
 *  ======== Intrinsics_maxbit ========
 */
#define ti_sysbios_knl_Intrinsics_maxbit(bits) ti_sysbios_knl_Intrinsics_SupportProxy_maxbit(bits)

#endif

#endif

#endif

#endif

#endif

#endif

#ifdef __cplusplus
}
#endif
