//*****************************************************************************
//
// epi.c - Driver for the EPI module.
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

#include "inc/hw_epi.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/epi.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
//! \addtogroup epi_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! Sets the usage mode of the EPI module.
//!
//! \param ulBase is the EPI module base address.
//! \param ulMode is the usage mode of the EPI module.
//!
//! This functions sets the operating mode of the EPI module.  The parameter
//! \e ulMode must be one of the following:
//!
//! - \b EPI_MODE_GENERAL - use for general-purpose mode operation
//! - \b EPI_MODE_SDRAM - use with SDRAM device
//! - \b EPI_MODE_HB8 - use with host-bus 8-bit interface
//! - \b EPI_MODE_HB16 - use with host-bus 16-bit interface
//! - \b EPI_MODE_DISABLE - disable the EPI module
//!
//! Selection of any of the above modes enables the EPI module, except
//! for \b EPI_MODE_DISABLE which should be used to disable the module.
//!
//! \return None.
//
//*****************************************************************************
void
EPIModeSet(unsigned long ulBase, unsigned long ulMode)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT((ulMode == EPI_MODE_GENERAL) ||
           (ulMode == EPI_MODE_SDRAM) ||
           (ulMode == EPI_MODE_HB8) ||
           (ulMode == EPI_MODE_HB16) ||
           (ulMode == EPI_MODE_DISABLE));

    //
    // Write the mode word to the register.
    //
    HWREG(ulBase + EPI_O_CFG) = ulMode;
}

//*****************************************************************************
//
//! Sets the clock divider for the EPI module.
//!
//! \param ulBase is the EPI module base address.
//! \param ulDivider is the value of the clock divider to be applied to
//! the external interface (0-65535).
//!
//! This function sets the clock divider(s) that is used to determine the
//! clock rate of the external interface.  The \e ulDivider value is used to
//! derive the EPI clock rate from the system clock based on the following
//! formula.
//!
//! EPIClock = (Divider == 0) ? SysClk : (SysClk / (((Divider / 2) + 1) * 2))
//!
//! For example, a divider value of 1 results in an EPI clock rate of half
//! the system clock, value of 2 or 3 yields one quarter of the system clock and
//! a value of 4 results in one sixth of the system clock rate.
//!
//! In cases where a dual chip select mode is in use and different clock rates
//! are required for each chip select, the \e ulDivider parameter must contain
//! two dividers.  The lower 16 bits define the divider to be used with CS0n
//! and the upper 16 bits define the divider for CS1n.
//!
//! \return None.
//
//*****************************************************************************
void
EPIDividerSet(unsigned long ulBase, unsigned long ulDivider)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);

    //
    // Write the divider value to the register.
    //
    HWREG(ulBase + EPI_O_BAUD) = ulDivider;
}

//*****************************************************************************
//
//! Configures the SDRAM mode of operation.
//!
//! \param ulBase is the EPI module base address.
//! \param ulConfig is the SDRAM interface configuration.
//! \param ulRefresh is the refresh count in core clocks (0-2047).
//!
//! This function is used to configure the SDRAM interface, when the SDRAM
//! mode is chosen with the function EPIModeSet().  The parameter \e ulConfig
//! is the logical OR of several sets of choices:
//!
//! The processor core frequency must be specified with one of the following:
//!
//! - \b EPI_SDRAM_CORE_FREQ_0_15 - core clock is 0 MHz < clk <= 15 MHz
//! - \b EPI_SDRAM_CORE_FREQ_15_30 - core clock is 15 MHz < clk <= 30 MHz
//! - \b EPI_SDRAM_CORE_FREQ_30_50 - core clock is 30 MHz < clk <= 50 MHz
//! - \b EPI_SDRAM_CORE_FREQ_50_100 - core clock is 50 MHz < clk <= 100 MHz
//!
//! The low power mode is specified with one of the following:
//!
//! - \b EPI_SDRAM_LOW_POWER - enter low power, self-refresh state
//! - \b EPI_SDRAM_FULL_POWER - normal operating state
//!
//! The SDRAM device size is specified with one of the following:
//!
//! - \b EPI_SDRAM_SIZE_64MBIT - 64 Mbit device (8 MB)
//! - \b EPI_SDRAM_SIZE_128MBIT - 128 Mbit device (16 MB)
//! - \b EPI_SDRAM_SIZE_256MBIT - 256 Mbit device (32 MB)
//! - \b EPI_SDRAM_SIZE_512MBIT - 512 Mbit device (64 MB)
//!
//! The parameter \e ulRefresh sets the refresh counter in units of core
//! clock ticks.  It is an 11-bit value with a range of 0 - 2047 counts.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigSDRAMSet(unsigned long ulBase, unsigned long ulConfig,
                  unsigned long ulRefresh)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulRefresh < 2048);

    //
    // Fill in the refresh count field of the configuration word.
    //
    ulConfig &= ~EPI_SDRAMCFG_RFSH_M;
    ulConfig |= ulRefresh << EPI_SDRAMCFG_RFSH_S;

    //
    // Write the SDRAM configuration register.
    //
    HWREG(ulBase + EPI_O_SDRAMCFG) = ulConfig;
}

//*****************************************************************************
//
//! Configures the interface for Host-bus 8 operation.
//!
//! \param ulBase is the EPI module base address.
//! \param ulConfig is the interface configuration.
//! \param ulMaxWait is the maximum number of external clocks to wait
//! if a FIFO ready signal is holding off the transaction.
//!
//! This function is used to configure the interface when used in Host-bus 8
//! operation as chosen with the function EPIModeSet().  The parameter
//! \e ulConfig is the logical OR of any of the following:
//!
//! - one of \b EPI_HB8_MODE_ADMUX, \b EPI_HB8_MODE_ADDEMUX,
//! \b EPI_HB8_MODE_SRAM, or \b EPI_HB8_MODE_FIFO to select the HB8 mode
//! - \b EPI_HB8_USE_TXEMPTY - enable TXEMPTY signal with FIFO
//! - \b EPI_HB8_USE_RXFULL - enable RXFULL signal with FIFO
//! - \b EPI_HB8_WRHIGH - use active high write strobe, otherwise it is
//! active low
//! - \b EPI_HB8_RDHIGH - use active high read strobe, otherwise it is
//! active low
//! - one of \b EPI_HB8_WRWAIT_0, \b EPI_HB8_WRWAIT_1, \b EPI_HB8_WRWAIT_2,
//! or \b EPI_HB8_WRWAIT_3 to select the number of write wait states (default
//! is 0 wait states)
//! - one of \b EPI_HB8_RDWAIT_0, \b EPI_HB8_RDWAIT_1, \b EPI_HB8_RDWAIT_2,
//! or \b EPI_HB8_RDWAIT_3 to select the number of read wait states (default
//! is 0 wait states)
//! - \b EPI_HB8_WORD_ACCESS - use Word Access mode to route bytes to the
//! correct byte lanes allowing data to be stored in bits [31:8].  If absent,
//! all data transfers use bits [7:0].
//! - \b EPI_HB8_CSBAUD_DUAL - use different baud rates when accessing devices
//! on each CSn. CS0n uses the baud rate specified by the lower 16 bits of the
//! divider passed to EPIDividerSet() and CS1n uses the divider passed in the
//! upper 16 bits.  If this option is absent, both chip selects use the baud
//! rate resulting from the divider in the lower 16 bits of the parameter passed
//! to EPIDividerSet().
//! - one of \b EPI_HB8_CSCFG_CS, \b EPI_HB8_CSCFG_ALE,
//! \b EPI_HB8_CSCFG_DUAL_CS or \b EPI_HB8_CSCFG_ALE_DUAL_CS.
//! \b EPI_HB8_CSCFG_CS sets EPI30 to operate as a Chip Select (CSn) signal.
//! \b EPI_HB8_CSCFG_ALE sets EPI30 to operate as an address latch (ALE).
//! \b EPI_HB8_CSCFG_DUAL_CS sets EPI30 to operate as CS0n and EPI27 as CS1n
//! with the asserted chip select determined from the most significant address
//! bit for the respective external address map.  \b EPI_HB8_CSCFG_ALE_DUAL_CS
//! sets EPI30 as an address latch (ALE), EPI27 as CS0n and EPI26 as CS1n with
//! the asserted chip select determined from the most significant address bit
//! for the respective external address map.
//!
//! The parameter \e ulMaxWait is used if the FIFO mode is chosen.  If a
//! FIFO is used along with RXFULL or TXEMPTY ready signals, then this
//! parameter determines the maximum number of clocks to wait when the
//! transaction is being held off by by the FIFO using one of these ready
//! signals.  A value of 0 means to wait forever.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB8Set(unsigned long ulBase, unsigned long ulConfig,
                unsigned long ulMaxWait)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulMaxWait < 256);

    //
    // Determine the CS and word access modes.
    //
    HWREG(ulBase + EPI_O_HB8CFG2) = (((ulConfig & EPI_HB8_WORD_ACCESS) ?
                                       EPI_HB8CFG2_WORD : 0) |
                                     ((ulConfig & EPI_HB8_CSBAUD_DUAL) ?
                                       EPI_HB8CFG2_CSBAUD : 0) |
                                      ((ulConfig & EPI_HB8_CSCFG_MASK) << 15));
    //
    // Fill in the max wait field of the configuration word.
    //
    ulConfig &= ~EPI_HB8CFG_MAXWAIT_M;
    ulConfig |= ulMaxWait << EPI_HB8CFG_MAXWAIT_S;

    //
    // Write the main HostBus8 configuration register.
    //
    HWREG(ulBase + EPI_O_HB8CFG)  = ulConfig;
}

//*****************************************************************************
//
//! Configures the interface for Host-bus 16 operation.
//!
//! \param ulBase is the EPI module base address.
//! \param ulConfig is the interface configuration.
//! \param ulMaxWait is the maximum number of external clocks to wait
//! if a FIFO ready signal is holding off the transaction.
//!
//! This function is used to configure the interface when used in Host-bus 16
//! operation as chosen with the function EPIModeSet().  The parameter
//! \e ulConfig is the logical OR of any of the following:
//!
//! - one of \b EPI_HB16_MODE_ADMUX, \b EPI_HB16_MODE_ADDEMUX,
//! \b EPI_HB16_MODE_SRAM, or \b EPI_HB16_MODE_FIFO to select the HB16 mode
//! - \b EPI_HB16_USE_TXEMPTY - enable TXEMPTY signal with FIFO
//! - \b EPI_HB16_USE_RXFULL - enable RXFULL signal with FIFO
//! - \b EPI_HB16_WRHIGH - use active high write strobe, otherwise it is
//! active low
//! - \b EPI_HB16_RDHIGH - use active high read strobe, otherwise it is
//! active low
//! - one of \b EPI_HB16_WRWAIT_0, \b EPI_HB16_WRWAIT_1, \b EPI_HB16_WRWAIT_2,
//! or \b EPI_HB16_WRWAIT_3 to select the number of write wait states (default
//! is 0 wait states)
//! - one of \b EPI_HB16_RDWAIT_0, \b EPI_HB16_RDWAIT_1, \b EPI_HB16_RDWAIT_2,
//! or \b EPI_HB16_RDWAIT_3 to select the number of read wait states (default
//! is 0 wait states)
//! - \b EPI_HB16_WORD_ACCESS - use Word Access mode to route bytes to the
//! correct byte lanes allowing data to be stored in bits [31:16].  If absent,
//! all data transfers use bits [15:0].
//! - \b EPI_HB16_BSEL - enables byte selects.  In this mode, two EPI signals
//! operate as byte selects allowing 8-bit transfers.  If this flag is not
//! specified, data must be read and written using only 16-bit transfers.
//! - \b EPI_HB16_CSBAUD_DUAL - use different baud rates when accessing devices
//! on each CSn. CS0n uses the baud rate specified by the lower 16 bits of the
//! divider passed to EPIDividerSet() and CS1n uses the divider passed in the
//! upper 16 bits.  If this option is absent, both chip selects use the baud
//! rate resulting from the divider in the lower 16 bits of the parameter passed
//! to EPIDividerSet().
//! - one of \b EPI_HB16_CSCFG_CS, \b EPI_HB16_CSCFG_ALE,
//! \b EPI_HB16_CSCFG_DUAL_CS or \b EPI_HB16_CSCFG_ALE_DUAL_CS.
//! \b EPI_HB16_CSCFG_CS sets EPI30 to operate as a Chip Select (CSn) signal.
//! \b EPI_HB16_CSCFG_ALE sets EPI30 to operate as an address latch (ALE).
//! \b EPI_HB16_CSCFG_DUAL_CS sets EPI30 to operate as CS0n and EPI27 as CS1n
//! with the asserted chip select determined from the most significant address
//! bit for the respective external address map.  \b EPI_HB16_CSCFG_ALE_DUAL_CS
//! sets EPI30 as an address latch (ALE), EPI27 as CS0n and EPI26 as CS1n with
//! the asserted chip select determined from the most significant address bit
//! for the respective external address map.
//!
//! The parameter \e ulMaxWait is used if the FIFO mode is chosen.  If a
//! FIFO is used along with RXFULL or TXEMPTY ready signals, then this
//! parameter determines the maximum number of clocks to wait when the
//! transaction is being held off by by the FIFO using one of these ready
//! signals.  A value of 0 means to wait forever.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB16Set(unsigned long ulBase, unsigned long ulConfig,
                unsigned long ulMaxWait)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulMaxWait < 256);

    //
    // Determine the CS and word access modes.
    //
    HWREG(ulBase + EPI_O_HB16CFG2) = (((ulConfig & EPI_HB16_WORD_ACCESS) ?
                                       EPI_HB16CFG2_WORD : 0) |
                                     ((ulConfig & EPI_HB16_CSBAUD_DUAL) ?
                                       EPI_HB16CFG2_CSBAUD : 0) |
                                      ((ulConfig & EPI_HB16_CSCFG_MASK) << 15));

    //
    // Fill in the max wait field of the configuration word.
    //
    ulConfig &= ~EPI_HB16CFG_MAXWAIT_M;
    ulConfig |= ulMaxWait << EPI_HB16CFG_MAXWAIT_S;

    //
    // Write the main HostBus16 configuration register.
    //
    HWREG(ulBase + EPI_O_HB16CFG)  = ulConfig;
}

//*****************************************************************************
//
//! Configures the interface for general-purpose mode operation.
//!
//! \param ulBase is the EPI module base address.
//! \param ulConfig is the interface configuration.
//! \param ulFrameCount is the frame size in clocks, if the frame signal
//! is used (0-15).
//! \param ulMaxWait is the maximum number of external clocks to wait
//! when the external clock enable is holding off the transaction (0-255).
//!
//! This function is used to configure the interface when used in
//! general-purpose operation as chosen with the function EPIModeSet().  The
//! parameter \e ulConfig is the logical OR of any of the following:
//!
//! - \b EPI_GPMODE_CLKPIN - interface clock is output on a pin
//! - \b EPI_GPMODE_CLKGATE - clock is stopped when there is no transaction,
//! otherwise it is free-running
//! - \b EPI_GPMODE_RDYEN - the external peripheral drives an iRDY signal into
//! pin EPI0S27.  If absent, the peripheral is assumed to be ready at all times.
//! This flag may only be used with a free-running clock (\b EPI_GPMODE_CLKGATE
//! is absent).
//! - \b EPI_GPMODE_FRAMEPIN - framing signal is emitted on a pin
//! - \b EPI_GPMODE_FRAME50 - framing signal is 50/50 duty cycle, otherwise it
//! is a pulse
//! - \b EPI_GPMODE_READWRITE - read and write strobes are emitted on pins
//! - \b EPI_GPMODE_WRITE2CYCLE - a two-cycle write is used, otherwise a
//! single-cycle write is used
//! - \b EPI_GPMODE_READ2CYCLE - a two-cycle read is used, otherwise a
//! single-cycle read is used
//! - \b EPI_GPMODE_ASIZE_NONE, \b EPI_GPMODE_ASIZE_4,
//! \b EPI_GPMODE_ASIZE_12, or \b EPI_GPMODE_ASIZE_20 to choose no address
//! bus or an address bus size of 4, 12, or 20 bits
//! - \b EPI_GPMODE_DSIZE_8, \b EPI_GPMODE_DSIZE_16,
//! \b EPI_GPMODE_DSIZE_24, or \b EPI_GPMODE_DSIZE_32 to select a data bus
//! size of 8, 16, 24, or 32 bits
//! - \b EPI_GPMODE_WORD_ACCESS - use Word Access mode to route bytes to the
//! correct byte lanes allowing data to be stored in the upper bits of the word
//! when necessary.
//!
//! The parameter \e ulFrameCount is the number of clocks used to form the
//! framing signal, if the framing signal is used.  The behavior depends on
//! whether the frame signal is a pulse or a 50/50 duty cycle.  This value
//! is not used if the framing signal is not enabled with the option
//! \b EPI_GPMODE_FRAMEPIN.
//!
//! The parameter \e ulMaxWait is used if the external clock enable is turned
//! on with the \b EPI_GPMODE_CLKENA option is used.  In the case that
//! external clock enable is used, this parameter determines the maximum
//! number of clocks to wait when the external clock enable signal is holding
//! off a transaction.  A value of 0 means to wait forever.  If a non-zero
//! value is used and exceeded, an interrupt occurs and the transaction
//! aborted.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigGPModeSet(unsigned long ulBase, unsigned long ulConfig,
                   unsigned long ulFrameCount, unsigned long ulMaxWait)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulFrameCount < 16);
    ASSERT(ulMaxWait < 256);

    //
    // Set the word access mode.
    //
    HWREG(ulBase + EPI_O_GPCFG2) = ((ulConfig & EPI_GPMODE_WORD_ACCESS) ?
                                    EPI_GPCFG2_WORD : 0);

    //
    // Fill in the frame count field of the configuration word.
    //
    ulConfig &= ~EPI_GPCFG_FRMCNT_M;
    ulConfig |= ulFrameCount << EPI_GPCFG_FRMCNT_S;

    //
    // Fill in the max wait field of the configuration word.
    //
    ulConfig &= ~EPI_GPCFG_MAXWAIT_M;
    ulConfig |= ulMaxWait << EPI_GPCFG_MAXWAIT_S;

    //
    // Write the non-moded configuration register.
    //
    HWREG(ulBase + EPI_O_GPCFG) = ulConfig;
}

//*****************************************************************************
//
//! Configures the address map for the external interface.
//!
//! \param ulBase is the EPI module base address.
//! \param ulMap is the address mapping configuration.
//!
//! This function is used to configure the address mapping for the external
//! interface.  This determines the base address of the external memory or
//! device within the processor peripheral and/or memory space.
//!
//! The parameter \e ulMap is the logical OR of the following:
//!
//! - \b EPI_ADDR_PER_SIZE_256B, \b EPI_ADDR_PER_SIZE_64KB,
//! \b EPI_ADDR_PER_SIZE_16MB, or \b EPI_ADDR_PER_SIZE_512MB to choose a
//! peripheral address space of 256 bytes, 64 Kbytes, 16 Mbytes or 512 Mbytes
//! - \b EPI_ADDR_PER_BASE_NONE, \b EPI_ADDR_PER_BASE_A, or
//! \b EPI_ADDR_PER_BASE_C to choose the base address of the peripheral
//! space as none, 0xA0000000, or 0xC0000000
//! - \b EPI_ADDR_RAM_SIZE_256B, \b EPI_ADDR_RAM_SIZE_64KB,
//! \b EPI_ADDR_RAM_SIZE_16MB, or \b EPI_ADDR_RAM_SIZE_512MB to choose a
//! RAM address space of 256 bytes, 64 Kbytes, 16 Mbytes or 512 Mbytes
//! - \b EPI_ADDR_RAM_BASE_NONE, \b EPI_ADDR_RAM_BASE_6, or
//! \b EPI_ADDR_RAM_BASE_8 to choose the base address of the RAM space
//! as none, 0x60000000, or 0x80000000
//!
//! \return None.
//
//*****************************************************************************
void
EPIAddressMapSet(unsigned long ulBase, unsigned long ulMap)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulMap < 0x100);

    //
    // Set the value of the address mapping register.
    //
    HWREG(ulBase + EPI_O_ADDRMAP) = ulMap;
}

//*****************************************************************************
//
//! Configures a non-blocking read transaction.
//!
//! \param ulBase is the EPI module base address.
//! \param ulChannel is the read channel (0 or 1).
//! \param ulDataSize is the size of the data items to read.
//! \param ulAddress is the starting address to read.
//!
//! This function is used to configure a non-blocking read channel for a
//! transaction.  Two channels are available which can be used in a ping-pong
//! method for continuous reading.  It is not necessary to use both channels
//! to perform a non-blocking read.
//!
//! The parameter \e ulDataSize is one of \b EPI_NBCONFIG_SIZE_8,
//! \b EPI_NBCONFIG_SIZE_16, or \b EPI_NBCONFIG_SIZE_32 for 8-bit, 16-bit,
//! or 32-bit sized data transfers.
//!
//! The parameter \e ulAddress is the starting address for the read, relative
//! to the external device.  The start of the device is address 0.
//!
//! Once configured, the non-blocking read is started by calling
//! EPINonBlockingReadStart().  If the addresses to be read from the device
//! are in a sequence, it is not necessary to call this function multiple
//! times.  Until it is changed, the EPI module stores the last address
//! that was used for a non-blocking read (per channel).
//!
//! \return None.
//
//*****************************************************************************
void
EPINonBlockingReadConfigure(unsigned long ulBase, unsigned long ulChannel,
                            unsigned long ulDataSize, unsigned long ulAddress)
{
    unsigned long ulOffset;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulChannel < 2);
    ASSERT(ulDataSize < 4);
    ASSERT(ulAddress < 0x20000000);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ulOffset = ulChannel * (EPI_O_RSIZE1 - EPI_O_RSIZE0);

    //
    // Write the data size register for the channel.
    //
    HWREG(ulBase + EPI_O_RSIZE0 + ulOffset) = ulDataSize;

    //
    // Write the starting address register for the channel.
    //
    HWREG(ulBase + EPI_O_RADDR0 + ulOffset) = ulAddress;
}

//*****************************************************************************
//
//! Starts a non-blocking read transaction.
//!
//! \param ulBase is the EPI module base address.
//! \param ulChannel is the read channel (0 or 1).
//! \param ulCount is the number of items to read (1-4095).
//!
//! This function starts a non-blocking read that was previously configured
//! with the function EPINonBlockingReadConfigure().  Once this function is
//! called, the EPI module begins reading data from the external device
//! into the read FIFO.  The EPI stops reading when the FIFO fills up
//! and resumes reading when the application drains the FIFO, until the
//! total specified count of data items has been read.
//!
//! Once a read transaction is completed and the FIFO drained, another
//! transaction can be started from the next address by calling this
//! function again.
//!
//! \return None.
//
//*****************************************************************************
void
EPINonBlockingReadStart(unsigned long ulBase, unsigned long ulChannel,
                        unsigned long ulCount)
{
    unsigned long ulOffset;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulChannel < 2);
    ASSERT(ulCount < 4096);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ulOffset = ulChannel * (EPI_O_RPSTD1 - EPI_O_RPSTD0);

    //
    // Write to the read count register.
    //
    HWREG(ulBase + EPI_O_RPSTD0 + ulOffset) = ulCount;
}

//*****************************************************************************
//
//! Stops a non-blocking read transaction.
//!
//! \param ulBase is the EPI module base address.
//! \param ulChannel is the read channel (0 or 1).
//!
//! This function cancels a non-blocking read transaction that is already
//! in progress.
//!
//! \return None.
//
//*****************************************************************************
void
EPINonBlockingReadStop(unsigned long ulBase, unsigned long ulChannel)
{
    unsigned long ulOffset;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulChannel < 2);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ulOffset = ulChannel * (EPI_O_RPSTD1 - EPI_O_RPSTD0);

    //
    // Write a 0 to the read count register, which cancels the transaction.
    //
    HWREG(ulBase + EPI_O_RPSTD0 + ulOffset) = 0;
}

//*****************************************************************************
//
//! Get the count remaining for a non-blocking transaction.
//!
//! \param ulBase is the EPI module base address.
//! \param ulChannel is the read channel (0 or 1).
//!
//! This function gets the remaining count of items for a non-blocking read
//! transaction.
//!
//! \return The number of items remaining in the non-blocking read transaction.
//
//*****************************************************************************
unsigned long
EPINonBlockingReadCount(unsigned long ulBase, unsigned long ulChannel)
{
    unsigned long ulOffset;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulChannel < 2);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ulOffset = ulChannel * (EPI_O_RPSTD1 - EPI_O_RPSTD0);

    //
    // Read the count remaining and return the value to the caller.
    //
    return(HWREG(ulBase + EPI_O_RPSTD0 + ulOffset));
}

//*****************************************************************************
//
//! Get the count of items available in the read FIFO.
//!
//! \param ulBase is the EPI module base address.
//!
//! This function gets the number of items that are available to read in
//! the read FIFO.  The read FIFO is filled by a non-blocking read transaction
//! which is configured by the functions EPINonBlockingReadConfigure() and
//! EPINonBlockingReadStart().
//!
//! \return The number of items available to read in the read FIFO.
//
//*****************************************************************************
unsigned long
EPINonBlockingReadAvail(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);

    //
    // Read the FIFO count and return it to the caller.
    //
    return(HWREG(ulBase + EPI_O_RFIFOCNT));
}

//*****************************************************************************
//
//! Read available data from the read FIFO, as 32-bit data items.
//!
//! \param ulBase is the EPI module base address.
//! \param ulCount is the maximum count of items to read.
//! \param pulBuf is the caller supplied buffer where the read data should
//! be stored.
//!
//! This function reads 32-bit data items from the read FIFO and stores
//! the values in a caller-supplied buffer.  The function reads and stores
//! data from the FIFO until there is no more data in the FIFO or the maximum
//! count is reached as specified in the parameter \e ulCount.  The actual
//! count of items is returned.
//!
//! \return The number of items read from the FIFO.
//
//*****************************************************************************
unsigned long
EPINonBlockingReadGet32(unsigned long ulBase, unsigned long ulCount,
                        unsigned long *pulBuf)
{
    unsigned long ulCountRead = 0;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulCount < 4096);
    ASSERT(pulBuf);

    //
    // Read from the FIFO while there are any items to read and
    // the caller's specified count is not exceeded.
    //
    while(HWREG(ulBase + EPI_O_RFIFOCNT) && ulCount--)
    {
        //
        // Read from the FIFO and store in the caller supplied buffer.
        //
        *pulBuf = HWREG(ulBase + EPI_O_READFIFO);

        //
        // Update the caller's buffer pointer and the count of items read.
        //
        pulBuf++;
        ulCountRead++;
    }

    //
    // Return the count of items read to the caller.
    //
    return(ulCountRead);
}

//*****************************************************************************
//
//! Read available data from the read FIFO, as 16-bit data items.
//!
//! \param ulBase is the EPI module base address.
//! \param ulCount is the maximum count of items to read.
//! \param pusBuf is the caller-supplied buffer where the read data should
//! be stored.
//!
//! This function reads 16-bit data items from the read FIFO and stores
//! the values in a caller-supplied buffer.  The function reads and stores
//! data from the FIFO until there is no more data in the FIFO or the maximum
//! count is reached as specified in the parameter \e ulCount.  The actual
//! count of items is returned.
//!
//! \return The number of items read from the FIFO.
//
//*****************************************************************************
unsigned long
EPINonBlockingReadGet16(unsigned long ulBase, unsigned long ulCount,
                        unsigned short *pusBuf)
{
    unsigned long ulCountRead = 0;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulCount < 4096);
    ASSERT(pusBuf);

    //
    // Read from the FIFO while there are any items to read, and
    // the caller's specified count is not exceeded.
    //
    while(HWREG(ulBase + EPI_O_RFIFOCNT) && ulCount--)
    {
        //
        // Read from the FIFO and store in the caller-supplied buffer.
        //
        *pusBuf = (unsigned short)HWREG(ulBase + EPI_O_READFIFO);

        //
        // Update the caller's buffer pointer and the count of items read.
        //
        pusBuf++;
        ulCountRead++;
    }

    //
    // Return the count of items read to the caller.
    //
    return(ulCountRead);
}

//*****************************************************************************
//
//! Read available data from the read FIFO, as 8-bit data items.
//!
//! \param ulBase is the EPI module base address.
//! \param ulCount is the maximum count of items to read.
//! \param pucBuf is the caller-supplied buffer where the read data should
//! be stored.
//!
//! This function reads 8-bit data items from the read FIFO and stores
//! the values in a caller-supplied buffer.  The function reads and stores
//! data from the FIFO until there is no more data in the FIFO or the maximum
//! count is reached as specified in the parameter \e ulCount.  The actual
//! count of items is returned.
//!
//! \return The number of items read from the FIFO.
//
//*****************************************************************************
unsigned long
EPINonBlockingReadGet8(unsigned long ulBase, unsigned long ulCount,
                       unsigned char *pucBuf)
{
    unsigned long ulCountRead = 0;

    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulCount < 4096);
    ASSERT(pucBuf);

    //
    // Read from the FIFO while there are any items to read, and
    // the caller's specified count is not exceeded.
    //
    while(HWREG(ulBase + EPI_O_RFIFOCNT) && ulCount--)
    {
        //
        // Read from the FIFO and store in the caller supplied buffer.
        //
        *pucBuf = (unsigned char)HWREG(ulBase + EPI_O_READFIFO);

        //
        // Update the caller's buffer pointer and the count of items read.
        //
        pucBuf++;
        ulCountRead++;
    }

    //
    // Return the count of items read to the caller.
    //
    return(ulCountRead);
}

//*****************************************************************************
//
//! Configures the read FIFO.
//!
//! \param ulBase is the EPI module base address.
//! \param ulConfig is the FIFO configuration.
//!
//! This function configures the FIFO trigger levels and error
//! generation.  The parameter \e ulConfig is the logical OR of the
//! following:
//!
//! - \b EPI_FIFO_CONFIG_WTFULLERR - enables an error interrupt when a write is
//! attempted and the write FIFO is full
//! - \b EPI_FIFO_CONFIG_RSTALLERR - enables an error interrupt when a read is
//! stalled due to an interleaved write or other reason
//! - \b EPI_FIFO_CONFIG_TX_EMPTY, \b EPI_FIFO_CONFIG_TX_1_4,
//! \b EPI_FIFO_CONFIG_TX_1_2, or \b EPI_FIFO_CONFIG_TX_3_4 to set the
//! TX FIFO trigger level to empty, 1/4, 1/2, or 3/4 level
//! - \b EPI_FIFO_CONFIG_RX_1_8, \b EPI_FIFO_CONFIG_RX_1_4,
//! \b EPI_FIFO_CONFIG_RX_1_2, \b EPI_FIFO_CONFIG_RX_3_4,
//! \b EPI_FIFO_CONFIG_RX_7_8, or \b EPI_FIFO_CONFIG_RX_FULL to set the
//! RX FIFO trigger level to 1/8, 1/4, 1/2, 3/4, 7/8 or full level
//!
//! \return None.
//
//*****************************************************************************
void
EPIFIFOConfig(unsigned long ulBase, unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulConfig == (ulConfig & 0x00030077));

    //
    // Load the configuration into the FIFO config reg.
    //
    HWREG(ulBase + EPI_O_FIFOLVL) = ulConfig;
}

//*****************************************************************************
//
//! Reads the number of empty slots in the write transaction FIFO.
//!
//! \param ulBase is the EPI module base address.
//!
//! This function returns the number of slots available in the transaction
//! FIFO.  It can be used in a polling method to avoid attempting a write
//! that would stall.
//!
//! \return The number of empty slots in the transaction FIFO.
//
//*****************************************************************************
unsigned long
EPIWriteFIFOCountGet(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);

    //
    // Read the FIFO count and return it to the caller.
    //
    return(HWREG(ulBase + EPI_O_WFIFOCNT));
}

//*****************************************************************************
//
//! Enables EPI interrupt sources.
//!
//! \param ulBase is the EPI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the specified EPI sources to generate interrupts.
//! The \e ulIntFlags parameter can be the logical OR of any of the following
//! values:
//!
//! - \b EPI_INT_TXREQ - transmit FIFO is below the trigger level
//! - \b EPI_INT_RXREQ - read FIFO is above the trigger level
//! - \b EPI_INT_ERR - an error condition occurred
//!
//! \return Returns None.
//
//*****************************************************************************
void
EPIIntEnable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulIntFlags < 16);

    //
    // Write the interrupt flags mask to the mask register.
    //
    HWREG(ulBase + EPI_O_IM) |= ulIntFlags;
}

//*****************************************************************************
//
//! Disables EPI interrupt sources.
//!
//! \param ulBase is the EPI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the specified EPI sources for interrupt
//! generation.  The \e ulIntFlags parameter can be the logical OR
//! of any of the following values: \b EPI_INT_RXREQ, \b EPI_INT_TXREQ, or
//! \b I2S_INT_ERR.
//!
//! \return Returns None.
//
//*****************************************************************************
void
EPIIntDisable(unsigned long ulBase, unsigned long ulIntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulIntFlags < 16);

    //
    // Write the interrupt flags mask to the mask register.
    //
    HWREG(ulBase + EPI_O_IM) &= ~ulIntFlags;
}

//*****************************************************************************
//
//! Gets the EPI interrupt status.
//!
//! \param ulBase is the EPI module base address.
//! \param bMasked is set \b true to get the masked interrupt status, or
//! \b false to get the raw interrupt status.
//!
//! This function returns the EPI interrupt status.  It can return either
//! the raw or masked interrupt status.
//!
//! \return Returns the masked or raw EPI interrupt status, as a bit field
//! of any of the following values: \b EPI_INT_TXREQ, \b EPI_INT_RXREQ,
//! or \b EPI_INT_ERR
//
//*****************************************************************************
unsigned long
EPIIntStatus(unsigned long ulBase, tBoolean bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ulBase + EPI_O_MIS));
    }
    else
    {
        return(HWREG(ulBase + EPI_O_RIS));
    }
}

//*****************************************************************************
//
//! Gets the EPI error interrupt status.
//!
//! \param ulBase is the EPI module base address.
//!
//! This function returns the error status of the EPI.  If the return value of
//! the function EPIIntStatus() has the flag \b EPI_INT_ERR set, then this
//! function can be used to determine the cause of the error.
//!
//! This function returns a bit mask of error flags, which can be the logical
//! OR of any of the following:
//!
//! - \b EPI_INT_ERR_WTFULL - occurs when a write stalled when the transaction
//! FIFO was full
//! - \b EPI_INT_ERR_RSTALL - occurs when a read stalled
//! - \b EPI_INT_ERR_TIMEOUT - occurs when the external clock enable held
//! off a transaction longer than the configured maximum wait time
//!
//! \return Returns the interrupt error flags as the logical OR of any of
//! the following: \b EPI_INT_ERR_WTFULL, \b EPI_INT_ERR_RSTALL, or
//! \b EPI_INT_ERR_TIMEOUT.
//
//*****************************************************************************
unsigned long
EPIIntErrorStatus(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);

    //
    // Read the error status and return to caller.
    //
    return(HWREG(ulBase + EPI_O_EISC));
}

//*****************************************************************************
//
//! Clears pending EPI error sources.
//!
//! \param ulBase is the EPI module base address.
//! \param ulErrFlags is a bit mask of the error sources to be cleared.
//!
//! This function clears the specified pending EPI errors.  The \e ulErrFlags
//! parameter can be the logical OR of any of the following values:
//! \b EPI_INT_ERR_WTFULL, \b EPI_INT_ERR_RSTALL, or \b EPI_INT_ERR_TIMEOUT.
//!
//! \return Returns None.
//
//*****************************************************************************
void
EPIIntErrorClear(unsigned long ulBase, unsigned long ulErrFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(ulErrFlags < 16);

    //
    // Write the error flags to the register to clear the pending errors.
    //
    HWREG(ulBase + EPI_O_EISC) = ulErrFlags;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the EPI module.
//!
//! \param ulBase is the EPI module base address.
//! \param pfnHandler is a pointer to the function to be called when the
//! interrupt is activated.
//!
//! This sets and enables the handler to be called when the EPI module
//! generates an interrupt.  Specific EPI interrupts must still be enabled
//! with the EPIIntEnable() function.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
EPIIntRegister(unsigned long ulBase, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);
    ASSERT(pfnHandler);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_EPI0, pfnHandler);

    //
    // Enable the EPI interface interrupt.
    //
    IntEnable(INT_EPI0);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the EPI module.
//!
//! \param ulBase is the EPI module base address.
//!
//! This function disables and clears the handler to be called when the
//! EPI interrupt occurs.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
EPIIntUnregister(unsigned long ulBase)
{
    //
    // Check the arguments.
    //
    ASSERT(ulBase == EPI0_BASE);

    //
    // Disable the EPI interface interrupt.
    //
    IntDisable(INT_EPI0);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_EPI0);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
