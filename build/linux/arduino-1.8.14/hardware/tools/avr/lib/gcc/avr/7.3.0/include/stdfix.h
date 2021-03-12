/* Copyright (C) 2007-2017 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* ISO/IEC JTC1 SC22 WG14 N1169
 * Date: 2006-04-04
 * ISO/IEC TR 18037
 * Programming languages - C - Extensions to support embedded processors
 */

#ifndef _AVRGCC_STDFIX_H
#define _AVRGCC_STDFIX_H

/* 7.18a.1 Introduction.  */
/* 7.18a.3 Precision macros.  */

#include <stdfix-gcc.h>


#if __SIZEOF_INT__ == 2

typedef signed char int_hr_t;
typedef unsigned char uint_uhr_t;

typedef short int int_r_t;
typedef short unsigned int uint_ur_t;

typedef short int int_hk_t;
typedef short unsigned int uint_uhk_t;

typedef long int int_lr_t;
typedef long unsigned int uint_ulr_t;

typedef long int int_k_t;
typedef long unsigned int uint_uk_t;

typedef long long int int_llr_t;
typedef long long unsigned int uint_ullr_t;

typedef long long int int_lk_t;
typedef long long unsigned int uint_ulk_t;

typedef long long int int_llk_t;
typedef long long unsigned int uint_ullk_t;

#elif __SIZEOF_INT__ == 1  /*  -mint8  */

typedef signed char int_hr_t;
typedef unsigned char uint_uhr_t;

typedef long int int_r_t;
typedef long unsigned int uint_ur_t;

typedef long int int_hk_t;
typedef long unsigned int uint_uhk_t;

typedef long long int int_lr_t;
typedef long long unsigned int uint_ulr_t;

typedef long long int int_k_t;
typedef long long unsigned int uint_uk_t;

#endif /* __SIZEOF_INT__ == 1, 2 */


/* 7.18a.6  The fixed-point intrinsic functions.  */


/* 7.18a.6.2  The fixed-point absolute value functions.  */

#define abshr __builtin_avr_abshr
#define absr  __builtin_avr_absr
#define abslr __builtin_avr_abslr

#define abshk __builtin_avr_abshk
#define absk  __builtin_avr_absk

#if __SIZEOF_INT__ == 2

#define abslk  __builtin_avr_abslk
#define absllr __builtin_avr_absllr  /* GCC Extension */
#define absllk __builtin_avr_absllk  /* GCC Extension */

#endif /* sizeof (int) == 2 */


/* 7.18a.6.3  The fixed-point round functions.  */

/* The Embedded-C paper specifies results only for rounding points

       0 < RP < FBIT
  
   As an extension, the following functions work as expected
   with rounding points

       -IBIT < RP < FBIT
 
   For example, rounding an accum with a rounding point of -1 will
   result in an even integer value.  */

#define roundhr  __builtin_avr_roundhr
#define roundr   __builtin_avr_roundr
#define roundlr  __builtin_avr_roundlr

#define rounduhr __builtin_avr_rounduhr
#define roundur  __builtin_avr_roundur
#define roundulr __builtin_avr_roundulr

#define roundhk  __builtin_avr_roundhk
#define roundk   __builtin_avr_roundk

#define rounduhk __builtin_avr_rounduhk
#define rounduk  __builtin_avr_rounduk

#if __SIZEOF_INT__ == 2

#define roundlk   __builtin_avr_roundlk
#define roundulk  __builtin_avr_roundulk
#define roundllr  __builtin_avr_roundllr  /* GCC Extension */
#define roundullr __builtin_avr_roundullr /* GCC Extension */
#define roundllk  __builtin_avr_roundllk  /* GCC Extension */
#define roundullk __builtin_avr_roundullk /* GCC Extension */

#endif /* sizeof (int) == 2 */


/* 7.18a.6.4  The fixed-point bit countls functions.  */

#define countlshr  __builtin_avr_countlshr
#define countlsr   __builtin_avr_countlsr
#define countlslr  __builtin_avr_countlslr

#define countlsuhr __builtin_avr_countlsuhr
#define countlsur  __builtin_avr_countlsur
#define countlsulr __builtin_avr_countlsulr

#define countlshk  __builtin_avr_countlshk
#define countlsk   __builtin_avr_countlsk

#define countlsuhk __builtin_avr_countlsuhk
#define countlsuk  __builtin_avr_countlsuk

#if __SIZEOF_INT__ == 2

#define countlslk   __builtin_avr_countlslk
#define countlsulk  __builtin_avr_countlsulk
#define countlsllr  __builtin_avr_countlsllr  /* GCC Extension */
#define countlsullr __builtin_avr_countlsullr /* GCC Extension */
#define countlsllk  __builtin_avr_countlsllk  /* GCC Extension */
#define countlsullk __builtin_avr_countlsullk /* GCC Extension */

#endif /* sizeof (int) == 2 */


/* 7.18a.6.5  The bitwise fixed-point to integer conversion functions. */

#define bitshr  __builtin_avr_bitshr
#define bitsr   __builtin_avr_bitsr
#define bitslr  __builtin_avr_bitslr

#define bitsuhr __builtin_avr_bitsuhr
#define bitsur  __builtin_avr_bitsur
#define bitsulr __builtin_avr_bitsulr

#define bitshk  __builtin_avr_bitshk
#define bitsk   __builtin_avr_bitsk

#define bitsuhk __builtin_avr_bitsuhk
#define bitsuk  __builtin_avr_bitsuk

#if __SIZEOF_INT__ == 2

#define bitslk   __builtin_avr_bitslk
#define bitsulk  __builtin_avr_bitsulk
#define bitsllr  __builtin_avr_bitsllr  /* GCC Extension */
#define bitsullr __builtin_avr_bitsullr /* GCC Extension */
#define bitsllk  __builtin_avr_bitsllk  /* GCC Extension */
#define bitsullk __builtin_avr_bitsullk /* GCC Extension */

#endif /* sizeof (int) == 2 */


/* 7.18a.6.6  The bitwise integer to fixed-point conversion functions. */

#define hrbits  __builtin_avr_hrbits
#define rbits   __builtin_avr_rbits
#define lrbits  __builtin_avr_lrbits

#define uhrbits __builtin_avr_uhrbits
#define urbits  __builtin_avr_urbits
#define ulrbits __builtin_avr_ulrbits

#define hkbits  __builtin_avr_hkbits
#define kbits   __builtin_avr_kbits

#define uhkbits __builtin_avr_uhkbits
#define ukbits  __builtin_avr_ukbits

#if __SIZEOF_INT__ == 2

#define lkbits   __builtin_avr_lkbits
#define ulkbits  __builtin_avr_ulkbits
#define llrbits  __builtin_avr_llrbits  /* GCC Extension */
#define ullrbits __builtin_avr_ullrbits /* GCC Extension */
#define llkbits  __builtin_avr_llkbits  /* GCC Extension */
#define ullkbits __builtin_avr_ullkbits /* GCC Extension */

#endif /* sizeof (int) == 2 */


/* 7.18a.6.7  Type-generic fixed-point functions.  */

#define absfx     __builtin_avr_absfx
#define roundfx   __builtin_avr_roundfx
#define countlsfx __builtin_avr_countlsfx


/* Hook in stuff from AVR-Libc.  */

#if (defined (__WITH_AVRLIBC__)                 \
     && defined (__has_include)                 \
     && __has_include (<stdfix-avrlibc.h>))
#include <stdfix-avrlibc.h>
#endif

#endif /* _AVRGCC_STDFIX_H */
