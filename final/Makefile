DEBUG	= -O3
CC	= gcc

INCLUDE = -I/usr/local/include \
          -I/usr/lib/jvm/jdk-7-oracle-armhf/include \
          -I/usr/lib/jvm/jdk-7-oracle-armhf/include/linux \
	  -I./lib
		
CFLAGS 	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe -std=gnu99

LDFLAGS = -L/usr/local/lib

LDLIBS = -lwiringPi -lpthread -lm -lbcm2835

JAVAPATH = .
LIBPATH = ./lib
JAVALIBPATH = /root/work/GIT/SzakdogaGIT

all:
	@echo "--> Making IMeasure.class..."
	@javac -d $(JAVAPATH) IMeasure.java 
	@echo "--> Making Dht.class, Dhtmain.class, DhtValue.class..."
	@javac -d $(JAVAPATH) dht.java
	@echo "--> Generating JNI header for libDht.so..."
	@javah -d $(LIBPATH) -jni Java.DhtMain
	@echo "--> Making libDht.so..."
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o ./lib/libDht.so -shared -fPIC dht.c
	@echo "--> Making Us.class, UsMain.class, UsValue.class..."
	@javac -d $(JAVAPATH) us.java
	@echo "--> Generating JNI header for libUs.so..."
	@javah -d $(LIBPATH) -jni Java.Us
	@echo "--> Making libUs.so..."
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o ./lib/libUs.so -shared -fPIC us.c
	@echo "--> Making JNI_handler.class..."
	@javac -d $(JAVAPATH) JNI_handler.java
