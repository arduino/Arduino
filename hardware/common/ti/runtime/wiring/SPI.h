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

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <inttypes.h>
#include <stdio.h>

#include <ti/drivers/SPI.h>
#include <ti/sysbios/gates/GateMutex.h>

#define SPI_MODE0 SPI_POL0_PHA0
#define SPI_MODE1 SPI_POL0_PHA1
#define SPI_MODE2 SPI_POL1_PHA0
#define SPI_MODE3 SPI_POL1_PHA1

#define MSBFIRST 1
#define LSBFIRST 0

#define SPI_CLOCK_MAX 16000000L
#define SPI_CLOCK_DIV1 1
#define SPI_CLOCK_DIV2 2
#define SPI_CLOCK_DIV4 4
#define SPI_CLOCK_DIV8 8
#define SPI_CLOCK_DIV16 16
#define SPI_CLOCK_DIV32 32

class SPIClass
{
    private:
        bool begun;
        uint8_t slaveSelect;
        uint8_t spiModule;
        uint8_t bitOrder;
        uint8_t dataMode;
        uint8_t clockDivider;
        SPI_Handle spi;
        SPI_Params params;
        SPI_Transaction transaction;
        GateMutex_Struct gate;
        void init(unsigned long);

    public:
        SPIClass(void);
        SPIClass(unsigned long);
        void begin(); // Default
        void begin(uint8_t);
        void end();
        void end(uint8_t);

        void setBitOrder(uint8_t);
        void setBitOrder(uint8_t, uint8_t);

        void setDataMode(uint8_t);
        void setClockDivider(uint8_t);

        uint8_t transfer(uint8_t);
        uint8_t transfer(uint8_t, uint8_t);
        uint8_t transfer(uint8_t, uint8_t, uint8_t);

        void setModule(uint8_t);
};

extern SPIClass SPI;

#endif
