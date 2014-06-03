/* TestMillisMicros
  Uses pin7 (PD_3) PWM driving pin2 pulseIn to test millis and micros
*/


#include "wiring_private.h" // needed for PWWWrite

#define IN  2
#define OUT 7

void test() {
  unsigned long pulselength;
  unsigned long startm,startu;
  unsigned long endm,endu;
  pulselength = pulseIn(IN,HIGH);
  Serial.print("pulseIn length (us) = ");
  Serial.println(pulselength);

  while(digitalRead(IN) == 0);
  while(digitalRead(IN) == 1);
  while(digitalRead(IN) == 0);
  startu= micros();
  startm= millis();
  while(digitalRead(IN) == 1);
  endm = millis();
  endu = micros();
  Serial.print("delta micros()      = ");
  Serial.println(endu - startu);
  Serial.print("delta millis()      = ");
  Serial.println(endm - startm);
  Serial.println();
}

void setup() {                
  Serial.begin(9600);
  Serial.println("\nTestMillisMicros setup");
  Serial.println("pin 7 PWM drives pin 2\n");
  pinMode(IN,  INPUT);     
  pinMode(OUT, OUTPUT);     
  delay(100);

  PWMWrite(OUT, 255, 250, 1); // runs the PWM freq slow 1Hz
  test();

  PWMWrite(OUT, 255, 100, 1); // runs the PWM freq slow 1Hz
  test();

  PWMWrite(OUT, 255, 10, 1); // runs the PWM freq slow 1Hz
  test();

}

void loop() {
}
