#include <Servo.h>
Servo servomotor;
int angle = 0;

void setup()
{
  servomor.attach(8);
}

void loop()
{
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(3, 255);
  delay(3000);

  digitalWrite(9, HIGH);
  delay(1000);

  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(3, 255);
  delay(3000);

  digitalWrite(9, HIGH);
  delay(1000);
}

