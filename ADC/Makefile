DEBUG	= -O3
CC	= gcc
INCLUDE = -I/usr/local/include
CFLAGS 	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS = -L/usr/local/lib
LDLIBS	= -lwiringPi -lpthread -lm

adc:	adc.o
	@echo [link]
	@$(CC) -o $@ adc.o $(LDFLAGS) $(LDLIBS)
