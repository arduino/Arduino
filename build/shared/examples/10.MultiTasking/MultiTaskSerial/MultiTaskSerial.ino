void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.print("Task 1 millis: ");
  Serial.println(millis());
  delay(1000);
}
