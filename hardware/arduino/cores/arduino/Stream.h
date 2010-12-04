/*
  Stream.h - base class for character-based streams.
  Copyright (c) 2010 David A. Mellis.  All right reserved.

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

#ifndef Stream_h
#define Stream_h

#include <inttypes.h>
#include "Print.h"

class Stream : public Print
{
  public:
    virtual int available() = 0;
    virtual int read() = 0;
    
    /*
     * Return the next byte waiting to be read.
     */
    virtual int peek() = 0;
    
    /*
     * Forces output to the underlying device.
     */
    virtual void flush() = 0;
    
    /*
     * Return the byte offset places from the beginning of the buffer.
     *
     * Default implementation for classes without a buffer.
     */
    int peek(uint8_t offset) {
      return (offset == 0) ? peek() : -1;
    }
    
    /*
     * Remove count bytes from the buffer.
     *
     * Inefficient default implementation.
     */
    void remove(uint8_t count) {
      for (uint8_t i = 0; i < count; i++) {
        read();
      }
    }
};

#endif
