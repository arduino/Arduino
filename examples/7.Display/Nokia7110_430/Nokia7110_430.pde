//
//  Nokia7110_430.pde
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Nokia7110_430
//  Created by Rei VILO on 25/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//

// Core library
#if defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#else // error
#error Platform not supported
#endif

// Include application, user and local libraries
#include "nokia7110_library.h"

//
// Nokia7110_430
//
// Based on 
// . LCD BoosterPack by SugarAddict » Mon Jan 02, 2012 6:01 am
//   http://www.43oh.com/forum/viewtopic.php?p=15140#p15140
//
// . code by oPossum » Sat Mar 31, 2012 10:29 pm
//   http://www.43oh.com/forum/viewtopic.php?p=18568#p18568
//
// . AnalogInput_InternalThermometer_430
//   Robert Wessels and Rei Vilo
//
// !!! To do: 
// . use Energia pin names
// . use C++ instead of C
// . simplify <template>
//

// from AnalogInput_InternalThermometer_430 
#define NUMBER 4 // take number / 2
uint32_t average = 0;
uint32_t values[NUMBER];
uint8_t j = 0;
uint8_t i = 0;
boolean flag = false;


// !!! utility?
using namespace nokia7110;

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

unsigned adc;                                           // ADC value

// !!! what the use for that?
//#pragma vector = WDT_VECTOR                             // - Watchdog timer interrupt vector 
//__interrupt void wdt_isr(void)                          // This interrupt will occur once per second
//{                                                       //
//    ++tt;                                               // Increment time_t
//    __bic_SR_register_on_exit(LPM0_bits);               // Wakeup main code
//}                                                       //
//                                                        //
//#pragma vector = ADC10_VECTOR                           // ADC conversion complete interrupt
//__interrupt void ADC10_ISR(void)                        //
//{                                                       //
//    adc = ADC10MEM;                                     // Read ADC
//    __bic_SR_register_on_exit(LPM0_bits);               // Wakeup main code
//}                                                       //

int x, y;
char c;
int dc, dk, df;                                     // Temperature in degrees C, K, and F


// Add setup code 
void setup() {
    
    // !!! this section is horrendous
    WDTCTL = WDTPW | WDTHOLD;
    
    P1REN = RXD | SWITCH;
    P1DIR = LCD_RESET; 
    P1OUT = RXD | SWITCH | LCD_RESET;
    
    P2DIR = LCD_DC | LCD_CE | LCD_CLK | LCD_DATA;
    P2REN = LCD_BTN;
    P2OUT = LCD_DC | LCD_CE | LCD_CLK | LCD_BTN;

    //    P2DIR = LCD_DC | LCD_CE | LCD_CLK | LCD_BACKLIGHT | LCD_DATA;
    //    P2REN = LCD_BTN;
    //    P2OUT = LCD_DC | LCD_CE | LCD_CLK | LCD_BACKLIGHT | LCD_BTN;

    //    ADC10CTL0 = 0;                                      // Configure ADC
    //    ADC10CTL1 = INCH_10 | ADC10DIV_3;                   //
    //    ADC10CTL0 = SREF_1 | ADC10SHT_3 | REFON | ADC10ON | ADC10IE;
    //    ADC10CTL0 |= ADC10IE;                               // Enable ADC conversion complete interrupt
    //
    // 32 kHz xtal loading
    //BCSCTL3 = XCAP_1;                                 // 6 pF (default)
    //    BCSCTL3 = XCAP_2;                                   // 10 pF
    //BCSCTL3 = XCAP_3;                                 // 12.5 pF
    //
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDTSSEL;     // Use WDT as interval timer
    IE1 |= WDTIE;                                       // Enable WDT interrupt
    _EINT();                                            // Enable interrupts
    // !!! end of the horrendous section
    
    // from AnalogInput_InternalThermometer_430 
    analogReference(INTERNAL1V5);
    for (j=0; j<NUMBER; j++) values[j]=0;
    average = 0;
    j=0;
    
    if (true) {
        lcd.reset();
        lcd.init();
        lcd.clear();
        
        lcd.print(30, 6, "MSP430");
        lcd.print(18, 7, "Nokia 7110");
        
        // !!! isn't delay available?
        __delay_cycles((uint64_t)30000000);
    }
    
    if (true) {
        lcd.clear();
        lcd.print(9, 7, "Character Set");
        x = 0;
        y = 0;
        lcd.pos(x, y);
        for (c = 32; c < 127; ++c) {
            lcd.print(c);
            if (++x >= 16) x = 0, lcd.pos(x, ++y);
        }
        __delay_cycles((uint64_t)30000000);
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
        //    for(x = 15; x < 96; ++x) {
        //      draw_bargraph(x);
        //      __delay_cycles(200000);
        //    }
        __delay_cycles((uint64_t)30000000);
    }
    
    if (true) {
        lcd.clear();                                        //
        lcd.pd12(15, 48, 3);                                // Degrees
        lcd.pd12(16, 59, 3);                                // F
        //    lcd.print(24, 7, "\x7F""C");                        // C
        //    lcd.print(66, 7, "\x7F""K");                        // K
    }
    
}           


// Add loop code 
void loop() {                                           // for-ever
    //        show_time(localtime(&tt));                      // Convert time_t to tm struct and show on LCD
    //  __bis_SR_register(LPM0_bits + GIE);             // Sleep until WDT interrupt
    //
    //  ADC10CTL0 |= (ENC | ADC10SC);                   // Begin ADC conversion
    //  __bis_SR_register(LPM0_bits + GIE);             // Sleep until conversion complete
    //  //
    //  // Convert to temperature
    //  dc = ((27069L * adc) - 18169625L) >> 16;        // Vref = 1.5V
    //  dk = ((27069L * adc) - 268467L) >> 16;          // Vref = 1.5V
    //  df = ((48724L * adc) - 30634388L) >> 16;        // Vref = 1.5V
    //  //
    //  // Display on LCD
    //  print_int(df, 5);                               // Degrees F
    //  print_int(dc, 0, 7);                            // Degrees C
    //  print_int(dk, 42, 7);                           // Degrees K
    //  draw_bargraph(df);                              // Deg F Bargraph
    
    
    // from AnalogInput_InternalThermometer_430
    if (i == 10) {
        i = 0;
        average -= values[j];
        values[j] = ((uint32_t)analogRead(TEMPSENSOR)*27069 - 18169625) >> 16;
        average += values[j];
        j++; 
        if (j==NUMBER) flag=true;
        j %= NUMBER;
        
        if (flag) print_int(average/NUMBER, 3);
    }
    
    __delay_cycles((uint64_t)10000000);
    i++;
}                                                   

