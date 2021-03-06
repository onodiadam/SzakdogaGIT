#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>


#define US_TRIGGER_PIN	7
#define US_ECHO_PIN	6


static int triggered = 0;
static inline void doTrigger();
static struct timeval t1, t2, t3;
static double elapsedTime;

void echoArrived();
void waitEcho();

int main()
{

	//init the wiringPi
	wiringPiSetup();

	piHiPri(99);
	
	//set up pin directions
	pinMode(US_TRIGGER_PIN, OUTPUT);
	pinMode(US_ECHO_PIN, INPUT);
	digitalWrite(US_TRIGGER_PIN, 0);
	
	//set up pin pullups
	pullUpDnControl(US_TRIGGER_PIN, PUD_OFF);
	pullUpDnControl(US_ECHO_PIN, PUD_OFF);
	
	printf("\nGPIO config done.\r\n\r\n");
	
	printf("\nULTRASONIC MEASURE.\r\n\r\n");
	
	wiringPiISR (US_ECHO_PIN,INT_EDGE_RISING ,  echoArrived);
	
	doTrigger();
	gettimeofday(&t1, NULL);
	waitEcho();
	gettimeofday(&t2, NULL);
	
	  elapsedTime = (double)(t2.tv_usec - t1.tv_usec);
	 printf("\nULTRASONIC MEASURE DONE.\r\n\r\n");
	printf("\nTIME %f us\r\n", elapsedTime);
	
	return 0;
}

static inline void doTrigger()
{
	digitalWrite(US_TRIGGER_PIN, 1);
	delayMicroseconds(10);
	digitalWrite(US_TRIGGER_PIN, 1);
}

void waitEcho()
{
    while(!digitalRead(US_ECHO_PIN));
}

void echoArrived()
{
  gettimeofday(&t2, NULL);
  

	
  printf("\nULTRASONIC MEASURE DONE.\r\n\r\n");
  printf("\nTIME %f us\r\n", elapsedTime);
	

  fflush(stdout);
  triggered = 1;
  
}
