//www.mindplusplus.wordpress.com/2013/05/21/accessing-the-raspberry-pis-1mh-timer/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define ST_BASE (0x20003000)
#define TIMER_OFFSET (4)

long timer()
{

	long long int t, prev, *timer; //64 bit timer
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
/*	
	//read initial timer
	prev = *timer;
	//and wait
	sleep(1);
	while (1==1) { //forever
		//read new timer
		t = *timer;
		//print difference (and flush output)
		printf("Timer diff = %lld      \n", t - prev);
		printf("\n");
		//save current time
		prev = t;
		fflush(stdout);
		
		//and wait
		usleep(10);
	}*/
	
	return *timer;
}
int main(int argc, char *argv[]) {
printf("%lld\n",timer());
return 0;
}
