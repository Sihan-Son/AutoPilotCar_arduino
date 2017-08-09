void setup()
{
  pinMode(Led, OUTPUT);
  pinMode(sensorpin, INPUT);
}

void loop()
{
  val = digitalRead(sesorpin);
  if (val == HIGH)
  {
    digitalWrite (Led, Low);
  }
  else
  {
    digitalWrite(Led, HIGH);
  }
}

