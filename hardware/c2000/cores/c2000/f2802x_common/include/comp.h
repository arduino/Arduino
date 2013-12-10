#ifndef _COMP_H_
#define _COMP_H_

//#############################################################################
//
//! \file   f2802x_common/include/comp.h
//!
//! \brief  Contains public interface to various functions related to the 
//!         comparator (COMP) object
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



//!
//! \defgroup COMP

//!
//! \ingroup COMP
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the comparator (COMP) registers
//!
#define COMP1_BASE_ADDR              (0x00006400)

//! \brief Defines the base address of the comparator (COMP) registers
//!
#define COMP2_BASE_ADDR              (0x00006420)


//! \brief Defines the location of the COMPDACE bits in the COMPCTL register
//!
#define COMP_COMPCTL_COMPDACE_BITS          (1 << 0)

//! \brief Defines the location of the COMPSOURCE bits in the COMPCTL register
//!
#define COMP_COMPCTL_COMPSOURCE_BITS        (1 << 1)

//! \brief Defines the location of the CMPINV bits in the COMPCTL register
//!
#define COMP_COMPCTL_CMPINV_BITS            (1 << 2)

//! \brief Defines the location of the QUALSEL bits in the COMPCTL register
//!
#define COMP_COMPCTL_QUALSEL_BITS           (31 << 3)

//! \brief Defines the location of the SYNCSEL bits in the COMPCTL register
//!
#define COMP_COMPCTL_SYNCSEL_BITS           (1 << 8)
    

//! \brief Defines the location of the COMPSTS bits in the COMPSTS register
//!
#define COMP_COMPSTS_COMPSTS_BITS           (1 << 0)
    

//! \brief Defines the location of the DACSOURCE bits in the DACCTL register
//!
#define COMP_DACCTL_DACSOURCE_BITS          (1 << 0)

//! \brief Defines the location of the RAMPSOURCE bits in the DACCTL register
//!
#define COMP_DACCTL_RAMPSOURCE_BITS         (15 << 1)

//! \brief Defines the location of the FREE:SOFT bits in the DACCTL register
//!
#define COMP_DACCTL_FREESOFT_BITS           (3 << 14)




// **************************************************************************
// the typedefs

//! \brief Enumeration to define the comparator (COMP) output qualification
//!
typedef enum
{
    COMP_QualSel_Sync = (0 << 3),       //!< Syncronize comparator output
    COMP_QualSel_Qual_2 = (1 << 3),     //!< Qualify comparator output with 2 cycles
    COMP_QualSel_Qual_3 = (2 << 3),     //!< Qualify comparator output with 3 cycles
    COMP_QualSel_Qual_4 = (3 << 3),     //!< Qualify comparator output with 4 cycles
    COMP_QualSel_Qual_5 = (3 << 3),     //!< Qualify comparator output with 5 cycles
    COMP_QualSel_Qual_6 = (4 << 3),     //!< Qualify comparator output with 6 cycles
    COMP_QualSel_Qual_7 = (5 << 3),     //!< Qualify comparator output with 7 cycles
    COMP_QualSel_Qual_8 = (6 << 3),     //!< Qualify comparator output with 8 cycles
    COMP_QualSel_Qual_9 = (7 << 3),     //!< Qualify comparator output with 9 cycles
    COMP_QualSel_Qual_10 = (8 << 3),    //!< Qualify comparator output with 10 cycles
    COMP_QualSel_Qual_11 = (9 << 3),    //!< Qualify comparator output with 11 cycles
    COMP_QualSel_Qual_12 = (10 << 3),   //!< Qualify comparator output with 12 cycles
    COMP_QualSel_Qual_13 = (11 << 3),   //!< Qualify comparator output with 13 cycles
    COMP_QualSel_Qual_14 = (12 << 3),   //!< Qualify comparator output with 14 cycles
    COMP_QualSel_Qual_15 = (13 << 3),   //!< Qualify comparator output with 15 cycles
    COMP_QualSel_Qual_16 = (14 << 3),   //!< Qualify comparator output with 16 cycles
    COMP_QualSel_Qual_17 = (15 << 3),   //!< Qualify comparator output with 17 cycles
    COMP_QualSel_Qual_18 = (16 << 3),   //!< Qualify comparator output with 18 cycles
    COMP_QualSel_Qual_19 = (17 << 3),   //!< Qualify comparator output with 19 cycles
    COMP_QualSel_Qual_20 = (18 << 3),   //!< Qualify comparator output with 20 cycles
    COMP_QualSel_Qual_21 = (19 << 3),   //!< Qualify comparator output with 21 cycles
    COMP_QualSel_Qual_22 = (20 << 3),   //!< Qualify comparator output with 22 cycles
    COMP_QualSel_Qual_23 = (21 << 3),   //!< Qualify comparator output with 23 cycles
    COMP_QualSel_Qual_24 = (22 << 3),   //!< Qualify comparator output with 24 cycles
    COMP_QualSel_Qual_25 = (23 << 3),   //!< Qualify comparator output with 25 cycles
    COMP_QualSel_Qual_26 = (24 << 3),   //!< Qualify comparator output with 26 cycles
    COMP_QualSel_Qual_27 = (25 << 3),   //!< Qualify comparator output with 27 cycles
    COMP_QualSel_Qual_28 = (26 << 3),   //!< Qualify comparator output with 28 cycles
    COMP_QualSel_Qual_29 = (27 << 3),   //!< Qualify comparator output with 29 cycles
    COMP_QualSel_Qual_30 = (28 << 3),   //!< Qualify comparator output with 30 cycles
    COMP_QualSel_Qual_31 = (29 << 3),   //!< Qualify comparator output with 31 cycles
    COMP_QualSel_Qual_32 = (30 << 3),   //!< Qualify comparator output with 32 cycles
    COMP_QualSel_Qual_33 = (31 << 3)    //!< Qualify comparator output with 33 cycles
} COMP_QualSel_e;


//! \brief Enumeration to define the comparator (COMP) ramp generator sync source
//!
typedef enum
{
    COMP_RampSyncSrc_PWMSYNC1 = (0 << 1),       //!< PWMSync1 used as Ramp Sync
    COMP_RampSyncSrc_PWMSYNC2 = (1 << 1),       //!< PWMSync2 used as Ramp Sync
    COMP_RampSyncSrc_PWMSYNC3 = (2 << 1),       //!< PWMSync3 used as Ramp Sync
    COMP_RampSyncSrc_PWMSYNC4 = (3 << 1)        //!< PWMSync4 used as Ramp Sync
} COMP_RampSyncSrc_e;


//! \brief Defines the comparator (COMP) object
//!
typedef struct _COMP_Obj_
{
    volatile uint16_t    COMPCTL;            //!< COMP Control Register
    volatile uint16_t    rsvd_1;             //!< Reserved
    volatile uint16_t    COMPSTS;            //!< COMP Status Register
    volatile uint16_t    rsvd_2;             //!< Reserved
    volatile uint16_t    DACCTL;             //!< DAC Control Register
    volatile uint16_t    rsvd_3;             //!< Reserved
    volatile uint16_t    DACVAL;             //!< DAC Value Register
    volatile uint16_t    rsvd_4;             //!< Reserved
    volatile uint16_t    RAMPMAXREF_ACTIVE;  //!< Ramp Generator Maxmimum Reference (Active)
    volatile uint16_t    rsvd_5;             //!< Reserved
    volatile uint16_t    RAMPMAXREF_SHADOW;  //!< Ramp Generator Maximum Reference (Shadow)
    volatile uint16_t    rsvd_6;             //!< Reserved
    volatile uint16_t    RAMPDECVAL_ACTIVE;  //!< Ramp Generator Decrement Value (Active)
    volatile uint16_t    rsvd_7;             //!< Reserved
    volatile uint16_t    RAMPDECVAL_SHADOW;  //!< Ramp Generator Decrement Value (Shadow)
    volatile uint16_t    rsvd_8;             //!< Reserved
    volatile uint16_t    RAMPSTS;            //!< Ramp Generator Status
} COMP_Obj;


//! \brief Defines the comparator (COMP) handle
//!
typedef struct COMP_Obj  *COMP_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Disables the comparator (COMP)
//! \param[in] compHandle  The comparator (COMP) object handle
void COMP_disable(COMP_Handle compHandle);


//! \brief     Disables the DAC
//! \param[in] compHandle  The comparator (COMP) object handle
void COMP_disableDac(COMP_Handle compHandle);


//! \brief     Enables the comparator (COMP)
//! \param[in] compHandle  The comparator (COMP) object handle
void COMP_enable(COMP_Handle compHandle);


//! \brief     Enables the DAC
//! \param[in] compHandle  The comparator (COMP) object handle
void COMP_enableDac(COMP_Handle compHandle);


//! \brief     Initializes the comparator (COMP) object handle
//! \param[in] pMemory   A pointer to the base address of the COMP registers
//! \param[in] numBytes  The number of bytes allocated for the COMP object, bytes
//! \return    The comparator (COMP) object handle
COMP_Handle COMP_init(void *pMemory, const size_t numBytes);


//! \brief     Sets the DAC's value
//! \param[in] compHandle   The comparator (COMP) object handle
//! \param[in] dacValue     The DAC's value
inline void COMP_setDacValue(COMP_Handle compHandle, uint16_t dacValue)
{
    COMP_Obj *comp = (COMP_Obj *)compHandle;
        
    comp->DACVAL = dacValue;
    
    return;
}


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif // end of _COMP_H_ definition

