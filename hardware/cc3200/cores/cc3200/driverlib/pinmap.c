//*****************************************************************************
//
// pinmap.c - Mapping of peripherals to pins.
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup pin_api
//! @{
//
//*****************************************************************************


//*****************************************************************************
// Includes
//*****************************************************************************

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ocp_shared.h"
#include "pinmap.h"

 
#define PAD_MODE_MASK		0x0000000F
#define PAD_STRENGTH_MASK	0x000000E0
#define PAD_TYPE_MASK		0x00000310
#define PAD_CONFIG_BASE		((OCP_SHARED_BASE + \
                                  OCP_SHARED_O_GPIO_PAD_CONFIG_0))

//*****************************************************************************
//
//
//*****************************************************************************

static const unsigned long g_ulPinToPadMap[64] =
{
	10,11,12,13,14,15,16,17,255,255,18,
	19,20,21,22,23,24,28,28,29,25,255,
	255,255,255,255,255,255,26,27,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,
	31,255,255,255,255,0,255,32,30,255,1,
	255,2,3,4,5,6,7,8,9
}; 


//*****************************************************************************
//
//! Sets pin mode.
//!
//! \param ulPin is a valid pin.
//! \param ulPinMode is one of the valid mode
//!
//! This function allows the given pin to be enabled in given mode
//! 
//! \return none
//
//*****************************************************************************
void PinModeSet(unsigned long ulPin,unsigned long ulPinMode)
{

  unsigned long ulPad;

  
  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  
  //
  // Set the mode.
  //
  
  HWREG(ulPad) = (((HWREG(ulPad) & ~PAD_MODE_MASK) |  ulPinMode) & ~(3<<10));

}

//*****************************************************************************
//
//! Gets pin mode.
//!
//! \param ulPin is a valid pin.
//!
//! This function returns the current pin mode
//! 
//! \return current pin mode.
//
//*****************************************************************************
unsigned long PinModeGet(unsigned long ulPin)
{
  
  unsigned long ulPad;

  
  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  
  //
  // return the mode.
  //
  
  return (HWREG(ulPad) & PAD_MODE_MASK);

}

//*****************************************************************************
//
//! Gets Pin output drive strength and Type
//! 
//! \param ulPin is one of the valid pin
//! \param pulPinStrength is pointer to storage for output drive strength
//! \param pulPinType is pinter to storage for pin type
//!
//! This function gets the pin type and output drive strength for the pin
//! specified by \e ulPin parameter. Parameters \e pulPinStrength and 
//! \e pulPinType corresponds to the values used in PinConfigSet().
//!
//!
//! \return None.
//
//*****************************************************************************

void PinConfigGet(unsigned long ulPin,unsigned long  *pulPinStrength,
	       					unsigned long *pulPinType)
{

  unsigned long ulPad;

  
  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  //
  // Get the type
  //
  *pulPinType = (HWREG(ulPad) & PAD_TYPE_MASK); 

  //
  // Get the output drive strength
  //
  *pulPinType = (HWREG(ulPad) & PAD_STRENGTH_MASK); 

}

//*****************************************************************************
//
//! Configure Pin output drive strength and Type
//! 
//! \param ulPin is one of the valid pin
//! \param ulPinStrength is logical OR of valid output drive strengths.
//! \param ulPinType is one of the valid pin type.
//!
//!  This function sets the pin type and strength for the pin specified by
//! \e ulPin parameter.
//!
//! The parameter \e ulPinStrength should be logical OR of one or more of the 
//! following
//! - \b PIN_STRENGTH_2MA
//! - \b PIN_STRENGTH_4MA
//! - \b PIN_STRENGTH_8MA
//!
//!
//! The parameter \e ulPinType should be one of the following
//! For standard type 
//!
//! - \b PIN_TYPE_STD
//! - \b PIN_TYPE_STD_PU
//! - \b PIN_TYPE_STD_PD
//!
//! And for Open drain type
//!
//! - \b PIN_TYPE_OD
//! - \b PIN_TYPE_OD_PU
//! - \b PIN_TYPE_OD_PD 
//!
//! \return None.
//
//*****************************************************************************

void PinConfigSet(unsigned long ulPin,unsigned long  ulPinStrength, 
						unsigned long ulPinType)
{

  unsigned long ulPad;

  
  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;


  //
  // Write the register
  //

  HWREG(ulPad) = ((HWREG(ulPad) & ~(PAD_STRENGTH_MASK | PAD_TYPE_MASK)) |
		  		(ulPinStrength | ulPinType ));


}

//*****************************************************************************
//
//! Sets the  current type for the specified pin
//! 
//! \param ulPin is  one of the valid pin.
//! \param ulPinType is one of valid pin type.
//!
//! This function sets the current type of specified pin. The \e ulPinType
//! should be one of the following
//! For standard type 
//! - \b PIN_TYPE_STD
//! - \b PIN_TYPE_STD_PU
//! - \b PIN_TYPE_STD_PD
//!
//! And for Open drain type
//!
//! - \b PIN_TYPE_OD
//! - \b PIN_TYPE_OD_PU
//! - \b PIN_TYPE_OD_PD
//!
//! \return None.
//
//*****************************************************************************
void PinTypeSet(unsigned long ulPin, unsigned long ulPinType)
{

  unsigned long ulPad;

  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  //
  // Set pin type
  //
  HWREG(ulPad) = ((HWREG(ulPad) & ~PAD_TYPE_MASK) | ulPinType); 
}


//*****************************************************************************
//
//! Gets the  current type for the specified pin
//! 
//! \param ulPin is  one of the valid pin.
//!
//! This function gets the current type of specified pin
//!
//! \return Returns the current pin type setting specified as one of
//! - \b PIN_TYPE_STD,\b PIN_TYPE_STD_PU,\b PIN_TYPE_STD_PD,
//! - \b PIN_TYPE_OD, \b PIN_TYPE_OD_PU or \b PIN_TYPE_OD_PD
//
//*****************************************************************************

unsigned long PinTypeGet(unsigned long ulPin)
{

  unsigned long ulPad;

  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  //
  // Return type
  //
  return (HWREG(ulPad) & PAD_TYPE_MASK); 
}

//*****************************************************************************
//
//! Sets the output drive strength of the specified pin
//! 
//! \param ulPin is one of the valid pin.
//! \param ulPinStrength is the strength to be set
//!
//! This function sets the current output drive strength configuration of 
//! pin specified in \e ulPin parameter. The \e ulPinStrength should be 
//! logical OR of one or more of the following
//! - \b PIN_STRENGTH_2MA
//! - \b PIN_STRENGTH_4MA
//! - \b PIN_STRENGTH_8MA
//!
//! \return None.
//
//*****************************************************************************

void PinStrengthSet(unsigned long ulPin, unsigned ulPinStrength)
{
   unsigned long ulPad;

  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  
  //
  // Set the strength
  //

  HWREG(ulPad) = (HWREG(ulPad) & ~PAD_STRENGTH_MASK) | ulPinStrength;

}

//*****************************************************************************
//
//! Gets the current output drive strength of the specified pin
//! 
//! \param ulPin is one of the valid pin.
//!
//! This function gets the current strength configuration of pin specified
//! in \e ulPin parameter
//!
//! \return Returns the output drive strength setting as logical OR of 
//! - \b PIN_STRENGTH_2MA, \b PIN_STRENGTH_4MA and \b PIN_STRENGTH_8MA
//
//*****************************************************************************

unsigned long PinStrengthGet(unsigned long ulPin)
{
  
  unsigned long ulPad;

  //
  // Get the corresponding Pad
  //
  
  ulPad = g_ulPinToPadMap[ulPin & 0x3F];
  
  
  //
  // Calculate the register address
  //

  ulPad = ((ulPad << 2) + PAD_CONFIG_BASE) ;

  //
  // Return strength
  //
  return (HWREG(ulPad) & PAD_STRENGTH_MASK);

}



//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by UART peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The UART pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin(s); other configurations may work as well depending upon the
//! board setup (for example, using the on-chip pull-ups).
//!
//!
//! \note This function cannot be used to turn any pin into a UART pin; it 
//! only sets the pin mode and configures it for proper UART operation.
//!
//!
//! \return None.
//
//*****************************************************************************
void PinTypeUART(unsigned long ulPin,unsigned long ulPinMode)
{
    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for standard operation
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA,PIN_TYPE_STD);
}


//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by I2C peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The I2C pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! the pin.
//!
//!
//! \note This function cannot be used to turn any pin into a I2C pin; it 
//! only sets the pin mode and configures it for proper I2C operation.
//!
//!
//! \return None.
//
//*****************************************************************************
void PinTypeI2C(unsigned long ulPin,unsigned long ulPinMode)
{
    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for open-drain operation with a weak pull-up. 
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA,PIN_TYPE_OD_PU);
}


//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by McSPI peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The McSPI pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin.
//!
//!
//! \note This function cannot be used to turn any pin into a McSPI pin; it 
//! only sets the pin mode and configures it for proper McSPI operation.
//!
//!
//! \return None.
//
//*****************************************************************************
void PinTypeMcSPI(unsigned long ulPin,unsigned long ulPinMode)
{

    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for standard operation
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA|PIN_STRENGTH_4MA,PIN_TYPE_STD);

}


//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by McASP peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The McASP pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin.
//!
//!
//! \note This function cannot be used to turn any pin into a McASP pin; it 
//! only sets the pin mode and configures it for proper McASP operation.
//!
//! \return None.
//
//*****************************************************************************
void PinTypeMcASP(unsigned long ulPin,unsigned long ulPinMode)
{

    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for standard operation
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA|PIN_STRENGTH_4MA,PIN_TYPE_STD);

}


//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by McASP peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The timer PWM pins must be properly configured for the Timer peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin; other configurations may work as well depending upon the
//! board setup (for example, using the on-chip pull-ups).
//!
//!
//! \note This function cannot be used to turn any pin into a timer PWM pin; it 
//! only sets the pin mode and configures it for proper timer PWM operation.
//!
//! \return None.
//
//*****************************************************************************
void PinTypeTimer(unsigned long ulPin,unsigned long ulPinMode)
{

    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for standard operation
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA|PIN_STRENGTH_4MA,PIN_TYPE_STD);
}


//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by Camera peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The Camera pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin.
//!
//!
//! \note This function cannot be used to turn any pin into a Camera pin; it 
//! only sets the pin mode and configures it for proper Camera operation.
//!
//! \return None.
//
//*****************************************************************************
void PinTypeCAM(unsigned long ulPin,unsigned long ulPinMode)
{

    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for standard operation
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA|PIN_STRENGTH_4MA,PIN_TYPE_STD);

}


//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by Camera peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//!
//! The EPI pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin.
//!
//!
//! \note This function cannot be used to turn any pin into an EPI pin; it 
//! only sets the pin mode and configures it for proper EPI operation.
//!
//! \return None.
//
//*****************************************************************************
void PinTypeEPI(unsigned long ulPin,unsigned long ulPinMode)
{

    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin,ulPinMode);

    //
    // Set the pin for standard operation
    //
    PinConfigSet(ulPin,PIN_STRENGTH_2MA|PIN_STRENGTH_4MA,PIN_TYPE_STD);

}

//*****************************************************************************
//
//! Sets the pin mode and configures the pin for use by GPIO peripheral
//!
//! \param ulPin is one of the valid pin.
//! \param ulPinMode is one of the valid pin mode.
//! \param bOpenDrain is one to decide either OpenDrain or STD
//!
//! The GPIO pins must be properly configured for the peripheral to
//! function correctly.  This function provides a typical configuration for
//! those pin.
//!
//!
//! \return None.
//
//*****************************************************************************
void PinTypeGPIO(unsigned long ulPin,unsigned long ulPinMode,tBoolean bOpenDrain)
{

    //
    // Set the pin for standard push-pull operation.
    //
	if(bOpenDrain)
	{
		PinConfigSet(ulPin, PIN_STRENGTH_2MA, PIN_TYPE_OD);
	}
	else
	{
		PinConfigSet(ulPin, PIN_STRENGTH_2MA, PIN_TYPE_STD);
	}
    //
    // Set the pin to specified mode
    //
    PinModeSet(ulPin, ulPinMode);

}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
