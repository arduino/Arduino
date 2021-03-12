/* Copyright (C) 2011-2017 Free Software Foundation, Inc.
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


/* Overriding some definitions from elfos.h for AVR.  */

#undef PCC_BITFIELD_TYPE_MATTERS

#undef PREFERRED_DEBUGGING_TYPE
#define PREFERRED_DEBUGGING_TYPE DBX_DEBUG

#undef MAX_OFILE_ALIGNMENT
#define MAX_OFILE_ALIGNMENT (32768 * 8)

#undef STRING_LIMIT
#define STRING_LIMIT ((unsigned) 64)

/* Output alignment 2**1 for jump tables.  */
#undef ASM_OUTPUT_BEFORE_CASE_LABEL
#define ASM_OUTPUT_BEFORE_CASE_LABEL(FILE, PREFIX, NUM, TABLE) \
  ASM_OUTPUT_ALIGN (FILE, 1);

/* Be conservative in crtstuff.c.  */
#undef INIT_SECTION_ASM_OP
#undef FINI_SECTION_ASM_OP
