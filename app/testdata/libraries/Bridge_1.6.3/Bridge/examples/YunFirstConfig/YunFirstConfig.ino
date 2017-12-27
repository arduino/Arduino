
/*
  Arduino Yún First configuration sketch

  Configures the YunShield/Yún WiFi and infos via the Bridge
  Works correctly if Line Ending is set as "NewLine"
  If your board has two USB ports, use the Native one

  The circuit:
   Arduino YunShield
   (or any Yun model with firmware > 1.6.1)

  created March 2016
  by Arduino LLC

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/YunFirstConfig
*/

#include <Process.h>

#define MAX_WIFI_LIST 10

String networks[MAX_WIFI_LIST];
String yunName;
String yunPassword;

void setup() {
  SERIAL_PORT_USBVIRTUAL.begin(9600);  // initialize serial communication
  while (!SERIAL_PORT_USBVIRTUAL);     // do nothing until the serial monitor is opened

  SERIAL_PORT_USBVIRTUAL.println(F("Hi! Nice to see you!"));
  SERIAL_PORT_USBVIRTUAL.println(F("I'm your YunShield assistant sketch"));
  SERIAL_PORT_USBVIRTUAL.println(F("I'll help you configuring your Yun in a matter of minutes"));

  SERIAL_PORT_USBVIRTUAL.println(F("Let's start by communicating with the Linux processor"));
  SERIAL_PORT_USBVIRTUAL.println(F("When LED (L13) will light up we'll be ready to go!"));
  SERIAL_PORT_USBVIRTUAL.println(F("Waiting..."));
  SERIAL_PORT_USBVIRTUAL.println(F("(in the meanwhile, if you are using the IDE's serial monitor, make sure that it's configured to send a \"Newline\")\n"));
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();  // make contact with the linux processor
  digitalWrite(13, HIGH);  // Led on pin 13 turns on when the bridge is ready

  // Recover if the board is in AP mode - unused
  Process wifiList;
  bool master = false;
  wifiList.runShellCommand(F("iwinfo | grep \"Mode: Master\""));
  while (wifiList.available() > 0) {
    wifiList.read();
    master = true;
  }

  // Get the list of reachable networks
  wifiList.runShellCommand(F("iwinfo wlan0 scan | grep ESSID | cut -d\"\\\"\" -f2"));

  uint8_t num_networks = 0;
  uint8_t i = 0;
  char c;
  bool dropNet = false;

  networks[0].reserve(32);

  while (wifiList.available() > 0) {
    c = wifiList.read();
    if (c != '\n') {
      networks[i] += c;
    } else {
      // check if we already found networks[i] and eventually drop it
      for (uint8_t s = 0; s < i; s++) {
        if (networks[i].equals(networks[s])) {
          dropNet = true;
        }
      }
      if (i <= MAX_WIFI_LIST && dropNet == false) {
        networks[i++].reserve(32);
      } else {
        dropNet = false;
        networks[i]="";
      }
    }
  }

  num_networks = i;

  String encryption;
  String password;
  int chose = 0;

  // If networks number is 0, start manual configuration
  if (num_networks == 0) {
    SERIAL_PORT_USBVIRTUAL.println(F("Oops, it seems that you have no WiFi network available"));
    SERIAL_PORT_USBVIRTUAL.println(F("Let's configure it manually"));
    SERIAL_PORT_USBVIRTUAL.println(F("SSID of the network you want to connect to: "));
    networks[0] = getUserInput(networks[0], false);
    SERIAL_PORT_USBVIRTUAL.println(F("Password for the network you want to connect to: "));
    password = getUserInput(password, true);
    SERIAL_PORT_USBVIRTUAL.print(F("Encryption (eg WPA, WPA2, WEP): "));
    encryption = getUserInput(encryption, false);
  } else {
    // else print them prepending a number
    SERIAL_PORT_USBVIRTUAL.print(F("It looks like you have "));
    SERIAL_PORT_USBVIRTUAL.print(num_networks);
    SERIAL_PORT_USBVIRTUAL.println(F(" networks around you "));
    SERIAL_PORT_USBVIRTUAL.println(F("Which one do you want to connect to?\n"));
    for (i = 0; i < num_networks && i < MAX_WIFI_LIST; i++) {
      SERIAL_PORT_USBVIRTUAL.print(i);
      SERIAL_PORT_USBVIRTUAL.println(") " + networks[i]);
    }
    String selection;
    selection = getUserInput(selection, false);
    chose = atoi(selection.c_str());
  }

  // Extract the selected network security
  bool openNet = false;
  wifiList.runShellCommand("iwinfo wlan0 scan | grep \"" + networks[chose] + "\" -A5 | grep Encryption | cut -f2 -d\":\"");
  while (wifiList.available() > 0) {
    c = wifiList.read();
    encryption += c;
  }

  if (encryption.indexOf("none") >= 0) {
    openNet = true;
    encryption = "none";
  }
  if (encryption.indexOf("WPA2") >= 0) {
    encryption = "psk2";
  }
  if (encryption.indexOf("WPA") >= 0) {
    encryption = "psk";
  }
  if (encryption.indexOf("WEP") >= 0) {
    encryption = "wep";
  }

  if (openNet == false && password.length() == 0) {
    SERIAL_PORT_USBVIRTUAL.print(F("It looks like you need a password to connect to "));
    SERIAL_PORT_USBVIRTUAL.println(networks[chose]);
    SERIAL_PORT_USBVIRTUAL.print(F("Write it here: "));
    password = getUserInput(password, true);
  }

  // Change hostname/root password
  SERIAL_PORT_USBVIRTUAL.println(F("We are almost done! Give a name and a password to your Yun"));
  SERIAL_PORT_USBVIRTUAL.print(F("Name: "));
  yunName = getUserInput(yunName, false);
  SERIAL_PORT_USBVIRTUAL.print(F("Password: "));
  yunPassword = getUserInput(yunPassword, true);

  // Select a country code
  String countryCode;
  SERIAL_PORT_USBVIRTUAL.println(F("One last question: where do you live?"));
  SERIAL_PORT_USBVIRTUAL.print(F("Insert a two letters county code (eg IT, US, DE): "));
  countryCode = getUserInput(countryCode, false);

  yunName.trim();
  yunPassword.trim();
  networks[chose].trim();
  password.trim();
  countryCode.trim();

  // Configure the Yun with user provided strings
  wifiConfig(yunName, yunPassword, networks[chose], password, "YUN" + yunName + "AP", countryCode, encryption);

  SERIAL_PORT_USBVIRTUAL.print(F("Waiting for the Yun to connect to the network"));
}

bool Connected = false;
bool serialTerminalMode = false;
int runs = 0;

void loop() {
  if (!serialTerminalMode) {
    String resultStr = "";

    if (!Connected) {
      SERIAL_PORT_USBVIRTUAL.print(".");
      runs++;
    }

    // If it takes more than 20 seconds to connect, stop trying
    if (runs > 20) {
      SERIAL_PORT_USBVIRTUAL.println("");
      SERIAL_PORT_USBVIRTUAL.println(F("We couldn't connect to the network."));
      SERIAL_PORT_USBVIRTUAL.println(F("Restart the board if you want to execute the wizard again"));
      resultStr = getUserInput(resultStr, false);
    }

    // Check if we have an IP address
    Process wifiCheck;
    wifiCheck.runShellCommand(F("/usr/bin/pretty-wifi-info.lua | grep \"IP address\" | cut -f2 -d\":\" | cut -f1 -d\"/\"" ));  // command you want to run
    while (wifiCheck.available() > 0) {
      char c = wifiCheck.read();
      resultStr += c;
    }

    delay(1000);

    if (resultStr != "") {
      // We got an IP, freeze the loop, display the value and "spawn" a serial terminal
      Connected = true;
      resultStr.trim();
      SERIAL_PORT_USBVIRTUAL.println("");
      SERIAL_PORT_USBVIRTUAL.print(F("\nGreat! You can now reach your Yun from a browser typing http://"));
      SERIAL_PORT_USBVIRTUAL.println(resultStr);
      SERIAL_PORT_USBVIRTUAL.print(F("Press 'Enter' key twice to start a serial terminal"));
      resultStr = getUserInput(resultStr, false);
      serialTerminalMode = true;
      //startSerialTerminal();
      SERIAL_PORT_HARDWARE.write((uint8_t *)"\xff\0\0\x05XXXXX\x7f\xf9", 11); // send "bridge shutdown" command
      delay(100);
      SERIAL_PORT_HARDWARE.println("\nreset\n\n");
      SERIAL_PORT_HARDWARE.flush();
      SERIAL_PORT_HARDWARE.println("\nreset\n\n");
      SERIAL_PORT_HARDWARE.write((uint8_t *)"\n", 1);
    }

  } else {
    loopSerialTerminal();
  }
}

String getUserInput(String out, bool obfuscated) {
  /*
    while (SerialUSB.available() <= 0) {}
    while (SerialUSB.available() > 0) {
    char c =  SerialUSB.read();
    out += c;
    }
    return out;
  */
  while (SERIAL_PORT_USBVIRTUAL.available() <= 0) {}
  while (1) {
    char c = SERIAL_PORT_USBVIRTUAL.read();
    if (c == '\n' || c == '\r')
      break;
    else {
      if (c != -1) {
        out += c;
        if (obfuscated)
          SERIAL_PORT_USBVIRTUAL.print("*");
        else
          SERIAL_PORT_USBVIRTUAL.print(c);
      }
    }
  }
  SERIAL_PORT_USBVIRTUAL.println("");
  return out;
}

void wifiConfig(String yunName, String yunPsw, String wifissid, String wifipsw, String wifiAPname, String countryCode, String encryption) {
  Process p;

  p.runShellCommand("blink-start 100"); //start the blue blink

  p.runShellCommand("hostname " + yunName); //change the current hostname
  p.runShellCommand("uci set system.@system[0].hostname='" + yunName + "'"); //change teh hostname in uci

  p.runShellCommand("uci set arduino.@arduino[0].access_point_wifi_name='" + wifiAPname + "'");

  //this block resets the wifi psw
  p.runShellCommand("uci set wireless.@wifi-iface[0].encryption='" + encryption + "'");
  p.runShellCommand("uci set wireless.@wifi-iface[0].mode='sta'\n");
  p.runShellCommand("uci set wireless.@wifi-iface[0].ssid='" + wifissid + "'");
  p.runShellCommand("uci set wireless.@wifi-iface[0].key='" + wifipsw + "'");
  p.runShellCommand("uci set wireless.radio0.channel='auto'");
  p.runShellCommand("uci set wireless.radio0.country='" + countryCode + "'");
  p.runShellCommand("uci delete network.lan.ipaddr");
  p.runShellCommand("uci delete network.lan.netmask");
  p.runShellCommand("uci set network.lan.proto='dhcp'");

  p.runShellCommand("echo -e \"" + yunPsw + "\n" + yunPsw + "\" | passwd root"); //change the passwors
  p.runShellCommand("uci commit"); //save the mods done via UCI
  p.runShellCommand("blink-stop"); //start the blue blink

  p.runShellCommand("wifi ");
}

long linuxBaud = 250000;

void startSerialTerminal() {
  SERIAL_PORT_USBVIRTUAL.begin(115200);  // open serial connection via USB-Serial
  SERIAL_PORT_HARDWARE.begin(linuxBaud); // open serial connection to Linux
}

boolean commandMode = false;
void loopSerialTerminal() {
  // copy from USB-CDC to UART
  int c = SERIAL_PORT_USBVIRTUAL.read();    // read from USB-CDC
  if (c != -1) {                            // got anything?
    if (commandMode == false) {             // if we aren't in command mode...
      if (c == '~') {                       //    Tilde '~' key pressed?
        commandMode = true;                 //       enter in command mode
      } else {
        SERIAL_PORT_HARDWARE.write(c);      //    otherwise write char to UART
      }
    } else {                                // if we are in command mode...
      if (c == '0') {                       //     '0' key pressed?
        SERIAL_PORT_HARDWARE.begin(57600);  //        set speed to 57600
        SERIAL_PORT_USBVIRTUAL.println("Speed set to 57600");
      } else if (c == '1') {                //     '1' key pressed?
        SERIAL_PORT_HARDWARE.begin(115200); //        set speed to 115200
        SERIAL_PORT_USBVIRTUAL.println("Speed set to 115200");
      } else if (c == '2') {                //     '2' key pressed?
        SERIAL_PORT_HARDWARE.begin(250000); //        set speed to 250000
        SERIAL_PORT_USBVIRTUAL.println("Speed set to 250000");
      } else if (c == '3') {                //     '3' key pressed?
        SERIAL_PORT_HARDWARE.begin(500000); //        set speed to 500000
        SERIAL_PORT_USBVIRTUAL.println("Speed set to 500000");
      } else if (c == '~') {                //     '~` key pressed?
        SERIAL_PORT_HARDWARE.write((uint8_t *)"\xff\0\0\x05XXXXX\x7f\xf9", 11); // send "bridge shutdown" command
        SERIAL_PORT_USBVIRTUAL.println("Sending bridge's shutdown command");
      } else {                              //     any other key pressed?
        SERIAL_PORT_HARDWARE.write('~');    //        write '~' to UART
        SERIAL_PORT_HARDWARE.write(c);      //        write char to UART
      }
      commandMode = false;                  //     in all cases exit from command mode
    }
  }

  // copy from UART to USB-CDC
  c = SERIAL_PORT_HARDWARE.read();          // read from UART
  if (c != -1) {                            // got anything?
    SERIAL_PORT_USBVIRTUAL.write(c);        //    write to USB-CDC
  }
}
