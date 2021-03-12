/* Copyright (c) 2002-2007  Marek Michalkiewicz
   Copyright (c) 2006, Carlos Lamas
   Copyright (c) 2009-2010, Jan Waclawek
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/*
   pgmspace.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
     Eric B. Weddington <eric@ecentral.com>
     Wolfgang Haidinger <wh@vmars.tuwien.ac.at> (pgm_read_dword())
     Ivanov Anton <anton@arc.com.ru> (pgm_read_float())
 */

/** \file */
/** \defgroup avr_pgmspace <avr/pgmspace.h>: Program Space Utilities
    \code
    #include <avr/io.h>
    #include <avr/pgmspace.h>
    \endcode

    The functions in this module provide interfaces for a program to access
    data stored in program space (flash memory) of the device.  In order to
    use these functions, the target device must support either the \c LPM or
    \c ELPM instructions.

    \note These functions are an attempt to provide some compatibility with
    header files that come with IAR C, to make porting applications between
    different compilers easier.  This is not 100% compatibility though (GCC
    does not have full support for multiple address spaces yet).

    \note If you are working with strings which are completely based in ram,
    use the standard string functions described in \ref avr_string.

    \note If possible, put your constant tables in the lower 64 KB and use
    pgm_read_byte_near() or pgm_read_word_near() instead of
    pgm_read_byte_far() or pgm_read_word_far() since it is more efficient that
    way, and you can still use the upper 64K for executable code.
    All functions that are suffixed with a \c _P \e require their
    arguments to be in the lower 64 KB of the flash ROM, as they do
    not use ELPM instructions.  This is normally not a big concern as
    the linker setup arranges any program space constants declared
    using the macros from this header file so they are placed right after
    the interrupt vectors, and in front of any executable code.  However,
    it can become a problem if there are too many of these constants, or
    for bootloaders on devices with more than 64 KB of ROM.
    <em>All these functions will not work in that situation.</em>

    \note For <b>Xmega</b> devices, make sure the NVM controller
    command register (\c NVM.CMD or \c NVM_CMD) is set to 0x00 (NOP)
    before using any of these functions.
*/

#ifndef __PGMSPACE_H_
#define __PGMSPACE_H_ 1

#ifndef __DOXYGEN__
#define __need_size_t
#endif
#include <inttypes.h>
#include <stddef.h>
#include <avr/io.h>

#ifndef __DOXYGEN__
#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif

#ifndef __ATTR_PROGMEM__
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#endif

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif
#endif	/* !__DOXYGEN__ */

/**
   \ingroup avr_pgmspace
   \def PROGMEM

   Attribute to use in order to declare an object being located in
   flash ROM.
 */
#define PROGMEM __ATTR_PROGMEM__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DOXYGEN__)
/*
 * Doxygen doesn't grok the appended attribute syntax of
 * GCC, and confuses the typedefs with function decls, so
 * supply a doxygen-friendly view.
 */

/**
   \ingroup avr_pgmspace
   \typedef prog_void
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of a "void" object located in flash ROM.  Does not make much
   sense by itself, but can be used to declare a "void *" object in
   flash ROM.
*/
typedef void PROGMEM prog_void;

/**
   \ingroup avr_pgmspace
   \typedef prog_char
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of a "char" object located in flash ROM.
*/
typedef char PROGMEM prog_char;

/**
   \ingroup avr_pgmspace
   \typedef prog_uchar
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "unsigned char" object located in flash ROM.
*/
typedef unsigned char PROGMEM prog_uchar;

/**
   \ingroup avr_pgmspace
   \typedef prog_int8_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "int8_t" object located in flash ROM.
*/
typedef int8_t PROGMEM prog_int8_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint8_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "uint8_t" object located in flash ROM.
*/
typedef uint8_t PROGMEM prog_uint8_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_int16_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "int16_t" object located in flash ROM.
*/
typedef int16_t PROGMEM prog_int16_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint16_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "uint16_t" object located in flash ROM.
*/
typedef uint16_t PROGMEM prog_uint16_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_int32_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "int32_t" object located in flash ROM.
*/
typedef int32_t PROGMEM prog_int32_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint32_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "uint32_t" object located in flash ROM.
*/
typedef uint32_t PROGMEM prog_uint32_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_int64_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "int64_t" object located in flash ROM.

   \note This type is not available when the compiler
   option -mint8 is in effect.
*/
typedef int64_t PROGMEM prog_int64_t;

/**
   \ingroup avr_pgmspace
   \typedef prog_uint64_t
   \note DEPRECATED

   This typedef is now deprecated because the usage of the __progmem__ 
   attribute on a type is not supported in GCC. However, the use of the 
   __progmem__ attribute on a variable declaration is supported, and this is 
   now the recommended usage.

   The typedef is only visible if the macro __PROG_TYPES_COMPAT__
   has been defined before including <avr/pgmspace.h> (either by a
   \c \#define directive, or by a -D compiler option.)

   Type of an "uint64_t" object located in flash ROM.

   \note This type is not available when the compiler
   option -mint8 is in effect.
*/
typedef uint64_t PROGMEM prog_uint64_t;

/** \ingroup avr_pgmspace
    \def PGM_P

    Used to declare a variable that is a pointer to a string in program
    space. */

#ifndef PGM_P
#define PGM_P const char *
#endif

/** \ingroup avr_pgmspace
    \def PGM_VOID_P

    Used to declare a generic pointer to an object in program space. */

#ifndef PGM_VOID_P
#define PGM_VOID_P const void *
#endif

#elif defined(__PROG_TYPES_COMPAT__)  /* !DOXYGEN */

typedef void prog_void __attribute__((__progmem__,deprecated("prog_void type is deprecated.")));
typedef char prog_char __attribute__((__progmem__,deprecated("prog_char type is deprecated.")));
typedef unsigned char prog_uchar __attribute__((__progmem__,deprecated("prog_uchar type is deprecated.")));
typedef int8_t    prog_int8_t   __attribute__((__progmem__,deprecated("prog_int8_t type is deprecated.")));
typedef uint8_t   prog_uint8_t  __attribute__((__progmem__,deprecated("prog_uint8_t type is deprecated.")));
typedef int16_t   prog_int16_t  __attribute__((__progmem__,deprecated("prog_int16_t type is deprecated.")));
typedef uint16_t  prog_uint16_t __attribute__((__progmem__,deprecated("prog_uint16_t type is deprecated.")));
typedef int32_t   prog_int32_t  __attribute__((__progmem__,deprecated("prog_int32_t type is deprecated.")));
typedef uint32_t  prog_uint32_t __attribute__((__progmem__,deprecated("prog_uint32_t type is deprecated.")));
#if !__USING_MINT8
typedef int64_t   prog_int64_t  __attribute__((__progmem__,deprecated("prog_int64_t type is deprecated.")));
typedef uint64_t  prog_uint64_t __attribute__((__progmem__,deprecated("prog_uint64_t type is deprecated.")));
#endif

#ifndef PGM_P
#define PGM_P const prog_char *
#endif

#ifndef PGM_VOID_P
#define PGM_VOID_P const prog_void *
#endif

#else /* !defined(__DOXYGEN__), !defined(__PROG_TYPES_COMPAT__) */

#ifndef PGM_P
#define PGM_P const char *
#endif

#ifndef PGM_VOID_P
#define PGM_VOID_P const void *
#endif
#endif /* defined(__DOXYGEN__), defined(__PROG_TYPES_COMPAT__) */

/* Although in C, we can get away with just using __c, it does not work in
   C++. We need to use &__c[0] to avoid the compiler puking. Dave Hylands
   explaned it thusly,

     Let's suppose that we use PSTR("Test"). In this case, the type returned
     by __c is a prog_char[5] and not a prog_char *. While these are
     compatible, they aren't the same thing (especially in C++). The type
     returned by &__c[0] is a prog_char *, which explains why it works
     fine. */

#if defined(__DOXYGEN__)
/*
 * The #define below is just a dummy that serves documentation
 * purposes only.
 */
/** \ingroup avr_pgmspace
    \def PSTR(s)

    Used to declare a static pointer to a string in program space. */
# define PSTR(s) ((const PROGMEM char *)(s))
#else  /* !DOXYGEN */
/* The real thing. */
# define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))
#endif /* DOXYGEN */

#ifndef __DOXYGEN__ /* Internal macros, not documented. */
#define __LPM_classic__(addr)   \
(__extension__({                \
    uint16_t __addr16 = (uint16_t)(addr); \
    uint8_t __result;           \
    __asm__ __volatile__        \
    (                           \
        "lpm" "\n\t"            \
        "mov %0, r0" "\n\t"     \
        : "=r" (__result)       \
        : "z" (__addr16)        \
        : "r0"                  \
    );                          \
    __result;                   \
}))

#define __LPM_tiny__(addr)      \
(__extension__({                \
    uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; \
    uint8_t __result;           \
    __asm__                     \
    (                           \
        "ld %0, z" "\n\t"       \
        : "=r" (__result)       \
        : "z" (__addr16)        \
    );                          \
    __result;                   \
}))

#define __LPM_enhanced__(addr)  \
(__extension__({                \
    uint16_t __addr16 = (uint16_t)(addr); \
    uint8_t __result;           \
    __asm__ __volatile__        \
    (                           \
        "lpm %0, Z" "\n\t"      \
        : "=r" (__result)       \
        : "z" (__addr16)        \
    );                          \
    __result;                   \
}))

#define __LPM_word_classic__(addr)          \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    uint16_t __result;                      \
    __asm__ __volatile__                    \
    (                                       \
        "lpm"           "\n\t"              \
        "mov %A0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %B0, r0"   "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
        : "r0"                              \
    );                                      \
    __result;                               \
}))

#define __LPM_word_tiny__(addr)             \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; \
    uint16_t __result;                      \
    __asm__                                 \
    (                                       \
        "ld %A0, z+"     "\n\t"             \
        "ld %B0, z"      "\n\t"             \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
    );                                      \
    __result;                               \
}))

#define __LPM_word_enhanced__(addr)         \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    uint16_t __result;                      \
    __asm__ __volatile__                    \
    (                                       \
        "lpm %A0, Z+"   "\n\t"              \
        "lpm %B0, Z"    "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
    );                                      \
    __result;                               \
}))

#define __LPM_dword_classic__(addr)         \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    uint32_t __result;                      \
    __asm__ __volatile__                    \
    (                                       \
        "lpm"           "\n\t"              \
        "mov %A0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %B0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %C0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %D0, r0"   "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
        : "r0"                              \
    );                                      \
    __result;                               \
}))

#define __LPM_dword_tiny__(addr)            \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; \
    uint32_t __result;                      \
    __asm__                                 \
    (                                       \
        "ld %A0, z+"    "\n\t"              \
        "ld %B0, z+"    "\n\t"              \
        "ld %C0, z+"    "\n\t"              \
        "ld %D0, z"     "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
    );                                      \
    __result;                               \
}))

#define __LPM_dword_enhanced__(addr)        \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    uint32_t __result;                      \
    __asm__ __volatile__                    \
    (                                       \
        "lpm %A0, Z+"   "\n\t"              \
        "lpm %B0, Z+"   "\n\t"              \
        "lpm %C0, Z+"   "\n\t"              \
        "lpm %D0, Z"    "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
    );                                      \
    __result;                               \
}))

#define __LPM_float_classic__(addr)         \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    float __result;                         \
    __asm__ __volatile__                    \
    (                                       \
        "lpm"           "\n\t"              \
        "mov %A0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %B0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %C0, r0"   "\n\t"              \
        "adiw r30, 1"   "\n\t"              \
        "lpm"           "\n\t"              \
        "mov %D0, r0"   "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
        : "r0"                              \
    );                                      \
    __result;                               \
}))

#define __LPM_float_tiny__(addr)            \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; \
    float __result;                         \
    __asm__                                 \
    (                                       \
        "ld %A0, z+"   "\n\t"               \
        "ld %B0, z+"   "\n\t"               \
        "ld %C0, z+"   "\n\t"               \
        "ld %D0, z"    "\n\t"               \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
    );                                      \
    __result;                               \
}))

#define __LPM_float_enhanced__(addr)        \
(__extension__({                            \
    uint16_t __addr16 = (uint16_t)(addr);   \
    float __result;                         \
    __asm__ __volatile__                    \
    (                                       \
        "lpm %A0, Z+"   "\n\t"              \
        "lpm %B0, Z+"   "\n\t"              \
        "lpm %C0, Z+"   "\n\t"              \
        "lpm %D0, Z"    "\n\t"              \
        : "=r" (__result), "=z" (__addr16)  \
        : "1" (__addr16)                    \
    );                                      \
    __result;                               \
}))

#if defined (__AVR_HAVE_LPMX__)
#define __LPM(addr)         __LPM_enhanced__(addr)
#define __LPM_word(addr)    __LPM_word_enhanced__(addr)
#define __LPM_dword(addr)   __LPM_dword_enhanced__(addr)
#define __LPM_float(addr)   __LPM_float_enhanced__(addr)
/*
Macro to read data from program memory for avr tiny parts(tiny 4/5/9/10/20/40).
why:
- LPM instruction is not available in AVR_TINY instruction set.
- Programs are executed starting from address 0x0000 in program memory.
But it must be addressed starting from 0x4000 when accessed via data memory.
Reference: TINY device (ATTiny 4,5,9,10,20 and 40) datasheets
Bug: avrtc-536
*/
#elif defined (__AVR_TINY__)
#define __LPM(addr)         __LPM_tiny__(addr)
#define __LPM_word(addr)    __LPM_word_tiny__(addr)
#define __LPM_dword(addr)   __LPM_dword_tiny__(addr)
#define __LPM_float(addr)   __LPM_float_tiny__(addr)
#else
#define __LPM(addr)         __LPM_classic__(addr)
#define __LPM_word(addr)    __LPM_word_classic__(addr)
#define __LPM_dword(addr)   __LPM_dword_classic__(addr)
#define __LPM_float(addr)   __LPM_float_classic__(addr)
#endif

#endif  /* !__DOXYGEN__ */

/** \ingroup avr_pgmspace
    \def pgm_read_byte_near(address_short)
    Read a byte from the program space with a 16-bit (near) address. 
    \note The address is a byte address.
    The address is in the program space. */

#define pgm_read_byte_near(address_short) __LPM((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_word_near(address_short)
    Read a word from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_word_near(address_short) __LPM_word((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_dword_near(address_short)
    Read a double word from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_dword_near(address_short) \
    __LPM_dword((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_float_near(address_short)
    Read a float from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_float_near(address_short) \
    __LPM_float((uint16_t)(address_short))

/** \ingroup avr_pgmspace
    \def pgm_read_ptr_near(address_short)
    Read a pointer from the program space with a 16-bit (near) address. 
    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_ptr_near(address_short) \
    (void*)__LPM_word((uint16_t)(address_short))

#if defined(RAMPZ) || defined(__DOXYGEN__)

/* Only for devices with more than 64K of program memory.
   RAMPZ must be defined (see iom103.h, iom128.h).
*/

/* The classic functions are needed for ATmega103. */
#ifndef __DOXYGEN__		/* These are internal macros, avoid "is
				   not documented" warnings. */
#define __ELPM_classic__(addr)      \
(__extension__({                    \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint8_t __result;               \
    __asm__ __volatile__            \
    (                               \
        "out %2, %C1" "\n\t"        \
        "mov r31, %B1" "\n\t"       \
        "mov r30, %A1" "\n\t"       \
        "elpm" "\n\t"               \
        "mov %0, r0" "\n\t"         \
        : "=r" (__result)           \
        : "r" (__addr32),           \
          "I" (_SFR_IO_ADDR(RAMPZ)) \
        : "r0", "r30", "r31"        \
    );                              \
    __result;                       \
}))

#define __ELPM_enhanced__(addr)     \
(__extension__({                    \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint8_t __result;               \
    __asm__ __volatile__            \
    (                               \
        "out %2, %C1" "\n\t"        \
        "movw r30, %1" "\n\t"       \
        "elpm %0, Z+" "\n\t"        \
        : "=r" (__result)           \
        : "r" (__addr32),           \
          "I" (_SFR_IO_ADDR(RAMPZ)) \
        : "r30", "r31"              \
    );                              \
    __result;                       \
}))

#define __ELPM_xmega__(addr)        \
(__extension__({                    \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint8_t __result;               \
    __asm__ __volatile__            \
    (                               \
        "in __tmp_reg__, %2" "\n\t" \
        "out %2, %C1" "\n\t"        \
        "movw r30, %1" "\n\t"       \
        "elpm %0, Z+" "\n\t"        \
        "out %2, __tmp_reg__"       \
        : "=r" (__result)           \
        : "r" (__addr32),           \
          "I" (_SFR_IO_ADDR(RAMPZ)) \
        : "r30", "r31"              \
    );                              \
    __result;                       \
}))

#define __ELPM_word_classic__(addr)     \
(__extension__({                        \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint16_t __result;                  \
    __asm__ __volatile__                \
    (                                   \
        "out %2, %C1"   "\n\t"          \
        "mov r31, %B1"  "\n\t"          \
        "mov r30, %A1"  "\n\t"          \
        "elpm"          "\n\t"          \
        "mov %A0, r0"   "\n\t"          \
        "in r0, %2"     "\n\t"          \
        "adiw r30, 1"   "\n\t"          \
        "adc r0, __zero_reg__" "\n\t"   \
        "out %2, r0"    "\n\t"          \
        "elpm"          "\n\t"          \
        "mov %B0, r0"   "\n\t"          \
        : "=r" (__result)               \
        : "r" (__addr32),               \
          "I" (_SFR_IO_ADDR(RAMPZ))     \
        : "r0", "r30", "r31"            \
    );                                  \
    __result;                           \
}))

#define __ELPM_word_enhanced__(addr)    \
(__extension__({                        \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint16_t __result;                  \
    __asm__ __volatile__                \
    (                                   \
        "out %2, %C1"   "\n\t"          \
        "movw r30, %1"  "\n\t"          \
        "elpm %A0, Z+"  "\n\t"          \
        "elpm %B0, Z"   "\n\t"          \
        : "=r" (__result)               \
        : "r" (__addr32),               \
          "I" (_SFR_IO_ADDR(RAMPZ))     \
        : "r30", "r31"                  \
    );                                  \
    __result;                           \
}))

#define __ELPM_word_xmega__(addr)       \
(__extension__({                        \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint16_t __result;                  \
    __asm__ __volatile__                \
    (                                   \
        "in __tmp_reg__, %2" "\n\t"     \
        "out %2, %C1"   "\n\t"          \
        "movw r30, %1"  "\n\t"          \
        "elpm %A0, Z+"  "\n\t"          \
        "elpm %B0, Z"   "\n\t"          \
        "out %2, __tmp_reg__"           \
        : "=r" (__result)               \
        : "r" (__addr32),               \
          "I" (_SFR_IO_ADDR(RAMPZ))     \
        : "r30", "r31"                  \
    );                                  \
    __result;                           \
}))

#define __ELPM_dword_classic__(addr)      \
(__extension__({                          \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint32_t __result;                    \
    __asm__ __volatile__                  \
    (                                     \
        "out %2, %C1"          "\n\t"     \
        "mov r31, %B1"         "\n\t"     \
        "mov r30, %A1"         "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %A0, r0"          "\n\t"     \
        "in r0, %2"            "\n\t"     \
        "adiw r30, 1"          "\n\t"     \
        "adc r0, __zero_reg__" "\n\t"     \
        "out %2, r0"           "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %B0, r0"          "\n\t"     \
        "in r0, %2"            "\n\t"     \
        "adiw r30, 1"          "\n\t"     \
        "adc r0, __zero_reg__" "\n\t"     \
        "out %2, r0"           "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %C0, r0"          "\n\t"     \
        "in r0, %2"            "\n\t"     \
        "adiw r30, 1"          "\n\t"     \
        "adc r0, __zero_reg__" "\n\t"     \
        "out %2, r0"           "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %D0, r0"          "\n\t"     \
        : "=r" (__result)                 \
        : "r" (__addr32),                 \
          "I" (_SFR_IO_ADDR(RAMPZ))       \
        : "r0", "r30", "r31"              \
    );                                    \
    __result;                             \
}))

#define __ELPM_dword_enhanced__(addr)     \
(__extension__({                          \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint32_t __result;                    \
    __asm__ __volatile__                  \
    (                                     \
        "out %2, %C1"   "\n\t"            \
        "movw r30, %1"  "\n\t"            \
        "elpm %A0, Z+"  "\n\t"            \
        "elpm %B0, Z+"  "\n\t"            \
        "elpm %C0, Z+"  "\n\t"            \
        "elpm %D0, Z"   "\n\t"            \
        : "=r" (__result)                 \
        : "r" (__addr32),                 \
          "I" (_SFR_IO_ADDR(RAMPZ))       \
        : "r30", "r31"                    \
    );                                    \
    __result;                             \
}))

#define __ELPM_dword_xmega__(addr)        \
(__extension__({                          \
    uint32_t __addr32 = (uint32_t)(addr); \
    uint32_t __result;                    \
    __asm__ __volatile__                  \
    (                                     \
        "in __tmp_reg__, %2" "\n\t"       \
        "out %2, %C1"   "\n\t"            \
        "movw r30, %1"  "\n\t"            \
        "elpm %A0, Z+"  "\n\t"            \
        "elpm %B0, Z+"  "\n\t"            \
        "elpm %C0, Z+"  "\n\t"            \
        "elpm %D0, Z"   "\n\t"            \
        "out %2, __tmp_reg__"             \
        : "=r" (__result)                 \
        : "r" (__addr32),                 \
          "I" (_SFR_IO_ADDR(RAMPZ))       \
        : "r30", "r31"                    \
    );                                    \
    __result;                             \
}))

#define __ELPM_float_classic__(addr)      \
(__extension__({                          \
    uint32_t __addr32 = (uint32_t)(addr); \
    float __result;                       \
    __asm__ __volatile__                  \
    (                                     \
        "out %2, %C1"          "\n\t"     \
        "mov r31, %B1"         "\n\t"     \
        "mov r30, %A1"         "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %A0, r0"          "\n\t"     \
        "in r0, %2"            "\n\t"     \
        "adiw r30, 1"          "\n\t"     \
        "adc r0, __zero_reg__" "\n\t"     \
        "out %2, r0"           "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %B0, r0"          "\n\t"     \
        "in r0, %2"            "\n\t"     \
        "adiw r30, 1"          "\n\t"     \
        "adc r0, __zero_reg__" "\n\t"     \
        "out %2, r0"           "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %C0, r0"          "\n\t"     \
        "in r0, %2"            "\n\t"     \
        "adiw r30, 1"          "\n\t"     \
        "adc r0, __zero_reg__" "\n\t"     \
        "out %2, r0"           "\n\t"     \
        "elpm"                 "\n\t"     \
        "mov %D0, r0"          "\n\t"     \
        : "=r" (__result)                 \
        : "r" (__addr32),                 \
          "I" (_SFR_IO_ADDR(RAMPZ))       \
        : "r0", "r30", "r31"              \
    );                                    \
    __result;                             \
}))

#define __ELPM_float_enhanced__(addr)     \
(__extension__({                          \
    uint32_t __addr32 = (uint32_t)(addr); \
    float __result;                       \
    __asm__ __volatile__                  \
    (                                     \
        "out %2, %C1"   "\n\t"            \
        "movw r30, %1"  "\n\t"            \
        "elpm %A0, Z+"  "\n\t"            \
        "elpm %B0, Z+"  "\n\t"            \
        "elpm %C0, Z+"  "\n\t"            \
        "elpm %D0, Z"   "\n\t"            \
        : "=r" (__result)                 \
        : "r" (__addr32),                 \
          "I" (_SFR_IO_ADDR(RAMPZ))       \
        : "r30", "r31"                    \
    );                                    \
    __result;                             \
}))

#define __ELPM_float_xmega__(addr)        \
(__extension__({                          \
    uint32_t __addr32 = (uint32_t)(addr); \
    float __result;                       \
    __asm__ __volatile__                  \
    (                                     \
        "in __tmp_reg__, %2" "\n\t"       \
        "out %2, %C1"   "\n\t"            \
        "movw r30, %1"  "\n\t"            \
        "elpm %A0, Z+"  "\n\t"            \
        "elpm %B0, Z+"  "\n\t"            \
        "elpm %C0, Z+"  "\n\t"            \
        "elpm %D0, Z"   "\n\t"            \
        "out %2, __tmp_reg__"             \
        : "=r" (__result)                 \
        : "r" (__addr32),                 \
          "I" (_SFR_IO_ADDR(RAMPZ))       \
        : "r30", "r31"                    \
    );                                    \
    __result;                             \
}))

/*
Check for architectures that implement RAMPD (avrxmega5, avrxmega7)
as they need to save/restore RAMPZ for ELPM macros so it does
not interfere with data accesses.
*/
#if defined (__AVR_HAVE_RAMPD__)

#define __ELPM(addr)        __ELPM_xmega__(addr)
#define __ELPM_word(addr)   __ELPM_word_xmega__(addr)
#define __ELPM_dword(addr)  __ELPM_dword_xmega__(addr)
#define __ELPM_float(addr)  __ELPM_float_xmega__(addr)

#else

#if defined (__AVR_HAVE_LPMX__)

#define __ELPM(addr)        __ELPM_enhanced__(addr)
#define __ELPM_word(addr)   __ELPM_word_enhanced__(addr)
#define __ELPM_dword(addr)  __ELPM_dword_enhanced__(addr)
#define __ELPM_float(addr)  __ELPM_float_enhanced__(addr)

#else

#define __ELPM(addr)        __ELPM_classic__(addr)
#define __ELPM_word(addr)   __ELPM_word_classic__(addr)
#define __ELPM_dword(addr)  __ELPM_dword_classic__(addr)
#define __ELPM_float(addr)  __ELPM_float_classic__(addr)

#endif  /* __AVR_HAVE_LPMX__ */

#endif  /* __AVR_HAVE_RAMPD__ */

#endif	/* !__DOXYGEN__ */

/** \ingroup avr_pgmspace
    \def pgm_read_byte_far(address_long)
    Read a byte from the program space with a 32-bit (far) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_byte_far(address_long)  __ELPM((uint32_t)(address_long))

/** \ingroup avr_pgmspace
    \def pgm_read_word_far(address_long)
    Read a word from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */

#define pgm_read_word_far(address_long)  __ELPM_word((uint32_t)(address_long))

/** \ingroup avr_pgmspace
    \def pgm_read_dword_far(address_long)
    Read a double word from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */

#define pgm_read_dword_far(address_long) __ELPM_dword((uint32_t)(address_long))

/** \ingroup avr_pgmspace
    \def pgm_read_float_far(address_long)
    Read a float from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */

#define pgm_read_float_far(address_long) __ELPM_float((uint32_t)(address_long))

/** \ingroup avr_pgmspace
    \def pgm_read_ptr_far(address_long)
    Read a pointer from the program space with a 32-bit (far) address. 

    \note The address is a byte address.
    The address is in the program space. */

#define pgm_read_ptr_far(address_long) (void*)__ELPM_word((uint32_t)(address_long))

#endif /* RAMPZ or __DOXYGEN__ */

/** \ingroup avr_pgmspace
    \def pgm_read_byte(address_short)
    Read a byte from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_byte(address_short)    pgm_read_byte_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_word(address_short)
    Read a word from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_word(address_short)    pgm_read_word_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_dword(address_short)
    Read a double word from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_dword(address_short)   pgm_read_dword_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_float(address_short)
    Read a float from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_float(address_short)   pgm_read_float_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_read_ptr(address_short)
    Read a pointer from the program space with a 16-bit (near) address. 

    \note The address is a byte address. 
    The address is in the program space. */

#define pgm_read_ptr(address_short)     pgm_read_ptr_near(address_short)

/** \ingroup avr_pgmspace
    \def pgm_get_far_address(var)

   This macro facilitates the obtention of a 32 bit "far" pointer (only 24 bits
   used) to data even passed the 64KB limit for the 16 bit ordinary pointer. It
   is similar to the '&' operator, with some limitations.

   Comments:

   - The overhead is minimal and it's mainly due to the 32 bit size operation.

   - 24 bit sizes guarantees the code compatibility for use in future devices.

   - hh8() is an undocumented feature but seems to give the third significant byte
     of a 32 bit data and accepts symbols, complementing the functionality of hi8()
     and lo8(). There is not an equivalent assembler function to get the high
     significant byte.

   - 'var' has to be resolved at linking time as an existing symbol, i.e, a simple
     type variable name, an array name (not an indexed element of the array, if the
     index is a constant the compiler does not complain but fails to get the address
     if optimization is enabled), a struct name or a struct field name, a function
     identifier, a linker defined identifier,...

   - The returned value is the identifier's VMA (virtual memory address) determined
     by the linker and falls in the corresponding memory region. The AVR Harvard
     architecture requires non overlapping VMA areas for the multiple address spaces
     in the processor: Flash ROM, RAM, and EEPROM. Typical offset for this are
     0x00000000, 0x00800xx0, and 0x00810000 respectively, derived from the linker
     script used and linker options. The value returned can be seen then as a
     universal pointer.
*/

#define pgm_get_far_address(var)                          \
({                                                    \
	uint_farptr_t tmp;                                \
                                                      \
	__asm__ __volatile__(                             \
                                                      \
			"ldi	%A0, lo8(%1)"           "\n\t"    \
			"ldi	%B0, hi8(%1)"           "\n\t"    \
			"ldi	%C0, hh8(%1)"           "\n\t"    \
			"clr	%D0"                    "\n\t"    \
		:                                             \
			"=d" (tmp)                                \
		:                                             \
			"p"  (&(var))                             \
	);                                                \
	tmp;                                              \
})



/** \ingroup avr_pgmspace
    \fn const void * memchr_P(const void *s, int val, size_t len)
    \brief Scan flash memory for a character.

    The memchr_P() function scans the first \p len bytes of the flash
    memory area pointed to by \p s for the character \p val.  The first
    byte to match \p val (interpreted as an unsigned character) stops
    the operation.

    \return The memchr_P() function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area.	*/
extern const void * memchr_P(const void *, int __val, size_t __len) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn int memcmp_P(const void *s1, const void *s2, size_t len)
    \brief Compare memory areas

    The memcmp_P() function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations.

    \returns The memcmp_P() function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.	*/
extern int memcmp_P(const void *, const void *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn void *memccpy_P (void *dest, const void *src, int val, size_t len)

    This function is similar to memccpy() except that \p src is pointer
    to a string in program space.	*/
extern void *memccpy_P(void *, const void *, int __val, size_t);

/** \ingroup avr_pgmspace
    \fn void *memcpy_P(void *dest, const void *src, size_t n)

    The memcpy_P() function is similar to memcpy(), except the src string
    resides in program space.

    \returns The memcpy_P() function returns a pointer to dest.  */
extern void *memcpy_P(void *, const void *, size_t);

/** \ingroup avr_pgmspace
    \fn void *memmem_P(const void *s1, size_t len1, const void *s2, size_t len2)

    The memmem_P() function is similar to memmem() except that \p s2 is
    pointer to a string in program space.	*/
extern void *memmem_P(const void *, size_t, const void *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn const void +memrchr_P(const void *src, int val, size_t len)

    The memrchr_P() function is like the memchr_P() function, except
    that it searches backwards from the end of the \p len bytes pointed
    to by \p src instead of forwards from the front. (Glibc, GNU extension.)

    \return The memrchr_P() function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area.	*/
extern const void * memrchr_P(const void *, int __val, size_t __len) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn char *strcat_P(char *dest, const char *src)

    The strcat_P() function is similar to strcat() except that the \e src
    string must be located in program space (flash).

    \returns The strcat() function returns a pointer to the resulting string
    \e dest. */
extern char *strcat_P(char *, const char *);

/** \ingroup avr_pgmspace
    \fn const char *strchr_P(const char *s, int val)
    \brief Locate character in program space string.

    The strchr_P() function locates the first occurrence of \p val
    (converted to a char) in the string pointed to by \p s in program
    space. The terminating null character is considered to be part of
    the string.

    The strchr_P() function is similar to strchr() except that \p s is
    pointer to a string in program space.

    \returns The strchr_P() function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern const char * strchr_P(const char *, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn const char *strchrnul_P(const char *s, int c)

    The strchrnul_P() function is like strchr_P() except that if \p c is
    not found in \p s, then it returns a pointer to the null byte at the
    end of \p s, rather than \c NULL. (Glibc, GNU extension.)

    \return The strchrnul_P() function returns a pointer to the matched
    character, or a pointer to the null byte at the end of \p s (i.e.,
    \c s+strlen(s)) if the character is not found.	*/
extern const char * strchrnul_P(const char *, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn int strcmp_P(const char *s1, const char *s2)

    The strcmp_P() function is similar to strcmp() except that \p s2 is
    pointer to a string in program space.

    \returns The strcmp_P() function returns an integer less than, equal
    to, or greater than zero if \p s1 is found, respectively, to be less
    than, to match, or be greater than \p s2. A consequence of the
    ordering used by strcmp_P() is that if \p s1 is an initial substring
    of \p s2, then \p s1 is considered to be "less than" \p s2. */
extern int strcmp_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strcpy_P(char *dest, const char *src)

    The strcpy_P() function is similar to strcpy() except that src is a
    pointer to a string in program space.

    \returns The strcpy_P() function returns a pointer to the destination
    string dest. */
extern char *strcpy_P(char *, const char *);

/** \ingroup avr_pgmspace
    \fn int strcasecmp_P(const char *s1, const char *s2)
    \brief Compare two strings ignoring case.

    The strcasecmp_P() function compares the two strings \p s1 and \p s2,
    ignoring the case of the characters.

    \param s1 A pointer to a string in the devices SRAM.
    \param s2 A pointer to a string in the devices Flash.

    \returns The strcasecmp_P() function returns an integer less than,
    equal to, or greater than zero if \p s1 is found, respectively, to
    be less than, to match, or be greater than \p s2. A consequence of
    the ordering used by strcasecmp_P() is that if \p s1 is an initial
    substring of \p s2, then \p s1 is considered to be "less than" \p s2. */
extern int strcasecmp_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strcasestr_P(const char *s1, const char *s2)

    This funtion is similar to strcasestr() except that \p s2 is pointer
    to a string in program space.	*/
extern char *strcasestr_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn size_t strcspn_P(const char *s, const char *reject)

    The strcspn_P() function calculates the length of the initial segment
    of \p s which consists entirely of characters not in \p reject. This
    function is similar to strcspn() except that \p reject is a pointer
    to a string in program space.

    \return The strcspn_P() function returns the number of characters in
    the initial segment of \p s which are not in the string \p reject.
    The terminating zero is not considered as a part of string.	*/
extern size_t strcspn_P(const char *__s, const char * __reject) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn size_t strlcat_P(char *dst, const char *src, size_t siz)
    \brief Concatenate two strings.

    The strlcat_P() function is similar to strlcat(), except that the \p src
    string must be located in program space (flash).

    Appends \p src to string \p dst of size \p siz (unlike strncat(),
    \p siz is the full size of \p dst, not space left).  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz <=
    \p strlen(dst)).

    \returns The strlcat_P() function returns strlen(src) + MIN(siz,
    strlen(initial dst)).  If retval >= siz, truncation occurred.	*/
extern size_t strlcat_P (char *, const char *, size_t );

/** \ingroup avr_pgmspace
    \fn size_t strlcpy_P(char *dst, const char *src, size_t siz)
    \brief Copy a string from progmem to RAM.

    Copy \p src to string \p dst of size \p siz.  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz == 0).
    The strlcpy_P() function is similar to strlcpy() except that the
    \p src is pointer to a string in memory space.

    \returns The strlcpy_P() function returns strlen(src). If
    retval >= siz, truncation occurred.  */
extern size_t strlcpy_P (char *, const char *, size_t );

/** \ingroup avr_pgmspace
    \fn size_t strnlen_P(const char *src, size_t len)
    \brief Determine the length of a fixed-size string.

    The strnlen_P() function is similar to strnlen(), except that \c src is a
    pointer to a string in program space.

    \returns The strnlen_P function returns strlen_P(src), if that is less than
    \c len, or \c len if there is no '\\0' character among the first \c len
    characters pointed to by \c src. */
extern size_t strnlen_P(const char *, size_t) __ATTR_CONST__; /* program memory can't change */

/** \ingroup avr_pgmspace
    \fn int strncmp_P(const char *s1, const char *s2, size_t n)

    The strncmp_P() function is similar to strcmp_P() except it only compares
    the first (at most) n characters of s1 and s2.

    \returns The strncmp_P() function returns an integer less than, equal to,
    or greater than zero if s1 (or the first n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than s2.  */
extern int strncmp_P(const char *, const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strncasecmp_P(const char *s1, const char *s2, size_t n)
    \brief Compare two strings ignoring case.

    The strncasecmp_P() function is similar to strcasecmp_P(), except it
    only compares the first \p n characters of \p s1.

    \param s1 A pointer to a string in the devices SRAM.
    \param s2 A pointer to a string in the devices Flash.
    \param n The maximum number of bytes to compare.

    \returns The strncasecmp_P() function returns an integer less than,
    equal to, or greater than zero if \p s1 (or the first \p n bytes
    thereof) is found, respectively, to be less than, to match, or be
    greater than \p s2. A consequence of the ordering used by
    strncasecmp_P() is that if \p s1 is an initial substring of \p s2,
    then \p s1 is considered to be "less than" \p s2.  */
extern int strncasecmp_P(const char *, const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strncat_P(char *dest, const char *src, size_t len)
    \brief Concatenate two strings.

    The strncat_P() function is similar to strncat(), except that the \e src
    string must be located in program space (flash).

    \returns The strncat_P() function returns a pointer to the resulting string
    dest.  */
extern char *strncat_P(char *, const char *, size_t);

/** \ingroup avr_pgmspace
    \fn char *strncpy_P(char *dest, const char *src, size_t n)

    The strncpy_P() function is similar to strcpy_P() except that not more
    than n bytes of src are copied.  Thus, if there is no null byte among the
    first n bytes of src, the result will not be null-terminated.

    In the case where the length of src is less than that of n, the remainder
    of dest will be padded with nulls.

    \returns The strncpy_P() function returns a pointer to the destination
    string dest.  */
extern char *strncpy_P(char *, const char *, size_t);

/** \ingroup avr_pgmspace
    \fn char *strpbrk_P(const char *s, const char *accept)

    The strpbrk_P() function locates the first occurrence in the string
    \p s of any of the characters in the flash string \p accept. This
    function is similar to strpbrk() except that \p accept is a pointer
    to a string in program space.

    \return  The strpbrk_P() function returns a pointer to the character
    in \p s that matches one of the characters in \p accept, or \c NULL
    if no such character is found. The terminating zero is not considered
    as a part of string: if one or both args are empty, the result will
    \c NULL. */
extern char *strpbrk_P(const char *__s, const char * __accept) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn const char *strrchr_P(const char *s, int val)
    \brief Locate character in string.

    The strrchr_P() function returns a pointer to the last occurrence of
    the character \p val in the flash string \p s.

    \return The strrchr_P() function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern const char * strrchr_P(const char *, int __val) __ATTR_CONST__;

/** \ingroup avr_pgmspace
    \fn char *strsep_P(char **sp, const char *delim)
    \brief Parse a string into tokens.

    The strsep_P() function locates, in the string referenced by \p *sp,
    the first occurrence of any character in the string \p delim (or the
    terminating '\\0' character) and replaces it with a '\\0'.  The
    location of the next character after the delimiter character (or \c
    NULL, if the end of the string was reached) is stored in \p *sp. An
    ``empty'' field, i.e. one caused by two adjacent delimiter
    characters, can be detected by comparing the location referenced by
    the pointer returned in \p *sp to '\\0'. This function is similar to
    strsep() except that \p delim is a pointer to a string in program
    space.

    \return The strsep_P() function returns a pointer to the original
    value of \p *sp. If \p *sp is initially \c NULL, strsep_P() returns
    \c NULL. */
extern char *strsep_P(char **__sp, const char * __delim);

/** \ingroup avr_pgmspace
    \fn size_t strspn_P(const char *s, const char *accept)

    The strspn_P() function calculates the length of the initial segment
    of \p s which consists entirely of characters in \p accept. This
    function is similar to strspn() except that \p accept is a pointer
    to a string in program space.

    \return  The strspn_P() function returns the number of characters in
    the initial segment of \p s which consist only of characters from \p
    accept. The terminating zero is not considered as a part of string.	*/
extern size_t strspn_P(const char *__s, const char * __accept) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strstr_P(const char *s1, const char *s2)
    \brief Locate a substring.

    The strstr_P() function finds the first occurrence of the substring
    \p s2 in the string \p s1.  The terminating '\\0' characters are not
    compared. The strstr_P() function is similar to strstr() except that
    \p s2 is pointer to a string in program space.

    \returns The strstr_P() function returns a pointer to the beginning
    of the substring, or NULL if the substring is not found. If \p s2
    points to a string of zero length, the function returns \p s1. */
extern char *strstr_P(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strtok_P(char *s, const char * delim)
    \brief Parses the string into tokens.

    strtok_P() parses the string \p s into tokens. The first call to
    strtok_P() should have \p s as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to strtok_P().
    The delimiter string \p delim may be different for each call.

    The strtok_P() function is similar to strtok() except that \p delim
    is pointer to a string in program space.

    \returns The strtok_P() function returns a pointer to the next token or
    NULL when no more tokens are found.

    \note strtok_P() is NOT reentrant. For a reentrant version of this
    function see strtok_rP().
 */
extern char *strtok_P(char *__s, const char * __delim);

/** \ingroup avr_pgmspace
    \fn char *strtok_rP (char *string, const char *delim, char **last)
    \brief Parses string into tokens.

    The strtok_rP() function parses \p string into tokens. The first call to
    strtok_rP() should have string as its first argument. Subsequent calls
    should have the first argument set to NULL. If a token ends with a
    delimiter, this delimiting character is overwritten with a '\\0' and a
    pointer to the next character is saved for the next call to strtok_rP().
    The delimiter string \p delim may be different for each call. \p last is
    a user allocated char* pointer. It must be the same while parsing the
    same string. strtok_rP() is a reentrant version of strtok_P().

    The strtok_rP() function is similar to strtok_r() except that \p delim
    is pointer to a string in program space.

    \returns The strtok_rP() function returns a pointer to the next token or
    NULL when no more tokens are found. */
extern char *strtok_rP(char *__s, const char * __delim, char **__last);

/** \ingroup avr_pgmspace
    \fn size_t strlen_PF(uint_farptr_t s)
    \brief Obtain the length of a string

    The strlen_PF() function is similar to strlen(), except that \e s is a
    far pointer to a string in program space.

    \param s A far pointer to the string in flash

    \returns The strlen_PF() function returns the number of characters in
    \e s. The contents of RAMPZ SFR are undefined when the function returns. */
extern size_t strlen_PF(uint_farptr_t src) __ATTR_CONST__; /* program memory can't change */

/** \ingroup avr_pgmspace
    \fn size_t strnlen_PF(uint_farptr_t s, size_t len)
    \brief Determine the length of a fixed-size string

    The strnlen_PF() function is similar to strnlen(), except that \e s is a
    far pointer to a string in program space.

    \param s A far pointer to the string in Flash
    \param len The maximum number of length to return

    \returns The strnlen_PF function returns strlen_P(\e s), if that is less
    than \e len, or \e len if there is no '\\0' character among the first \e
    len characters pointed to by \e s. The contents of RAMPZ SFR are
    undefined when the function returns. */
extern size_t strnlen_PF(uint_farptr_t src, size_t len) __ATTR_CONST__; /* program memory can't change */

/** \ingroup avr_pgmspace
    \fn void *memcpy_PF(void *dest, uint_farptr_t src, size_t n)
    \brief Copy a memory block from flash to SRAM

    The memcpy_PF() function is similar to memcpy(), except the data
    is copied from the program space and is addressed using a far pointer.

    \param dest A pointer to the destination buffer
    \param src A far pointer to the origin of data in flash memory
    \param n The number of bytes to be copied

    \returns The memcpy_PF() function returns a pointer to \e dst. The contents
    of RAMPZ SFR are undefined when the function returns. */
extern void *memcpy_PF(void *dest, uint_farptr_t src, size_t len);

/** \ingroup avr_pgmspace
    \fn char *strcpy_PF(char *dst, uint_farptr_t src)
    \brief Duplicate a string

    The strcpy_PF() function is similar to strcpy() except that \e src is a far
    pointer to a string in program space.

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash

    \returns The strcpy_PF() function returns a pointer to the destination
    string \e dst. The contents of RAMPZ SFR are undefined when the funcion
    returns. */
extern char *strcpy_PF(char *dest, uint_farptr_t src);

/** \ingroup avr_pgmspace
    \fn char *strncpy_PF(char *dst, uint_farptr_t src, size_t n)
    \brief Duplicate a string until a limited length

    The strncpy_PF() function is similar to strcpy_PF() except that not more
    than \e n bytes of \e src are copied.  Thus, if there is no null byte among
    the first \e n bytes of \e src, the result will not be null-terminated.

    In the case where the length of \e src is less than that of \e n, the
    remainder of \e dst will be padded with nulls.

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The maximum number of bytes to copy

    \returns The strncpy_PF() function returns a pointer to the destination
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns. */
extern char *strncpy_PF(char *dest, uint_farptr_t src, size_t len);

/** \ingroup avr_pgmspace
    \fn char *strcat_PF(char *dst, uint_farptr_t src)
    \brief Concatenates two strings

    The strcat_PF() function is similar to strcat() except that the \e src
    string must be located in program space (flash) and is addressed using
    a far pointer

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the string to be appended in Flash

    \returns The strcat_PF() function returns a pointer to the resulting
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns */
extern char *strcat_PF(char *dest, uint_farptr_t src);

/** \ingroup avr_pgmspace
    \fn size_t strlcat_PF(char *dst, uint_farptr_t src, size_t n)
    \brief Concatenate two strings

    The strlcat_PF() function is similar to strlcat(), except that the \e src
    string must be located in program space (flash) and is addressed using
    a far pointer.

    Appends src to string dst of size \e n (unlike strncat(), \e n is the
    full size of \e dst, not space left).  At most \e n-1 characters
    will be copied.  Always NULL terminates (unless \e n <= strlen(\e dst)).

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The total number of bytes allocated to the destination string

    \returns The strlcat_PF() function returns strlen(\e src) + MIN(\e n,
    strlen(initial \e dst)).  If retval >= \e n, truncation occurred. The
    contents of RAMPZ SFR are undefined when the funcion returns. */
extern size_t strlcat_PF(char *dst, uint_farptr_t src, size_t siz);

/** \ingroup avr_pgmspace
    \fn char *strncat_PF(char *dst, uint_farptr_t src, size_t n)
    \brief Concatenate two strings

    The strncat_PF() function is similar to strncat(), except that the \e src
    string must be located in program space (flash) and is addressed using a
    far pointer.

    \param dst A pointer to the destination string in SRAM
    \param src A far pointer to the source string in Flash
    \param n The maximum number of bytes to append

    \returns The strncat_PF() function returns a pointer to the resulting
    string \e dst. The contents of RAMPZ SFR are undefined when the function
    returns. */
extern char *strncat_PF(char *dest, uint_farptr_t src, size_t len);

/** \ingroup avr_pgmspace
    \fn int strcmp_PF(const char *s1, uint_farptr_t s2)
    \brief Compares two strings

    The strcmp_PF() function is similar to strcmp() except that \e s2 is a far
    pointer to a string in program space.

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash

    \returns The strcmp_PF() function returns an integer less than, equal to,
    or greater than zero if \e s1 is found, respectively, to be less than, to
    match, or be greater than \e s2. The contents of RAMPZ SFR are undefined
    when the function returns. */
extern int strcmp_PF(const char *s1, uint_farptr_t s2) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strncmp_PF(const char *s1, uint_farptr_t s2, size_t n)
    \brief Compare two strings with limited length

    The strncmp_PF() function is similar to strcmp_PF() except it only
    compares the first (at most) \e n characters of \e s1 and \e s2.

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash
    \param n The maximum number of bytes to compare

    \returns The strncmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. The
    contents of RAMPZ SFR are undefined when the function returns. */
extern int strncmp_PF(const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strcasecmp_PF(const char *s1, uint_farptr_t s2)
    \brief Compare two strings ignoring case

    The strcasecmp_PF() function compares the two strings \e s1 and \e s2, ignoring
    the case of the characters.

    \param s1 A pointer to the first string in SRAM
    \param s2 A far pointer to the second string in Flash

    \returns The strcasecmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 is found, respectively, to be less than, to
    match, or be greater than \e s2. The contents of RAMPZ SFR are undefined
    when the function returns. */
extern int strcasecmp_PF(const char *s1, uint_farptr_t s2) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn int strncasecmp_PF(const char *s1, uint_farptr_t s2, size_t n)
    \brief Compare two strings ignoring case

    The strncasecmp_PF() function is similar to strcasecmp_PF(), except it
    only compares the first \e n characters of \e s1 and the string in flash is
    addressed using a far pointer.

    \param s1 A pointer to a string in SRAM
    \param s2 A far pointer to a string in Flash
    \param n The maximum number of bytes to compare

    \returns The strncasecmp_PF() function returns an integer less than, equal
    to, or greater than zero if \e s1 (or the first \e n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than \e s2. The
    contents of RAMPZ SFR are undefined when the function returns.  */
extern int strncasecmp_PF(const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;

/** \ingroup avr_pgmspace
    \fn char *strstr_PF(const char *s1, uint_farptr_t s2)
    \brief Locate a substring.

    The strstr_PF() function finds the first occurrence of the substring \c s2
    in the string \c s1.  The terminating '\\0' characters are not
    compared.
    The strstr_PF() function is similar to strstr() except that \c s2 is a
    far pointer to a string in program space.

    \returns The strstr_PF() function returns a pointer to the beginning of the
    substring, or NULL if the substring is not found.
    If \c s2 points to a string of zero length, the function returns \c s1. The
    contents of RAMPZ SFR are undefined when the function returns. */
extern char *strstr_PF(const char *s1, uint_farptr_t s2);

/** \ingroup avr_pgmspace
    \fn size_t strlcpy_PF(char *dst, uint_farptr_t src, size_t siz)
    \brief Copy a string from progmem to RAM.

    Copy src to string dst of size siz.  At most siz-1 characters will be
    copied. Always NULL terminates (unless siz == 0).

    \returns The strlcpy_PF() function returns strlen(src). If retval >= siz,
    truncation occurred.  The contents of RAMPZ SFR are undefined when the
    function returns. */
extern size_t strlcpy_PF(char *dst, uint_farptr_t src, size_t siz);

/** \ingroup avr_pgmspace
    \fn int memcmp_PF(const void *s1, uint_farptr_t s2, size_t len)
    \brief Compare memory areas

    The memcmp_PF() function compares the first \p len bytes of the memory
    areas \p s1 and flash \p s2. The comparision is performed using unsigned
    char operations. It is an equivalent of memcmp_P() function, except
    that it is capable working on all FLASH including the exteded area
    above 64kB.

    \returns The memcmp_PF() function returns an integer less than, equal
    to, or greater than zero if the first \p len bytes of \p s1 is found,
    respectively, to be less than, to match, or be greater than the first
    \p len bytes of \p s2.  */
extern int memcmp_PF(const void *, uint_farptr_t, size_t) __ATTR_PURE__;

#ifdef __DOXYGEN__
/** \ingroup avr_pgmspace
    \fn size_t strlen_P(const char *src)

    The strlen_P() function is similar to strlen(), except that src is a
    pointer to a string in program space.

    \returns The strlen_P() function returns the number of characters in src.

    \note strlen_P() is implemented as an inline function in the avr/pgmspace.h
    header file, which will check if the length of the string is a constant
    and known at compile time. If it is not known at compile time, the macro
    will issue a call to __strlen_P() which will then calculate the length
    of the string as normal.
*/
static inline size_t strlen_P(const char * s);
#else
extern size_t __strlen_P(const char *) __ATTR_CONST__;  /* internal helper function */
__attribute__((__always_inline__)) static __inline__ size_t strlen_P(const char * s);
static __inline__ size_t strlen_P(const char *s) {
  return __builtin_constant_p(__builtin_strlen(s))
     ? __builtin_strlen(s) : __strlen_P(s);
}
#endif

#ifdef __cplusplus
}
#endif

#endif /* __PGMSPACE_H_ */
