// 서보 선언
#include "Servo.h"
Servo steer_servo;
//초음파 번호
#define Front_Echo 2
#define Front_Trig 3
#define Right_Side_Echo 4
#define Right_Side_Trig 5
#define Left_Side_Echo 6
#define Left_Side_Trig 7
//모터 번호
#define R_motor_f 8
#define R_motor_b 9
#define R_motor_speed A0
#define L_motor_f 10
#define L_motor_b 11
#define L_motorspeed A1
#define R_IR 12
#define L_IR 13
int type;
int F_Echo=0;
int R_Echo=0;
int L_Echo=0;

void setup() {
  pinMode(Front_Trig, OUTPUT); 
  pinMode(Front_Echo, INPUT);
  pinMode(Right_Side_Trig, OUTPUT); 
  pinMode(Right_Side_Echo, INPUT);
  pinMode(Left_Side_Trig, OUTPUT); 
  pinMode(Left_Side_Echo, INPUT);
  pinMode(R_motor_f, OUTPUT);
  pinMode(R_motor_b, OUTPUT); 
  pinMode(R_motor_speed, OUTPUT);
  pinMode(L_motor_f, OUTPUT);
  pinMode(L_motor_b, OUTPUT);
  pinMode(L_motorspeed, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop() {
  digitalWrite(Front_Trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Front_Trig, LOW);
  F_Echo = pulseIn(Front_Echo, HIGH)/58.2;
  digitalWrite(Right_Side_Trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Right_Side_Trig, LOW);
  R_Echo = pulseIn(Right_Side_Echo, HIGH)/58.2;
  digitalWrite(Left_Side_Trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(Left_Side_Trig, LOW);
  L_Echo = pulseIn(Left_Side_Echo, HIGH)/58.2;
  if(F_Echo>30){
    type=1;
  }
  if(F_Echo<30){
    type=2;
  }
  if(F_Echo<10&&R_Echo<10){
    type=3;
  }
    if(F_Echo<10&&L_Echo<10){
    type=4;
  }
    if(F_Echo<10&&R_Echo<10&&L_Echo<10){
    type=5;
  }
  switch (type){
  case 1:{
  digitalWrite(R_motor_f,HIGH); 
  digitalWrite(R_motor_b,LOW);
  analogWrite(R_motor_speed,255);
  digitalWrite(L_motor_f,HIGH); 
  digitalWrite(L_motor_b,LOW);
  analogWrite(L_motorspeed,255);
  break;
  }
  case 2:{
  digitalWrite(R_motor_f,HIGH); 
  digitalWrite(R_motor_b,LOW);
  analogWrite(R_motor_speed,150);
  digitalWrite(L_motor_f,HIGH); 
  digitalWrite(L_motor_b,LOW);
  analogWrite(L_motorspeed,150);
  break;
  }
  case 3:{
  digitalWrite(R_motor_f,HIGH); 
  digitalWrite(R_motor_b,HIGH);
  analogWrite(R_motor_speed,150);
  digitalWrite(L_motor_f,HIGH); 
  digitalWrite(L_motor_b,HIGH);
  analogWrite(L_motorspeed,150);
  break;
  }
  case 4:{
  digitalWrite(R_motor_f,HIGH); 
  digitalWrite(R_motor_b,HIGH);
  analogWrite(R_motor_speed,150);
  digitalWrite(L_motor_f,HIGH); 
  digitalWrite(L_motor_b,HIGH);
  analogWrite(L_motorspeed,150);  
  break;
  }
  case 5:{
  digitalWrite(R_motor_f,HIGH); 
  digitalWrite(R_motor_b,HIGH);
  analogWrite(R_motor_speed,150);
  digitalWrite(L_motor_f,HIGH); 
  digitalWrite(L_motor_b,HIGH);
  analogWrite(L_motorspeed,150);  
  break;
  }
  }
}

