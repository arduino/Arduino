#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);

EthernetServer server(23);

void setup() {
  Serial.begin(9600);
  Serial.println("\nTestEthernetServer setup");
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("ip:port ");
  Serial.print(Ethernet.localIP());
  Serial.println(":23");
}


void loop() {
  EthernetClient client = server.available();
  if (client) {
    client.println("Welcome");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == 'x') {
          client.println("Bye");
          delay(100);
          client.stop();
          break;
        }
      }
    }
    delay(1);
    client.stop();
  }
}

