#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <unistd.h>

#define SERVO 1

int main()
{

	char str;
	
	if(wiringPiSetup()==-1)
	return 1;
	softPwmCreate(SERVO, 0, 200);

	while(1)
	{
		fputs("select R, L Q : ", stdout);
		scanf("%c",&str);
		getchar();
		if(str == 'r')
		{
			softPwmWrite(SERVO,20);
			usleep(50000);
			softPwmWrite(SERVO,0);
		}
		else if(str =='l')
		{
			softPwmWrite(SERVO,20);
			usleep(50000);
			softPwmWrite(SERVO,0);
		}
		else if(str =='q')
		return 0;
	}
return 0;
}
