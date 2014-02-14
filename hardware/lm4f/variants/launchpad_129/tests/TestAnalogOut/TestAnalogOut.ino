#include "TestAnalogOut.h"

// used grep CCP.*, pins_energia.h  | awk '{print $5}' | xargs -i grep X11_.[0-9].*{} pins_energia.h  | sort -k 3  | awk '{print "    {\""$3"\",\""$2"\","$3"},"}'

// This scans through the PWM output pins outputing a PWM increasing voltage.
// Pressing USR_SW1 changes to the next pin. The console shows which pin on X11
// is currently being PWM'ed. Connect an LED from GND to X11 pin printed.

#define LED D1_LED
int pwmvalue;
int pinindex;

analogoutpin_t analogoutpins[] = {
    {"PD_1","X11_48",PD_1}, 
    {"PD_3","X11_46",PD_3}, 
    {"PL_4","X11_65",PL_4},
    {"PL_5","X11_79",PL_5},
    {"PM_6","X11_88",PM_6},
    {"PM_7","X11_86",PM_7},
    {"PB_2","X11_67",PB_2},
    {"PB_3","X11_69",PB_3},
    {"PA_0","X11_74",PA_0},
    {"PA_2","X11_06",PA_2},
    {"PA_3","X11_08",PA_3},

//  trouble makers - hangs
    {"PD_4","X11_40",PD_4},
    {"PA_7","X11_27",PA_7},
    {"PA_6","X11_25",PA_6},
    {"PA_5","X11_12",PA_5},
    {"PA_4","X11_10",PA_4},
    {"PD_7","X11_42",PD_7},
    {"PD_6","X11_44",PD_6},
    {"PD_5","X11_38",PD_5},
    {"PB_0","X11_58",PB_0},
    {"PM_5","X11_90",PM_5},
    {"PM_4","X11_92",PM_4},
    {"PM_3","X11_33",PM_3},
    {"PM_2","X11_37",PM_2},
    {"PM_1","X11_39",PM_1},
    {"PM_0","X11_41",PM_0},

//  trouble makers - don't work
    {"PD_0","X11_50",PD_0},
    {"PD_2","X11_52",PD_2}, 


//  {"PA_1","X11_76",PA_1}, // PA_1 screws up serial port
};

void pinChange() {
    pinindex++;
    Serial.print("    ");
    Serial.print(pinindex);
//    Serial.print(" ");
//    Serial.print(analogoutpins[pinindex].portpin);
    Serial.print(" ");
    Serial.print(analogoutpins[pinindex].portLabel);
    Serial.print(" ");
    Serial.println(analogoutpins[pinindex].x11Label);
    pinMode(analogoutpins[pinindex].portpin, OUTPUT);
    if (pinindex > 27) { // sizeof(analogoutpins) didn't seem to work here
        pinindex = 0;
    }
}

void setup() {
    Serial.begin(9600);
    Serial.println("\nTestAnalogOut begin");
    pwmvalue = 0;
    pinindex = -1;

    pinMode(LED, OUTPUT);
    pinMode(USR_SW1, INPUT_PULLUP);
    pinChange();
}

void loop() {
    //Serial.println(pwmvalue);
    analogWrite(analogoutpins[pinindex].portpin,pwmvalue);
    pwmvalue += 25;
    if (pwmvalue > 100) { // can't see changes in values > 100 
        pwmvalue = 0;
    }
    delay(100); 
    digitalWrite(LED,LOW);
    delay(100);
    digitalWrite(LED,HIGH);

    // Serial.println(millis());
    // Serial.println(digitalRead(USR_SW1));

    if (digitalRead(USR_SW1) == false) {
        while(!digitalRead(USR_SW1)) {} // wait for button release
        pinChange();
    }
}
