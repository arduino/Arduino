#ifndef TOGGLE_CPP
#define TOGGLE_CPP

#include "Arduino.h"

inline void toggle (bool &buttonState, bool change)
{
  buttonState = change ? !buttonState : buttonState;
}

#endif
