/*
  Web client
 
 This sketch demonstrate Ethernet lib cooperative multitasking.
 
 It open two parallel connections to a website using an Arduino
 Ethernet shield, and prints the results when finished.
 
 A third task keep blinking the LED on pin 13.
 
 Circuit:
 * Ethernet shield
 
 created 23 Nov 2012
 by Cristian Maglie
 
 */

#include <SPI.h>
#include <Ethernet.h>
#include <Scheduler.h>

byte mac[] = { 
  0x2E, 0xA2, 0xB1, 0x3F, 0xF6, 0x56 };

// Change with your target server.
IPAddress server(192,168,1,20);

void setup() {
  // Set LED pin as OUTPUT and start blinking task.
  pinMode(13, OUTPUT);
  Scheduler.startLoop(blinkLed);
  
  Serial.begin(9600);
  while (!Serial)
    ;

  // Configure ethernet
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    for(;;)
      ;
  }
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet mask  : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Gateway IP   : ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS IP       : ");
  Serial.println(Ethernet.dnsServerIP());
  Serial.println();
}

EthernetClient client1;
EthernetClient client2;

char buffer1[4096];
char buffer2[4096];

boolean done1 = false;
boolean done2 = false;

void loop() {
  Scheduler.start(task1);
  Scheduler.start(task2);

  // Wait for clients to finish jobs
  while (!done1)
    yield();
  while (!done2)
    yield();

  Serial.println();
  Serial.println("Client 1 received:");
  Serial.println("==================");
  Serial.println(buffer1);
  Serial.println();
  Serial.println("Client 2 received:");
  Serial.println("==================");
  Serial.println(buffer2);

  // Halt
  for (;;) 
    yield();
}

void task1() {
  Serial.println("CONNECTING-1");
  client1.connect(server, 80);
  Serial.println("CONNECTED-1");

  client1.println("GET /site1 HTTP/1.0");
  client1.println();

  int i=0;
  while (client1.connected() && i<4096) {
    if (client1.available())
      buffer1[i++] = client1.read();
    if ((i%16)==0)
      Serial.print(".");
    // slow down to show that other task can run in parallel
    delay(1);
  }
  buffer1[i]=0;

  client1.stop();
  Serial.println("DISCONNECTED-1");

  done1 = true;
}

void task2() {
  Serial.println("CONNECTING-2");
  client2.connect(server, 80);
  Serial.println("CONNECTED-2");
  
  client2.println("GET /site2 HTTP/1.0");
  client2.println();

  int i=0;
  while (client2.connected() && i<4096) {
    if (client2.available())
      buffer2[i++] = client2.read();
    if ((i%16)==0)
      Serial.print("x");
    delay(1);
  }
  buffer2[i]=0;

  client2.stop();
  Serial.println("DISCONNECTED-2");

  done2 = true;
}

// Monitor loop to see if scheduling is running properly.
// Just blink an LED.
void blinkLed() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}
