void setup()
{
  int pins[] = {9, 8, 7, 3, 4, 5, 10, 11, 12};
  for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop()
{
  int Y = analogRead(A0);
  int X = analogRead(A1);

  float MD = 0.5 * (Y - 512) + 0.5 * (X - 512);
  float ME = 0.5 * (Y - 512) - 0.5 * (X - 512);
  float MC = X - 512;

  MD = constrain(MD, -255, 255);
  ME = constrain(ME, -255, 255);
  MC = constrain(MC, -255, 255);

  digitalWrite(8, MD > 0);
  digitalWrite(7, MD <= 0);
  digitalWrite(4, ME > 0);
  digitalWrite(5, ME <= 0);
  digitalWrite(11, MC > 0);
  digitalWrite(12, MC <= 0);

  analogWrite(9, abs(MD));
  analogWrite(3, abs(ME));
  analogWrite(10, abs(MC));
}
