/* 
    TestAnalogIn reads and prints all 24 analogIn readings. The 
    dktm4c129 exposes all the pins. Tested by shorting each pin
    to ground. 

    This sketch uses ANSI term escape codes to create a tabbed
    display. Use a VT100/ANSI serial terminal emulator to view.
    see http://en.wikipedia.org/wiki/ANSI_escape_code for more info.
*/

char buf[50];

uint8_t channels[] = {
    A0,  // PE_3
    A1,  // PE_2
    A2,  // PE_1
    A3,  // PE_0
    A4,  // PD_7
    A5,  // PD_6
    A6,  // PD_5
    A7,  // PD_4
    A8,  // PE_5
    A9,  // PE_4
    A10, // PB_4
    A11, // PB_5
    A12, // PD_3
    A13, // PD_2
    A14, // PD_1
    A15, // PD_0
    A16, // PK_0
    A17, // PK_1
    A18, // PK_2
    A19, // PK_3
};

char channellabels[][5][10] = {
    {"PE_3","X11_20"}, // A0
    {"PE_2","X11_18"}, // A1
    {"PE_1","X11_16"}, // A2
    {"PE_0","X11_14"}, // A3
    {"PD_7","X11_42"}, // A4
    {"PD_6","X11_44"}, // A5
    {"PD_5","X11_38"}, // A6
    {"PD_4","X11_40"}, // A7
    {"PE_5","X11_24"}, // A8
    {"PE_4","X11_22"}, // A9
    {"PB_4","X11_05"}, // A10
    {"PB_5","X11_07"}, // A11
    {"PD_3","X11_46"}, // A12
    {"PD_2","X11_52"}, // A13
    {"PD_1","X11_48"}, // A14
    {"PD_0","X11_50"}, // A15
    {"PK_0","X11_26"}, // A16
    {"PK_1","X11_28"}, // A17
    {"PK_2","X11_30"}, // A18
    {"PK_3","X11_32"}, // A19
};


void moveTo(int l,int r) {
    Serial.print("\x1B[");
    Serial.print(l,DEC);
    Serial.print(";");
    Serial.print(r,DEC);
    Serial.print("f\x1B[K");
}

void printLabels() {
    for (int i = 0; i < sizeof(channels); i++) {
        moveTo(i+3,1);
        sprintf(buf,"A%02d %s %s ",i,channellabels[i][0],channellabels[i][1]);
        Serial.print(buf);
    }
}

void setup() {
    Serial.begin(9600);
    delay(100);
    Serial.print("\x1B[1;1f"); // go home
    Serial.print("\x1B[2J");   // clear
    Serial.print("\x1B[?25l"); // hide cursor
    Serial.print("TestAnalogIn");
    printLabels();
}

void loop() {
  int i, adc;
  
    for (i = 0; i < sizeof(channels); i++) {
        moveTo(i+3,17);
        adc = analogRead(channels[i]);
        sprintf(buf,"%4d",adc);
        Serial.print(buf);
    }
    delay(500);
}
