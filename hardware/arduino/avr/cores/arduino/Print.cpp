/* 
 Print.cpp - Base class that provides print() and println()
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
 
 Modified 23 November 2006 by David A. Mellis
 Modified 21 December 2014 by Michael Jonker. Enhanced with fieldControl parameter, most print methods defined through templates definitions in Print.h
 */

#include "Print.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Public Methods //////////////////////////////////////////////////////////////

/* default implementation: may be overridden */
size_t Print::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  while (size--) {
    n += write(*buffer++);
  }
  return n;
}

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

// Private Methods /////////////////////////////////////////////////////////////

size_t Print::printNumber(unsigned long n, unsigned char base, unsigned char fieldControl)
{
  // special cases
  if (base == 0) return write(n); // binary output
  if (base == 1) base = 10;       // prevent infinite loop

  char buf[8 * sizeof(long) + 2]; // Assumes maximum of 8 characters per byte (binary radix ) + sign character plus + termination byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';

  // sign handling
  char sign;
  if      ( (fieldControl&m_signedItem) and (signed long)n <0 ) { sign = '-';   n = -(signed long)n;} // negative signed value (always add '-' sign)
  else if (!(fieldControl&m_forceSign)                        )   sign = '\0';                        // no forced sign
  else if ( n==0 )                                                sign = ' ';                         // forced signed and     zero value (add a space )
  else                                                            sign = '+';                         // forced signed and non-zero value (add a '+' sign)

  do {
    unsigned long m = n;
    n /= base;
    char c = m - base * n;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  // field size handling
  int8_t fillLen = (fieldControl & m_fieldSizeMask) +1 - (&buf[sizeof(buf) - 1] - str);

  // reduce the fill length if we add an unforced sign symbol
  if(sign != '\0' and (fieldControl & m_forceSign)==0 ) fillLen--;

  // if there is a sign symbol, and we fill blanks, set the sign now and forget about it
  if(!(fieldControl & m_fillZeroes) and sign != '\0' ) { *--str = sign; sign ='\0'; }

  // defines the filling character
  char fill = (fieldControl & m_fillZeroes) ? '0' : ' ';

  while (fillLen-- > 0) *--str = fill;

  // if there is a sign symbol to be added
  if(sign != '\0') *--str = sign;

  return write(str);
}


size_t Print::printFloat(double number, unsigned char digits, unsigned char fieldControl) 
{ 
  size_t n = 0;
  bool isNegative = number<0; // To handle negative numbers

  if (isnan(number)) return print("nan");
  if (isinf(number)) return print("inf");
  if (number > 4294967040.0) return print ("ovf");  // constant determined empirically
  if (number <-4294967040.0) return print ("ovf");  // constant determined empirically
  
  if (isNegative) number = -number;

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i) rounding /= 10.0;
  
  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;

  if (isNegative) int_part = ((unsigned long) -int_part); // fold sign back in because printNumber takes care of this
  n += printNumber(int_part, Print::Radix_DEC, fieldControl|m_signedItem);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) n += write("."); 

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    unsigned char toPrint = int(remainder);
    n += write('0' + toPrint);
    remainder -= toPrint;
  } 
  
  return n;
}
