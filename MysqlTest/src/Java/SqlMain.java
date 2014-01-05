package Java;

import java.util.Date;

import Java.MySQLHandler;

public class SqlMain 
{
	
	private static final String SRV_ADDRESS 		= "192.168.0.100";
	private static final String SRV_DATABASE 		= "test";
	private static final String SRV_USER			= "test";
	private static final String SRV_PASSWD 			= "test";
	
	public static void main(String[] args) throws Exception 
	{
		MySQLHandler dao = new MySQLHandler();
		dao.connectDatabase(SRV_ADDRESS, SRV_DATABASE, SRV_USER, SRV_PASSWD);
		dao.addMeasure(9, 1234, new Date());
		dao.closeDatabase();
	}


} 