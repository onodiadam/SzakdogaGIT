#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define TRIGGER 7
#define ECHO 6

int main()
{	
	wiringPiSetup();
	wiringPiSetupSys();
	pinMode(TRIGGER, OUTPUT);
	pinMode(ECHO, INPUT);
	struct timeval start, end;
	
	digitalWrite(TRIGGER, LOW);
	usleep(30);
	
	digitalWrite(TRIGGER, HIGH);
	usleep(10);
	digitalWrite(TRIGGER, LOW);

	
	while(digitalRead(ECHO) == LOW);
	
	gettimeofday(&start,NULL);
	
	printf("%ld\n", (start.tv_usec));	
//	long startTime = micros();
//	printf("Start Time: %lu\n", startTime);
	while(digitalRead(ECHO) == HIGH);
	
	gettimeofday(&end, NULL);
	
	printf("%ld\n", (end.tv_usec - start.tv_usec));
	
//	long stopTime = micros();
//	long travelTime = stopTime - startTime;
//	printf("Stop Time: %lu\n", stopTime);
//	int distance = 0;
//	distance = travelTime/54;
	
//	printf("Distance: %dcm\n", distance);
/*	struct timeval start, end;
	gettimeofday(&start,NULL);
	delay(500);
	gettimeofday(&end,NULL);
	if (end.tv_usec < start.tv_usec)
		{end.tv_usec += 1000000;}	
	
	printf("%ld\n", (end.tv_usec - start.tv_usec));	
	printf("%ld\n", (start.tv_usec));	
	printf("%ld\n", (end.tv_usec));	
	*/
	return 1;
}
