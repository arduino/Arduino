/*
  PubNub sample subscribe client

  This sample client will subscribe to and handle raw PubNub messages
  (not doing any JSON decoding).  It does so with a randomly generated
  UUID.

  Circuit:
  * Ethernet shield attached to pins 10, 11, 12, 13
  * (Optional.) LED on pin 8 for reception indication.
  * Pin A4 unconnected (noise source for random number generator)

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

char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "hello_world";
char uuid[] = "xxxxxxxx-xxxx-4444-9999-xxxxxxxxxxxx";

void random_uuid() {
	randomSeed(analogRead(4) + millis() * 1024);
	snprintf(uuid, sizeof(uuid), "%04lx%04lx-%04lx-4444-9999-%04lx%04lx%04lx",
		random(0x10000), random(0x10000), random(0x10000),
		random(0x10000), random(0x10000), random(0x10000));
}

void setup()
{
	pinMode(subLedPin, OUTPUT);
	digitalWrite(subLedPin, LOW);

	Serial.begin(9600);
	Serial.println("Serial set up");

	while (!Ethernet.begin(mac)) {
		Serial.println("Ethernet setup error");
		delay(1000);
	}
	Serial.println("Ethernet set up");

	PubNub.begin(pubkey, subkey);
	random_uuid();
	PubNub.set_uuid(uuid);
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

	PubSubClient *client;

	Serial.println("waiting for a message (subscribe)");
	client = PubNub.subscribe(channel);
	if (!client) {
		Serial.println("subscription error");
		delay(1000);
		return;
	}
	Serial.print("Received: ");
	while (client->wait_for_data()) {
		char c = client->read();
		Serial.print(c);
	}
	client->stop();
	Serial.println();
	flash(subLedPin);

	delay(200);
}
