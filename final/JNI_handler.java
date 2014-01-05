package Java;

import Java.DhtMain;
import Java.UsMain;
import java.util.Date;
import Java.MySQLHandler;

class Main
{
	private static final String SRV_ADDRESS 		= "192.168.0.100";
	private static final String SRV_DATABASE 		= "test";
	private static final String SRV_USER			= "test";
	private static final String SRV_PASSWD 			= "test";
	
	
	public static void main(String [] args	) throws Exception
	{
		DhtMain dht = new DhtMain();
		DhtValue dhtData = (DhtValue)dht.measure();
		
		int humadity = dhtData.hum;
		int temperature = dhtData.temp;
		
		UsMain us = new UsMain();
		UsValue usData = (UsValue)us.measure();
		
		int distance = usData.distance;
		
		//System.out.println("Temp: " + temperature + "*C\t Hum: " + humadity + "%\t dist: " + distance + "cm");
		MySQLHandler dao = new MySQLHandler();
		dao.connectDatabase(SRV_ADDRESS, SRV_DATABASE, SRV_USER, SRV_PASSWD);
		Date date = new Date();
		dao.addMeasure(0, 12554, date);
		dao.addMeasure(1, humadity, date); //type, value
		dao.addMeasure(2, temperature, date); //type, value
		dao.addMeasure(3, distance, date); //type, value
		
		//0: ADC, 1: Hum, 2: Temp, 3: Us
		dao.closeDatabase();

	}
	
}
