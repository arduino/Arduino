/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

typedef struct WireContext {
    I2C_Transaction i2cTransaction;
    uint8_t rxBuffer[BUFFER_LENGTH];
    uint8_t rxReadIndex;
    uint8_t rxWriteIndex;

    uint8_t txBuffer[BUFFER_LENGTH];
    uint8_t txReadIndex;
    uint8_t txWriteIndex;

    bool idle;
} WireContext;

class TwoWire : public Stream
{
    private:
        bool begun;

        uint8_t i2cModule;
        I2C_Handle i2c;

        GateMutex_Struct gate;
        uint8_t gateEnterCount;

        void (*user_onRequest)(void);
        void (*user_onReceive)(int);
        void onRequestService(void);
        void onReceiveService(uint8_t*, int);
        void init(unsigned long);
        void forceStop(void);
        WireContext *getWireContext(void);

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
