/*
  PubNub sample client

  This sample client will publish raw (JSON pre-encoded) PubNub messages.

  Circuit:
  * (Optional.) Analog sensors on pins A0 to A5.
  * (Optional.) LED on pin 9 for success indication.

  created 23 October 2012
  by Petr Baudis

  https://github.com/pubnub/pubnub-api/tree/master/arduino
  This code is in the public domain.
  */

#include <SPI.h>
#include <WiFi.h>
#include <PubNub.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

const int pubLedPin = RED_LED;

char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "hello_world";

// your network name also called SSID
char ssid[] = "energia";
// your network password
char password[] = "launchpad";

/* Modify this with the analog channels you would like to read */
/* CC3200, MSP430F5529 TivaC123, TivaC1294 LaunchPads */
#define NUM_CHANNELS 4
const static uint8_t analog_pins[] = {2, 6, 23, 24};

void setup()
{
	pinMode(pubLedPin, OUTPUT);
	digitalWrite(pubLedPin, LOW);

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
	WiFiClient *client;

	char msg[64] = "{\"analog\":[";
	for (int i = 0; i < NUM_CHANNELS; i++) {
		sprintf(msg + strlen(msg), "%d", analogRead(analog_pins[i]));
		if (i < NUM_CHANNELS - 1)
			strcat(msg, ",");
	}
	strcat(msg, "]}");

	Serial.print("publishing message: ");
	Serial.println(msg);
	client = PubNub.publish(channel, msg);
	if (!client) {
		Serial.println("publishing error");
	} else {
		flash(pubLedPin);
		client->stop();
	}

	delay(5000);
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
