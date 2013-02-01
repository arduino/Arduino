/*---------------TX and RX Buffer ---------------------*/
const String Msg1 = "Hello ceci est {\"OUT\":1,\"STATUS\":1}un message de test";
const String Msg2 = "Hello Corrections, suggestions, and {\"OUT\":1,\"STATUS\":1}new documentation should";
const String Msg3 = "Hello an instance {\"OUT\":1,\"STATUS\":1}of a class that inherits from Stream.";
const String Msg5 = "Hello class main page for more{\"OUT\":1,\"STATUS\":1} information.";
const String Msg6 = "Hello he{\"OUT\":1,\"STATUS\":1} Stream class, and is called by";
const String Msg7 = "Hello and a computer duinoput.rt{\"OUT\":1,\"STATUS\":1} of";

//unsigned char Rx_Buf[30] = {""}; 
String Rx_Buf1;
String Rx_Buf2;
String Rx_Buf3;
String Rx_Buf5;
String Rx_Buf6;
String Rx_Buf7;
char receivedChar1 = NULL;
char receivedChar2 = NULL;
char receivedChar3 = NULL;
char receivedChar5 = NULL;
char receivedChar6 = NULL;
char receivedChar7 = NULL;
 float count =0.0;

void setup() {
pinMode(RED_LED,OUTPUT);

Serial.begin(115200);
Serial1.begin(115200);
Serial2.begin(115200);
Serial3.begin(115200);
Serial5.begin(115200);
Serial6.begin(115200);
Serial7.begin(115200);
}

void loop() {
  char t=0;
    Rx_Buf7="";
    Rx_Buf1="";
    Rx_Buf2="";
    Rx_Buf3="";
    Rx_Buf5="";
    Rx_Buf6="";
 // Warning : Not possible to send data on TX pin if data is not received by RX pin.
 // the controller hang !!!!!!!
 // Serial6 must be disabled if Tuart6() disabled
 // Serial6.flush() do not works
 
    Serial6.end();
    Serial7.print(Msg7);
    Serial7.write(0x0D);
    //delay(4);
    Serial1.print(Msg1);
    Serial1.write(0x0D);
    delay(4);
    Serial2.print(Msg2);
    Serial2.write(0x0D);
    //delay(4);
    Serial3.print(Msg3);
    Serial3.write(0x0D);
    //delay(4);
    Serial5.print(Msg5);
    Serial5.write(0x0D);
    //delay(4);
    Serial6.print(Msg6);
    Serial6.write(0x0D);
    //delay(4);
 

 Tuart7();
 Tuart1();
 //while (Serial6.available()) {Serial6.flush();}
 //Tuart6();
 Tuart3();
 Tuart5();
 Tuart2();  

  if ((count >1000.0) && (count < 1020)){Serial.println(count);} 
  if (count >2000.0 && count < 2020){Serial.println(count);} 
  
delay(5);
digitalWrite(RED_LED,HIGH);
delay(5);
digitalWrite(RED_LED,LOW);
delay(5);
}

void Tuart7 (){
 //   Serial7.print(Msg7);
 //   Serial7.write(0x0D);
 //   delay(4);

    
 //Keep asking for more characters as long as they're available
 while(Serial7.available()) {  
      receivedChar7=Serial7.read();
       if (receivedChar7 != 0x0D){Rx_Buf7= Rx_Buf7+ receivedChar7;}
      // else if (receivedChar7 == 0x0D){Serial.println(Rx_Buf7);}
       }           
    if (Rx_Buf7.equals(Msg7)) {count= count + 1.0 ;}
    else {Serial.println("No transmissions on Uart7 "); Serial.println(count);}
  
}

void Tuart1 (){
   // Serial1.print(Msg1);
   // Serial1.write(0x0D);
   //delay(4);
 //Keep asking for more characters as long as they're available
 while(Serial1.available()) {  
      receivedChar1=Serial1.read();
       if (receivedChar1 != 0x0D){Rx_Buf1= Rx_Buf1+ receivedChar1;}
      // else if (receivedChar1 == 0x0D){Serial.println(Rx_Buf1);}
       }           
    if (Rx_Buf1.equals(Msg1)) {count= count +1.0;}
    else {Serial.println("No transmissions on Uart1 ");Serial.println(count);}
  
}

void Tuart2 (){
   // Serial2.print(Msg2);
    //Serial2.write(0x0D);
   //delay(4);
 //Keep asking for more characters as long as they're available
 while(Serial2.available()) {  
      receivedChar2=Serial2.read();
       if (receivedChar2 != 0x0D){Rx_Buf2= Rx_Buf2+ receivedChar2;}
      // else if (receivedChar2 == 0x0D){Serial.println(Rx_Buf2);}
       }           
    if (Rx_Buf2.equals(Msg2)) {count=count+1.0;}
    else {Serial.println("No transmissions on Uart2 ");Serial.println(count);}
  
}
void Tuart3 (){
   // Serial3.print(Msg3);
   // Serial3.write(0x0D);
    //delay(4);
 //Keep asking for more characters as long as they're available
 while(Serial3.available()) {  
      receivedChar3=Serial3.read();
       if (receivedChar3 != 0x0D){Rx_Buf3= Rx_Buf3+ receivedChar3;}
       //else if (receivedChar3 == 0x0D){Serial.println(Rx_Buf3);}
       }           
    if (Rx_Buf3.equals(Msg3)) {count=count+1.0;}
    else {Serial.println("No transmissions on Uart3 ");Serial.println(count);}
  
}
void Tuart5 (){
    //Serial5.print(Msg5);
    //Serial5.write(0x0D);
    //delay(4);
 //Keep asking for more characters as long as they're available
 while(Serial5.available()) {  
      receivedChar5=Serial5.read();
       if (receivedChar5 != 0x0D){Rx_Buf5= Rx_Buf5+ receivedChar5;}
      // else if (receivedChar5 == 0x0D){Serial.println(Rx_Buf5);}
       }           
    if (Rx_Buf5.equals(Msg5)) {count=count+1.0;}
    else {Serial.println("No transmissions on Uart5 ");Serial.println(count);}
  
}
void Tuart6 (){
   // Serial6.print(Msg6);
   // Serial6.write(0x0D);
    //delay(4);
 //Keep asking for more characters as long as they're available
 while(Serial6.available()) {  
      receivedChar6=Serial6.read();
       if (receivedChar6 != 0x0D){Rx_Buf6= Rx_Buf6+ receivedChar6;}
      //else if (receivedChar6 == 0x0D){Serial.println(Rx_Buf6);}
       }           
    if (Rx_Buf6.equals(Msg6)) {count=count+1.0;}
    else {Serial.println("No transmissions on Uart6 ");Serial.println(count);}
  
}
