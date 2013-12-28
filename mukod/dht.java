class HumadityTemperature
{
	public native long readDHT();
	static 
	{
		System.load("/root/work/GIT/SzakdogaGIT/mukod/libDht.so");	
	}
	
}

class Main
{
	public static void main(String[] args)
	{
		HumadityTemperature humtemp = new HumadityTemperature();
		long ht = humtemp.readDHT();
		System.out.printf("Para x 16 + Homerseklet = ", ht);
	}
}
