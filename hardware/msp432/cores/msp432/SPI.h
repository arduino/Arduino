/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <inttypes.h>
#include <stdio.h>

#include <ti/drivers/SPI.h>

class SPIClass
{
    private:
        bool begun;
        uint8_t slaveSelect;
        uint8_t spiModule;
        SPI_Handle spi;
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
