
/* this linker command file is to be included if user wants to use the DCSM feature on the device
 * DCSM  means Dual Zone Code Security Module.
 * This linker command file works as an addendum ot the already existing Flash/RAM linker command file
 * that the project has.
 * The sections in the *_ZoneSelectBlock.asm source file is linked as per the commands given in the file
 * NOTE - please note fill=0xFFFF, this helps if users include this file in the project by mistake and 
 * doesn't provide the needed proper *_ZoneSelectBlock.asm sources . 
 * Please refer to the Blinky DCSM example in the controlsuite examples for proper usage of this.
 * 
 * Once users are confident that they want to program the passwords in OTP, the sDSECT section type can be removed.
 * 
*/ 

MEMORY
{
PAGE 0 :  /* Program Memory */
 
   /* Part of Z1 OTP.  LinkPointers/PSWD LOCK/CRC LOCK/JTAG lock/ Boot Ctrl */
   DCSM_OTP_Z1_P0	: origin = 0x78000, length = 0x000020		
   /* Part of Z2 OTP.  LinkPointers/PSWD LOCK/CRC LOCK/JTAG lock/ Boot Ctrl */
   DCSM_OTP_Z2_P0	: origin = 0x78200, length = 0x000020		
   
   /* DCSM Z1 Zone Select Contents (!!Movable!!) */
   /* Part of Z1 OTP.  Z1 password locations / Flash and RAM partitioning */
   DCSM_ZSEL_Z1_P0	: origin = 0x78020, length = 0x000010	
   
   /* DCSM Z1 Zone Select Contents (!!Movable!!) */
   /* Part of Z2 OTP.  Z2 password locations / Flash and RAM partitioning  */
   DCSM_ZSEL_Z2_P0	: origin = 0x78220, length = 0x000010		
}


SECTIONS
{
   dcsm_otp_z1		: > DCSM_OTP_Z1_P0,		PAGE = 0, type = DSECT
   dcsm_otp_z2		: > DCSM_OTP_Z2_P0,		PAGE = 0, type = DSECT 
   
   dcsm_zsel_z1		: > DCSM_ZSEL_Z1_P0,	PAGE = 0, type = DSECT
   dcsm_zsel_z2		: > DCSM_ZSEL_Z2_P0,	PAGE = 0, type = DSECT
		 
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
