/**
 * This code shows how to read the settings from the  
 * DataFlash on a XPlain board.
 * 
 * Created 2010 by Eberhard Fahle <e.fahle@wayoda.org>
 * 
 * THIS CODE IS IN THE PUBLIC DOMAIN
 */

/* The name of the library to include is "xplDataFlash" */
#include "xplDataFlash.h"

/* Creates the variable by which we access the DataFlash */
xplDataFlash df=xplDataFlash();

void setup() {
  Serial.begin(9600);
  Serial.print("pagesize=");
  Serial.print(df.getPageSize());
  Serial.println();
  Serial.print("devId=");
  int deviceId=df.getDeviceId();
  Serial.print(deviceId,HEX);
  Serial.println();
  int vendorId=df.getManufacturerId();
  Serial.print("vendorId=");
  Serial.print(vendorId,HEX);
  Serial.println();
}

void loop () {
}


     
     
