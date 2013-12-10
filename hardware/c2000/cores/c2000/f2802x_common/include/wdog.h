#ifndef _WDOG_H_
#define _WDOG_H_

//#############################################################################
//
//! \file   f2802x_common/include/wdog.h
//!
//! \brief  Contains public interface to various functions related
//!         to the watchdog (WDOG) timer object 
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
//! \defgroup WDOG

//!
//! \ingroup WDOG
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the watchdog (WDOG) registers
//!
#define WDOG_BASE_ADDR                  (0x00007022)


//! \brief Defines the location of the WDOVERRIDE bits in the SCSR register
//!
#define WDOG_SCSR_WDOVERRIDE_BITS         (1 << 0)

//! \brief Defines the location of the WDENINT bits in the SCSR register
//!
#define WDOG_SCSR_WDENINT_BITS            (1 << 1)

//! \brief Defines the location of the WDINTS bits in the SCSR register
//!
#define WDOG_SCSR_WDINTS_BITS             (1 << 2)


//! \brief Defines the location of the WDCNTR bits in the WDCNTR register
//!
#define WDOG_WDCNTR_BITS                (255 << 0)


//! \brief Defines the location of the WDKEY bits in the WDKEY register
//!
#define WDOG_WDKEY_BITS                 (255 << 0)


//! \brief Defines the location of the WDPS bits in the WDCR register
//!
#define WDOG_WDCR_WDPS_BITS             (7 << 0)

//! \brief Defines the location of the WDCHK bits in the WDCR register
//!
#define WDOG_WDCR_WDCHK_BITS            (7 << 3)

//! \brief Defines the location of the WDDIS bits in the WDCR register
//!
#define WDOG_WDCR_WDDIS_BITS            (1 << 6)

//! \brief Defines the location of the WDFLAG bits in the WDCR register
//!
#define WDOG_WDCR_WDFLAG_BITS           (1 << 7)


//! \brief Defines the watchdog write enable mode
//!
#define WDOG_WDCR_WRITE_ENABLE          (5 << 3)


// **************************************************************************
// the typedefs


//! \brief Enumeration to define the watchdog (WDOG) interrupt status
//!
typedef enum
{
    WDOG_IntStatus_Active=(0 << 2),   // Denotes an active interrupt status
    WDOG_IntStatus_InActive=(1 << 2)  // Denotes an in-active interrupt status
} WDOG_IntStatus_e;


//! \brief Enumeration to define the watchdog (WDOG) timer clock prescaler, which sets the clock frequency
//!
typedef enum
{
    WDOG_PreScaler_OscClk_by_512_by_1=1,   //!< Denotes WDCLK = OSCCLK/512/1
    WDOG_PreScaler_OscClk_by_512_by_2,     //!< Denotes WDCLK = OSCCLK/512/2
    WDOG_PreScaler_OscClk_by_512_by_4,     //!< Denotes WDCLK = OSCCLK/512/4
    WDOG_PreScaler_OscClk_by_512_by_8,     //!< Denotes WDCLK = OSCCLK/512/8
    WDOG_PreScaler_OscClk_by_512_by_16,    //!< Denotes WDCLK = OSCCLK/512/16
    WDOG_PreScaler_OscClk_by_512_by_32,    //!< Denotes WDCLK = OSCCLK/512/32
    WDOG_PreScaler_OscClk_by_512_by_64     //!< Denotes WDCLK = OSCCLK/512/64
} WDOG_PreScaler_e;


//! \brief Defines the watchdog (WDOG) object
//!
typedef struct _WDOG_Obj_
{
    volatile uint16_t   SCSR;      //!< System Control & Status Register
    volatile uint16_t   WDCNTR;    //!< Watchdog Counter Register
    volatile uint16_t   rsvd_1;    //!< Reserved
    volatile uint16_t   WDKEY;     //!< Watchdog Reset Key Register
    volatile uint16_t   rsvd_2[3]; //!< Reserved
    volatile uint16_t   WDCR;      //!< Watchdog Control Register
} WDOG_Obj;


//! \brief Defines the watchdog (WDOG) handle
//!
typedef struct WDOG_Obj *WDOG_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Clears the watchdog (WDOG) counter
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_clearCounter(WDOG_Handle wdogHandle);


//! \brief     Disables the watchdog (WDOG) timer
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_disable(WDOG_Handle wdogHandle);


//! \brief     Disables the watchdog (WDOG) timer interrupt
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_disableInt(WDOG_Handle wdogHandle);


//! \brief     Disables the timer override
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_disableOverRide(WDOG_Handle wdogHandle);


//! \brief     Enables the watchdog (WDOG) timer
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_enable(WDOG_Handle wdogHandle);


//! \brief     Enables the watchdog (WDOG) timer interrupt
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_enableInt(WDOG_Handle wdogHandle);


//! \brief     Enables the watchdog (WDOG) timer override
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
void WDOG_enableOverRide(WDOG_Handle wdogHandle);


//! \brief     Gets the watchdog (WDOG) interrupt status
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
//! \return    The interrupt status
WDOG_IntStatus_e WDOG_getIntStatus(WDOG_Handle wdogHandle);


//! \brief     Initializes the watchdog (WDOG) object handle
//! \param[in] pMemory     A pointer to the base address of the WDOG registers
//! \param[in] numBytes    The number of bytes allocated for the WDOG object, bytes
//! \return    The watchdog (WDOG) object handle
WDOG_Handle WDOG_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the watchdog (WDOG) counter
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
//! \param[in] count       The count
void WDOG_setCount(WDOG_Handle wdogHandle,const uint8_t count);


//! \brief     Sets the watchdog (WDOG) timer clock prescaler
//! \param[in] wdogHandle  The watchdog (WDOG) timer object handle
//! \param[in] preScaler   The prescaler
void WDOG_setPreScaler(WDOG_Handle wdogHandle,const WDOG_PreScaler_e preScaler);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _WDOG_H_ definition

