#include <Servo.h>

int TRIG = 12;                  //ultrasonic sensor trig pin
int ECHO = 11;                  // " echo pin
float duration;
float distance;

#define L_Motor_F 2       //드라이브와 아두이노 연결 핀
#define L_Motor_B 3
#define L_Motor_V 5
#define R_Motor_B 7
#define R_Motor_F 8
#define R_Motor_V 6
#define Obstacle 1
Servo Steer_Servo;

void setup()
{
  Steer_Servo.attach(9);            //9번핀에 서보 연결
  pinMode(L_Motor_F, OUTPUT);
  pinMode(L_Motor_B, OUTPUT);
  pinMode(L_Motor_V, OUTPUT);
  pinMode(R_Motor_B, OUTPUT);
  pinMode(R_Motor_F, OUTPUT);
  pinMode(R_Motor_V, OUTPUT);
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  getDistance();
  if (distance >= 40)
  {
    Steer_Servo.write(95);
    setSpeed(110);
    forward();
  }
  else if ((distance < 40) && (distance >= 7) && digitalRead(Obstacle) == LOW)
  {
    Steer_Servo.write(60);
    setSpeed(90);
    forward();
    delay(100);
  }
  else if ((distance < 40) && (distance >= 7) && digitalRead(Obstacle) == HIGH)
  {

    Steer_Servo.write(130);
    setSpeed(90);
    forward();
    delay(100);
  }
  else if (distance < 7)
  {
    stop();
  }
}

void forward()     //정회전
{
  digitalWrite(L_Motor_F, LOW);
  digitalWrite(L_Motor_B, HIGH);
  digitalWrite(R_Motor_F, LOW);
  digitalWrite(R_Motor_B, HIGH);
}

void stop()      //정지
{
  digitalWrite(L_Motor_F, LOW);
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, LOW);
  digitalWrite(R_Motor_B, LOW);

}

void backward()     //역회전
{
  Steer_Servo.write(95);
  digitalWrite(L_Motor_F, HIGH);
  digitalWrite(L_Motor_B, LOW);
  digitalWrite(R_Motor_F, HIGH);
  digitalWrite(R_Motor_B, LOW);
}

void getDistance()          //거리계산
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = ((340 * duration) / 10000) / 2;
}

void setSpeed(char speed)
{
  analogWrite(L_Motor_V, speed);
  analogWrite(R_Motor_V, speed);
}


