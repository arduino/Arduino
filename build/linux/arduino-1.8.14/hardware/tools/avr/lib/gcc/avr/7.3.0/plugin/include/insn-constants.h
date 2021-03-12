/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define LPM_REGNO 0
#define ZERO_REGNO 1
#define TMP_REGNO 0
#define TMP_REGNO_TINY 16
#define REG_W 24
#define REG_X 26
#define REG_Y 28
#define REG_Z 30
#define ZERO_REGNO_TINY 17
#define ACC_A 18
#define REG_SP 32
#define ACC_B 10

enum unspec {
  UNSPEC_STRLEN = 0,
  UNSPEC_MOVMEM = 1,
  UNSPEC_INDEX_JMP = 2,
  UNSPEC_FMUL = 3,
  UNSPEC_FMULS = 4,
  UNSPEC_FMULSU = 5,
  UNSPEC_COPYSIGN = 6,
  UNSPEC_IDENTITY = 7,
  UNSPEC_INSERT_BITS = 8,
  UNSPEC_ROUND = 9
};
#define NUM_UNSPEC_VALUES 10
extern const char *const unspec_strings[];

enum unspecv {
  UNSPECV_PROLOGUE_SAVES = 0,
  UNSPECV_EPILOGUE_RESTORES = 1,
  UNSPECV_WRITE_SP = 2,
  UNSPECV_GOTO_RECEIVER = 3,
  UNSPECV_ENABLE_IRQS = 4,
  UNSPECV_MEMORY_BARRIER = 5,
  UNSPECV_NOP = 6,
  UNSPECV_SLEEP = 7,
  UNSPECV_WDR = 8,
  UNSPECV_DELAY_CYCLES = 9
};
#define NUM_UNSPECV_VALUES 10
extern const char *const unspecv_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
