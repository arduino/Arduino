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
    A20, // PE_6
    A21, // PE_7
    A22, // PP_7
    A23, // PP_6
};

char channellabels[][5] = {
    "PE_3", // A0
    "PE_2", // A1
    "PE_1", // A2
    "PE_0", // A3
    "PD_7", // A4
    "PD_6", // A5
    "PD_5", // A6
    "PD_4", // A7
    "PE_5", // A8
    "PE_4", // A9
    "PB_4", // A10
    "PB_5", // A11
    "PD_3", // A12
    "PD_2", // A13
    "PD_1", // A14
    "PD_0", // A15
    "PK_0", // A16
    "PK_1", // A17
    "PK_2", // A18
    "PK_3", // A19
    "PE_6", // A20
    "PE_7", // A21
    "PP_7", // A22
    "PP_6", // A23
};


void moveTo(int l,int r) {
    Serial.print("\x1B[");
    Serial.print(l,DEC);
    Serial.print(";");
    Serial.print(r,DEC);
    Serial.print("f\x1B[K");
}

void printLabels() {
    for (int i = 0; i < 24; i++) {
        moveTo(i+3,1);
        sprintf(buf,"A%02d %s",i,channellabels[i]);
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
  
    for (i = 0; i < 24; i++) {
        moveTo(i+3,10);
        adc = analogRead(channels[i]);
        sprintf(buf,"%4d",adc);
        Serial.print(buf);
    }
    delay(500);
}
