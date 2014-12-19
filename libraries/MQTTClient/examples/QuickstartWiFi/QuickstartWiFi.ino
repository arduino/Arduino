#include <SPI.h>
#include <WiFi.h>
#include <WifiIPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

// your network name also called SSID
char ssid[] = "energia";
// your network password
char password[] = "launchpad";

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

// getTemp() function for cc3200
#ifdef TARGET_IS_CC3101
#include <Wire.h>
#include "Adafruit_TMP006.h"
Adafruit_TMP006 tmp006(0x41);
#endif
  
WifiIPStack ipstack;  
MQTT::Client<WifiIPStack, Countdown, MQTT_MAX_PACKET_SIZE> client(ipstack);

void setup() {
  uint8_t macOctets[6];
  
  Serial.begin(115200);
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid); 
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  // We are connected and have an IP address.
  Serial.print("\nIP Address obtained: ");
  Serial.println(WiFi.localIP());

  mac = WiFi.macAddress(macOctets);
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

  #ifdef TARGET_IS_CC3101
  if (!tmp006.begin()) {
    Serial.println("No sensor found");
    while (1);
  }
  #endif
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

// getTemp() function for MSP430F5529
#if defined(__MSP430F5529)
// Temperature Sensor Calibration-30 C
#define CALADC12_15V_30C  *((unsigned int *)0x1A1A)
// Temperature Sensor Calibration-85 C
#define CALADC12_15V_85C  *((unsigned int *)0x1A1C)

double getTemp() {
 return (float)(((long)analogRead(TEMPSENSOR) - CALADC12_15V_30C) * (85 - 30)) /
        (CALADC12_15V_85C - CALADC12_15V_30C) + 30.0f;
}

// getTemp() function for Stellaris and TivaC LaunchPad
#elif defined(TARGET_IS_SNOWFLAKE_RA0) || defined(TARGET_IS_BLIZZARD_RB1)

double getTemp() {
  return (float)(147.5 - ((75 * 3.3 * (long)analogRead(TEMPSENSOR)) / 4096));
}

// getTemp() function for cc3200
#elif defined(TARGET_IS_CC3101)
double getTemp() {
  return (double)tmp006.readObjTempC();
}
#else
double getTemp() {
  return 21.05;
}
#endif
