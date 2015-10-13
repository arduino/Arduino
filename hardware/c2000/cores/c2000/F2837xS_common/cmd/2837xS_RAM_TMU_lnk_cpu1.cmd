
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
   RAMLS5           : origin = 0x00A800, length = 0x000800
   RAMGS0           : origin = 0x00C000, length = 0x001000
   RESET           	: origin = 0x3FFFC0, length = 0x000002

PAGE 1 :

   BOOT_RSVD        : origin = 0x000002, length = 0x000120     /* Part of M0, BOOT rom will use this for stack */
   RAMM1            : origin = 0x000400, length = 0x000400     /* on-chip RAM block M1 */
   RAMD1            : origin = 0x00B800, length = 0x000800
                    
                    
   RAMGS1           : origin = 0x00D000, length = 0x001000
   RAMGS2_GS4       : origin = 0x00E000, length = 0x003000
   /*
   RAMGS2           : origin = 0x00E000, length = 0x001000
   RAMGS3           : origin = 0x00F000, length = 0x001000
   RAMGS4           : origin = 0x010000, length = 0x001000
   */
   RAMGS5           : origin = 0x011000, length = 0x001000
   RAMGS6           : origin = 0x012000, length = 0x001000
   RAMGS7           : origin = 0x013000, length = 0x001000
   RAMGS8           : origin = 0x014000, length = 0x001000
   RAMGS9           : origin = 0x015000, length = 0x001000
   RAMGS10          : origin = 0x016000, length = 0x001000
   RAMGS11          : origin = 0x017000, length = 0x001000
   RAMGS12          : origin = 0x018000, length = 0x001000
   RAMGS13          : origin = 0x019000, length = 0x001000
   RAMGS14          : origin = 0x01A000, length = 0x001000
   RAMGS15          : origin = 0x01B000, length = 0x001000

   CANA_MSG_RAM     : origin = 0x049000, length = 0x000800 
   CANB_MSG_RAM     : origin = 0x04B000, length = 0x000800
   
   CPU2TOCPU1RAM    : origin = 0x03F800, length = 0x000400
   CPU1TOCPU2RAM    : origin = 0x03FC00, length = 0x000400
}


SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
   ramfuncs         : > RAMM0      PAGE = 0
   .text            :>> RAMM0 | RAMD0 |  RAMLS0 | RAMLS1 | RAMLS2 | RAMLS3 | RAMLS4 | RAMLS5 | RAMGS0,   PAGE = 0
   .cinit           : > RAMM0,     PAGE = 0
   .pinit           : > RAMM0,     PAGE = 0
   .switch          : > RAMM0,     PAGE = 0
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */

   .stack           : > RAMGS1,    PAGE = 1
   .ebss            : > RAMGS2_GS4,PAGE = 1
   .econst          : > RAMGS1,    PAGE = 1
   .esysmem         : > RAMGS1,    PAGE = 1
   Filter_RegsFile  : > RAMGS1,	   PAGE = 1
                      
   .sysmem          : > RAMGS1,    PAGE = 1                      
   .cio             : > RAMGS1,    PAGE = 1

#ifdef __TI_COMPILER_VERSION
   #if __TI_COMPILER_VERSION >= 15009000
    .TI.ramfunc : {} > RAMM0,      PAGE = 0
   #endif
#endif
   
   /* The following section definitions are required when using the IPC API Drivers */ 
    GROUP : > CPU1TOCPU2RAM, PAGE = 1 
    {
        PUTBUFFER 
        PUTWRITEIDX 
        GETREADIDX 
    }
    
    GROUP : > CPU2TOCPU1RAM, PAGE = 1
    {
        GETBUFFER :    TYPE = DSECT
        GETWRITEIDX :  TYPE = DSECT
        PUTREADIDX :   TYPE = DSECT
    }  
    
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
