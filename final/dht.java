class Dht
{
	public native long readDHT();
	static 
	{
		System.loadLibrary("Dht");	
	}
	
}

class DhtMain
{
	public static void main(String[] args)
	{
		Dht humtemp = new Dht();
		long ht = humtemp.readDHT();
		System.out.println("H: " + (int)((ht & 0xFFFF0000) >> 16) + "T:" + (int)(ht & 0x0000FFFF) + "\r\n");
	}
}
