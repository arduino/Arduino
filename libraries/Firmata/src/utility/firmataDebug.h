#ifndef FIRMATA_DEBUG_H
#define FIRMATA_DEBUG_H

#ifdef SERIAL_DEBUG
  #define DEBUG_BEGIN(baud) Serial.begin(baud); while(!Serial) {;}
  #define DEBUG_PRINTLN(x)  Serial.println (x)
  #define DEBUG_PRINT(x)    Serial.print (x)
#else
  #define DEBUG_BEGIN(baud)
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINT(x)
#endif

#endif /* FIRMATA_DEBUG_H */
