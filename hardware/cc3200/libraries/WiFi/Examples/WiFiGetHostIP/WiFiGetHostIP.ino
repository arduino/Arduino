#include <WiFi.h>

char yourSSID[] = "your ssid";
char yourPASS[] = "your password";


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("**Simplelink IP by name demo**");
  Serial.print("Attempting to connect to ");
  Serial.println(yourSSID);
  
  WiFi.begin(yourSSID, yourPASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nCONNECTED");
}

void loop()
{
  
  if (Serial.available()) {
    char nameBuf[32];
    memset(nameBuf, 0, 32);
    int i = 0;
    while(Serial.available()) {
      nameBuf[i++] = Serial.read();
    }
    
    Serial.print("Getting IP for ");
    Serial.println(nameBuf);
    
    IPAddress IP(0,0,0,0);
    int iRet = WiFi.hostByName(nameBuf, IP);
    Serial.println(IP);
    delay(1000);
  }
  
  
}
