#include <Servo.h>

//Servo Steer_Servo;
Servo myservo;
//모터 PIN 설정
#define IN1 5 //forward
#define IN2 6 //backward

#define IN3 7
#define IN4 6

#define ENA 4 //in1,2
#define ENB 8 // in3,4

//모터 번호
#define ALL_CH 2

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //Steer_Servo.attach(2);
  myservo.attach(2);

}

// 속도 설정
// mode : 각 모터를 선택적으로 변경 가능
// CH1, CH2, ALL_CH
// speed : 0 ~ 255 까지 가능
// 60 이하로는 모터가 거의 동작안함.

void setMotorSpeed(unsigned char mode, unsigned char speed){


    analogWrite(ENA, speed);
    analogWrite(ENB, speed);    
  
}

//앞으로
void forward(){
  myservo.write(85);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//뒤로
void backward(){
    myservo.write(85);

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
  myservo.write(60);
  delay(1000);
}

void turnRight()
{
  forward();
  myservo.write(120);
  delay(1000);
}

void turnLeft_R()
{
  backward();
  myservo.write(60);
  delay(1000);
}

void turnRight_R()
{
  backward();
  myservo.write(120);
  delay(1000);
}

void loop() {
    // put your main code here, to run repeatedly:
  //최대 속도로 동작
  setMotorSpeed(ALL_CH, 255);

  forward();

  delay(3000); //1초동안 동작함
 setMotorSpeed(ALL_CH, 200); 
  turnLeft();
  turnLeft_R();
  forward();
  delay(1000);
  



  //속도 조절 확인
  setMotorSpeed(ALL_CH, 200);  
  forward();
  delay(1000);
  backward();
  delay(1000);

  setMotorSpeed(ALL_CH, 150);  
  forward();
  delay(1000);
  backward();
  delay(1000);
  
  setMotorSpeed(ALL_CH, 100);  
  forward();
  delay(1000);
  backward();
  delay(1000);
  
  setMotorSpeed(ALL_CH, 80);  
  forward();
  delay(1000);
  backward();
  delay(1000);



}
