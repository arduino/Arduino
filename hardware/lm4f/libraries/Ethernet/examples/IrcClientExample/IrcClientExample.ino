/* IRC Example
 * Simple IRC client which connects gracefully, joins #energia and says a simple Hello
 * before quitting and indefinitely sleeping.
 *
 * Written in March 2014 by Eric Brundick for the Energia project.
 *
 * Requires the Ethernet library, tested with TI Tiva Connected LaunchPad
 *   based on the TM4C1294NCPDT microcontroller.
 *
 * Released as Public Domain.  Do with it as you wish.
 */

#include <Ethernet.h>
#include <IPAddress.h>
#include <string.h>

byte ourMac[] = { 0x52, 0x54, 0xFF, 0xFF, 0xFF, 0x01 };
EthernetClient client;

const char *ircserver_name = "chat.freenode.net";

//#define IRC_USE_IP_NOT_DNS
//IPAddress ircserver(62,231,75,133);
// ^ Required for connecting through an SSH tunnel for getting around a firewall
// Comment out #define IRC_USE_IP_NOT_DNS to use the ircserver_name DNS to connect.

#define IRCSERVER_PORT 6667

const char *irc_nick = "MyTivaLP";
const char *irc_user = "tm4c129";
const char *irc_user_description = "Energia Warrior";
const char *irc_channel = "#energia";

void dispatch_composite_message(uint8_t, int);
void process_inbound_message(uint8_t, int);

void setup()
{
  IPAddress ip;
  
  Serial.setBufferSize(2048, 64);  /* New Energia 12 feature; specifying large TX buffer to avoid locking
                                    * up the sketch for any reason when spitting debugging messages
                                    * over the ICDI backchannel UART.
                                    */
  Serial.begin(115200);
  
  // Wait for USR_SW1 to be pressed before continuing (10ms resolution polling the button)...
  pinMode(USR_SW1, INPUT_PULLUP);
  uint32_t lastmillis = millis();
  while (digitalRead(USR_SW1)) {
    if ( (millis() - lastmillis) > 1000 ) {
      Serial.println("Waiting for USR_SW1 press to begin...");
      lastmillis = millis();
    }
    delay(10);
  }
  
  // Initialize network.
  Serial.println("\n\nDHCP IRC Client Example");  
  Serial.print("DHCP init: ");
  if (!Ethernet.begin(ourMac)) {
    Serial.println("Failed to configure Ethernet using DHCP.  Halting.");
    while(1)
      delay(1000);
  }
  Serial.print("done; IP=");
  ip = Ethernet.localIP();
  ip.printTo(Serial);
  Serial.println("\n");
}

volatile boolean is_connected = false;
volatile int prot_stage = 0;  // State machine status.
volatile boolean prot_stage_latched = false;
/* ^ Determines if the current event stage has been carried out, in which
 * case we're waiting for some reply or some other event to proceed to
 * the next event stage.
 */

// IRC protocol event stages
#define PROT_STAGE_WAITINIT 0
#define PROT_STAGE_NICK 1
#define PROT_STAGE_USER 2
#define PROT_STAGE_JOIN 3
#define PROT_STAGE_SAYHELLO 4
#define PROT_STAGE_QUIT 5
#define PROT_STAGE_DONE 6

void loop()
{
  uint8_t buf[2049];
  int len;
  
  // Main loop
  if (!is_connected || !client.connected()) {
    Serial.print("Connecting to: ");
    Serial.println(ircserver_name);
#ifdef IRC_USE_IP_NOT_DNS
    if (client.connect(ircserver, IRCSERVER_PORT)) {
#else
    if (client.connect(ircserver_name, IRCSERVER_PORT)) {
#endif
      Serial.println("connected\n");
      is_connected = true;
      prot_stage = PROT_STAGE_WAITINIT;  /* Connected; wait for server to send some welcome data
                                          * before logging in & registering nickname, etc.
                                          */
    } else {
      is_connected = false;
      Serial.println("Failed; pausing 5 seconds before retrying");
      delay(5000);
    }
  } else {
    // Process incoming data first
    if (client.available()) {
      if ((len = client.read(buf, 2048)) > 0) {
        buf[len] = '\0';
        Serial.print("Inbound msg: ");
        Serial.write(buf, len);
        Serial.println();
        dispatch_composite_message(buf, len);
        // TODO: Use a ring-buffer with this code as the producer and
        //   dispatch_composite_message as the consumer.
      }
    }
    
    // Check protocol event stage and perform outbound messages
    switch (prot_stage) {
      case PROT_STAGE_NICK:
        if (!prot_stage_latched) {
          Serial.println("Registering NICK-\n");
          // Compose NICK command
          client.print("NICK ");
          client.print(irc_nick);
          client.print("\r\n");
          prot_stage++;  // No reply needed to advance to next step
        }
        break;
  
      case PROT_STAGE_USER:
        if (!prot_stage_latched) {
          Serial.println("Registering USER-\n");
          client.print("USER ");
          client.print(irc_nick);
          client.print(" ");
          client.print(irc_user);
          client.print(" ");
          client.print(ircserver_name);
          client.print(" :");
          client.print(irc_user_description);
          client.print("\r\n");
          prot_stage_latched = true;
          // Must wait for RPY_ENDOFMOTD before proceeding.
          // This is found & processed in process_inbound_message() below.
        }
        break;
  
      case PROT_STAGE_JOIN:
        if (!prot_stage_latched) {
          Serial.print("Joining "); Serial.print(irc_channel); Serial.println("-");
          client.print("JOIN ");
          client.print(irc_channel);
          client.print("\r\n");
          prot_stage_latched = true;
          // Must wait for RPY_TOPIC before proceeding.
          // This is found & processed in process_inbound_message() below.
        }
        break;
  
      case PROT_STAGE_SAYHELLO:
        if (!prot_stage_latched) {
          Serial.print("Writing to "); Serial.print(irc_channel); Serial.println("-");
          client.print("PRIVMSG ");
          client.print(irc_channel);
          client.print(" :");
          client.println("Hi everyone!  I am a TI TM4C129 LaunchPad connecting to IRC and sending you a brief message.");
          prot_stage++;  // No reply needed to proceed with the next step
        }
        break;

      case PROT_STAGE_QUIT:
        if (!prot_stage_latched) {
          Serial.println("Issuing QUIT-\n");
          client.print("QUIT :Bye for now!\r\n");
          prot_stage++;
        }
        break;
  
      case PROT_STAGE_DONE:
        Serial.println("Done.");
        // IRC server should close connection; we don't bother doing it ourselves here.
        while (1)
          delay(1000);
        break;
    }  /* switch(prot_stage) */
  }  /* if (is_connected) */
} /* loop() */

/* Process a packet into a sequence of \r\n-terminated lines; Note this should be replaced
 * with a ring-buffer design, as data which flows across multiple packets will not be
 * processed correctly; the last request will be truncated and the beginning of the next
 * request will be handled improperly.
 */
void dispatch_composite_message(uint8_t *buf, int len)
{
  uint8_t *bufptr = buf;
  uint8_t *nl = (uint8_t *)strstr((char *)bufptr, "\r\n");
  int sublen = 0;
  
  while (nl != NULL) {
    sublen = (int) (nl - bufptr);
    process_inbound_message(bufptr, sublen);
    bufptr += sublen + 2;
    if ( (bufptr - buf) >= len )
      return;
    
    nl = (uint8_t *)strstr((char *)bufptr, "\r\n");
  }
}

/* Process individual line. */
void process_inbound_message(uint8_t *buf, int sublen)
{
  uint8_t *arg1, *arg2;
  int len;
  
  // Process inbound message
  buf[sublen] = '\0';
  
  arg1 = (uint8_t *)strstr((char *)buf, " ");
  if (arg1 == NULL)
    return;
  *arg1 = '\0';
  arg1++;
  int i=0;
  while (arg1[i] != ' ' && arg1[i] != '\0')
    i++;
  arg1[i] = '\0';
  if ( (arg1 + i - buf) >= sublen )
    arg2 = NULL;
  else
    arg2 = arg1 + i + 1;

  Serial.print("Reply ARG: "); Serial.println((char *)arg1);
  
  // WAITINIT waits for any sort of reply from the IRC server indicating it has connected
  if (prot_stage == PROT_STAGE_WAITINIT) {
    prot_stage++;
    prot_stage_latched = false;
    return;
  }
  
  // Perform PING reply
  if (!strcmp((char *)buf, "PING")) {
    Serial.print("Received PING "); Serial.print((char *)arg1); Serial.println("; sending PONG");
    client.print("PONG ");
    if (arg1[0] == ':')
      client.print((char *)(arg1+1));
    else
      client.print((char *)arg1);    
    client.print("\r\n");
  }
  
  // RPY_ENDOFMOTD to advance past USER
  if (prot_stage == PROT_STAGE_USER && !strcmp((char *)arg1, "376")) {
    prot_stage++;
    prot_stage_latched = false;
  }
  
  // RPY_TOPIC to advance past JOIN
  if (prot_stage == PROT_STAGE_JOIN && !strcmp((char *)arg1, "332")) {
    prot_stage++;
    prot_stage_latched = false;
  }

  // TODO: Add more stuff!  Process more replies.
}
