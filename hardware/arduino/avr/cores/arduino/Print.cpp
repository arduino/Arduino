/* Print.cpp copyright notice

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

/* Print.cpp short description
   this code provides the implementation of the non trivial methods of the Print class.
*/

#define _define_static_PrintFormat_instances // force declaration of static PrintFormat instances here (in PrintFromat.h included from Print.h)

#include "Print.h"
#include <math.h>

// == Public Methods ==============================================================================================================

/* default implementation: may be overridden */
size_t Print::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  while (size--) { n += write(*buffer++); }
  return n;
}

// these basic print method are declared but not defined in the header file. The space penalty of inlineing a call to a virtual method not negligible.
size_t Print::print(char        item)              { return write((uint8_t)item);}
size_t Print::print(const char* item, size_t size) { return write((const uint8_t *)item, size); }

size_t Print::print(const __FlashStringHelper *ifsh)
{
  PGM_P p = reinterpret_cast<PGM_P>(ifsh);
  size_t n = 0;
  while (1) {
    unsigned char c = pgm_read_byte(p++);
    if (c == 0) break;
    n += write(c);
  }
  return n;
}

// == Private Methods =============================================================================================================

size_t Print::printString(const char* cstr, unsigned int size, unsigned int formatControl)
{
  unsigned int nchar = 0;

  // field size handling
  int fillLen = (formatControl&PrintFormat::m_FieldSizeMask) -size;

  // sign handling
  char sign;
  if      ( (formatControl&PrintFormat::m_IsNegative) ) sign = '-';   // negative signed value (always add '-' sign)
  else if (!(formatControl&PrintFormat::m_ForceSign)  ) sign = '\0';  // no forced sign
  else if ( *cstr == '0' )                              sign = ' ';   // forced signed and     zero value (add a space )
  else                                                  sign = '+';   // forced signed and non-zero value (add a '+' sign)

  if(formatControl&PrintFormat::m_ForceSign) fillLen++; // with forcedSign we get one position more 
  // reduce the fill length if we add sign symbol
  if(sign) fillLen--;


  unsigned char fillControl = formatControl&(PrintFormat::m_FillZeros|PrintFormat::m_AlignLeft);
  // if we have to fill spaces, fill spaces
  if(fillControl == 0) nchar+=printPadding(' ', fillLen);

  // if there is a sign symbol add the sign
  if(sign) nchar += write(sign);

  // if we have to fill zeros, fill zeros
  if( fillControl == PrintFormat::m_FillZeros) nchar+=printPadding('0', fillLen);

  // write what needs to be written
  nchar += write((const uint8_t *)cstr, size);

  // post fill whatever space is left with whatever is needed
  if( fillControl == (PrintFormat::m_AlignLeft|PrintFormat::m_FillZeros)) nchar+=printPadding('-', fillLen);
  if( fillControl == (PrintFormat::m_AlignLeft                         )) nchar+=printPadding(' ', fillLen);

  return nchar;
}

size_t Print::printNumber(unsigned long n, unsigned int formatControl)
{
  // special cases
  // if (base == 0) return write(n); // binary output ==> breaking backward compatibility
  unsigned char base = ((formatControl>>8) & (PrintFormat::m_RadixMask>>8))+1;
  if (base == 1) base = 10;       // default value is decimal (also prevent infinite loop)

  char buf[8 * sizeof(long) + 2]; // Assumes maximum of 8 characters per byte (binary radix ) + sign character plus + termination byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';

  do { // loop to print the number
    unsigned long m = n;
    n /= base;
    char c = m - base * n;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  // field size handling
  int8_t fillLen = (formatControl&PrintFormat::m_FieldSizeMask) - (&buf[sizeof(buf)-1] - str);

  if((formatControl&(PrintFormat::m_IsNegative|PrintFormat::m_ForceSign)) == PrintFormat::m_IsNegative) fillLen--;
  if(formatControl&PrintFormat::m_StrictSize && fillLen<0)
  {
    str -= fillLen;
    *str = '#';
  }

  return printString(&str[0], &buf[sizeof(buf)-1] - str, formatControl);
}


unsigned long&  asLong (const float& aFloat) { return (unsigned long&)  aFloat;} // interpret a float as long
float& asFloat(const unsigned long&  aLong)  { return (float&) aLong; } // interpret a long  as float

size_t Print::printFloat(double number, unsigned int formatControl) 
{ 
  size_t nc = 0;

#ifdef slow_code // use this on machines where a double has more than 4 bytes
// if(sizeof(double) >4)
// if negative, mark as negative and make value positive
   if (number<0) { number = -number; formatControl |= PrintFormat::m_IsNegative; } // Mark as negative item if negative

#else

// if negative, mark as negative and make value positive (irrespective of nan ovf ...)
  if (asLong((float)number)&0x80000000) { number = asFloat(asLong((float)number) & ~0x80000000); formatControl |= PrintFormat::m_IsNegative; } // Mark as negative item if negative
  // note: the more elegant alternative   asLong(number) = asLong((float)number) & ~0x80000000; // only works when a double equals a float (like on the Arduino, but not while emulating)
#endif

  unsigned char digits = ((formatControl>>8) & (PrintFormat::m_PrecisionMask>>8));
  if(digits) digits--;

  // TODO write some fast code testing for nan: (asLong(number) == 0x7F800000) and inf: ((asLong(number) & 0x7F800000) == 0x7F800000)
  float ovfValue = float(0xFFFFFF00u);   // constant determined by reasoning ;-)
  char* specialNumber = NULL;
  if      (isnan(number))                      specialNumber=(char*) "nan";
  else if (isinf(number))                      specialNumber=(char*) "inf";
  else if (float(number) > ovfValue)           specialNumber=(char*) "ovf";

  if(specialNumber)
  {
    nc = printString(specialNumber, 3, formatControl);
    digits++;
    nc += printPadding(' ', digits);
    return nc;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i) rounding /= 10.0;
  /* //fast code
  {
    double rounding  = 0.5;
    if(digits!=0)
    {
      double  factor    = 0.1;
      uint8_t digitMask = digits;
      while(1)
      {
        if(digitMask&1) rounding *= factor;
        digitMask = digitMask>>1;
        if(!digitMask) break;
        factor *= factor;
      }
    }
  }
  */

  number = (float)(number +rounding); // cast to float to test behaviour on machines were double is double (and "ca ne mange pas de pain" on the Arduino)

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;

  double remainder = number - (double)int_part;

  formatControl = (formatControl &~PrintFormat::m_PrecisionMask) | ((10-1)<<8); // replace precision with radix 10
  nc += printNumber(int_part, formatControl);

  // Print the decimal point, always! // changed!! but only if there are digits beyond
  nc += write('.'); 

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    unsigned char toPrint = int(remainder);
    nc += write('0' + toPrint);
    remainder -= toPrint;
  }

  return nc;
}

//Print_cpp =======================================================================================================================
