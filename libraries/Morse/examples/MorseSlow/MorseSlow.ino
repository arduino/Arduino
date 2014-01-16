
#include <Morse.h>

 Morse morse(13);

void setup()
{
}

void loop()
{
   morse.dot(); morse.dot(); morse.dot(); morse.endchar();
   morse.dash(); morse.dash(); morse.dash(); morse.endchar();
   morse.dot(); morse.dot(); morse.dot(); morse.endchar();
   morse.endword();
}

