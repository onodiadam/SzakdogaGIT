class Us
{
	public native int distance();
	static
	{
		System.loadLibrary("Us");
	}
	
}

class Main
{
	public static void main(String[] args)
	{
			Us obj = new Us();
			int distance = obj.distance();
			System.out.printf("Tavolsag: ",distance);
	}
}
