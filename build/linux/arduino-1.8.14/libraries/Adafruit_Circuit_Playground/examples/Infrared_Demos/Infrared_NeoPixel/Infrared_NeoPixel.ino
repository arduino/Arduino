/* Infrared_NeoPixel.ino Example sketch for IRLib2 and Circuit Playground Express
   Illustrates how to change NeoPixel patterns and colors using
   an IR remote. Programmed to use IR codes for Adafruit mini remote
   https://www.adafruit.com/product/389
   Press the following keys on the remote:
    vol-          decrease brightness
    vol+          increase brightness
    right arrow   rotate clockwise   
    left arrow    rotate counterclockwise
    up arrow      rotate faster
    down arrow    rotate slower
    0             rainbow pattern
    1             candy cane pattern
    2             one red pixel
    3             decreased solid colors
    4             increase solid colors
 */
#include <Adafruit_CircuitPlayground.h>
#include "adafruit_mini_codes.h"

#if !defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
  #error "Infrared support is only for the Circuit Playground Express, it doesn't work with the Classic version"
#endif


//Pattern numbers
#define RAINBOW    0
#define CANDY_CANE 1
#define JUST_ONE   2
#define MONOCHROME 3

uint8_t i,j,Phase, Pattern;
int8_t Direction, Mono;
int16_t Bright, Speed;

void Show_Pattern(void) {
  CircuitPlayground.setBrightness(Bright);
  for(i=0;i<11;i++) {
    j= (20+i+Phase*Direction) % 10;
    switch (Pattern) {
      case RAINBOW:
        CircuitPlayground.setPixelColor(j, CircuitPlayground.colorWheel(25*i));  
        break;
      case CANDY_CANE: 
        if((i % 5)<2) {
          CircuitPlayground.setPixelColor(j, 255,0,0);
        } else  {
          CircuitPlayground.setPixelColor(j, 255,255,255);
        }
        break;
      case JUST_ONE:
        if(i<2) {
          CircuitPlayground.setPixelColor(j, 255,0,0);
        } else  {
          CircuitPlayground.setPixelColor(j, 0,0,0);
        }
        break;
      case MONOCHROME:
        CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(25*Mono));  
        break;
    }
  }
}

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.irReceiver.enableIRIn(); // Start the receiver
  Bright=8;  Phase=0;  Pattern=2;  Direction=1;  Speed=300;
  Mono=0;  
}

void loop() {
  // First up, display whatever neopixel patterm we're doing
  Show_Pattern();

  // a small pause
  delay(Speed);

  // go to next phase next time
  Phase++;
  if (Phase >= 10) {
   Phase = 0;
  }

  // Did we get any infrared signals?
  if (! CircuitPlayground.irReceiver.getResults()) {
    return;
  }

  // Did we get any decodable messages?
  if (! CircuitPlayground.irDecoder.decode()) {
    CircuitPlayground.irReceiver.enableIRIn(); // Restart receiver  
    return;
  }

  // We can print out the message if we want...
  CircuitPlayground.irDecoder.dumpResults(false);

  // Did we get any NEC remote messages?
  if (! CircuitPlayground.irDecoder.protocolNum == NEC) {
    CircuitPlayground.irReceiver.enableIRIn(); // Restart receiver  
    return;
  }

  // What message did we get?
  switch(CircuitPlayground.irDecoder.value) {
  case ADAF_MINI_0_10_PLUS: 
    Serial.println("Rainbow mode!");
    Pattern = RAINBOW; 
    break;
  case ADAF_MINI_1: 
    Serial.println("Candy Cane mode!");
    Pattern = CANDY_CANE;  
    break;
  case ADAF_MINI_2: 
    Serial.println("Just One mode!");
    Pattern = JUST_ONE;  
    break;
  case ADAF_MINI_3: 
    Serial.println("Monochrome mode, less");
    Pattern = MONOCHROME; 
    Mono--;
    if (Mono < 0) {
      Mono = 9;
    }
    break;
  case ADAF_MINI_4: 
    Serial.println("Monochrome mode, more");
    Pattern = MONOCHROME;
    Mono++;
    if (Mono > 9) {
      Mono = 0;
    }
    break;
  case ADAF_MINI_LEFT_ARROW: 
    Serial.println("Counter-Clockwise");
    Direction = 1;
    break;
  case ADAF_MINI_RIGHT_ARROW: 
    Serial.println("Clockwise");
    Direction = -1;
    break;
  case ADAF_MINI_VOLUME_UP: 
    Serial.println("Brighter");
    Bright = min(255, Bright+2); 
    break;
  case ADAF_MINI_VOLUME_DOWN: 
    Serial.println("Dimmer");
    Bright = max(0, Bright-2); 
    break;
  case ADAF_MINI_UP_ARROW: 
    Serial.println("Faster");
    Speed = max(50, Speed-50); 
    break;
  case ADAF_MINI_DOWN_ARROW: 
    Serial.println("Slower");
    Speed = min(2000, Speed+50); 
    break;
  }
  //Restart receiver
  CircuitPlayground.irReceiver.enableIRIn();      
}
