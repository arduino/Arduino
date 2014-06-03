#define OUT D1_LED
#define CLK D2_LED

void setup() {                
  Serial.begin(9600);
  Serial.println("\nTestShiftOut setup");
  pinMode(OUT, OUTPUT);     
  pinMode(CLK, OUTPUT);     

  shiftOut(OUT,CLK,MSBFIRST,0xF0);
}

void loop() {
}
