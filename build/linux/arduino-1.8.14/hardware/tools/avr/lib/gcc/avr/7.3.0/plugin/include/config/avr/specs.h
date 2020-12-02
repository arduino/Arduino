/* Specs definitions for Atmel AVR back end.

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


/* Default specs layout.  The actual definitions might be superseeded
   by device- or OS- specific files, like avrlibc.h, ../rtems.h, etc.
   The specs are repeated in the device specs files.  Subspecs are
   specs known to GCC or specs defined in the device specs files.  */


#undef  CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC                      \
  "%(cpp)"

#undef  CC1_SPEC
#define CC1_SPEC                                \
  "%(cc1_n_flash) "                             \
  "%(cc1_errata_skip) "                         \
  "%(cc1_rmw) "                                 \
  "%(cc1_non_bit_addressable_registers_mask) "  \
  "%(cc1_absdata) "

#undef  CC1PLUS_SPEC
#define CC1PLUS_SPEC                                    \
  "%(cc1) "                                             \
  "%{!frtti:-fno-rtti} "                                \
  "%{!fenforce-eh-specs:-fno-enforce-eh-specs} "        \
  "%{!fexceptions:-fno-exceptions} "

#define ASM_RELAX_SPEC                          \
  "%{mrelax:--mlink-relax} "

#undef  ASM_SPEC
#define ASM_SPEC                                \
  "%(asm_arch) "                                \
  "%(asm_relax) "                               \
  "%(asm_rmw) "                                 \
  "%(asm_errata_skip) "

#define LINK_ARCH_SPEC                          \
  "%{mmcu=*:-m%*} "

#define LINK_RELAX_SPEC                         \
  "%{mrelax:--relax} "

#undef  LINK_SPEC
#define LINK_SPEC                               \
  "%(link_arch) "                               \
  "%(link_data_start) "                         \
  "%(link_text_start) "                         \
  "%(link_relax) "                              \
  "%(link_pmem_wrap) "                          \
  "%{shared:%eshared is not supported} "

#undef  LIB_SPEC
#define LIB_SPEC " %{!mmcu=avr1:-lc} "

#undef  LIBGCC_SPEC
#define LIBGCC_SPEC " %{!mmcu=avr1:-lgcc} "

#define STARTFILE_SPEC ""
#define ENDFILE_SPEC ""
