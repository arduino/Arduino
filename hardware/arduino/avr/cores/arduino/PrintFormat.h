/* PrintFormat.h copyright notice

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

*/

/* PrintFormat.h short description
   This code defines the classes and constant class instances for controlling the print output format, as used by the Print class
*/

#ifndef PrintFormat_h
#define PrintFormat_h

class PrintFormat
{
friend class Print;
friend class PrintSequence;

protected:
  unsigned int myFormatControl;

  static const unsigned char m_FieldSizeMask  = 0x1f; /* contains the field width -1 of the entry to be printed */
  static const unsigned char m_StrictSize     = 0x20; /* if set, the field width is strict and shall not be exceeded  */
  static const unsigned char m_AlignLeft      = 0x40; /* if set, left align the field by adding the padding characters to the right */
  static const unsigned char m_FillZeros      = 0x80; /* if set, fill with '0' instead of spaces */

  static const unsigned int  m_RadixMask      = 0x1f00; /* gives the radix -1 of the entry to be printed IntegerFormat only) */
  static const unsigned int  m_PrecisionMask  = 0x1f00; /* gives the precision -1 of the entry to be printed (FloatFormat only) */
  static const unsigned int  m_Reserved       = 0x2000; /* reserved (possibly to mark negated option) */
  static const unsigned int  m_ForceSign      = 0x4000; /* if set, force sign symbol, including for positive values */
  static const unsigned int  m_IsNegative     = 0x8000; /* if set, the value shall be interpreted as a signed item (reserved for internal use) */

  // define a format control merging constructor. For non-null FieldSize or Radix/Precision values, the right hand size values override the left hand size values;
  PrintFormat(unsigned int lhs, unsigned int rhs) :
             myFormatControl( lhs                                                  // get the right hand side
                              & ~((rhs & m_FieldSizeMask) ? m_FieldSizeMask : 0)   // if rhs has a non-zero FieldSize value , wipe out the fieldSize from the lhs
                              & ~((rhs & m_RadixMask    ) ? m_RadixMask     : 0)   // idem for Radix/Precision
                              |    rhs                                             // merge with the lefthand side
                            ) {}

  PrintFormat(unsigned int aFormatControl) : myFormatControl(aFormatControl) {}

public:

  unsigned int  getFormatControl() const { return myFormatControl; }

  inline friend PrintFormat operator&(const PrintFormat& lhs, const PrintFormat& rhs) { return PrintFormat(lhs.myFormatControl, rhs.myFormatControl); }

  static const PrintFormat FIELDSIZE(unsigned char number) { return PrintFormat(  number & m_FieldSizeMask); }
  static const PrintFormat STRICTSIZE;
  static const PrintFormat FILLZEROS;
  static const PrintFormat FORCESIGN;
  static const PrintFormat DEFAULTPF;
};


class IntegerFormat : PrintFormat
{
friend class Print;
friend class PrintSequence;
  IntegerFormat(unsigned int aFormatControl)        : PrintFormat(aFormatControl) {}
  IntegerFormat(unsigned int lhs, unsigned int rhs) : PrintFormat(lhs, rhs) {}
public:
  // todo try to formulate this more concise
  inline friend IntegerFormat operator&(const IntegerFormat& lhs, const IntegerFormat& rhs) { return IntegerFormat(lhs.getFormatControl(), rhs.getFormatControl() ); }
  inline friend IntegerFormat operator&(const IntegerFormat& lhs, const PrintFormat& rhs)   { return IntegerFormat(lhs.getFormatControl(), rhs.getFormatControl() ); }
  inline friend IntegerFormat operator&(const PrintFormat& lhs,   const IntegerFormat& rhs) { return IntegerFormat(lhs.getFormatControl(), rhs.getFormatControl() ); }

  using PrintFormat::getFormatControl;

  static const IntegerFormat RADIX(unsigned char number)   { return IntegerFormat(number ? ((number-1)&(m_RadixMask>>8))<<8 : 0); }  // bit truncation (wrapping)
//static const IntegerFormat RADIX(unsigned char number)   { return IntegerFormat(number ? (number>(m_RadixMask>>8) ? m_RadixMask : (number-1)<<8) : 0); } // min/max limitation
  static const IntegerFormat ALIGNLEFT;
};


class FloatFormat : PrintFormat
{
friend class Print;
friend class PrintSequence;
  FloatFormat(unsigned int aFormatControl)        : PrintFormat(aFormatControl) {}
  FloatFormat(unsigned int lhs, unsigned int rhs) : PrintFormat(lhs, rhs) {}
public:
  inline friend FloatFormat operator&(const FloatFormat& lhs, const FloatFormat& rhs) { return FloatFormat(lhs.getFormatControl(), rhs.getFormatControl() ); }
  inline friend FloatFormat operator&(const FloatFormat& lhs, const PrintFormat& rhs) { return FloatFormat(lhs.getFormatControl(), rhs.getFormatControl() ); }
  inline friend FloatFormat operator&(const PrintFormat& lhs, const FloatFormat& rhs) { return FloatFormat(lhs.getFormatControl(), rhs.getFormatControl() ); }

  using PrintFormat::getFormatControl;

  static const FloatFormat PRECISION(unsigned char number) { return FloatFormat(number>=(m_PrecisionMask>>8) ? m_PrecisionMask : (number+1)<<8); }
};


#ifdef trap_invalid_PrintFormat_operation
// Define a 'sink' to capture all invalid PrintFormat operations to make error messages more readable.
// First attempt to set the scene: (However, this limited implementation makes the compiler error messages even more confusing).
// TODO extend further, use templates.
   class  invalid_PrintFormat_operation{};
   inline const invalid_PrintFormat_operation operator& (const IntegerFormat& lhs, const FloatFormat&   rhs);
   inline const invalid_PrintFormat_operation operator& (const FloatFormat&   lhs, const IntegerFormat& rhs);
#endif

#ifdef _define_static_PrintFormat_instances
// this is my way (and choice) to keep implementation and definition in the same file.
// the macro _define_static_PrintFormat_instances is #defined in one .cpp file (either PrintFormat.cpp or Print.cpp) before the #include of this header file.
const PrintFormat     PrintFormat::STRICTSIZE(m_StrictSize);
const PrintFormat     PrintFormat::FILLZEROS (m_FillZeros);
const PrintFormat     PrintFormat::FORCESIGN (m_ForceSign);
const PrintFormat     PrintFormat::DEFAULTPF (0);
const IntegerFormat IntegerFormat::ALIGNLEFT (m_AlignLeft);
#endif // _define_static_PrintFormat_instances

#endif // PrintFormat_h ===========================================================================================================

