/*
 Analog signal chain on Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 The sketch demonstrates a complete analog signal chain getting
 input from the 3-axis accelerometer and using that to mix the color 
 for the RGB LED.
 
 
 Sketch was originally written for Educational BoosterPack and for the 
 "Getting Started with LaunchPad" book. Updated to use 12-bit ADC LaunchPad
 and with new pin-out of the Educational BoosterPack MK II
 
 The circuit utilizes the LEDs on the Educational BoosterPack MK II:
 * RED LED attached from digital pin 39 to ground.
 * GREEN LED attached from digital pin 38 to ground.
 * BLUE LED attached from digital pin 37 to ground.
 Analog accelerometer channels:
 * analog 25: z-axis
 * analog 24: y-axis
 * analog 23: x-axis
 
 
 Absolute rating/conversion can be determined from the ADXL3xx datasheet.
 As a quick reference, for LaunchPads with 12-bit ADC (MSP430F5529, Tiva C, etc.), 
 the entire analog  range is [0,4096]. For simple tilting calculation 
 [-1g,1g] ~ = [mid-800, mid + 800] = [2048-800,2048+800] = [1248,2848]
 
  
Created Dec 2012
Modified Dec 2013
by Dung Dang

*/
const int xpin = 23; // x-axis of the accelerometer
const int ypin = 24; // y-axis
const int zpin = 25; // z-axis (only on 3-axis models)
const int redLED= 39; // assign red LED to Pin #9
const int greenLED= 38;// assign green LED to Pin #10
const int blueLED= 37; // assign blueLED to Pin #12

void setup() { 
    Serial.begin(9600); // initialize for sending diagnostic info to computer
}
void loop() { 
    int analogValue;// CHECK X AXIS (red) 
    analogValue = analogRead(xpin); // read X axis 
    Serial.print("RED (X): ");      // print to serial monitor 
    Serial.print(analogValue); 
    Serial.print("\t"); 
    if(analogValue >2048){ // check if tilting on x axis in positive direction
        analogValue = map(analogValue, 2048, 2850, 0, 150); // map to RGB range 
        analogWrite(redLED, analogValue); // output color 
    } 
    else if(analogValue<2048){ // check if tilting on x axis in negative direction 
        analogValue = map(analogValue, 1250, 2048, 150, 0); // map to RGB range 
        analogWrite(redLED, analogValue);  // output color 
    } 
    else{ 
        analogWrite(redLED, 0); // analogValue is b/w 450 & 490, X axis is ~flat 
    }
    // CHECK Y AXIS (green) 
    analogValue = analogRead(ypin); // read Y axis 
    Serial.print("GREEN (Y): "); // print to serial monitor 
    Serial.print(analogValue); 
    Serial.print("\t"); 
    if(analogValue >2048){ // check if tilting on Y axis in positive direction 
        analogValue = map(analogValue, 2048, 2850, 0, 150); // map to RGB range 
        analogWrite(greenLED, analogValue); // output color 
    } 
    else if(analogValue<2048){ // check if tilting on Y axis in negative direction 
        analogValue = map(analogValue, 1250, 2048, 150, 0); // map to RGB range
        analogWrite(greenLED, analogValue); // output color 
    } 
    else{ 
        analogWrite(greenLED, 0);// analogValue is b/w 450 & 490, Y axis is ~flat 
    }
    // CHECK Z AXIS (blue) 
    analogValue = analogRead(zpin); // read Z axis 
    Serial.print("BLUE (Z): "); // print to serial monitor 
    Serial.print(analogValue); 
    Serial.print("\t"); 
    if(analogValue >2048){ // check if tilting on Z axis in positive direction 
        analogValue = map(analogValue, 2048, 2850, 0, 150); // map to RGB range 
        analogWrite(blueLED, analogValue); // output color 
    }
    else if(analogValue<2048){ // check if tilting on Z axis in negative direction 
        analogValue = map(analogValue, 1250, 2048, 150, 0); // map to RGB range 
        analogWrite(blueLED, analogValue); // output color 
    } 
    else{ 
        analogWrite(blueLED, 0); // analogValue is b/w 450 & 490, Z axis is ~flat 
    }
}
