/* Infrared_Record.ino Example sketch for IRLib2 and Circuit Playground Express
   Illustrates how to receive an IR signal, decode and save it.
   Then retransmit it whenever you push the left pushbutton.
*/
#include <Adafruit_CircuitPlayground.h>

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
  #error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif


/* IR signals consist of a protocol number, a value, and a number of bits.
 *  Store all of these values for future use.
 */
uint8_t IR_protocol;
uint32_t IR_value;
uint16_t IR_bits;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Send an IR signal and I will record it.");
  Serial.println("Press the left button and we will retransmit it.");
  CircuitPlayground.begin();

  CircuitPlayground.irReceiver.enableIRIn(); // Start the receiver
  IR_protocol=0; //  Indicates we've not received a code yet
}

void loop() {
  /*  Receiver will look for a signal and when wa complete frame of data
   *   has been received, getResults() returns true. Once that happens,
   *   the receiver stops reccording  so you will need to restart it
   *   after you have processed the data.
   */
  if(CircuitPlayground.irReceiver.getResults()) {
    //attempt to decode it
    if(CircuitPlayground.irDecoder.decode()) {
        Serial.println("IR decoded");
        //Print the results.  Change parameter to "true" for verbose output.
        CircuitPlayground.irDecoder.dumpResults(false);
        Serial.println("Saving results. Press left button to retransmit.");
        IR_protocol=CircuitPlayground.irDecoder.protocolNum;
        IR_value= CircuitPlayground.irDecoder.value;
        IR_bits= CircuitPlayground.irDecoder.bits;
    }
    CircuitPlayground.irReceiver.enableIRIn();      //Restart receiver
  }

  /* If the left button is pressed and we have received a code
   * retransmit it using the sender.
   */
  if (CircuitPlayground.leftButton()) {
    Serial.println("Left button pressed!");
    if(IR_protocol) {
      CircuitPlayground.irSend.send(IR_protocol, IR_value, IR_bits);
      Serial.println("Sending recorded IR signal");
      Serial.print("Protocol:"); Serial.print(IR_protocol,DEC);
      Serial.print("  Value:0x");  Serial.print(IR_value,HEX);
      Serial.print("  Bits:"); Serial.println(IR_bits,DEC);
    } else {
      Serial.println("No signal saved yet.");
    }
  }
}

