DEBUG	= -O3
CC	= gcc
INCLUDE = -I/usr/local/include -I/usr/lib/jvm/jdk-7-oracle-armhf/include -I/usr/lib/jvm/jdk-7-oracle-armhf/include/linux
CFLAGS 	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe -std=gnu99

LDFLAGS = -L/usr/local/lib

LDLIBS = -lwiringPi -lpthread -lm -lbcm2835

dht:
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o libDht.so -shared -fPIC dht.c
	
dhtJava:
	@javac -cp . dht.java
	@javah -jni Dht
	
us:
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o libUs.so -shared -fPIC us.c
	
usJava:
	@javac us.java
	@javah -jni Us
