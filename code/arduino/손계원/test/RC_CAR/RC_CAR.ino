#include <Servo.h>
#include <SoftwareSerial.h>

//블루투스
int Tx = 2;
int Rx = 3;
SoftwareSerial BTSerial(Tx, Rx);
int ledPin = 10;

//Servo
Servo Steer_Servo;

//모터
#define L_Motor_V 12
#define L_Motor_F 4
#define L_Motor_B 5

#define R_Motor_V 8
#define R_Motor_F 7
#define R_Motor_B 6

void setup() {

  BTSerial.begin(9600);
  Steer_Servo.attach(13);
  pinMode(L_Motor_V, OUTPUT);
  pinMode(L_Motor_F, OUTPUT);
  pinMode(L_Motor_B, OUTPUT);
  pinMode(R_Motor_V, OUTPUT);
  pinMode(R_Motor_F, OUTPUT);
  pinMode(R_Motor_B, OUTPUT);

}

void setSpeed(char speed) //속력 ㄱ60~255 사이 pwm 값 입력
{
  analogWrite(R_Motor_V, speed);
  analogWrite(L_Motor_V, speed);
}

//전진
void forward()
{
  Steer_Servo.write(85);
  digitalWrite(L_Motor_F, HIGH) ;
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, HIGH) ;
  digitalWrite(R_Motor_B, LOW);
}

//후진
void backward()
{
  Steer_Servo.write(85);
  digitalWrite(L_Motor_F, LOW) ;
  digitalWrite(L_Motor_B, HIGH);
  digitalWrite(R_Motor_F, LOW);
  digitalWrite(R_Motor_B, HIGH);
}

//정지
void stop()
{
  digitalWrite(L_Motor_F, HIGH) ;
  digitalWrite(L_Motor_B, HIGH);
  digitalWrite(R_Motor_F, HIGH);
  digitalWrite(R_Motor_B, HIGH);
}

void turn_Left()
{
  forward();
  Steer_Servo.write(60);
  delay(1000);
}

void turn_Right()
{
  forward();
  Steer_Servo.write(120);
  delay(1000);
}

void turn_Left_R()
{
  backward();
  Steer_Servo.write(60);
  delay(1000);
}

void turn_Right_R()
{
  backward();
  Steer_Servo.write(120);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available())
  {
    char cmd = (char)BTSerial.read();

    if (cmd == 'l')
    {
      setSpeed(200);
      turn_Left();
    }
    if (cmd == 'r')
    {
      setSpeed(200);
      turn_Right();
    }
    if (cmd == 'f')
    {
      setSpeed(255);
      forward();
      delay(1000);
    }
    if (cmd == '1')
    {
      digitalWrite(ledPin, HIGH);
    }
  }

}
