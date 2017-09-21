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

void setup()
{
	pinMode(C_Motor_V, OUTPUT);
	pinMode(C_Motor_F, OUTPUT);
	pinMode(C_Motor_B, OUTPUT);
	Steer_Servo.attach(7);
	BT.begin(9600);
	Serial.begin(9600);
}

void setSpeed(unsigned speed)
{
	analogWrite(C_Motor_V, speed);
}

void forward()
{
	Steer_Servo.write(90);
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, LOW);
}

void backward()
{
	Steer_Servo.write(90);
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
	setSpeed(130);
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, LOW);
	delay(500);
	Steer_Servo.write(150);
	delay(1000);

	Steer_Servo.write(75); // 우회전 이후 정면 각도가 75
	delay(500);
}

void turn_Left()
{
	setSpeed(130);
	digitalWrite(C_Motor_F, HIGH);
	digitalWrite(C_Motor_B, LOW);
	delay(500);
	Steer_Servo.write(30);
	delay(1000);

	Steer_Servo.write(100);
	delay(500);
}

int i;

void loop()
{
	setSpeed(130);

	if(BT.available())
	{
		char value = (char)BT.read();

		if (value == 'l')
		{
			turn_Left();
			delay(1000);
		}
		if (value == 'r')
		{
			turn_Right();
			delay(1000);
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

	/*
	Serial.println("f");
	forward();
	delay(1000);
	
	Serial.println("b");
	backward();
	delay(1000);
	
	Serial.println("l");
	turn_Left();
	
	Serial.println("r");
	turn_Right();
	*/
	
}
