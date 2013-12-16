#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>


#define US_TRIGGER_PIN	7
#define US_ECHO_PIN	6

int main()
{
	timeval t1, t2;
	double elapsedTime;
	
	//init the wiringPi
	wiringPiSetup();

	//set up pin directions
	pinMode(US_TRIGGER_PIN, OUTPUT);
	pinMode(US_ECHO_PIN, INPUT);
	digitalWrite(US_TRIGGER_PIN, 0);
	
	//set up pin pullups
	pullUpDnControl(US_TRIGGER_PIN, PUD_OFF);
	pullUpDnControl(US_ECHO_PIN, PUD_OFF);
	
	printf("\nGPIO config done.\r\n\r\n");
	
	gettimeofday(&t1, NULL);
	usleep(1000);
	gettimeofday(&t2, NULL);
	
	elapsedTime = (t2.tv_usec - t1.tv_usec);
	
	printf("\nULTRASONIC MEASURE.\r\n\r\n");
	printf("\nTIME %i us\r\n", elapsedTime);
	

	fflush(stdout);


}
