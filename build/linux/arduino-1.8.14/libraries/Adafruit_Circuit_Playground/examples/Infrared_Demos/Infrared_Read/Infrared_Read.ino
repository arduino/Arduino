/* Infrared_Read.ino Example sketch for IRLib2 and Circuit Playground Express
   Illustrates how to receive an IR signal, decode it and print
   information about it to the serial monitor.
*/
#include <Adafruit_CircuitPlayground.h>

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
  #error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif


void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);

  while (!Serial); // Wait until serial console is opened
  
  CircuitPlayground.irReceiver.enableIRIn(); // Start the receiver
  Serial.println("Ready to receive IR signals");
}

void loop() {
  //Continue looping until you get a complete signal received
  if (CircuitPlayground.irReceiver.getResults()) {
    CircuitPlayground.irDecoder.decode();           //Decode it
    CircuitPlayground.irDecoder.dumpResults(false);  //Now print results. Use false for less detail
    CircuitPlayground.irReceiver.enableIRIn();      //Restart receiver
  }
}
