/*
 Web client
 
 This sketch connects to a website (http://energia.nu)
 using a WiFi BoosterPack.
 
 Initial version created by  dlf (Metodo2 srl)
 Modified 2013 by Robert Wessels (http://energia.nu)
 
 Circuit:
 * MSP430F5529 LaunchPad with WiFi BoosterPack

 */
 
#include <SPI.h>
#include <WiFi.h>

char ssid[] = "energia";     // your network name (SSID) 
char pass[] = "supersecret"; // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(50, 62, 217, 1); // numeric IP for Energia.nu (no DNS)
//char server[] = "energia.nu";    // name address for Energia.nu (using DNS)

// Initialize the WiFi client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200); 

  // Set communication pins for CC3000
  WiFi.setCSpin(18);  // 18: P2_2 @ F5529, PE_0 @ LM4F/TM4C
  WiFi.setENpin(2);   //  2: P6_5 @ F5529, PB_5 @ LM4F/TM4C
  WiFi.setIRQpin(19); // 19: P2_0 @ F5529, PB_2 @ LM4F/TM4C

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
  WiFi.begin(ssid, pass);
  Serial.println("Connected to wifi");
  Serial.println("Waiting for DHCP address....");
  // wait for 5 seconds for connection:
  delay(5000);
  printWifiStatus();
  
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET /hello.html HTTP/1.1");
    client.println("Host:energia.nu");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Failed to connect");
    while(true);    
  }
}

void loop() {
  // if there are incoming bytes available 
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();

    // do nothing forevermore:
    while(true);
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
