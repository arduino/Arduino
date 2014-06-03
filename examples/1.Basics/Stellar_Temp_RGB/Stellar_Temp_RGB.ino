/*
  Stellaris Demo
Similar to the one originally flashed on TI's Stellaris.
This sketch use internal temperature sensor to command the RGB led.
PushButton 1 is used to save the temperature.

No Hardware Required.

Created 2014-04-03
by Alessio Graziano */

#define HALFRANGE 5.0f //Maximum difference between saved and present temperature

float temp0=304; //Initial Zero temperature

void setup()
{
  //Set all leds as output
  pinMode( RED_LED, OUTPUT );
  pinMode( BLUE_LED, OUTPUT );
  pinMode( GREEN_LED, OUTPUT );

  //Set PUSBUTTON1 as input and attach interrupt
  pinMode(PUSH1,INPUT_PULLUP);
  attachInterrupt(PUSH1,resetTemp0,FALLING);

  //Init serial
  Serial.begin(9600);

}

float temperature,dt;

void loop()
{
  //Evaluates temperature in K (The International System of Units rocks!)
  temperature=(float) ( 4206.5 - 2475*analogRead(TEMPSENSOR)/4096 ) /10; //Convert as shown in the Stellaris Workshop Book

  //Evaluate difference between present and saved temp
  dt=temperature-temp0;

  if(fabs(dt)<0.5) //If temperature near saved one
    digitalWrite(GREEN_LED,HIGH); //Turn Green Led On
  else
    digitalWrite(GREEN_LED,LOW);

  if(dt>0) //If temperature above saved
  {
    analogWrite(BLUE_LED,0);
    analogWrite(RED_LED,dt*255/HALFRANGE); //Signal with red led
  }
  else
  {
    analogWrite(RED_LED,0);
    analogWrite(BLUE_LED,-dt*255/HALFRANGE); //Signal with blue led
  }

//Write temperature on serial
  Serial.print(temperature);
  Serial.println(" K");

//Wait 300ms
  delay(300);
}

//This function is called when the pushbutton1 is pressed
void resetTemp0()
{
  //Save Last read as Zero Temperature 
  temp0=temperature;
}

