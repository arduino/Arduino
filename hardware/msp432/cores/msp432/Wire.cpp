/*
 ************************************************************************
 *  TwoWire.cpp
 *
 *  Arduino core files for TI-RTOS
 *      Copyright (c) 2013 Louis Peryea. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:
  TwoWire.cpp - Hardware serial library for Wiring
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
  Modified for MSP430 by Robert Wessels
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wiring_private.h"
#include "Wire.h"


#define TX_BUFFER_EMPTY    (txReadIndex == txWriteIndex)
#define TX_BUFFER_FULL     (((txWriteIndex + 1) % BUFFER_LENGTH) == txReadIndex)

#define RX_BUFFER_EMPTY    (rxReadIndex == rxWriteIndex)
#define RX_BUFFER_FULL     (((rxWriteIndex + 1) % BUFFER_LENGTH) == rxReadIndex)

#define RUN_BIT     0x1
#define START_BIT   0x2
#define STOP_BIT    0x4
#define ACK_BIT     0x8

#define NOT_ACTIVE  0xA

TwoWire::TwoWire()
{
    begun = FALSE;

    i2cModule = NOT_ACTIVE;

    /* Read / Write buffer indexes */
    rxReadIndex = 0;
    rxWriteIndex = 0;
    txReadIndex = 0;
    txWriteIndex = 0;

    idle = true;

    /* I2C Transfer initial params */
    i2cTransaction.slaveAddress = 0;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.readBuf = rxBuffer;
    i2cTransaction.readCount = 0;
    i2cTransaction.writeCount = 0;
}

TwoWire::TwoWire(unsigned long module)
{
    begun = FALSE;

    i2cModule = module;

    /* Read / Write buffer indexes */
    rxReadIndex = 0;
    rxWriteIndex = 0;
    txReadIndex = 0;
    txWriteIndex = 0;

    idle = true;

    /* I2C Transfer initial params */
    i2cTransaction.slaveAddress = 0;
    i2cTransaction.writeBuf = txBuffer;
    i2cTransaction.readBuf = rxBuffer;
    i2cTransaction.readCount = 0;
    i2cTransaction.writeCount = 0;
}

/*
 * Private Methods
 */

void TwoWire::forceStop(void)
{
    //this has been removed so i can remove the pin map that used to be at the top of this file
}

// Public Methods //////////////////////////////////////////////////////////////

// Initialize as a master
void TwoWire::begin(void)
{
    I2C_Params params;

    /* return if I2C already started */
    if (begun == TRUE) return;

    if (i2cModule == NOT_ACTIVE) {
        i2cModule = BOOST_PACK_WIRE;
    }

    Board_initI2C();
    I2C_Params_init(&params);
    params.transferMode = I2C_MODE_BLOCKING;
    params.bitRate = I2C_400kHz;
    i2c = I2C_open(i2cModule, &params);

    GateMutex_construct(&gate, NULL);
    begun = TRUE;
}

//Save slave address for use in I2C_Transaction
void TwoWire::begin(uint8_t address)
{
    i2cTransaction.slaveAddress = address;
    begin();
}

void TwoWire::begin(int address)
{
    begin((uint8_t)address);
}

void TwoWire::end()
{
    begun = false;
    I2C_close(i2c);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
    if (quantity > BUFFER_LENGTH) {
        quantity = BUFFER_LENGTH;
    }
    if (!quantity) {
        return (0);
    }

    beginTransmission(address);

    i2cTransaction.readCount = quantity;

    if (sendStop) {
        /* if != 0; then error occured */
        return (endTransmission(sendStop) ? 0 : quantity);
    }

    return (quantity);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
    return (requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true));
}
uint8_t TwoWire::requestFrom(int address, int quantity)
{
    return (requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true));
}
uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
    return (requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop));
}

void TwoWire::beginTransmission(uint8_t address)
{
    GateMutex_enter(GateMutex_handle(&gate));

    if (idle) {
        i2cTransaction.slaveAddress = address;
        idle = false;
    }
}

void TwoWire::beginTransmission(int address)
{
    beginTransmission((uint8_t)address);
}

uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
    bool ret;

    ret = I2C_transfer(i2c, &i2cTransaction);

    txWriteIndex = 0;

    i2cTransaction.writeCount = 0;
    rxReadIndex = 0; //i2cTransaction will overwrite buffer staring at 0
    rxWriteIndex = i2cTransaction.readCount;

    i2cTransaction.readCount = 0;

    if (sendStop) {
        idle = true;

        if (rxReadIndex == 0) {
            GateMutex_leave(GateMutex_handle(&gate), 0);
        }
    }

    /* success = 0; 4 = other error */
    return (ret ? 0 : 4);
}

//  This provides backwards compatibility with the original
//  definition, and expected behaviour, of endTransmission
//
uint8_t TwoWire::endTransmission(void)
{
    return (endTransmission(true));
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(uint8_t data)
{
    // if(transmitting){
    // in master transmitter mode
    // don't bother if buffer is full
    if (TX_BUFFER_FULL){
        setWriteError();
        return 0;
    }

    // put byte in tx buffer
    txBuffer[txWriteIndex] = data;
    txWriteIndex = (txWriteIndex + 1) % BUFFER_LENGTH;
    i2cTransaction.writeCount = txWriteIndex;

    return (1);
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
    for(size_t i = 0; i < quantity; i++){
        write(data[i]);
    }
    return (quantity);
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::available(void)
{
//    return(rxWriteIndex);
    return (1);
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::read(void)
{
    int value = -1;
  
    // get each successive byte on each call
    if (rxReadIndex <= BUFFER_LENGTH) {
        value = rxBuffer[rxReadIndex];
        rxReadIndex = (rxReadIndex + 1) % BUFFER_LENGTH;
    }

    if (rxReadIndex == 0) {
        GateMutex_leave(GateMutex_handle(&gate), 0);
    }

    return (value);
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::peek(void)
{
    int value = -1;
  
    if(!RX_BUFFER_EMPTY){
        value = rxBuffer[rxReadIndex];
    }
    
    return (value);
}
void TwoWire::flush(void)
{
    txWriteIndex = 0;
    rxReadIndex = rxWriteIndex;
}

// sets function called on slave write
// we can use a call back for this
void TwoWire::onReceive( void (*function)(int) )
{
    user_onReceive = function;
}

// sets function called on slave read
void TwoWire::onRequest( void (*function)(void) )
{
    user_onRequest = function;
}

void TwoWire::setModule(unsigned long _i2cModule)
{
    i2cModule = _i2cModule;
    if (i2cTransaction.slaveAddress != 0) {
        begin(i2cTransaction.slaveAddress);
    }
    else {
        begin();
    }
}

//Pre-instantiate Object
TwoWire Wire;
