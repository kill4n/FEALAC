void setup()
{
  Serial.begin(9600);

  // Tiempo de espera:
  pinMode(13, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    char d = Serial.read();
    if (d == 5)
      digitalWrite(13, HIGH);
    if (d == 'z')
      digitalWrite(13, LOW);
  }
}
