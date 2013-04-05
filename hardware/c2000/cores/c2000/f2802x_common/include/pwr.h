#ifndef _PWR_H_
#define _PWR_H_

//#############################################################################
//
//! \file   f2802x_common/include/pwr.h
//!
//! \brief  Contains public interface to various functions related
//!         to the power (PWR) object 
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include "f2802x_common/include/cpu.h"


//!
//! \defgroup PWR

//!
//! \ingroup PWR
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the power (PWR) registers
//!
#define PWR_BASE_ADDR              (0x00000985)


//! \brief Defines the location of the BORENZ bits in the BORCFG register
//!
#define PWR_BORCFG_BORENZ_BITS     (1 << 0)


//! \brief Defines the location of the LPM bits in the LPMCR0 register
//!
#define PWR_LPMCR0_LPM_BITS        (3 << 0)

//! \brief Defines the location of the QUALSTDBY bits in the LPMCR0 register
//!
#define PWR_LPMCR0_QUALSTDBY_BITS  (63 << 2)

//! \brief Defines the location of the WDINTE bits in the LPMCR0 register
//!
#define PWR_LPMCR0_WDINTE_BITS     (1 << 15)


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the power (PWR) low power modes
//!
typedef enum
{
    PWR_LowPowerMode_Idle=0,    //!< Denotes the idle mode
    PWR_LowPowerMode_Standby,   //!< Denotes the standby mode
    PWR_LowPowerMode_Halt       //!< Denotes the halt mode
} PWR_LowPowerMode_e;


//! \brief Enumeration to define the power (PWR) number of standby clock cycles
//!
typedef enum
{
    PWR_NumStandByClocks_2=(0 << 2),    //!< Denotes 2 standby clock cycles
    PWR_NumStandByClocks_3=(1 << 2),    //!< Denotes 3 standby clock cycles
    PWR_NumStandByClocks_4=(2 << 2),    //!< Denotes 4 standby clock cycles
    PWR_NumStandByClocks_5=(3 << 2),    //!< Denotes 5 standby clock cycles
    PWR_NumStandByClocks_6=(4 << 2),    //!< Denotes 6 standby clock cycles
    PWR_NumStandByClocks_7=(5 << 2),    //!< Denotes 7 standby clock cycles
    PWR_NumStandByClocks_8=(6 << 2),    //!< Denotes 8 standby clock cycles
    PWR_NumStandByClocks_9=(7 << 2),    //!< Denotes 9 standby clock cycles
    PWR_NumStandByClocks_10=(8 << 2),   //!< Denotes 10 standby clock cycles
    PWR_NumStandByClocks_11=(9 << 2),   //!< Denotes 11 standby clock cycles
    PWR_NumStandByClocks_12=(10 << 2),  //!< Denotes 12 standby clock cycles
    PWR_NumStandByClocks_13=(11 << 2),  //!< Denotes 13 standby clock cycles
    PWR_NumStandByClocks_14=(12 << 2),  //!< Denotes 14 standby clock cycles
    PWR_NumStandByClocks_15=(13 << 2),  //!< Denotes 15 standby clock cycles
    PWR_NumStandByClocks_16=(14 << 2),  //!< Denotes 16 standby clock cycles
    PWR_NumStandByClocks_17=(15 << 2),  //!< Denotes 17 standby clock cycles
    PWR_NumStandByClocks_18=(16 << 2),  //!< Denotes 18 standby clock cycles
    PWR_NumStandByClocks_19=(17 << 2),  //!< Denotes 19 standby clock cycles
    PWR_NumStandByClocks_20=(18 << 2),  //!< Denotes 20 standby clock cycles
    PWR_NumStandByClocks_21=(19 << 2),  //!< Denotes 21 standby clock cycles
    PWR_NumStandByClocks_22=(20 << 2),  //!< Denotes 22 standby clock cycles
    PWR_NumStandByClocks_23=(21 << 2),  //!< Denotes 23 standby clock cycles
    PWR_NumStandByClocks_24=(22 << 2),  //!< Denotes 24 standby clock cycles
    PWR_NumStandByClocks_25=(23 << 2),  //!< Denotes 25 standby clock cycles
    PWR_NumStandByClocks_26=(24 << 2),  //!< Denotes 26 standby clock cycles
    PWR_NumStandByClocks_27=(25 << 2),  //!< Denotes 27 standby clock cycles
    PWR_NumStandByClocks_28=(26 << 2),  //!< Denotes 28 standby clock cycles
    PWR_NumStandByClocks_29=(27 << 2),  //!< Denotes 29 standby clock cycles
    PWR_NumStandByClocks_30=(28 << 2),  //!< Denotes 30 standby clock cycles
    PWR_NumStandByClocks_31=(29 << 2),  //!< Denotes 31 standby clock cycles
    PWR_NumStandByClocks_32=(30 << 2),  //!< Denotes 32 standby clock cycles
    PWR_NumStandByClocks_33=(31 << 2),  //!< Denotes 33 standby clock cycles
    PWR_NumStandByClocks_34=(32 << 2),  //!< Denotes 34 standby clock cycles
    PWR_NumStandByClocks_35=(33 << 2),  //!< Denotes 35 standby clock cycles
    PWR_NumStandByClocks_36=(34 << 2),  //!< Denotes 36 standby clock cycles
    PWR_NumStandByClocks_37=(35 << 2),  //!< Denotes 37 standby clock cycles
    PWR_NumStandByClocks_38=(36 << 2),  //!< Denotes 38 standby clock cycles
    PWR_NumStandByClocks_39=(37 << 2),  //!< Denotes 39 standby clock cycles
    PWR_NumStandByClocks_40=(38 << 2),  //!< Denotes 40 standby clock cycles
    PWR_NumStandByClocks_41=(39 << 2),  //!< Denotes 41 standby clock cycles
    PWR_NumStandByClocks_42=(40 << 2),  //!< Denotes 42 standby clock cycles
    PWR_NumStandByClocks_43=(41 << 2),  //!< Denotes 43 standby clock cycles
    PWR_NumStandByClocks_44=(42 << 2),  //!< Denotes 44 standby clock cycles
    PWR_NumStandByClocks_45=(43 << 2),  //!< Denotes 45 standby clock cycles
    PWR_NumStandByClocks_46=(44 << 2),  //!< Denotes 46 standby clock cycles
    PWR_NumStandByClocks_47=(45 << 2),  //!< Denotes 47 standby clock cycles
    PWR_NumStandByClocks_48=(46 << 2),  //!< Denotes 48 standby clock cycles
    PWR_NumStandByClocks_49=(47 << 2),  //!< Denotes 49 standby clock cycles
    PWR_NumStandByClocks_50=(48 << 2),  //!< Denotes 50 standby clock cycles
    PWR_NumStandByClocks_51=(49 << 2),  //!< Denotes 51 standby clock cycles
    PWR_NumStandByClocks_52=(50 << 2),  //!< Denotes 52 standby clock cycles
    PWR_NumStandByClocks_53=(51 << 2),  //!< Denotes 53 standby clock cycles
    PWR_NumStandByClocks_54=(52 << 2),  //!< Denotes 54 standby clock cycles
    PWR_NumStandByClocks_55=(53 << 2),  //!< Denotes 55 standby clock cycles
    PWR_NumStandByClocks_56=(54 << 2),  //!< Denotes 56 standby clock cycles
    PWR_NumStandByClocks_57=(55 << 2),  //!< Denotes 57 standby clock cycles
    PWR_NumStandByClocks_58=(56 << 2),  //!< Denotes 58 standby clock cycles
    PWR_NumStandByClocks_59=(57 << 2),  //!< Denotes 59 standby clock cycles
    PWR_NumStandByClocks_60=(58 << 2),  //!< Denotes 60 standby clock cycles
    PWR_NumStandByClocks_61=(59 << 2),  //!< Denotes 61 standby clock cycles
    PWR_NumStandByClocks_62=(60 << 2),  //!< Denotes 62 standby clock cycles
    PWR_NumStandByClocks_63=(61 << 2),  //!< Denotes 63 standby clock cycles
    PWR_NumStandByClocks_64=(62 << 2),  //!< Denotes 64 standby clock cycles
    PWR_NumStandByClocks_65=(63 << 2)   //!< Denotes 65 standby clock cycles
} PWR_NumStandByClocks_e;


//! \brief Defines the power (PWR) object
//!
typedef struct _PWR_Obj_
{
    volatile uint16_t   BORCFG;          //!< BOR (Brown Out Reset) Configuration Register
    volatile uint16_t   rsvd_1[26264];   //<! Reserved
    volatile uint16_t   LPMCR0;          //<! Low Power Mode Control Register 0
} PWR_Obj;


//! \brief Defines the power (PWR) handle
//!
typedef struct PWR_Obj *PWR_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


//! \brief     Disables the brownout reset functions
//! \param[in] pwrHandle     The power (PWR) object handle
void PWR_disableBrownOutReset(PWR_Handle pwrHandle);


//! \brief     Disables the watchdog interrupt
//! \param[in] pwrHandle     The power (PWR) object handle
void PWR_disableWatchDogInt(PWR_Handle pwrHandle);


//! \brief     Enables the brownout reset functions
//! \param[in] pwrHandle     The power (PWR) object handle
void PWR_enableBrownOutReset(PWR_Handle pwrHandle);


//! \brief     Enables the watchdog interrupt
//! \param[in] pwrHandle     The power (PWR) object handle
void PWR_enableWatchDogInt(PWR_Handle pwrHandle);


//! \brief     Initializes the power (PWR) object handle
//! \param[in] pMemory     A pointer to the base address of the PWR registers
//! \param[in] numBytes    The number of bytes allocated for the PWR object, bytes
//! \return    The power (PWR) object handle
PWR_Handle PWR_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the low power mode
//! \param[in] pwrHandle     The power (PWR) object handle
//! \param[in] lowPowerMode  The low power mode
void PWR_setLowPowerMode(PWR_Handle pwrHandle,const PWR_LowPowerMode_e lowPowerMode);


//! \brief     Sets the number of standby clock cycles
//! \param[in] pwrHandle     The power (PWR) object handle
//! \param[in] numClkCycles  The number of standby clock cycles
void PWR_setNumStandByClocks(PWR_Handle pwrHandle,const PWR_NumStandByClocks_e numClkCycles);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _PWR_H_ definition

