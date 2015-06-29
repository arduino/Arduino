/*
 Basic MQTT example 
 
  - connects to an MQTT server
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic"
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

char server[] = "iot.eclipse.org";

byte buffer[128];

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Got a message, publishing it");
  // If length is larger than 128,
  // then make sure we do not write more then our buffer can handle
  if(length > 128) length = 128;
  
  memcpy(buffer, payload, length);
  client.publish("outTopic", buffer, length);
}

void setup()
{
  Serial.begin(115200);
  
  // Start Ethernet with the build in MAC Address
  Ethernet.begin(0);
  
  IPAddress ip = Ethernet.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

}

void loop()
{
  // Reconnect if the connection was lost
  if (!client.connected()) {
    Serial.println("Disconnected. Reconnecting....");

    if(!client.connect("energiaClient")) {
      Serial.println("Connection failed");
    } else {
      Serial.println("Connection success");
      if(client.subscribe("inTopic")) {
        Serial.println("Subscription successfull");
      }
    }
  }
  
  // Check if any message were received
  // on the topic we subsrcived to
  client.poll();
}
