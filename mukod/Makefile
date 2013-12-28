DEBUG	= -O3
CC	= gcc
INCLUDE = -I/usr/local/include -I/usr/lib/jvm/jdk-7-oracle-armhf/include -I/usr/lib/jvm/jdk-7-oracle-armhf/include/linux

CFLAGS 	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe -std=gnu99

LDFLAGS = -L/usr/local/lib
LDLIBS	= -lwiringPi -lpthread -lm -lbcm2835

dht:	dht.o
	@echo $(INCLUDE) [link]
	@$(CC) -shared -o libDht.so -fPIC $(LDFLAGS) $(LDLIBS)
