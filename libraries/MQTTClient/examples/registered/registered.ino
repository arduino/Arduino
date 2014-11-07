#include <SPI.h>
#include <Ethernet.h>
#include <EthernetStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

#define MQTT_MAX_PACKET_SIZE 100
#define SIZE 100

int ledPin = 9;

// Update these with values suitable for your network.
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x03 };

int mqttPort = 1883;

char topic[] = "iot-2/evt/status/fmt/json";
char subTopic[] = "iot-2/cmd/+/fmt/json";

char organization[] = "w8wx0";
char typeId[] = "LaunchPad";

char deviceId[] = "00aabbccde03";

char authMethod[] = "use-token-auth";

char authToken[] = "W7TXtNbehlf7Bq5BEm";

char registeredMQTTDNS[] = "w8wx0.messaging.internetofthings.ibmcloud.com";

char clientId[] = "d:w8wx0:LaunchPad:00aabbccde03";
char registeredUrl[SIZE];

void callback(char* topic, byte* payload, unsigned int length);

EthernetStack ipstack;  
MQTT::Client<EthernetStack, Countdown, MQTT_MAX_PACKET_SIZE> client(ipstack);
void messageArrived(MQTT::MessageData& md);


void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);

  //build the mqtt url and the client id
  sprintf(clientId, "d:%s:%s:%s", organization, typeId, deviceId);
  sprintf(registeredUrl,"%s.messaging.internetofthings.ibmcloud.com",organization);
  delay(1000);
}

void loop() {
  int rc = -1;
  if (!client.isConnected()) {
    Serial.print("Connecting to Registered mode with clientid : ");
    Serial.print(clientId);
    Serial.print("\ton topic : ");
    Serial.println(registeredUrl);
    while (rc != 0) {
      rc = ipstack.connect(registeredUrl, mqttPort);
    }
    MQTTPacket_connectData options = MQTTPacket_connectData_initializer;
    options.MQTTVersion = 3;
    options.clientID.cstring = clientId;
    options.username.cstring = authMethod;
    options.password.cstring = authToken;
    options.keepAliveInterval = 10;
    rc = -1;
    while ((rc = client.connect(options)) != 0)
      ;
    Serial.println("Connected\n");
    
    //unsubscribe the topic, if it had subscribed it before.
 
    client.unsubscribe(subTopic);
    //Try to subscribe for commands
    if ((rc = client.subscribe(subTopic, MQTT::QOS0, messageArrived)) != 0) {
            Serial.print("Subscribe failed with return code : ");
            Serial.println(rc);
    } else {
          Serial.println("Subscribed\n");
    }
    Serial.println("Subscription tried......");
    
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
    Serial.print("Message publish failed with return code : ");
    Serial.println(rc);
  }

  client.yield(1000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Message has arrived");
  
  char * msg = (char *)malloc(length * sizeof(char));
  int count = 0;
  for(count = 0 ; count < length ; count++) {
    msg[count] = payload[count];
  }
  msg[count] = '\0';
  Serial.println(msg);
  
  if(length > 0) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);  
  }

  free(msg);
}

void messageArrived(MQTT::MessageData& md) {
  Serial.print("Message Received\t");
    MQTT::Message &message = md.message;
    int topicLen = strlen(md.topicName.lenstring.data) + 1;
//    char* topic = new char[topicLen];
    char * topic = (char *)malloc(topicLen * sizeof(char));
    topic = md.topicName.lenstring.data;
    topic[topicLen] = '\0';
    
    int payloadLen = message.payloadlen + 1;
//    char* payload = new char[payloadLen];
    char * payload = (char*)message.payload;
    payload[payloadLen] = '\0';
    
    String topicStr = topic;
    String payloadStr = payload;
    
    //Command topic: iot-2/cmd/blink/fmt/json

    if(strstr(topic, "/cmd/blink") != NULL) {
      Serial.print("Command IS Supported : ");
      Serial.print(payload);
      Serial.println("\t.....");
      
      pinMode(ledPin, OUTPUT);
      
      //Blink twice
      for(int i = 0 ; i < 2 ; i++ ) {
        digitalWrite(ledPin, HIGH);
        delay(250);
        digitalWrite(ledPin, LOW);
        delay(250);
      }
    } else {
      Serial.println("Command Not Supported:");            
    }
}

double getTemp(void) {
  return 20.0;
}
