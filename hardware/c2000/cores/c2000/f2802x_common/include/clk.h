#ifndef _CLK_H_
#define _CLK_H_

//#############################################################################
//
//! \file   f2802x_common/include/clk.h
//!
//! \brief  Contains public interface to various functions related to the 
//!         clock (CLK) object 
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
#include "f2802x_common/include/pwm.h"


//!
//! \defgroup CLK

//!
//! \ingroup CLK
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


//! \brief Defines the base address of the clock (CLK) registers
//!
#define  CLK_BASE_ADDR                   (0x00007010)

//! \brief Defines the location of the HRPWMENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_HRPWMENCLK_BITS     (1 << 0)

//! \brief Defines the location of the LINAENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_LINAENCLK_BITS      (1 << 1)

//! \brief Defines the location of the TBCLKSYNC bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_TBCLKSYNC_BITS      (1 << 2)

//! \brief Defines the location of the ADCENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_ADCENCLK_BITS       (1 << 3)

//! \brief Defines the location of the I2CAENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_I2CAENCLK_BITS      (1 << 4)

//! \brief Defines the location of the SPIAENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_SPIAENCLK_BITS      (1 << 8)

//! \brief Defines the location of the SPIBENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_SPIBENCLK_BITS      (1 << 9)

//! \brief Defines the location of the SCIAENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_SCIAENCLK_BITS      (1 << 10)

//! \brief Defines the location of the ECANAENCLK bits in the PCLKCR0 register
//!
#define  CLK_PCLKCR0_ECANAENCLK_BITS     (1 << 14)


//! \brief Defines the location of the EPWM1ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM1ENCLK_BITS     (1 << 0)

//! \brief Defines the location of the EPWM2ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM2ENCLK_BITS     (1 << 1)

//! \brief Defines the location of the EPWM3ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM3ENCLK_BITS     (1 << 2)

//! \brief Defines the location of the EPWM4ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM4ENCLK_BITS     (1 << 3)

//! \brief Defines the location of the EPWM5ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM5ENCLK_BITS     (1 << 4)

//! \brief Defines the location of the EPWM6ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM6ENCLK_BITS     (1 << 5)

//! \brief Defines the location of the EPWM7ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EPWM7ENCLK_BITS     (1 << 6)

//! \brief Defines the location of the ECAP1ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_ECAP1ENCLK_BITS     (1 << 8)

//! \brief Defines the location of the EQEP1ENCLK bits in the PCLKCR1 register
//!
#define  CLK_PCLKCR1_EQEP1ENCLK_BITS     (1 << 14)


//! \brief Defines the location of the COMP1ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_COMP1ENCLK_BITS     (1 << 0)

//! \brief Defines the location of the COMP2ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_COMP2ENCLK_BITS     (1 << 1)

//! \brief Defines the location of the COMP3ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_COMP3ENCLK_BITS     (1 << 2)

//! \brief Defines the location of the CPUTIMER0ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_CPUTIMER0ENCLK_BITS (1 << 8)

//! \brief Defines the location of the CPUTIMER1ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_CPUTIMER1ENCLK_BITS (1 << 9)

//! \brief Defines the location of the CPUTIMER2ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_CPUTIMER2ENCLK_BITS (1 << 10)

//! \brief Defines the location of the GPIOINENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_GPIOINENCLK_BITS    (1 << 13)

//! \brief Defines the location of the CLA1ENCLK bits in the PCLKCR3 register
//!
#define  CLK_PCLKCR3_CLA1ENCLK_BITS      (1 << 14)


//! \brief Defines the location of the LSPNCLK bits in the LOSPCP register
//!
#define  CLK_LOSPCP_LSPCLK_BITS          (7 << 0)


//! \brief Defines the location of the XCLKOUTDIV bits in the XCLK register
//!
#define  CLK_XCLK_XCLKOUTDIV_BITS        (3 << 0)

//! \brief Defines the location of the XCLKINSEL bits in the XCLK register
//!
#define  CLK_XCLK_XCLKINSEL_BITS         (1 << 6)


//! \brief Defines the location of the OSCCLKSRCSEL bits in the CLKCTL register
//!
#define  CLK_CLKCTL_OSCCLKSRCSEL_BITS    (1 << 0)

//! \brief Defines the location of the OSCCLKSRC2SEL bits in the CLKCTL register
//!
#define  CLK_CLKCTL_OSCCLKSRC2SEL_BITS   (1 << 1)

//! \brief Defines the location of the WDCLKSRCSEL bits in the CLKCTL register
//!
#define  CLK_CLKCTL_WDCLKSRCSEL_BITS     (1 << 2)

//! \brief Defines the location of the TMR2CLKSRCSEL bits in the CLKCTL register
//!
#define  CLK_CLKCTL_TMR2CLKSRCSEL_BITS   (3 << 3)

//! \brief Defines the location of the TMR2CLKPRESCALE bits in the CLKCTL register
//!
#define  CLK_CLKCTL_TMR2CLKPRESCALE_BITS (7 << 5)

//! \brief Defines the location of the INTOSC1OFF bits in the CLKCTL register
//!
#define  CLK_CLKCTL_INTOSC1OFF_BITS      (1 << 8)

//! \brief Defines the location of the INTOSC1HALTI bits in the CLKCTL register
//!
#define  CLK_CLKCTL_INTOSC1HALTI_BITS    (1 << 9)

//! \brief Defines the location of the INTOSC2OFF bits in the CLKCTL register
//!
#define  CLK_CLKCTL_INTOSC2OFF_BITS      (1 << 10)

//! \brief Defines the location of the INTOSC2HALTI bits in the CLKCTL register
//!
#define  CLK_CLKCTL_INTOSC2HALTI_BITS    (1 << 11)

//! \brief Defines the location of the WDHALTI bits in the CLKCTL register
//!
#define  CLK_CLKCTL_WDHALTI_BITS         (1 << 12)

//! \brief Defines the location of the XCLKINOFF bits in the CLKCTL register
//!
#define  CLK_CLKCTL_XCLKINOFF_BITS       (1 << 13)

//! \brief Defines the location of the XTALOSCOFF bits in the CLKCTL register
//!
#define  CLK_CLKCTL_XTALOSCOFF_BITS      (1 << 14)

//! \brief Defines the location of the NMIRESETSEL bits in the CLKCTL register
//!
#define  CLK_CLKCTL_NMIRESETSEL_BITS     (1 << 15)


// **************************************************************************
// the typedefs


//! \brief Enumeration to define the external clock output frequency
//!
typedef enum
{
    CLK_ClkOutPreScaler_SysClkOut_by_4=(0 << 0),  //!< Denotes XCLKOUT = SYSCLKOUT/4
    CLK_ClkOutPreScaler_SysClkOut_by_2=(1 << 0),  //!< Denotes XCLKOUT = SYSCLKOUT/2
    CLK_ClkOutPreScaler_SysClkOut_by_1=(2 << 0),  //!< Denotes XCLKOUT = SYSCLKOUT/1
    CLK_ClkOutPreScaler_Off                       //!< Denotes XCLKOUT = Off
} CLK_ClkOutPreScaler_e;


//! \brief Enumeration to define the comparator numbers
//!
typedef enum
{
    CLK_CompNumber_1=(1 << 0),  //!< Denotes comparator number 1
    CLK_CompNumber_2=(1 << 1),  //!< Denotes comparator number 2
    CLK_CompNumber_3=(1 << 2)   //!< Denotes comparator number 3
} CLK_CompNumber_e;


//! \brief Enumeration to define the CPU timer numbers
//!
typedef enum
{
    CLK_CpuTimerNumber_0=(1 << 8),  //!< Denotes CPU timer number 0
    CLK_CpuTimerNumber_1=(1 << 9),  //!< Denotes CPU timer number 1
    CLK_CpuTimerNumber_2=(1 << 10)  //!< Denotes CPU timer number 2
} CLK_CpuTimerNumber_e;


//! \brief Enumeration to define the low speed clock prescaler, which sets the clock frequency
//!
typedef enum
{
    CLK_LowSpdPreScaler_SysClkOut_by_1=(0 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/1
    CLK_LowSpdPreScaler_SysClkOut_by_2=(1 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/2
    CLK_LowSpdPreScaler_SysClkOut_by_4=(2 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/4
    CLK_LowSpdPreScaler_SysClkOut_by_6=(3 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/6
    CLK_LowSpdPreScaler_SysClkOut_by_8=(4 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/8
    CLK_LowSpdPreScaler_SysClkOut_by_10=(5 << 0), //!< Denotes Low Speed Clock = SYSCLKOUT/10
    CLK_LowSpdPreScaler_SysClkOut_by_12=(6 << 0), //!< Denotes Low Speed Clock = SYSCLKOUT/12
    CLK_LowSpdPreScaler_SysClkOut_by_14=(7 << 0)  //!< Denotes Low Speed Clock = SYSCLKOUT/14
} CLK_LowSpdPreScaler_e;


//! \brief Enumeration to define the clock in source
//!
typedef enum
{
    CLK_ClkInSrc_Gpio38=0,
    CLK_ClkInSrc_Gpio39
} CLK_ClkInSrc_e;


//! \brief Enumeration to define the clock oscillator source
//!
typedef enum
{
    CLK_OscSrc_Internal=(0 << 0),  //!< Denotes an internal oscillator source
    CLK_OscSrc_External=(1 << 0)   //!< Denotes an external oscillator source
} CLK_OscSrc_e;


//! \brief Enumeration to define the clock oscillator 2 source
//!
typedef enum
{
    CLK_Osc2Src_Internal=(0 << 1),  //!< Denotes an internal oscillator 2 source
    CLK_Osc2Src_External=(1 << 1)   //!< Denotes an external oscillator 2 source
} CLK_Osc2Src_e;


//! \brief Enumeration to define the timer 2 prescaler, which sets the timer 2 frequency
//!
typedef enum
{
    CLK_Timer2PreScaler_by_1=(0 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 1
    CLK_Timer2PreScaler_by_2=(1 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 2
    CLK_Timer2PreScaler_by_4=(2 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 4
    CLK_Timer2PreScaler_by_8=(3 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 8
    CLK_Timer2PreScaler_by_16=(4 << 5) //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 16
} CLK_Timer2PreScaler_e;


//! \brief Enumeration to define the timer 2 source
//!
typedef enum
{
    CLK_Timer2Src_SysClk=(0 << 3),   //!< Denotes the CPU timer 2 clock source is SYSCLKOUT
    CLK_Timer2Src_ExtOsc=(1 << 3),   //!< Denotes the CPU timer 2 clock source is external oscillator
    CLK_Timer2Src_IntOsc1=(2 << 3),  //!< Denotes the CPU timer 2 clock source is internal oscillator 1
    CLK_Timer2Src_IntOsc2=(3 << 3)   //!< Denotes the CPU timer 2 clock source is internal oscillator 2
} CLK_Timer2Src_e;


//! \brief Enumeration to define the watchdog clock source
//!
typedef enum
{
    CLK_WdClkSrc_IntOsc1=(0 << 2),         //!< Denotes the watchdog clock source is internal oscillator 1
    CLK_WdClkSrc_ExtOscOrIntOsc2=(1 << 2)  //!< Denotes the watchdog clock source is external oscillator or internal oscillator 2
} CLK_WdClkSrc_e;


//! \brief Defines the clock (CLK) object
//!
typedef struct _CLK_Obj_
{
    volatile uint16_t   XCLK;         //!< XCLKOUT/XCLKIN Control
    volatile uint16_t   rsvd_1;       //!< Reserved
    volatile uint16_t   CLKCTL;       //!< Clock Control Register
    volatile uint16_t   rsvd_2[8];    //!< Reserved
    volatile uint16_t   LOSPCP;       //!< Low-Speed Peripheral Clock Pre-Scaler Register
    volatile uint16_t   PCLKCR0;      //!< Peripheral Clock Control Register 0
    volatile uint16_t   PCLKCR1;      //!< Peripheral Clock Control Register 1
    volatile uint16_t   rsvd_3[2];    //!< Reserved
    volatile uint16_t   PCLKCR3;      //!< Peripheral Clock Control Register 3
} CLK_Obj;


//! \brief Defines the clock (CLK) handle
//!
typedef struct CLK_Obj *CLK_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes


//! \brief     Disables the ADC clock
//! \param[in] clkHandle  The clock (CLK) object handle
void CLK_disableAdcClock(CLK_Handle clkHandle);


//! \brief     Disables the CLA clock
//! \param[in] clkHandle  The clock (CLK) object handle
void CLK_disableClaClock(CLK_Handle clkHandle);


//! \brief     Disables the XCLKIN oscillator input
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableClkIn(CLK_Handle clkHandle);


//! \brief     Disables the comparator clock
//! \param[in] clkHandle   The clock (CLK) object handle
//! \param[in] compNumber  The comparator number
void CLK_disableCompClock(CLK_Handle clkHandle,const CLK_CompNumber_e compNumber);


//! \brief     Disables the CPU timer clock
//! \param[in] clkHandle       The clock (CLK) object handle
//! \param[in] cpuTimerNumber  The CPU timer number
void CLK_disableCpuTimerClock(CLK_Handle clkHandle,
                              const CLK_CpuTimerNumber_e cpuTimerNumber);


//! \brief     Disables the crystal oscillator
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableCrystalOsc(CLK_Handle clkHandle);


//! \brief     Disables the ECANA clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableEcanaClock(CLK_Handle clkHandle);


//! \brief     Disables the ECAP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableEcap1Clock(CLK_Handle clkHandle);


//! \brief     Disables the EQEP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableEqep1Clock(CLK_Handle clkHandle);


//! \brief     Disables the GPIO input clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableGpioInputClock(CLK_Handle clkHandle);


//! \brief     Disables the HRPWM clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableHrPwmClock(CLK_Handle clkHandle);


//! \brief     Disables the HRPWM clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableHrPwmClock(CLK_Handle clkHandle);


//! \brief     Disables the I2C clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableI2cClock(CLK_Handle clkHandle);


//! \brief     Disables the LIN-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableLinAClock(CLK_Handle clkHandle);


//! \brief     Disables internal oscillator 1
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableOsc1(CLK_Handle clkHandle);


//! \brief     Disables internal oscillator 1 halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableOsc1HaltMode(CLK_Handle clkHandle);


//! \brief     Disables internal oscillator 2
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableOsc2(CLK_Handle clkHandle);


//! \brief     Disables internal oscillator 2 halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableOsc2HaltMode(CLK_Handle clkHandle);


//! \brief     Disables the pwm clock
//! \param[in] clkHandle   The clock (CLK) object handle
//! \param[in] pwmNumber   The PWM number
void CLK_disablePwmClock(CLK_Handle clkHandle,const PWM_Number_e pwmNumber);


//! \brief     Disables the SCI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableSciaClock(CLK_Handle clkHandle);


//! \brief     Disables the SPI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableSpiaClock(CLK_Handle clkHandle);


//! \brief     Disables the SPI-B clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableSpibClock(CLK_Handle clkHandle);


//! \brief     Disables the ePWM module time base clock sync signal
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableTbClockSync(CLK_Handle clkHandle);


//! \brief     Disables the watchdog halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_disableWatchDogHaltMode(CLK_Handle clkHandle);


//! \brief     Enables the ADC clock
//! \param[in] clkHandle  The clock (CLK) object handle
void CLK_enableAdcClock(CLK_Handle clkHandle);


//! \brief     Enables the CLA clock
//! \param[in] clkHandle  The clock (CLK) object handle
void CLK_enableClaClock(CLK_Handle clkHandle);


//! \brief     Enables the XCLKIN oscillator input
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableClkIn(CLK_Handle clkHandle);


//! \brief     Enables the comparator clock
//! \param[in] clkHandle   The clock (CLK) object handle
//! \param[in] compNumber  The comparator number
void CLK_enableCompClock(CLK_Handle clkHandle,const CLK_CompNumber_e compNumber);


//! \brief     Enables the CPU timer clock
//! \param[in] clkHandle       The clock (CLK) object handle
//! \param[in] cpuTimerNumber  The CPU timer number
void CLK_enableCpuTimerClock(CLK_Handle clkHandle,
                             const CLK_CpuTimerNumber_e cpuTimerNumber);


//! \brief     Enables the crystal oscillator
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableCrystalOsc(CLK_Handle clkHandle);


//! \brief     Enables the ECANA clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableEcanaClock(CLK_Handle clkHandle);


//! \brief     Enables the ECAP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableEcap1Clock(CLK_Handle clkHandle);


//! \brief     Enables the EQEP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableEqep1Clock(CLK_Handle clkHandle);


//! \brief     Enables the GPIO input clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableGpioInputClock(CLK_Handle clkHandle);


//! \brief     Enables the HRPWM clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableHrPwmClock(CLK_Handle clkHandle);


//! \brief     Enables the I2C clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableI2cClock(CLK_Handle clkHandle);


//! \brief     Enables the LIN-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableLinAClock(CLK_Handle clkHandle);


//! \brief     Enables internal oscillator 1
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableOsc1(CLK_Handle clkHandle);


//! \brief     Enables internal oscillator 1 halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableOsc1HaltMode(CLK_Handle clkHandle);


//! \brief     Enables internal oscillator 2
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableOsc2(CLK_Handle clkHandle);


//! \brief     Enables internal oscillator 2 halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableOsc2HaltMode(CLK_Handle clkHandle);


//! \brief     Enables the pwm clock
//! \param[in] clkHandle   The clock (CLK) object handle
//! \param[in] pwmNumber   The PWM number
void CLK_enablePwmClock(CLK_Handle clkHandle,const PWM_Number_e pwmNumber);


//! \brief     Enables the SCI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableSciaClock(CLK_Handle clkHandle);


//! \brief     Enables the SPI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableSpiaClock(CLK_Handle clkHandle);


//! \brief     Enables the SPI-B clock
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableSpibClock(CLK_Handle clkHandle);


//! \brief     Enables the ePWM module time base clock sync signal
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableTbClockSync(CLK_Handle clkHandle);


//! \brief     Enables the watchdog halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
void CLK_enableWatchDogHaltMode(CLK_Handle clkHandle);


//! \brief     Initializes the clock (CLK) object handle
//! \param[in] pMemory     A pointer to the base address of the CLK registers
//! \param[in] numBytes    The number of bytes allocated for the CLK object, bytes
//! \return    The clock (CLK) object handle
CLK_Handle CLK_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the external clock out prescaler
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] preScaler  The prescaler value
void CLK_setClkOutPreScaler(CLK_Handle clkHandle,
                            const CLK_ClkOutPreScaler_e preScaler);


//! \brief     Sets the low speed peripheral clock prescaler
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] preScaler  The prescaler value
void CLK_setLowSpdPreScaler(CLK_Handle clkHandle,
                            const CLK_LowSpdPreScaler_e preScaler);


//! \brief     Sets the oscillator clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The oscillator clock source
void CLK_setOscSrc(CLK_Handle clkHandle,const CLK_OscSrc_e src);
                      

//! \brief     Sets the oscillator 2 clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The oscillator 2 clock source
void CLK_setOsc2Src(CLK_Handle clkHandle,const CLK_Osc2Src_e src);
                      

//! \brief     Sets the timer 2 clock prescaler
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] preScaler  The prescaler value
void CLK_setTimer2PreScaler(CLK_Handle clkHandle,
                            const CLK_Timer2PreScaler_e preScaler);
                      

//! \brief     Sets the timer 2 clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The timer 2 clock source
void CLK_setTimer2Src(CLK_Handle clkHandle,const CLK_Timer2Src_e src);
                      

//! \brief     Sets the watchdog clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The watchdog clock source
void CLK_setWatchDogSrc(CLK_Handle clkHandle,const CLK_WdClkSrc_e src);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup


#endif  // end of _CLK_H_ definition

