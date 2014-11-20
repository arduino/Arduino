/*
  PubNub sample JSON-parsing client with WiFi support

  This combines two sketches: the PubNubJson example of PubNub library
  and the WifiWebClientRepeating example of the WiFi library.

  This sample client will properly parse JSON-encoded PubNub subscription
  replies using the aJson library. It will send a simple message, then
  properly parsing and inspecting a subscription message received back.

  This is achieved by integration with the aJson library. You will need
  a version featuring Wiring Stream integration, that can be found
  at http://github.com/pasky/aJson as of 2013-05-30.

  Circuit:
  * Wifi shield attached to pins 10, 11, 12, 13
  * (Optional) Analog sensors attached to analog pin.
  * (Optional) LEDs to be dimmed attached to PWM pins 8 and 9.


  Please refer to the PubNubJson example description for some important
  notes, especially regarding memory saving on Arduino Uno/Duemilanove.
  You can also save some RAM by not using WiFi password protection.


  created 30 May 2013
  by Petr Baudis

  https://github.com/pubnub/pubnub-api/tree/master/arduino
  This code is in the public domain.
  */

#include <SPI.h>
#include <WiFi.h>
#include <PubNub.h>
#include <aJSON.h>

// your network name also called SSID
char ssid[] = "energia";
// your network password
char password[] = "launchpad";
// your network key Index number (needed only for WEP)
static int keyIndex = 0;

const static char pubkey[] = "demo";
const static char subkey[] = "demo";
const static char channel[] = "hello_world";

/* Modify this with the analog channels you would like to read */
/* CC3200, MSP430F5529 TivaC123, TivaC1294 LaunchPads */
#define NUM_CHANNELS 4
const static uint8_t analog_pins[] = {2, 6, 23, 24};

void setup()
{
	Serial.begin(115200);
	Serial.println("Serial set up");

	if (WiFi.status() == WL_NO_SHIELD) {
	  Serial.println("WiFi shield not present");
	  while(true); // stop
	}

	int status;
	// attempt to connect to Wifi network:
	do {
		Serial.print("WiFi connecting to SSID: ");
		Serial.println(ssid);

		// Connect to the network. Uncomment whichever line is right for you:
		//status = WiFi.begin(ssid); // open network
		//status = WiFi.begin(ssid, keyIndex, key); // WEP network
		status = WiFi.begin(ssid, password); // WPA / WPA2 Personal network
	} while (status != WL_CONNECTED);
	Serial.println("WiFi set up");

	PubNub.begin(pubkey, subkey);
	Serial.println("PubNub set up");
}

aJsonObject *createMessage()
{
	aJsonObject *msg = aJson.createObject();

	aJsonObject *sender = aJson.createObject();
	aJson.addStringToObject(sender, "name", "Arduino");
	aJson.addItemToObject(msg, "sender", sender);

	int analogValues[NUM_CHANNELS];
	for (int i = 0; i < NUM_CHANNELS; i++) {
		analogValues[i] = analogRead(analog_pins[i]);
	}
	aJsonObject *analog = aJson.createIntArray(analogValues, NUM_CHANNELS);
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
	// Intriguingly, the WiFi library doesn't seem to have a call
	// equivalent to Ethernet.maintain();
	//WiFi.maintain();

	WiFiClient *client;

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
