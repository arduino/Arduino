//*****************************************************************************
//
// mcspi.c - Driver for the McSPI.
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
//! \addtogroup McSPI_Multichannel_Serial_Port_Interface_api
//! @{
//
//*****************************************************************************


#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_mcspi.h"
#include "inc/hw_apps_config.h"
#include "interrupt.h"
#include "mcspi.h"


//*****************************************************************************
//
// A mapping of McSPI base address to interupt number.
//
//*****************************************************************************
static const unsigned long g_ppulMcSPIIntMap[][3] =
{
    { MCSPIS0_BASE, INT_MCSPIS0 }, //Shared betwen APPS and NWP
    { MCSPIA1_BASE, INT_MCSPIA1 }, // To external host
    { MCSPIA2_BASE, INT_MCSPIA2 }, //LINK SPI
};

//*****************************************************************************
//
// A mapping of McSPI base address to DMA done interrupt mask bit
//
//*****************************************************************************
static const unsigned long g_ulMcSPIDmaMaskMap[][2]=
{
  {MCSPIS0_BASE,APPS_CONFIG_DMA_DONE_INT_MASK_SHSPI_WR_DMA_DONE_INT_MASK},
  {MCSPIA2_BASE,APPS_CONFIG_DMA_DONE_INT_MASK_HOSTSPI_WR_DMA_DONE_INT_MASK},
  {MCSPIA1_BASE,APPS_CONFIG_DMA_DONE_INT_MASK_APPS_SPI_WR_DMA_DONE_INT_MASK},
};

//*****************************************************************************
//
//! \internal
//! Gets the McSPI interrupt number.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! Given a McSPI base address, returns the corresponding interrupt number.
//!
//! \return Returns a McSPI interrupt number, or -1 if \e ulBase is invalid.
//
//*****************************************************************************
static long
McSPIIntNumberGet(unsigned long ulBase)
{
    unsigned long ulIdx;

    //
    // Loop through the table that maps McSPI base addresses to interrupt
    // numbers.
    //
    for(ulIdx = 0; ulIdx < (sizeof(g_ppulMcSPIIntMap) /
                            sizeof(g_ppulMcSPIIntMap[0])); ulIdx++)
    {
        //
        // See if this base address matches.
        //
        if(g_ppulMcSPIIntMap[ulIdx][0] == ulBase)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(g_ppulMcSPIIntMap[ulIdx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(-1);
}

//*****************************************************************************
//
//! \internal
//! Gets the McSPI DMA interrupt mask bit.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! Given a McSPI base address, DMA interrupt mask bit.
//!
//! \return Returns a DMA interrupt mask bit, or -1 if \e ulBase is invalid.
//
//*****************************************************************************
static long
McSPIDmaMaskGet(unsigned long ulBase)
{
    unsigned long ulIdx;

    //
    // Loop through the table that maps UART base addresses to interrupt
    // numbers.
    //
    for(ulIdx = 0; ulIdx < (sizeof(g_ulMcSPIDmaMaskMap) /
                            sizeof(g_ulMcSPIDmaMaskMap[0])); ulIdx++)
    {
        //
        // See if this base address matches.
        //
        if(g_ulMcSPIDmaMaskMap[ulIdx][0] == ulBase)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(g_ulMcSPIDmaMaskMap[ulIdx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(-1);
}

//*****************************************************************************
//
//! Resets a McSPI port.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This function resets a McSPI port.
//!
//! \return None.
//
//*****************************************************************************
void
McSPIReset(unsigned long ulBase)
{

  //
  // Assert soft reset (auto clear)
  //
  HWREG(ulBase+MCSPI_O_SYSCONFIG) |= MCSPI_SYSCONFIG_SOFTRESET;

  //
  // wait until reset is done
  //
  while(!(HWREG(ulBase+MCSPI_O_SYSSTATUS)& MCSPI_SYSSTATUS_RESETDONE))
  {
  }
}

//*****************************************************************************
//
//! Sets the configuration of a McSPI port.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucMSMode is the mode for the port.
//! \param ulMcSPIClk is the McSPI Clock frequency
//! \param ulBaud is the desired baud rate. (Only for master mode)
//! \param ulWordLen is the word length of an SPI transaction
//! \param ucCSPolarity is the chip select polarity (only for master)
//! \param ucClkPhase is the Clock phase
//! \param ucClkPolarity is the Clock polarity
//!
//! The McSPI has only one channel provision, hence there is no channel 
//! parameter
//!
//! This function configures the McSPI for operation in the specified data
//! This function sets some default configurations also
//! 1 - Interrupt is not enabled
//! 2 - DMA is not enabled
//! 3 - FIFO is not enabled
//! 4 - The TRM mode is Transmit and Receive mode
//! 5 - Data line configuration - By default DAT1 is reception and DAT0 
//! is Transmit
//! To change any of the default values, do use the respective API calls
//!
//! \return None.
//
//*****************************************************************************
void
McSPIConfig(unsigned long ulBase, unsigned char ucMSMode,
            unsigned long ulMcSPIClk, unsigned long ulBaud,
            unsigned char ucWordLen, unsigned char ucCSPolarity,
            unsigned char ucClkPhase, unsigned char ucClkPolarity)
{

  unsigned long ulRegData = 0;
  unsigned long ulDivider = 0;
  unsigned long ulCLKDVal = 0;
  unsigned long ulEXTCLKVal;



  //
  // Check the mode
  //
  if(ucMSMode == MCSPI_MASTER_MODE)
  {

    //
    // Read MODULCTRL register
    //  
    ulRegData = HWREG(ulBase + MCSPI_O_MODULCTRL);
    
    //
    // Set Master mode.
    //
    ulRegData &= ~(MCSPI_MODULCTRL_MS);

    //
    // Single channel mode.
    // Software controlled Chip Select (or SPIEN)
    //
    ulRegData |= MCSPI_MODULCTRL_SINGLE;

    //
    // Write the configuration
    //
    HWREG(ulBase + MCSPI_O_MODULCTRL) = ulRegData;

    //
    // Configure baud
    // shall use the Clock ratio extension
    // EXTCLK	Clock ratio extension:
    // This register is used to concatenate with MCSPI_CHCONF[CLKD] 
    // register for clock ratio only when granularity is one clock cycle
    // (MCSPI_CHCONF[CLKG] set to 1). Then the max value reached is 4096 
    // clock divider ratio.
    // 0x0:	Clock ratio is CLKD + 1
    // 0x1:	Clock ratio is CLKD + 1 + 16
    // 0xFF	Clock ratio is CLKD + 1 + 4080
    //
    ulRegData =  HWREG(ulBase+MCSPI_O_CH0CONF);

    //
    // Divide the SPI clock from Baud to find the divisor
    //
    ulDivider = ulMcSPIClk/ulBaud;

    //
    // Decrement the ulDivider
    //
    ulDivider--;

    //
    // The least significant four bits of the Divider is used fo configure CLKD in MCSPI_CHiCONF
    // next eight least significant bits are used to configure the EXTCLK in MCSPI_CHiCTRL
    //
    ulCLKDVal = (ulDivider & 0x0000000F);
    ulEXTCLKVal = ((ulDivider & 0x00000FF0)>>4);

    //
    // Write the values to ulRegData
    //
    ulRegData =((ulCLKDVal << MCSPI_CH0CONF_CLKD_S) & MCSPI_CH0CONF_CLKD_M);

    //
    // Write the ext clk value
    //
    HWREG(ulBase+MCSPI_O_CH0CTRL) = (ulEXTCLKVal<<MCSPI_CH0CTRL_EXTCLK_S);

  }
  else //configuration specific to slave
  {
    // 
    // Set Slave mode
    //
    HWREG(ulBase + MCSPI_O_MODULCTRL) |= MCSPI_MODULCTRL_MS;
    ulRegData = 0;
  }
  
  //
  // Disable all the interrupts
  //
  HWREG(ulBase+MCSPI_O_IRQENABLE) = 0x0;

  //
  // Set the clock phase
  //
  if(ucClkPhase)
  {
    ulRegData =  ulRegData| MCSPI_CH0CONF_PHA;
  }
  
  //
  // Set the clk polarity
  //
  if(ucClkPolarity)
  {
  ulRegData =  ulRegData| MCSPI_CH0CONF_POL;
  }
  
  //
  // Set the spi enable (chipselect) Polarity
  //
  if(ucCSPolarity)
  {
  ulRegData =  ulRegData| MCSPI_CH0CONF_EPOL;
  }

  //
  // Configure the wordlength
  //
  ulRegData = ulRegData | (((ucWordLen-1) << MCSPI_CH0CONF_WL_S) & MCSPI_CH0CONF_WL_M);

  //
  // Enable the one clock granularity
  //
  ulRegData = ulRegData | MCSPI_CH0CONF_CLKG;

  //
  // Finally, write to the CONF register
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) = ulRegData;
}

//*****************************************************************************
//
//! Returns the Master or Slave mode of an McSPI port.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function returns whether the port is configured as a Master or a Slave
//!
//! \return Returns \b McSPI_MASTER_MODE if the port is configured in Master mode
//! or \b McSPI_SLAVE_MODE if the port is configured in Slave mode.
//!
//
//*****************************************************************************
unsigned char
McSPIMSModeGet(unsigned long ulBase)
{
    return((HWREG(ulBase + MCSPI_O_MODULCTRL) & MCSPI_MODULCTRL_MS) >> 0x2);
}

//*****************************************************************************
//
//! Returns the Word length.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function returns the word length configured on the McSPI port in number of bits.
//! The value ranges from 4 bits to 32 bits. Setting of Word length is done in the config function
//!
//! \return Returns the word length in bits.
//!
//
//*****************************************************************************
unsigned long
McSPIWordLenGet(unsigned long ulBase)
{
  unsigned long ulRegVal;
  
  //
  // Read register
  //
  ulRegVal = HWREG(ulBase+MCSPI_O_CH0CONF);
  
  //
  // Get the word length
  //
  ulRegVal = ((ulRegVal & MCSPI_CH0CONF_WL_M) >> MCSPI_CH0CONF_WL_S) + 1;
  
  //
  // Return the value
  //
  return ulRegVal;
}

//*****************************************************************************
//
//! Sets the SPI Trancieve Receive Mode.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucSPIMode is the Mode to be set, can be one of
//!
//! The function sets the port into one of above modes.
//! After initial configuration, the port will be in TRMMODDE
//! Use this function if it needs to be changed to TONLY or RONLY
//!
//! \return None
//
//*****************************************************************************
void
McSPISPITRModeSet(unsigned long ulBase, unsigned long ulSPIMode)
{
  unsigned long ulRegVal;

  //
  //Read the register value
  //
  ulRegVal = HWREG(ulBase+MCSPI_O_CH0CONF);

  //
  // Set TRM bits
  //
  ulSPIMode = ((ulSPIMode & 0x3) << MCSPI_CH0CONF_TRM_S);
  ulRegVal  = ((ulRegVal & ~MCSPI_CH0CONF_TRM_M) | ulSPIMode);

  //
  // Write the configuration
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) = ulRegVal;
}

//*****************************************************************************
//
//! Returns the SPI Transcieve Receive mode.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function returns the TRM of specified McSPI port.
//!
//! \return Returns \b MCSPI_CHiCONF_TRM_TRMODE or \b MCSPI_CHiCONF_TRM_RONLY
//! or \b MCSPI_CHiCONF_TRM_TONLY
//
//*****************************************************************************
unsigned char
McSPISPITRModeGet(unsigned long ulBase)
{
    return(HWREG((ulBase+MCSPI_O_CH0CONF))& 
           MCSPI_CH0CONF_TRM_M>>MCSPI_CH0CONF_TRM_S);
}

//*****************************************************************************
//
//! Sets the Data[0] and Data[1] config.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucDataLineConf is the bit encoded value
//!        bit 0 - DPE0 - if set, then no transmission on DL0
//!                       if cleared, then transmission enabled on DL0
//!        bit 1 - DPE1 - if set, then no transmission on DL1
//!                       if cleared, then transmission enabled on DL1
//!        bit 2 - IS -  Input select
//!                      if set, DL1 selected for reception
//!                      if cleared, then DL0 selected for reception
//!
//! This function sets the configuration on data lines.
//!
//! \return None
//!
//
//*****************************************************************************
void
McSPIDataLineConfigSet(unsigned long ulBase, unsigned char ucDataLineConf)
{
  unsigned long ulRegVal;

  //
  // Read the register
  //
  ulRegVal = HWREG(ulBase+MCSPI_O_CH0CONF);

  //
  // Mask and set data lines config bits
  //
  ulRegVal &= ~(7<<16);
  ulRegVal |= ucDataLineConf << 16;

  //
  // Write the values
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) = ulRegVal;
}

//*****************************************************************************
//
//! Gets the Data[0] and Data[1] config.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function gets the configuration of data lines.
//!
//! \return return value is a bit encoded value
//!        bit 0 - DPE0 - if set, then no transmission on DL0
//!                       if cleared, then transmission enabled on DL0
//!        bit 1 - DPE1 - if set, then no transmission on DL1
//!                       if cleared, then transmission enabled on DL1
//!        bit 2 - IS -  Input select
//!                      if set, DL1 selected for reception
//!                      if cleared, then DL0 selected for reception
//!
//
//*****************************************************************************
unsigned long
McSPIDataLineConfigGet(unsigned long ulBase)
{
  unsigned long ulRegVal;
  
  //
  // Read register
  //
  ulRegVal = ((HWREG(ulBase+MCSPI_O_CH0CONF) >> 16 ) & 0x7);
  
  //
  // Retrun the value
  //
  return ulRegVal;
}

//*****************************************************************************
//
//! Enables the McSPI Channel
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function enables the McSPI channel for operation.
//!
//! \return None
//!
//
//*****************************************************************************
void
McSPIChannelEnable(unsigned long ulBase)
{
  //
  // Set Channel Enable Bit
  //
  HWREG(ulBase+MCSPI_O_CH0CTRL) |= MCSPI_CH0CTRL_EN;
}

//*****************************************************************************
//
//! Disables the McSPI Channel0.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function disables the McSPI channel0 for operation.
//!
//! \return None
//!
//
//*****************************************************************************
void
McSPIChannelDisable(unsigned long ulBase)
{
  //
  // Reset Channel Enable Bit
  //
  HWREG(ulBase+MCSPI_O_CH0CTRL) &= ~MCSPI_CH0CTRL_EN;
}

//*****************************************************************************
//
//! Receives a word from the specified port.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function gets a word from the receive FIFO for the specified
//! port.
//!
//!
//! \return Returns \b true if the word is successfully retrieved from the
//! receive FIFO or \b false if there was no word on the receive FIFO
//! FIFO.
//
//*****************************************************************************
tBoolean
McSPIDataNonBlockingGet(unsigned long ulBase, unsigned long * pulData)
{
  unsigned long ulRegVal;

  //
  // Read register status register
  //
  ulRegVal = HWREG(ulBase+MCSPI_O_CH0STAT);

  //
  // Check is data is available
  //
  if(ulRegVal & MCSPI_CH0STAT_RXS)
  {
      *pulData = HWREG(ulBase+MCSPI_O_RX0);
      return(true);
   }

   return(false);
}

//*****************************************************************************
//
//! Waits for the word to be received on the specified port.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function gets word from the receive FIFO for the specified
//! port.  If there is no word available, this function waits until a
//! word is received before returning.
//!
//! \return Returns the word read from the specified port, cast as an
//! \e unsigned long.
//
//*****************************************************************************
unsigned long
McSPIDataGet(unsigned long ulBase)
{
  //
  // Wait for Rx data
  //
  while(!(HWREG(ulBase+MCSPI_O_CH0STAT) & MCSPI_CH0STAT_RXS))
  {
  }
  
  //
  // Return the value
  //
  return(HWREG(ulBase + MCSPI_O_RX0));
}

//*****************************************************************************
//
//! Transmits a word on the specified port.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function transmits a word on the transmit FIFO for the specified
//! port.
//!
//! \return Returns \b true if the word is successfully written to the
//! transmit FIFO or \b false if there was no space on the transmit FIFO
//!
//*****************************************************************************
tBoolean
McSPIDataNonBlockingPut(unsigned long ulBase, unsigned long ulData)
{
    unsigned long ulRegVal;
    
    //
    // Read status register
    //
    ulRegVal = HWREG(ulBase+MCSPI_O_CH0STAT);
    
    //
    // Write value into Tx register/FIFO
    // if space is available
    //
    if(ulRegVal & MCSPI_CH0STAT_TXS)
    {
      HWREG(ulBase+MCSPI_O_TX0) = ulData;
      return(true);
    }
    
    return(false);
}

//*****************************************************************************
//
//! Waits until the word is transmitted on the specified port.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function transmits a word on the transmit FIFO for the specified
//! port. This function waits until the space is available on TX FIFO
//!
//! \return none
//!
//*****************************************************************************
void
McSPIDataPut(unsigned long ulBase, unsigned long ulData)
{
  //
  // Wait for space in FIFO
  //
  while(!(HWREG(ulBase+MCSPI_O_CH0STAT)&MCSPI_CH0STAT_TXS))
  {
  }
  
  //
  // Write the data
  //
  HWREG(ulBase+MCSPI_O_TX0) = ulData;
}


//*****************************************************************************
//
//! Enables the chip select (SPIEN)
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function enables the Chip select (SPIEN).The polatity of the enabled
//! state will depend on the configuration done via \sa McSPIConfig()
//!
//! \return None.
//!
//
//*****************************************************************************
void McSPICSEnable(unsigned long ulBase)
{
  //
  // Set Chip Select enable bit.
  //
  HWREG( ulBase+MCSPI_O_CH0CONF) |= MCSPI_CH0CONF_FORCE;
}

//*****************************************************************************
//
//! Disables the chip select (SPIEN)
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function disables the Chip select (SPIEN).The polatity of the disabled
//! state will depend on the configuration done via \sa McSPIConfig()
//!
//! \return None.
//!
//
//*****************************************************************************
void McSPICSDisable(unsigned long ulBase)
{
  //
  // Reset Chip Select enable bit.
  //
  HWREG( ulBase+MCSPI_O_CH0CONF) &= ~MCSPI_CH0CONF_FORCE;
}

//*****************************************************************************
//
//! Transfer Data over McSPI channel
//!
//! \param ulBase is the base address of McSPI port.
//! \param ucDout is the pointer to Tx data buffer or 0.
//! \param ucDin is pointer to Rx data buffer or 0
//! \param ulSize is the size of data in bytes.
//! \param ulFlags controlls chip select toggling.
//!
//! This function transfers \e ulSize bytes of data over McSPI channel.
//!
//! The parameter \e ucDout is a pointer to Tx buffer. If this parameter is 
//! set to 0, a stream of 1s is transferred
//!
//! The parameter \e ucDin is a pointer to Rx buffer.If this paramter is set
//! to 0, the received data is dead into a dummy variable internally.
//! 
//! The parameter \e ulFlags should be one of the following
//!
//! - \b MCSPI_CS_ENABLE if CS needs to be enabled at start of transfer.
//! - \b MCSPI_CS_DISABLE if CS need to be disabled at the end of transfer.
//!
//! \return None.
//
//*****************************************************************************
void McSPITransfer(unsigned long ulBase, unsigned char *ucDout,
                   unsigned char *ucDin, unsigned long ulSize,
                   unsigned long ulFlags)
{

  unsigned long ulDummy;

  if( ulFlags & MCSPI_CS_ENABLE)
  {
    HWREG( ulBase+MCSPI_O_CH0CONF) |= MCSPI_CH0CONF_FORCE;
  }

  while(ulSize)
  {

    while(!(HWREG(ulBase+MCSPI_O_CH0STAT) & MCSPI_CH0STAT_TXS))
    {
    }

    if(ucDout != 0)
    {
      HWREG(ulBase+MCSPI_O_TX0) = *ucDout;
      ucDout++;
    }
    else
    {
      HWREG(ulBase+MCSPI_O_TX0) = 0xFF;
    }

    while(!(HWREG(ulBase+MCSPI_O_CH0STAT)&MCSPI_CH0STAT_RXS))
    {
    }

    if(ucDin != 0)
    {
      *ucDin = HWREG(ulBase+MCSPI_O_RX0);
      ucDin++;
    }
    else
    {
      ulDummy = HWREG(ulBase+MCSPI_O_RX0);
    }

    ulSize--;
  }
  
  ulDummy = ulDummy;

  if( ulFlags & MCSPI_CS_DISABLE)
  {
    HWREG( ulBase+MCSPI_O_CH0CONF) &= ~MCSPI_CH0CONF_FORCE;
  }

}



//*****************************************************************************
//
//! Enables Tx and RX FIFO(s)
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulFlags selects the FIFO(s) to be enabled
//!
//! This function enables the Tx and RX FIFO(s) as specified by \e ulFlags.
//! The parameter \e ulFlags shoulde be logical OR of one or more of the
//! following:
//!
//! - \b MCSPI_TX_FIFO
//! - \b MCSPI_RX_FIFO
//!
//! \return None.
//
//*****************************************************************************
void McSPIFIFOEnable(unsigned long ulBase, unsigned long ulFlags)
{
  //
  // Set FIFO enable bits.
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) |= ulFlags;
}

//*****************************************************************************
//
//! Disables Tx and RX FIFO(s)
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulFlags selects the FIFO(s) to be enabled
//!
//! This function disables the Tx and RX FIFO(s) as specified by \e ulFlags.
//! The parameter \e ulFlags shoulde be logical OR of one or more of the
//! following:
//!
//! - \b MCSPI_TX_FIFO
//! - \b MCSPI_RX_FIFO
//!
//! \return None.
//
//*****************************************************************************
void McSPIFIFODisable(unsigned long ulBase, unsigned long ulFlags)
{
  //
  // Reset FIFO Enable bits.
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) &= ~(ulFlags);
}

//*****************************************************************************
//
//! Sets almost full level (AFL) for Rx FIFO.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucAFLevel is the almost full level for Rx FIFO.
//!
//! This function sets almost full level (AFL) for Rx FIFO. McSPI generates
//! an interrupt or read DMA request when the Rx FIFO contains atleast
//! \e ucAFLevel number of McSPI words.
//!
//! \return None.
//
//*****************************************************************************
void
McSPIConfigureAFL(unsigned long ulBase, unsigned char ucAFLevel)
{
  unsigned long ulRegVal;
  
  //
  // Read register value
  //
  ulRegVal  = (HWREG(ulBase+MCSPI_O_XFERLEVEL) & ~MCSPI_XFERLEVEL_AFL_M);
  
  //
  // Mask and Set the FIFO almost full level
  //
  ucAFLevel =  ucAFLevel & 0xFF;
  ulRegVal |=((ucAFLevel - 1) << MCSPI_XFERLEVEL_AFL_S);
  
  //
  // Write the configuration
  //
  HWREG(ulBase+MCSPI_O_XFERLEVEL) = ulRegVal;
}

//*****************************************************************************
//
//! Sets almost empty level (AEL) for Tx FIFO.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucAELevel is the almost empty level for Rx FIFO.
//!
//! This function almost empty level (AEL) for Tx FIFO. McSPI generates
//! an interrupt or write DMA request when the Tx FIFO has atleast
//! \e ucAELevel words free.
//!
//! \return None.
//
//*****************************************************************************
void
McSPIConfigureAEL(unsigned long ulBase, unsigned char ucAELevel)
{
  unsigned long ulRegVal;

  //
  // Read register value
  //
  ulRegVal = (HWREG(ulBase+MCSPI_O_XFERLEVEL)  & ~MCSPI_XFERLEVEL_AEL_M);

  //
  // Mask and Set the FIFO almost empty level
  //
  ucAELevel = ucAELevel & 0xFF;
  ulRegVal |= (ucAELevel -1) << MCSPI_XFERLEVEL_AEL_S;
  
  //
  // Write the configuration
  //
  HWREG(ulBase+MCSPI_O_XFERLEVEL) =  ulRegVal;
}

//*****************************************************************************
//
//! Sets the word count.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucWCNT is the requires word count.
//!
//! This function sets the word count, which is the number of words to be 
//! transffered on the channel from the FIFO. 
//!
//! \return None.
//
//*****************************************************************************
void McSPIConfigureWCNT(unsigned long ulBase, unsigned short ucWCNT)
{
  unsigned long ulRegVal;
  
  //
  // Read register value
  //    
  ulRegVal = (HWREG(ulBase+MCSPI_O_XFERLEVEL) & ~MCSPI_XFERLEVEL_WCNT_M);
  
  //
  // Set the word count, which is the number of words to be 
  // transffered on the channel from the FIFO. 
  //
  ulRegVal |= ((ucWCNT & 0xFFFF) << MCSPI_XFERLEVEL_WCNT_S);
  
  //
  // Write the configuration
  //  
  HWREG(ulBase+MCSPI_O_XFERLEVEL) = ulRegVal;
}

//*****************************************************************************
//
//! Enable Tx and/or Rx DMA
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulFlags selectes the DMA requests to be enabled
//!
//! This API enables Tx and Rx DMA request based on the \e ulFlags parameter
//! The parameter \e ulFlags is the logical OR of one or more of 
//! the following :
//!
//! - \b MCSPI_RX_DMA
//! - \b MCSPI_TX_DMA
//!
//! \return None.
//
//*****************************************************************************
void McSPIDmaEnable(unsigned long ulBase, unsigned long ulFlags)
{
  //
  // Enable DMA based on ulFlags
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) |= ulFlags;
}

//*****************************************************************************
//
//! Disabe Tx and/or Rx DMA
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulFlags selectes the DMA requests to be enabled
//!
//! This API disables Tx and Rx DMA request based on the \e ulFlags parameter
//! The parameter \e ulFlags is the logical OR of one or more of 
//! the following :
//!
//! - \b MCSPI_RX_DMA
//! - \b MCSPI_TX_DMA
//!
//! \return None.
//
//*****************************************************************************
void
McSPIDmaDisable(unsigned long ulBase, unsigned ulFlags)
{
  //
  // Disable DMA based on ulFlags
  //
  HWREG(ulBase+MCSPI_O_CH0CONF) &= ulFlags;
}

//*****************************************************************************
//
//! Registers an interrupt handler for a McSPI interrupt.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param pfnHandler is a pointer to the function to be called when the
//! UART interrupt occurs.
//!
//! This function does the actual registering of the interrupt handler.  This
//! function enables the global interrupt in the interrupt controller; specific
//! McSPI interrupts must be enabled via McSPIIntEnable(). It is the interrupt
//! handler's responsibility to clear the interrupt source.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
McSPIIntRegister(unsigned long ulBase, void(*pfnHandler)(void))
{
    unsigned long ulInt;

    //
    // Determine the interrupt number based on the McSPI port.
    //
    ulInt = McSPIIntNumberGet(ulBase);

    //
    // Register the interrupt handler.
    //
    IntRegister(ulInt, pfnHandler);

    //
    // Enable the McSPI interrupt.
    //
    IntEnable(ulInt);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for a McSPI interrupt.
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function does the actual unregistering of the interrupt handler.  It
//! clears the handler to be called when a McSPI interrupt occurs.  This
//! function also masks off the interrupt in the interrupt controller so that
//! the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
McSPIIntUnregister(unsigned long ulBase)
{
    unsigned long ulInt;
    
    //
    // Determine the interrupt number based on the McSPI port.
    //
    ulInt = McSPIIntNumberGet(ulBase);
    
    //
    // Disable the interrupt.
    //
    IntDisable(ulInt);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ulInt);
}

//*****************************************************************************
//
//! Enables individual McSPI interrupt sources.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated McSPI interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b MCSPI_INT_DMATX
//! - \b MCSPI_INT_DMARX
//! - \b MCSPI_INT_EOW
//! - \b MCSPI_INT_RX_OVRFLOW
//! - \b MCSPI_INT_RX_FULL
//! - \b MCSPI_INT_TX_UDRFLOW
//! - \b MCSPI_INT_TX_EMPTY
//!
//! \return None.
//
//*****************************************************************************
void
McSPIIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
  unsigned long ulDmaMsk;
 
  //
  // Enable DMA  Tx Interrupt
  //
  if(ulIntFlags & MCSPI_INT_DMATX)
  {
      ulDmaMsk = McSPIDmaMaskGet(ulBase);
      HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_CLR) = ulDmaMsk;
  }

  //
  // Enable DMA  Rx Interrupt
  //
  if(ulIntFlags & MCSPI_INT_DMARX)
  {
      ulDmaMsk = (McSPIDmaMaskGet(ulBase) >> 1);
      HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_CLR) = ulDmaMsk;
  }
  
  //
  // Enable the specific Interrupts
  //   
  HWREG(ulBase+MCSPI_O_IRQENABLE) |= (ulIntFlags & 0x0002000F);
}


//*****************************************************************************
//
//! Disables individual McSPI interrupt sources.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated McSPI interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to McSPIIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
McSPIIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
  unsigned long ulDmaMsk;

  //
  // Disable DMA  Tx Interrupt
  //
  if(ulIntFlags & MCSPI_INT_DMATX)
  {
      ulDmaMsk = McSPIDmaMaskGet(ulBase);
      HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_SET) = ulDmaMsk;
  }

  //
  // Disable DMA  Tx Interrupt
  //
  if(ulIntFlags & MCSPI_INT_DMARX)
  {
      ulDmaMsk = (McSPIDmaMaskGet(ulBase) >> 1);
      HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_MASK_SET) = ulDmaMsk;
  }
  
  //
  // Disable the specific Interrupts
  //   
  HWREG(ulBase+MCSPI_O_IRQENABLE) &= ~(ulIntFlags & 0x0002000F);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param bMasked is \b false if the raw interrupt status is required and
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the specified McSPI. 
//! The status of interrupts that are allowed to reflect to the processor can 
//! be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! values described in McSPIIntEnable().
//
//*****************************************************************************
unsigned long
McSPIIntStatus(unsigned long ulBase, tBoolean bMasked)
{
  unsigned long ulIntStat;
  unsigned long ulIntFlag;
  unsigned long ulDmaMsk;

  //
  // Get McSPI interrupt status
  //
  ulIntFlag = HWREG(ulBase+MCSPI_O_IRQSTATUS) & 0x0002000F;
  
  if(bMasked)
  {
     ulIntFlag &= HWREG(ulBase+MCSPI_O_IRQENABLE);
  }
  
  //
  // Get the interrupt bit
  //
  ulDmaMsk = McSPIDmaMaskGet(ulBase);
  
  //
  // Get the DMA interrupt status
  //
  if(bMasked)
  {
    ulIntStat = HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_STS_MASKED);
  }
  else
  {
    ulIntStat = HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_STS_RAW);
  }
  
  //
  // Get McSPI Tx DMA done status
  //
  if(ulIntStat & ulDmaMsk)
  {
     ulIntFlag |= MCSPI_INT_DMATX;
  }
  
  //
  // Get McSPI Rx DMA done status
  //
  if(ulIntStat & (ulDmaMsk >> 1))
  {
     ulIntFlag |= MCSPI_INT_DMARX;
  }
 
  //
  // Return status
  //
  return(ulIntFlag);
}


//*****************************************************************************
//
//! Clears McSPI interrupt sources.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified McSPI interrupt sources are cleared, so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupt from being recognized again immediately upon exit.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to McSPIIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
McSPIIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
  unsigned long ulDmaMsk;

  //
  // Disable DMA  Tx Interrupt
  //
  if(ulIntFlags & MCSPI_INT_DMATX)
  {
      ulDmaMsk = McSPIDmaMaskGet(ulBase);
      HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_ACK) = ulDmaMsk;
  }

  //
  // Disable DMA  Tx Interrupt
  //
  if(ulIntFlags & MCSPI_INT_DMARX)
  {
      ulDmaMsk = (McSPIDmaMaskGet(ulBase) >> 1);
      HWREG(APPS_CONFIG_BASE + APPS_CONFIG_O_DMA_DONE_INT_ACK) = ulDmaMsk;
  }
  
  //
  // Clear Interrupts
  //
  HWREG(ulBase+MCSPI_O_IRQSTATUS) = (ulIntFlags & 0x0002000F);
}

//*****************************************************************************
//
//! Sets the initial delay for first McSPI transfer
//!
//! \param ulBase is the base address of the McSPI port.
//! \param ucDelay is the number of clock cycles to be prefixed to Tx data.
//!
//! This function sets the delay for first transfer over McSPI channel.The
//! McSPI waits for a \e ucDelay clocks to transmit the first spi word after 
//! the channel is enabled and corresponding TX register is filled.
//!
//! The parameter \e ucDelay should be set to \b MCSPI_INITDLY_0 for 0 clocks,
//! \b MCSPI_INITDLY_4 for 4 clocks, \b MCSPI_INITDLY_8 for 8 clocks,
//! \b MCSPI_INITDLY_16 for 16 clocks and \b MCSPI_INITDLY_32 32 clocks delays.
//! 
//! \return None.
//
//*****************************************************************************
void McSPIInitDelaySet(unsigned long ulBase, unsigned char ucDelay)
{
  //
  // Set the specific delay.
  //
  HWREG(ulBase+MCSPI_O_MODULCTRL) |= (ucDelay &  MCSPI_MODULCTRL_INITDLY_M);
}


//*****************************************************************************
//
//! Gets the initial delay for first McSPI transfer
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function gets the current delay for first transfer over McSPI channel.
//! McSPI can waits for a 4,8,16 or 32 clocks to transmit the first spi word 
//! after the channel is enabled and corresponding TX register is filled.
//! 
//! \return Return the current delay as defined in \sa McSPIInitDelaySet().
//
//*****************************************************************************
unsigned long McSPIInitDelayGet(unsigned long ulBase)
{
  //
  // Set the specific delay.
  //
  return (HWREG(ulBase+MCSPI_O_MODULCTRL) & 0x70);
}

//*****************************************************************************
//
//! Enables Start bit
//!
//! \param ulBase is the base address of the McSPI port.
//! \param bSBPolHigh \b true if polarity is high, \b flash otherwise
//!
//! This finction enables the start bit feature of McSPI. If enabled, the 
//! Start bit D/CX is prefixed to SPI transfer with polarity as secified by
//! \e bSBPolHigh parameter.
//! 
//! \return None.
//
//*****************************************************************************
void McSPIStartBitEnable(unsigned long ulBase, tBoolean bSBPolHigh)
{

    unsigned long ulRegVal;

    //
    // Read the current register configuration.
    //
    ulRegVal = HWREG(ulBase+MCSPI_O_CH0CONF);
    
    //
    // Enable the start bit
    //
    ulRegVal |= MCSPI_CH0CONF_SBE;
    
    //
    // Set start bit polarity to 1 or 0
    //
    if(bSBPolHigh)
    {
      ulRegVal |= MCSPI_CH0CONF_SBPOL;
    }
    else
    {
      ulRegVal &= ~MCSPI_CH0CONF_SBPOL;
    }
      
    //
    // Write the new configuration.
    //
    HWREG(ulBase+MCSPI_O_CH0CONF) = ulRegVal;

}

//*****************************************************************************
//
//! Disables Start bit
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! \param ulBase is the base address of the McSPI port.
//! \param bSBPolHigh \b true if polarity is high, \b flash otherwise
//!
//! This finction disables the start bit feature of McSPI. If enabled, the 
//! Start bit D/CX is prefixed to SPI transfer with polarity as secified by
//! \e bSBPolHigh parameter of \sa McSPIStartBitEnable().
//!
//! \return None.
//
//*****************************************************************************
void McSPIStartBitDisable(unsigned long ulBase)
{
  //
  // Disable Start bit
  //
  HWREG(ulBase + MCSPI_O_CH0CONF) &= ~MCSPI_CH0CONF_SBE;
}

//*****************************************************************************
//
//! Enables Turbo Mode
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function Enables Turbo Mode for McSPI channel. Turbo is activated to
//! maximize the throughput for multi-SPI words transfer.
//!
//!
//! \return None.
//
//*****************************************************************************
void McSPITurboModeEnable(unsigned long ulBase)
{
  HWREG(ulBase+MCSPI_O_CH0CONF) |= MCSPI_CH0CONF_TURBO;
}

//*****************************************************************************
//
//! Disables Turbo Mode
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function disables Turbo Mode for McSPI channel. Turbo is activated to
//! maximize the throughput for multi-SPI words transfer.
//!
//!
//! \return None.
//
//*****************************************************************************
void McSPITurboModeDisable(unsigned long ulBase)
{
  HWREG(ulBase+MCSPI_O_CH0CONF) &= ~MCSPI_CH0CONF_TURBO;
}

//*****************************************************************************
//
//! Enable 3 Pin Mode for McSPI channel
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function Enable 3 Pin Mode for McSPI channel. In 3 Pin Mode
//! McSPI channel uses only MISO, MOSI and SPICLK clock pin(s) for spi 
//! transfers. SPIEN is ignored both in Master and Slave modes. 
//!
//! \return None.
//
//*****************************************************************************
void McSPI3PinModeEnable(unsigned long ulBase)
{
  //
  // Enable 3 Pin mode.
  //
  HWREG(ulBase+MCSPI_O_MODULCTRL) |= MCSPI_MODULCTRL_PIN34;
}

//*****************************************************************************
//
//! Enable 3 Pin Mode for McSPI channel
//!
//! \param ulBase is the base address of the McSPI port.
//!
//! This function disables 3 Pin Mode for McSPI channel. In 3 Pin Mode
//! McSPI channel uses only MISO, MOSI and SPICLK clock pin(s) for spi 
//! transfers. SPIEN is ignored both in Master and Slave modes.
//!
//! \return None.
//
//*****************************************************************************
void McSPI3PinModeDisable(unsigned long ulBase)
{
  //
  // Disable 3 Pin mode.
  //
  HWREG(ulBase+MCSPI_O_MODULCTRL) &= ~MCSPI_MODULCTRL_PIN34;
}



//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
