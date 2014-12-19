#include <Ethernet.h>
#include <EthernetStack.h>
#include <IPAddress.h>
#include <Countdown.h>
#include <MQTTClient.h>

// IBM IoT Foundation Cloud Settings
#define MQTT_MAX_PACKET_SIZE 100
#define IBMSERVERURLLEN  64
#define IBMIOTFSERVERSUFFIX "messaging.internetofthings.ibmcloud.com"
char organization[] = "quickstart";
char typeId[] = "iotsample-ti-energia";
char pubtopic[] = "iot-2/evt/status/fmt/json";
char deviceId[] = "000000000000";
char clientId[64];

char mqttAddr[IBMSERVERURLLEN];
int mqttPort = 1883;

MACAddress mac;
  
EthernetStack ipstack;  
MQTT::Client<EthernetStack, Countdown, MQTT_MAX_PACKET_SIZE> client(ipstack);

void setup() {
  uint8_t macOctets[6];
  
  Serial.begin(115200);

  Serial.println("Starting Ethernet");
  Ethernet.enableLinkLed();
  Ethernet.enableActivityLed();
  Ethernet.begin(0);

  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (Ethernet.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  // We are connected and have an IP address.
  Serial.print("\nIP Address obtained: ");
  Serial.println(Ethernet.localIP());

  mac = Ethernet.macAddress(macOctets);
  Serial.print("MAC Address: ");
  Serial.println(mac);
  
  // Use MAC Address as deviceId
  sprintf(deviceId, "%02x%02x%02x%02x%02x%02x", macOctets[0], macOctets[1], macOctets[2], macOctets[3], macOctets[4], macOctets[5]);
  Serial.print("deviceId: ");
  Serial.println(deviceId);

  sprintf(clientId, "d:%s:%s:%s", organization, typeId, deviceId);
  sprintf(mqttAddr, "%s.%s", organization, IBMIOTFSERVERSUFFIX);

  Serial.println("IBM IoT Foundation QuickStart example, view data in cloud here");
  Serial.print("--> http://quickstart.internetofthings.ibmcloud.com/#/device/");
  Serial.println(deviceId);
}

void loop() {

  int rc = -1;  
  if (!client.isConnected()) {
    Serial.print("Connecting to ");
    Serial.print(mqttAddr);
    Serial.print(":");
    Serial.println(mqttPort);
    Serial.print("With client id: ");
    Serial.println(clientId);
    
    while (rc != 0) {
      rc = ipstack.connect(mqttAddr, mqttPort);
    }

    MQTTPacket_connectData connectData = MQTTPacket_connectData_initializer;
    connectData.MQTTVersion = 3;
    connectData.clientID.cstring = clientId;
    
    rc = -1;
    while ((rc = client.connect(connectData)) != 0)
      ;
    Serial.println("Connected\n");
  }

  
  char json[56] = "{\"d\":{\"myName\":\"TILaunchPad\",\"temperature\":";

  dtostrf(getTemp(),1,2, &json[43]);
  json[48] = '}';
  json[49] = '}';
  json[50] = '\0';
  Serial.print("Publishing: ");
  Serial.println(json);
  MQTT::Message message;
  message.qos = MQTT::QOS0; 
  message.retained = false;
  message.payload = json; 
  message.payloadlen = strlen(json);
  rc = client.publish(pubtopic, message);
  if (rc != 0) {
    Serial.print("Message publish failed with return code : ");
    Serial.println(rc);
  }
  
  // Wait for one second before publishing again
  client.yield(1000);
}

double getTemp(void) {
  return (float)(147.5 - ((75 * 3.3 * (long)analogRead(TEMPSENSOR)) / 4096));
}
