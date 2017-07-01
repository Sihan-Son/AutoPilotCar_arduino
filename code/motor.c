#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <softPwm.h>

#define MOTOR1 1
#define MOTOR2 0
#define Speed 4

int main(void)
{
	if(wiringPiSetup() ==-1)
	return 1;
	
	
	
	pinMode(MOTOR1, OUTPUT);
	pinMode(MOTOR2, OUTPUT);

	for(;;)
	{
		digitalWrite(MOTOR1, 1);
		digitalWrite(MOTOR2, 0);
		//usleep(50000);
		//digitalWrite(4,0);
		//digitalWrite(5,1);
	}
	return 0;
}
