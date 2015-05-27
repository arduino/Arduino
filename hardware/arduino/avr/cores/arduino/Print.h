/* Print.h copyright notice

  Copyright (c) 2015 Michael Jonker. All right reserved.

  "THE BEER-WARE LICENSE" (Revision 42++)  http://en.wikipedia.org/wiki/Beerware
  Michael Jonker <EBPISTC: 52.36040, 4.87001, NAP+5, -493899258> wrote this file.

  As long as you retain this notice you can can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the
  Free Software Foundation; either version 2.1 of the License, or (at your option)
  any later version.
  If we meet some day, and you think this stuff is worth it, you can buy me a beer in return.

  This code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  For a copy of the GNU Lesser General Public License write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA.

  This code replaces the version of David A. Mellis.
*/

/* Print.h short description
   this code defines the Print class and provides the implementation of the trivial methods of this class.
*/

#ifndef Print_h // == Print.h =====================================================================================================
#define Print_h

#include <stddef.h>
#include <inttypes.h>

#include "WString.h"
#include "Printable.h"
#include "PrintFormat.h"
namespace ArduinoPrint
{
  static const PrintFormat   FIELDSIZE(unsigned char number) { return   PrintFormat::FIELDSIZE(number); }
  static const IntegerFormat RADIX    (unsigned char number) { return IntegerFormat::RADIX    (number); }
  static const FloatFormat   PRECISION(unsigned char number) { return   FloatFormat::PRECISION(number); }

  static const PrintFormat   STRICTSIZE = PrintFormat::STRICTSIZE;
  static const PrintFormat   FILLZEROS  = PrintFormat::FILLZEROS;
  static const PrintFormat   FORCESIGN  = PrintFormat::FORCESIGN;
  static const IntegerFormat ALIGNLEFT  = IntegerFormat::ALIGNLEFT;
  static const IntegerFormat BIN = RADIX( 2);
  static const IntegerFormat OCT = RADIX( 8);
  static const IntegerFormat DEC = RADIX(10);
  static const IntegerFormat HEX = RADIX(16);

// these are defined in some standard include file...
  static const char NEWLINE = '\n';
  static const char endl    = '\n';      // defined in: #include <iostream>; using namespace std;  
};
using namespace ArduinoPrint;

class PrintSequence;
class Print
{
  private:
    int write_error;
    size_t printString           (const char*   value, unsigned int size, unsigned int formatControl);
    size_t printNumber           (unsigned long value, unsigned int formatControl);
    size_t printFloat            (double        value, unsigned int formatControl);
    size_t printExpon            (double        value, unsigned int formatControl);
    inline size_t printSignedNumber(signed long value, unsigned int formatControl) { if(value<0) { value=-value; formatControl |= PrintFormat::m_IsNegative; }
                                                                                     return printNumber((unsigned long)value, formatControl); }


  protected:
    inline void setWriteError(int err = 1) { write_error = err; }

  public:

    inline Print() : write_error(0)  {}

    inline int  getWriteError()      { return write_error; }
    inline void clearWriteError()    { setWriteError(0); }

    inline size_t printPadding(char value,  unsigned char length)
    {
      for(unsigned char nc = length; nc!=0; nc--) write(value);
      return length;
    }
    inline size_t printPattern(char* value, unsigned char length, unsigned char offset=0)
    {
      char* cp = value+offset;
      for(unsigned char nc = length; nc!=0; nc--) { write(*cp); cp = *(cp+1) ? cp+1 : value; }
      return length;
    }
    inline size_t printPadding(char  value,             signed char length                        ) { return length>0 ? printPadding(value,           (unsigned char) length        ) : 0; }
    inline size_t printPadding(char  value,             signed int  length                        ) { return length>0 ? printPadding(value,           (unsigned char) length        ) : 0; }
    inline size_t printPadding(char  value,           unsigned int  length                        ) { return            printPadding(value,           (unsigned char) length        )    ; }
    inline size_t printPattern(char* pattern,           signed char length, unsigned char offset=0) { return length>0 ? printPattern(pattern,         (unsigned char) length, offset) : 0; }
    inline size_t printPattern(char* pattern,           signed int  length, unsigned char offset=0) { return length>0 ? printPattern(pattern,         (unsigned char) length, offset) : 0; }
    inline size_t printPattern(char* pattern,         unsigned int  length, unsigned char offset=0) { return            printPattern(pattern,         (unsigned char) length, offset)    ; }
    inline size_t printPattern(const String& pattern,   signed char length, unsigned char offset=0) { return length>0 ? printPattern(pattern.c_str(), (unsigned char) length, offset) : 0; }
    inline size_t printPattern(const String& pattern,   signed int  length, unsigned char offset=0) { return length>0 ? printPattern(pattern.c_str(), (unsigned char) length, offset) : 0; }
    inline size_t printPattern(const String& pattern, unsigned int  length, unsigned char offset=0) { return            printPattern(pattern.c_str(), (unsigned char) length, offset)    ; }
    // TODO simply with templates

    PrintSequence getPrintSequence();

//  virtual methods that must/can be provided by the extending class
    virtual size_t write(uint8_t) = 0;                          // pure virtual, must be provided
    virtual size_t write(const uint8_t *buffer, size_t size);   // locally defined, can be overridden

//  these methods are not inlined as the space penalty for inlining a virtual method call is non negligible
    size_t print(char          item);
    size_t print(const char*   item, size_t size);
    size_t print(const __FlashStringHelper* item);

//  all other print methods are inlined calls to others print() methods or to Print private methods.

    inline size_t print(uint8_t*       item, size_t size, const PrintFormat& format=PrintFormat::DEFAULTPF) { return printString((char*)item,  size,          format.getFormatControl()); }
    inline size_t print(const char*    item, size_t size, const PrintFormat& format=PrintFormat::DEFAULTPF) { return printString(item,         size,          format.getFormatControl()); }
    inline size_t print(const char*    item,              const PrintFormat& format=PrintFormat::DEFAULTPF) { return printString(item,         strlen(item),  format.getFormatControl()); }
    inline size_t print(const String&  item,              const PrintFormat& format=PrintFormat::DEFAULTPF) { return printString(item.c_str(), item.length(), format.getFormatControl()); }
    //TODO fix make a printFlashString(item, format)
    inline size_t print(const __FlashStringHelper* item,  const PrintFormat& format/*=PrintFormat::DEFAULTPF */) { return print(item); }

    //TODO templatify (if possible)
    inline size_t print(unsigned char item, const IntegerFormat& format=DEC)          { return printNumber((unsigned long)item, format.getFormatControl() ); }
    inline size_t print(unsigned  int item, const IntegerFormat& format=DEC)          { return printNumber((unsigned long)item, format.getFormatControl() ); }
    inline size_t print(unsigned long item, const IntegerFormat& format=DEC)          { return printNumber((unsigned long)item, format.getFormatControl() ); }
    inline size_t print(          int item, const IntegerFormat& format=DEC)          { return printSignedNumber(   (long)item, format.getFormatControl() ); }
    inline size_t print(         long item, const IntegerFormat& format=DEC)          { return printSignedNumber(   (long)item, format.getFormatControl() ); }
    inline size_t print(       double item, const   FloatFormat& format=PRECISION(2)) { return printFloat(item, format.getFormatControl() ); }

    inline size_t print(unsigned char item, const   PrintFormat& format    )          { return printNumber((unsigned long)item, format.getFormatControl() ); }
    inline size_t print(unsigned  int item, const   PrintFormat& format    )          { return printNumber((unsigned long)item, format.getFormatControl() ); }
    inline size_t print(unsigned long item, const   PrintFormat& format    )          { return printNumber((unsigned long)item, format.getFormatControl() ); }
    inline size_t print(          int item, const   PrintFormat& format    )          { return printSignedNumber(   (long)item, format.getFormatControl() ); }
    inline size_t print(         long item, const   PrintFormat& format    )          { return printSignedNumber(   (long)item, format.getFormatControl() ); }
    inline size_t print(       double item, const   PrintFormat& format    )          { return printFloat(item, format.getFormatControl() ); }

    inline size_t print(const Printable& item)                                        { return item.printTo(*this);}

    // backward compatible calls:
    inline size_t print(unsigned char item, unsigned char radix)  { return printNumber((unsigned long)item, RADIX(radix).getFormatControl() ); }
    inline size_t print(unsigned  int item, unsigned char radix)  { return printNumber((unsigned long)item, RADIX(radix).getFormatControl() ); }
    inline size_t print(unsigned long item, unsigned char radix)  { return printNumber((unsigned long)item, RADIX(radix).getFormatControl() ); }
    inline size_t print(          int item, unsigned char radix)  { return printSignedNumber(   (long)item, RADIX(radix).getFormatControl() ); }
    inline size_t print(         long item, unsigned char radix)  { return printSignedNumber(   (long)item, RADIX(radix).getFormatControl() ); }
    inline size_t print(       double item, unsigned char digits) { return printFloat(item, PRECISION(digits).getFormatControl());}

//  define println() methods by template
                          inline size_t println(void)                                 { return                                    print('\n'); }
    template <typename R> inline size_t println(R item                              ) { return print(item)         + print('\n'); }
    template <typename R> inline size_t println(R item, const PrintFormat&   format ) { return print(item, format) + print('\n'); }
    template <typename R> inline size_t println(R item, const IntegerFormat& format ) { return print(item, format) + print('\n'); }
    template <typename R> inline size_t println(R item, const FloatFormat&   format ) { return print(item, format) + print('\n'); }
    template <typename R> inline size_t println(R item, unsigned char extra) { return print(item, extra) + print('\n'); }
//  TODO: see if we can remove the first templates by giving a default for PrintFormat without making print() ambiguous for R=char*, ...

};

#endif //Print_h ==================================================================================================================

// eof