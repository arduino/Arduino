#include <SPI.h>
#include <WiFi.h>

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting WiFi SmartConfig");
  WiFi.startSmartConfig();

  Serial.print("Connected to SSID: ");
  Serial.println(WiFi.SSID());

  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  // Noting to do
}
