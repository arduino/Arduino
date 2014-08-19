/*
 ************************************************************************
 *	HardwareSerial.cpp
 *
 *	Arduino core files for ARM Cortex-M4F: Tiva-C and Stellaris
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************

 2013-12-23 Limited size for RX and TX buffers, by spirilis

 
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
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % txBufferSize) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % rxBufferSize) == rxReadIndex)

#define UART_BASE g_ulUARTBase[uartModule]

static const unsigned long g_ulUARTBase[8] =
{
    UART0_BASE, UART1_BASE, UART2_BASE, UART3_BASE,
	UART4_BASE, UART5_BASE, UART6_BASE, UART7_BASE
};

//*****************************************************************************
//
// The list of possible interrupts for the console UART.
//
//*****************************************************************************
static const unsigned long g_ulUARTInt[8] =
{
    INT_UART0, INT_UART1, INT_UART2, INT_UART3,
	INT_UART4, INT_UART5, INT_UART6, INT_UART7
};

//*****************************************************************************
//
// The list of UART peripherals.
//
//*****************************************************************************
static const unsigned long g_ulUARTPeriph[8] =
{
    SYSCTL_PERIPH_UART0, SYSCTL_PERIPH_UART1, SYSCTL_PERIPH_UART2,
	SYSCTL_PERIPH_UART3, SYSCTL_PERIPH_UART4, SYSCTL_PERIPH_UART5,
	SYSCTL_PERIPH_UART6, SYSCTL_PERIPH_UART7
};
//*****************************************************************************
//
// The list of UART GPIO configurations.
//
//*****************************************************************************
static const unsigned long g_ulUARTConfig[8][2] =
{

#if defined(PART_TM4C1233H6PM) || defined(PART_LM4F120H5QR)
    {GPIO_PA0_U0RX, GPIO_PA1_U0TX}, {GPIO_PC4_U1RX, GPIO_PC5_U1TX},
    {GPIO_PD6_U2RX, GPIO_PD7_U2TX}, {GPIO_PC6_U3RX, GPIO_PC7_U3TX},
    {GPIO_PC4_U4RX, GPIO_PC5_U4TX},	{GPIO_PE4_U5RX, GPIO_PE5_U5TX},
	{GPIO_PD4_U6RX, GPIO_PD5_U6TX},	{GPIO_PE0_U7RX, GPIO_PE1_U7TX}
#elif defined(PART_TM4C129XNCZAD)
    {GPIO_PA0_U0RX, GPIO_PA1_U0TX}, {GPIO_PQ4_U1RX, GPIO_PQ5_U1TX},
    {GPIO_PD4_U2RX, GPIO_PD5_U2TX}, {GPIO_PA4_U3RX, GPIO_PA5_U3TX},
    {GPIO_PK0_U4RX, GPIO_PK1_U4TX},	{GPIO_PH6_U5RX, GPIO_PH7_U5TX},
	{GPIO_PP0_U6RX, GPIO_PP1_U6TX},	{GPIO_PC4_U7RX, GPIO_PC5_U7TX}
#elif defined(PART_TM4C1294NCPDT)
    {GPIO_PA0_U0RX, GPIO_PA1_U0TX}, {GPIO_PB0_U1RX, GPIO_PB1_U1TX},
    {GPIO_PA6_U2RX, GPIO_PA7_U2TX}, {GPIO_PA4_U3RX, GPIO_PA5_U3TX},
    {GPIO_PK0_U4RX, GPIO_PK1_U4TX},	{GPIO_PC6_U5RX, GPIO_PC7_U5TX},
	{GPIO_PP0_U6RX, GPIO_PP1_U6TX},	{GPIO_PC4_U7RX, GPIO_PC5_U7TX}
#else
#error "**** No PART defined or unsupported PART ****"
#endif
};

static const unsigned long g_ulUARTPort[8] =
{
#if defined(PART_TM4C1233H6PM) || defined(PART_LM4F120H5QR)
	GPIO_PORTA_BASE, GPIO_PORTC_BASE, GPIO_PORTD_BASE, GPIO_PORTC_BASE,
	GPIO_PORTC_BASE, GPIO_PORTE_BASE, GPIO_PORTD_BASE, GPIO_PORTE_BASE
#elif defined(PART_TM4C129XNCZAD)
	GPIO_PORTA_BASE, GPIO_PORTQ_BASE, GPIO_PORTD_BASE, GPIO_PORTA_BASE,
	GPIO_PORTK_BASE, GPIO_PORTH_BASE, GPIO_PORTP_BASE, GPIO_PORTC_BASE
#elif defined(PART_TM4C1294NCPDT)
	GPIO_PORTA_BASE, GPIO_PORTB_BASE, GPIO_PORTA_BASE, GPIO_PORTA_BASE,
	GPIO_PORTK_BASE, GPIO_PORTC_BASE, GPIO_PORTP_BASE, GPIO_PORTC_BASE
#else
#error "**** No PART defined or unsupported PART ****"
#endif
};

static const unsigned long g_ulUARTPins[8] =
{
#if defined(PART_TM4C1233H6PM) || defined(PART_LM4F120H5QR)
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_4 | GPIO_PIN_5,
    GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_6 | GPIO_PIN_7,
    GPIO_PIN_4 | GPIO_PIN_5, GPIO_PIN_4 | GPIO_PIN_5,
    GPIO_PIN_4 | GPIO_PIN_5, GPIO_PIN_0 | GPIO_PIN_1
#elif defined(PART_TM4C129XNCZAD)
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_4 | GPIO_PIN_5,
    GPIO_PIN_4 | GPIO_PIN_5, GPIO_PIN_4 | GPIO_PIN_5,
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_6 | GPIO_PIN_7,
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_4 | GPIO_PIN_5
#elif defined(PART_TM4C1294NCPDT)
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_0 | GPIO_PIN_1,
    GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_4 | GPIO_PIN_5,
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_6 | GPIO_PIN_7,
    GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_4 | GPIO_PIN_5
#else
#error "**** No PART defined or unsupported PART ****"
#endif
};

// Constructors ////////////////////////////////////////////////////////////////
HardwareSerial::HardwareSerial(void)
{
    txWriteIndex = 0;
    txReadIndex = 0;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartModule = 0;

    txBuffer = (unsigned char *) 0xFFFFFFFF;
    rxBuffer = (unsigned char *) 0xFFFFFFFF;
    txBufferSize = SERIAL_BUFFER_SIZE;
    rxBufferSize = SERIAL_BUFFER_SIZE;
}

HardwareSerial::HardwareSerial(unsigned long module) 
{
    txWriteIndex = 0;
    txReadIndex = 0;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartModule = module;

    txBuffer = (unsigned char *) 0xFFFFFFFF;
    rxBuffer = (unsigned char *) 0xFFFFFFFF;
    txBufferSize = SERIAL_BUFFER_SIZE;
    rxBufferSize = SERIAL_BUFFER_SIZE;
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

                txReadIndex = (txReadIndex + 1) % txBufferSize;
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
	baudRate = baud;
    //
    // Initialize the UART.
    //
    ROM_SysCtlPeripheralEnable(g_ulUARTPeriph[uartModule]);

    //TODO:Add functionality for PinConfigure with variable uartModule
    ROM_GPIOPinConfigure(g_ulUARTConfig[uartModule][0]);
    ROM_GPIOPinConfigure(g_ulUARTConfig[uartModule][1]);

    ROM_GPIOPinTypeUART(g_ulUARTPort[uartModule], g_ulUARTPins[uartModule]);

    ROM_UARTConfigSetExpClk(UART_BASE, F_CPU, baudRate,
                            (UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_WLEN_8));
    //
    // Set the UART to interrupt whenever the TX FIFO is almost empty or
    // when any character is received.
    //
    ROM_UARTFIFOLevelSet(UART_BASE, UART_FIFO_TX1_8, UART_FIFO_RX1_8);
    flushAll();
    ROM_UARTIntDisable(UART_BASE, 0xFFFFFFFF);
    ROM_UARTIntEnable(UART_BASE, UART_INT_RX | UART_INT_RT);
    ROM_IntEnable(g_ulUARTInt[uartModule]);

    //
    // Enable the UART operation.
    //
    ROM_UARTEnable(UART_BASE);

    // Allocate TX & RX buffers
    if (txBuffer != (unsigned char *)0xFFFFFFFF)  // Catch attempts to re-init this Serial instance by freeing old buffer first
        free(txBuffer);
    if (rxBuffer != (unsigned char *)0xFFFFFFFF)  // Catch attempts to re-init this Serial instance by freeing old buffer first
        free(rxBuffer);
    txBuffer = (unsigned char *) malloc(txBufferSize);
    rxBuffer = (unsigned char *) malloc(rxBufferSize);

    SysCtlDelay(100);
}

void
HardwareSerial::setBufferSize(unsigned long txsize, unsigned long rxsize)
{
    if (txsize > 0)
        txBufferSize = txsize;
    if (rxsize > 0)
        rxBufferSize = rxsize;
}

void
HardwareSerial::setModule(unsigned long module)
{
    ROM_UARTIntDisable(UART_BASE, UART_INT_RX | UART_INT_RT);
    ROM_IntDisable(g_ulUARTInt[uartModule]);
	uartModule = module;
	begin(baudRate);

}
void 
HardwareSerial::setPins(unsigned long pins)
{
	if(pins == UART1_PORTB)
	{
		ROM_GPIOPinConfigure(GPIO_PB0_U1RX);
		ROM_GPIOPinConfigure(GPIO_PB1_U1TX);
		ROM_GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	}
	else
	{
		//Default UART1 Pin Muxing
		ROM_GPIOPinConfigure(g_ulUARTConfig[1][0]);
		ROM_GPIOPinConfigure(g_ulUARTConfig[1][1]);
		ROM_GPIOPinTypeUART(g_ulUARTPort[1], g_ulUARTPins[1]);
	}
}

HardwareSerial::operator bool()
{
	return true;
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
    ROM_UARTIntDisable(UART_BASE, UART_INT_RX | UART_INT_RT);
}

int HardwareSerial::available(void)
{
    return((rxWriteIndex >= rxReadIndex) ?
		(rxWriteIndex - rxReadIndex) : rxBufferSize - (rxReadIndex - rxWriteIndex));
}

int HardwareSerial::peek(void)
{
    unsigned char cChar = 0;

    //
    // Wait for a character to be received.
    //
    if(RX_BUFFER_EMPTY)
    {
    	return -1;
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
    if(RX_BUFFER_EMPTY) {
    	return -1;
    }

    //
    // Read a character from the buffer.
    //
    unsigned char cChar = rxBuffer[rxReadIndex];
	rxReadIndex = ((rxReadIndex) + 1) % rxBufferSize;
	return cChar;
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
/*
    //this is not necessary: https://github.com/energia/Energia/issues/225
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
		txWriteIndex = (txWriteIndex + 1) % txBufferSize;
        numTransmit ++;
    }
*/
    //
    // Send the character to the UART output.
    //
    while (TX_BUFFER_FULL);
    txBuffer[txWriteIndex] = c;
    txWriteIndex = (txWriteIndex + 1) % txBufferSize;
    numTransmit ++;

    //
    // If we have anything in the buffer, make sure that the UART is set
    // up to transmit it.
    //
    if(!TX_BUFFER_EMPTY)
    {
	    primeTransmit(UART_BASE);
        ROM_UARTIntEnable(UART_BASE, UART_INT_TX);
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
    ulInts = ROM_UARTIntStatus(UART_BASE, true);
    ROM_UARTIntClear(UART_BASE, ulInts);

    // Are we being interrupted because the TX FIFO has space available?
    //
    if(ulInts & UART_INT_TX)
    {
        //
        // Move as many bytes as we can into the transmit FIFO.
        //
        primeTransmit(UART_BASE);

        //
        // If the output buffer is empty, turn off the transmit interrupt.
        //
        if(TX_BUFFER_EMPTY)
        {
            ROM_UARTIntDisable(UART_BASE, UART_INT_TX);
        }
    }
    if(ulInts & (UART_INT_RX | UART_INT_RT))
    {
        while(ROM_UARTCharsAvail(UART_BASE))
            {

            //
            // Read a character
            //
            lChar = ROM_UARTCharGetNonBlocking(UART_BASE);
            //
            // If there is space in the receive buffer, put the character
            // there, otherwise throw it away.
            //
            uint8_t volatile full = RX_BUFFER_FULL;
            if(full) break;

            rxBuffer[rxWriteIndex] =
                (unsigned char)(lChar & 0xFF);
            rxWriteIndex = ((rxWriteIndex) + 1) % rxBufferSize;

            //
            // If we wrote anything to the transmit buffer, make sure it actually
            // gets transmitted.
            //
        }
        primeTransmit(UART_BASE);
        ROM_UARTIntEnable(UART_BASE, UART_INT_TX);
    }
}

void
UARTIntHandler(void)
{
    Serial.UARTIntHandler();
}

void
UARTIntHandler1(void)
{
    Serial1.UARTIntHandler();
}

void
UARTIntHandler2(void)
{
    Serial2.UARTIntHandler();
}

void
UARTIntHandler3(void)
{
    Serial3.UARTIntHandler();
}

void
UARTIntHandler4(void)
{
    Serial4.UARTIntHandler();
}

void
UARTIntHandler5(void)
{
    Serial5.UARTIntHandler();
}

void
UARTIntHandler6(void)
{
    Serial6.UARTIntHandler();
}

void
UARTIntHandler7(void)
{
    Serial7.UARTIntHandler();
}

void serialEvent() __attribute__((weak));
void serialEvent() {}
void serialEvent1() __attribute__((weak));
void serialEvent1() {}
void serialEvent2() __attribute__((weak));
void serialEvent2() {}
void serialEvent3() __attribute__((weak));
void serialEvent3() {}
void serialEvent4() __attribute__((weak));
void serialEvent4() {}
void serialEvent5() __attribute__((weak));
void serialEvent5() {}
void serialEvent6() __attribute__((weak));
void serialEvent6() {}
void serialEvent7() __attribute__((weak));
void serialEvent7() {}

void serialEventRun(void)
{
    if (Serial.available()) serialEvent();
    if (Serial1.available()) serialEvent1();
    if (Serial2.available()) serialEvent2();
    if (Serial3.available()) serialEvent3();
    if (Serial4.available()) serialEvent4();
    if (Serial5.available()) serialEvent5();
    if (Serial6.available()) serialEvent6();
    if (Serial7.available()) serialEvent7();
}

HardwareSerial Serial;
HardwareSerial Serial1(1);
HardwareSerial Serial2(2);
HardwareSerial Serial3(3);
HardwareSerial Serial4(4);
HardwareSerial Serial5(5);
HardwareSerial Serial6(6);
HardwareSerial Serial7(7);
