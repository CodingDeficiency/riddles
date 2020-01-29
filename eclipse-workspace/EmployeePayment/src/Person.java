
public class Person 
{
	private String fName;
	private String lName;
	private double hourlyRate;
	/**
	 * 
	 */
	public Person() 
	{
		this.fName = "John";
		this.lName = "Smith";
		this.hourlyRate = 45;
		
	}
	
	public Person(String fName, String lName, double hourlyRate) {
		this.fName = fName;
		this.lName = lName;
		this.hourlyRate = hourlyRate;
	}

	public String getfName() 
	{
		return fName;
	}

	public void setfName(String fName) 
	{
		this.fName = fName;
	}

	public String getlName() 
	{
		return lName;
	}

	public void setlName(String lName)
	{
		this.lName = lName;
	}

	public double getHourlyRate() 
	{
		return hourlyRate;
	}

	public void setHourlyRate(double hourlyRate)
	{
		this.hourlyRate = hourlyRate;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString()
	{
		return "Person [fName=" + fName + ", lName=" + lName + ", hourlyRate=" + hourlyRate + "]";
	}
	
	public double getPaid(int hours)
	{
		return this.hourlyRate*hours;
	}
	

}
