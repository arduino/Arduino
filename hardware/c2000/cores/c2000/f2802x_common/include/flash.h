#ifndef _FLASH_H_
#define _FLASH_H_

//#############################################################################
//
//! \file   f2802x_common/include/flash.h
//!
//! \brief  Contains public interface to various functions related
//!         to the flash (FLASH) object 
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
//! \defgroup FLASH

//!
//! \ingroup FLASH
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the flash (FLASH) registers
//!
#define FLASH_BASE_ADDR                     (0x00000A80)


//! \brief Defines the default active wait count in units of SYSCLKOUT cycles
//!
#define FLASH_ACTIVE_WAIT_COUNT_DEFAULT     (0x01FF)


//! \brief Defines the default standby wait count in units of SYSCLKOUT cycles
//!
#define FLASH_STANDBY_WAIT_COUNT_DEFAULT    (0x01FF)


//! \brief Defines the location of the ENPIPE bits in the FOPT register
//!
#define FLASH_FOPT_ENPIPE_BITS              (1 << 0)


//! \brief Defines the location of the ACTIVEWAIT bits in the FACTIVEWAIT register
//!
#define FLASH_FACTIVEWAIT_ACTIVEWAIT_BITS   (255 << 0)


//! \brief Defines the location of the RANDWAIT bits in the FBANKWAIT register
//!
#define FLASH_FBANKWAIT_RANDWAIT_BITS       (15 << 0)

//! \brief Defines the location of the PAGEWAIT bits in the FBANKWAIT register
//!
#define FLASH_FBANKWAIT_PAGEWAIT_BITS       (15 << 8)


//! \brief Defines the location of the OTPWAIT bits in the FOTPWAIT register
//!
#define FLASH_FOTPWAIT_OTPWAIT_BITS         (31 << 0)


//! \brief Defines the location of the PWR bits in the FPWR register
//!
#define FLASH_FPWR_PWR_BITS                 (3 << 0)


//! \brief Defines the location of the PWRS bits in the FSTATUS register
//!
#define FLASH_FSTATUS_PWRS_BITS             (3 << 0)

//! \brief Defines the location of the STDBYWAITS bits in the FSTATUS register
//!
#define FLASH_FSTATUS_STDBYWAITS_BITS       (1 << 2)

//! \brief Defines the location of the ACTIVEWAITS bits in the FSTATUS register
//!
#define FLASH_FSTATUS_ACTIVEWAITS_BITS      (1 << 3)

//! \brief Defines the location of the 3VSTAT bits in the FSTATUS register
//!
#define FLASH_FSTATUS_3VSTAT_BITS           (1 << 8)


//! \brief Defines the location of the STDBYWAIT bits in the FSTDBYWAIT register
//!
#define FLASH_FSTDBYWAIT_STDBYWAIT_BITS     (255 << 0)


// **************************************************************************
// the typedefs


//! \brief Enumeration to define the 3V status
//!
typedef enum
{
    FLASH_3VStatus_InRange=(0 << 8),     //!< Denotes the 3V flash voltage is in range
    FLASH_3VStatus_OutOfRange=(1 << 8)   //!< Denotes the 3V flash voltage went out of range
} FLASH_3VStatus_e;


//! \brief Enumeration to define the counter status
//!
typedef enum
{
    FLASH_CounterStatus_NotCounting=0,   //!< Denotes the flash counter is not counting
    FLASH_CounterStatus_Counting         //!< Denotes the flash counter is counting
} FLASH_CounterStatus_e;


//! \brief Enumeration to define the number of one-time programmable wait states
//!
typedef enum
{
    FLASH_NumOtpWaitStates_1=(1 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 1
    FLASH_NumOtpWaitStates_2=(2 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 2
    FLASH_NumOtpWaitStates_3=(3 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 3
    FLASH_NumOtpWaitStates_4=(4 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 4
    FLASH_NumOtpWaitStates_5=(5 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 5
    FLASH_NumOtpWaitStates_6=(6 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 6
    FLASH_NumOtpWaitStates_7=(7 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 7
    FLASH_NumOtpWaitStates_8=(8 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 8
    FLASH_NumOtpWaitStates_9=(9 << 0),    //!< Denotes the number of one-time programmable (OTP) wait states is 9
    FLASH_NumOtpWaitStates_10=(10 << 0),  //!< Denotes the number of one-time programmable (OTP) wait states is 10
    FLASH_NumOtpWaitStates_11=(11 << 0),  //!< Denotes the number of one-time programmable (OTP) wait states is 11
    FLASH_NumOtpWaitStates_12=(12 << 0),  //!< Denotes the number of one-time programmable (OTP) wait states is 12
    FLASH_NumOtpWaitStates_13=(13 << 0),  //!< Denotes the number of one-time programmable (OTP) wait states is 13
    FLASH_NumOtpWaitStates_14=(14 << 0),  //!< Denotes the number of one-time programmable (OTP) wait states is 14
    FLASH_NumOtpWaitStates_15=(15 << 0)   //!< Denotes the number of one-time programmable (OTP) wait states is 15
} FLASH_NumOtpWaitStates_e;


//! \brief Enumeration to define the number of paged wait states
//!
typedef enum
{
    FLASH_NumPagedWaitStates_0=(0 << 8),     //!< Denotes the number of paged read wait states is 0
    FLASH_NumPagedWaitStates_1=(1 << 8),     //!< Denotes the number of paged read wait states is 1
    FLASH_NumPagedWaitStates_2=(2 << 8),     //!< Denotes the number of paged read wait states is 2
    FLASH_NumPagedWaitStates_3=(3 << 8),     //!< Denotes the number of paged read wait states is 3
    FLASH_NumPagedWaitStates_4=(4 << 8),     //!< Denotes the number of paged read wait states is 4
    FLASH_NumPagedWaitStates_5=(5 << 8),     //!< Denotes the number of paged read wait states is 5
    FLASH_NumPagedWaitStates_6=(6 << 8),     //!< Denotes the number of paged read wait states is 6
    FLASH_NumPagedWaitStates_7=(7 << 8),     //!< Denotes the number of paged read wait states is 7
    FLASH_NumPagedWaitStates_8=(8 << 8),     //!< Denotes the number of paged read wait states is 8
    FLASH_NumPagedWaitStates_9=(9 << 8),     //!< Denotes the number of paged read wait states is 9
    FLASH_NumPagedWaitStates_10=(10 << 8),   //!< Denotes the number of paged read wait states is 10
    FLASH_NumPagedWaitStates_11=(11 << 8),   //!< Denotes the number of paged read wait states is 11
    FLASH_NumPagedWaitStates_12=(12 << 8),   //!< Denotes the number of paged read wait states is 12
    FLASH_NumPagedWaitStates_13=(13 << 8),   //!< Denotes the number of paged read wait states is 13
    FLASH_NumPagedWaitStates_14=(14 << 8),   //!< Denotes the number of paged read wait states is 14
    FLASH_NumPagedWaitStates_15=(15 << 8)    //!< Denotes the number of paged read wait states is 15
} FLASH_NumPagedWaitStates_e;


//! \brief Enumeration to define the number of random wait states
//!
typedef enum
{
    FLASH_NumRandomWaitStates_1=(1 << 0),     //!< Denotes the number of randowm read wait states is 1
    FLASH_NumRandomWaitStates_2=(2 << 0),     //!< Denotes the number of randowm read wait states is 2
    FLASH_NumRandomWaitStates_3=(3 << 0),     //!< Denotes the number of randowm read wait states is 3
    FLASH_NumRandomWaitStates_4=(4 << 0),     //!< Denotes the number of randowm read wait states is 4
    FLASH_NumRandomWaitStates_5=(5 << 0),     //!< Denotes the number of randowm read wait states is 5
    FLASH_NumRandomWaitStates_6=(6 << 0),     //!< Denotes the number of randowm read wait states is 6
    FLASH_NumRandomWaitStates_7=(7 << 0),     //!< Denotes the number of randowm read wait states is 7
    FLASH_NumRandomWaitStates_8=(8 << 0),     //!< Denotes the number of randowm read wait states is 8
    FLASH_NumRandomWaitStates_9=(9 << 0),     //!< Denotes the number of randowm read wait states is 9
    FLASH_NumRandomWaitStates_10=(10 << 0),   //!< Denotes the number of randowm read wait states is 10
    FLASH_NumRandomWaitStates_11=(11 << 0),   //!< Denotes the number of randowm read wait states is 11
    FLASH_NumRandomWaitStates_12=(12 << 0),   //!< Denotes the number of randowm read wait states is 12
    FLASH_NumRandomWaitStates_13=(13 << 0),   //!< Denotes the number of randowm read wait states is 13
    FLASH_NumRandomWaitStates_14=(14 << 0),   //!< Denotes the number of randowm read wait states is 14
    FLASH_NumRandomWaitStates_15=(15 << 0)    //!< Denotes the number of randowm read wait states is 15
} FLASH_NumRandomWaitStates_e;


//! \brief Enumeration to define the power modes
//!
typedef enum
{
    FLASH_PowerMode_PumpAndBankSleep=(0 << 0),    //!< Denotes a pump and bank sleep power mode
    FLASH_PowerMode_PumpAndBankStandby=(1 << 0),  //!< Denotes a pump and bank standby power mode
    FLASH_PowerMode_PumpAndBankActive=(3 << 0)    //!< Denotes a pump and bank active power mode 
} FLASH_PowerMode_e;


//! \brief Defines the flash (FLASH) object
//!
typedef struct _FLASH_Obj_
{
    volatile uint16_t  FOPT;         //!< Flash Option Register
    volatile uint16_t  rsvd_1;       //!< Reserved
    volatile uint16_t  FPWR;         //!< Flash Power Modes Register
    volatile uint16_t  FSTATUS;      //!< Status Register
    volatile uint16_t  FSTDBYWAIT;   //!< Flash Sleep To Standby Wait Register
    volatile uint16_t  FACTIVEWAIT;  //!< Flash Standby to Active Wait Register
    volatile uint16_t  FBANKWAIT;    //!< Flash Read Access Wait State Register
    volatile uint16_t  FOTPWAIT;     //!< OTP Read Access Wait State Register
} FLASH_Obj;


//! \brief Defines the flash (FLASH) handle
//!
typedef struct FLASH_Obj *FLASH_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Clears the 3V status
//! \param[in] flashHandle  The flash (FLASH) object handle
void FLASH_clear3VStatus(FLASH_Handle flashHandle);


//! \brief     Disables the pipeline mode
//! \param[in] flashHandle  The flash (FLASH) object handle
void FLASH_disablePipelineMode(FLASH_Handle flashHandle);


//! \brief     Enables the pipeline mode
//! \param[in] flashHandle  The flash (FLASH) object handle
void FLASH_enablePipelineMode(FLASH_Handle flashHandle);


//! \brief     Gets the 3V status
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \return    The 3V status
FLASH_3VStatus_e FLASH_get3VStatus(FLASH_Handle flashHandle);


//! \brief     Gets the active wait count
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \return    The active wait count
uint16_t FLASH_getActiveWaitCount(FLASH_Handle flashHandle);


//! \brief     Gets the active wait counter status
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \return    The active wait counter status
FLASH_CounterStatus_e FLASH_getActiveWaitStatus(FLASH_Handle flashHandle);


//! \brief     Gets the power mode
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \return    The power mode
FLASH_PowerMode_e FLASH_getPowerMode(FLASH_Handle flashHandle);


//! \brief     Gets the standby wait count
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \return    The standby wait count
uint16_t FLASH_getStandbyWaitCount(FLASH_Handle flashHandle);


//! \brief     Gets the standby wait counter status
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \return    The standby wait counter status
FLASH_CounterStatus_e FLASH_getStandbyWaitStatus(FLASH_Handle flashHandle);


//! \brief     Initializes the flash (FLASH) handle
//! \param[in] pMemory     A pointer to the base address of the FLASH registers
//! \param[in] numBytes    The number of bytes allocated for the FLASH object, bytes
//! \return    The flash (FLASH) object handle
FLASH_Handle FLASH_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the active wait count
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \param[in] count        The active wait count
void FLASH_setActiveWaitCount(FLASH_Handle flashHandle,const uint16_t count);


//! \brief     Sets the number of paged read wait states
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \param[in] numStates    The number of paged read wait states
void FLASH_setNumPagedReadWaitStates(FLASH_Handle flashHandle,const FLASH_NumPagedWaitStates_e numStates);


//! \brief     Sets the number of random read wait states
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \param[in] numStates    The number of random read wait states
void FLASH_setNumRandomReadWaitStates(FLASH_Handle flashHandle,const FLASH_NumRandomWaitStates_e numStates);


//! \brief     Sets the number of one-time programmable (OTP) wait states
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \param[in] numStates    The number of one-time programmable (OTP) wait states
void FLASH_setOtpWaitStates(FLASH_Handle flashHandle,const FLASH_NumOtpWaitStates_e numStates);


//! \brief     Sets the power mode
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \param[in] mode         The power mode
void FLASH_setPowerMode(FLASH_Handle flashHandle,const FLASH_PowerMode_e mode);


//! \brief     Sets the standby wait count
//! \param[in] flashHandle  The flash (FLASH) object handle
//! \param[in] count        The standby wait count
void FLASH_setStandbyWaitCount(FLASH_Handle flashHandle,const uint16_t count);

//! \brief     Setup flash for optimal performance
//! \param[in] flashHandle  The flash (FLASH) object handle
void FLASH_setup(FLASH_Handle flashHandle);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _FLASH_H_ definition

