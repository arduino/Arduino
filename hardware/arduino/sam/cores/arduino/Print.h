/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

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

#ifndef Print_h
#define Print_h

#include <inttypes.h>
#include <stdio.h> // for size_t

#include "WString.h"
#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}
  
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
  
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == NULL) return 0;
      return write((const uint8_t *)str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
      return write((const uint8_t *)buffer, size);
    }
    
    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(  signed long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    
    size_t print(const char str[])   { return write(str); }
    size_t print(const char c)       { return write(c); }
    size_t print(const Printable &x) { return x.printTo(*this); }
    
    size_t print(  signed char  n, int f = DEC) { return print((  signed long) n, f); }
    size_t print(  signed short n, int f = DEC) { return print((  signed long) n, f); }
    size_t print(  signed int   n, int f = DEC) { return print((  signed long) n, f); }
    size_t print(unsigned char  n, int f = DEC) { return print((unsigned long) n, f); }
    size_t print(unsigned short n, int f = DEC) { return print((unsigned long) n, f); }
    size_t print(unsigned int   n, int f = DEC) { return print((unsigned long) n, f); }
    size_t print(    float      n, int f = 2  ) { return print((    double   ) n, f); }
    
    size_t println(void);
    
    template<typename T> size_t println(const T &arg)      { size_t t = print(arg);  return t + println(); }
    template<typename T> size_t println(const T &n, int f) { size_t t = print(n, f); return t + println(); }
};

#endif
