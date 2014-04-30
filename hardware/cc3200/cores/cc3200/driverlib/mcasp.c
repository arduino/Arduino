//*****************************************************************************
//
// mcasp.c - Driver for the Multi Channel Audio Serial Port.
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
//! \addtogroup McASP_Multichannel_Audio_Serial_Port_api
//! @{
//
//*****************************************************************************
#include "inc/hw_types.h"
#include "inc/hw_mcasp.h"
#include "inc/hw_apps_config.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "debug.h"
#include "interrupt.h"
#include "mcasp.h"

//*****************************************************************************
// Macros
//*****************************************************************************
#define MCASP_HWREG(offset)	HWREG(ulBase + offset)
#define MCASP_HCLK_INTRL        0x80000000
#define MCASP_CLK_INTRL         0x00000020

#define	MCASP_0_WFIFOCTL	0x00001000
#define	MCASP_0_WFIFOSTS	0x00001004
#define	MCASP_0_RFIFOCTL	0x00001008
#define	MCASP_0_RFIFOSTS	0x0000100C


//*****************************************************************************
//
//! Reset the McASP module
//!
//!
//! This function resets the McASP module.
//!
//! \return None.
//
//*****************************************************************************
void McASPReset(unsigned long ulBase)
{
  //
  // Reset McASP
  //
  MCASP_HWREG(MCASP_O_GBLCTL )=0x00000000;
  
  //
  // Wait for reset to complete
  //
  while(MCASP_HWREG(MCASP_O_GBLCTL))
  {
    
  }
}

//*****************************************************************************
//
//! Set the McASP pin as output or input.
//!
//! \param ulPin is on of the valid McASP pin.
//! \param ulPinDir set the direction on the pin.
//!
//! This function sete the McASP pin to function as input or output.
//! The parameter \e ulPin can be one of the following :
//! - \b MCASP_PIN_DATA_0
//! - \b MCASP_PIN_DATA_1
//! - \b MCASP_PIN_AFSX
//! - \b MCASP_PIN_ACLKX
//!
//! The parameter \e ulPinDir should be one of the following :
//! - \b MCASP_PIN_OUT
//! - \b MCASP_PIN_IN
//!
//! \return None.
//
//*****************************************************************************
void McASPPinDirSet(unsigned long ulBase, unsigned long ulPin,unsigned long ulPinDir)
{
  unsigned long ulReg;
  
  //
  // Make all pins to McASP
  //
  MCASP_HWREG(MCASP_O_PFUNC)=0;
  
  //
  // Read direction register
  //
  ulReg=MCASP_HWREG(MCASP_O_PDIR);
  
  //
  // Mask and set pin direction
  //
  ulReg|=((ulReg & ~(1 << ulPin))|((ulPinDir & 0x1) << ulPin));
  
  //
  // Write the configuration
  //
  MCASP_HWREG(MCASP_O_PDIR)=ulReg;
}

//*****************************************************************************
//
//! Get the McASP pin direction
//!
//! \param ulPin is on of the valid McASP pin.
//!
//! This function gets the current McASP pin direction.
//! The parameter \e ulPin can be one of the following :
//! - \b MCASP_PIN_DATA_0
//! - \b MCASP_PIN_DATA_1
//! - \b MCASS_PIN_AFSX
//! - \b MCASS_PIN_ACLKX
//!
//! \return \b MCASP_PIN_OUT if pin is an output pin else \b MCASP_PIN_IN
//
//*****************************************************************************
unsigned long McASPPinDirGet(unsigned long ulBase, unsigned long ulPin)
{
  unsigned long ulReg;
  
  //
  // Read direction register
  //
  ulReg=MCASP_HWREG(MCASP_O_PDIR);

  //
  // Return the value
  //
  return ((ulReg & (1 << ulPin))? MCASP_PIN_OUT : MCASP_PIN_IN);
}

//*****************************************************************************
//
//! Enables the McASP internal module
//!
//! \param ulFlag is the bit mask of modules to be enabled
//!
//! This function enables the McASP internal module based on the flag passed.
//! The parameter \e ulFlag is logical OR of one or more of the following :
//!
//! - \b MCASP_GBL_RCLK
//! - \b MCASP_GBL_RHCLK
//! - \b MCASP_GBL_RSERCLR
//! - \b MCASP_GBL_RSM
//! - \b MCASP_GBL_RFSYNC
//! - \b MCASP_GBL_XCLK
//! - \b MCASP_GBL_XHCLK
//! - \b MCASP_GBL_XSERCLR
//! - \b MCASP_GBL_XSM
//! - \b MCASP_GBL_XFSYNC
//!
//! \return None.
//
//*****************************************************************************
void McASPGBLEnable(unsigned long ulBase, unsigned long ulFlag)
{
  unsigned long ulReg;
  
  //
  // Read global control register
  //
  ulReg=MCASP_HWREG(MCASP_O_GBLCTL);
  
  //
  // Remove the sub modules reset as specified by ulFlasg parameter
  //
  ulReg |= ulFlag;
  
  //
  // Write the configuration
  //
  MCASP_HWREG(MCASP_O_GBLCTL) = ulReg;
  
  //
  // Wait for write completeion
  //
  while(MCASP_HWREG(MCASP_O_GBLCTL)!=ulReg)
  {
    
  }
}

//*****************************************************************************
//
//! Disable the McASP internal module
//!
//! \param ulFlag is the bit mask of modules to be disabled
//!
//! This function disable the McASP internal module based on the flag passed.
//! The parameter \e ulFlag is logical OR of one or more of the following :
//!
//! - \b MCASP_GBL_RCLK
//! - \b MCASP_GBL_RHCLK
//! - \b MCASP_GBL_RSERCLR
//! - \b MCASP_GBL_RSM
//! - \b MCASP_GBL_RFSYNC
//! - \b MCASP_GBL_XCLK
//! - \b MCASP_GBL_XHCLK
//! - \b MCASP_GBL_XSERCLR
//! - \b MCASP_GBL_XSM
//! - \b MCASP_GBL_XFSYNC
//!
//! \return None.
//
//*****************************************************************************
void McASPGBLDisable(unsigned long ulBase, unsigned long ulFlag)
{
  unsigned long ulReg;
  
  //
  // Read global control register
  //
  ulReg=MCASP_HWREG(MCASP_O_GBLCTL);
  
  //
  // Enable reset for specified sub module
  //
  ulReg &= ~ulFlag;
  
  //
  // Write th configuration
  //
  MCASP_HWREG(MCASP_O_GBLCTL)=ulReg;
  
  //
  // Wait for write completeion
  //
  while(MCASP_HWREG(MCASP_O_GBLCTL)!=ulReg)
  {
    
  }
}

//*****************************************************************************
//
//! Sets the Transmit bit stream format.
//!
//! \param ulFdelay is the delay between Fsync and first slot.
//! \param ulPad specifies the the padding of data bits.
//! \param ulSlot is the slot size in bits within the frame.
//! \param ulWord is the word size in bits within the slot
//! \param ulAlign is the output data alignment.
//! \param ulOrder is the order of output data.
//! \param ulDspRep is the DSP representation of input data.
//!
//! The function configures the Transmit formatter.
//!
//! The parameter \e ulFdealy This is the delay between the frame sync active
//! edge and the start of the slot and can be one of \b MCASP_FMT_FSDLY_NONE,
//! \b MCASP_FMT_FSDLY_1 and \b MCASP_FMT_FSDLY_2.
//!
//! The parameter \e ulPad gives the extra bit padded to actual data to form
//! the slot. This can be one of the following parameters :
//! - \b MCASP_FMT_PAD_0   - Pad with all 0s
//! - \b MCASP_FMT_PAD_1   - Pad with all 1s
//! - \b MCASP_FMT_DBIT_n  - Pad with data bit at bit position n. ( n=0 to 31)
//!
//! The parameter \e ulSlot sets the slot size in bits within each frame and
//! can take following values :
//! - \b MCASP_FMT_SSZ_n   - where n can be 8, 12, 16, 20, 24, 32
//!
//! The parametaer \e ulSlot sets the slot size in bits within each slot rounded
//! up to nearest multiple of 4 and can take following values :
//! - \b MCASP_FMT_WSZ_n   - where n can be 8, 12, 16, 20, 24, 32
//!
//! To set the actual word size see \sa McASPTxValidBitSet().
//!
//!
//! \e ulAlign specefies the alignment of the output data and can be one
//! of \b MCASP_FMT_ALIGN_LFT and \b MCASP_FMT_ALIGN_RHT.
//!
//! \e ulOrder specefies the order of output data. This can be one of the
//! following :
//! - \b MCASP_FMT_FST_LSB
//! - \b MCASP_FMT_FST_MSB
//!
//! The parameter \e ulDspRep gives the input data representation and can take
//! one of following values :
//! - \b MCASP_FMT_Q31   - For Q31 Fraction Representation
//! - \b MCASP_FMT_INT   - For Interger Representation
//!
//! \return None.
//
//*****************************************************************************

void McASPTxFMTConfig(unsigned long ulBase, unsigned long ulFdelay,unsigned long ulPad,
                       unsigned long ulSlot, unsigned long ulWord,
		       unsigned long ulAlign, unsigned long ulOrder,
		       unsigned long ulDspRep)
{
  unsigned long ulReg;
  unsigned long ulFlag, ulRot;
  unsigned long ulSlotSize, ulWordSize;


  //
  // Read Tx format register
  //
  ulReg=MCASP_HWREG(MCASP_O_TXFMT);
  
  //
  // Claculate the Slot size and work length from the 
  // passed parameter
  //
  ulSlotSize = (((ulSlot >> 4)+1) << 1);
  ulWordSize = (ulWord << 2);
  ulWord = ulWord & 0x7;

  //
  // Check for requested format
  //
  if(ulDspRep == MCASP_FMT_Q31)
  {
    //
    // Check the order, LSB or MSB first
    //
    if(ulOrder == MCASP_FMT_FST_MSB)
    {
      //
      // Check the alignment requirement
      //
      if(ulAlign == MCASP_FMT_ALIGN_LFT)
      {
        //
        // Set rotatin to zero for left alignment
        //
        ulRot = 0;
      }
      else
      {
        //
        // Set rotation for right alignment
        //
        ulRot = (ulSlotSize-ulWordSize);
      }
    }
    else
    {
      //
      // Check the alignment requirement
      //
      if((ulAlign == MCASP_FMT_ALIGN_LFT))
      {
        //
        // Set rotation for left alignment
        //
        ulRot = (((32-ulWordSize)));
      }
      else
      {
        //
        // Set rotation for right alignment
        //
        ulRot = (((32-ulSlotSize)));
      }
    }
  }
  else // For integer data format
  {
    //
    // Check the alignment requirement
    //
    if(ulOrder == MCASP_FMT_FST_MSB)
    {
      if(ulAlign == MCASP_FMT_ALIGN_LFT)
      {
              ulRot = ulWordSize;
      }
      else
      {
              ulRot = (ulSlotSize);
      }
    }
    else
    {
      if((ulAlign == MCASP_FMT_ALIGN_LFT))
      {
              ulRot = 0;
      }
      else
      {
              ulRot=((32-(ulSlotSize - ulWordSize))%32);
      }
    }
  }

  //
  // Mask and set the format
  //
  ulFlag = ((ulRot >> 2) | ulSlot | ulPad | ulOrder | ulFdelay);
  ulReg = ((ulReg & ~(MCASP_TXFMT_XDATDLY_M |
                  MCASP_TXFMT_XPAD_M |
                  MCASP_TXFMT_XRVRS |
                  MCASP_TXFMT_XPBIT_M |
                  MCASP_TXFMT_XSSZ_M |
                  MCASP_TXFMT_XBUSEL |
                  MCASP_TXFMT_XROT_M)) | ulFlag);

  //
  // Write the configuration
  //
  MCASP_HWREG(MCASP_O_TXFMT) = ulReg;

}

//*****************************************************************************
//
//! Sets the Receive bit stream format.
//!
//! \param ulFdelay is the delay between Fsync and first slot.
//! \param ulPad specifies the the padding of data bits.
//! \param ulSlot is the slot size in bits within the frame.
//! \param ulWord is the word size in bits within the slot
//! \param ulAlign is the input data alignment.
//! \param ulOrder is the order of input data.
//! \param ulDspRep is the DSP representation of output data.
//!
//! The function configures the Receive formatter.
//!
//! The parameter \e ulFdealy This is the delay between the frame sync active
//! edge and the start of the slot and can be one of \b MCASP_FMT_FSDLY_NONE,
//! \b MCASP_FMT_FSDLY_1 and \b MCASP_FMT_FSDLY_2.
//!
//! The parameter \e ulPad gives the extra bit padded to actual data to form
//! the slot. This can be one of the following parameters :
//! - \b MCASP_FMT_PAD_0   - Pad with all 0s
//! - \b MCASP_FMT_PAD_1   - Pad with all 1s
//! - \b MCASP_FMT_DBIT_n  - Pad with data bit at bit position n. ( n=0 to 31)
//!
//! The parametaer ulSlot sets the slot size in bits within each frame and
//! can take following values :
//! - \b MCASP_FMT_SSZ_n   - where n can be 8, 12, 16, 20, 24, 32
//!
//! The parametaer ulSlot sets the slot size in bits within each slot rounded
//! up to nearest multiple of 4 and can take following values :
//! - \b MCASP_FMT_WSZ_n   - where n can be 8, 12, 16, 20, 24, 32
//!
//! To set the actual word size see \sa McASPRxValidBitSet().
//!
//!
//! ulAlign specefies the alignment of the input data and can be one
//! of \b MCASP_FMT_ALIGN_LFT and \b MCASP_FMT_ALIGN_RHT.
//!
//! ulOrder specefies the order of input data. This can be one of the
//! following :
//! - \b MCASP_FMT_FIRST_LSB
//! - \b MCASP_FMT_FIRST_MSB
//!
//! The parameter \e ulDspRep gives the output data representation and can take
//! one of following values :
//! - \b MCASP_FMT_Q31   - For Q31 Fraction Representation
//! - \b MCASP_FMT_INT   - For Interger Representation
//!
//! \return None.
//
//*****************************************************************************

void McASPRxFMTConfig(unsigned long ulBase, unsigned long ulFdelay,unsigned long ulPad,
                       unsigned long ulSlot, unsigned long ulWord,
		       unsigned long ulAlign, unsigned long ulOrder,
		       unsigned long ulDspRep)
{
  unsigned long ulReg;
  unsigned long ulFlag, ulRot;
  unsigned long ulSlotSize, ulWordSize;



  //
  // Read Rx format register
  //
  ulReg=MCASP_HWREG(MCASP_O_RXFMT);
  
  //
  // Claculate the Slot size and work length from the 
  // passed parameter
  //  
  ulSlotSize = (((ulSlot >> 4)+1) << 1);
  ulWordSize = (ulWord << 2);
  ulWord = ulWord & 0x7;

  //
  // For Q31 format
  //
  if(ulDspRep == MCASP_FMT_Q31)
  {
    //
    // Check alignment requirement
    //
    if(ulOrder == MCASP_FMT_FST_MSB)
    {
      if(ulAlign == MCASP_FMT_ALIGN_LFT)
      {
        ulRot= ulSlotSize;
      }
      else
      {
        ulRot=ulWordSize;
      }
    }
    else
    {
      if((ulAlign == MCASP_FMT_ALIGN_LFT))
      {
        ulRot=((32-(ulSlotSize - ulWordSize))%32);
      }
      else
      {
        ulRot=0;
      }
    }
  }
  else // for Integer format
  {
    if(ulOrder == MCASP_FMT_FST_MSB)
    {
      if(ulAlign == MCASP_FMT_ALIGN_LFT)
      {
        ulRot=(ulSlotSize-ulWordSize);
      }
      else
      {
        ulRot=0;
      }
    }
    else
    {
      if((ulAlign == MCASP_FMT_ALIGN_LFT))
      {
        ulRot=(32-ulSlotSize);
      }
      else
      {
        ulRot=(32-ulWordSize);
      }
    }
  }

  //
  // Mask and set the format
  //
  ulFlag = ((ulRot >> 2) |ulSlot | ulPad | ulOrder | ulFdelay);
  ulReg=((ulReg & ~(MCASP_RXFMT_RDATDLY_M |
                  MCASP_RXFMT_RPAD_M |
                  MCASP_RXFMT_RRVRS |
                  MCASP_RXFMT_RPBIT_M |
                  MCASP_RXFMT_RSSZ_M |
                  MCASP_RXFMT_RBUSEL |
                  MCASP_RXFMT_RROT_M)) | ulFlag);

  //
  // Write the configuration
  //
  MCASP_HWREG(MCASP_O_RXFMT) = ulReg;

}

//*****************************************************************************
//
//! Sets the valid bits in the Transmit slot
//!
//! \param ulValidMask is the bit mask of valid bis in the transmit slot
//!
//! This function takes a 32 bit bit mask and sets the valid bits in a slot.
//! Each bit in the bit mask corresponds to a single bit in a slot and
//! is valid if the corresponding bit in the bit mask is set to 1.
//!
//! \return None.
//
//*****************************************************************************
void McASPTxValidBitSet(unsigned long ulBase, unsigned long ulValidMask)
{
  //
  // Set the valid bit in a Tx slot
  //
  MCASP_HWREG(MCASP_O_TXMASK) = ulValidMask;
}

//*****************************************************************************
//
//! Gets the valid bits in the Transmit slot
//!
//! This function returns a 32 bit bit mask of valid bits in a slot.
//! Each bit in the bit mask corresponds to a single bit in a slot and
//! is valid if the corresponding bit in the bit mask is set to 1.
//!
//! \return Returns bit mask of valid bits.
//
//*****************************************************************************
unsigned long McASPTxValidBitGet(unsigned long ulBase)
{
  //
  // Return the valid bit in a Tx slot
  //
  return(MCASP_HWREG(MCASP_O_TXMASK));
}

//*****************************************************************************
//
//! Sets the valid bits in the Receive slot
//!
//! \param ulValidMask is the bit mask of valid bis in the receive slot
//!
//! This function takes a 32 bit bit mask and sets the valid bits in a slot.
//! Each bit in the bit mask corresponds to a single bit in a slot and
//! is valid if the corresponding bit in the bit mask is set to 1.
//!
//! \return None.
//
//*****************************************************************************
void McASPRxValidBitSet(unsigned long ulBase, unsigned long ulValidMask)
{  
  //
  // Set the valid bit in a Rx slot
  //
  MCASP_HWREG(MCASP_O_RXMASK) = ulValidMask;
}


//*****************************************************************************
//
//! Gets the valid bits in the Receive slot
//!
//! This function returns a 32 bit bit mask of valid bits in a slot.
//! Each bit in the bit mask corresponds to a single bit in a slot and
//! is valid if the corresponding bit in the bit mask is set to 1.
//!
//! \return Returns bit mask of valid bits.
//
//*****************************************************************************
unsigned long McASPRxValidBitGet(unsigned long ulBase)
{
  //
  // Return the valid bit in a Rx slot
  //
  return(MCASP_HWREG(MCASP_O_RXMASK));
}

//*****************************************************************************
//
//! Configure the McASP Transmit and Receive Bit Clock
//!
//! \param ulMcASPClk is the rate of the clock supplied to McASP module.
//! \param ulBitClk is the required Bit clock output
//! \param ulClkPol selects the edge at which Tx sends data.
//!
//! This function configure the internal clock dividers to produce the required
//! output bit clk from the McASP module input clock.
//!
//! The parameter \e ulClkPol selects the edge at which Tx sends data.
//! This canbe one of the following
//!
//! - \b MCASP_CLK_POL_RISE - Send data at Rising edge, Receive at Falling edge
//! - \b MCASP_CLK_POL_FALL - Send data at Falling edge, Receive at Rising edge
//!
//! \return None.
//
//*****************************************************************************
void McASPClkConfig(unsigned long ulBase, unsigned long ulMcASPClk, unsigned long ulBitClk,
                             unsigned ulClkPol)
{
  unsigned long ulHClkDiv;
  unsigned long ulClkDiv=0;
  unsigned ulReg;


  //
  // Calculate HCLK divider
  //
  ulHClkDiv = ((ulMcASPClk/ulBitClk)-1);

  //
  // Check if HClk divider is overflowing
  //
  if(ulHClkDiv > 0xFFF)
  {
    ulHClkDiv = 0xFFF;
    
    //
    // Calculate clock divider
    //
    ulClkDiv = ((ulMcASPClk/(ulBitClk * (ulHClkDiv + 1))) & 0x1F);
  }


  //
  // Read clock divider register
  //
  ulReg = MCASP_HWREG(MCASP_O_ACLKXCTL);
  
  //
  // Mask and set clk divider and polarity
  //
  ulReg = (ulReg & ~(MCASP_ACLKXCTL_CLKXP |
                  MCASP_ACLKXCTL_ASYNC |
                  MCASP_ACLKXCTL_CLKXDIV_M));
  
  ulReg = (ulReg |MCASP_ACLKXCTL_CLKXM | ulClkDiv | ulClkPol);
  MCASP_HWREG(MCASP_O_ACLKXCTL) = ulReg;


  
  //
  // Read HClock divider
  //
  ulReg=MCASP_HWREG(MCASP_O_AHCLKXCTL);
  
  //
  // Mask and set clk divider and polarity
  //
  ulReg=(ulReg & ~(MCASP_AHCLKXCTL_HCLKXP |
                  MCASP_AHCLKXCTL_HCLKXDIV_M));

  ulReg = (ulReg | MCASP_AHCLKXCTL_HCLKXM | ulHClkDiv);
  MCASP_HWREG(MCASP_O_AHCLKXCTL)=ulReg;

}


//*****************************************************************************
//
//! Configure the Transmit and Receive Frame Sync
//!
//! \param ulFSyncMode is the frame sunc mode
//! \param ulWidth sets the frame Sync duration
//! \param ulPol is the frame Sync polarity
//! \param bExtrn select external frame sync.
//!
//! This function configures the Transmit and Receive frame sync.
//! The parameter \e ulFSyncMode can be
//! - \b MCASP_FS_MODE_BURST  - Burst Mode.
//! - \b MCASP_FS_MODE_I2S    - I2S Mode
//! - \b MCASP_FS_MODE_TDM_n  - n slot TDM mode, wherer n varies from 2 to 32.
//!
//! Parameter \e ulWidth sets the Frame Sync duration and is ignored if
//! burst or I2S mode is selected. It is any one of the following :
//! - \b MCASP_FS_WIDTH_BIT   - Frame Sync duration is 1 bit
//! - \b MCASP_FS_WIDTH_WORD  - Frame Sync duration is 1 word
//!
//! \e ulPol selects the polarity of Frame sync. Ignored if I2S mode is
//! selected
//!
//! - \b MCASP_FS_POL_RISE - Rising Edge
//! - \b MCASP_FS_POL_FALL - Falling Edge
//!
//! Set \e bExtrn to \b true if the frame sync is external else \b false.
//!
//! \return None.
//
//*****************************************************************************
void McASPFSyncConfig(unsigned long ulBase, unsigned long ulFSyncMode,unsigned long ulWidth,
                        unsigned long ulPol,tBoolean bExtrn)
{
  unsigned long ulFlag = 0;

  //
  // Check for require mode
  //
  if(ulFSyncMode == MCASP_FS_MODE_BURST)
  {
    ulWidth = MCASP_FS_WIDTH_BIT;
  }
  else if(ulFSyncMode == MCASP_FS_MODE_I2S)
  {
    //
    // For I2S, Frame sync width is always a frame and polarity
    // is falling edge
    //
    ulWidth = MCASP_FS_WIDTH_WORD;
    ulPol = MCASP_FS_POL_FALL;
  }

  //
  // Create the flag
  //
  ulFlag = ulFSyncMode;
  ulFlag |= ulWidth;
  ulFlag |= ulPol;
  ulFlag |= (bExtrn == false)?0x00000002:0;

  //
  // Configure the Tx Frame Sync
  //
  MCASP_HWREG(MCASP_O_TXFMCTL) = ulFlag;

  //
  // Configure the Rx Frame Sync
  //
  MCASP_HWREG(MCASP_O_RXFMCTL) = ulFlag;
}



//*****************************************************************************
//
//! Enable Serializer in specfic mode
//!
//! \param ulDataPin is one of the valid McASP Data pin.
//! \param ulSerMode is a valid serializer mode.
//! \param ulInactLvl is state of data pin when serializer is inactive.
//!
//! This function takes McASP data pin as one of the parameter and enables the
//! the corresponding serializer with the specified configuration.
//!
//! The parameter \e ulPin can be \b MCASP_PIN_DATA_0 or \b MCASP_PIN_DATA_1.
//! The \e ulSerMode cabe be one of the following :
//! - \b MCASP_SER_MODE_TX     - Transmitter
//! - \b MCASP_SER_MODE_RX     - Receiver
//!
//!
//! The \e ulInactLvl parameter can be on of the following :
//! - \b MCASP_INACT_TRI - Pin tri-stated when inactive.
//! - \b MCASP_INACT_0   - Pin pulled low when inactive.
//! - \b MCASP_INACT_1   - Pin Pulled high when inactive.
//!
//! \return None.
//
//*****************************************************************************

void McASPSerEnable(unsigned long ulBase, unsigned long ulDataPin, unsigned long ulSerMode,
                       unsigned long ulInactLvl)
{
  unsigned long ulReg;

  //
  // Only SERDES 0 and 1 (i.e. Data line  0 and 1 ) are supported.
  //
  if((ulDataPin == MCASP_PIN_DATA_0) || (ulDataPin == MCASP_PIN_DATA_1))
  {
    //
    // Shift and get register address.
    //
    ulDataPin = ulDataPin << 2;
    
    //
    // Read the corresponding serdes register
    //
    ulReg = MCASP_HWREG(MCASP_O_XRSRCTL0 + ulDataPin);
    
    //
    // Mask and set active level and mode (Tx or Rx) mode of operation
    //
    ulReg = ((ulReg & ~(0x3F))|((ulSerMode | ulInactLvl)& 0x3F));
    
    //
    // Write the configuration into the register
    //
    MCASP_HWREG(MCASP_O_XRSRCTL0 + ulDataPin) = ulReg;
  }
}

//******************************************************************************
//
//! Disable the Serializer
//!
//! \param ulDataPin is one of the valid McASP Data pin.
//!
//! This function will disable the serializer specified but \b ulDataPin
//!
//! \return none.
//
//*****************************************************************************
void McASPSerDisable(unsigned long ulBase, unsigned long ulDataPin)
{
  //
  // Only SERDES 0 and 1 (i.e. Data line  0 and 1 ) are supported.
  //
  if((ulDataPin == MCASP_PIN_DATA_0) || (ulDataPin == MCASP_PIN_DATA_1))
  {
    //
    // Calculate serdes register
    //
    ulDataPin = ulDataPin << 2;
    
    //
    // Disable specified SERDES
    //
    MCASP_HWREG(MCASP_O_XRSRCTL0 + ulDataPin) &= ~MCASP_XRSRCTL0_SRMOD_M;
  }
}

//*****************************************************************************
//
//! Send data on a particular Tx data pin
//!
//! \param ulDataPin is one of the valid Tx data pin.
//! \param ulData is the data to be transmitted.
//!
//! This function sends data on data pin specified by \b ulDataPin.
//!
//! \return 0 on success, -1 otherwise.
//
//*****************************************************************************
long McASPSendNonBlocking(unsigned long ulBase, unsigned long ulDataPin,unsigned long ulData)
{

  ulDataPin = ulDataPin << 2;

  //
  // Send Data if fifo has free space
  //
  if( MCASP_HWREG(MCASP_O_TXSTAT) & MCASP_INT_XDATA)
  {
    //
    // Write data into the FIFO
    //
    MCASP_HWREG(MCASP_O_TXBUF0 + ulDataPin) = ulData;
    return 0;
  }

  //
  // FIFO is full
  //
  return(-1);
}

//*****************************************************************************
//
//! Send data on a particular Tx data pin
//!
//! \param ulDataPin is one of the valid Tx data pin.
//! \param ulData is the data to be transmitted.
//!
//! This function sends data on data pin specified by \b ulDataPin. The
//! function will not return until the data is send. Trying to send data
//! on a data pin configured as Rx will cause the function to go into
//! infinite loop
//!
//! \return None.
//
//*****************************************************************************
void McASPSend(unsigned long ulBase, unsigned long ulDataPin, unsigned long ulData)
{

  ulDataPin = ulDataPin << 2;

  //
  // Wait for free space in fifo
  //
  while(!( MCASP_HWREG(MCASP_O_TXSTAT) & MCASP_INT_XDATA))
  {

  }
  
  //
  // Write Data into the FIFO
  //
  MCASP_HWREG(MCASP_O_TXBUF0 + ulDataPin) = ulData;

}

//*****************************************************************************
//
//! Receive data from a particular Rx pin
//!
//! \param ulDataPin is one of the valid Rx data pin.
//! \param ulData is the data to be transmitted.
//!
//! This function receives data from data pin specified by \b ulDataPin.
//!
//! \return 0 on success, -1 otherwise.
//
//*****************************************************************************
long McASPRecvNonBlocking(unsigned long ulBase, unsigned long ulDataPin, unsigned long *ulData)
{
  //
  // left shift by 4
  //
  ulDataPin = ulDataPin << 2;

  //
  // Check if data is available in FIFO
  //
  if(MCASP_HWREG(MCASP_O_RXSTAT) & MCASP_RXSTAT_RDATA)
  {
    //
    // Read the Data
    //
    *ulData = MCASP_HWREG(MCASP_O_RXBUF0 + ulDataPin);
    return 0;
  }

  //
  // FIFO is empty
  //
  return -1;
}



//*****************************************************************************
//
//! Receive data from a particular Rx pin
//!
//! \param ulDataPin is one of the valid Rx data pin.
//! \param ulData is the data to be transmitted.
//!
//! This function receives data from data pin specified by \b ulDataPin. The
//! function will not return until the data a new data is available. Trying
//! to receive on a data pin configured as Tx will cause the function to go
//! into infinite loop.
//!
//! \return none.
//
//*****************************************************************************
void McASPRecv(unsigned long ulBase, unsigned long ulDataPin, unsigned long *ulData)
{
  //
  // left shift by 4
  //
  ulDataPin = ulDataPin << 2;

  //
  // Wait for atleat on word in FIFO
  //
  while(!(MCASP_HWREG(MCASP_O_RXSTAT) & MCASP_RXSTAT_RDATA))
  {

  }

  //
  // Read the Data
  //
  *ulData = MCASP_HWREG(MCASP_O_RXBUF0 + ulDataPin);
}

//*****************************************************************************
//
//! Sets the active slots within a Transmit frame.
//!
//! \param ulMask is the bit mask of active slots.
//!
//! This function sets the active slots within a frame.
//! The parameter \e ulValidMask is the bit mask of active slots within a frame
//! and each bit that is set 1 sets the corresponding slot as active.
//!
//! \return None.
//
//*****************************************************************************
void McASPTxActiveSlotSet(unsigned long ulBase, unsigned long ulMask)
{
  //
  // Set active slot(s) in Transmit frame
  //
  MCASP_HWREG(MCASP_O_TXTDM) = ulMask;
}

//*****************************************************************************
//
//! Gets the active slots within a Transmit frame.
//!
//!
//! This function returns the active slots within a transmit frame.
//!
//! \return Returns a bitmap of activ slots.
//
//*****************************************************************************
unsigned long McASPTxActiveSlotGet(unsigned long ulBase)
{
  //
  // Get active slot(s) in transmit frame
  //
  return(MCASP_HWREG(MCASP_O_TXTDM));
}


//*****************************************************************************
//
//! Sets the active slots within a Receive frame.
//!
//! \param ulMask is the bit mask of active slots.
//!
//! This function sets the active slots within a receive frame.
//! The parameter \e ulValidMask is the bit mask of active slots within a frame
//! and each bit that is set 1 sets the corresponding slot as active.
//!
//! \return None.
//
//*****************************************************************************
void McASPRxActiveSlotSet(unsigned long ulBase, unsigned long ulMask)
{
  //
  // Set active slot(s) in receive frame
  //
  MCASP_HWREG(MCASP_O_RXTDM) = ulMask;
}

//*****************************************************************************
//
//! Get the active slots within a Receive frame.
//!
//! \param ulMask is the bit mask of active slots.
//!
//! This function sets the active slots within a receive frame.
//!
//! \return Returns bit-map of active slots.
//
//*****************************************************************************
unsigned long McASPRxActiveSlotGet(unsigned long ulBase)
{
  //
  // Get active slot(s) in receive frame
  //
  return(MCASP_HWREG(MCASP_O_RXTDM));
}

//*****************************************************************************
//
//! Sets McASP transfer mode
//!
//! \param ulMode is one of the valid transfer mode
//!
//! This function sets the transfer mode of serilizer and corresponding data
//! pins. For configuring serializer and data pins independently use
//! McASPSerEnable(), McASPSerDisable() and McASPPinDirSet()
//!
//! The parameter \e ulMode should be one of the following
//!
//! - \b MCASP_MODE_0 Data 0 and Data 1 are Rx.
//! - \b MCASP_MODE_1 Data 0 is Tx and Data 1 is Rx.
//! - \b MCASP_MODE_2 Data 0 is Rx and Data 1 is Tx.
//! - \b MCASP_MODE_3 Data 0 and Data 1 are Tx.
//!
//! \return None.
//
//*****************************************************************************
void McASPXferModeSet(unsigned long ulBase, unsigned long ulMode)
{
  //
  // Set pin directions for clock and frame sync
  //
  McASPPinDirSet(ulBase, MCASP_PIN_AFSX, MCASP_PIN_OUT);
  McASPPinDirSet(ulBase, MCASP_PIN_ACLKX, MCASP_PIN_OUT);

  //
  // Enable and set pin direction for SERDES 0 is required mode
  //
  McASPSerEnable(ulBase, MCASP_PIN_DATA_0,(ulMode &0x1)?MCASP_SER_MODE_TX
                                :MCASP_SER_MODE_RX,MCASP_INACT_TRI);
  McASPPinDirSet(ulBase, MCASP_PIN_DATA_0,(ulMode &0x1)?MCASP_PIN_OUT
                 :MCASP_PIN_IN);

  //
  // Enable and set pin direction for SERDES 1 is required mode
  //
  McASPSerEnable(ulBase, MCASP_PIN_DATA_1,(ulMode &0x2)?MCASP_SER_MODE_TX
                 :MCASP_SER_MODE_RX,MCASP_INACT_TRI);
  McASPPinDirSet(ulBase, MCASP_PIN_DATA_1,(ulMode &0x2)?MCASP_PIN_OUT
                 :MCASP_PIN_IN);
}

//*****************************************************************************
//
//! Register interrupt handler and enable the interrupts
//!
//! \param pfnHandler is the pointer to McASp interrupt handler function.
//!
//! This function registers an interrupt handler for McASP and enable the McASP
//! global interrupt in the interrupt controller. Specific interrupts must be
//! be enabled via \sa McASPIntEnable(). Its interrupt handlers responsiblity
//! to clear the interrupt sources.
//!
//! \return None.
//
//*****************************************************************************
void McASPIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
  //
  //Register McASP Interrupt Handler
  //
  IntRegister(INT_MCASP, pfnHandler);

  //
  //Enable McASP Interrupt
  //
  IntEnable(INT_MCASP);
}



//*****************************************************************************
//
//! Unregister interrupt handler and disable the interrupts
//!
//!
//! This function unregisters any interrupt handler for McASP and disables
//! the McASP global interrupt in the interrupt controller.
//!
//!
//! \return None.
//
//*****************************************************************************

void McASPIntUnregister(unsigned long ulBase)
{
  //
  //Disable McASP Interrupt
  //
  IntDisable(INT_MCASP);

  //
  //Unregister McASP Interrupt Handler
  //
  IntUnregister(INT_MCASP);
}

//*****************************************************************************
//
//! Enable individual interrupts for McASP
//!
//! \param ulIntFlag is the bit mask of interrupts to be enable.
//!
//! This function enables different interrupt sources.
//! The parameter \e ulIntFlag is logical OR of one or more of the following.
//!
//! For Transmit
//! - \b MCASP_INT_XUNDRN    - Transmit Under Run.
//! - \b MCASP_INT_XSYNCERR  - Transmit unexpecter Frames Sync.
//! - \b MCASP_INT_XBDCLK    - Transmit Bad clock.
//! - \b MCASP_INT_XDMAERR   - Transmit DMA error.
//! - \b MCASP_INT_XLAST     - Transmit last slot.
//! - \b MCASP_INT_XDATA     - Transmit next data.
//! - \b MCASP_INT_XSOF      - Transmit Start Of Frame.
//! - \b MCASP_INT_XDMA      - Transmit DMA.
//!
//! For Receive
//! - \b MCASP_INT_ROVRN     - Receive Over Run.
//! - \b MCASP_INT_RSYNCERR  - Receive Unexpected Frame Sync.
//! - \b MCASP_INT_RBDCLK    - Receive Bad Clock.
//! - \b MCASP_INT_RDMAERR   - Receive DMA error.
//! - \b MCASP_INT_RLAST     - Receive Last slot.
//! - \b MCASP_INT_RDATA     - Receive next data.
//! - \b MCASP_INT_RSOF      - Receive Start Of Frame.
//! - \b MCASP_INT_RDMA      - Receive DMA.
//!
//! \return None.
//
//*****************************************************************************
void McASPIntEnable(unsigned long ulBase, unsigned long ulIntFlag)
{
  unsigned long ulReg;


  if((ulIntFlag & MCASP_INT_XDMA))
  {
    //
    // Enable Tx DMA Interrupt
    //
    HWREG( APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_CLR )
       |= APPS_CONFIG_DMA_DONE_INT_MASK_CLR_MACASP_WR_DMA_DONE_INT_MASK_CLR;
  }


  if((ulIntFlag & MCASP_INT_RDMA))
  {
    //
    // Enable Rx DMA Interrupt
    //
    HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_CLR )
      |= APPS_CONFIG_DMA_DONE_INT_MASK_CLR_MCASP_RD_DMA_DONE_INT_MASK_CLR;
  }

  //
  //Enable specific Tx Interrupts
  //
  ulReg  = MCASP_HWREG(MCASP_O_EVTCTLX);
  ulReg |= (ulIntFlag & 0xFF);
  MCASP_HWREG(MCASP_O_EVTCTLX) = ulReg;

  //
  //Enable specific Rx Interrupts
  //
  ulReg  = MCASP_HWREG(MCASP_O_EVTCTLR);
  ulReg |= ((ulIntFlag >> 16) & 0xFF);
  MCASP_HWREG(MCASP_O_EVTCTLR) = ulReg;

}

//*****************************************************************************
//
//! Disable individual interrupts for McASP
//!
//! \param ulIntFlag is the bit mask of interrupts to be enable.
//!
//! This function disables the indicated interrupt source.
//!
//! See \sa McASPIntEnable() for more info on \e ulIntFlag.
//!
//! \return None.
//
//*****************************************************************************
void McASPIntDisable(unsigned long ulBase, unsigned long ulIntFlag)
{
  unsigned long ulReg;

  if((ulIntFlag & MCASP_INT_XDMA))
  {
    //
    // Disable Tx DMA Interrupt
    //
    HWREG( APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_SET )
            |= APPS_CONFIG_DMA_DONE_INT_MASK_SET_MCASP_WR_DMA_DONE_INT_MASK_SET;
  }


  if((ulIntFlag & MCASP_INT_RDMA))
  {
    //
    // Disable Rx DMA Interrupt
    //
    HWREG( APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_SET )
            |= APPS_CONFIG_DMA_DONE_INT_MASK_SET_MCASP_RD_DMA_DONE_INT_MASK_SET;
  }

  //
  // Disable specific Tx Interrupts
  //
  ulReg=MCASP_HWREG(MCASP_O_EVTCTLX);
  ulReg &= ~(ulIntFlag & 0xFF);
  MCASP_HWREG(MCASP_O_EVTCTLX)=ulReg;

  //
  // Disable specific Rx Interrupts
  //
  ulReg=MCASP_HWREG(MCASP_O_EVTCTLR);
  ulReg &= ~((ulIntFlag >> 16) & 0xFF);
  MCASP_HWREG(MCASP_O_EVTCTLR)=ulReg;
}


//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! This function returns the current interrupt status for the McASP enumerated
//! as a bit field of following values
//! \b MCASP_STAT_XERR
//! \b MCASP_STAT_XDMAERR
//! \b MCASP_STAT_XSTAFRM
//! \b MCASP_STAT_XDATA
//! \b MCASP_STAT_XLAST
//! \b MCASP_STAT_XTDMSLOT
//! \b MCASP_STAT_XCKFAIL
//! \b MCASP_STAT_XSYNCERR
//! \b MCASP_STAT_XUNDRN
//! \b MCASP_STAT_RERR
//! \b MCASP_STAT_RDMAERR
//! \b MCASP_STAT_RSTAFRM
//! \b MCASP_STAT_RDATA
//! \b MCASP_STAT_RLAST
//! \b MCASP_STAT_RTDMSLOT
//! \b MCASP_STAT_RCKFAIL
//! \b MCASP_STAT_RSYNCERR
//! \b MCASP_STAT_ROVERN
//!
//! \return Returns the current interrupt status,  enumerated as a bit field of
//! values described above.
//
//*****************************************************************************
unsigned long McASPIntStatus(unsigned long ulBase)
{
  unsigned long ulStatus;

  //
  // Read Tx Interrupt status
  //
  ulStatus = MCASP_HWREG(MCASP_O_TXSTAT);
  
  //
  // Read Rx Interrupt status
  //
  ulStatus |= MCASP_HWREG(MCASP_O_RXSTAT) << 16;

  return ulStatus;
}

//*****************************************************************************
//
//! Clears McASP interrupt sources.
//!
//! \param ulIntFlag is a bit mask of the interrupt to be cleared.
//!
//! The specified McASP interrupt sources are cleared, so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupt from being recognized again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlag
//! parameter to McASPIntStatus().
//!
//! \note Because there is a write buffer in the Cortex processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************

void McASPIntClear(unsigned long ulBase, unsigned long ulIntFlag)
{
  //
  // Clear Tx Interrupt
  //
  MCASP_HWREG(MCASP_O_TXSTAT) = ulIntFlag & 0x1FF ;
  
  //
  // Clear Rx Interrupt
  //
  MCASP_HWREG(MCASP_O_RXSTAT) = (ulIntFlag >> 16) & 0x1FF;
}

//*****************************************************************************
//
//! Gets the current DMA Interrupt status.
//!
//! \param bMasked is \b false if the raw interrupt status is required.
//!
//! This function returns the DMA interrupt for the McASP enumerated as a bit
//! field of following values
//! \b MCASP_XDMA_DONE  - Transmit DMA Done
//! \b MCASP_RDMA_DONE  - Receive DMA Done.
//!
//! \return Returns the current DMA status, enumerated as a bit field of
//! values described above.
//
//*****************************************************************************
unsigned long McASPDMAStatus(unsigned long ulBase, tBoolean bMasked)
{
  unsigned long ulStat;

  if(bMasked)
  {
    //
    // Read masked interrupt status
    //
    ulStat = HWREG( APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_STS_MASKED);
  }
  else
  {
    //
    // Read raw interrupt status
    //
    ulStat = HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_STS_RAW);
  }

  //
  // Mask out other fieds
  //
  ulStat &= (0x00000800 | 0x00000400 );

  return ulStat;
}

//*****************************************************************************
//
//! Clears DMA Interrupt status.
//!
//! \param ulDMAFlag is a bit mask of DMA interrupt sources.
//!
//! This function clears the DMA interupt status. \e ulDMAFlag can take
//! following values
//! \b MCASP_XDMA_DONE
//! \b MCASP_RDMA_DONE
//!
//! \return none.
//
//*****************************************************************************
void McASPDMAClear(unsigned long ulBase, unsigned long ulDmaFlag)
{
  //
  // Clear DMA interrupt status
  //
  HWREG( APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_ACK) =  ulDmaFlag;
}

//*****************************************************************************
//
//! Enable DMA for Transmit and/or Receive.
//!
//! \param ulDmaFlag specfies if DMA to be enabled for Transmit and/or Receive
//!
//! This function enable DMA for Transmit and/or Receive as specified by
//! \e ulFlag
//!
//! The parameter \e ulFlag must be one of the following :
//! - \b MCASP_DMA_TX    - Tx DMA Only
//! - \b MCASP_DMA_RX    - Rx DMA Only
//! - \b MCASP_DMA_BOTH  - Both Tx and Rx DMA
//!
//! \return None.
//
//*****************************************************************************
void McASPDMAEnable(unsigned long ulBase, unsigned long ulDmaFlag)
{
  
  if((ulDmaFlag & MCASP_DMA_TX))
  {
    //
    // Enable Tx DMA
    //
    MCASP_HWREG(MCASP_O_XEVTCTL) &= ~0x1;
  }

  if((ulDmaFlag & MCASP_DMA_RX))
  {
    //
    // Enable Rx DMA
    //
    MCASP_HWREG(MCASP_O_REVTCTL) &= ~0x1;
  }
}

//*****************************************************************************
//
//! Disable DMA for Transmit and/or Receive.
//!
//! \param ulDmaFlag specfies if DMA to be disabled for Transmit and/or Receive
//!
//! This function disable DMA for Transmit and/or Receive as specified by
//! \e ulFlag
//!
//! The parameter \e ulFlag must be one of the following :
//! - \b MCASP_DMA_TX    - Tx DMA Only
//! - \b MCASP_DMA_RX    - Rx DMA Only
//! - \b MCASP_DMA_BOTH  - Both Tx and Rx DMA
//!
//! \return None.
//
//*****************************************************************************
void McASPDMADisable(unsigned long ulBase, unsigned long ulDmaFlag)
{
  if((ulDmaFlag & MCASP_DMA_TX))
  {
    //
    // Disable Tx DMA
    //
    MCASP_HWREG(MCASP_O_XEVTCTL) |= 0x1;
  }

  if((ulDmaFlag & MCASP_DMA_RX))
  {
    //
    // Disable Rx DMA
    //
    MCASP_HWREG(MCASP_O_REVTCTL) |= 0x1;
  }
}

//*****************************************************************************
//
//! Selects the McASP transmit data port
//!
//! \param ulDataPort selects the required data port
//!
//! This function selects between DMA and CPU port for sending data and can
//! take following values
//! - \b MCASP_PORT_DMA - DMA Port
//! - \b MCASP_PORT_CPU - CPU Port
//!
//! \return none.
//
//*****************************************************************************
void McASPTxPortSet(unsigned long ulBase, unsigned long ulDataPort)
{
  //
  // Set the Tx data port
  //
  MCASP_HWREG(MCASP_O_TXFMT)|= ulDataPort;
}


//*****************************************************************************
//
//! Get current transmit data port
//!
//! \return \b MCASP_PORT_DMA or \b MCASP_PORT_CPU
//
//*****************************************************************************
unsigned long McASPTxPortGet(unsigned long ulBase)
{
  //
  // Get the Tx Data port
  //
  return(MCASP_HWREG(MCASP_O_TXFMT) & MCASP_PORT_CPU);
}

//*****************************************************************************
//
//! Selects the McASP receive data port
//!
//! \param ulDataPort selects the required data port
//!
//! This function selects between DMA and CPU port for sending data and can
//! take following values
//! - \b MCASP_PORT_DMA - DMA Port
//! - \b MCASP_PORT_CPU - CPU Port
//!
//! \return none.
//
//*****************************************************************************
void McASPRxPortSet(unsigned long ulBase, unsigned long ulDataPort)
{
  //
  // Set the Rx data port
  //
  MCASP_HWREG(MCASP_O_RXFMT)|= ulDataPort;
}

//*****************************************************************************
//
//! Get current receive data port
//!
//! \return \b MCASP_PORT_DMA or \b MCASP_PORT_CPU
//
//*****************************************************************************
unsigned long McASPRxPortGet(unsigned long ulBase)
{
  //
  // Get Rx Data port
  //
  return(MCASP_HWREG(MCASP_O_RXFMT) & MCASP_PORT_CPU);
}

//*****************************************************************************
//
//! Enables McASP transmitter
//!
//! This function enables the McASP transmitter. This function should only be
//! called after required transmitter configuration are done.
//!
//! \return none.
//
//*****************************************************************************
void McASPTxEnable(unsigned long ulBase)
{
  //
  // MCASP require the sub modules to be enabled
  // in a sequence
  //
  
  //
  // Remove Tx HCLK reset
  //
  McASPGBLEnable(ulBase, MCASP_GBL_XHCLK);
  
  //
  // Remove Tx XCLK reset
  //
  McASPGBLEnable(ulBase, MCASP_GBL_XCLK);
  
  //
  // Enable Tx SERDES(s)
  //
  McASPGBLEnable(ulBase, MCASP_GBL_XSER);
  
  //
  // Enable Tx state machine
  //
  McASPGBLEnable(ulBase, MCASP_GBL_XSM);
  
  //
  // Enable FSync generator
  //
  McASPGBLEnable(ulBase, MCASP_GBL_XFSYNC);
}

//*****************************************************************************
//
//! Disables McASP transmitter
//!
//! This function puts McASP TX sub system in reset. 
//!
//! \return none.
//
//*****************************************************************************
void McASPTxDisable(unsigned long ulBase)
{
  //
  // Reset all MCASP TX sub modules
  //
  MCASP_HWREG(MCASP_O_GBLCTLX)=0;
}

//*****************************************************************************
//
//! Enable the McASP receiver
//!
//! This function enables the McASP receiver. This function should only be
//! called after required receiver configuration are done.
//!
//! \return none.
//
//*****************************************************************************
void McASPRxEnable(unsigned long ulBase)
{
  //
  // Enable Rx HCLK
  //
  McASPGBLEnable(ulBase, MCASP_GBL_RHCLK);
  
  //
  // Enable Rx XCLK
  //
  McASPGBLEnable(ulBase, MCASP_GBL_RCLK);
  
  //
  // Enable Rx SERDES(s)
  //
  McASPGBLEnable(ulBase, MCASP_GBL_RSER );
  
  //
  // Enable Rx state machine
  //
  McASPGBLEnable(ulBase, MCASP_GBL_RSM );
  
  //
  // Enable RX FSync
  //
  McASPGBLEnable(ulBase, MCASP_GBL_RFSYNC);
}


//*****************************************************************************
//
//! Disables McASP receiver
//!
//! This function puts McASP RX sub system in reset. 
//!
//! \return none.
//
//*****************************************************************************
void McASPRxDisable(unsigned long ulBase)
{
  //
  // Reset all MCASP TX sub modules
  //
  MCASP_HWREG(MCASP_O_GBLCTLR)=0;
}

//*****************************************************************************
//
//! Return the current Tx slot number
//!
//! This function returns the current TX slot number
//!
//! \return Returns current Tx slot number.
//
//*****************************************************************************
unsigned long McASPTxCurSlotGet(unsigned long ulBase)
{
  //
  // Return Tx slot number
  //
  return MCASP_HWREG(MCASP_O_TXTDMSLOT);
}

//*****************************************************************************
//
//! Return the current Rx slot number
//!
//! This function returns the current RX slot number
//!
//! \return Returns current Rx slot number.
//
//*****************************************************************************
unsigned long McASPRxCurSlotGet(unsigned long ulBase)
{
  //
  // Return Rx slot number
  //
  return MCASP_HWREG(MCASP_O_RXTDMSLOT);
}

//*****************************************************************************
//
//! Configure the transmit clock check circuit
//!
//! \param ulPrescale is the transmit clock check prescale value.
//! \param ulMin is transmit clock minimum boundary.
//! \param ulMax is transmit clock maximum boundary.
//!
//! \return none.
//
//*****************************************************************************
void McASPTxClkChkConfig(unsigned long ulBase, unsigned long ulPrescale,unsigned long ulMin, 
                         unsigned long ulMax)
{

  //
  // Configure Tx clock check.
  //
  MCASP_HWREG(MCASP_O_TXCLKCHK) = (ulMax<<16 | ulMin << 8 | ulPrescale);

}

//*****************************************************************************
//
//! Get the last transmit clock check count
//!
//!
//! \return Returns last transmit clock check count.
//
//*****************************************************************************
unsigned long McASPTxClkChkCount(unsigned long ulBase)
{
  //
  // Return last transmit clock check count.
  // 
  return (MCASP_HWREG(MCASP_O_TXCLKCHK)>>24);
}

//*****************************************************************************
//
//! Configure the receive clock check circuit
//!
//! \param ulPrescale is the receive clock check prescale value.
//! \param ulMin is receive clock minimum boundary.
//! \param ulMax is receive clock maximum boundary.
//!
//! \return none.
//
//*****************************************************************************
void McASPRxClkChkConfig(unsigned long ulBase, unsigned long ulPrescale,unsigned long ulMin, 
                         unsigned long ulMax)
{
  //
  // Configure Tx clock check.
  //
  MCASP_HWREG(MCASP_O_RXCLKCHK) = (ulMax<<16 | ulMin << 8 | ulPrescale);

}

//*****************************************************************************
//
//! Get the last receive clock check count
//!
//!
//! \return Returns last receive clock check count.
//
//*****************************************************************************
unsigned long McASPRxClkChkCount(unsigned long ulBase)
{
  //
  // return last receive clock check count.
  //
  return (MCASP_HWREG(MCASP_O_RXCLKCHK)>>24);
}

//*****************************************************************************
//
//! Enables and configures Transmit FIFO
//!
//! \param ulLevel is transmit DMA event level, should be a multiple of
//! number of serializers enabled as transmitters.
//! \param ulWordsPertransfer is numder of words transferred from write FIFO
//! to McASP. 
//!
//! This function enbles Transmit FIFO and configure numder of words to be 
//! transferred from write FIFO to McASP channel. \e ulWordsPertransfer should 
//! equal to  number of serializers enabled as
//! transmitters.
//!
//! return None.
//
//*****************************************************************************
void McASPTxFIFOEnable(unsigned long ulBase, unsigned long ulLevel, unsigned long ulWordsPerTransfer)
{
  //
  //Enable and write FIFO configuration
  //
  MCASP_HWREG(MCASP_0_WFIFOCTL) = ((1<<16) | (ulLevel & 0xFF) << 8
					| (ulWordsPerTransfer & 0x1F));
}

//*****************************************************************************
//
//! Disables Tx FIFO
//!
//! This function disables the transmit FIFO.
//!
//! \return None.
//
//*****************************************************************************
void McASPTxFIFODisable(unsigned long ulBase)
{
  //
  // Disable Tx FIFO
  //
  MCASP_HWREG(MCASP_0_WFIFOCTL) = 0;
}

//*****************************************************************************
//
//! Enables and configures Receive FIFO
//!
//! \param ulLevel is receive DMA event level and should be a multiple of
//! number of serializers enabled as receivers.
//! \param ulWordsPerTransfer is numder of words transferred from write FIFO
//! to McASP. 
//!
//! This function enbles Transmit FIFO and configure numder of words to be 
//! transferred from write FIFO to McASP channel.\e ulWordspertransfer should 
//! equal to  number of serializers enabled as
//! receivers.
//! retrun None.
//
//*****************************************************************************

void McASPRxFIFOEnable(unsigned long ulBase, unsigned long ulLevel, unsigned long ulWordsPerTransfer)
{

  //
  // Enable and Write FIFO configuration
  //
  MCASP_HWREG(MCASP_0_RFIFOCTL) = ((1<<16) | (ulLevel & 0xFF) << 8
					| (ulWordsPerTransfer & 0x1F));
}

//*****************************************************************************
//
//! Disables Rx FIFO
//!
//! This function disables the receive FIFO.
//!
//! \return none.
//
//*****************************************************************************
void McASPRxFIFODisable(unsigned long ulBase)
{
  //
  //
  // Disable Rx FIFO
  MCASP_HWREG(MCASP_0_RFIFOCTL) = 0;
}


//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

