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
#include <limits.h> // for INT_MAX

#include "WString.h"
#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#ifdef BIN // Prevent warnings if BIN is previously defined in "iotnx4.h" or similar
#undef BIN
#endif
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

    // default to zero, meaning "a single write may block"
    // should be overriden by subclasses with buffering
    virtual int availableForWrite() { return 0; }

    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    size_t print(const Printable&);

    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);

    // Addition by NicoHood
    template <typename First, typename Second, typename Third, typename... Rest> 
    inline size_t print(const First& first, const Second& second, const Third& third, const Rest&... rest) {
        // A Wrapper is needed here in order to not call the
        // Formatted functions if the input was three integers
        // If you input only two integers the formatted
        // Functions have higher priority
        return printWrapper(first, second, third, rest...);
    }

    template <typename First> 
    inline size_t printWrapper(const First& first) {
        return print(first);
    }

    template <typename First, typename... Rest> 
    inline size_t printWrapper(const First& first, const Rest&... rest) {
        size_t r = 0;
        r+=print(first);
        r+=printWrapper(rest...); // recursive call using pack expansion syntax
        return r;
    }

    template <typename First, typename Second, typename Third, typename... Rest> 
    inline size_t println(const First& first, const Second& second, const Third& third, const Rest&... rest) {
        // A Wrapper is needed here in order to not call the
        // Formatted functions if the input was three integers
        // If you input only two integers the formatted
        // Functions have higher priority
        return printlnWrapper(first, second, third, rest...);
    }

    template <typename First> 
    inline size_t printlnWrapper(const First& first) {
        return println(first);
    }

    template <typename First, typename... Rest> 
    inline size_t printlnWrapper(const First& first, const Rest&... rest) {
        size_t r = 0;
        r+=print(first);
        r+=printlnWrapper(rest...); // recursive call using pack expansion syntax
        return r;
    }

};

#endif
