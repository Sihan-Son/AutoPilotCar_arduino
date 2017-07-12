//모터 PIN 설정
#define IN1 6 //forward
#define IN2 7 //backward

#define IN3 5
#define IN4 4

#define ENA 10 //in1,2
#define ENB 9 // in3,4

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

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//뒤로
void backward(){
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

void loop() {
    // put your main code here, to run repeatedly:
  //최대 속도로 동작
  setMotorSpeed(ALL_CH, 255);

  //앞으로 가기
  forward();
  delay(1000); //1초동안 동작함
  //뒤로가기
  backward();
  delay(1000);
  //왼쪽으로 돌기


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
