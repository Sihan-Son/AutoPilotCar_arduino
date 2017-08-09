#include <SoftwareSerial.h>
#include<Servo.h>
Servo Steer_Servo;
Servo UW_Servo;
#define TRIG 9
#define ECHO 8
#define L_Motor_F 6
#define L_Motor_B 5
#define L_Motor_V A0
#define R_Motor_F 4
#define R_Motor_B 3
#define R_Motor_V A1
void setup()
{
  Serial.begin(9600);
  pinMode(L_Motor_F, OUTPUT);
  pinMode(L_Motor_B, OUTPUT);
  pinMode(R_Motor_F, OUTPUT);
  pinMode(R_Motor_B, OUTPUT);
  pinMode(L_Motor_V, OUTPUT);
  pinMode(R_Motor_V, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Steer_Servo.attach(12);
  UW_Servo.attach(7);
}
void loop()
{
  float duration, distance, a, b, c, d;
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.print("\nDIstance : ");
  Serial.println(distance);
  Serial.println("forward");
  forward();

  if (distance < 15)
  {
    Serial.println("stop");
    stop();
    UW_Servo.write(170);
    delay(500);
    digitalWrite(TRIG, HIGH);
    delay(10);
    digitalWrite(TRIG, LOW);
    b = pulseIn(ECHO, HIGH);
    a = ((float)(340 * b) / 10000) / 2;
    Serial.print(a);
    Serial.println("cm");
    UW_Servo.write(15);
    delay(500);
    digitalWrite(TRIG, HIGH);
    delay(10);
    digitalWrite(TRIG, LOW);
    d = pulseIn(ECHO, HIGH);
    c = ((float)(340 * d) / 10000) / 2;
    Serial.print(c);
    Serial.println("cm");
    UW_Servo.write(90);
    stop();
    {
      if (a < c)
      {
        Serial.println("backward");
        backward();
        Serial.println("turn_Left");
        turn_Left();
      }
      else
      {
        Serial.println("backward");
        backward();
        Serial.println("turn_Right");
        turn_Right();
      }
    }
  }
  else
  {
    Serial.println("forward");
    forward();
  }
}

void forward()
{
  Steer_Servo.write(84);
  digitalWrite(L_Motor_F, HIGH);
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, HIGH);
  digitalWrite(R_Motor_B, LOW);
  analogWrite(L_Motor_V, 255);
  analogWrite(R_Motor_V, 255);
}

void backward()
{
  digitalWrite(L_Motor_F, LOW);
  digitalWrite(L_Motor_B, HIGH);
  digitalWrite(R_Motor_F, LOW);
  digitalWrite(R_Motor_B, HIGH);
  analogWrite(L_Motor_V, 255);
  analogWrite(R_Motor_V, 255);
  delay(1000);
}

void turn_Left()
{
  Steer_Servo.write(54);
  digitalWrite(L_Motor_F, HIGH);
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, HIGH);
  digitalWrite(R_Motor_B, LOW);
  analogWrite(L_Motor_V, 255);
  analogWrite(R_Motor_V, 255);
  delay(2000);
  Steer_Servo.write(84);
}

void turn_Right()
{
  Steer_Servo.write(114);
  digitalWrite(L_Motor_F, HIGH);
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, HIGH);
  digitalWrite(R_Motor_B, LOW);
  analogWrite(L_Motor_V, 255);
  analogWrite(R_Motor_V, 255);
  delay(2000);
  Steer_Servo.write(84);
}

void stop()
{
  digitalWrite(L_Motor_F, LOW);
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, LOW);
  digitalWrite(R_Motor_B, LOW);
  analogWrite(L_Motor_V, 255);
  analogWrite(R_Motor_V, 255);
  delay(500);
}
