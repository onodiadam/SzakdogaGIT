		package Java;
import Java.IMeasure;

class DhtMain implements IMeasure
{
	static
	{
		System.loadLibrary("Dht");
	}

	public Object measure()
	{
		int ht = read();
		
		DhtValue dhtvalue = new DhtValue();
		
		dhtvalue.hum = (int)(ht & 0xFFFF0000) >> 16;
		dhtvalue.temp = (int)(ht & 0x0000FFFF);
		return dhtvalue;
	}

	public native int read();
}

class DhtValue
{
	int hum;
	int temp;
	
}
