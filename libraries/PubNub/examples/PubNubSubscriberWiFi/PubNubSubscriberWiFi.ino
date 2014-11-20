/*
  PubNub sample subscribe client

  This sample client will subscribe to and handle raw PubNub messages
  (not doing any JSON decoding).  It does so with a randomly generated
  UUID.

  Circuit:
  * (Optional.) RED_LED for reception indication.
  * Internal temperature sensor (noise source for random number generator)

  created 23 October 2012
  by Petr Baudis

  https://github.com/pubnub/pubnub-api/tree/master/arduino
  This code is in the public domain.
  */

#include <SPI.h>
#include <WiFi.h>
#include <PubNub.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

const int subLedPin = RED_LED;

char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "hello_world";
char uuid[] = "xxxxxxxx-xxxx-4444-9999-xxxxxxxxxxxx";

// your network name also called SSID
char ssid[] = "energia";
// your network password
char password[] = "launchpad";

void random_uuid() {
	randomSeed(analogRead(0) + millis() * 1024);
	snprintf(uuid, sizeof(uuid), "%04lx%04lx-%04lx-4444-9999-%04lx%04lx%04lx",
		random(0x10000), random(0x10000), random(0x10000),
		random(0x10000), random(0x10000), random(0x10000));
}

void setup()
{
	pinMode(subLedPin, OUTPUT);
	digitalWrite(subLedPin, LOW);

	Serial.begin(115200);
	Serial.println("Serial set up");

	// attempt to connect to Wifi network:
	Serial.print("Attempting to connect to Network named: ");
	// print the network name (SSID);
	Serial.println(ssid); 
	// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
	WiFi.begin(ssid, password);
	while ( WiFi.status() != WL_CONNECTED) {
		// print dots while we wait to connect
		Serial.print(".");
		delay(300);
	}

	Serial.println("\nYou're connected to the network");
	Serial.println("Waiting for an ip address");

	while (WiFi.localIP() == INADDR_NONE) {
		// print dots while we wait for an ip addresss
		Serial.print(".");
		delay(300);
	}

	Serial.println("\nIP Address obtained");
	// We are connected and have an IP address.
	// Print the WiFi status.
	printWifiStatus();

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

void printWifiStatus() {
	// print the SSID of the network you're attached to:
	Serial.print("SSID: ");
	Serial.println(WiFi.SSID());

	// print your WiFi IP address:
	IPAddress ip = WiFi.localIP();
	Serial.print("IP Address: ");
	Serial.println(ip);

	// print the received signal strength:
	long rssi = WiFi.RSSI();
	Serial.print("signal strength (RSSI):");
	Serial.print(rssi);
	Serial.println(" dBm");
}
