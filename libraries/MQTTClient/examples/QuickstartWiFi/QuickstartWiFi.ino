#include <SPI.h>
#include <WiFi.h>
#include <WifiIPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

char quickstartMQTTDNS[] = "quickstart.messaging.internetofthings.ibmcloud.com";
int mqttPort = 1883;
//The convention to be followed is d:quickstart:iotsample-energia:<MAC Address>
char clientId[] = "d:quickstart:iotsample-energia:00a2bb3c7e02";
char topic[] = "iot-2/evt/status/fmt/json";

// getTemp() function for cc3200
#ifdef TARGET_IS_CC3101
#include <Wire.h>
#include "Adafruit_TMP006.h"
Adafruit_TMP006 tmp006(0x41);
#endif

String dummy(56);

// your network name also called SSID
char ssid[] = "energia1";
// your network password
char password[] = "launchpad";

#define MQTT_MAX_PACKET_SIZE 100
  
WifiIPStack ipstack;  
MQTT::Client<WifiIPStack, Countdown, MQTT_MAX_PACKET_SIZE> client(ipstack);

void setup() {
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

  Serial.println("\nIP Address obtained");
  // We are connected and have an IP address.
  Serial.println(WiFi.localIP());

  #ifdef __CC3200R1M1RGC__
  if (!tmp006.begin()) {
    Serial.println("No sensor found");
    while (1);
  }
  #endif
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

  
  char json[56] = "{\"d\":{\"myName\":\"TILaunchPad\",\"temperature\":";

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
#elif defined(__CC3200R1M1RGC__)
double getTemp() {
  return (double)tmp006.readObjTempC();
}
#else
double getTemp() {
  return 21.05;
}
#endif
