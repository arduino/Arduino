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
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % TX_BUFFER_SIZE) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % RX_BUFFER_SIZE) == rxReadIndex)
HardwareSerial Serial;
// Constructors ////////////////////////////////////////////////////////////////
HardwareSerial::HardwareSerial(void)
{
    txWriteIndex = 0;
    txReadIndex = 0;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartBase = 0;
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
        MAP_IntDisable(INT_UART0);

        //
        // Yes - take some characters out of the transmit buffer and feed
        // them to the UART transmit FIFO.
        //
        while(MAP_UARTSpaceAvail(ulBase) && !TX_BUFFER_EMPTY)
        {
            MAP_UARTCharPutNonBlocking(ulBase,
                                       txBuffer[txReadIndex]);
            txWriteIndex = (txWriteIndex + 1) % TX_BUFFER_SIZE;
        }

        //
        // Reenable the UART interrupt.
        //
        MAP_IntEnable(INT_UART0);
    }
}

// Public Methods //////////////////////////////////////////////////////////////

void 
HardwareSerial::begin(unsigned long baud)
{
    //
    // Initialize the UART.
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
    ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    //
    // Only allow a single instance to be opened.
    //
    ASSERT(uartBase == 0);
	//
    // Check to make sure the UART peripheral is present.
    //
    if(!MAP_SysCtlPeripheralPresent(UART0_BASE))
    {
        return;
    }
	uartBase = UART0_BASE;
	MAP_SysCtlPeripheralEnable(uartBase);
	MAP_UARTConfigSetExpClk(uartBase, MAP_SysCtlClockGet(), baud,
                            (UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_WLEN_8));
    //
    // Set the UART to interrupt whenever the TX FIFO is almost empty or
    // when any character is received.
    //
    MAP_UARTFIFOLevelSet(uartBase, UART_FIFO_TX1_8, UART_FIFO_RX1_8);
	flushAll();
	MAP_UARTIntDisable(uartBase, 0xFFFFFFFF);
    MAP_UARTIntEnable(uartBase, UART_INT_RX | UART_INT_RT);
    MAP_IntEnable(INT_UART0);
	MAP_IntMasterEnable();

    //
    // Enable the UART operation.
    //
    MAP_UARTEnable(uartBase);

}

void HardwareSerial::end()
{
    unsigned long ulInt = MAP_IntMasterDisable();
	
	flushAll();
	
    //
    // If interrupts were enabled when we turned them off, turn them
    // back on again.
    //
    if(!ulInt)
    {
        MAP_IntMasterEnable();
    }
	
    ROM_IntDisable(INT_UART0);
    ROM_UARTIntDisable(UART0_BASE, UART_INT_RX | UART_INT_RT);

}

int HardwareSerial::available(void)
{
    return((rxWriteIndex >= rxReadIndex) ? 
		(rxWriteIndex - rxReadIndex) : RX_BUFFER_SIZE - (rxReadIndex - rxWriteIndex));
}

int HardwareSerial::peek(void)
{
    unsigned char cChar;

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
    rxReadIndex = ((rxReadIndex) + 1) % RX_BUFFER_SIZE;
	return(cChar);
}

void HardwareSerial::flush()
{
    while(!TX_BUFFER_EMPTY)
    {
    }
}

size_t HardwareSerial::write(const uint8_t *buffer, size_t size)
{
    unsigned int uIdx;

    //
    // Check for valid arguments.
    //
    ASSERT(buffer != 0);
    ASSERT(uartBase != 0);

    //
    // Send the characters
    //
    for(uIdx = 0; uIdx < size; uIdx++)
    {
        //
        // If the character to the UART is \n, then add a \r before it so that
        // \n is translated to \n\r in the output.
        //
        if(buffer[uIdx] == '\n')
        {
            if(!TX_BUFFER_FULL)
            {
                txBuffer[txWriteIndex] = '\r';
			    txWriteIndex = (txWriteIndex + 1) % TX_BUFFER_SIZE;
            }
            else
            {
                //
                // Buffer is full - discard remaining characters and return.
                //
                break;
            }
        }

        //
        // Send the character to the UART output.
        //
        if(!TX_BUFFER_FULL)
        {
            txBuffer[txWriteIndex] = buffer[uIdx];
			txWriteIndex = (txWriteIndex + 1) % TX_BUFFER_SIZE;
        }
        else
        {
            //
            // Buffer is full - discard remaining characters and return.
            //
            break;
        }
    }

    //
    // If we have anything in the buffer, make sure that the UART is set
    // up to transmit it.
    //
    if(!TX_BUFFER_EMPTY)
    {
	    primeTransmit(uartBase);
        MAP_UARTIntEnable(uartBase, UART_INT_TX);
    }

    //
    // Return the number of characters written.
    //
    return(uIdx);
}

size_t HardwareSerial::write(uint8_t c)
{
    write((const uint8_t *) &c,1);
    return 1;
}
size_t HardwareSerial::write(const char *str) {
    return write((const uint8_t *) str, strlen(str));
}

void HardwareSerial::UARTIntHandler(void){
    unsigned long ulInts;
    long lChar;
    //
    // Get and clear the current interrupt source(s)
    //
    ulInts = MAP_UARTIntStatus(uartBase, true);
    MAP_UARTIntClear(uartBase, ulInts);

    //
    // Are we being interrupted because the TX FIFO has space available?
    //
    if(ulInts & UART_INT_TX)
    {
        //
        // Move as many bytes as we can into the transmit FIFO.
        //
        primeTransmit(uartBase);

        //
        // If the output buffer is empty, turn off the transmit interrupt.
        //
        if(TX_BUFFER_EMPTY)
        {
            MAP_UARTIntDisable(uartBase, UART_INT_TX);
        }
    }

    //
    // Are we being interrupted due to a received character?
    //
    if(ulInts & (UART_INT_RX | UART_INT_RT))
    {
        //
        // Get all the available characters from the UART.
        //
        while(MAP_UARTCharsAvail(uartBase))
        {
            //
            // Read a character
            //
            lChar = MAP_UARTCharGetNonBlocking(uartBase);

            //
            // If there is space in the receive buffer, put the character
            // there, otherwise throw it away.
            //
            if(!RX_BUFFER_FULL)
            {
                //
                // Store the new character in the receive buffer
                //
                rxBuffer[rxWriteIndex] = 
				    (unsigned char)(lChar & 0xFF);
                rxReadIndex = ((rxReadIndex) + 1) % RX_BUFFER_SIZE;
            }
        }

        //
        // If we wrote anything to the transmit buffer, make sure it actually
        // gets transmitted.
        //
        primeTransmit(uartBase);
        MAP_UARTIntEnable(uartBase, UART_INT_TX);
    }
}

void
UART0IntHandler(void)
{
    Serial.UARTIntHandler();
}