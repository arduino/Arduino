/*
 ***********************************************************************
 *  HardwareSerial.cpp
 *
 *  Arduino core files for TI-RTOS
 *      Copyright (c) 2013 Louis Peryea. All right reserved.
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
  Modified for MSP430 2012 by Robert Wessels
  Modified for TI-RTOS 2013 by Louis Peryea

 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wiring_private.h"
#include "HardwareSerial.h"

#define RX_BUFFER_EMPTY   (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL    (((rxWriteIndex + 1) % SERIAL_BUFFER_SIZE) == rxReadIndex)

void uartReadCallback(UART_Handle uart, void *buf, size_t count);

HardwareSerial::HardwareSerial(void)
{
    begun = false;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartModule = 0;
}

HardwareSerial::HardwareSerial(unsigned long module)
{
    begun = false;
    rxWriteIndex = 0;
    rxReadIndex = 0;
    uartModule = module;
}

/*
 * Private Methods
 */
void HardwareSerial::flushAll(void)
{
}

/*
 * Public Methods
 */
void HardwareSerial::begin(unsigned long baud)
{
    UART_Params uartParams;

    if (begun == TRUE) return;

    Semaphore_construct(&rxSemaphore, 0, NULL);

    Board_initUART();

    baudRate = baud;

    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.readCallback = uartReadCallback;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = baud;

    uart = UART_open(Board_UART, &uartParams);

    /* start the read process */
    UART_read(uart, &rxBuffer[rxWriteIndex], 1);

    if (uart == NULL) {
        //System_abort("Error opening the UART");
    }

    GateMutex_construct(&gate, NULL);
    begun = TRUE;
}

void HardwareSerial::setModule(unsigned long module)
{
    /* Change which pins UART is on */
    /* need to implement */
}

void HardwareSerial::setPins(unsigned long pins)
{
    /* almost same functionality as above */
}

void HardwareSerial::sieze(void)
{
    GateMutex_enter(GateMutex_handle(&gate));
}

void HardwareSerial::release(void)
{
    GateMutex_leave(GateMutex_handle(&gate), 0);
}

void HardwareSerial::end(void)
{
    begun = false;
    UART_close(uart);
}

int HardwareSerial::available(void)
{
    if (RX_BUFFER_EMPTY) {
        /* kick off another character read operation */
        UART_read(uart, &rxBuffer[rxWriteIndex], 1);
    }

    return (rxWriteIndex >= rxReadIndex) ?
        (rxWriteIndex - rxReadIndex) : SERIAL_BUFFER_SIZE - (rxReadIndex - rxWriteIndex);
}

int HardwareSerial::peek(void)
{
    unsigned char cChar = 0;

    if (available() == 0) {
        return (-1);
    }

    /* Read a character from the buffer. */
    cChar = rxBuffer[rxReadIndex];

    /* Return the character to the caller. */
    return (cChar);
}

int HardwareSerial::read(void)
{
    int iChar;
    unsigned int hwiKey;

    while ((iChar = peek()) < 0) {
        Semaphore_pend(Semaphore_handle(&rxSemaphore), BIOS_WAIT_FOREVER);
    }

    hwiKey = Hwi_disable();

    rxReadIndex = ((rxReadIndex) + 1) % SERIAL_BUFFER_SIZE;

    Hwi_restore(hwiKey);

    return (iChar);
}

void HardwareSerial::flush()
{
}

size_t HardwareSerial::write(uint8_t c)
{
    UART_write(uart,(char*)&c,1);
    return (1);
}

void HardwareSerial::readCallback(UART_Handle uart, void *buf, size_t count)
{
    uint8_t volatile full = RX_BUFFER_FULL;

    rxWriteIndex = ((rxWriteIndex) + 1) % SERIAL_BUFFER_SIZE;

    if (full) {
        rxReadIndex = ((rxReadIndex) + 1) % SERIAL_BUFFER_SIZE;
    }

    Semaphore_post(Semaphore_handle(&rxSemaphore));
}

/* C type function to call the thing above */
void uartReadCallback(UART_Handle uart, void *buf, size_t count)
{
    Serial.readCallback(uart, buf, count);
}


void serialEvent() __attribute__((weak));
void serialEvent() { }

void serialEventRun(void)
{
    if (Serial.available()) {
        serialEvent();
    }
}

HardwareSerial Serial;
