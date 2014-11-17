/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Modified by Gilles De Vos December 10, 2013.
  Released into the public domain.
*/
#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void endchar();
    void endword();
//#ifdef LIB_MORSE_CHARACTERS_AVAILABLE
    void _A();
    void _B();
    void _C();
    void _D();
    void _E();
    void _F();
    void _G();
    void _H();
    void _I();
    void _J();
    void _K();
    void _L();
    void _M();
    void _N();
    void _O();
    void _P();
    void _Q();
    void _R();
    void _S();
    void _T();
    void _U();
    void _V();
    void _W();
    void _X();
    void _Y();
    void _Z();
    void _1();
    void _2();
    void _3();
    void _4();
    void _5();
    void _6();
    void _7();
    void _8();
    void _9();
    void _0();
//#endif
  private:
    int _pin;
};

#endif