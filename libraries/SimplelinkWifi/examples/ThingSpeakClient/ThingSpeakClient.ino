/*

 Energia --> ThingSpeak Channel via CC3000 SimpleLink WiFi BoosterPack
 
 The ThingSpeak Client sketch is designed for the LaunchPad and WiFi BoosterPack.
 This sketch updates a channel feed with an analog input reading via the
 ThingSpeak API (http://community.thingspeak.com/documentation/)
 using HTTP POST. The LaunchPad uses DHCP and DNS for a simpler network setup.
 The sketch also includes a Watchdog / Reset function to make sure the
 Arduino stays connected and/or regains connectivity after a network outage.
 Use the Serial Monitor on the Arduino IDE to see verbose network feedback
 and ThingSpeak connectivity status.
 
 Getting Started with ThingSpeak:
 
   * Sign Up for New User Account - https://www.thingspeak.com/users/new
   * Register your Arduino by selecting Devices, Add New Device
   * Once the Arduino is registered, click Generate Unique MAC Address
   * Enter the new MAC Address in this sketch under "Local Network Settings"
   * Create a new Channel by selecting Channels and then Create New Channel
   * Enter the Write API Key in this sketch under "ThingSpeak Settings"
 
 Energia Requirements:
 
   * F5529 LaunchPad with CC3000 SimpleLink BoosterPack
   * Energia IDE 0101E0010 or later
   
  Network Requirements:

   * Ethernet port on Router    
   * DHCP enabled on Router
 
 Created: October 16, 2013 by Robert Wessels (http://energia.nu)
 Derived from example Sketch by Hans Scharler (http://www.iamshadowlord.com)
 
*/

#include <SPI.h>
#include <WiFi.h>

char ssid[] = "energia";    // your network SSID (name) 
char pass[] = "supersecret"; // your network password (use for WPA, or use as key for WEP)


// ThingSpeak Settings
//char thingSpeakAddress[] = "api.thingspeak.com";
IPAddress hostIp(184,106,153,149);
// ThingSpeak API key
String writeAPIKey = "THINGSPEAKAPIKEY";
 // Time interval in milliseconds to update ThingSpeak (number of seconds * 1000 = interval)
const int updateThingSpeakInterval = 20 * 1000;

// Variable Setup
long lastConnectionTime = 0; 
boolean lastConnected = false;
int failedCounter = 0;

// Initialize WiFi Client
WiFiClient client;

void setup()
{
  // Start Serial for debugging on the Serial Monitor
  Serial.begin(115200);

  // Set communication pins for CC3000
  WiFi.setCSpin(18);  // 18: P2_2 @ F5529, PE_0 @ LM4F/TM4C
  WiFi.setENpin(2);   //  2: P6_5 @ F5529, PB_5 @ LM4F/TM4C
  WiFi.setIRQpin(19); // 19: P2_0 @ F5529, PB_2 @ LM4F/TM4C

  // Start WiFi
  startWiFi();
}

void loop()
{
  // Read value from Temperature Sensor
  String analogPin0 = String(analogRead(A0), DEC);
  // Read push button S1
  String digitalPin = String(digitalRead(PUSH1), DEC);

  // Print Update Response to Serial Monitor
  if (client.available())
  {
    char c = client.read();
    Serial.print(c);
  }
  // Disconnect from ThingSpeak
  if (!client.connected() && lastConnected)
  {
    Serial.println("...disconnected");
    Serial.println();
    
    client.stop();
  }
  
  // Update ThingSpeak
  if(!client.connected() && (millis() - lastConnectionTime > updateThingSpeakInterval))
  {
    updateThingSpeak("field1="+analogPin0+"&field2="+digitalPin);
  }

  // Check if WiFi needs to be restarted
  if (failedCounter > 3 ) {failedCounter = 0; startWiFi();}
  
  lastConnected = client.connected();
}

void updateThingSpeak(String tsData)
{
  Serial.println("Updating ThingSpeak");
  
  if (client.connect(hostIp, 80)) {
    Serial.println("Connected to ThingSpeak!");
    Serial.println();
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+writeAPIKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n");
    client.print(tsData);
    
    Serial.println("Updated!");
    failedCounter = 0;
  } else {
    failedCounter++;
    client.stop();
 
    Serial.println("Connection to ThingSpeak Failed ("+String(failedCounter, DEC)+")");   
    Serial.println();
  }
  
  lastConnectionTime = millis();
}

void startWiFi()
{
  WiFi.disconnect();
  client.stop();

  Serial.print("Connecting LaunchPad to SSID:");
  Serial.print(ssid);
  Serial.println();
  
  // Connect to network and obtain an IP address using DHCP
  if (WiFi.begin(ssid, pass) == 0) {
    Serial.println("Connected to WiFi!");
    // Wait 5 seconds to get a valid IP address
    delay(5000);
    printWifiStatus();
    Serial.println();
  } else {
    Serial.println("LaunchPad connected to network using DHCP");
    Serial.println();
  }
  
  delay(1000);
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
