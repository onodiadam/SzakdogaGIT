package Java;
class Us
{
	public native int distance();
	static
	{
		System.loadLibrary("Us");
	}
	
}

class UsMain implements IMeasure
{
	public Object measure()
	{
			Us obj = new Us();
			UsValue usv = new UsValue();
			usv.distance = obj.distance();
			return usv;
	}
}

class UsValue
{
	int distance;
	
}