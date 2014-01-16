
#include <Morse.h>

 Morse morse(13);

void setup()
{
}

void loop()
{
  morse._S();
  morse._O();
  morse._S();
  morse.endword();
  
}

