#ifndef _PWMDAC_H_
#define _PWMDAC_H_

//! \file   ~dmc_dev/sw/drivers/pwmdac/src/32b/f28x/f2803x/pwmdac.h
//! \brief  Contains public interface to various functions related
//!         to the pulse width modulation digital-to-analog 
//!         converter (PWMDAC) object
//!
//! (C) Copyright 2011, Texas Instruments, Inc.


// **************************************************************************
// the includes

#include "dmc_dev/sw/drivers/pwm/src/32b/f28x/f2803x/pwm.h"


//!
//! \defgroup PWMDAC

//!
//! \ingroup PWMDAC
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines

//!  \brief  Defines the pulse width modulation digital-to-analog (PWMDAC) handle
//!
#define   PWMDAC_Handle                             PWM_Handle

//!  \brief  Links the PWMDAC_disableDeadBand() function to the PWM_disableDeadBand() function
//!
#define   PWMDAC_disableDeadBand                    PWM_disableDeadBand

//!  \brief  Links the PWMDAC_() function to the PWM_() function
//!
#define   PWMDAC_disableChopping                    PWM_disableChopping

//!  \brief  Links the PWMDAC_() function to the PWM_() function
//!
#define   PWMDAC_disableTripZones                   PWM_disableTripZones

//!  \brief  Links the PWMDAC_disableCounterLoad() function to the PWM_disableCounterLoad() function
//!
#define   PWMDAC_disableCounterLoad                 PWM_disableCounterLoad

//!  \brief  Links the PWMDAC_init() function to the PWM_init() function
//!
#define   PWMDAC_init                               PWM_init

//!  \brief  Links the PWMDAC_setActionQual_CntDown_CmpA_PwmA() function to the PWM_setActionQual_CntDown_CmpA_PwmA() function
//!
#define   PWMDAC_setActionQual_CntDown_CmpA_PwmA    PWM_setActionQual_CntDown_CmpA_PwmA

//!  \brief  Links the PWMDAC_setActionQual_CntDown_CmpB_PwmB() function to the PWM_setActionQual_CntDown_CmpB_PwmB() function
//!
#define   PWMDAC_setActionQual_CntDown_CmpB_PwmB    PWM_setActionQual_CntDown_CmpB_PwmB

//!  \brief  Links the PWMDAC_setActionQual_CntUp_CmpA_PwmA() function to the PWM_setActionQual_CntUp_CmpA_PwmA() function
//!
#define   PWMDAC_setActionQual_CntUp_CmpA_PwmA      PWM_setActionQual_CntUp_CmpA_PwmA

//!  \brief  Links the PWMDAC_setActionQual_CntUp_CmpB_PwmB() function to the PWM_setActionQual_CntUp_CmpB_PwmB() function
//!
#define   PWMDAC_setActionQual_CntUp_CmpB_PwmB      PWM_setActionQual_CntUp_CmpB_PwmB

//!  \brief  Links the PWMDAC_setClkDiv() function to the PWM_setClkDiv() function
//!
#define   PWMDAC_setClkDiv                          PWM_setClkDiv

//!  \brief  Links the PWMDAC_setCounterMode() function to the PWM_setCounterMode() function
//!
#define   PWMDAC_setCounterMode                     PWM_setCounterMode

//!  \brief  Links the PWMDAC_setHighSpeedClkDiv() function to the PWM_setHighSpeedClkDiv() function
//!
#define   PWMDAC_setHighSpeedClkDiv                 PWM_setHighSpeedClkDiv

//!  \brief  Links the PWMDAC_setLoadMode_CmpA() function to the PWM_setLoadMode_CmpA() function
//!
#define   PWMDAC_setLoadMode_CmpA                   PWM_setLoadMode_CmpA

//!  \brief  Links the PWMDAC_setLoadMode_CmpB() function to the PWM_setLoadMode_CmpB() function
//!
#define   PWMDAC_setLoadMode_CmpB                   PWM_setLoadMode_CmpB

//!  \brief  Links the PWMDAC_setPeriod() function to the PWM_setPeriod() function
//!
#define   PWMDAC_setPeriod                          PWM_setPeriod

//!  \brief  Links the PWMDAC_setPeriodLoad() function to the PWM_setPeriodLoad() function
//!
#define   PWMDAC_setPeriodLoad                      PWM_setPeriodLoad

//!  \brief  Links the PWMDAC_setPhase() function to the PWM_setPhase() function
//!
#define   PWMDAC_setPhase                           PWM_setPhase

//!  \brief  Links the PWMDAC_setPhaseDir() function to the PWM_setPhaseDir() function
//!
#define   PWMDAC_setPhaseDir                        PWM_setPhaseDir

//!  \brief  Links the PWMDAC_setRunMode() function to the PWM_setRunMode() function
//!
#define   PWMDAC_setRunMode                         PWM_setRunMode

//!  \brief  Links the PWMDAC_setShadowMode_CmpA() function to the PWM_setShadowMode_CmpA() function
//!
#define   PWMDAC_setShadowMode_CmpA                 PWM_setShadowMode_CmpA

//!  \brief  Links the PWMDAC_setShadowMode_CmpB() function to the PWM_setShadowMode_CmpB() function
//!
#define   PWMDAC_setShadowMode_CmpB                 PWM_setShadowMode_CmpB

//!  \brief  Links the PWMDAC_setSyncMode() function to the PWM_setSyncMode() function
//!
#define   PWMDAC_setSyncMode                        PWM_setSyncMode

//!  \brief  Links the PWMDAC_setTripZoneState_TZA() function to the PWM_setTripZoneState_TZA() function
//!
#define   PWMDAC_setTripZoneState_TZA               PWM_setTripZoneState_TZA

//!  \brief  Links the PWMDAC_setTripZoneState_TZB() function to the PWM_setTripZoneState_TZB() function
//!
#define   PWMDAC_setTripZoneState_TZB               PWM_setTripZoneState_TZB

//!  \brief  Links the PWMDAC_setTripZoneState_DCAEVT1() function to the PWM_setTripZoneState_DCAEVT1() function
//!
#define   PWMDAC_setTripZoneState_DCAEVT1           PWM_setTripZoneState_DCAEVT1

//!  \brief  Links the PWMDAC_setTripZoneState_DCAEVT2() function to the PWM_setTripZoneState_DCAEVT2() function
//!
#define   PWMDAC_setTripZoneState_DCAEVT2           PWM_setTripZoneState_DCAEVT2

//!  \brief  Links the PWMDAC_setTripZoneState_DCBEVT1() function to the PWM_setTripZoneState_DCBEVT1() function
//!
#define   PWMDAC_setTripZoneState_DCBEVT1           PWM_setTripZoneState_DCBEVT1


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the pulse width modulation digital-to-analog (PWM) numbers
//!
typedef enum
{
    PWMDAC_Number_1=0,
    PWMDAC_Number_2,
    PWMDAC_Number_3,
    PWMDAC_Number_4,
    PWMDAC_Number_5,
    PWMDAC_Number_6,
    PWMDAC_Number_7
} PWMDAC_Number_e;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _PWMDAC_H_ definition

