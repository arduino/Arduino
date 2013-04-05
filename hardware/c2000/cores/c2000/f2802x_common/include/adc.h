#ifndef _ADC_H_
#define _ADC_H_

//#############################################################################
//
//! \file   f2802x_common/include/adc.h
//!
//! \brief  Contains public interface to various functions related to the 
//!         analog-to-digital converter (ADC) object
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
//! \defgroup ADC

//!
//! \ingroup ADC
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the analog-to-digital converter (ADC) registers
//!
#define ADC_BASE_ADDR              (0x00000B00)


//! \brief Defines the ADC delay for part of the ADC initialization
//!
#define ADC_DELAY_usec                 10000L


//! \brief Integer value bias corresponding to voltage 1.65V bias of input data on 3.3V, 12 bit ADC
//!
#define ADC_dataBias                    0x800 


//! \brief Defines the location of the TEMPCONV bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_TEMPCONV_BITS          (1 << 0)

//! \brief Defines the location of the VREFLOCONV bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_VREFLOCONV_BITS        (1 << 1)

//! \brief Defines the location of the INTPULSEPOS bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_INTPULSEPOS_BITS       (1 << 2)

//! \brief Defines the location of the ADCREFSEL bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCREFSEL_BITS         (1 << 3)

//! \brief Defines the location of the ADCREFPWD bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCREFPWD_BITS         (1 << 5)

//! \brief Defines the location of the ADCBGPWD bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCBGPWD_BITS          (1 << 6)

//! \brief Defines the location of the ADCPWDN bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCPWDN_BITS           (1 << 7)

//! \brief Defines the location of the ADCBSYCHAN bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCBSYCHAN_BITS        (31 << 8)

//! \brief Defines the location of the ADCBSY bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCBSY_BITS            (1 << 13)

//! \brief Defines the location of the ADCENABLE bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_ADCENABLE_BITS         (1 << 14)

//! \brief Defines the location of the RESET bits in the ADCTL1 register
//!
#define ADC_ADCCTL1_RESET_BITS             (1 << 15)


//! \brief Defines the number of bits per INTSELxNy register
//!
#define ADC_INTSELxNy_NUMBITS_PER_REG        8

//! \brief Defines the log2() of the number of bits per INTSELxNy register
//!
#define ADC_INTSELxNy_LOG2_NUMBITS_PER_REG   3

//! \brief Defines the location of the INTSEL bits in the INTSELxNy register
//!
#define ADC_INTSELxNy_INTSEL_BITS          (31 << 0)

//! \brief Defines the location of the INTE bits in the INTSELxNy register
//!
#define ADC_INTSELxNy_INTE_BITS            (1 << 5)

//! \brief Defines the location of the INTCONT bits in the INTSELxNy register
//!
#define ADC_INTSELxNy_INTCONT_BITS         (1 << 6)


//! \brief Defines the location of the ACQPS bits in the ADCSOCxCTL register
//!
#define ADC_ADCSOCxCTL_ACQPS_BITS          (63 << 0)

//! \brief Defines the location of the CHSEL bits in the ADCSOCxCTL register
//!
#define ADC_ADCSOCxCTL_CHSEL_BITS          (15 << 6)

//! \brief Defines the location of the TRIGSEL bits in the ADCSOCxCTL register
//!
#define ADC_ADCSOCxCTL_TRIGSEL_BITS        (31 << 11)



//! \brief Defines the location of the SIMULEN0 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN0_BITS    (1 << 0)

//! \brief Defines the location of the SIMULEN2 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN2_BITS    (1 << 1)

//! \brief Defines the location of the SIMULEN4 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN4_BITS    (1 << 2)

//! \brief Defines the location of the SIMULEN6 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN6_BITS    (1 << 3)

//! \brief Defines the location of the SIMULEN8 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN8_BITS    (1 << 4)

//! \brief Defines the location of the SIMULEN10 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN10_BITS   (1 << 5)

//! \brief Defines the location of the SIMULEN12 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN12_BITS   (1 << 6)

//! \brief Defines the location of the SIMULEN14 bits in the ADCSAMPLEMODE register
//!
#define ADC_ADCSAMPLEMODE_SIMULEN14_BITS   (1 << 7)


//! \brief Define for the channel separate flag
//!
#define ADC_ADCSAMPLEMODE_SEPARATE_FLAG     0x100

// Useful definitions
#define ADC_FP_SCALE 32768       //Scale factor for Q15 fixed point numbers (2^15)
#define ADC_FP_ROUND ADC_FP_SCALE/2  //Added to Q15 numbers before converting to integer to round the number

// Amount to add to Q15 fixed point numbers to shift from Celsius to Kelvin
// (Converting guarantees number is positive, which makes rounding more efficient)
#define ADC_KELVIN 273
#define ADC_KELVIN_OFF (ADC_FP_SCALE * ADC_KELVIN)

// The folloing pointers to function calls are:
//Slope of temperature sensor (deg. C / ADC code).  Stored in fixed point Q15 format.
#define ADC_getTempSlope() (*(int (*)(void))0x3D7E80)()
//ADC code corresponding to temperature sensor output at 0 deg. C
#define ADC_getTempOffset() (*(int (*)(void))0x3D7E83)()



// **************************************************************************
// the typedefs

//! \brief Enumeration to define the analog-to-digital converter (ADC) interrupt number
//!
typedef enum
{
    ADC_IntNumber_1=0,   //!< Denotes ADCINT1
    ADC_IntNumber_2,     //!< Denotes ADCINT2
    ADC_IntNumber_3,     //!< Denotes ADCINT3
    ADC_IntNumber_4,     //!< Denotes ADCINT4
    ADC_IntNumber_5,     //!< Denotes ADCINT5
    ADC_IntNumber_6,     //!< Denotes ADCINT6
    ADC_IntNumber_7,     //!< Denotes ADCINT7
    ADC_IntNumber_8,     //!< Denotes ADCINT8
    ADC_IntNumber_9      //!< Denotes ADCINT9
} ADC_IntNumber_e;


//! \brief Enumeration to define the analog-to-digital converter (ADC) interrupt mode
//!
typedef enum
{
    ADC_IntMode_ClearFlag=0,     //!< Denotes that a new interrupt with not be generated until the interrupt flag is cleared
    ADC_IntMode_EOC              //!< Denotes that a new interrupt with be generated on the next end of conversion (EOC)
} ADC_IntMode_e;


//! \brief Enumeration to define the analog-to-digital converter (ADC) interrupt pulse generation mode
//!
typedef enum
{
    ADC_IntPulseGenMode_During=(0 << 2),     //!< Denotes that interrupt pulse generation occurs when the ADC begins conversion
    ADC_IntPulseGenMode_Prior=(1 << 2)       //!< Denotes that interrupt pulse generation occurs 1 cycle prior to the ADC result latching
} ADC_IntPulseGenMode_e;


//! \brief Enumeration to define the analog-to-digital converter (ADC) interrupt source
//!
typedef enum
{
    ADC_IntSrc_EOC0=(0 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC0
    ADC_IntSrc_EOC1=(1 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC1
    ADC_IntSrc_EOC2=(2 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC2
    ADC_IntSrc_EOC3=(3 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC3
    ADC_IntSrc_EOC4=(4 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC4
    ADC_IntSrc_EOC5=(5 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC5
    ADC_IntSrc_EOC6=(6 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC6
    ADC_IntSrc_EOC7=(7 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC7
    ADC_IntSrc_EOC8=(8 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC8
    ADC_IntSrc_EOC9=(9 << 0),     //!< Denotes that interrupt source is the end of conversion for SOC9
    ADC_IntSrc_EOC10=(10 << 0),   //!< Denotes that interrupt source is the end of conversion for SOC10
    ADC_IntSrc_EOC11=(11 << 0),   //!< Denotes that interrupt source is the end of conversion for SOC11
    ADC_IntSrc_EOC12=(12 << 0),   //!< Denotes that interrupt source is the end of conversion for SOC12
    ADC_IntSrc_EOC13=(13 << 0),   //!< Denotes that interrupt source is the end of conversion for SOC13
    ADC_IntSrc_EOC14=(14 << 0),   //!< Denotes that interrupt source is the end of conversion for SOC14 
    ADC_IntSrc_EOC15=(15 << 0)    //!< Denotes that interrupt source is the end of conversion for SOC15
} ADC_IntSrc_e;


//! \brief Enumeration to define the analog-to-digital converter (ADC) result number
//!
typedef enum
{
    ADC_ResultNumber_0=0,     //!< Denotes ADCRESULT0
    ADC_ResultNumber_1,       //!< Denotes ADCRESULT1
    ADC_ResultNumber_2,       //!< Denotes ADCRESULT2
    ADC_ResultNumber_3,       //!< Denotes ADCRESULT3
    ADC_ResultNumber_4,       //!< Denotes ADCRESULT4
    ADC_ResultNumber_5,       //!< Denotes ADCRESULT5
    ADC_ResultNumber_6,       //!< Denotes ADCRESULT6
    ADC_ResultNumber_7,       //!< Denotes ADCRESULT7
    ADC_ResultNumber_8,       //!< Denotes ADCRESULT8
    ADC_ResultNumber_9,       //!< Denotes ADCRESULT9
    ADC_ResultNumber_10,      //!< Denotes ADCRESULT10
    ADC_ResultNumber_11,      //!< Denotes ADCRESULT11
    ADC_ResultNumber_12,      //!< Denotes ADCRESULT12
    ADC_ResultNumber_13,      //!< Denotes ADCRESULT13
    ADC_ResultNumber_14,      //!< Denotes ADCRESULT14
    ADC_ResultNumber_15       //!< Denotes ADCRESULT15
} ADC_ResultNumber_e;


//! \brief Enumeration to define the analog-to-digital converter (ADC) sample modes
//!
typedef enum
{
    ADC_SampleMode_SOC0_and_SOC1_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 0),     //!< Denotes SOC0 and SOC1 are sampled separately
    ADC_SampleMode_SOC2_and_SOC3_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 1),     //!< Denotes SOC2 and SOC3 are sampled separately
    ADC_SampleMode_SOC4_and_SOC5_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 2),     //!< Denotes SOC4 and SOC5 are sampled separately
    ADC_SampleMode_SOC6_and_SOC7_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 3),     //!< Denotes SOC6 and SOC7 are sampled separately
    ADC_SampleMode_SOC8_and_SOC9_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 4),     //!< Denotes SOC8 and SOC9 are sampled separately
    ADC_SampleMode_SOC10_and_SOC11_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 5),   //!< Denotes SOC10 and SOC11 are sampled separately
    ADC_SampleMode_SOC12_and_SOC13_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 6),   //!< Denotes SOC12 and SOC13 are sampled separately
    ADC_SampleMode_SOC14_and_SOC15_Separate=ADC_ADCSAMPLEMODE_SEPARATE_FLAG + (1 << 7),   //!< Denotes SOC14 and SOC15 are sampled separately
    ADC_SampleMode_SOC0_and_SOC1_Together=(1 << 0),                                       //!< Denotes SOC0 and SOC1 are sampled together
    ADC_SampleMode_SOC2_and_SOC3_Together=(1 << 1),                                       //!< Denotes SOC2 and SOC3 are sampled together
    ADC_SampleMode_SOC4_and_SOC5_Together=(1 << 2),                                       //!< Denotes SOC4 and SOC5 are sampled together
    ADC_SampleMode_SOC6_and_SOC7_Together=(1 << 3),                                       //!< Denotes SOC6 and SOC7 are sampled together
    ADC_SampleMode_SOC8_and_SOC9_Together=(1 << 4),                                       //!< Denotes SOC8 and SOC9 are sampled together
    ADC_SampleMode_SOC10_and_SOC11_Together=(1 << 5),                                     //!< Denotes SOC10 and SOC11 are sampled together
    ADC_SampleMode_SOC12_and_SOC13_Together=(1 << 6),                                     //!< Denotes SOC12 and SOC13 are sampled together
    ADC_SampleMode_SOC14_and_SOC15_Together=(1 << 7)                                      //!< Denotes SOC14 and SOC15 are sampled together
} ADC_SampleMode_e;


//! \brief Enumeration to define the start of conversion (SOC) channel numbers
//!
typedef enum
{
    ADC_SocChanNumber_A0=(0 << 6),                                     //!< Denotes SOC channel number A0
    ADC_SocChanNumber_A1=(1 << 6),                                     //!< Denotes SOC channel number A1
    ADC_SocChanNumber_A2=(2 << 6),                                     //!< Denotes SOC channel number A2
    ADC_SocChanNumber_A3=(3 << 6),                                     //!< Denotes SOC channel number A3
    ADC_SocChanNumber_A4=(4 << 6),                                     //!< Denotes SOC channel number A4
    ADC_SocChanNumber_A5=(5 << 6),                                     //!< Denotes SOC channel number A5
    ADC_SocChanNumber_A6=(6 << 6),                                     //!< Denotes SOC channel number A6
    ADC_SocChanNumber_A7=(7 << 6),                                     //!< Denotes SOC channel number A7
    ADC_SocChanNumber_B0=(8 << 6),                                     //!< Denotes SOC channel number B0
    ADC_SocChanNumber_B1=(9 << 6),                                     //!< Denotes SOC channel number B1
    ADC_SocChanNumber_B2=(10 << 6),                                    //!< Denotes SOC channel number B2
    ADC_SocChanNumber_B3=(11 << 6),                                    //!< Denotes SOC channel number B3
    ADC_SocChanNumber_B4=(12 << 6),                                    //!< Denotes SOC channel number B4
    ADC_SocChanNumber_B5=(13 << 6),                                    //!< Denotes SOC channel number B5
    ADC_SocChanNumber_B6=(14 << 6),                                    //!< Denotes SOC channel number B6
    ADC_SocChanNumber_B7=(15 << 6),                                    //!< Denotes SOC channel number B7
    ADC_SocChanNumber_A0_and_B0_Together=(0 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A1_and_B1_Together=(1 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A2_and_B2_Together=(2 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A3_and_B3_Together=(3 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A4_and_B4_Together=(4 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A5_and_B5_Together=(5 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A6_and_B6_Together=(6 << 6),                     //!< Denotes SOC channel number A0 and B0 together
    ADC_SocChanNumber_A7_and_B7_Together=(7 << 6)                      //!< Denotes SOC channel number A0 and B0 together
} ADC_SocChanNumber_e;


//! \brief Enumeration to define the start of conversion (SOC) numbers
//!
typedef enum
{
    ADC_SocNumber_0=0,                     //!< Denotes SOC0
    ADC_SocNumber_1,                       //!< Denotes SOC1
    ADC_SocNumber_2,                       //!< Denotes SOC2
    ADC_SocNumber_3,                       //!< Denotes SOC3
    ADC_SocNumber_4,                       //!< Denotes SOC4
    ADC_SocNumber_5,                       //!< Denotes SOC5
    ADC_SocNumber_6,                       //!< Denotes SOC6
    ADC_SocNumber_7,                       //!< Denotes SOC7
    ADC_SocNumber_8,                       //!< Denotes SOC8
    ADC_SocNumber_9,                       //!< Denotes SOC9
    ADC_SocNumber_10,                      //!< Denotes SOC10
    ADC_SocNumber_11,                      //!< Denotes SOC11
    ADC_SocNumber_12,                      //!< Denotes SOC12
    ADC_SocNumber_13,                      //!< Denotes SOC13
    ADC_SocNumber_14,                      //!< Denotes SOC14
    ADC_SocNumber_15                       //!< Denotes SOC15
} ADC_SocNumber_e;


//! \brief Enumeration to define the start of conversion (SOC) sample delays
//!
typedef enum
{
    ADC_SocSampleWindow_7_cycles=6,         //!< Denotes an SOC sample window of 7 cycles
    ADC_SocSampleWindow_8_cycles,           //!< Denotes an SOC sample window of 8 cycles
    ADC_SocSampleWindow_9_cycles,           //!< Denotes an SOC sample window of 9 cycles
    ADC_SocSampleWindow_10_cycles,          //!< Denotes an SOC sample window of 10 cycles
    ADC_SocSampleWindow_11_cycles,          //!< Denotes an SOC sample window of 11 cycles
    ADC_SocSampleWindow_12_cycles,          //!< Denotes an SOC sample window of 12 cycles
    ADC_SocSampleWindow_13_cycles,          //!< Denotes an SOC sample window of 13 cycles
    ADC_SocSampleWindow_14_cycles,          //!< Denotes an SOC sample window of 14 cycles
    ADC_SocSampleWindow_15_cycles,          //!< Denotes an SOC sample window of 15 cycles
    ADC_SocSampleWindow_16_cycles,          //!< Denotes an SOC sample window of 16 cycles
    ADC_SocSampleWindow_17_cycles,          //!< Denotes an SOC sample window of 17 cycles
    ADC_SocSampleWindow_18_cycles,          //!< Denotes an SOC sample window of 18 cycles
    ADC_SocSampleWindow_19_cycles,          //!< Denotes an SOC sample window of 19 cycles
    ADC_SocSampleWindow_20_cycles,          //!< Denotes an SOC sample window of 20 cycles
    ADC_SocSampleWindow_21_cycles,          //!< Denotes an SOC sample window of 21 cycles
    ADC_SocSampleWindow_22_cycles,          //!< Denotes an SOC sample window of 22 cycles
    ADC_SocSampleWindow_23_cycles,          //!< Denotes an SOC sample window of 23 cycles
    ADC_SocSampleWindow_24_cycles,          //!< Denotes an SOC sample window of 24 cycles
    ADC_SocSampleWindow_25_cycles,          //!< Denotes an SOC sample window of 25 cycles
    ADC_SocSampleWindow_26_cycles,          //!< Denotes an SOC sample window of 26 cycles
    ADC_SocSampleWindow_27_cycles,          //!< Denotes an SOC sample window of 27 cycles
    ADC_SocSampleWindow_28_cycles,          //!< Denotes an SOC sample window of 28 cycles
    ADC_SocSampleWindow_29_cycles,          //!< Denotes an SOC sample window of 29 cycles
    ADC_SocSampleWindow_30_cycles,          //!< Denotes an SOC sample window of 30 cycles
    ADC_SocSampleWindow_31_cycles,          //!< Denotes an SOC sample window of 31 cycles
    ADC_SocSampleWindow_32_cycles,          //!< Denotes an SOC sample window of 32 cycles
    ADC_SocSampleWindow_33_cycles,          //!< Denotes an SOC sample window of 33 cycles
    ADC_SocSampleWindow_34_cycles,          //!< Denotes an SOC sample window of 34 cycles
    ADC_SocSampleWindow_35_cycles,          //!< Denotes an SOC sample window of 35 cycles
    ADC_SocSampleWindow_36_cycles,          //!< Denotes an SOC sample window of 36 cycles
    ADC_SocSampleWindow_37_cycles,          //!< Denotes an SOC sample window of 37 cycles
    ADC_SocSampleWindow_38_cycles,          //!< Denotes an SOC sample window of 38 cycles
    ADC_SocSampleWindow_39_cycles,          //!< Denotes an SOC sample window of 39 cycles
    ADC_SocSampleWindow_40_cycles,          //!< Denotes an SOC sample window of 40 cycles
    ADC_SocSampleWindow_41_cycles,          //!< Denotes an SOC sample window of 41 cycles
    ADC_SocSampleWindow_42_cycles,          //!< Denotes an SOC sample window of 42 cycles
    ADC_SocSampleWindow_43_cycles,          //!< Denotes an SOC sample window of 43 cycles
    ADC_SocSampleWindow_44_cycles,          //!< Denotes an SOC sample window of 44 cycles
    ADC_SocSampleWindow_45_cycles,          //!< Denotes an SOC sample window of 45 cycles
    ADC_SocSampleWindow_46_cycles,          //!< Denotes an SOC sample window of 46 cycles
    ADC_SocSampleWindow_47_cycles,          //!< Denotes an SOC sample window of 47 cycles
    ADC_SocSampleWindow_48_cycles,          //!< Denotes an SOC sample window of 48 cycles
    ADC_SocSampleWindow_49_cycles,          //!< Denotes an SOC sample window of 49 cycles
    ADC_SocSampleWindow_50_cycles,          //!< Denotes an SOC sample window of 50 cycles
    ADC_SocSampleWindow_51_cycles,          //!< Denotes an SOC sample window of 51 cycles
    ADC_SocSampleWindow_52_cycles,          //!< Denotes an SOC sample window of 52 cycles
    ADC_SocSampleWindow_53_cycles,          //!< Denotes an SOC sample window of 53 cycles
    ADC_SocSampleWindow_54_cycles,          //!< Denotes an SOC sample window of 54 cycles
    ADC_SocSampleWindow_55_cycles,          //!< Denotes an SOC sample window of 55 cycles
    ADC_SocSampleWindow_56_cycles,          //!< Denotes an SOC sample window of 56 cycles
    ADC_SocSampleWindow_57_cycles,          //!< Denotes an SOC sample window of 57 cycles
    ADC_SocSampleWindow_58_cycles,          //!< Denotes an SOC sample window of 58 cycles
    ADC_SocSampleWindow_59_cycles,          //!< Denotes an SOC sample window of 59 cycles
    ADC_SocSampleWindow_60_cycles,          //!< Denotes an SOC sample window of 60 cycles
    ADC_SocSampleWindow_61_cycles,          //!< Denotes an SOC sample window of 61 cycles
    ADC_SocSampleWindow_62_cycles,          //!< Denotes an SOC sample window of 62 cycles
    ADC_SocSampleWindow_63_cycles,          //!< Denotes an SOC sample window of 63 cycles
    ADC_SocSampleWindow_64_cycles           //!< Denotes an SOC sample window of 64 cycles
} ADC_SocSampleWindow_e;


//! \brief Enumeration to define the start of conversion (SOC) trigger source
//!
typedef enum
{
    ADC_SocTrigSrc_Sw=(0 << 11),               //!< Denotes a software trigger source for the SOC flag
    ADC_SocTrigSrc_CpuTimer_0=(1 << 11),       //!< Denotes a CPUTIMER0 trigger source for the SOC flag
    ADC_SocTrigSrc_CpuTimer_1=(2 << 11),       //!< Denotes a CPUTIMER1 trigger source for the SOC flag
    ADC_SocTrigSrc_CpuTimer_2=(3 << 11),       //!< Denotes a CPUTIMER2 trigger source for the SOC flag
    ADC_SocTrigSrc_XINT2_XINT2SOC=(4 << 11),   //!< Denotes a XINT2, XINT2SOC trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM1_ADCSOCA=(5 << 11),    //!< Denotes a EPWM1, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM1_ADCSOCB=(6 << 11),    //!< Denotes a EPWM1, ADCSOCB trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM2_ADCSOCA=(7 << 11),    //!< Denotes a EPWM2, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM2_ADCSOCB=(8 << 11),    //!< Denotes a EPWM2, ADCSOCB trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM3_ADCSOCA=(9 << 11),    //!< Denotes a EPWM3, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM3_ADCSOCB=(10 << 11),   //!< Denotes a EPWM3, ADCSOCB trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM4_ADCSOCA=(11 << 11),   //!< Denotes a EPWM4, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM4_ADCSOCB=(12 << 11),   //!< Denotes a EPWM4, ADCSOCB trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM5_ADCSOCA=(13 << 11),   //!< Denotes a EPWM5, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM5_ADCSOCB=(14 << 11),   //!< Denotes a EPWM5, ADCSOCB trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM6_ADCSOCA=(15 << 11),   //!< Denotes a EPWM6, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM6_ADCSOCB=(16 << 11),   //!< Denotes a EPWM7, ADCSOCB trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM7_ADCSOCA=(17 << 11),   //!< Denotes a EPWM7, ADCSOCA trigger source for the SOC flag
    ADC_SocTrigSrc_EPWM7_ADCSOCB=(18 << 11)    //!< Denotes a EPWM7, ADCSOCB trigger source for the SOC flag
} ADC_SocTrigSrc_e;


//! \brief Enumeration to define the voltage reference source
//!
typedef enum
{
    ADC_VoltageRefSrc_Int=0,    //!< Denotes an internal voltage reference source
    ADC_VoltageRefSrc_Ext       //!< Denotes an internal voltage reference source
} ADC_VoltageRefSrc_e;


//! \brief Defines the analog-to-digital converter (ADC) object
//!
typedef struct _ADC_Obj_
{
    volatile uint16_t      ADCRESULT[16];    //!< ADC result registers
    volatile uint16_t      resvd_1[26096];   //!< Reserved
    volatile uint16_t      ADCCTL1;          //!< ADC Control Register 1
    volatile uint16_t      rsvd_2[3];        //!< Reserved
    volatile uint16_t      ADCINTFLG;        //!< ADC Interrupt Flag Register
    volatile uint16_t      ADCINTFLGCLR;     //!< ADC Interrupt Flag Clear Register
    volatile uint16_t      ADCINTOVF;        //!< ADC Interrupt Overflow Register
    volatile uint16_t      ADCINTOVFCLR;     //!< ADC Interrupt Overflow Clear Register
    volatile uint16_t      INTSELxNy[5];     //!< ADC Interrupt Select x and y Register
    volatile uint16_t      rsvd_3[3];        //!< Reserved
    volatile uint16_t      SOCPRICTRL;       //!< ADC Start Of Conversion Priority Control Register
    volatile uint16_t      rsvd_4;           //!< Reserved
    volatile uint16_t      ADCSAMPLEMODE;    //!< ADC Sample Mode Register
    volatile uint16_t      rsvd_5;           //!< Reserved
    volatile uint16_t      ADCINTSOCSEL1;    //!< ADC Interrupt Trigger SOC Select 1 Register
    volatile uint16_t      ADCINTSOCSEL2;    //!< ADC Interrupt Trigger SOC Select 2 Register
    volatile uint16_t      rsvd_6[2];        //!< Reserved
    volatile uint16_t      ADCSOCFLG1;       //!< ADC SOC Flag 1 Register
    volatile uint16_t      rsvd_7;           //!< Reserved
    volatile uint16_t      ADCSOCFRC1;       //!< ADC SOC Force 1 Register
    volatile uint16_t      rsvd_8;           //!< Reserved
    volatile uint16_t      ADCSOCOVF1;       //!< ADC SOC Overflow 1 Register
    volatile uint16_t      rsvd_9;           //!< Reserved
    volatile uint16_t      ADCSOCOVFCLR1;    //!< ADC SOC Overflow Clear 1 Register
    volatile uint16_t      rsvd_10;          //!< Reserved
    volatile uint16_t      ADCSOCxCTL[16];   //!< ADC SOCx Control Registers
    volatile uint16_t      rsvd_11[16];      //!< Reserved
    volatile uint16_t      ADCREFTRIM;       //!< ADC Reference/Gain Trim Register
    volatile uint16_t      ADCOFFTRIM;       //!< ADC Offset Trim Register
    volatile uint16_t      resvd_12[13];     //!< Reserved
    volatile uint16_t      ADCREV;           //!< ADC Revision Register
} ADC_Obj;


//! \brief Defines the analog-to-digital converter (ADC) handle
//!
typedef struct ADC_Obj  *ADC_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


//! \brief     Clears the analog-to-digital converter (ADC) interrupt flag
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The ADC interrupt number
inline void ADC_clearIntFlag(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    // clear the bit
    adc->ADCINTFLGCLR = 1 << intNumber;

 return;
} // end of ADC_clearIntFlag() function


//! \brief     Disables the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_disable(ADC_Handle adcHandle);


//! \brief     Disables the analog-to-digital converter (ADC) band gap circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_disableBandGap(ADC_Handle adcHandle);


//! \brief     Disables the analog-to-digital converter (ADC) interrupt
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
void ADC_disableInt(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber);


//! \brief     Disables the analog-to-digital converter (ADC) reference buffers circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_disableRefBuffers(ADC_Handle adcHandle);

//! \brief     Disables temperature sensor for conversion on A5
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_disableTempSensor(ADC_Handle adcHandle);

//! \brief     Enables the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_enable(ADC_Handle adcHandle);


//! \brief     Enables the analog-to-digital converter (ADC) band gap circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_enableBandGap(ADC_Handle adcHandle);


//! \brief     Enables the analog-to-digital converter (ADC) interrupt
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
void ADC_enableInt(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber);


//! \brief     Enables the analog-to-digital converter (ADC) reference buffers circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_enableRefBuffers(ADC_Handle adcHandle);

//! \brief     Enables temperature sensor for conversion on A5
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_enableTempSensor(ADC_Handle adcHandle);

//! \brief     Reads the specified ADC result (i.e. value)
//! \param[in] adcHandle     The ADC handle
//! \param[in] resultNumber  The result number for the ADCRESULT registers
//! \return    The ADC result
inline void ADC_forceConversion(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;

    adc->ADCSOCFRC1 |= 1 << socNumber;

    return;
} // end of ADC_forceConversion() function

//! \brief     Reads the status for a given ADC interrupt
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The ADC interrupt number
//! \return    Interrupt status for selected ADC interrupt
inline bool_t ADC_getIntStatus(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    // clear the bit
    return (adc->ADCINTFLG >> intNumber) & 0x01;

} // end of ADC_getIntStatus() function


//! \brief     Gets the analog-to-digital converter (ADC) start-of-conversion (SOC) sample delay value
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber  The SOC number
//! \return    The ADC sample delay value
inline ADC_SocSampleWindow_e ADC_getSocSampleWindow(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;
    ADC_SocSampleWindow_e sampleWindow;


    // get the bits
    sampleWindow = (ADC_SocSampleWindow_e)(adc->ADCSOCxCTL[socNumber] & ADC_ADCSOCxCTL_ACQPS_BITS);

    return(sampleWindow);
} // end of ADC_getSocSampleWindow() function

//! \brief     Converts a temperature sensor sample into a temperature in Celcius
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \return    Temperature in degrees Celcius
inline int16_t ADC_getTemperatureC(ADC_Handle adcHandle, int16_t sensorSample)
{
    return ((sensorSample - ADC_getTempOffset())*(int32_t)ADC_getTempSlope() + ADC_FP_ROUND + ADC_KELVIN_OFF)/ADC_FP_SCALE - ADC_KELVIN;
}

//! \brief     Converts a temperature sensor sample into a temperature in Kelvin
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \return    Temperature in degrees Kelvin
inline int16_t ADC_getTemperatureK(ADC_Handle adcHandle, int16_t sensorSample)
{
    return ((sensorSample - ADC_getTempOffset())*(int32_t)ADC_getTempSlope() + ADC_FP_ROUND + ADC_KELVIN_OFF)/ADC_FP_SCALE;
}

//! \brief     Initializes the analog-to-digital converter (ADC) object handle
//! \param[in] pMemory   A pointer to the base address of the ADC registers
//! \param[in] numBytes  The number of bytes allocated for the ADC object, bytes
//! \return    The analog-to-digital converter (ADC) object handle
ADC_Handle ADC_init(void *pMemory, const size_t numBytes);


//! \brief     Powers down the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_powerDown(ADC_Handle adcHandle);


//! \brief     Powers up the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_powerUp(ADC_Handle adcHandle);


//! \brief     Reads the specified ADC result (i.e. value)
//! \param[in] adcHandle     The ADC handle
//! \param[in] resultNumber  The result number for the ADCRESULT registers
//! \return    The ADC result
inline uint_least16_t ADC_readResult(ADC_Handle adcHandle, const ADC_ResultNumber_e resultNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;

    return(adc->ADCRESULT[resultNumber]);
} // end of ADC_read() function


//! \brief     Resets the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
void ADC_reset(ADC_Handle adcHandle);


//! \brief     Sets the interrupt mode
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
//! \param[in] intMode    The interrupt mode
void ADC_setIntMode(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber, const ADC_IntMode_e intMode);


//! \brief     Sets the interrupt pulse generation mode
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] pulseMode  The pulse generation mode
void ADC_setIntPulseGenMode(ADC_Handle adcHandle, const ADC_IntPulseGenMode_e pulseMode);


//! \brief     Sets the interrupt source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
//! \param[in] intSrc     The interrupt source
void ADC_setIntSrc(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber, const ADC_IntSrc_e intSrc);


//! \brief     Sets the sample mode
//! \param[in] adcHandle   The analog-to-digital converter (ADC) object handle
//! \param[in] sampleMode  The sample mode
void ADC_setSampleMode(ADC_Handle adcHandle, const ADC_SampleMode_e sampleMode);


//! \brief     Sets the start-of-conversion (SOC) channel number
//! \param[in] adcHandle   The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber   The SOC number
//! \param[in] chanNumber  The channel number
void ADC_setSocChanNumber(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocChanNumber_e chanNumber);


//! \brief     Sets the start-of-conversion (SOC) sample delay
//! \param[in] adcHandle    The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber    The SOC number
//! \param[in] sampleDelay  The sample delay
void ADC_setSocSampleWindow(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocSampleWindow_e sampleWindow);


//! \brief     Sets the start-of-conversion (SOC) trigger source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber  The SOC number
//! \param[in] trigSrc    The trigger delay
void ADC_setSocTrigSrc(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocTrigSrc_e trigSrc);


//! \brief     Sets the voltage reference source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] voltRef    The voltage reference source
void ADC_setVoltRefSrc(ADC_Handle adcHandle, const ADC_VoltageRefSrc_e voltRef);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif // end of _ADC_H_ definition

