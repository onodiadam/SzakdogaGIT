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
		System.out.println("Ht: " + ht + "\r\n");
	}
}
