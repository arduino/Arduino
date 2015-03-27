#include <CapacitiveSensorDue.h>
/*
#include <WiFi.h>
*/
#include <Arduino.h>
#line 5
CapacitiveSensorDue cs_13_8 = CapacitiveSensorDue(13,8);
void setup();
void loop();
#line 6
void setup()
{
	Serial.begin(9600);
}
void loop()
{
	long total1 = cs_13_8.read(30);
	Serial.println(total1);
	delay(100);
}

