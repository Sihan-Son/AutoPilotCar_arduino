#include <SoftwareSerial.h>
#include <Servo.h>

//bluetooth
#define Tx 2
#define Rx 3
SoftwareSerial BT(Tx, Rx);

//Servo
Servo Steer_Servo;

#define C_Motor_V 4
#define C_Motor_B 5
#define C_Motor_F 6

void setup() {
	// put your setup code here, to run once:
	BT.begin(9600);
	pinMode(C_Motor_V, OUTPUT);
	pinMode(C_Motor_F, OUTPUT);
	pinMode(C_Motor_B, OUTPUT);
	Steer_Servo.attach(7);

}

void setSpeed(unsigned speed)
{
	analogWrite(C_Motor_V, speed);
}

void forward()
{
	Steer_Servo.write(80);
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, LOW);
}

void backward()
{
	Steer_Servo.write(80);
	digitalWrite(C_Motor_F, LOW);
	digitalWrite(C_Motor_B, HIGH);
}

void stop(int time)
{
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, HIGH);
	delay(time);
}

void turn_Right()
{
	setSpeed(120);
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, LOW);
	Steer_Servo.write(110);
	delay(1000);
}

void turn_Left()
{
	setSpeed(120);
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, LOW);
	Steer_Servo.write(60);
	delay(1000);
}
void loop() {
	// put your main code here, to run repeatedly:
	setSpeed(150);
	if (BT.available())
	{
		char value = (char)BT.read();

		if (value == 'l')
		{
			turn_Left();
		}
		if (value == 'r')
		{
			turn_Right();
		}
		if (value == 'f')
		{
			forward();
			delay(1000);
		}
		if (value == 'b')
		{
			backward();
			delay(1000);
		}
		if (value == 's')
		{
			stop(1000);
		}
	}

}