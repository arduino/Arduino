//*****************************************************************************
//
// uart.c - Driver for the UART.
//
// Copyright (c) 2005-2013 Texas Instruments Incorporated.  All rights reserved.
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
//! \addtogroup uart_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"

//*****************************************************************************
//
// The system clock divider defining the maximum baud rate supported by the
// UART.
//
//*****************************************************************************
#define UART_CLK_DIVIDER        8

//*****************************************************************************
//
// A mapping of UART base address to interrupt number.
//
//*****************************************************************************
static const uint32_t g_ppui32UARTIntMap[][2] =
{
    { UART0_BASE, INT_UART0_BLIZZARD },
    { UART1_BASE, INT_UART1_BLIZZARD },
    { UART2_BASE, INT_UART2_BLIZZARD },
    { UART3_BASE, INT_UART3_BLIZZARD },
    { UART4_BASE, INT_UART4_BLIZZARD },
    { UART5_BASE, INT_UART5_BLIZZARD },
    { UART6_BASE, INT_UART6_BLIZZARD },
    { UART7_BASE, INT_UART7_BLIZZARD },
};
static const uint_fast8_t g_ui8UARTIntMapRows =
    sizeof(g_ppui32UARTIntMap) / sizeof(g_ppui32UARTIntMap[0]);
static const uint32_t g_ppui32UARTIntMapSnowflake[][2] =
{
    { UART0_BASE, INT_UART0_SNOWFLAKE },
    { UART1_BASE, INT_UART1_SNOWFLAKE },
    { UART2_BASE, INT_UART2_SNOWFLAKE },
    { UART3_BASE, INT_UART3_SNOWFLAKE },
    { UART4_BASE, INT_UART4_SNOWFLAKE },
    { UART5_BASE, INT_UART5_SNOWFLAKE },
    { UART6_BASE, INT_UART6_SNOWFLAKE },
    { UART7_BASE, INT_UART7_SNOWFLAKE },
};
static const uint_fast8_t g_ui8UARTIntMapRowsSnowflake =
    sizeof(g_ppui32UARTIntMapSnowflake) /
    sizeof(g_ppui32UARTIntMapSnowflake[0]);

//*****************************************************************************
//
//! \internal
//! Checks a UART base address.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function determines if a UART port base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_UARTBaseValid(uint32_t ui32Base)
{
    return((ui32Base == UART0_BASE) || (ui32Base == UART1_BASE) ||
           (ui32Base == UART2_BASE) || (ui32Base == UART3_BASE) ||
           (ui32Base == UART4_BASE) || (ui32Base == UART5_BASE) ||
           (ui32Base == UART6_BASE) || (ui32Base == UART7_BASE));
}
#endif

//*****************************************************************************
//
//! \internal
//! Gets the UART interrupt number.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! Given a UART base address, this function returns the corresponding
//! interrupt number.
//!
//! \return Returns a UART interrupt number, or 0 if \e ui32Base is invalid.
//
//*****************************************************************************
static uint32_t
_UARTIntNumberGet(uint32_t ui32Base)
{
    uint_fast8_t ui8Idx, ui8Rows;
    const uint32_t (*ppui32UARTIntMap)[2];

    //
    // Default interrupt map.
    //
    ppui32UARTIntMap = g_ppui32UARTIntMap;
    ui8Rows = g_ui8UARTIntMapRows;

    if(CLASS_IS_SNOWFLAKE)
    {
        ppui32UARTIntMap = g_ppui32UARTIntMapSnowflake;
        ui8Rows = g_ui8UARTIntMapRowsSnowflake;
    }

    //
    // Loop through the table that maps UART base addresses to interrupt
    // numbers.
    //
    for(ui8Idx = 0; ui8Idx < ui8Rows; ui8Idx++)
    {
        //
        // See if this base address matches.
        //
        if(ppui32UARTIntMap[ui8Idx][0] == ui32Base)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(ppui32UARTIntMap[ui8Idx][1]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(0);
}

//*****************************************************************************
//
//! Sets the type of parity.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32Parity specifies the type of parity to use.
//!
//! This function configures the type of parity to use for transmitting and
//! expect when receiving.  The \e ui32Parity parameter must be one of
//! \b UART_CONFIG_PAR_NONE, \b UART_CONFIG_PAR_EVEN, \b UART_CONFIG_PAR_ODD,
//! \b UART_CONFIG_PAR_ONE, or \b UART_CONFIG_PAR_ZERO.  The last two
//! parameters allow direct control of the parity bit; it is always either one
//! or zero based on the mode.
//!
//! \return None.
//
//*****************************************************************************
void
UARTParityModeSet(uint32_t ui32Base, uint32_t ui32Parity)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));
    ASSERT((ui32Parity == UART_CONFIG_PAR_NONE) ||
           (ui32Parity == UART_CONFIG_PAR_EVEN) ||
           (ui32Parity == UART_CONFIG_PAR_ODD) ||
           (ui32Parity == UART_CONFIG_PAR_ONE) ||
           (ui32Parity == UART_CONFIG_PAR_ZERO));

    //
    // Set the parity mode.
    //
    HWREG(ui32Base + UART_O_LCRH) = ((HWREG(ui32Base + UART_O_LCRH) &
                                      ~(UART_LCRH_SPS | UART_LCRH_EPS |
                                        UART_LCRH_PEN)) | ui32Parity);
}

//*****************************************************************************
//
//! Gets the type of parity currently being used.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function gets the type of parity used for transmitting data and
//! expected when receiving data.
//!
//! \return Returns the current parity settings, specified as one of
//! \b UART_CONFIG_PAR_NONE, \b UART_CONFIG_PAR_EVEN, \b UART_CONFIG_PAR_ODD,
//! \b UART_CONFIG_PAR_ONE, or \b UART_CONFIG_PAR_ZERO.
//
//*****************************************************************************
uint32_t
UARTParityModeGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return the current parity setting.
    //
    return(HWREG(ui32Base + UART_O_LCRH) &
           (UART_LCRH_SPS | UART_LCRH_EPS | UART_LCRH_PEN));
}

//*****************************************************************************
//
//! Sets the FIFO level at which interrupts are generated.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32TxLevel is the transmit FIFO interrupt level, specified as one
//! of \b UART_FIFO_TX1_8, \b UART_FIFO_TX2_8, \b UART_FIFO_TX4_8,
//! \b UART_FIFO_TX6_8, or \b UART_FIFO_TX7_8.
//! \param ui32RxLevel is the receive FIFO interrupt level, specified as one of
//! \b UART_FIFO_RX1_8, \b UART_FIFO_RX2_8, \b UART_FIFO_RX4_8,
//! \b UART_FIFO_RX6_8, or \b UART_FIFO_RX7_8.
//!
//! This function configures the FIFO level at which transmit and receive
//! interrupts are generated.
//!
//! \return None.
//
//*****************************************************************************
void
UARTFIFOLevelSet(uint32_t ui32Base, uint32_t ui32TxLevel,
                 uint32_t ui32RxLevel)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));
    ASSERT((ui32TxLevel == UART_FIFO_TX1_8) ||
           (ui32TxLevel == UART_FIFO_TX2_8) ||
           (ui32TxLevel == UART_FIFO_TX4_8) ||
           (ui32TxLevel == UART_FIFO_TX6_8) ||
           (ui32TxLevel == UART_FIFO_TX7_8));
    ASSERT((ui32RxLevel == UART_FIFO_RX1_8) ||
           (ui32RxLevel == UART_FIFO_RX2_8) ||
           (ui32RxLevel == UART_FIFO_RX4_8) ||
           (ui32RxLevel == UART_FIFO_RX6_8) ||
           (ui32RxLevel == UART_FIFO_RX7_8));

    //
    // Set the FIFO interrupt levels.
    //
    HWREG(ui32Base + UART_O_IFLS) = ui32TxLevel | ui32RxLevel;
}

//*****************************************************************************
//
//! Gets the FIFO level at which interrupts are generated.
//!
//! \param ui32Base is the base address of the UART port.
//! \param pui32TxLevel is a pointer to storage for the transmit FIFO level,
//! returned as one of \b UART_FIFO_TX1_8, \b UART_FIFO_TX2_8,
//! \b UART_FIFO_TX4_8, \b UART_FIFO_TX6_8, or \b UART_FIFO_TX7_8.
//! \param pui32RxLevel is a pointer to storage for the receive FIFO level,
//! returned as one of \b UART_FIFO_RX1_8, \b UART_FIFO_RX2_8,
//! \b UART_FIFO_RX4_8, \b UART_FIFO_RX6_8, or \b UART_FIFO_RX7_8.
//!
//! This function gets the FIFO level at which transmit and receive interrupts
//! are generated.
//!
//! \return None.
//
//*****************************************************************************
void
UARTFIFOLevelGet(uint32_t ui32Base, uint32_t *pui32TxLevel,
                 uint32_t *pui32RxLevel)
{
    uint32_t ui32Temp;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Read the FIFO level register.
    //
    ui32Temp = HWREG(ui32Base + UART_O_IFLS);

    //
    // Extract the transmit and receive FIFO levels.
    //
    *pui32TxLevel = ui32Temp & UART_IFLS_TX_M;
    *pui32RxLevel = ui32Temp & UART_IFLS_RX_M;
}

//*****************************************************************************
//
//! Sets the configuration of a UART.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32UARTClk is the rate of the clock supplied to the UART module.
//! \param ui32Baud is the desired baud rate.
//! \param ui32Config is the data format for the port (number of data bits,
//! number of stop bits, and parity).
//!
//! This function configures the UART for operation in the specified data
//! format.  The baud rate is provided in the \e ui32Baud parameter and the
//! data format in the \e ui32Config parameter.
//!
//! The \e ui32Config parameter is the logical OR of three values: the number
//! of data bits, the number of stop bits, and the parity.
//! \b UART_CONFIG_WLEN_8, \b UART_CONFIG_WLEN_7, \b UART_CONFIG_WLEN_6, and
//! \b UART_CONFIG_WLEN_5 select from eight to five data bits per byte
//! (respectively).  \b UART_CONFIG_STOP_ONE and \b UART_CONFIG_STOP_TWO select
//! one or two stop bits (respectively).  \b UART_CONFIG_PAR_NONE,
//! \b UART_CONFIG_PAR_EVEN, \b UART_CONFIG_PAR_ODD, \b UART_CONFIG_PAR_ONE,
//! and \b UART_CONFIG_PAR_ZERO select the parity mode (no parity bit, even
//! parity bit, odd parity bit, parity bit always one, and parity bit always
//! zero, respectively).
//!
//! The peripheral clock is the same as the processor clock.  The frequency of
//! the system clock is the value returned by SysCtlClockGet(), or it can be
//! explicitly hard coded if it is constant and known (to save the
//! code/execution overhead of a call to SysCtlClockGet()).
//!
//! For Tiva parts that have the ability to specify the UART baud clock
//! source (via UARTClockSourceSet()), the peripheral clock can be changed to
//! PIOSC.  In this case, the peripheral clock should be specified as
//! 16,000,000 (the nominal rate of PIOSC).
//!
//! \return None.
//
//*****************************************************************************
void
UARTConfigSetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk,
                    uint32_t ui32Baud, uint32_t ui32Config)
{
    uint32_t ui32Div;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));
    ASSERT(ui32Baud != 0);
    ASSERT(ui32UARTClk >= (ui32Baud * UART_CLK_DIVIDER));

    //
    // Stop the UART.
    //
    UARTDisable(ui32Base);

    //
    // Is the required baud rate greater than the maximum rate supported
    // without the use of high speed mode?
    //
    if((ui32Baud * 16) > ui32UARTClk)
    {
        //
        // Enable high speed mode.
        //
        HWREG(ui32Base + UART_O_CTL) |= UART_CTL_HSE;

        //
        // Half the supplied baud rate to compensate for enabling high speed
        // mode.  This allows the following code to be common to both cases.
        //
        ui32Baud /= 2;
    }
    else
    {
        //
        // Disable high speed mode.
        //
        HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_HSE);
    }

    //
    // Compute the fractional baud rate divider.
    //
    ui32Div = (((ui32UARTClk * 8) / ui32Baud) + 1) / 2;

    //
    // Set the baud rate.
    //
    HWREG(ui32Base + UART_O_IBRD) = ui32Div / 64;
    HWREG(ui32Base + UART_O_FBRD) = ui32Div % 64;

    //
    // Set parity, data length, and number of stop bits.
    //
    HWREG(ui32Base + UART_O_LCRH) = ui32Config;

    //
    // Clear the flags register.
    //
    HWREG(ui32Base + UART_O_FR) = 0;

    //
    // Start the UART.
    //
    UARTEnable(ui32Base);
}

//*****************************************************************************
//
//! Gets the current configuration of a UART.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32UARTClk is the rate of the clock supplied to the UART module.
//! \param pui32Baud is a pointer to storage for the baud rate.
//! \param pui32Config is a pointer to storage for the data format.
//!
//! This function determines the baud rate and data format for the UART, given
//! an explicitly provided peripheral clock (hence the ExpClk suffix).  The
//! returned baud rate is the actual baud rate; it may not be the exact baud
//! rate requested or an ``official'' baud rate.  The data format returned in
//! \e pui32Config is enumerated the same as the \e ui32Config parameter of
//! UARTConfigSetExpClk().
//!
//! The peripheral clock is the same as the processor clock.  The frequency of
//! the system clock is the value returned by SysCtlClockGet(), or it can be
//! explicitly hard coded if it is constant and known (to save the
//! code/execution overhead of a call to SysCtlClockGet()).
//!
//! For Tiva parts that have the ability to specify the UART baud clock
//! source (via UARTClockSourceSet()), the peripheral clock can be changed to
//! PIOSC.  In this case, the peripheral clock should be specified as
//! 16,000,000 (the nominal rate of PIOSC).
//!
//! \return None.
//
//*****************************************************************************
void
UARTConfigGetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk,
                    uint32_t *pui32Baud, uint32_t *pui32Config)
{
    uint32_t ui32Int, ui32Frac;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Compute the baud rate.
    //
    ui32Int = HWREG(ui32Base + UART_O_IBRD);
    ui32Frac = HWREG(ui32Base + UART_O_FBRD);
    *pui32Baud = (ui32UARTClk * 4) / ((64 * ui32Int) + ui32Frac);

    //
    // See if high speed mode enabled.
    //
    if(HWREG(ui32Base + UART_O_CTL) & UART_CTL_HSE)
    {
        //
        // High speed mode is enabled so the actual baud rate is actually
        // double what was just calculated.
        //
        *pui32Baud *= 2;
    }

    //
    // Get the parity, data length, and number of stop bits.
    //
    *pui32Config = (HWREG(ui32Base + UART_O_LCRH) &
                    (UART_LCRH_SPS | UART_LCRH_WLEN_M | UART_LCRH_STP2 |
                     UART_LCRH_EPS | UART_LCRH_PEN));
}

//*****************************************************************************
//
//! Enables transmitting and receiving.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function enables the UART and its transmit and receive FIFOs.
//!
//! \return None.
//
//*****************************************************************************
void
UARTEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Enable the FIFO.
    //
    HWREG(ui32Base + UART_O_LCRH) |= UART_LCRH_FEN;

    //
    // Enable RX, TX, and the UART.
    //
    HWREG(ui32Base + UART_O_CTL) |= (UART_CTL_UARTEN | UART_CTL_TXE |
                                     UART_CTL_RXE);
}

//*****************************************************************************
//
//! Disables transmitting and receiving.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function disables the UART, waits for the end of transmission of the
//! current character, and flushes the transmit FIFO.
//!
//! \return None.
//
//*****************************************************************************
void
UARTDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Wait for end of TX.
    //
    while(HWREG(ui32Base + UART_O_FR) & UART_FR_BUSY)
    {
    }

    //
    // Disable the FIFO.
    //
    HWREG(ui32Base + UART_O_LCRH) &= ~(UART_LCRH_FEN);

    //
    // Disable the UART.
    //
    HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_UARTEN | UART_CTL_TXE |
                                      UART_CTL_RXE);
}

//*****************************************************************************
//
//! Enables the transmit and receive FIFOs.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This functions enables the transmit and receive FIFOs in the UART.
//!
//! \return None.
//
//*****************************************************************************
void
UARTFIFOEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Enable the FIFO.
    //
    HWREG(ui32Base + UART_O_LCRH) |= UART_LCRH_FEN;
}

//*****************************************************************************
//
//! Disables the transmit and receive FIFOs.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function disables the transmit and receive FIFOs in the UART.
//!
//! \return None.
//
//*****************************************************************************
void
UARTFIFODisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Disable the FIFO.
    //
    HWREG(ui32Base + UART_O_LCRH) &= ~(UART_LCRH_FEN);
}

//*****************************************************************************
//
//! Enables SIR (IrDA) mode on the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//! \param bLowPower indicates if SIR Low Power Mode is to be used.
//!
//! This function enables SIR (IrDA) mode on the UART.  If the \e bLowPower
//! flag is set, then SIR low power mode will be selected as well.  This
//! function only has an effect if the UART has not been enabled by a call to
//! UARTEnable().  The call UARTEnableSIR() must be made before a call to
//! UARTConfigSetExpClk() because the UARTConfigSetExpClk() function calls the
//! UARTEnable() function.  Another option is to call UARTDisable() followed by
//! UARTEnableSIR() and then enable the UART by calling UARTEnable().
//!
//! \note The availability of SIR (IrDA) operation varies with the Tiva
//! part in use.  Please consult the datasheet for the part you are using to
//! determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTEnableSIR(uint32_t ui32Base, bool bLowPower)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Enable SIR and SIRLP (if appropriate).
    //
    if(bLowPower)
    {
        HWREG(ui32Base + UART_O_CTL) |= (UART_CTL_SIREN | UART_CTL_SIRLP);
    }
    else
    {
        HWREG(ui32Base + UART_O_CTL) |= (UART_CTL_SIREN);
    }
}

//*****************************************************************************
//
//! Disables SIR (IrDA) mode on the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function disables SIR(IrDA) mode on the UART.  This function only has
//! an effect if the UART has not been enabled by a call to UARTEnable().  The
//! call UARTEnableSIR() must be made before a call to UARTConfigSetExpClk()
//! because the UARTConfigSetExpClk() function calls the UARTEnable() function.
//! Another option is to call UARTDisable() followed by UARTEnableSIR() and
//! then enable the UART by calling UARTEnable().
//!
//! \note The availability of SIR (IrDA) operation varies with the Tiva
//! part in use.  Please consult the datasheet for the part you are using to
//! determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTDisableSIR(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Disable SIR and SIRLP (if appropriate).
    //
    HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_SIREN | UART_CTL_SIRLP);
}

//*****************************************************************************
//
//! Enables ISO7816 smart card mode on the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function enables the SMART control bit for the ISO7816 smart card mode
//! on the UART.  This call also sets 8-bit word length and even parity as
//! required by ISO7816.
//!
//! \note The availability of ISO7816 smart card mode varies with the Tiva
//! part and UART in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTSmartCardEnable(uint32_t ui32Base)
{
    uint32_t ui32Val;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Set 8-bit word length, even parity, 2 stop bits (note that although the
    // STP2 bit is ignored when in smartcard mode, this code lets the caller
    // read back the actual setting in use).
    //
    ui32Val = HWREG(ui32Base + UART_O_LCRH);
    ui32Val &= ~(UART_LCRH_SPS | UART_LCRH_EPS | UART_LCRH_PEN |
                 UART_LCRH_WLEN_M);
    ui32Val |= UART_LCRH_WLEN_8 | UART_LCRH_PEN | UART_LCRH_EPS |
               UART_LCRH_STP2;
    HWREG(ui32Base + UART_O_LCRH) = ui32Val;

    //
    // Enable SMART mode.
    //
    HWREG(ui32Base + UART_O_CTL) |= UART_CTL_SMART;
}

//*****************************************************************************
//
//! Disables ISO7816 smart card mode on the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function clears the SMART (ISO7816 smart card) bit in the UART
//! control register.
//!
//! \note The availability of ISO7816 smart card mode varies with the Tiva
//! part and UART in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTSmartCardDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Disable the SMART bit.
    //
    HWREG(ui32Base + UART_O_CTL) &= ~UART_CTL_SMART;
}

//*****************************************************************************
//
//! Sets the states of the DTR and/or RTS modem control signals.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32Control is a bit-mapped flag indicating which modem control bits
//! should be set.
//!
//! This function configures the states of the DTR or RTS modem handshake
//! outputs from the UART.
//!
//! The \e ui32Control parameter is the logical OR of any of the following:
//!
//! - \b UART_OUTPUT_DTR - The Modem Control DTR signal
//! - \b UART_OUTPUT_RTS - The Modem Control RTS signal
//!
//! \note The availability of hardware modem handshake signals varies with the
//! Tiva part and UART in use.  Please consult the datasheet for the part
//! you are using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTModemControlSet(uint32_t ui32Base, uint32_t ui32Control)
{
    uint32_t ui32Temp;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == UART1_BASE);
    ASSERT((ui32Control & ~(UART_OUTPUT_RTS | UART_OUTPUT_DTR)) == 0);

    //
    // Set the appropriate modem control output bits.
    //
    ui32Temp = HWREG(ui32Base + UART_O_CTL);
    ui32Temp |= (ui32Control & (UART_OUTPUT_RTS | UART_OUTPUT_DTR));
    HWREG(ui32Base + UART_O_CTL) = ui32Temp;
}

//*****************************************************************************
//
//! Clears the states of the DTR and/or RTS modem control signals.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32Control is a bit-mapped flag indicating which modem control bits
//! should be set.
//!
//! This function clears the states of the DTR or RTS modem handshake outputs
//! from the UART.
//!
//! The \e ui32Control parameter is the logical OR of any of the following:
//!
//! - \b UART_OUTPUT_DTR - The Modem Control DTR signal
//! - \b UART_OUTPUT_RTS - The Modem Control RTS signal
//!
//! \note The availability of hardware modem handshake signals varies with the
//! Tiva part and UART in use.  Please consult the datasheet for the part
//! you are using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTModemControlClear(uint32_t ui32Base, uint32_t ui32Control)
{
    uint32_t ui32Temp;

    //
    // Check the arguments.
    //
    ASSERT(ui32Base == UART1_BASE);
    ASSERT((ui32Control & ~(UART_OUTPUT_RTS | UART_OUTPUT_DTR)) == 0);

    //
    // Set the appropriate modem control output bits.
    //
    ui32Temp = HWREG(ui32Base + UART_O_CTL);
    ui32Temp &= ~(ui32Control & (UART_OUTPUT_RTS | UART_OUTPUT_DTR));
    HWREG(ui32Base + UART_O_CTL) = ui32Temp;
}

//*****************************************************************************
//
//! Gets the states of the DTR and RTS modem control signals.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns the current states of each of the two UART modem
//! control signals, DTR and RTS.
//!
//! \note The availability of hardware modem handshake signals varies with the
//! Tiva part and UART in use.  Please consult the datasheet for the part
//! you are using to determine whether this support is available.
//!
//! \return Returns the states of the handshake output signals.  This value is
//! a logical OR combination of values \b UART_OUTPUT_RTS and
//! \b UART_OUTPUT_DTR where the presence of each flag indicates that the
//! associated signal is asserted.
//
//*****************************************************************************
uint32_t
UARTModemControlGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == UART1_BASE);

    return(HWREG(ui32Base + UART_O_CTL) & (UART_OUTPUT_RTS | UART_OUTPUT_DTR));
}

//*****************************************************************************
//
//! Gets the states of the RI, DCD, DSR and CTS modem status signals.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns the current states of each of the four UART modem
//! status signals, RI, DCD, DSR and CTS.
//!
//! \note The availability of hardware modem handshake signals varies with the
//! Tiva part and UART in use.  Please consult the datasheet for the part
//! you are using to determine whether this support is available.
//!
//! \return Returns the states of the handshake output signals.  This value
//! is a logical OR combination of values \b UART_INPUT_RI,
//! \b UART_INPUT_DCD, \b UART_INPUT_CTS and \b UART_INPUT_DSR where the
//! presence of each flag indicates that the associated signal is asserted.
//
//*****************************************************************************
uint32_t
UARTModemStatusGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(ui32Base == UART1_BASE);

    return(HWREG(ui32Base + UART_O_FR) & (UART_INPUT_RI | UART_INPUT_DCD |
                                          UART_INPUT_CTS | UART_INPUT_DSR));
}

//*****************************************************************************
//
//! Sets the UART hardware flow control mode to be used.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32Mode indicates the flow control modes to be used.  This
//! parameter is a logical OR combination of values \b UART_FLOWCONTROL_TX and
//! \b UART_FLOWCONTROL_RX to enable hardware transmit (CTS) and receive (RTS)
//! flow control or \b UART_FLOWCONTROL_NONE to disable hardware flow control.
//!
//! This function configures the required hardware flow control modes.  If
//! \e ui32Mode contains flag \b UART_FLOWCONTROL_TX, data is only transmitted
//! if the incoming CTS signal is asserted.  If \e ui32Mode contains flag
//! \b UART_FLOWCONTROL_RX, the RTS output is controlled by the hardware and is
//! asserted only when there is space available in the receive FIFO.  If no
//! hardware flow control is required, \b UART_FLOWCONTROL_NONE should be
//! passed.
//!
//! \note The availability of hardware flow control varies with the Tiva
//! part and UART in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTFlowControlSet(uint32_t ui32Base, uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));
    ASSERT((ui32Mode & ~(UART_FLOWCONTROL_TX | UART_FLOWCONTROL_RX)) == 0);

    //
    // Set the flow control mode as requested.
    //
    HWREG(ui32Base + UART_O_CTL) = ((HWREG(ui32Base + UART_O_CTL) &
                                     ~(UART_FLOWCONTROL_TX |
                                       UART_FLOWCONTROL_RX)) | ui32Mode);
}

//*****************************************************************************
//
//! Returns the UART hardware flow control mode currently in use.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns the current hardware flow control mode.
//!
//! \note The availability of hardware flow control varies with the Tiva
//! part and UART in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return Returns the current flow control mode in use.  This value is a
//! logical OR combination of values \b UART_FLOWCONTROL_TX if transmit
//! (CTS) flow control is enabled and \b UART_FLOWCONTROL_RX if receive (RTS)
//! flow control is in use.  If hardware flow control is disabled,
//! \b UART_FLOWCONTROL_NONE is returned.
//
//*****************************************************************************
uint32_t
UARTFlowControlGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    return(HWREG(ui32Base + UART_O_CTL) & (UART_FLOWCONTROL_TX |
                                           UART_FLOWCONTROL_RX));
}

//*****************************************************************************
//
//! Sets the operating mode for the UART transmit interrupt.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32Mode is the operating mode for the transmit interrupt.  It may
//! be \b UART_TXINT_MODE_EOT to trigger interrupts when the transmitter is
//! idle or \b UART_TXINT_MODE_FIFO to trigger based on the current transmit
//! FIFO level.
//!
//! This function allows the mode of the UART transmit interrupt to be set.  By
//! default, the transmit interrupt is asserted when the FIFO level falls past
//! a threshold set via a call to UARTFIFOLevelSet().  Alternatively, if this
//! function is called with \e ui32Mode set to \b UART_TXINT_MODE_EOT, the
//! transmit interrupt is asserted once the transmitter is completely idle -
//! the transmit FIFO is empty and all bits, including any stop bits, have
//! cleared the transmitter.
//!
//! \note The availability of end-of-transmission mode varies with the
//! Tiva part in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTTxIntModeSet(uint32_t ui32Base, uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));
    ASSERT((ui32Mode == UART_TXINT_MODE_EOT) ||
           (ui32Mode == UART_TXINT_MODE_FIFO));

    //
    // Set or clear the EOT bit of the UART control register as appropriate.
    //
    HWREG(ui32Base + UART_O_CTL) = ((HWREG(ui32Base + UART_O_CTL) &
                                     ~(UART_TXINT_MODE_EOT |
                                       UART_TXINT_MODE_FIFO)) | ui32Mode);
}

//*****************************************************************************
//
//! Returns the current operating mode for the UART transmit interrupt.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns the current operating mode for the UART transmit
//! interrupt.  The return value is \b UART_TXINT_MODE_EOT if the transmit
//! interrupt is currently configured to be asserted once the transmitter is
//! completely idle - the transmit FIFO is empty and all bits, including any
//! stop bits, have cleared the transmitter.  The return value is
//! \b UART_TXINT_MODE_FIFO if the interrupt is configured to be asserted based
//! on the level of the transmit FIFO.
//!
//! \note The availability of end-of-transmission mode varies with the
//! Tiva part in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return Returns \b UART_TXINT_MODE_FIFO or \b UART_TXINT_MODE_EOT.
//
//*****************************************************************************
uint32_t
UARTTxIntModeGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return the current transmit interrupt mode.
    //
    return(HWREG(ui32Base + UART_O_CTL) & (UART_TXINT_MODE_EOT |
                                           UART_TXINT_MODE_FIFO));
}

//*****************************************************************************
//
//! Determines if there are any characters in the receive FIFO.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns a flag indicating whether or not there is data
//! available in the receive FIFO.
//!
//! \return Returns \b true if there is data in the receive FIFO or \b false
//! if there is no data in the receive FIFO.
//
//*****************************************************************************
bool
UARTCharsAvail(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return the availability of characters.
    //
    return((HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE) ? false : true);
}

//*****************************************************************************
//
//! Determines if there is any space in the transmit FIFO.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns a flag indicating whether or not there is space
//! available in the transmit FIFO.
//!
//! \return Returns \b true if there is space available in the transmit FIFO
//! or \b false if there is no space available in the transmit FIFO.
//
//*****************************************************************************
bool
UARTSpaceAvail(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return the availability of space.
    //
    return((HWREG(ui32Base + UART_O_FR) & UART_FR_TXFF) ? false : true);
}

//*****************************************************************************
//
//! Receives a character from the specified port.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function gets a character from the receive FIFO for the specified
//! port.
//!
//! \return Returns the character read from the specified port, cast as a
//! \e int32_t.  A \b -1 is returned if there are no characters present in the
//! receive FIFO.  The UARTCharsAvail() function should be called before
//! attempting to call this function.
//
//*****************************************************************************
int32_t
UARTCharGetNonBlocking(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // See if there are any characters in the receive FIFO.
    //
    if(!(HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE))
    {
        //
        // Read and return the next character.
        //
        return(HWREG(ui32Base + UART_O_DR));
    }
    else
    {
        //
        // There are no characters, so return a failure.
        //
        return(-1);
    }
}

//*****************************************************************************
//
//! Waits for a character from the specified port.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function gets a character from the receive FIFO for the specified
//! port.  If there are no characters available, this function waits until a
//! character is received before returning.
//!
//! \return Returns the character read from the specified port, cast as a
//! \e int32_t.
//
//*****************************************************************************
int32_t
UARTCharGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Wait until a char is available.
    //
    while(HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE)
    {
    }

    //
    // Now get the char.
    //
    return(HWREG(ui32Base + UART_O_DR));
}

//*****************************************************************************
//
//! Sends a character to the specified port.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ucData is the character to be transmitted.
//!
//! This function writes the character \e ucData to the transmit FIFO for the
//! specified port.  This function does not block, so if there is no space
//! available, then a \b false is returned and the application must retry the
//! function later.
//!
//! \return Returns \b true if the character was successfully placed in the
//! transmit FIFO or \b false if there was no space available in the transmit
//! FIFO.
//
//*****************************************************************************
bool
UARTCharPutNonBlocking(uint32_t ui32Base, unsigned char ucData)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // See if there is space in the transmit FIFO.
    //
    if(!(HWREG(ui32Base + UART_O_FR) & UART_FR_TXFF))
    {
        //
        // Write this character to the transmit FIFO.
        //
        HWREG(ui32Base + UART_O_DR) = ucData;

        //
        // Success.
        //
        return(true);
    }
    else
    {
        //
        // There is no space in the transmit FIFO, so return a failure.
        //
        return(false);
    }
}

//*****************************************************************************
//
//! Waits to send a character from the specified port.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ucData is the character to be transmitted.
//!
//! This function sends the character \e ucData to the transmit FIFO for the
//! specified port.  If there is no space available in the transmit FIFO, this
//! function waits until there is space available before returning.
//!
//! \return None.
//
//*****************************************************************************
void
UARTCharPut(uint32_t ui32Base, unsigned char ucData)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Wait until space is available.
    //
    while(HWREG(ui32Base + UART_O_FR) & UART_FR_TXFF)
    {
    }

    //
    // Send the char.
    //
    HWREG(ui32Base + UART_O_DR) = ucData;
}

//*****************************************************************************
//
//! Causes a BREAK to be sent.
//!
//! \param ui32Base is the base address of the UART port.
//! \param bBreakState controls the output level.
//!
//! Calling this function with \e bBreakState set to \b true asserts a break
//! condition on the UART.  Calling this function with \e bBreakState set to
//! \b false removes the break condition.  For proper transmission of a break
//! command, the break must be asserted for at least two complete frames.
//!
//! \return None.
//
//*****************************************************************************
void
UARTBreakCtl(uint32_t ui32Base, bool bBreakState)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Set the break condition as requested.
    //
    HWREG(ui32Base + UART_O_LCRH) =
        (bBreakState ?
         (HWREG(ui32Base + UART_O_LCRH) | UART_LCRH_BRK) :
         (HWREG(ui32Base + UART_O_LCRH) & ~(UART_LCRH_BRK)));
}

//*****************************************************************************
//
//! Determines whether the UART transmitter is busy or not.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function allows the caller to determine whether all transmitted bytes
//! have cleared the transmitter hardware.  If \b false is returned, the
//! transmit FIFO is empty and all bits of the last transmitted character,
//! including all stop bits, have left the hardware shift register.
//!
//! \return Returns \b true if the UART is transmitting or \b false if all
//! transmissions are complete.
//
//*****************************************************************************
bool
UARTBusy(uint32_t ui32Base)
{
    //
    // Check the argument.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Determine if the UART is busy.
    //
    return((HWREG(ui32Base + UART_O_FR) & UART_FR_BUSY) ? true : false);
}

//*****************************************************************************
//
//! Registers an interrupt handler for a UART interrupt.
//!
//! \param ui32Base is the base address of the UART port.
//! \param pfnHandler is a pointer to the function to be called when the
//! UART interrupt occurs.
//!
//! This function does the actual registering of the interrupt handler.  This
//! function enables the global interrupt in the interrupt controller; specific
//! UART interrupts must be enabled via UARTIntEnable().  It is the interrupt
//! handler's responsibility to clear the interrupt source.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
UARTIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the UART port.
    //
    ui32Int = _UARTIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the UART interrupt.
    //
    IntEnable(ui32Int);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for a UART interrupt.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function does the actual unregistering of the interrupt handler.  It
//! clears the handler to be called when a UART interrupt occurs.  This
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
UARTIntUnregister(uint32_t ui32Base)
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the UART port.
    //
    ui32Int = _UARTIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Disable the interrupt.
    //
    IntDisable(ui32Int);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(ui32Int);
}

//*****************************************************************************
//
//! Enables individual UART interrupt sources.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated UART interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b UART_INT_9BIT - 9-bit Address Match interrupt
//! - \b UART_INT_OE - Overrun Error interrupt
//! - \b UART_INT_BE - Break Error interrupt
//! - \b UART_INT_PE - Parity Error interrupt
//! - \b UART_INT_FE - Framing Error interrupt
//! - \b UART_INT_RT - Receive Timeout interrupt
//! - \b UART_INT_TX - Transmit interrupt
//! - \b UART_INT_RX - Receive interrupt
//! - \b UART_INT_DSR - DSR interrupt
//! - \b UART_INT_DCD - DCD interrupt
//! - \b UART_INT_CTS - CTS interrupt
//! - \b UART_INT_RI - RI interrupt
//!
//! \return None.
//
//*****************************************************************************
void
UARTIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Enable the specified interrupts.
    //
    HWREG(ui32Base + UART_O_IM) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables individual UART interrupt sources.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be
//! disabled.
//!
//! This function disables the indicated UART interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ui32IntFlags parameter has the same definition as the
//! \e ui32IntFlags parameter to UARTIntEnable().
//!
//! \return None.
//
//*****************************************************************************
void
UARTIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Disable the specified interrupts.
    //
    HWREG(ui32Base + UART_O_IM) &= ~(ui32IntFlags);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param ui32Base is the base address of the UART port.
//! \param bMasked is \b false if the raw interrupt status is required and
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the specified UART.  Either
//! the raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return Returns the current interrupt status, enumerated as a bit field of
//! values described in UARTIntEnable().
//
//*****************************************************************************
uint32_t
UARTIntStatus(uint32_t ui32Base, bool bMasked)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(ui32Base + UART_O_MIS));
    }
    else
    {
        return(HWREG(ui32Base + UART_O_RIS));
    }
}

//*****************************************************************************
//
//! Clears UART interrupt sources.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32IntFlags is a bit mask of the interrupt sources to be cleared.
//!
//! The specified UART interrupt sources are cleared, so that they no longer
//! assert.  This function must be called in the interrupt handler to keep the
//! interrupt from being triggered again immediately upon exit.
//!
//! The \e ui32IntFlags parameter has the same definition as the
//! \e ui32IntFlags parameter to UARTIntEnable().
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
UARTIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Clear the requested interrupt sources.
    //
    HWREG(ui32Base + UART_O_ICR) = ui32IntFlags;
}

//*****************************************************************************
//
//! Enable UART DMA operation.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32DMAFlags is a bit mask of the DMA features to enable.
//!
//! The specified UART DMA features are enabled.  The UART can be
//! configured to use DMA for transmit or receive and to disable
//! receive if an error occurs.  The \e ui32DMAFlags parameter is the
//! logical OR of any of the following values:
//!
//! - UART_DMA_RX - enable DMA for receive
//! - UART_DMA_TX - enable DMA for transmit
//! - UART_DMA_ERR_RXSTOP - disable DMA receive on UART error
//!
//! \note The uDMA controller must also be set up before DMA can be used
//! with the UART.
//!
//! \return None.
//
//*****************************************************************************
void
UARTDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Set the requested bits in the UART DMA control register.
    //
    HWREG(ui32Base + UART_O_DMACTL) |= ui32DMAFlags;
}

//*****************************************************************************
//
//! Disable UART DMA operation.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32DMAFlags is a bit mask of the DMA features to disable.
//!
//! This function is used to disable UART DMA features that were enabled
//! by UARTDMAEnable().  The specified UART DMA features are disabled.  The
//! \e ui32DMAFlags parameter is the logical OR of any of the following values:
//!
//! - UART_DMA_RX - disable DMA for receive
//! - UART_DMA_TX - disable DMA for transmit
//! - UART_DMA_ERR_RXSTOP - do not disable DMA receive on UART error
//!
//! \return None.
//
//*****************************************************************************
void
UARTDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Clear the requested bits in the UART DMA control register.
    //
    HWREG(ui32Base + UART_O_DMACTL) &= ~ui32DMAFlags;
}

//*****************************************************************************
//
//! Gets current receiver errors.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns the current state of each of the 4 receiver error
//! sources.  The returned errors are equivalent to the four error bits
//! returned via the previous call to UARTCharGet() or UARTCharGetNonBlocking()
//! with the exception that the overrun error is set immediately when the
//! overrun occurs rather than when a character is next read.
//!
//! \return Returns a logical OR combination of the receiver error flags,
//! \b UART_RXERROR_FRAMING, \b UART_RXERROR_PARITY, \b UART_RXERROR_BREAK
//! and \b UART_RXERROR_OVERRUN.
//
//*****************************************************************************
uint32_t
UARTRxErrorGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return the current value of the receive status register.
    //
    return(HWREG(ui32Base + UART_O_RSR) & 0x0000000F);
}

//*****************************************************************************
//
//! Clears all reported receiver errors.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function is used to clear all receiver error conditions reported via
//! UARTRxErrorGet().  If using the overrun, framing error, parity error or
//! break interrupts, this function must be called after clearing the interrupt
//! to ensure that later errors of the same type trigger another interrupt.
//!
//! \return None.
//
//*****************************************************************************
void
UARTRxErrorClear(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Any write to the Error Clear Register clears all bits which are
    // currently set.
    //
    HWREG(ui32Base + UART_O_ECR) = 0;
}

//*****************************************************************************
//
//! Sets the baud clock source for the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui32Source is the baud clock source for the UART.
//!
//! This function allows the baud clock source for the UART to be selected.
//! The possible clock source are the system clock (\b UART_CLOCK_SYSTEM) or
//! the precision internal oscillator (\b UART_CLOCK_PIOSC).
//!
//! Changing the baud clock source changes the baud rate generated by the
//! UART.  Therefore, the baud rate should be reconfigured after any change to
//! the baud clock source.
//!
//! \note The ability to specify the UART baud clock source varies with the
//! Tiva part in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UARTClockSourceSet(uint32_t ui32Base, uint32_t ui32Source)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));
    ASSERT((ui32Source == UART_CLOCK_SYSTEM) ||
           (ui32Source == UART_CLOCK_PIOSC));

    //
    // Set the UART clock source.
    //
    HWREG(ui32Base + UART_O_CC) = ui32Source;
}

//*****************************************************************************
//
//! Gets the baud clock source for the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function returns the baud clock source for the specified UART.  The
//! possible baud clock source are the system clock (\b UART_CLOCK_SYSTEM) or
//! the precision internal oscillator (\b UART_CLOCK_PIOSC).
//!
//! \note The ability to specify the UART baud clock source varies with the
//! Tiva part in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
uint32_t
UARTClockSourceGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Return the UART clock source.
    //
    return(HWREG(ui32Base + UART_O_CC));
}

//*****************************************************************************
//
//! Enables 9-bit mode on the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function enables the 9-bit operational mode of the UART.
//!
//! \note The availability of 9-bit mode varies with the Tiva part in use.
//! Please consult the datasheet for the part you are using to determine
//! whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UART9BitEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Enable 9-bit mode.
    //
    HWREG(ui32Base + UART_O_9BITADDR) |= UART_9BITADDR_9BITEN;
}

//*****************************************************************************
//
//! Disables 9-bit mode on the specified UART.
//!
//! \param ui32Base is the base address of the UART port.
//!
//! This function disables the 9-bit operational mode of the UART.
//!
//! \note The availability of 9-bit mode varies with the Tiva part in use.
//! Please consult the datasheet for the part you are using to determine
//! whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UART9BitDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Disable 9-bit mode.
    //
    HWREG(ui32Base + UART_O_9BITADDR) &= ~UART_9BITADDR_9BITEN;
}

//*****************************************************************************
//
//! Sets the device address(es) for 9-bit mode.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui8Addr is the device address.
//! \param ui8Mask is the device address mask.
//!
//! This function configures the device address or range of device addresses
//! that respond to requests on the 9-bit UART port.  The received address is
//! masked with the mask and then compared against the given address, allowing
//! either a single address (if \b ui8Mask is 0xff) or a set of addresses to be
//! matched.
//!
//! \note The availability of 9-bit mode varies with the Tiva part in use.
//! Please consult the datasheet for the part you are using to determine
//! whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UART9BitAddrSet(uint32_t ui32Base, uint8_t ui8Addr,
                uint8_t ui8Mask)
{
    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Set the address and mask.
    //
    HWREG(ui32Base + UART_O_9BITADDR) = ui8Addr << UART_9BITADDR_ADDR_S;
    HWREG(ui32Base + UART_O_9BITAMASK) = ui8Mask << UART_9BITAMASK_MASK_S;
}

//*****************************************************************************
//
//! Sends an address character from the specified port when operating in 9-bit
//! mode.
//!
//! \param ui32Base is the base address of the UART port.
//! \param ui8Addr is the address to be transmitted.
//!
//! This function waits until all data has been sent from the specified port
//! and then sends the given address as an address byte.  It then waits until
//! the address byte has been transmitted before returning.
//!
//! The normal data functions (UARTCharPut(), UARTCharPutNonBlocking(),
//! UARTCharGet(), and UARTCharGetNonBlocking()) are used to send and receive
//! data characters in 9-bit mode.
//!
//! \note The availability of 9-bit mode varies with the Tiva part in use.
//! Please consult the datasheet for the part you are using to determine
//! whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
UART9BitAddrSend(uint32_t ui32Base, uint8_t ui8Addr)
{
    uint32_t ui32LCRH;

    //
    // Check the arguments.
    //
    ASSERT(_UARTBaseValid(ui32Base));

    //
    // Wait until the FIFO is empty and the UART is not busy.
    //
    while((HWREG(ui32Base + UART_O_FR) & (UART_FR_TXFE | UART_FR_BUSY)) !=
          UART_FR_TXFE)
    {
    }

    //
    // Force the address/data bit to 1 to indicate this is an address byte.
    //
    ui32LCRH = HWREG(ui32Base + UART_O_LCRH);
    HWREG(ui32Base + UART_O_LCRH) = ((ui32LCRH & ~UART_LCRH_EPS) |
                                     UART_LCRH_SPS | UART_LCRH_PEN);

    //
    // Send the address.
    //
    HWREG(ui32Base + UART_O_DR) = ui8Addr;

    //
    // Wait until the address has been sent.
    //
    while((HWREG(ui32Base + UART_O_FR) & (UART_FR_TXFE | UART_FR_BUSY)) !=
          UART_FR_TXFE)
    {
    }

    //
    // Restore the address/data setting.
    //
    HWREG(ui32Base + UART_O_LCRH) = ui32LCRH;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
