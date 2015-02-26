void setup2()
{
  Serial.begin(115200);
}

void loop2()
{
  Serial.print("Task 2 millis: ");
  Serial.println(millis());
  delay(500);
}
