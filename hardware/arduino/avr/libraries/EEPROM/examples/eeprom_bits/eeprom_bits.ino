/***
    eeprom_bits example.
    
	This example sketch is highlighting the usage 
	of EEPROM.readBit() and EEPROM.writeBit().
    
	
	
    Written by Christopher Andrews 2015
    Released under MIT licence.
***/

#include <EEPROM.h>

void setup() {
  
  int address = 0; //Address to first EEPROM cell.
  
  delay( 2000 );  //Prevent touching the EEPROM through resets and uploading of sketch.
  Serial.begin( 9600 );
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo boards only.
  }
  
  //Clear first cell so we can see the changes.
  EEPROM.update( address, 0 );
  
  Serial.print( "Contents of cell 0: " );
  Serial.println( EEPROM.read( address ), HEX );
  delay( 500 );
  
  //Set the fourth bit HIGH, or true
  EEPROM.writeBit( address, 3, true ); //Parameters: cell index, bit index, value
  
  Serial.print( "Contents of cell 0 after setting bit: " );
  Serial.println( EEPROM.read( address ), HEX );
  delay( 500 );
  
  Serial.print( "Value of fourth bit: " );
  
  bool value = EEPROM.readBit( address, 3 );
  
  if( value ){
    Serial.println( "true" );
  }else{
    Serial.println( "false" );
  }
}

void loop(){

}