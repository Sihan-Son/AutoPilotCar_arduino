#include <Servo.h>
int motor = 5;
Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(motor);
  pinMode(motor, OUTPUT);;
}

void loop() 
{
  int sensor = analogRead(A0);
  if(sensor > 1000)
  {
    for(int i = 0; i < 180; i++)
    {
      servo.write(i);
      delay(10);
    }
    while(sensor >=1000 && sensor <= 1023)
    {
      delay(100);
      sensor = analogRead(A0);
    }
    else
    {
      for (int k = 180; k > 0; k--)
      {
        servo.write(k);
      delay(10);
      }
      while(sensor >=0 && sensor < 1000)
      {
      delay(100);
      sensor = analogRead(A0);
      }
        
      }
    }
    digitalWrite(Led, HIGH);
  }
}

