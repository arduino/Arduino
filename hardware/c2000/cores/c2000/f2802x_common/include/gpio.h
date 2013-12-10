#ifndef _GPIO_H_
#define _GPIO_H_

//#############################################################################
//
//! \file   f2802x_common/include/gpio.h
//!
//! \brief  Contains public interface to general purpose I/O (GPIO) methods
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
//! \defgroup GPIO

//!
//! \ingroup GPIO
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines

//! \brief Defines the base address of the general purpose I/O (GPIO) registers
//!
#define  GPIO_BASE_ADDR        (0x00006F80)


//! \brief Defines the location of the CONFIG bits in the GPMUX register
//!
#define  GPIO_GPMUX_CONFIG_BITS    (3 << 0)


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the general purpose I/O (GPIO) modes for each pin
//!
typedef enum
{
  GPIO_0_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_0_Mode_EPWM1A,              //!< Denotes a EPWM1A function
  GPIO_0_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_0_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_1_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_1_Mode_EPWM1B,              //!< Denotes a EPWM1B function
  GPIO_1_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_1_Mode_COMP1OUT,            //!< Denotes a COMP1OUT function
  GPIO_2_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_2_Mode_EPWM2A,              //!< Denotes a EPWM2A function
  GPIO_2_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_2_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_3_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_3_Mode_EPWM2B,              //!< Denotes a EPWM2B function
  GPIO_3_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_3_Mode_COMP2OUT,            //!< Denotes a COMP2OUT function
  GPIO_4_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_4_Mode_EPWM3A,              //!< Denotes a EPWM3A function
  GPIO_4_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_4_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_5_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_5_Mode_EPWM3B,              //!< Denotes a EPWM3B function
  GPIO_5_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_5_Mode_ECAP1,               //!< Denotes a ECAP1 function
  GPIO_6_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_6_Mode_EPWM4A,              //!< Denotes a EPWM4A function
  GPIO_6_Mode_EPWMSYNCI,           //!< Denotes a EPWMSYNCI function
  GPIO_6_Mode_EPWMSYNCO,           //!< Denotes a EPWMSYNCO function
  GPIO_7_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_7_Mode_EPWM4B,              //!< Denotes a EPWM4B function
  GPIO_7_Mode_SCIRXDA,             //!< Denotes a SCIRXDA function
  GPIO_7_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_12_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_12_Mode_TZ1_NOT,            //!< Denotes a TZ1_NOT function
  GPIO_12_Mode_SCITXDA,            //!< Denotes a SCITXDA function
  GPIO_12_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_16_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_16_Mode_SPISIMOA,           //!< Denotes a SPISIMOA function
  GPIO_16_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_16_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_17_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_17_Mode_SPISOMIA,           //!< Denotes a SPISOMIA function
  GPIO_17_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_17_Mode_TZ3_NOT,            //!< Denotes a TZ3_NOT function
  GPIO_18_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_18_Mode_SPICLKA,            //!< Denotes a SPICLKA function
  GPIO_18_Mode_SCITXDA,            //!< Denotes a SCITXDA function
  GPIO_18_Mode_XCLKOUT,            //!< Denotes a XCLKOUT function
  GPIO_19_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_19_Mode_SPISTEA_NOT,        //!< Denotes a SPISTEA_NOT function
  GPIO_19_Mode_SCIRXDA,            //!< Denotes a SCIRXDA function
  GPIO_19_Mode_ECAP1,              //!< Denotes a ECAP1 function
  GPIO_28_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_28_Mode_SCIRXDA,            //!< Denotes a SCIRXDA function
  GPIO_28_Mode_SDDA,               //!< Denotes a SDDA function
  GPIO_28_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_29_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_29_Mode_SCITXDA,            //!< Denotes a SCITXDA function
  GPIO_29_Mode_SCLA,               //!< Denotes a SCLA function
  GPIO_29_Mode_TZ3_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_32_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_32_Mode_SDAA,               //!< Denotes a SDDA function
  GPIO_32_Mode_EPWMSYNCI,          //!< Denotes a EPWMSYNCI function
  GPIO_32_Mode_ADCSOCAO_NOT,       //!< Denotes a ADCSOCAO_NOT function
  GPIO_33_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_33_Mode_SCLA,               //!< Denotes a SCLA function
  GPIO_33_Mode_EPWMSYNCO,          //!< Denotes a EPWMSYNCO function
  GPIO_33_Mode_ADCSOCBO_NOT,       //!< Denotes a ADCSOCBO_NOT function
  GPIO_34_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_34_Mode_COMP2OUT,           //!< Denotes a COMP2OUT function
  GPIO_34_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_34_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_35_Mode_JTAG_TDI=0,         //!< Denotes a JTAG_TDI function
  GPIO_35_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_35_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_35_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_36_Mode_JTAG_TMS=0,         //!< Denotes a JTAG_TMS function
  GPIO_36_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_36_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_36_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_37_Mode_JTAG_TDO=0,         //!< Denotes a JTAG_TDO function
  GPIO_37_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_37_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_37_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_38_Mode_JTAG_TCK=0,         //!< Denotes a JTAG_TCK function
  GPIO_38_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_38_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_38_Mode_Rsvd_3              //!< Denotes a reserved function
} GPIO_Mode_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) directions
//!
typedef enum
{
    GPIO_Direction_Input=0,    //!< Denotes an input direction
    GPIO_Direction_Output      //!< Denotes an output direction
} GPIO_Direction_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) pull ups
//!
typedef enum
{
    GPIO_PullUp_Enable=0,    //!< Denotes pull up will be enabled
    GPIO_PullUp_Disable      //!< Denotes pull up will be disabled
} GPIO_PullUp_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) qualification
//!
typedef enum
{
    GPIO_Qual_Sync = 0,      //!< Denotes input will be synchronized to SYSCLK
    GPIO_Qual_Sample_3,      //!< Denotes input is qualified with 3 samples
    GPIO_Qual_Sample_6,      //!< Denotes input is qualified with 6 samples
    GPIO_Qual_ASync          //!< Denotes input is asynchronous
} GPIO_Qual_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) ports
//!
typedef enum
{
    GPIO_Port_A = 0,    //!< GPIO Port A
    GPIO_Port_B         //!< GPIO Port B
} GPIO_Port_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) numbers
//!
typedef enum
{
    GPIO_Number_0=0,    //!< Denotes GPIO number 0
    GPIO_Number_1,      //!< Denotes GPIO number 1
    GPIO_Number_2,      //!< Denotes GPIO number 2
    GPIO_Number_3,      //!< Denotes GPIO number 3
    GPIO_Number_4,      //!< Denotes GPIO number 4
    GPIO_Number_5,      //!< Denotes GPIO number 5
    GPIO_Number_6,      //!< Denotes GPIO number 6
    GPIO_Number_7,      //!< Denotes GPIO number 7
    GPIO_Rsvd_8,        //!< This GPIO not present
    GPIO_Rsvd_9,        //!< This GPIO not present
    GPIO_Rsvd_10,       //!< This GPIO not present
    GPIO_Rsvd_11,       //!< This GPIO not present
    GPIO_Number_12,     //!< Denotes GPIO number 12
    GPIO_Rsvd_13,       //!< This GPIO not present
    GPIO_Rsvd_14,       //!< This GPIO not present
    GPIO_Rsvd_15,       //!< This GPIO not present
    GPIO_Number_16,     //!< Denotes GPIO number 16
    GPIO_Number_17,     //!< Denotes GPIO number 17
    GPIO_Number_18,     //!< Denotes GPIO number 18
    GPIO_Number_19,     //!< Denotes GPIO number 19
    GPIO_Rsvd_20,       //!< This GPIO not present
    GPIO_Rsvd_21,       //!< This GPIO not present
    GPIO_Rsvd_22,       //!< This GPIO not present
    GPIO_Rsvd_23,       //!< This GPIO not present
    GPIO_Rsvd_24,       //!< This GPIO not present
    GPIO_Rsvd_25,       //!< This GPIO not present
    GPIO_Rsvd_26,       //!< This GPIO not present
    GPIO_Rsvd_27,       //!< This GPIO not present
    GPIO_Number_28,     //!< Denotes GPIO number 28
    GPIO_Number_29,     //!< Denotes GPIO number 29
    GPIO_Rsvd_30,       //!< This GPIO not present
    GPIO_Rsvd_31,       //!< This GPIO not present
    GPIO_Number_32,     //!< Denotes GPIO number 32
    GPIO_Number_33,     //!< Denotes GPIO number 33
    GPIO_Number_34,     //!< Denotes GPIO number 34
    GPIO_Number_35,     //!< Denotes GPIO number 35
    GPIO_Number_36,     //!< Denotes GPIO number 36
    GPIO_Number_37,     //!< Denotes GPIO number 37
    GPIO_Number_38,     //!< Denotes GPIO number 38
    GPIO_numGpios
} GPIO_Number_e;


//! \brief Defines the General Purpose I/O (GPIO) object
//!
typedef struct _GPIO_Obj_
{
    volatile uint32_t GPACTRL;         //!< GPIO A Control Register
    volatile uint32_t GPAQSEL1;        //!< GPIO A Qualifier Select 1 Register
    volatile uint32_t GPAQSEL2;        //!< GPIO A Qualifier Select 2 Register
    volatile uint32_t GPAMUX1;         //!< GPIO A MUX 1 Register
    volatile uint32_t GPAMUX2;         //!< GPIO A MUX 2 Register
    volatile uint32_t GPADIR;          //!< GPIO A Direction Register
    volatile uint32_t GPAPUD;          //!< GPIO A Pull Up Disable Register
    volatile uint16_t rsvd_1[2];       //!< Reserved
    volatile uint32_t GPBCTRL;         //!< GPIO B Control Register
    volatile uint32_t GPBQSEL1;        //!< GPIO B Qualifier Select 1 Register
    volatile uint16_t rsvd_2[2];       //!< Reserved
    volatile uint32_t GPBMUX1;         //!< GPIO B MUX 1 Register
    volatile uint16_t rsvd_3[2];       //!< Reserved
    volatile uint32_t GPBDIR;          //!< GPIO B Direction Register
    volatile uint32_t GPBPUD;          //!< GPIO B Pull Up Disable Register
    volatile uint16_t rsvd_4[24];      //!< Reserved 
    volatile uint32_t AIOMUX1;         //!< Analog, I/O Mux 1 Register
    volatile uint16_t rsvd_5[2];       //!< Reserved
    volatile uint32_t AIODIR;          //!< Analog, I/O Direction Register
    volatile uint16_t rsvd_6[4];       //!< Reserved
    volatile uint32_t GPADAT;          //!< GPIO A Data Register
    volatile uint32_t GPASET;          //!< GPIO A Set Register
    volatile uint32_t GPACLEAR;        //!< GPIO A Clear Register
    volatile uint32_t GPATOGGLE;       //!< GPIO A Toggle Register
    volatile uint32_t GPBDAT;          //!< GPIO B Data Register
    volatile uint32_t GPBSET;          //!< GPIO B Set Register
    volatile uint32_t GPBCLEAR;        //!< GPIO B Clear Register
    volatile uint32_t GPBTOGGLE;       //!< GPIO B Toggle Register
    volatile uint16_t rsvd_7[8];       //!< Reserved
    volatile uint32_t AIODAT;          //!< Analog I/O Data Register
    volatile uint32_t AIOSET;          //!< Analog I/O Data Set Register
    volatile uint32_t AIOCLEAR;        //!< Analog I/O Clear Register
    volatile uint32_t AIOTOGGLE;       //!< Analog I/O Toggle Register
    volatile uint16_t GPIOXINTnSEL[3]; //!< XINT1-3 Source Select Registers
    volatile uint16_t rsvd_8[5];       //!< Reserved
    volatile uint32_t GPIOLPMSEL;      //!< GPIO Low Power Mode Wakeup Select Register
} GPIO_Obj;


//! \brief Defines the general purpose I/O (GPIO) handle
//!
typedef struct GPIO_Obj   *GPIO_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Returns the data value present on a pin (either input or output)
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \return    The boolen state of a pin (high/low)
uint16_t GPIO_getData(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);


//! \brief     Returns the data value present on a GPIO port
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioPort  The GPIO port
//! \return    The data values for the specified port
uint16_t GPIO_getPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort);


//! \brief     Initializes the general purpose I/O (GPIO) object handle
//! \param[in] pMemory     A pointer to the base address of the GPIO registers
//! \param[in] numBytes    The number of bytes allocated for the GPIO object, bytes
//! \return    The general purpose I/O (GPIO) object handle
GPIO_Handle GPIO_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the general purpose I/O (GPIO) signal direction
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] direction   The signal direction 
void GPIO_setDirection(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const GPIO_Direction_e direction);

//! \brief     Sets the general purpose I/O (GPIO) signal pullups
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] pullUp      The pull up enable or disable
void GPIO_setPullUp(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const GPIO_PullUp_e pullUp);


//! \brief     Sets the general purpose I/O (GPIO) external interrupt number
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] intNumber   The interrupt number
void GPIO_setExtInt(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const CPU_ExtIntNumber_e intNumber);


//! \brief     Sets the specified general purpose I/O (GPIO) signal low
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
void GPIO_setLow(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


//! \brief     Sets the mode for the specified general purpose I/O (GPIO) signal
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] mode        The mode
void GPIO_setMode(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const GPIO_Mode_e mode);


//! \brief     Sets the specified general purpose I/O (GPIO) signal high
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
void GPIO_setHigh(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


//! \brief     Sets data output on a given GPIO port
//! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
//! \param[in] gpioPort     The GPIO number
//! \param[in] data         The data to write to the port
void GPIO_setPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort, const uint16_t data);


//! \brief     Sets the qualification for the specified general purpose I/O (GPIO)
//! \param[in] gpioHandle    The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber    The GPIO number
//! \param[in] qualification The desired input qualification
void GPIO_setQualification(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Qual_e qualification);

//! \brief     Sets the qualification period for the specified general purpose I/O block (8 I/O's per block)
//! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber   The GPIO number
//! \param[in] period       The desired input qualification period
void GPIO_setQualificationPeriod(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const uint8_t period);

//! \brief     Toggles the specified general purpose I/O (GPIO) signal
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
void GPIO_toggle(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);

//! \brief     Selects a gpio pin to wake up device from STANDBY and HALT LPM
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
void GPIO_lpmSelect(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _GPIO_H_ definition



