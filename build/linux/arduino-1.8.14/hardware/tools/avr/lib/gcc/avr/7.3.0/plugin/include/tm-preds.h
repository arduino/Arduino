/* Generated automatically by the program 'build/genpreds'
   from the machine description file '../../gcc/gcc/config/avr/avr.md'.  */

#ifndef GCC_TM_PREDS_H
#define GCC_TM_PREDS_H

#ifdef HAVE_MACHINE_MODES
extern int general_operand (rtx, machine_mode);
extern int address_operand (rtx, machine_mode);
extern int register_operand (rtx, machine_mode);
extern int pmode_register_operand (rtx, machine_mode);
extern int scratch_operand (rtx, machine_mode);
extern int immediate_operand (rtx, machine_mode);
extern int const_int_operand (rtx, machine_mode);
extern int const_double_operand (rtx, machine_mode);
extern int nonimmediate_operand (rtx, machine_mode);
extern int nonmemory_operand (rtx, machine_mode);
extern int push_operand (rtx, machine_mode);
extern int pop_operand (rtx, machine_mode);
extern int memory_operand (rtx, machine_mode);
extern int indirect_operand (rtx, machine_mode);
extern int ordered_comparison_operator (rtx, machine_mode);
extern int comparison_operator (rtx, machine_mode);
extern int l_register_operand (rtx, machine_mode);
extern int d_register_operand (rtx, machine_mode);
extern int even_register_operand (rtx, machine_mode);
extern int odd_register_operand (rtx, machine_mode);
extern int stack_register_operand (rtx, machine_mode);
extern int low_io_address_operand (rtx, machine_mode);
extern int high_io_address_operand (rtx, machine_mode);
extern int io_address_operand (rtx, machine_mode);
extern int nop_general_operand (rtx, machine_mode);
extern int nox_general_operand (rtx, machine_mode);
extern int const0_operand (rtx, machine_mode);
extern int const1_operand (rtx, machine_mode);
extern int const_0_to_7_operand (rtx, machine_mode);
extern int const_2_to_7_operand (rtx, machine_mode);
extern int const_1_to_6_operand (rtx, machine_mode);
extern int const_2_to_6_operand (rtx, machine_mode);
extern int const_m255_to_m1_operand (rtx, machine_mode);
extern int reg_or_0_operand (rtx, machine_mode);
extern int symbol_ref_operand (rtx, machine_mode);
extern int text_segment_operand (rtx, machine_mode);
extern int single_one_operand (rtx, machine_mode);
extern int single_zero_operand (rtx, machine_mode);
extern int avr_sp_immediate_operand (rtx, machine_mode);
extern int eqne_operator (rtx, machine_mode);
extern int gelt_operator (rtx, machine_mode);
extern int difficult_comparison_operator (rtx, machine_mode);
extern int simple_comparison_operator (rtx, machine_mode);
extern int extend_operator (rtx, machine_mode);
extern int call_insn_operand (rtx, machine_mode);
extern int pseudo_register_operand (rtx, machine_mode);
extern int pseudo_register_or_const_int_operand (rtx, machine_mode);
extern int combine_pseudo_register_operand (rtx, machine_mode);
extern int const_8_16_24_operand (rtx, machine_mode);
extern int u8_operand (rtx, machine_mode);
extern int s8_operand (rtx, machine_mode);
extern int o8_operand (rtx, machine_mode);
extern int s9_operand (rtx, machine_mode);
extern int register_or_s9_operand (rtx, machine_mode);
extern int u16_operand (rtx, machine_mode);
extern int s16_operand (rtx, machine_mode);
extern int o16_operand (rtx, machine_mode);
extern int const_operand (rtx, machine_mode);
extern int nonmemory_or_const_operand (rtx, machine_mode);
extern int const_or_immediate_operand (rtx, machine_mode);
#endif /* HAVE_MACHINE_MODES */

#define CONSTRAINT_NUM_DEFINED_P 1
enum constraint_num
{
  CONSTRAINT__UNKNOWN = 0,
  CONSTRAINT_r,
  CONSTRAINT_t,
  CONSTRAINT_b,
  CONSTRAINT_e,
  CONSTRAINT_w,
  CONSTRAINT_d,
  CONSTRAINT_l,
  CONSTRAINT_a,
  CONSTRAINT_x,
  CONSTRAINT_y,
  CONSTRAINT_z,
  CONSTRAINT_q,
  CONSTRAINT_I,
  CONSTRAINT_J,
  CONSTRAINT_K,
  CONSTRAINT_L,
  CONSTRAINT_M,
  CONSTRAINT_N,
  CONSTRAINT_O,
  CONSTRAINT_P,
  CONSTRAINT_m,
  CONSTRAINT_o,
  CONSTRAINT_Q,
  CONSTRAINT_p,
  CONSTRAINT_G,
  CONSTRAINT_Cm2,
  CONSTRAINT_C03,
  CONSTRAINT_C04,
  CONSTRAINT_C05,
  CONSTRAINT_C06,
  CONSTRAINT_C07,
  CONSTRAINT_Ca1,
  CONSTRAINT_Ca2,
  CONSTRAINT_Ca3,
  CONSTRAINT_Ca4,
  CONSTRAINT_Co1,
  CONSTRAINT_Co2,
  CONSTRAINT_Co3,
  CONSTRAINT_Co4,
  CONSTRAINT_Cx2,
  CONSTRAINT_Cx3,
  CONSTRAINT_Cx4,
  CONSTRAINT_Csp,
  CONSTRAINT_Cxf,
  CONSTRAINT_C0f,
  CONSTRAINT_Cn8,
  CONSTRAINT_Ynn,
  CONSTRAINT_Y00,
  CONSTRAINT_Yx2,
  CONSTRAINT_YIJ,
  CONSTRAINT_V,
  CONSTRAINT__l,
  CONSTRAINT__g,
  CONSTRAINT_i,
  CONSTRAINT_s,
  CONSTRAINT_n,
  CONSTRAINT_E,
  CONSTRAINT_F,
  CONSTRAINT_X,
  CONSTRAINT_Y01,
  CONSTRAINT_Ym1,
  CONSTRAINT_Y02,
  CONSTRAINT_Ym2,
  CONSTRAINT__LIMIT
};

extern enum constraint_num lookup_constraint_1 (const char *);
extern const unsigned char lookup_constraint_array[];

/* Return the constraint at the beginning of P, or CONSTRAINT__UNKNOWN if it
   isn't recognized.  */

static inline enum constraint_num
lookup_constraint (const char *p)
{
  unsigned int index = lookup_constraint_array[(unsigned char) *p];
  return (index == UCHAR_MAX
          ? lookup_constraint_1 (p)
          : (enum constraint_num) index);
}

extern bool (*constraint_satisfied_p_array[]) (rtx);

/* Return true if X satisfies constraint C.  */

static inline bool
constraint_satisfied_p (rtx x, enum constraint_num c)
{
  int i = (int) c - (int) CONSTRAINT_I;
  return i >= 0 && constraint_satisfied_p_array[i] (x);
}

static inline bool
insn_extra_register_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_r && c <= CONSTRAINT_q;
}

static inline bool
insn_extra_memory_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_m && c <= CONSTRAINT_Q;
}

static inline bool
insn_extra_special_memory_constraint (enum constraint_num)
{
  return false;
}

static inline bool
insn_extra_address_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_p && c <= CONSTRAINT_p;
}

static inline void
insn_extra_constraint_allows_reg_mem (enum constraint_num c,
				      bool *allows_reg, bool *allows_mem)
{
  if (c >= CONSTRAINT_G && c <= CONSTRAINT_YIJ)
    return;
  if (c >= CONSTRAINT_V && c <= CONSTRAINT__g)
    {
      *allows_mem = true;
      return;
    }
  (void) c;
  *allows_reg = true;
  *allows_mem = true;
}

static inline size_t
insn_constraint_len (char fc, const char *str ATTRIBUTE_UNUSED)
{
  switch (fc)
    {
    case 'C': return 3;
    case 'Y': return 3;
    default: break;
    }
  return 1;
}

#define CONSTRAINT_LEN(c_,s_) insn_constraint_len (c_,s_)

extern enum reg_class reg_class_for_constraint_1 (enum constraint_num);

static inline enum reg_class
reg_class_for_constraint (enum constraint_num c)
{
  if (insn_extra_register_constraint (c))
    return reg_class_for_constraint_1 (c);
  return NO_REGS;
}

extern bool insn_const_int_ok_for_constraint (HOST_WIDE_INT, enum constraint_num);
#define CONST_OK_FOR_CONSTRAINT_P(v_,c_,s_) \
    insn_const_int_ok_for_constraint (v_, lookup_constraint (s_))

enum constraint_type
{
  CT_REGISTER,
  CT_CONST_INT,
  CT_MEMORY,
  CT_SPECIAL_MEMORY,
  CT_ADDRESS,
  CT_FIXED_FORM
};

static inline enum constraint_type
get_constraint_type (enum constraint_num c)
{
  if (c >= CONSTRAINT_p)
    {
      if (c >= CONSTRAINT_G)
        return CT_FIXED_FORM;
      return CT_ADDRESS;
    }
  if (c >= CONSTRAINT_m)
    return CT_MEMORY;
  if (c >= CONSTRAINT_I)
    return CT_CONST_INT;
  return CT_REGISTER;
}
#endif /* tm-preds.h */
