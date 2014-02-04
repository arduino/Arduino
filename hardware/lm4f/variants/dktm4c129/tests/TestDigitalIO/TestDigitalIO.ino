#include "TestDigitalIO.h"
#include "patches_dktm4c129.h"

void errorPrint(int error) {
  if (error) {
    Serial.print("failed");
  } 
  else {
    Serial.print("passed");
  }
  Serial.println();
}

int testOutput(int pin, char *label) {
  int error = 0;
  
  char buf[50];
  sprintf(buf,"%2d:%-4s >         ",pin,label);
  Serial.print(buf);

  pinMode(pin,OUTPUT);
  digitalWrite(pin,0);
  if (digitalRead(pin) != 0) {
    error++;
  }
  digitalWrite(pin,1);
  if (digitalRead(pin) != 1) {
    error++;
  }
  digitalWrite(pin,0);
  if (digitalRead(pin) != 0) {
    error++;
  }
  errorPrint(error);
  pinMode(pin,INPUT_PULLUP);
  return (error > 0);
}

int test(patch_t patch) {
  int error = 0;
  char buf[50];

  testOutput(patch.aPin,patch.aLabel);
  testOutput(patch.bPin,patch.bLabel);

  // a > b

  sprintf(buf,"%2d:%-4s > %2d:%-4s ",patch.aPin,patch.aLabel,patch.bPin,patch.bLabel);
  Serial.print(buf);

  pinMode(patch.aPin,OUTPUT);
  pinMode(patch.bPin,INPUT_PULLUP);
  digitalWrite(patch.aPin,0);
  if (digitalRead(patch.bPin) != 0) {
    error++;
  }
  digitalWrite(patch.aPin,1);
  if (digitalRead(patch.bPin) != 1) {
    error++;
  }
  digitalWrite(patch.aPin,0);
  if (digitalRead(patch.bPin) != 0) {
    error++;
  }
  errorPrint(error);

  error = 0;
  // a < b
  sprintf(buf,"%2d:%-4s > %2d:%-4s ",patch.bPin,patch.bLabel,patch.aPin,patch.aLabel);
  Serial.print(buf);

  pinMode(patch.aPin,INPUT_PULLUP);
  pinMode(patch.bPin,OUTPUT);
  digitalWrite(patch.bPin,0);
  if (digitalRead(patch.aPin) != 0) {
    error++;
  }
  digitalWrite(patch.bPin,1);
  if (digitalRead(patch.aPin) != 1) {
    error++;
  }
  digitalWrite(patch.bPin,0);
  if (digitalRead(patch.aPin) != 0) {
    error++;
  }
  errorPrint(error);

  pinMode(patch.aPin,INPUT_PULLUP);
  pinMode(patch.aPin,INPUT_PULLUP);

  Serial.println();
  return (error > 0);
}  


void setup() {
  int i = 0;
  int fail = 0;
  int pass = 0;

  Serial.begin(9600);
  delay(1000);
  Serial.println("TestDigitalIO dktm4c129 setup\n");
  Serial.println("test begin");
  do {
    if(test(patches[i])) {
        fail++;
    } else {
        pass++;
    }
  } 
  while (patches[++i].aPin);
  Serial.println("test   end");
  Serial.print("passed ");
  Serial.println(pass);
  Serial.print("failed ");
  Serial.println(fail);

}

void loop() {
}


