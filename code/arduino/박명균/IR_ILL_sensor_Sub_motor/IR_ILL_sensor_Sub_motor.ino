int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;

#include <Servo.h>
int ill_sensorpin = A0;// 센서값을 읽을 단자 설정
int IR_sensorpin = 9; // 센서값을 읽을 단자 설정
int ill_val = 0;
int IR_val = 0;
Servo IR_servo;
Servo ill_servo;

void setup ()
{
  pinMode(IN1, OUPUT);
  pinMode(IN2, OUPUT);
  pinMode(IN3, OUPUT);
  pinMode(IN4, OUPUT);
  ill_servo.attach(3);
  IR_servo.attach(2);
  Serial.begin(9600);
}

void loop ()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println(val);
  val = analogRead(ill_sensorpin);
  val = map(val, 0 , 50, 0, 180);
  if (val < 85) {
    ill_servo.write(35);
    delay(3000);
    ill_servo.write(0);
  }
  delay(1000);
}
Serial.println(IR_val);
IR_val = digitalRead (IR_sensorpin); // 센서값을 읽어옴
if (IR_val == HIGH) { // 장애물 감지 안됨
  IR_servo.write(0);
  delay(100);
} else {
  IR_servo.write(35);
  delay(100);
}
