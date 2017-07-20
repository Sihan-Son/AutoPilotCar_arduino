#include <Servo.h>

//Servo
Servo Steer_Servo;

#define C_Motor_V 4
#define C_Motor_B 5
#define C_Motor_F 6

void setup() {
  // put your setup code here, to run once:
  pinMode(C_Motor_V,OUTPUT);
  pinMode(C_Motor_F,OUTPUT);
  pinMode(C_Motor_B,OUTPUT);
  Steer_Servo.attach(7);

}

void setSpeed(unsigned speed)
{
  analogWrite(C_Motor_V,speed);
}

void forward()
{
  Steer_Servo.write(85);
  digitalWrite(C_Motor_F,HIGH);
  digitalWrite(C_Motor_B,LOW);
}

void backward()
{
  Steer_Servo.write(85);
  digitalWrite(C_Motor_F,LOW);
  digitalWrite(C_Motor_B,HIGH);
}

void stop(int time)
{
  digitalWrite(C_Motor_F,HIGH);
  digitalWrite(C_Motor_B,HIGH);
  delay(time);
}

void turn_Right()
{
  setSpeed(150);
  digitalWrite(C_Motor_F,HIGH);
  digitalWrite(C_Motor_B,LOW);  
  Steer_Servo.write(120);
  delay(1000);
}

void turn_Left()
{
  setSpeed(150);
  digitalWrite(C_Motor_F,HIGH);
  digitalWrite(C_Motor_B,LOW);
  Steer_Servo.write(60);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  turn_Right();
  turn_Left();
  stop(3000);
  
  setSpeed(150);
  forward();
  delay(1000);
  //backward();
  //delay(1000);

  stop(3000);
}
