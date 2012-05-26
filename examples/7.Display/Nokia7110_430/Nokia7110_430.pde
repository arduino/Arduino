//
//  Nokia7110_430b.pde
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Nokia7110_430b
//  Created by Rei VILO on 26/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//

//
// See ReadMe.txt for references
//

// Core library
#if defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#else // error
#error Platform not supported
#endif

// Include application, user and local libraries
#include "nokia7110_library.h"

// from AnalogInput_InternalThermometer_430 
#define NUMBER 8 // take number / 2
uint32_t average = 0;
uint32_t values[NUMBER];
uint8_t j = 0;
uint8_t i = 0;
boolean flag = false;

boolean backlight = false;


//    P1.0    Reset
//    P1.3    Temp Sensor (Not used)
//    P2.0    Serial Data
//    P2.1    Backlight
//    P2.2    Chip Select
//    P2.3    Data/Command
//    P2.4    Serial Clock
//    P2.5    Pushbutton

// P1
static const unsigned LCD_RESET = BIT0; 
static const unsigned RXD = BIT2;
static const unsigned SWITCH = BIT3;

// P2
static const unsigned LCD_DATA = BIT0;
static const unsigned LCD_BACKLIGHT = BIT1;
static const unsigned LCD_CE = BIT2;
static const unsigned LCD_DC = BIT3;
static const unsigned LCD_CLK = BIT4;
static const unsigned LCD_BTN = BIT5;

// !!! template or class?
Nokia7110<P2OUT, LCD_CLK, LCD_DATA, P2OUT, LCD_DC, P2OUT, LCD_CE, P1OUT, LCD_RESET, 10000> lcd;

// Print integer from -999 to 9999 using 12 x 16 font
void print_int(int i, const unsigned y) {
    if (i < -999 || i > 9999) return;
    const unsigned neg = i < 0;
    if (neg) i = -i;
    div_t d; 
    d.quot = i;
    unsigned x = 48;
    do {
        d = div(d.quot, 10);
        lcd.pd12(d.rem, x -= 12, y);
    } 
    while (d.quot);
    if (neg) lcd.pd12(14, x -= 12, y);
    while (x) lcd.pd12(10, x -= 12, y);
}


// Print integer from -999 to 9999 using 6 x 8 font
void print_int(int i, unsigned x, const unsigned y) {
    if (i < -999 || i > 9999) return;
    const unsigned e = x;
    x += 24;
    const unsigned neg = i < 0;
    if (neg) i = -i;
    div_t d; 
    d.quot = i;
    do {
        d = div(d.quot, 10);
        lcd.print(x -= 6, y, '0' + d.rem);
    } 
    while (d.quot);
    if (neg) lcd.print(x -= 6, y, '-');
    while (x > e) lcd.print(x -= 6, y, ' ');
}


// Print number with 1 decimal place passed as integer *10
// from -9999=-999.9 to 99999=9999.9 using 12 x 16 font
void print_dec1(int ui, const unsigned y) {
    if (ui < -9999 || ui > 99999) return;
    boolean neg = (ui < 0);
    if (neg) ui = -ui;
    unsigned x = 60;
    
    lcd.pd12(ui%10, x -= 12, y);
    lcd.pd12(12, x -= 12, y); // .
    ui /= 10;
    
    do {
        lcd.pd12(ui%10, x -= 12, y);
        ui /= 10;
    } 
    while (ui>0);
    
    if (neg) lcd.pd12(14, x -= 12, y);
    while (x) lcd.pd12(10, x -= 12, y);
}


void draw_bargraph(int f) {
    int x, y, bg;
    char c;
    unsigned char bgc[9] = { 
        0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0                     };
    char *bgl[8] = { 
        "90", "80", "70", "60", "50", "40", "30", "20"                     };
    
    x = 20;                                         //
    bg = (f - (x - 5)) * 4 / 5;                     //
    for (y = 7; y >= 0; --y) {                       //
        lcd.pos(83, y);                             //
        if (bg < 0) {
            c = bgc[8];
        } 
        else if (bg > 7) {
            c = bgc[7];
        } 
        else {
            c = bgc[bg];
        }
        lcd.write((unsigned char *)&c, 1, lcd_data); 
        lcd.print(bgl[y], c);
        bg -= 8;
    }                                               //
}


int x, y;
char c;


// Add setup code 
void setup() {
    pinMode(P1_0, OUTPUT);     
    pinMode(P1_1, OUTPUT);     
    pinMode(P1_2, OUTPUT);     
    
    pinMode(P2_0, OUTPUT);     
    pinMode(P2_1, OUTPUT);     
    pinMode(P2_2, OUTPUT);     
    pinMode(P2_3, OUTPUT);     
    pinMode(P2_4, OUTPUT);     
    
    pinMode(P2_5, INPUT_PULLUP);  
    
    
    // from AnalogInput_InternalThermometer_430 
    analogReference(INTERNAL1V5);
    analogRead(TEMPSENSOR); // first reading usually wrong
    
    for (j=0; j<NUMBER; j++) values[j]=0;
    average = 0;
    j=0;
    
    lcd.reset();
    lcd.init();
    
    if (false) {
        lcd.clear();        
        lcd.print(30, 6, "MSP430");
        lcd.print(18, 7, "Nokia 7110");
        
        delay(3000);
    }
    
    if (false) {
        lcd.clear();
        lcd.print(9, 7, "Character Set");
        x = 0;
        y = 0;
        lcd.pos(x, y);
        for (c = 32; c < 127; ++c) {
            lcd.print(c);
            if (++x >= 16) x = 0, lcd.pos(x, ++y);
        }
        delay(3000); 
    }
    
    if (false) {
        lcd.clear();    
        lcd.pd12(15, 48, 5); 
        lcd.pd12(16, 59, 5);
        lcd.print(24, 7, "\x7F""C"); 
        lcd.print(66, 7, "\x7F""K");
        print_int(8888, 5); 
        print_int(8888, 0, 7);  
        print_int(8888, 42, 7);
        for(x = 15; x < 96; ++x) {
            draw_bargraph(x);
            __delay_cycles(200000);
        }
        delay(3000); 
    }
    
    if (true) {
        lcd.clear();                                        //
        lcd.print(12, 0, "Nokia7110_430");
        lcd.print(12, 1, "Thermometer");
        lcd.pd12(15, 60, 3);                                // o Degrees
        lcd.pd12(16, 68, 3);                                // C
    }
}           


// Add loop code 
void loop() {       
    
    // from AnalogInput_InternalThermometer_430
    if (i == 10) {
        i = 0;
        average -= values[j];
        values[j] = ((uint32_t)analogRead(TEMPSENSOR)*27069 - 18169625) * 10 >> 16;
        average += values[j];
        j++; 
        if (j==NUMBER) flag=true;
        j %= NUMBER;
        
        if (flag) {
            print_dec1((average/NUMBER), 3);
            lcd.pos(0, 7);
            lcd.print(backlight ? "Light on " : "Light off");
        } else {
            lcd.pos(0, 7);
            lcd.print("Wait ");
            lcd.pos(30, 7);
            lcd.print('0'+NUMBER-j);
        }
    }
    
    if (digitalRead(P2_5)==LOW) {
        while (digitalRead(P2_5)==LOW); // debounce
        backlight = ~backlight;
        lcd.pos(0, 7);
        lcd.print(backlight ? "Light on " : "Light off");
        
        digitalWrite(P2_1, (backlight ? HIGH : LOW));        
    }
	delay(100);
    i++;
}                                                   

