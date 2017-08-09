//초음파
#define TRIG 12
#define ECHO 13

//모터 PIN 설정
#define IN1 6 //forward
#define IN2 7 //backward

#define IN3 5
#define IN4 4

#define ENA 10 //in1,2
#define ENB 9 // in3,4

#define ALL_CH 2

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void setMotorSpeed(unsigned char mode, unsigned char speed) {


  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

}

//앞으로
void forward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//뒤로
void backward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  int distance = 0;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  distance = pulseIn(ECHO, HIGH) / 58.2;
  // Serial.print("distance:"+(String)distance);
  // Serial.println("cm");

  if (distance < 30)
  {
    setMotorSpeed(ALL_CH, 0);
    forward();
    Serial.print("distance:" + (String)distance);
    Serial.println("cm");
  }
  if (distance > 30 && distance < 60)
  {
    setMotorSpeed(ALL_CH, 150);
    forward();
    Serial.print("distance:" + (String)distance);
    Serial.println("cm");
  }
  if (distance > 60 && distance < 100)
  {
    setMotorSpeed(ALL_CH, 255);
    forward();
    Serial.print("distance:" + (String)distance);
    Serial.println("cm");
  }
  else {
    setMotorSpeed(ALL_CH, 255);
    forward();
    Serial.print("distance:" + (String)distance);
    Serial.println("cm");
  }
  delay(500);
  Serial.println("");

}
