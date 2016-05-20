/*

USBSerial.h (formerly NewSoftSerial.h) - 
 Multi-instance USB serial library for Arduino/Wiring
 
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

#ifndef USBSerial_h
#define USBSerial_h

#include <inttypes.h>
#include <Stream.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/


class USBSerial : public Stream {
private:


  // static data

  // private methods

public:
  // public methods
  USBSerial(uint16_t port);
  ~USBSerial();
  void begin();
  void end();
  void end(uint8_t disableXTAL);
  virtual int available(void);
  virtual int peek();
  virtual size_t write(uint8_t byte);
  virtual size_t write(const uint8_t *buffer, size_t size);
  virtual int read();
  virtual void flush();

  using Print::write;

  // public only for easy access by interrupt handlers
  static inline void handle_interrupt();
};

#endif

