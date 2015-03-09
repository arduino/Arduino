/* PrintDemo.cpp copyright notice

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

/* compilation & testing

# options to get it compiled outside Arduino environment (for debugging and code optimisation)
export Arduino=/Arduino/arduino-git/ # or whatever
cd $Arduino/examples/test_FormattedPrint

g++ -g \
 -DtestCode\
 -Dno_testCompilationErrors\
 -I$Arduino/hardware/arduino/avr/cores/arduino\
 -I$Arduino/hardware/arduino/sam/cores/arduino\
 PrintDemo.cpp\
 2>&1| grep --text -E "error:"\
 ||\
 gdb \
 ./a.exe

# command for code inspection
$Arduino/arduino-1.0.5/hardware/tools/avr/bin/avr-g++ \
  -DtestCode \
  -I../../../arduino-1.0.5/hardware/arduino/cores/arduino \
  -I../../../arduino-1.0.5/hardware/arduino/variants/standard \
  -I../../../arduino-1.0.5/hardware/tools/avr/avr/include \
  -mmcu=atmega328p -Os PrintDemo.cpp \
  -S \
  2>&1| grep  -E "error"

# note: includes are needed for WString.h and avr/pgmspace.h
*/

#ifdef testCode
#define __ATTR_PROGMEM__
#define pgm_read_byte(x) *(x)
#define __PGMSPACE_H_
#define PSTR
typedef const char* PGM_P;

#include <stddef.h>
#include <inttypes.h>

#define Arduino_h
#define _define_static_PrintFormat_instances // force declaration of static PrintFormat instances here (in PrintFromat.h included from Print.h)
#include "Print.h"

#include <stdio.h>
#include <string.h>

class HardwareSerial : public Print
{
  public:
  virtual size_t write(uint8_t c)
  {
    printf("%c", c);
    return 1;
  }
} Serial;

void printDemo(); // forward definition

int main()
{
  printDemo();
}
#include "Print.cpp"


#else

#include "Arduino.h"
#endif


static unsigned long&  _asLong (const float& aFloat) { return (unsigned long&)  aFloat;} // interpret a float as long
static float& _asFloat(const unsigned long&  aLong)  { return (float&) aLong; } // interpret a long  as float

void printDemo()
{
  unsigned int nc;
  unsigned int i;
  Serial.println(F("\nrunning printDemo... ======================================================================================\n"));
  
  Serial.println(F("The new version of the Print class allows you to code things like:"));
  Serial.print(F("Serial.print(3.141592, PRECISION(4) & FIELDSIZE(3));          // "));
                  Serial.print(3.141592, PRECISION(4) & FIELDSIZE(3));                  Serial.println(F(" ; note FIELDSIZE only affects the integer part and does not concern the fraction"));
  Serial.print(F("Serial.print(66, HEX);                                        // "));
                  Serial.print(66, HEX);                                                Serial.println(F(" ;"));
  Serial.print(F("Serial.print(22, RADIX(5) & FIELDSIZE(8) & ALIGNLEFT);        // "));
                  Serial.print(22, RADIX(5) & FIELDSIZE(8) & ALIGNLEFT);                Serial.println(F(" ;"));
  Serial.print(F("Serial.print(34, OCT & FIELDSIZE(8) & FORCESIGN & FILLZEROS); // "));
                  Serial.print(34, OCT & FIELDSIZE(8) & FORCESIGN & FILLZEROS);         Serial.println(F(" ; note forced sign does not consume 'fieldsize'"));
  Serial.print(F("Serial.print(54, 13);                                         // "));
                  Serial.print(54, 13);                                                 Serial.println(F(" ; backward compatible base argument"));
  Serial.print(F("Serial.print(3.141592, 3);                                    // "));
                  Serial.print(3.141592, 3);                                            Serial.println(F(" ; backward compatible precision argument"));

  Serial.println(F("\nRadix test, looping from radix 0 .. 34 (0x22)"));
  IntegerFormat di = HEX & FIELDSIZE(2) & FILLZEROS;
  IntegerFormat ti = RADIX(0) & FIELDSIZE(4);
  Serial.print("0x"); Serial.print( 0, di); nc=Serial.print(42u, ti & RADIX( 0) & FIELDSIZE(8)); Serial.print(" nc="); Serial.println(nc); // will result in the default radix
  Serial.print("0x"); Serial.print( 1, di); nc=Serial.print(42u, ti & RADIX( 1) & FIELDSIZE(8)); Serial.print(" nc="); Serial.println(nc); // should become binary format?
  Serial.print("0x"); Serial.print( 2, di); nc=Serial.print(42u, ti & RADIX( 2) & FIELDSIZE(8)); Serial.print(" nc="); Serial.println(nc);
  ti = ti & FIELDSIZE(8);
  for(i=3; i<35; i++)
  {
    Serial.print("0x"); Serial.print( i, di); nc=Serial.print(42u, ti & RADIX( i) ); Serial.print(" nc="); Serial.println(nc);
  }
  Serial.println(F("note: Radix 33 (0x21)... wraps onto radix 1..."));

  Serial.println(F("\nPrecision test looping over precisison and complemented with Serial.printPattern((char*) \" - -.- - |\", 42-nc, nc%10)"));
  IntegerFormat df = DEC & FIELDSIZE(2);
  PrintFormat   tf = FIELDSIZE(8);
  for(i=0; i<32; i++)
  {
    Serial.print( i, df);
    nc =Serial.print(41.9876543210987654321098765432109876543210, tf & PRECISION( i) );
    nc+=Serial.print("  ");
    nc+=Serial.printPattern((char*) " - -.- - |", 42-nc, nc%10);
    Serial.print(" nc="); Serial.println(nc,FIELDSIZE(2));
  }

  Serial.println(F("\nundocumented printPattern feature:"));
  Serial.print(F("Serial.printPattern((char*) \" - -.- - |\\0surprise \", 60, 11); // "));
  Serial.printPattern((char*) " - -.- - |\0surprise :", 60, 11);
  Serial.println();

  Serial.print(F("\ntest print FlashStringHelper\nSerial.print(F(\"waar eens de boterbloempjes bloeiden...\"));   // "));
  Serial.println(F("waar eens de boterbloempjes bloeiden..."));

  Serial.println("\ndefault test:");
  Serial.print("Serial.print(0xB)    :"); Serial.println(0xB);
  Serial.print("Serial.print(12.345) :"); Serial.println(12.345);

  Serial.println("\nspecial float test");
  {
  nc=Serial.println("test positive float overflow (Note, ovf corresponds to float that cannot be represented as a long) this will be resolved by a future Scientific format)");
  FloatFormat ff = FIELDSIZE(15) & PRECISION(2);
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff60, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffff60, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffff60), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff70, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffff70, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffff70), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff7f, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffff7f, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffff7f), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff80, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffff80, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffff80), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff81, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffff81, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffff81), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff90, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffff90, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffff90), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffffa0, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffffa0, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffffa0), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xfffffff0, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xfffffff0, FIELDSIZE(10)); nc +=Serial.print(   float(0xfffffff0), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffffff, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print(             0xffffffff, FIELDSIZE(10)); nc +=Serial.print(   float(0xffffffff), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.println("test negative float overflow");
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff60, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffff60, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffff60), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff70, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffff70, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffff70), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff7f, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffff7f, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffff7f), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff80, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffff80, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffff80), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff81, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffff81, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffff81), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffff90, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffff90, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffff90), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffffa0, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffffa0, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffffa0), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xfffffff0, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xfffffff0, FIELDSIZE(10)); nc +=Serial.print(  -float(0xfffffff0), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xffffffff, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" -"); nc +=Serial.print(             0xffffffff, FIELDSIZE(10)); nc +=Serial.print(  -float(0xffffffff), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.println("test positive/negative float nan & inf"); // see also http://en.wikipedia.org/wiki/IEEE_754-1985 and
  nc=Serial.print("0x"); nc +=Serial.print( 0x7F800000, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0x7F800000, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0x7F800000), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0x7F800001, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0x7F800001, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0x7F800001), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0x7FC00000, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0x7FC00000, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0x7FC00000), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0x7FFFFFFF, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0x7FFFFFFF, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0x7FFFFFFF), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xFF800000, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0xFF800000, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0xFF800000), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xFF800001, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0xFF800001, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0xFF800001), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xFFC00000, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0xFFC00000, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0xFFC00000), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  nc=Serial.print("0x"); nc +=Serial.print( 0xFFFFFFFF, HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print("  "); nc +=Serial.print((long)0xFFFFFFFF, FIELDSIZE(10)); nc +=Serial.print(_asFloat(0xFFFFFFFF), ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));

#ifdef development_test_negative_nan_conversion
  float negnan = _asFloat(0xFFFFFFFF);
  nc=Serial.println("test negative float nan conversion");
  nc=Serial.print("0x"); nc +=Serial.print(_asLong(negnan), HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" "); nc +=Serial.print(_asLong(negnan), FIELDSIZE(10)); nc +=Serial.print(negnan, ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
  if(_asLong(negnan)&0x80000000) { _asLong(negnan) = _asLong(negnan) & ~0x80000000; }
  nc=Serial.print("0x"); nc +=Serial.print(_asLong(negnan), HEX & FIELDSIZE(8) & FILLZEROS); nc +=Serial.print(" "); nc +=Serial.print(_asLong(negnan), FIELDSIZE(10)); nc +=Serial.print(negnan, ff); nc +=Serial.print(" | "); nc +=Serial.println(nc,FIELDSIZE(2));
#endif

  Serial.print("\nBeware, HEX constants like 0xFFFFFFFF and 0xFFFFFFFFl are interpreted as (unsigned long)\n");
  Serial.print("print(        0xFFFFFFFF,   HEX/DEC) : "); Serial.print(        0xFFFFFFFF,   HEX & FIELDSIZE(8) & FILLZEROS); Serial.print("/"); Serial.println(        0xFFFFFFFF);
  Serial.print("print(        0xFFFFFFFFl,  HEX/DEC) : "); Serial.print(        0xFFFFFFFFl,  HEX & FIELDSIZE(8) & FILLZEROS); Serial.print("/"); Serial.println(        0xFFFFFFFF);
  Serial.print("print(  (long)0xFFFFFFFF,   HEX/DEC) : "); Serial.print(  (long)0xFFFFFFFF,   HEX & FIELDSIZE(8) & FILLZEROS); Serial.print("/"); Serial.println(  (long)0xFFFFFFFF);
  Serial.print("print((signed)0xFFFFFFFF,   HEX/DEC) : "); Serial.print((signed)0xFFFFFFFF,   HEX & FIELDSIZE(8) & FILLZEROS); Serial.print("/"); Serial.println((signed)0xFFFFFFFF);
  Serial.print("print(      (unsigned)-1,   HEX/DEC) : "); Serial.print(      (unsigned)-1,   HEX & FIELDSIZE(8) & FILLZEROS); Serial.print("/"); Serial.println(      (unsigned)-1);
  Serial.print("print(                -1,   HEX/DEC) : "); Serial.print(                -1,   HEX & FIELDSIZE(8) & FILLZEROS); Serial.print("/"); Serial.println(                -1);
  Serial.print("\n");
  }
  Serial.println("\ntest FIELDSIZE(5)");
  {
  Serial.println(       0, DEC & FIELDSIZE(5));
  Serial.println(       1, DEC & FIELDSIZE(5));
  Serial.println(      12, DEC & FIELDSIZE(5));
  Serial.println(     123, DEC & FIELDSIZE(5));
  Serial.println(    1234, DEC & FIELDSIZE(5));
  Serial.println(   12345, DEC & FIELDSIZE(5));
  Serial.println(  123456, DEC & FIELDSIZE(5));
  Serial.println( 1234567, DEC & FIELDSIZE(5));
  Serial.println(-      1, DEC & FIELDSIZE(5));
  Serial.println(-     12, DEC & FIELDSIZE(5));
  Serial.println(-    123, DEC & FIELDSIZE(5));
  Serial.println(-   1234, DEC & FIELDSIZE(5));
  Serial.println(-  12345, DEC & FIELDSIZE(5));
  Serial.println(- 123456, DEC & FIELDSIZE(5));
  Serial.println(-1234567, DEC & FIELDSIZE(5));

  Serial.println("\ntest FIELDSIZE(5) & STRICTSIZE");

  Serial.println(       0, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(       1, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(      12, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(     123, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(    1234, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(   12345, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(  123456, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println( 1234567, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(-      1, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(-     12, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(-    123, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(-   1234, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(-  12345, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(- 123456, DEC & FIELDSIZE(5) & STRICTSIZE);
  Serial.println(-1234567, DEC & FIELDSIZE(5) & STRICTSIZE);

  Serial.println("\ntest FIELDSIZE(5) & STRICTSIZE & FORCESIGN");
  Serial.println(       0, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(       1, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(      12, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(     123, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(    1234, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(   12345, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(  123456, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println( 1234567, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(-      1, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(-     12, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(-    123, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(-   1234, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(-  12345, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(- 123456, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
  Serial.println(-1234567, DEC & FIELDSIZE(5) & STRICTSIZE & FORCESIGN);

  Serial.println("\ntest FIELDSIZE(1) & STRICTSIZE");
  Serial.println(       0, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println(       1, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println(      12, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println(     123, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println(-      1, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println(-     12, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println(-    123, DEC & FIELDSIZE(1) & STRICTSIZE);
  Serial.println("\ntest FIELDSIZE(1) & STRICTSIZE & FORCESIGN");
  Serial.println(       0, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  Serial.println(       1, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  Serial.println(      12, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  Serial.println(     123, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  Serial.println(-      1, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  Serial.println(-     12, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  Serial.println(-    123, DEC & FIELDSIZE(1) & STRICTSIZE & FORCESIGN);
  }
  Serial.println("\ntest alignments");
  {
  Serial.print( 1234, DEC & FIELDSIZE(8) & FILLZEROS );                         Serial.println(F(" : FIELDSIZE(8) & FILLZEROS"));
  Serial.print( 1234, DEC & FIELDSIZE(8) );                                     Serial.println(F(" : FIELDSIZE(8)"));
  Serial.print( 1234, DEC & FIELDSIZE(8) & ALIGNLEFT );                         Serial.println(F(" : FIELDSIZE(8) & ALIGNLEFT"));
  Serial.print( 1234, DEC & FIELDSIZE(8) & ALIGNLEFT & FILLZEROS );             Serial.println(F(" : FIELDSIZE(8) & ALIGNLEFT & FILLZEROS"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & FILLZEROS );                         Serial.println(F(" : FIELDSIZE(8) & FILLZEROS"));
  Serial.print(-1234, DEC & FIELDSIZE(8) );                                     Serial.println(F(" : FIELDSIZE(8)"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & ALIGNLEFT );                         Serial.println(F(" : FIELDSIZE(8) & ALIGNLEFT"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & ALIGNLEFT & FILLZEROS );             Serial.println(F(" : FIELDSIZE(8) & ALIGNLEFT & FILLZEROS"));
  Serial.println("\ntest alignments with forced sign");
  Serial.print( 1234, DEC & FIELDSIZE(8) & FORCESIGN & FILLZEROS );             Serial.println(F(" : FIELDSIZE(8) & FORCESIGN & FILLZEROS"));
  Serial.print( 1234, DEC & FIELDSIZE(8) & FORCESIGN );                         Serial.println(F(" : FIELDSIZE(8) & FORCESIGN"));
  Serial.print( 1234, DEC & FIELDSIZE(8) & FORCESIGN & ALIGNLEFT );             Serial.println(F(" : FIELDSIZE(8) & FORCESIGN & ALIGNLEFT"));
  Serial.print( 1234, DEC & FIELDSIZE(8) & FORCESIGN & ALIGNLEFT & FILLZEROS ); Serial.println(F(" : FIELDSIZE(8) & FORCESIGN & ALIGNLEFT & FILLZEROS"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & FORCESIGN & FILLZEROS );             Serial.println(F(" : FIELDSIZE(8) & FORCESIGN & FILLZEROS"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & FORCESIGN );                         Serial.println(F(" : FIELDSIZE(8) & FORCESIGN"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & FORCESIGN & ALIGNLEFT );             Serial.println(F(" : FIELDSIZE(8) & FORCESIGN & ALIGNLEFT"));
  Serial.print(-1234, DEC & FIELDSIZE(8) & FORCESIGN & ALIGNLEFT & FILLZEROS ); Serial.println(F(" : FIELDSIZE(8) & FORCESIGN & ALIGNLEFT & FILLZEROS"));
  }
  Serial.println(F("notes:"));
  Serial.println(F("& FILLZER0 & ALLIGNLEFT produces dashes and not zeros, should we find a more appropriate name for FILLZEROS (FILLALTCHAR, NOSPACEFILL, ...)"));
  Serial.println(F("& FORCESIGN symbol is not reduced from FIELDSIZE(), the same holds for PRECISION"));
  PrintFormat pf0 = FORCESIGN;

  Serial.println();
  Serial.println(F("The PrintFormatter class for custom formatted print has not been implemented."));
  Serial.println(F("Custom formatting can be realized very easily with an adapter class."));
  #define __stringify(__ITEM) #__ITEM
  #define __tostring(__ITEM) __stringify(__ITEM)
  Serial.print  (F("See the code in " __FILE__ ", line " __tostring(__LINE__) ", for an example of an IPAddressFormatAdapter"));


//  Using an adapter class IPAddressFormatAdapter
  class IPAddressFormatAdapter : public Printable
  {
    typedef unsigned char IPAdress[4];
    IPAdress myIPAddress;
    static unsigned long& _asLong(IPAdress& anIPAdress) { return (unsigned long&) anIPAdress;} // interpret an unsigned long as a unsigned char[4]

    public:
    IPAddressFormatAdapter(unsigned long anIpAddress) { _asLong(myIPAddress)=anIpAddress;}

    size_t printTo(Print& out) const
    {
      unsigned char nc=0;
      for(int i=0;i<4; i++) {if(i!=0) nc+=out.print('.'); nc+=out.print(myIPAddress[3-i]);} // I'm an endian, I'm a little endian! (but not an Inglishmen in NY)
      return nc;
    }
  };
  Serial.println();
  Serial.println(F("Serial.print(IPAddressFormatAdapter(0x21428418)); // produces:"));
  Serial.print(IPAddressFormatAdapter(0x21428418));

  Serial.println('\n');
  Serial.println(F("Compiler checks: an illegal PrintFormat usage is trapped as a compilation error:"));
  Serial.println(F("Serial.print(42, PRECISION(4));             // error: 'PrintFormat' is an inaccessible base of 'FloatFormat'"));
  Serial.println(F("Serial.print(42., HEX);                     // error: 'PrintFormat' is an inaccessible base of 'IntegerFormat'"));
  Serial.println(F("PrintFormat myFormat(HEX & PRECISION(4));   // error: ambiguous overload for 'operator&' (operand types are 'const IntegerFormat' and 'const FloatFormat')"));
  Serial.println(F("// To test trapping of (almost) all illegal PrintFormat usage, compile with -DtestCompilationErrors"));

#ifdef testCompilationErrors
// The following code will produce compilation errors, as it involves impossible PrintFormat combinations or conversions
  PrintFormat pf1 = HEX;                                    // error : 'PrintFormat' is an inaccessible base of 'IntegerFormat'
  PrintFormat pf2 = PRECISION(4);                           // error : 'PrintFormat' is an inaccessible base of 'FloatFormat'
  PrintFormat pf3 = HEX & PRECISION(4);                     // error : conversion from 'invalid_PrintFormat_operation' to non-scalar type 'PrintFormat' requested
  PrintFormat pf4 = PRECISION(4) & HEX;                     // error : conversion from 'invalid_PrintFormat_operation' to non-scalar type 'PrintFormat' requested
  PrintFormat pf5 = PRECISION(4) & FIELDSIZE(4) & HEX;      // error : conversion from 'invalid_PrintFormat_operation' to non-scalar type 'PrintFormat' requested
  PrintFormat pf6 = PRECISION(4) & FIELDSIZE(4) & 42;       // error : conversion from 'invalid_PrintFormat_operation' to non-scalar type 'PrintFormat' requested

  int i0 = HEX & PRECISION(4);                              // error : cannot convert 'invalid_PrintFormat_operation' to 'int' in initialization
  int i1 = PRECISION(4) & HEX;                              // error : cannot convert 'invalid_PrintFormat_operation' to 'int' in initialization
  int i2 = PRECISION(4) & FIELDSIZE(4) & HEX;               // error : cannot convert 'invalid_PrintFormat_operation' to 'int' in initialization
  int i3 = PRECISION(4) & FIELDSIZE(4) & 42;                // error : conversion from 'invalid_PrintFormat_operation' to non-scalar type 'PrintFormat' requested

  Serial.print((unsigned)42, FIELDSIZE(4) & PRECISION(4) & FILLZEROS & FORCESIGN);  // error : 'PrintFormat' is an inaccessible base of 'FloatFormat'
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & FILLZEROS & FORCESIGN);  // error : 'PrintFormat' is an inaccessible base of 'FloatFormat'

  Serial.print((unsigned)42, HEX & PRECISION(4) & FIELDSIZE(4) & FILLZEROS & FORCESIGN);      // error : ambiguous overload for 'operator&' (operand types are 'const IntegerFormat' and 'const FloatFormat')
  Serial.print((unsigned)42, PRECISION(4) & HEX & FIELDSIZE(4) & FILLZEROS & FORCESIGN);      // error : ambiguous overload for 'operator&' (operand types are 'const FloatFormat' and 'const IntegerFormat')
  Serial.print((unsigned)42, 42 & PRECISION(4) & FIELDSIZE(4) & HEX & FILLZEROS & FORCESIGN); // error : ambiguous overload for 'operator&' (operand types are 'int' and 'const FloatFormat')
  Serial.print((unsigned)42, PRECISION(4) & 42 & FIELDSIZE(4) & HEX & FILLZEROS & FORCESIGN); // error : ambiguous overload for 'operator&' (operand types are 'const FloatFormat' and 'int')
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & HEX & 42 & FILLZEROS & FORCESIGN); // error : ambiguous overload for 'operator&' (operand types are 'FloatFormat' and 'const IntegerFormat')
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & HEX & FILLZEROS & FORCESIGN);      // error : ambiguous overload for 'operator&' (operand types are 'FloatFormat' and 'const IntegerFormat')
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & 42 & HEX & FILLZEROS & FORCESIGN); // error : ambiguous overload for 'operator&' (operand types are 'FloatFormat' and 'int')
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & HEX );                             // error : ambiguous overload for 'operator&' (operand types are 'FloatFormat' and 'const IntegerFormat')
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & 42 );                              // error : ambiguous overload for 'operator&' (operand types are 'FloatFormat' and 'int')

  Serial.print((unsigned)42, FIELDSIZE(4) & HEX & PRECISION(4) & FILLZEROS & FORCESIGN);  // error : ambiguous overload for 'operator&' (operand types are 'IntegerFormat' and 'const FloatFormat')
  Serial.print((unsigned)42, FIELDSIZE(4) & PRECISION(4) & HEX & FILLZEROS & FORCESIGN);  // error : ambiguous overload for 'operator&' (operand types are 'FloatFormat' and 'const IntegerFormat')
  Serial.print((unsigned)42, PRECISION(4) & FIELDSIZE(4) & FILLZEROS & FORCESIGN);        // error : call of overloaded 'print(unsigned int, FloatFormat)' is ambiguous

  // no match for operator
  Serial.print((unsigned)42,  FIELDSIZE(4) || HEX || FILLZEROS);
  Serial.print((unsigned)42,  FIELDSIZE(4) |  HEX |  FILLZEROS);
  Serial.print((unsigned)42,  FIELDSIZE(4) && HEX && FILLZEROS);
  Serial.print((unsigned)42,  FIELDSIZE(4) &  HEX &  FILLZEROS);     // ok
  Serial.print((unsigned)42,  FIELDSIZE(4) +  HEX +  FILLZEROS);     // not initutive, because HEX+HEX = ??
  Serial.print((unsigned)42,  FIELDSIZE(4),   HEX,   FILLZEROS);     // do not think this is technically possible, and if so (vararg) inefficient
  Serial.print((unsigned)42, (FIELDSIZE(4),   HEX,   FILLZEROS)  );  // unnatural (but could be made to work by overloading the operator,

  PrintFormat myPrintFormat1 = FIELDSIZE(4) & RADIX(4) & FILLZEROS;  // error : 'PrintFormat' is an inaccessible base of 'IntegerFormat'
  Serial.print((unsigned)42,  myPrintFormat1);
  Serial.print((unsigned)42,  myPrintFormat1 & ~FILLZEROS);

  PrintFormat myPrintFormat2 = FIELDSIZE(4) + RADIX(4) + FILLZEROS;  // error : no match for 'operator+' (operand types are 'const PrintFormat' and 'const IntegerFormat')
  Serial.print((unsigned)42,  myPrintFormat2);
  Serial.print((unsigned)42,  myPrintFormat2 -FILLZEROS);            // error : no match for 'operator-' (operand types are 'PrintFormat' and 'const PrintFormat')

  (FIELDSIZE(4) + HEX + HEX + HEX) == (FIELDSIZE(4) + HEX);          // error : no match for 'operator+' (operand types are 'const PrintFormat' and 'const IntegerFormat')
#endif

  Serial.print(F("\nEnd printDemo... ==========================================================================================\n\n"));
}

/* Still todo:

implement
//- radix offset handling
//- precision offset handling
//- fieldsize offset handling
//- ALIGNLEFT
//- STRICTSIZE
//- SIGNED  inf nan ovf
//- ALIGNED inf nan ovf
//- use printString in printNumber
//- add inline padding function printPadding(char padding, unsigned char size)
//- printPadding to return number of characters written;
//- use printPadding in printString
//- use printPadding to add precision space for inf nan ovf
//- add inline pattern function printPattern(char* pattern, unsigned char size)
//- add tests cases for nan and inf
//- recognize negative nan
//- test on Arduino and release

- StringFormat
- printString specific options
- ScientificFormat
- printScientific
- footprint studies
- optimize floatPrint
- invalid_PrintFormat_operation sink, i.e. define a 'black hole' class that absorbs all non defined operations involving classes derived from PrintFormat  
Debatable:
- implementation of .withSize() .withEtc() functions
*/
/* Discussions

for reflection
FIELDSIZE(n), RADIX(n), PRECISION(n)
a value of n=0 indicates the default.
IntegerFormat mfbase = DEC & FIELDSIZE(4);
IntegerFormat mfder1 = mfbase & HEX;          //gives HEX & FIELDSIZE(4);
IntegerFormat mfder2 = mfbase & FIELDSIZE(2); //gives DEC & FIELDSIZE(2);

Hence FIELDSIZE(0), RADIX(0), PRECISION(0) are not available. We may get the 0 values back if we could have a removal operator (and/or a removal Format Class)
other solution, each format has a bit mask showing the active fields, this bit mask is only used for combining format fields

Naming conventions
Currently Print related constants are part of the namespace ArduinoPrint. This namespace is automatically used when Print.h is included
- namespace ArduinoPrint, vs nested namespace Arduino::Print::
- using namespace by default?

printFormat hierarchy based on
- PrintFormat
- IntegerFormat
- FloatFormat
- StringFormat
- ScientificFormat
- NumericFormat

- RADIX(n)      note: free choice RADIX alternative would be BASE(n)
                      RADIX(0) means unchanged (or default) radix.
                      RADIX(1) should be RADIX(10) or binary format
- BIN           note: is implemented as RADIX(2)
- OCT           idem RADIX(8)
- DEC           idem RADIX(10)
- HEX           idem RADIX(16)
- FIELDSIZE(n)  note: FIELDSIZE does not count forced signs, and float fractions
- ALIGNLEFT     note: not allowed for float format
- FORCESIGN
- FILLZEROS     note FILLZEROS with ALIGNLEFT will fill dashes, should we rename FILLZEROS with FILLALT
- STRICTSIZE    note better alternative ENFORCEDSIZE, or maybe STRICTSIZE(n)
- PRECISION(n)
- EXPONENT EXPONENT(n) SCIENTIFIC(n)  Note, still to be implemented, but what format to be chosen

breaking of old code
- RADIX(0) now gives default, used to give raw format, RADIX(1) gives Decimal, should give raw format? swap RADIX(0) and RADIX(1)?
- decimal point in float is not suppressed (or should precision parameter include the decimal point)

Discussion
- option to suppress decimal point for PRECISION(0)?    (one could convert floats to int before printing, one can add a decimal point after printing)
- implement .withSize() etc... explain the fear for an "unhealthy" explosion of added methods for all possible derived classes.
*/
/* On the CustomFormatter
  i.e. print(elementary_type, customFormatter)
  a custom formatter class is lengthy and boring to implement: one cannot define templates for virtual methods (dat is logisch he!)
  Furthermore, the need for a custom formatter class is questionable. Encapsulation of data in a printable adapter class may be more appropriate, like:

//  Using an adapter class IPAddressFormatAdapter
  class IPAddressFormatAdapter : public Printable
  {
    typedef unsigned char IPAdress[4];
    IPAdress myIPAddress;
    static unsigned long& _asLong(IPAdress& anIPAdress) { return (unsigned long&) anIPAdress;} // interpret an unsigned long as a unsigned char[4]

    public:
    IPAddressFormatAdapter(unsigned long anIpAddress) { _asLong(myIPAddress)=anIpAddress;}

    size_t printTo(Print& out) const
    {
      unsigned char nc=0;
      for(int i=0;i<4; i++) {if(i!=0) nc+=out.print('.'); nc+=out.print(myIPAddress[3-i]);} // I'm an endian, I'm a little endian! (but not an Inglishmen in NY)
      return nc;
    }
  };

//  the following hypothetical (because not available) method invocation:
//  Serial.print(myIpAdress, myIpAdressFormatter);
//  may be implemented as:
    Serial.print(IPAddressFormatAdapter(myIpAdress));
*/

// eof
