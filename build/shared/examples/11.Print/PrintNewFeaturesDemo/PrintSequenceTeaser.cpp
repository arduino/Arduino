/* PrintSequenceTeaser.cpp copyright notice

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

/* compilation & testing

# options to get it compiled outside Arduino environment (for debugging and code optimisation)
export Arduino=/Arduino/arduino-git/ # or whatever
cd $Arduino/examples/test_FormattedPrint

g++ -g \
 -DtestCode\
 -Dno_testCompilationErrors\
 -I$Arduino/hardware/arduino/avr/cores/arduino\
 -I$Arduino/hardware/arduino/sam/cores/arduino\
 PrintSequenceTeaser.cpp\
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
  -mmcu=atmega328p -Os PrintSequenceTeaser.cpp \
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

#else
#include "Arduino.h"

#endif



#define PrintFormatterV1_h // no, no, no-ho, we don't want this printFormatter
#ifndef PrintFormatterV1_h // == PrintFormatter.h ===================================================================================
#define PrintFormatterV1_h

class Print;
class PrintFormatter;

// implementation of Print method print(T_TYPE item, PrintFormatter aPrintFormatter)
template <typename T_TYPE> size_t Print::print(T_TYPE item, PrintFormatter aPrintFormatter) { aPrintFormatter.printFormatted(this, item);}

class PrintFormatter
{
  public:
    // so I thought "that will be rather easy" and wrote (before commenting it out with //)
    // template<typename T_TYPE> virtual size_t printFormatted(Print& out, T_TYPE item) {};

    // but of course templates may not be virtual, (en da's logisch hè).
    // this means that the PrintFormatter class has to define virtual methods for all basic types (making the vtable rather large I guess),

    // So we could define entries for all basic types that map to a few intrinsic primitive types (integer, float, string),...
    // which are defined as virtual.
    virtual size_t printFormattedInterger (Print& out, unsigned long item) const = 0;
    virtual size_t printFormattedFloat    (Print& out, double        item) const = 0;
    virtual size_t printFormattedString   (Print& out, char*         item) const = 0;
    virtual size_t printFormattedPrintable(Print& out, Printable&    item) const = 0;
    
    inline size_t printFormatted(print& out, unsigned long item) printFormattedInterger(out, (unsigned long) item);
    // and other integer like objects
    // idem for float, string, and Printable
    //
    // hm that will be rather messy... and our vtable has still 4 entries (mostly for John with the short surname)
    //
    // However, who needs such feature? Nobody, i.e. see discussion at the end.
};
#endif // PrintFormatter_h ========================================================================================================

#define PrintFormatterV2_h // I am maybe onto something, still some compiler hiccups to be removed
#ifndef PrintFormatterV2_h // == PrintFormatter.h ===================================================================================
#define PrintFormatterV2_h

template <typename T_TYPE> class PrintFormatter;

// temporary replacement for Print in development cycle
class DevPrint
{
  // for test I replace this with Serial
//template<typename T_TYPE> size_t print(T_TYPE item, PrintFormatter<T_TYPE>  thePrintFormatter) {return thePrintFormatter.printFormatted(this, item); }
  template<typename T_TYPE> size_t print(T_TYPE item, PrintFormatter<T_TYPE>& thePrintFormatter) {return thePrintFormatter.printFormatted(this, item); }
} SerialDev;

template <typename T_TYPE> class PrintFormatter
{
  public:
  virtual size_t printFormatted (DevPrint& out, T_TYPE item) const = 0;
};

template<typename T_TYPE>
class MyGeneralFormatter : public PrintFormatter<T_TYPE> 
{
  long nbase;
  public:
  MyGeneralFormatter(long base) : nbase(base){}
  size_t printFormatted (DevPrint& out, T_TYPE item) const {return out.print(item%nbase);}
};

class MyExplicitLongFormatter : public PrintFormatter<long> 
{
  long nbase;
  public:
  MyExplicitLongFormatter(long base) : nbase(base){}
  size_t printFormatted (DevPrint& out, long item) const {return out.print(item%nbase);}
};

void testPrintFormatter()
{
  SerialDev.print(0x12345678l, MyGeneralFormatter<long>(13));
  SerialDev.print(0x12345678l, MyExplicitLongFormatter(13));
  SerialDev.print(12345678.,   MyGeneralFormatter<long>(13));
  SerialDev.print(12345678.,   MyExplicitLongFormatter(13));
}

 
#endif // PrintFormatter_h ========================================================================================================


// still in development, to be published independently when more or less stable.
#ifndef PrintSequence_h // == PrintSequence.h =====================================================================================
#define PrintSequence_h
class Print;
class EndSequence
{
  friend class PrintSequence;
  virtual unsigned int printCloseString(Print& out) const { return 0;}
};

//TODO define derived class ClosedPrintSequence (which only has the method to Open() ), Alternative: use PrintSequence and OpenPrintSequence
class PrintSequence
{
protected:
  Print&      myPrint;
  PrintFormat myPrintFormat;
  PrintFormat myDefaultPrintFormat;
  int nchar;
  virtual unsigned int printOpenString(Print& out) const { return 0;}

public:
  PrintSequence(Print& aPrint) : myPrint(aPrint), myDefaultPrintFormat(0), myPrintFormat(0) { Open(); }
  void reset() { nchar=0; }
  int  end()   { return nchar; }

  inline PrintSequence& Open()                                  { nchar = printOpenString(myPrint);                                                  return *this; }
  inline unsigned int   operator<<(const EndSequence& item)     { int nres = nchar+item.printCloseString(myPrint); nchar = 0;                        return  nres; }

  inline PrintSequence& operator<<(const PrintFormat&   format) { myPrintFormat = myPrintFormat & format;                                            return *this; }
  inline PrintSequence& operator<<(const IntegerFormat& format) { myPrintFormat = myPrintFormat & format;                                            return *this; }
  inline PrintSequence& operator<<(const FloatFormat&   format) { myPrintFormat = myPrintFormat & format;                                            return *this; }
  inline PrintSequence& operator<<(const char item)             { nchar += myPrint.print(item);                myPrintFormat = myDefaultPrintFormat; return *this; }
  inline PrintSequence& operator<<(const Printable& item)       { nchar += myPrint.print(item);                myPrintFormat = myDefaultPrintFormat; return *this; }
  template <typename R>
  inline PrintSequence& operator<<(const R item)                { nchar += myPrint.print(item, myPrintFormat); myPrintFormat = myDefaultPrintFormat; return *this; }
};

// define as weak so it can be overridden;
// PrintSequence Print::getPrintSequence() __attribute__((weak));
PrintSequence Print::getPrintSequence() { return PrintSequence(*this); }

#endif //PrintSequence_h ==========================================================================================================


#ifdef testCode

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

void printSequenceTeaser();

int main()
{
  printSequenceTeaser();
}

#include "Print.cpp"
#endif


#ifndef PrintSequenceTeaser_cpp // == PrintSequenceTeaser.cpp =====================================================================
#define PrintSequenceTeaser_cpp
    
void printSequenceTeaser()
{
  Serial.print(F("\nrunning PrintSequence teaser... ===========================================================================\n"));

  int n;

  PrintSequence mps(Serial);  // alternative PrintSequence mps=Serial.getPrintSequence();
  Serial.println(F("n = mps<<\"Hi, one=\"<<1<<NEWLINE<<\"two dot two =\"<<2.2<<NEWLINE<<\"or to be more precise\"<<PRECISION(2)<<FIELDSIZE(4)<<2.2<<EndSequence();"));
                    n = mps<<"Hi, one="<<1<<NEWLINE<<"two dot two ="<<2.2<<NEWLINE<<"or to be more precise"<<PRECISION(2)<<FIELDSIZE(4)<<2.2<<EndSequence();

  Serial.print(F("\n\nSerial.getPrintSequence()<<\"one \"<<1<<\" two=\"<<2.1<<NEWLINE<<\" etc, all in one sequence...\"\n"));
                  n = Serial.getPrintSequence()<<"one "<<1<<", two="<<2.1<<NEWLINE<<" etc, all in one sequence...\n"
  <<F(" one:   ") << F("Waar eens de boterbloempjes bloeiden, staat nu een ma-af palei  (s)\n")
  <<F(" F()'d: ") << F("Waar eens het geld werd uitgevonden, trap ik nu in de hondepoe  (p)\n")
  <<" <<2    : " <<2<<'\n'
  <<" <<3<<4 : " <<3<<4<<'\n'
  <<" <<3.4  : " <<3.4<<'\n'
  <<F(" << PRECISION(1) <<3.4 : ")<<  PRECISION(1) <<3.4<<'\n'
  <<F(" << PRECISION(2) <<3.4 : ")<<  PRECISION(2) <<3.4<<'\n'
  <<F(" << FIELDSIZE(4) << STRICTSIZE                 << 123456.54321 : ")<<  FIELDSIZE(4) << STRICTSIZE                  <<123456.54321<<'\n'
  <<F(" <<(FIELDSIZE(4) &  STRICTSIZE &  PRECISION(4))<< 123456.54321 : ")<< (FIELDSIZE(4) &  STRICTSIZE &  PRECISION(4)) <<123456.54321<<'\n'
  <<F(" << FIELDSIZE(4) << STRICTSIZE << PRECISION(4) << 123456.54321 : ")<<  FIELDSIZE(4) << STRICTSIZE << PRECISION(4)  <<123456.54321<<'\n'
  <<F(" <<(FIELDSIZE(4) &  STRICTSIZE &  HEX         )<< 123456.54321 : ")<< (FIELDSIZE(4) &  STRICTSIZE &  HEX         ) <<123456.54321<<F(" // this is not nice, HEX is interpreted as PRECISION(16)!\n")
  <<F(" << FIELDSIZE(4) << STRICTSIZE << HEX          << 123456.54321 : ")<<  FIELDSIZE(4) << STRICTSIZE << HEX           <<123456.54321<<F(" // idem\n")
  <<F(" << HEX << FIELDSIZE(4) << STRICTSIZE << PRECISION(4) <<123456.54321 : ")<<  HEX << FIELDSIZE(4) << STRICTSIZE << PRECISION(4) <<123456.54321<<F(" // idem and in this context HEX is merged (hence overridden) with PRECISION()\n")
  <<F(" << FIELDSIZE(4) << STRICTSIZE << PRECISION(4) << HEX <<123456.54321 : ")<<  FIELDSIZE(4) << STRICTSIZE << PRECISION(4) << HEX <<123456.54321<<F(" // and vice versa\n")
  <<F(" << F(\" wordt aan gewerkt\\n\")  :")<<F(" I am working on a solution\n")
//<<" float9 "<<  FIELDSIZE(4) &  STRICTSIZE & PRECISION(4)  <<123456.54321<<'\n' // error : no match for ?operator&? (operand types are ?PrintSequence? and ?const PrintFormat?)
//<<" floatA "<< (3.4 << FIELDSIZE(8) & STRICTSIZE) <<'\n'                        // error : no match for ?operator<<? (operand types are ?double? and ?const PrintFormat?)
//<<" floatB "<< FIELDSIZE(8) & STRICTSIZE <<3.4<<'\n'                            // error : no match for ?operator<<? (operand types are ?const PrintFormat? and ?double?)
//<<" float "<<HEX & FIELDSIZE(4) % 3.4<<'\n'
//<<" float "<<PrintFormat(HEX&FIELDSIZE(4))% 3.4<<'\n'
  <<F(" <<EndSequence() : ")<<EndSequence();

  Serial.print(n);
  Serial.print(" characters printed\n");

  class MyEndSequence : public EndSequence
  {
    unsigned int printCloseString(Print& out) const { return out.print('}'); }
  } myEndSequence;
  // TODO introduce StartSequence ??


  Serial.println("\nPrintSequence using a custom EndSequence:");
  n = Serial.getPrintSequence()<<"{\n"
//  << F(" ach zal de mensheid ooit eens leren, te leven zonder bruut geweld...  ") <<NEWLINE
//  << F(" enz... ") <<NEWLINE
  << F(" waar moet dat heen, hoe zal dat gaan, waar komt die rot sooi toch vandaan") <<NEWLINE
  << F(" to appreciate this, you should see (code/output) what myEndSequence will add\n")
  << myEndSequence;

#ifdef repeatIpAddressFormatAdapter
  PrintSequence out(Serial);
  out<<" : "<<n <<" characters printed\n";
  
//  Using an adapter class IpAddressFormatAdapter
    class IpAddressFormatAdapter : public Printable
    {
      unsigned long myIpAddress;
      typedef unsigned char IpAdressData[4];
      static IpAdressData& _asIPADDRESS(const unsigned long& aLong) { return (IpAdressData&) aLong;} // interpret an unsigned long as a unsigned char[4]
      public:
      IpAddressFormatAdapter(unsigned long anIpAddress) : myIpAddress(anIpAddress) {}
      size_t printTo(Print& out) const
      {
        unsigned char nc=0;
        for(int i=0;i<4; i++) {if(i!=0) nc+=out.print('.'); nc+=out.print(_asIPADDRESS(myIpAddress)[3-i]);} // I'm an endian, I'm a little endian! (but not an Inglishmen in NY)
        return nc;
      }
    };

//  the following hypothetical method invocation:
//  Serial.print(myIpAdress, myIpAdressFormatter);
//  may be replaced by:
    out<<"\nDemo of a FormatAdapter class";
    n = out<<"\nNetwork address=["<<IpAddressFormatAdapter(0x19540508)<<"] (over gekken en dwazen gesproken...)"<<NEWLINE<<EndSequence();
#endif

  Serial.print(F("\nEnd PrintSequence teaser. Stay tuned, coming soon... ======================================================\n\n"));
}
#endif // PrintSequenceTeaser_cpp =================================================================================================



/* Research:
// useful constructs only available in C++11
// using PrintFormat::PrintFormat; // inheriting constructors
// PrintFormat() = delete;         // inheriting constructors, default / delete
// template<typename T_lhs, typename T_rhs> inline friend IntegerFormat operator&(T_lhs lhs, T_rhs rhs) = delete; // default or delete 
// template<typename... T> inline friend void operator&(T...) = delete                                            // variadic templates
//
// use of SFINAE
http://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error
http://stackoverflow.com/questions/982808/c-sfinae-examples           (=== TypeSink example ====)
http://stackoverflow.com/questions/26220144/disable-default-template-and-only-use-specialization-through-sfinae
http://stackoverflow.com/questions/7986125/disabling-hiding-functions-in-a-template-based-on-compile-time-constants

//hiding or unhiding members in derived classes (not sure this will work for constructors)
http://www.learncpp.com/cpp-tutorial/116-adding-changing-and-hiding-members-in-a-derived-class/

// what is explicit good for?? (http://programmers.stackexchange.com/questions/197893/why-are-constructors-not-inherited)

can one access a base class from a derived class (http://www.cplusplus.com/forum/general/35681/)
class Derived : Base {} d;
d.base::


http://stackoverflow.com/questions/1628768/why-does-an-overridden-function-in-the-derived-class-hide-other-overloads-of-the


c++ traits (see reference: http://www.cplusplus.com/reference/type_traits/is_integral/

disabling casts: http://www.gockelhut.com/c++/articles/disable_implicit_casts
void foo(uint32_t x);
// delete all implied one parameter foo functions:
template <typename T> void foo(T) = delete;
//or in general, delete all implied foo functions
template <typename... T>  void func_name(T...) = delete

declare constructor as explicit could do?
*/

/* PrintSequence operator candidate list (for setting NextFormat and DefaultFormat, should have a lower precedence then operator<<
example && default format
& next format

out && (HEX & FILLZEROS)<<42<<" 0x"<<39 & DEC << 39

http://en.cppreference.com/w/cpp/language/operator_precedence
Precedence  Operator          O Description                                                 Associativity 
1           ::                x Scope resolution                                            Left-to-right  
2           ++ --               Suffix/postfix increment and decrement  
            type() type{}     ? Function-style type cast  
            ()                  Function call  
            []                  Array subscripting  
            .                 x Element selection by reference  
            ->                  Element selection through pointer  
3           ++ --               Prefix increment and decrement                              Right-to-left  
            +  -                Unary plus and minus  
            !  ~                Logical NOT and bitwise NOT  
            (type)            ? C-style type cast  
            *                   Indirection (dereference)  
            &                   Address-of  
            sizeof            ? Size-of[note 1]  
            new, new[]          Dynamic memory allocation  
            delete, delete[]    Dynamic memory deallocation  
4           .*                x Pointer to member                                           Left-to-right  
               ->*              Pointer to member                                           Left-to-right  
5           *  /  %             Multiplication, division, and remainder  
6           +  -                Addition and subtraction  
7           << >>               Bitwise left shift and right shift  
8           <  <=               For relational operators < and = respectively  
            >  >=               For relational operators > and = respectively  
9           == !=               For relational = and ? respectively  
10          &                   Bitwise AND  
11          ^                   Bitwise XOR (exclusive or)  
12          |                   Bitwise OR (inclusive or)  
13          &&                  Logical AND  
14          ||                  Logical OR  
15          ?:                x Ternary conditional[note 2]                                 Right-to-left  
            =                   Direct assignment (provided by default for C++ classes)  
            += -=               Assignment by sum and difference  
            *= /= %=            Assignment by product, quotient, and remainder  
            <<= >>=             Assignment by bitwise left shift and right shift  
            &= ^= |=            Assignment by bitwise AND, XOR, and OR  
16          throw             ? Throw operator (for exceptions)  
17          ,                   Comma                                                       Left-to-right  
 
DFDDFPS DefaultFormated_DefaultDefaultFormat_PrintSequence
SFDDFPS  StringFormated_DefaultDefaultFormat_PrintSequence
IFDDFPS IntegerFormated_DefaultDefaultFormat_PrintSequence
FFDDFPS   FloatFormated_DefaultDefaultFormat_PrintSequence

DFDSFPS DefaultFormated_StringDefaultFormat_PrintSequence
SFDSFPS  StringFormated_StringDefaultFormat_PrintSequence
IFDSFPS IntegerFormated_StringDefaultFormat_PrintSequence
FFDSFPS   FloatFormated_StringDefaultFormat_PrintSequence

DFDIFPS DefaultFormated_IntegerDefaultFormat_PrintSequence
SFDIFPS  StringFormated_IntegerDefaultFormat_PrintSequence
IFDIFPS IntegerFormated_IntegerDefaultFormat_PrintSequence
FFDIFPS   FloatFormated_IntegerDefaultFormat_PrintSequence

DFDFFPS DefaultFormated_FloatDefaultFormat_PrintSequence
SFDFFPS  StringFormated_FloatDefaultFormat_PrintSequence
IFDFFPS IntegerFormated_FloatDefaultFormat_PrintSequence
FFDFFPS   FloatFormated_FloatDefaultFormat_PrintSequence

operation <<PrintFormat - - - - - - - - - - - - - - -  <<primitive - - - - - - - - - -  <<
          PF        SF          IF          FF         S           I           F
DF_df     DF_df     SF_df       IF_df       FF_df      DF_df       DF_df       DF_df  
SF_df     SF_df     SF_df       xx          xx         DF_df       xx          xx   
IF_df     IF_df     xx          IF_df       xx         xx          DF_df       xx   
FF_df     FF_df     xx          xx          FF_df      xx          xx          DF_df
                                                                                    
DF_sf     DF_sf     SF_sf       IF_sf       FF_sf      SF_sf     !-IF_sf     !-FF_sf
SF_sf     SF_sf     SF_sf       xx          xx         SF_sf       xx          xx   
IF_sf     IF_sf     xx          IF_sf       xx         xx        !-IF_sf       xx   
FF_sf     FF_sf     xx          xx          FF_sf      xx          xx        !-FF_sf
                                                                                    
DF_if     DF_if     SF_if       IF_if       FF_if    !-IF_if       IF_if     !-FF_if
SF_if     SF_if     SF_if       xx          xx       !-IF_if       xx          xx   
IF_if     IF_if     xx          IF_if       xx         xx          IF_if       xx   
FF_if     FF_if     xx          xx          FF_if      xx          xx        !-FF_if
                                                                                    
DF_ff     DF_ff     SF_ff       IF_ff       FF_ff    !-SF_ff     !-IF_ff       FF_ff
SF_ff     SF_ff     SF_ff       xx          xx       !-SF_ff       xx          xx   
IF_ff     IF_ff     xx          IF_ff       xx         xx        !-IF_ff       xx   
FF_ff     FF_ff     xx          xx          FF_ff      xx          xx          FF_ff

out<<HEX<<32<<" "<<32


- Some more thoughts/discussion/input is needed/welcome on how a PrintFormat in a PrintSequence should affect following items:
Merging a PrintFormat with the operator<< will modify the PrintFormat for the coming item only.
After each output of an item, the format is reset to a default.
How should one set the default format, use a specific operator.
Should it be possible to merge (modify) the default format.
If a default format is set with a e.g. a floating point qualifier (i.e. PRECISION(4), what should then be the behaviour for printing items other than float?
should there be distinct default format for integers, floats, string

PrintSequence mps(Serial);
PrintFormat   myDefaultFormat(HEX & FILLEZEROS & FIELDSIZE(8))
mps <<"start" <<HEX <<66 <=  myDefaultFormat <<" default set" <<(FIELDSIZE(5)&ALIGNLEFT) <<36;
mps <<"start" <<HEX <<66 ==  myDefaultFormat <<" default set" <<(FIELDSIZE(5)&ALIGNLEFT) <<36;
mps <<"start" <<HEX <<66 !=  myDefaultFormat <<" default set" <<(FIELDSIZE(5)&ALIGNLEFT) <<36;
mps <<"start" <<HEX <<66 &&  myDefaultFormat <<" default set" <<(FIELDSIZE(5)&ALIGNLEFT) <<36;
mps <<"start" <<HEX <<66 ||  myDefaultFormat <<" default set" <<(FIELDSIZE(5)&ALIGNLEFT) <<36;
mps <<"start" <<HEX <<66 <<= myDefaultFormat <<" default set" <<(FIELDSIZE(5)&ALIGNLEFT) <<36;

should we replace the operator<< PrintFormat by operator &, hence
mps <<"start" &HEX <<66 <=  myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;
mps <<"start" &HEX <<66 ==  myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;
mps <<"start" &HEX <<66 !=  myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;
mps <<"start" &HEX <<66 &&  myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;
mps <<"start" &HEX <<66 ||  myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;
mps <<"start" &HEX <<66 <<= myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;

my preferred solution
mps <<"start" &HEX <<66 &&  myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;

printSequence
{
  printSequence operator& (PrintFormat nextFormat);    // merge in next format
  printSequence operator&&(PrintFormat defaultFormat); // merge in a default format
  template<typename T_TYPE>
  printSequence operator<<(T_TYPE item);               // output an item
}

try this one out:

mps <<"start" &HEX <<66 && myDefaultFormat <<" default set" &FIELDSIZE(5) &ALIGNLEFT <<36;

<< & && .F()


mps << item <<item & format & format << item .F() .F() <<item .()

*/

/* Still todo:

implement
- format control in PrintSequence
= in progress
  PrintSequence maintains a nextPrintFormat and defaultprintFormat
  After each print() invocation, nextPrintFormat will be reset to defaultprintFormat
  the  operator<<(PrintSequence, PrintFormat) will merge the PrintFormat operand with the nextPrintFormat value.
  the  operator<<(PrintSequence, EndSequence) will reset nextPrintFormat and defaultPrintFormat to the PrintSequence class default;

  example:
  PrintSequence myPrintSequence = Serial.getPrintSequence();
  PrintSequence myPrintSequence(Serial); // alternative
  myPrintSeqeunce<<"{test 0x"<<HEX<<FILLZEROS<<FIELDSIZE(8)<<363880<<" again "<<363880<<"}\n"<<
  will print: {test 0x00009010 again 363880}

= The PrintSequence defaultPrintFormat can be changed by an operation on the PrintSequence
  This should be an intuitive operation, options are:
  - a new operator e.g. 
    myPrintSequence <<"Constants:" % PRECISION(2) % FIELDSIZE(8)  << " pi="<<3.1415<<" e="<<2.71828<<" sqrt(2)="<< 1.414;
    myPrintSequence <<"Constants:" %(PRECISION(2) & FIELDSIZE(8)) << " pi="<<3.1415<<" e="<<2.71828<<" sqrt(2)="<< 1.414;
  - a DEFAULT object of class SetFormatDefault that can be used with the << operator:
    class SetFormatDefault {} DEFAULT
    operator<<(SetFormatDefault item) { }
    myPrintSequence <<"Constants:" <<PRECISION(2) <<FIELDSIZE(8) <<DEFAULT   << " pi="<<3.1415<<" e="<<2.71828<<" sqrt(2)="<< 1.414;
    myPrintSequence <<"Constants:" <<DEFAULT(PRECISION(2)&FIELDSIZE(8))      << " pi="<<3.1415<<" e="<<2.71828<<" sqrt(2)="<< 1.414;
    myPrintSequence <<"Constants:" .setDefault(PRECISION(2) & FIELDSIZE(8) ) << " pi="<<3.1415<<" e="<<2.71828<<" sqrt(2)="<< 1.414;

- adaptable PrintSequence (e.g. to add sequence header and sequence trailer); Provide hooks to add e.g. CRC)
- add state handling to a printSequence (to distinguish open and closed sequences
*/

// eof
