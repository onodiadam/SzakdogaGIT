class Dht
{
	public native long readDHT();
	static 
	{
		System.loadLibrary("Dht");	
	}
	
}

class Main
{
	public static void main(String[] args)
	{
		Dht humtemp = new Dht();
		long ht = humtemp.readDHT();
		System.out.printf("Para x 16 + Homerseklet = ", ht);
	}
}
