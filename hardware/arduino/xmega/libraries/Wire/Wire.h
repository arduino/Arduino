/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
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

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
#include "Stream.h"

#if !defined(__AVR_XMEGA__)

#define BUFFER_LENGTH 32

class TwoWire : public Stream
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire();
    void begin();
    void begin(uint8_t);
    void begin(int);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
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
};

extern TwoWire Wire;

#else // __AVT_XMEGA__

#include "Arduino.h"
#include <avr/io.h>
#include <inttypes.h>

#include "ByteBuffer.h"

/** 
 * Error code reported by a xmWire class method :
 * The last operation did not raise an error
 */
#define TWI_SUCCESS 0
/** 
 * Error code reported by a xmWire class method :
 * You cannot start a new IO operation, the last one
 * hasn't terminated yet. 
 */
#define TWI_BUSY 1
/** 
 * Error code reported by a xmWire class method :
 * The slave address was outside the valid range 
 * 1..127 or 0x01..0x7F  
 */
#define TWI_SLAVE_ADDRESS_INVALID 2
/** 
 * Error code reported by a xmWire class method :
 * The size of your request to send or receive would 
 * overflow the internal buffer.
 */
#define TWI_OUT_OF_MEMORY 3
/** 
 * Error code reported by a xmWire class method :
 *
 */
#define TWI_BUS_ARBITRATION_LOST 4
/** 
 * Error code reported by a xmWire class method :
 * Transmission has terminated because a TWI bus error
 * was detected.
 */
#define TWI_BUS_ERROR 5
/** 
 * Error code reported by a xmWire class method :
 * The slave did not ACK the data written to it.
 */
#define TWI_NACK 6
/** 
 * Error code reported by a xmWire class method :
 * Internal error when creating an instance of xmWire  
 */
#define TWI_ERROR_PORT 7
/** 
 * Error code reported by a xmWire class method :
 * The argument for speed selection in begin was not 
 * one of the constants
 * xmWire::TWI_SPEED_100000 or xmWire::TWI_SPEED_400000 
 */
#define TWI_ERROR_SPEED 8
/** 
 * Error code reported by a xmWire class method when setting up 
 * in slave mode :
 * The slave address is outside the valid range 
 * 1..127 or 0x01..0x7F  
 */
#define TWI_ERROR_ADDRESS 9
/** 
 * Error code reported by a xmWire class method :
 * The size of the internal buffers must be >=0
 */
#define TWI_ERROR_BUFFERSIZE 10
/** 
 * Error code reported by a xmWire class method :
 * You tried to add data to a sendbuffer, but no transmission
 * is in progress.
 */
#define TWI_NOT_TRANSMITTING 11
/** 
 * Error code reported by a xmWire class method :
 * This has to be implemented in  a future release.
 */
#define TWI_NOT_IMPLEMENTED 100

#ifndef F_CPU
#define F_CPU 32000000UL
#endif

class xmWire : public Stream {
 public:
    /** 
     * Constant default size of the send/receive buffer 
     */
    const static int DEFAULT_BUFFER_SIZE;
    /** 
     * Constant for a port on an atxmega that provides a TWI :
     * Value for the TWI on Port C
     */
    const static uint8_t TWI_PORT_C;
    /** 
     * Constant for a port on an atxmega that provides a TWI :
     * Value for the TWI on Port D
     */
    const static uint8_t TWI_PORT_D;
    /** 
     * Constant for a port on an atxmega that provides a TWI :
     * Value for the TWI on Port E
     */
    const static uint8_t TWI_PORT_E;
    /** 
     * Constant for a port on an atxmega that provides a TWI :
     * Value for the TWI on Port F
     */
    const static uint8_t TWI_PORT_F;
    /** 
     * Constant for the transmission speed of the TWI :
     * Transmission should work at 100kHz
     */
    const static uint8_t TWI_SPEED_100000;
    /** 
     * Constant for the transmission speed of the TWI :
     * Transmission should work at 100kHz
     */
    const static uint8_t TWI_SPEED_400000;

    
 private:
    /* constant signals an invalid port setting */ 
    const static uint8_t TWI_PORT_NA;
    /* The port on which we are located */
    uint8_t port;
    /* The speed we use */
    uint8_t speed;
    /* The size of the internal buffers for send and receive */
    int bufferSize;
    /** 
     * The TWI address of this instance. 
     * If the address is 0, we are a bus master
     */
    uint8_t address;
    /** 
     * When we transmitt data to a slave this is 
     * the address of the slave.
     */
    uint8_t slaveAddress;
    /** 
     * When we read data from a slave this is 
     * the number of bytes we expect in the 
     * current transmission 
     */
    int slaveReadSize;

    /** 
     * A pointer to the TWI port we are using
     */
    TWI_t *twi;

    /** A buffer for outgoing the data */
    ByteBuffer sendBuffer;
    /** A buffer for incoming data */
    ByteBuffer receiveBuffer;

    /** The result of the last operation */
    volatile int twiResult;
    /** True if the bus is currently busy */
    //    volatile boolean busy;
     
  public:
    /** 
     * Create a new instance of a TWI port
     * @param port the port on the xmega to use
     */
    xmWire(uint8_t port);
    /** 
     * Start the TWI port in master mode
     * @param speed the speed to use for TWI transmissions
     * @param bufferSize the size of the internal send and receive buffers
     * @return TWI_ERROR_PORT if you specified an invalid 
     * port in the constructor<br>
     * Returns TWI_ERROR_BUFFERSIZE if the buffersize is invalid<=0<br>
     * Returns TWI_OUT_OF_MEMORY if we had encounter an out of memory 
     * when creating the buffers<br>
     * Returns TWI_ERROR_SPEED if speed was set to an unknown value
     */
    int begin(uint8_t speed=TWI_SPEED_100000, 
	      int bufferSize=DEFAULT_BUFFER_SIZE);
    
    /** 
     * Start the TWI port in slave mode.
     * @param address the address we will listen to as a slave
     * @param speed the speed to use for TWI transmissions
     * @param bufferSize the size of the internal send and receive buffers
     * @return TWI_ERROR_PORT if you specified an invalid 
     * port in the constructor<br>
     * Returns TWI_ERROR_BUFFERSIZE if the buffersize is invalid<=0<br>
     * Returns TWI_OUT_OF_MEMORY if we had encounter an out of memory 
     * when creating the buffers<br>
     * Returns TWI_ERROR_SPEED if speed was set to an unknown value
     * Returns TWI_ERROR_ADDRESS if the address is not in nthe range
     * 1..127.
     */
    int begin(uint8_t address,
	      uint8_t speed=TWI_SPEED_100000, 
	      int bufferSize=DEFAULT_BUFFER_SIZE);

    /** 
     * Begin a transmission to a slave device.
     * @param slaveAddress the address on which the slave is listening
     * Subsequently, queue bytes for transmission with the send() 
     * function and transmit them by calling endTransmission() or repeatedStart(). 
     * @return TWI_SUCCESS if a new transmission was started.
     * Returns TWI_ERROR_ADDRESS if slaveAddress is not in range 1...127
     * Returns TWI_BUSY if processing the last transmission hasn't 
     * terminated yet.
     */
    int beginTransmission(uint8_t slaveAddress);

    /** 
     * Ends a transmission to a slave device that was begun by beginTransmission()
     * and actually transmits the bytes that were queued by send().
     * @param expectedByteCount if readcount is  greater 0, we send a repeated start condition
     * down the wire and try to read readCount bytes from the slave.
     * @return 0 on success
     */
    int endTransmission(int expectedByteCount=0);

    /** 
     * Request bytes from a slave device. 
     * @param slaveAddress the address on which the slave is listening
     * @param expectedByteCount the number of bytes we expect the slave to return.
     * @return TWI_SUCCESS if the request is send to the slave. Returns
     * TWI_ERROR_ADDRESS if slaveAddress is not in range 1...127.
     */
    int requestFrom(uint8_t slaveAddress, int expectedByteCount);

    /** 
     * Queues a byte for a transmission from a master to slave device. 
     * @param value to value to send.
     */
    virtual size_t write(uint8_t value);

    /** 
     * Queues a array of bytes for a transmission from a master to slave device. 
     * @param data a pointer to the data to send.
     * @return the length of the data in bytes
     * @return 0 on success, TWI_OUT_OF_MEMORY if the sendbuffer would overflow
     */
    virtual size_t write(const uint8_t *data, size_t quantity);

    /** 
     * Gets the result of the last bus activity.
     * @return int the result of the last IO action
     * on the TWI bus. This value is reset to TWI_SUCCESS
     * every time a new transmission is started
     */
    int transmissionResult();

    /** 
     * Tests wether the TWI bus is currently IDLE
     * @return true if the TWI bus is in idle state
     */
    boolean ready();
      
    /** 
     * Gets the number unread bytes in the internal receive buffer.
     * @return The number of unread bytes in the internal receive buffer
     */
    virtual int available(void);

    /** 
     * Get a single byte from the receive-buffer. This method can only 
     * be called safely when a previous call to available returned
     * at value >=1.
     * @return the first unread byte value from the receive buffer
     */
    uint8_t receive(void);

    virtual int read(void);
    virtual int peek(void);
	virtual void flush(void);

    /** 
     * Our internal interrupt handler
     */
    void onMasterInterrupt();

    using Print::write;
};

extern xmWire xmWireC;
extern xmWire xmWireD;
extern xmWire xmWireE;
extern xmWire xmWireF;

#endif // __AVR_XMEGA__

#endif

