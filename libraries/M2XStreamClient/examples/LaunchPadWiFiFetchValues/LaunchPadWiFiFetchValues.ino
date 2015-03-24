#include <aJSON.h>
#include "SPI.h"
#include "WiFi.h"

#include "M2XStreamClient.h"

char ssid[] = "<ssid>"; //  your network SSID (name)
char pass[] = "<WPA password>";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

char deviceId[] = "<device id>"; // Device you want to receive values
char streamName[] = "<stream name>"; // Stream you want to receive values
char m2xKey[] = "<M2X access key>"; // Your M2X access key

WiFiClient client;
M2XStreamClient m2xClient(&client, m2xKey);

void setup() {
    Serial.begin(9600);

    // attempt to connect to Wifi network:
    Serial.print("Attempting to connect to Network named: ");
    // print the network name (SSID);
    Serial.println(ssid); 
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, pass);
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
  
    // you're connected now, so print out the status  
    printWifiStatus();
}

void loop() {
  aJsonObject *object = NULL;
  int response = m2xClient.listStreamValues(deviceId, streamName, NULL, &object);
  Serial.print("M2X client response code: ");
  Serial.println(response);

  if (response == -1) while(1) ;

  if (object) {
    aJsonObject *values = aJson.getObjectItem(object, "values");
    for (unsigned char i = 0; i < aJson.getArraySize(values); i++) {
      aJsonObject *item = aJson.getArrayItem(values, i);
      aJsonObject *timestamp = aJson.getObjectItem(item, "timestamp");
      aJsonObject *val = aJson.getObjectItem(item, "value");

      Serial.print("Found a data point, index: ");
      Serial.println(i);
      Serial.print("Timestamp: ");
      Serial.println(timestamp->valuestring);
      Serial.print("Value: ");
      switch (val->type) {
        case aJson_Int:
          Serial.println(val->valueint);
          break;
        case aJson_Float:
          Serial.println(val->valuefloat);
          break;
        case aJson_String:
          Serial.println(val->valuestring);
          break;
        default:
          Serial.println("(Unknown format)");
          break;
      }
    }
    aJson.deleteItem(object);
  }

  delay(5000);
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
