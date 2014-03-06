/*

 Arduino --> ThingSpeak Channel via Ethernet
 
 The ThingSpeak Client sketch is designed for the Arduino and Ethernet.
 This sketch updates a channel feed with an analog input reading via the
 ThingSpeak API (http://community.thingspeak.com/documentation/)
 using HTTP POST. The Arduino uses DHCP and DNS for a simpler network setup.
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
 
 Arduino Requirements:
 
   * Arduino with Ethernet Shield or Arduino Ethernet
   * Arduino 1.0 IDE
   
  Network Requirements:

   * Ethernet port on Router    
   * DHCP enabled on Router
   * Unique MAC Address for Arduino
 
 Created: October 17, 2011 by Hans Scharler (http://www.iamshadowlord.com)
 
 Additional Credits:
 Example sketches from Arduino team, Ethernet by Adrian McEwen
 
*/

#include <Ethernet.h>

// ThingSpeak Settings
char thingSpeakAddress[] = "api.thingspeak.com";
String writeAPIKey = "YOURTHINSPEAKAPI";
const int updateThingSpeakInterval = 1 * 1000;      // Time interval in milliseconds to update ThingSpeak (number of seconds * 1000 = interval)

// Variable Setup
long lastConnectionTime = 0; 
boolean lastConnected = false;
int failedCounter = 0;

EthernetClient client;
// Initialize Arduino Ethernet Client
void setup()
{
  // Start Serial for debugging on the Serial Monitor
  Serial.begin(115200);
  delay(100);
  Ethernet.begin(0);
  // print the Ethernet board/shield's IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  pinMode(D1_LED, OUTPUT);
}

void loop()
{
  // Read value from Analog Input Pin 0
  String analogPin0 = String(analogRead(A10), DEC);
 
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
    Serial.println("client stopped");
  }

  // Update ThingSpeak
  if(!client.connected() && (millis() - lastConnectionTime > updateThingSpeakInterval))
  {
    updateThingSpeak("field1="+analogPin0);
  }
  
  // Check if Arduino Ethernet needs to be restarted
  lastConnected = client.connected();
}

void updateThingSpeak(String tsData)
{
  Serial.println("Updating ThingSpeak");
  if (client.connect(thingSpeakAddress, 80))
  {
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
    
    failedCounter = 0;
  } else {
    failedCounter++;
    client.stop();
    
    Serial.println("Connection to ThingSpeak Failed ("+String(failedCounter, DEC)+")");   
    Serial.println();
  }

  lastConnectionTime = millis();
}

