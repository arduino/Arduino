/*
  CreateNetwork
  Start WiFi in in AP mode creating a network that you can connecto to
  from a PC or SmartPhone. There is a limitation that only ONE device
  can be connected. Trying to connect to the network with a second client 
  will fail. To connect with a different device, first disconnect the device
  currently connected.
  
  Hardware Required:
  * CC3200 LaunchPad or MSP430/TivaC LaunchPad with CC3200 BoosterPack

  Created November 2014
  by Robert Wessels
  
  This example code is in the public domain.
*/
#include <SPI.h>
#include <WiFi.h>

char wifi_name[] = "foobar";
char wifi_password[] = "launchpad";

void setup()
{
  Serial.begin(115200);

  // Start WiFi and create a network with wifi_name as the network name
  // with wifi_password as the password.
  Serial.print("Starting network...");
  WiFi.beginNetwork(wifi_name, wifi_password);
  Serial.println("done.");
}

void loop()
{
  // Nothing ToDo.
}
