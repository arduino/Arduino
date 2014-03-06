/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __CC_H__
#define __CC_H__

typedef unsigned    char    u8_t;
typedef signed      char    s8_t;
typedef unsigned    short   u16_t;
typedef signed      short   s16_t;
typedef unsigned    long    u32_t;
typedef signed      long    s32_t;
typedef u32_t               mem_ptr_t;
typedef u8_t                sys_prot_t;

#ifndef BYTE_ORDER
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#if defined(__arm__) && defined(__ARMCC_VERSION)
    //
    // Setup PACKing macros for KEIL/RVMDK Tools
    //
    #define PACK_STRUCT_BEGIN __packed
    #define PACK_STRUCT_STRUCT
    #define PACK_STRUCT_END
    #define PACK_STRUCT_FIELD(x) x
#elif defined (__IAR_SYSTEMS_ICC__)
    //
    // Setup PACKing macros for IAR Tools
    //
    #define PACK_STRUCT_BEGIN
    #define PACK_STRUCT_STRUCT
    #define PACK_STRUCT_END
    #define PACK_STRUCT_FIELD(x) x
    #define PACK_STRUCT_USE_INCLUDES
#else
    //
    // Setup PACKing macros for GCC Tools
    //
    #define PACK_STRUCT_BEGIN
    #define PACK_STRUCT_STRUCT __attribute__ ((__packed__))
    #define PACK_STRUCT_END
    #define PACK_STRUCT_FIELD(x) x
#endif

//*****************************************************************************
//
// Define LWIP_PLATFORM_DIAG and LWIP_PLATFORM_ASSERT macros.  Both of these
// are expected to display the message argument using a platform/app specific
// display routine.  The ASSERT macro should then abort execution.
//
// In general, the user should define these in the target/application specific
// LWIPOPTS.H file, using whatever display mechanisms are availble for the
// board/application.  However, some general default macros are provided here
// to allow the LWIP code to build properly with/without the DEBUG macro
// defined.
//
//*****************************************************************************
//
// Define an empty DIAG display maro here ... since we have no knowledge of
// what display routines are available.
//
#ifndef LWIP_PLATFORM_DIAG
#define LWIP_PLATFORM_DIAG(msg)
#endif

//
// Define a generic ASSERT display macro here ... use the DIAG macro to display
// the message, then use the __error__ function, which should always be
// defined by the user application for DEBUG builds, to abandon execution.
//
#ifndef LWIP_PLATFORM_ASSERT
#ifdef DEBUG

#include <stdint.h>
#include <stdbool.h>

extern void __error__(char *pcFilename, uint32_t ui32Line);
#define LWIP_PLATFORM_ASSERT(msg)       \
{                                       \
    LWIP_PLATFORM_DIAG(msg);            \
    __error__(__FILE__, __LINE__);      \
}
#else
#define LWIP_PLATFORM_ASSERT(msg)
#endif
#endif

#endif /* __CC_H__ */
