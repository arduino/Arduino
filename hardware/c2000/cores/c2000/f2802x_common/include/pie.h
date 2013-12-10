#ifndef _PIE_H_
#define _PIE_H_

//#############################################################################
//
//! \file   f2802x_common/include/pie.h
//!
//! \brief  Contains public interface to various functions related
//!         to the peripheral interrupt expansion (PIE) object
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
#include "f2802x_common/include/adc.h"
#include "f2802x_common/include/pwm.h"


//!
//! \defgroup PIE

//!
//! \ingroup PIE
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the peripheral interrupt expansion (PIE) registers
//!
#define  PIE_BASE_ADDR              (0x00000CE0)


//! \brief Defines the location of the INT1 bits in the DBGIER register
//!
#define PIE_DBGIER_INT1_BITS        (1 << 0)

//! \brief Defines the location of the INT2 bits in the DBGIER register
//!
#define PIE_DBGIER_INT2_BITS        (1 << 1)

//! \brief Defines the location of the INT3 bits in the DBGIER register
//!
#define PIE_DBGIER_INT3_BITS        (1 << 2)

//! \brief Defines the location of the INT4 bits in the DBGIER register
//!
#define PIE_DBGIER_INT4_BITS        (1 << 3)

//! \brief Defines the location of the INT5 bits in the DBGIER register
//!
#define PIE_DBGIER_INT5_BITS        (1 << 4)

//! \brief Defines the location of the INT6 bits in the DBGIER register
//!
#define PIE_DBGIER_INT6_BITS        (1 << 5)

//! \brief Defines the location of the INT7 bits in the DBGIER register
//!
#define PIE_DBGIER_INT7_BITS        (1 << 6)

//! \brief Defines the location of the INT8 bits in the DBGIER register
//!
#define PIE_DBGIER_INT8_BITS        (1 << 7)

//! \brief Defines the location of the INT9 bits in the DBGIER register
//!
#define PIE_DBGIER_INT9_BITS        (1 << 8)

//! \brief Defines the location of the INT10 bits in the DBGIER register
//!
#define PIE_DBGIER_INT10_BITS       (1 << 9)

//! \brief Defines the location of the INT11 bits in the DBGIER register
//!
#define PIE_DBGIER_INT11_BITS       (1 << 10)

//! \brief Defines the location of the INT12 bits in the DBGIER register
//!
#define PIE_DBGIER_INT12_BITS       (1 << 11)

//! \brief Defines the location of the INT13 bits in the DBGIER register
//!
#define PIE_DBGIER_INT13_BITS       (1 << 12)

//! \brief Defines the location of the INT14 bits in the DBGIER register
//!
#define PIE_DBGIER_INT14_BITS       (1 << 13)

//! \brief Defines the location of the DLOGINT bits in the DBGIER register
//!
#define PIE_DBGIER_DLOGINT_BITS     (1 << 14)

//! \brief Defines the location of the RTOSINT bits in the DBGIER register
//!
#define PIE_DBGIER_RTOSINT_BITS     (1 << 15)



//! \brief Defines the location of the INT1 bits in the IER register
//!
#define PIE_IER_INT1_BITS        (1 << 0)

//! \brief Defines the location of the INT2 bits in the IER register
//!
#define PIE_IER_INT2_BITS        (1 << 1)

//! \brief Defines the location of the INT3 bits in the IER register
//!
#define PIE_IER_INT3_BITS        (1 << 2)

//! \brief Defines the location of the INT4 bits in the IER register
//!
#define PIE_IER_INT4_BITS        (1 << 3)

//! \brief Defines the location of the INT5 bits in the IER register
//!
#define PIE_IER_INT5_BITS        (1 << 4)

//! \brief Defines the location of the INT6 bits in the IER register
//!
#define PIE_IER_INT6_BITS        (1 << 5)

//! \brief Defines the location of the INT7 bits in the IER register
//!
#define PIE_IER_INT7_BITS        (1 << 6)

//! \brief Defines the location of the INT8 bits in the IER register
//!
#define PIE_IER_INT8_BITS        (1 << 7)

//! \brief Defines the location of the INT9 bits in the IER register
//!
#define PIE_IER_INT9_BITS        (1 << 8)

//! \brief Defines the location of the INT10 bits in the IER register
//!
#define PIE_IER_INT10_BITS       (1 << 9)

//! \brief Defines the location of the INT11 bits in the IER register
//!
#define PIE_IER_INT11_BITS       (1 << 10)

//! \brief Defines the location of the INT12 bits in the IER register
//!
#define PIE_IER_INT12_BITS       (1 << 11)

//! \brief Defines the location of the INT13 bits in the IER register
//!
#define PIE_IER_INT13_BITS       (1 << 12)

//! \brief Defines the location of the INT14 bits in the IER register
//!
#define PIE_IER_INT14_BITS       (1 << 13)

//! \brief Defines the location of the DLOGINT bits in the IER register
//!
#define PIE_IER_DLOGINT_BITS     (1 << 14)

//! \brief Defines the location of the RTOSINT bits in the IER register
//!
#define PIE_IER_RTOSINT_BITS     (1 << 15)


//! \brief Defines the location of the INTx1 bits in the IERx register
//!
#define PIE_IERx_INTx1_BITS      (1 << 0)

//! \brief Defines the location of the INTx2 bits in the IERx register
//!
#define PIE_IERx_INTx2_BITS      (1 << 1)

//! \brief Defines the location of the INTx3 bits in the IERx register
//!
#define PIE_IERx_INTx3_BITS      (1 << 2)

//! \brief Defines the location of the INTx4 bits in the IERx register
//!
#define PIE_IERx_INTx4_BITS      (1 << 3)

//! \brief Defines the location of the INTx5 bits in the IERx register
//!
#define PIE_IERx_INTx5_BITS      (1 << 4)

//! \brief Defines the location of the INTx6 bits in the IERx register
//!
#define PIE_IERx_INTx6_BITS      (1 << 5)

//! \brief Defines the location of the INTx7 bits in the IERx register
//!
#define PIE_IERx_INTx7_BITS      (1 << 6)

//! \brief Defines the location of the INTx8 bits in the IERx register
//!
#define PIE_IERx_INTx8_BITS      (1 << 7)


//! \brief Defines the location of the INT1 bits in the IFR register
//!
#define PIE_IFR_INT1_BITS        (1 << 0)

//! \brief Defines the location of the INT2 bits in the IFR register
//!
#define PIE_IFR_INT2_BITS        (1 << 1)

//! \brief Defines the location of the INT3 bits in the IFR register
//!
#define PIE_IFR_INT3_BITS        (1 << 2)

//! \brief Defines the location of the INT4 bits in the IFR register
//!
#define PIE_IFR_INT4_BITS        (1 << 3)

//! \brief Defines the location of the INT5 bits in the IFR register
//!
#define PIE_IFR_INT5_BITS        (1 << 4)

//! \brief Defines the location of the INT6 bits in the IFR register
//!
#define PIE_IFR_INT6_BITS        (1 << 5)

//! \brief Defines the location of the INT7 bits in the IFR register
//!
#define PIE_IFR_INT7_BITS        (1 << 6)

//! \brief Defines the location of the INT8 bits in the IFR register
//!
#define PIE_IFR_INT8_BITS        (1 << 7)

//! \brief Defines the location of the INT9 bits in the IFR register
//!
#define PIE_IFR_INT9_BITS        (1 << 8)

//! \brief Defines the location of the INT10 bits in the IFR register
//!
#define PIE_IFR_INT10_BITS       (1 << 9)

//! \brief Defines the location of the INT11 bits in the IFR register
//!
#define PIE_IFR_INT11_BITS       (1 << 10)

//! \brief Defines the location of the INT12 bits in the IFR register
//!
#define PIE_IFR_INT12_BITS       (1 << 11)

//! \brief Defines the location of the INT13 bits in the IFR register
//!
#define PIE_IFR_INT13_BITS       (1 << 12)

//! \brief Defines the location of the INT14 bits in the IFR register
//!
#define PIE_IFR_INT14_BITS       (1 << 13)

//! \brief Defines the location of the DLOGINT bits in the IFR register
//!
#define PIE_IFR_DLOGINT_BITS     (1 << 14)

//! \brief Defines the location of the RTOSINT bits in the IFR register
//!
#define PIE_IFR_RTOSINT_BITS     (1 << 15)


//! \brief Defines the location of the INTx1 bits in the IFRx register
//!
#define PIE_IFRx_INTx1_BITS      (1 << 0)

//! \brief Defines the location of the INTx2 bits in the IFRx register
//!
#define PIE_IFRx_INTx2_BITS      (1 << 1)

//! \brief Defines the location of the INTx3 bits in the IFRx register
//!
#define PIE_IFRx_INTx3_BITS      (1 << 2)

//! \brief Defines the location of the INTx4 bits in the IFRx register
//!
#define PIE_IFRx_INTx4_BITS      (1 << 3)

//! \brief Defines the location of the INTx5 bits in the IFRx register
//!
#define PIE_IFRx_INTx5_BITS      (1 << 4)

//! \brief Defines the location of the INTx6 bits in the IFRx register
//!
#define PIE_IFRx_INTx6_BITS      (1 << 5)

//! \brief Defines the location of the INTx7 bits in the IFRx register
//!
#define PIE_IFRx_INTx7_BITS      (1 << 6)

//! \brief Defines the location of the INTx8 bits in the IFRx register
//!
#define PIE_IFRx_INTx8_BITS      (1 << 7)


//! \brief Defines the location of the ENPIE bits in the PIECTRL register
//!
#define PIE_PIECTRL_ENPIE_BITS   (1 << 0)

//! \brief Defines the location of the PIEVECT bits in the PIECTRL register
//!
#define PIE_PIECTRL_PIEVECT_BITS (32767 << 1)



//! \brief Defines the location of the GROUP1 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP1_BITS   (1 << 0)

//! \brief Defines the location of the GROUP2 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP2_BITS   (1 << 1)

//! \brief Defines the location of the GROUP3 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP3_BITS   (1 << 2)

//! \brief Defines the location of the GROUP4 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP4_BITS   (1 << 3)

//! \brief Defines the location of the GROUP5 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP5_BITS   (1 << 4)

//! \brief Defines the location of the GROUP6 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP6_BITS   (1 << 5)

//! \brief Defines the location of the GROUP7 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP7_BITS   (1 << 6)

//! \brief Defines the location of the GROUP8 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP8_BITS   (1 << 7)

//! \brief Defines the location of the GROUP9 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP9_BITS   (1 << 8)

//! \brief Defines the location of the GROUP10 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP10_BITS  (1 << 9)

//! \brief Defines the location of the GROUP11 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP11_BITS  (1 << 10)

//! \brief Defines the location of the GROUP12 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP12_BITS  (1 << 11)


#define PIE_XINTnCR_POLARITY_BITS  (3 << 2)
#define PIE_XINTnCR_ENABLE_BITS    (1 << 0)


// **************************************************************************
// the typedefs

//! \brief Defines the type for an interrupt vector
//!
typedef interrupt void (*intVec_t)(void);


//! \brief Enumeration to define the external interrupt polarity
//!
typedef enum
{
    PIE_ExtIntPolarity_FallingEdge=(0 << 2),          //!< Denotes an interrupt is generated on the falling edge
    PIE_ExtIntPolarity_RisingEdge=(1 << 2),           //!< Denotes an interrupt is generated on the rising edge
    PIE_ExtIntPolarity_RisingAndFallingEdge=(3 << 2)  //!< Denotes an interrupt is generated on the falling and rising edges
} PIE_ExtIntPolarity_e;


//! \brief Enumeration to define the peripheral interrupt expansion (PIE) group numbers
//!
typedef enum
{
    PIE_GroupNumber_1 = 0,     //!< Denotes PIE group number 1
    PIE_GroupNumber_2 = 1,     //!< Denotes PIE group number 2
    PIE_GroupNumber_3 = 2,     //!< Denotes PIE group number 3
    PIE_GroupNumber_4 = 3,     //!< Denotes PIE group number 4
    PIE_GroupNumber_5 = 4,     //!< Denotes PIE group number 5
    PIE_GroupNumber_6 = 5,     //!< Denotes PIE group number 6
    PIE_GroupNumber_7 = 6,     //!< Denotes PIE group number 7
    PIE_GroupNumber_8 = 7,     //!< Denotes PIE group number 8
    PIE_GroupNumber_9 = 8,     //!< Denotes PIE group number 9
    PIE_GroupNumber_10 = 9,    //!< Denotes PIE group number 10
    PIE_GroupNumber_11 = 10,   //!< Denotes PIE group number 11
    PIE_GroupNumber_12 = 11    //!< Denotes PIE group number 12
} PIE_GroupNumber_e;


//! \brief Enumeration to define the peripheral interrupt expansion (PIE) sub-group numbers
//!
typedef enum
{
    PIE_SubGroupNumber_1 = 0,     //!< Denotes PIE group number 1
    PIE_SubGroupNumber_2 = 1,     //!< Denotes PIE group number 2
    PIE_SubGroupNumber_3 = 2,     //!< Denotes PIE group number 3
    PIE_SubGroupNumber_4 = 3,     //!< Denotes PIE group number 4
    PIE_SubGroupNumber_5 = 4,     //!< Denotes PIE group number 5
    PIE_SubGroupNumber_6 = 5,     //!< Denotes PIE group number 6
    PIE_SubGroupNumber_7 = 6,     //!< Denotes PIE group number 7
    PIE_SubGroupNumber_8 = 7      //!< Denotes PIE group number 8
} PIE_SubGroupNumber_e;


//! \brief Enumeration to define the system interrupts 
//!
typedef enum
{
    PIE_SystemInterrupts_Reset = 0,           //!< Reset interrupt vector
    PIE_SystemInterrupts_INT1,                //!< INT1 interrupt vector
    PIE_SystemInterrupts_INT2,                //!< INT2 interrupt vector
    PIE_SystemInterrupts_INT3,                //!< INT3 interrupt vector
    PIE_SystemInterrupts_INT4,                //!< INT4 interrupt vector
    PIE_SystemInterrupts_INT5,                //!< INT5 interrupt vector
    PIE_SystemInterrupts_INT6,                //!< INT6 interrupt vector
    PIE_SystemInterrupts_INT7,                //!< INT7 interrupt vector
    PIE_SystemInterrupts_INT8,                //!< INT8 interrupt vector
    PIE_SystemInterrupts_INT9,                //!< INT9 interrupt vector
    PIE_SystemInterrupts_INT10,               //!< INT10 interrupt vector
    PIE_SystemInterrupts_INT11,               //!< INT11 interrupt vector
    PIE_SystemInterrupts_INT12,               //!< INT12 interrupt vector
    PIE_SystemInterrupts_TINT1,               //!< INT13 interrupt vector
    PIE_SystemInterrupts_TINT2,               //!< INT14 interrupt vector
    PIE_SystemInterrupts_DATALOG,             //!< DATALOG interrupt vector
    PIE_SystemInterrupts_RTOSINT,             //!< RTOSINT interrupt vector
    PIE_SystemInterrupts_EMUINT,              //!< EMUINT interrupt vector
    PIE_SystemInterrupts_NMI,                 //!< NMI interrupt vector
    PIE_SystemInterrupts_ILLEGAL,             //!< ILLEGAL interrupt vector
    PIE_SystemInterrupts_USER1,               //!< USER1 interrupt vector
    PIE_SystemInterrupts_USER2,               //!< USER2 interrupt vector
    PIE_SystemInterrupts_USER3,               //!< USER3 interrupt vector
    PIE_SystemInterrupts_USER4,               //!< USER4 interrupt vector
    PIE_SystemInterrupts_USER5,               //!< USER5 interrupt vector
    PIE_SystemInterrupts_USER6,               //!< USER6 interrupt vector
    PIE_SystemInterrupts_USER7,               //!< USER7 interrupt vector
    PIE_SystemInterrupts_USER8,               //!< USER8 interrupt vector
    PIE_SystemInterrupts_USER9,               //!< USER9 interrupt vector
    PIE_SystemInterrupts_USER10,              //!< USER10 interrupt vector
    PIE_SystemInterrupts_USER11,              //!< USER11 interrupt vector
    PIE_SystemInterrupts_USER12               //!< USER12 interrupt vector
} PIE_SystemInterrupts_e;


//! \brief Enumeration to define the peripheral interrupt expansion (PIE) individual interrupt sources
//!
typedef enum
{
    //Group 1 Interrupts
    PIE_InterruptSource_ADCINT_1_1 = (1 << 0),     //!< Group 1 ADC Interrupt 1
    PIE_InterruptSource_ADCINT_1_2 = (1 << 1),     //!< Group 1 ADC Interrupt 2
    PIE_InterruptSource_XINT_1 = (1 << 3),       //!< External Interrupt 1
    PIE_InterruptSource_XINT_2 = (1 << 4),       //!< External Interrupt 2
    PIE_InterruptSource_ADCINT_9 = (1 << 5),     //!< ADC Interrupt 9
    PIE_InterruptSource_TIMER_0 = (1 << 6),      //!< Timer Interrupt 0
    PIE_InterruptSource_WAKE = (1 << 7),         //!< Wake Up Interrupt
    
    //Group 2 Interrupts
    PIE_InterruptSource_TZ1 = (1 << 0),          //!< EPWM TZ1 Interrupt
    PIE_InterruptSource_TZ2 = (1 << 1),          //!< EPWM TZ2 Interrupt
    PIE_InterruptSource_TZ3 = (1 << 2),          //!< EPWM TZ3 Interrupt
    PIE_InterruptSource_TZ4 = (1 << 3),          //!< EPWM TZ4 Interrupt
    
    //Group 3 Interrupts
    PIE_InterruptSource_EPWM1 = (1 << 0),          //!< EPWM 1 Interrupt
    PIE_InterruptSource_EPWM2 = (1 << 1),          //!< EPWM 2 Interrupt
    PIE_InterruptSource_EPWM3 = (1 << 2),          //!< EPWM 3 Interrupt
    PIE_InterruptSource_EPWM4 = (1 << 3),          //!< EPWM 4 Interrupt
    
    //Group 4 Interrupts
    PIE_InterruptSource_ECAP1 = (1 << 0),          //!< ECAP 1 Interrupt
    
    //Group 6 Interrupts
    PIE_InterruptSource_SPIARX = (1 << 0),          //!< SPI A RX Interrupt
    PIE_InterruptSource_SPIATX = (1 << 1),          //!< SPI A TX Interrupt
    
    //Group 8 Interrupts
    PIE_InterruptSource_I2CA1 = (1 << 0),          //!< I2C A Interrupt 1
    PIE_InterruptSource_I2CA2 = (1 << 1),          //!< I2C A Interrupt 2
    
    //Group 9 Interrupts
    PIE_InterruptSource_SCIARX = (1 << 0),          //!< SCI A RX Interrupt
    PIE_InterruptSource_SCIATX = (1 << 1),          //!< SCI A TX Interrupt
    
    //Group 10 Interrupts
    PIE_InterruptSource_ADCINT_10_1 = (1 << 0),     //!< Group 10 ADC Interrupt 1
    PIE_InterruptSource_ADCINT_10_2 = (1 << 1),     //!< Group 10 ADC Interrupt 2
    PIE_InterruptSource_ADCINT_3 = (1 << 2),     //!< ADC Interrupt 3
    PIE_InterruptSource_ADCINT_4 = (1 << 3),     //!< ADC Interrupt 4
    PIE_InterruptSource_ADCINT_5 = (1 << 4),     //!< ADC Interrupt 5
    PIE_InterruptSource_ADCINT_6 = (1 << 5),     //!< ADC Interrupt 6
    PIE_InterruptSource_ADCINT_7 = (1 << 6),     //!< ADC Interrupt 7
    PIE_InterruptSource_ADCINT_8 = (1 << 7),     //!< ADC Interrupt 8
    
    //Group 12 Interrupts
    PIE_InterruptSource_XINT_3 = (1 << 0)        //!< External Interrupt 3
    
} PIE_InterruptSource_e;


//! \brief Defines the PIE_IERIFR_t data type
//!
typedef struct _PIE_IERIFR_t
{
    volatile uint16_t   IER;   //!< the Interrupt Enable Register (IER)             
    volatile uint16_t   IFR;   //!< the Interrupt Flag Register (IFR)  
} PIE_IERIFR_t;


//! \brief Defines the peripheral interrupt expansion (PIE) object
//!
typedef struct _PIE_Obj_
{
    volatile uint16_t      PIECTRL;             //!< PIE Control Register
    volatile uint16_t      PIEACK;              //!< PIE Acknowledge Register
    volatile PIE_IERIFR_t  PIEIER_PIEIFR[12];   //!< PIE Interrupt Enable Register and PIE Interrupt Flag Register
    volatile uint16_t      rsvd_1[6];           //!< Reserved
    volatile intVec_t      Reset;               //!< Reset interrupt vector
    volatile intVec_t      INT1;                //!< INT1 interrupt vector
    volatile intVec_t      INT2;                //!< INT2 interrupt vector
    volatile intVec_t      INT3;                //!< INT3 interrupt vector
    volatile intVec_t      INT4;                //!< INT4 interrupt vector
    volatile intVec_t      INT5;                //!< INT5 interrupt vector
    volatile intVec_t      INT6;                //!< INT6 interrupt vector
    volatile intVec_t      INT7;                //!< INT7 interrupt vector
    volatile intVec_t      INT8;                //!< INT8 interrupt vector
    volatile intVec_t      INT9;                //!< INT9 interrupt vector
    volatile intVec_t      INT10;               //!< INT10 interrupt vector
    volatile intVec_t      INT11;               //!< INT11 interrupt vector
    volatile intVec_t      INT12;               //!< INT12 interrupt vector
    volatile intVec_t      TINT1;               //!< INT13 interrupt vector
    volatile intVec_t      TINT2;               //!< INT14 interrupt vector
    volatile intVec_t      DATALOG;             //!< DATALOG interrupt vector
    volatile intVec_t      RTOSINT;             //!< RTOSINT interrupt vector
    volatile intVec_t      EMUINT;              //!< EMUINT interrupt vector
    volatile intVec_t      NMI;                 //!< NMI interrupt vector
    volatile intVec_t      ILLEGAL;             //!< ILLEGAL interrupt vector
    volatile intVec_t      USER1;               //!< USER1 interrupt vector
    volatile intVec_t      USER2;               //!< USER2 interrupt vector
    volatile intVec_t      USER3;               //!< USER3 interrupt vector
    volatile intVec_t      USER4;               //!< USER4 interrupt vector
    volatile intVec_t      USER5;               //!< USER5 interrupt vector
    volatile intVec_t      USER6;               //!< USER6 interrupt vector
    volatile intVec_t      USER7;               //!< USER7 interrupt vector
    volatile intVec_t      USER8;               //!< USER8 interrupt vector
    volatile intVec_t      USER9;               //!< USER9 interrupt vector
    volatile intVec_t      USER10;              //!< USER10 interrupt vector
    volatile intVec_t      USER11;              //!< USER11 interrupt vector
    volatile intVec_t      USER12;              //!< USER12 interrupt vector
    volatile intVec_t      rsvd1_1;             //!< Reserved (Note: using ADCINT_1 in group 10)
    volatile intVec_t      rsvd1_2;             //!< Reserved (Note: using ADCINT_2 in group 10)
    volatile intVec_t      rsvd1_3;             //!< Reserved
    volatile intVec_t      XINT1;               //!< XINT1 interrupt vector
    volatile intVec_t      XINT2;               //!< XINT2 interrupt vector 
    volatile intVec_t      ADCINT9;             //!< ADCINT9 interrupt vector 
    volatile intVec_t      TINT0;               //!< TINT0 interrupt vector 
    volatile intVec_t      WAKEINT;             //!< WAKEINT interrupt vector 
    volatile intVec_t      EPWM1_TZINT;         //!< EPWM1_TZINT interrupt vector 
    volatile intVec_t      EPWM2_TZINT;         //!< EPWM2_TZINT interrupt vector 
    volatile intVec_t      EPWM3_TZINT;         //!< EPWM3_TZINT interrupt vector 
    volatile intVec_t      EPWM4_TZINT;         //!< EPWM4_TZINT interrupt vector 
    volatile intVec_t      rsvd2_5;             //!< Reserved
    volatile intVec_t      rsvd2_6;             //!< Reserved
    volatile intVec_t      rsvd2_7;             //!< Reserved
    volatile intVec_t      rsvd2_8;             //!< Reserved
    volatile intVec_t      EPWM1_INT;           //!< EPWM1 interrupt vector 
    volatile intVec_t      EPWM2_INT;           //!< EPWM2 interrupt vector 
    volatile intVec_t      EPWM3_INT;           //!< EPWM3 interrupt vector 
    volatile intVec_t      EPWM4_INT;           //!< EPWM4 interrupt vector 
    volatile intVec_t      rsvd3_5;             //!< Reserved
    volatile intVec_t      rsvd3_6;             //!< Reserved
    volatile intVec_t      rsvd3_7;             //!< Reserved
    volatile intVec_t      rsvd3_8;             //!< Reserved
    volatile intVec_t      ECAP1_INT;           //!< ECAP1_INT interrupt vector 
    volatile intVec_t      rsvd4_2;             //!< Reserved
    volatile intVec_t      rsvd4_3;             //!< Reserved
    volatile intVec_t      rsvd4_4;             //!< Reserved
    volatile intVec_t      rsvd4_5;             //!< Reserved
    volatile intVec_t      rsvd4_6;             //!< Reserved
    volatile intVec_t      rsvd4_7;             //!< Reserved
    volatile intVec_t      rsvd4_8;             //!< Reserved
    volatile intVec_t      rsvd5_1;             //!< Reserved
    volatile intVec_t      rsvd5_2;             //!< Reserved
    volatile intVec_t      rsvd5_3;             //!< Reserved
    volatile intVec_t      rsvd5_4;             //!< Reserved
    volatile intVec_t      rsvd5_5;             //!< Reserved
    volatile intVec_t      rsvd5_6;             //!< Reserved
    volatile intVec_t      rsvd5_7;             //!< Reserved
    volatile intVec_t      rsvd5_8;             //!< Reserved
    volatile intVec_t      SPIRXINTA;           //!< SPIRXINTA interrupt vector 
    volatile intVec_t      SPITXINTA;           //!< SPITXINTA interrupt vector 
    volatile intVec_t      rsvd6_3;             //!< Reserved 
    volatile intVec_t      rsvd6_4;             //!< Reserved 
    volatile intVec_t      rsvd6_5;             //!< Reserved
    volatile intVec_t      rsvd6_6;             //!< Reserved
    volatile intVec_t      rsvd6_7;             //!< Reserved
    volatile intVec_t      rsvd6_8;             //!< Reserved
    volatile intVec_t      rsvd7_1;             //!< Reserved
    volatile intVec_t      rsvd7_2;             //!< Reserved
    volatile intVec_t      rsvd7_3;             //!< Reserved
    volatile intVec_t      rsvd7_4;             //!< Reserved
    volatile intVec_t      rsvd7_5;             //!< Reserved
    volatile intVec_t      rsvd7_6;             //!< Reserved
    volatile intVec_t      rsvd7_7;             //!< Reserved
    volatile intVec_t      rsvd7_8;             //!< Reserved
    volatile intVec_t      I2CINT1A;            //!< I2CINT1A interrupt vector 
    volatile intVec_t      I2CINT2A;            //!< I2CINT2A interrupt vector 
    volatile intVec_t      rsvd8_3;             //!< Reserved
    volatile intVec_t      rsvd8_4;             //!< Reserved
    volatile intVec_t      rsvd8_5;             //!< Reserved
    volatile intVec_t      rsvd8_6;             //!< Reserved
    volatile intVec_t      rsvd8_7;             //!< Reserved
    volatile intVec_t      rsvd8_8;             //!< Reserved
    volatile intVec_t      SCIRXINTA;           //!< SCIRXINTA interrupt vector 
    volatile intVec_t      SCITXINTA;           //!< SCITXINTA interrupt vector 
    volatile intVec_t      rsvd9_3;             //!< Reserved
    volatile intVec_t      rsvd9_4;             //!< Reserved
    volatile intVec_t      rsvd9_5;             //!< Reserved
    volatile intVec_t      rsvd9_6;             //!< Reserved
    volatile intVec_t      rsvd9_7;             //!< Reserved
    volatile intVec_t      rsvd9_8;             //!< Reserved
    volatile intVec_t      ADCINT1;             //!< ADCINT1 interrupt vector
    volatile intVec_t      ADCINT2;             //!< ADCINT2 interrupt vector
    volatile intVec_t      ADCINT3;             //!< ADCINT3 interrupt vector
    volatile intVec_t      ADCINT4;             //!< ADCINT4 interrupt vector
    volatile intVec_t      ADCINT5;             //!< ADCINT5 interrupt vector
    volatile intVec_t      ADCINT6;             //!< ADCINT6 interrupt vector
    volatile intVec_t      ADCINT7;             //!< ADCINT7 interrupt vector
    volatile intVec_t      ADCINT8;             //!< ADCINT8 interrupt vector
    volatile intVec_t      rsvd11_1;            //!< Reserved
    volatile intVec_t      rsvd11_2;            //!< Reserved
    volatile intVec_t      rsvd11_3;            //!< Reserved
    volatile intVec_t      rsvd11_4;            //!< Reserved
    volatile intVec_t      rsvd11_5;            //!< Reserved
    volatile intVec_t      rsvd11_6;            //!< Reserved
    volatile intVec_t      rsvd11_7;            //!< Reserved
    volatile intVec_t      rsvd11_8;            //!< Reserved
    volatile intVec_t      XINT3;               //!< XINT3 interrupt vector
    volatile intVec_t      rsvd12_2;            //!< Reserved
    volatile intVec_t      rsvd12_3;            //!< Reserved
    volatile intVec_t      rsvd12_4;            //!< Reserved
    volatile intVec_t      rsvd12_5;            //!< Reserved
    volatile intVec_t      rsvd12_6;            //!< Reserved
    volatile intVec_t      rsvd12_7;            //!< Reserved
    volatile intVec_t      rsvd12_8;            //!< Reserved
    volatile uint16_t  rsvd13[25200];           //!< Reserved
    volatile uint16_t  XINTnCR[3];              //!< External Interrupt n Control Register
    volatile uint16_t  rsvd14[5];               //!< Reserved
    volatile uint16_t  XINTnCTR[3];             //!< External Interrupt n Counter Register
} PIE_Obj;


//! \brief Defines the peripheral interrupt expansion (PIE) handle
//!
typedef struct PIE_Obj *PIE_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Clears all the interrupts
//! \param[in] pieHandle    The peripheral interrupt expansion (PIE) object handle
void PIE_clearAllInts(PIE_Handle pieHandle);


//! \brief     Clears all the interrupt flags
//! \param[in] pieHandle    The peripheral interrupt expansion (PIE) object handle
void PIE_clearAllFlags(PIE_Handle pieHandle);


//! \brief     Clears an interrupt defined by group number
//! \param[in] pieHandle    The peripheral interrupt expansion (PIE) object handle
//! \param[in] groupNumber  The group number
inline void PIE_clearInt(PIE_Handle pieHandle,const PIE_GroupNumber_e groupNumber)
{
    PIE_Obj *pie = (PIE_Obj *)pieHandle;


    // set the group number
    pie->PIEACK = (1 << groupNumber);

    return;
} // end of PIE_clearInt() function


//! \brief     Disables the peripheral interrupt expansion (PIE)
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_disable(PIE_Handle pieHandle);


//! \brief     Disables all of the interrupts
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_disableAllInts(PIE_Handle pieHandle);

//! \brief     Disables the capture interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_disableCaptureInt(PIE_Handle pieHandle);

//! \brief     Disable a specific PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] group  The PIE group an interrupt belongs to
//! \param[in] intSource  The specific interrupt source to disable
void PIE_disableInt(PIE_Handle pieHandle, const PIE_GroupNumber_e group, const PIE_InterruptSource_e intSource);

//! \brief     Enables the peripheral interrupt expansion (PIE)
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_enable(PIE_Handle pieHandle);

//! \brief     Enables the specified ADC interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] intNumber  The interrupt number
void PIE_enableAdcInt(PIE_Handle pieHandle,const ADC_IntNumber_e intNumber);

//! \brief     Enables the capture interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_enableCaptureInt(PIE_Handle pieHandle);

//! \brief     Enables the prescribed external interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
//! \param[in] intNumber  The interrupt number
void PIE_enableExtInt(PIE_Handle pieHandle,const CPU_ExtIntNumber_e intNumber);

//! \brief     Enable a specific PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] group  The PIE group an interrupt belongs to
//! \param[in] intSource  The specific interrupt source to enable
void PIE_enableInt(PIE_Handle pieHandle, const PIE_GroupNumber_e group, const PIE_InterruptSource_e intSource);

//! \brief     Enables the PWM interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
//! \param[in] pwmNumber  The PWM number
void PIE_enablePwmInt(PIE_Handle pieHandle,const PWM_Number_e pwmNumber);

//! \brief     Enables the PWM Trip Zone interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
//! \param[in] pwmNumber  The PWM number
void PIE_enablePwmTzInt(PIE_Handle pieHandle, const PWM_Number_e pwmNumber);

//! \brief     Enables the Cpu Timer 0 interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
void PIE_enableTimer0Int(PIE_Handle pieHandle);

//! \brief     Gets the external interrupt count value
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
//! \param[in] intNumber  The external interrupt number
//! \return    The count value
uint16_t PIE_getExtIntCount(PIE_Handle pieHandle,const CPU_ExtIntNumber_e intNumber);

//! \brief     Gets PIE interrupt enable values
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] group  The PIE group the flags belong to
uint16_t PIE_getIntEnables(PIE_Handle pieHandle, const PIE_GroupNumber_e group);

//! \brief     Gets PIE interrupt flag values
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] group  The PIE group the flags belong to
uint16_t PIE_getIntFlags(PIE_Handle pieHandle, const PIE_GroupNumber_e group);

//! \brief     Force a specific PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] group  The PIE group an interrupt belongs to
//! \param[in] intSource  The specific interrupt source to force
void PIE_forceInt(PIE_Handle pieHandle, const PIE_GroupNumber_e group, const PIE_InterruptSource_e intSource);


//! \brief     Defines an illegal interrupt service routine - if the program pointer references this function, 
//!            there is an incorrect mapping in the PIE interrupt table
interrupt void PIE_illegalIsr(void);


//! \brief     Initializes the peripheral interrupt expansion (PIE) object handle
//! \param[in] pMemory    A pointer to the memory for the PIE object
//! \param[in] numBytes   The number of bytes allocated for the PIE object, bytes
//! \return    The peripheral interrupt expansion (PIE) object handle
PIE_Handle PIE_init(void *pMemory,const size_t numBytes);

//! \brief     Registers a handler for a PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] groupNumber  The PIE group an interrupt belongs to
//! \param[in] subGroupNumber  The PIE subgroup an interrupt belongs to
//! \param[in] vector  The specific interrupt handler
void PIE_registerPieIntHandler(PIE_Handle pieHandle, 
                           const PIE_GroupNumber_e groupNumber, 
                           const PIE_SubGroupNumber_e subGroupNumber, 
                           const intVec_t vector);


//! \brief     Registers a handler for a PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] systemInt  The system interrupt to register this handler to
//! \param[in] vector  The specific interrupt handler
void PIE_registerSystemIntHandler(PIE_Handle pieHandle, 
                           const PIE_SystemInterrupts_e systemInt, 
                           const intVec_t vector);


#ifdef _DEBUG
//! \brief      Initializes the vector table with Debug interrupt handlers
//! \param[in]  pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_setDebugIntVectorTable(PIE_Handle pieHandle);
#endif //end #ifdef DEBUG

//! \brief      Initializes the vector table with illegal ISR handlers
//! \param[in]  pieHandle  The peripheral interrupt expansion (PIE) object handle
void PIE_setDefaultIntVectorTable(PIE_Handle pieHandle);


//! \brief     Sets the external interrupt polarity
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
//! \param[in] intNumber  The external interrupt number
//! \param[in] polarity   The signal polarity
void PIE_setExtIntPolarity(PIE_Handle pieHandle,
                           const CPU_ExtIntNumber_e intNumber,
                           const PIE_ExtIntPolarity_e polarity);
                           
                           
//! \brief     Unregisters a handler for a PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] groupNumber  The PIE group an interrupt belongs to
//! \param[in] subGroupNumber  The PIE subgroup an interrupt belongs to
void PIE_unregisterPieIntHandler(PIE_Handle pieHandle, 
                           const PIE_GroupNumber_e groupNumber, 
                           const PIE_SubGroupNumber_e subGroupNumber);


//! \brief     Unregisters a handler for a PIE interrupt
//! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
//! \param[in] systemInt  The system interrupt to unregister
void PIE_unregisterSystemIntHandler(PIE_Handle pieHandle, 
                           const PIE_SystemInterrupts_e systemInt);




#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _PIE_H_ definition

