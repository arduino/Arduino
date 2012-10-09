//*****************************************************************************
//
// i2s.c - Driver for the I2S controller.
//
// Copyright (c) 2008-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup i2s_api
//! @{
//
//*****************************************************************************

#include "inc/hw_i2s.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/i2s.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
//! Enables the I2S transmit module for operation.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function enables the transmit module for operation.  The module
//! should be enabled after configuration.  When the module is disabled,
//! no data or clocks are generated on the I2S signals.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Enable the tx FIFO service request.
    //
    HWREG(ulBase + I2S_O_TXISM) = I2S_TXISM_FFM;

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ulBase + I2S_O_CFG) |= I2S_CFG_TXEN;
}

//*****************************************************************************
//
//! Disables the I2S transmit module for operation.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function disables the transmit module for operation.  The module
//! should be disabled before configuration.  When the module is disabled,
//! no data or clocks are generated on the I2S signals.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ulBase + I2S_O_CFG) &= ~I2S_CFG_TXEN;
}

//*****************************************************************************
//
//! Writes data samples to the I2S transmit FIFO with blocking.
//!
//! \param ulBase is the I2S module base address.
//! \param ulData is the single- or dual-channel I2S data.
//!
//! This function writes a single-channel sample or combined left-right
//! samples to the I2S transmit FIFO.  The format of the sample is determined
//! by the configuration that was used with the function I2STxConfigSet().
//! If the transmit mode is \b I2S_MODE_DUAL_STEREO then the \e ulData
//! parameter contains either the left or right sample.  The left and right
//! sample alternate with each write to the FIFO, left sample first.  If the
//! transmit mode is \b I2S_MODE_COMPACT_STEREO_16 or
//! \b I2S_MODE_COMPACT_STEREO_8, then the \e ulData parameter contains both
//! the left and right samples.  If the transmit mode is
//! \b I2S_MODE_SINGLE_MONO then the \e ulData parameter contains the single
//! channel sample.
//!
//! For the compact modes, both the left and right samples are written at
//! the same time.  If 16-bit compact mode is used, then the least significant
//! 16 bits contain the left sample, and the most significant 16 bits contain
//! the right sample.  If 8-bit compact mode is used, then the lower 8 bits
//! contain the left sample, and the next 8 bits contain the right sample,
//! with the upper 16 bits unused.
//!
//! If there is no room in the transmit FIFO, then this function waits
//! in a polling loop until the data can be written.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxDataPut(unsigned long ulBase, unsigned long ulData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Wait until there is space.
    //
    while(HWREG(ulBase + I2S_O_TXLEV) >= 16)
    {
    }

    //
    // Write the data to the I2S.
    //
    HWREG(ulBase + I2S_O_TXFIFO) = ulData;
}

//*****************************************************************************
//
//! Writes data samples to the I2S transmit FIFO without blocking.
//!
//! \param ulBase is the I2S module base address.
//! \param ulData is the single- or dual-channel I2S data.
//!
//! This function writes a single-channel sample or combined left-right
//! samples to the I2S transmit FIFO.  The format of the sample is determined
//! by the configuration that was used with the function I2STxConfigSet().
//! If the transmit mode is \b I2S_MODE_DUAL_STEREO then the \e ulData
//! parameter contains either the left or right sample.  The left and right
//! sample alternate with each write to the FIFO, left sample first.  If the
//! transmit mode is \b I2S_MODE_COMPACT_STEREO_16 or
//! \b I2S_MODE_COMPACT_STEREO_8, then the \e ulData parameter contains both
//! the left and right samples.  If the transmit mode is
//! \b I2S_MODE_SINGLE_MONO then the \e ulData parameter contains the single-
//! channel sample.
//!
//! For the compact modes, both the left and right samples are written at
//! the same time.  If 16-bit compact mode is used, then the least significant
//! 16 bits contain the left sample, and the most significant 16 bits contain
//! the right sample.  If 8-bit compact mode is used, then the lower 8 bits
//! contain the left sample, and the next 8 bits contain the right sample,
//! with the upper 16 bits unused.
//!
//! If there is no room in the transmit FIFO, then this function returns
//! immediately without writing any data to the FIFO.
//!
//! \return The number of elements written to the I2S transmit FIFO (1 or 0).
//
//*****************************************************************************
long
I2STxDataPutNonBlocking(unsigned long ulBase, unsigned long ulData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Check for space to write.
    //
    if(HWREG(ulBase + I2S_O_TXLEV) < 16)
    {
        HWREG(ulBase + I2S_O_TXFIFO) = ulData;
        return(1);
    }
    else
    {
        return(0);
    }
}

//*****************************************************************************
//
//! Configures the I2S transmit module.
//!
//! \param ulBase is the I2S module base address.
//! \param ulConfig is the logical OR of the configuration options.
//!
//! This function is used to configure the options for the I2S transmit
//! channel.  The parameter \e ulConfig is the logical OR of the following
//! options:
//!
//! - \b I2S_CONFIG_FORMAT_I2S for standard I2S format,
//!   \b I2S_CONFIG_FORMAT_LEFT_JUST for left justified format, or
//!   \b I2S_CONFIG_FORMAT_RIGHT_JUST for right justified format.
//! - \b I2S_CONFIG_SCLK_INVERT to invert the polarity of the serial bit clock.
//! - \b I2S_CONFIG_MODE_DUAL for dual channel stereo,
//!   \b I2S_CONFIG_MODE_COMPACT_16 for 16-bit compact stereo mode,
//!   \b I2S_CONFIG_MODE_COMPACT_8 for 8-bit compact stereo mode, or
//!   \b I2S_CONFIG_MODE_MONO for single channel mono format.
//! - \b I2S_CONFIG_CLK_MASTER or \b I2S_CONFIG_CLK_SLAVE to select whether
//!   the I2S transmitter is the clock master or slave.
//! - \b I2S_CONFIG_SAMPLE_SIZE_32, \b _24, \b _20, \b _16, or \b _8
//!   to select the number of bits per sample.
//! - \b I2S_CONFIG_WIRE_SIZE_32, \b _24, \b _20, \b _16, or \b _8
//!   to select the number of bits per word that are transferred on the data
//!   line.
//! - \b I2S_CONFIG_EMPTY_ZERO or \b I2S_CONFIG_EMPTY_REPEAT to select whether
//!   the module transmits zeroes or repeats the last sample when the FIFO is
//!   empty.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxConfigSet(unsigned long ulBase, unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulConfig & (I2S_CONFIG_FORMAT_MASK | I2S_CONFIG_MODE_MASK |
                        I2S_CONFIG_EMPTY_MASK | I2S_CONFIG_CLK_MASK |
                        I2S_CONFIG_SAMPLE_SIZE_MASK |
                        I2S_CONFIG_WIRE_SIZE_MASK)) == ulConfig);

    //
    // Check to see if a compact mode is used.
    //
    if((ulConfig & I2S_CONFIG_MODE_MASK) == I2S_CONFIG_MODE_COMPACT_8)
    {
        //
        // If compact 8 mode is used, then need to adjust some bits
        // before writing the config register.  Also set the FIFO
        // config register for 8-bit compact samples.
        //
        ulConfig &= ~I2S_CONFIG_MODE_MONO;
        HWREG(ulBase + I2S_O_TXFIFOCFG) = I2S_TXFIFOCFG_CSS;
    }
    else
    {
        //
        // If compact 8 mode is not used, then set the FIFO config
        // register for 16 bit.  This setting is okay if a compact
        // mode is not used.
        //
        HWREG(ulBase + I2S_O_TXFIFOCFG) = 0;
    }

    //
    // Write the configuration register.  Because all the fields are
    // specified by the configuration parameter, it is not necessary
    // to do a read-modify-write.
    //
    HWREG(ulBase + I2S_O_TXCFG) = ulConfig;
}

//*****************************************************************************
//
//! Sets the FIFO level at which a service request is generated.
//!
//! \param ulBase is the I2S module base address.
//! \param ulLevel is the FIFO service request limit.
//!
//! This function is used to set the transmit FIFO fullness level at which a
//! service request occurs.  The service request is used to generate an
//! interrupt or a DMA transfer request.  The transmit FIFO generates a
//! service request when the number of items in the FIFO is less than the level
//! specified in the \e ulLevel parameter.  For example, if \e ulLevel is 8,
//! then a service request is generated when there are less than 8 samples
//! remaining in the transmit FIFO.
//!
//! For the purposes of counting the FIFO level, a left-right sample pair
//! counts as 2, whether the mode is dual or compact stereo.  When mono mode is
//! used, internally the mono sample is still treated as a sample pair, so a
//! single mono sample counts as 2.  Because the FIFO always deals with sample
//! pairs, the level must be an even number from 0 to 16.  The maximum value is
//! 16, which causes a service request when there is any room in the FIFO.
//! The minimum value is 0, which disables the service request.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxFIFOLimitSet(unsigned long ulBase, unsigned long ulLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT(ulLevel <= 16);

    //
    // Write the FIFO limit
    //
    HWREG(ulBase + I2S_O_TXLIMIT) = ulLevel;
}

//*****************************************************************************
//
//! Gets the current setting of the FIFO service request level.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function is used to get the value of the transmit FIFO service
//! request level.  This value is set using the I2STxFIFOLimitSet()
//! function.
//!
//! \return Returns the current value of the FIFO service request limit.
//
//*****************************************************************************
unsigned long
I2STxFIFOLimitGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Read and return the FIFO limit
    //
    return(HWREG(ulBase + I2S_O_TXLIMIT));
}

//*****************************************************************************
//
//! Gets the number of samples in the transmit FIFO.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function is used to get the number of samples in the transmit FIFO.
//! For the purposes of measuring the FIFO level, a left-right sample pair
//! counts as 2, whether the mode is dual or compact stereo.  When mono mode is
//! used, internally the mono sample is still treated as a sample pair, so a
//! single mono sample counts as 2.  Because the FIFO always deals with sample
//! pairs, normally the level is an even number from 0 to 16.  If dual stereo
//! mode is used and only the left sample has been written without the matching
//! right sample, then the FIFO level is an odd value.  If the FIFO level is
//! odd, it indicates a left-right sample mismatch.
//!
//! \return Returns the number of samples in the transmit FIFO, which is
//! normally an even number.
//
//*****************************************************************************
unsigned long
I2STxFIFOLevelGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Read and return the transmit FIFO level.
    //
    return(HWREG(ulBase + I2S_O_TXLEV));
}

//*****************************************************************************
//
//! Enables the I2S receive module for operation.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function enables the receive module for operation.  The module should
//! be enabled after configuration.  When the module is disabled, no data is
//! clocked in regardless of the signals on the I2S interface.
//!
//! \return None.
//
//*****************************************************************************
void
I2SRxEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Enable the tx FIFO service request.
    //
    HWREG(ulBase + I2S_O_RXISM) = I2S_RXISM_FFM;

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ulBase + I2S_O_CFG) |= I2S_CFG_RXEN;
}

//*****************************************************************************
//
//! Disables the I2S receive module for operation.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function disables the receive module for operation.  The module should
//! be disabled before configuration.  When the module is disabled, no data is
//! clocked in regardless of the signals on the I2S interface.
//!
//! \return None.
//
//*****************************************************************************
void
I2SRxDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Read-modify-write the enable bit.
    //
    HWREG(ulBase + I2S_O_CFG) &= ~I2S_CFG_RXEN;
}

//*****************************************************************************
//
//! Reads data samples from the I2S receive FIFO with blocking.
//!
//! \param ulBase is the I2S module base address.
//! \param pulData points to storage for the returned I2S sample data.
//!
//! This function reads a single channel sample or combined left-right
//! samples from the I2S receive FIFO.  The format of the sample is determined
//! by the configuration that was used with the function I2SRxConfigSet().
//! If the receive mode is \b I2S_MODE_DUAL_STEREO then the returned value
//! contains either the left or right sample.  The left and right sample
//! alternate with each read from the FIFO, left sample first.  If the receive
//! mode is \b I2S_MODE_COMPACT_STEREO_16 or \b I2S_MODE_COMPACT_STEREO_8, then
//! the returned data contains both the left and right samples.  If the
//! receive mode is \b I2S_MODE_SINGLE_MONO then the returned data
//! contains the single channel sample.
//!
//! For the compact modes, both the left and right samples are read at
//! the same time.  If 16-bit compact mode is used, then the least significant
//! 16 bits contain the left sample, and the most significant 16 bits contain
//! the right sample.  If 8-bit compact mode is used, then the lower 8 bits
//! contain the left sample, and the next 8 bits contain the right sample,
//! with the upper 16 bits unused.
//!
//! If there is no data in the receive FIFO, then this function waits
//! in a polling loop until data is available.
//!
//! \return None.
//
//*****************************************************************************
void
I2SRxDataGet(unsigned long ulBase, unsigned long *pulData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Wait until there is data available.
    //
    while(HWREG(ulBase + I2S_O_RXLEV) == 0)
    {
    }

    //
    // Read data from the I2S receive FIFO.
    //
    *pulData = HWREG(ulBase + I2S_O_RXFIFO);
}

//*****************************************************************************
//
//! Reads data samples from the I2S receive FIFO without blocking.
//!
//! \param ulBase is the I2S module base address.
//! \param pulData points to storage for the returned I2S sample data.
//!
//! This function reads a single channel sample or combined left-right
//! samples from the I2S receive FIFO.  The format of the sample is determined
//! by the configuration that was used with the function I2SRxConfigSet().
//! If the receive mode is \b I2S_MODE_DUAL_STEREO then the received data
//! contains either the left or right sample.  The left and right sample
//! alternate with each read from the FIFO, left sample first.  If the receive
//! mode is \b I2S_MODE_COMPACT_STEREO_16 or \b I2S_MODE_COMPACT_STEREO_8, then
//! the received data contains both the left and right samples.  If the
//! receive mode is \b I2S_MODE_SINGLE_MONO then the received data
//! contains the single channel sample.
//!
//! For the compact modes, both the left and right samples are read at
//! the same time.  If 16-bit compact mode is used, then the least significant
//! 16 bits contain the left sample, and the most significant 16 bits contain
//! the right sample.  If 8-bit compact mode is used, then the lower 8 bits
//! contain the left sample, and the next 8 bits contain the right sample,
//! with the upper 16 bits unused.
//!
//! If there is no data in the receive FIFO, then this function returns
//! immediately without reading any data from the FIFO.
//!
//! \return The number of elements read from the I2S receive FIFO (1 or 0).
//
//*****************************************************************************
long
I2SRxDataGetNonBlocking(unsigned long ulBase, unsigned long *pulData)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Check for available samples.
    //
    if(HWREG(ulBase + I2S_O_RXLEV) != 0)
    {
        *pulData = HWREG(ulBase + I2S_O_RXFIFO);
        return(1);
    }
    else
    {
        return(0);
    }
}

//*****************************************************************************
//
//! Configures the I2S receive module.
//!
//! \param ulBase is the I2S module base address.
//! \param ulConfig is the logical OR of the configuration options.
//!
//! This function is used to configure the options for the I2S receive
//! channel.  The parameter \e ulConfig is the logical OR of the following
//! options:
//!
//! - \b I2S_CONFIG_FORMAT_I2S for standard I2S format,
//!   \b I2S_CONFIG_FORMAT_LEFT_JUST for left justified format, or
//!   \b I2S_CONFIG_FORMAT_RIGHT_JUST for right justified format.
//! - \b I2S_CONFIG_SCLK_INVERT to invert the polarity of the serial bit clock.
//! - \b I2S_CONFIG_MODE_DUAL for dual channel stereo,
//!   \b I2S_CONFIG_MODE_COMPACT_16 for 16-bit compact stereo mode,
//!   \b I2S_CONFIG_MODE_COMPACT_8 for 8-bit compact stereo mode, or
//!   \b I2S_CONFIG_MODE_MONO for single channel mono format.
//! - \b I2S_CONFIG_CLK_MASTER or \b I2S_CONFIG_CLK_SLAVE to select whether
//!   the I2S receiver is the clock master or slave.
//! - \b I2S_CONFIG_SAMPLE_SIZE_32, \b _24, \b _20, \b _16, or \b _8
//!   to select the number of bits per sample.
//! - \b I2S_CONFIG_WIRE_SIZE_32, \b _24, \b _20, \b _16, or \b _8
//!   to select the number of bits per word that are transferred on the data
//!   line.
//!
//! \return None.
//
//*****************************************************************************
void
I2SRxConfigSet(unsigned long ulBase, unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulConfig & (I2S_CONFIG_FORMAT_MASK | I2S_CONFIG_MODE_MASK |
                        I2S_CONFIG_CLK_MASK | I2S_CONFIG_SAMPLE_SIZE_MASK |
                        I2S_CONFIG_WIRE_SIZE_MASK)) == ulConfig);

    //
    // Clear out any prior config of the RX FIFO config register.
    //
    HWREG(ulBase + I2S_O_RXFIFOCFG) = 0;

    //
    // If mono mode is used, then the FMM bit needs to be set.
    //
    if((ulConfig & I2S_CONFIG_MODE_MASK) == I2S_CONFIG_MODE_MONO)
    {
        HWREG(ulBase + I2S_O_RXFIFOCFG) |= I2S_RXFIFOCFG_FMM;
    }

    //
    // If a compact mode is used, then the CSS bit needs to be set.
    //
    else if((ulConfig & I2S_CONFIG_MODE_MASK) == I2S_CONFIG_MODE_COMPACT_8)
    {
        HWREG(ulBase + I2S_O_RXFIFOCFG) |= I2S_RXFIFOCFG_CSS;
    }

    //
    // The "mono" bits must be removed from the configuration word
    // prior to writing to hardware, because the RX configuration register
    // does not actually use these bits.
    //
    ulConfig &= ~I2S_CONFIG_MODE_MONO;

    //
    // Write the configuration register.  Because all the fields are
    // specified by the configuration parameter, it is not necessary
    // to do a read-modify-write.
    //
    HWREG(ulBase + I2S_O_RXCFG) = ulConfig;
}

//*****************************************************************************
//
//! Sets the FIFO level at which a service request is generated.
//!
//! \param ulBase is the I2S module base address.
//! \param ulLevel is the FIFO service request limit.
//!
//! This function is used to set the receive FIFO fullness level at which a
//! service request occurs.  The service request is used to generate an
//! interrupt or a DMA transfer request.  The receive FIFO generates a
//! service request when the number of items in the FIFO is greater than the
//! level specified in the \e ulLevel parameter.  For example, if \e ulLevel is
//! 4, then a service request is generated when there are more than 4 samples
//! available in the receive FIFO.
//!
//! For the purposes of counting the FIFO level, a left-right sample pair
//! counts as 2, whether the mode is dual or compact stereo.  When mono mode is
//! used, internally the mono sample is still treated as a sample pair, so a
//! single mono sample counts as 2.  Because the FIFO always deals with sample
//! pairs, the level must be an even number from 0 to 16.  The minimum value is
//! 0, which causes a service request when there is any data available in
//! the FIFO.  The maximum value is 16, which disables the service request
//! (because there cannot be more than 16 items in the FIFO).
//!
//! \return None.
//
//*****************************************************************************
void
I2SRxFIFOLimitSet(unsigned long ulBase, unsigned long ulLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT(ulLevel <= 16);

    //
    // Write the FIFO limit
    //
    HWREG(ulBase + I2S_O_RXLIMIT) = ulLevel;
}

//*****************************************************************************
//
//! Gets the current setting of the FIFO service request level.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function is used to get the value of the receive FIFO service
//! request level.  This value is set using the I2SRxFIFOLimitSet()
//! function.
//!
//! \return Returns the current value of the FIFO service request limit.
//
//*****************************************************************************
unsigned long
I2SRxFIFOLimitGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Read and return the FIFO limit.  The lower bit is masked
    // because it always reads as 1 and has no meaning.
    //
    return(HWREG(ulBase + I2S_O_RXLIMIT) & 0xFFFE);
}

//*****************************************************************************
//
//! Gets the number of samples in the receive FIFO.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function is used to get the number of samples in the receive FIFO.
//! For the purposes of measuring the FIFO level, a left-right sample pair
//! counts as 2, whether the mode is dual or compact stereo.  When mono mode is
//! used, internally the mono sample is still treated as a sample pair, so a
//! single mono sample counts as 2.  Because the FIFO always deals with sample
//! pairs, normally the level is an even number from 0 to 16.  If dual stereo
//! mode is used and only the left sample has been read without reading the
//! matching right sample, then the FIFO level is an odd value.  If the FIFO
//! level is odd, it indicates a left-right sample mismatch.
//!
//! \return Returns the number of samples in the transmit FIFO, which is
//! normally an even number.
//
//*****************************************************************************
unsigned long
I2SRxFIFOLevelGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Read and return the receive FIFO level.
    //
    return(HWREG(ulBase + I2S_O_RXLEV));
}

//*****************************************************************************
//
//! Enables the I2S transmit and receive modules for operation.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function simultaneously enables the transmit and receive modules for
//! operation, providing a synchronized SCLK and LRCLK.  The module should be
//! enabled after configuration.  When the module is disabled, no data or
//! clocks are generated on the I2S signals.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxRxEnable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Enable the Tx FIFO service request.
    //
    HWREG(ulBase + I2S_O_TXISM) = I2S_TXISM_FFM;

    //
    // Enable the Rx FIFO service request.
    //
    HWREG(ulBase + I2S_O_RXISM) = I2S_RXISM_FFM;

    //
    // Enable the transmit and receive modules.
    //
    HWREG(ulBase + I2S_O_CFG) |= I2S_CFG_TXEN | I2S_CFG_RXEN;
}

//*****************************************************************************
//
//! Disables the I2S transmit and receive modules.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function simultaneously disables the transmit and receive modules.
//! When the module is disabled, no data or clocks are generated on the I2S
//! signals.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxRxDisable(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Disable the transmit and receive modules.
    //
    HWREG(ulBase + I2S_O_CFG) &= ~(I2S_CFG_TXEN | I2S_CFG_RXEN);
}

//*****************************************************************************
//
//! Configures the I2S transmit and receive modules.
//!
//! \param ulBase is the I2S module base address.
//! \param ulConfig is the logical OR of the configuration options.
//!
//! This function is used to configure the options for the I2S transmit and
//! receive channels with identical parameters.  The parameter \e ulConfig is
//! the logical OR of the following options:
//!
//! - \b I2S_CONFIG_FORMAT_I2S for standard I2S format,
//!   \b I2S_CONFIG_FORMAT_LEFT_JUST for left justified format, or
//!   \b I2S_CONFIG_FORMAT_RIGHT_JUST for right justified format.
//! - \b I2S_CONFIG_SCLK_INVERT to invert the polarity of the serial bit clock.
//! - \b I2S_CONFIG_MODE_DUAL for dual-channel stereo,
//!   \b I2S_CONFIG_MODE_COMPACT_16 for 16-bit compact stereo mode,
//!   \b I2S_CONFIG_MODE_COMPACT_8 for 8-bit compact stereo mode, or
//!   \b I2S_CONFIG_MODE_MONO for single-channel mono format.
//! - \b I2S_CONFIG_CLK_MASTER or \b I2S_CONFIG_CLK_SLAVE to select whether
//!   the I2S transmitter is the clock master or slave.
//! - \b I2S_CONFIG_SAMPLE_SIZE_32, \b _24, \b _20, \b _16, or \b _8
//!   to select the number of bits per sample.
//! - \b I2S_CONFIG_WIRE_SIZE_32, \b _24, \b _20, \b _16, or \b _8
//!   to select the number of bits per word that are transferred on the data
//!   line.
//! - \b I2S_CONFIG_EMPTY_ZERO or \b I2S_CONFIG_EMPTY_REPEAT to select whether
//!   the module transmits zeroes or repeats the last sample when the FIFO is
//!   empty.
//!
//! \return None.
//
//*****************************************************************************
void
I2STxRxConfigSet(unsigned long ulBase, unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulConfig & (I2S_CONFIG_FORMAT_MASK | I2S_CONFIG_MODE_MASK |
                        I2S_CONFIG_EMPTY_MASK | I2S_CONFIG_CLK_MASK |
                        I2S_CONFIG_SAMPLE_SIZE_MASK |
                        I2S_CONFIG_WIRE_SIZE_MASK)) == ulConfig);

    //
    // Clear out any prior configuration of the FIFO config registers.
    //
    HWREG(ulBase + I2S_O_TXFIFOCFG) = 0;
    HWREG(ulBase + I2S_O_RXFIFOCFG) = 0;

    //
    // If mono mode is used, then the FMM bit needs to be set.
    //
    if((ulConfig & I2S_CONFIG_MODE_MASK) == I2S_CONFIG_MODE_MONO)
    {
        HWREG(ulBase + I2S_O_RXFIFOCFG) |= I2S_RXFIFOCFG_FMM;
        ulConfig &= ~(I2S_CONFIG_MODE_MONO);
    }

    //
    // If a compact mode is used, then the CSS bit needs to be set.
    //
    if((ulConfig & I2S_CONFIG_MODE_MASK) == I2S_CONFIG_MODE_COMPACT_8)
    {
        HWREG(ulBase + I2S_O_TXFIFOCFG) |= I2S_TXFIFOCFG_CSS;
        HWREG(ulBase + I2S_O_RXFIFOCFG) |= I2S_RXFIFOCFG_CSS;
    }

    //
    // Write the configuration register.  Because all the fields are specified
    // by the configuration parameter, it is not necessary to do a
    // read-modify-write.
    //
    HWREG(ulBase + I2S_O_TXCFG) = ulConfig;
    HWREG(ulBase + I2S_O_RXCFG) = ulConfig;
}

//*****************************************************************************
//
//! Selects the source of the master clock, internal or external.
//!
//! \param ulBase is the I2S module base address.
//! \param ulMClock is the logical OR of the master clock configuration
//! choices.
//!
//! This function selects whether the master clock is sourced from the device
//! internal PLL or comes from an external pin.  The I2S serial bit clock
//! (SCLK) and left-right word clock (LRCLK) are derived from the I2S master
//! clock.  The transmit and receive modules can be configured independently.
//!  The \e ulMClock parameter is chosen from the following:
//!
//! - one of \b I2S_TX_MCLK_EXT or \b I2S_TX_MCLK_INT
//! - one of \b I2S_RX_MCLK_EXT or \b I2S_RX_MCLK_INT
//!
//! \return None.
//
//*****************************************************************************
void
I2SMasterClockSelect(unsigned long ulBase, unsigned long ulMClock)
{
    unsigned long ulConfig;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulMClock & (I2S_TX_MCLK_EXT | I2S_RX_MCLK_EXT)) == ulMClock);

    //
    // Set the clock selection bits in the configuation word.
    //
    ulConfig = HWREG(ulBase + I2S_O_CFG) &
                   ~(I2S_TX_MCLK_EXT | I2S_RX_MCLK_EXT);
    HWREG(ulBase + I2S_O_CFG) = ulConfig | ulMClock;
}

//*****************************************************************************
//
//! Enables I2S interrupt sources.
//!
//! \param ulBase is the I2S module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the specified I2S sources to generate interrupts.
//! The \e ulIntFlags parameter can be the logical OR of any of the following
//! values:
//!
//! - \b I2S_INT_RXERR for receive errors
//! - \b I2S_INT_RXREQ for receive FIFO service requests
//! - \b I2S_INT_TXERR for transmit errors
//! - \b I2S_INT_TXREQ for transmit FIFO service requests
//!
//! \return None.
//
//*****************************************************************************
void
I2SIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulIntFlags & (I2S_INT_RXERR | I2S_INT_RXREQ |
                          I2S_INT_TXERR | I2S_INT_TXREQ)) == ulIntFlags);

    //
    // Enable the specified interrupts.
    //
    HWREG(ulBase + I2S_O_IM) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables I2S interrupt sources.
//!
//! \param ulBase is the I2S module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the specified I2S sources for interrupt
//! generation.  The \e ulIntFlags parameter can be the logical OR
//! of any of the following values: \b I2S_INT_RXERR, \b I2S_INT_RXREQ,
//! \b I2S_INT_TXERR, or \b I2S_INT_TXREQ.
//!
//! \return None.
//
//*****************************************************************************
void
I2SIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulIntFlags & (I2S_INT_RXERR | I2S_INT_RXREQ |
                          I2S_INT_TXERR | I2S_INT_TXREQ)) == ulIntFlags);

    //
    // Enable the specified interrupts.
    //
    HWREG(ulBase + I2S_O_IM) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the I2S interrupt status.
//!
//! \param ulBase is the I2S module base address.
//! \param bMasked is set \b true to get the masked interrupt status, or
//! \b false to get the raw interrupt status.
//!
//! This function returns the I2S interrupt status.  It can return either
//! the raw or masked interrupt status.
//!
//! \return Returns the masked or raw I2S interrupt status, as a bit field
//! of any of the following values: \b I2S_INT_RXERR, \b I2S_INT_RXREQ,
//! \b I2S_INT_TXERR, or \b I2S_INT_TXREQ
//
//*****************************************************************************
unsigned long
I2SIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + I2S_O_MIS));
    }
    else
    {
        return(HWREG(ulBase + I2S_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears pending I2S interrupt sources.
//!
//! \param ulBase is the I2S module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! This function clears the specified pending I2S interrupts.  This function
//! must be called in the interrupt handler to keep the interrupt from being
//! triggered again immediately upon exit.  The \e ulIntFlags parameter can be
//! the logical OR of any of the following values: \b I2S_INT_RXERR,
//! \b I2S_INT_RXREQ, \b I2S_INT_TXERR, or \b I2S_INT_TXREQ.
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
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
void
I2SIntClear(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT((ulIntFlags & (I2S_INT_RXERR | I2S_INT_RXREQ |
                          I2S_INT_TXERR | I2S_INT_TXREQ)) == ulIntFlags);

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ulBase + I2S_O_IC) = ulIntFlags;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the I2S controller.
//!
//! \param ulBase is the I2S module base address.
//! \param pfnHandler is a pointer to the function to be called when the
//! interrupt is activated.
//!
//! This function sets and enables the handler to be called when the I2S
//! controller generates an interrupt.  Specific I2S interrupts must still be
//! enabled with the I2SIntEnable() function.  It is the responsibility of the
//! interrupt handler to clear any pending interrupts with I2SIntClear().
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
I2SIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);
    ASSERT(pfnHandler);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_I2S0, pfnHandler);

    //
    // Enable the I2S interface interrupt.
    //
    IntEnable(INT_I2S0);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the I2S controller.
//!
//! \param ulBase is the I2S module base address.
//!
//! This function disables and clears the handler to be called when the
//! I2S interrupt occurs.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
I2SIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == I2S0_BASE);

    //
    // Disable the I2S interface interrupt.
    //
    IntDisable(INT_I2S0);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_I2S0);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
