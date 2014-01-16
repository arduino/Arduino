
/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Modified by Gilles De Vos, December 10, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Morse.h"
#include "LibMorseConf.h"

Morse::Morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(LIB_MORSE_DOT_DURATION);
  digitalWrite(_pin, LOW);
  delay(LIB_MORSE_UNIT); 
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(LIB_MORSE_DASH_DURATION);
  digitalWrite(_pin, LOW);
  delay(LIB_MORSE_UNIT);
}

void Morse::endchar()
{
  if ((LIB_MORSE_SHORT_GAP - LIB_MORSE_UNIT) > 0)
    delay(LIB_MORSE_SHORT_GAP - LIB_MORSE_UNIT);
}

void Morse::endword()
{
  if ((LIB_MORSE_MEDIUM_GAP - LIB_MORSE_UNIT) > 0)
    delay(LIB_MORSE_MEDIUM_GAP - LIB_MORSE_UNIT);
  
}

#ifdef LIB_MORSE_ALPHABET_AVAILABLE
void Morse::_A()
{
  dot(); dash(); endchar();
}

void Morse::_B()
{
  dash(); dot(); dot(); dot(); endchar();
}

void Morse::_C()
{
  dash(); dot(); dash(); dot(); endchar();
}

void Morse::_D()
{
  dash(); dot(); dot(); endchar();
}

void Morse::_E()
{
  dot(); endchar();
}

void Morse::_F()
{
  dot(); dot(); dash(); dot(); endchar();
}

void Morse::_G()
{
  dash(); dash(); dot(); endchar();
}

void Morse::_H()
{
  dot(); dot(); dot(); dot(); endchar();
}

void Morse::_I()
{
  dot(); dot(); endchar();
}

void Morse::_J()
{
  dot(); dash(); dash(); dash(); endchar();
}

void Morse::_K()
{
  dash(); dot(); dash(); endchar();
}

void Morse::_L()
{
  dot(); dash(); dot(); dot(); endchar();
}

void Morse::_M()
{
  dash(); dash(); endchar();
}

void Morse::_N()
{
  dash(); dot(); endchar();
}

void Morse::_O()
{
  dash(); dash(); dash(); endchar();
}

void Morse::_P()
{
  dot(); dash(); dash(); dot(); endchar();
}

void Morse::_Q()
{
  dash(); dash(); dot(); dash(); endchar();
}

void Morse::_R()
{
  dot(); dash(); dot(); endchar();
}

void Morse::_S()
{
  dot(); dot(); dot(); endchar();
}

void Morse::_T()
{
  dash(); endchar();
}

void Morse::_U()
{
  dot(); dot(); dash(); dot(); endchar();
}

void Morse::_V()
{
  dot(); dot(); dot(); dash(); endchar();
}

void Morse::_W()
{
  dot(); dash(); dash(); endchar();
}

void Morse::_X()
{
  dash(); dot(); dot(); dash(); endchar();
}

void Morse::_Y()
{
  dash(); dot(); dash(); dash(); endchar();
}

void Morse::_Z()
{
  dash(); dash(); dot(); dot(); endchar();
}

void Morse::_1()
{
  dot(); dash(); dash(); dash(); dash(); endchar();
}

void Morse::_2()
{
  dot(); dot(); dash(); dash(); dash(); endchar();
}

void Morse::_3()
{
  dot(); dot(); dot(); dash(); dash(); endchar();
}

void Morse::_4()
{
  dot(); dot(); dot(); dot(); dash(); endchar();
}

void Morse::_5()
{
  dot(); dot(); dot(); dot(); dot(); endchar();
}

void Morse::_6()
{
  dash(); dot(); dot(); dot(); dot(); endchar();
}

void Morse::_7()
{
  dash(); dash(); dot(); dot(); dot(); endchar();
}

void Morse::_8()
{
  dash(); dash(); dash(); dot(); dot(); endchar();
}

void Morse::_9()
{
  dash(); dash(); dash(); dash(); dot(); endchar();
}

void Morse::_0()
{
  dash(); dash(); dash(); dash(); dash(); endchar();
}

#endif
