#include <Ethernet.h>
#include <EthernetStack.h>
#include <Countdown.h>
#include <MQTTClient.h>

#define MQTT_MAX_PACKET_SIZE 100
#define SIZE 100

int ledPin = RED_LED;
// your network name also called SSID
char ssid[] = "energia1";
// your network password
char password[] = "launchpad";

int mqttPort = 1883;

char topic[] = "iot-2/evt/status/fmt/json";
char subTopic[] = "iot-2/cmd/+/fmt/json";

// When adding a device on internetofthings.ibmcloud.com the following
// information will be generated:
// org=abcxyz
// type=LaunchPad
// id=myLaunchPad2
// auth-method=token
// auth-token=ZrBCpuUG912v@aJ*MJ

char organization[] = "b7olvk";
char typeId[] = "LaunchPad";
char deviceId[] = "myLaunchPad";

// Authentication method. Should be use-toke-auth
// When using authenticated mode
char authMethod[] = "use-token-auth";
// The auth-token from the information above
char authToken[] = "eQw5BEyZP6HCW2unZM";
// This string will be created in setup
char clientId[48];
// This string will be created in setup
char registeredUrl[SIZE];

// The function to call when a message arrives
void callback(char* topic, byte* payload, unsigned int length);

EthernetStack ipstack;  
MQTT::Client<EthernetStack, Countdown, MQTT_MAX_PACKET_SIZE> client(ipstack);
void messageArrived(MQTT::MessageData& md);

void setup() {
  Serial.begin(115200);
  
  Serial.println("Starting Ethernet");
  Ethernet.enableLinkLed();
  Ethernet.enableActivityLed();
  Ethernet.begin(0);

  Serial.println("\nIP Address obtained");
  // We are connected and have an IP address.
  Serial.println(Ethernet.localIP());

  // Create the mqtt url and the client id
  sprintf(clientId, "d:%s:%s:%s", organization, typeId, deviceId);
  sprintf(registeredUrl,"%s.messaging.internetofthings.ibmcloud.com",organization);
  delay(1000);
}

void loop() {
  int rc = -1;
  if (!client.isConnected()) {
    Serial.print("Connecting to: ");
    Serial.print(registeredUrl);
    Serial.print(" with client id: ");
    Serial.println(clientId);
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
    
    Serial.print("Subscribing to topic: ");
    Serial.println(subTopic);
    // Unsubscribe the topic, if it had subscribed it before.
    client.unsubscribe(subTopic);
    // Try to subscribe for commands
    if ((rc = client.subscribe(subTopic, MQTT::QOS0, messageArrived)) != 0) {
            Serial.print("Subscribe failed with return code : ");
            Serial.println(rc);
    } else {
          Serial.println("Subscribe success\n");
    }
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
  rc = client.publish(topic, message);
  if (rc != 0) {
    Serial.print("Message publish failed with return code : ");
    Serial.println(rc);
  }
  
  // Wait for one second before publishing again
  // This will also service any incomming messages
  client.yield(5000);
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

double getTemp() {
  return (float)(147.5 - ((75 * 3.3 * (long)analogRead(TEMPSENSOR)) / 4096));
}
