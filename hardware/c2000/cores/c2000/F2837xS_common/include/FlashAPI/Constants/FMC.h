/*--------------------------------------------------------*/
/* F021\Constants\FMC.h                                   */
/*                                                        */
/* Copyright (c) 2009-2011 Texas Instruments Incorporated */
/*                                                        */
/* F021 Flash API v1.00                                   */
/*--------------------------------------------------------*/

/*!
    \file F021\Constants\FMC.h
    \brief A set of Constant Values for the FMC Family.
*/
#ifndef F021_CONSTANTS_FMC_H_
#define F021_CONSTANTS_FMC_H_

/*!
    \brief Specifies the bit mask for determining all address bits exclusive of
    the offest imposed by the memory map register
*/
#define F021_PROGRAM_ADDRESS_MASK    0x07FFFFFFU

/*!
    \brief Specifies the Offset to the TI OTP
*/
#define F021_PROGRAM_TIOTP_OFFSET    0xF0080000


/*!
    \brief PGM_OSU Max Value
*/
#define F021_PGM_OSU_MAX    0xFFU

/*!
    \brief PGM_OSU Min Value
*/
#define F021_PGM_OSU_MIN    0x02U

/*!
    \brief ERA_OSU Max Value
*/
#define F021_ERA_OSU_MAX    0xFFU

/*!
    \brief ERA_OSU Min Value
*/
#define F021_ERA_OSU_MIN    0x02U

/*!
    \brief ADD_EXZ Max Value
*/
#define F021_ADD_EXZ_MAX    0x0FU

/*!
    \brief ADD_EXZ Min Value
*/
#define F021_ADD_EXZ_MIN    0x02U

/*!
    \brief EXE_VALD Max Value
*/
#define F021_EXE_VALD_MAX    0x0FU

/*!
    \brief EXE_VALD Min Value
*/
#define F021_EXE_VALD_MIN    0x02U

/*!
    \brief PROG_PUL_WIDTH Max Value
*/
#define F021_PROG_PUL_WIDTH_MAX    0xFFFFU

/*!
    \brief PROG_PUL_WIDTH Min Value
*/
#define F021_PROG_PUL_WIDTH_MIN    0x0002U

/*!
    \brief ERA_PUL_WIDTH Max Value
*/
#define F021_ERA_PUL_WIDTH_MAX    0xFFFFFFFFU

/*!
    \brief ERA_PUL_WIDTH Min Value
*/
#define F021_ERA_PUL_WIDTH_MIN    0x00000002U

/*!
 *  FMC memory map defines
 */
#define F021_FLASH_MAP_BEGIN     0x00000000
#define F021_FLASH_MAP_END       0x00FFFFFF
#define F021_OTP_MAP_BEGIN       0xF0000000
#define F021_OTP_MAP_END         0xF000FFFF
#define F021_OTPECC_MAP_BEGIN    0xF0040000
#define F021_OTPECC_MAP_END      0xF0041FFF
#define F021_EEPROMECC_MAP_BEGIN 0xF0100000
#define F021_EEPROMECC_MAP_END   0xF01FFFFF
#define F021_EEPROM_MAP_BEGIN    0xF0200000
#define F021_EEPROM_MAP_END      0xF03FFFFF
#define F021_FLASHECC_MAP_BEGIN  0xF0400000
#define F021_FLASHECC_MAP_END    0xF04FFFFF

/*!
    \brief Define to map the direct access to the FMC registers.
*/
#define F021_CPU0_REGISTER_ADDRESS 0xFFF87000

/*!
 *  Specific TI OTP Offsets
 */
#define F021_TIOTP_PER_BANK_SIZE 0x2000U
#define F021_TIOTP_SETTINGS_BASE 0x150U
#define F021_TIOTP_BANK_SECTOR_OFFSET 0x158U

#endif /* F021_CONSTANTS_FMC_H_ */
