
MEMORY
{
PAGE 0 :
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */

   BEGIN           	: origin = 0x000000, length = 0x000002
   RAMM0           	: origin = 0x000122, length = 0x0002DE
   RAMD0           	: origin = 0x00B000, length = 0x000800
   RAMLS0          	: origin = 0x008000, length = 0x000800
   RAMLS1          	: origin = 0x008800, length = 0x000800
   RAMLS2      		: origin = 0x009000, length = 0x000800
   RAMLS3      		: origin = 0x009800, length = 0x000800
   RAMLS4      		: origin = 0x00A000, length = 0x000800
   RAMGS14          : origin = 0x01A000, length = 0x001000
   RAMGS15          : origin = 0x01B000, length = 0x001000
   RESET           	: origin = 0x3FFFC0, length = 0x000002

PAGE 1 :

   BOOT_RSVD       : origin = 0x000002, length = 0x000120     /* Part of M0, BOOT rom will use this for stack */
   RAMM1           : origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
   RAMD1           : origin = 0x00B800, length = 0x000800


   RAMLS5      : origin = 0x00A800, length = 0x000800
   
   RAMGS0      : origin = 0x00C000, length = 0x001000
   RAMGS1      : origin = 0x00D000, length = 0x001000
   RAMGS2      : origin = 0x00E000, length = 0x001000
   RAMGS3      : origin = 0x00F000, length = 0x001000
   RAMGS4      : origin = 0x010000, length = 0x001000
   RAMGS5      : origin = 0x011000, length = 0x001000
   RAMGS6      : origin = 0x012000, length = 0x001000
   RAMGS7      : origin = 0x013000, length = 0x001000
   RAMGS8      : origin = 0x014000, length = 0x001000
   RAMGS9      : origin = 0x015000, length = 0x001000
   RAMGS10     : origin = 0x016000, length = 0x001000
   RAMGS11     : origin = 0x017000, length = 0x001000
   RAMGS12     : origin = 0x018000, length = 0x001000
   RAMGS13     : origin = 0x019000, length = 0x001000

   CANA_MSG_RAM     : origin = 0x049000, length = 0x000800 
   CANB_MSG_RAM     : origin = 0x04B000, length = 0x000800
}


SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
   ramfuncs         : > RAMM0      PAGE = 0
   .text            : >>RAMD0 |  RAMLS0 | RAMLS1 | RAMLS2 | RAMLS3 | RAMLS4,   PAGE = 0
   .cinit           : > RAMM0,     PAGE = 0
   .pinit           : > RAMM0,     PAGE = 0
   .switch          : > RAMM0,     PAGE = 0
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */

   .stack           : > RAMM1,     PAGE = 1
   .ebss            : > RAMLS5,     PAGE = 1
   .econst          : > RAMLS5,     PAGE = 1
   .esysmem         : > RAMLS5,     PAGE = 1
   Filter_RegsFile  : > RAMGS0,	   PAGE = 1
   
   SHARERAMGS0		: > RAMGS0,		PAGE = 1
   SHARERAMGS1		: > RAMGS1,		PAGE = 1
   SHARERAMGS2		: > RAMGS2,		PAGE = 1
   SHARERAMGS3		: > RAMGS3,		PAGE = 1
   SHARERAMGS4		: > RAMGS4,		PAGE = 1
   SHARERAMGS5		: > RAMGS5,		PAGE = 1
   SHARERAMGS6		: > RAMGS6,		PAGE = 1
   SHARERAMGS7		: > RAMGS7,		PAGE = 1
   SHARERAMGS8		: > RAMGS8,		PAGE = 1
   SHARERAMGS9		: > RAMGS9,		PAGE = 1
   SHARERAMGS10		: > RAMGS10,	PAGE = 1
   SHARERAMGS11		: > RAMGS11,	PAGE = 1
   SHARERAMGS12		: > RAMGS12,	PAGE = 1
   SHARERAMGS13		: > RAMGS13,	PAGE = 1
   SHARERAMGS14		: > RAMGS14,	PAGE = 0
   SHARERAMGS15		: > RAMGS15,	PAGE = 0
   
#ifdef __TI_COMPILER_VERSION
   #if __TI_COMPILER_VERSION >= 15009000
    .TI.ramfunc : {} > RAMM0,      PAGE = 0
   #endif
#endif
   
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
