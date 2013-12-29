package Java;

import Java.DhtMain;
import Java.UsMain;

class Main
{
	public static void main(String [] args	)
	{
		DhtMain dht = new DhtMain();
		DhtValue dhtData = (DhtValue)dht.measure();
		
		int humadity = dhtData.hum;
		int temperature = dhtData.temp;
		
		UsMain us = new UsMain();
		UsValue usData = (UsValue)us.measure();
		
		int distance = usData.distance;
		
		System.out.println("Temp: " + temperature + "°C\t Hum: " + humadity + "%\t dist: " + distance + "cm");

	}
	
}
