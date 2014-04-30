//*****************************************************************************
//
// adc.c - Driver for the ADC module.
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
//! \addtogroup ADC_Analog_to_Digital_Converter_api
//! @{
//
//*****************************************************************************
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_adc.h"
#include "inc/hw_apps_config.h"
#include "interrupt.h"
#include "adc.h"


//*****************************************************************************
//
//! Enables the ADC
//!
//! \param ulBase is the base address of the ADC
//!
//! This function sets the ADC global enable
//!
//! \return None.
//
//*****************************************************************************
void ADCEnable(unsigned long ulBase)
{
  //
  // Set the global enable bit in the control register.
  //  
  HWREG(ulBase + ADC_O_ADC_CTRL) |= 0x1;
}

//*****************************************************************************
//
//! Disable the ADC
//!
//! \param ulBase is the base address of the ADC
//!
//! This function clears the ADC global enable
//!
//! \return None.
//
//*****************************************************************************
void ADCDisable(unsigned long ulBase)
{
  //
  // Clear the global enable bit in the control register.
  // 
  HWREG(ulBase + ADC_O_ADC_CTRL) &= ~0x1 ;
}

//*****************************************************************************
//
//! Enables specified ADC channel
//!
//! \param ulBase is the base address of the ADC
//!
//! This function enables specified ADC channel and configures the 
//! pin as analog pin.
//!
//! \return None.
//
//*****************************************************************************
void ADCChannelEnable(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulCh;
  
  ulCh =  (ulChannel == ADC_CH_0)? 0x02 :
          (ulChannel == ADC_CH_1)? 0x04 :
          (ulChannel == ADC_CH_2)? 0x08 : 0x10;
  
  HWREG(ulBase + ADC_O_ADC_SPARE1) |= ulCh;
}

//*****************************************************************************
//
//! Disables specified ADC channel
//!
//! \param ulBase is the base address of the ADC
//!
//! This function disables specified ADC channel.
//!
//! \return None.
//
//*****************************************************************************
void ADCChannelDisable(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulCh;
  
  ulCh =  (ulChannel == ADC_CH_0)? 0x02 :
          (ulChannel == ADC_CH_1)? 0x04 :
          (ulChannel == ADC_CH_2)? 0x08 : 0x10;
  
  HWREG(ulBase + ADC_O_ADC_SPARE1) &= ~ulCh;
}

//*****************************************************************************
//
//! Enables and registers ADC interrupt handler for specified channel 
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//! \param pfnHandler is a pointer to the function to be called when the
//! ADC channel interrupt occurs.
//!
//! This function enables and registers ADC interrupt handler for specified 
//! channel. Individual interrupt for each channel should be enabled using
//! \sa ADCIntEnable(). It is the interrupt handler's responsibility to clear 
//! the interrupt source.
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! \return None.
//
//*****************************************************************************
void ADCIntRegister(unsigned long ulBase, unsigned long ulChannel, 
                    void (*pfnHandler)(void))
{
  unsigned long ulIntNo;
  
  //
  // Get the interrupt number associted with the specified channel 
  //
  ulIntNo = (ulChannel == ADC_CH_0)? INT_ADCCH0 :
            (ulChannel == ADC_CH_1)? INT_ADCCH1 :
            (ulChannel == ADC_CH_2)? INT_ADCCH2 : INT_ADCCH3;
  
  //
  // Register the interrupt handler
  //
  IntRegister(ulIntNo,pfnHandler);
  
  //
  // Enable ADC interrupt
  //
  IntEnable(ulIntNo);
}


//*****************************************************************************
//
//! Disables and unregisters ADC interrupt handler for specified channel 
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//!
//! This function disables and unregisters ADC interrupt handler for specified 
//! channel. This function also masks off the interrupt in the interrupt 
//! controller so that the interrupt handler no longer is called.
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! \return None.
//
//*****************************************************************************
void ADCIntUnregister(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulIntNo;
  
  //
  // Get the interrupt number associted with the specified channel 
  //
  ulIntNo = (ulChannel == ADC_CH_0)? INT_ADCCH0 :
            (ulChannel == ADC_CH_1)? INT_ADCCH1 :
            (ulChannel == ADC_CH_2)? INT_ADCCH2 : INT_ADCCH3;
  
  //
  // Disable ADC interrupt
  //
  IntDisable(ulIntNo);
  
  //
  // Unregister the interrupt handler
  //
  IntUnregister(ulIntNo);
}

//*****************************************************************************
//
//! Enables individual interrupt sources for specified channel 
//!
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated ADC interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//! - \b ADC_DMA_DONE for DMA done
//! - \b ADC_FIFO_OVERFLOW for FIFO over flow
//! - \b ADC_FIFO_UNDERFLOW for FIFO under flow
//! - \b ADC_FIFO_EMPTY for FIFO empty
//! - \b ADC_FIFO_FULL for FIFO full
//!
//! \return None.
//
//*****************************************************************************
void ADCIntEnable(unsigned long ulBase, unsigned long ulChannel, 
                  unsigned long ulIntFlags)
{
  unsigned long ulOffset;
  unsigned long ulDmaMsk;
 
  //
  // Enable DMA Done interrupt
  //
  if(ulIntFlags & ADC_DMA_DONE)
  {
     ulDmaMsk = (ulChannel == ADC_CH_0)?0x00001000:
                (ulChannel == ADC_CH_1)?0x00002000:
                (ulChannel == ADC_CH_2)?0x00004000:0x00008000;
                
     HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_CLR) = ulDmaMsk;
  }
  
  ulIntFlags = ulIntFlags &  0x0F;
  //
  // Get the interrupt enable register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_irq_en + ulChannel;
  
  //
  // Unmask the specified interrupts
  //
  HWREG(ulBase + ulOffset) |= (ulIntFlags & 0xf);
}


//*****************************************************************************
//
//! Disables individual interrupt sources for specified channel 
//!
//!
//! \param ulBase is the base address of the ADC.
//! \param ulChannel is one of the valid ADC channels
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function disables the indicated ADC interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The parameters\e ulIntFlags and \e ulChannel should be as explained in
//! ADCIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void ADCIntDisable(unsigned long ulBase, unsigned long ulChannel, 
                  unsigned long ulIntFlags)
{
  unsigned long ulOffset;
  unsigned long ulDmaMsk;
  
  //
  // Disable DMA Done interrupt
  //
  if(ulIntFlags & ADC_DMA_DONE)
  {
     ulDmaMsk = (ulChannel == ADC_CH_0)?0x00001000:
                (ulChannel == ADC_CH_1)?0x00002000:
                (ulChannel == ADC_CH_2)?0x00004000:0x00008000;
                
     HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_SET) = ulDmaMsk;
  }
  
  //
  // Get the interrupt enable register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_irq_en + ulChannel;
  
  //
  // Unmask the specified interrupts
  //
  HWREG(ulBase + ulOffset) &= ~ulIntFlags;
}


//*****************************************************************************
//
//! Gets the current channel interrupt status
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//!
//! This function returns the interrupt status of the specified ADC channel.
//!
//! The parameter \e ulChannel should be as explained in \sa ADCIntEnable().
//!
//! \return Return the ADC channel interrupt status,  enumerated as a bit 
//! field of values described in ADCIntEnable()
//
//*****************************************************************************
unsigned long ADCIntStatus(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulOffset;
  unsigned long ulDmaMsk;
  unsigned long ulIntStatus;
  
  //
  // Get DMA Done interrupt status
  //
  ulDmaMsk = (ulChannel == ADC_CH_0)?0x00001000:
            (ulChannel == ADC_CH_1)?0x00002000:
            (ulChannel == ADC_CH_2)?0x00004000:0x00008000;
            
  ulIntStatus = HWREG(APPS_CONFIG_BASE + 
                     APPS_CONFIG_O_DMA_DONE_INT_STS_MASKED)& ulDmaMsk;

  
  //
  // Get the interrupt enable register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_irq_status + ulChannel;
  
  //
  // Read ADC interrupt status
  //
  ulIntStatus |= HWREG(ulBase + ulOffset) & 0xf;
  
  //
  // Return the current interrupt status
  //
  return(ulIntStatus);
}


//*****************************************************************************
//
//! Clears the current channel interrupt sources
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//!
//! This function clears individual interrupt source for the specified 
//! ADC channel.
//!
//! The parameter \e ulChannel should be as explained in \sa ADCIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void ADCIntClear(unsigned long ulBase, unsigned long ulChannel, 
                  unsigned long ulIntFlags)
{
  unsigned long ulOffset; 
  unsigned long ulDmaMsk;
  
  //
  // Clear DMA Done interrupt
  //
  if(ulIntFlags & ADC_DMA_DONE)
  {
     ulDmaMsk = (ulChannel == ADC_CH_0)?0x00001000:
                (ulChannel == ADC_CH_1)?0x00002000:
                (ulChannel == ADC_CH_2)?0x00004000:0x00008000;
                
     HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_ACK) = ulDmaMsk;
  }
  
  //
  // Get the interrupt enable register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_irq_status + ulChannel;
  
  //
  // Clear the specified interrupts
  //
  HWREG(ulBase + ulOffset) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Enables the ADC DMA operation for specified channel
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//!
//! This function enables the DMA operation for specified ADC channel
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! \return None.
//
//*****************************************************************************
void ADCDMAEnable(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulBitMask;
  
  //
  // Get the bit mask for enabling DMA for specified channel
  //
  ulBitMask = (ulChannel == ADC_CH_0)?0x01:
              (ulChannel == ADC_CH_1)?0x04:
              (ulChannel == ADC_CH_2)?0x10:0x40;
              
  //
  // Enable DMA request for the specified channel
  //             
  HWREG(ulBase + ADC_O_adc_dma_mode_en) |= ulBitMask;
}

//*****************************************************************************
//
//! Disables the ADC DMA operation for specified channel
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels
//!
//! This function disables the DMA operation for specified ADC channel
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! \return None.
//
//*****************************************************************************
void ADCDMADisable(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulBitMask;
  
  //
  // Get the bit mask for disabling DMA for specified channel
  //
  ulBitMask = (ulChannel == ADC_CH_0)?0x01:
              (ulChannel == ADC_CH_1)?0x04:
              (ulChannel == ADC_CH_2)?0x10:0x40;
              
  //
  // Disable DMA request for the specified channel
  //             
  HWREG(ulBase + ADC_O_adc_dma_mode_en) &= ~ulBitMask;
}

//*****************************************************************************
//
//! Sets the channel gain for specified ADC channel
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels.
//! \param ucGain specifes the required gain.
//!
//! This function sets the channel gain for specified ADC channel
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! The parameter \e ucGain should be one of the following
//!
//! - \b ADC_GAIN_1X
//! - \b ADC_GAIN_2X
//! - \b ADC_GAIN_3X
//! - \b ADC_GAIN_4X
//!
//! \return None.
//
//*****************************************************************************
void ADCChannelGainSet(unsigned long ulBase, unsigned long ulChannel,
                       unsigned char ucGain)
{
  unsigned long ulOffset;
  
  //
  // Get the gain config register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_gain + ulChannel;
  
  //
  // Set the channel gain
  //
  HWREG(ulBase + ulOffset) = ((HWREG(ulBase + ulOffset) & ~0x3) | ucGain);
}

//*****************************************************************************
//
//! Gets the current channel gain for specified ADC channel
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels.
//!
//! This function sets the channel gain for specified ADC channel
//!
//! The parameter \e ulChannel should as explained in ADCChannelGainSet()
//!
//! \returns Returns the current channel gain for the specified channel, 
//! eumerated as values described in ADCChannelGainSet()
//
//*****************************************************************************
unsigned char ADCChannleGainGet(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulOffset;
  
  //
  // Get the gain config register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_gain + ulChannel;
  
  //
  // Return the channel gain
  //
  return(HWREG(ulBase + ulOffset) & 0x3);
}


//*****************************************************************************
//
//! Configures the ADC internal timer
//!
//! \param ulBase is the base address of the ADC
//! \param ulValue is wrap arround value of the timer
//!
//! This function Configures the ADC internal timer. The ADC timer is a 17 bit 
//! used to timestamp the ADC data samples internally. 
//! User can read the timestamp along with the sample from the FIFO register(s). 
//! Each sample in the FIFO contains 14 bit actual data and 18 bit timestamp
//!
//! The parameter \e ulValue can take any value between 0 - 2^17
//!
//! \returns None.
//
//*****************************************************************************
void ADCTimerConfig(unsigned long ulBase, unsigned long ulValue)
{
  unsigned long ulReg;
  
  //
  // Read the currrent config
  //
  ulReg =  HWREG(ulBase + ADC_O_adc_timer_configuration);
  
  //
  // Mask and set timer count field
  //
  ulReg = ((ulReg & ~0x1FFFF) | (ulValue & 0x1FFFF));  
  
  //
  // Set the timer count value
  //
  HWREG(ulBase + ADC_O_adc_timer_configuration) = ulReg;
}

//*****************************************************************************
//
//! Resets ADC internal timer
//!
//! \param ulBase is the base address of the ADC
//!
//! This function resets 17-bit ADC internal timer
//!
//! \returns None.
//
//*****************************************************************************
void ADCTimerReset(unsigned long ulBase)
{
  //
  // Reset the timer
  //
  HWREG(ulBase + ADC_O_adc_timer_configuration) |= (1 << 24);
}

//*****************************************************************************
//
//! Enables ADC internal timer
//!
//! \param ulBase is the base address of the ADC
//!
//! This function enables 17-bit ADC internal timer
//!
//! \returns None.
//
//*****************************************************************************
void ADCTimerEnable(unsigned long ulBase)
{
  //
  // Enable the timer
  //
  HWREG(ulBase + ADC_O_adc_timer_configuration) |= (1 << 25);
}

//*****************************************************************************
//
//! Disables ADC internal timer
//!
//! \param ulBase is the base address of the ADC
//!
//! This function disables 17-bit ADC internal timer
//!
//! \returns None.
//
//*****************************************************************************
void ADCTimerDisable(unsigned long ulBase)
{
  //
  // Disable the timer
  //
  HWREG(ulBase + ADC_O_adc_timer_configuration) &= ~(1 << 25);
}

//*****************************************************************************
//
//! Gets the current value of ADC internal timer
//!
//! \param ulBase is the base address of the ADC
//!
//! This function the current value of 17-bit ADC internal timer
//!
//! \returns Return the current value of ADC internal timer.
//
//*****************************************************************************
unsigned long ADCTimerValueGet(unsigned long ulBase)
{
  return(HWREG(ulBase + ADC_O_adc_timer_current_count));
}

//*****************************************************************************
//
//! Gets the current FIFO level for specified ADC channel
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels.
//!
//! This function returns the current FIFO level for specified ADC channel.
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! \returns Return the current FIFO level for specified channel
//
//*****************************************************************************
unsigned char ADCFIFOLvlGet(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulOffset;
  
  //
  // Get the fifo level register offset for specified channel
  //
  ulOffset = ADC_O_adc_ch0_fifo_lvl + ulChannel;
  
  //
  // Return FIFO level
  //
  return(HWREG(ulBase + ulOffset) & 0x7);
}

//*****************************************************************************
//
//! Reads FIFO for specified ADC channel
//!
//! \param ulBase is the base address of the ADC
//! \param ulChannel is one of the valid ADC channels.
//!
//! This function returns one data sample from the channel fifo as specified by
//! \e ulChannel parameter.
//!
//! The parameter \e ulChannel should be one of the following
//!
//! - \b ADC_CH_0 for channel 0
//! - \b ADC_CH_1 for channel 1
//! - \b ADC_CH_2 for channel 2
//! - \b ADC_CH_3 for channel 3
//!
//! \returns Return one data sample from the channel fifo.
//
//*****************************************************************************
unsigned long ADCFIFORead(unsigned long ulBase, unsigned long ulChannel)
{
  unsigned long ulOffset;
  
  //
  // Get the fifo register offset for specified channel
  //
  ulOffset = ADC_O_channel0FIFODATA + ulChannel;
  
  //
  // Return FIFO level
  //
  return(HWREG(ulBase + ulOffset));
}


//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
