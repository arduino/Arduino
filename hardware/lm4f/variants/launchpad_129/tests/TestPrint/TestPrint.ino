void setup() {
  const uint8_t buf[] = "123\n";
  const String s      = "123\n";
  const char str[]    = "123\n";
  unsigned char c     = 31;
  unsigned char b     = 32;
  int i;
  unsigned int n      = 123;
  long l              = -123456; 
  unsigned long u     = 123456; 
  double d            = 123.456789;
  double f            = 123.456;
  
  Serial.begin(9600);
  Serial.println("TestPrint");

// Print::write(const uint8_t *buffer, size_t size)
  Serial.write(buf,4);

// Print::print(const String &s)
  Serial.print(s);

// Print::print(const char str[])
  Serial.print(str);

//  Print::print(char c)
  Serial.print(c);
  Serial.println();

// Print::print(unsigned char b, int base)
  Serial.print(b,10);
  Serial.print(" ");
  Serial.print(b,16);
  Serial.print(" ");
  Serial.print(b,2);
  Serial.println();

// Print::print(int n, int base)
  Serial.print(n,10);
  Serial.print(" ");
  Serial.print(n,16);
  Serial.print(" ");
  Serial.print(n,2);
  Serial.println();
  
// Print::print(long n, int base)
  Serial.print(l,10);
  Serial.print(" ");
  Serial.print(l,16);
  Serial.print(" ");
  Serial.print(l,2);
  Serial.println();
  
// Print::print(unsigned long n, int base)
  Serial.print(u,10);
  Serial.print(" ");
  Serial.print(u,16);
  Serial.print(" ");
  Serial.print(u,2);
  Serial.println();

// Print::print(double n, int digits)
  Serial.print(d,1);
  Serial.print(" ");
  Serial.print(d,2);
  Serial.print(" ");
  Serial.print(d,3);
  Serial.print(" ");
  Serial.print(d,4);
  Serial.print(" ");
  Serial.print(d);
  Serial.println();

// Print::print(float n, int digits)
  Serial.print(f,1);
  Serial.print(" ");
  Serial.print(f,2);
  Serial.print(" ");
  Serial.print(f,3);
  Serial.print(" ");
  Serial.print(f,4);
  Serial.print(" ");
  Serial.print(f);
  Serial.println();
  
  











  
}

void loop() {
}
