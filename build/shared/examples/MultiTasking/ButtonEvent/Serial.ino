
void serialSetup()
{
  pinMode(RED_LED, OUTPUT);
  Serial.begin(115200);
  delay(500);
  Serial.println("Press button PUSH1!");
}


void serialLoop()
{
  static uint8_t state = 1;

  button.waitForPress();
  Serial.println("Button was pressed!");

  digitalWrite(RED_LED, state);
  state = !state;
}

