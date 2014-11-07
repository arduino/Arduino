#include <SPI.h>
#include <Ethernet.h>
#include <EthernetStack.h>
#include <Countdown.h>
#include <MQTTClient.h>


// Update these with values suitable for your network.
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
char quickstartMQTTDNS[] = "quickstart.messaging.internetofthings.ibmcloud.com";
int mqttPort = 1883;
//The convention to be followed is d:quickstart:iotsample-energia:<MAC Address>
char clientId[] = "d:quickstart:iotsample-energia:00aabbccde02";
char topic[] = "iot-2/evt/status/fmt/json";

#define MQTT_MAX_PACKET_SIZE 100
  
EthernetStack ipstack;  
MQTT::Client<EthernetStack, Countdown, MQTT_MAX_PACKET_SIZE> client(ipstack);

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  delay(2000);
}

void loop() {
  int rc = -1;
  if (!client.isConnected()) {
    Serial.println("Connecting\n");
    while (rc != 0) {
      rc = ipstack.connect(quickstartMQTTDNS, mqttPort);
    }
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    data.MQTTVersion = 3;
    data.clientID.cstring = clientId;
    rc = -1;
    while ((rc = client.connect(data)) != 0)
      ;
    Serial.println("Connected\n");
  }

  char json[56] = "{\"d\":{\"myName\":\"TI LaunchPad\",\"temperature\":";
  dtostrf(getTemp(),1,2, &json[43]);
  json[48] = '}';
  json[49] = '}';
  json[50] = '\0';
  Serial.println(json);
  MQTT::Message message;
  message.qos = MQTT::QOS0; 
  message.retained = false;
  message.payload = json; 
  message.payloadlen = strlen(json);
  rc = client.publish(topic, message);
  if (rc != 0) {
    Serial.print("return code from publish was ");
    Serial.println(rc);
  }
  client.yield(1000);
}

double getTemp(void) {
  return 21.0
}
