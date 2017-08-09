#define TRIG 12
#define ECHO 13

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  int distance = 0;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  distance = pulseIn(ECHO, HIGH) / 58.2;
  Serial.print("distance:" + (String)distance);
  Serial.println("cm");
}


