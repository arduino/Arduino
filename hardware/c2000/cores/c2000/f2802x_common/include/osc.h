#ifndef _OSC_H_
#define _OSC_H_

//#############################################################################
//
//! \file   f2802x_common/include/osc.h
//!
//! \brief  Contains public interface to various functions related
//!         to the oscillator (OSC) object 
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
//! \defgroup OSC

//!
//! \ingroup OSC
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the oscillator (OSC) registers
//!
#define  OSC_BASE_ADDR                   (0x00007014)

//! \brief Defines the address of the Fine Trim Slope 1 in OTP
//!
#define OSC_OTP_FINE_TRIM_SLOPE1         (0x003D7E90)

//! \brief Defines the address of the Fine Trim Offset 1 in OTP
//!
#define OSC_OTP_FINE_TRIM_OFFSET1        (0x003D7E93)

//! \brief Defines the address of the Course Trim 1 in OTP
//!
#define OSC_OTP_COURSE_TRIM1             (0x003D7E96)

//! \brief Defines the address of the Fine Trim Slope 1 in OTP
//!
#define OSC_OTP_FINE_TRIM_SLOPE2         (0x003D7E99)

//! \brief Defines the address of the Fine Trim Offset 1 in OTP
//!
#define OSC_OTP_FINE_TRIM_OFFSET2        (0x003D7E9C)

//! \brief Defines the address of the Course Trim 1 in OTP
//!
#define OSC_OTP_COURSE_TRIM2             (0x003D7E9F)

//! \brief Defines the address of the Reference Temp Offset in OTP
//!
#define OSC_OTP_REF_TEMP_OFFSET          (0x003D7EA2)

//! \brief Defines the location of the COARSETRIM bits in the INTOSCnTRIM register
//!
#define  OSC_INTOSCnTRIM_COARSE_BITS     (255 << 0)

//! \brief Defines the location of the FINETRIM bits in the INTOSCnTRIM register
//!
#define  OSC_INTOSCnTRIM_FINE_BITS       (63 << 9)


#define OSC_POSTRIM 32
#define OSC_POSTRIM_OFF FP_SCALE*OSC_POSTRIM

#define FP_SCALE 32768       // Scale factor for Q15 fixed point numbers (2^15)
#define FP_ROUND FP_SCALE/2  // Quantity added to Q15 numbers before converting
                           // to integer to round the number


// **************************************************************************
// the typedefs


//! \brief Enumeration to define the oscillator (OSC) source
//!
typedef enum
{
    OSC_Src_Internal=(0 << 0),  //!< Denotes an internal oscillator
    OSC_Src_External=(1 << 0)   //!< Denotes an external oscillator
} OSC_Src_e;


//! \brief Enumeration to define the oscillator (OSC) 2 source
//!
typedef enum
{
    OSC_Osc2Src_Internal=(0 << 1),  //!< Denotes an internal oscillator source for oscillator 2
    OSC_Osc2Src_External=(1 << 1)   //!< Denotes an external oscillator source for oscillator 2
} OSC_Osc2Src_e;


//! \brief Enumeration to define the oscillator (OSC) number
//!
typedef enum
{
    OSC_Number_1=1,  //!< Denotes oscillator number 1
    OSC_Number_2     //!< Denotes oscillator number 2
} OSC_Number_e;


//! \brief Defines the oscillator (OSC) object
//!
typedef struct _OSC_Obj_
{
    volatile uint16_t   INTOSC1TRIM;  //!< Internal Oscillator 1 Trim Register
    volatile uint16_t   rsvd_1;       //!< Reserved
    volatile uint16_t   INTOSC2TRIM;  //!< Internal Oscillator 2 Trim Register
} OSC_Obj;


//! \brief Defines the oscillator (OSC) handle
//!
typedef struct OSC_Obj *OSC_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//ADC reading of temperature sensor at reference temperature for compensation
    #define getRefTempOffset() (*(int16_t (*)(void))0x3D7EA2)()

//! \brief     Initializes the oscillator (OSC) handle
//! \param[in] pMemory     A pointer to the base address of the FLASH registers
//! \param[in] numBytes    The number of bytes allocated for the FLASH object, bytes
//! \return    The flash (FLASH) object handle
OSC_Handle OSC_init(void *pMemory,const size_t numBytes);

//! \brief     Gets the fine trim offset for oscillator 1
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The fine trim offset for oscillator 1
inline int16_t OSC_getFineTrimSlope1(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_FINE_TRIM_SLOPE1)());
}

//! \brief     Gets the fine trim offset for oscillator 2
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The fine trim offset for oscillator 2
inline int16_t OSC_getFineTrimSlope2(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_FINE_TRIM_SLOPE2)());
}

//! \brief     Gets the fine trim offset for oscillator 1
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The fine trim offset for oscillator 1
inline int16_t OSC_getFineTrimOffset1(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_FINE_TRIM_OFFSET1)());
}

//! \brief     Gets the fine trim offset for oscillator 2
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The fine trim offset for oscillator 2
inline int16_t OSC_getFineTrimOffset2(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_FINE_TRIM_OFFSET2)());
}


//! \brief     Gets the fine trim offset for oscillator 1
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The fine trim offset for oscillator 1
inline int16_t OSC_getCourseTrim1(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_COURSE_TRIM1)());
}

//! \brief     Gets the fine trim offset for oscillator 2
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The fine trim offset for oscillator 2
inline int16_t OSC_getCourseTrim2(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_COURSE_TRIM2)());
}

//! \brief     Gets the reference temperature offset
//! \param[in] clkHandle  The oscillator (OSC) object handle
//! \return    The reference temperature offset
inline int16_t OSC_getRefTempOffset(OSC_Handle oscHandle)
{
    return ((*(int16_t (*)(void))OSC_OTP_REF_TEMP_OFFSET)());
}

void OSC_runCompensation(OSC_Handle oscHandle, const OSC_Number_e oscNumber, int16_t sample);

//! \brief     Sets the coarse trim value for a specified oscillator
//! \param[in] oscHandle  The oscillator (OSC) object handle
//! \param[in] oscNumber  The oscillator number
//! \param[in] trimValue  The coarse trim value
void OSC_setCoarseTrim(OSC_Handle oscHandle,
                       const OSC_Number_e oscNumber,
                       const uint8_t trimValue);


//! \brief     Sets the fine trim value for a specified oscillator
//! \param[in] oscHandle  The oscillator (OSC) object handle
//! \param[in] oscNumber  The oscillator number
//! \param[in] trimValue  The fine trim value
void OSC_setFineTrim(OSC_Handle oscHandle,
                     const OSC_Number_e oscNumber,
                     const uint8_t trimValue);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _OSC_H_ definition

