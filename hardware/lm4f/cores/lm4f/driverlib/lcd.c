//*****************************************************************************
//
// lcd.c - Defines and Macros for the LCD Controller module.
//
// Copyright (c) 2012-2013 Texas Instruments Incorporated.  All rights reserved.
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

//*****************************************************************************
//
//! \addtogroup lcd_api
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_lcd.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/lcd.h"
#include "driverlib/debug.h"

//*****************************************************************************
//
// These are currently missing from hw_lcd.h.  Remove them once you start
// seeing build warnings :-)
//
//*****************************************************************************
#define LCD_RASTRTIM0_MSBPPL_S   (3)
#define LCD_RASTRTIM2_MSBLPP_S   (26)

//*****************************************************************************
//
//! Configures the basic operating mode and clock rate for the LCD controller.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui8Mode specifies the basic operating mode to be used.
//! \param ui32PixClk specifies the desired LCD controller pixel or master
//! clock rate in Hz.
//! \param ui32SysClk specifies the current system clock rate in Hz.
//!
//! This function sets the basic operating mode of the LCD controller and also
//! its master clock. The \e ui8Mode parameter may be set to either \b
//! LCD_MODE_LIDD or \b LCD_MODE_RASTER. \b LCD_MODE_LIDD is used to select
//! LCD Interface Display Driver mode for character panels connected via
//! an asynchronous interface (CS, WE, OE, ALE, data) and \b LCD_MODE_RASTER
//! is used to communicate with panels via a synchronous video interface using
//! data and sync signals.  Additionally, \b LIDD_MODE_AUTO_UFLOW_RESTART may
//! be ORed with either of these modes to indicate that the hardware should
//! restart automatically if a data underflow occurs.
//!
//! The \e ui32PixClk parameter specifies the desired master clock for the
//! the LCD controller.  In LIDD mode, this value controls the MCLK used in
//! communication with the display and valid values are between \e ui32SysClk
//! and \e ui32SysClk/255.  In raster mode, \e ui32PixClk specifies the pixel
//! clock rate for the raster interface and valid values are between \e
//! ui32SysClk/2 and \e ui32SysClk/255.  The actual clock rate set may differ
//! slightly from the desired rate due to the fact that only integer dividers
//! are supported.  The rate set will, however, be no higher than the requested
//! value.
//!
//! The \e ui32SysClk parameter provides the current system clock rate and is
//! used to allow the LCD controller clock rate divisor to be correctly set
//! to give the desired \e ui32PixClk rate.
//!
//! \return Returns the actual LCD controller pixel clock or MCLK rate set.
//
//*****************************************************************************
uint32_t
LCDModeSet(uint32_t ui32Base, uint8_t ui8Mode, uint32_t ui32PixClk,
           uint32_t ui32SysClk)
{
    uint32_t ui32Div;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui8Mode & ~(LCD_MODE_RASTER | LCD_MODE_LIDD |
                        LCD_MODE_AUTO_UFLOW_RESTART)) == 0);

    //
    // Enable clocks to the LCD controller submodules.
    //
    HWREG(ui32Base + LCD_O_CLKEN) = (LCD_CLKEN_DMA | LCD_CLKEN_CORE |
                                     LCD_CLKEN_LIDD);

    //
    // Determine the clock divider to use to get as close as possible to the
    // desired pixel clock.  Note that we set the division up so that we
    // round the divisor up and ensure that the clock used is never faster
    // than the requested rate.
    //
    ui32Div = (ui32SysClk + (ui32PixClk - 1)) / ui32PixClk;

    //
    // Check that the calculated value is valid.
    //
    ASSERT(ui32Div);
    ASSERT(ui32Div < 256);
    ASSERT(!((ui8Mode & LCD_MODE_RASTER) && (ui32Div < 2)));

    //
    // Write the LCDCTL register to set the mode.
    //
    HWREG(ui32Base + LCD_O_CTL) = (uint32_t)ui8Mode |
                                  (ui32Div << LCD_CTL_CLKDIV_S);

    //
    // Return the selected clock rate.  Finding ui32Div set to 0 should not
    // happen unless someone passed pathological arguments and builds without
    // the ASSERTS, but we guard against it just in case.
    //
    return(ui32Div ? (ui32SysClk / ui32Div) : ui32SysClk);
}

//*****************************************************************************
//
//! Resets one or more of the LCD controller clock domains.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32Clocks defines the subset of clock domains to be reset.
//!
//! This function allows sub-modules of the LCD controller to be reset under
//! software control.  The \e ui32Clocks parameter is the logical OR of the
//! following clocks:
//!
//! - \b LCD_CLOCK_MAIN causes the entire LCD controller module to be reset.
//! - \b LCD_CLOCK_DMA causes the DMA controller submodule to be reset.
//! - \b LCD_CLOCK_LIDD causes the LIDD submodule to be reset.
//! - \b LCD_CLOCK_CORE causes the code module, including the raster logic to
//! be reset.
//!
//! In all cases, LCD controller register values are preserved across these
//! resets.
//!
//! \return None.
//
//*****************************************************************************
void
LCDClockReset(uint32_t ui32Base, uint32_t ui32Clocks)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32Clocks & ~(LCD_CLOCK_MAIN | LCD_CLOCK_LIDD | LCD_CLOCK_DMA |
                            LCD_CLOCK_CORE)));

    //
    // Reset the required LCD controller sub-module(s).
    //
    HWREG(LCD0_BASE + 0x70) = ui32Clocks;

    //
    // Wait a while.
    //
    SysCtlDelay(10);

    //
    // Remove software reset.
    //
    HWREG(LCD0_BASE + 0x70) = 0x00000000;

    //
    // Wait a while.
    //
    SysCtlDelay(10);
}

//*****************************************************************************
//
//! Sets the LCD controller communication parameters when in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32Config defines the display interface configuration.
//!
//! This function is used when the LCD controller is configured in LIDD
//! mode and specifies the configuration of the interface between the
//! controller and the display panel.  The \e ui32Config parameter is
//! comprised of one of the following modes:
//!
//! - \b LIDD_CONFIG_SYNC_MPU68 selects Sync MPU68 mode.  LCDCP = EN, LCDLP =
//! DIR, LCDFP = ALE, LCDAC = CS0, LCDMCLK = MCLK.
//! - \b LIDD_CONFIG_ASYNC_MPU68 selects Async MPU68 mode.  LCDCP = EN, LCDLP =
//! DIR, LCDFP = ALE, LCDAC = CS0, LCDMCLK = CS1.
//! - \b LIDD_CONFIG_SYNC_MPU80 selects Sync MPU80 mode.  LCDCP = RS, LCDLP =
//! WS, LCDFP = ALE, LCDAC = CS0, LCDMCLK = MCLK.
//! - \b LIDD_CONFIG_ASYNC_MPU80 selects Async MPU80 mode.  LCDCP = RS, LCDLP =
//! WS, LCDFP = ALE, LCDAC = CS0, LCDMCLK = CS1.
//! - \b LIDD_CONFIG_ASYNC_HITACHI selects Hitachi (async) mode.  LCDCP = N/C,
//! LCDLP = DIR, LCDFP = ALE, LCDAC = E0, LCDMCLK = E1.
//!
//! Additional flags may be ORed into \e ui32Config to control the polarities
//! of various control signals:
//!
//! - \b LIDD_CONFIG_INVERT_ALE - Address Latch Enable (ALE) polarity control.
//! By default, ALE is active low.  If this flag is set, it becomes active
//! high.
//! - \b LIDD_CONFIG_INVERT_RS_EN - Read Strobe/Enable polarity control.  By
//! default, RS is active low and Enable is active high. If this flag is set,
//! RS becomes active high and Enable active low.
//! - \b LIDD_CONFIG_INVERT_WS_DIR - Write Strobe/Direction polarity control.
//! By default, WS is active low and Direction write low/read high. If this
//! flag is set, WS becomes active high and Direction becomes write high/read
//! low.
//! - \b LIDD_CONFIG_INVERT_CS0 - Chip Select 0/Enable 0 polarity control.  By
//! default, CS0 and E0 are active high.  If this flag is set, they become
//! active low.
//! - \b LIDD_CONFIG_INVERT_CS1 - Chip Select 1/Enable 1 polarity control.  By
//! default, CS1 and E1 are active high.  If this flag is set, they become
//! active low.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIDDConfigSet(uint32_t ui32Base, uint32_t ui32Config)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32Config & ~(LIDD_CONFIG_SYNC_MPU68 | LIDD_CONFIG_ASYNC_MPU68 |
                            LIDD_CONFIG_SYNC_MPU80 | LIDD_CONFIG_ASYNC_MPU80 |
                            LIDD_CONFIG_ASYNC_HITACHI |
                            LIDD_CONFIG_INVERT_ALE |
                            LIDD_CONFIG_INVERT_RS_EN |
                            LIDD_CONFIG_INVERT_WS_DIR |
                            LIDD_CONFIG_INVERT_CS0 | LIDD_CONFIG_INVERT_CS1)));

    //
    // Write the LIDD Control Register.
    //
    HWREG(ui32Base + LCD_O_LIDDCTL) = ui32Config;
}

//*****************************************************************************
//
//! Sets the LCD controller interface timing when in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select whose timings are to be set.
//! \param pTiming points to a structure containing the desired timing
//! parameters.
//!
//! This function is used in LIDD mode to set the setup, strobe and hold times
//! for the various interface control signals.  Independent timings are stored
//! for each of the two supported chip selects offered by the LCD controller.
//!
//! For a definition of the timing parameters required, see the definition of
//! tLCDIDDTiming.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return None
//
//*****************************************************************************
void
LCDIDDTimingSet(uint32_t ui32Base, uint32_t ui32CS,
                const tLCDIDDTiming *pTiming)
{
    uint32_t ui32Val;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));
    ASSERT(pTiming);
    ASSERT(pTiming->ui8WSSetup < 32);
    ASSERT(pTiming->ui8WSDuration && (pTiming->ui8WSDuration < 64));
    ASSERT(pTiming->ui8WSHold && (pTiming->ui8WSHold < 16));
    ASSERT(pTiming->ui8RSSetup < 32);
    ASSERT(pTiming->ui8RSDuration && (pTiming->ui8RSDuration < 64));
    ASSERT(pTiming->ui8RSHold && (pTiming->ui8RSHold < 16));
    ASSERT(pTiming->ui8DelayCycles && (pTiming->ui8DelayCycles < 5));

    //
    // Convert the timings provided into a value ready for the register.
    //
    ui32Val =
        (((uint32_t)(pTiming->ui8WSSetup) << LCD_LIDDCS0CFG_WRSU_S) |
         ((uint32_t)(pTiming->ui8WSDuration) << LCD_LIDDCS0CFG_WRDUR_S) |
         ((uint32_t)(pTiming->ui8WSHold) << LCD_LIDDCS0CFG_WRHOLD_S) |
         ((uint32_t)(pTiming->ui8RSSetup) << LCD_LIDDCS0CFG_RDSU_S) |
         ((uint32_t)(pTiming->ui8RSDuration) << LCD_LIDDCS0CFG_RDDUR_S) |
         ((uint32_t)(pTiming->ui8RSHold) << LCD_LIDDCS0CFG_RDHOLD_S) |
         ((uint32_t)(pTiming->ui8DelayCycles - 1) << LCD_LIDDCS0CFG_GAP_S));

    //
    // Write the appropriate LCD LIDD CS configuration register.
    //
    if(!ui32CS)
    {
        HWREG(ui32Base + LCD_O_LIDDCS0CFG) = ui32Val;
    }
    else
    {
        HWREG(ui32Base + LCD_O_LIDDCS1CFG) = ui32Val;
    }
}

//*****************************************************************************
//
//! Disables DMA operation when the LCD controller is in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//!
//! When the LCD controller is operating in LCD Interface Display Driver mode,
//! this function must be called after completion of a DMA transaction and
//! before calling LCDIDDCommandWrite(), LCDIDDDataWrite(), LCDIDDStatusRead(),
//! LCDIDDIndexedWrite(), LCDIDDIndexedRead() or LCDIDDDataRead() to disable
//! DMA mode and allow CPU-initiated transactions to the display.
//!
//! \note LIDD DMA mode is enabled automatically when LCDIDDDMAWrite() is
//! called.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIDDDMADisable(uint32_t ui32Base)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Disable DMA.
    //
    HWREG(ui32Base + LCD_O_LIDDCTL) &= ~LCD_LIDDCTL_DMAEN;
}

//*****************************************************************************
//
//! Writes a command to the display when the LCD controller is in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//! \param ui16Cmd is the 16 bit command word to write.
//!
//! This function writes a 16 bit command word to the display when the LCD
//! controller is in LIDD mode.  A command write occurs with the ALE signal
//! active.
//!
//! This function must not be called if the LIDD interface is currently
//! configured to expect DMA transactions.  If DMA was previously used to
//! write to the panel, LCDIDDDMADisable() must be called before this function
//! can be used.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIDDCommandWrite(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Cmd)
{
    uint32_t ui32Reg;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));

    //
    // Determine the register to write based on the CS value supplied.
    //
    ui32Reg = ui32CS ? LCD_O_LIDDCS1ADDR : LCD_O_LIDDCS0ADDR;

    //
    // Write the command/address to the register.
    //
    HWREG(ui32Base + ui32Reg) = ui16Cmd;
}

//*****************************************************************************
//
//! Writes a data value to the display when the LCD controller is in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//! \param ui16Data is the 16 bit data word to write.
//!
//! This function writes a 16 bit data word to the display when the LCD
//! controller is in LIDD mode.  A data write occurs with the ALE signal
//! inactive.
//!
//! This function must not be called if the LIDD interface is currently
//! configured to expect DMA transactions.  If DMA was previously used to
//! write to the panel, LCDIDDDMADisable() must be called before this function
//! can be used.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIDDDataWrite(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Data)
{
    uint32_t ui32Reg;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));

    //
    // Determine the register to write based on the CS value supplied.
    //
    ui32Reg = ui32CS ? LCD_O_LIDDCS1DATA : LCD_O_LIDDCS0DATA;

    //
    // Write the data value to the register.
    //
    HWREG(ui32Base + ui32Reg) = ui16Data;
}

//*****************************************************************************
//
//! Writes data to a given display register when the LCD controller is in LIDD
//! mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//! \param ui16Addr is the address of the display register to write.
//! \param ui16Data is the data to write.
//!
//! This function writes a 16 bit data word to a register in the display when
//! the LCD controller is in LIDD mode and configured to use either the
//! Motorola (\b LIDD_CONFIG_SYNC_MPU68 or \b LIDD_CONFIG_ASYNC_MPU68) or
//! Intel (\b LIDD_CONFIG_SYNC_MPU80 or \b LIDD_CONFIG_ASYNC_MPU80) modes
//! which employ an external address latch.
//!
//! When configured in Hitachi mode (\b LIDD_CONFIG_ASYNC_HITACHI), this
//! function should not be used.  In this case the functions
//! LCDIDDCommandWrite() and LCDIDDDataWrite() may be used to transfer
//! command and data bytes to the panel.
//!
//! This function must not be called if the LIDD interface is currently
//! configured to expect DMA transactions.  If DMA was previously used to
//! write to the panel, LCDIDDDMADisable() must be called before this function
//! can be used.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIDDIndexedWrite(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Addr,
                   uint16_t ui16Data)
{
    uint32_t ui32Addr;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));

    //
    // Determine the address register to write.
    //
    ui32Addr = ui32CS ? LCD_O_LIDDCS1ADDR : LCD_O_LIDDCS0ADDR;

    //
    // Write the address.
    //
    HWREG(ui32Base + ui32Addr) = ui16Addr;

    //
    // Determine the data register to write.
    //
    ui32Addr = ui32CS ? LCD_O_LIDDCS1DATA : LCD_O_LIDDCS0DATA;

    //
    // Write the data.
    //
    HWREG(ui32Base + ui32Addr) = ui16Data;
}

//*****************************************************************************
//
//! Reads a status word from the display when the LCD controller is in LIDD
//! mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//!
//! This function reads the 16 bit status word from the display when the LCD
//! controller is in LIDD mode.  A status read occurs with the ALE signal
//! active.  If the interface is configured in Hitachi mode (\b
//! LIDD_CONFIG_ASYNC_HITACHI), this operation corresponds to a command mode
//! read.
//!
//! This function must not be called if the LIDD interface is currently
//! configured to expect DMA transactions.  If DMA was previously used to
//! write to the panel, LCDIDDDMADisable() must be called before this function
//! can be used.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return Returns the status word read from the display panel.
//
//*****************************************************************************
uint16_t
LCDIDDStatusRead(uint32_t ui32Base, uint32_t ui32CS)
{
    uint32_t ui32Reg;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));

    //
    // Determine the register to read based on the CS value supplied.
    //
    ui32Reg = ui32CS ? LCD_O_LIDDCS1ADDR : LCD_O_LIDDCS0ADDR;

    //
    // Read the relevant status register.
    //
    return((uint16_t)HWREG(ui32Base + ui32Reg));
}

//*****************************************************************************
//
//! Reads a data word from the display when the LCD controller is in LIDD
//! mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//!
//! This function reads the 16 bit data word from the display when the LCD
//! controller is in LIDD mode.  A data read occurs with the ALE signal
//! inactive.
//!
//! This function must not be called if the LIDD interface is currently
//! configured to expect DMA transactions.  If DMA was previously used to
//! write to the panel, LCDIDDDMADisable() must be called before this function
//! can be used.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return Returns the status word read from the display panel.
//
//*****************************************************************************
uint16_t
LCDIDDDataRead(uint32_t ui32Base, uint32_t ui32CS)
{
    uint32_t ui32Reg;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));

    //
    // Determine the register to read based on the CS value supplied.
    //
    ui32Reg = ui32CS ? LCD_O_LIDDCS1DATA : LCD_O_LIDDCS0DATA;

    //
    // Read the relevant data register.
    //
    return((uint16_t)HWREG(ui32Base + ui32Reg));
}

//*****************************************************************************
//
//! Reads a given display register when the LCD controller is in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//! \param ui16Addr is the address of the display register to read.
//!
//! This function reads 16 bit word from a register in the display when
//! the LCD controller is in LIDD mode and configured to use either the
//! Motorola (\b LIDD_CONFIG_SYNC_MPU68 or \b LIDD_CONFIG_ASYNC_MPU68) or
//! Intel (\b LIDD_CONFIG_SYNC_MPU80 or \b LIDD_CONFIG_ASYNC_MPU80) modes
//! which employ an external address latch.
//!
//! When configured in Hitachi mode (\b LIDD_CONFIG_ASYNC_HITACHI), this
//! function should not be used.  In this case the functions
//! LCDIDDStatusRead() and LCDIDDDataRead() may be used to read status
//! and data bytes from the panel.
//!
//! This function must not be called if the LIDD interface is currently
//! configured to expect DMA transactions.  If DMA was previously used to
//! write to the panel, LCDIDDDMADisable() must be called before this function
//! can be used.
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return None.
//
//*****************************************************************************
uint16_t
LCDIDDIndexedRead(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Addr)
{
    uint32_t ui32Addr;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));

    //
    // Determine the address register to write.
    //
    ui32Addr = ui32CS ? LCD_O_LIDDCS1ADDR : LCD_O_LIDDCS0ADDR;

    //
    // Write the address.
    //
    HWREG(ui32Base + ui32Addr) = ui16Addr;

    //
    // Determine the data register to read.
    //
    ui32Addr = ui32CS ? LCD_O_LIDDCS1DATA : LCD_O_LIDDCS0DATA;

    //
    // Return the data read.
    //
    return((uint16_t)HWREG(ui32Base + ui32Addr));
}

//*****************************************************************************
//
//! Writes a block of data to the display using DMA when the LCD controller is
//! in LIDD mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32CS specifies the chip select to use. Valid values are 0 and 1.
//! \param pui32Data is the address of the first 16-bit word to write.  This
//! address must be aligned on a 32-bit word boundary.
//! \param ui32Count is the number of 16-bit words to write.  This value must
//! be a multiple of 2.
//!
//! This function writes a block of 16-bit data words to the display using
//! DMA.  It is only valid when the LCD controller is in LIDD mode.
//! Completion of the DMA transfer is signaled by the \b
//! LCD_INT_DMA_DONE interrupt.
//!
//! This function enables DMA mode prior to starting the transfer.  The
//! caller is responsible for ensuring that any earlier DMA transfer has
//! completed before initiating another transfer.
//!
//! During the time that DMA is enabled, none of the other LCD LIDD data
//! transfer functions may be called.  When the DMA transfer is complete and
//! the application wishes to use the CPU to communicate with the display,
//! LCDIDDDMADisable() must be called to disable DMA access prior to calling
//! LCDIDDCommandWrite(), LCDIDDDataWrite(), LCDIDDStatusRead(),
//! LCDIDDIndexedWrite(), LCDIDDIndexedRead() or LCDIDDDataRead().
//!
//! \note CS1 is not available when operating in Sync MPU68 or Sync MPU80
//! modes.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIDDDMAWrite(uint32_t ui32Base, uint32_t ui32CS, const uint32_t *pui32Data,
               uint32_t ui32Count)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32CS == 0) || (ui32CS == 1));
    ASSERT(!((uint32_t)pui32Data & 3));
    ASSERT(!(ui32Count & 1));

    //
    // Make sure DMA is disabled so that enabling it triggers this new
    // transfer.
    //
    HWREG(ui32Base + LCD_O_LIDDCTL) &= ~LCD_LIDDCTL_DMAEN;

    //
    // Set up the transfer.  Note that the ceiling register must contain the
    // address of the last word which contains data we want transfered and NOT
    // the first location after the data we want written.
    //
    HWREG(ui32Base + LCD_O_DMABAFB0) = (uint32_t)pui32Data;
    HWREG(ui32Base + LCD_O_DMACAFB0) = ((uint32_t)pui32Data +
                                        (ui32Count * 2) - 4);

    //
    // Tell the controller which CS to use for the DMA transaction.
    //
    if(!ui32CS)
    {
        //
        // Use CS0.
        //
        HWREG(ui32Base + LCD_O_LIDDCTL) &= ~LCD_LIDDCTL_DMACS;
    }
    else
    {
        //
        // Use CS1.
        //
        HWREG(ui32Base + LCD_O_LIDDCTL) |= LCD_LIDDCTL_DMACS;
    }

    //
    // Enable the DMA engine and start the transaction.
    //
    HWREG(ui32Base + LCD_O_LIDDCTL) |= LCD_LIDDCTL_DMAEN;
}

//*****************************************************************************
//
//! Sets the LCD controller interface timing when in raster mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param ui32Config specifies properties of the raster interface and the
//! attached display panel.
//! \param ui8PalLoadDelay specifies the number of system clocks to wait
//! between each 16 halfword (16-bit) burst when loading the palette from
//! SRAM into the internal palette RAM of the controller.
//!
//! This function configures the basic operating mode of the raster interface
//! and specifies the type of panel that the controller is to drive.
//!
//! The \e ui32Config parameter must defined one of the following to select
//! the required target panel type and output pixel format:
//!
//! - \b RASTER_FMT_ACTIVE_24BPP_PACKED selects an active matrix display
//! and uses a packed 24-bit per pixel packet frame buffer where 4 pixels
//! are described within 3 consecutive 32-bit words.
//! - \b RASTER_FMT_ACTIVE_24BPP_UNPACKED selects an active matrix display
//! and uses an unpacked 24-bit per pixel packet frame buffer where each
//! 32-bit word contains a single pixel and 8 bits of padding.
//! - \b RASTER_FMT_ACTIVE_16BPP selects an active matrix display
//! and uses a 16-bit per pixel frame buffer with 2 pixels in each 32-bit
//! word.
//! - \b RASTER_FMT_ACTIVE_PALETTIZED_12BIT selects an active matrix display
//! and uses a 1, 2, 4 or 8bpp frame buffer with palette lookup.  Output color
//! data is described in 12-bit format using bits 11:0 of the data bus.  The
//! frame buffer pixel format is defined by the value passed in the \e ui32Type
//! parameter to LCDRasterPaletteSet().
//! - \b RASTER_FMT_ACTIVE_PALETTIZED_16BIT selects an active matrix display
//! and uses a 1, 2, 4 or 8bpp frame buffer with palette lookup.  Output color
//! data is described in 16-bit 5:6:5 format.  The frame buffer pixel format is
//! defined by the value passed in the \e ui32Type parameter to
//! LCDRasterPaletteSet().
//! - \b RASTER_FMT_PASSIVE_MONO_4PIX selects a monochrome, passive matrix
//! display which outputs 4 pixels on each pixel clock.
//! - \b RASTER_FMT_PASSIVE_MONO_8PIX selects a monochrome, passive matrix
//! display which outputs 8 pixels on each pixel clock.
//! - \b RASTER_FMT_PASSIVE_COLOR_12BIT selects a passive matrix display
//! and uses a 12bpp frame buffer.  The palette is bypassed and 12-bit pixel
//! data is sent to the grayscaler for the display.
//! - \b RASTER_FMT_PASSIVE_COLOR_16BIT selects a passive matrix display
//! and uses a 16bpp frame buffer with pixels in 5:6:5 format.  Only the 4
//! most significant bits of each color component are sent to the grayscaler
//! for the display.
//!
//! TODO: Awaiting clarification of how RASTER_FMT_PASSIVE_MONO_4PIX and
//! RASTER_FMT_PASSIVE_MONO_8PIX are used.  This is not clear from the current
//! LCD controller specification.
//!
//! Additionally, the following flags may be ORed into \e ui32Config:
//!
//! - \b RASTER_ACTVID_DURING_BLANK sets Actvid to toggle during vertical
//! blanking.
//! - \b RASTER_NIBBLE_MODE_ENABLED enables nibble mode.  This works with
//! \b RASTER_READ_ORDER_REVERSED to determine how 1, 2 and 4bpp pixels are
//! extracted from words read from the frame buffer.  If specified, words
//! read from the frame buffer are byte swapped prior to individual pixels
//! being parsed from them.
//! - \b RASTER_LOAD_DATA_ONLY tells the controller to read only pixel data
//! from the frame buffer and to use the last palette read.  No palette load
//! is performed.
//! - \b RASTER_LOAD_PALETTE_ONLY tells the controller to read only the palette
//! data from the frame buffer.
//! - \b RASTER_READ_ORDER_REVERSED when using 1, 2, 4 and 8bpp frame buffers,
//! this option reverses the order in which frame buffer words are parsed.
//! When this option is specified, the leftmost pixel in a word is taken from
//! the most significant bits.  When absent, the leftmost pixel is parsed from
//! the least significant bits.
//!
//! If the LCD controller's raster engine is enabled when this function is
//! called, it is disabled as a side effect of the call.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterConfigSet(uint32_t ui32Base, uint32_t ui32Config,
                   uint8_t ui8PalLoadDelay)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32Config & ~(RASTER_FMT_ACTIVE_24BPP_PACKED |
                            RASTER_FMT_ACTIVE_24BPP_UNPACKED |
                            RASTER_FMT_ACTIVE_PALETTIZED_12BIT |
                            RASTER_FMT_ACTIVE_PALETTIZED_16BIT |
                            RASTER_FMT_PASSIVE_MONO_4PIX |
                            RASTER_FMT_PASSIVE_MONO_8PIX |
                            RASTER_FMT_PASSIVE_PALETTIZED |
                            RASTER_FMT_PASSIVE_COLOR_12BIT |
                            RASTER_FMT_PASSIVE_COLOR_16BIT |
                            RASTER_ACTVID_DURING_BLANK |
                            RASTER_NIBBLE_MODE_ENABLED |
                            RASTER_LOAD_DATA_ONLY |
                            RASTER_LOAD_PALETTE_ONLY |
                            RASTER_READ_ORDER_REVERSED)));

    //
    // Write the raster control register.
    //
    HWREG(ui32Base + LCD_O_RASTRCTL) = (ui32Config |
                                        ((uint32_t)ui8PalLoadDelay <<
                                         LCD_RASTRCTL_REQDLY_S));
}

//*****************************************************************************
//
//! Sets the LCD controller interface timing when in raster mode.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param pTiming points to a structure containing the desired timing
//! parameters.
//!
//! This function is used in raster mode to set the panel size and sync timing
//! parameters.
//!
//! For a definition of the timing parameters required, see the definition of
//! tLCDRasterTiming.
//!
//! \return None
//
//*****************************************************************************
void
LCDRasterTimingSet(uint32_t ui32Base, const tLCDRasterTiming *pTiming)
{
    uint32_t ui32T0, ui32T1, ui32T2;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(pTiming);
    ASSERT(!(pTiming->ui32Flags & ~(RASTER_TIMING_SYNCS_OPPOSITE_PIXCLK |
                                    RASTER_TIMING_SYNCS_ON_FALLING_PIXCLK |
                                    RASTER_TIMING_SYNCS_ON_RISING_PIXCLK |
                                    RASTER_TIMING_ACTIVE_LOW_OE |
                                    RASTER_TIMING_ACTIVE_LOW_PIXCLK |
                                    RASTER_TIMING_ACTIVE_LOW_HSYNC |
                                    RASTER_TIMING_ACTIVE_LOW_VSYNC)));
    ASSERT(pTiming->ui16PanelWidth && (pTiming->ui16PanelWidth <= 2048) &&
           ((pTiming->ui16PanelWidth % 16) == 0));
    ASSERT(pTiming->ui16PanelHeight && (pTiming->ui16PanelHeight <= 2048));
    ASSERT(pTiming->ui16HFrontPorch && (pTiming->ui16HFrontPorch <= 1024));
    ASSERT(pTiming->ui16HBackPorch && (pTiming->ui16HBackPorch <= 1024));
    ASSERT(pTiming->ui16HSyncWidth && (pTiming->ui16HSyncWidth <= 1024));
    ASSERT(pTiming->ui8VSyncWidth && (pTiming->ui8VSyncWidth <= 64));

    //
    // Construct the values we need for the three raster timing registers.
    //
    ui32T0 = ((uint32_t)((pTiming->ui16HBackPorch - 1) & 0xFF) <<
              LCD_RASTRTIM0_HBP_S) |
             ((uint32_t)((pTiming->ui16HFrontPorch - 1) & 0xFF) <<
              LCD_RASTRTIM0_HFP_S) |
             ((uint32_t)((pTiming->ui16HSyncWidth - 1) & 0x3F) <<
              LCD_RASTRTIM0_HSW_S) |
             (((uint32_t)((pTiming->ui16PanelWidth - 1) & 0x3F0) >> 4) <<
              LCD_RASTRTIM0_PPL_S) |
             (((uint32_t)((pTiming->ui16PanelWidth - 1) & 0x400) >> 10) <<
              LCD_RASTRTIM0_MSBPPL_S);
    ui32T1 = ((uint32_t)pTiming->ui8VBackPorch << LCD_RASTRTIM1_VBP_S) |
             ((uint32_t)pTiming->ui8VFrontPorch << LCD_RASTRTIM1_VFP_S) |
             ((uint32_t)((pTiming->ui8VSyncWidth - 1) & 0x3F) <<
              LCD_RASTRTIM1_VSW_S) |
             ((uint32_t)(pTiming->ui16PanelHeight - 1) & 0x3FF) <<
             LCD_RASTRTIM1_LPP_S;
    ui32T2 = pTiming->ui32Flags |
             ((((pTiming->ui16HSyncWidth - 1) & 0x3C0) >> 6) <<
              LCD_RASTRTIM2_HSW_S) |
             ((((pTiming->ui16PanelHeight - 1) & 0x400) >> 10) <<
              LCD_RASTRTIM2_MSBLPP_S) |
             ((((pTiming->ui16HBackPorch - 1) & 0x300) >> 8) <<
              LCD_RASTRTIM2_MSBHBP_S) |
             ((((pTiming->ui16HFrontPorch - 1) & 0x300) >> 8) <<
              LCD_RASTRTIM2_MSBHFP_S) |
             (pTiming->ui8ACBiasLineCount << LCD_RASTRTIM2_ACBF_S);

    //
    // Write the timing registers, taking care to preserve any existing value
    // in the AC Bias interrupt field of RASTRTIM2.
    //
    HWREG(ui32Base + LCD_O_RASTRTIM0) = ui32T0;
    HWREG(ui32Base + LCD_O_RASTRTIM1) = ui32T1;
    HWREG(ui32Base + LCD_O_RASTRTIM2) = (HWREG(ui32Base + LCD_O_RASTRTIM2) &
                                         LCD_RASTRTIM2_ACBI_M) | ui32T2;
}

//*****************************************************************************
//
//! Sets the number of AC bias pin transitions per interrupt.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8Count is the number of AC bias pin transitions to count before
//! the AC bias count interrupt is asserted.  Valid values are from 0 to 15.
//!
//! This function is used to set the number of AC bias transitions between
//! each AC bias count interrupt (\b LCD_INT_AC_BIAS_CNT).  If \e ui8Count is
//! 0, no AC bias count interrupt is generated.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterACBiasIntCountSet(uint32_t ui32Base, uint8_t ui8Count)
{
    uint32_t ui32Val;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(ui8Count < 16);

    //
    // Get the existing raster timing 2 register value and mask in the new
    // AC Bias interrupt count.
    //
    ui32Val = HWREG(ui32Base + LCD_O_RASTRTIM2);
    ui32Val &= ~LCD_RASTRTIM2_ACBI_M;
    ui32Val |= ((ui8Count << LCD_RASTRTIM2_ACBI_S) & LCD_RASTRTIM2_ACBI_M);

    //
    // Write the new value back to the register.
    //
    HWREG(ui32Base + LCD_O_RASTRTIM2) = ui32Val;
}

//*****************************************************************************
//
//! Enables the raster output.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function enables the LCD controller raster output and starts
//! displaying the content of the current frame buffer on the attached panel.
//! Prior to enabling the raster output, LCDModeSet(), LCDRasterConfigSet(),
//! LCDDMAConfigSet(), LCDRasterTimingSet(), LCDRasterPaletteSet() and
//! LCDRasterFrameBufferSet() must have been called.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterEnable(uint32_t ui32Base)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Reset the module prior to starting the raster.  This is required to
    // ensure correct operation of the raster engine.
    //
    LCDClockReset(ui32Base, LCD_CLOCK_MAIN);

    //
    // Enable the raster engine.
    //
    HWREG(ui32Base + LCD_O_RASTRCTL) |= LCD_RASTRCTL_LCDEN;
}

//*****************************************************************************
//
//! Determines whether or not the raster output is currently enabled.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function may be used to query whether or not the raster output is
//! currently enabled.
//!
//! \return Returns \e true if the raster is enabled or \e false if it is
//! disabled.
//
//*****************************************************************************
bool
LCDRasterEnabled(uint32_t ui32Base)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Return the current raster engine status.
    //
    return((HWREG(ui32Base + LCD_O_RASTRCTL) & LCD_RASTRCTL_LCDEN) ?
           true : false);
}

//*****************************************************************************
//
//! Disables the raster output.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function disables the LCD controller raster output and stops driving
//! the attached display.
//!
//! \note Once disabled, the raster engine continues to scan data until the
//! end of the current frame. If the display is to be re-enabled, this must not
//! be done until after the final \b LCD_INT_RASTER_FRAME_DONE has been
//! received, indicating that the raster engine has stopped.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterDisable(uint32_t ui32Base)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Disable the raster engine.
    //
    HWREG(ui32Base + LCD_O_RASTRCTL) &= ~LCD_RASTRCTL_LCDEN;
}

//*****************************************************************************
//
//! Sets the position and size of the subpanel on the raster display.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Flags may be either \b LCD_SUBPANEL_AT_TOP to show frame buffer
//! image data in the top portion of the display and default color in the
//! bottom portion, or \b LCD_SUBPANEL_AT_BOTTOM to show image data at the
//! bottom of the display and default color at the top.
//! \param ui32BottomLines defines the number of lines comprising the bottom
//! portion of the display.  If \b LCD_SUBPANEL_AT_TOP is set in \e ui32Flags,
//! these lines contain the default pixel color when the subpanel is
//! enabled, otherwise they contain image data.
//! \param ui32DefaultPixel is the 24-bit RGB color to show in the portion of
//! the display not configured to show image data.
//!
//! The LCD controller provides a feature which allows a portion of the display
//! to be filled with a default color rather than image data from the frame
//! buffer. This may be used to reduce SRAM bandwidth requirements since
//! no data is fetched for lines containing the default color.  This feature
//! is only available when the LCD controller is in raster mode and configured
//! to drive an active matrix display.
//!
//! The subpanel area containing image data from the frame buffer may be
//! positioned either at the top or bottom of the display as controlled by
//! the value of \e ui32Flags.  The height of the bottom portion of the display
//! is defined by \e ui32BottomLines.
//!
//! When a subpanel is configured, the application must also reconfigure the
//! frame buffer to ensure that it contains the correct number of lines for
//! the subpanel size in use.  This can be achieved by calling
//! LCDRasterFrameBufferSet() with the \e ui32NumBytes parameter set
//! appropriately to describe the required number of active video lines in
//! the subpanel area.
//!
//! The subpanel display mode is not enabled using this function.  To enable
//! the subpanel once it has been configured, call LCDRasterSubPanelEnable().
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterSubPanelConfigSet(uint32_t ui32Base, uint32_t ui32Flags,
                           uint32_t ui32BottomLines, uint32_t ui32DefaultPixel)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT((ui32Flags == LCD_SUBPANEL_AT_TOP) ||
           (ui32Flags == LCD_SUBPANEL_AT_BOTTOM));
    ASSERT(ui32BottomLines && (ui32BottomLines <= 2048));

    //
    // Adjust the line count into the 0-2047 range.
    //
    ui32BottomLines--;

    //
    // Set the first subpanel configuration register, taking care to leave the
    // subpanel enabled if it already was.
    //
    HWREG(ui32Base + LCD_O_RASTRSUBP1) = (HWREG(ui32Base + LCD_O_RASTRSUBP1) &
                                          LCD_RASTRSUBP1_SPEN) | ui32Flags |
                                         ((ui32DefaultPixel & 0xFFFF) <<
                                          LCD_RASTRSUBP1_DPDLSB_S) |
                                         ((ui32BottomLines <<
                                           LCD_RASTRSUBP1_LPPT_S) &
                                          LCD_RASTRSUBP1_LPPT_M);

    //
    // Set the second subpanel configuration register.
    //
    HWREG(ui32Base + LCD_O_RASTRSUBP2) =
        ((ui32DefaultPixel >> 16) & LCD_RASTRSUBP2_DPDMSB_M) |
        (((ui32BottomLines >> LCD_RASTRSUBP1_LPPT_S) & 1) << 8);
}

//*****************************************************************************
//
//! Enables subpanel display mode.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function enables subpanel display mode and displays a default color
//! rather than image data in the number of lines and at the position specified
//! by a previous call to LCDRasterSubPanelConfigSet().  Prior to calling
//! LCDRasterSubPanelEnable(), the frame buffer should have been reconfigured
//! to match the desired subpanel size using a call to
//! LCDRasterFrameBufferSet().
//!
//! Subpanel display is only possible when the LCD controller is in raster
//! mode and is configured to drive an active matrix display.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterSubPanelEnable(uint32_t ui32Base)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Enable the subpanel.
    //
    HWREG(ui32Base + LCD_O_RASTRSUBP1) |= LCD_RASTRSUBP1_SPEN;
}

//*****************************************************************************
//
//! Disables subpanel display mode.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function disables subpanel display mode and reverts to showing the
//! entire frame buffer image on the display.  After the subpanel is disabled,
//! the frame buffer size must be reconfigured to match the full dimensions of
//! the display area by calling LCDRasterFrameBufferSet() with an appropriate
//! value for the \e ui32NumBytes parameter.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterSubPanelDisable(uint32_t ui32Base)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Disable the subpanel.
    //
    HWREG(ui32Base + LCD_O_RASTRSUBP1) &= ~LCD_RASTRSUBP1_SPEN;
}

//*****************************************************************************
//
//! Configures the LCD controller DMA engine.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Config provides flags defining the desired DMA parameters.
//!
//! This function is used to configure the DMA engine within the LCD
//! controller.  This engine is responsible for performing bulk data transfers
//! to the display when in LIDD mode or for transferring palette and pixel data
//! from SRAM to the display panel when in raster mode.
//!
//! The \e ui32Config parameter is a logical OR of various flags. It must
//! contain one value from each of the following groups.  The first group
//! sets the DMA engine's bus priority with higher numbers representing higher
//! priorities:
//!
//! - \b LCD_DMA_PRIORITY_0
//! - \b LCD_DMA_PRIORITY_1
//! - \b LCD_DMA_PRIORITY_2
//! - \b LCD_DMA_PRIORITY_3
//! - \b LCD_DMA_PRIORITY_4
//! - \b LCD_DMA_PRIORITY_5
//! - \b LCD_DMA_PRIORITY_6
//! - \b LCD_DMA_PRIORITY_7
//!
//! The second group of flags set the number of words that have to be in the
//! FIFO before it signals that it is ready:
//!
//! - \b LCD_DMA_FIFORDY_8_WORDS
//! - \b LCD_DMA_FIFORDY_16_WORDS
//! - \b LCD_DMA_FIFORDY_32_WORDS
//! - \b LCD_DMA_FIFORDY_64_WORDS
//! - \b LCD_DMA_FIFORDY_128_WORDS
//! - \b LCD_DMA_FIFORDY_256_WORDS
//! - \b LCD_DMA_FIFORDY_512_WORDS
//!
//! The third group of flags set the number of 32-bit words in each DMA burst
//! transfer:
//!
//! - \b LCD_DMA_BURST_1
//! - \b LCD_DMA_BURST_2
//! - \b LCD_DMA_BURST_4
//! - \b LCD_DMA_BURST_8
//! - \b LCD_DMA_BURST_16
//!
//! The final group of flags set internal byte lane controls and allows byte
//! swapping within the DMA engine.  The label represents the output byte order
//! for an input 32-bit word ordered ``0123''.
//!
//! - \b LCD_DMA_BYTE_ORDER_0123
//! - \b LCD_DMA_BYTE_ORDER_1023
//! - \b LCD_DMA_BYTE_ORDER_3210
//! - \b LCD_DMA_BYTE_ORDER_2301
//!
//! Additionally, \b LCD_DMA_PING_PONG may be specified.  This flag configures
//! the controller to operate in double-buffered mode.  When data is scanned
//! out from the first frame buffer, the DMA engine immediately moves to
//! the second frame buffer and scan from there before moving back to the
//! first.  If this flag is clear, the DMA engine uses a single frame buffer,
//! restarting the scan from the beginning of the buffer each time it completes
//! a frame.
//!
//! \note DMA burst sizes \b LCD_DMA_BURST_1 and \b LCD_DMA_BURST_2 are only
//! supported when the source data is in external, EPI-connected memory.  If
//! used when the source is internal SRAM, the DMA operation does not complete
//! correctly.
//!
//! \return None.
//
//*****************************************************************************
void
LCDDMAConfigSet(uint32_t ui32Base, uint32_t ui32Config)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32Config & ~(LCD_DMACTL_DMAMSTRP_M | LCD_DMACTL_FIFORDY_M |
                            LCD_DMACTL_BURSTSZ_M | LCD_DMACTL_BYTESWAP |
                            LCD_DMACTL_BIGDEND | LCD_DMACTL_FMODE)));

    //
    // Write the DMA control register.
    //
    HWREG(ui32Base + LCD_O_DMACTL) = ui32Config;
}

//*****************************************************************************
//
//! Initializes the color palette in a frame buffer.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32Type specifies the type of pixel data to be held in the frame
//! buffer and also the format of the source color values passed.
//! \param pui32Addr points to the start of the frame buffer into which the
//! palette information is to be written.
//! \param pui32SrcColors points to the first color value which is to be
//! written into the frame buffer palette.
//! \param ui32Start specifies the index of the first color in the palette
//! to update.
//! \param ui32Count specifies the number of source colors to be copied into
//! the frame buffer palette.
//!
//! This function is used to initialize the color palette stored at the
//! beginning of a frame buffer.  It writes the relevant pixel type into the
//! first entry of the frame buffer and copies the requested number of colors
//! from a source buffer into the palette starting at the required index,
//! optionally converting them from 24-bit color format into the 12-bit format
//! used by the LCD controller.
//!
//! \e ui32Type must be set to one of the following values to indicate the
//! type of frame buffer whose palette is being initialized:
//!
//! - \b LCD_PALETTE_TYPE_1BPP configures this as a 1 bit per pixel
//! (monochrome) frame buffer.  This format requires a 2 entry palette.
//! - \b LCD_PALETTE_TYPE_2BPP configures this as a 2 bit per pixel frame
//! buffer. This format requires a 4 entry palette.
//! - \b LCD_PALETTE_TYPE_4BPP configures this as a 4 bit per pixel frame
//! buffer. This format requires a 4 entry palette.
//! - \b LCD_PALETTE_TYPE_8BPP configures this as an 8 bit per pixel frame
//! buffer. This format requires a 256 entry palette.
//! - \b LCD_PALETTE_TYPE_DIRECT configures this as a direct color (12, 16 or
//! 24 bit per pixel).  The color palette is not used in these modes but the
//! frame buffer type must still be initialized to ensure that the hardware
//! uses the correct pixel type.  When this value is used, the format of the
//! pixels in the frame buffer is defined by the \e ui32Config parameter
//! previously passed to LCDRasterConfigSet().
//!
//! Optionally, the \b LCD_PALETTE_SRC_24BIT flag may be ORed into \e ui32Type
//! to indicate that the supplied colors in the \e pui32SrcColors array are in
//! the 24-bit format as used by the TivaWare Graphics Library with one color
//! stored in each 32-bit word.  In this case, the colors read from the source
//! array are converted to the 12-bit format used by the LCD controller before
//! being written into the frame buffer palette.
//!
//! If \b LCD_PALETTE_SRC_24BIT is not present, it is assumed that the
//! \e pui32SrcColors array contains 12-bit colors in the format required by
//! the LCD controller with 2 colors stored in each 32-bit word.  In this case
//! the values are copied directly into the frame buffer palette without any
//! reformatting.
//!
//! \return None.
//
//*****************************************************************************
void
LCDRasterPaletteSet(uint32_t ui32Base, uint32_t ui32Type, uint32_t *pui32Addr,
                    const uint32_t *pui32SrcColors, uint32_t ui32Start,
                    uint32_t ui32Count)
{
    uint16_t *pui16Pal;
    uint16_t *pui16Src;
    uint32_t ui32Loop;

    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(ui32Start < 256);
    ASSERT((ui32Start + ui32Count) <= 256);
    ASSERT(pui32Addr);
    ASSERT(pui32SrcColors);
    ASSERT(!(ui32Type & ~(LCD_PALETTE_SRC_24BIT | LCD_PALETTE_TYPE_DIRECT |
                          LCD_PALETTE_TYPE_8BPP | LCD_PALETTE_TYPE_4BPP |
                          LCD_PALETTE_TYPE_2BPP | LCD_PALETTE_TYPE_1BPP)));

    //
    // Get a pointer to the start of the palette.
    //
    pui16Pal = (uint16_t *)pui32Addr;

    //
    // Are we converting the palette color format?
    //
    if(ui32Type & LCD_PALETTE_SRC_24BIT)
    {
        //
        // Yes - loop through each of the supplied 24-bit colors converting
        // and storing each.
        //
        ui32Loop = 0;
        while(ui32Count)
        {
            pui16Pal[ui32Start + ui32Loop] =
                PAL_FROM_RGB(pui32SrcColors[ui32Loop]);
            ui32Loop++;
            ui32Count--;
        }
    }
    else
    {
        //
        // No - loop through the supplied 12-bit colors storing each.
        //

        pui16Src = (uint16_t *)pui32SrcColors;
        while(ui32Count)
        {
            pui16Pal[ui32Start] = pui16Src[ui32Start];
            ui32Start++;
            ui32Count--;
        }
    }

    //
    // Write the pixel type into the first palette entry.
    //
    pui16Pal[0] &= ~(LCD_PALETTE_TYPE_8BPP | LCD_PALETTE_TYPE_DIRECT);
    pui16Pal[0] |= (ui32Type & ~LCD_PALETTE_SRC_24BIT);
}

//*****************************************************************************
//
//! Sets the LCD controller frame buffer start address and size in raster mode.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui8Buffer specifies which frame buffer to configure.  Valid values
//! are 0 and 1.
//! \param pui32Addr points to the first byte of the frame buffer.  This
//! pointer must be aligned on a 32-bit (word) boundary.
//! \param ui32NumBytes specifies the size of the frame buffer in bytes.  This
//! value must be a multiple of 4.
//!
//! This function is used to configure the position and size of one of the
//! two supported frame buffers while in raster mode.  The second frame buffer
//! (configured when ui8Buffer is set to 1) is only used if the controller
//! is set to operate in ping-pong mode (by specifying the \b LCD_DMA_PING_PONG
//! configuration flag on a call to LCDDMAConfigSet()).
//!
//! The format of the frame buffer depends upon the image type in use and
//! the current raster configuration settings.  If \b RASTER_LOAD_DATA_ONLY
//! was specified in a previous call to LCDRasterConfigSet(), the frame buffer
//! contains only packed pixel data in the required bit depth and format.
//! In other cases, the frame buffer comprises a palette of either 8 or 128
//! 32-bit words followed by the packed pixel data.  The palette size is 8
//! words (16 16-bit entries) for all pixel formats other than 8bpp which
//! uses a palette of 128 words (256 16-bit entries).  Note that the 8 word
//! palette is still present even for 12, 16 and 24-bit formats which do not
//! use the lookup table.
//!
//! The frame buffer size, specified using the \e ui32NumBytes parameter, must
//! be the palette size (if any) plus the size of the image bitmap required
//! for the currently configured display resolution.
//!
//! \e ui32NumBytes = (Palette Size) + ((Width * Height) * BPP) / 8)
//!
//! If \b RASTER_LOAD_DATA_ONLY is not specified, frame buffers passed to this
//! function must be initialized using a call to LCDRasterPaletteSet() prior to
//! enabling the raster output.  If this is not done, the pixel format
//! identifier and color table required by the hardware is not present
//! and the results are unpredictable.
//!
//! \return None.
//*****************************************************************************
void
LCDRasterFrameBufferSet(uint32_t ui32Base, uint8_t ui8Buffer,
                        uint32_t *pui32Addr, uint32_t ui32NumBytes)
{
    //
    // Sanity check parameters.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!((uint32_t)pui32Addr & 3));
    ASSERT(!(ui32NumBytes & 3));
    ASSERT(ui8Buffer < 2);

    //
    // Are we setting the values for frame buffer 0?
    //
    if(!ui8Buffer)
    {
        //
        // Yes - set the registers for frame buffer 0.
        //
        HWREG(ui32Base + LCD_O_DMABAFB0) = (uint32_t)pui32Addr;
        HWREG(ui32Base + LCD_O_DMACAFB0) = (uint32_t)pui32Addr +
                                           ui32NumBytes - 4;
    }
    else
    {
        //
        // No - set the registers for frame buffer 1.
        //
        HWREG(ui32Base + LCD_O_DMABAFB1) = (uint32_t)pui32Addr;
        HWREG(ui32Base + LCD_O_DMACAFB1) = (uint32_t)pui32Addr +
                                           ui32NumBytes - 4;
    }
}

//*****************************************************************************
//
//! Enables individual LCD controller interrupt sources.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated LCD controller interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b LCD_INT_DMA_DONE - This interrupt indicates that a LIDD DMA
//! transfer is complete.
//! - \b LCD_INT_RASTER_FRAME_DONE - This interrupt indicates that a
//! raster-mode frame is complete.
//! - \b LCD_INT_SYNC_LOST - This interrupt indicates that frame
//! synchronization was lost.
//! - \b LCD_INT_AC_BIAS_CNT - This interrupt is valid for passive matrix
//! panels only and indicates that that AC bias transition counter has
//! decremented to zero. The counter, set by a call to
//! LCDRasterACBiasIntCountSet(), is reloaded but remains disabled until this
//! interrupt is cleared.
//! - \b LCD_INT_UNDERFLOW - This interrupt indicates that a data underflow
//! occurred. The internal FIFO was empty when the output logic attempted to
//! read data to send to the display.
//! - \b LCD_INT_PAL_LOAD - This interrupt indicates that the color palette
//! has been loaded.
//! - \b LCD_INT_EOF0 - This interrupt indicates that the raw End-of-Frame 0
//! has been signaled.
//! - \b LCD_INT_EOF1 - This interrupt indicates that the raw End-of-Frame 1
//! has been signaled.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32IntFlags & ~(LCD_INT_DMA_DONE | LCD_INT_SYNC_LOST |
                              LCD_INT_AC_BIAS_CNT | LCD_INT_UNDERFLOW |
                              LCD_INT_PAL_LOAD | LCD_INT_EOF0 | LCD_INT_EOF1 |
                              LCD_INT_RASTER_FRAME_DONE)));

    //
    // Enable the interrupt sources by setting the appropriate bits in the
    // mask register.
    //
    HWREG(ui32Base + LCD_O_IM) = ui32IntFlags;
}

//*****************************************************************************
//
//! Disables individual LCD controller interrupt sources.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be
//! disabled.
//!
//! This function disables the indicated LCD controller interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b LCD_INT_DMA_DONE - This interrupt indicates that a LIDD DMA
//! transfer is complete.
//! - \b LCD_INT_RASTER_FRAME_DONE - This interrupt indicates that a
//! raster-mode frame is complete.
//! - \b LCD_INT_SYNC_LOST - This interrupt indicates that frame
//! synchronization was lost.
//! - \b LCD_INT_AC_BIAS_CNT - This interrupt is valid for passive matrix
//! panels only and indicates that that AC bias transition counter has
//! decremented to zero. The counter, set by a call to
//! LCDRasterACBiasIntCountSet(), is reloaded but remains disabled until this
//! interrupt is cleared.
//! - \b LCD_INT_UNDERFLOW - This interrupt indicates that a data underflow
//! occurred. The internal FIFO was empty when the output logic attempted to
//! read data to send to the display.
//! - \b LCD_INT_PAL_LOAD - This interrupt indicates that the color palette
//! has been loaded.
//! - \b LCD_INT_EOF0 - This interrupt indicates that the raw End-of-Frame 0
//! has been signaled.
//! - \b LCD_INT_EOF2 - This interrupt indicates that the raw End-of-Frame 1
//! has been signaled.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32IntFlags & ~(LCD_INT_DMA_DONE | LCD_INT_SYNC_LOST |
                              LCD_INT_AC_BIAS_CNT | LCD_INT_UNDERFLOW |
                              LCD_INT_PAL_LOAD | LCD_INT_EOF0 | LCD_INT_EOF1 |
                              LCD_INT_RASTER_FRAME_DONE)));

    //
    // Disable the interrupt sources by clearing the appropriate bits in the
    // mask register.
    //
    HWREG(ui32Base + LCD_O_IENC) = ui32IntFlags;
}

//*****************************************************************************
//
//! Gets the current LCD controller interrupt status.
//!
//! \param ui32Base is the base address of the controller.
//! \param bMasked is false if the raw interrupt status is required and true
//! if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the LCD controller.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status as the logical OR of any of
//! the following:
//!
//! - \b LCD_INT_DMA_DONE - This interrupt indicates that a LIDD DMA
//! transfer is complete.
//! - \b LCD_INT_RASTER_FRAME_DONE - This interrupt indicates that a
//! raster-mode frame is complete.
//! - \b LCD_INT_SYNC_LOST - This interrupt indicates that frame
//! synchronization was lost.
//! - \b LCD_INT_AC_BIAS_CNT - This interrupt is valid for passive matrix
//! panels only and indicates that that AC bias transition counter has
//! decremented to zero. The counter, set by a call to
//! LCDRasterACBiasIntCountSet(), is reloaded but remains disabled until this
//! interrupt is cleared.
//! - \b LCD_INT_UNDERFLOW - This interrupt indicates that a data underflow
//! occurred. The internal FIFO was empty when the output logic attempted to
//! read data to send to the display.
//! - \b LCD_INT_PAL_LOAD - This interrupt indicates that the color palette
//! has been loaded.
//! - \b LCD_INT_EOF0 - This interrupt indicates that the raw End-of-Frame 0
//! has been signaled.
//! - \b LCD_INT_EOF2 - This interrupt indicates that the raw End-of-Frame 1
//! has been signaled.
//
//*****************************************************************************
uint32_t
LCDIntStatus(uint32_t ui32Base, bool bMasked)
{
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Were we asked for the masked or raw interrupt status?
    //
    if(bMasked)
    {
        //
        // Return the masked interrupt status.
        //
        return(HWREG(ui32Base + LCD_O_MISCLR));
    }
    else
    {
        //
        // Return the raw interrupts status.
        //
        return(HWREG(ui32Base + LCD_O_RISSET));
    }
}

//*****************************************************************************
//
//! Clears LCD controller interrupt sources.
//!
//! \param ui32Base is the base address of the controller.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified LCD controller interrupt sources are cleared so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep the interrupt from being triggered again immediately upon exit.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b LCD_INT_DMA_DONE - This interrupt indicates that a LIDD DMA
//! transfer is complete.
//! - \b LCD_INT_RASTER_FRAME_DONE - This interrupt indicates that a
//! raster-mode frame is complete.
//! - \b LCD_INT_SYNC_LOST - This interrupt indicates that frame
//! synchronization was lost.
//! - \b LCD_INT_AC_BIAS_CNT - This interrupt is valid for passive matrix
//! panels only and indicates that that AC bias transition counter has
//! decremented to zero. The counter, set by a call to
//! LCDRasterACBiasIntCountSet(), is reloaded but remains disabled until this
//! interrupt is cleared.
//! - \b LCD_INT_UNDERFLOW - This interrupt indicates that a data underflow
//! occurred. The internal FIFO was empty when the output logic attempted to
//! read data to send to the display.
//! - \b LCD_INT_PAL_LOAD - This interrupt indicates that the color palette
//! has been loaded.
//! - \b LCD_INT_EOF0 - This interrupt indicates that the raw End-of-Frame 0
//! has been signaled.
//! - \b LCD_INT_EOF2 - This interrupt indicates that the raw End-of-Frame 1
//! has been signaled.
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
LCDIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(!(ui32IntFlags & ~(LCD_INT_DMA_DONE | LCD_INT_SYNC_LOST |
                              LCD_INT_AC_BIAS_CNT | LCD_INT_UNDERFLOW |
                              LCD_INT_PAL_LOAD | LCD_INT_EOF0 | LCD_INT_EOF1 |
                              LCD_INT_RASTER_FRAME_DONE)));

    //
    // Clear the requested interrupts.
    //
    HWREG(ui32Base + LCD_O_MISCLR) = ui32IntFlags;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the LCD controller module.
//!
//! \param ui32Base specifies the LCD controller module base address.
//! \param pfnHandler is a pointer to the function to be called when the LCD
//! controller interrupt occurs.
//!
//! This function registers the handler to be called when the LCD controller
//! module interrupt occurs.
//!
//! \note This function need not be called if the appropriate interrupt vector
//! is statically linked into the vector table in the application startup code.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == LCD0_BASE);
    ASSERT(pfnHandler);

    //
    // Register the interrupt handler.
    //
    IntRegister(INT_LCD0_SNOWFLAKE, pfnHandler);

    //
    // Enable the interrupt in the interrupt controller.
    //
    IntEnable(INT_LCD0_SNOWFLAKE);
}

//*****************************************************************************
//
//! Unregisters the interrupt handler for the LCD controller module.
//!
//! \param ui32Base specifies the LCD controller module base address.
//!
//! This function unregisters the interrupt handler and disables the global LCD
//! controller interrupt in the interrupt controller.
//!
//! \note This function need not be called if the appropriate interrupt vector
//! is statically linked into the vector table in the application startup code.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
LCDIntUnregister(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == LCD0_BASE);

    //
    // Disable the interrupt in the interrupt controller.
    //
    IntDisable(INT_LCD0_SNOWFLAKE);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_LCD0_SNOWFLAKE);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
