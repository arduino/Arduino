/*
  ByteBuffer.cpp - A buffer for TWI/I2C communication
  Copyright (c) Eberhard Fahle

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

#include "ByteBuffer.h"

ByteBuffer::ByteBuffer() {
    bufferSize=-1;
    buffer=NULL;
    bufferLimit=-1;
    bufferPosition=-1;
}
    
int ByteBuffer::begin(int size) {
    if(size<=0) {
	//we need some size 
	return -1;
    }
    this->bufferSize=size;
    buffer=(uint8_t *)malloc(this->bufferSize);
    if(buffer==NULL) {
	//out of mem
	return -2;
    }
    bufferLimit=0;
    bufferPosition=0;
    return 0;
}
    
void ByteBuffer::end() {
    if(bufferSize>0) {
	free(buffer);
	buffer=NULL;
	bufferSize=-1;
	bufferLimit=-1;
	bufferPosition=-1;
    }
}
	
void ByteBuffer::clear() {
    if(bufferSize>0) {
	bufferPosition=0;
	bufferLimit=0;
    }
}

void ByteBuffer::flip() {
    if(bufferSize>0) {
	bufferPosition=0;
    }
}

int ByteBuffer::remaining() {
    if(bufferSize<0)
	return -1;
    return bufferLimit-bufferPosition;
}

int ByteBuffer::position() {
    if(bufferSize<0)
	return -1;
    return bufferLimit;
}

int ByteBuffer::size() {
    return bufferSize;
}

int ByteBuffer::put(uint8_t data) {
    if(bufferSize<0 || bufferLimit==bufferSize)
	return -1;
    *(buffer+bufferPosition)=data;
    bufferLimit++;
    bufferPosition++;
    return 0;
}

int ByteBuffer::put(uint8_t* data, int length) {
    if(bufferSize<0 || length<0 || (bufferLimit+length)>bufferSize)
	return -1;
    for(int i=0;i<length;i++) {
	*(buffer+i)=*(data+i);
	bufferLimit++;
	bufferPosition++;
    }
    return 0;
}

int ByteBuffer::get() {
    if(bufferSize<0 || bufferPosition==bufferLimit)
	return -1;
    int retval=(int)*(buffer+bufferPosition);
    bufferPosition++;
    return retval;
};

int ByteBuffer::peek() {
    if(bufferSize<0 || bufferPosition==bufferLimit)
	return -1;
    int retval=(int)*(buffer+bufferPosition);
    return retval;
};

#endif // __AVR_XMEGA__