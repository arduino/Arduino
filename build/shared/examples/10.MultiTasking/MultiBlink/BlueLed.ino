#undef LED
#define LED BLUE_LED

void setupBlueLed() {                
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever as a task.
void loopBlueLed() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for 100 ms
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(100);               // wait for 100 ms
}
