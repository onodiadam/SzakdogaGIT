package Java;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Date;


public class MySQLHandler
{
  private Connection connect = null;
  private Statement statement = null;
  private PreparedStatement preparedStatement = null;
  private ResultSet resultSet = null;
  
  private static final boolean DEBUG = false;
  
  public void connectDatabase(String address, String database, String user, String passwd) throws Exception
  {
	  try
	  {
		  // Load the driver
		  Class.forName("com.mysql.jdbc.Driver");
      
		  // Put together the connection string from parameters
		  String connStr = "jdbc:mysql://" + address + "/" + database + "?"+ "user=" + user + "&password=" + passwd;
		  logMessage("Conn str: " + connStr);
      
		  // Connect the database
		  connect = DriverManager.getConnection(connStr);
		  logMessage("Connect done");
	  }
	  catch(Exception ex)
	  {
		  logMessage(ex.getMessage());
		  throw new Exception("Error occured during db connection", ex);
	  }
  }
  
  public void addMeasure(int measureType, int measureValue, Date date) throws Exception
  {
	  try
	  {
		  java.text.SimpleDateFormat sdf = new java.text.SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		  String currentTime = sdf.format(date);
		  
		  String insertString = "INSERT INTO Measurement (Measure_type, Measure_value, Time) VALUES (" + measureType + ", " + measureValue + ", \"" + currentTime + "\");";
		  logMessage("Ins str: " + insertString);
		  
		  statement = connect.createStatement();
		  statement.executeUpdate(insertString);
		  logMessage("Insert done");
		  
		  statement.close();
	  }
	  catch(Exception ex)
	  {
		  logMessage(ex.getMessage());
		  throw new Exception("Error occured during db insert", ex);
	  }
  }
  
  public void closeDatabase() 
  {
	  try 
	  {
		  if (resultSet != null) 
			  resultSet.close();

		  if (statement != null) 
			  statement.close();
 
		  if (connect != null) 
			  connect.close();
	  } 
	  catch (Exception e) 
	  {
		  logMessage(e.getMessage());
	  }
  }
  
  private void logMessage(String message)
  {
	  if(DEBUG)
		  System.out.println("MySQLHandler DEBUG ==>  " + message);
  }

} 
