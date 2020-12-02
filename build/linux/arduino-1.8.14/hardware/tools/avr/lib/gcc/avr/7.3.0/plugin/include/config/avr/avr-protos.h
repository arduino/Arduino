/* Prototypes for exported functions defined in avr.c
   
   Copyright (C) 2000-2017 Free Software Foundation, Inc.
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


extern int avr_function_arg_regno_p (int r);
extern void avr_cpu_cpp_builtins (struct cpp_reader * pfile);
extern enum reg_class avr_regno_reg_class (int r);
extern void asm_globalize_label (FILE *file, const char *name);
extern void avr_adjust_reg_alloc_order (void);
extern int avr_initial_elimination_offset (int from, int to);
extern int avr_simple_epilogue (void);
extern int avr_hard_regno_rename_ok (unsigned int, unsigned int);
extern rtx avr_return_addr_rtx (int count, rtx tem);
extern void avr_register_target_pragmas (void);
extern void avr_init_expanders (void);

#ifdef TREE_CODE
extern void avr_asm_output_aligned_decl_common (FILE*, tree, const char*, unsigned HOST_WIDE_INT, unsigned int, bool);
extern void avr_asm_asm_output_aligned_bss (FILE *, tree, const char *, unsigned HOST_WIDE_INT, int, void (*) (FILE *, tree, const char *, unsigned HOST_WIDE_INT, int));
extern void asm_output_external (FILE *file, tree decl, char *name);
extern int avr_progmem_p (tree decl, tree attributes);
extern bool avr_addr_space_supported_p (addr_space_t, location_t loc = UNKNOWN_LOCATION);

#ifdef RTX_CODE /* inside TREE_CODE */
extern void avr_init_cumulative_args (CUMULATIVE_ARGS*, tree, rtx, tree);
#endif /* RTX_CODE inside TREE_CODE */

#endif /* TREE_CODE */

#ifdef RTX_CODE
extern int avr_hard_regno_call_part_clobbered (unsigned, machine_mode);
extern const char *output_movqi (rtx_insn *insn, rtx operands[], int *l);
extern const char *output_movhi (rtx_insn *insn, rtx operands[], int *l);
extern const char *output_movsisf (rtx_insn *insn, rtx operands[], int *l);
extern const char *avr_out_tstsi (rtx_insn *, rtx*, int*);
extern const char *avr_out_tsthi (rtx_insn *, rtx*, int*);
extern const char *avr_out_tstpsi (rtx_insn *, rtx*, int*);
extern const char *avr_out_compare (rtx_insn *, rtx*, int*);
extern const char *avr_out_compare64 (rtx_insn *, rtx*, int*);
extern const char *ret_cond_branch (rtx x, int len, int reverse);
extern const char *avr_out_movpsi (rtx_insn *, rtx*, int*);
extern const char *avr_out_sign_extend (rtx_insn *, rtx*, int*);
extern const char *avr_out_insert_notbit (rtx_insn *, rtx*, rtx, int*);

extern const char *ashlqi3_out (rtx_insn *insn, rtx operands[], int *len);
extern const char *ashlhi3_out (rtx_insn *insn, rtx operands[], int *len);
extern const char *ashlsi3_out (rtx_insn *insn, rtx operands[], int *len);

extern const char *ashrqi3_out (rtx_insn *insn, rtx operands[], int *len);
extern const char *ashrhi3_out (rtx_insn *insn, rtx operands[], int *len);
extern const char *ashrsi3_out (rtx_insn *insn, rtx operands[], int *len);

extern const char *lshrqi3_out (rtx_insn *insn, rtx operands[], int *len);
extern const char *lshrhi3_out (rtx_insn *insn, rtx operands[], int *len);
extern const char *lshrsi3_out (rtx_insn *insn, rtx operands[], int *len);

extern const char *avr_out_ashlpsi3 (rtx_insn *, rtx*, int*);
extern const char *avr_out_ashrpsi3 (rtx_insn *, rtx*, int*);
extern const char *avr_out_lshrpsi3 (rtx_insn *, rtx*, int*);

extern bool avr_rotate_bytes (rtx operands[]);

extern const char* avr_out_fract (rtx_insn *, rtx[], bool, int*);
extern rtx avr_to_int_mode (rtx);

extern void avr_expand_prologue (void);
extern void avr_expand_epilogue (bool);
extern bool avr_emit_movmemhi (rtx*);
extern int avr_epilogue_uses (int regno);
extern int avr_starting_frame_offset (void);

extern void avr_output_addr_vec_elt (FILE *stream, int value);
extern const char *avr_out_sbxx_branch (rtx_insn *insn, rtx operands[]);
extern const char* avr_out_bitop (rtx, rtx*, int*);
extern const char* avr_out_plus (rtx, rtx*, int* =NULL, int* =NULL, bool =true);
extern const char* avr_out_round (rtx_insn *, rtx*, int* =NULL);
extern const char* avr_out_addto_sp (rtx*, int*);
extern const char* avr_out_xload (rtx_insn *, rtx*, int*);
extern const char* avr_out_movmem (rtx_insn *, rtx*, int*);
extern const char* avr_out_insert_bits (rtx*, int*);
extern bool avr_popcount_each_byte (rtx, int, int);
extern bool avr_has_nibble_0xf (rtx);

extern int extra_constraint_Q (rtx x);
extern int avr_adjust_insn_length (rtx_insn *insn, int len);
extern const char* output_reload_inhi (rtx*, rtx, int*);
extern const char* output_reload_insisf (rtx*, rtx, int*);
extern const char* avr_out_reload_inpsi (rtx*, rtx, int*);
extern const char* avr_out_lpm (rtx_insn *, rtx*, int*);
extern void avr_notice_update_cc (rtx body, rtx_insn *insn);
extern int reg_unused_after (rtx_insn *insn, rtx reg);
extern int _reg_unused_after (rtx_insn *insn, rtx reg);
extern int avr_jump_mode (rtx x, rtx_insn *insn);
extern int test_hard_reg_class (enum reg_class rclass, rtx x);
extern int jump_over_one_insn_p (rtx_insn *insn, rtx dest);

extern int avr_hard_regno_mode_ok (int regno, machine_mode mode);
extern void avr_final_prescan_insn (rtx_insn *insn, rtx *operand,
				    int num_operands);
extern int avr_simplify_comparison_p (machine_mode mode,
				      RTX_CODE op, rtx x);
extern RTX_CODE avr_normalize_condition (RTX_CODE condition);
extern void out_shift_with_cnt (const char *templ, rtx_insn *insn,
				rtx operands[], int *len, int t_len);
extern enum reg_class avr_mode_code_base_reg_class (machine_mode, addr_space_t, RTX_CODE, RTX_CODE);
extern bool avr_regno_mode_code_ok_for_base_p (int, machine_mode, addr_space_t, RTX_CODE, RTX_CODE);
extern rtx avr_incoming_return_addr_rtx (void);
extern rtx avr_legitimize_reload_address (rtx*, machine_mode, int, int, int, int, rtx (*)(rtx,int));
extern bool avr_mem_flash_p (rtx);
extern bool avr_mem_memx_p (rtx);
extern bool avr_load_libgcc_p (rtx);
extern bool avr_xload_libgcc_p (machine_mode);
extern rtx avr_eval_addr_attrib (rtx x);
extern bool avr_casei_sequence_check_operands (rtx *xop);

static inline unsigned
regmask (machine_mode mode, unsigned regno)
{
  return ((1u << GET_MODE_SIZE (mode)) - 1) << regno;
}

extern void avr_fix_inputs (rtx*, unsigned, unsigned);
extern bool avr_emit3_fix_outputs (rtx (*)(rtx,rtx,rtx), rtx*, unsigned, unsigned);

extern rtx lpm_reg_rtx;
extern rtx lpm_addr_reg_rtx;
extern rtx tmp_reg_rtx;
extern rtx zero_reg_rtx;
extern rtx all_regs_rtx[32];
extern rtx rampz_rtx;

#endif /* RTX_CODE */

#ifdef REAL_VALUE_TYPE
extern void asm_output_float (FILE *file, REAL_VALUE_TYPE n);
#endif

extern bool avr_have_dimode;

namespace gcc { class context; }
class rtl_opt_pass;

extern rtl_opt_pass *make_avr_pass_recompute_notes (gcc::context *);
extern rtl_opt_pass *make_avr_pass_casesi (gcc::context *);

/* From avr-log.c */

#define avr_dump(...) avr_vdump (NULL, __FUNCTION__, __VA_ARGS__)
#define avr_edump(...) avr_vdump (stderr, __FUNCTION__, __VA_ARGS__)
#define avr_fdump(FIL, ...) avr_vdump (FIL, __FUNCTION__, __VA_ARGS__)

extern int avr_vdump (FILE*, const char*, ...);
extern void avr_log_set_avr_log (void);

typedef struct
{
  unsigned address_cost :1;
  unsigned builtin :1;
  unsigned constraints :1;
  unsigned legitimate_address_p :1;
  unsigned legitimize_address :1;
  unsigned legitimize_reload_address :1;
  unsigned progmem :1;
  unsigned rtx_costs :1;
} avr_log_t;

extern avr_log_t avr_log;
extern unsigned long avr_non_bit_addressable_registers_mask;
