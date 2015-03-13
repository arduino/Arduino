/*
  PubNub sample JSON-parsing client

  This sample client will properly parse JSON-encoded PubNub subscription
  replies using the aJson library. It will send a simple message, then
  properly parsing and inspecting a subscription message received back.

  This is achieved by integration with the aJson library. You will need
  a version featuring Wiring Stream integration, that can be found
  at http://github.com/interactive-matter/aJson as of 2012-11-12.

  Circuit:
  * Ethernet shield attached to pins 10, 11, 12, 13
  * (Optional) Analog sensors attached to analog pin.
  * (Optional) LEDs to be dimmed attached to PWM pins 8 and 9.


  Note that due to use of the aJSON library, this sketch is more memory
  sensitive than the others. In order to be able to use it on the boards
  based on ATMega328, some special care is needed. Memory saving tips:

  (i) Remove myI, dnsI from the sketch unless you need them.

  (ii) In the aJSON library's utility/stringbuffer.c, change BUFFER_SIZE
  from 256 to 128 or less. Note that this will limit the length of JSON
  messages your script will be able to process.

  (iii) In the file hardware/arduino/cores/arduino/HardwareSerial.cpp
  which is part of your Arduino installation, decrease SERIAL_BUFFER_SIZE
  from 64 to 16 or even smaller value (depends on your Serial usage).

  Usually, (i) and (ii) is enough; try (iii) if you can't do one of these.
  If you are still short on memory (will manifest as connection error,
  there will be not enough memory left for EthernetClient), some very
  aggressive code changes would be required, or re-consider whether you
  cannot write ad-hoc JSON generating/parsing code covering just your
  particular scenario instead of using the generic aJSON library.


  created 26 October 2012
  by Petr Baudis

  https://github.com/pubnub/pubnub-api/tree/master/arduino
  This code is in the public domain.
  */

#include <SPI.h>
#include <Ethernet.h>
#include <PubNub.h>
#include <aJSON.h>

// Some Ethernet shields have a MAC address printed on a sticker on the shield;
// fill in that address here, or choose your own at random:
const static byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Memory saving tip: remove myI and dnsI from your sketch if you
// are content to rely on DHCP autoconfiguration.
IPAddress myI(10, 42, 0, 2);
IPAddress dnsI(8, 8, 8, 8);

const static char pubkey[] = "demo";
const static char subkey[] = "demo";
const static char channel[] = "hello_world";

void setup()
{
	Serial.begin(9600);
	Serial.println("Serial set up");

	Ethernet.begin((byte*) mac, myI, dnsI);
	Serial.println("Ethernet set up");

	PubNub.begin(pubkey, subkey);
	Serial.println("PubNub set up");
}

aJsonObject *createMessage()
{
	aJsonObject *msg = aJson.createObject();

	aJsonObject *sender = aJson.createObject();
	aJson.addStringToObject(sender, "name", "Arduino");
	aJson.addNumberToObject(sender, "mac_last_byte", mac[5]);
	aJson.addItemToObject(msg, "sender", sender);

	int analogValues[6];
	for (int i = 0; i < 6; i++) {
		analogValues[i] = analogRead(i);
	}
	aJsonObject *analog = aJson.createIntArray(analogValues, 6);
	aJson.addItemToObject(msg, "analog", analog);
	return msg;
}

/* Process message like: { "pwm": { "8": 0, "9": 128 } } */
void processPwmInfo(aJsonObject *item)
{
	aJsonObject *pwm = aJson.getObjectItem(item, "pwm");
	if (!pwm) {
		Serial.println("no pwm data");
		return;
	}

	const static int pins[] = { 8, 9 };
	const static int pins_n = 2;
	for (int i = 0; i < pins_n; i++) {
		char pinstr[3];
		snprintf(pinstr, sizeof(pinstr), "%d", pins[i]);

		aJsonObject *pwmval = aJson.getObjectItem(pwm, pinstr);
		if (!pwmval) continue; /* Value not provided, ok. */
		if (pwmval->type != aJson_Int) {
			Serial.print(" invalid data type ");
			Serial.print(pwmval->type, DEC);
			Serial.print(" for pin ");
			Serial.println(pins[i], DEC);
			continue;
		}

		Serial.print(" setting pin ");
		Serial.print(pins[i], DEC);
		Serial.print(" to value ");
		Serial.println(pwmval->valueint, DEC);
		analogWrite(pins[i], pwmval->valueint);
	}
}

void dumpMessage(Stream &s, aJsonObject *msg)
{
	int msg_count = aJson.getArraySize(msg);
	for (int i = 0; i < msg_count; i++) {
		aJsonObject *item, *sender, *analog, *value;
		s.print("Msg #");
		s.println(i, DEC);

		item = aJson.getArrayItem(msg, i);
		if (!item) { s.println("item not acquired"); delay(1000); return; }

		processPwmInfo(item);

		/* Below, we parse and dump messages from fellow Arduinos. */

		sender = aJson.getObjectItem(item, "sender");
		if (!sender) { s.println("sender not acquired"); delay(1000); return; }

		s.print(" mac_last_byte: ");
		value = aJson.getObjectItem(sender, "mac_last_byte");
		if (!value) { s.println("mac_last_byte not acquired"); delay(1000); return; }
		s.print(value->valueint, DEC);

		s.print(" A2: ");
		analog = aJson.getObjectItem(item, "analog");
		if (!analog) { s.println("analog not acquired"); delay(1000); return; }
		value = aJson.getArrayItem(analog, 2);
		if (!value) { s.println("analog[2] not acquired"); delay(1000); return; }
		s.print(value->valueint, DEC);

		s.println();
	}
}

void loop()
{
	Ethernet.maintain();

	EthernetClient *client;

	/* Publish */

	Serial.print("publishing a message: ");
	aJsonObject *msg = createMessage();
	char *msgStr = aJson.print(msg);
	aJson.deleteItem(msg);

	// msgStr is returned in a buffer that can be potentially
	// needlessly large; this call will "tighten" it
	msgStr = (char *) realloc(msgStr, strlen(msgStr) + 1);

	Serial.println(msgStr);
	client = PubNub.publish(channel, msgStr);
	free(msgStr);
	if (!client) {
		Serial.println("publishing error");
		delay(1000);
		return;
	}
	client->stop();

	/* Subscribe and load reply */

	Serial.println("waiting for a message (subscribe)");
	client = PubNub.subscribe(channel);
	if (!client) {
		Serial.println("subscription error");
		delay(1000);
		return;
	}

	/* Parse */

	aJsonClientStream stream(client);
	msg = aJson.parse(&stream);
	client->stop();
	if (!msg) { Serial.println("parse error"); delay(1000); return; }
	dumpMessage(Serial, msg);
	aJson.deleteItem(msg);

	delay(10000);
}
