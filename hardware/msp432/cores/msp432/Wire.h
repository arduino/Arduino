/*
  ************************************************************************
  * Wire.h
  *
  * Arduino core files for TI-RTOS
  *     Copyright (c) 2013 Louis Peryea. All right reserved.
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
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
#include "Stream.h"

#include <ti/drivers/I2C.h>
#include <ti/sysbios/gates/GateMutex.h>

#define BUFFER_LENGTH     64

#define IDLE 0
#define MASTER_TX 1
#define MASTER_RX 2
#define SLAVE_RX 3

#define BOOST_PACK_WIRE 0

class TwoWire : public Stream
{
    private:
        bool begun;
        uint8_t rxBuffer[BUFFER_LENGTH];
        uint8_t rxReadIndex;
        uint8_t rxWriteIndex;

        uint8_t txBuffer[BUFFER_LENGTH];
        uint8_t txReadIndex;
        uint8_t txWriteIndex;

        uint8_t i2cModule;

        bool idle;

        I2C_Handle i2c;
        I2C_Transaction i2cTransaction;

        GateMutex_Struct gate;

        void (*user_onRequest)(void);
        void (*user_onReceive)(int);
        void onRequestService(void);
        void onReceiveService(uint8_t*, int);
        void init(unsigned long);
        void forceStop(void);

    public:
        TwoWire(void);
        TwoWire(unsigned long);
        void begin();
        void begin(uint8_t);
        void begin(int);
        void beginTransmission(uint8_t);
        void beginTransmission(int);
        void end(void);
        uint8_t endTransmission(void);
        uint8_t endTransmission(uint8_t);
        uint8_t requestFrom(uint8_t, uint8_t);
        uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
        uint8_t requestFrom(int, int);
        uint8_t requestFrom(int, int, int);
        virtual size_t write(uint8_t);
        virtual size_t write(const uint8_t *, size_t);
        virtual int available(void);
        virtual int read(void);
        virtual int peek(void);
        virtual void flush(void);
        void onReceive( void (*)(int) );
        void onRequest( void (*)(void) );

        inline size_t write(unsigned long n) { return write((uint8_t)n); }
        inline size_t write(long n) { return write((uint8_t)n); }
        inline size_t write(unsigned int n) { return write((uint8_t)n); }
        inline size_t write(int n) { return write((uint8_t)n); }

        using Print::write;

        void setModule(unsigned long);

};

extern TwoWire Wire;
extern "C" void I2CIntHandler(void);
#endif
