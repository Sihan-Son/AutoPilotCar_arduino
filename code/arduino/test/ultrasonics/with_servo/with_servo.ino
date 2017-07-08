#include <Servo.h>

Servo steer_servo;
#define TRIG 12
#define ECHO 13

void setup() {
  Serial.begin(9600);  
  pinMode(TRIG,OUTPUT); 
  pinMode(ECHO,INPUT);
  steer_servo.attach(2);

}

void loop() {
 int distance = 0;  
 
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG,LOW); 
  distance = pulseIn(ECHO,HIGH)/58.2;  
  Serial.print("distance:"+(String)distance); 
  Serial.println("cm");
  //delay(3000);
  if(distance <20)
  {
    steer_servo.write(115);
  }
  else
  {
    steer_servo.write(85);
  }
  
  
}
