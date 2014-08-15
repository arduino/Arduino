#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

/*
  Repeating Wifi Web Client

 This sketch connects to a a web server and makes a request

 Circuit:
 * WiFi shield attached to pins SPI pins and pin 7

 created 23 April 2012
 modified 31 May 2012
 by Tom Igoe
 modified 13 Jan 2014
 by Federico Vanzati
 modified 6 July 2014
 by Noah Luskey

 This code is in the public domain.

 Circuit:
 * CC3200 WiFi LaunchPad or CC3100 WiFi BoosterPack
   with TM4C or MSP430 LaunchPad
 */

char ssid[] = "your network";      //  your network SSID (name)
char pass[] = "your password";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

// Initialize the Wifi client library
WiFiClient client;

// server address:
char server[] = "energia.nu";
//IPAddress server(50,62,217,1);

unsigned long lastConnectionTime = 0;            // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10L * 1000L; // delay between updates, in milliseconds

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);

  // print the network name (SSID);
  Serial.print("Attempting to connect to Network named: ");
  Serial.print(ssid);

  uint16_t now = millis();
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  status = WiFi.begin(ssid, pass);
  while ( status != WL_CONNECTED) {
    status = WiFi.status();
    Serial.print(".");
    // Print dots while attempting to connect
    delay(100);
    // Print a new line every second
    if(millis() - now > 1000) {
      Serial.println();
      now = millis();
    }
  }

  Serial.println("\nConnected to wifi");

  // wait for an assigned IP address
  Serial.println("Waiting for IP address.");
  while (WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    // Print dots while while waiting for IP address
    delay(100);
    // Print a new line every second
    if(millis() - now > 1000) {
      Serial.println();
      now = millis();
    }
  }

  // We are connected and have an IP address.
  // Print the WiFi status.
  printWifiStatus();
}

void loop() {
  // if there's incoming data from the net connection.
  // send it out the serial port.  This is for debugging
  // purposes only:
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if ten seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }

}

// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    // send the HTTP PUT request:
    client.println("GET /latest.txt HTTP/1.1");
    client.println("Host: www.energia.nu");
    client.println("User-Agent: Energia/1.1");
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
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


