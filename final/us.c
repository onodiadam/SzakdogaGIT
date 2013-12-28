#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TRIGGER 7
#define ECHO 6
#define ST_BASE (0x20003000)
#define TIMER_OFFSET (4)

long timer()
{

	long long int *timer; //64 bit timer
	int fd;
	void *st_base; //byte ptr to simplify offset math
	
	//get access to system core memory
	if (-1 == (fd = open("/dev/mem", O_RDONLY))) {
		fprintf(stderr, "open() failed.\n");
		return 255;
		
	}
	
	//map a specific page into process's address space
	if (MAP_FAILED == (st_base = mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd, ST_BASE))) {
		fprintf(stderr, "mmap() failed.\n");
		return 255;
	}

	//set up pointer, based on mapped page
	timer = (long long int *)((char *)st_base + TIMER_OFFSET);

	return *timer;
}

void init() {
	wiringPiSetup();
	piHiPri(99);
	pinMode(TRIGGER, OUTPUT);
	pinMode(ECHO, INPUT);
	
	digitalWrite(TRIGGER, LOW);
	delay(30);	
}

JNIEXPORT jint JNICALL Java_Us_distance(JNIEnv *env, jobject obj) {
//int distance() {
	init();
	digitalWrite(TRIGGER, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIGGER, LOW);

	long start, stop, diff;
	
	while(digitalRead(ECHO) == LOW);
	start = timer();
	
	while(digitalRead(ECHO) == HIGH);
	stop = timer();
	diff = (stop - start) / 58;
	return diff;
}

