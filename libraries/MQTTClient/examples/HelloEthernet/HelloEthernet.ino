/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution. 
 *
 * The Eclipse Public License is available at 
 *   http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at 
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial contribution
 *******************************************************************************/

#define MQTTCLIENT_QOS2 1

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

char printbuf[100];

int arrivedcount = 0;

void messageArrived(MQTT::MessageData& md)
{
  MQTT::Message &message = md.message;
  
  sprintf(printbuf, "Message %d arrived: qos %d, retained %d, dup %d, packetid %d\n", 
		++arrivedcount, message.qos, message.retained, message.dup, message.id);
  Serial.print(printbuf);
  sprintf(printbuf, "Payload %s\n", (char*)message.payload);
  Serial.print(printbuf);
}


EthernetStack ipstack;
MQTT::Client<EthernetStack, Countdown> client = MQTT::Client<EthernetStack, Countdown>(ipstack);

byte mac[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 };  // replace with your device's MAC
const char* topic = "energia-sample";

void connect()
{
  char hostname[] = "iot.eclipse.org";
  int port = 1883;
  sprintf(printbuf, "Connecting to %s:%d\n", hostname, port);
  Serial.print(printbuf);
  int rc = ipstack.connect(hostname, port);
  if (rc != 1)
  {
    sprintf(printbuf, "rc from TCP connect is %d\n", rc);
    Serial.print(printbuf);
  }
 
  Serial.println("MQTT connecting");
  MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
  data.MQTTVersion = 3;
  data.clientID.cstring = (char*)"energia-sample";
  rc = client.connect(data);
  if (rc != 0)
  {
    sprintf(printbuf, "rc from MQTT connect is %d\n", rc);
    Serial.print(printbuf);
  }
  Serial.println("MQTT connected");
  
  rc = client.subscribe(topic, MQTT::QOS2, messageArrived);   
  if (rc != 0)
  {
    sprintf(printbuf, "rc from MQTT subscribe is %d\n", rc);
    Serial.print(printbuf);
  }
  Serial.println("MQTT subscribed");
}

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting Ethernet");
  Ethernet.enableLinkLed();
  Ethernet.enableActivityLed();
  Ethernet.begin(0);

  Serial.println("\nIP Address obtained");
  // We are connected and have an IP address.
  Serial.println(Ethernet.localIP());
  
  Serial.println("MQTT Hello example");
  connect();
}

void loop()
{
  if (!client.isConnected())
    connect();
  
  MQTT::Message message;
  
  arrivedcount = 0;

  // Send and receive QoS 0 message
  char buf[100];
  sprintf(buf, "Hello World! QoS 0 message");
  Serial.println(buf);
  message.qos = MQTT::QOS0;
  message.retained = false;
  message.dup = false;
  message.payload = (void*)buf;
  message.payloadlen = strlen(buf)+1;
  int rc = client.publish(topic, message);
  while (arrivedcount == 0)
    client.yield(1000);
        
  // Send and receive QoS 1 message
  sprintf(buf, "Hello World!  QoS 1 message");
  Serial.println(buf);
  message.qos = MQTT::QOS1;
  message.payloadlen = strlen(buf)+1;
  rc = client.publish(topic, message);
  while (arrivedcount == 1)
    client.yield(1000);
        
  // Send and receive QoS 2 message
  sprintf(buf, "Hello World!  QoS 2 message");
  Serial.println(buf);
  message.qos = MQTT::QOS2;
  message.payloadlen = strlen(buf)+1;
  rc = client.publish(topic, message);
  while (arrivedcount == 2)
    client.yield(1000);
    
  delay(2000);
}
