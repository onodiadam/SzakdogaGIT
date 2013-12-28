DEBUG	= -O3
CC	= gcc
INCLUDE = -I/usr/local/include -I/usr/lib/jvm/java-7-openjdk/include -I/usr/lib/jvm/java-7-openjdk/include/linux
CFLAGS 	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS = -L/usr/local/lib

hello:
	@$(CC) $(INCLUDE) $(LDFLAGS) $(LDLIBS) -o libHello.so -shared -fpic Hello.c
	
helloJava:
	@javac Hello.java
	@javah -jni Hello
