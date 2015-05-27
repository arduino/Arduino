void printDemo();
void printSequenceTeaser();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {} // wait for serial port to connect. Needed for Leonardo only
}

void loop() {
  // put your main code here, to run repeatedly:

  // The new version of the Print class allows you to code things like:
  Serial.println("\nFirst a trivial exercise:");
  Serial.println(3.141592, PRECISION(4) & FIELDSIZE(3)); // note FIELDSIZE only concerns the integer part
  Serial.println(66, HEX);
  Serial.println(22, RADIX(5) & FIELDSIZE(8) & ALIGNLEFT);
  Serial.println(34, OCT & FIELDSIZE(8) & FORCESIGN & FILLZEROS);

  // print is backward compatible for the radix and precision argument, so old code won't break
  Serial.println(54, 13);
  Serial.println(3.141592, 3);

  Serial.println(F("\nFor real long string, we recommend you to use the F() macro, it will save dynamic memory."));  
  Demo_Radix();       // Demonstration of RADIX usage complemented with Serial.printPattern()
  Demo_Precision();   // Demonstration of PRECISION usage complemented with Serial.printPattern()
  Demo_Fieldsize();   // Demonstration of FIELDSIZE usage
  Demo_Alignment();   // Demonstration of ALIGNMENT usage
  Demo_customFormat();// Demonstration of custom format option
  Teaser();           // coming next

  // for more demos, uncomment the next line
  // printDemo(); // but this has now become rather boring

  // for a sneak preview of what's coming next uncomment the next line
  // printSequenceTeaser();

// Note: the following lines produce compiler errors as they involve incompatible PrintFormat objects:
/* So it is commented out
   FloatPrintFormat   HexFloatFormat          = HEX;
   IntegerPrintFormat PrecisionIntergerFormat = PRECISION(5);
   PrintFormat        HexPrintFormat          = HEX;
   PrintFormat        PrecisionPrintFormat    = PRECISION(5);
   IntegerFormat      PrecisionHexCombination = HEX & PRECISION(5);
   Serial.print(42,   PRECISION(5)); // PRECISION only works for floats
   Serial.print(3.14, HEX);          // HEX only for integers
   Serial.print("42", HEX);          // HEX also does not work for strings
// */  

  delay(5000);
}

void Demo_Radix()
{
  Serial.println(F("\nRADIX() demo, for RADIX( 0 .. 42)"));
  const PrintFormat testFormat  = FIELDSIZE(8);
  for(int i=0; i<42; i++)
  {
    Serial.print("0x"); Serial.print( i, FIELDSIZE(2)); Serial.println(42, testFormat & RADIX( i) );
  }
}

void Demo_Precision()
{
  Serial.println(F("\nPRECISION() Demo, for PRECISION(0 ..42); complemented with Serial.printPattern()"));
  IntegerFormat myIntFormat  = DEC & FIELDSIZE(2);
  PrintFormat   myTestFormat = FIELDSIZE(8);

  for(int i=0; i<42; i++)
  {
    unsigned char nchar=0; // number of characters printed this line
    nchar+=Serial.print( i, myIntFormat);
    nchar+=Serial.print(41.9876543210987654321098765432109876543210, myTestFormat & PRECISION(i) );
    nchar+=Serial.print("  ");
    // we now fill it up with:
    char* patternString = " - -.- - |";
    int   patternLength = 50 - nchar;
    int   patternOffset = nchar % strlen(patternString);
    nchar+=Serial.printPattern(patternString, patternLength, patternOffset );
    Serial.print(" nchar="); Serial.println(nchar,FIELDSIZE(6) & ALIGNLEFT & FILLZEROS);
  }
}

void Demo_Fieldsize()
{
  Serial.println(F("FIELDSIZE demo, printing varying length patterns with fixed FIELDSIZE with / without ALIGNLEFT"));
  long testValues[] = {0, 1, 12, 123, 1234, 1234, 12345, 123456, -1223456, -12345, -1234, -123, -12, -1, -0};
  int  nTestValues = sizeof(testValues) / sizeof(testValues[0]);

  Serial.println(F("FIELDSIZE(8)"));
  for(int i=0; i< nTestValues; i++)
  {
    Serial.print(testValues[i], FIELDSIZE(8) & ALIGNLEFT);
    Serial.print(" / ");
    Serial.print(testValues[i], FIELDSIZE(8));
    Serial.println();
  }

  Serial.println(F("FIELDSIZE(5)"));
  for(int i=0; i< nTestValues; i++)
  {
    Serial.print(testValues[i], FIELDSIZE(5) & ALIGNLEFT);
    Serial.print(" / ");
    Serial.print(testValues[i], FIELDSIZE(5));
    Serial.println();
  }

  Serial.println(F("FIELDSIZE(5) & STRICTSIZE"));
  for(int i=0; i< nTestValues; i++)
  {
    Serial.print(testValues[i], FIELDSIZE(5) & STRICTSIZE & ALIGNLEFT);
    Serial.print(" / ");
    Serial.print(testValues[i], FIELDSIZE(5) & STRICTSIZE);
    Serial.println();
  }

  Serial.println(F("FIELDSIZE(5) & STRICTSIZE & FORCESIGN"));
  for(int i=0; i< nTestValues; i++)
  {
    Serial.print(testValues[i], FIELDSIZE(5) & STRICTSIZE & FORCESIGN & ALIGNLEFT);
    Serial.print(" / ");
    Serial.print(testValues[i], FIELDSIZE(5) & STRICTSIZE & FORCESIGN);
    Serial.println();
  }
}

void Demo_Alignment()
{
  Serial.println(F("\nALIGNMENT demo, printing +/-1234 with FIELDSIZE(8) and various combinations of FORCESIGN & FILLZEROS & ALIGNLEFT"));
  // zut FIELDSIZE ALIGLEFT does not work (yet) with strings, so ... verzin toch een list jonge vriend.
  int nc;
  nc=Serial.print(F(" ")                                    ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8)                                     ); Serial.println(";");
  nc=Serial.print(F(" & ALIGNLEFT")                         ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & ALIGNLEFT                         ); Serial.println(";");
  nc=Serial.print(F(" & FILLZEROS")                         ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & FILLZEROS                         ); Serial.println(";");
  nc=Serial.print(F(" & ALIGNLEFT & FILLZEROS")             ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & ALIGNLEFT & FILLZEROS             ); Serial.println(";");
  nc=Serial.print(F(" ")                                    ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8)                                     ); Serial.println(";");
  nc=Serial.print(F(" & ALIGNLEFT")                         ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & ALIGNLEFT                         ); Serial.println(";");
  nc=Serial.print(F(" & FILLZEROS")                         ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & FILLZEROS                         ); Serial.println(";");
  nc=Serial.print(F(" & ALIGNLEFT & FILLZEROS")             ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & ALIGNLEFT & FILLZEROS             ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN ")                        ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & FORCESIGN                         ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN & ALIGNLEFT")             ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & FORCESIGN & ALIGNLEFT             ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN & FILLZEROS")             ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & FORCESIGN & FILLZEROS             ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN & ALIGNLEFT & FILLZEROS") ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print( 1234, FIELDSIZE(8) & FORCESIGN & ALIGNLEFT & FILLZEROS ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN ")                        ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & FORCESIGN                         ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN & ALIGNLEFT")             ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & FORCESIGN & ALIGNLEFT             ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN & FILLZEROS")             ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & FORCESIGN & FILLZEROS             ); Serial.println(";");
  nc=Serial.print(F(" & FORCESIGN & ALIGNLEFT & FILLZEROS") ); Serial.printPadding(' ', 40-nc); Serial.print(" : "); Serial.print(-1234, FIELDSIZE(8) & FORCESIGN & ALIGNLEFT & FILLZEROS ); Serial.println(";");
}

void Teaser()
{
  #ifdef Teaser
  Serial.println(F("\nPrintSequence teaser"));
  PrintSequence mps(Serial);
//PrintSequence mps=Serial.getPrintSequence();// alternative 

  n = mps<<"Ciao Arduini"<<NEWLINE
  <<", one="<<1<<NEWLINE
  <<"two dot two ="<<2.2<<"  or to be more precise"<<PRECISION(2)<<FIELDSIZE(4)<<2.2<<NEWLINE
  <<" etc, all in one sequence...\n"
  <<EndSequence();

  out<<n<<F("characters printed\n");


  class MyEndSequence : public EndSequence
  {
    unsigned int printCloseString(Print& out) const { return out.print('|eof}'); }
  } myEndSequence;

  n = Serial.getPrintSequence()<<'{'<<F("PrintSequence using a custom EndSequence.")<<myEndSequence;
  #endif // teaser
}

void Demo_customFormat()
{
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
        nc+=out.print('[');
        for(int i=0;i<4; i++) {if(i!=0) nc+=out.print('.'); nc+=out.print(_asIPADDRESS(myIpAddress)[3-i]);} // I'm an endian, I'm a little endian!
        nc+=out.print(']');
        return nc;
      }
    };

  Serial.print("\nDemo of a FormatAdapter class");
  Serial.print("\nNetwork address(");
  Serial.print(0xC0A80001);
  Serial.print(")=");
//Serial.println(myIpAdress, myIpAdressFormatter); // will not be implemented, but can be replaced by
Serial.print(IpAddressFormatAdapter(0xC0A80001));
Serial.println();
//dir werkt nog niet
//Serial.println(IpAddressFormatAdapter(0xC0A80001));
}
