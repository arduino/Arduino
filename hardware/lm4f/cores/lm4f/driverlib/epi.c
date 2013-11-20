//*****************************************************************************
//
// epi.c - Driver for the EPI module.
//
// Copyright (c) 2008-2013 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_epi.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
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
// Helper masks for chip select configuration options.
//
//*****************************************************************************
#define EPI_HB8_CS_MASK         (EPI_HB8_MODE_FIFO | EPI_HB8_RDWAIT_3 |       \
                                 EPI_HB8_WRWAIT_3 | EPI_HB8_RDHIGH |          \
                                 EPI_HB8_WRHIGH | EPI_HB8_ALE_HIGH)

#define EPI_HB16_CS_MASK        (EPI_HB8_CS_MASK | EPI_HB16_BURST_TRAFFIC)

//*****************************************************************************
//
// Ensure that erratum workaround inline functions have a public version
// available in exactly one object module (this one).
//
//*****************************************************************************

//*****************************************************************************
//
//! Safely writes a word to the EPI 0x10000000 address space.
//!
//! \param pui32Addr is the address which is to be written.
//! \param ui32Value is the 32-bit word to write.
//!
//! This function must be used when writing words to EPI-attached memory
//! configured to use the address space at 0x10000000 on devices affected by
//! the EPI#01 erratum.  Direct access to memory in these cases can cause data
//! corruption depending upon memory accesses immediately before or after the
//! EPI access but using this function will allow EPI accesses to complete
//! correctly. The function is defined as ``inline'' in epi.h.
//!
//! Use of this function on a device not affected by the erratum is safe but
//! will impact performance due to an additional overhead of at least 2 cycles
//! per access.  This erratum affects only the 0x10000000 address space
//! typically used to store the LCD controller frame buffer.  The 0x60000000
//! address space is not affected and applications using this address mapping
//! need not use this function.
//!
//! \return None.
//
//*****************************************************************************
extern void EPIWorkaroundWordWrite(uint32_t *pui32Addr, uint32_t ui32Value);

//*****************************************************************************
//
//! Safely reads a word from the EPI 0x10000000 address space.
//!
//! \param pui32Addr is the address which is to be read.
//!
//! This function must be used when reading words from EPI-attached memory
//! configured to use the address space at 0x10000000 on devices affected by
//! the EPI#01 erratum.  Direct access to memory in these cases can cause data
//! corruption depending upon memory accesses immediately before or after the
//! EPI access but using this function will allow EPI accesses to complete
//! correctly. The function is defined as ``inline'' in epi.h.
//!
//! Use of this function on a device not affected by the erratum is safe but
//! will impact performance due to an additional overhead of at least 2 cycles
//! per access.  This erratum affects only the 0x10000000 address space
//! typically used to store the LCD controller frame buffer.  The 0x60000000
//! address space is not affected and applications using this address mapping
//! need not use this function.
//!
//! \return The 32-bit word stored at address \e pui32Addr.
//
//*****************************************************************************
extern uint32_t EPIWorkaroundWordRead(uint32_t *pui32Addr);

//*****************************************************************************
//
//! Safely writes a half-word to the EPI 0x10000000 address space.
//!
//! \param pui16Addr is the address which is to be written.
//! \param ui16Value is the 16-bit half-word to write.
//!
//! This function must be used when writing half-words to EPI-attached memory
//! configured to use the address space at 0x10000000 on devices affected by
//! the EPI#01 erratum.  Direct access to memory in these cases can cause data
//! corruption depending upon memory accesses immediately before or after the
//! EPI access but using this function will allow EPI accesses to complete
//! correctly. The function is defined as ``inline'' in epi.h.
//!
//! Use of this function on a device not affected by the erratum is safe but
//! will impact performance due to an additional overhead of at least 2 cycles
//! per access.  This erratum affects only the 0x10000000 address space
//! typically used to store the LCD controller frame buffer.  The 0x60000000
//! address space is not affected and applications using this address mapping
//! need not use this function.
//!
//! \return None.
//
//*****************************************************************************
extern void EPIWorkaroundHWordWrite(uint16_t *pui16Addr, uint16_t ui16Value);

//*****************************************************************************
//
//! Safely reads a half-word from the EPI 0x10000000 address space.
//!
//! \param pui16Addr is the address which is to be read.
//!
//! This function must be used when reading half-words from EPI-attached memory
//! configured to use the address space at 0x10000000 on devices affected by
//! the EPI#01 erratum.  Direct access to memory in these cases can cause data
//! corruption depending upon memory accesses immediately before or after the
//! EPI access but using this function will allow EPI accesses to complete
//! correctly. The function is defined as ``inline'' in epi.h.
//!
//! Use of this function on a device not affected by the erratum is safe but
//! will impact performance due to an additional overhead of at least 2 cycles
//! per access.  This erratum affects only the 0x10000000 address space
//! typically used to store the LCD controller frame buffer.  The 0x60000000
//! address space is not affected and applications using this address mapping
//! need not use this function.
//!
//! \return The 16-bit word stored at address \e pui16Addr.
//
//*****************************************************************************
extern uint16_t EPIWorkaroundHwordRead(uint16_t *pui16Addr);

//*****************************************************************************
//
//! Safely writes a byte to the EPI 0x10000000 address space.
//!
//! \param pui8Addr is the address which is to be written.
//! \param ui8Value is the 8-bit byte to write.
//!
//! This function must be used when writing bytes to EPI-attached memory
//! configured to use the address space at 0x10000000 on devices affected by
//! the EPI#01 erratum.  Direct access to memory in these cases can cause data
//! corruption depending upon memory accesses immediately before or after the
//! EPI access but using this function will allow EPI accesses to complete
//! correctly. The function is defined as ``inline'' in epi.h.
//!
//! Use of this function on a device not affected by the erratum is safe but
//! will impact performance due to an additional overhead of at least 2 cycles
//! per access.  This erratum affects only the 0x10000000 address space
//! typically used to store the LCD controller frame buffer.  The 0x60000000
//! address space is not affected and applications using this address mapping
//! need not use this function.
//!
//! \return None.
//
//*****************************************************************************
extern void EPIWorkaroundByteWrite(uint8_t *pui8Addr, uint8_t ui8Value);

//*****************************************************************************
//
//! Safely reads a byte from the EPI 0x10000000 address space.
//!
//! \param pui8Addr is the address which is to be read.
//!
//! This function must be used when reading bytes from EPI-attached memory
//! configured to use the address space at 0x10000000 on devices affected by
//! the EPI#01 erratum.  Direct access to memory in these cases can cause data
//! corruption depending upon memory accesses immediately before or after the
//! EPI access but using this function will allow EPI accesses to complete
//! correctly. The function is defined as ``inline'' in epi.h.
//!
//! Use of this function on a device not affected by the erratum is safe but
//! will impact performance due to an additional overhead of at least 2 cycles
//! per access.  This erratum affects only the 0x10000000 address space
//! typically used to store the LCD controller frame buffer.  The 0x60000000
//! address space is not affected and applications using this address mapping
//! need not use this function.
//!
//! \return The 8-bit byte stored at address \e pui8Addr.
//
//*****************************************************************************
extern uint8_t EPIWorkaroundByteRead(uint8_t *pui8Addr);

//*****************************************************************************
//
//! Sets the usage mode of the EPI module.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Mode is the usage mode of the EPI module.
//!
//! This functions sets the operating mode of the EPI module.  The parameter
//! \e ui32Mode must be one of the following:
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
EPIModeSet(uint32_t ui32Base, uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT((ui32Mode == EPI_MODE_GENERAL) ||
           (ui32Mode == EPI_MODE_SDRAM) ||
           (ui32Mode == EPI_MODE_HB8) ||
           (ui32Mode == EPI_MODE_HB16) ||
           (ui32Mode == EPI_MODE_DISABLE));

    //
    // Write the mode word to the register.
    //
    HWREG(ui32Base + EPI_O_CFG) = ui32Mode;
}

//*****************************************************************************
//
//! Sets the clock divider for the EPI module's CS0n/CS1n.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Divider is the value of the clock divider to be applied to
//! the external interface (0-65535).
//!
//! This function sets the clock divider(s) that is used to determine the
//! clock rate of the external interface.  The \e ui32Divider value is used to
//! derive the EPI clock rate from the system clock based on the following
//! formula.
//!
//! EPIClk = (Divider == 0) ? SysClk : (SysClk / (((Divider / 2) + 1) * 2))
//!
//! For example, a divider value of 1 results in an EPI clock rate of half
//! the system clock, value of 2 or 3 yields one quarter of the system clock
//! and a value of 4 results in one sixth of the system clock rate.
//!
//! In cases where a dual chip select mode is in use and different clock rates
//! are required for each chip select, the \e ui32Divider parameter must
//! contain two dividers.  The lower 16 bits define the divider to be used with
//! CS0n and the upper 16 bits define the divider for CS1n.
//!
//! \return None.
//
//*****************************************************************************
void
EPIDividerSet(uint32_t ui32Base, uint32_t ui32Divider)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // Write the divider value to the register.
    //
    HWREG(ui32Base + EPI_O_BAUD) = ui32Divider;
}

//*****************************************************************************
//
//! Sets the clock divider for the specified CS in the EPI module.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select to modify and has a valid range of 0-3.
//! \param ui32Divider is the value of the clock divider to be applied to
//! the external interface (0-65535).
//!
//! This function sets the clock divider(s) for the specified CS that is used
//! to determine the clock rate of the external interface.  The \e ui32Divider
//! value is used to derive the EPI clock rate from the system clock based on
//! the following formula.
//!
//! EPIClk = (Divider == 0) ? SysClk : (SysClk / (((Divider / 2) + 1) * 2))
//!
//! For example, a divider value of 1 results in an EPI clock rate of half
//! the system clock, value of 2 or 3 yields one quarter of the system clock
//! and a value of 4 results in one sixth of the system clock rate.
//!
//! \note The availability of CS2n and CS3n varies based on the Tiva part
//! in use.  Please consult the data sheet to determine if this feature is
//! available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIDividerCSSet(uint32_t ui32Base, uint32_t ui32CS,
                uint32_t ui32Divider)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Write the divider value to the register bitfield.
    //
    if(ui32CS < 2)
    {
        ui32Reg = HWREG(ui32Base + EPI_O_BAUD) & ~(0xffff << (16 * ui32CS));
        ui32Reg |= ((ui32Divider & 0xffff) << (16 * ui32CS));
        HWREG(ui32Base + EPI_O_BAUD) = ui32Reg;
    }
    else
    {
        ui32Reg = (HWREG(ui32Base + EPI_O_BAUD2) &
                   ~(0xffff << (16 * (ui32CS - 2))));
        ui32Reg |= ((ui32Divider & 0xffff) << (16 * (ui32CS - 2)));
        HWREG(ui32Base + EPI_O_BAUD2) = ui32Reg;
    }
}

//*****************************************************************************
//
//! Sets the transfer count for uDMA transmit operations on EPI.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Count is the number of units to transmit by uDMA to WRFIFO.
//!
//! This function is used to help configure the EPI uDMA transmit operations.
//! A non-zero transmit count in combination with a FIFO threshold trigger
//! asserts an EPI uDMA transmit.
//!
//! \note The availability of the EPI DMA TX count varies based on the
//! Tiva part in use.  Please consult the data sheet to determine if this
//! feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIDMATxCount(uint32_t ui32Base, uint32_t ui32Count)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Count < 0x00ff);

    //
    // Assign the DMA TX count value provided.
    //
    HWREG(ui32Base + EPI_O_DMATXCNT) = ui32Count & 0x00ff;
}

//*****************************************************************************
//
//! Configures the SDRAM mode of operation.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Config is the SDRAM interface configuration.
//! \param ui32Refresh is the refresh count in core clocks (0-2047).
//!
//! This function is used to configure the SDRAM interface, when the SDRAM
//! mode is chosen with the function EPIModeSet().  The parameter
//! \e ui32Config is the logical OR of several sets of choices:
//!
//! The processor core frequency must be specified with one of the following:
//!
//! - \b EPI_SDRAM_CORE_FREQ_0_15 defines core clock as 0 MHz < clk <= 15 MHz
//! - \b EPI_SDRAM_CORE_FREQ_15_30 defines core clock as 15 MHz < clk <= 30 MHz
//! - \b EPI_SDRAM_CORE_FREQ_30_50 defines core clock as 30 MHz < clk <= 50 MHz
//! - \b EPI_SDRAM_CORE_FREQ_50_100 defines core clock as 50 MHz < clk <=
//!   100 MHz
//!
//! The low power mode is specified with one of the following:
//!
//! - \b EPI_SDRAM_LOW_POWER enter low power, self-refresh state.
//! - \b EPI_SDRAM_FULL_POWER normal operating state.
//!
//! The SDRAM device size is specified with one of the following:
//!
//! - \b EPI_SDRAM_SIZE_64MBIT size is a 64 Mbit device (8 MB).
//! - \b EPI_SDRAM_SIZE_128MBIT size is a 128 Mbit device (16 MB).
//! - \b EPI_SDRAM_SIZE_256MBIT size is a 256 Mbit device (32 MB).
//! - \b EPI_SDRAM_SIZE_512MBIT size is a 512 Mbit device (64 MB).
//!
//! The parameter \e ui16Refresh sets the refresh counter in units of core
//! clock ticks.  It is an 11-bit value with a range of 0 - 2047 counts.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigSDRAMSet(uint32_t ui32Base, uint32_t ui32Config,
                  uint32_t ui32Refresh)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Refresh < 2048);

    //
    // Fill in the refresh count field of the configuration word.
    //
    ui32Config &= ~EPI_SDRAMCFG_RFSH_M;
    ui32Config |= ui32Refresh << EPI_SDRAMCFG_RFSH_S;

    //
    // Write the SDRAM configuration register.
    //
    HWREG(ui32Base + EPI_O_SDRAMCFG) = ui32Config;
}

//*****************************************************************************
//
//! Configures the interface for Host-bus 8 operation.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Config is the interface configuration.
//! \param ui32MaxWait is the maximum number of external clocks to wait
//! if a FIFO ready signal is holding off the transaction, 0-255.
//!
//! This function is used to configure the interface when used in host-bus 8
//! operation as chosen with the function EPIModeSet().  The parameter
//! \e ui32Config is the logical OR of the following:
//!
//! - Host-bus 8 submode, select one of:
//!   - \b EPI_HB8_MODE_ADMUX sets data and address muxed, AD[7:0]
//!   - \b EPI_HB8_MODE_ADDEMUX sets up data and address separate, D[7:0]
//!   - \b EPI_HB8_MODE_SRAM as \b EPI_HB8_MODE_ADDEMUX, but uses address
//!     switch for multiple reads instead of OEn strobing, D[7:0]
//!   - \b EPI_HB8_MODE_FIFO adds XFIFO with sense of XFIFO full and XFIFO
//!     empty, D[7:0]
//!
//! - \b EPI_HB8_USE_TXEMPTY enables TXEMPTY signal with FIFO
//! - \b EPI_HB8_USE_RXFULL enables RXFULL signal with FIFO
//! - \b EPI_HB8_WRHIGH sets active high write strobe, otherwise it is
//!   active low
//! - \b EPI_HB8_RDHIGH sets active high read strobe, otherwise it is
//!   active low
//!
//! - Write wait state when \b EPI_HB8_BAUD is used, select one of:
//!   - \b EPI_HB8_WRWAIT_0 sets write wait state to 2 EPI clocks (default)
//!   - \b EPI_HB8_WRWAIT_1 sets write wait state to 4 EPI clocks
//!   - \b EPI_HB8_WRWAIT_2 sets write wait state to 6 EPI clocks
//!   - \b EPI_HB8_WRWAIT_3  sets write wait state to 8 EPI clocks
//!
//! - Read wait state when \b EPI_HB8_BAUD is used, select one of:
//!   - \b EPI_HB8_RDWAIT_0 sets read wait state to 2 EPI clocks (default)
//!   - \b EPI_HB8_RDWAIT_1 sets read wait state to 4 EPI clocks
//!   - \b EPI_HB8_RDWAIT_2 sets read wait state to 6 EPI clocks
//!   - \b EPI_HB8_RDWAIT_3 sets read wait state to 8 EPI clocks
//!
//! - \b EPI_HB8_WORD_ACCESS - use Word Access mode to route bytes to the
//!   correct byte lanes allowing data to be stored in bits [31:8].  If absent,
//!   all data transfers use bits [7:0].
//!   \note \b EPI_HB8_WORD_ACCESS is not available on all parts.  Please
//!   consult the data sheet to determine if this feature is available.
//!
//! - \b EPI_HB8_CLOCK_GATE_IDLE sets the EPI clock to be held low when no data
//!   is available to read or write
//! - \b EPI_HB8_CLOCK_INVERT inverts the EPI clock
//! - \b EPI_HB8_IN_READY_EN sets EPIS032 as a ready/stall signal, active high
//! - \b EPI_HB8_IN_READY_EN_INVERTEsets EPIS032 as ready/stall signal, active
//!   low
//! - \b EPI_HB8_ALE_HIGH sets the address latch active high (default)
//! - \b EPI_HB8_ALE_LOW sets address latch active low
//! - \b EPI_HB8_CSBAUD use different baud rates when accessing devices on each
//!   chip select.  CS0n uses the baud rate specified by the lower 16 bits
//!   of the divider passed to EPIDividerSet() and CS1n uses the divider passed
//!   in the upper 16 bits.  If this option is absent, both chip selects use
//!   the baud rate resulting from the divider in the lower 16 bits of the
//!   parameter passed to EPIDividerSet().
//!
//! In addition, some parts support a CS2n and CS3n for a total of 4 chip
//! selects.  If \b EPI_HB8_CSBAUD is configured, EPIDividerCSSet() should be
//! used to to configure the divider for CS2n and CS3n.  They both also use the
//! lower 16 bits passed to EPIDividerSet() if this option is absent.
//!
//! The use of \b EPI_HB8_CSBAUD also allows for unique chip select
//! configurations.  The CS0n, CS1n, CS2n, and CS3n can each be configured by
//! calling EPIConfigHB8CSSet() if \b EPI_HB8_CSBAUD is used.  Otherwise, the
//! configuration provided in \e ui32Config is used for all chip selects
//! enabled.
//!
//! - Chip select configuration, select one of:
//!   - \b EPI_HB8_CSCFG_CS sets EPIS030 to operate as a chip select signal
//!   - \b EPI_HB8_CSCFG_ALE sets EPIS030 to operate as an address latch
//!     (ALE)
//!   - \b EPI_HB8_CSCFG_DUAL_CS sets EPIS030 to operate as CS0n and EPIS027
//!     as CS1n with the asserted chip select determined from the most
//!     significant address bit for the respective external address map
//!   - \b EPI_HB8_CSCFG_ALE_DUAL_CS sets EPIS030 as an address latch (ALE),
//!     EPIS027 as CS0n and EPIS026 as CS1n with the asserted chip select
//!     determined from the most significant address bit for the respective
//!     external address map
//!   - \b EPI_HB8_CSCFG_ALE_SINGLE_CS sets EPIS030 to operate as an address
//!     latch (ALE) and EPIS027 is used as a chip select
//!   - \b EPI_HB8_CSCFG_QUAD_CS sets EPIS030 as CS0n, EPIS027 as CS1n,
//!     EPIS034 as CS2n and EPIS033 as CS3n
//!   - \b EPI_HB8_CSCFG_ALE_QUAD_CS sets EPIS030 as an address latch (ALE),
//!     EPIS026 as CS0n, EPIS027 as CS1n, EPIS034 as CS2n and EPIS033 as CS3n
//!
//! The parameter \e ui32MaxWait is used if the FIFO mode is chosen.  If a
//! FIFO is used aint32_t with RXFULL or TXEMPTY ready signals, then this
//! parameter determines the maximum number of clocks to wait when the
//! transaction is being held off by by the FIFO using one of these ready
//! signals.  A value of 0 means to wait forever.
//!
//! \note  Availability of configuration options varies based on the Tiva
//! part in use.  Please consult the data sheet to determine if the features
//! desired are available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB8Set(uint32_t ui32Base, uint32_t ui32Config,
                uint32_t ui32MaxWait)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32MaxWait < 256);

    //
    // Determine the CS and word access modes.
    //
    HWREG(ui32Base + EPI_O_HB8CFG2) =
        ((ui32Config & EPI_HB8_CSBAUD) ? EPI_HB8CFG2_CSBAUD : 0) |
        ((ui32Config & EPI_HB8_CSCFG_MASK) << 15);

    //
    // Fill in the max wait field of the configuration word.
    //
    ui32Config &= ~EPI_HB8CFG_MAXWAIT_M;
    ui32Config |= ui32MaxWait << EPI_HB8CFG_MAXWAIT_S;

    //
    // Write the main HostBus8 configuration register.
    //
    HWREG(ui32Base + EPI_O_HB8CFG) = ui32Config;
}

//*****************************************************************************
//
//! Configures the interface for Host-bus 16 operation.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Config is the interface configuration.
//! \param ui32MaxWait is the maximum number of external clocks to wait
//! if a FIFO ready signal is holding off the transaction.
//!
//! This function is used to configure the interface when used in Host-bus 16
//! operation as chosen with the function EPIModeSet().  The parameter
//! \e ui32Config is the logical OR of the following:
//! - Host-bus 16 submode, select one of:
//!     - \b EPI_HB16_MODE_ADMUX sets data and address muxed, AD[15:0].
//!     - \b EPI_HB16_MODE_ADDEMUX sets up data and address as separate,
//!       D[15:0].
//!     - \b EPI_HB16_MODE_SRAM sets as \b EPI_HB16_MODE_ADDEMUX but uses
//!       address switch for multiple reads instead of OEn strobing, D[15:0].
//!     - \b EPI_HB16_MODE_FIFO addes XFIFO controls with sense of XFIFO full
//!       and XFIFO empty, D[15:0].  This submode uses no address or ALE.
//!
//! - \b EPI_HB16_USE_TXEMPTY enables TXEMPTY signal with FIFO.
//! - \b EPI_HB16_USE_RXFULL enables RXFULL signal with FIFO.
//! - \b EPI_HB16_WRHIGH use active high write strobe, otherwise it is
//!   active low.
//! - \b EPI_HB16_RDHIGH use active high read strobe, otherwise it is
//!   active low.
//! - Write wait state, select one of:
//!     - \b EPI_HB16_WRWAIT_0 sets write wait state to 2 EPI clocks.
//!     - \b EPI_HB16_WRWAIT_1 sets write wait state to 4 EPI clocks.
//!     - \b EPI_HB16_WRWAIT_2 sets write wait state to 6 EPI clocks.
//!     - \b EPI_HB16_WRWAIT_3 sets write wait state to 8 EPI clocks.
//!
//! - Read wait state, select one of:
//!     - \b EPI_HB16_RDWAIT_0 sets read wait state to 2 EPI clocks.
//!     - \b EPI_HB16_RDWAIT_1 sets read wait state to 4 EPI clocks.
//!     - \b EPI_HB16_RDWAIT_2 sets read wait state to 6 EPI clocks.
//!     - \b EPI_HB16_RDWAIT_3 sets read wait state to 8 EPI clocks.
//!
//! - \b EPI_HB16_WORD_ACCESS use Word Access mode to route bytes to the
//!   correct byte lanes allowing data to be stored in bits [31:16].  If
//!   absent, all data transfers use bits [15:0].
//!
//! \note \b EPI_HB16_WORD_ACCESS is not available on all parts.  Please
//! consult the data sheet to determine if this feature is available.
//!
//! - \b EPI_HB16_CLOCK_GATE_IDLE holds the EPI clock low when no data is
//!   available to read or write.
//! - \b EPI_HB16_CLOCK_INVERT inverts the EPI clock.
//! - \b EPI_HB16_IN_READY_EN sets EPIS032 as a ready/stall signal, active
//!   high.
//! - \b EPI_HB16_IN_READY_EN_INVERTED sets EPIS032 as ready/stall signal,
//!   active low.
//! - Address latch logic, select one of:
//!     - \b EPI_HB16_ALE_HIGH sets the address latch active high (default).
//!     - \b EPI_HB16_ALE_LOW sets address latch active low.
//!
//! - \b EPI_HB16_BURST_TRAFFIC enables burst traffic.  Only valid with
//!   \b EPI_HB16_MODE_ADMUX and a chip select configuration that utilizes an
//!   ALE.
//! - \b EPI_HB16_BSEL enables byte selects.  In this mode, two EPI signals
//!   operate as byte selects allowing 8-bit transfers.  If this flag is not
//!   specified, data must be read and written using only 16-bit transfers.
//! - \b EPI_HB16_CSBAUD use different baud rates when accessing devices
//!   on each chip select.  CS0n uses the baud rate specified by the lower 16
//!   bits of the divider passed to EPIDividerSet() and CS1n uses the divider
//!   passed in the upper 16 bits.  If this option is absent, both chip selects
//!   use the baud rate resulting from the divider in the lower 16 bits of the
//!   parameter passed to EPIDividerSet().
//!
//! In addition, some parts support a CS2n and CS3n for a total of 4 chip
//! selects.  If \b EPI_HB16_CSBAUD is configured, EPIDividerCSSet() should be
//! used to to configure the divider for CS2n and CS3n.  They both also use the
//! lower 16 bits passed to EPIDividerSet() if this option is absent.
//!
//! The use of \b EPI_HB16_CSBAUD also allows for unqiue chip select
//! configurations.  The CS0n, CS1n, CS2n, and CS3n can each be configured by
//! calling EPIConfigHB16CSSet() if \b EPI_HB16_CSBAUD is used.  Otherwise, the
//! configuration provided in \e ui32Config is used for all chip selects.
//!
//! - Chip select configuration, select one of:
//!     - \b EPI_HB16_CSCFG_CS sets EPIS030 to operate as a chip select signal.
//!     - \b EPI_HB16_CSCFG_ALE sets EPIS030 to operate as an address latch
//!       (ALE).
//!     - \b EPI_HB16_CSCFG_DUAL_CS sets EPIS030 to operate as CS0n and EPIS027
//!       as CS1n with the asserted chip select determined from the most
//!       significant address bit for the respective external address map.
//!     - \b EPI_HB16_CSCFG_ALE_DUAL_CS sets EPIS030 as an address latch (ALE),
//!       EPIS027 as CS0n and EPIS026 as CS1n with the asserted chip select
//!       determined from the most significant address bit for the respective
//!       external address map.
//!     - \b EPI_HB16_CSCFG_ALE_SINGLE_CS sets EPIS030 to operate as an address
//!       latch (ALE) and EPIS027 is used as a chip select.
//!     - \b EPI_HB16_CSCFG_QUAD_CS sets EPIS030 as CS0n, EPIS027 as CS1n,
//!       EPIS034 as CS2n and EPIS033 as CS3n.
//!     - \b EPI_HB16_CSCFG_ALE_QUAD_CS sets EPIS030 as an  address latch
//!       (ALE), EPIS026 as CS0n, EPIS027 as CS1n, EPIS034 as CS2n and EPIS033
//!       as CS3n.
//!
//! \note The availability of \b EPI_HB16_CSCFG_ALE_SINGLE_CS,
//! \b EPI_HB16_CSCFG_QUAD_CS, and \b EPI_HB16_CSFCG_ALE_QUAD_CS functionality
//! varies based on the Tiva part in use.  Please consult the data sheet
//! to determine if these! features are available.
//!
//! The parameter \e ui32MaxWait is used if the FIFO mode is chosen.  If a
//! FIFO is used along with RXFULL or TXEMPTY ready signals, then this
//! parameter determines the maximum number of clocks to wait when the
//! transaction is being held off by by the FIFO using one of these ready
//! signals.  A value of 0 means to wait forever.
//!
//! \note  Availability of configuration options varies based on the Tiva
//! part in use.  Please consult the data sheet to determine if the features
//! desired are available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB16Set(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32MaxWait)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32MaxWait < 256);

    //
    // Determine the CS and word access modes.
    //
    HWREG(ui32Base + EPI_O_HB16CFG2) =
        ((ui32Config & EPI_HB16_CSBAUD) ? EPI_HB16CFG2_CSBAUD : 0) |
        ((ui32Config & EPI_HB16_CSCFG_MASK) << 15);

    //
    // Fill in the max wait field of the configuration word.
    //
    ui32Config &= ~EPI_HB16CFG_MAXWAIT_M;
    ui32Config |= ui32MaxWait << EPI_HB16CFG_MAXWAIT_S;

    //
    // Write the main HostBus16 configuration register.
    //
    HWREG(ui32Base + EPI_O_HB16CFG) = ui32Config;
}

//*****************************************************************************
//
//! Sets the individual chip select configuration for the Host-bus 8 interface.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select value to configure.
//! \param ui32Config is the configuration settings.
//!
//! This function is used to configure individual chip select settings for the
//! Host-bus 8 interface mode.  EPIConfigHB8Set() must have been setup with
//! the \b EPI_HB8_CSBAUD flag for the individual chip select configuration
//! option to be available.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.  The parameter \e ui32Config is the logical OR of the
//! following:
//!
//! - Host-bus 8 submode, select one of:
//!     - \b EPI_HB8_MODE_ADMUX sets data and address muxed, AD[7:0].
//!     - \b EPI_HB8_MODE_ADDEMUX sets up data and address separate, D[7:0].
//!     - \b EPI_HB8_MODE_SRAM as \b EPI_HB8_MODE_ADDEMUX, but uses address
//!       switch for multiple reads instead of OEn strobing, D[7:0].
//!     - \b EPI_HB8_MODE_FIFO adds XFIFO with sense of XFIFO full and XFIFO
//!       empty, D[7:0].  This is only available for CS0n and CS1n.
//!
//! - \b EPI_HB8_WRHIGH sets active high write strobe, otherwise it is
//!   active low.
//! - \b EPI_HB8_RDHIGH sets active high read strobe, otherwise it is
//!   active low.
//! - Write wait state when \b EPI_HB8_BAUD is used, select one of:
//!     - \b EPI_HB8_WRWAIT_0 sets write wait state to 2 EPI clocks (default).
//!     - \b EPI_HB8_WRWAIT_1 sets write wait state to 4 EPI clocks.
//!     - \b EPI_HB8_WRWAIT_2 sets write wait state to 6 EPI clocks.
//!     - \b EPI_HB8_WRWAIT_3 sets write wait state to 8 EPI clocks.
//! - Read wait state when \b EPI_HB8_BAUD is used, select one of:
//!     - \b EPI_HB8_RDWAIT_0 sets read wait state to 2 EPI clocks (default).
//!     - \b EPI_HB8_RDWAIT_1 sets read wait state to 4 EPI clocks.
//!     - \b EPI_HB8_RDWAIT_2 sets read wait state to 6 EPI clocks.
//!     - \b EPI_HB8_RDWAIT_3 sets read wait state to 8 EPI clocks.
//! - \b EPI_HB8_ALE_HIGH sets the address latch active high (default).
//! - \b EPI_HB8_ALE_LOW sets address latch active low.
//!
//! \note The availability of a unique chip select configuration within
//! Host-bus 8 interface mode varies based on the Tiva part in use.
//! Please consult the data sheet to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB8CSSet(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config)
{
    uint32_t ui32Offset, ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Determine the register offset based on the ui32CS provided.
    //
    if(ui32CS < 2)
    {
        ui32Offset = EPI_O_HB8CFG + (ui32CS << 2);
    }
    else
    {
        ui32Offset = EPI_O_HB8CFG3 + ((ui32CS - 2) << 2);
    }

    //
    // Preserve the bits that will not be modified.
    //
    ui32Reg = HWREG(ui32Base + ui32Offset) & ~EPI_HB8_CS_MASK;

    //
    // Write the target chip select HostBus8 configuration fields.
    //
    HWREG(ui32Base + ui32Offset) = (ui32Reg | ui32Config);
}

//*****************************************************************************
//
//! Sets the individual chip select configuration for the Host-bus 16
//! interface.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select value to configure.
//! \param ui32Config is the configuration settings.
//!
//! This function is used to configure individual chip select settings for the
//! Host-bus 16 interface mode.  EPIConfigHB16Set() must have been set up with
//! the \b EPI_HB16_CSBAUD flag for the individual chip select configuration
//! option to be available.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The  \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of  0-3.  The parameter \e ui32Config is the logical OR the
//! following:
//!
//! - Host-bus 16 submode, select one of:
//!     - \b EPI_HB16_MODE_ADMUX sets data and address muxed, AD[15:0].
//!     - \b EPI_HB16_MODE_ADDEMUX sets up data and address separate, D[15:0].
//!     - \b EPI_HB16_MODE_SRAM same as \b EPI_HB8_MODE_ADDEMUX, but uses
//!       address switch for multiple reads instead of OEn strobing, D[15:0].
//!     - \b EPI_HB16_MODE_FIFO adds XFIFO with sense of XFIFO full and XFIFO
//!       empty, D[15:0].  This is only available on CS0n and CS1n.
//! - \b EPI_HB16_WRHIGH sets active high write strobe, otherwise it is
//!   active low.
//! - \b EPI_HB16_RDHIGH sets active high read strobe, otherwise it is
//!   active low.
//! - Write wait state when \b EPI_HB16_BAUD is used, select one of:
//!     - \b EPI_HB16_WRWAIT_0 sets write wait state to 2 EPI clocks (default).
//!     - \b EPI_HB16_WRWAIT_1 sets write wait state to 4 EPI clocks.
//!     - \b EPI_HB16_WRWAIT_2 sets write wait state to 6 EPI clocks.
//!     - \b EPI_HB16_WRWAIT_3  sets write wait state to 8 EPI clocks.
//! - Read wait state when \b EPI_HB16_BAUD is used, select one of:
//!     - \b EPI_HB16_RDWAIT_0 sets read wait state to 2 EPI clocks (default).
//!     - \b EPI_HB16_RDWAIT_1 sets read wait state to 4 EPI clocks.
//!     - \b EPI_HB16_RDWAIT_2 sets read wait state to 6 EPI clocks.
//!     - \b EPI_HB16_RDWAIT_3 sets read wait state to 8 EPI clocks.
//! - \b EPI_HB16_ALE_HIGH sets the address latch active high (default).
//! - \b EPI_HB16_ALE_LOW sets address latch active low.
//! - \b EPI_HB16_BURST_TRAFFIC enables burst traffic.  Only valid with
//!   \b EPI_HB16_MODE_ADMUX and a chip select configuration that utilizes an
//!   ALE.
//!
//! \note The availability of the unique chip select configuration within the
//! Host-bus 16 interface mode varies based on the Tiva part in use.
//! Please consult the data sheet to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB16CSSet(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config)
{
    uint32_t ui32Offset, ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Determine the register offset based on the ui32CS provided.
    //
    if(ui32CS < 2)
    {
        ui32Offset = EPI_O_HB16CFG + (ui32CS << 2);
    }
    else
    {
        ui32Offset = EPI_O_HB16CFG3 + ((ui32CS - 2) << 2);
    }

    //
    // Preserve the bits that will not be modified.
    //
    ui32Reg = HWREG(ui32Base + ui32Offset) & ~EPI_HB16_CS_MASK;

    //
    // Write the target chip select HostBus16 configuration fields.
    //
    HWREG(ui32Base + ui32Offset) = (ui32Reg | ui32Config);
}

//*****************************************************************************
//
//! Sets the individual chip select timing settings for the Host-bus 8
//! interface.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select value to configure.
//! \param ui32Config is the configuration settings.
//!
//! This function is used to set individual chip select timings for the
//! Host-bus 8 interface mode.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.  The parameter \e ui32Config is the logical OR of the
//! following:
//!
//! - Input ready stall delay, select one of:
//!     - \b EPI_HB8_IN_READY_DELAY_1 sets the stall on input ready (EPIS032)
//!     to start 1 EPI clock after signaled.
//!     - \b EPI_HB8_IN_READY_DELAY_2 sets the stall on input ready (EPIS032)
//!     to start 2 EPI clocks after signaled.
//!     - \b EPI_HB8_IN_READY_DELAY_3 sets the stall on input ready (EPIS032)
//!     to start 3 EPI clocks after signaled.
//!
//! - Host bus transfer delay, select one of:
//!     - \b EPI_HB8_CAP_WIDTH_1 defines the inter-transfer capture width to
//!     create a delay of 1 EPI clock.
//!     - \b EPI_HB8_CAP_WIDTH_2 defines the inter-transfer capture width
//!     to create a delay of 2 EPI clocks.
//!
//! - \b EPI_HB8_WRWAIT_MINUS_DISABLE disables the additional write wait state
//! reduction.
//! - \b EPI_HB8_WRWAIT_MINUS_ENABLE enables a 1 EPI clock write wait state
//! reduction.
//! - \b EPI_HB8_RDWAIT_MINUS_DISABLE disables the additional read wait state
//! reduction.
//! - \b EPI_HB8_RDWAIT_MINUS_ENABLE enables a 1 EPI clock read wait state
//!reduction.
//!
//! \note The availability of unique chip select timings within Host-bus 8
//! interface mode varies based on the Tiva part in use.  Please consult
//! the data sheet to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB8TimingSet(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Write the target chip select HostBus8 timing register.
    //
    HWREG(ui32Base + (EPI_O_HB8TIME + (ui32CS << 2))) = ui32Config;
}

//*****************************************************************************
//
//! Sets the individual chip select timing settings for the Host-bus 16
//! interface.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select value to configure.
//! \param ui32Config is the configuration settings.
//!
//! This function is used to set individual chip select timings for the
//! Host-bus 16 interface mode.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.  The parameter \e ui32Config is the logical OR of the
//! following:
//!
//! - Input ready stall delay, select one of:
//!     - \b EPI_HB16_IN_READY_DELAY_1 sets the stall on input ready (EPIS032)
//!     to start 1 EPI clock after signaled.
//!     - \b EPI_HB16_IN_READY_DELAY_2 sets the stall on input ready (EPIS032)
//!     to start 2 EPI clocks after signaled.
//!     - \b EPI_HB16_IN_READY_DELAY_3 sets the stall on input ready (EPIS032)
//!     to start 3 EPI clocks after signaled.
//!
//! - PSRAM size limitation, select one of:
//!     - \b EPI_HB16_PSRAM_NO_LIMIT defines no row size limitation.
//!     - \b EPI_HB16_PSRAM_128 defines the PSRAM row size to 128 bytes.
//!     - \b EPI_HB16_PSRAM_256 defines the PSRAM row size to 256 bytes.
//!     - \b EPI_HB16_PSRAM_512 defines the PSRAM row size to 512 bytes.
//!     - \b EPI_HB16_PSRAM_1024 defines the PSRAM row size to 1024 bytes.
//!     - \b EPI_HB16_PSRAM_2048 defines the PSRAM row size to 2048 bytes.
//!     - \b EPI_HB16_PSRAM_4096 defines the PSRAM row size to 4096 bytes.
//!     - \b EPI_HB16_PSRAM_8192 defines the PSRAM row size to 8192 bytes.
//!
//! - Host bus transfer delay, select one of:
//!     - \b EPI_HB16_CAP_WIDTH_1 defines the inter-transfer capture width to
//!     create a delay of 1 EPI clock
//!     - \b EPI_HB16_CAP_WIDTH_2 defines the inter-transfer capture width
//!     to create a delay of 2 EPI clocks.
//!
//! - Write wait state timing reduction, select one of:
//!     - \b EPI_HB16_WRWAIT_MINUS_DISABLE disables the additional write wait
//!     state reduction.
//!     - \b EPI_HB16_WRWAIT_MINUS_ENABLE enables a 1 EPI clock write wait
//!     state reduction.
//!
//! - Read wait state timing reduction, select one of:
//!     - \b EPI_HB16_RDWAIT_MINUS_DISABLE disables the additional read wait
//!     state reduction.
//!     - \b EPI_HB16_RDWAIT_MINUS_ENABLE enables a 1 EPI clock read wait state
//!     reduction.
//!
//! \note The availability of unique chip select timings within Host-bus 16
//! interface mode varies based on the Tiva part in use.  Please consult
//! the data sheet to determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIConfigHB16TimingSet(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Write the target chip select HostBus16 timing register.
    //
    HWREG(ui32Base + (EPI_O_HB16TIME + (ui32CS << 2))) = ui32Config;
}

//*****************************************************************************
//
//! Sets the PSRAM configuration register.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select target.
//! \param ui32CR is the PSRAM configuration register value.
//!
//! This function sets the PSRAM's configuration register by using the PSRAM
//! configuration register enable signal.  The Host-bus 16 interface mode
//! should be configured prior to calling this function.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.  The parameter \e ui32CR value is determined by
//! consulting the PSRAM's data sheet.
//!
//! \note The availability of PSRAM support varies based on the Tiva part
//! in use.  Please consult the data sheet to determine if this feature is
//! available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIPSRAMConfigRegSet(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32CR)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Determine the register offset based on the ui32CS provided.
    //
    if(ui32CS < 2)
    {
        ui32Offset = EPI_O_HB16CFG + (ui32CS << 2);
    }
    else
    {
        ui32Offset = EPI_O_HB16CFG3 + ((ui32CS - 2) << 2);
    }

    //
    // Setup for the PSRAM configuration register write.  Only 21 bits are
    // valid on a write.
    //
    HWREG(ui32Base + EPI_O_HBPSRAM) = (ui32CR & 0x1fffff);

    //
    // Set the PSRAM configuration register write enable.
    //
    HWREG(ui32Base + ui32Offset) |= EPI_HB16CFG_WRCRE;
}

//*****************************************************************************
//
//! Requests a configuration register read from the PSRAM.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select target.
//!
//! This function requests a read of the PSRAM's configuration register.  The
//! Host-bus 16 interface mode should be configured prior to calling this
//! function.
//! The EPIPSRAMConfigRegGet() and EPIPSRAMConfigRegGetNonBlocking() can
//! be used to retrieve the configuration register value.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.
//!
//! \note The availability of PSRAM support varies based on the Tiva part
//! in use.  Please consult the data sheet to determine if this feature is
//! available.
//!
//! \return none.
//
//*****************************************************************************
void
EPIPSRAMConfigRegRead(uint32_t ui32Base, uint32_t ui32CS)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Determine the register offset based on the ui32CS provided.
    //
    if(ui32CS < 2)
    {
        ui32Offset = EPI_O_HB16CFG + (ui32CS << 2);
    }
    else
    {
        ui32Offset = EPI_O_HB16CFG3 + ((ui32CS - 2) << 2);
    }

    //
    // Set the PSRAM configuration register read enable.
    //
    HWREG(ui32Base + ui32Offset) |= EPI_HB16CFG_RDCRE;
}

//*****************************************************************************
//
//! Retrieves the contents of the EPI PSRAM configuration register.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select target.
//! \param pui32CR is the provided storage used to hold the register value.
//!
//! This function copies the contents of the EPI PSRAM configuration register
//! to the provided storage if the PSRAM read configuration register enable
//! is no longer asserted.  Otherwise the provided storage is not modified.
//!
//! The Host-bus 16 interface mode should be setup and EPISRAMConfigRegRead()
//! should be called prior to calling this function.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.  The \e pui32CR parameter is a pointer to provided
//! storage used to hold the register value.
//!
//! \note The availability of PSRAM support varies based on the Tiva part
//! in use.  Please consult the data sheet to determine if this feature is
//! available.
//!
//! \return \b true if the value was copied to the provided storage and
//! \b false if it was not.
//
//*****************************************************************************
bool
EPIPSRAMConfigRegGetNonBlocking(uint32_t ui32Base, uint32_t ui32CS,
                                uint32_t *pui32CR)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Determine the register offset based on the ui32CS provided.
    //
    if(ui32CS < 2)
    {
        ui32Offset = EPI_O_HB16CFG + (ui32CS << 2);
    }
    else
    {
        ui32Offset = EPI_O_HB16CFG3 + ((ui32CS - 2) << 2);
    }

    //
    // Verify PSRAM read enable is not asserted.
    //
    if(HWREG(ui32Base + ui32Offset) & EPI_HB16CFG_RDCRE)
    {
        return(false);
    }

    //
    // Copy the PSRAM configuration register value to the provided storage.
    // Only the lower 16 bits are valid on a read.
    //
    *pui32CR = HWREG(ui32Base + EPI_O_HBPSRAM) & 0xffff;

    //
    // Notify caller the provided storage holds the EPI PSRAM configuration
    // register contents.
    //
    return(true);
}

//*****************************************************************************
//
//! Retrieves the contents of the EPI PSRAM configuration register.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32CS is the chip select target.
//!
//! This function retrieves the EPI PSRAM configuration register.  The register
//! is read once the EPI PSRAM configuration register read enable signal is
//! de-asserted.
//!
//! The Host-bus 16 interface mode should be setup and EPISRAMConfigRegRead()
//! should be called prior to calling this function.
//!
//! The \e ui32Base parameter is the base address for the EPI hardware module.
//! The \e ui32CS parameter specifies the chip select to configure and has a
//! valid range of 0-3.
//!
//! \note The availability of PSRAM support varies based on the Tiva part
//! in use.  Please consult the data sheet to determine if this feature is
//! available.
//!
//! \return none.
//
//*****************************************************************************
uint32_t
EPIPSRAMConfigRegGet(uint32_t ui32Base, uint32_t ui32CS)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32CS < 4);

    //
    // Determine the register offset based on the ui32CS provided.
    //
    if(ui32CS < 2)
    {
        ui32Offset = EPI_O_HB16CFG + (ui32CS << 2);
    }
    else
    {
        ui32Offset = EPI_O_HB16CFG3 + ((ui32CS - 2) << 2);
    }

    //
    // Wait for PSRAM read enable to deassert if necessary.
    //
    while(HWREG(ui32Base + ui32Offset) & EPI_HB16CFG_RDCRE)
    {
    }

    //
    // Return the EPI PSRAM configuration register contents.
    // Only the lower 16 bits are valid on a read.
    //
    return(HWREG(ui32Base + EPI_O_HBPSRAM) & 0xffff);
}

//*****************************************************************************
//
//! Configures the interface for general-purpose mode operation.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Config is the interface configuration.
//! \param ui32FrameCount is the frame size in clocks, if the frame signal
//! is used (0-15).
//! \param ui32MaxWait is the maximum number of external clocks to wait
//! when the external clock enable is holding off the transaction (0-255).
//!
//! This function is used to configure the interface when used in
//! general-purpose operation as chosen with the function EPIModeSet().  The
//! parameter \e ui32Config is the logical OR of the following:
//!
//! - \b EPI_GPMODE_CLKPIN interface clock as output on a pin.
//! - \b EPI_GPMODE_CLKGATE clock is stopped when there is no transaction,
//!   otherwise it is free-running.
//! - \b EPI_GPMODE_RDYEN the external peripheral drives an iRDY signal into
//!   pin EPI0S27.  If absent, the peripheral is assumed to be ready at all
//!   times.  This flag may only be used with a free-running clock
//!   (\b EPI_GPMODE_CLKGATE is absent).
//! - \b EPI_GPMODE_FRAMEPIN framing signal is emitted on a pin.
//! - \b EPI_GPMODE_FRAME50 framing signal is 50/50 duty cycle, otherwise it
//!   is a pulse.
//! - \b EPI_GPMODE_WRITE2CYCLE a two-cycle write is used, otherwise a
//!   single-cycle write is used.
//! - \b EPI_GPMODE_READ2CYCLE a two-cycle read is used, otherwise a
//!   single-cycle read is used.
//! - Address bus size, select one of:
//!     - \b EPI_GPMODE_ASIZE_NONE sets no address bus.
//!     - \b EPI_GPMODE_ASIZE_4 sets an address bus size of 4 bits.
//!     - \b EPI_GPMODE_ASIZE_12 sets an address bus size of 12 bits.
//!     - \b EPI_GPMODE_ASIZE_20 sets an address bus size of 20 bits.
//! - Data bus size, select one of:
//!     - \b EPI_GPMODE_DSIZE_8 sets a data bus size of 8 bits.
//!     - \b EPI_GPMODE_DSIZE_16 sets a data bus size of 16 bits.
//!     - \b EPI_GPMODE_DSIZE_24 sets a data bus size of 24 bits.
//!     - \b EPI_GPMODE_DSIZE_32 sets a data bus size of 32 bits.
//! - \b EPI_GPMODE_WORD_ACCESS - use Word Access mode to route bytes to the
//!   correct byte lanes allowing data to be stored in the upper bits of the
//!   word when necessary.
//!
//! \note \b EPI_GPMODE_WORD_ACCESS is not available on all parts.  Please
//! consult the data sheet to determine if this feature is available.
//!
//! The parameter \e ui32FrameCount is the number of clocks used to form the
//! framing signal, if the framing signal is used.  The behavior depends on
//! whether the frame signal is a pulse or a 50/50 duty cycle.  This value
//! is not used if the framing signal is not enabled with the option
//! \b EPI_GPMODE_FRAMEPIN.
//!
//! The parameter \e ui32MaxWait is used if the external clock enable is turned
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
EPIConfigGPModeSet(uint32_t ui32Base, uint32_t ui32Config,
                   uint32_t ui32FrameCount, uint32_t ui32MaxWait)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32FrameCount < 16);
    ASSERT(ui32MaxWait < 256);

    //
    // Fill in the frame count field of the configuration word.
    //
    ui32Config &= ~EPI_GPCFG_FRMCNT_M;
    ui32Config |= ui32FrameCount << EPI_GPCFG_FRMCNT_S;

    //
    // Fill in the max wait field of the configuration word.
    //
    ui32Config &= ~EPI_GPCFG_MAXWAIT_M;
    ui32Config |= ui32MaxWait << EPI_GPCFG_MAXWAIT_S;

    //
    // Write the non-moded configuration register.
    //
    HWREG(ui32Base + EPI_O_GPCFG) = ui32Config;
}

//*****************************************************************************
//
//! Configures the address map for the external interface.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Map is the address mapping configuration.
//!
//! This function is used to configure the address mapping for the external
//! interface, which then determines the base address of the external memory or
//! device within the processor peripheral and/or memory space.
//!
//! The parameter \e ui32Map is the logical OR of the following:
//!
//! - Peripheral address space size, select one of:
//!     - \b EPI_ADDR_PER_SIZE_256B sets the peripheral address space to 256
//! bytes.
//!     - \b EPI_ADDR_PER_SIZE_64KB sets the peripheral address space to 64
//! Kbytes.
//!     - \b EPI_ADDR_PER_SIZE_16MB sets the peripheral address space to 16
//! Mbytes.
//!     - \b EPI_ADDR_PER_SIZE_256MB sets the peripheral address space to 256
//! Mbytes.
//! - Peripheral base address, select one of:
//!     - \b EPI_ADDR_PER_BASE_NONE sets the peripheral base address to none.
//!     - \b EPI_ADDR_PER_BASE_A sets the peripheral base address to
//! 0xA0000000.
//!     - \b EPI_ADDR_PER_BASE_C sets the peripheral base address to
//! 0xC0000000.
//! - RAM address space, select one of:
//!     - \b EPI_ADDR_RAM_SIZE_256B sets the RAM address space to 256 bytes.
//!     - \b EPI_ADDR_RAM_SIZE_64KB sets the RAM address space to 64 Kbytes.
//!     - \b EPI_ADDR_RAM_SIZE_16MB sets the RAM address space to 16 Mbytes.
//!     - \b EPI_ADDR_RAM_SIZE_256MB sets the RAM address space to 256 Mbytes.
//! - RAM base address, select one of:
//!     - \b EPI_ADDR_RAM_BASE_NONE sets the RAM space address to none.
//!     - \b EPI_ADDR_RAM_BASE_6 sets the RAM space address to 0x60000000.
//!     - \b EPI_ADDR_RAM_BASE_8 sets the RAM space address to 0x80000000.
//! - \b EPI_ADDR_RAM_QUAD_MODE maps CS0n to 0x60000000, CS1n to 0x80000000,
//! CS2n to 0xA0000000, and CS3n to 0xC0000000.
//! - \b EPI_ADDR_CODE_SIZE_256B sets an external code size of 256 bytes, range
//! 0x00 to 0xFF.
//! - \b EPI_ADDR_CODE_SIZE_64KB sets an external code size of 64 Kbytes, range
//! 0x0000 to 0xFFFF.
//! - \b EPI_ADDR_CODE_SIZE_16MB sets an external code size of 16 Mbytes, range
//! 0x000000 to 0xFFFFFF.
//! - \b EPI_ADDR_CODE_SIZE_256MB sets an external code size of 256 Mbytes,
//! range 0x0000000 to 0xFFFFFFF.
//! - \b EPI_ADDR_CODE_BASE_NONE sets external code base to not mapped.
//! - \b EPI_ADDR_CODE_BASE_1 sets external code base to 0x10000000.
//!
//! \note The availability of \b EPI_ADDR_RAM_QUAD_MODE and \b EPI_ADDR_CODE_*
//! varies based on the Tiva part in use.  Please consult the data sheet
//! to determine if these features are available.
//!
//! \return None.
//
//*****************************************************************************
void
EPIAddressMapSet(uint32_t ui32Base, uint32_t ui32Map)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Map < 0x1000);

    //
    // Set the value of the address mapping register.
    //
    HWREG(ui32Base + EPI_O_ADDRMAP) = ui32Map;
}

//*****************************************************************************
//
//! Configures a non-blocking read transaction.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Channel is the read channel (0 or 1).
//! \param ui32DataSize is the size of the data items to read.
//! \param ui32Address is the starting address to read.
//!
//! This function is used to configure a non-blocking read channel for a
//! transaction.  Two channels are available which can be used in a ping-pong
//! method for continuous reading.  It is not necessary to use both channels
//! to perform a non-blocking read.
//!
//! The parameter \e ui8DataSize is one of \b EPI_NBCONFIG_SIZE_8,
//! \b EPI_NBCONFIG_SIZE_16, or \b EPI_NBCONFIG_SIZE_32 for 8-bit, 16-bit,
//! or 32-bit sized data transfers.
//!
//! The parameter \e ui32Address is the starting address for the read, relative
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
EPINonBlockingReadConfigure(uint32_t ui32Base, uint32_t ui32Channel,
                            uint32_t ui32DataSize, uint32_t ui32Address)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Channel < 2);
    ASSERT(ui32DataSize < 4);
    ASSERT(ui32Address < 0x20000000);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ui32Offset = ui32Channel * (EPI_O_RSIZE1 - EPI_O_RSIZE0);

    //
    // Write the data size register for the channel.
    //
    HWREG(ui32Base + EPI_O_RSIZE0 + ui32Offset) = ui32DataSize;

    //
    // Write the starting address register for the channel.
    //
    HWREG(ui32Base + EPI_O_RADDR0 + ui32Offset) = ui32Address;
}

//*****************************************************************************
//
//! Starts a non-blocking read transaction.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Channel is the read channel (0 or 1).
//! \param ui32Count is the number of items to read (1-4095).
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
EPINonBlockingReadStart(uint32_t ui32Base, uint32_t ui32Channel,
                        uint32_t ui32Count)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Channel < 2);
    ASSERT(ui32Count < 4096);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ui32Offset = ui32Channel * (EPI_O_RPSTD1 - EPI_O_RPSTD0);

    //
    // Write to the read count register.
    //
    HWREG(ui32Base + EPI_O_RPSTD0 + ui32Offset) = ui32Count;
}

//*****************************************************************************
//
//! Stops a non-blocking read transaction.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Channel is the read channel (0 or 1).
//!
//! This function cancels a non-blocking read transaction that is already
//! in progress.
//!
//! \return None.
//
//*****************************************************************************
void
EPINonBlockingReadStop(uint32_t ui32Base, uint32_t ui32Channel)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Channel < 2);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ui32Offset = ui32Channel * (EPI_O_RPSTD1 - EPI_O_RPSTD0);

    //
    // Write a 0 to the read count register, which cancels the transaction.
    //
    HWREG(ui32Base + EPI_O_RPSTD0 + ui32Offset) = 0;
}

//*****************************************************************************
//
//! Get the count remaining for a non-blocking transaction.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Channel is the read channel (0 or 1).
//!
//! This function gets the remaining count of items for a non-blocking read
//! transaction.
//!
//! \return The number of items remaining in the non-blocking read transaction.
//
//*****************************************************************************
uint32_t
EPINonBlockingReadCount(uint32_t ui32Base, uint32_t ui32Channel)
{
    uint32_t ui32Offset;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Channel < 2);

    //
    // Compute the offset needed to select the correct channel regs.
    //
    ui32Offset = ui32Channel * (EPI_O_RPSTD1 - EPI_O_RPSTD0);

    //
    // Read the count remaining and return the value to the caller.
    //
    return(HWREG(ui32Base + EPI_O_RPSTD0 + ui32Offset));
}

//*****************************************************************************
//
//! Get the count of items available in the read FIFO.
//!
//! \param ui32Base is the EPI module base address.
//!
//! This function gets the number of items that are available to read in
//! the read FIFO.  The read FIFO is filled by a non-blocking read transaction
//! which is configured by the functions EPINonBlockingReadConfigure() and
//! EPINonBlockingReadStart().
//!
//! \return The number of items available to read in the read FIFO.
//
//*****************************************************************************
uint32_t
EPINonBlockingReadAvail(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // Read the FIFO count and return it to the caller.
    //
    return(HWREG(ui32Base + EPI_O_RFIFOCNT));
}

//*****************************************************************************
//
//! Read available data from the read FIFO, as 32-bit data items.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Count is the maximum count of items to read.
//! \param pui32Buf is the caller supplied buffer where the read data should
//! be stored.
//!
//! This function reads 32-bit data items from the read FIFO and stores
//! the values in a caller-supplied buffer.  The function reads and stores
//! data from the FIFO until there is no more data in the FIFO or the maximum
//! count is reached as specified in the parameter \e ui32Count.  The actual
//! count of items is returned.
//!
//! \return The number of items read from the FIFO.
//
//*****************************************************************************
uint32_t
EPINonBlockingReadGet32(uint32_t ui32Base, uint32_t ui32Count,
                        uint32_t *pui32Buf)
{
    uint32_t ui32CountRead = 0;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Count < 4096);
    ASSERT(pui32Buf);

    //
    // Read from the FIFO while there are any items to read and
    // the caller's specified count is not exceeded.
    //
    while(HWREG(ui32Base + EPI_O_RFIFOCNT) && ui32Count--)
    {
        //
        // Read from the FIFO and store in the caller supplied buffer.
        //
        *pui32Buf = HWREG(ui32Base + EPI_O_READFIFO0);

        //
        // Update the caller's buffer pointer and the count of items read.
        //
        pui32Buf++;
        ui32CountRead++;
    }

    //
    // Return the count of items read to the caller.
    //
    return(ui32CountRead);
}

//*****************************************************************************
//
//! Read available data from the read FIFO, as 16-bit data items.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Count is the maximum count of items to read.
//! \param pui16Buf is the caller-supplied buffer where the read data should
//! be stored.
//!
//! This function reads 16-bit data items from the read FIFO and stores
//! the values in a caller-supplied buffer.  The function reads and stores
//! data from the FIFO until there is no more data in the FIFO or the maximum
//! count is reached as specified in the parameter \e ui32Count.  The actual
//! count of items is returned.
//!
//! \return The number of items read from the FIFO.
//
//*****************************************************************************
uint32_t
EPINonBlockingReadGet16(uint32_t ui32Base, uint32_t ui32Count,
                        uint16_t *pui16Buf)
{
    uint32_t ui32CountRead = 0;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Count < 4096);
    ASSERT(pui16Buf);

    //
    // Read from the FIFO while there are any items to read, and
    // the caller's specified count is not exceeded.
    //
    while(HWREG(ui32Base + EPI_O_RFIFOCNT) && ui32Count--)
    {
        //
        // Read from the FIFO and store in the caller-supplied buffer.
        //
        *pui16Buf = (uint16_t)HWREG(ui32Base + EPI_O_READFIFO0);

        //
        // Update the caller's buffer pointer and the count of items read.
        //
        pui16Buf++;
        ui32CountRead++;
    }

    //
    // Return the count of items read to the caller.
    //
    return(ui32CountRead);
}

//*****************************************************************************
//
//! Read available data from the read FIFO, as 8-bit data items.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Count is the maximum count of items to read.
//! \param pui8Buf is the caller-supplied buffer where the read data should
//! be stored.
//!
//! This function reads 8-bit data items from the read FIFO and stores
//! the values in a caller-supplied buffer.  The function reads and stores
//! data from the FIFO until there is no more data in the FIFO or the maximum
//! count is reached as specified in the parameter \e ui32Count.  The actual
//! count of items is returned.
//!
//! \return The number of items read from the FIFO.
//
//*****************************************************************************
uint32_t
EPINonBlockingReadGet8(uint32_t ui32Base, uint32_t ui32Count,
                       uint8_t *pui8Buf)
{
    uint32_t ui32CountRead = 0;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Count < 4096);
    ASSERT(pui8Buf);

    //
    // Read from the FIFO while there are any items to read, and
    // the caller's specified count is not exceeded.
    //
    while(HWREG(ui32Base + EPI_O_RFIFOCNT) && ui32Count--)
    {
        //
        // Read from the FIFO and store in the caller supplied buffer.
        //
        *pui8Buf = (uint8_t)HWREG(ui32Base + EPI_O_READFIFO0);

        //
        // Update the caller's buffer pointer and the count of items read.
        //
        pui8Buf++;
        ui32CountRead++;
    }

    //
    // Return the count of items read to the caller.
    //
    return(ui32CountRead);
}

//*****************************************************************************
//
//! Configures the read FIFO.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32Config is the FIFO configuration.
//!
//! This function configures the FIFO trigger levels and error
//! generation.  The parameter \e ui32Config is the logical OR of the
//! following:
//!
//! - \b EPI_FIFO_CONFIG_WTFULLERR enables an error interrupt when a write is
//! attempted and the write FIFO is full
//! - \b EPI_FIFO_CONFIG_RSTALLERR enables an error interrupt when a read is
//! stalled due to an interleaved write or other reason
//! - FIFO TX trigger level, select one of:
//!     - \b EPI_FIFO_CONFIG_TX_EMPTY sets the FIFO TX trigger level to empty.
//!     - \b EPI_FIFO_CONFIG_TX_1_4 sets the FIFO TX trigger level to 1/4.
//!     - \b EPI_FIFO_CONFIG_TX_1_2 sets the FIFO TX trigger level to 1/2.
//!     -\b EPI_FIFO_CONFIG_TX_3_4 sets the FIFO TX trigger level to 3/4.
//! - FIFO RX trigger level, select one of:
//!     - \b EPI_FIFO_CONFIG_RX_1_8 sets the FIFO RX trigger level to 1/8.
//!     - \b EPI_FIFO_CONFIG_RX_1_4 sets the FIFO RX trigger level to 1/4.
//!     - \b EPI_FIFO_CONFIG_RX_1_2 sets the FIFO RX trigger level to 1/2.
//!     - \b EPI_FIFO_CONFIG_RX_3_4 sets the FIFO RX trigger level to 3/4.
//!     - \b EPI_FIFO_CONFIG_RX_7_8 sets the FIFO RX trigger level to 7/8.
//!     - \b EPI_FIFO_CONFIG_RX_FULL sets the FIFO RX trigger level to full.
//!
//! \return None.
//
//*****************************************************************************
void
EPIFIFOConfig(uint32_t ui32Base, uint32_t ui32Config)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32Config == (ui32Config & 0x00030077));

    //
    // Load the configuration into the FIFO config reg.
    //
    HWREG(ui32Base + EPI_O_FIFOLVL) = ui32Config;
}

//*****************************************************************************
//
//! Reads the number of empty slots in the write transaction FIFO.
//!
//! \param ui32Base is the EPI module base address.
//!
//! This function returns the number of slots available in the transaction
//! FIFO.  It can be used in a polling method to avoid attempting a write
//! that would stall.
//!
//! \return The number of empty slots in the transaction FIFO.
//
//*****************************************************************************
uint32_t
EPIWriteFIFOCountGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // Read the FIFO count and return it to the caller.
    //
    return(HWREG(ui32Base + EPI_O_WFIFOCNT));
}

//*****************************************************************************
//
//! Enables EPI interrupt sources.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! This function enables the specified EPI sources to generate interrupts.
//! The \e ui32IntFlags parameter can be the logical OR of any of the following
//! values:
//!
//! - \b EPI_INT_TXREQ interrupt when transmit FIFO is below the trigger level.
//! - \b EPI_INT_RXREQ interrupt when read FIFO is above the trigger level.
//! - \b EPI_INT_ERR interrupt when an error condition occurs.
//! - \b EPI_INT_DMA_TX_DONE interrupt when the transmit DMA completes.
//! - \b EPI_INT_DMA_RX_DONE interrupt when the read DMA completes.
//!
//! \return Returns None.
//
//*****************************************************************************
void
EPIIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32IntFlags < 17);

    //
    // Write the interrupt flags mask to the mask register.
    //
    HWREG(ui32Base + EPI_O_IM) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables EPI interrupt sources.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be disabled.
//!
//! This function disables the specified EPI sources for interrupt
//! generation.  The \e ui32IntFlags parameter can be the logical OR of any of
//! the following values:
//!
//! - \b EPI_INT_TXREQ interrupt when transmit FIFO is below the trigger level.
//! - \b EPI_INT_RXREQ interrupt when read FIFO is above the trigger level.
//! - \b EPI_INT_ERR interrupt when an error condition occurrs.
//! - \b EPI_INT_DMA_TX_DONE interrupt when the transmit DMA completes.
//! - \b EPI_INT_DMA_RX_DONE interrupt when the read DMA completes.
//!
//! \return Returns None.
//
//*****************************************************************************
void
EPIIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32IntFlags < 17);

    //
    // Write the interrupt flags mask to the mask register.
    //
    HWREG(ui32Base + EPI_O_IM) &= ~ui32IntFlags;
}

//*****************************************************************************
//
//! Gets the EPI interrupt status.
//!
//! \param ui32Base is the EPI module base address.
//! \param bMasked is set \b true to get the masked interrupt status, or
//! \b false to get the raw interrupt status.
//!
//! This function returns the EPI interrupt status.  It can return either
//! the raw or masked interrupt status.
//!
//! \return Returns the masked or raw EPI interrupt status, as a bit field
//! of any of the following values:
//!
//! - \b EPI_INT_TXREQ interrupt when transmit FIFO is below the trigger level.
//! - \b EPI_INT_RXREQ interrupt when read FIFO is above the trigger level.
//! - \b EPI_INT_ERR interrupt when an error condition occurrs.
//! - \b EPI_INT_DMA_TX_DONE interrupt when the transmit DMA completes.
//! - \b EPI_INT_DMA_RX_DONE interrupt when the read DMA completes.
//
//*****************************************************************************
uint32_t
EPIIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ui32Base + EPI_O_MIS));
    }
    else
    {
        return(HWREG(ui32Base + EPI_O_RIS));
    }
}

//*****************************************************************************
//
//! Gets the EPI error interrupt status.
//!
//! \param ui32Base is the EPI module base address.
//!
//! This function returns the error status of the EPI.  If the return value of
//! the function EPIIntStatus() has the flag \b EPI_INT_ERR set, then this
//! function can be used to determine the cause of the error.
//!
//! \return Returns a bit mask of error flags, which can be the logical
//! OR of any of the following:
//!
//! - \b EPI_INT_ERR_WTFULL occurs when a write stalled when the transaction
//! FIFO was full
//! - \b EPI_INT_ERR_RSTALL occurs when a read stalled
//! - \b EPI_INT_ERR_TIMEOUT occurs when the external clock enable held
//! off a transaction longer than the configured maximum wait time
//
//*****************************************************************************
uint32_t
EPIIntErrorStatus(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // Read the error status and return to caller.
    //
    return(HWREG(ui32Base + EPI_O_EISC));
}

//*****************************************************************************
//
//! Clears pending EPI error sources.
//!
//! \param ui32Base is the EPI module base address.
//! \param ui32ErrFlags is a bit mask of the error sources to be cleared.
//!
//! This function clears the specified pending EPI errors.  The \e ui32ErrFlags
//! parameter can be the logical OR of any of the following values:
//!
//! - \b EPI_INT_ERR_DMAWRIC clears the EPI_INT_DMA_TX_DONE as an interrupt
//! source
//! - \b EPI_INT_ERR_DMARDIC clears the EPI_INT_DMA_RX_DONE as an interrupt
//! source
//! - \b EPI_INT_ERR_WTFULL occurs when a write stalled when the transaction
//! FIFO was full
//! - \b EPI_INT_ERR_RSTALL occurs when a read stalled
//! - \b EPI_INT_ERR_TIMEOUT occurs when the external clock enable held
//! off a transaction longer than the configured maximum wait time
//!
//! \return Returns None.
//
//*****************************************************************************
void
EPIIntErrorClear(uint32_t ui32Base, uint32_t ui32ErrFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(ui32ErrFlags < 0x20);

    //
    // Write the error flags to the register to clear the pending errors.
    //
    HWREG(ui32Base + EPI_O_EISC) = ui32ErrFlags;
}

//*****************************************************************************
//
//! Returns the interrupt number for a given EPI base address.
//!
//! \param ui32Base is the base address of the EPI module.
//!
//! This function returns the interrupt number for the EPI module with the base
//! address passed in the \e ui32Base parameter.
//!
//! \return Returns the EPI interrupt number or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint32_t
_EPIIntNumberGet(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // By default, assume EPI is not supported.
    //
    ui32Int = 0;

    if(CLASS_IS_SNOWFLAKE)
    {
        ui32Int = INT_EPI0_SNOWFLAKE;
    }

    return(ui32Int);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the EPI module.
//!
//! \param ui32Base is the EPI module base address.
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
EPIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);
    ASSERT(pfnHandler);

    //
    // Get the interrupt number for the EPI interface.
    //
    ui32Int = _EPIIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the EPI interface interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the EPI module.
//!
//! \param ui32Base is the EPI module base address.
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
EPIIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == EPI0_BASE);

    //
    // Get the interrupt number for the EPI interface.
    //
    ui32Int = _EPIIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Disable the EPI interface interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
