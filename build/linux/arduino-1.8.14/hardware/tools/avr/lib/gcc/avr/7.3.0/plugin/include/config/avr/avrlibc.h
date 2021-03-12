/* Definitions of target machine for the GNU compiler collection
   for Atmel AVR micro controller if configured for AVR-Libc.
   Copyright (C) 2012-2017 Free Software Foundation, Inc.
   Contributed by Georg-Johann Lay (avr@gjlay.de)

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

#undef  LIB_SPEC
#define LIB_SPEC                                \
  "%{!mmcu=avr1:-lc} %(avrlibc_devicelib)"

// AVR-Libc implements functions from libgcc.a in libm.a, see PR54461.
// For a list of functions which are provided by libm.a and are
// omitted from libgcc.a see libgcc's t-avrlibc.

#undef  LIBGCC_SPEC
#define LIBGCC_SPEC                             \
  "%{!mmcu=avr1:-lgcc -lm}"

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC                          \
  " %(avrlibc_startfile) "

#undef  LINK_GCC_C_SEQUENCE_SPEC
#define LINK_GCC_C_SEQUENCE_SPEC \
  "--start-group %G %L --end-group"
