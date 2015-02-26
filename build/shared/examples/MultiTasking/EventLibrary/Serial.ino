
void serialSetup()
{
  Serial.begin(115200);
  delay(500);
}


void serialLoop()
{
  myEvent.waitFor();
  Serial.println("Got an Event from myEvent!");
}

