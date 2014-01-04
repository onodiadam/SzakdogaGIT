#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Java_DhtMain.h>

#define MAX_TIME 185
#define DHT11PIN 0
int dht_val[5]={0,0,0,0,0};
int failmeter = 0;

JNIEXPORT jint JNICALL Java_Java_DhtMain_read(JNIEnv *env, jobject obj)
{
if (wiringPiSetup() == -1)
exit(1);
while(failmeter < 10)
{

		uint8_t lststate=HIGH;
		uint8_t counter = 0;
		uint8_t j= 0, i;
		long humtemp = 0;
		for (i = 0 ; i < 5 ; i++)
		{
			dht_val[i] = 0;
		}

		pinMode(DHT11PIN,OUTPUT);
		digitalWrite(DHT11PIN, LOW);
		delay(18);
		digitalWrite(DHT11PIN, HIGH);
		delayMicroseconds(40);
		pinMode(DHT11PIN, INPUT);
		
		for ( i = 0 ; i < MAX_TIME ; i++)
		{
				counter = 0;
				while(digitalRead(DHT11PIN)==lststate)
				{
					counter++;
					delayMicroseconds(1);
					if(counter==255)
						break;
				}
				lststate = digitalRead(DHT11PIN);
				if(counter == 255)
					break;
				if ((i >= 4) && (i%2 == 0))
				{
					dht_val[j/8]<<=1;
					if(counter > 16)
						dht_val[j/8] |= 1;
					j++;	
				}
		}
	
		if((j >= 40) && (dht_val[4] == ((dht_val[0] + dht_val[1] + dht_val[2] + dht_val[3]) & 0xFF)))
		{
			humtemp = (uint32_t)(dht_val[0] << 16) | (uint16_t) dht_val[2];
			if (dht_val[0]>10 && dht_val[0]<90 && dht_val[2] > 0 && dht_val[2] < 50)
			{
//			printf("Humidity = %d.%d %% Temperature = %d.%d *C\n",dht_val[0],dht_val[1],dht_val[2],dht_val[3]);
			failmeter = 0;
			return humtemp;
			}
		}
/*		else
		{
			humtemp = 1024;

			printf("Invalid data!");
			return humtemp;
		}
*/	
failmeter++;
delay(10);
}		
return 99;
}	
