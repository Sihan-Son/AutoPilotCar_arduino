#include <stdio.h>
#include <wiringPi.h> // for using wiringPi, to control GPIO PIN with C
#include <unistd.h>
#include <softPwm.h> // for PWM control

#define MOTOR1 1 //GPIO 18
#define MOTOR2 0 //GPIO 16
#define Speed 4 //GPIO 23

int main(void)
{
	if(wiringPiSetup() ==-1)
		return 1;
	
	softPwmCreate(Speed,0,100);
	
	pinMode(MOTOR1, OUTPUT);
	pinMode(MOTOR2, OUTPUT);
	

	for(;;)
	{
		softPwmWrite(Speed, 50);
		digitalWrite(MOTOR1, 1);
		digitalWrite(MOTOR2, 0);
		//usleep(50000);
		//digitalWrite(4,0);
		//digitalWrite(5,1);
	}
	return 0;
}
