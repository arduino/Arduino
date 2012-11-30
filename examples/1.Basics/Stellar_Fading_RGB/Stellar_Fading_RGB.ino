///
/// @mainpage	Stellar_Fading_RGB
/// @details	PWM demonstration with RGB LED
/// @n
/// @warning    RGB LED may be very bright.
/// @n          Protect your eyes!
/// @n
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @date	Nov 26, 2012
/// @version	103
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


///
/// @file	Stellar_Fading_RGB.ino
/// @brief	Main sketch
/// @details	PWM demonstration with RGB LED
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @date	Nov 26, 2012
/// @version	103
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///

// Core library - MCU-based
//#if defined(__LM4F120H5QR__) // StellarPad specific
//#include "Energia.h"
//#else
//#error Platform not supported
//#endif

// Include application, user and local libraries

// Define variables and constants

///
/// @brief	Set the colour
/// @param	red red component
/// @param	green green component
/// @param	blue blue component
///
void set(uint8_t red, uint8_t green, uint8_t blue) {

    analogWrite(RED_LED, red);
    analogWrite(GREEN_LED, green);
    analogWrite(BLUE_LED, blue);
    
    Serial.print(red, DEC);
    Serial.print("\t");
    Serial.print(green, DEC);
    Serial.print("\t");
    Serial.print(blue, DEC);
    Serial.print("\n");
}

///
/// @brief	Fading from one initial colour to another final colour
/// @param	fromRed initial red component
/// @param	fromGreen initial green component
/// @param	fromBlue initial blue component
/// @param	toRed final red component
/// @param	toGreen final green component
/// @param	toBlue final blue component
/// @param	steps number ot steps, default=8
/// @param	ms delay in ms, default=250ms
///
void fade(uint8_t fromRed, uint8_t fromGreen, uint8_t fromBlue,
          uint8_t toRed, uint8_t toGreen, uint8_t toBlue,
          uint8_t steps=8,
          uint16_t ms=250) {

    for (uint16_t i=0x00; i<steps; i++) {
        set(map(i, 0x00, steps-1, fromRed, toRed),
            map(i, 0x00, steps-1, fromGreen, toGreen),
            map(i, 0x00, steps-1, fromBlue, toBlue));
        delay(ms);
    }
}


///
/// @brief	Setup
///
// Add setup code
void setup() {
    
    Serial.begin(9600);
    
    // initialise digital pins as outputs
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    
    
    Serial.println("Showing RED...");
    set(0x7f, 0x00, 0x00);
    delay(1000);
    Serial.println("Showing GREEN...");
    set(0x00, 0x7f, 0x00);
    delay(1000);
    Serial.println("Showing BLUE...");
    set(0x00, 0x00, 0x7f);
    delay(1000);
    Serial.println("Showing WHITE...");
    set(0x7f, 0x7f, 0x7f);
    delay(1000);
    Serial.println("Showing BLACK...");
    set(0x00, 0x00, 0x00);
    delay(1000);
}

///
/// @brief	Loop
///
// Add loop code
void loop() {
    
    Serial.println("Fading from BLACK to RED...");
    fade(0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 32, 50);

    Serial.println("Fading from RED to GREEN...");
    fade(0x7f, 0x00, 0x00, 0x00, 0x7f, 0x00, 32, 50);

    Serial.println("Fading from GREEN to BLACK...");
    fade(0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 32, 50);
    Serial.println("Fading from BLACK to GREEN...");
    fade(0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 32, 50);

    Serial.println("Fading from GREEN to BLUE...");
    fade(0x00, 0x7f, 0x00, 0x00, 0x00, 0x7f, 32, 50);

    Serial.println("Fading from BLUE to BLACK...");
    fade(0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 32, 50);
    Serial.println("Fading from BLACK to BLUE...");
    fade(0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 32, 50);
    
    Serial.println("Fading from BLUE to RED...");
    fade(0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 32, 50);

    Serial.println("Fading from RED to BLACK...");
    fade(0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 32, 50);
    
    Serial.println("Fading from BLACK to WHITE...");
    fade(0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 32, 50);
    Serial.println("Blinking WHITE...");
    set(0x00, 0x00, 0x00);
    delay(500);
    set(0x7f, 0x7f, 0x7f);
    delay(500);
    set(0x00, 0x00, 0x00);
    delay(500);
    set(0x7f, 0x7f, 0x7f);
    delay(500);
    set(0x00, 0x00, 0x00);
    delay(1000);
}



