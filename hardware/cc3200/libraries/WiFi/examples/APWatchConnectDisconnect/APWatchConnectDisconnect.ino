/*
    WiFi AP-mode Connect/Disconnect monitor
    
    This sketch will put the CC3200 or CC3100 in Access Point mode and report
    when WiFi clients (cellphone, laptop, etc) connect to the Access Point and when
    they disconnect.
    
    Connections trigger a serial dump of every connected client with their IP and MAC.
    Disconnections only trigger a simple notification, as the "last disconnected client"
    information is not saved anywhere.
    
    Created 11/11/2014 by Eric Brundick for the Energia project.
 */
 
#ifndef __CC3200R1M1RGC__
// No need to include SPI.h for CC3200
#include <SPI.h>
#endif
#include <WiFi.h>


const char ssid[] = "MyEnergiaAP";
const char wifipw[] = "password";

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);  // LED will toggle when clients connect/disconnect
  digitalWrite(RED_LED, LOW);
  
  Serial.print("Setting up Access Point named: ");
  Serial.println(ssid);
  Serial.print("AP uses WPA and password is: ");
  Serial.println(wifipw);
  
  WiFi.beginNetwork((char *)ssid, (char *)wifipw);
  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for the AP config to complete
    Serial.print('.');
    delay(300);
  }
  Serial.println();
  Serial.println("AP active.");
}

unsigned int num_clients = 0;

void loop()
{
  unsigned int a, i;

  a = WiFi.getTotalDevices();

  // Did a client connect/disconnect since the last time we checked?
  if (a != num_clients) {
    if (a > num_clients) {  // Client connect
      digitalWrite(RED_LED, !digitalRead(RED_LED));
      Serial.println("Client connected! All clients:");
      for (i = 0; i < a; i++) {
        Serial.print("Client #");
        Serial.print(i);
        Serial.print(" at IP address = ");
        Serial.print(WiFi.deviceIpAddress(i));
        Serial.print(", MAC = ");
        Serial.println(WiFi.deviceMacAddress(i));
      }
    } else {  // Client disconnect
      digitalWrite(RED_LED, !digitalRead(RED_LED));
      Serial.println("Client disconnected.");
    }    
    num_clients = a;
  }

  delay(100);
}
