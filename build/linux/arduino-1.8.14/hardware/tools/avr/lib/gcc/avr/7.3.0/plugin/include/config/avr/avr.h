/* Definitions of target machine for GNU compiler,
   for ATMEL AVR at90s8515, ATmega103/103L, ATmega603/603L microcontrollers.
   Copyright (C) 1998-2017 Free Software Foundation, Inc.
   Contributed by Denis Chertykov (chertykov@gmail.com)

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

typedef struct
{
  /* Id of the address space as used in c_register_addr_space */
  unsigned char id;

  /* Flavour of memory: 0 = RAM, 1 = Flash */
  int memory_class;

  /* Width of pointer (in bytes) */
  int pointer_size;

  /* Name of the address space as visible to the user */
  const char *name;

  /* Segment (i.e. 64k memory chunk) number.  */
  int segment;

  /* Section prefix, e.g. ".progmem1.data"  */
  const char *section_name;
} avr_addrspace_t;

extern const avr_addrspace_t avr_addrspace[];

/* Known address spaces */

enum
  {
    ADDR_SPACE_RAM, /* ADDR_SPACE_GENERIC */
    ADDR_SPACE_FLASH,
    ADDR_SPACE_FLASH1,
    ADDR_SPACE_FLASH2,
    ADDR_SPACE_FLASH3,
    ADDR_SPACE_FLASH4,
    ADDR_SPACE_FLASH5,
    ADDR_SPACE_MEMX,
    /* Sentinel */
    ADDR_SPACE_COUNT
  };

#define TARGET_CPU_CPP_BUILTINS()	avr_cpu_cpp_builtins (pfile)

#define AVR_SHORT_CALLS (TARGET_SHORT_CALLS                             \
                         && avr_arch == &avr_arch_types[ARCH_AVRXMEGA3])
#define AVR_HAVE_JMP_CALL (avr_arch->have_jmp_call && ! AVR_SHORT_CALLS)
#define AVR_HAVE_MUL (avr_arch->have_mul)
#define AVR_HAVE_MOVW (avr_arch->have_movw_lpmx)
#define AVR_HAVE_LPM (!AVR_TINY)
#define AVR_HAVE_LPMX (avr_arch->have_movw_lpmx)
#define AVR_HAVE_ELPM (avr_arch->have_elpm)
#define AVR_HAVE_ELPMX (avr_arch->have_elpmx)
#define AVR_HAVE_RAMPD (avr_arch->have_rampd)
#define AVR_HAVE_RAMPX (avr_arch->have_rampd)
#define AVR_HAVE_RAMPY (avr_arch->have_rampd)
#define AVR_HAVE_RAMPZ (avr_arch->have_elpm             \
                        || avr_arch->have_rampd)
#define AVR_HAVE_EIJMP_EICALL (avr_arch->have_eijmp_eicall)

#define AVR_TINY_PM_OFFSET (0x4000)

/* Handling of 8-bit SP versus 16-bit SP is as follows:

FIXME: DRIVER_SELF_SPECS has changed.
   -msp8 is used internally to select the right multilib for targets with
   8-bit SP.  -msp8 is set automatically by DRIVER_SELF_SPECS for devices
   with 8-bit SP or by multilib generation machinery.  If a frame pointer is
   needed and SP is only 8 bits wide, SP is zero-extended to get FP.

   TARGET_TINY_STACK is triggered by -mtiny-stack which is a user option.
   This option has no effect on multilib selection.  It serves to save some
   bytes on 16-bit SP devices by only changing SP_L and leaving SP_H alone.

   These two properties are reflected by built-in macros __AVR_SP8__ resp.
   __AVR_HAVE_8BIT_SP__ and __AVR_HAVE_16BIT_SP__.  During multilib generation
   there is always __AVR_SP8__ == __AVR_HAVE_8BIT_SP__.  */

#define AVR_HAVE_8BIT_SP                        \
  (TARGET_TINY_STACK || avr_sp8)

#define AVR_HAVE_SPH (!avr_sp8)

#define AVR_2_BYTE_PC (!AVR_HAVE_EIJMP_EICALL)
#define AVR_3_BYTE_PC (AVR_HAVE_EIJMP_EICALL)

#define AVR_XMEGA (avr_arch->xmega_p)
#define AVR_TINY  (avr_arch->tiny_p)

#define BITS_BIG_ENDIAN 0
#define BYTES_BIG_ENDIAN 0
#define WORDS_BIG_ENDIAN 0

#ifdef IN_LIBGCC2
/* This is to get correct SI and DI modes in libgcc2.c (32 and 64 bits).  */
#define UNITS_PER_WORD 4
#else
/* Width of a word, in units (bytes).  */
#define UNITS_PER_WORD 1
#endif

#define POINTER_SIZE 16


/* Maximum sized of reasonable data type
   DImode or Dfmode ...  */
#define MAX_FIXED_MODE_SIZE 32

#define PARM_BOUNDARY 8

#define FUNCTION_BOUNDARY 8

#define EMPTY_FIELD_BOUNDARY 8

/* No data type wants to be aligned rounder than this.  */
#define BIGGEST_ALIGNMENT 8

#define TARGET_VTABLE_ENTRY_ALIGN 8

#define STRICT_ALIGNMENT 0

#define INT_TYPE_SIZE (TARGET_INT8 ? 8 : 16)
#define SHORT_TYPE_SIZE (INT_TYPE_SIZE == 8 ? INT_TYPE_SIZE : 16)
#define LONG_TYPE_SIZE (INT_TYPE_SIZE == 8 ? 16 : 32)
#define LONG_LONG_TYPE_SIZE (INT_TYPE_SIZE == 8 ? 32 : 64)
#define FLOAT_TYPE_SIZE 32
#define DOUBLE_TYPE_SIZE 32
#define LONG_DOUBLE_TYPE_SIZE 32
#define LONG_LONG_ACCUM_TYPE_SIZE 64

#define DEFAULT_SIGNED_CHAR 1

#define SIZE_TYPE (INT_TYPE_SIZE == 8 ? "long unsigned int" : "unsigned int")
#define PTRDIFF_TYPE (INT_TYPE_SIZE == 8 ? "long int" :"int")

#define WCHAR_TYPE "int"
#define WINT_TYPE "int"
#define WCHAR_TYPE_SIZE 16

#define FIRST_PSEUDO_REGISTER 36

#define FIXED_REGISTERS {\
  1,1,/* r0 r1 */\
  0,0,/* r2 r3 */\
  0,0,/* r4 r5 */\
  0,0,/* r6 r7 */\
  0,0,/* r8 r9 */\
  0,0,/* r10 r11 */\
  0,0,/* r12 r13 */\
  0,0,/* r14 r15 */\
  0,0,/* r16 r17 */\
  0,0,/* r18 r19 */\
  0,0,/* r20 r21 */\
  0,0,/* r22 r23 */\
  0,0,/* r24 r25 */\
  0,0,/* r26 r27 */\
  0,0,/* r28 r29 */\
  0,0,/* r30 r31 */\
  1,1,/*  STACK */\
  1,1 /* arg pointer */  }

#define CALL_USED_REGISTERS {			\
  1,1,/* r0 r1 */				\
    0,0,/* r2 r3 */				\
    0,0,/* r4 r5 */				\
    0,0,/* r6 r7 */				\
    0,0,/* r8 r9 */				\
    0,0,/* r10 r11 */				\
    0,0,/* r12 r13 */				\
    0,0,/* r14 r15 */				\
    0,0,/* r16 r17 */				\
    1,1,/* r18 r19 */				\
    1,1,/* r20 r21 */				\
    1,1,/* r22 r23 */				\
    1,1,/* r24 r25 */				\
    1,1,/* r26 r27 */				\
    0,0,/* r28 r29 */				\
    1,1,/* r30 r31 */				\
    1,1,/*  STACK */				\
    1,1 /* arg pointer */  }

#define REG_ALLOC_ORDER {			\
    24,25,					\
    18,19,					\
    20,21,					\
    22,23,					\
    30,31,					\
    26,27,					\
    28,29,					\
    17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,	\
    0,1,					\
    32,33,34,35					\
    }

#define ADJUST_REG_ALLOC_ORDER avr_adjust_reg_alloc_order()


#define HARD_REGNO_NREGS(REGNO, MODE)                                   \
  ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)

#define HARD_REGNO_MODE_OK(REGNO, MODE) avr_hard_regno_mode_ok(REGNO, MODE)

#define MODES_TIEABLE_P(MODE1, MODE2) 1

enum reg_class {
  NO_REGS,
  R0_REG,			/* r0 */
  POINTER_X_REGS,		/* r26 - r27 */
  POINTER_Y_REGS,		/* r28 - r29 */
  POINTER_Z_REGS,		/* r30 - r31 */
  STACK_REG,			/* STACK */
  BASE_POINTER_REGS,		/* r28 - r31 */
  POINTER_REGS,			/* r26 - r31 */
  ADDW_REGS,			/* r24 - r31 */
  SIMPLE_LD_REGS,		/* r16 - r23 */
  LD_REGS,			/* r16 - r31 */
  NO_LD_REGS,			/* r0 - r15 */
  GENERAL_REGS,			/* r0 - r31 */
  ALL_REGS, LIM_REG_CLASSES
};


#define N_REG_CLASSES (int)LIM_REG_CLASSES

#define REG_CLASS_NAMES {					\
		 "NO_REGS",					\
		   "R0_REG",	/* r0 */                        \
		   "POINTER_X_REGS", /* r26 - r27 */		\
		   "POINTER_Y_REGS", /* r28 - r29 */		\
		   "POINTER_Z_REGS", /* r30 - r31 */		\
		   "STACK_REG",	/* STACK */			\
		   "BASE_POINTER_REGS",	/* r28 - r31 */		\
		   "POINTER_REGS", /* r26 - r31 */		\
		   "ADDW_REGS",	/* r24 - r31 */			\
                   "SIMPLE_LD_REGS", /* r16 - r23 */            \
		   "LD_REGS",	/* r16 - r31 */			\
                   "NO_LD_REGS", /* r0 - r15 */                 \
		   "GENERAL_REGS", /* r0 - r31 */		\
		   "ALL_REGS" }

#define REG_CLASS_CONTENTS {						\
  {0x00000000,0x00000000},	/* NO_REGS */				\
  {0x00000001,0x00000000},	/* R0_REG */                            \
  {3u << REG_X,0x00000000},     /* POINTER_X_REGS, r26 - r27 */		\
  {3u << REG_Y,0x00000000},     /* POINTER_Y_REGS, r28 - r29 */		\
  {3u << REG_Z,0x00000000},     /* POINTER_Z_REGS, r30 - r31 */		\
  {0x00000000,0x00000003},	/* STACK_REG, STACK */			\
  {(3u << REG_Y) | (3u << REG_Z),					\
     0x00000000},		/* BASE_POINTER_REGS, r28 - r31 */	\
  {(3u << REG_X) | (3u << REG_Y) | (3u << REG_Z),			\
     0x00000000},		/* POINTER_REGS, r26 - r31 */		\
  {(3u << REG_X) | (3u << REG_Y) | (3u << REG_Z) | (3u << REG_W),	\
     0x00000000},		/* ADDW_REGS, r24 - r31 */		\
  {0x00ff0000,0x00000000},	/* SIMPLE_LD_REGS r16 - r23 */          \
  {(3u << REG_X)|(3u << REG_Y)|(3u << REG_Z)|(3u << REG_W)|(0xffu << 16),\
     0x00000000},	/* LD_REGS, r16 - r31 */			\
  {0x0000ffff,0x00000000},	/* NO_LD_REGS  r0 - r15 */              \
  {0xffffffff,0x00000000},	/* GENERAL_REGS, r0 - r31 */		\
  {0xffffffff,0x00000003}	/* ALL_REGS */				\
}

#define REGNO_REG_CLASS(R) avr_regno_reg_class(R)

#define MODE_CODE_BASE_REG_CLASS(mode, as, outer_code, index_code)   \
  avr_mode_code_base_reg_class (mode, as, outer_code, index_code)

#define INDEX_REG_CLASS NO_REGS

#define REGNO_MODE_CODE_OK_FOR_BASE_P(num, mode, as, outer_code, index_code) \
  avr_regno_mode_code_ok_for_base_p (num, mode, as, outer_code, index_code)

#define REGNO_OK_FOR_INDEX_P(NUM) 0

#define HARD_REGNO_CALL_PART_CLOBBERED(REGNO, MODE)     \
  avr_hard_regno_call_part_clobbered (REGNO, MODE)

#define TARGET_SMALL_REGISTER_CLASSES_FOR_MODE_P hook_bool_mode_true

#define STACK_PUSH_CODE POST_DEC

#define STACK_GROWS_DOWNWARD 1

#define STARTING_FRAME_OFFSET avr_starting_frame_offset()

#define STACK_POINTER_OFFSET 1

#define FIRST_PARM_OFFSET(FUNDECL) 0

#define STACK_BOUNDARY 8

#define STACK_POINTER_REGNUM 32

#define FRAME_POINTER_REGNUM REG_Y

#define ARG_POINTER_REGNUM 34

#define STATIC_CHAIN_REGNUM ((AVR_TINY) ? 18 :2)

#define ELIMINABLE_REGS {					\
    { ARG_POINTER_REGNUM, STACK_POINTER_REGNUM },               \
    { ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM },               \
    { FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM },             \
    { FRAME_POINTER_REGNUM + 1, STACK_POINTER_REGNUM + 1 } }

#define INITIAL_ELIMINATION_OFFSET(FROM, TO, OFFSET)			\
  OFFSET = avr_initial_elimination_offset (FROM, TO)

#define RETURN_ADDR_RTX(count, tem) avr_return_addr_rtx (count, tem)

/* Don't use Push rounding. expr.c: emit_single_push_insn is broken 
   for POST_DEC targets (PR27386).  */
/*#define PUSH_ROUNDING(NPUSHED) (NPUSHED)*/

typedef struct avr_args
{
  /* # Registers available for passing */
  int nregs;

  /* Next available register number */
  int regno;
} CUMULATIVE_ARGS;

#define INIT_CUMULATIVE_ARGS(CUM, FNTYPE, LIBNAME, FNDECL, N_NAMED_ARGS) \
  avr_init_cumulative_args (&(CUM), FNTYPE, LIBNAME, FNDECL)

#define FUNCTION_ARG_REGNO_P(r) avr_function_arg_regno_p(r)

#define DEFAULT_PCC_STRUCT_RETURN 0

#define EPILOGUE_USES(REGNO) avr_epilogue_uses(REGNO)

#define HAVE_POST_INCREMENT 1
#define HAVE_PRE_DECREMENT 1

#define MAX_REGS_PER_ADDRESS 1

#define LEGITIMIZE_RELOAD_ADDRESS(X,MODE,OPNUM,TYPE,IND_L,WIN)          \
  do {                                                                  \
    rtx new_x = avr_legitimize_reload_address (&(X), MODE, OPNUM, TYPE, \
                                               ADDR_TYPE (TYPE),        \
                                               IND_L, make_memloc);     \
    if (new_x)                                                          \
      {                                                                 \
        X = new_x;                                                      \
        goto WIN;                                                       \
      }                                                                 \
  } while (0)

/* We increase branch costs after reload in order to keep basic-block
   reordering from introducing out-of-line jumps and to prefer fall-through
   edges instead.  The default branch costs are 0, mainly because otherwise
   do_store_flag might come up with bloated code.  */
#define BRANCH_COST(speed_p, predictable_p)     \
  (avr_branch_cost + (reload_completed ? 4 : 0))

#define SLOW_BYTE_ACCESS 0

#define NO_FUNCTION_CSE 1

#define REGISTER_TARGET_PRAGMAS()                                       \
  do {                                                                  \
    avr_register_target_pragmas();                                      \
  } while (0)

#define TEXT_SECTION_ASM_OP "\t.text"

#define DATA_SECTION_ASM_OP "\t.data"

#define BSS_SECTION_ASM_OP "\t.section .bss"

/* Define the pseudo-ops used to switch to the .ctors and .dtors sections.
   There are no shared libraries on this target, and these sections are
   placed in the read-only program memory, so they are not writable.  */

#undef CTORS_SECTION_ASM_OP
#define CTORS_SECTION_ASM_OP "\t.section .ctors,\"a\",@progbits"

#undef DTORS_SECTION_ASM_OP
#define DTORS_SECTION_ASM_OP "\t.section .dtors,\"a\",@progbits"

#define TARGET_ASM_CONSTRUCTOR avr_asm_out_ctor

#define TARGET_ASM_DESTRUCTOR avr_asm_out_dtor

#define SUPPORTS_INIT_PRIORITY 0

#define JUMP_TABLES_IN_TEXT_SECTION 1

#define ASM_COMMENT_START " ; "

#define ASM_APP_ON "/* #APP */\n"

#define ASM_APP_OFF "/* #NOAPP */\n"

#define IS_ASM_LOGICAL_LINE_SEPARATOR(C, STR) ((C) == '\n' || ((C) == '$'))

#define ASM_OUTPUT_ALIGNED_DECL_COMMON(STREAM, DECL, NAME, SIZE, ALIGN) \
  avr_asm_output_aligned_decl_common (STREAM, DECL, NAME, SIZE, ALIGN, false)

#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN) \
  avr_asm_asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN, \
				  asm_output_aligned_bss)

#define ASM_OUTPUT_ALIGNED_DECL_LOCAL(STREAM, DECL, NAME, SIZE, ALIGN)  \
  avr_asm_output_aligned_decl_common (STREAM, DECL, NAME, SIZE, ALIGN, true)

/* Globalizing directive for a label.  */
#define GLOBAL_ASM_OP ".global\t"

#define SUPPORTS_WEAK 1

#define HAS_INIT_SECTION 1

#define REGISTER_NAMES {				\
  "r0","r1","r2","r3","r4","r5","r6","r7",		\
    "r8","r9","r10","r11","r12","r13","r14","r15",	\
    "r16","r17","r18","r19","r20","r21","r22","r23",	\
    "r24","r25","r26","r27","r28","r29","r30","r31",	\
    "__SP_L__","__SP_H__","argL","argH"}

#define FINAL_PRESCAN_INSN(insn, operand, nop)  \
  avr_final_prescan_insn (insn, operand,nop)

#define ASM_OUTPUT_REG_PUSH(STREAM, REGNO)	\
{						\
  gcc_assert (REGNO < 32);			\
  fprintf (STREAM, "\tpush\tr%d", REGNO);	\
}

#define ASM_OUTPUT_REG_POP(STREAM, REGNO)	\
{						\
  gcc_assert (REGNO < 32);			\
  fprintf (STREAM, "\tpop\tr%d", REGNO);	\
}

#define ASM_OUTPUT_ADDR_VEC_ELT(STREAM, VALUE)  \
  avr_output_addr_vec_elt (STREAM, VALUE)

#define ASM_OUTPUT_ALIGN(STREAM, POWER)                 \
  do {                                                  \
    if ((POWER) > 0)                                    \
      fprintf (STREAM, "\t.p2align\t%d\n", POWER);      \
  } while (0)

#define CASE_VECTOR_MODE HImode

#undef WORD_REGISTER_OPERATIONS

/* Can move only a single byte from memory to reg in a
   single instruction. */

#define MOVE_MAX 1

/* Allow upto two bytes moves to occur using by_pieces
   infrastructure */

#define MOVE_MAX_PIECES 2

/* Set MOVE_RATIO to 3 to allow memory moves upto 4 bytes to happen
   by pieces when optimizing for speed, like it did when MOVE_MAX_PIECES
   was 4. When optimizing for size, allow memory moves upto 2 bytes. 
   Also see avr_use_by_pieces_infrastructure_p. */

#define MOVE_RATIO(speed) ((speed) ? 3 : 2)

#define TRULY_NOOP_TRUNCATION(OUTPREC, INPREC) 1

#define Pmode HImode

#define FUNCTION_MODE HImode

#define DOLLARS_IN_IDENTIFIERS 0

#define TRAMPOLINE_SIZE 4

/* Store in cc_status the expressions
   that the condition codes will describe
   after execution of an instruction whose pattern is EXP.
   Do not alter them if the instruction would not alter the cc's.  */

#define NOTICE_UPDATE_CC(EXP, INSN) avr_notice_update_cc (EXP, INSN)

/* The add insns don't set overflow in a usable way.  */
#define CC_OVERFLOW_UNUSABLE 01000
/* The mov,and,or,xor insns don't set carry.  That's ok though as the
   Z bit is all we need when doing unsigned comparisons on the result of
   these insns (since they're always with 0).  However, conditions.h has
   CC_NO_OVERFLOW defined for this purpose.  Rename it to something more
   understandable.  */
#define CC_NO_CARRY CC_NO_OVERFLOW


/* Output assembler code to FILE to increment profiler label # LABELNO
   for profiling a function entry.  */

#define FUNCTION_PROFILER(FILE, LABELNO)  \
  fprintf (FILE, "/* profiler %d */", (LABELNO))

#define ADJUST_INSN_LENGTH(INSN, LENGTH)                \
    (LENGTH = avr_adjust_insn_length (INSN, LENGTH))

extern const char *avr_devicespecs_file (int, const char**);

#define EXTRA_SPEC_FUNCTIONS                                   \
  { "device-specs-file", avr_devicespecs_file },

/* Driver self specs has lmited functionality w.r.t. '%s' for dynamic specs.
   Apply '%s' to a static string to inflate the file (directory) name which
   is used to diagnose problems with reading the specs file.  */

#undef  DRIVER_SELF_SPECS
#define DRIVER_SELF_SPECS                       \
  " %:device-specs-file(device-specs%s %{mmcu=*:%*})"

/* No libstdc++ for now.  Empty string doesn't work.  */
#define LIBSTDCXX "gcc"

/* This is the default without any -mmcu=* option.  */
#define MULTILIB_DEFAULTS { "mmcu=" AVR_MMCU_DEFAULT }

#define TEST_HARD_REG_CLASS(CLASS, REGNO) \
  TEST_HARD_REG_BIT (reg_class_contents[ (int) (CLASS)], REGNO)

#define CR_TAB "\n\t"

#define DWARF2_ADDR_SIZE 4

#define INCOMING_RETURN_ADDR_RTX   avr_incoming_return_addr_rtx ()
#define INCOMING_FRAME_SP_OFFSET   (AVR_3_BYTE_PC ? 3 : 2)

/* The caller's stack pointer value immediately before the call
   is one byte below the first argument.  */
#define ARG_POINTER_CFA_OFFSET(FNDECL)  -1

#define HARD_REGNO_RENAME_OK(OLD_REG, NEW_REG) \
  avr_hard_regno_rename_ok (OLD_REG, NEW_REG)

/* A C structure for machine-specific, per-function data.
   This is added to the cfun structure.  */
struct GTY(()) machine_function
{
  /* 'true' - if current function is a naked function.  */
  int is_naked;

  /* 'true' - if current function is an interrupt function 
     as specified by the "interrupt" attribute.  */
  int is_interrupt;

  /* 'true' - if current function is a signal function 
     as specified by the "signal" attribute.  */
  int is_signal;

  /* 'true' - if current function is an nmi function 
     as specified by the "nmi" attribute.  */
  int is_nmi;
  
  /* 'true' - if current function is a 'task' function 
     as specified by the "OS_task" attribute.  */
  int is_OS_task;

  /* 'true' - if current function is a 'main' function 
     as specified by the "OS_main" attribute.  */
  int is_OS_main;
  
  /* Current function stack size.  */
  int stack_usage;

  /* 'true' if a callee might be tail called */
  int sibcall_fails;

  /* 'true' if the above is_foo predicates are sanity-checked to avoid
     multiple diagnose for the same function.  */
  int attributes_checked_p;
};

/* AVR does not round pushes, but the existence of this macro is
   required in order for pushes to be generated.  */
#define PUSH_ROUNDING(X)	(X)

/* Define prototype here to avoid build warning.  Some files using
   ACCUMULATE_OUTGOING_ARGS (directly or indirectly) include
   tm.h but not tm_p.h.  */
extern int avr_accumulate_outgoing_args (void);
#define ACCUMULATE_OUTGOING_ARGS avr_accumulate_outgoing_args()

#define INIT_EXPANDERS avr_init_expanders()

/* Flags used for io and address attributes.  */
#define SYMBOL_FLAG_IO_LOW	(SYMBOL_FLAG_MACH_DEP << 4)
#define SYMBOL_FLAG_IO		(SYMBOL_FLAG_MACH_DEP << 5)
#define SYMBOL_FLAG_ADDRESS	(SYMBOL_FLAG_MACH_DEP << 6)
