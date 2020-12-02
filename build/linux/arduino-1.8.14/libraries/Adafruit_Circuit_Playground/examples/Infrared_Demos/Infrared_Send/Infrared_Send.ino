/* Infrared_Send.ino Example sketch for IRLib2 and Circuit Playground Express
   Illustrates how to transmit an IR signal whenever you do push one of the
   built-in pushbuttons.
*/
#include <Adafruit_CircuitPlayground.h>

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
  #error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif

void setup() {
  CircuitPlayground.begin();
}

//Defines for a Samsung TV using NECx protocol
#define MY_PROTOCOL NECX
#define MY_BITS 32
#define MY_MUTE 0xE0E0F00F
#define MY_POWER 0xE0E040BF

void loop() {
  // If the left button is pressed send a mute code.
  if (CircuitPlayground.leftButton()) {
    CircuitPlayground.irSend.send(MY_PROTOCOL,MY_MUTE,MY_BITS);
    while (CircuitPlayground.leftButton()) {}//wait until button released
  }
  // If the right button is pressed send a power code.
  if (CircuitPlayground.rightButton()) {
    CircuitPlayground.irSend.send(MY_PROTOCOL,MY_POWER,MY_BITS);
    while (CircuitPlayground.rightButton()) {}//wait until button released
  }
}

