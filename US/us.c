#include <stdio.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>


#define ADC_ADDR 0x48
#define ADC_PIN 1

int main()
{
	int adcResource;
	int adcValue[4];

	//init the wiringPi
	wiringPiSetup();

	//set up to input
	pinMode(ADC_PIN, INPUT);
	//status is off
	pullUpDnControl(ADC_PIN, PUD_OFF);
	
	printf("\nGPIO config done.\r\n\r\n");
	
	//Init I2C. Error if the adcResource is minus
	wiringPiI2CSetup(ADC_ADDR);

		//the first register is the 
		adcValue[0] = wiringPiI2CReadReg8(adcResource, 0);
		adcValue[1] = wiringPiI2CReadReg16(adcResource, 1);
		
		printf("\nADC value 0: 0x%i \r\n", adcValue[0]);
		printf("\nADC value 1: %i \r\n", adcValue[1]);

		fflush(stdout);


}
/*
adc_config()
* 18. oldal szerinti beállítás
* alert bit polaritás beállítás
* 
* 
* bit sorrendre figyelni kell
* %i nem hexa
* Javaból jni-vel hogy lehet használni a wiringPi-t


*/
