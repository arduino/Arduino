//#############################################################################
//
//! \file   f2802x_common/source/gpio.c
//!
//! \brief  The functions in this file are used to configure the general
//!         purpose I/O (GPIO) registers
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
#include "DSP28x_Project.h"
#include "f2802x_common/include/gpio.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

uint16_t GPIO_getData(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;



    if(gpioNumber < GPIO_Number_32)
    {
        return ((gpio->GPADAT >> gpioNumber) & 0x0001);
    }
    else
    {
        return ((gpio->GPBDAT >> (gpioNumber - GPIO_Number_32)) & 0x0001);
    }

} // end of GPIO_getData() function

uint16_t GPIO_getPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

    if(gpioPort == GPIO_Port_A)
    {
        return (gpio->GPADAT);
    }
    else if(gpioPort == GPIO_Port_B)
    {
        return (gpio->GPBDAT);
    }
    
    return (NULL);

} // end of GPIO_getPortData() function


GPIO_Handle GPIO_init(void *pMemory, const size_t numBytes)
{
    GPIO_Handle gpioHandle;


    if(numBytes < sizeof(GPIO_Obj))
    {
      return((GPIO_Handle)NULL);
    }

    // assign the handle
    gpioHandle = (GPIO_Handle)pMemory;

    return(gpioHandle);
} // end of GPIO_init() function


void GPIO_setDirection(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Direction_e direction)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber < GPIO_Number_32)
    {
      // clear the bit
      gpio->GPADIR &= (~((uint32_t)1 << gpioNumber));

      // set the bit
      gpio->GPADIR |= (uint32_t)direction << gpioNumber;
    }
    else
    {
      // clear the bit
      gpio->GPBDIR &= (~((uint32_t)1 << (gpioNumber - GPIO_Number_32)));

      // set the bit
      gpio->GPBDIR |= (uint32_t)direction << (gpioNumber - GPIO_Number_32);
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setDirection() function

void GPIO_setPullUp(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_PullUp_e pullUp)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber < GPIO_Number_32)
    {
      // clear the bit
      gpio->GPAPUD &= (~((uint32_t)1 << gpioNumber));

      // set the bit
      gpio->GPAPUD |= (uint32_t)pullUp << gpioNumber;
    }
    else
    {
      // clear the bit
      gpio->GPBPUD &= (~((uint32_t)1 << (gpioNumber - GPIO_Number_32)));

      // set the bit
      gpio->GPBPUD |= (uint32_t)pullUp << (gpioNumber - GPIO_Number_32);
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setPullUp() function


void GPIO_setExtInt(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const CPU_ExtIntNumber_e intNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // associate the interrupt with the GPIO pin
    gpio->GPIOXINTnSEL[intNumber] = gpioNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setExtInt() function


void GPIO_setHigh(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber < GPIO_Number_32)
    {
      gpio->GPASET = (uint32_t)1 << gpioNumber;
    }
    else
    {
      gpio->GPBSET = (uint32_t)1 << (gpioNumber - GPIO_Number_32);
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setHigh() function


void GPIO_setLow(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber < GPIO_Number_32)
    {
      gpio->GPACLEAR = (uint32_t)1 << gpioNumber;
    }
    else
    {
      gpio->GPBCLEAR = (uint32_t)1 << (gpioNumber - GPIO_Number_32);
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setLow() function


void GPIO_setMode(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Mode_e mode)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber < GPIO_Number_16)
    {
      uint8_t lShift = gpioNumber << 1;
      uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
      uint32_t setBits = (uint32_t)mode << lShift;

      // clear the bits
      gpio->GPAMUX1 &= (~clearBits);

      // set the bits
      gpio->GPAMUX1 |= setBits;
    }
    else if(gpioNumber < GPIO_Number_32)
    {
      uint8_t lShift = (gpioNumber - GPIO_Number_16) << 1;
      uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
      uint32_t setBits = (uint32_t)mode << lShift;

      // clear the bits
      gpio->GPAMUX2 &= (~clearBits);

      // set the bits
      gpio->GPAMUX2 |= setBits;
    }
    else
    {
      uint8_t lShift = (gpioNumber - GPIO_Number_32) << 1;
      uint32_t clearBits = (uint32_t)GPIO_GPMUX_CONFIG_BITS << lShift;
      uint32_t setBits = (uint32_t)mode << lShift;

      // clear the bits
      gpio->GPBMUX1 &= (~clearBits);

      // set the bits
      gpio->GPBMUX1 |= setBits;
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setMode() function

void GPIO_setPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort, const uint16_t data)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioPort == GPIO_Port_A)
    {
        gpio->GPADAT = data;
    }
    else if(gpioPort == GPIO_Port_B)
    {
        gpio->GPBDAT = data;
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setPortData() function

void GPIO_setQualification(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Qual_e qualification)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber <= GPIO_Rsvd_15)
    {
        gpio->GPAQSEL1 = (uint32_t)qualification << (2 * gpioNumber);
    }
    else if(gpioNumber <= GPIO_Rsvd_31)
    {
        gpio->GPAQSEL2 = (uint32_t)qualification << (2 * (gpioNumber - GPIO_Rsvd_15));
    }
    else if(gpioNumber <= GPIO_Number_38)
    {
        gpio->GPBQSEL1 = (uint32_t)qualification << (2 * (gpioNumber - GPIO_Rsvd_31));
    } 

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setQualification() function

void GPIO_setQualificationPeriod(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const uint8_t period)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    
    if(gpioNumber <= GPIO_Number_7)
    {
        gpio->GPACTRL = (uint32_t)period;
    }
    else if(gpioNumber <= GPIO_Rsvd_15)
    {
        gpio->GPACTRL = (uint32_t)period << 8;
    }
    else if(gpioNumber <= GPIO_Rsvd_23)
    {
        gpio->GPACTRL = (uint32_t)period << 16;
    }
    else if(gpioNumber < GPIO_Rsvd_31)
    {
        gpio->GPACTRL = (uint32_t)period << 24;
    }
    else if(gpioNumber <= GPIO_Number_38)
    {
        gpio->GPBCTRL = (uint32_t)period;
    } 
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_setQualificationPeriod() function


void GPIO_toggle(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(gpioNumber < GPIO_Number_32)
    {
      gpio->GPATOGGLE = (uint32_t)1 << gpioNumber;
    }
    else
    {
      gpio->GPBTOGGLE = (uint32_t)1 << (gpioNumber - GPIO_Number_32);
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_toggle() function

void GPIO_lpmSelect(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber)
{
    GPIO_Obj *gpio = (GPIO_Obj *)gpioHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    
    gpio->GPIOLPMSEL = ((uint32_t)1 << gpioNumber);
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of GPIO_lpmSelect() function
