#include "xplDataFlash.h"
#error This will erase all data on the DataFlash! Remove this line to proceed anyway...

xplDataFlash df=xplDataFlash();

void setup() {
  unsigned long startTime=millis();
  unsigned long endTime=0;
  unsigned long duration;
  Serial.begin(9600);
  Serial.print("Will now ERASE DataFlash ...");
  Serial.println(); 
  df.chipErase();
  Serial.print("Took : ");
  duration=endTime-startTime;
  Serial.print((unsigned int)duration,DEC);
  Serial.print("ms");
}
      
void loop () {
}





