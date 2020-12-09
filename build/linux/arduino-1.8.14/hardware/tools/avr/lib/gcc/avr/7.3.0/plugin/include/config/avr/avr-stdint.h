/* Definitions for <stdint.h> types on systems using newlib.
   Copyright (C) 2012-2017 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/*
   The intention of this file is to supply definitions that work with
   avr-gcc's -mint8 that sets int to an 8-bit type.

   This file is intended to yield the same results as newlib-stdint.h,
   but there are some differences to newlib-stdint.h:

   - AVR is an 8-bit architecture that cannot access 16-bit values
     atomically, this SIG_ATOMIC_TYPE is "char".

   - For the same reason, [u]int_fast8_t is defined as 8-bit type.

*/

#define SIG_ATOMIC_TYPE "char"

#define INT8_TYPE "signed char"
#define INT16_TYPE (INT_TYPE_SIZE == 16 ? "int" : "long int")
#define INT32_TYPE (INT_TYPE_SIZE == 16 ? "long int" : "long long int")
#define INT64_TYPE (INT_TYPE_SIZE == 16 ? "long long int" : 0)
#define UINT8_TYPE "unsigned char"
#define UINT16_TYPE (INT_TYPE_SIZE == 16 ? "unsigned int" : "long unsigned int")
#define UINT32_TYPE (INT_TYPE_SIZE == 16 ? "long unsigned int" : "long long unsigned int")
#define UINT64_TYPE (INT_TYPE_SIZE == 16 ? "long long unsigned int" : 0)

#define INT_LEAST8_TYPE INT8_TYPE
#define INT_LEAST16_TYPE INT16_TYPE
#define INT_LEAST32_TYPE INT32_TYPE
#define INT_LEAST64_TYPE INT64_TYPE
#define UINT_LEAST8_TYPE UINT8_TYPE
#define UINT_LEAST16_TYPE UINT16_TYPE
#define UINT_LEAST32_TYPE UINT32_TYPE
#define UINT_LEAST64_TYPE UINT64_TYPE

#define INT_FAST8_TYPE INT8_TYPE
#define INT_FAST16_TYPE (INT_TYPE_SIZE == 16 ? "int" : INT16_TYPE)
#define INT_FAST32_TYPE INT32_TYPE
#define INT_FAST64_TYPE INT64_TYPE
#define UINT_FAST8_TYPE UINT8_TYPE
#define UINT_FAST16_TYPE (INT_TYPE_SIZE == 16 ? "unsigned int" : UINT16_TYPE)
#define UINT_FAST32_TYPE UINT32_TYPE
#define UINT_FAST64_TYPE UINT64_TYPE

#define INTPTR_TYPE PTRDIFF_TYPE
#ifndef UINTPTR_TYPE
#define UINTPTR_TYPE SIZE_TYPE
#endif
