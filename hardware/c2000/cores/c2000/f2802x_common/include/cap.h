#ifndef _CAP_H_
#define _CAP_H_

//#############################################################################
//
//! \file   f2802x_common/include/cap.h
//!
//! \brief  Contains public interface to various functions related
//!         to the Enhanced Capture (CAP) object
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

// drivers
#include "f2802x_common/include/cpu.h"


// modules


//!
//! \defgroup CAP

//!
//! \ingroup CAP
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the capture (CAP) A registers
//!
#define CAPA_BASE_ADDR              (0x00006A00)




//! \brief Defines the location of the FREE/SOFT bits in the ECCTL1 register
//!
#define CAP_ECCTL1_FREESOFT_BITS   (3 << 14)

//! \brief Defines the location of the PRESCALE bits in the ECCTL1 register
//!
#define CAP_ECCTL1_PRESCALE_BITS   (31 << 9)

//! \brief Defines the location of the CAPLDEN bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CAPLDEN_BITS   (1 << 8)

//! \brief Defines the location of the CTRRST4 bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CTRRST4_BITS   (1 << 7)

//! \brief Defines the location of the CAP4POL bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CAP4POL_BITS   (1 << 6)

//! \brief Defines the location of the CTRRST3 bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CTRRST3_BITS   (1 << 5)

//! \brief Defines the location of the CAP3POL bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CAP3POL_BITS   (1 << 4)

//! \brief Defines the location of the CTRRST2 bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CTRRST2_BITS   (1 << 3)

//! \brief Defines the location of the CAP2POL bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CAP2POL_BITS   (1 << 2)

//! \brief Defines the location of the CTRRST1 bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CTRRST1_BITS   (1 << 1)

//! \brief Defines the location of the CAP1POL bits in the ECCTL1 register
//!
#define CAP_ECCTL1_CAP1POL_BITS   (1 << 0)


//! \brief Defines the location of the APWMPOL bits in the ECCTL2 register
//!
#define CAP_ECCTL2_APWMPOL_BITS   (1 << 10)

//! \brief Defines the location of the CAP/APWM bits in the ECCTL2 register
//!
#define CAP_ECCTL2_CAPAPWM_BITS   (1 << 9)

//! \brief Defines the location of the SWSYNC bits in the ECCTL2 register
//!
#define CAP_ECCTL2_SWSYNC_BITS    (1 << 8)

//! \brief Defines the location of the SYNCO_SEL bits in the ECCTL2 register
//!
#define CAP_ECCTL2_SYNCOSEL_BITS  (3 << 6)

//! \brief Defines the location of the SYNCI_EN bits in the ECCTL2 register
//!
#define CAP_ECCTL2_SYNCIEN_BITS   (1 << 5)

//! \brief Defines the location of the TSCTRSTOP bits in the ECCTL2 register
//!
#define CAP_ECCTL2_TSCTRSTOP_BITS (1 << 4)

//! \brief Defines the location of the REARM bits in the ECCTL2 register
//!
#define CAP_ECCTL2_REARM_BITS     (1 << 3)

//! \brief Defines the location of the STOP_WRAP bits in the ECCTL2 register
//!
#define CAP_ECCTL2_STOP_WRAP_BITS (3 << 1)

//! \brief Defines the location of the CONT/ONESHOT bits in the ECCTL2 register
//!
#define CAP_ECCTL2_CONTONESHOT_BITS (1 << 0)


//! \brief Defines the location of the CTR=COMP bits in the ECCxxx register
//!
#define CAP_ECCxxx_CTRCOMP_BITS  (1 << 7)

//! \brief Defines the location of the CTR=PRD bits in the ECCxxx register
//!
#define CAP_ECCxxx_CTRPRD_BITS   (1 << 6)

//! \brief Defines the location of the CTROVF bits in the ECCxxx register
//!
#define CAP_ECCxxx_CTROVF_BITS   (1 << 5)

//! \brief Defines the location of the CEVT4 bits in the ECCxxx register
//!
#define CAP_ECCxxx_CEVT4_BITS    (1 << 4)

//! \brief Defines the location of the CEVT4 bits in the ECCxxx register
//!
#define CAP_ECCxxx_CEVT3_BITS    (1 << 3)

//! \brief Defines the location of the CEVT4 bits in the ECCxxx register
//!
#define CAP_ECCxxx_CEVT2_BITS    (1 << 2)

//! \brief Defines the location of the CEVT4 bits in the ECCxxx register
//!
#define CAP_ECCxxx_CEVT1_BITS    (1 << 1)

//! \brief Defines the location of the INT bits in the ECCxxx register
//!
#define CAP_ECCxxx_INT_BITS      (1 << 0)




// **************************************************************************
// the typedefs

//! \brief Enumeration to define the capture (CAP) interrupts
//!
typedef enum
{
    CAP_Int_Type_CTR_CMP = (1 << 7),     //!< Denotes CTR = CMP interrupt
    CAP_Int_Type_CTR_PRD = (1 << 6),     //!< Denotes CTR = PRD interrupt
    CAP_Int_Type_CTR_OVF = (1 << 5),     //!< Denotes CTROVF interrupt
    CAP_Int_Type_CEVT4 = (1 << 4),       //!< Denotes CEVT4 interrupt
    CAP_Int_Type_CEVT3 = (1 << 3),       //!< Denotes CEVT3 interrupt
    CAP_Int_Type_CEVT2 = (1 << 2),       //!< Denotes CEVT2 interrupt
    CAP_Int_Type_CEVT1 = (1 << 1),       //!< Denotes CEVT1 interrupt
    CAP_Int_Type_Global = (1 << 0),      //!< Denotes Capture global interrupt
    CAP_Int_Type_All = 0x00FF            //!< Denotes All interrupts
} CAP_Int_Type_e;

//! \brief Enumeration to define the capture (CAP) prescaler values
//!
typedef enum
{
    CAP_Prescale_By_1 = (0 << 9),    //!< Divide by 1
    CAP_Prescale_By_2 = (1 << 9),    //!< Divide by 2
    CAP_Prescale_By_4 = (2 << 9),    //!< Divide by 4
    CAP_Prescale_By_6 = (3 << 9),    //!< Divide by 6
    CAP_Prescale_By_8 = (4 << 9),    //!< Divide by 8
    CAP_Prescale_By_10 = (5 << 9),   //!< Divide by 10
    CAP_Prescale_By_12 = (6 << 9),   //!< Divide by 12
    CAP_Prescale_By_14 = (7 << 9),   //!< Divide by 14
    CAP_Prescale_By_16 = (8 << 9),   //!< Divide by 16
    CAP_Prescale_By_18 = (9 << 9),   //!< Divide by 18
    CAP_Prescale_By_20 = (10 << 9),  //!< Divide by 20
    CAP_Prescale_By_22 = (11 << 9),  //!< Divide by 22
    CAP_Prescale_By_24 = (12 << 9),  //!< Divide by 24
    CAP_Prescale_By_26 = (13 << 9),  //!< Divide by 26
    CAP_Prescale_By_28 = (14 << 9),  //!< Divide by 28
    CAP_Prescale_By_30 = (15 << 9),  //!< Divide by 30
    CAP_Prescale_By_32 = (16 << 9),  //!< Divide by 32
    CAP_Prescale_By_34 = (17 << 9),  //!< Divide by 34
    CAP_Prescale_By_36 = (18 << 9),  //!< Divide by 36
    CAP_Prescale_By_38 = (19 << 9),  //!< Divide by 38
    CAP_Prescale_By_40 = (20 << 9),  //!< Divide by 40
    CAP_Prescale_By_42 = (21 << 9),  //!< Divide by 42
    CAP_Prescale_By_44 = (22 << 9),  //!< Divide by 44
    CAP_Prescale_By_46 = (23 << 9),  //!< Divide by 46
    CAP_Prescale_By_48 = (24 << 9),  //!< Divide by 48
    CAP_Prescale_By_50 = (25 << 9),  //!< Divide by 50
    CAP_Prescale_By_52 = (26 << 9),  //!< Divide by 52
    CAP_Prescale_By_54 = (27 << 9),  //!< Divide by 54
    CAP_Prescale_By_56 = (28 << 9),  //!< Divide by 56
    CAP_Prescale_By_58 = (29 << 9),  //!< Divide by 58
    CAP_Prescale_By_60 = (30 << 9),  //!< Divide by 60
    CAP_Prescale_By_62 = (31 << 9)   //!< Divide by 62
} CAP_Prescale_e;

//! \brief Enumeration to define the pulse width modulation (PWM) run modes
//!
typedef enum
{
    CAP_RunMode_HardStop = (0 << 14),
    CAP_RunMode_SoftStopAfterCycle = (1 << 14),
    CAP_RunMode_FreeRun = (2 << 14)
} CAP_RunMode_e;

//! \brief Enumeration to define the capture (CAP) Stop/Wrap modes
//!
typedef enum
{
    CAP_Stop_Wrap_CEVT1 = (0 << 1),     //!< Stop/Wrap after Capture Event 1
    CAP_Stop_Wrap_CEVT2 = (1 << 1),     //!< Stop/Wrap after Capture Event 2
    CAP_Stop_Wrap_CEVT3 = (2 << 1),     //!< Stop/Wrap after Capture Event 3
    CAP_Stop_Wrap_CEVT4 = (3 << 1)      //!< Stop/Wrap after Capture Event 4
} CAP_Stop_Wrap_e;

//! \brief Enumeration to define the capture (CAP) events
//!
typedef enum
{
    CAP_Event_1 = 0,     //!< Capture Event 1
    CAP_Event_2,         //!< Capture Event 2
    CAP_Event_3,         //!< Capture Event 3
    CAP_Event_4          //!< Capture Event 4
} CAP_Event_e;

//! \brief Enumeration to define the capture (CAP) event polarities
//!
typedef enum
{
    CAP_Polarity_Rising = 0,     //!< Rising Edge Triggered
    CAP_Polarity_Falling         //!< Falling Edge Triggered
} CAP_Polarity_e;


//! \brief Enumeration to define the capture (CAP) event resets
//!
typedef enum
{
    CAP_Reset_Disable = 0,     //!< Disable counter reset on capture event
    CAP_Reset_Enable           //!< Enable counter reset on capture event
} CAP_Reset_e;

//! \brief Enumeration to define the Sync Out options
//!
typedef enum
{
    CAP_SyncOut_SyncIn = (0 << 6),     //!< Sync In used for Sync Out
    CAP_SyncOut_CTRPRD = (1 << 6),     //!< CTR = PRD used for Sync Out
    CAP_SyncOut_Disable = (2 << 6)    //!< Disables Sync Out
} CAP_SyncOut_e;


//! \brief Defines the capture (CAP) object
//!
typedef struct _CAP_Obj_
{
    volatile uint32_t      TSCTR;        //!< Time-stamp Counter
    volatile uint32_t      CTRPHS;       //!< Counter Phase Offset Value Register
    volatile uint32_t      CAP1;         //!< Capture 1 Register
    volatile uint32_t      CAP2;         //!< Capture 2 Register
    volatile uint32_t      CAP3;         //!< Capture 3 Register
    volatile uint32_t      CAP4;         //!< Capture 4 Register
    volatile uint16_t      Rsvd_1[8];    //!< Reserved
    volatile uint16_t      ECCTL1;       //!< Capture Control Register 1
    volatile uint16_t      ECCTL2;       //!< Capture Control Register 2
    volatile uint16_t      ECEINT;       //!< Capture Interrupt Enable Register
    volatile uint16_t      ECEFLG;       //!< Capture Interrupt Flag Register
    volatile uint16_t      ECECLR;       //!< Capture Interrupt Clear Register
    volatile uint16_t      ECEFRC;       //!< Capture Interrupt Force Register

} CAP_Obj;


//! \brief Defines the capture (CAP) handle
//!
typedef struct CAP_Obj  *CAP_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes



//! \brief     Sets capture peripheral up for capture mode
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_setModeCap(CAP_Handle capHandle);

//! \brief     Sets capture peripheral up for APWM mode
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_setModeApwm(CAP_Handle capHandle);

//! \brief     Clears capture (CAP) interrupt flag
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] intType  The capture interrupt to be cleared
inline void CAP_clearInt(CAP_Handle capHandle, const CAP_Int_Type_e intType)
{ 
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    cap->ECECLR |= intType;
    
    return;
}

//! \brief     Disables loading of CAP1-4 on capture event
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_disableCaptureLoad(CAP_Handle capHandle);

//! \brief     Disables capture (CAP) interrupt source
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] intType  The capture interrupt type to be disabled
void CAP_disableInt(CAP_Handle capHandle, const CAP_Int_Type_e intType);

//! \brief     Disables counter synchronization
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_disableSyncIn(CAP_Handle capHandle);

//! \brief     Disables Time Stamp counter from running
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_disableTimestampCounter(CAP_Handle capHandle);

//! \brief     Enables loading of CAP1-4 on capture event
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_enableCaptureLoad(CAP_Handle capHandle);

//! \brief     Enables capture (CAP) interrupt source
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] intType  The capture interrupt type to be enabled
void CAP_enableInt(CAP_Handle capHandle, const CAP_Int_Type_e intType);

//! \brief     Enables counter synchronization
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_enableSyncIn(CAP_Handle capHandle);

//! \brief     Enables Time Stamp counter to running
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_enableTimestampCounter(CAP_Handle capHandle);

//! \brief     Gets the CAP1 register value
//! \param[in] capHandle  The capture (CAP) object handle
inline uint32_t CAP_getCap1(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    return (cap->CAP1);
} // end of CAP_getCap1() function

//! \brief     Gets the CAP2 register value
//! \param[in] capHandle  The capture (CAP) object handle
inline uint32_t CAP_getCap2(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    return (cap->CAP2);
} // end of CAP_getCap2() function

//! \brief     Gets the CAP3 register value
//! \param[in] capHandle  The capture (CAP) object handle
inline uint32_t CAP_getCap3(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    return (cap->CAP3);
} // end of CAP_getCap3() function

//! \brief     Gets the CAP4 register value
//! \param[in] capHandle  The capture (CAP) object handle
inline uint32_t CAP_getCap4(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    return (cap->CAP4);
} // end of CAP_getCap4() function

//! \brief     (Re-)Arm the capture module
//! \param[in] capHandle  The capture (CAP) object handle
inline void CAP_rearm(CAP_Handle capHandle)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    cap->ECCTL2 |= CAP_ECCTL2_REARM_BITS;
    
    return;
} // end of CAP_rearm() function

//! \brief     Sets the capture event polarity
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] event  The event to configure
//! \param[in] polarity  The polarity to configure the event for
void CAP_setCapEvtPolarity(CAP_Handle capHandle, const CAP_Event_e event, const CAP_Polarity_e polarity);

//! \brief     Sets the capture event counter reset configuration
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] event  The event to configure
//! \param[in] reset  Whether the event should reset the counter or not
void CAP_setCapEvtReset(CAP_Handle capHandle, const CAP_Event_e event, const CAP_Reset_e reset);

//! \brief     Sets up for continuous Capture
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_setCapContinuous(CAP_Handle capHandle);

//! \brief     Sets up for one-shot Capture
//! \param[in] capHandle  The capture (CAP) object handle
void CAP_setCapOneShot(CAP_Handle capHandle);

//! \brief     Sets the APWM period
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] period  The APWM period
inline void CAP_setApwmPeriod(CAP_Handle capHandle, const uint32_t period)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    cap->CAP1 = period;
    
    return;
} // end of CAP_setApwmPeriod() function

//! \brief     Sets the APWM compare value
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] compare  The APWM compare value
inline void CAP_setApwmCompare(CAP_Handle capHandle, const uint32_t compare)
{
    CAP_Obj *cap = (CAP_Obj *)capHandle;
    
    cap->CAP2 = compare;
    
    return;
} // end of CAP_setApwmCompare() function

//! \brief     Set the stop/wrap mode
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] stopWrap  The stop/wrap mode to set
void CAP_setStopWrap(CAP_Handle capHandle, const CAP_Stop_Wrap_e stopWrap);

//! \brief     Set the sync out mode
//! \param[in] capHandle  The capture (CAP) object handle
//! \param[in] syncOut  The sync out mode to set
void CAP_setSyncOut(CAP_Handle capHandle, const CAP_SyncOut_e syncOut);

//! \brief     Initializes the capture (CAP) object handle
//! \param[in] pMemory     A pointer to the base address of the CAP registers
//! \param[in] numBytes    The number of bytes allocated for the CAP object, bytes
//! \return    The capture (CAP) object handle
CAP_Handle CAP_init(void *pMemory,const size_t numBytes);



#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _CAP_H_ definition

