#include "TestAnalogOut.h"

// used grep CCP.*, pins_energia.h  | awk '{print $5}' | xargs -i grep X11_.[0-9].*{} pins_energia.h  | sort -k 3  | awk '{print "    {\""$3"\",\""$2"\","$3"},"}'

// This scans through the PWM output pins outputing a PWM increasing voltage.
// Pressing USR_SW1 changes to the next pin. The console shows which pin on X11
// is currently being PWM'ed. Connect an LED from GND to X11 pin printed.


#include "wiring_private.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "inc/hw_ints.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/timer.h"

#define LED D1_LED
int pwmvalue;
int pinindex;

#define DEBUG 1

// from Table 13-2. General-Purpose Timers Signals (128TQFP)
analogoutpin_t analogoutpins[] = {
// T0CCP0 
    {"PD_0","X11_50",PD_0}, // no led
    {"PA_0","X11_74",PA_0}, // verified
    {"PL_4","X11_65",PL_4}, // verified, also drives X11_74

// T0CCP1 
    {"PD_1","X11_48",PD_1},  // verified
    // skipping {"PA_1","X11_76",PA_1}, // PA_1 screws up serial port
    {"PL_5","X11_79",PL_5},  // verified, also drives X11_48

// T1CCP0 
    {"PD_2","X11_52",PD_2}, // verified
    {"PA_2","X11_06",PA_2}, // verified, also drives X11_52
    // skipping PL_6, not routed

// T1CCP1
    {"PD_3","X11_46",PD_3}, // verified
    {"PA_3","X11_08",PA_3}, // verified, also drives X11_46
    // skipping PL_7, not routed

// T2CCP0 
    {"PA_4","X11_10",PA_4}, // verified
    {"PM_0","X11_41",PM_0}, // verified, also drives X11_10

// T2CCP1 
    {"PA_5","X11_12",PA_5}, // verified
    {"PM_1","X11_39",PM_1}, // verified, also drives X11_12

// T3CCP0 
    {"PA_6","X11_25",PA_6}, // verified
    {"PM_2","X11_37",PM_2}, // verified, also drives X11_25
    {"PD_4","X11_40",PD_4}, // verified, also drives X11_37

// T3CCP1 
    {"PA_7","X11_27",PA_7}, // verified
    {"PM_3","X11_33",PM_3}, // verified
    {"PD_5","X11_38",PD_5}, // verified, also drives X11_33

// T4CCP0 
    {"PM_4","X11_92",PM_4}, // verified
    {"PB_0","X11_58",PB_0}, // verified
    {"PD_6","X11_44",PD_6}, // verified, also drives X11_58

// T4CCP1 
    {"PM_5","X11_90",PM_5}, // verified
    // skipping PB_1, not routed
    {"PD_7","X11_42",PD_7}, // verified

// T5CCP0 
    {"PM_6","X11_88",PM_6}, // verified
    {"PB_2","X11_67",PB_2}, // verified, also drives X11_88

// T5CCP1 
    {"PM_7","X11_86",PM_7}, // verified
    {"PB_3","X11_69",PB_3}, // verified, also drives X11_86

    {"","",0} // don't change this
};

void pinChange() {
    pinindex++;
    if (analogoutpins[pinindex].portpin == 0) { 
        Serial.println("\n\nstarting over\n\n");
        pinindex = 0;
    }

    Serial.print("  ");
    Serial.print(pinindex);
    Serial.print(" ");
    Serial.print(analogoutpins[pinindex].portLabel);
    Serial.print(" ");
    Serial.println(analogoutpins[pinindex].x11Label);
    pinMode(analogoutpins[pinindex].portpin, OUTPUT);

#ifdef DEBUG
    Serial.print("portlbl   ");
    Serial.println(analogoutpins[pinindex].portLabel);
    uint8_t pin = analogoutpins[pinindex].portpin;
    Serial.print("engpin  D ");
    Serial.println(pin);

    uint8_t bit = digitalPinToBitMask(pin); // get pin bit
    Serial.print("bit     H ");
    Serial.println(bit,HEX);
    uint8_t port = digitalPinToPort(pin);   // get pin port
    Serial.print("port    H ");
    Serial.println(port,HEX);
    uint8_t timer = digitalPinToTimer(pin);
    Serial.print("tmrIx   D ");
    Serial.println(timer);
    uint32_t portBase = (uint32_t) portBASERegister(port);
    Serial.print("portbaseH ");
    Serial.println(portBase,HEX);
    uint32_t offset = timerToOffset(timer);
    Serial.print("offset  H ");
    Serial.println(offset,HEX);
    uint32_t timerBase = getTimerBase123(offset);
    Serial.print("timerbase ");
    Serial.println(timerBase,HEX);
    uint32_t timerAB = TIMER_A << timerToAB(timer);
    Serial.print("timerab H ");
    Serial.println(timerAB,HEX);
    Serial.println("\n");
#endif

}

uint32_t getTimerBase123(uint32_t offset) {
    return (TIMER0_BASE + (offset << 12));
}

void setup() {
    Serial.begin(9600);
    Serial.println("\nTestAnalogOut begin\n");
    pwmvalue = 0;
    pinindex = -1;

    pinMode(LED, OUTPUT);
    pinMode(D2_LED, OUTPUT);
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
