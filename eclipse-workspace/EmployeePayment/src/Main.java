import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException 
	{
		// Setting variable
		
		//create the person object
		Person person = new Person();
		person.setfName("Victor");
		person.setlName("Doe");
		
		System.out.println("Enter the hourly rate: ");
		int rate = System.in.read();
		
		person.setHourlyRate(rate);
		
		// print the state of the person object
		System.out.println(person.toString());
		
		// get and print the weekly payment
		System.out.println(person.getPaid(40));
		
		return;
	}

}
