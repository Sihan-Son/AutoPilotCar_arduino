// 서보 선언
#include <Servo.h>
Servo Steer_Servo;

//초음파 번호
#define F_Side_ECHO 2
#define F_Side_TRIG 4
#define R_Side_ECHO 5
#define R_Side_TRIG 6
#define L_Side_ECHO 7
#define L_Side_TRIG 8


//모터 번호
#define R_Motor_F 12
#define R_Motor_B 9
#define R_Motor_V 3
int  type;
int F_Dis;
int R_Dis;
int L_Dis;

void setup() 
{
  Steer_Servo.attach(10);
//초음파 번호
  pinMode(F_Side_TRIG, OUTPUT); 
  pinMode(F_Side_ECHO, INPUT);
  pinMode(R_Side_TRIG, OUTPUT); 
  pinMode(R_Side_ECHO, INPUT);
  pinMode(L_Side_TRIG, OUTPUT); 
  pinMode(L_Side_ECHO, INPUT);
  //모터 번호
  pinMode(R_Motor_F, OUTPUT);
  pinMode(R_Motor_B, OUTPUT); 

  pinMode(R_Motor_V, INPUT);

  Serial.begin(9600);
  
}
void  setSpeed(char speed)
{
  analogWrite(R_Motor_V,speed);

}
void  forward()
{
  Steer_Servo.write(90);

  digitalWrite(R_Motor_F,HIGH);
  digitalWrite(R_Motor_B,LOW);
}
void backward()
{
Steer_Servo.write(90);

digitalWrite(R_Motor_F ,LOW);
digitalWrite(R_Motor_B ,HIGH);
}

int getDistance(char TRIG,char ECHO)
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  int distance = pulseIn(ECHO, HIGH)/58.2;
  return distance;
}

void loop() 
{
 
  F_Dis = getDistance(F_Side_TRIG,F_Side_ECHO);
  
  R_Dis = getDistance(R_Side_TRIG,R_Side_ECHO);
  
  L_Dis = getDistance(L_Side_TRIG,L_Side_ECHO);
  Serial.println(F_Dis);
  Serial.println(R_Dis);
  Serial.println(L_Dis);
  Steer_Servo.write(90);
  setSpeed(150);//문제가 없으면 주행
  forward();
  
  if(F_Dis>35&&R_Dis<8)// 전방 장애물없이 2차선 주행
  {
    type=1;
  }
  if(F_Dis>35&&L_Dis<8)// 전방 장애물없이 1차선 주행
  {
    type=2;
  }
  if(F_Dis<35&&R_Dis<8)// 전방 장애물있는 2차선 주행
  {
    type=3;
  }
  if(F_Dis<35&&L_Dis<8)// 전방 장애물있는 1차선 주행
  {
    type=4;
  }
  if(F_Dis<20&&R_Dis<8&&L_Dis<35)// 2차선 주행중 차선변경필요
  {
    type=5;
  }
  if(F_Dis<20&&L_Dis<8&&R_Dis<35)// 1차선 주행중 차선변경필요
  {
    type=6;
  }
  if(F_Dis<20&&R_Dis<8&&L_Dis>35)//2차선 주행중 좌회전도로
  {
    type=7;
  }
  if(F_Dis<20&&R_Dis>30&&L_Dis<35)//2차선 주행중 우회전도로
  {
    type=8;
  }
  if(F_Dis<20&&L_Dis>30&&R_Dis<35)//1차선 주행중 좌회전도로
  {
    type=9;
  }
  if(F_Dis<20&&L_Dis<8&&R_Dis>35)//1차선 주행중 우회전도로
  {
    type=10;
  }  






  
  switch (type)
  {
   case 1: // 전방 장애물없이 2차선 주행
   {
  setSpeed(150);//문제가 없으면 주행
  forward();
  if (L_Dis>18)
  {
  Steer_Servo.write(95);//왼쪽초음파가 벽과 가까워지면 서보를 벽반대로 돌린다
  forward();
    Serial.println("case1");
  }
  else if (L_Dis<21)
  {
     Steer_Servo.write(85);//왼쪽초음파가 벽과 멀어지면 서보를 벽으로 돌린다
  forward();
    }
    break;
  }
   case 2: // 전방 장애물없이 1차선 주행
   {
  setSpeed(150);//문제가 없으면 주행
  forward();
      Serial.println("case2");
  if (R_Dis>18)
  {
  Steer_Servo.write(85);//오른쪽초음파가 벽과 가까워지면 서보를 벽반대로 돌린다
  forward();
  }
  if (R_Dis<21)
  {
     Steer_Servo.write(95);//오른쪽초음파가 벽과 멀어지면 서보를 벽으로 돌린다
  forward();
  }
 break;
   }
   case 3: //전방 장애물있는 2차선 주행
   {
  setSpeed(100);
  forward();
      Serial.println("case3");
  if (L_Dis>18)
  {
  Steer_Servo.write(95);//왼쪽초음파가 벽과 가까워지면 서보를 벽반대로 돌린다
  forward();
  }
  if (L_Dis<21)
  {
     Steer_Servo.write(85);//왼쪽초음파가 벽과 멀어지면 서보를 벽으로 돌린다
  forward(); 
  }
 break;
   }
   case 4: //전방 장애물있는 1차선 주행
   {
  setSpeed(100);
  forward();
      Serial.println("case4");
  if (R_Dis>18)
  {
  Steer_Servo.write(85);//오른쪽초음파가 벽과 가까워지면 서보를 벽반대로 돌린다
  forward();
  }
  if (R_Dis<21)
  {
     Steer_Servo.write(95);//오른쪽초음파가 벽과 멀어지면 서보를 벽으로 돌린다
  forward();
  }
 break;
   }
   case 5:// 2차선 주행중 차선변경필요
   {    
 break;
   }
   case 6:// 1차선 주행중 차선변경필요
   { 
 break;
   }
   case 7://2차선 주행중 좌회전도로
   {    
 break;
   }
   case 8://2차선 주행중 우회전도로
   {    
 break;
   }
   case 9://1차선 주행중 좌회전도로
   {    
 break;
   }
   case 10://1차선 주행중 우회전도로
   {
 break;
   }
  }
}

