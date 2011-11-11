
/*
  ByteBuffer.h - A buffer for TWI/I2C communication
  Copyright (c) 2010 Eberhard Fahle

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

#ifdef __AVR_XMEGA__

#ifndef _WIREBUFFER_H_
#define _WIREBUFFER_H_

#include <inttypes.h>
#include <Arduino.h>

/** 
 * A very simple byte buffer class similar to the java.nio.ByteBuffer class
 */
class ByteBuffer {
 private:
    /* The maximum size of the buffer */
    int bufferSize;
    /* the data in the buffer */
    uint8_t* buffer;
    /* the limit of the buffer */
    int bufferLimit;
    /* the current read/write position of the buffer */
    int bufferPosition;

  public:
    /** 
     * Creates a new ByteBuffer. 
     * The memory for data stoarge is not initialized
     * until begin() is called.
     */
    ByteBuffer();
    
    /** 
     * Initializes the backup storage for the buffer.
     * @param size the maximum nuber of bytes that can be stored in the buffer
     * @return 0 on success. Returns -1 if we are not able to claim the 
     * necessary buffer memory.   
     */
    int begin(int size);
    
    /** 
     * Frees the data memory in the buffer. The buffer cannot used 
     * any more until you call begin(int size) again.
     * Does nothing if the buffer is not initialized.
     */
    void end();
    /** 
     * Clears the buffers contents. The position and limit will be set to 0.
     * Does nothing if the buffer is not initialized.
     */ 
    void clear();
    /** 
     * Sets the position to the begiining of the buffer.
     * Does nothing if the buffer is not initialized.
     */
    void flip();
    /** 
     * Gets the number of bytes that can be read from the buffer.
     * @return the number of bytes between the position and the limit
     * of the buffer. If the buffer is not initialized we return -1.
     */
    int remaining();
    /** 
     * Gets the current postion for reading or writing from/to the buffer.
     * @return The current position. If the buffer is not initalized
     * we return -1
     */
    int position();
    /** 
     * Gets the maximum size of the buffer.
     * @return the number of bytes that can be stored in the buffer.
     * If the buffer is not initalized we return -1
     */
    int size();

    /** 
     * Add a new byte to the data
     * @param data the byte to store in the buffer
     * @return 0 if the data was stored in the buffer. 
     * Returns -1 if the buffer is not initalized or there was not enough 
     * room for the byte to be stored.
     */
    int put(uint8_t data);
    /** 
     * Add a array of bytes to the data. If there is not
     * enough room in the buffer for the whole array the data is 
     * discarded and the buufers content remains unchanged.
     * @param data a pointer to the array of byte to be stored in the buffer
     * @param length the numner of bytes to be stored
     * @return 0 if the data was stored in the buffer. 
     * Returns -1 if the buffer is not initalized or there was not enough 
     * room for the byte to be stored.
     */
    int put(uint8_t* data, int length);
    
    /** 
     * Gets a single byte from the buffer
     * @return the byte a position if there is any data to read,
     * -1 otherwise
     */
    int get();

	int peek();
};

#endif

#endif // __AVR_XMEGA__

