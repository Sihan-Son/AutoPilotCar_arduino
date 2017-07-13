#include <SoftwareSerial.h>
#include <Servo.h>

int TxPin = 2;
int RxPin = 3;

Servo Steer_Servo;
SoftwareSerial BTSerial(TxPin, RxPin); 

//모터 PIN 설정
#define IN1 6 //forward
#define IN2 7 //backward

#define IN3 5
#define IN4 4

#define ENA 12 //in1,2
#define ENB 11 // in3,4

//모터 번호
#define ALL_CH 2

void setup() {
   BTSerial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Steer_Servo.attach(8);

}

void setMotorSpeed(unsigned char mode, unsigned char speed){


    analogWrite(ENA, speed);
    analogWrite(ENB, speed);    
  
}

//앞으로
void forward(){
  Steer_Servo.write(85);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//뒤로
void backward(){
   //-------------------------------- Steer_Servo.write(85);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


//스톱
void stopMotor(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);  
}
void turnLeft()
{
  forward();
  Steer_Servo.write(60);
  delay(1000);
}

void turnRight()
{
  forward();
  Steer_Servo.write(120);
  delay(1000);
}

void turnLeft_R()
{
  backward();
  Steer_Servo.write(60);
  delay(1000);
}

void turnRight_R()
{
  backward();
  Steer_Servo.write(120);
  delay(1000);
}

void loop() {
  
 if (BTSerial.available())
  {
   char cmd  = BTSerial.read();
    
    if(cmd == 'l') 
    {
        Steer_Servo.write(60);
    }
    else if(cmd == 'r')
    {
      Steer_Servo.write(110);
    }
    else if(cmd == "c")
    {
      Steer_Servo.write(85);
    }
    else if(cmd == "b")
    {
       setMotorSpeed(ALL_CH, 255); 

      backward();
      delay(1000);
    }
  }
}
