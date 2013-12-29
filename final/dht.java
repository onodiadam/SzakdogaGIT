class Dht
{
	public native int read();
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
		int ht = humtemp.read();
		System.out.println("H: " + (int)((ht & 0xFFFF0000) >> 16) + "T:" + (int)(ht & 0x0000FFFF) + "\r\n");
	}
}
