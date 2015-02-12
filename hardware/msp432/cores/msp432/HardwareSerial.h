/*
  ************************************************************************
  * TimerSerial.h
  *
  * Arduino core files for TI-RTOS
  *     Copyright (c) 2012 Louis Peryea. All right reserved.
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

  Modified for MSP430 2012 by Robert Wessels

*/

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include <inttypes.h>
#include "Stream.h"

#include <ti/drivers/UART.h>

#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/gates/GateMutex.h>

#define SERIAL_BUFFER_SIZE     1024

class HardwareSerial : public Stream
{

    private:
        bool begun;
        unsigned char rxBuffer[SERIAL_BUFFER_SIZE];
        unsigned long rxWriteIndex;
        unsigned long rxReadIndex;
        unsigned long baudRate;
        uint8_t uartModule;
        UART_Handle uart;
        Semaphore_Struct rxSemaphore;
        void init(unsigned long);
        void flushAll(void);
        GateMutex_Struct gate;

    public:
        HardwareSerial(void);
        HardwareSerial(unsigned long);
        void begin(unsigned long);
        void setModule(unsigned long);
        void setPins(unsigned long);
        void sieze(void);  /* sieze serial port for this thread */
        void release(void);  /* release serial port */
        void end(void);
        virtual int available(void);
        virtual int peek(void);
        virtual int read(void);
        virtual void flush(void);
        void readCallback(UART_Handle uart, void *buf, size_t count);
        virtual size_t write(uint8_t c);
        using Print::write; // pull in write(str) and write(buf, size) from Print
        
};

//Create new HardwareSerial called Serial for use in Sketch.
extern HardwareSerial Serial;

//I should delete this, but i need to check first
extern void serialEventRun(void) __attribute__((weak));
#endif
