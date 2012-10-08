/*
 ************************************************************************
 *	HardwareSerial.cpp
 *
 *	Arduino core files for MSP430
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "wiring_private.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_uart.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "HardwareSerial.h"

#define TX_BUFFER_EMPTY    (txReadIndex == txWriteIndex)
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % SERIAL_BUFFER_SIZE) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % SERIAL_BUFFER_SIZE) == rxReadIndex)

static const unsigned long g_ulUARTBase[3] =
{
    UART0_BASE, UART1_BASE, UART2_BASE
};

//*****************************************************************************
//
// The list of possible interrupts for the console UART.
//
//*****************************************************************************
static const unsigned long g_ulUARTInt[3] =
{
    INT_UART0, INT_UART1, INT_UART2
};

//*****************************************************************************
//
// The list of UART peripherals.
//
//*****************************************************************************
static const unsigned long g_ulUARTPeriph[3] =
{
    SYSCTL_PERIPH_UART0, SYSCTL_PERIPH_UART1, SYSCTL_PERIPH_UART2
};

// Constructors ////////////////////////////////////////////////////////////////
HardwareSerial::HardwareSerial(void)
{
    txWriteIndex = 0;
    txReadIndex = 0;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartModule = 0;
}
HardwareSerial::HardwareSerial(unsigned long _uartModule)
{
    txWriteIndex = 0;
    txReadIndex = 0;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartModule = _uartModule;
}
// Private Methods //////////////////////////////////////////////////////////////
void 
HardwareSerial::flushAll(void)
{
    // wait for transmission of outgoing data
    while(!TX_BUFFER_EMPTY)
    {
    }
    txReadIndex = 0;
    txWriteIndex = 0;

    //
    // Flush the receive buffer.
    //
    rxReadIndex = 0;
    rxWriteIndex = 0;
}

void
HardwareSerial::primeTransmit(unsigned long ulBase)
{
    //
    // Do we have any data to transmit?
    //
    if(!TX_BUFFER_EMPTY)
    {
        //
        // Disable the UART interrupt. If we don't do this there is a race
        // condition which can cause the read index to be corrupted.
        //
        ROM_IntDisable(g_ulUARTInt[uartModule]);
        //
        // Yes - take some characters out of the transmit buffer and feed
        // them to the UART transmit FIFO.
        //
        while(!TX_BUFFER_EMPTY)
        {
            while(ROM_UARTSpaceAvail(ulBase) && !TX_BUFFER_EMPTY){
                ROM_UARTCharPutNonBlocking(ulBase,
                                       txBuffer[txReadIndex]);
                
                txReadIndex = (txReadIndex + 1) % SERIAL_BUFFER_SIZE;
            }
        }

        //
        // Reenable the UART interrupt.
        //
        ROM_IntEnable(g_ulUARTInt[uartModule]);
    }
}

// Public Methods //////////////////////////////////////////////////////////////

void 
HardwareSerial::begin(unsigned long baud)
{
    //
    // Initialize the UART.
    //
    ROM_SysCtlPeripheralEnable(g_ulUARTInt[uartModule]);
    
    //TODO:Add functionality for PinConfigure with variable uartModule 
    ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
    ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
    
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    //
    // Only allow a single instance to be opened.
    //
    ASSERT(g_ulUARTBase[uartModule] == 0);
	//
    // Check to make sure the UART peripheral is present.
    //
    if(!ROM_SysCtlPeripheralPresent(g_ulUARTPeriph[uartModule]))
    {
        return;
    }
	ROM_SysCtlPeripheralEnable(g_ulUARTPeriph[uartModule]);
	ROM_UARTConfigSetExpClk(g_ulUARTBase[uartModule], ROM_SysCtlClockGet(), baud,
                            (UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_WLEN_8));
    //
    // Set the UART to interrupt whenever the TX FIFO is almost empty or
    // when any character is received.
    //
    ROM_UARTFIFOLevelSet(g_ulUARTBase[uartModule], UART_FIFO_TX1_8, UART_FIFO_RX1_8);
	flushAll();
	ROM_UARTIntDisable(g_ulUARTBase[uartModule], 0xFFFFFFFF);
    ROM_UARTIntEnable(g_ulUARTBase[uartModule], UART_INT_RX | UART_INT_RT);
    ROM_IntMasterEnable();
    ROM_IntEnable(g_ulUARTInt[uartModule]);
    

    //
    // Enable the UART operation.
    //
    ROM_UARTEnable(g_ulUARTBase[uartModule]);

}

void HardwareSerial::end()
{
    unsigned long ulInt = ROM_IntMasterDisable();
	
	flushAll();
	
    //
    // If interrupts were enabled when we turned them off, turn them
    // back on again.
    //
    if(!ulInt)
    {
        ROM_IntMasterEnable();
    }
	
    ROM_IntDisable(g_ulUARTInt[uartModule]);
    ROM_UARTIntDisable(g_ulUARTBase[uartModule], UART_INT_RX | UART_INT_RT);

}

int HardwareSerial::available(void)
{
    return((rxWriteIndex >= rxReadIndex) ? 
		(rxWriteIndex - rxReadIndex) : SERIAL_BUFFER_SIZE - (rxReadIndex - rxWriteIndex));
}

int HardwareSerial::peek(void)
{
    unsigned char cChar = 0;

    //
    // Wait for a character to be received.
    //
    while(RX_BUFFER_EMPTY)
    {
        //
        // Block waiting for a character to be received (if the buffer is
        // currently empty).
        //
    }

    //
    // Read a character from the buffer.
    //
    cChar = rxBuffer[rxReadIndex];
    //
    // Return the character to the caller.
    //
    return(cChar);
}

int HardwareSerial::read(void)
{
	unsigned char cChar = peek();
    rxReadIndex = ((rxReadIndex) + 1) % SERIAL_BUFFER_SIZE;
	return(cChar);
}

void HardwareSerial::flush()
{
    while(!TX_BUFFER_EMPTY);
}

size_t HardwareSerial::write(uint8_t c)
{

    unsigned int numTransmit = 0;
    //
    // Check for valid arguments.
    //
    ASSERT(c != 0);

    //
    // If the character to the UART is \n, then add a \r before it so that
    // \n is translated to \n\r in the output.
    //           
	
	// If the output buffer is full, there's nothing for it other than to
	// wait for the interrupt handler to empty it a bit

    if(c == '\n')
    {
        while (TX_BUFFER_FULL);
        txBuffer[txWriteIndex] = '\r';
		txWriteIndex = (txWriteIndex + 1) % SERIAL_BUFFER_SIZE;
        numTransmit ++;
    }
        
    //
    // Send the character to the UART output.
    //
    while (TX_BUFFER_FULL);
    txBuffer[txWriteIndex] = c;
    txWriteIndex = (txWriteIndex + 1) % SERIAL_BUFFER_SIZE;
    numTransmit ++;

    //
    // If we have anything in the buffer, make sure that the UART is set
    // up to transmit it.
    //
    if(!TX_BUFFER_EMPTY)
    {
	    primeTransmit(g_ulUARTBase[uartModule]);
        ROM_UARTIntEnable(g_ulUARTBase[uartModule], UART_INT_TX);
    }

    //
    // Return the number of characters written.
    //
    return(numTransmit);
}

void HardwareSerial::UARTIntHandler(void){
    unsigned long ulInts;
    long lChar;
    // Get and clear the current interrupt source(s)
    //
    ulInts = ROM_UARTIntStatus(g_ulUARTBase[uartModule], true);
    ROM_UARTIntClear(g_ulUARTBase[uartModule], ulInts);
    
    // Are we being interrupted because the TX FIFO has space available?
    //        
    if(ulInts & UART_INT_TX)
    {
        //
        // Move as many bytes as we can into the transmit FIFO.
        //
        primeTransmit(g_ulUARTBase[uartModule]);

        //
        // If the output buffer is empty, turn off the transmit interrupt.
        //
        if(TX_BUFFER_EMPTY)
        {
            ROM_UARTIntDisable(g_ulUARTBase[uartModule], UART_INT_TX);
        }
    }
    if(ulInts & (UART_INT_RX | UART_INT_RT))
    {
        while(ROM_UARTCharsAvail(g_ulUARTBase[uartModule]))
            {

            //
            // Read a character
            //
            lChar = ROM_UARTCharGetNonBlocking(g_ulUARTBase[uartModule]);
            //
            // If there is space in the receive buffer, put the character
            // there, otherwise throw it away.
            //
            while(RX_BUFFER_FULL);
            rxBuffer[rxWriteIndex] =
                (unsigned char)(lChar & 0xFF);
            rxWriteIndex = ((rxWriteIndex) + 1) % SERIAL_BUFFER_SIZE;

            //
            // If we wrote anything to the transmit buffer, make sure it actually
            // gets transmitted.
            //
        }
        primeTransmit(g_ulUARTBase[uartModule]);
        ROM_UARTIntEnable(g_ulUARTBase[uartModule], UART_INT_TX);
    }
}

void
UART0IntHandler(void)
{
    Serial.UARTIntHandler();
}

//Preinstantiate Object
HardwareSerial Serial;
