/*--------------------------------------------------------*/
/* F021\Constants\F2837xD.h                                */
/*                                                        */
/* Copyright (c) 2010-2013 Texas Instruments Incorporated */
/*                                                        */
/*--------------------------------------------------------*/

/*!
    \file F021\Constants\F2837xD.h
    \brief A set of Constant Values for the F2837xD Family.
*/
#ifndef F021_CONSTANTS_F2837xD_H_
#define F021_CONSTANTS_F2837xD_H_

/*!
    \brief Specifies the bit mask for determining all address bits exclusive of
    the offest imposed by the memory map register
*/
#define F021_PROGRAM_ADDRESS_MASK    0x07FFFFFF

/*!
    \brief Specifies the Offset to the TI OTP
*/

	#define F021_PROGRAM_TIOTP_OFFSET    0x00070000 //TI OTP start on C28x



/* Final values to be determined */

/*!
    \brief Maximum FClck Value
*/
#define F021_FCLK_MAX    0x18


/*!
    \brief PGM_OSU Max Value
*/
#define F021_PGM_OSU_MAX    0xFF

/*!
    \brief PGM_OSU Min Value
*/
#define F021_PGM_OSU_MIN    0x02

/*!
    \brief ERA_OSU Max Value
*/
#define F021_ERA_OSU_MAX    0xFF

/*!
    \brief ERA_OSU Min Value
*/
#define F021_ERA_OSU_MIN    0x02

/*!
    \brief ADD_EXZ Max Value
*/
#define F021_ADD_EXZ_MAX    0x0F

/*!
    \brief ADD_EXZ Min Value
*/
#define F021_ADD_EXZ_MIN    0x02

/*!
    \brief EXE_VALD Max Value
*/
#define F021_EXE_VALD_MAX    0x0F

/*!
    \brief EXE_VALD Min Value
*/
#define F021_EXE_VALD_MIN    0x02

/*!
    \brief PROG_PUL_WIDTH Max Value
*/
#define F021_PROG_PUL_WIDTH_MAX    0xFFFF

/*!
    \brief PROG_PUL_WIDTH Min Value
*/
#define F021_PROG_PUL_WIDTH_MIN    0x0002

/*!
    \brief ERA_PUL_WIDTH Max Value
*/
#define F021_ERA_PUL_WIDTH_MAX    0xFFFFFFFF

/*!
    \brief ERA_PUL_WIDTH Min Value
*/
#define F021_ERA_PUL_WIDTH_MIN    0x00000002

/*!
 *  FMC memory map defines
 */
 #if defined (_F2837xD)
	#define F021_FLASH_MAP_BEGIN      0x80000      
	#define F021_FLASH_MAP_END        0xBFFFF 
	#define F021_OTP_MAP_BEGIN        0x78000//Customer OTP start
	#define F021_OTP_MAP_END          0x783FF//Customer OTP End
	#define F021_OTPECC_MAP_BEGIN     0x1071000 
	#define F021_OTPECC_MAP_END       0x107107F
	#define F021_FLASHECC_MAP_BEGIN   0x1080000
	#define F021_FLASHECC_MAP_END     0x1087FFF
	#define F021_EEPROM_MAP_BEGIN     0xFFFFFFFF 
	#define F021_EEPROM_MAP_END       0xFFFFFFFF 
	#define F021_EEPROMECC_MAP_BEGIN  0xFFFFFFFF 
	#define F021_EEPROMECC_MAP_END    0xFFFFFFFF 
#endif

/*!
    \brief Define to map the direct access to the FMC registers.
*/

	#define F021_CPU0_REGISTER_ADDRESS 0x0005F800

/*!
 *  Specific TI OTP Offsets
 */

	#define F021_TIOTP_PER_BANK_SIZE 0x800 //Even though TI OTP is 2K, Size is mentioned here as 0x800 (4K) because code uses this to find the offset of TI OTP (1, 2) relative to OTP Base address
	#define F021_TIOTP_SETTINGS_BASE 0xA8
	#define F021_TIOTP_BANK_SECTOR_OFFSET 0xAC


#endif /* F021_CONSTANTS_F2837xD_H_ */
