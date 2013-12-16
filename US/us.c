#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>


#define US_TRIGGER_PIN	7
#define US_ECHO_PIN	6

int main()
{
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
	
	sleep(1000);
	
	printf("\nULTRASONIC MEASURE.\r\n\r\n");
	

	fflush(stdout);


}
