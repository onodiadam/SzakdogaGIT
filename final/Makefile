DEBUG	= -O3
CC	= gcc
INCLUDE = -I/usr/local/include -I/usr/lib/jvm/jdk-7-oracle-armhf/include -I/usr/lib/jvm/jdk-7-oracle-armhf/include/linux
CFLAGS 	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe -std=gnu99

LDFLAGS = -L/usr/local/lib

LDLIBS = -lwiringPi -lpthread -lm -lbcm2835

dht:
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o libDht.so -shared -fpic dht.c
	
dhtJava:
	@javac dht.java
	@javah -jni Dht
