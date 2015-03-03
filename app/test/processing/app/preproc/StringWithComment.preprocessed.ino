#include <Arduino.h>
#line 1
void setup();
void loop();
#line 1
void setup() {
  // put your setup code here, to run once:
  // "comment with a double quote
  /* \" other comment with double quote */
  Serial.println("Accept: */*");
  Serial.println("Accept: \" */*");
  Serial.println("Accept: \\"); // */*");
}

void loop() {
  // put your main code here, to run repeatedly:

}

