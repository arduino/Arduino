//
//  InterruptOnChange_430
//
//  © Robert Wessels 2013
//
//  The MSP430 GPIOs intterupt system can be configured to detect a FALLING or RISING edge.
//  It however can not be configured to detect both of them at the same time, also called CHANGE in Arduino.
//  This Sketch demonstrates how to "emulate" this by flipping the edge detection in the ISR.
//
//  Press push 2 to turn on the LED. Pushing the button triggers a FALLING edge interrupt.
//  The ISR will set the edge to RISING and upon release the LED will turn off.
//

uint8_t volatile edge;

void setup() {
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  pinMode(PUSH2, INPUT_PULLUP);

  edge = FALLING;
  attachInterrupt(PUSH2, func, FALLING);
}

void loop() {
  /* Add your loop code here */
}

void func() {
  if(edge == FALLING) {
    attachInterrupt(PUSH2, func, RISING); 
    edge = RISING;
  } else {
    attachInterrupt(PUSH2, func, FALLING);
    edge = FALLING;
  }

  P1OUT ^= 0x01;

}
