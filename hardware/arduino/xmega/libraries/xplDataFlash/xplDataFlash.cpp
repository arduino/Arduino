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
#include "xplDataFlash.h"

const int xplDataFlash::SECURITY_BUFFER_SIZE=128;
const int xplDataFlash::BUFFER_ID_1=1;
const int xplDataFlash::BUFFER_ID_2=2;
const int xplDataFlash::DATAFLASH_PAGES=8192;

xplDataFlash::xplDataFlash() {
    /*
      Init the SPI-module

      The /CS signal on the DataFlash is 
      connected to Pin PC1. We configure
      the pin as an output and pull it HIGH
    */
    PORTC.DIRSET=PIN1_bm;
    PORTC.PIN1CTRL=PORT_OPC_WIREDANDPULL_gc;
    PORTC.OUTSET=PIN1_bm;
    
    /*
      The MOSI and CLK pins have to be set as outputs
    */
    PORTC.DIRSET=0x20 | 0x80;

    /*
      Set SPI CTRL register to:
      - normal speed operation
      -  enabled 
      - transmission is MSB first
      - We are the SPI-Master
      - SPI uses MODE 3 (default on DataFlash)
      - PreScaler is PeripheralClock/4 
    */
    SPIC.CTRL=SPI_MASTER_bm | SPI_ENABLE_bm | SPI_MODE1_bm | SPI_MODE0_bm;
    
    /* read the static device ID */
    getID();
    /* we start the refresh counter on a random page */
    this->refreshCounter=random(0,DATAFLASH_PAGES);
    /* now do a test for the pagesize used on this board */
    this->pageSize=pageSizeDetect();
    this->size=(uint32_t)pageSize*(uint32_t)DATAFLASH_PAGES;
}

int xplDataFlash::writeBuffer(int bufferID, int addr, 
			      uint8_t *data, int length) {
    uint8_t cmd[4];
    if(bufferID=BUFFER_ID_1) {
	cmd[0]=0x84;
    }
    else if(bufferID=BUFFER_ID_2) {
	cmd[0]=0x87;
    }
    else {
	/* invalid buffer number */
	return -2;
    }
    if(addr>=pageSize) {
	/* address exceeds buffer size */
	return -3;
    }
    else if((addr+length)>pageSize) {
	/* We stop writing bytes at the end of the buffer */
	length=pageSize-addr;
    }
    cmd[1]=0x00;
    cmd[2]=(uint8_t)((addr>>8) & 0x07);
    cmd[3]=(uint8_t)(addr & 0xFF);
    spiWrite(cmd,4,data,length);
    return length;
}

int xplDataFlash::readBuffer(int bufferID, int addr, 
			     uint8_t *data, int length) {
    uint8_t cmd[4];
    if(bufferID=BUFFER_ID_1) {
	cmd[0]=0xD4;
    }
    else if(bufferID=BUFFER_ID_2) {
	cmd[0]=0xD6;
    }
    else {
	/* invalid buffer number */
	return -2;
    }
    if(addr>=pageSize) {
	/* address exceeds buffer size */
	return -3;
    }
    else if((addr+length)>pageSize) {
	/* We only read to the buffers end */
	length=pageSize-addr;
    }
    cmd[1]=0x00;
    cmd[2]=(uint8_t)((addr>>8) & 0x07);
    cmd[3]=(uint8_t)(addr & 0xFF);
    spiRead(cmd,4,data,length);
    return length;
}

int xplDataFlash::clearBuffer(int bufferID, uint8_t value) {
    uint8_t cmd[4];
    int length=1056;
    if(bufferID=BUFFER_ID_1) {
	cmd[0]=0x84;
    }
    else if(bufferID=BUFFER_ID_2) {
	cmd[0]=0x87;
    }
    else {
	/* invalid buffer number */
	return -2;
    }
    cmd[1]=0x00;
    cmd[2]=0x00;
    cmd[3]=0x00;
    spiFill(cmd,4,value,pageSize);
}

int xplDataFlash::read(uint32_t address, uint8_t *data, int length) {
    uint8_t cmd[5];
    if(address>=size) {
	//address beyond the flash size
	return -1;
    }
    cmd[0]=0x0B;
    if(pageSize==1024) {
	/*
	  Pagesize of 1024 has a "natural" linear address space
	*/
	cmd[1]=(uint8_t)((address >> 16) & 0xFF);
	cmd[2]=(uint8_t)((address >>  8) & 0xFF);
	cmd[3]=(uint8_t)(address & 0xFF);
    }
    else {
	/*
	  Pagesize of 1056 requires some calculations
	*/
	uint32_t page=address/1056UL;
	uint32_t offset=address%1056UL;
	uint32_t daddr=(page<<11) | offset;
	
	cmd[1]=(uint8_t)((daddr >> 16) & 0xFF);
	cmd[2]=(uint8_t)((daddr >> 8) & 0xFF);
	cmd[3]=(uint8_t)(daddr & 0xFF);
    }
    //we need on dummy byte, then we start reading in
    cmd[4]=0x00;

    spiRead(cmd,5,data,length);
    return 0;
}

int xplDataFlash::write(uint32_t address, uint8_t *data, int length) {
    int page;
    int bytesToWrite;
    int pageOffset;
    int dataOffset;
    int bytesOnPage;

    if(address>=size ) {
	//address is beyond the flash size
	return -1;
    }
    if(address+(uint32_t)length>size) {
	/* 
	   We write on the last page so we 
	   have to truncate the data. 
	*/
	length=size-address;
    }
    if(length<=0) {
	/* nothing to write */
	return 0;
    }
    bytesToWrite=length;
    page=(int)(address/(uint32_t)pageSize);
    pageOffset=(int)(address%(uint32_t)pageSize);
    dataOffset=0;
    while(bytesToWrite>0) {
	/* load the current page into the buffer */
	spiPageToBuffer(BUFFER_ID_1,page);
	if((pageSize-pageOffset)>=bytesToWrite) {
	    /* the remaining data to be written fits on the current page */
	    bytesOnPage=bytesToWrite;
	    bytesToWrite=0;
	}
	else {
	    bytesOnPage=pageSize-pageOffset;
	    bytesToWrite-=bytesOnPage;
	}
	writeBuffer(BUFFER_ID_1,pageOffset,
		    data+dataOffset, bytesOnPage);
	spiBufferToPage(BUFFER_ID_1,page);
	dataOffset+=bytesOnPage;
	page++;
	/* offset is always 0 on all but the first page */
	pageOffset=0;
    }
    /*
      Page Refresh
      Each one of 8192 pages on the chip has to be refreshed 
      from time to time (at max after 10000 writes to any of 
      the pages in the sekctor it belongs to). We use a slow and 
      simple strategy here. Whenever we write a page we also 
      refresh one. This guarantees that every page was refreshed 
      at least once every 8192 writes.
      The downside to this strategy is that every page-write action
      takes twice as long (~40ms)
    */
    spiRefreshPage(refreshCounter);
    refreshCounter++;
    return length;
}
    
void xplDataFlash::chipErase(){
    uint8_t cmd[4];
    cmd[0]=0xC7;
    cmd[1]=0x94;
    cmd[2]=0x80;
    cmd[3]=0x9A;

    /* CS low */
    PORTC.OUTCLR=PIN1_bm;
    /* 
       Send the command bytes
    */
    for(int i=0;i<4;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
    /* wait for operation to finish */
    waitForStatusReady();
}


int xplDataFlash::getPageSize() {
    return pageSize;
}

int xplDataFlash::getManufacturerId() {
    return vendorId;
}

int xplDataFlash::getDeviceId() {
    return deviceId;
}

void xplDataFlash::getID() {
    uint8_t cmd[]={0x9F};
    uint8_t data[4];
    
    spiRead(cmd,1,data,4);
    vendorId=(int)data[0];
    deviceId=((int)data[1])<<8;
    deviceId|=(int)data[2];
}

void xplDataFlash::spiRefreshPage(long page) {
    uint8_t cmd[4];
    /* we use buffer 0 for refreshing the page */
    cmd[0]=0x58;
    if(pageSize==1024) {
	page=page<<10;
    }
    else {
	page=page<<11;
    }
    cmd[1]=((uint8_t)(page>>16)) & 0xFF;
    cmd[2]=((uint8_t)(page>>8)) & 0xFF;
    cmd[3]=((uint8_t)page) & 0xFF;
    /* CS low */
    PORTC.OUTCLR=PIN1_bm;
    /* 
       Send the command bytes
    */
    for(int i=0;i<4;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
    /* wait for operation to finish */
    waitForStatusReady();
}     
 

uint8_t xplDataFlash::getStatus() {
    uint8_t retval=0x00;
    uint8_t cmd[]={0xD7};
    
    spiRead(cmd,1,&retval,1);
    return retval;
}

uint8_t xplDataFlash::waitForStatusReady() {
    int status;
    do {
	status=getStatus();
    } while(!(status & 0x80));
    return status;
}

void xplDataFlash::getSecurityRegister(uint8_t *buffer) {
    uint8_t cmd[] = {0x77,0x00,0x00,0x00};
    spiRead(cmd,4,buffer,128);
}

void xplDataFlash::spiRead(uint8_t cmd[], int cmdLength, uint8_t data[], int length) {
    /* CS low */
    PORTC.OUTCLR=PIN1_bm;

    /* 
       Send the command bytes
    */
    for(int i=0;i<cmdLength;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /*
      Cmd has been send. 
      If we expect any return value from the DataFlash we read 
      it into the data buffer
    */
    for(int i=0; i<length;i++) {
	//transmit a dummy byte
	SPIC.DATA=0x00;	
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
	//get the next byte back
	data[i]=SPIC.DATA;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
}

void xplDataFlash::spiWrite(uint8_t cmd[], int cmdLength, uint8_t data[], int length) {
    /* CS low */
    PORTC.OUTCLR=PIN1_bm;
    
    /* 
       Send the command bytes
    */
    for(int i=0;i<cmdLength;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /*
      Now send the data 
    */
    for(int i=0;i<length;i++) {
	SPIC.DATA=data[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
}
 
void xplDataFlash::spiFill(uint8_t cmd[], int cmdLength, uint8_t data, int length) {
    /* CS low */
    PORTC.OUTCLR=PIN1_bm;

    /* 
       Send the command bytes
    */
    for(int i=0;i<cmdLength;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /*
      Now send the data 
    */
    for(int i=0;i<length;i++) {
	SPIC.DATA=data;
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
}

void xplDataFlash::spiPageToBuffer(int buffer, int page) {
    uint8_t cmd[4];
    uint32_t addr=0UL;

    if(buffer==BUFFER_ID_1) {
	cmd[0]=0x53;
    }
    else if(buffer==BUFFER_ID_2) {
	cmd[0]=0x55;
    }
    if(pageSize==1024) {
	addr=((uint32_t)page)<<10;
    }
    else {
	addr=((uint32_t)page)<<11;
    }
    cmd[1]=(uint8_t)(page>>16) & 0xFF;
    cmd[2]=(uint8_t)(page>>8) & 0xFF;
    cmd[3]=(uint8_t)0;

    /* CS low */
    PORTC.OUTCLR=PIN1_bm;
    /* 
       Send the command bytes
    */
    for(int i=0;i<4;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
    /* wait for operation to finish */
    waitForStatusReady();
}

void xplDataFlash::spiBufferToPage(int buffer, int page) {
    uint8_t cmd[4];
    uint32_t addr=0UL;

    if(buffer==BUFFER_ID_1) {
	cmd[0]=0x83;
    }
    else if(buffer==BUFFER_ID_2) {
	cmd[0]=0x86;
    }
    if(pageSize==1024) {
	addr=((uint32_t)page)<<10;
    }
    else {
	addr=((uint32_t)page)<<11;
    }
    cmd[1]=(uint8_t)(addr>>16) & 0xFF;
    cmd[2]=(uint8_t)(addr>>8) & 0xFF;
    cmd[3]=(uint8_t)0;

    /* CS low */
    PORTC.OUTCLR=PIN1_bm;
    /* 
       Send the command bytes
    */
    for(int i=0;i<4;i++) {
	SPIC.DATA=cmd[i];
	while(!(SPIC.STATUS & SPI_IF_bm)) 
	    ;
    }
    /* CS high */
    PORTC.OUTSET=PIN1_bm;
    /* wait for operation to finish */
    waitForStatusReady();
}

int xplDataFlash::pageSizeDetect() {
    /*
      Test procedure is simple:
      fill a buffer with '\0';
      write 2 bytes with a different value ('1') to address 
      1023 and 1024 of the buffer;
      now read address 0 of the buffer, if its is !='\0'
      the buffers address counter has wrapped around an we
      have a pagesize of 1024 bytes;
      otherwise the chip uses the default size and the value
      at address 0 has not changed
    */
    uint8_t cmd[4];
    uint8_t outData[]={0x01,0x01};
    uint8_t inData[]={0x00,0x00};
    clearBuffer(BUFFER_ID_1);
    cmd[0]=0x84;
    cmd[1]=0x00;
    cmd[2]=0x03;
    cmd[3]=0xFF;
    spiWrite(cmd,4,outData,2);
    cmd[0]=0x4D;
    cmd[1]=0x00;
    cmd[2]=0x00;
    cmd[3]=0x00;
    spiRead(cmd,4,inData,2);
    if(inData[0])
	return 1024;
    return 1056;
}

    
    


