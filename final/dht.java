package Java;

class Dht 
{
	public native int read();
	static 
	{
		System.loadLibrary("Dht");	
	}
	
}

class DhtMain implements IMeasure
{
	public Object measure()
	{
		Dht humtemp = new Dht();
		int ht = humtemp.read();
		
		DhtValue dhtvalue = new DhtValue();
		
		dhtvalue.hum = (int)(ht & 0xFFFF0000) >> 16;
		dhtvalue.temp = (int)(ht & 0x0000FFFF);
		return dhtvalue;
	}
}

class DhtValue
{
	int hum;
	int temp;
	
}
