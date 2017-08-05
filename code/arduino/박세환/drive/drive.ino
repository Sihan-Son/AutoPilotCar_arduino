#include <Servo.h>

Servo Steer_Servo


#define Motor_F 12  //Forward
#define Motor_B     //Backward
#define Motor_V 3   //Velocity
#define Motor_S 9   //Stop
#define C_TRIG 2
#define L_TRIG 3
#define C_ECHO
#define L_ECHO



int C_Dis;
int L_Dis;
int R_Dis;



void setup()
{
  Serial.begin(9600);
  Steer_Servo.attach(x)
  pinMode(C_ECHO, INPUT);
  pinMode(L_ECHO, INPUT);
  pinMode(C_TRIG, OUTPUT);
  pinMode(L_TRIG, OUTPUT);
  pinMode(Motor_F, OUTPUT);
  pinMode(Motor_B, OUTPUT);
  pinMode(Motor_V, OUTPUT);
  pinMode(Motor_S, OUTPUT);
}


int getDistance(char TRIG, char ECHO)
{
  digitalWrite(TRIG, HIGH);

  delay(10);

  digitalWrite(TRIG ,LOW);

  int distance = pulseln(ECHO, HIGH)/58.2;

  return distance;
}



void loop()
{

  
  if(C_Dis>30)
  {
    digitalWrite(Motor_F, HIGH);
    analogWrite(3, 255);
  }

  delay(10)

  else if(C_Dis=<30&&L_Dis<=10)
  {
    digitalWrite(Motor_B, HIGH);
    analogWrite(3, 255);
    Steer_Servo.write(120);
    digitalWrite(Motor_F, HIGH);
    analogWrite(3, 255);
  }

  delay(10)

  else if(C_Dis=<30&&L_Dis>30)
  {
    digitalWrite(Motor_B, HIGH);
    analogWrite(3, 255);
    Steer_Servo.write(60);
    digitalWrite(Motor_F, HIGH);
    analogWrite(3, 255);
  }

}















