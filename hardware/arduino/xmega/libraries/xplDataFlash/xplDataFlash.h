/*
 * This file is part of xmlibraries.
 * xmlibraries is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xmlibraries is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2010 Eberhard Fahle <e.fahle@wayoda.org>
 */
#ifndef _XPLDATAFLASH_H_
#define _XPLDATAFLASH_H_

#include "Arduino.h"
#include <stdint.h>
#include <avr/io.h>

/** 
 * A class that simplifies the access to the dataflash chip 
 * on a XPlain board. 
 */
class xplDataFlash {
 public:
    const static int SECURITY_BUFFER_SIZE;
    const static int BUFFER_ID_1;
    const static int BUFFER_ID_2;
    const static int DATAFLASH_PAGES;
 private: 
    
    /** The manufacturer ID of the DataFlash */
    int vendorId;
    /** The deviceId of the DataFlash */
    int deviceId;
    /** The number of bytes on a DataFlash page */
    int pageSize;
    /** The number of bytes on the device */
    uint32_t size;
    /** 
     * The number of the next page that will be refreshed
     * to insure data integrity 
     */
    long refreshCounter;
    
 public:
    /**
     * Creates an instance of a xplDataFlash. Initializes 
     * SPI on port C where the DataFlash is connected.
     * The we read the contents of the manufacturer
     * and device ID and run a test to detect the pagesize
     * used on the chip.
     */
    xplDataFlash();

    /**
     * Returns the pagesize used for the device
     * @return the number of bytes in a page. 
     */
    int getPageSize();

    /**
     * Writes data into one of the internal buffers of the DataFlash
     * @param bufferID selects the buffer that is to be written.
     * This must be one of the constants xplDataFlash::BUFFER_ID_1 or  
     * xplDataFlash::BUFFER_ID_2 
     * @param bufferAddr the address of the first byte in the buffer to write.
     * @param data a pointer to the data to be written 
     * @param count the number of data bytes to write
     */
    int writeBuffer(int bufferID, int addr, 
		    uint8_t *data, int length);

    /**
     * Read data from one of the internal buffers of the DataFlash
     * @param bufferID selects the buffer from which the data is read.
     * This must be one of the constants xplDataFlash::BUFFER_ID_1 or  
     * xplDataFlash::BUFFER_ID_2 
     * @param bufferAddr the address where we start to read 
     * in the buffer.
     * @param data a pointer to a buffer where the data to be stored 
     * @param count the number of bytes to read
     */
    int readBuffer(int bufferID, int addr, 
		    uint8_t *data, int length);
    
    /**
     * Clear one of the internal buffers.
     * @param bufferID selects the buffer which is to be cleared.
     * This must be one of the constants xplDataFlash::BUFFER_ID_1 or  
     * xplDataFlash::BUFFER_ID_2 
     * @param value the value to use for claering the buffer
     */
    int clearBuffer(int bufferID, uint8_t value=0x00);

    /**
     * Writes raw bytes to the data flash.
     * @param address the address to which the data is to be written
     * @param data a pointer to the data to be written
     * @param length the number of bytes to write
     * @return 0 if the data was sucessfully written,
     * -1 otherwise.
     */
    int write(uint32_t address, uint8_t *data, int length);

    /**
     * Reads raw bytes from the data flash into a buffer.
     * @param address the address from which the data is to be read
     * @param data a pointer to a buffer into which the data is copied
     * @param length the number of bytes to read
     * @return the number of bytes read, -1 otherwise.
     */
    int read(uint32_t address, uint8_t *data, int length);
    
    /**
     * Erase all pages int the DataFlash that are not write protected.
     * This will erase all data on the device, by writing
     * 0xFF into every postion that is not write protected
     * by eithzer software of hardware. 
     * This will take quite some time, 
     * 28.6 seconds on my XPlain board.
     */
    void chipErase();
    
    /**
     * Gets the manufacturer ID of the device
     * @return int the manufacturer ID of the DataFlash 
     */
    int getManufacturerId();

    /**
     * Gets the device ID of the device
     * @return the device ID of the DataFlash
     */
    int getDeviceId();

    /**
     * Reads the status register of the DataFlash.
     * @return Returns the setting of the status register.
     */
    uint8_t getStatus();

    /**
     * Waits until the RDY/BUSY flag in the status 
     * register of the DataFlash is 1 (RDY).
     * @return Returns the setting of the status register.
     */
    uint8_t waitForStatusReady();

    /**
     * Read the contents of the DataFlash security register
     * @param buffer a pointer to a preallocated buffer
     * into which the security register data will be copied
     */
    void getSecurityRegister(uint8_t *buffer);

 private:
    /**
     * Reads the manufacturer and product ID from the 
     * DataFlash. 
     */
    void getID(); 

    /**
     * Refreshes a page in the DataFlash to ensure 
     * data integrity. The operation takes about 20ms.
     * @param page the page to refresh.
     */
    void spiRefreshPage(long page);

    /**
     * Low-level communication with the DataFlash.
     * @param cmd the cmd data to be clocked out.
     * @param cmdLength the length of the command data
     * @param data the data that is returned from the DataFlash
     * @param length the number of bytes to transceive
     */
    void spiRead(uint8_t cmd[], int cmdLength, uint8_t data[], int length);
    
    /**
     * Low-level communication with the DataFlash.
     * write data to the device.
     * @param cmd the cmd data to be clocked out.
     * @param cmdLength the length of the command data
     * @param data the data to be writen to the DataFlash
     * @param length the number of bytes in the data
     */
    void spiWrite(uint8_t cmd[], int cmdLength, uint8_t data[], int length);

    /**
     * Low-level communication with the DataFlash.
     * write a fixed value to a page on the device.
     * @param cmd the cmd data to be clocked out.
     * @param cmdLength the length of the command data.
     * @param value the value to be written to the DataFlash
     * @param length the number of values to be written
     */ 
    void spiFill(uint8_t cmd[], int cmdLength, uint8_t data, int length);

    /**
     * Low-level communication with the DataFlash.
     * Copy a page in the DataFlash to one of the buffers.
     * @param buffer the bufferId into which the page is to be copied.
     * @param page the number of the page to be copied.
     */ 
    void spiPageToBuffer(int buffer, int page);

    /**
     * Low-level communication with the DataFlash.
     * Copy the contents of a buffer into a page in the DataFlash.
     * @param buffer the bufferId from which the data is to be copied.
     * @param page the number of the page to be updated with the buffers content.
     */ 
    void spiBufferToPage(int buffer, int page);
    
    /**
     * Tests the pagesize used on this DataFlash chip.
     * @return the size of a page on this chip in bytes.
     */
    int pageSizeDetect();
};


#endif
