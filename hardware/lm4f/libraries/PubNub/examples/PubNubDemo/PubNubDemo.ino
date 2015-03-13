/*
  PubNub sample client

  This sample client will use just the minimal-footprint raw PubNub
  interface where it is your responsibility to deal with the JSON encoding.

  It will just send a hello world message and retrieve one back, reporting
  its deeds on serial console.

  Circuit:
  * Ethernet shield attached to pins 10, 11, 12, 13
  * (Optional.) LED on pin 8 for reception indication.
  * (Optional.) LED on pin 9 for publish indication.

  created 23 October 2012
  by Petr Baudis

  https://github.com/pubnub/pubnub-api/tree/master/arduino
  This code is in the public domain.
  */

#include <SPI.h>
#include <Ethernet.h>
#include <PubNub.h>

// Some Ethernet shields have a MAC address printed on a sticker on the shield;
// fill in that address here, or choose your own at random:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

const int subLedPin = 8;
const int pubLedPin = 9;

char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "hello_world";

void setup()
{
	pinMode(subLedPin, OUTPUT);
	pinMode(pubLedPin, OUTPUT);
	digitalWrite(subLedPin, LOW);
	digitalWrite(pubLedPin, LOW);

	Serial.begin(9600);
	Serial.println("Serial set up");

	while (!Ethernet.begin(mac)) {
		Serial.println("Ethernet setup error");
		delay(1000);
	}
	Serial.println("Ethernet set up");

	PubNub.begin(pubkey, subkey);
	Serial.println("PubNub set up");
}

void flash(int ledPin)
{
	/* Flash LED three times. */
	for (int i = 0; i < 3; i++) {
		digitalWrite(ledPin, HIGH);
		delay(100);
		digitalWrite(ledPin, LOW);
		delay(100);
	}
}

void loop()
{
	Ethernet.maintain();

	EthernetClient *client;

	Serial.println("publishing a message");
	client = PubNub.publish(channel, "\"\\\"Hello world!\\\" she said.\"");
	if (!client) {
		Serial.println("publishing error");
		delay(1000);
		return;
	}
	while (client->connected()) {
		while (client->connected() && !client->available()) ; // wait
		char c = client->read();
		Serial.print(c);
	}
	client->stop();
	Serial.println();
	flash(pubLedPin);

	Serial.println("waiting for a message (subscribe)");
	PubSubClient *pclient = PubNub.subscribe(channel);
	if (!pclient) {
		Serial.println("subscription error");
		delay(1000);
		return;
	}
	while (pclient->wait_for_data()) {
		char c = pclient->read();
		Serial.print(c);
	}
	pclient->stop();
	Serial.println();
	flash(subLedPin);

	Serial.println("retrieving message history");
	client = PubNub.history(channel);
	if (!client) {
		Serial.println("history error");
		delay(1000);
		return;
	}
	while (client->connected()) {
		while (client->connected() && !client->available()) ; // wait
		char c = client->read();
		Serial.print(c);
	}
	client->stop();
	Serial.println();

	delay(10000);
}
