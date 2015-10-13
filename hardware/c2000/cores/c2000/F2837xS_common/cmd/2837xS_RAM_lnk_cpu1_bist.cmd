
MEMORY
{
PAGE 0 :
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */

   BEGIN           : origin = 0x000000, length = 0x000002
   RAMM0           : origin = 0x000002, length = 0x0003FF
   RAMD0           : origin = 0x00B000, length = 0x000800
   RAMLS0          : origin = 0x008000, length = 0x000800
   RAMLS1          : origin = 0x008800, length = 0x000800
   RAMLS2          : origin = 0x009000, length = 0x000800
   RESET           : origin = 0x3FFFC0, length = 0x000002

PAGE 1 :

   BOOT_RSVD       : origin = 0x000002, length = 0x00004E     /* Part of M0, BOOT rom will use this for stack */
   RAMM1           : origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
   RAMD1           : origin = 0x00B800, length = 0x0003FF

   RAMLS3      : origin = 0x009800, length = 0x000800
   RAMLS4      : origin = 0x00A000, length = 0x000800
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
   RAMGS14     : origin = 0x01A000, length = 0x001000
   RAMGS15     : origin = 0x01B000, length = 0x001000
   
   CANA_MSG_RAM     : origin = 0x049000, length = 0x000800 
   CANB_MSG_RAM     : origin = 0x04B000, length = 0x000800   
}


SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
   ramfuncs         : > RAMLS0      PAGE = 0
   .text            : >>RAMLS0 | RAMLS1 | RAMLS2,   PAGE = 0
   .cinit           : > RAMLS1,     PAGE = 0
   .pinit           : > RAMLS1,     PAGE = 0
   .switch          : > RAMLS1,     PAGE = 0
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */
 
   .stack           : > RAMLS3,     PAGE = 1
   .ebss            : > RAMLS3,    PAGE = 1
   .econst          : > RAMLS3,    PAGE = 1
   .esysmem         : > RAMLS3,    PAGE = 1
   Filter_RegsFile  : > RAMLS3,	   PAGE = 1
   
#ifdef __TI_COMPILER_VERSION
   #if __TI_COMPILER_VERSION >= 15009000
    .TI.ramfunc : {} > RAMLS0      PAGE = 0
   #endif
#endif

}



/*
//===========================================================================
// End of file.
//===========================================================================
*/
