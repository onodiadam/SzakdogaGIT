package Java;
import Java.IMeasure;
class Us
{
	public native int read();
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
			usv.distance = obj.read();
			return usv;
	}
}

class UsValue
{
	int distance;
	
}
